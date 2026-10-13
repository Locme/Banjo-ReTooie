#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _gcnewoption_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DA8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DA8);
    return;
    // 0x80087DAC: addi        $t0, $zero, 0x88
    ctx->r8 = ADD32(0, 0X88);
;}
RECOMP_FUNC void baeggsetup_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808002B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808002C0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808002C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002CC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x808002D0: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x808002D4: jal         0x800F53D0
    // 0x808002D8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x808002D8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002DC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x808002E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002E4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808002E8: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x808002EC: beq         $at, $zero, L_808003D8
    if (ctx->r1 == 0) {
        // 0x808002F0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808003D8;
    }
    // 0x808002F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808002F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(504, 0X7FC) << 16);
    // 0x808002F8: addu        $at, $at, $t7
    gpr jr_addend_80800300 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808002FC: lw          $t7, 0x7FC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(504, 0X7FC));
    // 0x80800300: jr          $t7
    // 0x80800304: nop

    switch (jr_addend_80800300 >> 2) {
        case 0: goto L_80800308; break;
        case 1: goto L_80800324; break;
        case 2: goto L_80800340; break;
        case 3: goto L_8080035C; break;
        case 4: goto L_80800378; break;
        case 5: goto L_808003C4; break;
        case 6: goto L_808003A8; break;
        default: switch_error(__func__, 0x80800300, 0x808007FC);
    }
    // 0x80800304: nop

L_80800308:
    // 0x80800308: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080030C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800310: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800314: jal         0x80087258
    // 0x80800318: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _cheggnormal_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800318: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8080031C: b           L_808003DC
    // 0x80800320: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003DC;
    // 0x80800320: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800324:
    // 0x80800324: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800328: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8080032C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800330: jal         0x800871F0
    // 0x80800334: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _cheggfire_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800334: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x80800338: b           L_808003DC
    // 0x8080033C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003DC;
    // 0x8080033C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800340:
    // 0x80800340: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800344: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800348: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8080034C: jal         0x80087240
    // 0x80800350: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _cheggice_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800350: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x80800354: b           L_808003DC
    // 0x80800358: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003DC;
    // 0x80800358: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080035C:
    // 0x8080035C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800360: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800364: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800368: jal         0x80087228
    // 0x8080036C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _chegggrenade_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080036C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x80800370: b           L_808003DC
    // 0x80800374: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003DC;
    // 0x80800374: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800378:
    // 0x80800378: jal         0x800844D8
    // 0x8080037C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    _bababykaz_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x8080037C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_5:
    // 0x80800380: jal         0x80800008
    // 0x80800384: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80800008_baeggsetup(rdram, ctx);
        goto after_6;
    // 0x80800384: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80800388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080038C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800390: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800394: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800398: jal         0x800871C8
    // 0x8080039C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    _cheggclockwork_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x8080039C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_7:
    // 0x808003A0: b           L_808003DC
    // 0x808003A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003DC;
    // 0x808003A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003A8:
    // 0x808003A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003AC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808003B0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x808003B4: jal         0x80087208
    // 0x808003B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _chegggolden_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808003B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_8:
    // 0x808003BC: b           L_808003DC
    // 0x808003C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003DC;
    // 0x808003C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003C4:
    // 0x808003C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808003CC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x808003D0: jal         0x800873D8
    // 0x808003D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _cheggproximity_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808003D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_9:
L_808003D8:
    // 0x808003D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003DC:
    // 0x808003DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003E0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808003E4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808003E8: jr          $ra
    // 0x808003EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808003EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bsdronebitten_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800320: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800324: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800328: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080032C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800330: jal         0x80084660
    // 0x80800334: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    _badata_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800334: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800340: jal         0x8008CB3C
    // 0x80800344: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800344: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80800348: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080034C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800358: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080035C: jal         0x8009FFD8
    // 0x80800360: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800360: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: jal         0x8009C128
    // 0x8080036C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x8080036C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80800370: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x80800374: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800378: jal         0x800EEAD4
    // 0x8080037C: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    func_800EEAD4(rdram, ctx);
        goto after_4;
    // 0x8080037C: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    after_4:
    // 0x80800380: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800384: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: lbu         $t8, 0x30($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X30);
    // 0x80800390: jal         0x80084DB8
    // 0x80800394: sb          $t8, 0x191($s0)
    MEM_B(0X191, ctx->r16) = ctx->r24;
    _bamovegoto_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800394: sb          $t8, 0x191($s0)
    MEM_B(0X191, ctx->r16) = ctx->r24;
    after_5:
    // 0x80800398: lbu         $t9, 0x191($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X191);
    // 0x8080039C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003A0: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808003A4: bne         $t9, $at, L_808003C0
    if (ctx->r25 != ctx->r1) {
        // 0x808003A8: lui         $a2, 0x459C
        ctx->r6 = S32(0X459C << 16);
            goto L_808003C0;
    }
    // 0x808003A8: lui         $a2, 0x459C
    ctx->r6 = S32(0X459C << 16);
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B0: jal         0x80084DF8
    // 0x808003B4: lui         $a1, 0x4516
    ctx->r5 = S32(0X4516 << 16);
    _bamovegoto_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808003B4: lui         $a1, 0x4516
    ctx->r5 = S32(0X4516 << 16);
    after_6:
    // 0x808003B8: b           L_808003F8
    // 0x808003BC: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
        goto L_808003F8;
    // 0x808003BC: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
L_808003C0:
    // 0x808003C0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808003C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003C8: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x808003CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003D0: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x808003D4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808003D8: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x808003DC: jal         0x800F10B4
    // 0x808003E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x808003E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x808003E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003E8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x808003EC: jal         0x80084DF0
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808003F4: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
L_808003F8:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x80084E18
    // 0x80800400: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    _bamovegoto_entrypoint_12(rdram, ctx);
        goto after_9;
    // 0x80800400: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    after_9:
    // 0x80800404: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800408: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8080040C: addiu       $a2, $a2, 0x3028
    ctx->r6 = ADD32(ctx->r6, 0X3028);
    // 0x80800410: addiu       $a1, $a1, 0x3020
    ctx->r5 = ADD32(ctx->r5, 0X3020);
    // 0x80800414: jal         0x80084E10
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080041C: jal         0x80084E20
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x800961A0
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961A0(rdram, ctx);
        goto after_12;
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800430: jal         0x8008E944
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_13;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800438: jal         0x8009D9D4
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_14;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800440: sb          $zero, 0x190($s0)
    MEM_B(0X190, ctx->r16) = 0;
    // 0x80800444: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800448: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080044C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800450: jr          $ra
    // 0x80800454: nop

    return;
    // 0x80800454: nop

;}
RECOMP_FUNC void func_80800724_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080072C: jal         0x800D8FF8
    // 0x80800730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800734: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800738: lw          $v0, 0x18C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18C);
    // 0x8080073C: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80800740: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800744: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x80800748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080074C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800750: jr          $ra
    // 0x80800754: nop

    return;
    // 0x80800754: nop

