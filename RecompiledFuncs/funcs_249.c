#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801208_subaddiedialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801208: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080120C: andi        $t7, $a3, 0x20
    ctx->r15 = ctx->r7 & 0X20;
    // 0x80801210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801214: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801218: beq         $t7, $zero, L_80801228
    if (ctx->r15 == 0) {
        // 0x8080121C: sw          $a2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r6;
            goto L_80801228;
    }
    // 0x8080121C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80801220: ori         $t8, $a2, 0x1
    ctx->r24 = ctx->r6 | 0X1;
    // 0x80801224: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80801228:
    // 0x80801228: jal         0x80800000
    // 0x8080122C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_0;
    // 0x8080122C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x80801230: bne         $v0, $zero, L_80801240
    if (ctx->r2 != 0) {
        // 0x80801234: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801240;
    }
    // 0x80801234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801238: b           L_80801274
    // 0x8080123C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801274;
    // 0x8080123C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801240:
    // 0x80801240: jal         0x80016B30
    // 0x80801244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_1;
    // 0x80801244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801248: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080124C: beq         $v0, $at, L_8080125C
    if (ctx->r2 == ctx->r1) {
        // 0x80801250: nop
    
            goto L_8080125C;
    }
    // 0x80801250: nop

    // 0x80801254: b           L_80801274
    // 0x80801258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801274;
    // 0x80801258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080125C:
    // 0x8080125C: jal         0x800F54E4
    // 0x80801260: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80801260: nop

    after_2:
    // 0x80801264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801268: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8080126C: jal         0x800F4BB8
    // 0x80801270: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800F4BB8(rdram, ctx);
        goto after_3;
    // 0x80801270: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
L_80801274:
    // 0x80801274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801278: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080127C: jr          $ra
    // 0x80801280: nop

    return;
    // 0x80801280: nop

;}
RECOMP_FUNC void baeggsetup_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005CC: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x808005D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808005D4: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x808005D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005E0: beq         $at, $zero, L_80800634
    if (ctx->r1 == 0) {
        // 0x808005E4: swc1        $f4, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
            goto L_80800634;
    }
    // 0x808005E4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x808005E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808005EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(504, 0X818) << 16);
    // 0x808005F0: addu        $at, $at, $t6
    gpr jr_addend_808005F8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808005F4: lw          $t6, 0x818($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(504, 0X818));
    // 0x808005F8: jr          $t6
    // 0x808005FC: nop

    switch (jr_addend_808005F8 >> 2) {
        case 0: goto L_80800600; break;
        case 1: goto L_80800608; break;
        case 2: goto L_80800610; break;
        case 3: goto L_80800618; break;
        case 4: goto L_80800620; break;
        case 5: goto L_80800628; break;
        case 6: goto L_80800630; break;
        default: switch_error(__func__, 0x808005F8, 0x80800818);
    }
    // 0x808005FC: nop

L_80800600:
    // 0x80800600: b           L_80800634
    // 0x80800604: addiu       $a2, $zero, 0x443E
    ctx->r6 = ADD32(0, 0X443E);
        goto L_80800634;
    // 0x80800604: addiu       $a2, $zero, 0x443E
    ctx->r6 = ADD32(0, 0X443E);
L_80800608:
    // 0x80800608: b           L_80800634
    // 0x8080060C: addiu       $a2, $zero, 0x4590
    ctx->r6 = ADD32(0, 0X4590);
        goto L_80800634;
    // 0x8080060C: addiu       $a2, $zero, 0x4590
    ctx->r6 = ADD32(0, 0X4590);
L_80800610:
    // 0x80800610: b           L_80800634
    // 0x80800614: addiu       $a2, $zero, 0x4597
    ctx->r6 = ADD32(0, 0X4597);
        goto L_80800634;
    // 0x80800614: addiu       $a2, $zero, 0x4597
    ctx->r6 = ADD32(0, 0X4597);
L_80800618:
    // 0x80800618: b           L_80800634
    // 0x8080061C: addiu       $a2, $zero, 0x4591
    ctx->r6 = ADD32(0, 0X4591);
        goto L_80800634;
    // 0x8080061C: addiu       $a2, $zero, 0x4591
    ctx->r6 = ADD32(0, 0X4591);
L_80800620:
    // 0x80800620: b           L_80800634
    // 0x80800624: addiu       $a2, $zero, 0x458F
    ctx->r6 = ADD32(0, 0X458F);
        goto L_80800634;
    // 0x80800624: addiu       $a2, $zero, 0x458F
    ctx->r6 = ADD32(0, 0X458F);
L_80800628:
    // 0x80800628: b           L_80800634
    // 0x8080062C: addiu       $a2, $zero, 0x458F
    ctx->r6 = ADD32(0, 0X458F);
        goto L_80800634;
    // 0x8080062C: addiu       $a2, $zero, 0x458F
    ctx->r6 = ADD32(0, 0X458F);
L_80800630:
    // 0x80800630: addiu       $a2, $zero, 0x443E
    ctx->r6 = ADD32(0, 0X443E);
L_80800634:
    // 0x80800634: beq         $a2, $zero, L_80800680
    if (ctx->r6 == 0) {
        // 0x80800638: sw          $a2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r6;
            goto L_80800680;
    }
    // 0x80800638: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8080063C: jal         0x8009C128
    // 0x80800640: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800640: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800644: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800648: jal         0x8009DAAC
    // 0x8080064C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009DAAC(rdram, ctx);
        goto after_1;
    // 0x8080064C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800650: jal         0x800C4B64
    // 0x80800654: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_800C4B64(rdram, ctx);
        goto after_2;
    // 0x80800654: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800658: jal         0x800C4B70
    // 0x8080065C: addiu       $a0, $zero, 0x7FFF
    ctx->r4 = ADD32(0, 0X7FFF);
    func_800C4B70(rdram, ctx);
        goto after_3;
    // 0x8080065C: addiu       $a0, $zero, 0x7FFF
    ctx->r4 = ADD32(0, 0X7FFF);
    after_3:
    // 0x80800660: jal         0x800C4B7C
    // 0x80800664: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800C4B7C(rdram, ctx);
        goto after_4;
    // 0x80800664: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800668: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(504, 0X860) << 16);
    // 0x8080066C: addiu       $a3, $a3, 0x860
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(504, 0X860));
    // 0x80800670: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80800674: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800678: jal         0x8010D930
    // 0x8080067C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_8010D930(rdram, ctx);
        goto after_5;
    // 0x8080067C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_5:
L_80800680:
    // 0x80800680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800684: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800688: jr          $ra
    // 0x8080068C: nop

    return;
    // 0x8080068C: nop

;}
RECOMP_FUNC void func_80800744_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800744: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800748: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080074C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800750: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800754: jal         0x8008CABC
    // 0x80800758: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800758: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080075C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800760: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800764: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080076C: jal         0x8008AF24
    // 0x80800770: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800770: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
    after_1:
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800778: jal         0x8008B1A0
    // 0x8080077C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x8080077C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800784: jal         0x8008AED4
    // 0x80800788: addiu       $a1, $zero, 0x148
    ctx->r5 = ADD32(0, 0X148);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800788: addiu       $a1, $zero, 0x148
    ctx->r5 = ADD32(0, 0X148);
    after_3:
    // 0x8080078C: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80800790: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: jal         0x8008B1D4
    // 0x8080079C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x8080079C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A4: jal         0x8008B1BC
    // 0x808007A8: lui         $a1, 0x4090
    ctx->r5 = S32(0X4090 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808007A8: lui         $a1, 0x4090
    ctx->r5 = S32(0X4090 << 16);
    after_5:
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B0: jal         0x8008B134
    // 0x808007B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x808007B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808007B8: jal         0x8008B064
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808007C0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808007C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007C8: lw          $a1, 0x16C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X16C);
    // 0x808007CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007D0: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x808007D4: lui         $a3, 0xC516
    ctx->r7 = S32(0XC516 << 16);
    // 0x808007D8: jal         0x80085218
    // 0x808007DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _basudie_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808007DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x808007E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007E4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808007E8: jal         0x8009BFE4
    // 0x808007EC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_9;
    // 0x808007EC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_9:
    // 0x808007F0: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x808007F4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808007F8: jal         0x8009D820
    // 0x808007FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009D820(rdram, ctx);
        goto after_10;
    // 0x808007FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800800: sb          $zero, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = 0;
    // 0x80800804: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800808: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080080C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800810: jr          $ra
    // 0x80800814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _sucoaster_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A198: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A198);
    return;
    // 0x8008A19C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_8080013C_bsblongleg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800140: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800144: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800148: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080014C: jal         0x8009E77C
    // 0x80800150: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800150: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80800154: bne         $v0, $zero, L_808001F0
    if (ctx->r2 != 0) {
        // 0x80800158: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F0;
    }
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800160: jal         0x8009E53C
    // 0x80800164: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    func_8009E53C(rdram, ctx);
        goto after_1;
    // 0x80800164: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    after_1:
    // 0x80800168: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8080016C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x8009F1C8
    // 0x80800178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_2;
    // 0x80800178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800184: jal         0x8009F1C8
    // 0x80800188: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_3;
    // 0x80800188: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: jal         0x800A0CF4
    // 0x80800194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_4;
    // 0x80800194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x800A0CE8
    // 0x808001A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CE8(rdram, ctx);
        goto after_5;
    // 0x808001A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x800A0DD0
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DD0(rdram, ctx);
        goto after_6;
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808001B8: jal         0x8009BFE4
    // 0x808001BC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_7;
    // 0x808001BC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_7:
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808001C8: jal         0x8009C554
    // 0x808001CC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_8;
    // 0x808001CC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_8:
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: jal         0x80095760
    // 0x808001D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_set(rdram, ctx);
        goto after_9;
    // 0x808001D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: jal         0x800931AC
    // 0x808001E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800931AC(rdram, ctx);
        goto after_10;
    // 0x808001E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x808001E8: jal         0x80084428
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baalarm_new(rdram, ctx);
        goto after_11;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_808001F0:
    // 0x808001F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001FC: jr          $ra
    // 0x80800200: nop

    return;
    // 0x80800200: nop

