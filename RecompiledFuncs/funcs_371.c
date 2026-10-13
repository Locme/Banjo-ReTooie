#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800914_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800914: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800918: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080091C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800920: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x80800924: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800928: bnel        $a2, $zero, L_80800954
    if (ctx->r6 != 0) {
        // 0x8080092C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800954;
    }
    goto skip_0;
    // 0x8080092C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x80800930: jal         0x800C8A98
    // 0x80800934: nop

    func_800C8A98(rdram, ctx);
        goto after_0;
    // 0x80800934: nop

    after_0:
    // 0x80800938: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8080093C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800940: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800944: jal         0x800C8E54
    // 0x80800948: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    func_800C8E54(rdram, ctx);
        goto after_1;
    // 0x80800948: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_1:
    // 0x8080094C: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    // 0x80800950: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80800954:
    // 0x80800954: jal         0x800C8CB8
    // 0x80800958: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_2;
    // 0x80800958: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x8080095C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1264, 0X10E0) << 16);
    // 0x80800960: lwc1        $f12, 0x10E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1264, 0X10E0));
    // 0x80800964: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800968: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080096C: jal         0x800DC178
    // 0x80800970: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800970: nop

    after_3:
    // 0x80800974: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1264, 0X1100) << 16);
    // 0x80800978: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080097C: addiu       $a1, $a1, 0x1100
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1264, 0X1100));
    // 0x80800980: jal         0x800F2F60
    // 0x80800984: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800F2F60(rdram, ctx);
        goto after_4;
    // 0x80800984: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80800988: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8080098C: jal         0x800C8E84
    // 0x80800990: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C8E84(rdram, ctx);
        goto after_5;
    // 0x80800990: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80800994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800998: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080099C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808009A0: jr          $ra
    // 0x808009A4: nop

    return;
    // 0x808009A4: nop

;}
RECOMP_FUNC void baanim_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C764: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008C768: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008C76C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008C770: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008C774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008C778: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008C77C: jal         0x8008AD80
    // 0x8008C780: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    func_8008AD80(rdram, ctx);
        goto after_0;
    // 0x8008C780: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    after_0:
    // 0x8008C784: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008C788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008C78C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8008C790: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008C794: jal         0x8008B1A0
    // 0x8008C798: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_1;
    // 0x8008C798: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x8008C79C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8008C7A0: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8008C7A4: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8008C7A8: jal         0x8008B304
    // 0x8008C7AC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_8008B304(rdram, ctx);
        goto after_2;
    // 0x8008C7AC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_2:
    // 0x8008C7B0: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8008C7B4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8008C7B8: addiu       $a1, $a1, -0x3B24
    ctx->r5 = ADD32(ctx->r5, -0X3B24);
    // 0x8008C7BC: jal         0x8008AEE4
    // 0x8008C7C0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_8008AEE4(rdram, ctx);
        goto after_3;
    // 0x8008C7C0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_3:
    // 0x8008C7C4: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8008C7C8: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    // 0x8008C7CC: jal         0x8008AF04
    // 0x8008C7D0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    func_8008AF04(rdram, ctx);
        goto after_4;
    // 0x8008C7D0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_4:
    // 0x8008C7D4: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8008C7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C7DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008C7E0: jal         0x8008CA4C
    // 0x8008C7E4: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    func_8008CA4C(rdram, ctx);
        goto after_5;
    // 0x8008C7E4: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    after_5:
    // 0x8008C7E8: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x8008C7EC: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x8008C7F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C7F4: jal         0x8008C9BC
    // 0x8008C7F8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_6;
    // 0x8008C7F8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_6:
    // 0x8008C7FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8008C800: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008C804: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8008C808: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8008C80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C810: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8008C814: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x8008C818: jal         0x8008C9F0
    // 0x8008C81C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_7;
    // 0x8008C81C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x8008C820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C824: jal         0x8008C9E4
    // 0x8008C828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008C9E4(rdram, ctx);
        goto after_8;
    // 0x8008C828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8008C82C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C830: jal         0x8008C984
    // 0x8008C834: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8008C984(rdram, ctx);
        goto after_9;
    // 0x8008C834: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x8008C838: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x8008C83C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008C840: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008C844: sb          $zero, 0x38($t4)
    MEM_B(0X38, ctx->r12) = 0;
    // 0x8008C848: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x8008C84C: swc1        $f6, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f6.u32l;
    // 0x8008C850: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008C854: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008C858: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008C85C: jr          $ra
    // 0x8008C860: nop

    return;
    // 0x8008C860: nop

;}
RECOMP_FUNC void _chfireimp_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865C8: syscall     343
    recomp_syscall_handler(rdram, ctx, 0x800865C8);
    return;
    // 0x800865CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8008C9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C9D8: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008C9DC: jr          $ra
    // 0x8008C9E0: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    return;
    // 0x8008C9E0: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80081744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081744: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80081748: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008174C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80081750: addiu       $s0, $s0, 0x7C60
    ctx->r16 = ADD32(ctx->r16, 0X7C60);
    // 0x80081754: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80081758: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008175C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80081760: beq         $t6, $zero, L_80081784
    if (ctx->r14 == 0) {
        // 0x80081764: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_80081784;
    }
    // 0x80081764: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80081768: addiu       $s1, $s1, 0x6738
    ctx->r17 = ADD32(ctx->r17, 0X6738);
    // 0x8008176C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_80081770:
    // 0x80081770: jal         0x800819E4
    // 0x80081774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ovl_unload(rdram, ctx);
        goto after_0;
    // 0x80081774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80081778: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8008177C: bnel        $t7, $zero, L_80081770
    if (ctx->r15 != 0) {
        // 0x80081780: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_80081770;
    }
    goto skip_0;
    // 0x80081780: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_0:
L_80081784:
    // 0x80081784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80081788: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008178C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80081790: jr          $ra
    // 0x80081794: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80081794: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800EFD3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFD3C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800EFD40: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800EFD44: jr          $ra
    // 0x800EFD48: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x800EFD48: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void chcablespark_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(968, 0XB88) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(968, 0XB88));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xB88
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(968, 0XB88));
;}
RECOMP_FUNC void func_80800000_chstatictorch(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x80800010: jal         0x80101870
    // 0x80800014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800018: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x8080001C: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800020: bgezl       $t8, L_80800080
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800024: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800080;
    }
    goto skip_0;
    // 0x80800024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800028: jal         0x80104130
    // 0x8080002C: nop

    func_80104130(rdram, ctx);
        goto after_1;
    // 0x8080002C: nop

    after_1:
    // 0x80800030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800034: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800038: jal         0x800DBEFC
    // 0x8080003C: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x80800040: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800044: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800048: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800054: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800058: jal         0x80100094
    // 0x8080005C: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x8080005C: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x80800060: beq         $v0, $zero, L_8080007C
    if (ctx->r2 == 0) {
        // 0x80800064: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080007C;
    }
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: jal         0x80100094
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800070: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800074: jal         0x80089940
    // 0x80800078: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _suflamefx_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800078: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
L_8080007C:
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
RECOMP_FUNC void _chnests_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AB0: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085AB0);
    return;
    // 0x80085AB4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800F32D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F32D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F32D8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800F32DC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F32E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F32E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800F32E8: div.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800F32EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F32F0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x800F32F4: nop

    // 0x800F32F8: bc1fl       L_800F3308
    if (!c1cs) {
        // 0x800F32FC: mfc1        $a3, $f2
        ctx->r7 = (int32_t)ctx->f2.u32l;
            goto L_800F3308;
    }
    goto skip_0;
    // 0x800F32FC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    skip_0:
    // 0x800F3300: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x800F3304: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
L_800F3308:
    // 0x800F3308: jal         0x800F3214
    // 0x800F330C: nop

    func_800F3214(rdram, ctx);
        goto after_0;
    // 0x800F330C: nop

    after_0:
    // 0x800F3310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F3314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F3318: jr          $ra
    // 0x800F331C: nop

    return;
    // 0x800F331C: nop

;}
RECOMP_FUNC void func_80112570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80112574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80112578: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8011257C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80112580: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    // 0x80112584: jal         0x800EE7F8
    // 0x80112588: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80112588: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x8011258C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80112590: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80112594: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80112598: swc1        $f4, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f4.u32l;
    // 0x8011259C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801125A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801125A4: jr          $ra
    // 0x801125A8: nop

    return;
    // 0x801125A8: nop

    // 0x801125AC: nop

;}
RECOMP_FUNC void func_8010E390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010E394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E398: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010E39C: jal         0x800B3370
    // 0x8010E3A0: lw          $a0, 0x7074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7074);
    func_800B3370(rdram, ctx);
        goto after_0;
    // 0x8010E3A0: lw          $a0, 0x7074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7074);
    after_0:
    // 0x8010E3A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010E3A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010E3AC: sw          $zero, 0x7074($at)
    MEM_W(0X7074, ctx->r1) = 0;
    // 0x8010E3B0: jr          $ra
    // 0x8010E3B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010E3B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800CF01C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF01C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CF020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF024: jal         0x800CEAA8
    // 0x800CF028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEAA8(rdram, ctx);
        goto after_0;
    // 0x800CF028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CF02C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800CF030: lh          $t6, -0x4E98($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4E98);
    // 0x800CF034: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF038: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800CF03C: jal         0x800CEA60
    // 0x800CF040: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_800CEA60(rdram, ctx);
        goto after_1;
    // 0x800CF040: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_1:
    // 0x800CF044: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CF048: jal         0x800CEF00
    // 0x800CF04C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800CEF00(rdram, ctx);
        goto after_2;
    // 0x800CF04C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800CF050: jal         0x800CF580
    // 0x800CF054: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800CF580(rdram, ctx);
        goto after_3;
    // 0x800CF054: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800CF058: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CF05C: bne         $v0, $zero, L_800CF074
    if (ctx->r2 != 0) {
        // 0x800CF060: lwc1        $f12, 0x18($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
            goto L_800CF074;
    }
    // 0x800CF060: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800CF064: jal         0x800CE864
    // 0x800CF068: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CE864(rdram, ctx);
        goto after_4;
    // 0x800CF068: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800CF06C: b           L_800CF154
    // 0x800CF070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CF154;
    // 0x800CF070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CF074:
    // 0x800CF074: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800CF078: bne         $t8, $zero, L_800CF0CC
    if (ctx->r24 != 0) {
        // 0x800CF07C: nop
    
            goto L_800CF0CC;
    }
    // 0x800CF07C: nop

    // 0x800CF080: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800CF084: nop

    // 0x800CF088: bc1f        L_800CF0CC
    if (!c1cs) {
        // 0x800CF08C: nop
    
            goto L_800CF0CC;
    }
    // 0x800CF08C: nop

    // 0x800CF090: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800CF094: jal         0x800D8FF8
    // 0x800CF098: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x800CF098: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_5:
    // 0x800CF09C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CF0A0: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800CF0A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF0A8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800CF0AC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800CF0B0: nop

    // 0x800CF0B4: bc1fl       L_800CF0C4
    if (!c1cs) {
        // 0x800CF0B8: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_800CF0C4;
    }
    goto skip_0;
    // 0x800CF0B8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_0:
    // 0x800CF0BC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800CF0C0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_800CF0C4:
    // 0x800CF0C4: jal         0x800CE980
    // 0x800CF0C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE980(rdram, ctx);
        goto after_6;
    // 0x800CF0C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_800CF0CC:
    // 0x800CF0CC: jal         0x800CEA84
    // 0x800CF0D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEA84(rdram, ctx);
        goto after_7;
    // 0x800CF0D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x800CF0D4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800CF0D8: lh          $t9, -0x4E96($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4E96);
    // 0x800CF0DC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800CF0E0: beql        $v0, $t9, L_800CF154
    if (ctx->r2 == ctx->r25) {
        // 0x800CF0E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF154;
    }
    goto skip_1;
    // 0x800CF0E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800CF0E8: jal         0x800CF640
    // 0x800CF0EC: nop

    func_800CF640(rdram, ctx);
        goto after_8;
    // 0x800CF0EC: nop

    after_8:
    // 0x800CF0F0: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800CF0F4: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800CF0F8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CF0FC: addiu       $t1, $t1, -0x5580
    ctx->r9 = ADD32(ctx->r9, -0X5580);
    // 0x800CF100: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800CF104: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800CF108: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800CF10C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CF110: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x800CF114: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800CF118: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800CF11C: nop

    // 0x800CF120: bc1f        L_800CF13C
    if (!c1cs) {
        // 0x800CF124: nop
    
            goto L_800CF13C;
    }
    // 0x800CF124: nop

    // 0x800CF128: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800CF12C: jal         0x800C3FF0
    // 0x800CF130: nop

    func_800C3FF0(rdram, ctx);
        goto after_9;
    // 0x800CF130: nop

    after_9:
    // 0x800CF134: b           L_800CF148
    // 0x800CF138: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
        goto L_800CF148;
    // 0x800CF138: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_800CF13C:
    // 0x800CF13C: jal         0x800FC63C
    // 0x800CF140: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800FC63C(rdram, ctx);
        goto after_10;
    // 0x800CF140: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_10:
    // 0x800CF144: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_800CF148:
    // 0x800CF148: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CF14C: sh          $t2, -0x4E96($at)
    MEM_H(-0X4E96, ctx->r1) = ctx->r10;
    // 0x800CF150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CF154:
    // 0x800CF154: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CF158: jr          $ra
    // 0x800CF15C: nop

    return;
    // 0x800CF15C: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B10: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089B10);
    return;
    // 0x80089B14: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void fxrain_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F8: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x808002FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800300: beql        $v1, $t6, L_80800314
    if (ctx->r3 == ctx->r14) {
        // 0x80800304: lbu         $v0, 0x30($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X30);
            goto L_80800314;
    }
    goto skip_0;
    // 0x80800304: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    skip_0:
    // 0x80800308: jr          $ra
    // 0x8080030C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8080030C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800310: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