;}
RECOMP_FUNC void func_80105230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105230: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80105234: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80105238: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8010523C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80105240: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80105244: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80105248: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8010524C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80105250: jal         0x800D3948
    // 0x80105254: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80105254: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x80105258: beq         $v0, $zero, L_80105268
    if (ctx->r2 == 0) {
        // 0x8010525C: addiu       $s0, $sp, 0x58
        ctx->r16 = ADD32(ctx->r29, 0X58);
            goto L_80105268;
    }
    // 0x8010525C: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x80105260: b           L_80105374
    // 0x80105264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80105374;
    // 0x80105264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80105268:
    // 0x80105268: jal         0x8010D640
    // 0x8010526C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010D640(rdram, ctx);
        goto after_1;
    // 0x8010526C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80105270: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x80105274: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x80105278: jal         0x800EEB40
    // 0x8010527C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEB40(rdram, ctx);
        goto after_2;
    // 0x8010527C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80105280: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80105284: lwc1        $f4, 0x6450($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x80105288: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8010528C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80105290: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80105294: nop

    // 0x80105298: bc1f        L_801052A8
    if (!c1cs) {
        // 0x8010529C: nop
    
            goto L_801052A8;
    }
    // 0x8010529C: nop

    // 0x801052A0: b           L_80105374
    // 0x801052A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80105374;
    // 0x801052A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801052A8:
    // 0x801052A8: beq         $v0, $zero, L_801052B8
    if (ctx->r2 == 0) {
        // 0x801052AC: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_801052B8;
    }
    // 0x801052AC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x801052B0: b           L_801052BC
    // 0x801052B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_801052BC;
    // 0x801052B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_801052B8:
    // 0x801052B8: addiu       $s0, $s0, 0x4420
    ctx->r16 = ADD32(ctx->r16, 0X4420);
L_801052BC:
    // 0x801052BC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801052C0: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801052C4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x801052C8: nop

    // 0x801052CC: bc1tl       L_80105374
    if (c1cs) {
        // 0x801052D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80105374;
    }
    goto skip_0;
    // 0x801052D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801052D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_801052D8:
    // 0x801052D8: jal         0x80101E14
    // 0x801052DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x801052DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x801052E0: beql        $v0, $zero, L_80105358
    if (ctx->r2 == 0) {
        // 0x801052E4: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_80105358;
    }
    goto skip_1;
    // 0x801052E4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x801052E8: jal         0x801053D4
    // 0x801052EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801053D4(rdram, ctx);
        goto after_4;
    // 0x801052EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x801052F0: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x801052F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801052F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801052FC: andi        $a1, $s1, 0x1
    ctx->r5 = ctx->r17 & 0X1;
    // 0x80105300: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x80105304: jal         0x80088A58
    // 0x80105308: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    _fxstep_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x80105308: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x8010530C: beq         $v0, $zero, L_8010534C
    if (ctx->r2 == 0) {
        // 0x80105310: nop
    
            goto L_8010534C;
    }
    // 0x80105310: nop

    // 0x80105314: jal         0x800C4B64
    // 0x80105318: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    func_800C4B64(rdram, ctx);
        goto after_6;
    // 0x80105318: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_6:
    // 0x8010531C: jal         0x800C4B70
    // 0x80105320: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800C4B70(rdram, ctx);
        goto after_7;
    // 0x80105320: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_7:
    // 0x80105324: jal         0x800C4B7C
    // 0x80105328: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800C4B7C(rdram, ctx);
        goto after_8;
    // 0x80105328: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_8:
    // 0x8010532C: lw          $a1, 0x70($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X70);
    // 0x80105330: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80105334: addiu       $a3, $a3, 0x442C
    ctx->r7 = ADD32(ctx->r7, 0X442C);
    // 0x80105338: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x8010533C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80105340: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80105344: jal         0x8010D930
    // 0x80105348: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_8010D930(rdram, ctx);
        goto after_9;
    // 0x80105348: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_9:
L_8010534C:
    // 0x8010534C: b           L_80105374
    // 0x80105350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80105374;
    // 0x80105350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80105354: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_80105358:
    // 0x80105358: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8010535C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80105360: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x80105364: nop

    // 0x80105368: bc1fl       L_801052D8
    if (!c1cs) {
        // 0x8010536C: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_801052D8;
    }
    goto skip_2;
    // 0x8010536C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_2:
    // 0x80105370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80105374:
    // 0x80105374: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80105378: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8010537C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80105380: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80105384: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80105388: jr          $ra
    // 0x8010538C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8010538C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800A9460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9460: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9464: jr          $ra
    // 0x800A9468: lh          $v0, 0x76D0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X76D0);
    return;
    // 0x800A9468: lh          $v0, 0x76D0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X76D0);
;}
RECOMP_FUNC void chfootwear_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2448, 0X860) << 16);
    // 0x808006AC: jr          $ra
    // 0x808006B0: addiu       $v0, $v0, 0x860
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2448, 0X860));
    return;
    // 0x808006B0: addiu       $v0, $v0, 0x860
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2448, 0X860));
;}
RECOMP_FUNC void func_8080049C_chweldarbossfusebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080049C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808004A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004AC: jal         0x800D90A4
    // 0x808004B0: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x808004B0: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x808004B4: beql        $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x808004B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005B0;
    }
    goto skip_0;
    // 0x808004B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808004BC: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x808004C0: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1380, 0X790) << 16);
    // 0x808004C4: addiu       $t8, $t8, 0x790
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1380, 0X790));
    // 0x808004C8: bnel        $t6, $zero, L_808004FC
    if (ctx->r14 != 0) {
        // 0x808004CC: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_808004FC;
    }
    goto skip_1;
    // 0x808004CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x808004D0: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x808004D4: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x808004D8: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    // 0x808004DC: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x808004E0: jal         0x800C8A98
    // 0x808004E4: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x808004E4: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    after_1:
    // 0x808004E8: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x808004EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004F0: jal         0x800C8D4C
    // 0x808004F4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C8D4C(rdram, ctx);
        goto after_2;
    // 0x808004F4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x808004F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
L_808004FC:
    // 0x808004FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800500: jal         0x800EE7F8
    // 0x80800504: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800504: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800508: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080050C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800510: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800514: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800518: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080051C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80800520: jal         0x800C8CB8
    // 0x80800524: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x80800524: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_4:
    // 0x80800528: jal         0x8001210C
    // 0x8080052C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_5;
    // 0x8080052C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80800530: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80800534: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80800538: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1380, 0X798) << 16);
    // 0x8080053C: addiu       $t2, $t2, 0x798
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1380, 0X798));
    // 0x80800540: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800544: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x80800548: jal         0x800C8E84
    // 0x8080054C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800C8E84(rdram, ctx);
        goto after_6;
    // 0x8080054C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_6:
    // 0x80800550: jal         0x80105834
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_7;
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800558: jal         0x808005F8
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005F8_chweldarbossfusebox(rdram, ctx);
        goto after_8;
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800560: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1380, 0X7B0) << 16);
    // 0x80800564: addiu       $a3, $a3, 0x7B0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1380, 0X7B0));
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800570: jal         0x80089D50
    // 0x80800574: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800574: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80800578: jal         0x80105A5C
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_10;
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800580: beql        $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x80800584: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005B0;
    }
    goto skip_2;
    // 0x80800584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800588: jal         0x800C8B84
    // 0x8080058C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800C8B84(rdram, ctx);
        goto after_11;
    // 0x8080058C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_11:
    // 0x80800590: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80800594: addiu       $a0, $zero, 0x3AE
    ctx->r4 = ADD32(0, 0X3AE);
    // 0x80800598: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080059C: jal         0x80101180
    // 0x808005A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_12;
    // 0x808005A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x808005A4: jal         0x800FFAB0
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808005AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005B0:
    // 0x808005B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808005B8: jr          $ra
    // 0x808005BC: nop

    return;
    // 0x808005BC: nop