;}
RECOMP_FUNC void func_80800864_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080086C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800870: jal         0x80100094
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800878: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080087C: addiu       $a0, $zero, 0x239
    ctx->r4 = ADD32(0, 0X239);
    // 0x80800880: jal         0x801084B0
    // 0x80800884: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x80800884: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80800888: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080088C: jal         0x8008A028
    // 0x80800890: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800890: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_2:
    // 0x80800894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800898: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080089C: jr          $ra
    // 0x808008A0: nop

    return;
    // 0x808008A0: nop

;}
RECOMP_FUNC void func_808005AC_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808005B0: slti        $at, $a1, 0x96
    ctx->r1 = SIGNED(ctx->r5) < 0X96 ? 1 : 0;
    // 0x808005B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005B8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808005BC: bne         $at, $zero, L_808005D8
    if (ctx->r1 != 0) {
        // 0x808005C0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808005D8;
    }
    // 0x808005C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808005C4: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x808005C8: beq         $a1, $at, L_808006B4
    if (ctx->r5 == ctx->r1) {
        // 0x808005CC: lw          $v0, 0x48($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X48);
            goto L_808006B4;
    }
    // 0x808005CC: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x808005D0: b           L_808007F8
    // 0x808005D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007F8;
    // 0x808005D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005D8:
    // 0x808005D8: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x808005DC: bne         $at, $zero, L_808005F8
    if (ctx->r1 != 0) {
        // 0x808005E0: addiu       $t6, $a1, -0x29
        ctx->r14 = ADD32(ctx->r5, -0X29);
            goto L_808005F8;
    }
    // 0x808005E0: addiu       $t6, $a1, -0x29
    ctx->r14 = ADD32(ctx->r5, -0X29);
    // 0x808005E4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808005E8: beq         $a1, $at, L_80800668
    if (ctx->r5 == ctx->r1) {
        // 0x808005EC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800668;
    }
    // 0x808005EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808005F0: b           L_808007F8
    // 0x808005F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007F8;
    // 0x808005F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005F8:
    // 0x808005F8: sltiu       $at, $t6, 0x2A
    ctx->r1 = ctx->r14 < 0X2A ? 1 : 0;
    // 0x808005FC: beq         $at, $zero, L_808007EC
    if (ctx->r1 == 0) {
        // 0x80800600: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808007EC;
    }
    // 0x80800600: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800604: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1540, 0X106C) << 16);
    // 0x80800608: addu        $at, $at, $t6
    gpr jr_addend_80800610 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080060C: lw          $t6, 0x106C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1540, 0X106C));
    // 0x80800610: jr          $t6
    // 0x80800614: nop

    switch (jr_addend_80800610 >> 2) {
        case 0: goto L_80800658; break;
        case 1: goto L_808007DC; break;
        case 2: goto L_808007EC; break;
        case 3: goto L_808007EC; break;
        case 4: goto L_80800768; break;
        case 5: goto L_80800698; break;
        case 6: goto L_808007EC; break;
        case 7: goto L_808007C4; break;
        case 8: goto L_808007EC; break;
        case 9: goto L_808007EC; break;
        case 10: goto L_808007EC; break;
        case 11: goto L_808007EC; break;
        case 12: goto L_808007EC; break;
        case 13: goto L_808007EC; break;
        case 14: goto L_808007EC; break;
        case 15: goto L_808007EC; break;
        case 16: goto L_808007EC; break;
        case 17: goto L_808007EC; break;
        case 18: goto L_808007EC; break;
        case 19: goto L_808007EC; break;
        case 20: goto L_808007EC; break;
        case 21: goto L_80800618; break;
        case 22: goto L_808007EC; break;
        case 23: goto L_808007EC; break;
        case 24: goto L_808007EC; break;
        case 25: goto L_808007EC; break;
        case 26: goto L_808007EC; break;
        case 27: goto L_8080062C; break;
        case 28: goto L_808007EC; break;
        case 29: goto L_808007EC; break;
        case 30: goto L_808007EC; break;
        case 31: goto L_808007EC; break;
        case 32: goto L_808007EC; break;
        case 33: goto L_808007EC; break;
        case 34: goto L_808007EC; break;
        case 35: goto L_808007EC; break;
        case 36: goto L_808007EC; break;
        case 37: goto L_808007EC; break;
        case 38: goto L_808007EC; break;
        case 39: goto L_808007EC; break;
        case 40: goto L_808007EC; break;
        case 41: goto L_80800640; break;
        default: switch_error(__func__, 0x80800610, 0x8080106C);
    }
    // 0x80800614: nop

L_80800618:
    // 0x80800618: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080061C: jal         0x80800AF0
    // 0x80800620: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_80800AF0_chboggyfatboy(rdram, ctx);
        goto after_0;
    // 0x80800620: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x80800624: b           L_808007F8
    // 0x80800628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007F8;
    // 0x80800628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080062C:
    // 0x8080062C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800630: jal         0x80800C5C
    // 0x80800634: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_80800C5C_chboggyfatboy(rdram, ctx);
        goto after_1;
    // 0x80800634: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x80800638: b           L_808007F8
    // 0x8080063C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007F8;
    // 0x8080063C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800640:
    // 0x80800640: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1540, 0X1234) << 16);
    // 0x80800644: addiu       $a0, $a0, 0x1234
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1540, 0X1234));
    // 0x80800648: jal         0x80088090
    // 0x8080064C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080064C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80800650: b           L_808007F8
    // 0x80800654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007F8;
    // 0x80800654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800658:
    // 0x80800658: jal         0x80800F40
    // 0x8080065C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800F40_chboggyfatboy(rdram, ctx);
        goto after_3;
    // 0x8080065C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x80800660: b           L_808007F8
    // 0x80800664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007F8;
    // 0x80800664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800668:
    // 0x80800668: jal         0x808009E0
    // 0x8080066C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    func_808009E0_chboggyfatboy(rdram, ctx);
        goto after_4;
    // 0x8080066C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800670: jal         0x800DA298
    // 0x80800674: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800674: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    after_5:
    // 0x80800678: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8080067C: sll         $t8, $v0, 6
    ctx->r24 = S32(ctx->r2 << 6);
    // 0x80800680: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x80800684: lbu         $t0, 0x74($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X74);
    // 0x80800688: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x8080068C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800690: b           L_808007F4
    // 0x80800694: sb          $t2, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r10;
        goto L_808007F4;
    // 0x80800694: sb          $t2, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r10;
L_80800698:
    // 0x80800698: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x8080069C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808006A0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808006A4: jal         0x80800808
    // 0x808006A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800808_chboggyfatboy(rdram, ctx);
        goto after_6;
    // 0x808006A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x808006AC: b           L_808007F8
    // 0x808006B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007F8;
    // 0x808006B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006B4:
    // 0x808006B4: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x808006B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006BC: beq         $t3, $at, L_808006D4
    if (ctx->r11 == ctx->r1) {
        // 0x808006C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808006D4;
    }
    // 0x808006C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006C4: beq         $t3, $at, L_80800730
    if (ctx->r11 == ctx->r1) {
        // 0x808006C8: nop
    
            goto L_80800730;
    }
    // 0x808006C8: nop

    // 0x808006CC: b           L_808007F8
    // 0x808006D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007F8;
    // 0x808006D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006D4:
    // 0x808006D4: jal         0x800DA298
    // 0x808006D8: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808006D8: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    after_7:
    // 0x808006DC: beq         $v0, $zero, L_80800704
    if (ctx->r2 == 0) {
        // 0x808006E0: nop
    
            goto L_80800704;
    }
    // 0x808006E0: nop

    // 0x808006E4: jal         0x80800FE0
    // 0x808006E8: addiu       $a0, $zero, 0x3CA
    ctx->r4 = ADD32(0, 0X3CA);
    func_80800FE0_chboggyfatboy(rdram, ctx);
        goto after_8;
    // 0x808006E8: addiu       $a0, $zero, 0x3CA
    ctx->r4 = ADD32(0, 0X3CA);
    after_8:
    // 0x808006EC: beq         $v0, $zero, L_808006FC
    if (ctx->r2 == 0) {
        // 0x808006F0: addiu       $v1, $zero, 0x1092
        ctx->r3 = ADD32(0, 0X1092);
            goto L_808006FC;
    }
    // 0x808006F0: addiu       $v1, $zero, 0x1092
    ctx->r3 = ADD32(0, 0X1092);
    // 0x808006F4: b           L_808007F8
    // 0x808006F8: addiu       $v0, $zero, 0x1093
    ctx->r2 = ADD32(0, 0X1093);
        goto L_808007F8;
    // 0x808006F8: addiu       $v0, $zero, 0x1093
    ctx->r2 = ADD32(0, 0X1093);
