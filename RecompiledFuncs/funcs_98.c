#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800150_chgoldstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800158: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080015C: jal         0x80102424
    // 0x80800160: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800160: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800164: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800168: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080016C: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80800170: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80800174: beq         $at, $zero, L_808002B4
    if (ctx->r1 == 0) {
        // 0x80800178: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808002B4;
    }
    // 0x80800178: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080017C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2136, 0X850) << 16);
    // 0x80800180: addu        $at, $at, $t8
    gpr jr_addend_80800188 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800184: lw          $t8, 0x850($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2136, 0X850));
    // 0x80800188: jr          $t8
    // 0x8080018C: nop

    switch (jr_addend_80800188 >> 2) {
        case 0: goto L_80800190; break;
        case 1: goto L_80800218; break;
        case 2: goto L_808002B4; break;
        case 3: goto L_8080022C; break;
        case 4: goto L_80800278; break;
        case 5: goto L_808002A0; break;
        default: switch_error(__func__, 0x80800188, 0x80800850);
    }
    // 0x8080018C: nop

L_80800190:
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: jal         0x8008A4B0
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080019C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: addiu       $a1, $zero, 0x673
    ctx->r5 = ADD32(0, 0X673);
    // 0x808001A8: jal         0x801032B0
    // 0x808001AC: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_801032B0(rdram, ctx);
        goto after_2;
    // 0x808001AC: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_2:
    // 0x808001B0: jal         0x800DA298
    // 0x808001B4: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808001B4: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    after_3:
    // 0x808001B8: bne         $v0, $zero, L_808001DC
    if (ctx->r2 != 0) {
        // 0x808001BC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808001DC;
    }
    // 0x808001BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808001CC: jal         0x80085708
    // 0x808001D0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808001D0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_4:
    // 0x808001D4: b           L_808001F0
    // 0x808001D8: addiu       $a0, $zero, 0x2B0
    ctx->r4 = ADD32(0, 0X2B0);
        goto L_808001F0;
    // 0x808001D8: addiu       $a0, $zero, 0x2B0
    ctx->r4 = ADD32(0, 0X2B0);
L_808001DC:
    // 0x808001DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001E0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x808001E4: jal         0x80085708
    // 0x808001E8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    _capod_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x808001E8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_5:
    // 0x808001EC: addiu       $a0, $zero, 0x2B0
    ctx->r4 = ADD32(0, 0X2B0);
L_808001F0:
    // 0x808001F0: addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
    // 0x808001F4: jal         0x80101180
    // 0x808001F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x808001F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x808001FC: jal         0x80800000
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chgoldstatue(rdram, ctx);
        goto after_7;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800204: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800208: jal         0x80090734
    // 0x8080020C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80090734(rdram, ctx);
        goto after_8;
    // 0x8080020C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800210: b           L_808002B8
    // 0x80800214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002B8;
    // 0x80800214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800218:
    // 0x80800218: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    // 0x8080021C: jal         0x800DA3B8
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_9;
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800224: b           L_808002B8
    // 0x80800228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002B8;
    // 0x80800228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080022C:
    // 0x8080022C: jal         0x80085710
    // 0x80800230: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_10;
    // 0x80800230: nop

    after_10:
    // 0x80800234: jal         0x80800094
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800094_chgoldstatue(rdram, ctx);
        goto after_11;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080023C: jal         0x800F54E4
    // 0x80800240: nop

    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x80800240: nop

    after_12:
    // 0x80800244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800248: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x8080024C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800250: jal         0x800F7D38
    // 0x80800254: lw          $a3, 0x48($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X48);
    func_800F7D38(rdram, ctx);
        goto after_13;
    // 0x80800254: lw          $a3, 0x48($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X48);
    after_13:
    // 0x80800258: jal         0x800DA524
    // 0x8080025C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_14;
    // 0x8080025C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_14:
    // 0x80800260: jal         0x8010381C
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010381C(rdram, ctx);
        goto after_15;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800268: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x8080026C: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x80800270: b           L_808002B4
    // 0x80800274: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_808002B4;
    // 0x80800274: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_80800278:
    // 0x80800278: lhu         $t2, 0x64($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X64);
    // 0x8080027C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80800280: beql        $t3, $zero, L_808002B8
    if (ctx->r11 == 0) {
        // 0x80800284: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002B8;
    }
    goto skip_0;
    // 0x80800284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800288: jal         0x8010381C
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010381C(rdram, ctx);
        goto after_16;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800290: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800294: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x80800298: b           L_808002B4
    // 0x8080029C: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_808002B4;
    // 0x8080029C: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_808002A0:
    // 0x808002A0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: addiu       $a1, $zero, 0x673
    ctx->r5 = ADD32(0, 0X673);
    // 0x808002AC: jal         0x801032B0
    // 0x808002B0: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    func_801032B0(rdram, ctx);
        goto after_17;
    // 0x808002B0: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    after_17:
L_808002B4:
    // 0x808002B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002B8:
    // 0x808002B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

;}
RECOMP_FUNC void func_808004B4_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004BC: jal         0x808001FC
    // 0x808004C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001FC_bsstatue(rdram, ctx);
        goto after_0;
    // 0x808004C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004C4: jal         0x80082FE0
    // 0x808004C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808004C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808004CC: jal         0x800848E0
    // 0x808004D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badrone_entrypoint_31(rdram, ctx);
        goto after_2;
    // 0x808004D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808004D4: beq         $v0, $zero, L_808004E4
    if (ctx->r2 == 0) {
        // 0x808004D8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808004E4;
    }
    // 0x808004D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004DC: jal         0x80800000
    // 0x808004E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_bsstatue(rdram, ctx);
        goto after_3;
    // 0x808004E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_808004E4:
    // 0x808004E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004EC: jr          $ra
    // 0x808004F0: nop

    return;
    // 0x808004F0: nop

;}
RECOMP_FUNC void _bainvisible_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854C0: syscall     164
    recomp_syscall_handler(rdram, ctx, 0x800854C0);
    return;
    // 0x800854C4: xori        $t0, $zero, 0xC
    ctx->r8 = 0 ^ 0XC;
;}
RECOMP_FUNC void func_808009B4_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009C0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808009C4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808009C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009CC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808009D0: bnel        $t7, $at, L_80800A1C
    if (ctx->r15 != ctx->r1) {
        // 0x808009D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A1C;
    }
    goto skip_0;
    // 0x808009D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808009D8: jal         0x80105834
    // 0x808009DC: nop

    func_80105834(rdram, ctx);
        goto after_0;
    // 0x808009DC: nop

    after_0:
    // 0x808009E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1112, 0X1400) << 16);
    // 0x808009E4: addiu       $a2, $a2, 0x1400
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1112, 0X1400));
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808009F0: jal         0x80089D20
    // 0x808009F4: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808009F4: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    after_1:
    // 0x808009F8: jal         0x80105A5C
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_2;
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800A00: beql        $v0, $zero, L_80800A1C
    if (ctx->r2 == 0) {
        // 0x80800A04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A1C;
    }
    goto skip_1;
    // 0x80800A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800A08: jal         0x80085710
    // 0x80800A0C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x80800A0C: nop

    after_3:
    // 0x80800A10: jal         0x800FFAB0
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A1C:
    // 0x80800A1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A24: jr          $ra
    // 0x80800A28: nop

    return;
    // 0x80800A28: nop

;}
RECOMP_FUNC void func_800175F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800175F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800175F4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800175F8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800175FC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80017600: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80017604: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80017608: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001760C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80017610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017614: jal         0x800E96B0
    // 0x80017618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E96B0(rdram, ctx);
        goto after_0;
    // 0x80017618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8001761C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80017620: addiu       $s0, $s0, -0x6060
    ctx->r16 = ADD32(ctx->r16, -0X6060);
    // 0x80017624: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80017628: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8001762C: addiu       $s5, $zero, 0x6
    ctx->r21 = ADD32(0, 0X6);
    // 0x80017630: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x80017634: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80017638:
    // 0x80017638: lw          $v0, 0x20C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20C);
    // 0x8001763C: beql        $v0, $zero, L_800176B8
    if (ctx->r2 == 0) {
        // 0x80017640: lbu         $t1, 0x2($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X2);
            goto L_800176B8;
    }
    goto skip_0;
    // 0x80017640: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
    skip_0:
    // 0x80017644: beql        $v0, $s3, L_80017660
    if (ctx->r2 == ctx->r19) {
        // 0x80017648: lbu         $t6, 0x2($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X2);
            goto L_80017660;
    }
    goto skip_1;
    // 0x80017648: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    skip_1:
    // 0x8001764C: beql        $v0, $s4, L_80017734
    if (ctx->r2 == ctx->r20) {
        // 0x80017650: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80017734;
    }
    goto skip_2;
    // 0x80017650: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x80017654: b           L_80017734
    // 0x80017658: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80017734;
    // 0x80017658: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001765C: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
L_80017660:
    // 0x80017660: beql        $t6, $zero, L_800176A0
    if (ctx->r14 == 0) {
        // 0x80017664: sb          $zero, 0x5($s0)
        MEM_B(0X5, ctx->r16) = 0;
            goto L_800176A0;
    }
    goto skip_3;
    // 0x80017664: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    skip_3:
    // 0x80017668: lbu         $t7, 0x5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5);
    // 0x8001766C: bnel        $t7, $zero, L_800176A0
    if (ctx->r15 != 0) {
        // 0x80017670: sb          $zero, 0x5($s0)
        MEM_B(0X5, ctx->r16) = 0;
            goto L_800176A0;
    }
    goto skip_4;
    // 0x80017670: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    skip_4:
    // 0x80017674: lbu         $t8, 0x4($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X4);
    // 0x80017678: bnel        $t8, $zero, L_800176A0
    if (ctx->r24 != 0) {
        // 0x8001767C: sb          $zero, 0x5($s0)
        MEM_B(0X5, ctx->r16) = 0;
            goto L_800176A0;
    }
    goto skip_5;
    // 0x8001767C: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    skip_5:
    // 0x80017680: jal         0x80024E90
    // 0x80017684: addiu       $a0, $s0, 0x1E0
    ctx->r4 = ADD32(ctx->r16, 0X1E0);
    func_80024E90(rdram, ctx);
        goto after_1;
    // 0x80017684: addiu       $a0, $s0, 0x1E0
    ctx->r4 = ADD32(ctx->r16, 0X1E0);
    after_1:
    // 0x80017688: lbu         $t9, 0x3($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X3);
    // 0x8001768C: beql        $t9, $zero, L_800176A4
    if (ctx->r25 == 0) {
        // 0x80017690: lbu         $v0, 0x4($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X4);
            goto L_800176A4;
    }
    goto skip_6;
    // 0x80017690: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    skip_6:
    // 0x80017694: b           L_800176A0
    // 0x80017698: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
        goto L_800176A0;
    // 0x80017698: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x8001769C: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