;}
RECOMP_FUNC void suquiz_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D84: jal         0x800DA298
    // 0x80800D88: addiu       $a0, $zero, 0x6EB
    ctx->r4 = ADD32(0, 0X6EB);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800D88: addiu       $a0, $zero, 0x6EB
    ctx->r4 = ADD32(0, 0X6EB);
    after_0:
    // 0x80800D8C: bnel        $v0, $zero, L_80800DA8
    if (ctx->r2 != 0) {
        // 0x80800D90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DA8;
    }
    goto skip_0;
    // 0x80800D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800D94: jal         0x80088830
    // 0x80800D98: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80800D98: nop

    after_1:
    // 0x80800D9C: jal         0x800DA544
    // 0x80800DA0: addiu       $a0, $zero, 0x6EB
    ctx->r4 = ADD32(0, 0X6EB);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800DA0: addiu       $a0, $zero, 0x6EB
    ctx->r4 = ADD32(0, 0X6EB);
    after_2:
    // 0x80800DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DA8:
    // 0x80800DA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DAC: jr          $ra
    // 0x80800DB0: nop

    return;
    // 0x80800DB0: nop

;}
RECOMP_FUNC void _sccustom_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A680: syscall     846
    recomp_syscall_handler(rdram, ctx, 0x8008A680);
    return;
    // 0x8008A684: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void glcutDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x808004B8: jr          $ra
    // 0x808004BC: lh          $v0, 0x75E8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X75E8);
    return;
    // 0x808004BC: lh          $v0, 0x75E8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X75E8);
;}
RECOMP_FUNC void _glsplinecs_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088460: syscall     685
    recomp_syscall_handler(rdram, ctx, 0x80088460);
    return;
    // 0x80088464: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsmummove_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838C0: syscall     78
    recomp_syscall_handler(rdram, ctx, 0x800838C0);
    return;
    // 0x800838C4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080016C_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: jr          $ra
    // 0x80800170: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800170: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chamazonstadiumguard_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1900, 0X700) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x700
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1900, 0X700));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x700
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1900, 0X700));
;}
RECOMP_FUNC void subaddietaxi_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080070C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800714: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800718: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080071C: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80800720: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x80800724: bltzl       $t9, L_80800750
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800728: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800750;
    }
    goto skip_0;
    // 0x80800728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080072C: jal         0x800EA05C
    // 0x80800730: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800730: nop

    after_0:
    // 0x80800734: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800738: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080073C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800740: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x80800744: jal         0x800CB6B4
    // 0x80800748: lw          $a2, 0x48($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X48);
    func_800CB6B4(rdram, ctx);
        goto after_1;
    // 0x80800748: lw          $a2, 0x48($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X48);
    after_1:
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800750:
    // 0x80800750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800754: jr          $ra
    // 0x80800758: nop

    return;
    // 0x80800758: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825F0: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825F0);
    return;
    // 0x800825F4: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void chquicksandbaddy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800F2C: jal         0x800DC0C0
    // 0x80800F30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80800F30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800F34: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800F38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F3C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1896, 0X1390) << 16);
    // 0x80800F40: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800F44: nop

    // 0x80800F48: bc1fl       L_80800FBC
    if (!c1cs) {
        // 0x80800F4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800FBC;
    }
    goto skip_0;
    // 0x80800F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800F50: jal         0x808010A0
    // 0x80800F54: addiu       $a0, $a0, 0x1390
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1896, 0X1390));
    func_808010A0_chquicksandbaddy(rdram, ctx);
        goto after_1;
    // 0x80800F54: addiu       $a0, $a0, 0x1390
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1896, 0X1390));
    after_1:
    // 0x80800F58: beql        $v0, $zero, L_80800FBC
    if (ctx->r2 == 0) {
        // 0x80800F5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800FBC;
    }
    goto skip_1;
    // 0x80800F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800F60: jal         0x8001210C
    // 0x80800F64: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_2;
    // 0x80800F64: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x80800F68: beql        $v0, $zero, L_80800FBC
    if (ctx->r2 == 0) {
        // 0x80800F6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800FBC;
    }
    goto skip_2;
    // 0x80800F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800F70: jal         0x800B53A4
    // 0x80800F74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_3;
    // 0x80800F74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800F78: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1896, 0X1370) << 16);
    // 0x80800F7C: addiu       $t6, $t6, 0x1370
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1896, 0X1370));
    // 0x80800F80: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800F84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800F88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800F94: jal         0x800BABB8
    // 0x80800F98: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800F98: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_4:
    // 0x80800F9C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1896, 0X1390) << 16);
    // 0x80800FA0: addiu       $a1, $a1, 0x1390
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1896, 0X1390));
    // 0x80800FA4: jal         0x800BAB80
    // 0x80800FA8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800BAB80(rdram, ctx);
        goto after_5;
    // 0x80800FA8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80800FAC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800FB0: jal         0x800BA22C
    // 0x80800FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x80800FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800FB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FBC:
    // 0x80800FBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800FC0: jr          $ra
    // 0x80800FC4: nop

    return;
    // 0x80800FC4: nop

;}
RECOMP_FUNC void func_80800A70_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A74: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800A78: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800A7C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800A80: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800A84: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800A88: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800A8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A90: jal         0x80100094
    // 0x80800A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A98: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800A9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800AA0: jal         0x80800DA8
    // 0x80800AA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800DA8_chquiz(rdram, ctx);
        goto after_1;
    // 0x80800AA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800AA8: jal         0x8008A818
    // 0x80800AAC: nop

    _suquiz_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800AAC: nop

    after_2:
    // 0x80800AB0: beq         $v0, $zero, L_80800AC4
    if (ctx->r2 == 0) {
        // 0x80800AB4: addiu       $s3, $zero, 0x1910
        ctx->r19 = ADD32(0, 0X1910);
            goto L_80800AC4;
    }
    // 0x80800AB4: addiu       $s3, $zero, 0x1910
    ctx->r19 = ADD32(0, 0X1910);
    // 0x80800AB8: addiu       $s3, $zero, 0x1A00
    ctx->r19 = ADD32(0, 0X1A00);
    // 0x80800ABC: b           L_80800AC8
    // 0x80800AC0: addiu       $v0, $zero, 0x1A88
    ctx->r2 = ADD32(0, 0X1A88);
        goto L_80800AC8;
    // 0x80800AC0: addiu       $v0, $zero, 0x1A88
    ctx->r2 = ADD32(0, 0X1A88);
L_80800AC4:
    // 0x80800AC4: addiu       $v0, $zero, 0x19FF
    ctx->r2 = ADD32(0, 0X19FF);
