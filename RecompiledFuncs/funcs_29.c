#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800000_chbubbleelevator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800018: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x8080001C: jal         0x80088278
    // 0x80800020: addiu       $a0, $zero, 0x299
    ctx->r4 = ADD32(0, 0X299);
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a0, $zero, 0x299
    ctx->r4 = ADD32(0, 0X299);
    after_0:
    // 0x80800024: beq         $v0, $zero, L_80800034
    if (ctx->r2 == 0) {
        // 0x80800028: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800034;
    }
    // 0x80800028: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080002C: jal         0x80088C00
    // 0x80800030: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_1:
L_80800034:
    // 0x80800034: jal         0x800EA05C
    // 0x80800038: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80800038: nop

    after_2:
    // 0x8080003C: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    // 0x80800040: beq         $v0, $at, L_80800060
    if (ctx->r2 == ctx->r1) {
        // 0x80800044: addiu       $at, $zero, 0x15A
        ctx->r1 = ADD32(0, 0X15A);
            goto L_80800060;
    }
    // 0x80800044: addiu       $at, $zero, 0x15A
    ctx->r1 = ADD32(0, 0X15A);
    // 0x80800048: bne         $v0, $at, L_80800070
    if (ctx->r2 != ctx->r1) {
        // 0x8080004C: nop
    
            goto L_80800070;
    }
    // 0x8080004C: nop

    // 0x80800050: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x80800054: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80800058: b           L_80800070
    // 0x8080005C: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
        goto L_80800070;
    // 0x8080005C: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
L_80800060:
    // 0x80800060: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x80800064: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x80800068: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x8080006C: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
L_80800070:
    // 0x80800070: jal         0x8008A738
    // 0x80800074: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    _sujiggy_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x80800078: beq         $v0, $zero, L_80800088
    if (ctx->r2 == 0) {
        // 0x8080007C: nop
    
            goto L_80800088;
    }
    // 0x8080007C: nop

    // 0x80800080: jal         0x800DA544
    // 0x80800084: addiu       $a0, $zero, 0x399
    ctx->r4 = ADD32(0, 0X399);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800084: addiu       $a0, $zero, 0x399
    ctx->r4 = ADD32(0, 0X399);
    after_4:
L_80800088:
    // 0x80800088: jal         0x800D3E40
    // 0x8080008C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_5;
    // 0x8080008C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_5:
    // 0x80800090: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800094: beql        $a1, $zero, L_808000AC
    if (ctx->r5 == 0) {
        // 0x80800098: addiu       $a0, $zero, 0x399
        ctx->r4 = ADD32(0, 0X399);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x80800098: addiu       $a0, $zero, 0x399
    ctx->r4 = ADD32(0, 0X399);
    skip_0:
    // 0x8080009C: jal         0x80088840
    // 0x808000A0: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x808000A0: addiu       $a0, $zero, 0x81
    ctx->r4 = ADD32(0, 0X81);
    after_6:
    // 0x808000A4: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808000A8: addiu       $a0, $zero, 0x399
    ctx->r4 = ADD32(0, 0X399);
L_808000AC:
    // 0x808000AC: jal         0x800DA298
    // 0x808000B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808000B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_7:
    // 0x808000B4: bne         $v0, $zero, L_808000D4
    if (ctx->r2 != 0) {
        // 0x808000B8: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808000D4;
    }
    // 0x808000B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808000BC: bne         $a1, $zero, L_808000D4
    if (ctx->r5 != 0) {
        // 0x808000C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D4;
    }
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x808004DC
    // 0x808000C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_8;
    // 0x808000C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x808000CC: b           L_80800104
    // 0x808000D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_80800104;
    // 0x808000D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808000D4:
    // 0x808000D4: jal         0x800DA298
    // 0x808000D8: addiu       $a0, $zero, 0x6CA
    ctx->r4 = ADD32(0, 0X6CA);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808000D8: addiu       $a0, $zero, 0x6CA
    ctx->r4 = ADD32(0, 0X6CA);
    after_9:
    // 0x808000DC: beq         $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F8;
    }
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x808004DC
    // 0x808000EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_10;
    // 0x808000EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808000F0: b           L_80800104
    // 0x808000F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_80800104;
    // 0x808000F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808000F8:
    // 0x808000F8: jal         0x808004DC
    // 0x808000FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_11;
    // 0x808000FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800100: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80800104:
    // 0x80800104: nop

    // 0x80800108: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8080010C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_80103AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103AC8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80103ACC: jal         0x800D6C34
    // 0x80103AD0: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D6C34(rdram, ctx);
        goto after_0;
    // 0x80103AD0: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_0:
    // 0x80103AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103ADC: jr          $ra
    // 0x80103AE0: nop

    return;
    // 0x80103AE0: nop

;}
RECOMP_FUNC void func_8080190C_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080190C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801910: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80801914: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801918: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080191C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801920: bne         $t6, $at, L_80801938
    if (ctx->r14 != ctx->r1) {
        // 0x80801924: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80801938;
    }
    // 0x80801924: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801928: jal         0x800FA708
    // 0x8080192C: nop

    func_800FA708(rdram, ctx);
        goto after_0;
    // 0x8080192C: nop

    after_0:
    // 0x80801930: b           L_80801990
    // 0x80801934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801990;
    // 0x80801934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801938:
    // 0x80801938: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8080193C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801944: bne         $t7, $at, L_80801974
    if (ctx->r15 != ctx->r1) {
        // 0x80801948: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80801974;
    }
    // 0x80801948: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080194C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801950: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80801954: jal         0x800FAAB4
    // 0x80801958: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800FAAB4(rdram, ctx);
        goto after_1;
    // 0x80801958: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x8080195C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801960: jal         0x800FA934
    // 0x80801964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FA934(rdram, ctx);
        goto after_2;
    // 0x80801964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801968: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8080196C: b           L_80801990
    // 0x80801970: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80801990;
    // 0x80801970: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80801974:
    // 0x80801974: jal         0x800FA818
    // 0x80801978: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800FA818(rdram, ctx);
        goto after_3;
    // 0x80801978: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x8080197C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801980: jal         0x800FA8E8
    // 0x80801984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FA8E8(rdram, ctx);
        goto after_4;
    // 0x80801984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801988: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8080198C: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_80801990:
    // 0x80801990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801994: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080199C: jr          $ra
    // 0x808019A0: nop

    return;
    // 0x808019A0: nop

;}
RECOMP_FUNC void func_808005D8_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005E0: addiu       $at, $zero, 0x109D
    ctx->r1 = ADD32(0, 0X109D);
    // 0x808005E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005EC: bne         $a1, $at, L_80800634
    if (ctx->r5 != ctx->r1) {
        // 0x808005F0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800634;
    }
    // 0x808005F0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808005F4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    // 0x808005F8: jal         0x80089C30
    // 0x808005FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808005FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800600: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800604: jal         0x80102424
    // 0x80800608: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800608: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_1:
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800610: jal         0x80102424
    // 0x80800614: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800614: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080061C: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    // 0x80800620: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80800624: jal         0x80800878
    // 0x80800628: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800878_chmrsboggy(rdram, ctx);
        goto after_3;
    // 0x80800628: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8080062C: b           L_808006FC
    // 0x80800630: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006FC;
    // 0x80800630: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800634:
    // 0x80800634: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(888, 0XA58) << 16);
    // 0x80800638: addiu       $a2, $a2, 0xA58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(888, 0XA58));
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: jal         0x8008A1F8
    // 0x80800644: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800644: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
    // 0x80800648: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080064C: beql        $v0, $at, L_808006DC
    if (ctx->r2 == ctx->r1) {
        // 0x80800650: lw          $t6, 0x28($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X28);
            goto L_808006DC;
    }
    goto skip_0;
    // 0x80800650: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x80800654: beq         $v0, $zero, L_808006D8
    if (ctx->r2 == 0) {
        // 0x80800658: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D8;
    }
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: jal         0x80102FE8
    // 0x80800660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80102FE8(rdram, ctx);
        goto after_5;
    // 0x80800660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: jal         0x80102424
    // 0x8080066C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x8080066C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800674: jal         0x8008A4B0
    // 0x80800678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8080067C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x80800680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800684: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800688: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080068C: jal         0x800D1000
    // 0x80800690: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_8;
    // 0x80800690: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80800694: jal         0x800DA544
    // 0x80800698: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800698: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    after_9:
    // 0x8080069C: jal         0x800DA524
    // 0x808006A0: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    func_800DA524(rdram, ctx);
        goto after_10;
    // 0x808006A0: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    after_10:
    // 0x808006A4: jal         0x800DA524
    // 0x808006A8: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    func_800DA524(rdram, ctx);
        goto after_11;
    // 0x808006A8: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    after_11:
    // 0x808006AC: jal         0x800DA524
    // 0x808006B0: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    func_800DA524(rdram, ctx);
        goto after_12;
    // 0x808006B0: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    after_12:
    // 0x808006B4: jal         0x800DA524
    // 0x808006B8: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_800DA524(rdram, ctx);
        goto after_13;
    // 0x808006B8: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_13:
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x808006C4: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    // 0x808006C8: jal         0x80800878
    // 0x808006CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800878_chmrsboggy(rdram, ctx);
        goto after_14;
    // 0x808006CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x808006D0: b           L_808006FC
    // 0x808006D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006FC;
    // 0x808006D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006D8:
    // 0x808006D8: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
L_808006DC:
    // 0x808006DC: beql        $t6, $zero, L_808006F0
    if (ctx->r14 == 0) {
        // 0x808006E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006F0;
    }
    goto skip_1;
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808006E4: jal         0x80800790
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800790_chmrsboggy(rdram, ctx);
        goto after_15;
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006F0:
    // 0x808006F0: jal         0x80102424
    // 0x808006F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x808006F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808006F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006FC:
    // 0x808006FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800700: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800704: jr          $ra
    // 0x80800708: nop

    return;
    // 0x80800708: nop

;}
RECOMP_FUNC void badeathmatch_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800154: lw          $a2, 0x158($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X158);
    // 0x80800158: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080015C: beq         $a2, $zero, L_80800184
    if (ctx->r6 == 0) {
        // 0x80800160: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800184;
    }
    // 0x80800160: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800164: jal         0x8001B084
    // 0x80800168: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    heap_free(rdram, ctx);
        goto after_0;
    // 0x80800168: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800170: jal         0x800A4C68
    // 0x80800174: sw          $zero, 0x158($a0)
    MEM_W(0X158, ctx->r4) = 0;
    func_800A4C68(rdram, ctx);
        goto after_1;
    // 0x80800174: sw          $zero, 0x158($a0)
    MEM_W(0X158, ctx->r4) = 0;
    after_1:
    // 0x80800178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080017C: jal         0x800C968C
    // 0x80800180: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800C968C(rdram, ctx);
        goto after_2;
    // 0x80800180: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