L_808006FC:
    // 0x808006FC: b           L_808007F8
    // 0x80800700: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808007F8;
    // 0x80800700: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800704:
    // 0x80800704: jal         0x800F54E4
    // 0x80800708: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80800708: nop

    after_9:
    // 0x8080070C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800710: jal         0x800F64A4
    // 0x80800714: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800F64A4(rdram, ctx);
        goto after_10;
    // 0x80800714: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_10:
    // 0x80800718: beq         $v0, $zero, L_80800728
    if (ctx->r2 == 0) {
        // 0x8080071C: addiu       $v1, $zero, 0x1091
        ctx->r3 = ADD32(0, 0X1091);
            goto L_80800728;
    }
    // 0x8080071C: addiu       $v1, $zero, 0x1091
    ctx->r3 = ADD32(0, 0X1091);
    // 0x80800720: b           L_808007F8
    // 0x80800724: addiu       $v0, $zero, 0x110F
    ctx->r2 = ADD32(0, 0X110F);
        goto L_808007F8;
    // 0x80800724: addiu       $v0, $zero, 0x110F
    ctx->r2 = ADD32(0, 0X110F);
L_80800728:
    // 0x80800728: b           L_808007F8
    // 0x8080072C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808007F8;
    // 0x8080072C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800730:
    // 0x80800730: jal         0x800DA298
    // 0x80800734: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x80800734: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    after_11:
    // 0x80800738: beq         $v0, $zero, L_80800748
    if (ctx->r2 == 0) {
        // 0x8080073C: nop
    
            goto L_80800748;
    }
    // 0x8080073C: nop

    // 0x80800740: b           L_808007F8
    // 0x80800744: addiu       $v0, $zero, 0x1096
    ctx->r2 = ADD32(0, 0X1096);
        goto L_808007F8;
    // 0x80800744: addiu       $v0, $zero, 0x1096
    ctx->r2 = ADD32(0, 0X1096);
L_80800748:
    // 0x80800748: jal         0x80800FE0
    // 0x8080074C: addiu       $a0, $zero, 0x3CA
    ctx->r4 = ADD32(0, 0X3CA);
    func_80800FE0_chboggyfatboy(rdram, ctx);
        goto after_12;
    // 0x8080074C: addiu       $a0, $zero, 0x3CA
    ctx->r4 = ADD32(0, 0X3CA);
    after_12:
    // 0x80800750: beq         $v0, $zero, L_80800760
    if (ctx->r2 == 0) {
        // 0x80800754: addiu       $v1, $zero, 0x1092
        ctx->r3 = ADD32(0, 0X1092);
            goto L_80800760;
    }
    // 0x80800754: addiu       $v1, $zero, 0x1092
    ctx->r3 = ADD32(0, 0X1092);
    // 0x80800758: b           L_808007F8
    // 0x8080075C: addiu       $v0, $zero, 0x1093
    ctx->r2 = ADD32(0, 0X1093);
        goto L_808007F8;
    // 0x8080075C: addiu       $v0, $zero, 0x1093
    ctx->r2 = ADD32(0, 0X1093);
L_80800760:
    // 0x80800760: b           L_808007F8
    // 0x80800764: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808007F8;
    // 0x80800764: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800768:
    // 0x80800768: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x8080076C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1540, 0X1244) << 16);
    // 0x80800770: addiu       $a2, $a2, 0x1244
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1540, 0X1244));
    // 0x80800774: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800778: jal         0x80089D18
    // 0x8080077C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x8080077C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_13:
    // 0x80800780: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800784: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800788: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080078C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800790: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1540, 0X1114) << 16);
    // 0x80800794: lwc1        $f6, 0x1114($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1540, 0X1114));
    // 0x80800798: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8080079C: lui         $a2, 0x3F86
    ctx->r6 = S32(0X3F86 << 16);
    // 0x808007A0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808007A4: addiu       $a1, $zero, 0x525
    ctx->r5 = ADD32(0, 0X525);
    // 0x808007A8: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    // 0x808007AC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x808007B0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x808007B4: jal         0x800C9C70
    // 0x808007B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800C9C70(rdram, ctx);
        goto after_14;
    // 0x808007B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_14:
    // 0x808007BC: b           L_808007F8
    // 0x808007C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007F8;
    // 0x808007C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007C4:
    // 0x808007C4: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x808007C8: jal         0x800DA980
    // 0x808007CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_15;
    // 0x808007CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x808007D0: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x808007D4: b           L_808007F8
    // 0x808007D8: subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
        goto L_808007F8;
    // 0x808007D8: subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
L_808007DC:
    // 0x808007DC: jal         0x80800FAC
    // 0x808007E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800FAC_chboggyfatboy(rdram, ctx);
        goto after_16;
    // 0x808007E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_16:
    // 0x808007E4: b           L_808007F8
    // 0x808007E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007F8;
    // 0x808007E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007EC:
    // 0x808007EC: b           L_808007F8
    // 0x808007F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007F8;
    // 0x808007F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007F4:
    // 0x808007F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007F8:
    // 0x808007F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800800: jr          $ra
    // 0x80800804: nop

    return;
    // 0x80800804: nop

;}
RECOMP_FUNC void func_808000E8_idglowa(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000EC: bne         $a1, $at, L_80800100
    if (ctx->r5 != ctx->r1) {
        // 0x808000F0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800100;
    }
    // 0x808000F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000F8: nop

    // 0x808000FC: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_80800100:
    // 0x80800100: jr          $ra
    // 0x80800104: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    return;
    // 0x80800104: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _chhandcart_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AF8: syscall     415
    recomp_syscall_handler(rdram, ctx, 0x80086AF8);
    return;
    // 0x80086AFC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bstrexsmall_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AB8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801ABC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1BB8) << 16);
    // 0x80801AC0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801AC4: jr          $ra
    // 0x80801AC8: lw          $v0, 0x1BB8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1BB8));
    return;
    // 0x80801AC8: lw          $v0, 0x1BB8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1BB8));
    // 0x80801ACC: nop

;}
RECOMP_FUNC void func_8080156C_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080156C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801574: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801578: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8080157C: lw          $t6, 0x1E4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E4);
    // 0x80801580: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801584: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801588: sll         $t8, $t6, 21
    ctx->r24 = S32(ctx->r14 << 21);
    // 0x8080158C: bltz        $t8, L_808015B0
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801590: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808015B0;
    }
    // 0x80801590: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801594: jal         0x80015E80
    // 0x80801598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015E80(rdram, ctx);
        goto after_0;
    // 0x80801598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080159C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808015A0: jal         0x80015F28
    // 0x808015A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80015F28(rdram, ctx);
        goto after_1;
    // 0x808015A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x808015A8: b           L_808015C8
    // 0x808015AC: lhu         $t9, 0x140($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X140);
        goto L_808015C8;
    // 0x808015AC: lhu         $t9, 0x140($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X140);
L_808015B0:
    // 0x808015B0: jal         0x80015ECC
    // 0x808015B4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80015ECC(rdram, ctx);
        goto after_2;
    // 0x808015B4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x808015B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808015BC: jal         0x80015F5C
    // 0x808015C0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80015F5C(rdram, ctx);
        goto after_3;
    // 0x808015C0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x808015C4: lhu         $t9, 0x140($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X140);
L_808015C8:
    // 0x808015C8: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x808015CC: beql        $t9, $zero, L_808018C0
    if (ctx->r25 == 0) {
        // 0x808015D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808018C0;
    }
    goto skip_0;
    // 0x808015D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808015D4: beql        $t0, $zero, L_80801670
    if (ctx->r8 == 0) {
        // 0x808015D8: lw          $v0, 0x1E4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E4);
            goto L_80801670;
    }
    goto skip_1;
    // 0x808015D8: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    skip_1:
    // 0x808015DC: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
    // 0x808015E0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x808015E4: sll         $t3, $t1, 19
    ctx->r11 = S32(ctx->r9 << 19);
    // 0x808015E8: bgezl       $t3, L_80801670
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808015EC: lw          $v0, 0x1E4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E4);
            goto L_80801670;
    }
    goto skip_2;
    // 0x808015EC: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    skip_2:
    // 0x808015F0: beq         $t4, $zero, L_8080166C
    if (ctx->r12 == 0) {
        // 0x808015F4: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8080166C;
    }
    // 0x808015F4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808015F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808015FC: lwc1        $f6, 0x14C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x80801600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801604: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80801608: nop

    // 0x8080160C: bc1fl       L_80801628
    if (!c1cs) {
        // 0x80801610: lb          $t5, 0x1CF($s0)
        ctx->r13 = MEM_B(ctx->r16, 0X1CF);
            goto L_80801628;
    }
    goto skip_3;
    // 0x80801610: lb          $t5, 0x1CF($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1CF);
    skip_3:
    // 0x80801614: jal         0x808009E4
    // 0x80801618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808009E4_gczoombox(rdram, ctx);
        goto after_4;
    // 0x80801618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080161C: b           L_80801898
    // 0x80801620: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
        goto L_80801898;
    // 0x80801620: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    // 0x80801624: lb          $t5, 0x1CF($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1CF);