L_80800314:
    // 0x80800314: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800318: beq         $v0, $v1, L_80800338
    if (ctx->r2 == ctx->r3) {
        // 0x8080031C: nop
    
            goto L_80800338;
    }
    // 0x8080031C: nop

    // 0x80800320: beq         $v0, $at, L_80800338
    if (ctx->r2 == ctx->r1) {
        // 0x80800324: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800338;
    }
    // 0x80800324: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800328: beq         $v0, $at, L_80800340
    if (ctx->r2 == ctx->r1) {
        // 0x8080032C: nop
    
            goto L_80800340;
    }
    // 0x8080032C: nop

    // 0x80800330: b           L_80800374
    // 0x80800334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800374;
    // 0x80800334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800338:
    // 0x80800338: jr          $ra
    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800340:
    // 0x80800340: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8D4) << 16);
    // 0x80800344: lwc1        $f6, 0x8D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8D4));
    // 0x80800348: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8080034C: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80800350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800354: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800358: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8080035C: nop

    // 0x80800360: bc1f        L_8080036C
    if (!c1cs) {
        // 0x80800364: nop
    
            goto L_8080036C;
    }
    // 0x80800364: nop

    // 0x80800368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080036C:
    // 0x8080036C: jr          $ra
    // 0x80800370: nop

    return;
    // 0x80800370: nop

L_80800374:
    // 0x80800374: jr          $ra
    // 0x80800378: nop

    return;
    // 0x80800378: nop

;}
RECOMP_FUNC void bsbbuster_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001B0: jal         0x8009BC6C
    // 0x808001B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x808001B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001B8: jal         0x8009BC90
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_1;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: jal         0x800A0CF4
    // 0x808001C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x808001C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80095774
    // 0x808001D4: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    baflag_clear(rdram, ctx);
        goto after_3;
    // 0x808001D4: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_3:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x80095774
    // 0x808001E0: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    baflag_clear(rdram, ctx);
        goto after_4;
    // 0x808001E0: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_4:
    // 0x808001E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void func_80800074_suquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800078: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8080007C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80800080: sll         $t7, $a2, 3
    ctx->r15 = S32(ctx->r6 << 3);
    // 0x80800084: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800088: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0X1050) << 16);
    // 0x8080008C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800090: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800094: jr          $ra
    // 0x80800098: lwc1        $f0, 0x1050($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3370, 0X1050));
    return;
    // 0x80800098: lwc1        $f0, 0x1050($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3370, 0X1050));
;}
RECOMP_FUNC void func_800AD894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD894: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x800AD898: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800AD89C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800AD8A0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800AD8A4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800AD8A8: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800AD8AC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800AD8B0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800AD8B4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800AD8B8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800AD8BC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800AD8C0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800AD8C4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800AD8C8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800AD8CC: sw          $a0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r4;
    // 0x800AD8D0: addiu       $t1, $sp, 0x104
    ctx->r9 = ADD32(ctx->r29, 0X104);
    // 0x800AD8D4: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800AD8D8: addiu       $t0, $sp, 0xF8
    ctx->r8 = ADD32(ctx->r29, 0XF8);
    // 0x800AD8DC: addiu       $v0, $sp, 0x104
    ctx->r2 = ADD32(ctx->r29, 0X104);
    // 0x800AD8E0: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800AD8E4: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
L_800AD8E8:
    // 0x800AD8E8: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800AD8EC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800AD8F0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800AD8F4: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800AD8F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AD8FC: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800AD900: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800AD904: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AD908: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800AD90C: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800AD910: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800AD914: nop

    // 0x800AD918: sw          $t7, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r15;
    // 0x800AD91C: lwc1        $f18, -0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X4);
    // 0x800AD920: lwc1        $f16, -0x4($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, -0X4);
    // 0x800AD924: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AD928: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800AD92C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800AD930: bne         $at, $zero, L_800AD8E8
    if (ctx->r1 != 0) {
        // 0x800AD934: sw          $t9, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r25;
            goto L_800AD8E8;
    }
    // 0x800AD934: sw          $t9, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r25;
    // 0x800AD938: addiu       $t1, $sp, 0x104
    ctx->r9 = ADD32(ctx->r29, 0X104);
    // 0x800AD93C: addiu       $t0, $sp, 0xF8
    ctx->r8 = ADD32(ctx->r29, 0XF8);
    // 0x800AD940: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
    // 0x800AD944: addiu       $a1, $sp, 0xF8
    ctx->r5 = ADD32(ctx->r29, 0XF8);
L_800AD948:
    // 0x800AD948: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800AD94C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800AD950: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800AD954: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AD958: beql        $at, $zero, L_800AD96C
    if (ctx->r1 == 0) {
        // 0x800AD95C: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_800AD96C;
    }
    goto skip_0;
    // 0x800AD95C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    skip_0:
    // 0x800AD960: b           L_800AD96C
    // 0x800AD964: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_800AD96C;
    // 0x800AD964: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800AD968: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_800AD96C:
    // 0x800AD96C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AD970: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x800AD974: bne         $at, $zero, L_800AD948
    if (ctx->r1 != 0) {
        // 0x800AD978: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_800AD948;
    }
    // 0x800AD978: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800AD97C: addiu       $t1, $sp, 0x104
    ctx->r9 = ADD32(ctx->r29, 0X104);
    // 0x800AD980: addiu       $t0, $sp, 0xF8
    ctx->r8 = ADD32(ctx->r29, 0XF8);
    // 0x800AD984: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x800AD988: addiu       $a1, $sp, 0xEC
    ctx->r5 = ADD32(ctx->r29, 0XEC);
L_800AD98C:
    // 0x800AD98C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800AD990: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800AD994: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800AD998: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800AD99C: beql        $at, $zero, L_800AD9B0
    if (ctx->r1 == 0) {
        // 0x800AD9A0: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_800AD9B0;
    }
    goto skip_1;
    // 0x800AD9A0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    skip_1:
    // 0x800AD9A4: b           L_800AD9B0
    // 0x800AD9A8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_800AD9B0;
    // 0x800AD9A8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800AD9AC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_800AD9B0:
    // 0x800AD9B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AD9B4: bne         $a0, $a1, L_800AD98C
    if (ctx->r4 != ctx->r5) {
        // 0x800AD9B8: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_800AD98C;
    }
    // 0x800AD9B8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800AD9BC: addiu       $t4, $sp, 0x120
    ctx->r12 = ADD32(ctx->r29, 0X120);
    // 0x800AD9C0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800AD9C4: lw          $a0, 0x130($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X130);
    // 0x800AD9C8: addiu       $a1, $sp, 0xEC
    ctx->r5 = ADD32(ctx->r29, 0XEC);
    // 0x800AD9CC: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x800AD9D0: jal         0x800AA7FC
    // 0x800AD9D4: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    func_800AA7FC(rdram, ctx);
        goto after_0;
    // 0x800AD9D4: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    after_0:
    // 0x800AD9D8: jal         0x800B2190
    // 0x800AD9DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2190(rdram, ctx);
        goto after_1;
    // 0x800AD9DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800AD9E0: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x800AD9E4: lw          $t5, 0x120($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X120);
    // 0x800AD9E8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800AD9EC: lwc1        $f20, 0x148($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AD9F0: sltu        $at, $t0, $t5
    ctx->r1 = ctx->r8 < ctx->r13 ? 1 : 0;
    // 0x800AD9F4: beq         $at, $zero, L_800ADC8C
    if (ctx->r1 == 0) {
        // 0x800AD9F8: addiu       $fp, $sp, 0xBC
        ctx->r30 = ADD32(ctx->r29, 0XBC);
            goto L_800ADC8C;
    }
    // 0x800AD9F8: addiu       $fp, $sp, 0xBC
    ctx->r30 = ADD32(ctx->r29, 0XBC);
    // 0x800AD9FC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800ADA00: addiu       $s7, $sp, 0xB0
    ctx->r23 = ADD32(ctx->r29, 0XB0);
    // 0x800ADA04: addiu       $s6, $sp, 0xA4
    ctx->r22 = ADD32(ctx->r29, 0XA4);
    // 0x800ADA08: addiu       $s4, $sp, 0xC8
    ctx->r20 = ADD32(ctx->r29, 0XC8);
    // 0x800ADA0C: addiu       $s2, $sp, 0xD4
    ctx->r18 = ADD32(ctx->r29, 0XD4);
    // 0x800ADA10: lw          $t2, 0x130($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X130);
    // 0x800ADA14: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800ADA18: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
L_800ADA1C:
    // 0x800ADA1C: lhu         $t9, 0x10($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X10);
    // 0x800ADA20: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x800ADA24: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x800ADA28: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800ADA2C: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADA30: mflo        $t7
    ctx->r15 = lo;
    // 0x800ADA34: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x800ADA38: addu        $v0, $t8, $t4
    ctx->r2 = ADD32(ctx->r24, ctx->r12);
    // 0x800ADA3C: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADA40: addiu       $s5, $v0, 0x18
    ctx->r21 = ADD32(ctx->r2, 0X18);
    // 0x800ADA44: mflo        $t6
    ctx->r14 = lo;
    // 0x800ADA48: addu        $a3, $t6, $s5
    ctx->r7 = ADD32(ctx->r14, ctx->r21);
    // 0x800ADA4C: sltu        $at, $s5, $a3
    ctx->r1 = ctx->r21 < ctx->r7 ? 1 : 0;
    // 0x800ADA50: beql        $at, $zero, L_800ADC7C
    if (ctx->r1 == 0) {
        // 0x800ADA54: lw          $t9, 0x120($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X120);
            goto L_800ADC7C;
    }
    goto skip_2;
    // 0x800ADA54: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    skip_2:
    // 0x800ADA58: sw          $a3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r7;
    // 0x800ADA5C: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    // 0x800ADA60: lhu         $t7, 0x0($s5)
    ctx->r15 = MEM_HU(ctx->r21, 0X0);
