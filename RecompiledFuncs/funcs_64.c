#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800594_chflamer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800594: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800598: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080059C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A0: bne         $a1, $at, L_808005E4
    if (ctx->r5 != ctx->r1) {
        // 0x808005A4: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808005E4;
    }
    // 0x808005A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808005A8: jal         0x80100094
    // 0x808005AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808005B4: jal         0x8008A038
    // 0x808005B8: addiu       $a0, $v0, 0x1B4
    ctx->r4 = ADD32(ctx->r2, 0X1B4);
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808005B8: addiu       $a0, $v0, 0x1B4
    ctx->r4 = ADD32(ctx->r2, 0X1B4);
    after_1:
    // 0x808005BC: jal         0x800BF8E4
    // 0x808005C0: nop

    func_800BF8E4(rdram, ctx);
        goto after_2;
    // 0x808005C0: nop

    after_2:
    // 0x808005C4: blezl       $v0, L_808005F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808005C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808005F0;
    }
    goto skip_0;
    // 0x808005C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808005CC: jal         0x800C8A98
    // 0x808005D0: nop

    func_800C8A98(rdram, ctx);
        goto after_3;
    // 0x808005D0: nop

    after_3:
    // 0x808005D4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x808005DC: b           L_808005EC
    // 0x808005E0: sb          $zero, 0x14($v1)
    MEM_B(0X14, ctx->r3) = 0;
        goto L_808005EC;
    // 0x808005E0: sb          $zero, 0x14($v1)
    MEM_B(0X14, ctx->r3) = 0;
L_808005E4:
    // 0x808005E4: b           L_808005F0
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F0;
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005EC:
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F0:
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005F8: jr          $ra
    // 0x808005FC: nop

    return;
    // 0x808005FC: nop

;}
RECOMP_FUNC void func_808002DC_bsbbilldrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002E0: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x808002E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808002EC: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x808002F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002F4: beq         $at, $zero, L_808005AC
    if (ctx->r1 == 0) {
        // 0x808002F8: sb          $a1, 0x15C($a0)
        MEM_B(0X15C, ctx->r4) = ctx->r5;
            goto L_808005AC;
    }
    // 0x808002F8: sb          $a1, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = ctx->r5;
    // 0x808002FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800300: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(61, 0XA70) << 16);
    // 0x80800304: addu        $at, $at, $t6
    gpr jr_addend_8080030C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800308: lw          $t6, 0xA70($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(61, 0XA70));
    // 0x8080030C: jr          $t6
    // 0x80800310: nop

    switch (jr_addend_8080030C >> 2) {
        case 0: goto L_80800314; break;
        case 1: goto L_80800390; break;
        case 2: goto L_808003C4; break;
        case 3: goto L_80800430; break;
        case 4: goto L_80800540; break;
        default: switch_error(__func__, 0x8080030C, 0x80800A70);
    }
    // 0x80800310: nop

L_80800314:
    // 0x80800314: jal         0x8009C984
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_0;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080031C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800320: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080032C: jal         0x80098520
    // 0x80800330: swc1        $f2, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f2.u32l;
    func_80098520(rdram, ctx);
        goto after_1;
    // 0x80800330: swc1        $f2, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f2.u32l;
    after_1:
    // 0x80800334: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800338: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x80085338
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_2;
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800348: jal         0x8009EA2C
    // 0x8080034C: nop

    func_8009EA2C(rdram, ctx);
        goto after_3;
    // 0x8080034C: nop

    after_3:
    // 0x80800350: beq         $v0, $zero, L_80800374
    if (ctx->r2 == 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800374;
    }
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(61, 0XB30) << 16);
    // 0x8080035C: addiu       $a2, $a2, 0xB30
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(61, 0XB30));
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x8009D454
    // 0x80800368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D454(rdram, ctx);
        goto after_4;
    // 0x80800368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080036C: b           L_80800388
    // 0x80800370: sb          $v0, 0x164($s0)
    MEM_B(0X164, ctx->r16) = ctx->r2;
        goto L_80800388;
    // 0x80800370: sb          $v0, 0x164($s0)
    MEM_B(0X164, ctx->r16) = ctx->r2;
L_80800374:
    // 0x80800374: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(61, 0XB10) << 16);
    // 0x80800378: addiu       $a2, $a2, 0xB10
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(61, 0XB10));
    // 0x8080037C: jal         0x8009D454
    // 0x80800380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D454(rdram, ctx);
        goto after_5;
    // 0x80800380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800384: sb          $v0, 0x164($s0)
    MEM_B(0X164, ctx->r16) = ctx->r2;
L_80800388:
    // 0x80800388: b           L_808005AC
    // 0x8080038C: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
        goto L_808005AC;
    // 0x8080038C: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