L_80801628:
    // 0x80801628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080162C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80801630: sb          $t6, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r14;
    // 0x80801634: lb          $t7, 0x1CF($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1CF);
    // 0x80801638: bgez        $t7, L_8080164C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8080163C: andi        $t8, $t7, 0x3
        ctx->r24 = ctx->r15 & 0X3;
            goto L_8080164C;
    }
    // 0x8080163C: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x80801640: beq         $t8, $zero, L_8080164C
    if (ctx->r24 == 0) {
        // 0x80801644: nop
    
            goto L_8080164C;
    }
    // 0x80801644: nop

    // 0x80801648: addiu       $t8, $t8, -0x4
    ctx->r24 = ADD32(ctx->r24, -0X4);
L_8080164C:
    // 0x8080164C: sb          $t8, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r24;
    // 0x80801650: lb          $t9, 0x1CF($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1CF);
    // 0x80801654: bnel        $t9, $zero, L_80801898
    if (ctx->r25 != 0) {
        // 0x80801658: lb          $v0, 0x1CF($s0)
        ctx->r2 = MEM_B(ctx->r16, 0X1CF);
            goto L_80801898;
    }
    goto skip_4;
    // 0x80801658: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    skip_4:
    // 0x8080165C: jal         0x808009E4
    // 0x80801660: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808009E4_gczoombox(rdram, ctx);
        goto after_5;
    // 0x80801660: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80801664: b           L_80801898
    // 0x80801668: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
        goto L_80801898;
    // 0x80801668: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
L_8080166C:
    // 0x8080166C: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
L_80801670:
    // 0x80801670: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80801674: sll         $v1, $v0, 9
    ctx->r3 = S32(ctx->r2 << 9);
    // 0x80801678: srl         $t0, $v1, 31
    ctx->r8 = S32(U32(ctx->r3) >> 31);
    // 0x8080167C: beq         $t0, $zero, L_80801708
    if (ctx->r8 == 0) {
        // 0x80801680: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80801708;
    }
    // 0x80801680: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80801684: sll         $t2, $v0, 10
    ctx->r10 = S32(ctx->r2 << 10);
    // 0x80801688: bgezl       $t2, L_808016D4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8080168C: lb          $t2, 0x1CF($s0)
        ctx->r10 = MEM_B(ctx->r16, 0X1CF);
            goto L_808016D4;
    }
    goto skip_5;
    // 0x8080168C: lb          $t2, 0x1CF($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1CF);
    skip_5:
    // 0x80801690: lb          $t3, 0x1CF($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1CF);
    // 0x80801694: lbu         $t6, 0x1D1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1D1);
    // 0x80801698: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8080169C: sb          $t4, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r12;
    // 0x808016A0: lb          $t5, 0x1CF($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1CF);
    // 0x808016A4: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x808016A8: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x808016AC: bnel        $at, $zero, L_80801898
    if (ctx->r1 != 0) {
        // 0x808016B0: lb          $v0, 0x1CF($s0)
        ctx->r2 = MEM_B(ctx->r16, 0X1CF);
            goto L_80801898;
    }
    goto skip_6;
    // 0x808016B0: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    skip_6:
    // 0x808016B4: lbu         $t8, 0x1E5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
    // 0x808016B8: sb          $zero, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = 0;
    // 0x808016BC: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x808016C0: sb          $t0, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r8;
    // 0x808016C4: andi        $t1, $t0, 0xBF
    ctx->r9 = ctx->r8 & 0XBF;
    // 0x808016C8: b           L_80801894
    // 0x808016CC: sb          $t1, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r9;
        goto L_80801894;
    // 0x808016CC: sb          $t1, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r9;
    // 0x808016D0: lb          $t2, 0x1CF($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1CF);
L_808016D4:
    // 0x808016D4: lbu         $t4, 0x1D1($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1D1);
    // 0x808016D8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x808016DC: sb          $t3, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r11;
    // 0x808016E0: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    // 0x808016E4: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808016E8: bnel        $at, $zero, L_80801898
    if (ctx->r1 != 0) {
        // 0x808016EC: lb          $v0, 0x1CF($s0)
        ctx->r2 = MEM_B(ctx->r16, 0X1CF);
            goto L_80801898;
    }
    goto skip_7;
    // 0x808016EC: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    skip_7:
    // 0x808016F0: lbu         $t5, 0x1E5($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1E5);
    // 0x808016F4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x808016F8: sb          $t8, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r24;
    // 0x808016FC: ori         $t7, $t5, 0x20
    ctx->r15 = ctx->r13 | 0X20;
    // 0x80801700: b           L_80801894
    // 0x80801704: sb          $t7, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r15;
        goto L_80801894;
    // 0x80801704: sb          $t7, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r15;
L_80801708:
    // 0x80801708: beq         $t9, $zero, L_80801840
    if (ctx->r25 == 0) {
        // 0x8080170C: sll         $t1, $v0, 19
        ctx->r9 = S32(ctx->r2 << 19);
            goto L_80801840;
    }
    // 0x8080170C: sll         $t1, $v0, 19
    ctx->r9 = S32(ctx->r2 << 19);
    // 0x80801710: bgez        $t1, L_80801730
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80801714: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_80801730;
    }
    // 0x80801714: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80801718: beql        $t2, $zero, L_80801734
    if (ctx->r10 == 0) {
        // 0x8080171C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80801734;
    }
    goto skip_8;
    // 0x8080171C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_8:
    // 0x80801720: jal         0x8001211C
    // 0x80801724: nop

    func_8001211C(rdram, ctx);
        goto after_6;
    // 0x80801724: nop

    after_6:
    // 0x80801728: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8080172C: bne         $t3, $zero, L_808018BC
    if (ctx->r11 != 0) {
        // 0x80801730: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808018BC;
    }
L_80801730:
    // 0x80801730: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_80801734:
    // 0x80801734: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801738: lwc1        $f10, 0x14C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x8080173C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801740: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80801744: nop

    // 0x80801748: bc1fl       L_80801764
    if (!c1cs) {
        // 0x8080174C: lbu         $t4, 0x178($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X178);
            goto L_80801764;
    }
    goto skip_9;
    // 0x8080174C: lbu         $t4, 0x178($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X178);
    skip_9:
    // 0x80801750: jal         0x808009E4
    // 0x80801754: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808009E4_gczoombox(rdram, ctx);
        goto after_7;
    // 0x80801754: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80801758: b           L_808017A0
    // 0x8080175C: lbu         $t8, 0x1E5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
        goto L_808017A0;
    // 0x8080175C: lbu         $t8, 0x1E5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
    // 0x80801760: lbu         $t4, 0x178($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X178);
L_80801764:
    // 0x80801764: beql        $t4, $zero, L_808017A0
    if (ctx->r12 == 0) {
        // 0x80801768: lbu         $t8, 0x1E5($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
            goto L_808017A0;
    }
    goto skip_10;
    // 0x80801768: lbu         $t8, 0x1E5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
    skip_10:
    // 0x8080176C: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    // 0x80801770: bnel        $v0, $zero, L_808017A0
    if (ctx->r2 != 0) {
        // 0x80801774: lbu         $t8, 0x1E5($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
            goto L_808017A0;
    }
    goto skip_11;
    // 0x80801774: lbu         $t8, 0x1E5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
    skip_11:
    // 0x80801778: lbu         $t6, 0x1D0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1D0);
    // 0x8080177C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801780: addu        $t5, $s0, $t6
    ctx->r13 = ADD32(ctx->r16, ctx->r14);
    // 0x80801784: lbu         $t7, 0xF0($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0XF0);
    // 0x80801788: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8080178C: beql        $at, $zero, L_808017A0
    if (ctx->r1 == 0) {
        // 0x80801790: lbu         $t8, 0x1E5($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
            goto L_808017A0;
    }
    goto skip_12;
    // 0x80801790: lbu         $t8, 0x1E5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
    skip_12:
    // 0x80801794: jal         0x808009E4
    // 0x80801798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808009E4_gczoombox(rdram, ctx);
        goto after_8;
    // 0x80801798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8080179C: lbu         $t8, 0x1E5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