L_800176A0:
    // 0x800176A0: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
L_800176A4:
    // 0x800176A4: blez        $v0, L_80017730
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800176A8: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80017730;
    }
    // 0x800176A8: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x800176AC: b           L_80017730
    // 0x800176B0: sb          $t0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r8;
        goto L_80017730;
    // 0x800176B0: sb          $t0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r8;
    // 0x800176B4: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
L_800176B8:
    // 0x800176B8: beql        $t1, $zero, L_80017724
    if (ctx->r9 == 0) {
        // 0x800176BC: lbu         $v0, 0x4($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X4);
            goto L_80017724;
    }
    goto skip_7;
    // 0x800176BC: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    skip_7:
    // 0x800176C0: lbu         $t2, 0x4($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X4);
    // 0x800176C4: bnel        $t2, $zero, L_80017724
    if (ctx->r10 != 0) {
        // 0x800176C8: lbu         $v0, 0x4($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X4);
            goto L_80017724;
    }
    goto skip_8;
    // 0x800176C8: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    skip_8:
    // 0x800176CC: lw          $t3, 0x238($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X238);
    // 0x800176D0: bnel        $t3, $zero, L_80017724
    if (ctx->r11 != 0) {
        // 0x800176D4: lbu         $v0, 0x4($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X4);
            goto L_80017724;
    }
    goto skip_9;
    // 0x800176D4: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    skip_9:
    // 0x800176D8: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x800176DC: andi        $s1, $s2, 0xFF
    ctx->r17 = ctx->r18 & 0XFF;
    // 0x800176E0: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x800176E4: beq         $t4, $zero, L_80017700
    if (ctx->r12 == 0) {
        // 0x800176E8: nop
    
            goto L_80017700;
    }
    // 0x800176E8: nop

    // 0x800176EC: jal         0x80025F20
    // 0x800176F0: addiu       $a0, $s0, 0x1E0
    ctx->r4 = ADD32(ctx->r16, 0X1E0);
    func_80025F20(rdram, ctx);
        goto after_2;
    // 0x800176F0: addiu       $a0, $s0, 0x1E0
    ctx->r4 = ADD32(ctx->r16, 0X1E0);
    after_2:
    // 0x800176F4: sb          $s6, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r22;
    // 0x800176F8: b           L_80017708
    // 0x800176FC: andi        $s1, $s2, 0xFF
    ctx->r17 = ctx->r18 & 0XFF;
        goto L_80017708;
    // 0x800176FC: andi        $s1, $s2, 0xFF
    ctx->r17 = ctx->r18 & 0XFF;
L_80017700:
    // 0x80017700: jal         0x8001713C
    // 0x80017704: lh          $a1, 0x26E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X26E);
    func_8001713C(rdram, ctx);
        goto after_3;
    // 0x80017704: lh          $a1, 0x26E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X26E);
    after_3:
L_80017708:
    // 0x80017708: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8001770C: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x80017710: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x80017714: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80017718: jal         0x80017404
    // 0x8001771C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    func_80017404(rdram, ctx);
        goto after_4;
    // 0x8001771C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    after_4:
    // 0x80017720: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
L_80017724:
    // 0x80017724: blez        $v0, L_80017730
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80017728: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80017730;
    }
    // 0x80017728: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8001772C: sb          $t6, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r14;
L_80017730:
    // 0x80017730: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80017734:
    // 0x80017734: bne         $s2, $s5, L_80017638
    if (ctx->r18 != ctx->r21) {
        // 0x80017738: addiu       $s0, $s0, 0x274
        ctx->r16 = ADD32(ctx->r16, 0X274);
            goto L_80017638;
    }
    // 0x80017738: addiu       $s0, $s0, 0x274
    ctx->r16 = ADD32(ctx->r16, 0X274);
    // 0x8001773C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80017740: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017744: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80017748: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001774C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80017750: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80017754: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80017758: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001775C: jr          $ra
    // 0x80017760: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80017760: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800F3C_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F44: jal         0x8080147C
    // 0x80800F48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080147C_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80800F48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800F4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F54: lbu         $v0, 0x15C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X15C);
    // 0x80800F58: beq         $v0, $at, L_80800F70
    if (ctx->r2 == ctx->r1) {
        // 0x80800F5C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800F70;
    }
    // 0x80800F5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F60: beq         $v0, $at, L_80800F8C
    if (ctx->r2 == ctx->r1) {
        // 0x80800F64: lui         $a1, 0x3F66
        ctx->r5 = S32(0X3F66 << 16);
            goto L_80800F8C;
    }
    // 0x80800F64: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800F68: b           L_80800FAC
    // 0x80800F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800FAC;
    // 0x80800F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F70:
    // 0x80800F70: lw          $t6, 0x164($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X164);
    // 0x80800F74: beql        $t6, $zero, L_80800FAC
    if (ctx->r14 == 0) {
        // 0x80800F78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800FAC;
    }
    goto skip_0;
    // 0x80800F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800F7C: jal         0x80800DB8
    // 0x80800F80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800DB8_bsstatue(rdram, ctx);
        goto after_1;
    // 0x80800F80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800F84: b           L_80800FAC
    // 0x80800F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800FAC;
    // 0x80800F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F8C:
    // 0x80800F8C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800F90: jal         0x8008CB10
    // 0x80800F94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800F94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800F98: beq         $v0, $zero, L_80800FA8
    if (ctx->r2 == 0) {
        // 0x80800F9C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800FA8;
    }
    // 0x80800F9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FA0: jal         0x80800DB8
    // 0x80800FA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800DB8_bsstatue(rdram, ctx);
        goto after_3;
    // 0x80800FA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
L_80800FA8:
    // 0x80800FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800FAC:
    // 0x80800FAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FB0: jr          $ra
    // 0x80800FB4: nop

    return;
    // 0x80800FB4: nop

;}
RECOMP_FUNC void _subaddiecustomhits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A000: syscall     822
    recomp_syscall_handler(rdram, ctx, 0x8008A000);
    return;
    // 0x8008A004: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084040: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084040);
    return;
    // 0x80084044: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void subaddietaxi_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C54: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800C58: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800C5C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800C60: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80800C64: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800C68: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800C6C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800C70: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800C74: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800C78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C7C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800C80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C84: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80800C88: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80800C8C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80800C90: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80800C94: jal         0x80800CF0
    // 0x80800C98: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80800CF0_subaddietaxi(rdram, ctx);
        goto after_0;
    // 0x80800C98: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800C9C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800CA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CA4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800CA8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800CAC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800CB0: jal         0x80108474
    // 0x80800CB4: nop

    func_80108474(rdram, ctx);
        goto after_1;
    // 0x80800CB4: nop

    after_1:
    // 0x80800CB8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CBC: lhu         $t2, 0x76($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X76);
    // 0x80800CC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CC4: sll         $t1, $t9, 7
    ctx->r9 = S32(ctx->r25 << 7);
    // 0x80800CC8: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x80800CCC: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800CD0: sh          $t4, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r12;
    // 0x80800CD4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800CD8: jal         0x8010108C
    // 0x80800CDC: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_8010108C(rdram, ctx);
        goto after_2;
    // 0x80800CDC: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_2:
    // 0x80800CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800CE8: jr          $ra
    // 0x80800CEC: nop

    return;
    // 0x80800CEC: nop

;}
RECOMP_FUNC void func_800E2AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2AA4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800E2AA8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800E2AAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E2AB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E2AB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E2AB8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800E2ABC: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800E2AC0: beq         $t6, $zero, L_800E2AE4
    if (ctx->r14 == 0) {
        // 0x800E2AC4: sw          $a3, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r7;
            goto L_800E2AE4;
    }
    // 0x800E2AC4: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800E2AC8: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800E2ACC: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800E2AD0: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800E2AD4: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x800E2AD8: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800E2ADC: b           L_800E2AFC
    // 0x800E2AE0: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
        goto L_800E2AFC;
    // 0x800E2AE0: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_800E2AE4:
    // 0x800E2AE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E2AE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E2AEC: nop

    // 0x800E2AF0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800E2AF4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800E2AF8: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
L_800E2AFC:
    // 0x800E2AFC: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x800E2B00: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800E2B04: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800E2B08: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800E2B0C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800E2B10: jal         0x800E1C00
    // 0x800E2B14: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    func_800E1C00(rdram, ctx);
        goto after_0;
    // 0x800E2B14: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800E2B18: bne         $v0, $zero, L_800E2B30
    if (ctx->r2 != 0) {
        // 0x800E2B1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800E2B30;
    }
    // 0x800E2B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2B20: jal         0x800E23A4
    // 0x800E2B24: nop

    func_800E23A4(rdram, ctx);
        goto after_1;
    // 0x800E2B24: nop

    after_1:
    // 0x800E2B28: b           L_800E2C44
    // 0x800E2B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800E2C44;
    // 0x800E2B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E2B30:
    // 0x800E2B30: jal         0x800E1DF4
    // 0x800E2B34: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800E1DF4(rdram, ctx);
        goto after_2;
    // 0x800E2B34: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_2:
    // 0x800E2B38: jal         0x800E401C
    // 0x800E2B3C: nop

    func_800E401C(rdram, ctx);
        goto after_3;
    // 0x800E2B3C: nop

    after_3:
    // 0x800E2B40: jal         0x80018EFC
    // 0x800E2B44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mlMtxSet(rdram, ctx);
        goto after_4;
    // 0x800E2B44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800E2B48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2B4C: lwc1        $f12, -0x2B68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B68);
    // 0x800E2B50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800E2B54: nop

    // 0x800E2B58: c.eq.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl == ctx->f12.fl;
    // 0x800E2B5C: nop

    // 0x800E2B60: bc1tl       L_800E2B74
    if (c1cs) {
        // 0x800E2B64: lwc1        $f12, 0x40($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
            goto L_800E2B74;
    }
    goto skip_0;
    // 0x800E2B64: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x800E2B68: jal         0x8001907C
    // 0x800E2B6C: nop

    mlMtxRotRoll(rdram, ctx);
        goto after_5;
    // 0x800E2B6C: nop

    after_5:
    // 0x800E2B70: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