L_800ADA64:
    // 0x800ADA64: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800ADA68: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800ADA6C: addu        $a1, $t9, $s3
    ctx->r5 = ADD32(ctx->r25, ctx->r19);
    // 0x800ADA70: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x800ADA74: sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
    // 0x800ADA78: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    // 0x800ADA7C: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    // 0x800ADA80: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    // 0x800ADA84: sw          $v0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r2;
    // 0x800ADA88: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x800ADA8C: sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // 0x800ADA90: jal         0x800EE8CC
    // 0x800ADA94: sw          $v0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r2;
    func_800EE8CC(rdram, ctx);
        goto after_2;
    // 0x800ADA94: sw          $v0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r2;
    after_2:
    // 0x800ADA98: addiu       $s1, $s5, 0x2
    ctx->r17 = ADD32(ctx->r21, 0X2);
    // 0x800ADA9C: addiu       $s0, $sp, 0xB0
    ctx->r16 = ADD32(ctx->r29, 0XB0);
L_800ADAA0:
    // 0x800ADAA0: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    // 0x800ADAA4: addiu       $a1, $sp, 0xD4
    ctx->r5 = ADD32(ctx->r29, 0XD4);
    // 0x800ADAA8: addiu       $v1, $sp, 0xC8
    ctx->r3 = ADD32(ctx->r29, 0XC8);
    // 0x800ADAAC: sll         $t4, $t8, 4
    ctx->r12 = S32(ctx->r24 << 4);
    // 0x800ADAB0: addu        $a2, $t4, $s3
    ctx->r6 = ADD32(ctx->r12, ctx->r19);
    // 0x800ADAB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800ADAB8:
    // 0x800ADAB8: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800ADABC: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800ADAC0: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800ADAC4: beql        $at, $zero, L_800ADAD8
    if (ctx->r1 == 0) {
        // 0x800ADAC8: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_800ADAD8;
    }
    goto skip_3;
    // 0x800ADAC8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x800ADACC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800ADAD0: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800ADAD4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_800ADAD8:
    // 0x800ADAD8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800ADADC: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800ADAE0: beql        $at, $zero, L_800ADAF0
    if (ctx->r1 == 0) {
        // 0x800ADAE4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800ADAF0;
    }
    goto skip_4;
    // 0x800ADAE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_4:
    // 0x800ADAE8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800ADAEC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800ADAF0:
    // 0x800ADAF0: bne         $v1, $s2, L_800ADAB8
    if (ctx->r3 != ctx->r18) {
        // 0x800ADAF4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800ADAB8;
    }
    // 0x800ADAF4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800ADAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ADAFC: jal         0x800EE8CC
    // 0x800ADB00: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE8CC(rdram, ctx);
        goto after_3;
    // 0x800ADB00: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x800ADB04: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800ADB08: bne         $s0, $s4, L_800ADAA0
    if (ctx->r16 != ctx->r20) {
        // 0x800ADB0C: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800ADAA0;
    }
    // 0x800ADB0C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800ADB10: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x800ADB14: lw          $t9, 0xEC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XEC);
    // 0x800ADB18: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x800ADB1C: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x800ADB20: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800ADB24: bne         $at, $zero, L_800ADC58
    if (ctx->r1 != 0) {
        // 0x800ADB28: slt         $at, $t8, $t4
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
            goto L_800ADC58;
    }
    // 0x800ADB28: slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800ADB2C: bne         $at, $zero, L_800ADC58
    if (ctx->r1 != 0) {
        // 0x800ADB30: lw          $t5, 0xCC($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XCC);
            goto L_800ADC58;
    }
    // 0x800ADB30: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x800ADB34: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x800ADB38: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x800ADB3C: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x800ADB40: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800ADB44: bne         $at, $zero, L_800ADC58
    if (ctx->r1 != 0) {
        // 0x800ADB48: slt         $at, $t7, $t9
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_800ADC58;
    }
    // 0x800ADB48: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800ADB4C: bne         $at, $zero, L_800ADC58
    if (ctx->r1 != 0) {
        // 0x800ADB50: lw          $t8, 0xD0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XD0);
            goto L_800ADC58;
    }
    // 0x800ADB50: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800ADB54: lw          $t4, 0xF4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF4);
    // 0x800ADB58: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x800ADB5C: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x800ADB60: slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800ADB64: bne         $at, $zero, L_800ADC58
    if (ctx->r1 != 0) {
        // 0x800ADB68: slt         $at, $t5, $t6
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800ADC58;
    }
    // 0x800ADB68: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800ADB6C: bne         $at, $zero, L_800ADC58
    if (ctx->r1 != 0) {
        // 0x800ADB70: addiu       $a0, $sp, 0x98
        ctx->r4 = ADD32(ctx->r29, 0X98);
            goto L_800ADC58;
    }
    // 0x800ADB70: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x800ADB74: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800ADB78: jal         0x800EFB58
    // 0x800ADB7C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800EFB58(rdram, ctx);
        goto after_4;
    // 0x800ADB7C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_4:
    // 0x800ADB80: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x800ADB84: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800ADB88: jal         0x800EFB58
    // 0x800ADB8C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800EFB58(rdram, ctx);
        goto after_5;
    // 0x800ADB8C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_5:
    // 0x800ADB90: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x800ADB94: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x800ADB98: jal         0x800EE9EC
    // 0x800ADB9C: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    func_800EE9EC(rdram, ctx);
        goto after_6;
    // 0x800ADB9C: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    after_6:
    // 0x800ADBA0: jal         0x800EF2A0
    // 0x800ADBA4: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    func_800EF2A0(rdram, ctx);
        goto after_7;
    // 0x800ADBA4: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_7:
    // 0x800ADBA8: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800ADBAC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x800ADBB0: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x800ADBB4: nop

    // 0x800ADBB8: bc1fl       L_800ADBD8
    if (!c1cs) {
        // 0x800ADBBC: addiu       $a0, $sp, 0xF8
        ctx->r4 = ADD32(ctx->r29, 0XF8);
            goto L_800ADBD8;
    }
    goto skip_5;
    // 0x800ADBBC: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    skip_5:
    // 0x800ADBC0: jal         0x800EEAA4
    // 0x800ADBC4: lw          $a1, 0x140($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X140);
    func_800EEAA4(rdram, ctx);
        goto after_8;
    // 0x800ADBC4: lw          $a1, 0x140($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X140);
    after_8:
    // 0x800ADBC8: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800ADBCC: nop

    // 0x800ADBD0: bc1t        L_800ADC58
    if (c1cs) {
        // 0x800ADBD4: addiu       $a0, $sp, 0xF8
        ctx->r4 = ADD32(ctx->r29, 0XF8);
            goto L_800ADC58;
    }
    // 0x800ADBD4: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
L_800ADBD8:
    // 0x800ADBD8: jal         0x800EED58
    // 0x800ADBDC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EED58(rdram, ctx);
        goto after_9;
    // 0x800ADBDC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_9:
    // 0x800ADBE0: beq         $v0, $zero, L_800ADC00
    if (ctx->r2 == 0) {
        // 0x800ADBE4: addiu       $a0, $sp, 0x104
        ctx->r4 = ADD32(ctx->r29, 0X104);
            goto L_800ADC00;
    }
    // 0x800ADBE4: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    // 0x800ADBE8: jal         0x800EED58
    // 0x800ADBEC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800EED58(rdram, ctx);
        goto after_10;
    // 0x800ADBEC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_10:
    // 0x800ADBF0: beql        $v0, $zero, L_800ADC04
    if (ctx->r2 == 0) {
        // 0x800ADBF4: addiu       $a0, $sp, 0xF8
        ctx->r4 = ADD32(ctx->r29, 0XF8);
            goto L_800ADC04;
    }
    goto skip_6;
    // 0x800ADBF4: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    skip_6:
    // 0x800ADBF8: b           L_800ADC90
    // 0x800ADBFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ADC90;
    // 0x800ADBFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADC00:
    // 0x800ADC00: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
L_800ADC04:
    // 0x800ADC04: jal         0x800EED58
    // 0x800ADC08: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800EED58(rdram, ctx);
        goto after_11;
    // 0x800ADC08: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_11:
    // 0x800ADC0C: beq         $v0, $zero, L_800ADC2C
    if (ctx->r2 == 0) {
        // 0x800ADC10: addiu       $a0, $sp, 0x104
        ctx->r4 = ADD32(ctx->r29, 0X104);
            goto L_800ADC2C;
    }
    // 0x800ADC10: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    // 0x800ADC14: jal         0x800EED58
    // 0x800ADC18: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EED58(rdram, ctx);
        goto after_12;
    // 0x800ADC18: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_12:
    // 0x800ADC1C: beql        $v0, $zero, L_800ADC30
    if (ctx->r2 == 0) {
        // 0x800ADC20: addiu       $a0, $sp, 0xF8
        ctx->r4 = ADD32(ctx->r29, 0XF8);
            goto L_800ADC30;
    }
    goto skip_7;
    // 0x800ADC20: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    skip_7:
    // 0x800ADC24: b           L_800ADC90
    // 0x800ADC28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ADC90;
    // 0x800ADC28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADC2C:
    // 0x800ADC2C: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
L_800ADC30:
    // 0x800ADC30: jal         0x800EED58
    // 0x800ADC34: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EED58(rdram, ctx);
        goto after_13;
    // 0x800ADC34: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_13:
    // 0x800ADC38: beq         $v0, $zero, L_800ADC58
    if (ctx->r2 == 0) {
        // 0x800ADC3C: addiu       $a0, $sp, 0x104
        ctx->r4 = ADD32(ctx->r29, 0X104);
            goto L_800ADC58;
    }
    // 0x800ADC3C: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    // 0x800ADC40: jal         0x800EED58
    // 0x800ADC44: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EED58(rdram, ctx);
        goto after_14;
    // 0x800ADC44: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_14:
    // 0x800ADC48: beql        $v0, $zero, L_800ADC5C
    if (ctx->r2 == 0) {
        // 0x800ADC4C: lw          $t7, 0x114($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X114);
            goto L_800ADC5C;
    }
    goto skip_8;
    // 0x800ADC4C: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
    skip_8:
    // 0x800ADC50: b           L_800ADC90
    // 0x800ADC54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ADC90;
    // 0x800ADC54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADC58:
    // 0x800ADC58: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
L_800ADC5C:
    // 0x800ADC5C: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x800ADC60: sltu        $at, $s5, $t7
    ctx->r1 = ctx->r21 < ctx->r15 ? 1 : 0;
    // 0x800ADC64: bnel        $at, $zero, L_800ADA64
    if (ctx->r1 != 0) {
        // 0x800ADC68: lhu         $t7, 0x0($s5)
        ctx->r15 = MEM_HU(ctx->r21, 0X0);
            goto L_800ADA64;
    }
    goto skip_9;
    // 0x800ADC68: lhu         $t7, 0x0($s5)
    ctx->r15 = MEM_HU(ctx->r21, 0X0);
    skip_9:
    // 0x800ADC6C: lw          $t2, 0x130($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X130);
    // 0x800ADC70: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800ADC74: lw          $t0, 0x11C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X11C);
    // 0x800ADC78: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
L_800ADC7C:
    // 0x800ADC7C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800ADC80: sltu        $at, $t0, $t9
    ctx->r1 = ctx->r8 < ctx->r25 ? 1 : 0;
    // 0x800ADC84: bnel        $at, $zero, L_800ADA1C
    if (ctx->r1 != 0) {
        // 0x800ADC88: lw          $v1, 0x0($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X0);
            goto L_800ADA1C;
    }
    goto skip_10;
    // 0x800ADC88: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    skip_10:
L_800ADC8C:
    // 0x800ADC8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ADC90:
    // 0x800ADC90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800ADC94: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800ADC98: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800ADC9C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800ADCA0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800ADCA4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800ADCA8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADCAC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800ADCB0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800ADCB4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800ADCB8: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800ADCBC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800ADCC0: jr          $ra
    // 0x800ADCC4: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x800ADCC4: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    // 0x800ADCC8: nop

    // 0x800ADCCC: nop