L_80800184:
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void func_800A907C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A907C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A9080: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A9084: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800A9088: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800A908C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A9090: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800A9094: bne         $a1, $t0, L_800A90AC
    if (ctx->r5 != ctx->r8) {
        // 0x800A9098: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800A90AC;
    }
    // 0x800A9098: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800A909C: jal         0x800A9010
    // 0x800A90A0: nop

    func_800A9010(rdram, ctx);
        goto after_0;
    // 0x800A90A0: nop

    after_0:
    // 0x800A90A4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800A90A8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800A90AC:
    // 0x800A90AC: bne         $a3, $t0, L_800A90BC
    if (ctx->r7 != ctx->r8) {
        // 0x800A90B0: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_800A90BC;
    }
    // 0x800A90B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A90B4: b           L_800A9194
    // 0x800A90B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A9194;
    // 0x800A90B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A90BC:
    // 0x800A90BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A90C0: addiu       $a0, $a0, 0x76D0
    ctx->r4 = ADD32(ctx->r4, 0X76D0);
    // 0x800A90C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A90C8: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
    // 0x800A90CC: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    // 0x800A90D0: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800A90D4: addu        $t1, $a0, $t9
    ctx->r9 = ADD32(ctx->r4, ctx->r25);
    // 0x800A90D8: beq         $t8, $zero, L_800A90E8
    if (ctx->r24 == 0) {
        // 0x800A90DC: nop
    
            goto L_800A90E8;
    }
    // 0x800A90DC: nop

    // 0x800A90E0: b           L_800A9194
    // 0x800A90E4: lh          $v0, 0x8($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X8);
        goto L_800A9194;
    // 0x800A90E4: lh          $v0, 0x8($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X8);
L_800A90E8:
    // 0x800A90E8: bnel        $s0, $t0, L_800A90F8
    if (ctx->r16 != ctx->r8) {
        // 0x800A90EC: lh          $v0, 0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X2);
            goto L_800A90F8;
    }
    goto skip_0;
    // 0x800A90EC: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    skip_0:
    // 0x800A90F0: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800A90F4: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
L_800A90F8:
    // 0x800A90F8: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800A90FC: bnel        $at, $zero, L_800A910C
    if (ctx->r1 != 0) {
        // 0x800A9100: lh          $t2, 0x0($a0)
        ctx->r10 = MEM_H(ctx->r4, 0X0);
            goto L_800A910C;
    }
    goto skip_1;
    // 0x800A9100: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    skip_1:
    // 0x800A9104: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
    // 0x800A9108: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
L_800A910C:
    // 0x800A910C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800A9110: addu        $a2, $a0, $a3
    ctx->r6 = ADD32(ctx->r4, ctx->r7);
    // 0x800A9114: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800A9118: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800A911C: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x800A9120: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x800A9124: sh          $a3, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r7;
    // 0x800A9128: lbu         $t8, 0x4($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X4);
    // 0x800A912C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800A9130: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A9134: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800A9138: sb          $t6, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r14;
    // 0x800A913C: jal         0x800CA334
    // 0x800A9140: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800CA334(rdram, ctx);
        goto after_1;
    // 0x800A9140: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800A9144: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800A9148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A914C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800A9150: jal         0x8010FB34
    // 0x800A9154: sw          $v0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r2;
    func_8010FB34(rdram, ctx);
        goto after_2;
    // 0x800A9154: sw          $v0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r2;
    after_2:
    // 0x800A9158: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800A915C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800A9160: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9164: sw          $v0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r2;
    // 0x800A9168: sw          $s0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r16;
    // 0x800A916C: lbu         $t9, 0x4($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X4);
    // 0x800A9170: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A9174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A9178: bnel        $t9, $at, L_800A9194
    if (ctx->r25 != ctx->r1) {
        // 0x800A917C: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_800A9194;
    }
    goto skip_2;
    // 0x800A917C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    skip_2:
    // 0x800A9180: lw          $a1, 0x38($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X38);
    // 0x800A9184: jal         0x800A88C4
    // 0x800A9188: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800A88C4(rdram, ctx);
        goto after_3;
    // 0x800A9188: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_3:
    // 0x800A918C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A9190: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800A9194:
    // 0x800A9194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A919C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A91A0: jr          $ra
    // 0x800A91A4: nop

    return;
    // 0x800A91A4: nop

;}
RECOMP_FUNC void func_808002C4_gccollectDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2626, 0XBE0) << 16);
    // 0x808002C8: lh          $t6, 0xBE0($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(2626, 0XBE0));
    // 0x808002CC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2626, 0XBE2) << 16);
    // 0x808002D0: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2626, 0XBE4) << 16);
    // 0x808002D4: bne         $a0, $t6, L_808002F0
    if (ctx->r4 != ctx->r14) {
        // 0x808002D8: nop
    
            goto L_808002F0;
    }
    // 0x808002D8: nop

    // 0x808002DC: lh          $t7, 0xBE2($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(2626, 0XBE2));
    // 0x808002E0: bne         $a1, $t7, L_808002F0
    if (ctx->r5 != ctx->r15) {
        // 0x808002E4: nop
    
            goto L_808002F0;
    }
    // 0x808002E4: nop

    // 0x808002E8: jr          $ra
    // 0x808002EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808002EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002F0:
    // 0x808002F0: lh          $t8, 0xBE4($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(2626, 0XBE4));
    // 0x808002F4: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2626, 0XBE6) << 16);
    // 0x808002F8: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2626, 0XBE8) << 16);
    // 0x808002FC: bne         $a0, $t8, L_80800318
    if (ctx->r4 != ctx->r24) {
        // 0x80800300: nop
    
            goto L_80800318;
    }
    // 0x80800300: nop

    // 0x80800304: lh          $t9, 0xBE6($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(2626, 0XBE6));
    // 0x80800308: bne         $a1, $t9, L_80800318
    if (ctx->r5 != ctx->r25) {
        // 0x8080030C: nop
    
            goto L_80800318;
    }
    // 0x8080030C: nop

    // 0x80800310: jr          $ra
    // 0x80800314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800318:
    // 0x80800318: lh          $t0, 0xBE8($t0)
    ctx->r8 = MEM_H(ctx->r8, (int16_t)RELOC_LO16(2626, 0XBE8));
    // 0x8080031C: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2626, 0XBEC) << 16);
    // 0x80800320: addiu       $v1, $v1, 0xBEC
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2626, 0XBEC));
    // 0x80800324: bne         $a0, $t0, L_80800340
    if (ctx->r4 != ctx->r8) {
        // 0x80800328: lui         $t1, 0x8080
        ctx->r9 = S32(RELOC_HI16(2626, 0XBEA) << 16);
            goto L_80800340;
    }
    // 0x80800328: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2626, 0XBEA) << 16);
    // 0x8080032C: lh          $t1, 0xBEA($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(2626, 0XBEA));
    // 0x80800330: bne         $a1, $t1, L_80800340
    if (ctx->r5 != ctx->r9) {
        // 0x80800334: nop
    
            goto L_80800340;
    }
    // 0x80800334: nop

    // 0x80800338: jr          $ra
    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800340:
    // 0x80800340: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2626, 0XC0C) << 16);
    // 0x80800344: addiu       $v0, $v0, 0xC0C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2626, 0XC0C));
    // 0x80800348: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
L_8080034C:
    // 0x8080034C: bnel        $a0, $t2, L_8080036C
    if (ctx->r4 != ctx->r10) {
        // 0x80800350: lh          $t4, 0x4($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X4);
            goto L_8080036C;
    }
    goto skip_0;
    // 0x80800350: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
    skip_0:
    // 0x80800354: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80800358: bnel        $a1, $t3, L_8080036C
    if (ctx->r5 != ctx->r11) {
        // 0x8080035C: lh          $t4, 0x4($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X4);
            goto L_8080036C;
    }
    goto skip_1;
    // 0x8080035C: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
    skip_1:
    // 0x80800360: jr          $ra
    // 0x80800364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800368: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
L_8080036C:
    // 0x8080036C: bnel        $a0, $t4, L_8080038C
    if (ctx->r4 != ctx->r12) {
        // 0x80800370: lh          $t6, 0x8($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X8);
            goto L_8080038C;
    }
    goto skip_2;
    // 0x80800370: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    skip_2:
    // 0x80800374: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x80800378: bnel        $a1, $t5, L_8080038C
    if (ctx->r5 != ctx->r13) {
        // 0x8080037C: lh          $t6, 0x8($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X8);
            goto L_8080038C;
    }
    goto skip_3;
    // 0x8080037C: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    skip_3:
    // 0x80800380: jr          $ra
    // 0x80800384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800388: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
L_8080038C:
    // 0x8080038C: bnel        $a0, $t6, L_808003AC
    if (ctx->r4 != ctx->r14) {
        // 0x80800390: lh          $t8, 0xC($v1)
        ctx->r24 = MEM_H(ctx->r3, 0XC);
            goto L_808003AC;
    }
    goto skip_4;
    // 0x80800390: lh          $t8, 0xC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XC);
    skip_4:
    // 0x80800394: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x80800398: bnel        $a1, $t7, L_808003AC
    if (ctx->r5 != ctx->r15) {
        // 0x8080039C: lh          $t8, 0xC($v1)
        ctx->r24 = MEM_H(ctx->r3, 0XC);
            goto L_808003AC;
    }
    goto skip_5;
    // 0x8080039C: lh          $t8, 0xC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XC);
    skip_5:
    // 0x808003A0: jr          $ra
    // 0x808003A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808003A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808003A8: lh          $t8, 0xC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XC);
L_808003AC:
    // 0x808003AC: bnel        $a0, $t8, L_808003CC
    if (ctx->r4 != ctx->r24) {
        // 0x808003B0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_808003CC;
    }
    goto skip_6;
    // 0x808003B0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_6:
    // 0x808003B4: lh          $t9, 0xE($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XE);
    // 0x808003B8: bnel        $a1, $t9, L_808003CC
    if (ctx->r5 != ctx->r25) {
        // 0x808003BC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_808003CC;
    }
    goto skip_7;
    // 0x808003BC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_7:
    // 0x808003C0: jr          $ra
    // 0x808003C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808003C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808003C8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_808003CC:
    // 0x808003CC: bnel        $v1, $v0, L_8080034C
    if (ctx->r3 != ctx->r2) {
        // 0x808003D0: lh          $t2, 0x0($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X0);
            goto L_8080034C;
    }
    goto skip_8;
    // 0x808003D0: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    skip_8:
    // 0x808003D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003D8: jr          $ra
    // 0x808003DC: nop

    return;
    // 0x808003DC: nop

;}
RECOMP_FUNC void func_800177C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800177C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800177C8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800177CC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800177D0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800177D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800177D8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800177DC: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800177E0: addiu       $t7, $t7, -0x6060
    ctx->r15 = ADD32(ctx->r15, -0X6060);
    // 0x800177E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800177E8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800177EC: lw          $v0, 0x20C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20C);
    // 0x800177F0: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800177F4: beq         $t8, $zero, L_80017808
    if (ctx->r24 == 0) {
        // 0x800177F8: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80017808;
    }
    // 0x800177F8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800177FC: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x80017800: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x80017804: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80017808:
    // 0x80017808: jr          $ra
    // 0x8001780C: nop

    return;
    // 0x8001780C: nop

;}
RECOMP_FUNC void func_800FCDB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCDB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FCDB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FCDBC: jal         0x800FB5F8
    // 0x800FCDC0: nop

    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FCDC0: nop

    after_0:
    // 0x800FCDC4: beq         $v0, $zero, L_800FCDD4
    if (ctx->r2 == 0) {
        // 0x800FCDC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FCDD4;
    }
    // 0x800FCDC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FCDCC: b           L_800FCDD8
    // 0x800FCDD0: lw          $v0, 0x2C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2C);
        goto L_800FCDD8;
    // 0x800FCDD0: lw          $v0, 0x2C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2C);