L_808017A0:
    // 0x808017A0: lbu         $v1, 0x1D0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1D0);
    // 0x808017A4: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    // 0x808017A8: andi        $t0, $t8, 0xFFBF
    ctx->r8 = ctx->r24 & 0XFFBF;
    // 0x808017AC: sb          $t0, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r8;
    // 0x808017B0: andi        $t1, $t0, 0xDF
    ctx->r9 = ctx->r8 & 0XDF;
    // 0x808017B4: sb          $t1, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r9;
    // 0x808017B8: addu        $t2, $s0, $v1
    ctx->r10 = ADD32(ctx->r16, ctx->r3);
    // 0x808017BC: lbu         $a0, 0xF0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0XF0);
    // 0x808017C0: bne         $v0, $a0, L_80801824
    if (ctx->r2 != ctx->r4) {
        // 0x808017C4: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80801824;
    }
    // 0x808017C4: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x808017C8: lbu         $t6, 0x1D2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1D2);
    // 0x808017CC: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x808017D0: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x808017D4: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x808017D8: bne         $at, $zero, L_80801894
    if (ctx->r1 != 0) {
        // 0x808017DC: sb          $t3, 0x1D0($s0)
        MEM_B(0X1D0, ctx->r16) = ctx->r11;
            goto L_80801894;
    }
    // 0x808017DC: sb          $t3, 0x1D0($s0)
    MEM_B(0X1D0, ctx->r16) = ctx->r11;
    // 0x808017E0: andi        $t7, $t1, 0x7F
    ctx->r15 = ctx->r9 & 0X7F;
    // 0x808017E4: sb          $zero, 0x1D0($s0)
    MEM_B(0X1D0, ctx->r16) = 0;
    // 0x808017E8: jal         0x800DC1AC
    // 0x808017EC: sb          $t7, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r15;
    func_800DC1AC(rdram, ctx);
        goto after_9;
    // 0x808017EC: sb          $t7, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r15;
    after_9:
    // 0x808017F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3DD8) << 16);
    // 0x808017F4: lwc1        $f16, 0x3DD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3DD8));
    // 0x808017F8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808017FC: nop

    // 0x80801800: bc1fl       L_80801898
    if (!c1cs) {
        // 0x80801804: lb          $v0, 0x1CF($s0)
        ctx->r2 = MEM_B(ctx->r16, 0X1CF);
            goto L_80801898;
    }
    goto skip_13;
    // 0x80801804: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    skip_13:
    // 0x80801808: lbu         $t9, 0x1E5($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1E5);
    // 0x8080180C: lbu         $t1, 0x1D1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1D1);
    // 0x80801810: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x80801814: addiu       $t2, $t1, -0x4
    ctx->r10 = ADD32(ctx->r9, -0X4);
    // 0x80801818: sb          $t0, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r8;
    // 0x8080181C: b           L_80801894
    // 0x80801820: sb          $t2, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r10;
        goto L_80801894;
    // 0x80801820: sb          $t2, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r10;
L_80801824:
    // 0x80801824: beq         $at, $zero, L_80801838
    if (ctx->r1 == 0) {
        // 0x80801828: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80801838;
    }
    // 0x80801828: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8080182C: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80801830: b           L_80801894
    // 0x80801834: sb          $t3, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r11;
        goto L_80801894;
    // 0x80801834: sb          $t3, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r11;
L_80801838:
    // 0x80801838: b           L_80801894
    // 0x8080183C: sb          $t4, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r12;
        goto L_80801894;
    // 0x8080183C: sb          $t4, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r12;
L_80801840:
    // 0x80801840: bnel        $v1, $zero, L_80801898
    if (ctx->r3 != 0) {
        // 0x80801844: lb          $v0, 0x1CF($s0)
        ctx->r2 = MEM_B(ctx->r16, 0X1CF);
            goto L_80801898;
    }
    goto skip_14;
    // 0x80801844: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    skip_14:
    // 0x80801848: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    // 0x8080184C: blez        $v0, L_8080185C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801850: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8080185C;
    }
    // 0x80801850: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80801854: b           L_80801894
    // 0x80801858: sb          $t6, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r14;
        goto L_80801894;
    // 0x80801858: sb          $t6, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r14;
L_8080185C:
    // 0x8080185C: jal         0x800DC1AC
    // 0x80801860: nop

    func_800DC1AC(rdram, ctx);
        goto after_10;
    // 0x80801860: nop

    after_10:
    // 0x80801864: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3DDC) << 16);
    // 0x80801868: lwc1        $f18, 0x3DDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3DDC));
    // 0x8080186C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80801870: nop

    // 0x80801874: bc1fl       L_80801898
    if (!c1cs) {
        // 0x80801878: lb          $v0, 0x1CF($s0)
        ctx->r2 = MEM_B(ctx->r16, 0X1CF);
            goto L_80801898;
    }
    goto skip_15;
    // 0x80801878: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
    skip_15:
    // 0x8080187C: lbu         $t7, 0x1E5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1E5);
    // 0x80801880: lbu         $t9, 0x1D1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1D1);
    // 0x80801884: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80801888: addiu       $t0, $t9, -0x4
    ctx->r8 = ADD32(ctx->r25, -0X4);
    // 0x8080188C: sb          $t8, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r24;
    // 0x80801890: sb          $t0, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r8;
L_80801894:
    // 0x80801894: lb          $v0, 0x1CF($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CF);
L_80801898:
    // 0x80801898: bgezl       $v0, L_808018AC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8080189C: lbu         $v1, 0x1D1($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X1D1);
            goto L_808018AC;
    }
    goto skip_16;
    // 0x8080189C: lbu         $v1, 0x1D1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1D1);
    skip_16:
    // 0x808018A0: b           L_808018BC
    // 0x808018A4: sb          $zero, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = 0;
        goto L_808018BC;
    // 0x808018A4: sb          $zero, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = 0;
    // 0x808018A8: lbu         $v1, 0x1D1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1D1);
L_808018AC:
    // 0x808018AC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808018B0: bne         $at, $zero, L_808018BC
    if (ctx->r1 != 0) {
        // 0x808018B4: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_808018BC;
    }
    // 0x808018B4: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x808018B8: sb          $t1, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r9;
L_808018BC:
    // 0x808018BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018C0:
    // 0x808018C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808018C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808018C8: jr          $ra
    // 0x808018CC: nop

    return;
    // 0x808018CC: nop

;}
RECOMP_FUNC void func_8008ADBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ADBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008ADC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008ADC4: jal         0x8008B5E8
    // 0x8008ADC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008B5E8(rdram, ctx);
        goto after_0;
    // 0x8008ADC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008ADCC: jal         0x8001B084
    // 0x8008ADD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x8008ADD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008ADD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008ADD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008ADDC: jr          $ra
    // 0x8008ADE0: nop

    return;
    // 0x8008ADE0: nop

;}
RECOMP_FUNC void func_808041C8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808041C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808041CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808041D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808041D4: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    // 0x808041D8: jal         0x808015DC
    // 0x808041DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808015DC_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808041DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808041E0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808041E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808041E8: jal         0x808016A0
    // 0x808041EC: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    func_808016A0_chgameselect(rdram, ctx);
        goto after_1;
    // 0x808041EC: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    after_1:
    // 0x808041F0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808041F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808041F8: jal         0x808016E8
    // 0x808041FC: lw          $a0, 0x28($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X28);
    func_808016E8_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808041FC: lw          $a0, 0x28($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X28);
    after_2:
    // 0x80804200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80804204: jal         0x80803D00
    // 0x80804208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80804208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080420C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80804218: jr          $ra
    // 0x8080421C: nop

    return;
    // 0x8080421C: nop

;}
RECOMP_FUNC void bsbanbflip_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(34, 0X510) << 16);
    // 0x80800500: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800504: jr          $ra
    // 0x80800508: lw          $v0, 0x510($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(34, 0X510));
    return;
    // 0x80800508: lw          $v0, 0x510($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(34, 0X510));
;}
RECOMP_FUNC void _subaddierouteDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F58: syscall     818
    recomp_syscall_handler(rdram, ctx, 0x80089F58);
    return;
    // 0x80089F5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800130_ncbaspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080013C: jal         0x80112518
    // 0x80800140: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80112518(rdram, ctx);
        goto after_0;
    // 0x80800140: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800144: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800148: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080014C: jal         0x801124D0
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_1;
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800154: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800158: jal         0x80112524
    // 0x8080015C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80112524(rdram, ctx);
        goto after_2;
    // 0x8080015C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800160: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800164: jal         0x801124D0
    // 0x80800168: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_801124D0(rdram, ctx);
        goto after_3;
    // 0x80800168: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void func_80800078_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080007C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800080: jal         0x80100094
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800088: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x8080008C: addiu       $a1, $zero, 0x3CA
    ctx->r5 = ADD32(0, 0X3CA);
    // 0x80800090: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x80800094: jal         0x80089FD0
    // 0x80800098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _subaddieitem_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void func_800D4DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4DD0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D4DD4: lw          $t6, -0x4BE0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BE0);
    // 0x800D4DD8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D4DDC: beq         $t6, $zero, L_800D4E10
    if (ctx->r14 == 0) {
        // 0x800D4DE0: nop
    
            goto L_800D4E10;
    }
    // 0x800D4DE0: nop

    // 0x800D4DE4: beq         $a0, $at, L_800D4E0C
    if (ctx->r4 == ctx->r1) {
        // 0x800D4DE8: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800D4E0C;
    }
    // 0x800D4DE8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800D4DEC: beq         $a0, $at, L_800D4E04
    if (ctx->r4 == ctx->r1) {
        // 0x800D4DF0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800D4E04;
    }
    // 0x800D4DF0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800D4DF4: beql        $a0, $at, L_800D4E10
    if (ctx->r4 == ctx->r1) {
        // 0x800D4DF8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800D4E10;
    }
    goto skip_0;
    // 0x800D4DF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x800D4DFC: jr          $ra
    // 0x800D4E00: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800D4E00: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D4E04:
    // 0x800D4E04: jr          $ra
    // 0x800D4E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800D4E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D4E0C:
    // 0x800D4E0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800D4E10:
    // 0x800D4E10: jr          $ra
    // 0x800D4E14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800D4E14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_80800210_chhoneycarrier(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800214: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080021C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800220: jal         0x800DC298
    // 0x80800224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80800224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800228: beq         $v0, $zero, L_80800240
    if (ctx->r2 == 0) {
        // 0x8080022C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80800240;
    }
    // 0x8080022C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800230: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800234: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800238: b           L_80800250
    // 0x8080023C: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
        goto L_80800250;
    // 0x8080023C: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