L_80800AC8:
    // 0x80800AC8: addiu       $s4, $v0, 0x1
    ctx->r20 = ADD32(ctx->r2, 0X1);
    // 0x80800ACC: subu        $s0, $v0, $s3
    ctx->r16 = SUB32(ctx->r2, ctx->r19);
    // 0x80800AD0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800AD4: jal         0x800DC128
    // 0x80800AD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x80800AD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80800ADC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800AE0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800AE4: jal         0x80800944
    // 0x80800AE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800944_chquiz(rdram, ctx);
        goto after_4;
    // 0x80800AE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80800AEC: beq         $v0, $zero, L_80800B28
    if (ctx->r2 == 0) {
        // 0x80800AF0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80800B28;
    }
    // 0x80800AF0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80800AF4:
    // 0x80800AF4: bnel        $s0, $zero, L_80800B08
    if (ctx->r16 != 0) {
        // 0x80800AF8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800B08;
    }
    goto skip_0;
    // 0x80800AF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x80800AFC: jal         0x80800C24
    // 0x80800B00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800C24_chquiz(rdram, ctx);
        goto after_5;
    // 0x80800B00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80800B04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800B08:
    // 0x80800B08: jal         0x800DC128
    // 0x80800B0C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800DC128(rdram, ctx);
        goto after_6;
    // 0x80800B0C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80800B10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800B18: jal         0x80800944
    // 0x80800B1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800944_chquiz(rdram, ctx);
        goto after_7;
    // 0x80800B1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80800B20: bnel        $v0, $zero, L_80800AF4
    if (ctx->r2 != 0) {
        // 0x80800B24: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80800AF4;
    }
    goto skip_1;
    // 0x80800B24: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_1:
L_80800B28:
    // 0x80800B28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B2C: jal         0x808009D8
    // 0x80800B30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808009D8_chquiz(rdram, ctx);
        goto after_8;
    // 0x80800B30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80800B34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B38: jal         0x80800BD4
    // 0x80800B3C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80800BD4_chquiz(rdram, ctx);
        goto after_9;
    // 0x80800B3C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_9:
    // 0x80800B40: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800B44: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800B48: sw          $s1, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->r17;
    // 0x80800B4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B50: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800B54: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800B58: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800B5C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B64: jr          $ra
    // 0x80800B68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800B68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800A55E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A55E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A55E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A55E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A55EC: addiu       $a0, $a0, -0x6AC0
    ctx->r4 = ADD32(ctx->r4, -0X6AC0);
    // 0x800A55F0: jal         0x80085560
    // 0x800A55F4: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    _cadbmgrDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800A55F4: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    after_0:
    // 0x800A55F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A55FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5600: jr          $ra
    // 0x800A5604: nop

    return;
    // 0x800A5604: nop

;}
RECOMP_FUNC void func_8009DA40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DA40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009DA44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DA48: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009DA4C: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x8009DA50: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8009DA54: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    // 0x8009DA58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8009DA5C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009DA60: jal         0x800846D8
    // 0x8009DA64: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x8009DA64: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8009DA68: bne         $v0, $zero, L_8009DA7C
    if (ctx->r2 != 0) {
        // 0x8009DA6C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8009DA7C;
    }
    // 0x8009DA6C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8009DA70: lw          $t8, 0x104($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X104);
    // 0x8009DA74: b           L_8009DA8C
    // 0x8009DA78: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
        goto L_8009DA8C;
    // 0x8009DA78: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
L_8009DA7C:
    // 0x8009DA7C: lw          $v0, 0x104($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X104);
    // 0x8009DA80: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8009DA84: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8009DA88: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
L_8009DA8C:
    // 0x8009DA8C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8009DA90: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8009DA94: jal         0x8009D940
    // 0x8009DA98: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8009D940(rdram, ctx);
        goto after_1;
    // 0x8009DA98: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8009DA9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DAA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009DAA4: jr          $ra
    // 0x8009DAA8: nop

    return;
    // 0x8009DAA8: nop

;}
RECOMP_FUNC void func_80800000_chdeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800C6E38
    // 0x80800010: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80800014: beql        $v0, $zero, L_80800028
    if (ctx->r2 == 0) {
        // 0x80800018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800028;
    }
    goto skip_0;
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080001C: jal         0x800FFAB0
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800028:
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void func_80800048_cheggclockwork(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080004C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80800054: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800058: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8080005C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80800060: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80800064: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800068: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080006C: jal         0x80100094
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800074: jal         0x800D8FF8
    // 0x80800078: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800078: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_1:
    // 0x8080007C: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800080: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2104, 0X8B0) << 16);
    // 0x80800084: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800088: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8080008C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800090: lui         $a3, 0x3D08
    ctx->r7 = S32(0X3D08 << 16);
    // 0x80800094: ori         $a3, $a3, 0x6595
    ctx->r7 = ctx->r7 | 0X6595;
    // 0x80800098: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
    // 0x8080009C: lwc1        $f8, 0x8B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2104, 0X8B0));
    // 0x808000A0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x808000A4: jal         0x800F10B4
    // 0x808000A8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808000A8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808000AC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808000B0: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x808000B4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808000B8: addiu       $s2, $s3, 0x4
    ctx->r18 = ADD32(ctx->r19, 0X4);
    // 0x808000BC: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x808000C0: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x808000C4: bc1fl       L_80800104
    if (!c1cs) {
        // 0x808000C8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80800104;
    }
    goto skip_0;
    // 0x808000C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x808000CC: add.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f20.fl;
L_808000D0:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808000D8: jal         0x800EE7F8
    // 0x808000DC: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808000DC: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
    after_3:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x80088A80
    // 0x808000E8: lw          $a1, 0x38($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X38);
    _fxegg_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808000E8: lw          $a1, 0x38($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X38);
    after_4:
    // 0x808000EC: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x808000F0: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x808000F4: nop

    // 0x808000F8: bc1tl       L_808000D0
    if (c1cs) {
        // 0x808000FC: add.s       $f10, $f2, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f20.fl;
            goto L_808000D0;
    }
    goto skip_1;
    // 0x808000FC: add.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f20.fl;
    skip_1:
    // 0x80800100: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800104:
    // 0x80800104: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800108: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080010C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800110: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80800114: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80800118: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8080011C: jr          $ra
    // 0x80800120: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800120: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800F24D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F24D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F24D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F24D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F24DC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800F24E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F24E4: jal         0x800EE7F8
    // 0x800F24E8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800F24E8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800F24EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800F24F0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800F24F4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800F24F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_800F24FC:
    // 0x800F24FC: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F2500: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F2504: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F2508: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F250C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800F2510: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F2514: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F2518: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800F251C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F2520: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800F2524: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800F2528: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800F252C: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800F2530: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800F2534: bne         $v1, $a1, L_800F24FC
    if (ctx->r3 != ctx->r5) {
        // 0x800F2538: swc1        $f12, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f12.u32l;
            goto L_800F24FC;
    }
    // 0x800F2538: swc1        $f12, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f12.u32l;
    // 0x800F253C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F2540: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F2544: jr          $ra
    // 0x800F2548: nop

    return;
    // 0x800F2548: nop

;}
RECOMP_FUNC void func_80801E80_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801E84: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801E88: addu        $s2, $a0, $a1
    ctx->r18 = ADD32(ctx->r4, ctx->r5);
    // 0x80801E8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801E90: slt         $at, $a0, $s2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80801E94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801E98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801E9C: beq         $at, $zero, L_80801ED4
    if (ctx->r1 == 0) {
        // 0x80801EA0: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80801ED4;
    }
    // 0x80801EA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801EA4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2658, 0X20D8) << 16);
    // 0x80801EA8: addiu       $t7, $t7, 0x20D8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2658, 0X20D8));
    // 0x80801EAC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801EB0: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