;}
RECOMP_FUNC void func_80800770_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800770: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800774: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800778: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080077C: jal         0x808001A8
    // 0x80800780: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x80800780: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800784: jal         0x80082FE0
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800790: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800794: jal         0x80085338
    // 0x80800798: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_2;
    // 0x80800798: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x8080079C: jal         0x80084800
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808007A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007A8: bne         $v0, $at, L_808007C8
    if (ctx->r2 != ctx->r1) {
        // 0x808007AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007C8;
    }
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808007B4: jal         0x800947EC
    // 0x808007B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_4;
    // 0x808007B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C0: jal         0x80084CC8
    // 0x808007C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x808007C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_808007C8:
    // 0x808007C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007D4: jr          $ra
    // 0x808007D8: nop

    return;
    // 0x808007D8: nop

;}
RECOMP_FUNC void func_80096518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096518: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x8009651C: jr          $ra
    // 0x80096520: lbu         $v0, 0x56($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X56);
    return;
    // 0x80096520: lbu         $v0, 0x56($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X56);
;}
RECOMP_FUNC void func_80804EB4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804EB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804EBC: jal         0x80807C8C
    // 0x80804EC0: nop

    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804EC0: nop

    after_0:
    // 0x80804EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804EC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804ECC: jr          $ra
    // 0x80804ED0: nop

    return;
    // 0x80804ED0: nop

;}
RECOMP_FUNC void fxsparkle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800008: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800014: jal         0x800EE88C
    // 0x80800018: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8080001C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800020: jal         0x80800038
    // 0x80800024: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    fxsparkle_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800024: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void func_80800008_ncbaspiral(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x80112524
    // 0x80800014: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800014: nop

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
RECOMP_FUNC void subaddiedialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80800048: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080004C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800050: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80800054: bgezl       $t8, L_80800090
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800058: addiu       $a0, $a3, 0x4
        ctx->r4 = ADD32(ctx->r7, 0X4);
            goto L_80800090;
    }
    goto skip_0;
    // 0x80800058: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    skip_0:
    // 0x8080005C: jal         0x80800000
    // 0x80800060: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_0;
    // 0x80800060: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800064: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800068: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
    // 0x8080006C: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x80800070: lbu         $t2, 0x74($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X74);
    // 0x80800074: andi        $t1, $t0, 0x40
    ctx->r9 = ctx->r8 & 0X40;
    // 0x80800078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080007C: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x80800080: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800084: b           L_808000B8
    // 0x80800088: sb          $t4, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r12;
        goto L_808000B8;
    // 0x80800088: sb          $t4, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r12;
    // 0x8080008C: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
L_80800090:
    // 0x80800090: jal         0x808000C8
    // 0x80800094: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    subaddiedialog_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800094: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800098: beq         $v0, $zero, L_808000B4
    if (ctx->r2 == 0) {
        // 0x8080009C: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_808000B4;
    }
    // 0x8080009C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: lbu         $t6, 0x74($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X74);
    // 0x808000A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000A8: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x808000AC: b           L_808000B8
    // 0x808000B0: sb          $t7, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r15;
        goto L_808000B8;
    // 0x808000B0: sb          $t7, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r15;
L_808000B4:
    // 0x808000B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000B8:
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void _gcmapDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088118: syscall     672
    recomp_syscall_handler(rdram, ctx, 0x80088118);
    return;
    // 0x8008811C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800142F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800142F0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800142F4: lw          $t6, -0x7B7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B7C);
    // 0x800142F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800142FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014300: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80014304: bgez        $t7, L_80014328
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80014308: nop
    
            goto L_80014328;
    }
    // 0x80014308: nop

    // 0x8001430C: jal         0x8002EF70
    // 0x80014310: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_0;
    // 0x80014310: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80014314: jal         0x8002F250
    // 0x80014318: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80014318: nop

    after_1:
    // 0x8001431C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014320: jal         0x80015190
    // 0x80014324: sw          $v0, -0x70F8($at)
    MEM_W(-0X70F8, ctx->r1) = ctx->r2;
    func_80015190(rdram, ctx);
        goto after_2;
    // 0x80014324: sw          $v0, -0x70F8($at)
    MEM_W(-0X70F8, ctx->r1) = ctx->r2;
    after_2:
L_80014328:
    // 0x80014328: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001432C: addiu       $v0, $v0, -0x7B78
    ctx->r2 = ADD32(ctx->r2, -0X7B78);
    // 0x80014330: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80014334: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80014338: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001433C: sw          $t8, -0x7B7C($at)
    MEM_W(-0X7B7C, ctx->r1) = ctx->r24;
    // 0x80014340: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80014344: lw          $t0, -0x7B74($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7B74);
    // 0x80014348: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001434C: sw          $zero, -0x70F0($at)
    MEM_W(-0X70F0, ctx->r1) = 0;
    // 0x80014350: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80014354: bne         $t0, $at, L_800143C8
    if (ctx->r8 != ctx->r1) {
        // 0x80014358: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_800143C8;
    }
    // 0x80014358: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001435C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80014360: addiu       $t1, $t1, -0x7158
    ctx->r9 = ADD32(ctx->r9, -0X7158);
    // 0x80014364: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80014368: addiu       $v0, $v0, -0x7154
    ctx->r2 = ADD32(ctx->r2, -0X7154);
    // 0x8001436C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80014370: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80014374: beq         $t2, $t3, L_800143C8
    if (ctx->r10 == ctx->r11) {
        // 0x80014378: nop
    
            goto L_800143C8;
    }
    // 0x80014378: nop

    // 0x8001437C: lw          $t4, -0x7B80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7B80);
    // 0x80014380: bne         $t4, $zero, L_800143C8
    if (ctx->r12 != 0) {
        // 0x80014384: nop
    
            goto L_800143C8;
    }
    // 0x80014384: nop

    // 0x80014388: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8001438C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014390: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80014394: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80014398: jal         0x800140D8
    // 0x8001439C: lw          $a0, -0x71A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X71A8);
    func_800140D8(rdram, ctx);
        goto after_3;
    // 0x8001439C: lw          $a0, -0x71A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X71A8);
    after_3:
    // 0x800143A0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800143A4: addiu       $v0, $v0, -0x7154
    ctx->r2 = ADD32(ctx->r2, -0X7154);
    // 0x800143A8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800143AC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800143B0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800143B4: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800143B8: mfhi        $t9
    ctx->r25 = hi;
    // 0x800143BC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800143C0: b           L_80014430
    // 0x800143C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80014430;
    // 0x800143C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800143C8:
    // 0x800143C8: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800143CC: lw          $t0, -0x7B84($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7B84);
    // 0x800143D0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800143D4: addiu       $v0, $v0, -0x7154
    ctx->r2 = ADD32(ctx->r2, -0X7154);
    // 0x800143D8: beq         $t0, $zero, L_8001442C
    if (ctx->r8 == 0) {
        // 0x800143DC: lui         $t1, 0x8008
        ctx->r9 = S32(0X8008 << 16);
            goto L_8001442C;
    }
    // 0x800143DC: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x800143E0: addiu       $t1, $t1, -0x7158
    ctx->r9 = ADD32(ctx->r9, -0X7158);
    // 0x800143E4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800143E8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800143EC: bnel        $t2, $t3, L_80014430
    if (ctx->r10 != ctx->r11) {
        // 0x800143F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80014430;
    }
    goto skip_0;
    // 0x800143F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800143F4: jal         0x8002F240
    // 0x800143F8: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_4;
    // 0x800143F8: nop

    after_4:
    // 0x800143FC: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x80014400: bne         $t4, $zero, L_8001442C
    if (ctx->r12 != 0) {
        // 0x80014404: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8001442C;
    }
    // 0x80014404: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014408: addiu       $a0, $a0, -0x7BC8
    ctx->r4 = ADD32(ctx->r4, -0X7BC8);
    // 0x8001440C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80014410: jal         0x8002EAD0
    // 0x80014414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80014414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80014418: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001441C: addiu       $v1, $v1, -0x7B84
    ctx->r3 = ADD32(ctx->r3, -0X7B84);
    // 0x80014420: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80014424: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80014428: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8001442C:
    // 0x8001442C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80014430:
    // 0x80014430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80014434: jr          $ra
    // 0x80014438: nop

    return;
    // 0x80014438: nop

;}
RECOMP_FUNC void _bskazegghead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083410: syscall     61
    recomp_syscall_handler(rdram, ctx, 0x80083410);
    return;
    // 0x80083414: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80806BD4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806BD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806BD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80806BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806BE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80806BE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80806BE8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80806BEC: jal         0x80087D38
    // 0x80806BF0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcnewoption_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80806BF0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80806BF4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80806BF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80806BFC: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x80806C00: bne         $t6, $at, L_80806C18
    if (ctx->r14 != ctx->r1) {
        // 0x80806C04: nop
    
            goto L_80806C18;
    }
    // 0x80806C04: nop

    // 0x80806C08: jal         0x80806AA8
    // 0x80806C0C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80806AA8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80806C0C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80806C10: b           L_80806C24
    // 0x80806C14: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
        goto L_80806C24;
    // 0x80806C14: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_80806C18:
    // 0x80806C18: jal         0x80806AD4
    // 0x80806C1C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80806AD4_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80806C1C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x80806C20: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_80806C24:
    // 0x80806C24: bgez        $a2, L_80806C30
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80806C28: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80806C30;
    }
    // 0x80806C28: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80806C2C: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
L_80806C30:
    // 0x80806C30: jal         0x80806AF4
    // 0x80806C34: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80806AF4_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80806C34: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80806C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806C3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806C40: jr          $ra
    // 0x80806C44: nop

    return;
    // 0x80806C44: nop

;}
RECOMP_FUNC void func_800D192C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D192C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D1938: jal         0x800D1A04
    // 0x800D193C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x800D193C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D1940: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D1944: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D1948: jal         0x800D1864
    // 0x800D194C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800D1864(rdram, ctx);
        goto after_1;
    // 0x800D194C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800D1950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D1958: jr          $ra
    // 0x800D195C: nop

    return;
    // 0x800D195C: nop

;}
RECOMP_FUNC void func_80800024_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800028: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800030: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800034: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800038: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8080003C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800040: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800044: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x80800048: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080004C: jal         0x80089F20
    // 0x80800050: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800050: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    after_0:
    // 0x80800054: jal         0x80800694
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800694_chtiptup(rdram, ctx);
        goto after_1;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080005C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800064: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800068: beq         $t7, $at, L_8080008C
    if (ctx->r15 == ctx->r1) {
        // 0x8080006C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080008C;
    }
    // 0x8080006C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800070: beq         $t7, $at, L_8080009C
    if (ctx->r15 == ctx->r1) {
        // 0x80800074: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080009C;
    }
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080007C: beq         $t7, $at, L_80800104
    if (ctx->r15 == ctx->r1) {
        // 0x80800080: nop
    
            goto L_80800104;
    }
    // 0x80800080: nop

    // 0x80800084: b           L_808001F0
    // 0x80800088: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001F0;
    // 0x80800088: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080008C:
    // 0x8080008C: jal         0x808004C4
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004C4_chtiptup(rdram, ctx);
        goto after_2;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800094: b           L_808001F0
    // 0x80800098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001F0;
    // 0x80800098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080009C:
    // 0x8080009C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X1520) << 16);
    // 0x808000A0: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x808000A4: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808000A8: addiu       $a2, $a2, 0x1520
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X1520));
    // 0x808000AC: jal         0x80089D20
    // 0x808000B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808000B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x808000B4: beq         $v0, $zero, L_808000D8
    if (ctx->r2 == 0) {
        // 0x808000B8: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_808000D8;
    }
    // 0x808000B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808000BC: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1020, 0X152C) << 16);
    // 0x808000C0: addiu       $t9, $t9, 0x152C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1020, 0X152C));
    // 0x808000C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808000C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808000CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x808000D0: jal         0x80800614
    // 0x808000D4: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    func_80800614_chtiptup(rdram, ctx);
        goto after_4;
    // 0x808000D4: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    after_4:
L_808000D8:
    // 0x808000D8: jal         0x80101DDC
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000E0: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001EC;
    }
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x80102424
    // 0x808000EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808000EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x8008A4B0
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808000FC: b           L_808001F0
    // 0x80800100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001F0;
    // 0x80800100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800104:
    // 0x80800104: jal         0x80105A5C
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_8;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080010C: bne         $v0, $zero, L_80800138
    if (ctx->r2 != 0) {
        // 0x80800110: addiu       $a0, $s0, 0x58
        ctx->r4 = ADD32(ctx->r16, 0X58);
            goto L_80800138;
    }
    // 0x80800110: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800114: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x80800118: jal         0x800D9154
    // 0x8080011C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_800D9154(rdram, ctx);
        goto after_9;
    // 0x8080011C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_9:
    // 0x80800120: beq         $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x80800124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800138;
    }
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X1558) << 16);
    // 0x8080012C: addiu       $a2, $a2, 0x1558
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X1558));
    // 0x80800130: jal         0x80089D18
    // 0x80800134: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800134: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_10:
L_80800138:
    // 0x80800138: jal         0x8001210C
    // 0x8080013C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_11;
    // 0x8080013C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_11:
    // 0x80800140: bne         $v0, $zero, L_808001C4
    if (ctx->r2 != 0) {
        // 0x80800144: nop
    
            goto L_808001C4;
    }
    // 0x80800144: nop

    // 0x80800148: jal         0x80105AE8
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105AE8(rdram, ctx);
        goto after_12;
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800150: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1020, 0X1340) << 16);
    // 0x80800154: lwc1        $f4, 0x1340($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1020, 0X1340));
    // 0x80800158: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1020, 0X1568) << 16);
    // 0x8080015C: addiu       $v0, $v0, 0x1568
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1020, 0X1568));
    // 0x80800160: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800164: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800168: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080016C: bc1f        L_8080017C
    if (!c1cs) {
        // 0x80800170: nop
    
            goto L_8080017C;
    }
    // 0x80800170: nop

    // 0x80800174: b           L_8080017C
    // 0x80800178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080017C;
    // 0x80800178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080017C:
    // 0x8080017C: jal         0x800EE7F8
    // 0x80800180: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x80800180: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_13:
    // 0x80800184: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800188: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080018C: jal         0x800EF1B8
    // 0x80800190: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_14;
    // 0x80800190: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_14:
    // 0x80800194: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800198: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080019C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808001A0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x808001A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001A8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808001AC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808001B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808001B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808001B8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x808001BC: jal         0x80800614
    // 0x808001C0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80800614_chtiptup(rdram, ctx);
        goto after_15;
    // 0x808001C0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_15:
L_808001C4:
    // 0x808001C4: jal         0x80105834
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_16;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001CC: jal         0x80105A5C
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_17;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808001D4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1020, 0X154C) << 16);
    // 0x808001D8: addiu       $a3, $a3, 0x154C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1020, 0X154C));
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808001E4: jal         0x80089D50
    // 0x808001E8: sltiu       $a2, $v0, 0x1
    ctx->r6 = ctx->r2 < 0X1 ? 1 : 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x808001E8: sltiu       $a2, $v0, 0x1
    ctx->r6 = ctx->r2 < 0X1 ? 1 : 0;
    after_18:
L_808001EC:
    // 0x808001EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001F0:
    // 0x808001F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void func_8080000C_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800018: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x8080001C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800020: jal         0x800EE7F8
    // 0x80800024: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080002C: jal         0x8010A828
    // 0x80800030: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A828(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
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
RECOMP_FUNC void func_8001A6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A6C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A6C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A6C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001A6CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001A6D0: jal         0x8001E5DC
    // 0x8001A6D4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8001E5DC(rdram, ctx);
        goto after_0;
    // 0x8001A6D4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x8001A6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A6DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A6E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A6E4: jr          $ra
    // 0x8001A6E8: nop

    return;
    // 0x8001A6E8: nop

;}
RECOMP_FUNC void func_8080002C_chmumboskulls(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: jr          $ra
    // 0x80800030: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800030: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800014_chattract(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800020: lwc1        $f6, 0x54($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80800024: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080002C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800030: nop

    // 0x80800034: bc1tl       L_8080005C
    if (c1cs) {
        // 0x80800038: lbu         $t6, 0x79($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X79);
            goto L_8080005C;
    }
    goto skip_0;
    // 0x80800038: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    skip_0:
    // 0x8080003C: jal         0x800D8FF8
    // 0x80800040: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800040: nop

    after_0:
    // 0x80800044: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800048: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080004C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800050: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800054: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x80800058: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
L_8080005C:
    // 0x8080005C: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80800060: beql        $t7, $zero, L_8080011C
    if (ctx->r15 == 0) {
        // 0x80800064: lhu         $t0, 0x78($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X78);
            goto L_8080011C;
    }
    goto skip_1;
    // 0x80800064: lhu         $t0, 0x78($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X78);
    skip_1:
    // 0x80800068: lhu         $t8, 0x78($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X78);
    // 0x8080006C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x80800070: bnel        $t9, $zero, L_808001F4
    if (ctx->r25 != 0) {
        // 0x80800074: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001F4;
    }
    goto skip_2;
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800078: jal         0x800D9078
    // 0x8080007C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x8080007C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800080: beql        $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x80800084: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001F4;
    }
    goto skip_3;
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800088: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
    // 0x8080008C: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(812, 0X46A) << 16);
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x80800098: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8080009C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x808000A0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808000A4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x808000A8: lbu         $t3, 0x46A($t3)
    ctx->r11 = MEM_BU(ctx->r11, (int16_t)RELOC_LO16(812, 0X46A));
    // 0x808000AC: beq         $t3, $zero, L_808000C4
    if (ctx->r11 == 0) {
        // 0x808000B0: nop
    
            goto L_808000C4;
    }
    // 0x808000B0: nop

    // 0x808000B4: jal         0x80089CA0
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000BC: b           L_808000D0
    // 0x808000C0: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
        goto L_808000D0;
    // 0x808000C0: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
L_808000C4:
    // 0x808000C4: jal         0x80089C98
    // 0x808000C8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808000C8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_3:
    // 0x808000CC: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
L_808000D0:
    // 0x808000D0: lbu         $t7, 0x79($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X79);
    // 0x808000D4: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x808000D8: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x808000DC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x808000E0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x808000E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808000E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(812, 0X46C) << 16);
    // 0x808000EC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808000F0: lwc1        $f4, 0x46C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(812, 0X46C));
    // 0x808000F4: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x808000F8: srl         $t9, $a1, 10
    ctx->r25 = S32(U32(ctx->r5) >> 10);
    // 0x808000FC: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
    // 0x80800100: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x80102424
    // 0x8080010C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x8080010C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80800110: b           L_808001F4
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001F4;
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: lhu         $t0, 0x78($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X78);
L_8080011C:
    // 0x8080011C: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80800120: bnel        $t1, $zero, L_808001F4
    if (ctx->r9 != 0) {
        // 0x80800124: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001F4;
    }
    goto skip_4;
    // 0x80800124: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800128: jal         0x800D9078
    // 0x8080012C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x8080012C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_5:
    // 0x80800130: beq         $v0, $zero, L_808001F0
    if (ctx->r2 == 0) {
        // 0x80800134: lui         $t5, 0x8080
        ctx->r13 = S32(RELOC_HI16(812, 0X468) << 16);
            goto L_808001F0;
    }
    // 0x80800134: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(812, 0X468) << 16);
    // 0x80800138: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
    // 0x8080013C: addiu       $t5, $t5, 0x468
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(812, 0X468));
    // 0x80800140: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800144: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x80800148: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8080014C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80800150: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80800154: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80800158: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8080015C: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x80800160: nop

    // 0x80800164: bc1tl       L_808001D0
    if (c1cs) {
        // 0x80800168: lbu         $t3, 0x3($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X3);
            goto L_808001D0;
    }
    goto skip_5;
    // 0x80800168: lbu         $t3, 0x3($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X3);
    skip_5:
    // 0x8080016C: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: beq         $t6, $zero, L_8080018C
    if (ctx->r14 == 0) {
        // 0x80800178: nop
    
            goto L_8080018C;
    }
    // 0x80800178: nop

    // 0x8080017C: jal         0x80089CB8
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800184: b           L_80800198
    // 0x80800188: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
        goto L_80800198;
    // 0x80800188: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
L_8080018C:
    // 0x8080018C: jal         0x80089C98
    // 0x80800190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800194: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
L_80800198:
    // 0x80800198: lbu         $t0, 0x79($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X79);
    // 0x8080019C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(812, 0X470) << 16);
    // 0x808001A0: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808001A4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x808001A8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808001AC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808001B0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808001B4: lwc1        $f8, 0x470($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(812, 0X470));
    // 0x808001B8: andi        $t1, $t0, 0xFF0F
    ctx->r9 = ctx->r8 & 0XFF0F;
    // 0x808001BC: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x808001C0: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
    // 0x808001C4: b           L_808001F0
    // 0x808001C8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_808001F0;
    // 0x808001C8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x808001CC: lbu         $t3, 0x3($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X3);
L_808001D0:
    // 0x808001D0: beq         $t3, $zero, L_808001E8
    if (ctx->r11 == 0) {
        // 0x808001D4: nop
    
            goto L_808001E8;
    }
    // 0x808001D4: nop

    // 0x808001D8: jal         0x80089CA8
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001E0: b           L_808001F4
    // 0x808001E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001F4;
    // 0x808001E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001E8:
    // 0x808001E8: jal         0x800FFAB0
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_808001F0:
    // 0x808001F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001F4:
    // 0x808001F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001FC: jr          $ra
    // 0x80800200: nop

    return;
    // 0x80800200: nop

;}
RECOMP_FUNC void func_808006B4_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006B8: sltiu       $at, $a2, 0xA
    ctx->r1 = ctx->r6 < 0XA ? 1 : 0;
    // 0x808006BC: beq         $at, $zero, L_80800880
    if (ctx->r1 == 0) {
        // 0x808006C0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800880;
    }
    // 0x808006C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x808006C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(852, 0XAC8) << 16);
    // 0x808006CC: addu        $at, $at, $t6
    gpr jr_addend_808006D4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808006D0: lw          $t6, 0xAC8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(852, 0XAC8));
    // 0x808006D4: jr          $t6
    // 0x808006D8: nop

    switch (jr_addend_808006D4 >> 2) {
        case 0: goto L_808006DC; break;
        case 1: goto L_80800800; break;
        case 2: goto L_80800774; break;
        case 3: goto L_80800784; break;
        case 4: goto L_808007E4; break;
        case 5: goto L_80800808; break;
        case 6: goto L_80800800; break;
        case 7: goto L_80800774; break;
        case 8: goto L_80800818; break;
        case 9: goto L_80800858; break;
        default: switch_error(__func__, 0x808006D4, 0x80800AC8);
    }
    // 0x808006D8: nop

L_808006DC:
    // 0x808006DC: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x808006E0: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x808006E4: addiu       $t9, $a1, -0x2
    ctx->r25 = ADD32(ctx->r5, -0X2);
    // 0x808006E8: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808006EC: bnel        $t8, $at, L_80800700
    if (ctx->r24 != ctx->r1) {
        // 0x808006F0: sltiu       $at, $t9, 0x11
        ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
            goto L_80800700;
    }
    goto skip_0;
    // 0x808006F0: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    skip_0:
    // 0x808006F4: b           L_80800884
    // 0x808006F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800884;
    // 0x808006F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808006FC: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