L_80800390:
    // 0x80800390: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(61, 0XA84) << 16);
    // 0x80800394: lwc1        $f4, 0xA84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(61, 0XA84));
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808003A0: jal         0x80098520
    // 0x808003A4: swc1        $f4, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f4.u32l;
    func_80098520(rdram, ctx);
        goto after_6;
    // 0x808003A4: swc1        $f4, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f4.u32l;
    after_6:
    // 0x808003A8: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x808003AC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: jal         0x80085338
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_7;
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808003BC: b           L_808005B0
    // 0x808003C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808005B0;
    // 0x808003C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003C4:
    // 0x808003C4: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808003C8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: addiu       $a1, $zero, 0x442F
    ctx->r5 = ADD32(0, 0X442F);
    // 0x808003D4: jal         0x8009DF18
    // 0x808003D8: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    func_8009DF18(rdram, ctx);
        goto after_8;
    // 0x808003D8: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    after_8:
    // 0x808003DC: lui         $a1, 0xC59C
    ctx->r5 = S32(0XC59C << 16);
    // 0x808003E0: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x808003E4: jal         0x8009BCC4
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_9;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003EC: lui         $a1, 0xC69C
    ctx->r5 = S32(0XC69C << 16);
    // 0x808003F0: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x808003F4: jal         0x8009BCB4
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_10;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808003FC: lui         $a1, 0x450F
    ctx->r5 = S32(0X450F << 16);
    // 0x80800400: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x80800404: jal         0x8009BA58
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_11;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: jal         0x8009B9B0
    // 0x80800414: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80800414: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_12:
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800420: jal         0x8009E53C
    // 0x80800424: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    func_8009E53C(rdram, ctx);
        goto after_13;
    // 0x80800424: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    after_13:
    // 0x80800428: b           L_808005B0
    // 0x8080042C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808005B0;
    // 0x8080042C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800430:
    // 0x80800430: jal         0x800962D4
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800962D4(rdram, ctx);
        goto after_14;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800438: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080043C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800440: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800444: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800448: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8080044C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800450: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800454: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800458: jal         0x800EFA4C
    // 0x8080045C: nop

    func_800EFA4C(rdram, ctx);
        goto after_15;
    // 0x8080045C: nop

    after_15:
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800464: jal         0x8009C1F8
    // 0x80800468: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8009C1F8(rdram, ctx);
        goto after_16;
    // 0x80800468: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_16:
    // 0x8080046C: jal         0x800962D4
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800962D4(rdram, ctx);
        goto after_17;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800474: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800480: jal         0x80084A18
    // 0x80800484: nop

    _badust_entrypoint_10(rdram, ctx);
        goto after_18;
    // 0x80800484: nop

    after_18:
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: jal         0x80095760
    // 0x80800490: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    baflag_set(rdram, ctx);
        goto after_19;
    // 0x80800490: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_19:
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x8009BCB4
    // 0x8080049C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_20;
    // 0x8080049C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_20:
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x8009BA9C
    // 0x808004A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_21;
    // 0x808004A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x808004AC: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808004B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: jal         0x80085338
    // 0x808004BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_22;
    // 0x808004BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x808004C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(61, 0XA88) << 16);
    // 0x808004C4: lwc1        $f16, 0xA88($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(61, 0XA88));
    // 0x808004C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(61, 0XA8C) << 16);
    // 0x808004CC: lwc1        $f18, 0xA8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(61, 0XA8C));
    // 0x808004D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(61, 0XA90) << 16);
    // 0x808004D4: lwc1        $f4, 0xA90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(61, 0XA90));
    // 0x808004D8: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808004DC: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x808004E0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x808004E4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808004F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x808004F4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x808004F8: jal         0x800854A0
    // 0x808004FC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    _bamotor_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x808004FC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_23:
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800508: jal         0x80084FD0
    // 0x8080050C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bashake_entrypoint_1(rdram, ctx);
        goto after_24;
    // 0x8080050C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_24:
    // 0x80800510: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(61, 0XB50) << 16);
    // 0x80800514: addiu       $a2, $a2, 0xB50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(61, 0XB50));
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080051C: jal         0x8009D454
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D454(rdram, ctx);
        goto after_25;
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80800524: sb          $v0, 0x160($s0)
    MEM_B(0X160, ctx->r16) = ctx->r2;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: addiu       $a1, $zero, 0x40D
    ctx->r5 = ADD32(0, 0X40D);
    // 0x80800530: jal         0x8009DE38
    // 0x80800534: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_26;
    // 0x80800534: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_26:
    // 0x80800538: b           L_808005B0
    // 0x8080053C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808005B0;
    // 0x8080053C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800540:
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800548: jal         0x8009E53C
    // 0x8080054C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E53C(rdram, ctx);
        goto after_27;
    // 0x8080054C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_27:
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: jal         0x80095774
    // 0x80800558: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    baflag_clear(rdram, ctx);
        goto after_28;
    // 0x80800558: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_28:
    // 0x8080055C: jal         0x8009C984
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_29;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800564: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800568: jal         0x8009328C
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009328C(rdram, ctx);
        goto after_30;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800570: lui         $a1, 0x4436
    ctx->r5 = S32(0X4436 << 16);
    // 0x80800574: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800578: jal         0x8009BA58
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_31;
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: jal         0x8009BCB4
    // 0x80800588: lui         $a1, 0xC516
    ctx->r5 = S32(0XC516 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_32;
    // 0x80800588: lui         $a1, 0xC516
    ctx->r5 = S32(0XC516 << 16);
    after_32:
    // 0x8080058C: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
    // 0x80800590: lui         $a2, 0x4006
    ctx->r6 = S32(0X4006 << 16);
    // 0x80800594: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800598: ori         $a1, $a1, 0xDABA
    ctx->r5 = ctx->r5 | 0XDABA;
    // 0x8080059C: jal         0x8008CF1C
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_33;
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x808005A4: jal         0x808000C0
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C0_bsbbilldrill(rdram, ctx);
        goto after_34;
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
L_808005AC:
    // 0x808005AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808005B0:
    // 0x808005B0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808005B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808005B8: jr          $ra
    // 0x808005BC: nop

    return;
    // 0x808005BC: nop

;}
RECOMP_FUNC void func_8080003C_babackpack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080004C: jal         0x8008AD80
    // 0x80800050: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008AD80(rdram, ctx);
        goto after_0;
    // 0x80800050: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800054: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80800058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080005C: sw          $v0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r2;
    // 0x80800060: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80800064: jal         0x8008B1A0
    // 0x80800068: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_1;
    // 0x80800068: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    after_1:
    // 0x8080006C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80800070: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80800074: jal         0x8008AED4
    // 0x80800078: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800078: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    after_2:
    // 0x8080007C: jal         0x8008CAC8
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_3;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800084: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80800088: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080008C: jal         0x8008B10C
    // 0x80800090: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    func_8008B10C(rdram, ctx);
        goto after_4;
    // 0x80800090: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    after_4:
    // 0x80800094: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x80800098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080009C: jal         0x8008B134
    // 0x808000A0: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x808000A0: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    after_5:
    // 0x808000A4: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x808000A8: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808000AC: jal         0x8008B1BC
    // 0x808000B0: lw          $a0, 0x14($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X14);
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x808000B0: lw          $a0, 0x14($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X14);
    after_6:
    // 0x808000B4: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x808000B8: jal         0x8008B064
    // 0x808000BC: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x808000BC: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    after_7:
    // 0x808000C0: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x808000C4: jal         0x8008B304
    // 0x808000C8: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    func_8008B304(rdram, ctx);
        goto after_8;
    // 0x808000C8: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    after_8:
    // 0x808000CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void chfantasyathlete_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802DD8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2388, 0X31B4) << 16);
    // 0x80802DDC: jr          $ra
    // 0x80802DE0: addiu       $v0, $v0, 0x31B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2388, 0X31B4));
    return;
    // 0x80802DE0: addiu       $v0, $v0, 0x31B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2388, 0X31B4));
    // 0x80802DE4: nop

    // 0x80802DE8: nop

    // 0x80802DEC: nop

;}
RECOMP_FUNC void func_80800C64_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C70: jal         0x80100094
    // 0x80800C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C78: jal         0x8009EA64
    // 0x80800C7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8009EA64(rdram, ctx);
        goto after_1;
    // 0x80800C7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800C80: addiu       $at, $zero, 0x171
    ctx->r1 = ADD32(0, 0X171);
    // 0x80800C84: bne         $v0, $at, L_80800CB0
    if (ctx->r2 != ctx->r1) {
        // 0x80800C88: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CB0;
    }
    // 0x80800C88: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C8C: lbu         $t6, 0x100($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X100);
    // 0x80800C90: beql        $t6, $zero, L_80800CB4
    if (ctx->r14 == 0) {
        // 0x80800C94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800CB4;
    }
    goto skip_0;
    // 0x80800C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800C98: sb          $zero, 0x100($v1)
    MEM_B(0X100, ctx->r3) = 0;
    // 0x80800C9C: jal         0x80800C14
    // 0x80800CA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800C14_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x80800CA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800CA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800CA8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800CAC: swc1        $f4, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f4.u32l;
L_80800CB0:
    // 0x80800CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CB4:
    // 0x80800CB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CB8: jr          $ra
    // 0x80800CBC: nop

    return;
    // 0x80800CBC: nop

;}
RECOMP_FUNC void func_800C0534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_test_room_quiet()) { ctx->r2 = 0; return; }
    // 0x800C0534: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C0538: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C053C: lbu         $t6, -0x75D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X75D0);
    // 0x800C0540: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C0544: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C0548: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C054C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C0550: beq         $t6, $zero, L_800C05A0
    if (ctx->r14 == 0) {
        // 0x800C0554: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_800C05A0;
    }
    // 0x800C0554: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C0558: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800C055C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800C0560: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800C0564: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800C0568: lh          $t1, 0x4E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X4E);
    // 0x800C056C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0570: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    // 0x800C0574: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800C0578: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C057C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C0580: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C0584: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800C0588: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800C058C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800C0590: jal         0x80087E28
    // 0x800C0594: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    _gcdialogexec_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800C0594: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_0:
    // 0x800C0598: b           L_800C05A4
    // 0x800C059C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800C05A4;
    // 0x800C059C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800C05A0:
    // 0x800C05A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C05A4:
    // 0x800C05A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C05A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C05AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C05B0: jr          $ra
    // 0x800C05B4: nop

    return;
    // 0x800C05B4: nop

;}
RECOMP_FUNC void bawasher_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: jr          $ra
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80801B30_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801B34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801B38: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801B3C: jal         0x808001A8
    // 0x80801B40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x80801B40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801B44: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80801B48: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B50: jal         0x8008CCBC
    // 0x80801B54: addiu       $a1, $zero, 0x357
    ctx->r5 = ADD32(0, 0X357);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80801B54: addiu       $a1, $zero, 0x357
    ctx->r5 = ADD32(0, 0X357);
    after_1:
    // 0x80801B58: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801B5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801B68: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801B6C: jal         0x8009FFD8
    // 0x80801B70: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801B70: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80801B74: jal         0x808000BC
    // 0x80801B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000BC_bswasher(rdram, ctx);
        goto after_3;
    // 0x80801B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801B7C: jal         0x8009C984
    // 0x80801B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x80801B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801B84: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801B88: jal         0x8009C914
    // 0x80801B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_5;
    // 0x80801B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801B90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801B94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801B9C: jr          $ra
    // 0x80801BA0: nop

    return;
    // 0x80801BA0: nop