L_800E2B74:
    // 0x800E2B74: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800E2B78: jal         0x800191F8
    // 0x800E2B7C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    func_800191F8(rdram, ctx);
        goto after_6;
    // 0x800E2B7C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_6:
    // 0x800E2B80: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800E2B84: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800E2B88: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800E2B8C: bne         $t8, $zero, L_800E2B9C
    if (ctx->r24 != 0) {
        // 0x800E2B90: lwc1        $f14, 0x50($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
            goto L_800E2B9C;
    }
    // 0x800E2B90: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800E2B94: beq         $t9, $zero, L_800E2BB8
    if (ctx->r25 == 0) {
        // 0x800E2B98: nop
    
            goto L_800E2BB8;
    }
    // 0x800E2B98: nop

L_800E2B9C:
    // 0x800E2B9C: beq         $t0, $zero, L_800E2BB0
    if (ctx->r8 == 0) {
        // 0x800E2BA0: lwc1        $f12, 0x54($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
            goto L_800E2BB0;
    }
    // 0x800E2BA0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800E2BA4: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800E2BA8: b           L_800E2BB0
    // 0x800E2BAC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_800E2BB0;
    // 0x800E2BAC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_800E2BB0:
    // 0x800E2BB0: jal         0x80019D30
    // 0x800E2BB4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    mlMtxScale_xyz(rdram, ctx);
        goto after_7;
    // 0x800E2BB4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    after_7:
L_800E2BB8:
    // 0x800E2BB8: jal         0x80018C28
    // 0x800E2BBC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_8;
    // 0x800E2BBC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_8:
    // 0x800E2BC0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E2BC4: lui         $t2, 0xDA38
    ctx->r10 = S32(0XDA38 << 16);
    // 0x800E2BC8: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800E2BCC: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800E2BD0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800E2BD4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800E2BD8: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x800E2BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2BE0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800E2BE4: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x800E2BE8: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x800E2BEC: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800E2BF0: jal         0x800E204C
    // 0x800E2BF4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800E204C(rdram, ctx);
        goto after_9;
    // 0x800E2BF4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_9:
    // 0x800E2BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2BFC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800E2C00: jal         0x800E2180
    // 0x800E2C04: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    func_800E2180(rdram, ctx);
        goto after_10;
    // 0x800E2C04: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_10:
    // 0x800E2C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2C0C: jal         0x800E2260
    // 0x800E2C10: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800E2260(rdram, ctx);
        goto after_11;
    // 0x800E2C10: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_11:
    // 0x800E2C14: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E2C18: lui         $t7, 0xD838
    ctx->r15 = S32(0XD838 << 16);
    // 0x800E2C1C: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800E2C20: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E2C24: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800E2C28: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800E2C2C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800E2C30: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E2C34: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800E2C38: jal         0x800E22F0
    // 0x800E2C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E22F0(rdram, ctx);
        goto after_12;
    // 0x800E2C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800E2C40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E2C44:
    // 0x800E2C44: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E2C48: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800E2C4C: jr          $ra
    // 0x800E2C50: nop

    return;
    // 0x800E2C50: nop

;}
RECOMP_FUNC void _baswim_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852A8: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x800852A8);
    return;
    // 0x800852AC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_801125E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801125E8: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x801125EC: jr          $ra
    // 0x801125F0: lwc1        $f0, 0xC($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0XC);
    return;
    // 0x801125F0: lwc1        $f0, 0xC($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0XC);
;}
RECOMP_FUNC void bsbshock_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800474: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800478: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080047C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800480: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800484: jal         0x800C2FDC
    // 0x80800488: lbu         $a0, 0x164($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X164);
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800488: lbu         $a0, 0x164($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X164);
    after_0:
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800490: jal         0x800A0CE8
    // 0x80800494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CE8(rdram, ctx);
        goto after_1;
    // 0x80800494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: jal         0x800A0CF4
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808004A4: jal         0x80092BF4
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092BF4(rdram, ctx);
        goto after_3;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808004AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808004B0: nop

    // 0x808004B4: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x808004B8: nop

    // 0x808004BC: bc1tl       L_808004E0
    if (c1cs) {
        // 0x808004C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808004E0;
    }
    goto skip_0;
    // 0x808004C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808004C4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808004C8: jal         0x80093300
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80093300(rdram, ctx);
        goto after_4;
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: jal         0x8009C1B4
    // 0x808004D8: lui         $a1, 0x42AE
    ctx->r5 = S32(0X42AE << 16);
    func_8009C1B4(rdram, ctx);
        goto after_5;
    // 0x808004D8: lui         $a1, 0x42AE
    ctx->r5 = S32(0X42AE << 16);
    after_5:
    // 0x808004DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004E0:
    // 0x808004E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004E8: jr          $ra
    // 0x808004EC: nop

    return;
    // 0x808004EC: nop

;}
RECOMP_FUNC void _bavan_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085388: syscall     159
    recomp_syscall_handler(rdram, ctx, 0x80085388);
    return;
    // 0x8008538C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bakey_func_80091964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091964: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80091968: jr          $ra
    // 0x8009196C: lbu         $v0, 0x9($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X9);
    return;
    // 0x8009196C: lbu         $v0, 0x9($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X9);
;}
RECOMP_FUNC void func_800D21F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D21F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D21F4: addiu       $t7, $t7, -0x4BA4
    ctx->r15 = ADD32(ctx->r15, -0X4BA4);
    // 0x800D21F8: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800D21FC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800D2200: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800D2204: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800D2208: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D220C: addiu       $a1, $a1, -0x4D40
    ctx->r5 = ADD32(ctx->r5, -0X4D40);
    // 0x800D2210: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x800D2214: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800D2218: beql        $at, $zero, L_800D2254
    if (ctx->r1 == 0) {
        // 0x800D221C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800D2254;
    }
    goto skip_0;
    // 0x800D221C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x800D2220: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
L_800D2224:
    // 0x800D2224: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D2228: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800D222C: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800D2230: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x800D2234: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800D2238: bne         $a0, $t1, L_800D2248
    if (ctx->r4 != ctx->r9) {
        // 0x800D223C: nop
    
            goto L_800D2248;
    }
    // 0x800D223C: nop

    // 0x800D2240: jr          $ra
    // 0x800D2244: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D2244: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D2248:
    // 0x800D2248: bnel        $at, $zero, L_800D2224
    if (ctx->r1 != 0) {
        // 0x800D224C: lbu         $v1, 0x0($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X0);
            goto L_800D2224;
    }
    goto skip_1;
    // 0x800D224C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    skip_1:
    // 0x800D2250: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D2254:
    // 0x800D2254: jr          $ra
    // 0x800D2258: nop

    return;
    // 0x800D2258: nop

;}
RECOMP_FUNC void bscrouch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002D8: jal         0x8008CABC
    // 0x808002DC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808002DC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x808002E0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: jal         0x800852F0
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_1;
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: jal         0x800852F0
    // 0x808002F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x808002F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x80085300
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_3;
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800308: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080030C: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800310: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800314: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800318: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080031C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800320: jal         0x800F10B4
    // 0x80800324: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800324: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800328: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080032C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800330: jal         0x8009B9B0
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800338: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8080033C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800340: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800344: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800348: nop

    // 0x8080034C: bc1fl       L_80800360
    if (!c1cs) {
        // 0x80800350: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_80800360;
    }
    goto skip_0;
    // 0x80800350: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_0:
    // 0x80800354: jal         0x80084A10
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080035C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
L_80800360:
    // 0x80800360: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800364: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800368: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8080036C: nop

    // 0x80800370: bc1f        L_80800380
    if (!c1cs) {
        // 0x80800374: nop
    
            goto L_80800380;
    }
    // 0x80800374: nop

    // 0x80800378: jal         0x8009D658
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_7;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80800380:
    // 0x80800380: jal         0x8009EF04
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_8;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800388: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080038C: nop

    // 0x80800390: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x80800394: nop

    // 0x80800398: bc1f        L_808003B4
    if (!c1cs) {
        // 0x8080039C: nop
    
            goto L_808003B4;
    }
    // 0x8080039C: nop

    // 0x808003A0: jal         0x8009C984
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_9;
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003AC: jal         0x8009C914
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_10;
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_808003B4:
    // 0x808003B4: jal         0x8009C990
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_11;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808003BC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808003C0: jal         0x8009C984
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_12;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808003C8: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808003CC: jal         0x800F1DCC
    // 0x808003D0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_13;
    // 0x808003D0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_13:
    // 0x808003D4: jal         0x800F2100
    // 0x808003D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_14;
    // 0x808003D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_14:
    // 0x808003DC: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x808003E0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808003E4: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x808003E8: beq         $at, $zero, L_808005F4
    if (ctx->r1 == 0) {
        // 0x808003EC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808005F4;
    }
    // 0x808003EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808003F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(152, 0X978) << 16);
    // 0x808003F4: addu        $at, $at, $t6
    gpr jr_addend_808003FC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808003F8: lw          $t6, 0x978($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(152, 0X978));
    // 0x808003FC: jr          $t6
    // 0x80800400: nop

    switch (jr_addend_808003FC >> 2) {
        case 0: goto L_80800404; break;
        case 1: goto L_80800438; break;
        case 2: goto L_8080048C; break;
        case 3: goto L_8080056C; break;
        case 4: goto L_808004D4; break;
        default: switch_error(__func__, 0x808003FC, 0x80800978);
    }
    // 0x80800400: nop

L_80800404:
    // 0x80800404: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800408: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800414: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800418: nop

    // 0x8080041C: bc1f        L_808005F4
    if (!c1cs) {
        // 0x80800420: nop
    
            goto L_808005F4;
    }
    // 0x80800420: nop

    // 0x80800424: jal         0x80085338
    // 0x80800428: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    _batimer_set(rdram, ctx);
        goto after_15;
    // 0x80800428: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_15:
    // 0x8080042C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800430: b           L_808005F4
    // 0x80800434: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_808005F4;
    // 0x80800434: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800438:
    // 0x80800438: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80800444: nop

    // 0x80800448: bc1t        L_80800460
    if (c1cs) {
        // 0x8080044C: nop
    
            goto L_80800460;
    }
    // 0x8080044C: nop

    // 0x80800450: jal         0x80800000
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bscrouch(rdram, ctx);
        goto after_16;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800458: b           L_808005F4
    // 0x8080045C: nop

        goto L_808005F4;
    // 0x8080045C: nop

L_80800460:
    // 0x80800460: jal         0x800852F0
    // 0x80800464: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_decrement(rdram, ctx);
        goto after_17;
    // 0x80800464: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: jal         0x80085330
    // 0x80800470: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_isZero(rdram, ctx);
        goto after_18;
    // 0x80800470: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x80800474: beq         $v0, $zero, L_808005F4
    if (ctx->r2 == 0) {
        // 0x80800478: nop
    
            goto L_808005F4;
    }
    // 0x80800478: nop

    // 0x8080047C: jal         0x80800034
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800034_bscrouch(rdram, ctx);
        goto after_19;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800484: b           L_808005F4
    // 0x80800488: nop

        goto L_808005F4;
    // 0x80800488: nop