L_80800700:
    // 0x80800700: beq         $at, $zero, L_80800880
    if (ctx->r1 == 0) {
        // 0x80800704: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800880;
    }
    // 0x80800704: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800708: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(852, 0XAF0) << 16);
    // 0x8080070C: addu        $at, $at, $t9
    gpr jr_addend_80800714 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800710: lw          $t9, 0xAF0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(852, 0XAF0));
    // 0x80800714: jr          $t9
    // 0x80800718: nop

    switch (jr_addend_80800714 >> 2) {
        case 0: goto L_8080071C; break;
        case 1: goto L_8080071C; break;
        case 2: goto L_8080074C; break;
        case 3: goto L_8080075C; break;
        case 4: goto L_80800880; break;
        case 5: goto L_80800764; break;
        case 6: goto L_8080075C; break;
        case 7: goto L_8080075C; break;
        case 8: goto L_80800880; break;
        case 9: goto L_80800880; break;
        case 10: goto L_80800880; break;
        case 11: goto L_80800880; break;
        case 12: goto L_80800880; break;
        case 13: goto L_80800880; break;
        case 14: goto L_80800880; break;
        case 15: goto L_80800880; break;
        case 16: goto L_8080075C; break;
        default: switch_error(__func__, 0x80800714, 0x80800AF0);
    }
    // 0x80800718: nop

L_8080071C:
    // 0x8080071C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80800720: addiu       $at, $zero, 0x78A
    ctx->r1 = ADD32(0, 0X78A);
    // 0x80800724: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80800728: lhu         $t1, 0x14($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X14);
    // 0x8080072C: bne         $t1, $at, L_8080073C
    if (ctx->r9 != ctx->r1) {
        // 0x80800730: nop
    
            goto L_8080073C;
    }
    // 0x80800730: nop

    // 0x80800734: b           L_8080073C
    // 0x80800738: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
        goto L_8080073C;
    // 0x80800738: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
L_8080073C:
    // 0x8080073C: jal         0x80800894
    // 0x80800740: nop

    func_80800894_chhillbilly(rdram, ctx);
        goto after_0;
    // 0x80800740: nop

    after_0:
    // 0x80800744: b           L_80800884
    // 0x80800748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800884;
    // 0x80800748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080074C:
    // 0x8080074C: jal         0x80800894
    // 0x80800750: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80800894_chhillbilly(rdram, ctx);
        goto after_1;
    // 0x80800750: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_1:
    // 0x80800754: b           L_80800884
    // 0x80800758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800884;
    // 0x80800758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080075C:
    // 0x8080075C: b           L_80800884
    // 0x80800760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800884;
    // 0x80800760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800764:
    // 0x80800764: jal         0x8008A148
    // 0x80800768: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800768: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x8080076C: b           L_80800884
    // 0x80800770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800884;
    // 0x80800770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800774:
    // 0x80800774: jal         0x80800894
    // 0x80800778: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80800894_chhillbilly(rdram, ctx);
        goto after_3;
    // 0x80800778: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_3:
    // 0x8080077C: b           L_80800884
    // 0x80800780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800884;
    // 0x80800780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800784:
    // 0x80800784: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800788: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080078C: jal         0x800D9058
    // 0x80800790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D9058(rdram, ctx);
        goto after_4;
    // 0x80800790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x80800794: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800798: andi        $t3, $v0, 0x1FF
    ctx->r11 = ctx->r2 & 0X1FF;
    // 0x8080079C: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    // 0x808007A0: lhu         $t4, 0x6E($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X6E);
    // 0x808007A4: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x808007A8: lw          $a1, 0x54($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X54);
    // 0x808007AC: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x808007B0: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x808007B4: jal         0x8010297C
    // 0x808007B8: sh          $t6, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r14;
    func_8010297C(rdram, ctx);
        goto after_5;
    // 0x808007B8: sh          $t6, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r14;
    after_5:
    // 0x808007BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007C0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808007C4: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x808007C8: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808007CC: bne         $t8, $at, L_808007DC
    if (ctx->r24 != ctx->r1) {
        // 0x808007D0: nop
    
            goto L_808007DC;
    }
    // 0x808007D0: nop

    // 0x808007D4: jal         0x80800894
    // 0x808007D8: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80800894_chhillbilly(rdram, ctx);
        goto after_6;
    // 0x808007D8: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_6:
L_808007DC:
    // 0x808007DC: b           L_80800884
    // 0x808007E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800884;
    // 0x808007E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007E4:
    // 0x808007E4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x808007E8: addiu       $at, $zero, 0x789
    ctx->r1 = ADD32(0, 0X789);
    // 0x808007EC: lhu         $t0, 0x14($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X14);
    // 0x808007F0: bnel        $t0, $at, L_80800884
    if (ctx->r8 != ctx->r1) {
        // 0x808007F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800884;
    }
    goto skip_1;
    // 0x808007F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x808007F8: b           L_80800884
    // 0x808007FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800884;
    // 0x808007FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800800:
    // 0x80800800: b           L_80800884
    // 0x80800804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800884;
    // 0x80800804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800808:
    // 0x80800808: jal         0x80800894
    // 0x8080080C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800894_chhillbilly(rdram, ctx);
        goto after_7;
    // 0x8080080C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_7:
    // 0x80800810: b           L_80800884
    // 0x80800814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800884;
    // 0x80800814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800818:
    // 0x80800818: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8080081C: bne         $a1, $at, L_80800840
    if (ctx->r5 != ctx->r1) {
        // 0x80800820: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800840;
    }
    // 0x80800820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800824: addiu       $a1, $zero, 0x78A
    ctx->r5 = ADD32(0, 0X78A);
    // 0x80800828: jal         0x808009D8
    // 0x8080082C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808009D8_chhillbilly(rdram, ctx);
        goto after_8;
    // 0x8080082C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_8:
    // 0x80800830: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800834: jal         0x801020DC
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_801020DC(rdram, ctx);
        goto after_9;
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8080083C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800840:
    // 0x80800840: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80800844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800848: lbu         $t1, 0x2A($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2A);
    // 0x8080084C: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x80800850: b           L_80800884
    // 0x80800854: sb          $t2, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r10;
        goto L_80800884;
    // 0x80800854: sb          $t2, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r10;
L_80800858:
    // 0x80800858: lw          $t4, 0x64($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X64);
    // 0x8080085C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80800860: bgez        $t5, L_80800878
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800864: nop
    
            goto L_80800878;
    }
    // 0x80800864: nop

    // 0x80800868: jal         0x8008A148
    // 0x8080086C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_10;
    // 0x8080086C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800870: b           L_80800884
    // 0x80800874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800884;
    // 0x80800874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800878:
    // 0x80800878: b           L_80800884
    // 0x8080087C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800884;
    // 0x8080087C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800880:
    // 0x80800880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800884:
    // 0x80800884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080088C: jr          $ra
    // 0x80800890: nop

    return;
    // 0x80800890: nop

;}
RECOMP_FUNC void func_80801A10_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801A14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801A18: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80801A1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A20: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1008, 0X1D28) << 16);
    // 0x80801A24: addiu       $t7, $t7, 0x1D28
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1008, 0X1D28));
    // 0x80801A28: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80801A2C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80801A30: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801A34: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801A38: jal         0x800BBCB8
    // 0x80801A3C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80801A3C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x80801A40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801A48: jr          $ra
    // 0x80801A4C: nop

    return;
    // 0x80801A4C: nop

;}
RECOMP_FUNC void sumole_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808015FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801600: jal         0x80106790
    // 0x80801604: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801604: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80801608: lhu         $t6, 0x72($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X72);
    // 0x8080160C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801614: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801618: bne         $t7, $at, L_80801628
    if (ctx->r15 != ctx->r1) {
        // 0x8080161C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801628;
    }
    // 0x8080161C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801620: b           L_80801628
    // 0x80801624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801628;
    // 0x80801624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801628:
    // 0x80801628: jr          $ra
    // 0x8080162C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080162C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80012EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012EF4: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80012EF8: jr          $ra
    // 0x80012EFC: addiu       $v0, $v0, -0x6A98
    ctx->r2 = ADD32(ctx->r2, -0X6A98);
    return;
    // 0x80012EFC: addiu       $v0, $v0, -0x6A98
    ctx->r2 = ADD32(ctx->r2, -0X6A98);
;}
RECOMP_FUNC void ncbapan_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chstarspinnerplanet_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(952, 0X260) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x260
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(952, 0X260));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x260
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(952, 0X260));
;}
RECOMP_FUNC void bsbtrot_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801B80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801B8C: jal         0x8008CABC
    // 0x80801B90: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801B90: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80801B94: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80801B98: jal         0x808004B4
    // 0x80801B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80801B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801BA0: jal         0x8008E3E8
    // 0x80801BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E3E8(rdram, ctx);
        goto after_2;
    // 0x80801BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801BA8: beql        $v0, $zero, L_80801BBC
    if (ctx->r2 == 0) {
        // 0x80801BAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801BBC;
    }
    goto skip_0;
    // 0x80801BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801BB0: jal         0x80085078
    // 0x80801BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80801BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801BBC:
    // 0x80801BBC: jal         0x80095738
    // 0x80801BC0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_4;
    // 0x80801BC0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_4:
    // 0x80801BC4: beq         $v0, $zero, L_80801BDC
    if (ctx->r2 == 0) {
        // 0x80801BC8: nop
    
            goto L_80801BDC;
    }
    // 0x80801BC8: nop

    // 0x80801BCC: jal         0x8009B7C0
    // 0x80801BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_5;
    // 0x80801BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801BD4: b           L_80801BE8
    // 0x80801BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801BE8;
    // 0x80801BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801BDC:
    // 0x80801BDC: jal         0x80800438
    // 0x80801BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800438_bsbtrot(rdram, ctx);
        goto after_6;
    // 0x80801BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801BE8:
    // 0x80801BE8: jal         0x8009BB24
    // 0x80801BEC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_7;
    // 0x80801BEC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_7:
    // 0x80801BF0: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x80801BF4: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80801BF8: beq         $at, $zero, L_80801E5C
    if (ctx->r1 == 0) {
        // 0x80801BFC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801E5C;
    }
    // 0x80801BFC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801C00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2E2C) << 16);
    // 0x80801C04: addu        $at, $at, $t6
    gpr jr_addend_80801C0C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801C08: lw          $t6, 0x2E2C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(124, 0X2E2C));
    // 0x80801C0C: jr          $t6
    // 0x80801C10: nop

    switch (jr_addend_80801C0C >> 2) {
        case 0: goto L_80801C14; break;
        case 1: goto L_80801C60; break;
        case 2: goto L_80801D00; break;
        case 3: goto L_80801D88; break;
        case 4: goto L_80801E10; break;
        default: switch_error(__func__, 0x80801C0C, 0x80802E2C);
    }
    // 0x80801C10: nop