L_80801EB4:
    // 0x80801EB4: jal         0x800D1A04
    // 0x80801EB8: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x80801EB8: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    after_0:
    // 0x80801EBC: beq         $v0, $zero, L_80801ECC
    if (ctx->r2 == 0) {
        // 0x80801EC0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801ECC;
    }
    // 0x80801EC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801EC4: b           L_80801ED8
    // 0x80801EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801ED8;
    // 0x80801EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801ECC:
    // 0x80801ECC: bne         $s0, $s2, L_80801EB4
    if (ctx->r16 != ctx->r18) {
        // 0x80801ED0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80801EB4;
    }
    // 0x80801ED0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80801ED4:
    // 0x80801ED4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801ED8:
    // 0x80801ED8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801EDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801EE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801EE4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801EE8: jr          $ra
    // 0x80801EEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801EEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800000_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800DA298
    // 0x80800014: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x80800018: beql        $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x8080001C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000A4;
    }
    goto skip_0;
    // 0x8080001C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800020: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x80800024: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800028: beql        $t6, $zero, L_80800070
    if (ctx->r14 == 0) {
        // 0x8080002C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800070;
    }
    goto skip_1;
    // 0x8080002C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80800030: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800034: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800038: jal         0x80085750
    // 0x8080003C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    _capod_entrypoint_22(rdram, ctx);
        goto after_1;
    // 0x8080003C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80800040: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800044: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80800048: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8080004C: jal         0x80085748
    // 0x80800050: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_21(rdram, ctx);
        goto after_2;
    // 0x80800050: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_2:
    // 0x80800054: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80800058: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x8080005C: jal         0x80101238
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101238(rdram, ctx);
        goto after_3;
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800064: b           L_808000A4
    // 0x80800068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000A4;
    // 0x80800068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080006C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800070:
    // 0x80800070: jal         0x80085750
    // 0x80800074: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    _capod_entrypoint_22(rdram, ctx);
        goto after_4;
    // 0x80800074: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x80800078: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080007C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80800080: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80800084: jal         0x80085748
    // 0x80800088: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_21(rdram, ctx);
        goto after_5;
    // 0x80800088: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_5:
    // 0x8080008C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800090: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x80800094: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x80800098: jal         0x80101238
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101238(rdram, ctx);
        goto after_6;
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A4:
    // 0x808000A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_80114C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114C9C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80114CA0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80114CA4: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80114CA8: jr          $ra
    // 0x80114CAC: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    return;
    // 0x80114CAC: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_800A8258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8258: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A825C: jr          $ra
    // 0x800A8260: lwc1        $f0, 0x7638($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7638);
    return;
    // 0x800A8260: lwc1        $f0, 0x7638($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7638);
;}
RECOMP_FUNC void func_80800378_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080037C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800380: jal         0x800903D0
    // 0x80800384: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800903D0(rdram, ctx);
        goto after_0;
    // 0x80800384: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80800388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080038C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800390: jr          $ra
    // 0x80800394: nop

    return;
    // 0x80800394: nop

;}
RECOMP_FUNC void _chmumboskulls_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865D0: syscall     344
    recomp_syscall_handler(rdram, ctx, 0x800865D0);
    return;
    // 0x800865D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800D2398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D239C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D23A0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D23A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D23A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D23AC: jal         0x800D21F0
    // 0x800D23B0: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    func_800D21F0(rdram, ctx);
        goto after_0;
    // 0x800D23B0: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    after_0:
    // 0x800D23B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D23B8: slti        $t7, $v0, 0x0
    ctx->r15 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800D23BC: xori        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 ^ 0X1;
    // 0x800D23C0: beq         $v0, $zero, L_800D23D8
    if (ctx->r2 == 0) {
        // 0x800D23C4: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_800D23D8;
    }
    // 0x800D23C4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800D23C8: jal         0x800FA8E8
    // 0x800D23CC: lbu         $a1, 0x1($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X1);
    func_800FA8E8(rdram, ctx);
        goto after_1;
    // 0x800D23CC: lbu         $a1, 0x1($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X1);
    after_1:
    // 0x800D23D0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800D23D4: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_800D23D8:
    // 0x800D23D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D23DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D23E0: jr          $ra
    // 0x800D23E4: nop

    return;
    // 0x800D23E4: nop

;}
RECOMP_FUNC void func_800C67E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67E8: jr          $ra
    // 0x800C67EC: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    return;
    // 0x800C67EC: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
;}
RECOMP_FUNC void _sumole_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A68: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A68);
    return;
    // 0x80089A6C: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void baphysics_set_vertical_velocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BA58: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BA5C: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BA60: jr          $ra
    // 0x8009BA64: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009BA64: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_808068AC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808068AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808068B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808068B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808068B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808068BC: jal         0x80802BE8
    // 0x808068C0: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    func_80802BE8_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808068C0: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    after_0:
    // 0x808068C4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808068C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808068CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808068D0: jal         0x80802640
    // 0x808068D4: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    func_80802640_chgameselect(rdram, ctx);
        goto after_1;
    // 0x808068D4: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    after_1:
    // 0x808068D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808068DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808068E0: jr          $ra
    // 0x808068E4: nop

    return;
    // 0x808068E4: nop

;}
RECOMP_FUNC void bstrexlarge_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801490: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801494: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X1A10) << 16);
    // 0x80801498: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080149C: jr          $ra
    // 0x808014A0: lw          $v0, 0x1A10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1A10));
    return;
    // 0x808014A0: lw          $v0, 0x1A10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1A10));
;}
RECOMP_FUNC void fxstep_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080045C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800464: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800468: jal         0x8001ACCC
    // 0x8080046C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080046C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x80800470: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800474: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800478: sb          $zero, 0x26($v0)
    MEM_B(0X26, ctx->r2) = 0;
    // 0x8080047C: jal         0x800C2E04
    // 0x80800480: sb          $t6, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r14;
    func_800C2E04(rdram, ctx);
        goto after_1;
    // 0x80800480: sb          $t6, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r14;
    after_1:
    // 0x80800484: sb          $v0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r2;
    // 0x80800488: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8080048C: jal         0x800C330C
    // 0x80800490: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_2;
    // 0x80800490: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800494: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    // 0x80800498: jal         0x800C3418
    // 0x8080049C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C3418(rdram, ctx);
        goto after_3;
    // 0x8080049C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808004A0: jal         0x800C2E04
    // 0x808004A4: nop

    func_800C2E04(rdram, ctx);
        goto after_4;
    // 0x808004A4: nop

    after_4:
    // 0x808004A8: sb          $v0, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r2;
    // 0x808004AC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808004B0: jal         0x800C330C
    // 0x808004B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_5;
    // 0x808004B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x808004B8: lbu         $a0, 0x25($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X25);
    // 0x808004BC: jal         0x800C3418
    // 0x808004C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C3418(rdram, ctx);
        goto after_6;
    // 0x808004C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808004C4: jal         0x800EFD24
    // 0x808004C8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_7;
    // 0x808004C8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004D4: jal         0x80800520
    // 0x808004D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    fxstep_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x808004D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004E4: jal         0x8080052C
    // 0x808004E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    fxstep_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x808004E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_9:
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004F4: jal         0x8080055C
    // 0x808004F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    fxstep_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x808004F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x808004FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800500: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800504: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800508: jr          $ra
    // 0x8080050C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080050C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8080022C_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080022C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800234: jal         0x80800000
    // 0x80800238: nop

    func_80800000_bskazglide(rdram, ctx);
        goto after_0;
    // 0x80800238: nop

    after_0:
    // 0x8080023C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void func_80800018_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080001C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: jal         0x800DA298
    // 0x80800028: addiu       $a0, $zero, 0xA02
    ctx->r4 = ADD32(0, 0XA02);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a0, $zero, 0xA02
    ctx->r4 = ADD32(0, 0XA02);
    after_0:
    // 0x8080002C: beq         $v0, $zero, L_8080004C
    if (ctx->r2 == 0) {
        // 0x80800030: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080004C;
    }
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: jal         0x80101FDC
    // 0x80800038: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x8080003C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800040: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800044: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800048: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