L_800FCDD4:
    // 0x800FCDD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FCDD8:
    // 0x800FCDD8: jr          $ra
    // 0x800FCDDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FCDDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chtrashcangame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087690: syscall     604
    recomp_syscall_handler(rdram, ctx, 0x80087690);
    return;
    // 0x80087694: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bskaz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832F8: syscall     53
    recomp_syscall_handler(rdram, ctx, 0x800832F8);
    return;
    // 0x800832FC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800974_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800974: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80800978: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8080097C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800980: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800984: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800988: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080098C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80800990: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800994: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800998: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8080099C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808009A0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808009A4: jal         0x80100094
    // 0x808009A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009AC: jal         0x800DF324
    // 0x808009B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800DF324(rdram, ctx);
        goto after_1;
    // 0x808009B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x808009B4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x808009B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808009BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808009C0: jal         0x800AE290
    // 0x808009C4: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800AE290(rdram, ctx);
        goto after_2;
    // 0x808009C4: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_2:
    // 0x808009C8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x808009CC: jal         0x800AE080
    // 0x808009D0: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    func_800AE080(rdram, ctx);
        goto after_3;
    // 0x808009D0: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    after_3:
    // 0x808009D4: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    // 0x808009D8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808009DC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808009E0: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x808009E4: beq         $t9, $zero, L_80800A78
    if (ctx->r25 == 0) {
        // 0x808009E8: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80800A78;
    }
    // 0x808009E8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808009EC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808009F0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808009F4: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x808009F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_808009FC:
    // 0x808009FC: jal         0x80087A28
    // 0x80800A00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800A00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800A04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800A08: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800A0C: jal         0x800ADE50
    // 0x80800A10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800ADE50(rdram, ctx);
        goto after_5;
    // 0x80800A10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80800A14: jal         0x80018EFC
    // 0x80800A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mlMtxSet(rdram, ctx);
        goto after_6;
    // 0x80800A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800A1C: lwc1        $f12, 0x44($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X44);
    // 0x80800A20: lwc1        $f14, 0x48($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X48);
    // 0x80800A24: jal         0x80019110
    // 0x80800A28: lw          $a2, 0x4C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4C);
    mlMtxRotatePYR(rdram, ctx);
        goto after_7;
    // 0x80800A28: lw          $a2, 0x4C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4C);
    after_7:
    // 0x80800A2C: jal         0x80018AD0
    // 0x80800A30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mlMtxGet(rdram, ctx);
        goto after_8;
    // 0x80800A30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x80800A34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A38: jal         0x800F2C1C
    // 0x80800A3C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    func_800F2C1C(rdram, ctx);
        goto after_9;
    // 0x80800A3C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    after_9:
    // 0x80800A40: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800A44: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800A48: swc1        $f22, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f22.u32l;
    // 0x80800A4C: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80800A50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800A54: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    // 0x80800A58: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80800A5C: swc1        $f6, -0x50($s0)
    MEM_W(-0X50, ctx->r16) = ctx->f6.u32l;
    // 0x80800A60: swc1        $f10, -0x4C($s0)
    MEM_W(-0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x80800A64: lw          $t0, 0x6C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X6C);
    // 0x80800A68: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x80800A6C: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x80800A70: bnel        $at, $zero, L_808009FC
    if (ctx->r1 != 0) {
        // 0x80800A74: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_808009FC;
    }
    goto skip_0;
    // 0x80800A74: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
L_80800A78:
    // 0x80800A78: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800A7C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800A80: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800A84: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800A88: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800A8C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A90: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800A94: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80800A98: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80800A9C: jr          $ra
    // 0x80800AA0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80800AA0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800F84D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F84D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F84D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F84D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F84DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F84E0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F84E4: jal         0x8009659C
    // 0x800F84E8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009659C(rdram, ctx);
        goto after_0;
    // 0x800F84E8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F84EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F84F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F84F4: jr          $ra
    // 0x800F84F8: nop

    return;
    // 0x800F84F8: nop

;}
RECOMP_FUNC void func_800E0AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0AC0: addiu       $t6, $a0, 0x20
    ctx->r14 = ADD32(ctx->r4, 0X20);
    // 0x800E0AC4: jr          $ra
    // 0x800E0AC8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x800E0AC8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void sukickball_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080098C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800990: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800994: jal         0x80100094
    // 0x80800998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080099C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808009A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009A4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x808009A8: lbu         $v0, 0xA($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0XA);
    // 0x808009AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009B0: xori        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 ^ 0X2;
    // 0x808009B4: jr          $ra
    // 0x808009B8: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
    return;
    // 0x808009B8: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_800DFD10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFD10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DFD14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFD18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800DFD1C: jal         0x8001B668
    // 0x800DFD20: addiu       $a1, $zero, 0x1110
    ctx->r5 = ADD32(0, 0X1110);
    func_8001B668(rdram, ctx);
        goto after_0;
    // 0x800DFD20: addiu       $a1, $zero, 0x1110
    ctx->r5 = ADD32(0, 0X1110);
    after_0:
    // 0x800DFD24: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800DFD28: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800DFD2C: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x800DFD30: jal         0x8001B798
    // 0x800DFD34: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x800DFD34: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x800DFD38: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800DFD3C: addiu       $t8, $zero, 0x6D
    ctx->r24 = ADD32(0, 0X6D);
    // 0x800DFD40: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800DFD44: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800DFD48: jal         0x800DFAD0
    // 0x800DFD4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DFAD0(rdram, ctx);
        goto after_2;
    // 0x800DFD4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800DFD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFD54: lh          $v0, 0x1E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1E);
    // 0x800DFD58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DFD5C: jr          $ra
    // 0x800DFD60: nop

    return;
    // 0x800DFD60: nop

;}
RECOMP_FUNC void func_808005CC_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005CC: beq         $a0, $zero, L_808005F4
    if (ctx->r4 == 0) {
        // 0x808005D0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808005F4;
    }
    // 0x808005D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005D4: beq         $a0, $at, L_808005FC
    if (ctx->r4 == ctx->r1) {
        // 0x808005D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808005FC;
    }
    // 0x808005D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005DC: beq         $a0, $at, L_80800604
    if (ctx->r4 == ctx->r1) {
        // 0x808005E0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800604;
    }
    // 0x808005E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005E4: beq         $a0, $at, L_8080060C
    if (ctx->r4 == ctx->r1) {
        // 0x808005E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080060C;
    }
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808005EC: b           L_80800614
    // 0x808005F0: nop

        goto L_80800614;
    // 0x808005F0: nop

L_808005F4:
    // 0x808005F4: jr          $ra
    // 0x808005F8: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    return;
    // 0x808005F8: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_808005FC:
    // 0x808005FC: jr          $ra
    // 0x80800600: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    return;
    // 0x80800600: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_80800604:
    // 0x80800604: jr          $ra
    // 0x80800608: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    return;
    // 0x80800608: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_8080060C:
    // 0x8080060C: jr          $ra
    // 0x80800610: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    return;
    // 0x80800610: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_80800614:
    // 0x80800614: jr          $ra
    // 0x80800618: nop

    return;
    // 0x80800618: nop

;}
RECOMP_FUNC void _vpmodule_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890B8: syscall     761
    recomp_syscall_handler(rdram, ctx, 0x800890B8);
    return;
    // 0x800890BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008F62C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F62C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008F630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008F634: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008F638: jal         0x800F53D0
    // 0x8008F63C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x8008F63C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008F640: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008F644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F648: jal         0x80092D44
    // 0x8008F64C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80092D44(rdram, ctx);
        goto after_1;
    // 0x8008F64C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8008F650: jal         0x8009C984
    // 0x8008F654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_2;
    // 0x8008F654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008F658: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8008F65C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8008F660: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8008F664: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8008F668: jal         0x80108474
    // 0x8008F66C: nop

    func_80108474(rdram, ctx);
        goto after_3;
    // 0x8008F66C: nop

    after_3:
    // 0x8008F670: lbu         $t8, 0x65($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X65);
    // 0x8008F674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008F678: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8008F67C: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x8008F680: jal         0x80084D48
    // 0x8008F684: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
    _bahold_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x8008F684: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
    after_4:
    // 0x8008F688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008F68C: jal         0x8009E674
    // 0x8008F690: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_8009E674(rdram, ctx);
        goto after_5;
    // 0x8008F690: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_5:
    // 0x8008F694: bne         $v0, $zero, L_8008F6A4
    if (ctx->r2 != 0) {
        // 0x8008F698: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8008F6A4;
    }
    // 0x8008F698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008F69C: jal         0x8009E5C8
    // 0x8008F6A0: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x8008F6A0: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_6:
L_8008F6A4:
    // 0x8008F6A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F6A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008F6AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008F6B0: jr          $ra
    // 0x8008F6B4: nop

    return;
    // 0x8008F6B4: nop

;}
RECOMP_FUNC void _bsjig_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083200: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x80083200);
    return;
    // 0x80083204: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80801D7C_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D7C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80801D80: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801D84: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801D88: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801D8C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80801D90: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801D94: jal         0x80100094
    // 0x80801D98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801D98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801D9C: jal         0x800F54E4
    // 0x80801DA0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80801DA0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_1:
    // 0x80801DA4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80801DA8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801DAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801DB0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80801DB4: jal         0x800F4F34
    // 0x80801DB8: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    func_800F4F34(rdram, ctx);
        goto after_2;
    // 0x80801DB8: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_2:
    // 0x80801DBC: lhu         $t6, 0x72($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X72);
    // 0x80801DC0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801DC4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80801DC8: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x80801DCC: beq         $at, $zero, L_80802180
    if (ctx->r1 == 0) {
        // 0x80801DD0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80802180;
    }
    // 0x80801DD0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801DD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X27DC) << 16);
    // 0x80801DD8: addu        $at, $at, $t8
    gpr jr_addend_80801DE0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801DDC: lw          $t8, 0x27DC($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27DC));
    // 0x80801DE0: jr          $t8
    // 0x80801DE4: nop

    switch (jr_addend_80801DE0 >> 2) {
        case 0: goto L_80801DE8; break;
        case 1: goto L_80801EFC; break;
        case 2: goto L_80802180; break;
        case 3: goto L_80801F1C; break;
        case 4: goto L_80802180; break;
        case 5: goto L_80801FAC; break;
        case 6: goto L_80802068; break;
        case 7: goto L_808020E4; break;
        case 8: goto L_80802114; break;
        case 9: goto L_80802180; break;
        default: switch_error(__func__, 0x80801DE0, 0x808027DC);
    }
    // 0x80801DE4: nop

L_80801DE8:
    // 0x80801DE8: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    // 0x80801DEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801DF0: bne         $a0, $zero, L_80801E08
    if (ctx->r4 != 0) {
        // 0x80801DF4: nop
    
            goto L_80801E08;
    }
    // 0x80801DF4: nop

    // 0x80801DF8: jal         0x80101FDC
    // 0x80801DFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80801DFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80801E00: b           L_80802184
    // 0x80801E04: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
        goto L_80802184;
    // 0x80801E04: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