;}
RECOMP_FUNC void _ncba1p_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893D8: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x800893D8);
    return;
    // 0x800893DC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801CF8_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801CFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801D04: jal         0x80100094
    // 0x80801D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801D0C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1700, 0X25A0) << 16);
    // 0x80801D10: addiu       $t6, $t6, 0x25A0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1700, 0X25A0));
    // 0x80801D14: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801D18: addiu       $a0, $v0, 0x2C
    ctx->r4 = ADD32(ctx->r2, 0X2C);
    // 0x80801D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801D20: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801D24: jal         0x800BBCB8
    // 0x80801D28: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80801D28: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80801D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D34: jr          $ra
    // 0x80801D38: nop

    return;
    // 0x80801D38: nop

;}
RECOMP_FUNC void func_80802D50_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802D58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802D5C: lw          $a2, 0x188($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X188);
    // 0x80802D60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802D64: jal         0x80802C90
    // 0x80802D68: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80802C90_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80802D68: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802D6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802D70: beq         $v0, $zero, L_80802D80
    if (ctx->r2 == 0) {
        // 0x80802D74: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80802D80;
    }
    // 0x80802D74: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80802D78: b           L_80802D84
    // 0x80802D7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80802D84;
    // 0x80802D7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80802D80:
    // 0x80802D80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80802D84:
    // 0x80802D84: lh          $v0, 0xE2($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XE2);
    // 0x80802D88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802D8C: beq         $v0, $zero, L_80802DAC
    if (ctx->r2 == 0) {
        // 0x80802D90: nop
    
            goto L_80802DAC;
    }
    // 0x80802D90: nop

    // 0x80802D94: beq         $v0, $a1, L_80802DB4
    if (ctx->r2 == ctx->r5) {
        // 0x80802D98: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802DB4;
    }
    // 0x80802D98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802D9C: beq         $v0, $at, L_80802DDC
    if (ctx->r2 == ctx->r1) {
        // 0x80802DA0: nop
    
            goto L_80802DDC;
    }
    // 0x80802DA0: nop

    // 0x80802DA4: b           L_80802E30
    // 0x80802DA8: nop

        goto L_80802E30;
    // 0x80802DA8: nop

L_80802DAC:
    // 0x80802DAC: b           L_80802E6C
    // 0x80802DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802E6C;
    // 0x80802DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802DB4:
    // 0x80802DB4: bne         $v1, $zero, L_80802E30
    if (ctx->r3 != 0) {
        // 0x80802DB8: nop
    
            goto L_80802E30;
    }
    // 0x80802DB8: nop

    // 0x80802DBC: lh          $t6, 0xE6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XE6);
    // 0x80802DC0: sh          $zero, 0xE2($a2)
    MEM_H(0XE2, ctx->r6) = 0;
    // 0x80802DC4: bne         $t6, $zero, L_80802DD4
    if (ctx->r14 != 0) {
        // 0x80802DC8: nop
    
            goto L_80802DD4;
    }
    // 0x80802DC8: nop

    // 0x80802DCC: jal         0x80802C6C
    // 0x80802DD0: sh          $a1, 0xE6($a2)
    MEM_H(0XE6, ctx->r6) = ctx->r5;
    func_80802C6C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80802DD0: sh          $a1, 0xE6($a2)
    MEM_H(0XE6, ctx->r6) = ctx->r5;
    after_1:
L_80802DD4:
    // 0x80802DD4: b           L_80802E6C
    // 0x80802DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802E6C;
    // 0x80802DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802DDC:
    // 0x80802DDC: bne         $v1, $zero, L_80802E30
    if (ctx->r3 != 0) {
        // 0x80802DE0: nop
    
            goto L_80802E30;
    }
    // 0x80802DE0: nop

    // 0x80802DE4: lh          $v0, 0xE6($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XE6);
    // 0x80802DE8: sh          $zero, 0xE2($a2)
    MEM_H(0XE2, ctx->r6) = 0;
    // 0x80802DEC: beq         $v0, $zero, L_80802E04
    if (ctx->r2 == 0) {
        // 0x80802DF0: nop
    
            goto L_80802E04;
    }
    // 0x80802DF0: nop

    // 0x80802DF4: beq         $v0, $a1, L_80802E14
    if (ctx->r2 == ctx->r5) {
        // 0x80802DF8: nop
    
            goto L_80802E14;
    }
    // 0x80802DF8: nop

    // 0x80802DFC: b           L_80802E6C
    // 0x80802E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802E6C;
    // 0x80802E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802E04:
    // 0x80802E04: jal         0x80802C6C
    // 0x80802E08: sh          $a1, 0xE6($a2)
    MEM_H(0XE6, ctx->r6) = ctx->r5;
    func_80802C6C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80802E08: sh          $a1, 0xE6($a2)
    MEM_H(0XE6, ctx->r6) = ctx->r5;
    after_2:
    // 0x80802E0C: b           L_80802E6C
    // 0x80802E10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802E6C;
    // 0x80802E10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802E14:
    // 0x80802E14: jal         0x80802D14
    // 0x80802E18: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80802D14_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80802E18: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_3:
    // 0x80802E1C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80802E20: jal         0x80802E7C
    // 0x80802E24: sh          $v0, 0xE8($a0)
    MEM_H(0XE8, ctx->r4) = ctx->r2;
    func_80802E7C_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80802E24: sh          $v0, 0xE8($a0)
    MEM_H(0XE8, ctx->r4) = ctx->r2;
    after_4:
    // 0x80802E28: b           L_80802E6C
    // 0x80802E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802E6C;
    // 0x80802E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802E30:
    // 0x80802E30: jal         0x80802E7C
    // 0x80802E34: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80802E7C_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80802E34: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x80802E38: beq         $v0, $zero, L_80802E50
    if (ctx->r2 == 0) {
        // 0x80802E3C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80802E50;
    }
    // 0x80802E3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802E40: beq         $v0, $a1, L_80802E60
    if (ctx->r2 == ctx->r5) {
        // 0x80802E44: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80802E60;
    }
    // 0x80802E44: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80802E48: b           L_80802E6C
    // 0x80802E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802E6C;
    // 0x80802E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802E50:
    // 0x80802E50: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80802E54: addiu       $t7, $zero, 0xD8
    ctx->r15 = ADD32(0, 0XD8);
    // 0x80802E58: b           L_80802E68
    // 0x80802E5C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_80802E68;
    // 0x80802E5C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_80802E60:
    // 0x80802E60: addiu       $t9, $zero, 0xD6
    ctx->r25 = ADD32(0, 0XD6);
    // 0x80802E64: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80802E68:
    // 0x80802E68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802E6C:
    // 0x80802E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802E70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802E74: jr          $ra
    // 0x80802E78: nop

    return;
    // 0x80802E78: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BD0: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BD0);
    return;
    // 0x80087BD4: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void func_8010C3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C3A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010C3AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C3B0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8010C3B4: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8010C3B8: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8010C3BC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8010C3C0: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x8010C3C4: jal         0x8010B990
    // 0x8010C3C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8010B990(rdram, ctx);
        goto after_0;
    // 0x8010C3C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010C3CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8010C3D0: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8010C3D4: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8010C3D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C3DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010C3E0: jr          $ra
    // 0x8010C3E4: nop

    return;
    // 0x8010C3E4: nop