L_8080048C:
    // 0x8080048C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800490: nop

    // 0x80800494: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80800498: nop

    // 0x8080049C: bc1t        L_808004B4
    if (c1cs) {
        // 0x808004A0: nop
    
            goto L_808004B4;
    }
    // 0x808004A0: nop

    // 0x808004A4: jal         0x80800000
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bscrouch(rdram, ctx);
        goto after_20;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808004AC: b           L_808005F4
    // 0x808004B0: nop

        goto L_808005F4;
    // 0x808004B0: nop

L_808004B4:
    // 0x808004B4: jal         0x8008B324
    // 0x808004B8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_isStopped(rdram, ctx);
        goto after_21;
    // 0x808004B8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_21:
    // 0x808004BC: beq         $v0, $zero, L_808005F4
    if (ctx->r2 == 0) {
        // 0x808004C0: nop
    
            goto L_808005F4;
    }
    // 0x808004C0: nop

    // 0x808004C4: jal         0x80800068
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800068_bscrouch(rdram, ctx);
        goto after_22;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808004CC: b           L_808005F4
    // 0x808004D0: nop

        goto L_808005F4;
    // 0x808004D0: nop

L_808004D4:
    // 0x808004D4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808004D8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808004DC: jal         0x808000B4
    // 0x808004E0: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_808000B4_bscrouch(rdram, ctx);
        goto after_23;
    // 0x808004E0: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_23:
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: jal         0x808000FC
    // 0x808004EC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_808000FC_bscrouch(rdram, ctx);
        goto after_24;
    // 0x808004EC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_24:
    // 0x808004F0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808004F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808004F8: nop

    // 0x808004FC: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80800500: nop

    // 0x80800504: bc1f        L_808005F4
    if (!c1cs) {
        // 0x80800508: nop
    
            goto L_808005F4;
    }
    // 0x80800508: nop

    // 0x8080050C: jal         0x8008B2B4
    // 0x80800510: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_25;
    // 0x80800510: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_25:
    // 0x80800514: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800518: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080051C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800520: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800524: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80800528: nop

    // 0x8080052C: bc1f        L_8080054C
    if (!c1cs) {
        // 0x80800530: nop
    
            goto L_8080054C;
    }
    // 0x80800530: nop

    // 0x80800534: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800538: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080053C: jal         0x8008B1D4
    // 0x80800540: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_26;
    // 0x80800540: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_26:
    // 0x80800544: b           L_80800558
    // 0x80800548: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_80800558;
    // 0x80800548: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_8080054C:
    // 0x8080054C: jal         0x8008B1D4
    // 0x80800550: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_27;
    // 0x80800550: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_27:
    // 0x80800554: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_80800558:
    // 0x80800558: jal         0x8008B134
    // 0x8080055C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_28;
    // 0x8080055C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80800560: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800564: b           L_808005F4
    // 0x80800568: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_808005F4;
    // 0x80800568: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_8080056C:
    // 0x8080056C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800570: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800574: jal         0x808000B4
    // 0x80800578: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_808000B4_bscrouch(rdram, ctx);
        goto after_29;
    // 0x80800578: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_29:
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: jal         0x808000FC
    // 0x80800584: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_808000FC_bscrouch(rdram, ctx);
        goto after_30;
    // 0x80800584: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_30:
    // 0x80800588: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080058C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800590: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800594: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800598: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080059C: nop

    // 0x808005A0: bc1t        L_808005C8
    if (c1cs) {
        // 0x808005A4: nop
    
            goto L_808005C8;
    }
    // 0x808005A4: nop

    // 0x808005A8: jal         0x8008B1D4
    // 0x808005AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_31;
    // 0x808005AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_31:
    // 0x808005B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808005B4: jal         0x8008B134
    // 0x808005B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_32;
    // 0x808005B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x808005BC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x808005C0: b           L_808005F4
    // 0x808005C4: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
        goto L_808005F4;
    // 0x808005C4: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_808005C8:
    // 0x808005C8: jal         0x8008B324
    // 0x808005CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_isStopped(rdram, ctx);
        goto after_33;
    // 0x808005CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_33:
    // 0x808005D0: beq         $v0, $zero, L_808005F4
    if (ctx->r2 == 0) {
        // 0x808005D4: nop
    
            goto L_808005F4;
    }
    // 0x808005D4: nop

    // 0x808005D8: jal         0x8009C984
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_34;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x808005E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005E4: jal         0x8009C914
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_35;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808005EC: jal         0x80800068
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800068_bscrouch(rdram, ctx);
        goto after_36;
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
L_808005F4:
    // 0x808005F4: jal         0x8008E148
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_37;
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x808005FC: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x80800600: nop
    
            goto L_80800610;
    }
    // 0x80800600: nop

    // 0x80800604: jal         0x800848B0
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_38;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x8080060C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_80800610:
    // 0x80800610: jal         0x8008DD04
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_39;
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80800618: beq         $v0, $zero, L_80800628
    if (ctx->r2 == 0) {
        // 0x8080061C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800628;
    }
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800620: addiu       $t0, $zero, 0x2F
    ctx->r8 = ADD32(0, 0X2F);
    // 0x80800624: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_80800628:
    // 0x80800628: jal         0x8080070C
    // 0x8080062C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    bscrouch_entrypoint_4(rdram, ctx);
        goto after_40;
    // 0x8080062C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_40:
    // 0x80800630: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800634: bne         $v0, $at, L_80800654
    if (ctx->r2 != ctx->r1) {
        // 0x80800638: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_80800654;
    }
    // 0x80800638: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: jal         0x80085328
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isNonzero(rdram, ctx);
        goto after_41;
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x80800648: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x8080064C: nop
    
            goto L_80800654;
    }
    // 0x8080064C: nop

    // 0x80800650: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80800654:
    // 0x80800654: jal         0x8008E35C
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_42;
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8080065C: beq         $v0, $zero, L_8080066C
    if (ctx->r2 == 0) {
        // 0x80800660: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080066C;
    }
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800664: addiu       $t1, $zero, 0x2D
    ctx->r9 = ADD32(0, 0X2D);
    // 0x80800668: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
L_8080066C:
    // 0x8080066C: jal         0x8009E5C8
    // 0x80800670: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    bs_setState(rdram, ctx);
        goto after_43;
    // 0x80800670: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_43:
    // 0x80800674: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800678: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080067C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800680: jr          $ra
    // 0x80800684: nop

    return;
    // 0x80800684: nop

;}
RECOMP_FUNC void _suflamefx_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089948: syscall     798
    recomp_syscall_handler(rdram, ctx, 0x80089948);
    return;
    // 0x8008994C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80801578_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080157C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801580: jal         0x80106790
    // 0x80801584: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801584: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801588: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080158C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801590: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801594: beq         $v1, $zero, L_808015AC
    if (ctx->r3 == 0) {
        // 0x80801598: nop
    
            goto L_808015AC;
    }
    // 0x80801598: nop

    // 0x8080159C: beq         $v1, $at, L_808015BC
    if (ctx->r3 == ctx->r1) {
        // 0x808015A0: nop
    
            goto L_808015BC;
    }
    // 0x808015A0: nop

    // 0x808015A4: b           L_808015C8
    // 0x808015A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808015C8;
    // 0x808015A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808015AC:
    // 0x808015AC: jal         0x8080324C
    // 0x808015B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x808015B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808015B4: b           L_808015C8
    // 0x808015B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808015C8;
    // 0x808015B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808015BC:
    // 0x808015BC: jal         0x8080324C
    // 0x808015C0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_2;
    // 0x808015C0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
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
RECOMP_FUNC void _chcastleshockpadswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086750: syscall     364
    recomp_syscall_handler(rdram, ctx, 0x80086750);
    return;
    // 0x80086754: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A5C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5C0C: jal         0x8001ACCC
    // 0x800A5C10: addiu       $a0, $zero, 0x2C0
    ctx->r4 = ADD32(0, 0X2C0);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800A5C10: addiu       $a0, $zero, 0x2C0
    ctx->r4 = ADD32(0, 0X2C0);
    after_0:
    // 0x800A5C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5C18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A5C1C: sw          $v0, 0x7110($at)
    MEM_W(0X7110, ctx->r1) = ctx->r2;
    // 0x800A5C20: jr          $ra
    // 0x800A5C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800A5C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void bsbtrot_entrypoint_42(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802504: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080250C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802510: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80802514: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80802518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080251C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802520: beq         $v0, $at, L_8080253C
    if (ctx->r2 == ctx->r1) {
        // 0x80802524: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080253C;
    }
    // 0x80802524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802528: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080252C: beq         $v0, $at, L_80802560
    if (ctx->r2 == ctx->r1) {
        // 0x80802530: nop
    
            goto L_80802560;
    }
    // 0x80802530: nop

    // 0x80802534: b           L_808025A8
    // 0x80802538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808025A8;
    // 0x80802538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080253C:
    // 0x8080253C: lui         $a1, 0x3EF2
    ctx->r5 = S32(0X3EF2 << 16);
    // 0x80802540: jal         0x8008CB10
    // 0x80802544: ori         $a1, $a1, 0xE48F
    ctx->r5 = ctx->r5 | 0XE48F;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80802544: ori         $a1, $a1, 0xE48F
    ctx->r5 = ctx->r5 | 0XE48F;
    after_0:
    // 0x80802548: beq         $v0, $zero, L_808025A4
    if (ctx->r2 == 0) {
        // 0x8080254C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808025A4;
    }
    // 0x8080254C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802550: jal         0x80802380
    // 0x80802554: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80802380_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802554: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80802558: b           L_808025A8
    // 0x8080255C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808025A8;
    // 0x8080255C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802560:
    // 0x80802560: jal         0x8008CAC8
    // 0x80802564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_2;
    // 0x80802564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802568: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2E40) << 16);
    // 0x8080256C: lwc1        $f4, 0x2E40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2E40));
    // 0x80802570: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80802574: nop

    // 0x80802578: bc1f        L_80802588
    if (!c1cs) {
        // 0x8080257C: nop
    
            goto L_80802588;
    }
    // 0x8080257C: nop

    // 0x80802580: jal         0x80085058
    // 0x80802584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x80802584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80802588:
    // 0x80802588: jal         0x80800438
    // 0x8080258C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800438_bsbtrot(rdram, ctx);
        goto after_4;
    // 0x8080258C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802590: jal         0x8008CAEC
    // 0x80802594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_5;
    // 0x80802594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802598: beq         $v0, $zero, L_808025A4
    if (ctx->r2 == 0) {
        // 0x8080259C: addiu       $t6, $zero, 0x2F
        ctx->r14 = ADD32(0, 0X2F);
            goto L_808025A4;
    }
    // 0x8080259C: addiu       $t6, $zero, 0x2F
    ctx->r14 = ADD32(0, 0X2F);
    // 0x808025A0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808025A4:
    // 0x808025A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808025A8:
    // 0x808025A8: jal         0x8009E5C8
    // 0x808025AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808025AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808025B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808025B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808025B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808025BC: jr          $ra
    // 0x808025C0: nop

    return;
    // 0x808025C0: nop