L_80801E08:
    // 0x80801E08: jal         0x80106790
    // 0x80801E0C: nop

    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80801E0C: nop

    after_4:
    // 0x80801E10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801E14: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80801E18: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801E1C: nop

    // 0x80801E20: bc1fl       L_80802184
    if (!c1cs) {
        // 0x80801E24: sb          $zero, 0x14($s2)
        MEM_B(0X14, ctx->r18) = 0;
            goto L_80802184;
    }
    goto skip_0;
    // 0x80801E24: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
    skip_0:
    // 0x80801E28: lbu         $t9, 0x14($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X14);
    // 0x80801E2C: addiu       $a0, $zero, 0x364
    ctx->r4 = ADD32(0, 0X364);
    // 0x80801E30: bnel        $t9, $zero, L_80802184
    if (ctx->r25 != 0) {
        // 0x80801E34: sb          $zero, 0x14($s2)
        MEM_B(0X14, ctx->r18) = 0;
            goto L_80802184;
    }
    goto skip_1;
    // 0x80801E34: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
    skip_1:
    // 0x80801E38: jal         0x8008A298
    // 0x80801E3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _sudialog_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80801E3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80801E40: lbu         $a0, 0x10($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X10);
    // 0x80801E44: lbu         $t0, 0x11($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X11);
    // 0x80801E48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801E4C: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80801E50: beql        $at, $zero, L_80802184
    if (ctx->r1 == 0) {
        // 0x80801E54: sb          $zero, 0x14($s2)
        MEM_B(0X14, ctx->r18) = 0;
            goto L_80802184;
    }
    goto skip_2;
    // 0x80801E54: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
    skip_2:
    // 0x80801E58: blez        $a0, L_80801EB8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80801E5C: sw          $zero, 0x68($sp)
        MEM_W(0X68, ctx->r29) = 0;
            goto L_80801EB8;
    }
    // 0x80801E5C: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80801E60: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80801E64: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80801E68:
    // 0x80801E68: jal         0x80106790
    // 0x80801E6C: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80801E6C: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    after_6:
    // 0x80801E70: addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // 0x80801E74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801E78: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801E7C: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x80801E80: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x80801E84: jal         0x800F00A4
    // 0x80801E88: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800F00A4(rdram, ctx);
        goto after_7;
    // 0x80801E88: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_7:
    // 0x80801E8C: beq         $v0, $zero, L_80801EA0
    if (ctx->r2 == 0) {
        // 0x80801E90: lw          $v1, 0x6C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X6C);
            goto L_80801EA0;
    }
    // 0x80801E90: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80801E94: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801E98: b           L_80801EB8
    // 0x80801E9C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
        goto L_80801EB8;
    // 0x80801E9C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
L_80801EA0:
    // 0x80801EA0: lbu         $t3, 0x10($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X10);
    // 0x80801EA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801EA8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801EAC: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80801EB0: bnel        $at, $zero, L_80801E68
    if (ctx->r1 != 0) {
        // 0x80801EB4: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80801E68;
    }
    goto skip_3;
    // 0x80801EB4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_80801EB8:
    // 0x80801EB8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80801EBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801EC0: bnel        $t4, $zero, L_80802184
    if (ctx->r12 != 0) {
        // 0x80801EC4: sb          $zero, 0x14($s2)
        MEM_B(0X14, ctx->r18) = 0;
            goto L_80802184;
    }
    goto skip_4;
    // 0x80801EC4: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
    skip_4:
    // 0x80801EC8: jal         0x80108B04
    // 0x80801ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_8;
    // 0x80801ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80801ED0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801ED4: jal         0x80101FDC
    // 0x80801ED8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x80801ED8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80801EDC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801EE0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801EE4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80801EE8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801EEC: jal         0x800DC178
    // 0x80801EF0: nop

    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x80801EF0: nop

    after_10:
    // 0x80801EF4: b           L_80802180
    // 0x80801EF8: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
        goto L_80802180;
    // 0x80801EF8: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
L_80801EFC:
    // 0x80801EFC: jal         0x800D9078
    // 0x80801F00: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_11;
    // 0x80801F00: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_11:
    // 0x80801F04: beq         $v0, $zero, L_80802180
    if (ctx->r2 == 0) {
        // 0x80801F08: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80802180;
    }
    // 0x80801F08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801F0C: jal         0x80101FDC
    // 0x80801F10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x80801F10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80801F14: b           L_80802184
    // 0x80801F18: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
        goto L_80802184;
    // 0x80801F18: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
L_80801F1C:
    // 0x80801F1C: jal         0x8010D23C
    // 0x80801F20: nop

    func_8010D23C(rdram, ctx);
        goto after_13;
    // 0x80801F20: nop

    after_13:
    // 0x80801F24: beql        $v0, $zero, L_80802184
    if (ctx->r2 == 0) {
        // 0x80801F28: sb          $zero, 0x14($s2)
        MEM_B(0X14, ctx->r18) = 0;
            goto L_80802184;
    }
    goto skip_5;
    // 0x80801F28: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
    skip_5:
    // 0x80801F2C: jal         0x8010C500
    // 0x80801F30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010C500(rdram, ctx);
        goto after_14;
    // 0x80801F30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80801F34: beql        $v0, $zero, L_80802184
    if (ctx->r2 == 0) {
        // 0x80801F38: sb          $zero, 0x14($s2)
        MEM_B(0X14, ctx->r18) = 0;
            goto L_80802184;
    }
    goto skip_6;
    // 0x80801F38: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
    skip_6:
    // 0x80801F3C: jal         0x8008FDC4
    // 0x80801F40: nop

    func_8008FDC4(rdram, ctx);
        goto after_15;
    // 0x80801F40: nop

    after_15:
    // 0x80801F44: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x80801F48: bgez        $t5, L_80802180
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80801F4C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80802180;
    }
    // 0x80801F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801F50: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80801F54: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80801F58: jal         0x80085708
    // 0x80801F5C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    _capod_entrypoint_13(rdram, ctx);
        goto after_16;
    // 0x80801F5C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_16:
    // 0x80801F60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801F64: jal         0x80101FDC
    // 0x80801F68: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x80801F68: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_17:
    // 0x80801F6C: lbu         $t6, 0x65($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X65);
    // 0x80801F70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801F74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801F78: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80801F7C: sb          $t7, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r15;
    // 0x80801F80: jal         0x80086B58
    // 0x80801F84: swc1        $f8, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f8.u32l;
    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x80801F84: swc1        $f8, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f8.u32l;
    after_18:
    // 0x80801F88: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80801F8C: addiu       $t8, $zero, 0xA3
    ctx->r24 = ADD32(0, 0XA3);
    // 0x80801F90: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801F94: addiu       $a1, $zero, 0x133B
    ctx->r5 = ADD32(0, 0X133B);
    // 0x80801F98: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80801F9C: jal         0x8008A208
    // 0x80801FA0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_19;
    // 0x80801FA0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_19:
    // 0x80801FA4: b           L_80802184
    // 0x80801FA8: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
        goto L_80802184;
    // 0x80801FA8: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
L_80801FAC:
    // 0x80801FAC: jal         0x800D9078
    // 0x80801FB0: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_20;
    // 0x80801FB0: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_20:
    // 0x80801FB4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80801FB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801FBC: lwc1        $f12, 0x58($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80801FC0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801FC4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801FC8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801FCC: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    // 0x80801FD0: jal         0x800F12D4
    // 0x80801FD4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F12D4(rdram, ctx);
        goto after_21;
    // 0x80801FD4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x80801FD8: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80801FDC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80801FE0: jal         0x800EE7F8
    // 0x80801FE4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_22;
    // 0x80801FE4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_22:
    // 0x80801FE8: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80801FEC: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801FF0: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80801FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801FF8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80801FFC: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80802000: jal         0x800D1254
    // 0x80802004: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    func_800D1254(rdram, ctx);
        goto after_23;
    // 0x80802004: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_23:
    // 0x80802008: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x8080200C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X2804) << 16);
    // 0x80802010: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x80802014: bltz        $t1, L_80802050
    if (SIGNED(ctx->r9) < 0) {
        // 0x80802018: nop
    
            goto L_80802050;
    }
    // 0x80802018: nop

    // 0x8080201C: lwc1        $f6, 0x58($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80802020: lwc1        $f8, 0x2804($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X2804));
    // 0x80802024: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802028: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080202C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80802030: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1140, 0X2AEC) << 16);
    // 0x80802034: bc1f        L_80802050
    if (!c1cs) {
        // 0x80802038: nop
    
            goto L_80802050;
    }
    // 0x80802038: nop

    // 0x8080203C: jal         0x80089D18
    // 0x80802040: addiu       $a2, $a2, 0x2AEC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1140, 0X2AEC));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x80802040: addiu       $a2, $a2, 0x2AEC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1140, 0X2AEC));
    after_24:
    // 0x80802044: lbu         $t3, 0x65($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X65);
    // 0x80802048: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x8080204C: sb          $t4, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r12;
L_80802050:
    // 0x80802050: beq         $s0, $zero, L_80802180
    if (ctx->r16 == 0) {
        // 0x80802054: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80802180;
    }
    // 0x80802054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802058: jal         0x80101FDC
    // 0x8080205C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80101FDC(rdram, ctx);
        goto after_25;
    // 0x8080205C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_25:
    // 0x80802060: b           L_80802184
    // 0x80802064: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
        goto L_80802184;
    // 0x80802064: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
L_80802068:
    // 0x80802068: jal         0x800D9078
    // 0x8080206C: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_26;
    // 0x8080206C: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_26:
    // 0x80802070: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80802074: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802078: lwc1        $f12, 0x58($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X58);
    // 0x8080207C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80802080: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802084: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802088: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    // 0x8080208C: jal         0x800F12D4
    // 0x80802090: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F12D4(rdram, ctx);
        goto after_27;
    // 0x80802090: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_27:
    // 0x80802094: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80802098: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8080209C: jal         0x800EE7F8
    // 0x808020A0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_28;
    // 0x808020A0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_28:
    // 0x808020A4: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808020A8: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808020AC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x808020B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808020B4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808020B8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x808020BC: jal         0x800D1254
    // 0x808020C0: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    func_800D1254(rdram, ctx);
        goto after_29;
    // 0x808020C0: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    after_29:
    // 0x808020C4: beq         $s0, $zero, L_80802180
    if (ctx->r16 == 0) {
        // 0x808020C8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80802180;
    }
    // 0x808020C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808020CC: jal         0x80101FDC
    // 0x808020D0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80101FDC(rdram, ctx);
        goto after_30;
    // 0x808020D0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_30:
    // 0x808020D4: jal         0x800DA544
    // 0x808020D8: addiu       $a0, $zero, 0x1BB
    ctx->r4 = ADD32(0, 0X1BB);
    func_800DA544(rdram, ctx);
        goto after_31;
    // 0x808020D8: addiu       $a0, $zero, 0x1BB
    ctx->r4 = ADD32(0, 0X1BB);
    after_31:
    // 0x808020DC: b           L_80802184
    // 0x808020E0: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
        goto L_80802184;
    // 0x808020E0: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
L_808020E4:
    // 0x808020E4: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    // 0x808020E8: lbu         $a1, 0x13($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X13);
    // 0x808020EC: jal         0x800D2498
    // 0x808020F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_32;
    // 0x808020F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_32:
    // 0x808020F4: jal         0x800D9078
    // 0x808020F8: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_33;
    // 0x808020F8: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_33:
    // 0x808020FC: beq         $v0, $zero, L_80802180
    if (ctx->r2 == 0) {
        // 0x80802100: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80802180;
    }
    // 0x80802100: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802104: jal         0x80101FDC
    // 0x80802108: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80101FDC(rdram, ctx);
        goto after_34;
    // 0x80802108: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_34:
    // 0x8080210C: b           L_80802184
    // 0x80802110: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
        goto L_80802184;
    // 0x80802110: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