L_80801C14:
    // 0x80801C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C18: jal         0x8008DF8C
    // 0x80801C1C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    func_8008DF8C(rdram, ctx);
        goto after_8;
    // 0x80801C1C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    after_8:
    // 0x80801C20: beq         $v0, $zero, L_80801E5C
    if (ctx->r2 == 0) {
        // 0x80801C24: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80801E5C;
    }
    // 0x80801C24: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801C28: lui         $a2, 0x3F3B
    ctx->r6 = S32(0X3F3B << 16);
    // 0x80801C2C: ori         $a2, $a2, 0x98C8
    ctx->r6 = ctx->r6 | 0X98C8;
    // 0x80801C30: jal         0x8008B1D4
    // 0x80801C34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_9;
    // 0x80801C34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x80801C38: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80801C3C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80801C40: jal         0x8008B1BC
    // 0x80801C44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_10;
    // 0x80801C44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x80801C48: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801C4C: jal         0x8008B134
    // 0x80801C50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_11;
    // 0x80801C50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80801C54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801C58: b           L_80801E5C
    // 0x80801C5C: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80801E5C;
    // 0x80801C5C: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80801C60:
    // 0x80801C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C64: jal         0x8009D3A8
    // 0x80801C68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_12;
    // 0x80801C68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80801C6C: jal         0x8008E078
    // 0x80801C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_13;
    // 0x80801C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80801C74: beq         $v0, $zero, L_80801E5C
    if (ctx->r2 == 0) {
        // 0x80801C78: nop
    
            goto L_80801E5C;
    }
    // 0x80801C78: nop

    // 0x80801C7C: jal         0x8009FE58
    // 0x80801C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_14;
    // 0x80801C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801C84: lui         $a2, 0x3F61
    ctx->r6 = S32(0X3F61 << 16);
    // 0x80801C88: ori         $a2, $a2, 0x3A93
    ctx->r6 = ctx->r6 | 0X3A93;
    // 0x80801C8C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801C90: jal         0x8008B1D4
    // 0x80801C94: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_15;
    // 0x80801C94: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_15:
    // 0x80801C98: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80801C9C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801CA0: jal         0x8008B1BC
    // 0x80801CA4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_16;
    // 0x80801CA4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_16:
    // 0x80801CA8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801CAC: jal         0x8008B134
    // 0x80801CB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_17;
    // 0x80801CB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80801CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CB8: jal         0x8009D2D8
    // 0x80801CBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D2D8(rdram, ctx);
        goto after_18;
    // 0x80801CBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80801CC0: jal         0x8009BB00
    // 0x80801CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x80801CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80801CC8: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80801CCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801CD0: nop

    // 0x80801CD4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801CD8: nop

    // 0x80801CDC: bc1f        L_80801CEC
    if (!c1cs) {
        // 0x80801CE0: nop
    
            goto L_80801CEC;
    }
    // 0x80801CE0: nop

    // 0x80801CE4: jal         0x8009D658
    // 0x80801CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_20;
    // 0x80801CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
L_80801CEC:
    // 0x80801CEC: jal         0x800849D0
    // 0x80801CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_1(rdram, ctx);
        goto after_21;
    // 0x80801CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80801CF4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80801CF8: b           L_80801E5C
    // 0x80801CFC: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_80801E5C;
    // 0x80801CFC: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80801D00:
    // 0x80801D00: jal         0x8009BB00
    // 0x80801D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_22;
    // 0x80801D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80801D08: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80801D0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801D10: nop

    // 0x80801D14: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80801D18: nop

    // 0x80801D1C: bc1fl       L_80801D30
    if (!c1cs) {
        // 0x80801D20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D30;
    }
    goto skip_1;
    // 0x80801D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80801D24: jal         0x8009D658
    // 0x80801D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_23;
    // 0x80801D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80801D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801D30:
    // 0x80801D30: jal         0x8009D3A8
    // 0x80801D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_24;
    // 0x80801D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80801D38: jal         0x8008B324
    // 0x80801D3C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_25;
    // 0x80801D3C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_25:
    // 0x80801D40: beq         $v0, $zero, L_80801D78
    if (ctx->r2 == 0) {
        // 0x80801D44: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80801D78;
    }
    // 0x80801D44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801D48: lui         $a2, 0x3F63
    ctx->r6 = S32(0X3F63 << 16);
    // 0x80801D4C: ori         $a2, $a2, 0xC9EF
    ctx->r6 = ctx->r6 | 0XC9EF;
    // 0x80801D50: jal         0x8008B1D4
    // 0x80801D54: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_26;
    // 0x80801D54: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_26:
    // 0x80801D58: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801D5C: jal         0x8008B1BC
    // 0x80801D60: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_27;
    // 0x80801D60: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_27:
    // 0x80801D64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801D68: jal         0x8008B134
    // 0x80801D6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_28;
    // 0x80801D6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80801D70: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80801D74: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_80801D78:
    // 0x80801D78: jal         0x800849D0
    // 0x80801D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_1(rdram, ctx);
        goto after_29;
    // 0x80801D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80801D80: b           L_80801E5C
    // 0x80801D84: nop

        goto L_80801E5C;
    // 0x80801D84: nop

L_80801D88:
    // 0x80801D88: jal         0x8009BB00
    // 0x80801D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_30;
    // 0x80801D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80801D90: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80801D94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801D98: nop

    // 0x80801D9C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80801DA0: nop

    // 0x80801DA4: bc1fl       L_80801DB8
    if (!c1cs) {
        // 0x80801DA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801DB8;
    }
    goto skip_2;
    // 0x80801DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80801DAC: jal         0x8009D658
    // 0x80801DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_31;
    // 0x80801DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80801DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801DB8:
    // 0x80801DB8: jal         0x8009D3A8
    // 0x80801DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_32;
    // 0x80801DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80801DC0: jal         0x8008B324
    // 0x80801DC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_33;
    // 0x80801DC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_33:
    // 0x80801DC8: beq         $v0, $zero, L_80801E00
    if (ctx->r2 == 0) {
        // 0x80801DCC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80801E00;
    }
    // 0x80801DCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801DD0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80801DD4: jal         0x8008B1D4
    // 0x80801DD8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_34;
    // 0x80801DD8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_34:
    // 0x80801DDC: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80801DE0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801DE4: jal         0x8008B1BC
    // 0x80801DE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_35;
    // 0x80801DE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_35:
    // 0x80801DEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801DF0: jal         0x8008B134
    // 0x80801DF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_36;
    // 0x80801DF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_36:
    // 0x80801DF8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80801DFC: sw          $t0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r8;
L_80801E00:
    // 0x80801E00: jal         0x800849D0
    // 0x80801E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_1(rdram, ctx);
        goto after_37;
    // 0x80801E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80801E08: b           L_80801E5C
    // 0x80801E0C: nop

        goto L_80801E5C;
    // 0x80801E0C: nop

L_80801E10:
    // 0x80801E10: jal         0x8009BB00
    // 0x80801E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_38;
    // 0x80801E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80801E18: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80801E1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801E20: nop

    // 0x80801E24: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80801E28: nop

    // 0x80801E2C: bc1fl       L_80801E40
    if (!c1cs) {
        // 0x80801E30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E40;
    }
    goto skip_3;
    // 0x80801E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80801E34: jal         0x8009D658
    // 0x80801E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_39;
    // 0x80801E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80801E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801E40:
    // 0x80801E40: jal         0x8009D3A8
    // 0x80801E44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_40;
    // 0x80801E44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x80801E48: jal         0x8008B324
    // 0x80801E4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_41;
    // 0x80801E4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_41:
    // 0x80801E50: beq         $v0, $zero, L_80801E5C
    if (ctx->r2 == 0) {
        // 0x80801E54: addiu       $t1, $zero, 0x15
        ctx->r9 = ADD32(0, 0X15);
            goto L_80801E5C;
    }
    // 0x80801E54: addiu       $t1, $zero, 0x15
    ctx->r9 = ADD32(0, 0X15);
    // 0x80801E58: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80801E5C:
    // 0x80801E5C: jal         0x8008E35C
    // 0x80801E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_42;
    // 0x80801E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80801E64: beq         $v0, $zero, L_80801E70
    if (ctx->r2 == 0) {
        // 0x80801E68: addiu       $t2, $zero, 0x4C
        ctx->r10 = ADD32(0, 0X4C);
            goto L_80801E70;
    }
    // 0x80801E68: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x80801E6C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80801E70:
    // 0x80801E70: jal         0x8008E078
    // 0x80801E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_43;
    // 0x80801E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80801E78: beq         $v0, $zero, L_80801EB0
    if (ctx->r2 == 0) {
        // 0x80801E7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801EB0;
    }
    // 0x80801E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E80: jal         0x80091A58
    // 0x80801E84: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_44;
    // 0x80801E84: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_44:
    // 0x80801E88: beq         $v0, $zero, L_80801E9C
    if (ctx->r2 == 0) {
        // 0x80801E8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E9C;
    }
    // 0x80801E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E90: jal         0x8080075C
    // 0x80801E94: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8080075C_bsbtrot(rdram, ctx);
        goto after_45;
    // 0x80801E94: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_45:
    // 0x80801E98: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80801E9C:
    // 0x80801E9C: jal         0x8008DF18
    // 0x80801EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_46;
    // 0x80801EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x80801EA4: beq         $v0, $zero, L_80801EB0
    if (ctx->r2 == 0) {
        // 0x80801EA8: addiu       $t3, $zero, 0x45
        ctx->r11 = ADD32(0, 0X45);
            goto L_80801EB0;
    }
    // 0x80801EA8: addiu       $t3, $zero, 0x45
    ctx->r11 = ADD32(0, 0X45);
    // 0x80801EAC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80801EB0:
    // 0x80801EB0: jal         0x8008E260
    // 0x80801EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_47;
    // 0x80801EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80801EB8: beq         $v0, $zero, L_80801EC8
    if (ctx->r2 == 0) {
        // 0x80801EBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801EC8;
    }
    // 0x80801EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EC0: addiu       $t4, $zero, 0x3D
    ctx->r12 = ADD32(0, 0X3D);
    // 0x80801EC4: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80801EC8:
    // 0x80801EC8: jal         0x8009E5C8
    // 0x80801ECC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_48;
    // 0x80801ECC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_48:
    // 0x80801ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801ED4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801ED8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801EDC: jr          $ra
    // 0x80801EE0: nop

    return;
    // 0x80801EE0: nop

;}
RECOMP_FUNC void _gcgamefix_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088448: syscall     683
    recomp_syscall_handler(rdram, ctx, 0x80088448);
    return;
    // 0x8008844C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_800F6774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F677C: jal         0x800F6D24
    // 0x800F6780: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F6D24(rdram, ctx);
        goto after_0;
    // 0x800F6780: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6784: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F6788: beq         $t6, $zero, L_800F67DC
    if (ctx->r14 == 0) {
        // 0x800F678C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800F67DC;
    }
    // 0x800F678C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800F6790: jal         0x800F8088
    // 0x800F6794: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F8088(rdram, ctx);
        goto after_1;
    // 0x800F6794: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800F6798: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F679C: beq         $t7, $zero, L_800F67DC
    if (ctx->r15 == 0) {
        // 0x800F67A0: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800F67DC;
    }
    // 0x800F67A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F67A4: jal         0x800F68B8
    // 0x800F67A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F68B8(rdram, ctx);
        goto after_2;
    // 0x800F67A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800F67AC: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F67B0: beq         $t8, $zero, L_800F67DC
    if (ctx->r24 == 0) {
        // 0x800F67B4: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800F67DC;
    }
    // 0x800F67B4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800F67B8: jal         0x800F6CC8
    // 0x800F67BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F6CC8(rdram, ctx);
        goto after_3;
    // 0x800F67BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800F67C0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F67C4: beq         $t9, $zero, L_800F67DC
    if (ctx->r25 == 0) {
        // 0x800F67C8: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_800F67DC;
    }
    // 0x800F67C8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800F67CC: jal         0x800A8264
    // 0x800F67D0: nop

    func_800A8264(rdram, ctx);
        goto after_4;
    // 0x800F67D0: nop

    after_4:
    // 0x800F67D4: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F67D8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800F67DC:
    // 0x800F67DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F67E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F67E4: jr          $ra
    // 0x800F67E8: nop

    return;
    // 0x800F67E8: nop

;}
RECOMP_FUNC void func_80800FF4_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FF4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800FF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FFC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801000: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801004: jal         0x80100094
    // 0x80801008: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801008: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080100C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801010: lw          $t6, 0x550($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X550);
    // 0x80801014: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x80801018: beq         $at, $zero, L_80801208
    if (ctx->r1 == 0) {
        // 0x8080101C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801208;
    }
    // 0x8080101C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801020: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2216, 0X2158) << 16);
    // 0x80801024: addu        $at, $at, $t6
    gpr jr_addend_8080102C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801028: lw          $t6, 0x2158($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2216, 0X2158));
    // 0x8080102C: jr          $t6
    // 0x80801030: nop

    switch (jr_addend_8080102C >> 2) {
        case 0: goto L_80801034; break;
        case 1: goto L_80801208; break;
        case 2: goto L_80801074; break;
        case 3: goto L_808010BC; break;
        case 4: goto L_80801114; break;
        case 5: goto L_80801134; break;
        case 6: goto L_808011A0; break;
        default: switch_error(__func__, 0x8080102C, 0x80802158);
    }
    // 0x80801030: nop