;}
RECOMP_FUNC void func_80800220_bswalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800220: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800224: lwc1        $f6, 0x16C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X16C);
    // 0x80800228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080022C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800230: nop

    // 0x80800234: bc1f        L_80800240
    if (!c1cs) {
        // 0x80800238: nop
    
            goto L_80800240;
    }
    // 0x80800238: nop

    // 0x8080023C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800240:
    // 0x80800240: jr          $ra
    // 0x80800244: nop

    return;
    // 0x80800244: nop

;}
RECOMP_FUNC void glidmake_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800100: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800104: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800108: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8080010C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800110: jal         0x800EFD4C
    // 0x80800114: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EFD4C(rdram, ctx);
        goto after_0;
    // 0x80800114: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800118: jal         0x800EFD4C
    // 0x8080011C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EFD4C(rdram, ctx);
        goto after_1;
    // 0x8080011C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800120: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800124: jal         0x800D674C
    // 0x80800128: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x80800128: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x8080012C: jal         0x800B274C
    // 0x80800130: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B274C(rdram, ctx);
        goto after_3;
    // 0x80800130: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800134: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800138: jal         0x800879D0
    // 0x8080013C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    _dbid_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8080013C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x80800140: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x80800144: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_80800238;
    }
    // 0x80800144: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800148: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x8080014C: jal         0x800B2190
    // 0x80800150: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800B2190(rdram, ctx);
        goto after_5;
    // 0x80800150: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_5:
    // 0x80800154: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80800158: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8080015C: lh          $t8, 0x2($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X2);
    // 0x80800160: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80800164: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80800168: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x8080016C: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80800170: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x80800174: beq         $at, $zero, L_80800210
    if (ctx->r1 == 0) {
        // 0x80800178: nop
    
            goto L_80800210;
    }
    // 0x80800178: nop

    // 0x8080017C: lh          $t6, 0x0($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X0);
L_80800180:
    // 0x80800180: addiu       $t1, $t4, -0x4
    ctx->r9 = ADD32(ctx->r12, -0X4);
    // 0x80800184: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80800188: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8080018C: addu        $a3, $t7, $v0
    ctx->r7 = ADD32(ctx->r15, ctx->r2);
    // 0x80800190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800194: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
L_80800198:
    // 0x80800198: bne         $t3, $t1, L_808001B0
    if (ctx->r11 != ctx->r9) {
        // 0x8080019C: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_808001B0;
    }
    // 0x8080019C: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x808001A0: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x808001A4: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // 0x808001A8: b           L_808001F0
    // 0x808001AC: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
        goto L_808001F0;
    // 0x808001AC: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_808001B0:
    // 0x808001B0: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x808001B4: lh          $a2, 0x0($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X0);
    // 0x808001B8: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808001BC: beql        $at, $zero, L_808001D0
    if (ctx->r1 == 0) {
        // 0x808001C0: sh          $a2, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r6;
            goto L_808001D0;
    }
    goto skip_0;
    // 0x808001C0: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
    skip_0:
    // 0x808001C4: b           L_808001D0
    // 0x808001C8: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
        goto L_808001D0;
    // 0x808001C8: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // 0x808001CC: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
L_808001D0:
    // 0x808001D0: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    // 0x808001D4: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x808001D8: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808001DC: beql        $at, $zero, L_808001F0
    if (ctx->r1 == 0) {
        // 0x808001E0: sh          $a2, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r6;
            goto L_808001F0;
    }
    goto skip_1;
    // 0x808001E0: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
    skip_1:
    // 0x808001E4: b           L_808001F0
    // 0x808001E8: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
        goto L_808001F0;
    // 0x808001E8: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // 0x808001EC: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
L_808001F0:
    // 0x808001F0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x808001F4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x808001F8: bne         $t0, $t2, L_80800198
    if (ctx->r8 != ctx->r10) {
        // 0x808001FC: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_80800198;
    }
    // 0x808001FC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80800200: addiu       $t4, $t4, 0x2
    ctx->r12 = ADD32(ctx->r12, 0X2);
    // 0x80800204: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x80800208: bnel        $at, $zero, L_80800180
    if (ctx->r1 != 0) {
        // 0x8080020C: lh          $t6, 0x0($t4)
        ctx->r14 = MEM_H(ctx->r12, 0X0);
            goto L_80800180;
    }
    goto skip_2;
    // 0x8080020C: lh          $t6, 0x0($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X0);
    skip_2:
L_80800210:
    // 0x80800210: jal         0x80800000
    // 0x80800214: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800000_glidmake(rdram, ctx);
        goto after_6;
    // 0x80800214: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x80800218: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x8080021C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800238;
    }
    // 0x8080021C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x800EF0B4
    // 0x80800228: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800EF0B4(rdram, ctx);
        goto after_7;
    // 0x80800228: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_7:
    // 0x8080022C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800230: jal         0x800EF0B4
    // 0x80800234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF0B4(rdram, ctx);
        goto after_8;
    // 0x80800234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_80800238:
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080023C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800240: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800244: jr          $ra
    // 0x80800248: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800248: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gcgoto_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "gcgoto_entrypoint_4");
    // 0x80800468: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080046C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800470: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800474: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800478: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8080047C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80800480: jal         0x8008FE68
    // 0x80800484: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_8008FE68(rdram, ctx);
        goto after_0;
    // 0x80800484: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x80800488: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8080048C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800490: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800494: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800498: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080049C: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x808004A0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x808004A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808004A8: jal         0x800F10B4
    // 0x808004AC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808004AC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x808004B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004B4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808004B8: jal         0x800EEB9C
    // 0x808004BC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x808004BC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_2:
    // 0x808004C0: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808004C4: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808004C8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808004CC: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808004D0: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808004D4: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808004D8: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808004DC: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808004E0: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x808004E4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x808004E8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808004EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808004F0: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x808004F4: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x808004F8: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x808004FC: jal         0x800F54E4
    // 0x80800500: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800500: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80800504: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800508: jal         0x80087910
    // 0x8080050C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _plcamera_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080050C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x80800510: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800514: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800518: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080051C: jal         0x8080011C
    // 0x80800520: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8080011C_gcgoto(rdram, ctx);
        goto after_5;
    // 0x80800520: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80800524: jal         0x800A1618
    // 0x80800528: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A1618(rdram, ctx);
        goto after_6;
    // 0x80800528: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8080052C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800530: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800538: jal         0x80090358
    // 0x8080053C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80090358(rdram, ctx);
        goto after_7;
    // 0x8080053C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x80800540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800544: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800548: jr          $ra
    // 0x8080054C: nop

    return;
    // 0x8080054C: nop

;}
RECOMP_FUNC void _ncbafly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892C8: syscall     771
    recomp_syscall_handler(rdram, ctx, 0x800892C8);
    return;
    // 0x800892CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void idtwinkle_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080070C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800714: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800718: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080071C: jal         0x800D8FF8
    // 0x80800720: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800720: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800724: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800728: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080072C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80800730: lwc1        $f2, 0x1C($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80800734: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800738: nop

    // 0x8080073C: bc1fl       L_8080077C
    if (!c1cs) {
        // 0x80800740: lh          $a1, 0x28($a3)
        ctx->r5 = MEM_H(ctx->r7, 0X28);
            goto L_8080077C;
    }
    goto skip_0;
    // 0x80800740: lh          $a1, 0x28($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X28);
    skip_0:
    // 0x80800744: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800748: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080074C: swc1        $f4, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f4.u32l;
    // 0x80800750: lwc1        $f6, 0x1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80800754: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800758: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8080075C: nop

    // 0x80800760: bc1fl       L_808008B8
    if (!c1cs) {
        // 0x80800764: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008B8;
    }
    goto skip_1;
    // 0x80800764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800768: jal         0x80800478
    // 0x8080076C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_80800478_idtwinkle(rdram, ctx);
        goto after_1;
    // 0x8080076C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800770: b           L_808008B8
    // 0x80800774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008B8;
    // 0x80800774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800778: lh          $a1, 0x28($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X28);
L_8080077C:
    // 0x8080077C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800780: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800784: blez        $a1, L_8080086C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80800788: nop
    
            goto L_8080086C;
    }
    // 0x80800788: nop

    // 0x8080078C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800790: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800794: lw          $t6, 0x2C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X2C);
L_80800798:
    // 0x80800798: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x8080079C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808007A0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x808007A4: nop

    // 0x808007A8: bc1fl       L_808007C8
    if (!c1cs) {
        // 0x808007AC: lbu         $t7, 0xE($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0XE);
            goto L_808007C8;
    }
    goto skip_2;
    // 0x808007AC: lbu         $t7, 0xE($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XE);
    skip_2:
    // 0x808007B0: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x808007B4: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x808007B8: lh          $a1, 0x28($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X28);
    // 0x808007BC: b           L_8080085C
    // 0x808007C0: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
        goto L_8080085C;
    // 0x808007C0: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x808007C4: lbu         $t7, 0xE($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XE);