L_8080004C:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void func_800A5004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A500C: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A5010: lw          $t7, 0x3C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3C);
    // 0x800A5014: bnel        $t7, $zero, L_800A5038
    if (ctx->r15 != 0) {
        // 0x800A5018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A5038;
    }
    goto skip_0;
    // 0x800A5018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A501C: jal         0x800CA334
    // 0x800A5020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800CA334(rdram, ctx);
        goto after_0;
    // 0x800A5020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A5024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A5028: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x800A502C: jal         0x800A4E94
    // 0x800A5030: sw          $v0, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r2;
    func_800A4E94(rdram, ctx);
        goto after_1;
    // 0x800A5030: sw          $v0, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r2;
    after_1:
    // 0x800A5034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A5038:
    // 0x800A5038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A503C: jr          $ra
    // 0x800A5040: nop

    return;
    // 0x800A5040: nop

;}
RECOMP_FUNC void bssnowball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080019C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A8: jal         0x8009E74C
    // 0x808001AC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x808001AC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_0:
    // 0x808001B0: bne         $v0, $zero, L_80800220
    if (ctx->r2 != 0) {
        // 0x808001B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800220;
    }
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001BC: jal         0x800947EC
    // 0x808001C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_1;
    // 0x808001C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x8009BF5C
    // 0x808001CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_2;
    // 0x808001CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: jal         0x8009C4CC
    // 0x808001D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_3;
    // 0x808001D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808001DC: jal         0x8009C000
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C000(rdram, ctx);
        goto after_4;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001E4: jal         0x8009C570
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_resetAngularVelocity(rdram, ctx);
        goto after_5;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001EC: jal         0x8009EF60
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_6;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x80095774
    // 0x808001FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_clear(rdram, ctx);
        goto after_7;
    // 0x808001FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x80095774
    // 0x80800208: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    baflag_clear(rdram, ctx);
        goto after_8;
    // 0x80800208: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x8080020C: jal         0x800850E0
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basnowball_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x80092864
    // 0x8080021C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_10;
    // 0x8080021C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
L_80800220:
    // 0x80800220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800224: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800228: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080022C: jr          $ra
    // 0x80800230: nop

    return;
    // 0x80800230: nop

;}
RECOMP_FUNC void func_808001C0_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x808001C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001D8: beq         $a0, $at, L_8080034C
    if (ctx->r4 == ctx->r1) {
        // 0x808001DC: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8080034C;
    }
    // 0x808001DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808001E0: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x808001E4: beq         $a0, $at, L_80800218
    if (ctx->r4 == ctx->r1) {
        // 0x808001E8: lui         $a1, 0xC4AE
        ctx->r5 = S32(0XC4AE << 16);
            goto L_80800218;
    }
    // 0x808001E8: lui         $a1, 0xC4AE
    ctx->r5 = S32(0XC4AE << 16);
    // 0x808001EC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x808001F0: beq         $a0, $at, L_80800268
    if (ctx->r4 == ctx->r1) {
        // 0x808001F4: lui         $a1, 0x432E
        ctx->r5 = S32(0X432E << 16);
            goto L_80800268;
    }
    // 0x808001F4: lui         $a1, 0x432E
    ctx->r5 = S32(0X432E << 16);
    // 0x808001F8: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x808001FC: beq         $a0, $at, L_808002B8
    if (ctx->r4 == ctx->r1) {
        // 0x80800200: lui         $a1, 0xC48E
        ctx->r5 = S32(0XC48E << 16);
            goto L_808002B8;
    }
    // 0x80800200: lui         $a1, 0xC48E
    ctx->r5 = S32(0XC48E << 16);
    // 0x80800204: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x80800208: beq         $a0, $at, L_80800304
    if (ctx->r4 == ctx->r1) {
        // 0x8080020C: lui         $a1, 0x450F
        ctx->r5 = S32(0X450F << 16);
            goto L_80800304;
    }
    // 0x8080020C: lui         $a1, 0x450F
    ctx->r5 = S32(0X450F << 16);
    // 0x80800210: b           L_808003B4
    // 0x80800214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003B4;
    // 0x80800214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800218:
    // 0x80800218: lui         $a2, 0x45FB
    ctx->r6 = S32(0X45FB << 16);
    // 0x8080021C: ori         $a2, $a2, 0xF800
    ctx->r6 = ctx->r6 | 0XF800;
    // 0x80800220: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800224: ori         $a1, $a1, 0xA000
    ctx->r5 = ctx->r5 | 0XA000;
    // 0x80800228: jal         0x800EFA4C
    // 0x8080022C: lui         $a3, 0xC41E
    ctx->r7 = S32(0XC41E << 16);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x8080022C: lui         $a3, 0xC41E
    ctx->r7 = S32(0XC41E << 16);
    after_0:
    // 0x80800230: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800234: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800238: lui         $a1, 0x3F70
    ctx->r5 = S32(0X3F70 << 16);
    // 0x8080023C: lui         $a2, 0x3F3A
    ctx->r6 = S32(0X3F3A << 16);
    // 0x80800240: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800244: ori         $a2, $a2, 0xE148
    ctx->r6 = ctx->r6 | 0XE148;
    // 0x80800248: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x8080024C: jal         0x800EFA4C
    // 0x80800250: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x80800250: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800254: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x80800258: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080025C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800260: b           L_808003A4
    // 0x80800264: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
        goto L_808003A4;
    // 0x80800264: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
L_80800268:
    // 0x80800268: lui         $a2, 0x45FC
    ctx->r6 = S32(0X45FC << 16);
    // 0x8080026C: lui         $a3, 0xC47E
    ctx->r7 = S32(0XC47E << 16);
    // 0x80800270: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80800274: ori         $a2, $a2, 0x1000
    ctx->r6 = ctx->r6 | 0X1000;
    // 0x80800278: jal         0x800EFA4C
    // 0x8080027C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x8080027C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800280: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800284: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800288: lui         $a1, 0x3F70
    ctx->r5 = S32(0X3F70 << 16);
    // 0x8080028C: lui         $a2, 0x3F3A
    ctx->r6 = S32(0X3F3A << 16);
    // 0x80800290: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800294: ori         $a2, $a2, 0xE148
    ctx->r6 = ctx->r6 | 0XE148;
    // 0x80800298: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x8080029C: jal         0x800EFA4C
    // 0x808002A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x808002A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808002A4: lui         $at, 0x439C
    ctx->r1 = S32(0X439C << 16);
    // 0x808002A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002AC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808002B0: b           L_808003A4
    // 0x808002B4: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
        goto L_808003A4;
    // 0x808002B4: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