L_80802114:
    // 0x80802114: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    // 0x80802118: lbu         $a1, 0x13($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X13);
    // 0x8080211C: jal         0x800D2498
    // 0x80802120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_35;
    // 0x80802120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_35:
    // 0x80802124: lbu         $a0, 0x11($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X11);
    // 0x80802128: jal         0x800F1418
    // 0x8080212C: lbu         $a1, 0x13($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X13);
    func_800F1418(rdram, ctx);
        goto after_36;
    // 0x8080212C: lbu         $a1, 0x13($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X13);
    after_36:
    // 0x80802130: lbu         $t5, 0x10($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X10);
    // 0x80802134: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80802138: beql        $at, $zero, L_80802184
    if (ctx->r1 == 0) {
        // 0x8080213C: sb          $zero, 0x14($s2)
        MEM_B(0X14, ctx->r18) = 0;
            goto L_80802184;
    }
    goto skip_7;
    // 0x8080213C: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
    skip_7:
    // 0x80802140: lbu         $t6, 0x14($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X14);
    // 0x80802144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802148: bnel        $t6, $zero, L_80802184
    if (ctx->r14 != 0) {
        // 0x8080214C: sb          $zero, 0x14($s2)
        MEM_B(0X14, ctx->r18) = 0;
            goto L_80802184;
    }
    goto skip_8;
    // 0x8080214C: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
    skip_8:
    // 0x80802150: jal         0x80108B04
    // 0x80802154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_37;
    // 0x80802154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x80802158: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080215C: jal         0x80101FDC
    // 0x80802160: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80101FDC(rdram, ctx);
        goto after_38;
    // 0x80802160: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_38:
    // 0x80802164: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80802168: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080216C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80802170: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802174: jal         0x800DC178
    // 0x80802178: nop

    func_800DC178(rdram, ctx);
        goto after_39;
    // 0x80802178: nop

    after_39:
    // 0x8080217C: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
L_80802180:
    // 0x80802180: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
L_80802184:
    // 0x80802184: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80802188: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080218C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80802190: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802194: jr          $ra
    // 0x80802198: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80802198: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D20: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D20);
    return;
    // 0x80087D24: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void bssplitup_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(364, 0X740) << 16);
    // 0x808006E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006E4: jr          $ra
    // 0x808006E8: lw          $v0, 0x740($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X740));
    return;
    // 0x808006E8: lw          $v0, 0x740($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X740));
    // 0x808006EC: nop

;}
RECOMP_FUNC void func_80800998_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800998: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080099C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009A8: jal         0x800D8FF8
    // 0x808009AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808009AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808009B0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B8: jal         0x8009D3A8
    // 0x808009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x808009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808009C0: jal         0x8008E35C
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_2;
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808009C8: beq         $v0, $zero, L_808009E4
    if (ctx->r2 == 0) {
        // 0x808009CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009E4;
    }
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: jal         0x8009BCB4
    // 0x808009D4: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_3;
    // 0x808009D4: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    after_3:
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009DC: jal         0x8009BCC4
    // 0x808009E0: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_4;
    // 0x808009E0: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    after_4:
L_808009E4:
    // 0x808009E4: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808009E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F0: beq         $v0, $at, L_80800A0C
    if (ctx->r2 == ctx->r1) {
        // 0x808009F4: lui         $a1, 0x3E22
        ctx->r5 = S32(0X3E22 << 16);
            goto L_80800A0C;
    }
    // 0x808009F4: lui         $a1, 0x3E22
    ctx->r5 = S32(0X3E22 << 16);
    // 0x808009F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808009FC: beq         $v0, $at, L_80800A6C
    if (ctx->r2 == ctx->r1) {
        // 0x80800A00: nop
    
            goto L_80800A6C;
    }
    // 0x80800A00: nop

    // 0x80800A04: b           L_80800B1C
    // 0x80800A08: nop

        goto L_80800B1C;
    // 0x80800A08: nop

L_80800A0C:
    // 0x80800A0C: jal         0x8008CB10
    // 0x80800A10: ori         $a1, $a1, 0x8241
    ctx->r5 = ctx->r5 | 0X8241;
    baanim_isAt(rdram, ctx);
        goto after_5;
    // 0x80800A10: ori         $a1, $a1, 0x8241
    ctx->r5 = ctx->r5 | 0X8241;
    after_5:
    // 0x80800A14: beql        $v0, $zero, L_80800A28
    if (ctx->r2 == 0) {
        // 0x80800A18: lui         $a1, 0x3E8D
        ctx->r5 = S32(0X3E8D << 16);
            goto L_80800A28;
    }
    goto skip_0;
    // 0x80800A18: lui         $a1, 0x3E8D
    ctx->r5 = S32(0X3E8D << 16);
    skip_0:
    // 0x80800A1C: jal         0x80800068
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800068_bstnt(rdram, ctx);
        goto after_6;
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A24: lui         $a1, 0x3E8D
    ctx->r5 = S32(0X3E8D << 16);
L_80800A28:
    // 0x80800A28: ori         $a1, $a1, 0xD2F2
    ctx->r5 = ctx->r5 | 0XD2F2;
    // 0x80800A2C: jal         0x8008CB10
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_7;
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800A34: beql        $v0, $zero, L_80800A48
    if (ctx->r2 == 0) {
        // 0x80800A38: lui         $a1, 0x3EDE
        ctx->r5 = S32(0X3EDE << 16);
            goto L_80800A48;
    }
    goto skip_1;
    // 0x80800A38: lui         $a1, 0x3EDE
    ctx->r5 = S32(0X3EDE << 16);
    skip_1:
    // 0x80800A3C: jal         0x80800000
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bstnt(rdram, ctx);
        goto after_8;
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800A44: lui         $a1, 0x3EDE
    ctx->r5 = S32(0X3EDE << 16);
L_80800A48:
    // 0x80800A48: ori         $a1, $a1, 0x353F
    ctx->r5 = ctx->r5 | 0X353F;
    // 0x80800A4C: jal         0x8008CB10
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_9;
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800A54: beq         $v0, $zero, L_80800B1C
    if (ctx->r2 == 0) {
        // 0x80800A58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B1C;
    }
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A5C: jal         0x808007EC
    // 0x80800A60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808007EC_bstnt(rdram, ctx);
        goto after_10;
    // 0x80800A60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800A64: b           L_80800B1C
    // 0x80800A68: nop

        goto L_80800B1C;
    // 0x80800A68: nop

L_80800A6C:
    // 0x80800A6C: jal         0x8080009C
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_bstnt(rdram, ctx);
        goto after_11;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800A74: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800A78: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800A7C: lwc1        $f10, 0x170($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X170);
    // 0x80800A80: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800A84: jal         0x800136E4
    // 0x80800A88: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_12;
    // 0x80800A88: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_12:
    // 0x80800A8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800A90: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x80800A94: jal         0x8009328C
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009328C(rdram, ctx);
        goto after_13;
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800A9C: jal         0x8008CAC8
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_14;
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800AA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(404, 0X2204) << 16);
    // 0x80800AA8: lwc1        $f16, 0x2204($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(404, 0X2204));
    // 0x80800AAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(404, 0X2208) << 16);
    // 0x80800AB0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800AB4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800AB8: nop

    // 0x80800ABC: bc1fl       L_80800AE4
    if (!c1cs) {
        // 0x80800AC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AE4;
    }
    goto skip_2;
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800AC4: lwc1        $f18, 0x2208($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(404, 0X2208));
    // 0x80800AC8: lwc1        $f10, 0x16C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800ACC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800AD0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800AD4: jal         0x800F0E00
    // 0x80800AD8: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    func_800F0E00(rdram, ctx);
        goto after_15;
    // 0x80800AD8: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    after_15:
    // 0x80800ADC: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AE4:
    // 0x80800AE4: jal         0x8008CB10
    // 0x80800AE8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_16;
    // 0x80800AE8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_16:
    // 0x80800AEC: beql        $v0, $zero, L_80800B00
    if (ctx->r2 == 0) {
        // 0x80800AF0: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80800B00;
    }
    goto skip_3;
    // 0x80800AF0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_3:
    // 0x80800AF4: jal         0x80800554
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800554_bstnt(rdram, ctx);
        goto after_17;
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800AFC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80800B00:
    // 0x80800B00: lwc1        $f16, 0x16C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800B04: addiu       $t6, $zero, 0x10C
    ctx->r14 = ADD32(0, 0X10C);
    // 0x80800B08: c.eq.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl == ctx->f16.fl;
    // 0x80800B0C: nop

    // 0x80800B10: bc1f        L_80800B1C
    if (!c1cs) {
        // 0x80800B14: nop
    
            goto L_80800B1C;
    }
    // 0x80800B14: nop

    // 0x80800B18: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800B1C:
    // 0x80800B1C: jal         0x80800720
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800720_bstnt(rdram, ctx);
        goto after_18;
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800B24: jal         0x80800F94
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstnt_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B30: jal         0x8009E5C8
    // 0x80800B34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_20;
    // 0x80800B34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_20:
    // 0x80800B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B44: jr          $ra
    // 0x80800B48: nop

    return;
    // 0x80800B48: nop

;}
RECOMP_FUNC void func_80800F40_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800F4C: jal         0x80100094
    // 0x80800F50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800F54: bne         $v0, $zero, L_80800F9C
    if (ctx->r2 != 0) {
        // 0x80800F58: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800F9C;
    }
    // 0x80800F58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F60: jal         0x800897C0
    // 0x80800F64: addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800F64: addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    after_1:
    // 0x80800F68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F6C: jal         0x80100094
    // 0x80800F70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800F70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800F74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F78: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800F7C: jal         0x800897E8
    // 0x80800F80: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800F80: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_3:
    // 0x80800F84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F88: jal         0x80100094
    // 0x80800F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800F90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F94: jal         0x80089810
    // 0x80800F98: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x80800F98: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_5:
L_80800F9C:
    // 0x80800F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FA4: jr          $ra
    // 0x80800FA8: nop

    return;
    // 0x80800FA8: nop

;}
RECOMP_FUNC void func_8001ED68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ED68: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001ED6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ED70: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001ED74: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001ED78: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_8001ED7C:
    // 0x8001ED7C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001ED80: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8001ED84: lh          $t8, 0x28($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X28);
    // 0x8001ED88: bne         $t8, $at, L_8001EDC0
    if (ctx->r24 != ctx->r1) {
        // 0x8001ED8C: nop
    
            goto L_8001EDC0;
    }
    // 0x8001ED8C: nop

    // 0x8001ED90: b           L_8001ED98
    // 0x8001ED94: nop

        goto L_8001ED98;
    // 0x8001ED94: nop

L_8001ED98:
    // 0x8001ED98: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8001ED9C: sh          $t9, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r25;
    // 0x8001EDA0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EDA4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8001EDA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001EDAC: addiu       $a0, $t0, 0x14
    ctx->r4 = ADD32(ctx->r8, 0X14);
    // 0x8001EDB0: jal         0x80026500
    // 0x8001EDB4: lw          $a2, 0x48($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x8001EDB4: lw          $a2, 0x48($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X48);
    after_0:
    // 0x8001EDB8: b           L_8001EDD4
    // 0x8001EDBC: nop

        goto L_8001EDD4;
    // 0x8001EDBC: nop

L_8001EDC0:
    // 0x8001EDC0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EDC4: jal         0x8001EE34
    // 0x8001EDC8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001EE34(rdram, ctx);
        goto after_1;
    // 0x8001EDC8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
    // 0x8001EDCC: b           L_8001EDD4
    // 0x8001EDD0: nop

        goto L_8001EDD4;
    // 0x8001EDD0: nop