L_808007C8:
    // 0x808007C8: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x808007CC: bnel        $t7, $zero, L_8080085C
    if (ctx->r15 != 0) {
        // 0x808007D0: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8080085C;
    }
    goto skip_3;
    // 0x808007D0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_3:
    // 0x808007D4: lb          $t8, 0xF($v0)
    ctx->r24 = MEM_B(ctx->r2, 0XF);
    // 0x808007D8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808007DC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808007E0: nop

    // 0x808007E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808007E8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808007EC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x808007F0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x808007F4: lw          $t9, 0x2C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X2C);
    // 0x808007F8: addu        $v0, $t9, $a0
    ctx->r2 = ADD32(ctx->r25, ctx->r4);
    // 0x808007FC: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800800: c.le.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl <= ctx->f2.fl;
    // 0x80800804: nop

    // 0x80800808: bc1fl       L_80800830
    if (!c1cs) {
        // 0x8080080C: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_80800830;
    }
    goto skip_4;
    // 0x8080080C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_4:
    // 0x80800810: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
    // 0x80800814: lw          $t1, 0x2C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X2C);
    // 0x80800818: addu        $v0, $t1, $a0
    ctx->r2 = ADD32(ctx->r9, ctx->r4);
    // 0x8080081C: lb          $t2, 0xF($v0)
    ctx->r10 = MEM_B(ctx->r2, 0XF);
    // 0x80800820: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80800824: b           L_8080084C
    // 0x80800828: sb          $t3, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r11;
        goto L_8080084C;
    // 0x80800828: sb          $t3, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r11;
    // 0x8080082C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_80800830:
    // 0x80800830: nop

    // 0x80800834: bc1fl       L_80800850
    if (!c1cs) {
        // 0x80800838: lh          $a1, 0x28($a3)
        ctx->r5 = MEM_H(ctx->r7, 0X28);
            goto L_80800850;
    }
    goto skip_5;
    // 0x80800838: lh          $a1, 0x28($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X28);
    skip_5:
    // 0x8080083C: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80800840: lw          $t4, 0x2C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X2C);
    // 0x80800844: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80800848: sb          $a2, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r6;
L_8080084C:
    // 0x8080084C: lh          $a1, 0x28($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X28);
L_80800850:
    // 0x80800850: b           L_8080085C
    // 0x80800854: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
        goto L_8080085C;
    // 0x80800854: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x80800858: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8080085C:
    // 0x8080085C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80800860: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800864: bnel        $at, $zero, L_80800798
    if (ctx->r1 != 0) {
        // 0x80800868: lw          $t6, 0x2C($a3)
        ctx->r14 = MEM_W(ctx->r7, 0X2C);
            goto L_80800798;
    }
    goto skip_6;
    // 0x80800868: lw          $t6, 0x2C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X2C);
    skip_6:
L_8080086C:
    // 0x8080086C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800870: addiu       $a2, $a2, -0x7208
    ctx->r6 = ADD32(ctx->r6, -0X7208);
    // 0x80800874: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800878: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080087C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80800880: jal         0x80088660
    // 0x80800884: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800884: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80800888: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080088C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800890: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800894: lh          $t6, 0x28($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X28);
    // 0x80800898: bnel        $t0, $t6, L_808008B8
    if (ctx->r8 != ctx->r14) {
        // 0x8080089C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008B8;
    }
    goto skip_7;
    // 0x8080089C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x808008A0: lwc1        $f14, 0x20($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X20);
    // 0x808008A4: jal         0x800DC264
    // 0x808008A8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800DC264(rdram, ctx);
        goto after_3;
    // 0x808008A8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_3:
    // 0x808008AC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808008B0: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x808008B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008B8:
    // 0x808008B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008BC: jr          $ra
    // 0x808008C0: nop

    return;
    // 0x808008C0: nop

;}
RECOMP_FUNC void func_808000E0_chjamjarsdummy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000EC: jal         0x800D8FF8
    // 0x808000F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000F4: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808000F8: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x808000FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800100: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800104: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: bne         $t7, $at, L_8080011C
    if (ctx->r15 != ctx->r1) {
        // 0x80800110: swc1        $f6, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
            goto L_8080011C;
    }
    // 0x80800110: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80800114: jal         0x800872D0
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _chswappy_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_8080011C:
    // 0x8080011C: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80800120: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800124: srl         $t8, $v0, 4
    ctx->r24 = S32(U32(ctx->r2) >> 4);
    // 0x80800128: beql        $t8, $zero, L_80800154
    if (ctx->r24 == 0) {
        // 0x8080012C: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800154;
    }
    goto skip_0;
    // 0x8080012C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x80800130: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800134: beq         $t8, $at, L_808001A4
    if (ctx->r24 == ctx->r1) {
        // 0x80800138: addiu       $a0, $zero, 0x9F1
        ctx->r4 = ADD32(0, 0X9F1);
            goto L_808001A4;
    }
    // 0x80800138: addiu       $a0, $zero, 0x9F1
    ctx->r4 = ADD32(0, 0X9F1);
    // 0x8080013C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800140: beq         $t8, $at, L_808001E8
    if (ctx->r24 == ctx->r1) {
        // 0x80800144: lui         $a3, 0x437F
        ctx->r7 = S32(0X437F << 16);
            goto L_808001E8;
    }
    // 0x80800144: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800148: b           L_80800228
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800228;
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800150: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800154:
    // 0x80800154: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800158: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080015C: lw          $a2, 0x58($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X58);
    // 0x80800160: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800164: jal         0x800F10B4
    // 0x80800168: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800168: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8080016C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800178: jal         0x80089CD0
    // 0x8080017C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _subaddiefade_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x8080017C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_3:
    // 0x80800180: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
    // 0x8080018C: bnel        $at, $zero, L_80800228
    if (ctx->r1 != 0) {
        // 0x80800190: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800228;
    }
    goto skip_1;
    // 0x80800190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800194: jal         0x80800000
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_chjamjarsdummy(rdram, ctx);
        goto after_4;
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080019C: b           L_80800228
    // 0x808001A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800228;
    // 0x808001A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001A4:
    // 0x808001A4: jal         0x800DA9E4
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_5;
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808001AC: beql        $v0, $zero, L_808001C0
    if (ctx->r2 == 0) {
        // 0x808001B0: lwc1        $f16, 0x58($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
            goto L_808001C0;
    }
    goto skip_2;
    // 0x808001B0: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    skip_2:
    // 0x808001B4: jal         0x800FFAB0
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001BC: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
L_808001C0:
    // 0x808001C0: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808001CC: nop

    // 0x808001D0: bc1fl       L_80800228
    if (!c1cs) {
        // 0x808001D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800228;
    }
    goto skip_3;
    // 0x808001D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x808001D8: jal         0x80800000
    // 0x808001DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_chjamjarsdummy(rdram, ctx);
        goto after_7;
    // 0x808001DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808001E0: b           L_80800228
    // 0x808001E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800228;
    // 0x808001E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001E8:
    // 0x808001E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001EC: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808001F0: lw          $a2, 0x58($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X58);
    // 0x808001F4: jal         0x800F10B4
    // 0x808001F8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808001F8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_8:
    // 0x808001FC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800208: jal         0x80089CD0
    // 0x8080020C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _subaddiefade_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x8080020C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_9:
    // 0x80800210: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800214: bgtzl       $t2, L_80800228
    if (SIGNED(ctx->r10) > 0) {
        // 0x80800218: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800228;
    }
    goto skip_4;
    // 0x80800218: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8080021C: jal         0x800FFAB0
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800228:
    // 0x80800228: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080022C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

;}
RECOMP_FUNC void func_808021C0_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808021C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808021C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808021CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808021D0: lbu         $t6, 0x2D($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2D);
    // 0x808021D4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808021D8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808021DC: bne         $a2, $t6, L_80802208
    if (ctx->r6 != ctx->r14) {
        // 0x808021E0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80802208;
    }
    // 0x808021E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808021E4: beql        $a2, $at, L_80802280
    if (ctx->r6 == ctx->r1) {
        // 0x808021E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802280;
    }
    goto skip_0;
    // 0x808021E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808021EC: lbu         $a0, 0x2C($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X2C);
    // 0x808021F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808021F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808021F8: jal         0x800C4350
    // 0x808021FC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x808021FC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80802200: b           L_80802280
    // 0x80802204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802280;
    // 0x80802204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802208:
    // 0x80802208: beq         $a3, $zero, L_80802240
    if (ctx->r7 == 0) {
        // 0x8080220C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80802240;
    }
    // 0x8080220C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802210: beq         $a3, $at, L_80802240
    if (ctx->r7 == ctx->r1) {
        // 0x80802214: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802240;
    }
    // 0x80802214: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802218: beq         $a3, $at, L_80802240
    if (ctx->r7 == ctx->r1) {
        // 0x8080221C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80802240;
    }
    // 0x8080221C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802220: bnel        $a3, $at, L_8080227C
    if (ctx->r7 != ctx->r1) {
        // 0x80802224: sb          $a3, 0x2D($s0)
        MEM_B(0X2D, ctx->r16) = ctx->r7;
            goto L_8080227C;
    }
    goto skip_1;
    // 0x80802224: sb          $a3, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r7;
    skip_1:
    // 0x80802228: lbu         $a0, 0x2C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2C);
    // 0x8080222C: jal         0x800C2FDC
    // 0x80802230: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800C2FDC(rdram, ctx);
        goto after_1;
    // 0x80802230: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x80802234: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80802238: b           L_80802278
    // 0x8080223C: sb          $zero, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = 0;
        goto L_80802278;
    // 0x8080223C: sb          $zero, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = 0;
L_80802240:
    // 0x80802240: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80802244: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X465C) << 16);
    // 0x80802248: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080224C: lwc1        $f12, 0x465C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X465C));
    // 0x80802250: jal         0x800C4B64
    // 0x80802254: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800C4B64(rdram, ctx);
        goto after_2;
    // 0x80802254: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x80802258: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080225C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1692, 0X4648) << 16);
    // 0x80802260: addiu       $a2, $a2, 0x4648
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1692, 0X4648));
    // 0x80802264: lbu         $a0, 0x2C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2C);
    // 0x80802268: jal         0x800C4350
    // 0x8080226C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800C4350(rdram, ctx);
        goto after_3;
    // 0x8080226C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x80802270: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80802274: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
L_80802278:
    // 0x80802278: sb          $a3, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r7;
L_8080227C:
    // 0x8080227C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802280:
    // 0x80802280: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802288: jr          $ra
    // 0x8080228C: nop

    return;
    // 0x8080228C: nop

;}
RECOMP_FUNC void _bscrouch_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F70: syscall     36
    recomp_syscall_handler(rdram, ctx, 0x80082F70);
    return;
    // 0x80082F74: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bsjump_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832D0: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x800832D0);
    return;
    // 0x800832D4: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void _ncpod_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089508: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089508);
    return;
    // 0x8008950C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void suegg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3322, 0XE40) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xE40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3322, 0XE40));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xE40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3322, 0XE40));
;}
RECOMP_FUNC void _bskazstilt_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083678: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083678);
    return;
    // 0x8008367C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void glgamedata_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004BC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x808004C0: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    // 0x808004C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004C8:
    // 0x808004C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808004CC: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x808004D0: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x808004D4: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x808004D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808004DC: bne         $v0, $a0, L_808004C8
    if (ctx->r2 != ctx->r4) {
        // 0x808004E0: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_808004C8;
    }
    // 0x808004E0: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x808004E4: jr          $ra
    // 0x808004E8: nop

    return;
    // 0x808004E8: nop

    // 0x808004EC: nop