L_80801034:
    // 0x80801034: jal         0x800C954C
    // 0x80801038: nop

    func_800C954C(rdram, ctx);
        goto after_1;
    // 0x80801038: nop

    after_1:
    // 0x8080103C: bne         $v0, $zero, L_80801208
    if (ctx->r2 != 0) {
        // 0x80801040: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80801208;
    }
    // 0x80801040: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80801044: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80801048: addiu       $t8, $zero, 0x6F
    ctx->r24 = ADD32(0, 0X6F);
    // 0x8080104C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801050: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80801054: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80801058: jal         0x8008A208
    // 0x8080105C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x8080105C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80801060: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801064: jal         0x80800CF8
    // 0x80801068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_3;
    // 0x80801068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080106C: b           L_8080120C
    // 0x80801070: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080120C;
    // 0x80801070: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801074:
    // 0x80801074: jal         0x8080135C
    // 0x80801078: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8080135C_chfpsgame(rdram, ctx);
        goto after_4;
    // 0x80801078: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x8080107C: jal         0x8080121C
    // 0x80801080: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8080121C_chfpsgame(rdram, ctx);
        goto after_5;
    // 0x80801080: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x80801084: beq         $v0, $zero, L_8080109C
    if (ctx->r2 == 0) {
        // 0x80801088: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8080109C;
    }
    // 0x80801088: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080108C: jal         0x80800CF8
    // 0x80801090: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_6;
    // 0x80801090: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80801094: b           L_8080120C
    // 0x80801098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080120C;
    // 0x80801098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080109C:
    // 0x8080109C: jal         0x808012CC
    // 0x808010A0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808012CC_chfpsgame(rdram, ctx);
        goto after_7;
    // 0x808010A0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x808010A4: beq         $v0, $zero, L_80801208
    if (ctx->r2 == 0) {
        // 0x808010A8: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801208;
    }
    // 0x808010A8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808010AC: jal         0x80800CF8
    // 0x808010B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_8;
    // 0x808010B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x808010B4: b           L_8080120C
    // 0x808010B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080120C;
    // 0x808010B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010BC:
    // 0x808010BC: jal         0x8080135C
    // 0x808010C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8080135C_chfpsgame(rdram, ctx);
        goto after_9;
    // 0x808010C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x808010C4: jal         0x800D8FF8
    // 0x808010C8: nop

    func_800D8FF8(rdram, ctx);
        goto after_10;
    // 0x808010C8: nop

    after_10:
    // 0x808010CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808010D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808010D4: jal         0x800F1574
    // 0x808010D8: addiu       $a0, $a0, 0x554
    ctx->r4 = ADD32(ctx->r4, 0X554);
    func_800F1574(rdram, ctx);
        goto after_11;
    // 0x808010D8: addiu       $a0, $a0, 0x554
    ctx->r4 = ADD32(ctx->r4, 0X554);
    after_11:
    // 0x808010DC: beq         $v0, $zero, L_808010F4
    if (ctx->r2 == 0) {
        // 0x808010E0: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808010F4;
    }
    // 0x808010E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808010E4: jal         0x80800CF8
    // 0x808010E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_12;
    // 0x808010E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x808010EC: b           L_8080120C
    // 0x808010F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080120C;
    // 0x808010F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010F4:
    // 0x808010F4: jal         0x8080121C
    // 0x808010F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8080121C_chfpsgame(rdram, ctx);
        goto after_13;
    // 0x808010F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_13:
    // 0x808010FC: beq         $v0, $zero, L_80801208
    if (ctx->r2 == 0) {
        // 0x80801100: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801208;
    }
    // 0x80801100: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801104: jal         0x80800CF8
    // 0x80801108: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_14;
    // 0x80801108: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x8080110C: b           L_8080120C
    // 0x80801110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080120C;
    // 0x80801110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801114:
    // 0x80801114: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80801118: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080111C: bnel        $t9, $zero, L_8080120C
    if (ctx->r25 != 0) {
        // 0x80801120: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080120C;
    }
    goto skip_0;
    // 0x80801120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801124: jal         0x80800CF8
    // 0x80801128: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_15;
    // 0x80801128: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
    // 0x8080112C: b           L_8080120C
    // 0x80801130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080120C;
    // 0x80801130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801134:
    // 0x80801134: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801138: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8080113C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80801140: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801144: blezl       $t1, L_8080118C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80801148: lw          $t4, 0x28($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X28);
            goto L_8080118C;
    }
    goto skip_1;
    // 0x80801148: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    skip_1:
L_8080114C:
    // 0x8080114C: jal         0x800F53D0
    // 0x80801150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F53D0(rdram, ctx);
        goto after_16;
    // 0x80801150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801154: jal         0x800A4C68
    // 0x80801158: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A4C68(rdram, ctx);
        goto after_17;
    // 0x80801158: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x8080115C: jal         0x800C96CC
    // 0x80801160: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C96CC(rdram, ctx);
        goto after_18;
    // 0x80801160: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
    // 0x80801164: bne         $v0, $zero, L_80801174
    if (ctx->r2 != 0) {
        // 0x80801168: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_80801174;
    }
    // 0x80801168: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8080116C: b           L_80801188
    // 0x80801170: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
        goto L_80801188;
    // 0x80801170: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80801174:
    // 0x80801174: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80801178: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080117C: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80801180: bne         $at, $zero, L_8080114C
    if (ctx->r1 != 0) {
        // 0x80801184: nop
    
            goto L_8080114C;
    }
    // 0x80801184: nop

L_80801188:
    // 0x80801188: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
L_8080118C:
    // 0x8080118C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801190: beq         $t4, $zero, L_808011A0
    if (ctx->r12 == 0) {
        // 0x80801194: nop
    
            goto L_808011A0;
    }
    // 0x80801194: nop

    // 0x80801198: jal         0x80800CF8
    // 0x8080119C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_19;
    // 0x8080119C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_19:
L_808011A0:
    // 0x808011A0: jal         0x800D8FF8
    // 0x808011A4: nop

    func_800D8FF8(rdram, ctx);
        goto after_20;
    // 0x808011A4: nop

    after_20:
    // 0x808011A8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808011AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808011B0: jal         0x800F1574
    // 0x808011B4: addiu       $a0, $a0, 0x554
    ctx->r4 = ADD32(ctx->r4, 0X554);
    func_800F1574(rdram, ctx);
        goto after_21;
    // 0x808011B4: addiu       $a0, $a0, 0x554
    ctx->r4 = ADD32(ctx->r4, 0X554);
    after_21:
    // 0x808011B8: beq         $v0, $zero, L_808011D4
    if (ctx->r2 == 0) {
        // 0x808011BC: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_808011D4;
    }
    // 0x808011BC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x808011C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808011C4: jal         0x80800CF8
    // 0x808011C8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_22;
    // 0x808011C8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_22:
    // 0x808011CC: b           L_8080120C
    // 0x808011D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080120C;
    // 0x808011D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808011D4:
    // 0x808011D4: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x808011D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808011DC: lwc1        $f4, 0x554($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X554);
    // 0x808011E0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808011E4: nop

    // 0x808011E8: bc1fl       L_8080120C
    if (!c1cs) {
        // 0x808011EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080120C;
    }
    goto skip_2;
    // 0x808011EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808011F0: jal         0x808000BC
    // 0x808011F4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    func_808000BC_chfpsgame(rdram, ctx);
        goto after_23;
    // 0x808011F4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_23:
    // 0x808011F8: beq         $v0, $zero, L_80801208
    if (ctx->r2 == 0) {
        // 0x808011FC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801208;
    }
    // 0x808011FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801200: jal         0x80800CF8
    // 0x80801204: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_24;
    // 0x80801204: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_24:
L_80801208:
    // 0x80801208: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080120C:
    // 0x8080120C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801210: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801214: jr          $ra
    // 0x80801218: nop

    return;
    // 0x80801218: nop

;}
RECOMP_FUNC void func_80110DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110DE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110DE8: jal         0x80115478
    // 0x80110DEC: nop

    func_80115478(rdram, ctx);
        goto after_0;
    // 0x80110DEC: nop

    after_0:
    // 0x80110DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110DF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110DF8: jr          $ra
    // 0x80110DFC: nop

    return;
    // 0x80110DFC: nop

;}
RECOMP_FUNC void _bstntswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FE8: syscall     100
    recomp_syscall_handler(rdram, ctx, 0x80083FE8);
    return;
    // 0x80083FEC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chflysaucerdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1764, 0X1A8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1764, 0X1A8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1764, 0X1A8));
;}
RECOMP_FUNC void func_808004C8_sccustom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004D4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3342, 0X930) << 16);
    // 0x808004D8: jal         0x800E73D4
    // 0x808004DC: addiu       $a0, $a0, 0x930
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X930));
    func_800E73D4(rdram, ctx);
        goto after_0;
    // 0x808004DC: addiu       $a0, $a0, 0x930
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X930));
    after_0:
    // 0x808004E0: jal         0x8008A618
    // 0x808004E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x808004E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808004E8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3342, 0X930) << 16);
    // 0x808004EC: addiu       $a0, $a0, 0x930
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X930));
    // 0x808004F0: jal         0x800E6DB4
    // 0x808004F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_2;
    // 0x808004F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x808004F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3342, 0X930) << 16);
    // 0x80800500: addiu       $v0, $v0, 0x930
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3342, 0X930));
    // 0x80800504: jr          $ra
    // 0x80800508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8010CFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CFBC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8010CFC0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8010CFC4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8010CFC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8010CFCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010CFD0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8010CFD4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8010CFD8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8010CFDC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8010CFE0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010CFE4: jal         0x800F54E4
    // 0x8010CFE8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8010CFE8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_0:
    // 0x8010CFEC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8010CFF0: jal         0x800F57C0
    // 0x8010CFF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F57C0(rdram, ctx);
        goto after_1;
    // 0x8010CFF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8010CFF8: addiu       $s4, $sp, 0x44
    ctx->r20 = ADD32(ctx->r29, 0X44);
    // 0x8010CFFC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8010D000: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010D004: jal         0x800EE7F8
    // 0x8010D008: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8010D008: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8010D00C: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x8010D010: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010D014: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010D018: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010D01C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8010D020: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010D024: blez        $s2, L_8010D074
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8010D028: swc1        $f10, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
            goto L_8010D074;
    }
    // 0x8010D028: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x8010D02C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8010D030: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
    // 0x8010D034: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010D038: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8010D03C:
    // 0x8010D03C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8010D040: jal         0x800F5794
    // 0x8010D044: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F5794(rdram, ctx);
        goto after_3;
    // 0x8010D044: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x8010D048: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010D04C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8010D050: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010D054: jal         0x800F0008
    // 0x8010D058: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800F0008(rdram, ctx);
        goto after_4;
    // 0x8010D058: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x8010D05C: beq         $v0, $zero, L_8010D06C
    if (ctx->r2 == 0) {
        // 0x8010D060: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8010D06C;
    }
    // 0x8010D060: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8010D064: b           L_8010D078
    // 0x8010D068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010D078;
    // 0x8010D068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010D06C:
    // 0x8010D06C: bnel        $s0, $s2, L_8010D03C
    if (ctx->r16 != ctx->r18) {
        // 0x8010D070: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8010D03C;
    }
    goto skip_0;
    // 0x8010D070: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
L_8010D074:
    // 0x8010D074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010D078:
    // 0x8010D078: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010D07C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010D080: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8010D084: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8010D088: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8010D08C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8010D090: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8010D094: jr          $ra
    // 0x8010D098: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8010D098: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _scinfobar_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5E8: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5E8);
    return;
    // 0x8008A5EC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