L_8001EDD4:
    // 0x8001EDD4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EDD8: addiu       $a0, $t1, 0x14
    ctx->r4 = ADD32(ctx->r9, 0X14);
    // 0x8001EDDC: jal         0x8002645C
    // 0x8001EDE0: addiu       $a1, $t1, 0x28
    ctx->r5 = ADD32(ctx->r9, 0X28);
    func_8002645C(rdram, ctx);
        goto after_2;
    // 0x8001EDE0: addiu       $a1, $t1, 0x28
    ctx->r5 = ADD32(ctx->r9, 0X28);
    after_2:
    // 0x8001EDE4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EDE8: sw          $v0, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->r2;
    // 0x8001EDEC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EDF0: lw          $t4, 0x4C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4C);
    // 0x8001EDF4: beq         $t4, $zero, L_8001ED7C
    if (ctx->r12 == 0) {
        // 0x8001EDF8: nop
    
            goto L_8001ED7C;
    }
    // 0x8001EDF8: nop

    // 0x8001EDFC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EE00: lw          $t6, 0x50($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X50);
    // 0x8001EE04: lw          $t7, 0x4C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4C);
    // 0x8001EE08: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001EE0C: sw          $t8, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r24;
    // 0x8001EE10: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EE14: b           L_8001EE24
    // 0x8001EE18: lw          $v0, 0x4C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X4C);
        goto L_8001EE24;
    // 0x8001EE18: lw          $v0, 0x4C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X4C);
    // 0x8001EE1C: b           L_8001EE24
    // 0x8001EE20: nop

        goto L_8001EE24;
    // 0x8001EE20: nop

L_8001EE24:
    // 0x8001EE24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EE28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001EE2C: jr          $ra
    // 0x8001EE30: nop

    return;
    // 0x8001EE30: nop

;}
RECOMP_FUNC void bsrebound_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800110: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(340, 0X120) << 16);
    // 0x80800114: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800118: jr          $ra
    // 0x8080011C: lw          $v0, 0x120($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(340, 0X120));
    return;
    // 0x8080011C: lw          $v0, 0x120($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(340, 0X120));
;}
RECOMP_FUNC void func_808005B0_glrtc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x808005B4: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x808005B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005BC: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x808005C0: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x808005C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808005C8: andi        $s2, $a1, 0xFF
    ctx->r18 = ctx->r5 & 0XFF;
    // 0x808005CC: beq         $s0, $zero, L_808005FC
    if (ctx->r16 == 0) {
        // 0x808005D0: sw          $a1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r5;
            goto L_808005FC;
    }
    // 0x808005D0: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x808005D4: lbu         $v1, 0x3($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X3);
    // 0x808005D8: lbu         $a0, 0x0($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X0);
    // 0x808005DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005E0: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x808005E4: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x808005E8: mflo        $t7
    ctx->r15 = lo;
    // 0x808005EC: subu        $t9, $v1, $t7
    ctx->r25 = SUB32(ctx->r3, ctx->r15);
    // 0x808005F0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x808005F4: sb          $t8, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r24;
    // 0x808005F8: sb          $t9, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r25;
L_808005FC:
    // 0x808005FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800600: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80800604: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80800608:
    // 0x80800608: andi        $t0, $s0, 0x3
    ctx->r8 = ctx->r16 & 0X3;
    // 0x8080060C: addu        $t1, $t0, $a3
    ctx->r9 = ADD32(ctx->r8, ctx->r7);
    // 0x80800610: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80800614: srl         $t4, $s0, 2
    ctx->r12 = S32(U32(ctx->r16) >> 2);
    // 0x80800618: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x8080061C: addu        $t3, $s1, $s2
    ctx->r11 = ADD32(ctx->r17, ctx->r18);
    // 0x80800620: addu        $t6, $t5, $a3
    ctx->r14 = ADD32(ctx->r13, ctx->r7);
    // 0x80800624: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x80800628: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8080062C: srl         $t9, $t4, 2
    ctx->r25 = S32(U32(ctx->r12) >> 2);
    // 0x80800630: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x80800634: addu        $t8, $s1, $s2
    ctx->r24 = ADD32(ctx->r17, ctx->r18);
    // 0x80800638: addu        $t1, $t0, $a3
    ctx->r9 = ADD32(ctx->r8, ctx->r7);
    // 0x8080063C: sb          $t7, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r15;
    // 0x80800640: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80800644: srl         $t4, $t9, 2
    ctx->r12 = S32(U32(ctx->r25) >> 2);
    // 0x80800648: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x8080064C: addu        $t6, $t5, $a3
    ctx->r14 = ADD32(ctx->r13, ctx->r7);
    // 0x80800650: sb          $t2, 0x8($t3)
    MEM_B(0X8, ctx->r11) = ctx->r10;
    // 0x80800654: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80800658: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080065C: srl         $s0, $t4, 2
    ctx->r16 = S32(U32(ctx->r12) >> 2);
    // 0x80800660: addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
    // 0x80800664: bne         $v0, $a0, L_80800608
    if (ctx->r2 != ctx->r4) {
        // 0x80800668: sb          $t7, 0xC($t8)
        MEM_B(0XC, ctx->r24) = ctx->r15;
            goto L_80800608;
    }
    // 0x80800668: sb          $t7, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r15;
    // 0x8080066C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80800670: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80800674: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80800678: jr          $ra
    // 0x8080067C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8080067C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8080324C_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080324C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803254: jal         0x80102424
    // 0x80803258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80803258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080325C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803260: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803264: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80803268: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080326C: beq         $t6, $at, L_80803284
    if (ctx->r14 == ctx->r1) {
        // 0x80803270: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80803284;
    }
    // 0x80803270: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80803274: beql        $t6, $at, L_808032B4
    if (ctx->r14 == ctx->r1) {
        // 0x80803278: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_808032B4;
    }
    goto skip_0;
    // 0x80803278: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x8080327C: b           L_808032C0
    // 0x80803280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808032C0;
    // 0x80803280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803284:
    // 0x80803284: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80803288: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8080328C: bgezl       $t9, L_808032C0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80803290: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808032C0;
    }
    goto skip_1;
    // 0x80803290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80803294: lbu         $t0, 0x72($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X72);
    // 0x80803298: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080329C: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x808032A0: ori         $t2, $t1, 0x28
    ctx->r10 = ctx->r9 | 0X28;
    // 0x808032A4: sb          $t2, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r10;
    // 0x808032A8: b           L_808032BC
    // 0x808032AC: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
        goto L_808032BC;
    // 0x808032AC: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x808032B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_808032B4:
    // 0x808032B4: nop

    // 0x808032B8: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
L_808032BC:
    // 0x808032BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808032C0:
    // 0x808032C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808032C4: jr          $ra
    // 0x808032C8: nop

    return;
    // 0x808032C8: nop

;}
RECOMP_FUNC void func_80800128_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080012C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800138: jal         0x80100094
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800140: jal         0x800F54E4
    // 0x80800144: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800144: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800148: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080014C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800150: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800154: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80800158: jal         0x800F4F34
    // 0x8080015C: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    func_800F4F34(rdram, ctx);
        goto after_2;
    // 0x8080015C: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    after_2:
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800164: jal         0x80100094
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080016C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800170: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800174: jal         0x800897D8
    // 0x80800178: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800178: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8080017C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800180: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800184: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800188: sltiu       $at, $t8, 0xC
    ctx->r1 = ctx->r24 < 0XC ? 1 : 0;
    // 0x8080018C: beq         $at, $zero, L_8080038C
    if (ctx->r1 == 0) {
        // 0x80800190: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8080038C;
    }
    // 0x80800190: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800194: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1096, 0X1770) << 16);
    // 0x80800198: addu        $at, $at, $t8
    gpr jr_addend_808001A0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080019C: lw          $t8, 0x1770($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1096, 0X1770));
    // 0x808001A0: jr          $t8
    // 0x808001A4: nop

    switch (jr_addend_808001A0 >> 2) {
        case 0: goto L_808001A8; break;
        case 1: goto L_8080038C; break;
        case 2: goto L_8080038C; break;
        case 3: goto L_8080038C; break;
        case 4: goto L_80800208; break;
        case 5: goto L_80800208; break;
        case 6: goto L_80800244; break;
        case 7: goto L_8080038C; break;
        case 8: goto L_808002D0; break;
        case 9: goto L_8080031C; break;
        case 10: goto L_80800348; break;
        case 11: goto L_80800368; break;
        default: switch_error(__func__, 0x808001A0, 0x80801770);
    }
    // 0x808001A4: nop

L_808001A8:
    // 0x808001A8: jal         0x800DA298
    // 0x808001AC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808001AC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_5:
    // 0x808001B0: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E0;
    }
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: jal         0x800F54E4
    // 0x808001BC: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808001BC: nop

    after_6:
    // 0x808001C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001C4: jal         0x800F7B9C
    // 0x808001C8: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    func_800F7B9C(rdram, ctx);
        goto after_7;
    // 0x808001C8: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    after_7:
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80800AB8
    // 0x808001D4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_8;
    // 0x808001D4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x808001D8: b           L_8080038C
    // 0x808001DC: nop

        goto L_8080038C;
    // 0x808001DC: nop

L_808001E0:
    // 0x808001E0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1096, 0X1B7C) << 16);
    // 0x808001E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1810) << 16);
    // 0x808001E8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808001EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808001F0: addiu       $a2, $a2, 0x1810
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1810));
    // 0x808001F4: addiu       $a1, $a1, 0x1B7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1096, 0X1B7C));
    // 0x808001F8: jal         0x8080134C
    // 0x808001FC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_8080134C_chnicecavemen(rdram, ctx);
        goto after_9;
    // 0x808001FC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_9:
    // 0x80800200: b           L_8080038C
    // 0x80800204: nop

        goto L_8080038C;
    // 0x80800204: nop

L_80800208:
    // 0x80800208: jal         0x80801178
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801178_chnicecavemen(rdram, ctx);
        goto after_10;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800210: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800214: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800218: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080021C: lwc1        $f6, 0x10($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800228: nop

    // 0x8080022C: bc1f        L_8080038C
    if (!c1cs) {
        // 0x80800230: nop
    
            goto L_8080038C;
    }
    // 0x80800230: nop

    // 0x80800234: jal         0x80800AB8
    // 0x80800238: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_11;
    // 0x80800238: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_11:
    // 0x8080023C: b           L_8080038C
    // 0x80800240: nop

        goto L_8080038C;
    // 0x80800240: nop

L_80800244:
    // 0x80800244: jal         0x80801178
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801178_chnicecavemen(rdram, ctx);
        goto after_12;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080024C: jal         0x80101DDC
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_13;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800254: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800258: lw          $t1, 0x34($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X34);
            goto L_8080038C;
    }
    // 0x80800258: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8080025C: lw          $v0, 0x824($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X824);
    // 0x80800260: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800264: nop
    
            goto L_8080038C;
    }
    // 0x80800264: nop

    // 0x80800268: beql        $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x8080026C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80800290;
    }
    goto skip_0;
    // 0x8080026C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80800270: jal         0x800F54E4
    // 0x80800274: nop

    func_800F54E4(rdram, ctx);
        goto after_14;
    // 0x80800274: nop

    after_14:
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080027C: jal         0x800F82D4
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_15;
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80800284: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80800288: sw          $zero, 0x824($t2)
    MEM_W(0X824, ctx->r10) = 0;
    // 0x8080028C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800290:
    // 0x80800290: addiu       $t3, $zero, 0xA2
    ctx->r11 = ADD32(0, 0XA2);
    // 0x80800294: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800298: addiu       $a1, $zero, 0x17D7
    ctx->r5 = ADD32(0, 0X17D7);
    // 0x8080029C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808002A0: jal         0x8008A208
    // 0x808002A4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x808002A4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x808002A8: jal         0x800DA298
    // 0x808002AC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x808002AC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_17:
    // 0x808002B0: beq         $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x808002B4: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_808002C0;
    }
    // 0x808002B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002B8: b           L_808002C0
    // 0x808002BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_808002C0;
    // 0x808002BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_808002C0:
    // 0x808002C0: jal         0x80800AB8
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_18;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808002C8: b           L_8080038C
    // 0x808002CC: nop

        goto L_8080038C;
    // 0x808002CC: nop