L_808002B8:
    // 0x808002B8: lui         $a2, 0x4506
    ctx->r6 = S32(0X4506 << 16);
    // 0x808002BC: lui         $a3, 0x450F
    ctx->r7 = S32(0X450F << 16);
    // 0x808002C0: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x808002C4: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x808002C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808002CC: jal         0x800EFA4C
    // 0x808002D0: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x808002D0: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    after_4:
    // 0x808002D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2280, 0X910) << 16);
    // 0x808002D8: lwc1        $f0, 0x910($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2280, 0X910));
    // 0x808002DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002E8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808002EC: jal         0x800EFA4C
    // 0x808002F0: nop

    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x808002F0: nop

    after_5:
    // 0x808002F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808002F8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808002FC: b           L_808003A4
    // 0x80800300: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
        goto L_808003A4;
    // 0x80800300: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
L_80800304:
    // 0x80800304: lui         $a2, 0x4505
    ctx->r6 = S32(0X4505 << 16);
    // 0x80800308: ori         $a2, $a2, 0xF000
    ctx->r6 = ctx->r6 | 0XF000;
    // 0x8080030C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800310: ori         $a1, $a1, 0xF000
    ctx->r5 = ctx->r5 | 0XF000;
    // 0x80800314: jal         0x800EFA4C
    // 0x80800318: lui         $a3, 0xC3BC
    ctx->r7 = S32(0XC3BC << 16);
    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x80800318: lui         $a3, 0xC3BC
    ctx->r7 = S32(0XC3BC << 16);
    after_6:
    // 0x8080031C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2280, 0X914) << 16);
    // 0x80800320: lwc1        $f0, 0x914($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2280, 0X914));
    // 0x80800324: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800328: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080032C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800330: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800334: jal         0x800EFA4C
    // 0x80800338: nop

    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x80800338: nop

    after_7:
    // 0x8080033C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800340: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800344: b           L_808003A4
    // 0x80800348: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
        goto L_808003A4;
    // 0x80800348: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
L_8080034C:
    // 0x8080034C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2280, 0X918) << 16);
    // 0x80800350: lwc1        $f0, 0x918($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2280, 0X918));
    // 0x80800354: lui         $a2, 0x44BA
    ctx->r6 = S32(0X44BA << 16);
    // 0x80800358: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x8080035C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800360: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800364: jal         0x800EFA4C
    // 0x80800368: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x80800368: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_8:
    // 0x8080036C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800370: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800374: lui         $a1, 0x3F91
    ctx->r5 = S32(0X3F91 << 16);
    // 0x80800378: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    // 0x8080037C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800380: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800384: jal         0x800EFA4C
    // 0x80800388: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80800388: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x8080038C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800390: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80800394: b           L_808003A4
    // 0x80800398: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
        goto L_808003A4;
    // 0x80800398: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
    // 0x8080039C: b           L_808003B4
    // 0x808003A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003B4;
    // 0x808003A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A4:
    // 0x808003A4: jal         0x8080015C
    // 0x808003A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080015C_chfactoryroofbits(rdram, ctx);
        goto after_10;
    // 0x808003A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_10:
    // 0x808003AC: jal         0x800DA298
    // 0x808003B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x808003B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
L_808003B4:
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003BC: jr          $ra
    // 0x808003C0: nop

    return;
    // 0x808003C0: nop

;}
RECOMP_FUNC void func_80107784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107784: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80107788: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010778C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80107790: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80107794: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80107798: lh          $a1, 0xA($a1)
    ctx->r5 = MEM_H(ctx->r5, 0XA);
    // 0x8010779C: jal         0x801073F8
    // 0x801077A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_801073F8(rdram, ctx);
        goto after_0;
    // 0x801077A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x801077A4: bne         $v0, $zero, L_801077B8
    if (ctx->r2 != 0) {
        // 0x801077A8: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_801077B8;
    }
    // 0x801077A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801077AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801077B0: jal         0x801078DC
    // 0x801077B4: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    func_801078DC(rdram, ctx);
        goto after_1;
    // 0x801077B4: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
L_801077B8:
    // 0x801077B8: jal         0x80089C90
    // 0x801077BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x801077BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801077C0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801077C4: bnel        $v0, $at, L_80107844
    if (ctx->r2 != ctx->r1) {
        // 0x801077C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80107844;
    }
    goto skip_0;
    // 0x801077C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801077CC: jal         0x800D90A4
    // 0x801077D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x801077D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x801077D4: beq         $v0, $zero, L_80107840
    if (ctx->r2 == 0) {
        // 0x801077D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80107840;
    }
    // 0x801077D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801077DC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801077E0: jal         0x80102F74
    // 0x801077E4: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    func_80102F74(rdram, ctx);
        goto after_4;
    // 0x801077E4: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    after_4:
    // 0x801077E8: lbu         $t9, 0x64($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X64);
    // 0x801077EC: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x801077F0: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801077F4: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x801077F8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x801077FC: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
    // 0x80107800: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x80107804: jal         0x80102F74
    // 0x80107808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102F74(rdram, ctx);
        goto after_5;
    // 0x80107808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8010780C: bnel        $v0, $zero, L_80107820
    if (ctx->r2 != 0) {
        // 0x80107810: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80107820;
    }
    goto skip_1;
    // 0x80107810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80107814: jal         0x8010A590
    // 0x80107818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_6;
    // 0x80107818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8010781C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80107820:
    // 0x80107820: jal         0x80102F74
    // 0x80107824: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    func_80102F74(rdram, ctx);
        goto after_7;
    // 0x80107824: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_7:
    // 0x80107828: beq         $v0, $zero, L_80107838
    if (ctx->r2 == 0) {
        // 0x8010782C: nop
    
            goto L_80107838;
    }
    // 0x8010782C: nop

    // 0x80107830: jal         0x8010A63C
    // 0x80107834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_8;
    // 0x80107834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80107838:
    // 0x80107838: b           L_80107844
    // 0x8010783C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80107844;
    // 0x8010783C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80107840:
    // 0x80107840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80107844:
    // 0x80107844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80107848: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010784C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80107850: jr          $ra
    // 0x80107854: nop

    return;
    // 0x80107854: nop

;}
RECOMP_FUNC void chpowerhut_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080000C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800014: jal         0x80100094
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080001C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800020: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    // 0x80800024: jal         0x80088278
    // 0x80800028: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800028: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080002C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800030: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800034: jal         0x800EE88C
    // 0x80800038: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_2:
    // 0x8080003C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800040: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800044: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800048: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8080004C: jal         0x800D9058
    // 0x80800050: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    func_800D9058(rdram, ctx);
        goto after_3;
    // 0x80800050: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80800054: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800058: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080005C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80800060: sh          $t7, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r15;
    // 0x80800064: sb          $zero, 0xE($s0)
    MEM_B(0XE, ctx->r16) = 0;
    // 0x80800068: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8080006C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: jal         0x800DA298
    // 0x80800074: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800074: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    after_4:
    // 0x80800078: bnel        $v0, $zero, L_80800094
    if (ctx->r2 != 0) {
        // 0x8080007C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800094;
    }
    goto skip_0;
    // 0x8080007C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800080: jal         0x80088848
    // 0x80800084: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x80800084: nop

    after_5:
    // 0x80800088: beql        $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x8080008C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000BC;
    }
    goto skip_1;
    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800090: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800094:
    // 0x80800094: jal         0x80101FDC
    // 0x80800098: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800098: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x8080009C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000A4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x808000A8: sh          $t9, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r25;
    // 0x808000AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000B0: b           L_808000BC
    // 0x808000B4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
        goto L_808000BC;
    // 0x808000B4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x808000B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000BC:
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_80800C20_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800C2C: jal         0x8010D254
    // 0x80800C30: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800C30: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800C34: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80800C38: jal         0x800F1EA4
    // 0x80800C3C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F1EA4(rdram, ctx);
        goto after_1;
    // 0x80800C3C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800C40: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800C44: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800C48: jal         0x800F20BC
    // 0x80800C4C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    func_800F20BC(rdram, ctx);
        goto after_2;
    // 0x80800C4C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_2:
    // 0x80800C50: bne         $v0, $zero, L_80800C60
    if (ctx->r2 != 0) {
        // 0x80800C54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800C60;
    }
    // 0x80800C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C58: b           L_80800C64
    // 0x80800C5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C64;
    // 0x80800C5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C60:
    // 0x80800C60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C64:
    // 0x80800C64: jr          $ra
    // 0x80800C68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800C68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8008E0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E0C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E0CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E0D0: jal         0x80084768
    // 0x8008E0D4: nop

    _bapackctrl_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8008E0D4: nop

    after_0:
    // 0x8008E0D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E0DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E0E0: jr          $ra
    // 0x8008E0E4: nop

    return;
    // 0x8008E0E4: nop