;}
RECOMP_FUNC void func_808000A8_chtntblockage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x808000AC: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x808000B0: jr          $ra
    // 0x808000B4: addiu       $v0, $t6, 0x4C
    ctx->r2 = ADD32(ctx->r14, 0X4C);
    return;
    // 0x808000B4: addiu       $v0, $t6, 0x4C
    ctx->r2 = ADD32(ctx->r14, 0X4C);
;}
RECOMP_FUNC void _chlakemonster_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CD0: syscall     444
    recomp_syscall_handler(rdram, ctx, 0x80086CD0);
    return;
    // 0x80086CD4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chmonsterinterior_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086560: syscall     336
    recomp_syscall_handler(rdram, ctx, 0x80086560);
    return;
    // 0x80086564: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800000_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x8009E69C
    // 0x80800014: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_8009E69C(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_0:
    // 0x80800018: bnel        $v0, $zero, L_80800080
    if (ctx->r2 != 0) {
        // 0x8080001C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800080;
    }
    goto skip_0;
    // 0x8080001C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800020: jal         0x8009BC6C
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800028: jal         0x8009BC90
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: jal         0x80093360
    // 0x80800038: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_3;
    // 0x80800038: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080003C: jal         0x800A042C
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A042C(rdram, ctx);
        goto after_4;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: jal         0x8009C908
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_5;
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800050: jal         0x80095A40
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_6;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: jal         0x800961AC
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_7;
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800064: jal         0x800A4E30
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_8;
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080006C: jal         0x80084BE8
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800074: jal         0x800832E8
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800080:
    // 0x80800080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_80116120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116120: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80116124: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80116128: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8011612C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80116130: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80116134: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80116138: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8011613C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80116140: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80116144: jal         0x800F2388
    // 0x80116148: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800F2388(rdram, ctx);
        goto after_0;
    // 0x80116148: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x8011614C: jal         0x800F22EC
    // 0x80116150: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800F22EC(rdram, ctx);
        goto after_1;
    // 0x80116150: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x80116154: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80116158: lwc1        $f4, 0x6624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6624);
    // 0x8011615C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80116160: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80116164: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80116168: nop

    // 0x8011616C: bc1fl       L_801161FC
    if (!c1cs) {
        // 0x80116170: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_801161FC;
    }
    goto skip_0;
    // 0x80116170: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_0:
    // 0x80116174: jal         0x800D8FF8
    // 0x80116178: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80116178: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x8011617C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80116180: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80116184: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80116188: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8011618C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80116190: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80116194: jal         0x800FF060
    // 0x80116198: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800FF060(rdram, ctx);
        goto after_3;
    // 0x80116198: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8011619C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801161A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801161A4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x801161A8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801161AC: nop

    // 0x801161B0: bc1fl       L_801161CC
    if (!c1cs) {
        // 0x801161B4: div.s       $f2, $f0, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
            goto L_801161CC;
    }
    goto skip_1;
    // 0x801161B4: div.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    skip_1:
    // 0x801161B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801161BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801161C0: b           L_801161CC
    // 0x801161C4: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
        goto L_801161CC;
    // 0x801161C4: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x801161C8: div.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
L_801161CC:
    // 0x801161CC: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801161D0: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801161D4: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801161D8: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801161DC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801161E0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x801161E4: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801161E8: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801161EC: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801161F0: b           L_80116204
    // 0x801161F4: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
        goto L_80116204;
    // 0x801161F4: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x801161F8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_801161FC:
    // 0x801161FC: nop

    // 0x80116200: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
L_80116204:
    // 0x80116204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80116208: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8011620C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80116210: jr          $ra
    // 0x80116214: nop

    return;
    // 0x80116214: nop

;}
RECOMP_FUNC void _bskazmove_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834B0: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x800834B0);
    return;
    // 0x800834B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800995B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_800995B8");
    // 0x800995B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800995BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800995C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800995C4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800995C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800995CC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x800995D0: jal         0x800A34CC
    // 0x800995D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A34CC(rdram, ctx);
        goto after_0;
    // 0x800995D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800995D8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800995DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800995E0: beql        $a2, $zero, L_8009960C
    if (ctx->r6 == 0) {
        // 0x800995E4: lw          $t6, 0xC0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0XC0);
            goto L_8009960C;
    }
    goto skip_0;
    // 0x800995E4: lw          $t6, 0xC0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC0);
    skip_0:
    // 0x800995E8: beq         $a2, $at, L_8009962C
    if (ctx->r6 == ctx->r1) {
        // 0x800995EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8009962C;
    }
    // 0x800995EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800995F0: beq         $a2, $at, L_80099644
    if (ctx->r6 == ctx->r1) {
        // 0x800995F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80099644;
    }
    // 0x800995F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800995F8: beql        $a2, $at, L_800996C0
    if (ctx->r6 == ctx->r1) {
        // 0x800995FC: lw          $a1, 0xC0($s0)
        ctx->r5 = MEM_W(ctx->r16, 0XC0);
            goto L_800996C0;
    }
    goto skip_1;
    // 0x800995FC: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    skip_1:
    // 0x80099600: b           L_800996D0
    // 0x80099604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800996D0;
    // 0x80099604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80099608: lw          $t6, 0xC0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC0);
L_8009960C:
    // 0x8009960C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80099610: jal         0x800EC398
    // 0x80099614: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    func_800EC398(rdram, ctx);
        goto after_1;
    // 0x80099614: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    after_1:
    // 0x80099618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009961C: jal         0x800A34AC
    // 0x80099620: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800A34AC(rdram, ctx);
        goto after_2;
    // 0x80099620: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80099624: b           L_800996D0
    // 0x80099628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800996D0;
    // 0x80099628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009962C:
    // 0x8009962C: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x80099630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099634: jal         0x800A34AC
    // 0x80099638: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800A34AC(rdram, ctx);
        goto after_3;
    // 0x80099638: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_3:
    // 0x8009963C: b           L_800996D0
    // 0x80099640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800996D0;
    // 0x80099640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80099644:
    // 0x80099644: jal         0x8008FE68
    // 0x80099648: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008FE68(rdram, ctx);
        goto after_4;
    // 0x80099648: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x8009964C: jal         0x80090010
    // 0x80099650: nop

    func_80090010(rdram, ctx);
        goto after_5;
    // 0x80099650: nop

    after_5:
    // 0x80099654: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80099658: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8009965C: jal         0x800EFCD8
    // 0x80099660: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_800EFCD8(rdram, ctx);
        goto after_6;
    // 0x80099660: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_6:
    // 0x80099664: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80099668: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8009966C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80099670: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80099674: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80099678: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009967C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80099680: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80099684: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80099688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009968C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80099690: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80099694: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80099698: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8009969C: jal         0x800A34AC
    // 0x800996A0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    func_800A34AC(rdram, ctx);
        goto after_7;
    // 0x800996A0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x800996A4: lw          $t7, 0xC0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC0);
    // 0x800996A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800996AC: jal         0x800A34CC
    // 0x800996B0: lw          $a1, 0x1C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X1C);
    func_800A34CC(rdram, ctx);
        goto after_8;
    // 0x800996B0: lw          $a1, 0x1C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X1C);
    after_8:
    // 0x800996B4: b           L_800996D0
    // 0x800996B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800996D0;
    // 0x800996B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800996BC: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
L_800996C0:
    // 0x800996C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800996C4: jal         0x800A34AC
    // 0x800996C8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800A34AC(rdram, ctx);
        goto after_9;
    // 0x800996C8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_9:
    // 0x800996CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800996D0:
    // 0x800996D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800996D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800996D8: jr          $ra
    // 0x800996DC: nop

    return;
    // 0x800996DC: nop