L_808002D0:
    // 0x808002D0: jal         0x800DA298
    // 0x808002D4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA298(rdram, ctx);
        goto after_19;
    // 0x808002D4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_19:
    // 0x808002D8: beq         $v0, $zero, L_808002F4
    if (ctx->r2 == 0) {
        // 0x808002DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F4;
    }
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: jal         0x80800AB8
    // 0x808002E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_20;
    // 0x808002E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_20:
    // 0x808002EC: b           L_8080038C
    // 0x808002F0: nop

        goto L_8080038C;
    // 0x808002F0: nop

L_808002F4:
    // 0x808002F4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1096, 0X1B7C) << 16);
    // 0x808002F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1848) << 16);
    // 0x808002FC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80800300: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800304: addiu       $a2, $a2, 0x1848
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1848));
    // 0x80800308: addiu       $a1, $a1, 0x1B7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1096, 0X1B7C));
    // 0x8080030C: jal         0x8080134C
    // 0x80800310: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_8080134C_chnicecavemen(rdram, ctx);
        goto after_21;
    // 0x80800310: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_21:
    // 0x80800314: b           L_8080038C
    // 0x80800318: nop

        goto L_8080038C;
    // 0x80800318: nop

L_8080031C:
    // 0x8080031C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1096, 0X1B7C) << 16);
    // 0x80800320: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1880) << 16);
    // 0x80800324: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80800328: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080032C: addiu       $a2, $a2, 0x1880
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1880));
    // 0x80800330: addiu       $a1, $a1, 0x1B7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1096, 0X1B7C));
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x8080134C
    // 0x8080033C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_8080134C_chnicecavemen(rdram, ctx);
        goto after_22;
    // 0x8080033C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_22:
    // 0x80800340: b           L_8080038C
    // 0x80800344: nop

        goto L_8080038C;
    // 0x80800344: nop

L_80800348:
    // 0x80800348: jal         0x80101DDC
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_23;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800350: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080038C;
    }
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x80800AB8
    // 0x8080035C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_24;
    // 0x8080035C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_24:
    // 0x80800360: b           L_8080038C
    // 0x80800364: nop

        goto L_8080038C;
    // 0x80800364: nop

L_80800368:
    // 0x80800368: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1096, 0X1B7C) << 16);
    // 0x8080036C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X18B8) << 16);
    // 0x80800370: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80800374: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800378: addiu       $a2, $a2, 0x18B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X18B8));
    // 0x8080037C: addiu       $a1, $a1, 0x1B7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1096, 0X1B7C));
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: jal         0x8080134C
    // 0x80800388: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8080134C_chnicecavemen(rdram, ctx);
        goto after_25;
    // 0x80800388: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_25:
L_8080038C:
    // 0x8080038C: jal         0x80800CC8
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC8_chnicecavemen(rdram, ctx);
        goto after_26;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800394: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x8008A068
    // 0x808003A0: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    _subaddiepalette_entrypoint_1(rdram, ctx);
        goto after_27;
    // 0x808003A0: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_27:
    // 0x808003A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003B0: jr          $ra
    // 0x808003B4: nop

    return;
    // 0x808003B4: nop

;}
RECOMP_FUNC void func_80800210_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800218: jal         0x8008F8B0
    // 0x8080021C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008F8B0(rdram, ctx);
        goto after_0;
    // 0x8080021C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800220: jal         0x8008F8D8
    // 0x80800224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_1;
    // 0x80800224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800228: jal         0x8008F938
    // 0x8080022C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_2;
    // 0x8080022C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800230: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800234: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800238: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x8080023C: jal         0x8008F904
    // 0x80800240: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8008F904(rdram, ctx);
        goto after_3;
    // 0x80800240: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x80800244: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1584, 0X1A0C) << 16);
    // 0x80800248: addiu       $a0, $a0, 0x1A0C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1584, 0X1A0C));
    // 0x8080024C: jal         0x8008F990
    // 0x80800250: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    func_8008F990(rdram, ctx);
        goto after_4;
    // 0x80800250: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_4:
    // 0x80800254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void func_80018090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018090: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x80018094: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80018098: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001809C: addiu       $t7, $t7, -0x4D30
    ctx->r15 = ADD32(ctx->r15, -0X4D30);
    // 0x800180A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800180A4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800180A8: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x800180AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800180B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800180B4: bne         $t8, $zero, L_800180F8
    if (ctx->r24 != 0) {
        // 0x800180B8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800180F8;
    }
    // 0x800180B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800180BC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800180C0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x800180C4: jal         0x80016934
    // 0x800180C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80016934(rdram, ctx);
        goto after_0;
    // 0x800180C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800180CC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800180D0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800180D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800180D8: lw          $a0, -0x50F4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X50F4);
    // 0x800180DC: jal         0x800308B4
    // 0x800180E0: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x800180E0: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    after_1:
    // 0x800180E4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800180E8: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800180EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800180F0: jal         0x80016934
    // 0x800180F4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    func_80016934(rdram, ctx);
        goto after_2;
    // 0x800180F4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    after_2:
L_800180F8:
    // 0x800180F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800180FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80018100: jr          $ra
    // 0x80018104: nop

    return;
    // 0x80018104: nop

;}
RECOMP_FUNC void chdippy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1284, 0X15C8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x15C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1284, 0X15C8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x15C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1284, 0X15C8));
;}
RECOMP_FUNC void glglobalsettings_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x808003C8
    // 0x8080000C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    glglobalsettings_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080000C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800014: jal         0x80800458
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    glglobalsettings_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080001C: jal         0x808004F0
    // 0x80800020: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    glglobalsettings_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800020: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void func_80800320_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800324: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800328: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080032C: jal         0x800EA090
    // 0x80800330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA090(rdram, ctx);
        goto after_0;
    // 0x80800330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800334: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800338: jal         0x800DA298
    // 0x8080033C: addiu       $a0, $zero, 0x532
    ctx->r4 = ADD32(0, 0X532);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080033C: addiu       $a0, $zero, 0x532
    ctx->r4 = ADD32(0, 0X532);
    after_1:
    // 0x80800340: beq         $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x80800344: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_8080036C;
    }
    // 0x80800344: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800348: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080034C: beql        $t6, $at, L_80800364
    if (ctx->r14 == ctx->r1) {
        // 0x80800350: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800364;
    }
    goto skip_0;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800354: jal         0x8008A720
    // 0x80800358: nop

    _sujiggy_entrypoint_17(rdram, ctx);
        goto after_2;
    // 0x80800358: nop

    after_2:
    // 0x8080035C: beq         $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x80800360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800364:
    // 0x80800364: jal         0x80101FDC
    // 0x80800368: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800368: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
L_8080036C:
    // 0x8080036C: jal         0x80103EF4
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_4;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800374: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800378: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8080037C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800380: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800384: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800390: jal         0x80086898
    // 0x80800394: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800394: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_5:
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x800868A8
    // 0x808003A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x808003A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: jal         0x800868B0
    // 0x808003AC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x808003AC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_7:
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: jal         0x800868B8
    // 0x808003B8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _chdoormake_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x808003B8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_8:
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: jal         0x800868C0
    // 0x808003C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x808003C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003D0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x808003D4: jal         0x800868C8
    // 0x808003D8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x808003D8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_10:
    // 0x808003DC: jal         0x800DA298
    // 0x808003E0: addiu       $a0, $zero, 0x532
    ctx->r4 = ADD32(0, 0X532);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x808003E0: addiu       $a0, $zero, 0x532
    ctx->r4 = ADD32(0, 0X532);
    after_11:
    // 0x808003E4: beql        $v0, $zero, L_80800428
    if (ctx->r2 == 0) {
        // 0x808003E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800428;
    }
    goto skip_1;
    // 0x808003E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808003EC: jal         0x80088838
    // 0x808003F0: nop

    _glcutDll_entrypoint_18(rdram, ctx);
        goto after_12;
    // 0x808003F0: nop

    after_12:
    // 0x808003F4: jal         0x8008A720
    // 0x808003F8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    _sujiggy_entrypoint_17(rdram, ctx);
        goto after_13;
    // 0x808003F8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_13:
    // 0x808003FC: bne         $v0, $zero, L_80800424
    if (ctx->r2 != 0) {
        // 0x80800400: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_80800424;
    }
    // 0x80800400: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800404: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80800408: beq         $v1, $at, L_80800424
    if (ctx->r3 == ctx->r1) {
        // 0x8080040C: addiu       $at, $zero, 0x7A
        ctx->r1 = ADD32(0, 0X7A);
            goto L_80800424;
    }
    // 0x8080040C: addiu       $at, $zero, 0x7A
    ctx->r1 = ADD32(0, 0X7A);
    // 0x80800410: beq         $v1, $at, L_80800424
    if (ctx->r3 == ctx->r1) {
        // 0x80800414: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800424;
    }
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8080041C: jal         0x8010108C
    // 0x80800420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_14;
    // 0x80800420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
L_80800424:
    // 0x80800424: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800428:
    // 0x80800428: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080042C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800430: jr          $ra
    // 0x80800434: nop

    return;
    // 0x80800434: nop

;}
RECOMP_FUNC void chcactusofstrength_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(824, 0XD90) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xD90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(824, 0XD90));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xD90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(824, 0XD90));
;}
RECOMP_FUNC void func_800D36C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D36C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D36C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D36CC: jal         0x800D35D0
    // 0x800D36D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800D35D0(rdram, ctx);
        goto after_0;
    // 0x800D36D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D36D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800D36D8: jal         0x800D3524
    // 0x800D36DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800D3524(rdram, ctx);
        goto after_1;
    // 0x800D36DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x800D36E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800D36E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D36E8: bltz        $a1, L_800D36F8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800D36EC: nop
    
            goto L_800D36F8;
    }
    // 0x800D36EC: nop

    // 0x800D36F0: bne         $v0, $zero, L_800D3708
    if (ctx->r2 != 0) {
        // 0x800D36F4: nop
    
            goto L_800D3708;
    }
    // 0x800D36F4: nop

L_800D36F8:
    // 0x800D36F8: jal         0x800D3574
    // 0x800D36FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800D3574(rdram, ctx);
        goto after_2;
    // 0x800D36FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800D3700: b           L_800D3718
    // 0x800D3704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D3718;
    // 0x800D3704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3708:
    // 0x800D3708: jal         0x800B0D6C
    // 0x800D370C: nop

    func_800B0D6C(rdram, ctx);
        goto after_3;
    // 0x800D370C: nop

    after_3:
    // 0x800D3710: lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2);
    // 0x800D3714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3718:
    // 0x800D3718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D371C: jr          $ra
    // 0x800D3720: nop

    return;
    // 0x800D3720: nop