;}
RECOMP_FUNC void _chelectricfence_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862B0: syscall     301
    recomp_syscall_handler(rdram, ctx, 0x800862B0);
    return;
    // 0x800862B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801748_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801748: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080174C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801750: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801754: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801758: jal         0x8008CABC
    // 0x8080175C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080175C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80801760: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801764: jal         0x808004CC
    // 0x80801768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8080176C: jal         0x8009E710
    // 0x80801770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_2;
    // 0x80801770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80801774: addiu       $at, $zero, 0x143
    ctx->r1 = ADD32(0, 0X143);
    // 0x80801778: bne         $v0, $at, L_80801790
    if (ctx->r2 != ctx->r1) {
        // 0x8080177C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801790;
    }
    // 0x8080177C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801780: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801784: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801788: b           L_80801798
    // 0x8080178C: nop

        goto L_80801798;
    // 0x8080178C: nop

L_80801790:
    // 0x80801790: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(416, 0X1AE0) << 16);
    // 0x80801794: lwc1        $f0, 0x1AE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(416, 0X1AE0));
L_80801798:
    // 0x80801798: jal         0x8008AF24
    // 0x8080179C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x8080179C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x808017A0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808017A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808017AC: jal         0x8008B1C8
    // 0x808017B0: nop

    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x808017B0: nop

    after_4:
    // 0x808017B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017B8: jal         0x8008AED4
    // 0x808017BC: addiu       $a1, $zero, 0x1D2
    ctx->r5 = ADD32(0, 0X1D2);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x808017BC: addiu       $a1, $zero, 0x1D2
    ctx->r5 = ADD32(0, 0X1D2);
    after_5:
    // 0x808017C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017C4: jal         0x8008B1BC
    // 0x808017C8: lui         $a1, 0x4108
    ctx->r5 = S32(0X4108 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x808017C8: lui         $a1, 0x4108
    ctx->r5 = S32(0X4108 << 16);
    after_6:
    // 0x808017CC: lui         $a1, 0x3E05
    ctx->r5 = S32(0X3E05 << 16);
    // 0x808017D0: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    // 0x808017D4: jal         0x8008B24C
    // 0x808017D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x808017D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808017DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017E0: jal         0x8008B134
    // 0x808017E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x808017E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808017E8: jal         0x8008B064
    // 0x808017EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x808017EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808017F0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808017F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808017F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808017FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801800: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801804: jal         0x8009FFD8
    // 0x80801808: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x80801808: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_10:
    // 0x8080180C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801810: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80801814: jal         0x8009C99C
    // 0x80801818: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_11;
    // 0x80801818: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_11:
    // 0x8080181C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801820: jal         0x8009B9B0
    // 0x80801824: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80801824: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_12:
    // 0x80801828: jal         0x800909CC
    // 0x8080182C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800909CC(rdram, ctx);
        goto after_13;
    // 0x8080182C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80801830: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801834: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801838: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080183C: jr          $ra
    // 0x80801840: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801840: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80801244_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080124C: jal         0x8080064C
    // 0x80801250: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801250: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801254: jal         0x80801208
    // 0x80801258: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801208_bstrexlarge(rdram, ctx);
        goto after_1;
    // 0x80801258: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080125C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801264: jr          $ra
    // 0x80801268: nop

    return;
    // 0x80801268: nop

;}
RECOMP_FUNC void func_80800178_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080017C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800180: jal         0x8009EF1C
    // 0x80800184: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800184: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800188: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8080018C: jal         0x8009EF10
    // 0x80800190: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800190: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800194: bne         $v0, $zero, L_808001B0
    if (ctx->r2 != 0) {
        // 0x80800198: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_808001B0;
    }
    // 0x80800198: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8080019C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001A0: jal         0x8009B9B0
    // 0x808001A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808001A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808001A8: b           L_808001D0
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001D0;
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001B0:
    // 0x808001B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808001B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001B8: jal         0x800F1214
    // 0x808001BC: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x808001BC: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_3:
    // 0x808001C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001C4: jal         0x8009B9B0
    // 0x808001C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x808001C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808001CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001D0:
    // 0x808001D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001D4: jr          $ra
    // 0x808001D8: nop

    return;
    // 0x808001D8: nop

;}
RECOMP_FUNC void func_80800AC8_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800ACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AD0: jal         0x808001DC
    // 0x80800AD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001DC_bsswim(rdram, ctx);
        goto after_0;
    // 0x80800AD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AD8: jal         0x80082FE0
    // 0x80800ADC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800ADC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AE8: jr          $ra
    // 0x80800AEC: nop

    return;
    // 0x80800AEC: nop

;}
RECOMP_FUNC void func_80800000_chdinoroargrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800010: jal         0x8010A800
    // 0x80800014: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    func_8010A800(rdram, ctx);
        goto after_0;
    // 0x80800014: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void func_8080106C_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080106C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80801070: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80801074: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801078: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8080107C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80801080: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80801084: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80801088: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8080108C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80801090: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80801094: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80801098: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8080109C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808010A0: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x808010A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808010A8: andi        $t6, $a2, 0x1FF
    ctx->r14 = ctx->r6 & 0X1FF;
    // 0x808010AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808010B0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x808010B4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x808010B8: jal         0x80100074
    // 0x808010BC: addiu       $a2, $t7, 0x1C
    ctx->r6 = ADD32(ctx->r15, 0X1C);
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x808010BC: addiu       $a2, $t7, 0x1C
    ctx->r6 = ADD32(ctx->r15, 0X1C);
    after_0:
    // 0x808010C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808010C4: jal         0x80100094
    // 0x808010C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808010C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808010CC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x808010D0: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    // 0x808010D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808010D8: addiu       $s0, $v0, 0x1C
    ctx->r16 = ADD32(ctx->r2, 0X1C);
    // 0x808010DC: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x808010E0: beq         $t9, $zero, L_808011AC
    if (ctx->r25 == 0) {
        // 0x808010E4: lui         $at, 0xC248
        ctx->r1 = S32(0XC248 << 16);
            goto L_808011AC;
    }
    // 0x808010E4: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x808010E8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x808010EC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808010F0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808010F4: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x808010F8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808010FC: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80801100: addiu       $s3, $zero, 0x2C1
    ctx->r19 = ADD32(0, 0X2C1);
    // 0x80801104: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
L_80801108:
    // 0x80801108: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x8080110C: srl         $t2, $t1, 22
    ctx->r10 = S32(U32(ctx->r9) >> 22);
    // 0x80801110: bnel        $s3, $t2, L_80801164
    if (ctx->r19 != ctx->r10) {
        // 0x80801114: mfc1        $a1, $f28
        ctx->r5 = (int32_t)ctx->f28.u32l;
            goto L_80801164;
    }
    goto skip_0;
    // 0x80801114: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    skip_0:
    // 0x80801118: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8080111C: jal         0x800DC178
    // 0x80801120: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801120: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_2:
    // 0x80801124: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801128: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8080112C: jal         0x800DC178
    // 0x80801130: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80801130: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_3:
    // 0x80801134: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80801138: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8080113C: jal         0x800DC178
    // 0x80801140: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801140: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_4:
    // 0x80801144: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801148: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8080114C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801150: jal         0x800EFA4C
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801158: b           L_80801174
    // 0x8080115C: nop

        goto L_80801174;
    // 0x8080115C: nop

    // 0x80801160: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
L_80801164:
    // 0x80801164: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x80801168: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8080116C: jal         0x800EFA4C
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80801174:
    // 0x80801174: jal         0x800EFD24
    // 0x80801178: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_800EFD24(rdram, ctx);
        goto after_7;
    // 0x80801178: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_7:
    // 0x8080117C: jal         0x800EFD24
    // 0x80801180: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_8;
    // 0x80801180: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_8:
    // 0x80801184: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801188: jal         0x80800DD0
    // 0x8080118C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800DD0_chpiranha(rdram, ctx);
        goto after_9;
    // 0x8080118C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80801190: lw          $t3, 0x6C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X6C);
    // 0x80801194: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801198: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x8080119C: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x808011A0: sltu        $at, $s1, $t4
    ctx->r1 = ctx->r17 < ctx->r12 ? 1 : 0;
    // 0x808011A4: bnel        $at, $zero, L_80801108
    if (ctx->r1 != 0) {
        // 0x808011A8: lw          $t0, 0x0($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X0);
            goto L_80801108;
    }
    goto skip_1;
    // 0x808011A8: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    skip_1:
L_808011AC:
    // 0x808011AC: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x808011B0: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x808011B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808011B8: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x808011BC: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x808011C0: jal         0x800EFA4C
    // 0x808011C4: nop

    func_800EFA4C(rdram, ctx);
        goto after_10;
    // 0x808011C4: nop

    after_10:
    // 0x808011C8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x808011CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808011D0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x808011D4: jal         0x80800EFC
    // 0x808011D8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80800EFC_chpiranha(rdram, ctx);
        goto after_11;
    // 0x808011D8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_11:
    // 0x808011DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x808011E0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808011E4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808011E8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x808011EC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x808011F0: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x808011F4: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x808011F8: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x808011FC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80801200: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80801204: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80801208: jr          $ra
    // 0x8080120C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8080120C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_801111D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801111D0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801111D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801111D8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801111DC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x801111E0: jal         0x801107F0
    // 0x801111E4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x801111E4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x801111E8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x801111EC: jal         0x80112550
    // 0x801111F0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80112550(rdram, ctx);
        goto after_1;
    // 0x801111F0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x801111F4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x801111F8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x801111FC: jal         0x800EFB24
    // 0x80111200: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80111200: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80111204: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80111208: jal         0x800F1EA4
    // 0x8011120C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F1EA4(rdram, ctx);
        goto after_3;
    // 0x8011120C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80111210: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80111214: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80111218: jal         0x800136E4
    // 0x8011121C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x8011121C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_4:
    // 0x80111220: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80111224: jal         0x80112E84
    // 0x80111228: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80112E84(rdram, ctx);
        goto after_5;
    // 0x80111228: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_5:
    // 0x8011122C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80111230: beq         $v0, $at, L_80111280
    if (ctx->r2 == ctx->r1) {
        // 0x80111234: lwc1        $f8, 0x5C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_80111280;
    }
    // 0x80111234: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80111238: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8011123C: lwc1        $f10, 0x6540($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6540);
    // 0x80111240: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80111244: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80111248: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8011124C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80111250: jal         0x800EF934
    // 0x80111254: nop

    func_800EF934(rdram, ctx);
        goto after_6;
    // 0x80111254: nop

    after_6:
    // 0x80111258: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8011125C: jal         0x800EF04C
    // 0x80111260: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80111260: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80111264: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80111268: jal         0x8011349C
    // 0x8011126C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8011349C(rdram, ctx);
        goto after_8;
    // 0x8011126C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_8:
    // 0x80111270: bnel        $v0, $zero, L_80111284
    if (ctx->r2 != 0) {
        // 0x80111274: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80111284;
    }
    goto skip_0;
    // 0x80111274: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    skip_0:
    // 0x80111278: b           L_801112A0
    // 0x8011127C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801112A0;
    // 0x8011127C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80111280:
    // 0x80111280: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_80111284:
    // 0x80111284: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80111288: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8011128C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80111290: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    // 0x80111294: jal         0x80112D90
    // 0x80111298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80112D90(rdram, ctx);
        goto after_9;
    // 0x80111298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x8011129C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801112A0:
    // 0x801112A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801112A4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801112A8: jr          $ra
    // 0x801112AC: nop

    return;
    // 0x801112AC: nop