;}
RECOMP_FUNC void func_8001E418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E420: jal         0x8001D96C
    // 0x8001E424: nop

    func_8001D96C(rdram, ctx);
        goto after_0;
    // 0x8001E424: nop

    after_0:
    // 0x8001E428: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001E42C: jal         0x8001D37C
    // 0x8001E430: addiu       $a0, $a0, 0x18EC
    ctx->r4 = ADD32(ctx->r4, 0X18EC);
    func_8001D37C(rdram, ctx);
        goto after_1;
    // 0x8001E430: addiu       $a0, $a0, 0x18EC
    ctx->r4 = ADD32(ctx->r4, 0X18EC);
    after_1:
    // 0x8001E434: jal         0x8001E2A0
    // 0x8001E438: nop

    func_8001E2A0(rdram, ctx);
        goto after_2;
    // 0x8001E438: nop

    after_2:
    // 0x8001E43C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E444: jr          $ra
    // 0x8001E448: nop

    return;
    // 0x8001E448: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084380: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084380);
    return;
    // 0x80084384: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void chtntdetonator_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(904, 0X6A8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x6A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(904, 0X6A8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x6A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(904, 0X6A8));
;}
RECOMP_FUNC void _gcdialogexec_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E58: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E58);
    return;
    // 0x80087E5C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840C0: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x800840C0);
    return;
    // 0x800840C4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800154_changlerbossflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800154: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800158: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080015C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800160: bne         $a1, $at, L_80800178
    if (ctx->r5 != ctx->r1) {
        // 0x80800164: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800178;
    }
    // 0x80800164: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800168: jal         0x80800190
    // 0x8080016C: nop

    func_80800190_changlerbossflare(rdram, ctx);
        goto after_0;
    // 0x8080016C: nop

    after_0:
    // 0x80800170: b           L_80800180
    // 0x80800174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800180;
    // 0x80800174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800178:
    // 0x80800178: b           L_80800180
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800180;
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800180:
    // 0x80800180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080102C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801030: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801038: jal         0x80800BF0
    // 0x8080103C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bafpctrl_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080103C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801040: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801044: bne         $v0, $at, L_8080107C
    if (ctx->r2 != ctx->r1) {
        // 0x80801048: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080107C;
    }
    // 0x80801048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080104C: jal         0x80800D38
    // 0x80801050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bafpctrl_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80801050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801058: jal         0x800A3544
    // 0x8080105C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A3544(rdram, ctx);
        goto after_2;
    // 0x8080105C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801064: jal         0x8009337C
    // 0x80801068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009337C(rdram, ctx);
        goto after_3;
    // 0x80801068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080106C: jal         0x800A4EC8
    // 0x80801070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4EC8(rdram, ctx);
        goto after_4;
    // 0x80801070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801074: jal         0x800878B8
    // 0x80801078: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    _plcamera_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80801078: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_5:
L_8080107C:
    // 0x8080107C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801088: jr          $ra
    // 0x8080108C: nop

    return;
    // 0x8080108C: nop

;}
RECOMP_FUNC void func_80800098_bskazow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080009C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808000A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808000B0: jal         0x8008CB10
    // 0x808000B4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x808000B4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_0:
    // 0x808000B8: beq         $v0, $zero, L_808000C8
    if (ctx->r2 == 0) {
        // 0x808000BC: nop
    
            goto L_808000C8;
    }
    // 0x808000BC: nop

    // 0x808000C0: jal         0x800951B4
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_808000C8:
    // 0x808000C8: jal         0x800845C8
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D0: beq         $v0, $zero, L_808000E0
    if (ctx->r2 == 0) {
        // 0x808000D4: nop
    
            goto L_808000E0;
    }
    // 0x808000D4: nop

    // 0x808000D8: jal         0x800834B0
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_808000E0:
    // 0x808000E0: jal         0x80084600
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000E8: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000EC: addiu       $t6, $zero, 0xBB
        ctx->r14 = ADD32(0, 0XBB);
            goto L_808000F4;
    }
    // 0x808000EC: addiu       $t6, $zero, 0xBB
    ctx->r14 = ADD32(0, 0XBB);
    // 0x808000F0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808000F4:
    // 0x808000F4: jal         0x8008E35C
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_5;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000FC: beql        $v0, $zero, L_8080012C
    if (ctx->r2 == 0) {
        // 0x80800100: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080012C;
    }
    goto skip_0;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800104: jal         0x8009BB50
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080010C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800110: addiu       $t7, $zero, 0x160
    ctx->r15 = ADD32(0, 0X160);
    // 0x80800114: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80800118: nop

    // 0x8080011C: bc1fl       L_8080012C
    if (!c1cs) {
        // 0x80800120: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080012C;
    }
    goto skip_1;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800124: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080012C:
    // 0x8080012C: jal         0x8009E5C8
    // 0x80800130: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80800130: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800138: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080013C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FA0: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087FA0);
    return;
    // 0x80087FA4: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_808001E0_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E8: jal         0x8080003C
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080003C_chprisonbits(rdram, ctx);
        goto after_0;
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080017C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800184: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80800188: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3354, 0X8E4) << 16);
    // 0x8080018C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800190: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80800194: jal         0x80800000
    // 0x80800198: lw          $a0, 0x8E4($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(3354, 0X8E4));
    func_80800000_sujiggy(rdram, ctx);
        goto after_0;
    // 0x80800198: lw          $a0, 0x8E4($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(3354, 0X8E4));
    after_0:
    // 0x8080019C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

;}
RECOMP_FUNC void func_8008D04C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D04C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008D050: jr          $ra
    // 0x8008D054: lw          $v0, 0x3C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X3C);
    return;
    // 0x8008D054: lw          $v0, 0x3C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X3C);
;}
RECOMP_FUNC void func_808008AC_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808008B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808008BC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808008C0: jal         0x800B53A4
    // 0x808008C4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x808008C4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x808008C8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808008CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D4: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x808008D8: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    // 0x808008DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808008E0: jal         0x800C6920
    // 0x808008E4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_800C6920(rdram, ctx);
        goto after_1;
    // 0x808008E4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x808008E8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808008EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008F0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2412, 0X1404) << 16);
    // 0x808008F4: addiu       $t6, $t6, 0x1404
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2412, 0X1404));
    // 0x808008F8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808008FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800900: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800904: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800908: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8080090C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800910: jal         0x800BABB8
    // 0x80800914: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800914: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80800918: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080091C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800920: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800924: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800928: nop

    // 0x8080092C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80800930: jal         0x800BA4D0
    // 0x80800934: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_3;
    // 0x80800934: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    after_3:
    // 0x80800938: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8080093C: addiu       $a1, $a1, 0x7700
    ctx->r5 = ADD32(ctx->r5, 0X7700);
    // 0x80800940: jal         0x800BA544
    // 0x80800944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BA544(rdram, ctx);
        goto after_4;
    // 0x80800944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80800948: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080094C: jal         0x800BA22C
    // 0x80800950: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x80800950: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x80800954: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800958: jal         0x8080086C
    // 0x8080095C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    choildrill_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x8080095C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800960: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800964: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x80800968: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080096C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800970: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800974: jr          $ra
    // 0x80800978: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800978: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _gcstatusDll_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088368: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088368);
    return;
    // 0x8008836C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _chfriesstand_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DB0: syscall     240
    recomp_syscall_handler(rdram, ctx, 0x80085DB0);
    return;
    // 0x80085DB4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsbanbflip_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082678: syscall     5
    recomp_syscall_handler(rdram, ctx, 0x80082678);
    return;
    // 0x8008267C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800946C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800946C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800946C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800946CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800946D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800946D4: beq         $a1, $zero, L_800946FC
    if (ctx->r5 == 0) {
        // 0x800946D8: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800946FC;
    }
    // 0x800946D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800946DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800946E0: beq         $a1, $at, L_80094744
    if (ctx->r5 == ctx->r1) {
        // 0x800946E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80094744;
    }
    // 0x800946E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800946E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800946EC: beq         $a1, $at, L_80094788
    if (ctx->r5 == ctx->r1) {
        // 0x800946F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80094788;
    }
    // 0x800946F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800946F4: b           L_800947C8
    // 0x800946F8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_800947C8;
    // 0x800946F8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_800946FC:
    // 0x800946FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80094704: jal         0x800947EC
    // 0x80094708: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_0;
    // 0x80094708: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8009470C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094710: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80094714: jal         0x800947EC
    // 0x80094718: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_1;
    // 0x80094718: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8009471C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094720: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80094724: jal         0x800947EC
    // 0x80094728: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_2;
    // 0x80094728: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8009472C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094730: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80094734: jal         0x800947EC
    // 0x80094738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_3;
    // 0x80094738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8009473C: b           L_800947C8
    // 0x80094740: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_800947C8;
    // 0x80094740: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80094744:
    // 0x80094744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80094748: jal         0x800947EC
    // 0x8009474C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_4;
    // 0x8009474C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80094750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094754: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80094758: jal         0x800947EC
    // 0x8009475C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_5;
    // 0x8009475C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80094760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094764: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80094768: jal         0x800947EC
    // 0x8009476C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_6;
    // 0x8009476C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80094770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094774: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80094778: jal         0x800947EC
    // 0x8009477C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_7;
    // 0x8009477C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80094780: b           L_800947C8
    // 0x80094784: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_800947C8;
    // 0x80094784: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80094788:
    // 0x80094788: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009478C: jal         0x800947EC
    // 0x80094790: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_8;
    // 0x80094790: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80094794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094798: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8009479C: jal         0x800947EC
    // 0x800947A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_9;
    // 0x800947A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x800947A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800947A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800947AC: jal         0x800947EC
    // 0x800947B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_10;
    // 0x800947B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x800947B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800947B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800947BC: jal         0x800947EC
    // 0x800947C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_11;
    // 0x800947C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x800947C4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_800947C8:
    // 0x800947C8: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x800947CC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800947D0: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x800947D4: sb          $zero, 0x1($t9)
    MEM_B(0X1, ctx->r25) = 0;
    // 0x800947D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800947DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800947E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800947E4: jr          $ra
    // 0x800947E8: nop

    return;
    // 0x800947E8: nop