;}
RECOMP_FUNC void _chnests_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AD0: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085AD0);
    return;
    // 0x80085AD4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _bakaztorpedo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D88: syscall     136
    recomp_syscall_handler(rdram, ctx, 0x80084D88);
    return;
    // 0x80084D8C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _susplinet_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E28: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E28);
    return;
    // 0x80089E2C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80800004: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8080000C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800010: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800014: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8080001C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800020: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800024: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800028: jal         0x80100094
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800030: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800034: addiu       $a0, $zero, 0x299
    ctx->r4 = ADD32(0, 0X299);
    // 0x80800038: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8080003C: jal         0x800882C0
    // 0x80800040: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // 0x80800044: lhu         $t8, 0x6E($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X6E);
    // 0x80800048: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x8080004C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800050: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800054: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800058: sh          $t0, 0x6E($s4)
    MEM_H(0X6E, ctx->r20) = ctx->r8;
    // 0x8080005C: lw          $t1, 0x6C($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X6C);
    // 0x80800060: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x80800064: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x80800068: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x8080006C: beq         $t2, $zero, L_808000EC
    if (ctx->r10 == 0) {
        // 0x80800070: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_808000EC;
    }
    // 0x80800070: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800074: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800078: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080007C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800080: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
L_80800084:
    // 0x80800084: jal         0x80088BE8
    // 0x80800088: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800088: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x8080008C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800090: nop

    // 0x80800094: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800098: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8080009C: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    // 0x808000A0: jal         0x80088BE8
    // 0x808000A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808000A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808000A8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x808000AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808000B0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808000B4: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x808000B8: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x808000BC: jal         0x80088C00
    // 0x808000C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808000C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x808000C4: jal         0x80088498
    // 0x808000C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _glsplinefind_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808000C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x808000CC: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x808000D0: lw          $t3, 0x6C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X6C);
    // 0x808000D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808000D8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000DC: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x808000E0: sltu        $at, $s2, $t4
    ctx->r1 = ctx->r18 < ctx->r12 ? 1 : 0;
    // 0x808000E4: bne         $at, $zero, L_80800084
    if (ctx->r1 != 0) {
        // 0x808000E8: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_80800084;
    }
    // 0x808000E8: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
L_808000EC:
    // 0x808000EC: lw          $t5, 0x70($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X70);
    // 0x808000F0: lbu         $a0, 0x50($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X50);
    // 0x808000F4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2372, 0X1070) << 16);
    // 0x808000F8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x808000FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800100: addiu       $a3, $a3, 0x1070
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2372, 0X1070));
    // 0x80800104: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    // 0x80800108: jal         0x80089D68
    // 0x8080010C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x8080010C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800110: sb          $v0, 0x50($s4)
    MEM_B(0X50, ctx->r20) = ctx->r2;
    // 0x80800114: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800118: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8080011C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800120: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800124: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80800128: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8080012C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800130: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800134: jr          $ra
    // 0x80800138: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80800138: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CA8: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CA8);
    return;
    // 0x80083CAC: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void _badrone_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084840: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084840);
    return;
    // 0x80084844: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800430_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800438: jal         0x80800164
    // 0x8080043C: nop

    func_80800164_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x8080043C: nop

    after_0:
    // 0x80800440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800448: jr          $ra
    // 0x8080044C: nop

    return;
    // 0x8080044C: nop

;}
RECOMP_FUNC void gzreg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080049C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004A0: lui         $v1, 0xA410
    ctx->r3 = S32(0XA410 << 16);
    // 0x808004A4: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x808004A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004AC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x808004B0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x808004B4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x808004B8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XDB8) << 16);
    // 0x808004BC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x808004C0: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x808004C4: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x808004C8: addiu       $a0, $a0, 0xDB8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XDB8));
    // 0x808004CC: jal         0x8001D37C
    // 0x808004D0: addu        $a1, $t6, $v0
    ctx->r5 = ADD32(ctx->r14, ctx->r2);
    func_8001D37C(rdram, ctx);
        goto after_0;
    // 0x808004D0: addu        $a1, $t6, $v0
    ctx->r5 = ADD32(ctx->r14, ctx->r2);
    after_0:
    // 0x808004D4: lui         $v1, 0xA410
    ctx->r3 = S32(0XA410 << 16);
    // 0x808004D8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x808004DC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x808004E0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x808004E4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XDE0) << 16);
    // 0x808004E8: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x808004EC: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x808004F0: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x808004F4: addiu       $a0, $a0, 0xDE0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XDE0));
    // 0x808004F8: jal         0x8001D37C
    // 0x808004FC: addu        $a1, $t9, $v0
    ctx->r5 = ADD32(ctx->r25, ctx->r2);
    func_8001D37C(rdram, ctx);
        goto after_1;
    // 0x808004FC: addu        $a1, $t9, $v0
    ctx->r5 = ADD32(ctx->r25, ctx->r2);
    after_1:
    // 0x80800500: lui         $v1, 0xA410
    ctx->r3 = S32(0XA410 << 16);
    // 0x80800504: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x80800508: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8080050C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80800510: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80800514: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XE08) << 16);
    // 0x80800518: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8080051C: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x80800520: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x80800524: addiu       $a0, $a0, 0xE08
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XE08));
    // 0x80800528: jal         0x8001D37C
    // 0x8080052C: addu        $a1, $t2, $v0
    ctx->r5 = ADD32(ctx->r10, ctx->r2);
    func_8001D37C(rdram, ctx);
        goto after_2;
    // 0x8080052C: addu        $a1, $t2, $v0
    ctx->r5 = ADD32(ctx->r10, ctx->r2);
    after_2:
    // 0x80800530: lui         $t5, 0xA410
    ctx->r13 = S32(0XA410 << 16);
    // 0x80800534: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XE30) << 16);
    // 0x80800538: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3394, 0XEA0) << 16);
    // 0x8080053C: addiu       $a2, $a2, 0xEA0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3394, 0XEA0));
    // 0x80800540: addiu       $a1, $a1, 0xE30
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XE30));
    // 0x80800544: jal         0x80800000
    // 0x80800548: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    func_80800000_gzreg(rdram, ctx);
        goto after_3;
    // 0x80800548: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    after_3:
    // 0x8080054C: lui         $t6, 0xA404
    ctx->r14 = S32(0XA404 << 16);
    // 0x80800550: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XE40) << 16);
    // 0x80800554: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3394, 0XF30) << 16);
    // 0x80800558: addiu       $a2, $a2, 0xF30
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3394, 0XF30));
    // 0x8080055C: addiu       $a1, $a1, 0xE40
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XE40));
    // 0x80800560: jal         0x80800000
    // 0x80800564: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    func_80800000_gzreg(rdram, ctx);
        goto after_4;
    // 0x80800564: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    after_4:
    // 0x80800568: jal         0x8001B3C0
    // 0x8080056C: nop

    heap_bytes_free(rdram, ctx);
        goto after_5;
    // 0x8080056C: nop

    after_5:
    // 0x80800570: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XE50) << 16);
    // 0x80800574: addiu       $a0, $a0, 0xE50
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XE50));
    // 0x80800578: jal         0x8001D37C
    // 0x8080057C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8001D37C(rdram, ctx);
        goto after_6;
    // 0x8080057C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80800580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800588: jr          $ra
    // 0x8080058C: nop

    return;
    // 0x8080058C: nop

;}
RECOMP_FUNC void func_80800794_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800794: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800798: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080079C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808007A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808007A4: jal         0x8008CABC
    // 0x808007A8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808007A8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808007AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808007B0: jal         0x80800098
    // 0x808007B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800098_bsbansnooze(rdram, ctx);
        goto after_1;
    // 0x808007B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808007B8: jal         0x8008AF24
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C4: jal         0x8008AED4
    // 0x808007C8: addiu       $a1, $zero, 0x277
    ctx->r5 = ADD32(0, 0X277);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x808007C8: addiu       $a1, $zero, 0x277
    ctx->r5 = ADD32(0, 0X277);
    after_3:
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D0: jal         0x8008B1BC
    // 0x808007D4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x808007D4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_4:
    // 0x808007D8: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x808007DC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808007E0: jal         0x8008B1C8
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_5;
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007EC: jal         0x8008B134
    // 0x808007F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x808007F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808007F4: jal         0x8008B064
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808007FC: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80800800: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800804: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080080C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800810: jal         0x8009FFD8
    // 0x80800814: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x80800814: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_8:
    // 0x80800818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080081C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800820: jal         0x8009C99C
    // 0x80800824: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_9;
    // 0x80800824: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_9:
    // 0x80800828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080082C: jal         0x8009B9B0
    // 0x80800830: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x80800830: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80800834: jal         0x8009514C
    // 0x80800838: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009514C(rdram, ctx);
        goto after_11;
    // 0x80800838: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8080083C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800844: jal         0x80085338
    // 0x80800848: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _batimer_set(rdram, ctx);
        goto after_12;
    // 0x80800848: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_12:
    // 0x8080084C: jal         0x800A1718
    // 0x80800850: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A1718(rdram, ctx);
        goto after_13;
    // 0x80800850: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800854: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800858: jal         0x800A1760
    // 0x8080085C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A1760(rdram, ctx);
        goto after_14;
    // 0x8080085C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800860: bne         $v0, $s0, L_80800870
    if (ctx->r2 != ctx->r16) {
        // 0x80800864: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800870;
    }
    // 0x80800864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800868: jal         0x800A17A8
    // 0x8080086C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A17A8(rdram, ctx);
        goto after_15;
    // 0x8080086C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
L_80800870:
    // 0x80800870: jal         0x8009E710
    // 0x80800874: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_16;
    // 0x80800874: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800878: addiu       $at, $zero, 0x170
    ctx->r1 = ADD32(0, 0X170);
    // 0x8080087C: bne         $v0, $at, L_8080088C
    if (ctx->r2 != ctx->r1) {
        // 0x80800880: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8080088C;
    }
    // 0x80800880: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800884: b           L_80800890
    // 0x80800888: sb          $zero, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = 0;
        goto L_80800890;
    // 0x80800888: sb          $zero, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = 0;
L_8080088C:
    // 0x8080088C: sb          $t7, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = ctx->r15;
L_80800890:
    // 0x80800890: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800894: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800898: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080089C: jr          $ra
    // 0x808008A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808008A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _babounce_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845D0: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x800845D0);
    return;
    // 0x800845D4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _ncbaswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089310: syscall     773
    recomp_syscall_handler(rdram, ctx, 0x80089310);
    return;
    // 0x80089314: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_800A5490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5498: jal         0x8008FFE8
    // 0x800A549C: nop

    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x800A549C: nop

    after_0:
    // 0x800A54A0: jal         0x8010FFD8
    // 0x800A54A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FFD8(rdram, ctx);
        goto after_1;
    // 0x800A54A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A54A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A54AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A54B0: jr          $ra
    // 0x800A54B4: nop

    return;
    // 0x800A54B4: nop

    // 0x800A54B8: nop

    // 0x800A54BC: nop

;}
RECOMP_FUNC void func_800ADFE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADFE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ADFE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ADFE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800ADFEC: jal         0x800AE080
    // 0x800ADFF0: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x800ADFF0: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_0:
    // 0x800ADFF4: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x800ADFF8: beq         $t6, $zero, L_800AE008
    if (ctx->r14 == 0) {
        // 0x800ADFFC: nop
    
            goto L_800AE008;
    }
    // 0x800ADFFC: nop

    // 0x800AE000: jal         0x800E0A70
    // 0x800AE004: lh          $a0, 0xC($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XC);
    func_800E0A70(rdram, ctx);
        goto after_1;
    // 0x800AE004: lh          $a0, 0xC($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XC);
    after_1:
L_800AE008:
    // 0x800AE008: jal         0x8001B754
    // 0x800AE00C: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    func_8001B754(rdram, ctx);
        goto after_2;
    // 0x800AE00C: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_2:
    // 0x800AE010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE018: jr          $ra
    // 0x800AE01C: nop

    return;
    // 0x800AE01C: nop

;}