;}
RECOMP_FUNC void func_8001DA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DA58: jr          $ra
    // 0x8001DA5C: nop

    return;
    // 0x8001DA5C: nop

;}
RECOMP_FUNC void _gcintrotext_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880E8: syscall     671
    recomp_syscall_handler(rdram, ctx, 0x800880E8);
    return;
    // 0x800880EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080032C_chgoldstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800330: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2136, 0X910) << 16);
    // 0x80800334: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800338: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8080033C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800340: addiu       $t7, $t7, 0x910
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2136, 0X910));
    // 0x80800344: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800348: addiu       $t6, $sp, 0x64
    ctx->r14 = ADD32(ctx->r29, 0X64);
    // 0x8080034C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800350: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800354: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800358: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2136, 0X91C) << 16);
    // 0x8080035C: addiu       $t2, $t2, 0x91C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2136, 0X91C));
    // 0x80800360: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800364: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800368: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8080036C: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // 0x80800370: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80800374: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80800378: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8080037C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2136, 0X928) << 16);
    // 0x80800380: addiu       $t8, $t8, 0x928
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2136, 0X928));
    // 0x80800384: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80800388: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8080038C: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80800390: addiu       $t9, $sp, 0x40
    ctx->r25 = ADD32(ctx->r29, 0X40);
    // 0x80800394: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80800398: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8080039C: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x808003A0: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2136, 0X934) << 16);
    // 0x808003A4: addiu       $t3, $t3, 0x934
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2136, 0X934));
    // 0x808003A8: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x808003AC: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x808003B0: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x808003B4: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x808003B8: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x808003BC: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x808003C0: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x808003C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808003C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003CC: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x808003D0: jal         0x80100094
    // 0x808003D4: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003D4: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    after_0:
    // 0x808003D8: lw          $t7, 0x7C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C);
    // 0x808003DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003E4: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x808003E8: bgez        $t9, L_80800514
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808003EC: addiu       $a2, $sp, 0x58
        ctx->r6 = ADD32(ctx->r29, 0X58);
            goto L_80800514;
    }
    // 0x808003EC: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x808003F0: jal         0x8008A0E0
    // 0x808003F4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808003F4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x808003F8: addiu       $t8, $sp, 0x40
    ctx->r24 = ADD32(ctx->r29, 0X40);
    // 0x808003FC: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x80800400: addiu       $t2, $sp, 0x64
    ctx->r10 = ADD32(ctx->r29, 0X64);
    // 0x80800404: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80800408: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8080040C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: lui         $a1, 0x432F
    ctx->r5 = S32(0X432F << 16);
    // 0x80800418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080041C: jal         0x80089878
    // 0x80800420: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800420: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_2:
    // 0x80800424: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800428: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080042C: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x80800430: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x80800434: addiu       $t3, $sp, 0x58
    ctx->r11 = ADD32(ctx->r29, 0X58);
    // 0x80800438: addiu       $t5, $sp, 0x64
    ctx->r13 = ADD32(ctx->r29, 0X64);
    // 0x8080043C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800440: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800444: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80800448: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8080044C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800450: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: jal         0x80089870
    // 0x8080045C: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x8080045C: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    after_3:
    // 0x80800460: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x80800464: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x80800468: addiu       $t9, $sp, 0x58
    ctx->r25 = ADD32(ctx->r29, 0X58);
    // 0x8080046C: addiu       $t8, $sp, 0x64
    ctx->r24 = ADD32(ctx->r29, 0X64);
    // 0x80800470: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80800474: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80800478: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8080047C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x80800488: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8080048C: jal         0x80089870
    // 0x80800490: addiu       $a3, $zero, 0x24
    ctx->r7 = ADD32(0, 0X24);
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800490: addiu       $a3, $zero, 0x24
    ctx->r7 = ADD32(0, 0X24);
    after_4:
    // 0x80800494: jal         0x800898B0
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080049C: lhu         $t0, 0x72($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X72);
    // 0x808004A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004A4: srl         $t2, $t0, 10
    ctx->r10 = S32(U32(ctx->r8) >> 10);
    // 0x808004A8: bnel        $t2, $at, L_80800518
    if (ctx->r10 != ctx->r1) {
        // 0x808004AC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800518;
    }
    goto skip_0;
    // 0x808004AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808004B0: jal         0x800898E8
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_6;
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808004B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808004C4: nop

    // 0x808004C8: bc1fl       L_80800518
    if (!c1cs) {
        // 0x808004CC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800518;
    }
    goto skip_1;
    // 0x808004CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x808004D0: jal         0x80089868
    // 0x808004D4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x808004D4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_7:
    // 0x808004D8: beq         $v0, $zero, L_80800514
    if (ctx->r2 == 0) {
        // 0x808004DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800514;
    }
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: jal         0x800898C8
    // 0x808004E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_8;
    // 0x808004E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x808004E8: jal         0x800DA298
    // 0x808004EC: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808004EC: addiu       $a0, $zero, 0x57C
    ctx->r4 = ADD32(0, 0X57C);
    after_9:
    // 0x808004F0: bne         $v0, $zero, L_8080050C
    if (ctx->r2 != 0) {
        // 0x808004F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080050C;
    }
    // 0x808004F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004FC: jal         0x80800150
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800150_chgoldstatue(rdram, ctx);
        goto after_10;
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800504: b           L_80800518
    // 0x80800508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800518;
    // 0x80800508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080050C:
    // 0x8080050C: jal         0x80800150
    // 0x80800510: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800150_chgoldstatue(rdram, ctx);
        goto after_11;
    // 0x80800510: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
L_80800514:
    // 0x80800514: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800518:
    // 0x80800518: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8080051C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800520: jr          $ra
    // 0x80800524: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800524: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800F9178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9178: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F917C: jr          $ra
    // 0x800F9180: sb          $zero, 0x54FA($at)
    MEM_B(0X54FA, ctx->r1) = 0;
    return;
    // 0x800F9180: sb          $zero, 0x54FA($at)
    MEM_B(0X54FA, ctx->r1) = 0;
;}