;}
RECOMP_FUNC void bsdie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080017C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800180: jal         0x8008CABC
    // 0x80800184: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800184: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800188: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080018C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80800190: jal         0x80085228
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x8009B9B0
    // 0x808001A0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808001A0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_2:
    // 0x808001A4: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808001A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001AC: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x808001B0: nop
    
            goto L_808001D4;
    }
    // 0x808001B0: nop

    // 0x808001B4: beq         $v0, $at, L_80800258
    if (ctx->r2 == ctx->r1) {
        // 0x808001B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800258;
    }
    // 0x808001B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001BC: beq         $v0, $at, L_808002A8
    if (ctx->r2 == ctx->r1) {
        // 0x808001C0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808002A8;
    }
    // 0x808001C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001C4: beq         $v0, $at, L_80800324
    if (ctx->r2 == ctx->r1) {
        // 0x808001C8: nop
    
            goto L_80800324;
    }
    // 0x808001C8: nop

    // 0x808001CC: b           L_80800324
    // 0x808001D0: nop

        goto L_80800324;
    // 0x808001D0: nop

L_808001D4:
    // 0x808001D4: jal         0x8008E078
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001DC: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x808001E0: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800324;
    }
    // 0x808001E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808001E4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808001E8: jal         0x8008B1D4
    // 0x808001EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x808001EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x808001F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808001F4: jal         0x8008B134
    // 0x808001F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x808001F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: jal         0x8009BA58
    // 0x80800204: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x80800204: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_6:
    // 0x80800208: jal         0x8009E058
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E058(rdram, ctx);
        goto after_7;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x80800218: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080021C: jal         0x8009DF18
    // 0x80800220: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_8;
    // 0x80800220: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_8:
    // 0x80800224: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800228: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080022C: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800230: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800234: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800238: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080023C: jal         0x80085490
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800244: jal         0x80800000
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsdie(rdram, ctx);
        goto after_10;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080024C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800250: b           L_80800324
    // 0x80800254: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800324;
    // 0x80800254: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800258:
    // 0x80800258: jal         0x8008E078
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_11;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800260: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x80800264: nop
    
            goto L_80800324;
    }
    // 0x80800264: nop

    // 0x80800268: jal         0x8009E084
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E084(rdram, ctx);
        goto after_12;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: addiu       $a1, $zero, 0x427
    ctx->r5 = ADD32(0, 0X427);
    // 0x80800278: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080027C: jal         0x8009DF18
    // 0x80800280: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_13;
    // 0x80800280: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_13:
    // 0x80800284: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800288: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800294: jal         0x80085490
    // 0x80800298: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80800298: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_14:
    // 0x8080029C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808002A0: b           L_80800324
    // 0x808002A4: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80800324;
    // 0x808002A4: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_808002A8:
    // 0x808002A8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x808002AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002B0: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808002B4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002B8: jal         0x800F0E00
    // 0x808002BC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800F0E00(rdram, ctx);
        goto after_15;
    // 0x808002BC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_15:
    // 0x808002C0: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x808002C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002C8: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x808002CC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808002D0: nop

    // 0x808002D4: bc1fl       L_808002E8
    if (!c1cs) {
        // 0x808002D8: lui         $a1, 0x3F27
        ctx->r5 = S32(0X3F27 << 16);
            goto L_808002E8;
    }
    goto skip_0;
    // 0x808002D8: lui         $a1, 0x3F27
    ctx->r5 = S32(0X3F27 << 16);
    skip_0:
    // 0x808002DC: jal         0x80084A10
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_16;
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808002E4: lui         $a1, 0x3F27
    ctx->r5 = S32(0X3F27 << 16);
L_808002E8:
    // 0x808002E8: ori         $a1, $a1, 0x5F70
    ctx->r5 = ctx->r5 | 0X5F70;
    // 0x808002EC: jal         0x8008B348
    // 0x808002F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_17;
    // 0x808002F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x808002F4: beq         $v0, $zero, L_80800304
    if (ctx->r2 == 0) {
        // 0x808002F8: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800304;
    }
    // 0x808002F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808002FC: jal         0x8008B1BC
    // 0x80800300: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_18;
    // 0x80800300: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_18:
L_80800304:
    // 0x80800304: jal         0x8008B324
    // 0x80800308: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isStopped(rdram, ctx);
        goto after_19;
    // 0x80800308: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x8080030C: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x80800310: nop
    
            goto L_80800324;
    }
    // 0x80800310: nop

    // 0x80800314: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800318: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8080031C: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x80800320: swc1        $f10, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f10.u32l;
L_80800324:
    // 0x80800324: jal         0x80085238
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_7(rdram, ctx);
        goto after_20;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080032C: beq         $v0, $zero, L_8080033C
    if (ctx->r2 == 0) {
        // 0x80800330: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080033C;
    }
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: addiu       $t9, $zero, 0x54
    ctx->r25 = ADD32(0, 0X54);
    // 0x80800338: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_8080033C:
    // 0x8080033C: jal         0x8009E5C8
    // 0x80800340: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_21;
    // 0x80800340: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_21:
    // 0x80800344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800348: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080034C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800350: jr          $ra
    // 0x80800354: nop

    return;
    // 0x80800354: nop

;}
RECOMP_FUNC void bsrest_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080018C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800190: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800194: jal         0x8009CC68
    // 0x80800198: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009CC68(rdram, ctx);
        goto after_0;
    // 0x80800198: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080019C: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F8;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x8009C128
    // 0x808001A8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x808001A8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x8009CC18
    // 0x808001B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009CC18(rdram, ctx);
        goto after_2;
    // 0x808001B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x808001B8: bne         $v0, $zero, L_808001DC
    if (ctx->r2 != 0) {
        // 0x808001BC: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_808001DC;
    }
    // 0x808001BC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808001C0: jal         0x800A4CA8
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_3;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001CC: jal         0x801160DC
    // 0x808001D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_801160DC(rdram, ctx);
        goto after_4;
    // 0x808001D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808001D4: b           L_808001FC
    // 0x808001D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001FC;
    // 0x808001D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001DC:
    // 0x808001DC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808001E0: jal         0x800F1E6C
    // 0x808001E4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800F1E6C(rdram, ctx);
        goto after_5;
    // 0x808001E4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x808001E8: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F8;
    }
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x8009C914
    // 0x808001F4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x808001F4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_6:
L_808001F8:
    // 0x808001F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001FC:
    // 0x808001FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800200: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void bamovespline_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080034C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800350: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800354: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x80800358: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080035C: jal         0x808000F4
    // 0x80800360: swc1        $f12, 0x98($t6)
    MEM_W(0X98, ctx->r14) = ctx->f12.u32l;
    func_808000F4_bamovespline(rdram, ctx);
        goto after_0;
    // 0x80800360: swc1        $f12, 0x98($t6)
    MEM_W(0X98, ctx->r14) = ctx->f12.u32l;
    after_0:
    // 0x80800364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080036C: jr          $ra
    // 0x80800370: nop

    return;
    // 0x80800370: nop

;}
RECOMP_FUNC void gczoomboxdata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080025C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800260: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800264: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2686, 0XAA8) << 16);
    // 0x80800268: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080026C: jr          $ra
    // 0x80800270: lhu         $v0, 0xAA8($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(2686, 0XAA8));
    return;
    // 0x80800270: lhu         $v0, 0xAA8($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(2686, 0XAA8));
;}
RECOMP_FUNC void _ncpod_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089510: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089510);
    return;
    // 0x80089514: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void basnowball_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005B4: jal         0x800A1718
    // 0x808005B8: nop

    func_800A1718(rdram, ctx);
        goto after_0;
    // 0x808005B8: nop

    after_0:
    // 0x808005BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005C0: slti        $t6, $v0, 0x5
    ctx->r14 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x808005C4: xori        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 ^ 0X1;
    // 0x808005C8: jr          $ra
    // 0x808005CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808005CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800B9C_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BA4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800BA8: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x80800BAC: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80800BB0: srl         $t7, $a1, 26
    ctx->r15 = S32(U32(ctx->r5) >> 26);
    // 0x80800BB4: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80800BB8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80800BBC: jal         0x800CC63C
    // 0x80800BC0: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_0;
    // 0x80800BC0: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    after_0:
    // 0x80800BC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BC8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800BCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800BD0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800BD4: jal         0x800EE7F8
    // 0x80800BD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800BD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800BDC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800BE0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800BE4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800BE8: jal         0x800DC178
    // 0x80800BEC: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800BEC: nop

    after_2:
    // 0x80800BF0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800BF4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800BF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1612, 0X11BC) << 16);
    // 0x80800BFC: lh          $t9, 0xC($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XC);
    // 0x80800C00: lwc1        $f6, 0x11BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1612, 0X11BC));
    // 0x80800C04: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800C08: nop

    // 0x80800C0C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800C10: mul.s       $f12, $f14, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80800C14: jal         0x800DC178
    // 0x80800C18: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800C18: nop

    after_3:
    // 0x80800C1C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800C20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C24: jal         0x800EF1B8
    // 0x80800C28: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x80800C28: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80800C2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1612, 0X11C0) << 16);
    // 0x80800C30: lwc1        $f8, 0x11C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1612, 0X11C0));
    // 0x80800C34: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80800C38: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800C3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C40: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80800C44: swc1        $f10, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f10.u32l;
    // 0x80800C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C50: jr          $ra
    // 0x80800C54: nop

    return;
    // 0x80800C54: nop

;}
RECOMP_FUNC void func_80801B40_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B44: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80801B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B4C: beq         $a1, $at, L_80801B68
    if (ctx->r5 == ctx->r1) {
        // 0x80801B50: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801B68;
    }
    // 0x80801B50: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801B54: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80801B58: beq         $a1, $at, L_80801B98
    if (ctx->r5 == ctx->r1) {
        // 0x80801B5C: nop
    
            goto L_80801B98;
    }
    // 0x80801B5C: nop

    // 0x80801B60: b           L_80801BB4
    // 0x80801B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801BB4;
    // 0x80801B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B68:
    // 0x80801B68: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801B6C: jal         0x8008A4B8
    // 0x80801B70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80801B70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801B74: beq         $v0, $zero, L_80801BB0
    if (ctx->r2 == 0) {
        // 0x80801B78: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801BB0;
    }
    // 0x80801B78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801B7C: jal         0x80103110
    // 0x80801B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80801B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801B84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801B88: jal         0x80101FDC
    // 0x80801B8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80801B8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80801B90: b           L_80801BB4
    // 0x80801B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801BB4;
    // 0x80801B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B98:
    // 0x80801B98: jal         0x80801BC4
    // 0x80801B9C: nop

    func_80801BC4_chalienkids(rdram, ctx);
        goto after_3;
    // 0x80801B9C: nop

    after_3:
    // 0x80801BA0: b           L_80801BB4
    // 0x80801BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801BB4;
    // 0x80801BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801BA8: b           L_80801BB4
    // 0x80801BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801BB4;
    // 0x80801BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801BB0:
    // 0x80801BB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801BB4:
    // 0x80801BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801BBC: jr          $ra
    // 0x80801BC0: nop

    return;
    // 0x80801BC0: nop

;}
RECOMP_FUNC void func_800E8A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8A68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E8A6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E8A70: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E8A74: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E8A78: jal         0x800D8FF8
    // 0x800E8A7C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800E8A7C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x800E8A80: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800E8A84: addiu       $s1, $s1, -0x2980
    ctx->r17 = ADD32(ctx->r17, -0X2980);
    // 0x800E8A88: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800E8A8C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800E8A90: beql        $a0, $zero, L_800E8AF0
    if (ctx->r4 == 0) {
        // 0x800E8A94: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E8AF0;
    }
    goto skip_0;
    // 0x800E8A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800E8A98: jal         0x800B3034
    // 0x800E8A9C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    freelist_capacity(rdram, ctx);
        goto after_1;
    // 0x800E8A9C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_1:
    // 0x800E8AA0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800E8AA4: bnel        $at, $zero, L_800E8AF0
    if (ctx->r1 != 0) {
        // 0x800E8AA8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E8AF0;
    }
    goto skip_1;
    // 0x800E8AA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800E8AAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_800E8AB0:
    // 0x800E8AB0: jal         0x800B31B8
    // 0x800E8AB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    freelist_is_element_alive(rdram, ctx);
        goto after_2;
    // 0x800E8AB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800E8AB8: beql        $v0, $zero, L_800E8AD8
    if (ctx->r2 == 0) {
        // 0x800E8ABC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800E8AD8;
    }
    goto skip_2;
    // 0x800E8ABC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x800E8AC0: jal         0x800E8CB0
    // 0x800E8AC4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800E8CB0(rdram, ctx);
        goto after_3;
    // 0x800E8AC4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_3:
    // 0x800E8AC8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800E8ACC: jal         0x800E8DE4
    // 0x800E8AD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E8DE4(rdram, ctx);
        goto after_4;
    // 0x800E8AD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800E8AD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800E8AD8:
    // 0x800E8AD8: jal         0x800B3034
    // 0x800E8ADC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    freelist_capacity(rdram, ctx);
        goto after_5;
    // 0x800E8ADC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x800E8AE0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E8AE4: bnel        $at, $zero, L_800E8AB0
    if (ctx->r1 != 0) {
        // 0x800E8AE8: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_800E8AB0;
    }
    goto skip_3;
    // 0x800E8AE8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x800E8AEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E8AF0:
    // 0x800E8AF0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800E8AF4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E8AF8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E8AFC: jr          $ra
    // 0x800E8B00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E8B00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800A8984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8984: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A8988: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A898C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A8990: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8994: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800A8998: jr          $ra
    // 0x800A899C: lw          $v0, 0x768C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X768C);
    return;
    // 0x800A899C: lw          $v0, 0x768C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X768C);