;}
RECOMP_FUNC void func_8010A40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A40C: lh          $t6, 0x92($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X92);
    // 0x8010A410: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8010A414: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010A418: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010A41C: nop

    // 0x8010A420: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010A424: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010A428: jr          $ra
    // 0x8010A42C: nop

    return;
    // 0x8010A42C: nop

;}
RECOMP_FUNC void func_8010A85C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A85C: lbu         $t8, 0x77($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X77);
    // 0x8010A860: andi        $t7, $a1, 0xF
    ctx->r15 = ctx->r5 & 0XF;
    // 0x8010A864: andi        $t9, $t8, 0xFFF0
    ctx->r25 = ctx->r24 & 0XFFF0;
    // 0x8010A868: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8010A86C: jr          $ra
    // 0x8010A870: sb          $t0, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r8;
    return;
    // 0x8010A870: sb          $t0, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void _chpowerhut_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086038: syscall     274
    recomp_syscall_handler(rdram, ctx, 0x80086038);
    return;
    // 0x8008603C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80804EFC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804EFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80804F00: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80804F04: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80804F08: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80804F0C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80804F10: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80804F14: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80804F18: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80804F1C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80804F20: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80804F24: jal         0x80100094
    // 0x80804F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804F2C: lui         $s1, 0x8081
    ctx->r17 = S32(RELOC_HI16(1480, 0XA060) << 16);
    // 0x80804F30: addiu       $s1, $s1, -0x5FA0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1480, 0XA060));
    // 0x80804F34: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80804F38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80804F3C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_80804F40:
    // 0x80804F40: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80804F44: jal         0x800DF744
    // 0x80804F48: lh          $a1, 0x36($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X36);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80804F48: lh          $a1, 0x36($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X36);
    after_1:
    // 0x80804F4C: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x80804F50: slti        $at, $s2, 0x70
    ctx->r1 = SIGNED(ctx->r18) < 0X70 ? 1 : 0;
    // 0x80804F54: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80804F58: bne         $at, $zero, L_80804F40
    if (ctx->r1 != 0) {
        // 0x80804F5C: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_80804F40;
    }
    // 0x80804F5C: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80804F60: jal         0x800DF830
    // 0x80804F64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_2;
    // 0x80804F64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80804F68: jal         0x800D674C
    // 0x80804F6C: addiu       $a0, $zero, 0x955
    ctx->r4 = ADD32(0, 0X955);
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x80804F6C: addiu       $a0, $zero, 0x955
    ctx->r4 = ADD32(0, 0X955);
    after_3:
    // 0x80804F70: lw          $a3, 0x38($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X38);
    // 0x80804F74: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80804F78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80804F7C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80804F80: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    // 0x80804F84: jal         0x800DE498
    // 0x80804F88: addiu       $a2, $s4, 0x44
    ctx->r6 = ADD32(ctx->r20, 0X44);
    func_800DE498(rdram, ctx);
        goto after_4;
    // 0x80804F88: addiu       $a2, $s4, 0x44
    ctx->r6 = ADD32(ctx->r20, 0X44);
    after_4:
    // 0x80804F8C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80804F90: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80804F94: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80804F98:
    // 0x80804F98: lh          $t6, 0x34($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X34);
    // 0x80804F9C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80804FA0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80804FA4: beql        $t6, $zero, L_80804FB8
    if (ctx->r14 == 0) {
        // 0x80804FA8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80804FB8;
    }
    goto skip_0;
    // 0x80804FA8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x80804FAC: jal         0x80804FE4
    // 0x80804FB0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80804FE4_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80804FB0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x80804FB4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80804FB8:
    // 0x80804FB8: bne         $s3, $s1, L_80804F98
    if (ctx->r19 != ctx->r17) {
        // 0x80804FBC: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_80804F98;
    }
    // 0x80804FBC: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80804FC0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80804FC4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80804FC8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80804FCC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80804FD0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80804FD4: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80804FD8: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80804FDC: jr          $ra
    // 0x80804FE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80804FE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bsjump_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801084: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080108C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801090: jal         0x8009E704
    // 0x80801094: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x80801094: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801098: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8080109C: beq         $v0, $at, L_808010B8
    if (ctx->r2 == ctx->r1) {
        // 0x808010A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010B8;
    }
    // 0x808010A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010A4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x808010A8: beq         $v0, $at, L_808010B8
    if (ctx->r2 == ctx->r1) {
        // 0x808010AC: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_808010B8;
    }
    // 0x808010AC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808010B0: bne         $v0, $at, L_808010C0
    if (ctx->r2 != ctx->r1) {
        // 0x808010B4: nop
    
            goto L_808010C0;
    }
    // 0x808010B4: nop

L_808010B8:
    // 0x808010B8: jal         0x80095588
    // 0x808010BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80095588(rdram, ctx);
        goto after_1;
    // 0x808010BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_808010C0:
    // 0x808010C0: jal         0x800A042C
    // 0x808010C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A042C(rdram, ctx);
        goto after_2;
    // 0x808010C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010CC: jal         0x80093360
    // 0x808010D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_3;
    // 0x808010D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808010D4: jal         0x8009E0DC
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E0DC(rdram, ctx);
        goto after_4;
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808010DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808010E8: jr          $ra
    // 0x808010EC: nop

    return;
    // 0x808010EC: nop

;}
RECOMP_FUNC void func_808007D4_scradar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_808007D4_scradar");
    // 0x808007D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808007D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007E4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808007E8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808007EC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808007F0: lbu         $a0, 0xD($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XD);
    // 0x808007F4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808007F8: jal         0x800F5A00
    // 0x808007FC: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x808007FC: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800800: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800804: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800808: jal         0x800EFB24
    // 0x8080080C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x8080080C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x80800810: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800814: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800818: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8080081C: nop

    // 0x80800820: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800824: jal         0x8002DCA0
    // 0x80800828: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80800828: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_2:
    // 0x8080082C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800830: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800834: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800838: jal         0x80013B70
    // 0x8080083C: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    func_80013B70(rdram, ctx);
        goto after_3;
    // 0x8080083C: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x80800840: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800844: jal         0x800136E4
    // 0x80800848: sub.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x80800848: sub.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f8.fl;
    after_4:
    // 0x8080084C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3126, 0XE24) << 16);
    // 0x80800850: lwc1        $f2, 0xE24($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3126, 0XE24));
    // 0x80800854: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800858: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3126, 0XE28) << 16);
    // 0x8080085C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80800860: nop

    // 0x80800864: bc1f        L_80800870
    if (!c1cs) {
        // 0x80800868: nop
    
            goto L_80800870;
    }
    // 0x80800868: nop

    // 0x8080086C: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_80800870:
    // 0x80800870: lwc1        $f10, 0xE28($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3126, 0XE28));
    // 0x80800874: mul.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80800878: jal         0x800137F4
    // 0x8080087C: nop

    func_800137F4(rdram, ctx);
        goto after_5;
    // 0x8080087C: nop

    after_5:
    // 0x80800880: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x80800884: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80800888: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8080088C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80800890: jal         0x80013788
    // 0x80800894: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    func_80013788(rdram, ctx);
        goto after_6;
    // 0x80800894: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    after_6:
    // 0x80800898: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8080089C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808008A0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808008A4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x808008A8: nop

    // 0x808008AC: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x808008B0: jal         0x80800768
    // 0x808008B4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_80800768_scradar(rdram, ctx);
        goto after_7;
    // 0x808008B4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_7:
    // 0x808008B8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x808008BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008C0: beq         $v1, $at, L_808008F4
    if (ctx->r3 == ctx->r1) {
        // 0x808008C4: sb          $v0, 0xC($s0)
        MEM_B(0XC, ctx->r16) = ctx->r2;
            goto L_808008F4;
    }
    // 0x808008C4: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x808008C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008CC: beq         $v1, $at, L_808008F4
    if (ctx->r3 == ctx->r1) {
        // 0x808008D0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808008F4;
    }
    // 0x808008D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808008D4: beq         $v1, $at, L_80800900
    if (ctx->r3 == ctx->r1) {
        // 0x808008D8: lwc1        $f16, 0x3C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80800900;
    }
    // 0x808008D8: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808008DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808008E0: beq         $v1, $at, L_80800900
    if (ctx->r3 == ctx->r1) {
        // 0x808008E4: nop
    
            goto L_80800900;
    }
    // 0x808008E4: nop

    // 0x808008E8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808008EC: b           L_80800924
    // 0x808008F0: swc1        $f12, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f12.u32l;
        goto L_80800924;
    // 0x808008F0: swc1        $f12, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f12.u32l;
L_808008F4:
    // 0x808008F4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808008F8: b           L_80800924
    // 0x808008FC: swc1        $f12, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f12.u32l;
        goto L_80800924;
    // 0x808008FC: swc1        $f12, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f12.u32l;
L_80800900:
    // 0x80800900: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3126, 0XE2C) << 16);
    // 0x80800904: lwc1        $f18, 0xE2C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3126, 0XE2C));
    // 0x80800908: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080090C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800910: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800914: jal         0x800F0DC0
    // 0x80800918: nop

    func_800F0DC0(rdram, ctx);
        goto after_8;
    // 0x80800918: nop

    after_8:
    // 0x8080091C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800920: swc1        $f12, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f12.u32l;
L_80800924:
    // 0x80800924: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800928: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080092C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800930: jr          $ra
    // 0x80800934: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800934: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _sujiggy_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A700: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A700);
    return;
    // 0x8008A704: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