L_80800240:
    // 0x80800240: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80800244: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800248: nop

    // 0x8080024C: swc1        $f6, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f6.u32l;
L_80800250:
    // 0x80800250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void susubgame_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800764: jal         0x800CEAA8
    // 0x80800768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800CEAA8(rdram, ctx);
        goto after_0;
    // 0x80800768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080076C: beq         $v0, $zero, L_8080077C
    if (ctx->r2 == 0) {
        // 0x80800770: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080077C;
    }
    // 0x80800770: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800774: jal         0x800CE88C
    // 0x80800778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_1;
    // 0x80800778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_8080077C:
    // 0x8080077C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800784: jr          $ra
    // 0x80800788: nop

    return;
    // 0x80800788: nop

;}
RECOMP_FUNC void func_80800200_chlavacolumns(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080020C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800210: jal         0x80088F08
    // 0x80800214: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    _idworld_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800214: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_0:
    // 0x80800218: beq         $v0, $zero, L_80800230
    if (ctx->r2 == 0) {
        // 0x8080021C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800230;
    }
    // 0x8080021C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800220: jal         0x800EDCB8
    // 0x80800224: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800EDCB8(rdram, ctx);
        goto after_1;
    // 0x80800224: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800228: b           L_80800234
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800234;
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800230:
    // 0x80800230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800234:
    // 0x80800234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080023C: jr          $ra
    // 0x80800240: nop

    return;
    // 0x80800240: nop

;}
RECOMP_FUNC void _bsbfly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082950: syscall     22
    recomp_syscall_handler(rdram, ctx, 0x80082950);
    return;
    // 0x80082954: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A17A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A17A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A17AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A17B0: lw          $t6, 0x158($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X158);
    // 0x800A17B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A17B8: beql        $t6, $zero, L_800A17D4
    if (ctx->r14 == 0) {
        // 0x800A17BC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800A17D4;
    }
    goto skip_0;
    // 0x800A17BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x800A17C0: jal         0x800F9EC0
    // 0x800A17C4: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F9EC0(rdram, ctx);
        goto after_0;
    // 0x800A17C4: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x800A17C8: b           L_800A1864
    // 0x800A17CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A1864;
    // 0x800A17CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A17D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800A17D4:
    // 0x800A17D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A17D8: jal         0x800A3274
    // 0x800A17DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x800A17DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x800A17E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A17E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A17E8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A17EC: bgezl       $a1, L_800A1804
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800A17F0: sw          $a0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r4;
            goto L_800A1804;
    }
    goto skip_1;
    // 0x800A17F0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    skip_1:
    // 0x800A17F4: lbu         $t7, 0x7092($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7092);
    // 0x800A17F8: bnel        $t7, $zero, L_800A1864
    if (ctx->r15 != 0) {
        // 0x800A17FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1864;
    }
    goto skip_2;
    // 0x800A17FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800A1800: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
L_800A1804:
    // 0x800A1804: jal         0x800D4EB8
    // 0x800A1808: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800D4EB8(rdram, ctx);
        goto after_2;
    // 0x800A1808: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x800A180C: beq         $v0, $zero, L_800A1860
    if (ctx->r2 == 0) {
        // 0x800A1810: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_800A1860;
    }
    // 0x800A1810: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A1814: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800A1818: jal         0x800D3E40
    // 0x800A181C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800D3E40(rdram, ctx);
        goto after_3;
    // 0x800A181C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x800A1820: beq         $v0, $zero, L_800A1834
    if (ctx->r2 == 0) {
        // 0x800A1824: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_800A1834;
    }
    // 0x800A1824: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A1828: jal         0x800D4EB8
    // 0x800A182C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800D4EB8(rdram, ctx);
        goto after_4;
    // 0x800A182C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x800A1830: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800A1834:
    // 0x800A1834: jal         0x800D4E18
    // 0x800A1838: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800D4E18(rdram, ctx);
        goto after_5;
    // 0x800A1838: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_5:
    // 0x800A183C: jal         0x800A1294
    // 0x800A1840: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A1294(rdram, ctx);
        goto after_6;
    // 0x800A1840: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800A1844: jal         0x800D3E40
    // 0x800A1848: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800D3E40(rdram, ctx);
        goto after_7;
    // 0x800A1848: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_7:
    // 0x800A184C: beq         $v0, $zero, L_800A1860
    if (ctx->r2 == 0) {
        // 0x800A1850: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800A1860;
    }
    // 0x800A1850: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A1854: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x800A1858: jal         0x80085338
    // 0x800A185C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    _batimer_set(rdram, ctx);
        goto after_8;
    // 0x800A185C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_8:
L_800A1860:
    // 0x800A1860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1864:
    // 0x800A1864: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A1868: jr          $ra
    // 0x800A186C: nop

    return;
    // 0x800A186C: nop

;}
RECOMP_FUNC void bawobble_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800198: jal         0x8080004C
    // 0x8080019C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080004C_bawobble(rdram, ctx);
        goto after_0;
    // 0x8080019C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808001A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void func_80800430_chklungospiral(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800438: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x8080043C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800440: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800444: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800448: beq         $t7, $zero, L_80800470
    if (ctx->r15 == 0) {
        // 0x8080044C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800470;
    }
    // 0x8080044C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800450: jal         0x800856B8
    // 0x80800454: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800454: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800458: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080045C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800460: lhu         $t8, 0x6E($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6E);
    // 0x80800464: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800468: b           L_80800470
    // 0x8080046C: sh          $t9, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r25;
        goto L_80800470;
    // 0x8080046C: sh          $t9, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r25;
L_80800470:
    // 0x80800470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800478: jr          $ra
    // 0x8080047C: nop

    return;
    // 0x8080047C: nop

;}
RECOMP_FUNC void func_800CF7F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF7F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF7F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF7FC: jal         0x800CF580
    // 0x800CF800: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800CF580(rdram, ctx);
        goto after_0;
    // 0x800CF800: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CF804: beql        $v0, $zero, L_800CF820
    if (ctx->r2 == 0) {
        // 0x800CF808: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_800CF820;
    }
    goto skip_0;
    // 0x800CF808: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x800CF80C: jal         0x800A16A4
    // 0x800CF810: nop

    func_800A16A4(rdram, ctx);
        goto after_1;
    // 0x800CF810: nop

    after_1:
    // 0x800CF814: beql        $v0, $zero, L_800CF828
    if (ctx->r2 == 0) {
        // 0x800CF818: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800CF828;
    }
    goto skip_1;
    // 0x800CF818: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_1:
    // 0x800CF81C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
L_800CF820:
    // 0x800CF820: bne         $t6, $zero, L_800CF830
    if (ctx->r14 != 0) {
        // 0x800CF824: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800CF830;
    }
    // 0x800CF824: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800CF828:
    // 0x800CF828: jal         0x800CEBD8
    // 0x800CF82C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800CEBD8(rdram, ctx);
        goto after_2;
    // 0x800CF82C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_800CF830:
    // 0x800CF830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF838: jr          $ra
    // 0x800CF83C: nop

    return;
    // 0x800CF83C: nop

;}
RECOMP_FUNC void func_80101D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101D54: jal         0x80104248
    // 0x80101D58: nop

    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80101D58: nop

    after_0:
    // 0x80101D5C: beq         $v0, $zero, L_80101D6C
    if (ctx->r2 == 0) {
        // 0x80101D60: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101D6C;
    }
    // 0x80101D60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101D64: jal         0x8008B134
    // 0x80101D68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_1;
    // 0x80101D68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80101D6C:
    // 0x80101D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101D74: jr          $ra
    // 0x80101D78: nop

    return;
    // 0x80101D78: nop