;}
RECOMP_FUNC void func_80800CF4_suexpression(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF4: addiu       $v1, $a0, -0xC
    ctx->r3 = ADD32(ctx->r4, -0XC);
    // 0x80800CF8: sltiu       $at, $v1, 0xC6
    ctx->r1 = ctx->r3 < 0XC6 ? 1 : 0;
    // 0x80800CFC: bne         $at, $zero, L_80800D0C
    if (ctx->r1 != 0) {
        // 0x80800D00: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80800D0C;
    }
    // 0x80800D00: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80800D04: jr          $ra
    // 0x80800D08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800D08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D0C:
    // 0x80800D0C: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80800D10: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3138, 0XD60) << 16);
    // 0x80800D14: addiu       $t7, $t7, 0xD60
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3138, 0XD60));
    // 0x80800D18: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800D1C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80800D20: jr          $ra
    // 0x80800D24: nop

    return;
    // 0x80800D24: nop

    // 0x80800D28: nop

    // 0x80800D2C: nop

;}
RECOMP_FUNC void _bsmum_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083860: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083860);
    return;
    // 0x80083864: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_808001A8_chjujubagfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808001AC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1728, 0X4B8) << 16);
    // 0x808001B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808001B4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808001B8: addiu       $t7, $t7, 0x4B8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1728, 0X4B8));
    // 0x808001BC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x808001C0: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x808001C4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x808001C8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x808001CC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x808001D0: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1728, 0X4C4) << 16);
    // 0x808001D4: addiu       $t2, $t2, 0x4C4
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1728, 0X4C4));
    // 0x808001D8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x808001DC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x808001E0: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x808001E4: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x808001E8: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x808001EC: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x808001F0: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x808001F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001FC: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80800200: jal         0x80100094
    // 0x80800204: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800204: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    after_0:
    // 0x80800208: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080020C: jal         0x800DA298
    // 0x80800210: addiu       $a0, $zero, 0x9F3
    ctx->r4 = ADD32(0, 0X9F3);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800210: addiu       $a0, $zero, 0x9F3
    ctx->r4 = ADD32(0, 0X9F3);
    after_1:
    // 0x80800214: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x80800218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800224;
    }
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x8080000C
    // 0x80800220: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080000C_chjujubagfx(rdram, ctx);
        goto after_2;
    // 0x80800220: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
L_80800224:
    // 0x80800224: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800228: sll         $t6, $t9, 11
    ctx->r14 = S32(ctx->r25 << 11);
    // 0x8080022C: bltzl       $t6, L_8080027C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800230: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_8080027C;
    }
    goto skip_0;
    // 0x80800230: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800234: jal         0x8010D278
    // 0x80800238: nop

    func_8010D278(rdram, ctx);
        goto after_3;
    // 0x80800238: nop

    after_3:
    // 0x8080023C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800240: beq         $v0, $at, L_80800270
    if (ctx->r2 == ctx->r1) {
        // 0x80800244: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800270;
    }
    // 0x80800244: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800248: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080024C: beql        $a0, $zero, L_8080027C
    if (ctx->r4 == 0) {
        // 0x80800250: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_8080027C;
    }
    goto skip_1;
    // 0x80800250: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x80800254: jal         0x80106790
    // 0x80800258: nop

    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80800258: nop

    after_4:
    // 0x8080025C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800260: jal         0x80086978
    // 0x80800264: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _chnewmumbo_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800264: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800268: b           L_8080027C
    // 0x8080026C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_8080027C;
    // 0x8080026C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800270:
    // 0x80800270: jal         0x8008FE94
    // 0x80800274: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_8008FE94(rdram, ctx);
        goto after_6;
    // 0x80800274: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800278: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_8080027C:
    // 0x8080027C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800280: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800284: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800288: beq         $t7, $at, L_808002B0
    if (ctx->r15 == ctx->r1) {
        // 0x8080028C: addiu       $t0, $s0, 0x4
        ctx->r8 = ADD32(ctx->r16, 0X4);
            goto L_808002B0;
    }
    // 0x8080028C: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    // 0x80800290: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800294: beq         $t7, $at, L_80800320
    if (ctx->r15 == ctx->r1) {
        // 0x80800298: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800320;
    }
    // 0x80800298: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080029C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808002A0: beq         $t7, $at, L_80800360
    if (ctx->r15 == ctx->r1) {
        // 0x808002A4: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800360;
    }
    // 0x808002A4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002A8: b           L_808003C4
    // 0x808002AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003C4;
    // 0x808002AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002B0:
    // 0x808002B0: jal         0x800898B0
    // 0x808002B4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_7;
    // 0x808002B4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_7:
    // 0x808002B8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x808002BC: addiu       $t3, $sp, 0x40
    ctx->r11 = ADD32(ctx->r29, 0X40);
    // 0x808002C0: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // 0x808002C4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x808002C8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808002CC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002D0: lui         $a1, 0x41E0
    ctx->r5 = S32(0X41E0 << 16);
    // 0x808002D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002D8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x808002DC: jal         0x80089878
    // 0x808002E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x808002E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_8:
    // 0x808002E4: jal         0x800898E8
    // 0x808002E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_9;
    // 0x808002E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_9:
    // 0x808002EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002F0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002F4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808002F8: nop

    // 0x808002FC: bc1fl       L_808003C4
    if (!c1cs) {
        // 0x80800300: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808003C4;
    }
    goto skip_2;
    // 0x80800300: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80800304: jal         0x800898C8
    // 0x80800308: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_10;
    // 0x80800308: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_10:
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x8080000C
    // 0x80800314: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080000C_chjujubagfx(rdram, ctx);
        goto after_11;
    // 0x80800314: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80800318: b           L_808003C4
    // 0x8080031C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003C4;
    // 0x8080031C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800320:
    // 0x80800320: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x80800324: jal         0x800898B0
    // 0x80800328: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_12;
    // 0x80800328: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_12:
    // 0x8080032C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80800330: addiu       $t9, $sp, 0x40
    ctx->r25 = ADD32(ctx->r29, 0X40);
    // 0x80800334: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x80800338: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8080033C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800340: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800344: lui         $a1, 0x41E0
    ctx->r5 = S32(0X41E0 << 16);
    // 0x80800348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080034C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80800350: jal         0x80089878
    // 0x80800354: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x80800354: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_13:
    // 0x80800358: b           L_808003C4
    // 0x8080035C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003C4;
    // 0x8080035C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800360:
    // 0x80800360: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x80800364: jal         0x800898B0
    // 0x80800368: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_14;
    // 0x80800368: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_14:
    // 0x8080036C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800370: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x80800374: addiu       $t4, $sp, 0x4C
    ctx->r12 = ADD32(ctx->r29, 0X4C);
    // 0x80800378: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8080037C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800380: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800384: lui         $a1, 0x41E0
    ctx->r5 = S32(0X41E0 << 16);
    // 0x80800388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080038C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80800390: jal         0x80089878
    // 0x80800394: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x80800394: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_15:
    // 0x80800398: jal         0x800898F0
    // 0x8080039C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _sumumbofx_entrypoint_22(rdram, ctx);
        goto after_16;
    // 0x8080039C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_16:
    // 0x808003A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1728, 0X460) << 16);
    // 0x808003A4: lwc1        $f6, 0x460($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1728, 0X460));
    // 0x808003A8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808003AC: nop

    // 0x808003B0: bc1fl       L_808003C4
    if (!c1cs) {
        // 0x808003B4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808003C4;
    }
    goto skip_3;
    // 0x808003B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808003B8: jal         0x800FFAB0
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_17;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808003C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003C4:
    // 0x808003C4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808003C8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

;}