;}
RECOMP_FUNC void func_800DF824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF824: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF828: jr          $ra
    // 0x800DF82C: sw          $a0, -0x3688($at)
    MEM_W(-0X3688, ctx->r1) = ctx->r4;
    return;
    // 0x800DF82C: sw          $a0, -0x3688($at)
    MEM_W(-0X3688, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800D30_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800D3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800D40: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800D44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800D48: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800D4C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800D50: beql        $t7, $zero, L_80800D80
    if (ctx->r15 == 0) {
        // 0x80800D54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800D80;
    }
    goto skip_0;
    // 0x80800D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80800D58:
    // 0x80800D58: jal         0x80089D48
    // 0x80800D5C: lbu         $a0, 0x50($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X50);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800D5C: lbu         $a0, 0x50($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X50);
    after_0:
    // 0x80800D60: lw          $t8, 0x6C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X6C);
    // 0x80800D64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800D68: sb          $zero, 0x50($s1)
    MEM_B(0X50, ctx->r17) = 0;
    // 0x80800D6C: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800D70: sltu        $at, $s0, $t9
    ctx->r1 = ctx->r16 < ctx->r25 ? 1 : 0;
    // 0x80800D74: bne         $at, $zero, L_80800D58
    if (ctx->r1 != 0) {
        // 0x80800D78: nop
    
            goto L_80800D58;
    }
    // 0x80800D78: nop

    // 0x80800D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D80:
    // 0x80800D80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800D84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800D88: jr          $ra
    // 0x80800D8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800D8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80803A18_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803A20: jal         0x80088330
    // 0x80803A24: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    _gcstatusDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80803A24: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80803A28: jal         0x80088350
    // 0x80803A2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80803A2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80803A30: jal         0x80088348
    // 0x80803A34: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80803A34: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80803A38: jal         0x80803940
    // 0x80803A3C: nop

    func_80803940_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80803A3C: nop

    after_3:
    // 0x80803A40: jal         0x80803988
    // 0x80803A44: nop

    func_80803988_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80803A44: nop

    after_4:
    // 0x80803A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803A50: jr          $ra
    // 0x80803A54: nop

    return;
    // 0x80803A54: nop

;}
RECOMP_FUNC void func_800E8714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8714: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800E8718: addiu       $a2, $a2, -0x2A00
    ctx->r6 = ADD32(ctx->r6, -0X2A00);
    // 0x800E871C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800E8720: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E8724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8728: bne         $t6, $zero, L_800E8748
    if (ctx->r14 != 0) {
        // 0x800E872C: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_800E8748;
    }
    // 0x800E872C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800E8730: addiu       $a0, $zero, 0x244
    ctx->r4 = ADD32(0, 0X244);
    // 0x800E8734: jal         0x800B3268
    // 0x800E8738: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x800E8738: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x800E873C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800E8740: addiu       $a2, $a2, -0x2A00
    ctx->r6 = ADD32(ctx->r6, -0X2A00);
    // 0x800E8744: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800E8748:
    // 0x800E8748: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800E874C: jal         0x800B3044
    // 0x800E8750: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    freelist_next(rdram, ctx);
        goto after_1;
    // 0x800E8750: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x800E8754: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E8758: addiu       $a1, $zero, 0x244
    ctx->r5 = ADD32(0, 0X244);
    // 0x800E875C: jal         0x8002D6E0
    // 0x800E8760: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    _bzero(rdram, ctx);
        goto after_2;
    // 0x800E8760: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x800E8764: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800E8768: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E876C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800E8770: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x800E8774: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800E8778: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800E877C: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
L_800E8780:
    // 0x800E8780: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800E8784: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E8788: sh          $v1, 0x44($t0)
    MEM_H(0X44, ctx->r8) = ctx->r3;
    // 0x800E878C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800E8790: addiu       $t0, $t0, 0x118
    ctx->r8 = ADD32(ctx->r8, 0X118);
    // 0x800E8794: mflo        $t7
    ctx->r15 = lo;
    // 0x800E8798: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
    // 0x800E879C: addiu       $a2, $a2, 0x118
    ctx->r6 = ADD32(ctx->r6, 0X118);
    // 0x800E87A0: sh          $v1, 0x7C($v0)
    MEM_H(0X7C, ctx->r2) = ctx->r3;
    // 0x800E87A4: sh          $v1, 0xB4($v0)
    MEM_H(0XB4, ctx->r2) = ctx->r3;
    // 0x800E87A8: sh          $v1, 0xEC($v0)
    MEM_H(0XEC, ctx->r2) = ctx->r3;
    // 0x800E87AC: bne         $a3, $t1, L_800E8780
    if (ctx->r7 != ctx->r9) {
        // 0x800E87B0: sh          $v1, 0x44($v0)
        MEM_H(0X44, ctx->r2) = ctx->r3;
            goto L_800E8780;
    }
    // 0x800E87B0: sh          $v1, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r3;
    // 0x800E87B4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800E87B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E87BC: nop

    // 0x800E87C0: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x800E87C4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800E87C8: sh          $t8, 0x240($t2)
    MEM_H(0X240, ctx->r10) = ctx->r24;
    // 0x800E87CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E87D0: lbu         $v0, 0x2F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2F);
    // 0x800E87D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E87D8: jr          $ra
    // 0x800E87DC: nop

    return;
    // 0x800E87DC: nop

;}
RECOMP_FUNC void subaddietaxi_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080028C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800294: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800298: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080029C: jal         0x800CB3E0
    // 0x808002A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800CB3E0(rdram, ctx);
        goto after_0;
    // 0x808002A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808002A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002A8: beq         $v0, $at, L_808002C4
    if (ctx->r2 == ctx->r1) {
        // 0x808002AC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002C4;
    }
    // 0x808002AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002B0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808002B4: beq         $v0, $at, L_808002C4
    if (ctx->r2 == ctx->r1) {
        // 0x808002B8: nop
    
            goto L_808002C4;
    }
    // 0x808002B8: nop

    // 0x808002BC: b           L_80800324
    // 0x808002C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800324;
    // 0x808002C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002C4:
    // 0x808002C4: jal         0x80800220
    // 0x808002C8: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    func_80800220_subaddietaxi(rdram, ctx);
        goto after_1;
    // 0x808002C8: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    after_1:
    // 0x808002CC: bne         $v0, $zero, L_808002DC
    if (ctx->r2 != 0) {
        // 0x808002D0: nop
    
            goto L_808002DC;
    }
    // 0x808002D0: nop

    // 0x808002D4: b           L_80800324
    // 0x808002D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800324;
    // 0x808002D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002DC:
    // 0x808002DC: jal         0x80089C90
    // 0x808002E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808002E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808002E4: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x808002E8: beq         $at, $zero, L_808002F8
    if (ctx->r1 == 0) {
        // 0x808002EC: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_808002F8;
    }
    // 0x808002EC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808002F0: b           L_80800324
    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800324;
    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002F8:
    // 0x808002F8: jal         0x8008FCC8
    // 0x808002FC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_8008FCC8(rdram, ctx);
        goto after_3;
    // 0x808002FC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x80800300: xori        $t7, $v0, 0x13
    ctx->r15 = ctx->r2 ^ 0X13;
    // 0x80800304: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80800308: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x8080030C: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80800324;
    }
    // 0x8080030C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800310: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800314: jal         0x800905C4
    // 0x80800318: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800905C4(rdram, ctx);
        goto after_4;
    // 0x80800318: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x8080031C: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800320: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80800324:
    // 0x80800324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080032C: jr          $ra
    // 0x80800330: nop

    return;
    // 0x80800330: nop

;}
RECOMP_FUNC void func_80800940_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800948: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080094C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800950: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800954: addiu       $a0, $zero, 0x605
    ctx->r4 = ADD32(0, 0X605);
    // 0x80800958: jal         0x800C3FF0
    // 0x8080095C: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    func_800C3FF0(rdram, ctx);
        goto after_0;
    // 0x8080095C: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    after_0:
    // 0x80800960: addiu       $a0, $zero, 0x604
    ctx->r4 = ADD32(0, 0X604);
    // 0x80800964: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800968: jal         0x800C3FF0
    // 0x8080096C: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    func_800C3FF0(rdram, ctx);
        goto after_1;
    // 0x8080096C: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    after_1:
    // 0x80800970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800978: jr          $ra
    // 0x8080097C: nop

    return;
    // 0x8080097C: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A870: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A870);
    return;
    // 0x8008A874: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void func_808003C8_chfantasydrillfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003CC: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2348, 0XA10) << 16);
    // 0x808003D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2348, 0XA50) << 16);
    // 0x808003D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003DC: addiu       $v0, $v0, 0xA50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2348, 0XA50));
    // 0x808003E0: addiu       $v1, $v1, 0xA10
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2348, 0XA10));
    // 0x808003E4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_808003E8:
    // 0x808003E8: bnel        $a0, $t6, L_80800400
    if (ctx->r4 != ctx->r14) {
        // 0x808003EC: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80800400;
    }
    goto skip_0;
    // 0x808003EC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    skip_0:
    // 0x808003F0: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x808003F4: b           L_8080040C
    // 0x808003F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8080040C;
    // 0x808003F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x808003FC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80800400:
    // 0x80800400: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80800404: bnel        $at, $zero, L_808003E8
    if (ctx->r1 != 0) {
        // 0x80800408: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_808003E8;
    }
    goto skip_1;
    // 0x80800408: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_8080040C:
    // 0x8080040C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2348, 0XA10) << 16);
    // 0x80800410: lw          $v0, 0xA10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(2348, 0XA10));
    // 0x80800414: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2348, 0XA18) << 16);
    // 0x80800418: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2348, 0XA58) << 16);
    // 0x8080041C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800420: andi        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 & 0X1;
    // 0x80800424: addiu       $a0, $a0, 0xA58
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2348, 0XA58));
    // 0x80800428: addiu       $v1, $v1, 0xA18
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2348, 0XA18));
L_8080042C:
    // 0x8080042C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80800430: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x80800434: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x80800438: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x8080043C: sltiu       $t0, $t9, 0x1
    ctx->r8 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80800440: and         $v0, $v0, $t0
    ctx->r2 = ctx->r2 & ctx->r8;
    // 0x80800444: sltiu       $t2, $t1, 0x1
    ctx->r10 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80800448: and         $v0, $v0, $t2
    ctx->r2 = ctx->r2 & ctx->r10;
    // 0x8080044C: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80800450: and         $v0, $v0, $t4
    ctx->r2 = ctx->r2 & ctx->r12;
    // 0x80800454: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80800458: sltiu       $t6, $t5, 0x1
    ctx->r14 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8080045C: bne         $v1, $a0, L_8080042C
    if (ctx->r3 != ctx->r4) {
        // 0x80800460: and         $v0, $v0, $t6
        ctx->r2 = ctx->r2 & ctx->r14;
            goto L_8080042C;
    }
    // 0x80800460: and         $v0, $v0, $t6
    ctx->r2 = ctx->r2 & ctx->r14;
    // 0x80800464: beq         $v0, $zero, L_80800478
    if (ctx->r2 == 0) {
        // 0x80800468: addiu       $a0, $zero, 0xA0F
        ctx->r4 = ADD32(0, 0XA0F);
            goto L_80800478;
    }
    // 0x80800468: addiu       $a0, $zero, 0xA0F
    ctx->r4 = ADD32(0, 0XA0F);
    // 0x8080046C: jal         0x800DA524
    // 0x80800470: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x80800470: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800474: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80800478:
    // 0x80800478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080047C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800480: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80800484: jr          $ra
    // 0x80800488: nop

    return;
    // 0x80800488: nop

;}
RECOMP_FUNC void suspline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B0: jal         0x800EE7F8
    // 0x808001B4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808001B4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_0:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void func_80800024_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800030: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800034: jal         0x80100094
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080003C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800040: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800044: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800048: jal         0x800EE940
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800EE940(rdram, ctx);
        goto after_1;
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800050: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800054: jal         0x800EE7F8
    // 0x80800058: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800058: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x8080005C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800060: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080006C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800070: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800074: jal         0x80801324
    // 0x80800078: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    func_80801324_chaliendad(rdram, ctx);
        goto after_3;
    // 0x80800078: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    after_3:
    // 0x8080007C: jal         0x80801DD0
    // 0x80800080: nop

    func_80801DD0_chaliendad(rdram, ctx);
        goto after_4;
    // 0x80800080: nop

    after_4:
    // 0x80800084: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800088: bnel        $v0, $at, L_8080009C
    if (ctx->r2 != ctx->r1) {
        // 0x8080008C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080009C;
    }
    goto skip_0;
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800090: jal         0x800FFAB0
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080009C:
    // 0x8080009C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x808000F8: jr          $ra
    // 0x808000FC: sb          $a0, -0x4BF0($at)
    MEM_B(-0X4BF0, ctx->r1) = ctx->r4;
    return;
    // 0x808000FC: sb          $a0, -0x4BF0($at)
    MEM_B(-0X4BF0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _gcnewoption_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DB0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DB0);
    return;
    // 0x80087DB4: addi        $t0, $zero, 0x8C
    ctx->r8 = ADD32(0, 0X8C);
;}
RECOMP_FUNC void func_80800B6C_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800B7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B80: jal         0x800DF744
    // 0x80800B84: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80800B84: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80800B88: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800B8C: jal         0x800DF744
    // 0x80800B90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800B90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800B94: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800B98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B9C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800BA0: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x80800BA4: sll         $t0, $t8, 18
    ctx->r8 = S32(ctx->r24 << 18);
    // 0x80800BA8: bgez        $t0, L_80800BB8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800BAC: nop
    
            goto L_80800BB8;
    }
    // 0x80800BAC: nop

    // 0x80800BB0: b           L_80800BB8
    // 0x80800BB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800BB8;
    // 0x80800BB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800BB8:
    // 0x80800BB8: jal         0x800DF744
    // 0x80800BBC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800BBC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80800BC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BC4: jal         0x80101870
    // 0x80800BC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_3;
    // 0x80800BC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BD4: jr          $ra
    // 0x80800BD8: nop

    return;
    // 0x80800BD8: nop

;}
RECOMP_FUNC void func_8080078C_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800790: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800794: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080079C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808007A0: jal         0x8010CAC0
    // 0x808007A4: addiu       $a1, $zero, 0x2EE
    ctx->r5 = ADD32(0, 0X2EE);
    func_8010CAC0(rdram, ctx);
        goto after_0;
    // 0x808007A4: addiu       $a1, $zero, 0x2EE
    ctx->r5 = ADD32(0, 0X2EE);
    after_0:
    // 0x808007A8: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808007AC: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808007B0: bltz        $t8, L_808007E8
    if (SIGNED(ctx->r24) < 0) {
        // 0x808007B4: nop
    
            goto L_808007E8;
    }
    // 0x808007B4: nop

    // 0x808007B8: beq         $v0, $zero, L_80800810
    if (ctx->r2 == 0) {
        // 0x808007BC: addiu       $a0, $zero, 0x44
        ctx->r4 = ADD32(0, 0X44);
            goto L_80800810;
    }
    // 0x808007BC: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x808007C0: jal         0x800FC63C
    // 0x808007C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800FC63C(rdram, ctx);
        goto after_1;
    // 0x808007C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808007C8: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x808007CC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808007D0: jal         0x800FCAE0
    // 0x808007D4: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    func_800FCAE0(rdram, ctx);
        goto after_2;
    // 0x808007D4: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    after_2:
    // 0x808007D8: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808007DC: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x808007E0: b           L_80800810
    // 0x808007E4: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_80800810;
    // 0x808007E4: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_808007E8:
    // 0x808007E8: bne         $v0, $zero, L_80800810
    if (ctx->r2 != 0) {
        // 0x808007EC: addiu       $a0, $zero, 0x44
        ctx->r4 = ADD32(0, 0X44);
            goto L_80800810;
    }
    // 0x808007EC: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x808007F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007F4: jal         0x800FCAE0
    // 0x808007F8: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    func_800FCAE0(rdram, ctx);
        goto after_3;
    // 0x808007F8: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    after_3:
    // 0x808007FC: jal         0x800FCA90
    // 0x80800800: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    func_800FCA90(rdram, ctx);
        goto after_4;
    // 0x80800800: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_4:
    // 0x80800804: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800808: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x8080080C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800810:
    // 0x80800810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800814: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800818: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080081C: jr          $ra
    // 0x80800820: nop

    return;
    // 0x80800820: nop

;}
RECOMP_FUNC void glrecord_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80800090: lw          $v0, -0x2A48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2A48);
    // 0x80800094: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800098: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8080009C: jr          $ra
    // 0x808000A0: sll         $v0, $t6, 1
    ctx->r2 = S32(ctx->r14 << 1);
    return;
    // 0x808000A0: sll         $v0, $t6, 1
    ctx->r2 = S32(ctx->r14 << 1);
;}
RECOMP_FUNC void _batimer_isNonzero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085328: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x80085328);
    return;
    // 0x8008532C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void bsdronebitten_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080045C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800460: jal         0x80099AA8
    // 0x80800464: nop

    func_80099AA8(rdram, ctx);
        goto after_0;
    // 0x80800464: nop

    after_0:
    // 0x80800468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080046C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800470: jr          $ra
    // 0x80800474: nop

    return;
    // 0x80800474: nop

;}
RECOMP_FUNC void _choctopus_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F40: syscall     262
    recomp_syscall_handler(rdram, ctx, 0x80085F40);
    return;
    // 0x80085F44: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080000C_chelectricfence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x800EA05C
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800020: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x80800024: bnel        $v0, $at, L_80800040
    if (ctx->r2 != ctx->r1) {
        // 0x80800028: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800040;
    }
    goto skip_0;
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080002C: jal         0x8010A624
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_1;
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800034: jal         0x8010A570
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800040:
    // 0x80800040: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800044: jal         0x80104004
    // 0x80800048: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    func_80104004(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_3:
    // 0x8080004C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800050: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void chstarspinnerstar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(956, 0X6B0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x6B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(956, 0X6B0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x6B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(956, 0X6B0));
;}
RECOMP_FUNC void _gsmaker_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825F8: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825F8);
    return;
    // 0x800825FC: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void suquiz_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800D40: lw          $t6, 0x7614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7614);
    // 0x80800D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D4C: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    // 0x80800D50: jal         0x800DA544
    // 0x80800D54: sh          $a1, 0x34($t6)
    MEM_H(0X34, ctx->r14) = ctx->r5;
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800D54: sh          $a1, 0x34($t6)
    MEM_H(0X34, ctx->r14) = ctx->r5;
    after_0:
    // 0x80800D58: jal         0x800DA524
    // 0x80800D5C: addiu       $a0, $zero, 0x6EB
    ctx->r4 = ADD32(0, 0X6EB);
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80800D5C: addiu       $a0, $zero, 0x6EB
    ctx->r4 = ADD32(0, 0X6EB);
    after_1:
    // 0x80800D60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D64: jal         0x800887D8
    // 0x80800D68: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800D68: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    after_2:
    // 0x80800D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D74: jr          $ra
    // 0x80800D78: nop

    return;
    // 0x80800D78: nop

;}
RECOMP_FUNC void _sccustom_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A678: syscall     846
    recomp_syscall_handler(rdram, ctx, 0x8008A678);
    return;
    // 0x8008A67C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
