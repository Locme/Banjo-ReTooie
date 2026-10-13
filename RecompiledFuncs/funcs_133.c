#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8009B4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B4D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B4D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009B4D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B4DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8009B4E0: lw          $a1, 0xC8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC8);
    // 0x8009B4E4: jal         0x800EE7F8
    // 0x8009B4E8: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009B4E8: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_0:
    // 0x8009B4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B4F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B4F4: jr          $ra
    // 0x8009B4F8: nop

    return;
    // 0x8009B4F8: nop

;}
RECOMP_FUNC void _bashoessuck_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085090: syscall     149
    recomp_syscall_handler(rdram, ctx, 0x80085090);
    return;
    // 0x80085094: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void badeathmatch_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: lw          $v0, 0x158($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X158);
    // 0x8080038C: lbu         $t6, 0x21($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X21);
    // 0x80800390: beql        $t6, $zero, L_808003A4
    if (ctx->r14 == 0) {
        // 0x80800394: lbu         $v1, 0x20($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X20);
            goto L_808003A4;
    }
    goto skip_0;
    // 0x80800394: lbu         $v1, 0x20($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X20);
    skip_0:
    // 0x80800398: jr          $ra
    // 0x8080039C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x8080039C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x808003A0: lbu         $v1, 0x20($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X20);
L_808003A4:
    // 0x808003A4: jr          $ra
    // 0x808003A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808003A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80800000_chlavaentrydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080000C: beq         $a1, $at, L_80800028
    if (ctx->r5 == ctx->r1) {
        // 0x80800010: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800028;
    }
    // 0x80800010: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800014: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800018: beq         $a1, $at, L_8080003C
    if (ctx->r5 == ctx->r1) {
        // 0x8080001C: nop
    
            goto L_8080003C;
    }
    // 0x8080001C: nop

    // 0x80800020: b           L_808000BC
    // 0x80800024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000BC;
    // 0x80800024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800028:
    // 0x80800028: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8080002C: jal         0x80086670
    // 0x80800030: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800030: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80800034: b           L_808000BC
    // 0x80800038: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000BC;
    // 0x80800038: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080003C:
    // 0x8080003C: jal         0x80101080
    // 0x80800040: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_1;
    // 0x80800040: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800044: jal         0x80106790
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080004C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800054: jal         0x800866C0
    // 0x80800058: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800058: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x8080005C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800060: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800064: jal         0x800866D0
    // 0x80800068: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x80800068: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x8080006C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800070: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2000, 0X150) << 16);
    // 0x80800074: addiu       $t6, $t6, 0x150
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2000, 0X150));
    // 0x80800078: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8080007C: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x80800080: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800084: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800088: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080008C: jal         0x800BABB8
    // 0x80800090: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x80800090: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800094: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2000, 0X190) << 16);
    // 0x80800098: addiu       $a1, $a1, 0x190
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2000, 0X190));
    // 0x8080009C: jal         0x800C4AF0
    // 0x808000A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800C4AF0(rdram, ctx);
        goto after_6;
    // 0x808000A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808000A4: jal         0x800DA544
    // 0x808000A8: addiu       $a0, $zero, 0x398
    ctx->r4 = ADD32(0, 0X398);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x808000A8: addiu       $a0, $zero, 0x398
    ctx->r4 = ADD32(0, 0X398);
    after_7:
    // 0x808000AC: b           L_808000BC
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000BC;
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000B4: b           L_808000BC
    // 0x808000B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000BC;
    // 0x808000B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000BC:
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void bskazegghead_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B4: jal         0x8008CABC
    // 0x808000B8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808000B8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808000BC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808000C0: jal         0x80094BC0
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094BC0(rdram, ctx);
        goto after_1;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000C8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000CC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x808000D0: jal         0x80097C3C
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_shoot_egg(rdram, ctx);
        goto after_2;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D8: beql        $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x808000DC: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80800110;
    }
    goto skip_0;
    // 0x808000DC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000E0: jal         0x80094B14
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094B14(rdram, ctx);
        goto after_3;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000E8: beq         $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x808000EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080010C;
    }
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x800944E0
    // 0x808000F4: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    func_800944E0(rdram, ctx);
        goto after_4;
    // 0x808000F4: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    after_4:
    // 0x808000F8: lw          $a0, 0x15C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X15C);
    // 0x808000FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800100: jal         0x800F1418
    // 0x80800104: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_800F1418(rdram, ctx);
        goto after_5;
    // 0x80800104: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_5:
    // 0x80800108: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
L_8080010C:
    // 0x8080010C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800110:
    // 0x80800110: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800114: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800118: beq         $t7, $zero, L_808001D8
    if (ctx->r15 == 0) {
        // 0x8080011C: nop
    
            goto L_808001D8;
    }
    // 0x8080011C: nop

    // 0x80800120: jal         0x8008B348
    // 0x80800124: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    anctrl_isAt(rdram, ctx);
        goto after_6;
    // 0x80800124: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_6:
    // 0x80800128: beql        $v0, $zero, L_8080013C
    if (ctx->r2 == 0) {
        // 0x8080012C: lui         $a1, 0x3ECC
        ctx->r5 = S32(0X3ECC << 16);
            goto L_8080013C;
    }
    goto skip_1;
    // 0x8080012C: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    skip_1:
    // 0x80800130: jal         0x80084A88
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggsetup_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800138: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
L_8080013C:
    // 0x8080013C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800140: jal         0x8008B348
    // 0x80800144: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_8;
    // 0x80800144: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80800148: beq         $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x8080014C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800158;
    }
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x80084A78
    // 0x80800154: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    _baeggsetup_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x80800154: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    after_9:
L_80800158:
    // 0x80800158: lui         $a1, 0x3EDC
    ctx->r5 = S32(0X3EDC << 16);
    // 0x8080015C: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    // 0x80800160: jal         0x8008B348
    // 0x80800164: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x80800164: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x80800168: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x8080016C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800188;
    }
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    // 0x80800174: lui         $a2, 0x4204
    ctx->r6 = S32(0X4204 << 16);
    // 0x80800178: jal         0x80084A60
    // 0x8080017C: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    _baeggsetup_entrypoint_5(rdram, ctx);
        goto after_11;
    // 0x8080017C: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_11:
    // 0x80800180: jal         0x800C6DA0
    // 0x80800184: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800C6DA0(rdram, ctx);
        goto after_12;
    // 0x80800184: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_12:
L_80800188:
    // 0x80800188: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x8080018C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800190: jal         0x8008B348
    // 0x80800194: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_13;
    // 0x80800194: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x80800198: beq         $v0, $zero, L_808001D8
    if (ctx->r2 == 0) {
        // 0x8080019C: nop
    
            goto L_808001D8;
    }
    // 0x8080019C: nop

    // 0x808001A0: lw          $t8, 0x160($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X160);
    // 0x808001A4: lw          $t9, 0x15C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X15C);
    // 0x808001A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001AC: lui         $a1, 0x3EA3
    ctx->r5 = S32(0X3EA3 << 16);
    // 0x808001B0: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808001B4: beq         $at, $zero, L_808001D8
    if (ctx->r1 == 0) {
        // 0x808001B8: nop
    
            goto L_808001D8;
    }
    // 0x808001B8: nop

    // 0x808001BC: jal         0x8008B24C
    // 0x808001C0: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    anctrl_setStart(rdram, ctx);
        goto after_14;
    // 0x808001C0: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_14:
    // 0x808001C4: jal         0x8008B064
    // 0x808001C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_start(rdram, ctx);
        goto after_15;
    // 0x808001C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x808001CC: lw          $t0, 0x160($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X160);
    // 0x808001D0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x808001D4: sw          $t1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r9;
L_808001D8:
    // 0x808001D8: jal         0x8008DD04
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_16;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001E0: beq         $v0, $zero, L_808001F0
    if (ctx->r2 == 0) {
        // 0x808001E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F0;
    }
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: addiu       $t2, $zero, 0xDF
    ctx->r10 = ADD32(0, 0XDF);
    // 0x808001EC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_808001F0:
    // 0x808001F0: jal         0x800919F4
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_17;
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808001F8: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x808001FC: nop
    
            goto L_80800248;
    }
    // 0x808001FC: nop

    // 0x80800200: jal         0x8008B324
    // 0x80800204: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_18;
    // 0x80800204: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x80800208: beq         $v0, $zero, L_80800214
    if (ctx->r2 == 0) {
        // 0x8080020C: addiu       $t3, $zero, 0xDD
        ctx->r11 = ADD32(0, 0XDD);
            goto L_80800214;
    }
    // 0x8080020C: addiu       $t3, $zero, 0xDD
    ctx->r11 = ADD32(0, 0XDD);
    // 0x80800210: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80800214:
    // 0x80800214: jal         0x8008B2B4
    // 0x80800218: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_19;
    // 0x80800218: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_19:
    // 0x8080021C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(252, 0X2E0) << 16);
    // 0x80800220: lwc1        $f4, 0x2E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(252, 0X2E0));
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080022C: nop

    // 0x80800230: bc1fl       L_80800260
    if (!c1cs) {
        // 0x80800234: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800260;
    }
    goto skip_2;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800238: jal         0x80083300
    // 0x8080023C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _bskazcrouch_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x8080023C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_20:
    // 0x80800240: b           L_8080025C
    // 0x80800244: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_8080025C;
    // 0x80800244: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80800248:
    // 0x80800248: jal         0x8008B324
    // 0x8080024C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_21;
    // 0x8080024C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x80800250: beq         $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x80800254: addiu       $t4, $zero, 0xBB
        ctx->r12 = ADD32(0, 0XBB);
            goto L_8080025C;
    }
    // 0x80800254: addiu       $t4, $zero, 0xBB
    ctx->r12 = ADD32(0, 0XBB);
    // 0x80800258: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8080025C:
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800260:
    // 0x80800260: jal         0x8009E5C8
    // 0x80800264: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_22;
    // 0x80800264: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_22:
    // 0x80800268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080026C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800270: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800274: jr          $ra
    // 0x80800278: nop

    return;
    // 0x80800278: nop

;}
RECOMP_FUNC void func_80800B68_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800B6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800B74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800B78: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800B7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B80: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800B84: jal         0x80100094
    // 0x80800B88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B8C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800B90: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800B94: addiu       $t7, $t6, -0x1F
    ctx->r15 = ADD32(ctx->r14, -0X1F);
    // 0x80800B98: sltiu       $at, $t7, 0x2B
    ctx->r1 = ctx->r15 < 0X2B ? 1 : 0;
    // 0x80800B9C: beq         $at, $zero, L_80800DD8
    if (ctx->r1 == 0) {
        // 0x80800BA0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800DD8;
    }
    // 0x80800BA0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800BA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1664) << 16);
    // 0x80800BA8: addu        $at, $at, $t7
    gpr jr_addend_80800BB0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800BAC: lw          $t7, 0x1664($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1664));
    // 0x80800BB0: jr          $t7
    // 0x80800BB4: nop

    switch (jr_addend_80800BB0 >> 2) {
        case 0: goto L_80800D84; break;
        case 1: goto L_80800DD8; break;
        case 2: goto L_80800DD8; break;
        case 3: goto L_80800DD8; break;
        case 4: goto L_80800DD8; break;
        case 5: goto L_80800DD8; break;
        case 6: goto L_80800DD8; break;
        case 7: goto L_80800DD8; break;
        case 8: goto L_80800DD8; break;
        case 9: goto L_80800DD8; break;
        case 10: goto L_80800DD8; break;
        case 11: goto L_80800DD8; break;
        case 12: goto L_80800DD8; break;
        case 13: goto L_80800DD8; break;
        case 14: goto L_80800DD8; break;
        case 15: goto L_80800DD8; break;
        case 16: goto L_80800DD8; break;
        case 17: goto L_80800DD8; break;
        case 18: goto L_80800DD8; break;
        case 19: goto L_80800D4C; break;
        case 20: goto L_80800DD8; break;
        case 21: goto L_80800DD8; break;
        case 22: goto L_80800DD8; break;
        case 23: goto L_80800DD8; break;
        case 24: goto L_80800DD8; break;
        case 25: goto L_80800DD8; break;
        case 26: goto L_80800DD8; break;
        case 27: goto L_80800DD8; break;
        case 28: goto L_80800DD8; break;
        case 29: goto L_80800DD8; break;
        case 30: goto L_80800D70; break;
        case 31: goto L_80800D5C; break;
        case 32: goto L_80800DD8; break;
        case 33: goto L_80800DD8; break;
        case 34: goto L_80800DD8; break;
        case 35: goto L_80800DD8; break;
        case 36: goto L_80800DD8; break;
        case 37: goto L_80800DD8; break;
        case 38: goto L_80800DD8; break;
        case 39: goto L_80800DD8; break;
        case 40: goto L_80800DD8; break;
        case 41: goto L_80800DD8; break;
        case 42: goto L_80800BB8; break;
        default: switch_error(__func__, 0x80800BB0, 0x80801664);
    }
    // 0x80800BB4: nop

L_80800BB8:
    // 0x80800BB8: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800BBC: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800BC0: bgezl       $t0, L_80800DE4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800BC4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800DE4;
    }
    goto skip_0;
    // 0x80800BC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800BC8: jal         0x800F54E4
    // 0x80800BCC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800BCC: nop

    after_1:
    // 0x80800BD0: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
    // 0x80800BD4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800BD8: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80800BDC: jal         0x8010573C
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010573C(rdram, ctx);
        goto after_2;
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800BE4: jal         0x80103014
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_3;
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800BEC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800BF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800BF4: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800BF8: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800BFC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800C00: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800C04: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800C08: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800C0C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800C10: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800C14: jal         0x800EEC30
    // 0x80800C18: nop

    func_800EEC30(rdram, ctx);
        goto after_4;
    // 0x80800C18: nop

    after_4:
    // 0x80800C1C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800C20: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800C24: jal         0x800EF04C
    // 0x80800C28: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800C28: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x80800C2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800C30: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800C34: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800C38: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C3C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800C40: jal         0x800EFA4C
    // 0x80800C44: nop

    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x80800C44: nop

    after_6:
    // 0x80800C48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C4C: jal         0x800F8294
    // 0x80800C50: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F8294(rdram, ctx);
        goto after_7;
    // 0x80800C50: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_7:
    // 0x80800C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C58: jal         0x800F832C
    // 0x80800C5C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F832C(rdram, ctx);
        goto after_8;
    // 0x80800C5C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x80800C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C64: jal         0x800F608C
    // 0x80800C68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800F608C(rdram, ctx);
        goto after_9;
    // 0x80800C68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x80800C6C: jal         0x800F497C
    // 0x80800C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F497C(rdram, ctx);
        goto after_10;
    // 0x80800C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800C74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C78: jal         0x800F4A2C
    // 0x80800C7C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F4A2C(rdram, ctx);
        goto after_11;
    // 0x80800C7C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_11:
    // 0x80800C80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C84: jal         0x800F49A8
    // 0x80800C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F49A8(rdram, ctx);
        goto after_12;
    // 0x80800C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800C8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C90: jal         0x800F4A00
    // 0x80800C94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F4A00(rdram, ctx);
        goto after_13;
    // 0x80800C94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800C98: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80800C9C: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x80800CA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CA4: jal         0x800F49D4
    // 0x80800CA8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_14;
    // 0x80800CA8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_14:
    // 0x80800CAC: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800CB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800CB4: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800CB8: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800CBC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800CC0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800CC4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80800CC8: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800CCC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800CD0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800CD4: jal         0x800EEC30
    // 0x80800CD8: nop

    func_800EEC30(rdram, ctx);
        goto after_15;
    // 0x80800CD8: nop

    after_15:
    // 0x80800CDC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800CE0: jal         0x800EF04C
    // 0x80800CE4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_16;
    // 0x80800CE4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_16:
    // 0x80800CE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CEC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800CF0: jal         0x800F4A8C
    // 0x80800CF4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_800F4A8C(rdram, ctx);
        goto after_17;
    // 0x80800CF4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_17:
    // 0x80800CF8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800CFC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80800D00: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800D04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800D08: swc1        $f16, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f16.u32l;
    // 0x80800D0C: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80800D10: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x80800D14: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800D18: andi        $t8, $t5, 0xFFEF
    ctx->r24 = ctx->r13 & 0XFFEF;
    // 0x80800D1C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800D20: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800D24: ori         $t4, $t3, 0xF0
    ctx->r12 = ctx->r11 | 0XF0;
    // 0x80800D28: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
    // 0x80800D2C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80800D30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D34: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // 0x80800D38: addiu       $a3, $zero, 0xA4C
    ctx->r7 = ADD32(0, 0XA4C);
    // 0x80800D3C: jal         0x80085708
    // 0x80800D40: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    _capod_entrypoint_13(rdram, ctx);
        goto after_18;
    // 0x80800D40: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_18:
    // 0x80800D44: b           L_80800DE4
    // 0x80800D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DE4;
    // 0x80800D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D4C:
    // 0x80800D4C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800D50: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80800D54: b           L_80800DE0
    // 0x80800D58: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_80800DE0;
    // 0x80800D58: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_80800D5C:
    // 0x80800D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D60: jal         0x8080096C
    // 0x80800D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080096C_chtoothyfish(rdram, ctx);
        goto after_19;
    // 0x80800D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_19:
    // 0x80800D68: b           L_80800DE4
    // 0x80800D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DE4;
    // 0x80800D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D70:
    // 0x80800D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D74: jal         0x80801588
    // 0x80800D78: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80801588_chtoothyfish(rdram, ctx);
        goto after_20;
    // 0x80800D78: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_20:
    // 0x80800D7C: b           L_80800DE4
    // 0x80800D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DE4;
    // 0x80800D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D84:
    // 0x80800D84: jal         0x801015D0
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_21;
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800D8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800D90: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
L_80800D94:
    // 0x80800D94: lbu         $t2, 0x34($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X34);
    // 0x80800D98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D9C: addiu       $a0, $s0, 0x3
    ctx->r4 = ADD32(ctx->r16, 0X3);
    // 0x80800DA0: beq         $t2, $zero, L_80800DB8
    if (ctx->r10 == 0) {
        // 0x80800DA4: nop
    
            goto L_80800DB8;
    }
    // 0x80800DA4: nop

    // 0x80800DA8: jal         0x800DF744
    // 0x80800DAC: addiu       $a0, $s0, 0x3
    ctx->r4 = ADD32(ctx->r16, 0X3);
    func_800DF744(rdram, ctx);
        goto after_22;
    // 0x80800DAC: addiu       $a0, $s0, 0x3
    ctx->r4 = ADD32(ctx->r16, 0X3);
    after_22:
    // 0x80800DB0: b           L_80800DC4
    // 0x80800DB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80800DC4;
    // 0x80800DB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800DB8:
    // 0x80800DB8: jal         0x800DF744
    // 0x80800DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_23;
    // 0x80800DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800DC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800DC4:
    // 0x80800DC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800DC8: bne         $s0, $at, L_80800D94
    if (ctx->r16 != ctx->r1) {
        // 0x80800DCC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800D94;
    }
    // 0x80800DCC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800DD0: b           L_80800DE4
    // 0x80800DD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DE4;
    // 0x80800DD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DD8:
    // 0x80800DD8: b           L_80800DE4
    // 0x80800DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800DE4;
    // 0x80800DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DE0:
    // 0x80800DE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DE4:
    // 0x80800DE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800DEC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800DF0: jr          $ra
    // 0x80800DF4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800DF4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_808011C0_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808011C4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808011C8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808011CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808011D0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808011D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808011D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808011DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808011E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808011E4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808011E8: lui         $a1, 0xC2B4
    ctx->r5 = S32(0XC2B4 << 16);
    // 0x808011EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808011F0: jal         0x800EF4E4
    // 0x808011F4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_0;
    // 0x808011F4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808011F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011FC: jal         0x8009B94C
    // 0x80801200: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_8009B94C(rdram, ctx);
        goto after_1;
    // 0x80801200: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x80801204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801208: jal         0x8009BA9C
    // 0x8080120C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_8009BA9C(rdram, ctx);
        goto after_2;
    // 0x8080120C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x80801210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801214: jal         0x800852F8
    // 0x80801218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_increment(rdram, ctx);
        goto after_3;
    // 0x80801218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080121C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80801220: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801228: jal         0x80085310
    // 0x8080122C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isAt_rising(rdram, ctx);
        goto after_4;
    // 0x8080122C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80801230: bne         $v0, $zero, L_80801264
    if (ctx->r2 != 0) {
        // 0x80801234: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801264;
    }
    // 0x80801234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801238: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080123C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801240: jal         0x80085310
    // 0x80801244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isAt_rising(rdram, ctx);
        goto after_5;
    // 0x80801244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80801248: bne         $v0, $zero, L_80801264
    if (ctx->r2 != 0) {
        // 0x8080124C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801264;
    }
    // 0x8080124C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801250: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80801254: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801258: jal         0x80085310
    // 0x8080125C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isAt_rising(rdram, ctx);
        goto after_6;
    // 0x8080125C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801260: beq         $v0, $zero, L_80801278
    if (ctx->r2 == 0) {
        // 0x80801264: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801278;
    }
L_80801264:
    // 0x80801264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801268: addiu       $a1, $zero, 0x468
    ctx->r5 = ADD32(0, 0X468);
    // 0x8080126C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801270: jal         0x8009DF18
    // 0x80801274: addiu       $a3, $zero, 0x5DC0
    ctx->r7 = ADD32(0, 0X5DC0);
    func_8009DF18(rdram, ctx);
        goto after_7;
    // 0x80801274: addiu       $a3, $zero, 0x5DC0
    ctx->r7 = ADD32(0, 0X5DC0);
    after_7:
L_80801278:
    // 0x80801278: jal         0x8001210C
    // 0x8080127C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_8;
    // 0x8080127C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80801280: bne         $v0, $zero, L_808012F0
    if (ctx->r2 != 0) {
        // 0x80801284: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012F0;
    }
    // 0x80801284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801288: jal         0x8009C128
    // 0x8080128C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8009C128(rdram, ctx);
        goto after_9;
    // 0x8080128C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_9:
    // 0x80801290: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801294: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801298: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080129C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808012A4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808012A8: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    // 0x808012AC: jal         0x8009FBB0
    // 0x808012B0: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    func_8009FBB0(rdram, ctx);
        goto after_10;
    // 0x808012B0: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x808012B4: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x808012B8: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x808012BC: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x808012C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808012C4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808012C8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808012CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808012D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012D4: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x808012D8: addiu       $a2, $zero, -0x32
    ctx->r6 = ADD32(0, -0X32);
    // 0x808012DC: jal         0x800BA930
    // 0x808012E0: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    func_800BA930(rdram, ctx);
        goto after_11;
    // 0x808012E0: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    after_11:
    // 0x808012E4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808012E8: jal         0x800BA22C
    // 0x808012EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_12;
    // 0x808012EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
L_808012F0:
    // 0x808012F0: lui         $a2, 0x3FC6
    ctx->r6 = S32(0X3FC6 << 16);
    // 0x808012F4: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808012F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012FC: jal         0x80085320
    // 0x80801300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isGreaterThan(rdram, ctx);
        goto after_13;
    // 0x80801300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80801304: beq         $v0, $zero, L_80801314
    if (ctx->r2 == 0) {
        // 0x80801308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801314;
    }
    // 0x80801308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080130C: jal         0x8009BA58
    // 0x80801310: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_14;
    // 0x80801310: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    after_14:
L_80801314:
    // 0x80801314: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x80801318: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080131C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801320: jal         0x80085310
    // 0x80801324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isAt_rising(rdram, ctx);
        goto after_15;
    // 0x80801324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80801328: beq         $v0, $zero, L_80801388
    if (ctx->r2 == 0) {
        // 0x8080132C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801388;
    }
    // 0x8080132C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801330: jal         0x800A4DA4
    // 0x80801334: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DA4(rdram, ctx);
        goto after_16;
    // 0x80801334: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_16:
    // 0x80801338: jal         0x800A4CA8
    // 0x8080133C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_17;
    // 0x8080133C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801344: jal         0x80089288
    // 0x80801348: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x80801348: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    after_18:
    // 0x8080134C: lw          $t9, 0x15C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X15C);
    // 0x80801350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801354: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801358: beq         $t9, $zero, L_80801370
    if (ctx->r25 == 0) {
        // 0x8080135C: nop
    
            goto L_80801370;
    }
    // 0x8080135C: nop

    // 0x80801360: jal         0x80085338
    // 0x80801364: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_set(rdram, ctx);
        goto after_19;
    // 0x80801364: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_19:
    // 0x80801368: b           L_8080138C
    // 0x8080136C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080138C;
    // 0x8080136C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801370:
    // 0x80801370: jal         0x800A0180
    // 0x80801374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0180(rdram, ctx);
        goto after_20;
    // 0x80801374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080137C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801380: jal         0x80085338
    // 0x80801384: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    _batimer_set(rdram, ctx);
        goto after_21;
    // 0x80801384: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_21:
L_80801388:
    // 0x80801388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080138C:
    // 0x8080138C: jal         0x800852F0
    // 0x80801390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_22;
    // 0x80801390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80801394: beql        $v0, $zero, L_808013A8
    if (ctx->r2 == 0) {
        // 0x80801398: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013A8;
    }
    goto skip_0;
    // 0x80801398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080139C: jal         0x80085200
    // 0x808013A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_23;
    // 0x808013A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808013A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808013A8:
    // 0x808013A8: jal         0x8009E5C8
    // 0x808013AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bs_setState(rdram, ctx);
        goto after_24;
    // 0x808013AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x808013B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808013B4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808013B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808013BC: jr          $ra
    // 0x808013C0: nop

    return;
    // 0x808013C0: nop

;}
RECOMP_FUNC void _bsbpeck_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AE0: syscall     25
    recomp_syscall_handler(rdram, ctx, 0x80082AE0);
    return;
    // 0x80082AE4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800BD4_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800BE0: jal         0x80100094
    // 0x80800BE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800BE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800BE8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BEC: sw          $t6, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->r14;
    // 0x80800BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BF8: jr          $ra
    // 0x80800BFC: nop

    return;
    // 0x80800BFC: nop

;}
RECOMP_FUNC void func_8080462C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080462C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804634: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80804638: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    // 0x8080463C: jal         0x80801658
    // 0x80804640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801658_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80804644: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80804648: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(804, 0X7DB0) << 16);
    // 0x8080464C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80804650: lbu         $t7, 0x79($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X79);
    // 0x80804654: lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X30);
    // 0x80804658: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080465C: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x80804660: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80804664: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x80804668: lh          $a1, 0x7DB0($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(804, 0X7DB0));
    // 0x8080466C: jal         0x80802AD4
    // 0x80804670: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80802AD4_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804670: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80804674: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80804678: jal         0x80803D00
    // 0x8080467C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_2;
    // 0x8080467C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80804680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804684: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080468C: jr          $ra
    // 0x80804690: nop

    return;
    // 0x80804690: nop

;}
RECOMP_FUNC void func_80800000_chfantasysafeswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x8080000C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800010: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800014: jal         0x80103110
    // 0x80800018: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x80800018: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void _chglowbo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AC0: syscall     414
    recomp_syscall_handler(rdram, ctx, 0x80086AC0);
    return;
    // 0x80086AC4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void idbounce_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080093C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800940: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800944: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080094C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800950: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800954: jal         0x80800874
    // 0x80800958: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800874_idbounce(rdram, ctx);
        goto after_0;
    // 0x80800958: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080095C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800960: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800964: jal         0x80088890
    // 0x80800968: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _glidmake_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800968: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080096C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800970: jal         0x8001ACCC
    // 0x80800974: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x80800974: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    after_2:
    // 0x80800978: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8080097C: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80800980: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800984: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80800988: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8080098C: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x80800990: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80800994: beq         $at, $zero, L_808009C0
    if (ctx->r1 == 0) {
        // 0x80800998: sw          $v1, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->r3;
            goto L_808009C0;
    }
    // 0x80800998: sw          $v1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r3;
    // 0x8080099C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808009A0: nop

L_808009A4:
    // 0x808009A4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x808009A8: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x808009AC: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x808009B0: addiu       $v0, $t8, 0x4
    ctx->r2 = ADD32(ctx->r24, 0X4);
    // 0x808009B4: sltu        $at, $v0, $t0
    ctx->r1 = ctx->r2 < ctx->r8 ? 1 : 0;
    // 0x808009B8: bne         $at, $zero, L_808009A4
    if (ctx->r1 != 0) {
        // 0x808009BC: sw          $v0, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r2;
            goto L_808009A4;
    }
    // 0x808009BC: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
L_808009C0:
    // 0x808009C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808009C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2890, 0XE3C) << 16);
    // 0x808009C8: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x808009CC: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x808009D0: lwc1        $f8, 0xE3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2890, 0XE3C));
    // 0x808009D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808009D8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x808009DC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808009E0: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x808009E4: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x808009E8: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x808009EC: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x808009F0: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    // 0x808009F4: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x808009F8: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x808009FC: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80800A00: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x80800A04: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80800A08: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x80800A0C: lwc1        $f10, 0x1C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80800A10: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x80800A14: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80800A18: bnel        $t1, $at, L_80800AFC
    if (ctx->r9 != ctx->r1) {
        // 0x80800A1C: swc1        $f0, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
            goto L_80800AFC;
    }
    goto skip_0;
    // 0x80800A1C: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x80800A20: jal         0x80106314
    // 0x80800A24: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80106314(rdram, ctx);
        goto after_3;
    // 0x80800A24: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800A28: jal         0x80106790
    // 0x80800A2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80800A2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800A30: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800A34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A3C: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80800A40: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80800A44: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80800A48: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800A4C: jal         0x800EE7F8
    // 0x80800A50: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800A50: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x80800A54: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80800A58: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A5C: lw          $v0, 0x6C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X6C);
    // 0x80800A60: sll         $t3, $v0, 11
    ctx->r11 = S32(ctx->r2 << 11);
    // 0x80800A64: srl         $t4, $t3, 20
    ctx->r12 = S32(U32(ctx->r11) >> 20);
    // 0x80800A68: sltiu       $at, $t4, 0x4C7
    ctx->r1 = ctx->r12 < 0X4C7 ? 1 : 0;
    // 0x80800A6C: bne         $at, $zero, L_80800AA0
    if (ctx->r1 != 0) {
        // 0x80800A70: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_80800AA0;
    }
    // 0x80800A70: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80800A74: addiu       $at, $zero, 0x4C7
    ctx->r1 = ADD32(0, 0X4C7);
    // 0x80800A78: beq         $t4, $at, L_80800AE0
    if (ctx->r12 == ctx->r1) {
        // 0x80800A7C: addiu       $at, $zero, 0x50B
        ctx->r1 = ADD32(0, 0X50B);
            goto L_80800AE0;
    }
    // 0x80800A7C: addiu       $at, $zero, 0x50B
    ctx->r1 = ADD32(0, 0X50B);
    // 0x80800A80: beq         $t4, $at, L_80800AE0
    if (ctx->r12 == ctx->r1) {
        // 0x80800A84: addiu       $at, $zero, 0x50C
        ctx->r1 = ADD32(0, 0X50C);
            goto L_80800AE0;
    }
    // 0x80800A84: addiu       $at, $zero, 0x50C
    ctx->r1 = ADD32(0, 0X50C);
    // 0x80800A88: beq         $t4, $at, L_80800AE0
    if (ctx->r12 == ctx->r1) {
        // 0x80800A8C: addiu       $at, $zero, 0x531
        ctx->r1 = ADD32(0, 0X531);
            goto L_80800AE0;
    }
    // 0x80800A8C: addiu       $at, $zero, 0x531
    ctx->r1 = ADD32(0, 0X531);
    // 0x80800A90: beql        $t4, $at, L_80800AE4
    if (ctx->r12 == ctx->r1) {
        // 0x80800A94: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_80800AE4;
    }
    goto skip_1;
    // 0x80800A94: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    skip_1:
    // 0x80800A98: b           L_80800AF0
    // 0x80800A9C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
        goto L_80800AF0;
    // 0x80800A9C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80800AA0:
    // 0x80800AA0: addiu       $at, $zero, 0x34C
    ctx->r1 = ADD32(0, 0X34C);
    // 0x80800AA4: beq         $v0, $at, L_80800AD8
    if (ctx->r2 == ctx->r1) {
        // 0x80800AA8: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_80800AD8;
    }
    // 0x80800AA8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80800AAC: addiu       $at, $zero, 0x47E
    ctx->r1 = ADD32(0, 0X47E);
    // 0x80800AB0: beq         $v0, $at, L_80800AE0
    if (ctx->r2 == ctx->r1) {
        // 0x80800AB4: addiu       $at, $zero, 0x4C4
        ctx->r1 = ADD32(0, 0X4C4);
            goto L_80800AE0;
    }
    // 0x80800AB4: addiu       $at, $zero, 0x4C4
    ctx->r1 = ADD32(0, 0X4C4);
    // 0x80800AB8: beq         $v0, $at, L_80800AE0
    if (ctx->r2 == ctx->r1) {
        // 0x80800ABC: addiu       $at, $zero, 0x4C5
        ctx->r1 = ADD32(0, 0X4C5);
            goto L_80800AE0;
    }
    // 0x80800ABC: addiu       $at, $zero, 0x4C5
    ctx->r1 = ADD32(0, 0X4C5);
    // 0x80800AC0: beq         $v0, $at, L_80800AE0
    if (ctx->r2 == ctx->r1) {
        // 0x80800AC4: addiu       $at, $zero, 0x4C6
        ctx->r1 = ADD32(0, 0X4C6);
            goto L_80800AE0;
    }
    // 0x80800AC4: addiu       $at, $zero, 0x4C6
    ctx->r1 = ADD32(0, 0X4C6);
    // 0x80800AC8: beql        $v0, $at, L_80800AE4
    if (ctx->r2 == ctx->r1) {
        // 0x80800ACC: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_80800AE4;
    }
    goto skip_2;
    // 0x80800ACC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    skip_2:
    // 0x80800AD0: b           L_80800AF0
    // 0x80800AD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
        goto L_80800AF0;
    // 0x80800AD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80800AD8:
    // 0x80800AD8: b           L_80800B60
    // 0x80800ADC: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
        goto L_80800B60;
    // 0x80800ADC: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_80800AE0:
    // 0x80800AE0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
L_80800AE4:
    // 0x80800AE4: b           L_80800B60
    // 0x80800AE8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
        goto L_80800B60;
    // 0x80800AE8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80800AEC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80800AF0:
    // 0x80800AF0: b           L_80800B60
    // 0x80800AF4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
        goto L_80800B60;
    // 0x80800AF4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x80800AF8: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
L_80800AFC:
    // 0x80800AFC: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800B00: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800B04: jal         0x800EA05C
    // 0x80800B08: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800EA05C(rdram, ctx);
        goto after_6;
    // 0x80800B08: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_6:
    // 0x80800B0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800B10: addiu       $at, $zero, 0xE2
    ctx->r1 = ADD32(0, 0XE2);
    // 0x80800B14: beq         $v0, $at, L_80800B4C
    if (ctx->r2 == ctx->r1) {
        // 0x80800B18: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80800B4C;
    }
    // 0x80800B18: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B1C: addiu       $at, $zero, 0xE4
    ctx->r1 = ADD32(0, 0XE4);
    // 0x80800B20: beq         $v0, $at, L_80800B4C
    if (ctx->r2 == ctx->r1) {
        // 0x80800B24: addiu       $at, $zero, 0xE5
        ctx->r1 = ADD32(0, 0XE5);
            goto L_80800B4C;
    }
    // 0x80800B24: addiu       $at, $zero, 0xE5
    ctx->r1 = ADD32(0, 0XE5);
    // 0x80800B28: beq         $v0, $at, L_80800B4C
    if (ctx->r2 == ctx->r1) {
        // 0x80800B2C: addiu       $at, $zero, 0xF8
        ctx->r1 = ADD32(0, 0XF8);
            goto L_80800B4C;
    }
    // 0x80800B2C: addiu       $at, $zero, 0xF8
    ctx->r1 = ADD32(0, 0XF8);
    // 0x80800B30: beq         $v0, $at, L_80800B4C
    if (ctx->r2 == ctx->r1) {
        // 0x80800B34: addiu       $at, $zero, 0x138
        ctx->r1 = ADD32(0, 0X138);
            goto L_80800B4C;
    }
    // 0x80800B34: addiu       $at, $zero, 0x138
    ctx->r1 = ADD32(0, 0X138);
    // 0x80800B38: beql        $v0, $at, L_80800B50
    if (ctx->r2 == ctx->r1) {
        // 0x80800B3C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800B50;
    }
    goto skip_3;
    // 0x80800B3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_3:
    // 0x80800B40: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800B44: b           L_80800B60
    // 0x80800B48: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_80800B60;
    // 0x80800B48: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80800B4C:
    // 0x80800B4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800B50:
    // 0x80800B50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B54: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800B58: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x80800B5C: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
L_80800B60:
    // 0x80800B60: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800B64: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800B68: nop

    // 0x80800B6C: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x80800B70: nop

    // 0x80800B74: bc1tl       L_80800BD4
    if (c1cs) {
        // 0x80800B78: lwc1        $f18, 0xC($a2)
        ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
            goto L_80800BD4;
    }
    goto skip_4;
    // 0x80800B78: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    skip_4:
    // 0x80800B7C: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800B80: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800B84: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800B88: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800B8C: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80800B90: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800B94: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800B98: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800B9C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x80800BA0: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800BA4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800BA8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800BAC: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80800BB0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800BB4: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    // 0x80800BB8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800BBC: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x80800BC0: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x80800BC4: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800BC8: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x80800BCC: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x80800BD0: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
L_80800BD4:
    // 0x80800BD4: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80800BD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800BDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800BE0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800BE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80800BE8: addiu       $v0, $v0, 0x5480
    ctx->r2 = ADD32(ctx->r2, 0X5480);
    // 0x80800BEC: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80800BF0: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x80800BF4: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x80800BF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C00: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80800C04: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
    // 0x80800C08: jr          $ra
    // 0x80800C0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800C0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void subaddiesect_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800128: jal         0x80087F20
    // 0x8080012C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    _gcmapsects_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080012C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_80804D18_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804D18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804D1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804D20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804D24: jal         0x80807BB8
    // 0x80804D28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804D28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80804D2C: jal         0x80807DD4
    // 0x80804D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807DD4_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80804D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80804D34: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80804D38: ori         $a3, $a3, 0xEBEE
    ctx->r7 = ctx->r7 | 0XEBEE;
    // 0x80804D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804D40: addiu       $a1, $zero, 0x30D
    ctx->r5 = ADD32(0, 0X30D);
    // 0x80804D44: jal         0x8008CC34
    // 0x80804D48: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loopStartingAt(rdram, ctx);
        goto after_2;
    // 0x80804D48: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_2:
    // 0x80804D4C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80804D50: ori         $a3, $a3, 0xEBEE
    ctx->r7 = ctx->r7 | 0XEBEE;
    // 0x80804D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804D58: addiu       $a1, $zero, 0x311
    ctx->r5 = ADD32(0, 0X311);
    // 0x80804D5C: jal         0x808002CC
    // 0x80804D60: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_808002CC_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80804D60: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_3:
    // 0x80804D64: jal         0x80801A34
    // 0x80804D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A34_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80804D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80804D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804D70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804D74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804D78: jr          $ra
    // 0x80804D7C: nop

    return;
    // 0x80804D7C: nop

;}
RECOMP_FUNC void _bskaz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832D8: syscall     53
    recomp_syscall_handler(rdram, ctx, 0x800832D8);
    return;
    // 0x800832DC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void ncpod_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800958: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080095C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800960: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800964: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800968: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080096C: jal         0x8010FAE4
    // 0x80800970: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8010FAE4(rdram, ctx);
        goto after_0;
    // 0x80800970: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800974: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800978: bne         $v0, $at, L_80800988
    if (ctx->r2 != ctx->r1) {
        // 0x8080097C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800988;
    }
    // 0x8080097C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800980: b           L_808009D4
    // 0x80800984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009D4;
    // 0x80800984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800988:
    // 0x80800988: jal         0x8010F9C0
    // 0x8080098C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8010F9C0(rdram, ctx);
        goto after_1;
    // 0x8080098C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80800990: jal         0x80110024
    // 0x80800994: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80110024(rdram, ctx);
        goto after_2;
    // 0x80800994: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800998: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080099C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009A0: jal         0x808002D8
    // 0x808009A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    ncpod_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808009A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x808009A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808009AC: beql        $a1, $zero, L_808009C0
    if (ctx->r5 == 0) {
        // 0x808009B0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808009C0;
    }
    goto skip_0;
    // 0x808009B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808009B4: jal         0x80800548
    // 0x808009B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ncpod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x808009B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x808009BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_808009C0:
    // 0x808009C0: jal         0x80800BC0
    // 0x808009C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    ncpod_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x808009C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x808009C8: jal         0x8080006C
    // 0x808009CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8080006C_ncpod(rdram, ctx);
        goto after_6;
    // 0x808009CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x808009D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009D4:
    // 0x808009D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009DC: jr          $ra
    // 0x808009E0: nop

    return;
    // 0x808009E0: nop

;}
RECOMP_FUNC void _chtempleinternaldoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087368: syscall     555
    recomp_syscall_handler(rdram, ctx, 0x80087368);
    return;
    // 0x8008736C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080486C_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080486C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80804870: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1840, 0X50C0) << 16);
    // 0x80804874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804878: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080487C: addiu       $t7, $t7, 0x50C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1840, 0X50C0));
    // 0x80804880: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80804884: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80804888: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8080488C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80804890: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80804894: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804898: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8080489C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x808048A0: jal         0x80106790
    // 0x808048A4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808048A4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808048A8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808048AC: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x808048B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808048B4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808048B8: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x808048BC: beq         $t2, $at, L_80804944
    if (ctx->r10 == ctx->r1) {
        // 0x808048C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804944;
    }
    // 0x808048C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808048C4: jal         0x80102D78
    // 0x808048C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x808048C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808048CC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808048D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808048D4: jal         0x80102CF4
    // 0x808048D8: lui         $a1, 0x4370
    ctx->r5 = S32(0X4370 << 16);
    func_80102CF4(rdram, ctx);
        goto after_2;
    // 0x808048D8: lui         $a1, 0x4370
    ctx->r5 = S32(0X4370 << 16);
    after_2:
    // 0x808048DC: bne         $v0, $zero, L_808048F4
    if (ctx->r2 != 0) {
        // 0x808048E0: nop
    
            goto L_808048F4;
    }
    // 0x808048E0: nop

    // 0x808048E4: jal         0x80804AA8
    // 0x808048E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804AA8_chcollballcontrol(rdram, ctx);
        goto after_3;
    // 0x808048E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808048EC: b           L_80804900
    // 0x808048F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80804900;
    // 0x808048F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808048F4:
    // 0x808048F4: jal         0x80804A48
    // 0x808048F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804A48_chcollballcontrol(rdram, ctx);
        goto after_4;
    // 0x808048F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808048FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804900:
    // 0x80804900: jal         0x80102CF4
    // 0x80804904: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102CF4(rdram, ctx);
        goto after_5;
    // 0x80804904: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_5:
    // 0x80804908: bne         $v0, $zero, L_80804924
    if (ctx->r2 != 0) {
        // 0x8080490C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804924;
    }
    // 0x8080490C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804914: jal         0x80102B2C
    // 0x80804918: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102B2C(rdram, ctx);
        goto after_6;
    // 0x80804918: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_6:
    // 0x8080491C: b           L_808049A8
    // 0x80804920: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
        goto L_808049A8;
    // 0x80804920: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_80804924:
    // 0x80804924: jal         0x80102CF4
    // 0x80804928: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102CF4(rdram, ctx);
        goto after_7;
    // 0x80804928: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_7:
    // 0x8080492C: bne         $v0, $zero, L_808049A4
    if (ctx->r2 != 0) {
        // 0x80804930: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808049A4;
    }
    // 0x80804930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804934: jal         0x80102B2C
    // 0x80804938: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B2C(rdram, ctx);
        goto after_8;
    // 0x80804938: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_8:
    // 0x8080493C: b           L_808049A8
    // 0x80804940: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
        goto L_808049A8;
    // 0x80804940: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_80804944:
    // 0x80804944: jal         0x80102CF4
    // 0x80804948: lui         $a1, 0x4200
    ctx->r5 = S32(0X4200 << 16);
    func_80102CF4(rdram, ctx);
        goto after_9;
    // 0x80804948: lui         $a1, 0x4200
    ctx->r5 = S32(0X4200 << 16);
    after_9:
    // 0x8080494C: bne         $v0, $zero, L_80804968
    if (ctx->r2 != 0) {
        // 0x80804950: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804968;
    }
    // 0x80804950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804958: jal         0x80102B2C
    // 0x8080495C: lui         $a1, 0x4200
    ctx->r5 = S32(0X4200 << 16);
    func_80102B2C(rdram, ctx);
        goto after_10;
    // 0x8080495C: lui         $a1, 0x4200
    ctx->r5 = S32(0X4200 << 16);
    after_10:
    // 0x80804960: b           L_808049A8
    // 0x80804964: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
        goto L_808049A8;
    // 0x80804964: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_80804968:
    // 0x80804968: jal         0x80102CF4
    // 0x8080496C: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102CF4(rdram, ctx);
        goto after_11;
    // 0x8080496C: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_11:
    // 0x80804970: bne         $v0, $zero, L_8080498C
    if (ctx->r2 != 0) {
        // 0x80804974: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080498C;
    }
    // 0x80804974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080497C: jal         0x80102B2C
    // 0x80804980: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102B2C(rdram, ctx);
        goto after_12;
    // 0x80804980: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_12:
    // 0x80804984: b           L_808049A8
    // 0x80804988: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
        goto L_808049A8;
    // 0x80804988: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_8080498C:
    // 0x8080498C: jal         0x80102CF4
    // 0x80804990: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102CF4(rdram, ctx);
        goto after_13;
    // 0x80804990: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_13:
    // 0x80804994: bne         $v0, $zero, L_808049A4
    if (ctx->r2 != 0) {
        // 0x80804998: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808049A4;
    }
    // 0x80804998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080499C: jal         0x80102B2C
    // 0x808049A0: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B2C(rdram, ctx);
        goto after_14;
    // 0x808049A0: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_14:
L_808049A4:
    // 0x808049A4: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_808049A8:
    // 0x808049A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808049AC: andi        $t3, $a1, 0x1FF
    ctx->r11 = ctx->r5 & 0X1FF;
    // 0x808049B0: jal         0x80089AF8
    // 0x808049B4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_15;
    // 0x808049B4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_15:
    // 0x808049B8: beq         $v0, $zero, L_808049E8
    if (ctx->r2 == 0) {
        // 0x808049BC: nop
    
            goto L_808049E8;
    }
    // 0x808049BC: nop

    // 0x808049C0: jal         0x80800070
    // 0x808049C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800070_chcollballcontrol(rdram, ctx);
        goto after_16;
    // 0x808049C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808049C8: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808049CC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808049D0: nop

    // 0x808049D4: bc1f        L_808049E8
    if (!c1cs) {
        // 0x808049D8: nop
    
            goto L_808049E8;
    }
    // 0x808049D8: nop

    // 0x808049DC: jal         0x80800070
    // 0x808049E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800070_chcollballcontrol(rdram, ctx);
        goto after_17;
    // 0x808049E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808049E4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_808049E8:
    // 0x808049E8: jal         0x800D8FF8
    // 0x808049EC: nop

    func_800D8FF8(rdram, ctx);
        goto after_18;
    // 0x808049EC: nop

    after_18:
    // 0x808049F0: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808049F4: addiu       $a3, $s0, 0x28
    ctx->r7 = ADD32(ctx->r16, 0X28);
    // 0x808049F8: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808049FC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80804A00: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80804A04: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80804A08: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80804A0C: jal         0x800EFCD8
    // 0x80804A10: nop

    func_800EFCD8(rdram, ctx);
        goto after_19;
    // 0x80804A10: nop

    after_19:
    // 0x80804A14: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80804A18: jal         0x800EF04C
    // 0x80804A1C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_20;
    // 0x80804A1C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_20:
    // 0x80804A20: jal         0x8080405C
    // 0x80804A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080405C_chcollballcontrol(rdram, ctx);
        goto after_21;
    // 0x80804A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80804A28: jal         0x800136E4
    // 0x80804A2C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800136E4(rdram, ctx);
        goto after_22;
    // 0x80804A2C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_22:
    // 0x80804A30: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80804A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804A38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804A3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80804A40: jr          $ra
    // 0x80804A44: nop

    return;
    // 0x80804A44: nop

;}
RECOMP_FUNC void func_80802D9C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802DA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802DA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802DA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802DAC: jal         0x80100094
    // 0x80802DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802DB4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80802DB8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802DBC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802DC0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80802DC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802DC8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80802DCC: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80802DD0: jal         0x80089B00
    // 0x80802DD4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80802DD4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80802DD8: beq         $v0, $zero, L_80802E20
    if (ctx->r2 == 0) {
        // 0x80802DDC: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80802E20;
    }
    // 0x80802DDC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80802DE0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802DE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80802DE8: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80802DEC: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80802DF0: ori         $a0, $a0, 0x4482
    ctx->r4 = ctx->r4 | 0X4482;
    // 0x80802DF4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80802DF8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80802DFC: lui         $a2, 0x1388
    ctx->r6 = S32(0X1388 << 16);
    // 0x80802E00: bc1fl       L_80802E24
    if (!c1cs) {
        // 0x80802E04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802E24;
    }
    goto skip_0;
    // 0x80802E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802E08: jal         0x800C4140
    // 0x80802E0C: ori         $a2, $a2, 0x1F4
    ctx->r6 = ctx->r6 | 0X1F4;
    func_800C4140(rdram, ctx);
        goto after_2;
    // 0x80802E0C: ori         $a2, $a2, 0x1F4
    ctx->r6 = ctx->r6 | 0X1F4;
    after_2:
    // 0x80802E10: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80802E14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802E18: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80802E1C: swc1        $f8, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f8.u32l;
L_80802E20:
    // 0x80802E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802E24:
    // 0x80802E24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802E28: jr          $ra
    // 0x80802E2C: nop

    return;
    // 0x80802E2C: nop

;}
RECOMP_FUNC void func_800E0170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0170: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800E0174: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E0178: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800E017C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800E0180: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800E0184: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800E0188: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800E018C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800E0190: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800E0194: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x800E0198: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800E019C: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800E01A0: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800E01A4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800E01A8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800E01AC: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800E01B0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800E01B4: jal         0x800E0414
    // 0x800E01B8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800E0414(rdram, ctx);
        goto after_0;
    // 0x800E01B8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x800E01BC: beq         $s0, $zero, L_800E01D4
    if (ctx->r16 == 0) {
        // 0x800E01C0: mov.s       $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
            goto L_800E01D4;
    }
    // 0x800E01C0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800E01C4: lh          $t6, 0x2($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X2);
    // 0x800E01C8: lh          $t7, 0x0($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X0);
    // 0x800E01CC: b           L_800E01D8
    // 0x800E01D0: subu        $s6, $t6, $t7
    ctx->r22 = SUB32(ctx->r14, ctx->r15);
        goto L_800E01D8;
    // 0x800E01D0: subu        $s6, $t6, $t7
    ctx->r22 = SUB32(ctx->r14, ctx->r15);
L_800E01D4:
    // 0x800E01D4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_800E01D8:
    // 0x800E01D8: lh          $t8, 0x4($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X4);
    // 0x800E01DC: addiu       $s1, $s5, 0x8
    ctx->r17 = ADD32(ctx->r21, 0X8);
    // 0x800E01E0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800E01E4: blez        $t8, L_800E02B0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800E01E8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800E02B0;
    }
    // 0x800E01E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800E01EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E01F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800E01F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800E01F8: addiu       $s4, $sp, 0x68
    ctx->r20 = ADD32(ctx->r29, 0X68);
L_800E01FC:
    // 0x800E01FC: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800E0200: srl         $v1, $v0, 4
    ctx->r3 = S32(U32(ctx->r2) >> 4);
    // 0x800E0204: beql        $s2, $v1, L_800E0268
    if (ctx->r18 == ctx->r3) {
        // 0x800E0208: andi        $s0, $v0, 0xF
        ctx->r16 = ctx->r2 & 0XF;
            goto L_800E0268;
    }
    goto skip_0;
    // 0x800E0208: andi        $s0, $v0, 0xF
    ctx->r16 = ctx->r2 & 0XF;
    skip_0:
    // 0x800E020C: beq         $s2, $zero, L_800E022C
    if (ctx->r18 == 0) {
        // 0x800E0210: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800E022C;
    }
    // 0x800E0210: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800E0214: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E0218: jal         0x800E084C
    // 0x800E021C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800E084C(rdram, ctx);
        goto after_1;
    // 0x800E021C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x800E0220: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800E0224: srl         $t9, $v1, 4
    ctx->r25 = S32(U32(ctx->r3) >> 4);
    // 0x800E0228: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800E022C:
    // 0x800E022C: swc1        $f20, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f20.u32l;
    // 0x800E0230: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800E0234: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
    // 0x800E0238: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800E023C: swc1        $f20, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f20.u32l;
    // 0x800E0240: lwc1        $f14, 0x88($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800E0244: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800E0248: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x800E024C: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    // 0x800E0250: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x800E0254: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    // 0x800E0258: swc1        $f14, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f14.u32l;
    // 0x800E025C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x800E0260: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800E0264: andi        $s0, $v0, 0xF
    ctx->r16 = ctx->r2 & 0XF;
L_800E0268:
    // 0x800E0268: slti        $at, $s0, 0x9
    ctx->r1 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x800E026C: bne         $at, $zero, L_800E0278
    if (ctx->r1 != 0) {
        // 0x800E0270: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800E0278;
    }
    // 0x800E0270: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E0274: addiu       $s0, $s0, -0x9
    ctx->r16 = ADD32(ctx->r16, -0X9);
L_800E0278:
    // 0x800E0278: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x800E027C: jal         0x800E04C0
    // 0x800E0280: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800E04C0(rdram, ctx);
        goto after_2;
    // 0x800E0280: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x800E0284: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800E0288: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x800E028C: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x800E0290: lh          $t2, 0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2);
    // 0x800E0294: lh          $t4, 0x4($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X4);
    // 0x800E0298: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800E029C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800E02A0: addu        $s1, $s1, $t3
    ctx->r17 = ADD32(ctx->r17, ctx->r11);
    // 0x800E02A4: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800E02A8: bne         $at, $zero, L_800E01FC
    if (ctx->r1 != 0) {
        // 0x800E02AC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800E01FC;
    }
    // 0x800E02AC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800E02B0:
    // 0x800E02B0: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x800E02B4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800E02B8: jal         0x800E084C
    // 0x800E02BC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800E084C(rdram, ctx);
        goto after_3;
    // 0x800E02BC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x800E02C0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800E02C4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800E02C8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800E02CC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800E02D0: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800E02D4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800E02D8: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800E02DC: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800E02E0: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800E02E4: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800E02E8: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x800E02EC: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x800E02F0: jr          $ra
    // 0x800E02F4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800E02F4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_808005CC_chdrips(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005D8: jal         0x80100074
    // 0x808005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x808005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808005E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005E8: jr          $ra
    // 0x808005EC: nop

    return;
    // 0x808005EC: nop

;}
RECOMP_FUNC void func_80800184_bskazow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800188: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080018C: jal         0x8008CABC
    // 0x80800190: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800190: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800194: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800198: jal         0x800832E0
    // 0x8080019C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080019C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808001A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001A4: jal         0x800845D8
    // 0x808001A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808001A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808001AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(264, 0X2C4) << 16);
    // 0x808001B0: lwc1        $f4, 0x2C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(264, 0X2C4));
    // 0x808001B4: lui         $a2, 0x3EF0
    ctx->r6 = S32(0X3EF0 << 16);
    // 0x808001B8: ori         $a2, $a2, 0x3AFB
    ctx->r6 = ctx->r6 | 0X3AFB;
    // 0x808001BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001C0: addiu       $a1, $zero, 0xC9
    ctx->r5 = ADD32(0, 0XC9);
    // 0x808001C4: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x808001C8: jal         0x800845E8
    // 0x808001CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _babounce_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808001CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808001D0: lui         $a1, 0x3E37
    ctx->r5 = S32(0X3E37 << 16);
    // 0x808001D4: ori         $a1, $a1, 0x8034
    ctx->r5 = ctx->r5 | 0X8034;
    // 0x808001D8: jal         0x8008B10C
    // 0x808001DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8008B10C(rdram, ctx);
        goto after_4;
    // 0x808001DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001E8: jr          $ra
    // 0x808001EC: nop

    return;
    // 0x808001EC: nop

;}
RECOMP_FUNC void func_8008FB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FB10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008FB14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008FB18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008FB1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008FB20: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008FB24: jal         0x800F54E4
    // 0x8008FB28: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FB28: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FB2C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8008FB30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FB34: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8008FB38: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8008FB3C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8008FB40: jal         0x800F4EC8
    // 0x8008FB44: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_1;
    // 0x8008FB44: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8008FB48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008FB4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008FB50: jr          $ra
    // 0x8008FB54: nop

    return;
    // 0x8008FB54: nop

;}
RECOMP_FUNC void func_800BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA458: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BA45C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BA460: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800BA464: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800BA468: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800BA46C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800BA470: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x800BA474: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800BA478: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800BA47C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BA480: jal         0x800EFA6C
    // 0x800BA484: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_800EFA6C(rdram, ctx);
        goto after_0;
    // 0x800BA484: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_0:
    // 0x800BA488: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BA48C: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x800BA490: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    // 0x800BA494: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x800BA498: jal         0x800EFA6C
    // 0x800BA49C: addiu       $a0, $a0, 0x3A
    ctx->r4 = ADD32(ctx->r4, 0X3A);
    func_800EFA6C(rdram, ctx);
        goto after_1;
    // 0x800BA49C: addiu       $a0, $a0, 0x3A
    ctx->r4 = ADD32(ctx->r4, 0X3A);
    after_1:
    // 0x800BA4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA4A8: jr          $ra
    // 0x800BA4AC: nop

    return;
    // 0x800BA4AC: nop

;}
RECOMP_FUNC void _chfreezy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F80: syscall     266
    recomp_syscall_handler(rdram, ctx, 0x80085F80);
    return;
    // 0x80085F84: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F8D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8D88: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800F8D8C: addiu       $a2, $a3, 0x10
    ctx->r6 = ADD32(ctx->r7, 0X10);
    // 0x800F8D90: jal         0x80087918
    // 0x800F8D94: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _plcamera_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x800F8D94: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x800F8D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8DA0: jr          $ra
    // 0x800F8DA4: nop

    return;
    // 0x800F8DA4: nop

;}
RECOMP_FUNC void func_800DD1C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD1C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DD1C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD1C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800DD1CC: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800DD1D0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DD1D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800DD1D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800DD1DC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800DD1E0: lh          $t9, 0xA($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XA);
    // 0x800DD1E4: lw          $t8, -0x36A0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X36A0);
    // 0x800DD1E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800DD1EC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800DD1F0: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x800DD1F4: jal         0x8002E330
    // 0x800DD1F8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800DD1F8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800DD1FC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD200: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800DD204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DD208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DD20C: jr          $ra
    // 0x800DD210: nop

    return;
    // 0x800DD210: nop

;}
RECOMP_FUNC void bssplitup_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(364, 0X730) << 16);
    // 0x808005E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005E4: jr          $ra
    // 0x808005E8: lw          $v0, 0x730($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X730));
    return;
    // 0x808005E8: lw          $v0, 0x730($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X730));
;}
RECOMP_FUNC void chstonedartgunhead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BDC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1872, 0XF10) << 16);
    // 0x80800BE0: jr          $ra
    // 0x80800BE4: addiu       $v0, $v0, 0xF10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1872, 0XF10));
    return;
    // 0x80800BE4: addiu       $v0, $v0, 0xF10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1872, 0XF10));
;}
RECOMP_FUNC void func_80800EE0_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800EEC: jal         0x80100094
    // 0x80800EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800EF4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800EF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800EFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800F00: lwc1        $f4, 0x48($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X48);
    // 0x80800F04: sb          $zero, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = 0;
    // 0x80800F08: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80800F0C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800F10: addiu       $at, $zero, 0x19F
    ctx->r1 = ADD32(0, 0X19F);
    // 0x80800F14: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800F18: nop

    // 0x80800F1C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800F20: sh          $t8, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r24;
    // 0x80800F24: lh          $t9, 0x2C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2C);
    // 0x80800F28: sw          $t9, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r25;
    // 0x80800F2C: lwc1        $f8, 0x48($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X48);
    // 0x80800F30: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800F34: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80800F38: nop

    // 0x80800F3C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80800F40: sb          $t2, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r10;
    // 0x80800F44: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80800F48: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F4C: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x80800F50: srl         $t5, $t4, 22
    ctx->r13 = S32(U32(ctx->r12) >> 22);
    // 0x80800F54: bnel        $t5, $at, L_80800F94
    if (ctx->r13 != ctx->r1) {
        // 0x80800F58: swc1        $f0, 0x48($a2)
        MEM_W(0X48, ctx->r6) = ctx->f0.u32l;
            goto L_80800F94;
    }
    goto skip_0;
    // 0x80800F58: swc1        $f0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f0.u32l;
    skip_0:
    // 0x80800F5C: lh          $t7, 0x2C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2C);
    // 0x80800F60: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80800F64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F68: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80800F6C: lwc1        $f8, 0x48($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X48);
    // 0x80800F70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800F74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800F78: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800F7C: jal         0x800136E4
    // 0x80800F80: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80800F80: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    after_1:
    // 0x80800F84: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800F88: b           L_80800F94
    // 0x80800F8C: swc1        $f0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f0.u32l;
        goto L_80800F94;
    // 0x80800F8C: swc1        $f0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f0.u32l;
    // 0x80800F90: swc1        $f0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f0.u32l;
L_80800F94:
    // 0x80800F94: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80800F98: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80800F9C: jal         0x800EE7F8
    // 0x80800FA0: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800FA0: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    after_2:
    // 0x80800FA4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FA8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800FAC: jal         0x800EE7F8
    // 0x80800FB0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800FB0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_3:
    // 0x80800FB4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800FB8: jal         0x800D0B68
    // 0x80800FBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_4;
    // 0x80800FBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800FC0: beq         $v0, $zero, L_80800FD0
    if (ctx->r2 == 0) {
        // 0x80800FC4: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80800FD0;
    }
    // 0x80800FC4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FC8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800FCC: sh          $t8, 0x2C($t9)
    MEM_H(0X2C, ctx->r25) = ctx->r24;
L_80800FD0:
    // 0x80800FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800FD8: jr          $ra
    // 0x80800FDC: nop

    return;
    // 0x80800FDC: nop

;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034A10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80034A14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80034A18: blez        $a1, L_80034A74
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80034A1C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80034A74;
    }
    // 0x80034A1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80034A20: andi        $a3, $a1, 0x3
    ctx->r7 = ctx->r5 & 0X3;
    // 0x80034A24: beq         $a3, $zero, L_80034A48
    if (ctx->r7 == 0) {
        // 0x80034A28: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80034A48;
    }
    // 0x80034A28: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80034A2C:
    // 0x80034A2C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80034A30: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80034A34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80034A38: bne         $a0, $a2, L_80034A2C
    if (ctx->r4 != ctx->r6) {
        // 0x80034A3C: addu        $v1, $v1, $t6
        ctx->r3 = ADD32(ctx->r3, ctx->r14);
            goto L_80034A2C;
    }
    // 0x80034A3C: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80034A40: beql        $a2, $a1, L_80034A78
    if (ctx->r6 == ctx->r5) {
        // 0x80034A44: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80034A78;
    }
    goto skip_0;
    // 0x80034A44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
L_80034A48:
    // 0x80034A48: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80034A4C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80034A50: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x80034A54: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80034A58: lbu         $t0, 0x3($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X3);
    // 0x80034A5C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80034A60: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80034A64: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80034A68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80034A6C: bne         $a2, $a1, L_80034A48
    if (ctx->r6 != ctx->r5) {
        // 0x80034A70: addu        $v1, $v1, $t0
        ctx->r3 = ADD32(ctx->r3, ctx->r8);
            goto L_80034A48;
    }
    // 0x80034A70: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
L_80034A74:
    // 0x80034A74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80034A78:
    // 0x80034A78: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80034A7C: jr          $ra
    // 0x80034A80: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x80034A80: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void func_80801628_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801628: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080162C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801634: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80801638: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080163C: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80801640: bgezl       $t8, L_808016C4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801644: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808016C4;
    }
    goto skip_0;
    // 0x80801644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801648: jal         0x80100094
    // 0x8080164C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080164C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801650: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80801654: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x80801658: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080165C: beq         $t9, $zero, L_80801674
    if (ctx->r25 == 0) {
        // 0x80801660: nop
    
            goto L_80801674;
    }
    // 0x80801660: nop

    // 0x80801664: jal         0x80106790
    // 0x80801668: lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X30);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801668: lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X30);
    after_1:
    // 0x8080166C: b           L_80801674
    // 0x80801670: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80801674;
    // 0x80801670: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80801674:
    // 0x80801674: beq         $s0, $zero, L_80801688
    if (ctx->r16 == 0) {
        // 0x80801678: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801688;
    }
    // 0x80801678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080167C: jal         0x8010A654
    // 0x80801680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A654(rdram, ctx);
        goto after_2;
    // 0x80801680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801684: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80801688:
    // 0x80801688: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080168C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1324, 0X1E2C) << 16);
    // 0x80801690: lwc1        $f6, 0x1E2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1324, 0X1E2C));
    // 0x80801694: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80801698: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080169C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808016A0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808016A4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808016A8: jal         0x80085778
    // 0x808016AC: nop

    _chbadshad_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808016AC: nop

    after_3:
    // 0x808016B0: beq         $s0, $zero, L_808016C0
    if (ctx->r16 == 0) {
        // 0x808016B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808016C0;
    }
    // 0x808016B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016B8: jal         0x8010A654
    // 0x808016BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8010A654(rdram, ctx);
        goto after_4;
    // 0x808016BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
L_808016C0:
    // 0x808016C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808016C4:
    // 0x808016C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808016C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808016CC: jr          $ra
    // 0x808016D0: nop

    return;
    // 0x808016D0: nop

;}
RECOMP_FUNC void bsjig_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800360: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(212, 0X5B0) << 16);
    // 0x80800364: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800368: jr          $ra
    // 0x8080036C: lw          $v0, 0x5B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(212, 0X5B0));
    return;
    // 0x8080036C: lw          $v0, 0x5B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(212, 0X5B0));
;}
RECOMP_FUNC void func_80801D38_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801D44: jal         0x80100094
    // 0x80801D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801D4C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801D50: jal         0x80801C7C
    // 0x80801D54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801C7C_chinflatableboss(rdram, ctx);
        goto after_1;
    // 0x80801D54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80801D58: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801D5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801D60: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    // 0x80801D64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801D68: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80801D6C: jal         0x80108528
    // 0x80801D70: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    func_80108528(rdram, ctx);
        goto after_2;
    // 0x80801D70: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_2:
    // 0x80801D74: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801D7C: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    // 0x80801D80: jal         0x80102FDC
    // 0x80801D84: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x80801D84: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x80801D88: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80801D8C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80801D90: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80801D94: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
    // 0x80801D98: jal         0x80801CB4
    // 0x80801D9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801CB4_chinflatableboss(rdram, ctx);
        goto after_4;
    // 0x80801D9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80801DA0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80801DA4: andi        $t0, $v0, 0x1FF
    ctx->r8 = ctx->r2 & 0X1FF;
    // 0x80801DA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2D98) << 16);
    // 0x80801DAC: lhu         $t1, 0x6E($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X6E);
    // 0x80801DB0: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80801DB4: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80801DB8: sh          $t3, 0x6E($v1)
    MEM_H(0X6E, ctx->r3) = ctx->r11;
    // 0x80801DBC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80801DC0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80801DC4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80801DC8: lwc1        $f4, 0x2D98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(832, 0X2D98));
    // 0x80801DCC: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
    // 0x80801DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801DD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801DD8: jr          $ra
    // 0x80801DDC: nop

    return;
    // 0x80801DDC: nop

;}
RECOMP_FUNC void func_80100B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100B4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80100B50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100B54: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80100B58: jal         0x80100C74
    // 0x80100B5C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80100C74(rdram, ctx);
        goto after_0;
    // 0x80100B5C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80100B60: jal         0x80100C74
    // 0x80100B64: nop

    func_80100C74(rdram, ctx);
        goto after_1;
    // 0x80100B64: nop

    after_1:
    // 0x80100B68: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80100B6C: addiu       $s1, $s1, 0x5A60
    ctx->r17 = ADD32(ctx->r17, 0X5A60);
    // 0x80100B70: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80100B74: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80100B78: beql        $a0, $zero, L_80100BE4
    if (ctx->r4 == 0) {
        // 0x80100B7C: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_80100BE4;
    }
    goto skip_0;
    // 0x80100B7C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80100B80: jal         0x800B3034
    // 0x80100B84: nop

    freelist_capacity(rdram, ctx);
        goto after_2;
    // 0x80100B84: nop

    after_2:
    // 0x80100B88: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80100B8C: bnel        $at, $zero, L_80100BE4
    if (ctx->r1 != 0) {
        // 0x80100B90: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_80100BE4;
    }
    goto skip_1;
    // 0x80100B90: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80100B94: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_80100B98:
    // 0x80100B98: jal         0x800B31B8
    // 0x80100B9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    freelist_is_element_alive(rdram, ctx);
        goto after_3;
    // 0x80100B9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80100BA0: beq         $v0, $zero, L_80100BBC
    if (ctx->r2 == 0) {
        // 0x80100BA4: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80100BBC;
    }
    // 0x80100BA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80100BA8: jal         0x800B301C
    // 0x80100BAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    freelist_at(rdram, ctx);
        goto after_4;
    // 0x80100BAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x80100BB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80100BB4: jal         0x801009C4
    // 0x80100BB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_801009C4(rdram, ctx);
        goto after_5;
    // 0x80100BB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
L_80100BBC:
    // 0x80100BBC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80100BC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80100BC4: beql        $a0, $zero, L_80100BE4
    if (ctx->r4 == 0) {
        // 0x80100BC8: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_80100BE4;
    }
    goto skip_2;
    // 0x80100BC8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x80100BCC: jal         0x800B3034
    // 0x80100BD0: nop

    freelist_capacity(rdram, ctx);
        goto after_6;
    // 0x80100BD0: nop

    after_6:
    // 0x80100BD4: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80100BD8: bnel        $at, $zero, L_80100B98
    if (ctx->r1 != 0) {
        // 0x80100BDC: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_80100B98;
    }
    goto skip_3;
    // 0x80100BDC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x80100BE0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_80100BE4:
    // 0x80100BE4: beql        $a0, $zero, L_80100BFC
    if (ctx->r4 == 0) {
        // 0x80100BE8: lw          $a0, 0x4($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X4);
            goto L_80100BFC;
    }
    goto skip_4;
    // 0x80100BE8: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    skip_4:
    // 0x80100BEC: jal         0x800B3248
    // 0x80100BF0: nop

    freelist_free(rdram, ctx);
        goto after_7;
    // 0x80100BF0: nop

    after_7:
    // 0x80100BF4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80100BF8: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
L_80100BFC:
    // 0x80100BFC: beql        $a0, $zero, L_80100C64
    if (ctx->r4 == 0) {
        // 0x80100C00: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80100C64;
    }
    goto skip_5;
    // 0x80100C00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80100C04: jal         0x800B3034
    // 0x80100C08: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    freelist_capacity(rdram, ctx);
        goto after_8;
    // 0x80100C08: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_8:
    // 0x80100C0C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80100C10: bne         $at, $zero, L_80100C54
    if (ctx->r1 != 0) {
        // 0x80100C14: nop
    
            goto L_80100C54;
    }
    // 0x80100C14: nop

    // 0x80100C18: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
L_80100C1C:
    // 0x80100C1C: jal         0x800B31B8
    // 0x80100C20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    freelist_is_element_alive(rdram, ctx);
        goto after_9;
    // 0x80100C20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80100C24: beq         $v0, $zero, L_80100C3C
    if (ctx->r2 == 0) {
        // 0x80100C28: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80100C3C;
    }
    // 0x80100C28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80100C2C: jal         0x800B301C
    // 0x80100C30: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    freelist_at(rdram, ctx);
        goto after_10;
    // 0x80100C30: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_10:
    // 0x80100C34: jal         0x800887A0
    // 0x80100C38: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    _glpackvtx_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80100C38: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_11:
L_80100C3C:
    // 0x80100C3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80100C40: jal         0x800B3034
    // 0x80100C44: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    freelist_capacity(rdram, ctx);
        goto after_12;
    // 0x80100C44: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_12:
    // 0x80100C48: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80100C4C: bnel        $at, $zero, L_80100C1C
    if (ctx->r1 != 0) {
        // 0x80100C50: lw          $a0, 0x4($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X4);
            goto L_80100C1C;
    }
    goto skip_6;
    // 0x80100C50: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    skip_6:
L_80100C54:
    // 0x80100C54: jal         0x800B3248
    // 0x80100C58: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    freelist_free(rdram, ctx);
        goto after_13;
    // 0x80100C58: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_13:
    // 0x80100C5C: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x80100C60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80100C64:
    // 0x80100C64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80100C68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80100C6C: jr          $ra
    // 0x80100C70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80100C70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800BEB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEB28: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BEB2C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEB30: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEB34: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEB38: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEB3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BEB40: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEB44: jr          $ra
    // 0x800BEB48: lw          $v0, -0x7A44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7A44);
    return;
    // 0x800BEB48: lw          $v0, -0x7A44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7A44);
;}
RECOMP_FUNC void func_80800408_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800408: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080040C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800410: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800418: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080041C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800420: jal         0x80100094
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800428: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: jal         0x800897C8
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800438: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080043C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800440: addiu       $s2, $zero, 0x30
    ctx->r18 = ADD32(0, 0X30);
L_80800444:
    // 0x80800444: lw          $a0, 0x43C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X43C);
    // 0x80800448: beql        $a0, $zero, L_80800460
    if (ctx->r4 == 0) {
        // 0x8080044C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800460;
    }
    goto skip_0;
    // 0x8080044C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x80800450: jal         0x800BA2C4
    // 0x80800454: nop

    func_800BA2C4(rdram, ctx);
        goto after_2;
    // 0x80800454: nop

    after_2:
    // 0x80800458: sw          $v0, 0x43C($s0)
    MEM_W(0X43C, ctx->r16) = ctx->r2;
    // 0x8080045C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80800460:
    // 0x80800460: bne         $s1, $s2, L_80800444
    if (ctx->r17 != ctx->r18) {
        // 0x80800464: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800444;
    }
    // 0x80800464: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800468: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8080046C: lw          $a0, 0x434($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X434);
    // 0x80800470: beql        $a0, $zero, L_8080048C
    if (ctx->r4 == 0) {
        // 0x80800474: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080048C;
    }
    goto skip_1;
    // 0x80800474: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800478: jal         0x800BA2C4
    // 0x8080047C: nop

    func_800BA2C4(rdram, ctx);
        goto after_3;
    // 0x8080047C: nop

    after_3:
    // 0x80800480: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800484: sw          $v0, 0x434($t7)
    MEM_W(0X434, ctx->r15) = ctx->r2;
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080048C:
    // 0x8080048C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800490: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800494: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800498: jr          $ra
    // 0x8080049C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080049C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gcgoto_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x808006E8: addiu       $v0, $v0, 0x75C0
    ctx->r2 = ADD32(ctx->r2, 0X75C0);
    // 0x808006EC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x808006F0: jr          $ra
    // 0x808006F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    return;
    // 0x808006F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
;}
RECOMP_FUNC void func_808001E8_fxrain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E8: jr          $ra
    // 0x808001EC: sw          $a1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r5;
    return;
    // 0x808001EC: sw          $a1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_800C964C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C964C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9658: jal         0x800C91C8
    // 0x800C965C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C91C8(rdram, ctx);
        goto after_0;
    // 0x800C965C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x800C9660: bne         $v0, $zero, L_800C9674
    if (ctx->r2 != 0) {
        // 0x800C9664: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800C9674;
    }
    // 0x800C9664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C9668: jal         0x800C9150
    // 0x800C966C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C9150(rdram, ctx);
        goto after_1;
    // 0x800C966C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x800C9670: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800C9674:
    // 0x800C9674: jal         0x800881E0
    // 0x800C9678: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _gctransitionDll_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x800C9678: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800C967C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9684: jr          $ra
    // 0x800C9688: nop

    return;
    // 0x800C9688: nop

;}
RECOMP_FUNC void _chgameselect_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BD0: syscall     205
    recomp_syscall_handler(rdram, ctx, 0x80085BD0);
    return;
    // 0x80085BD4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _subaddiebounce_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A80: syscall     801
    recomp_syscall_handler(rdram, ctx, 0x80089A80);
    return;
    // 0x80089A84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BF7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF7E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BF7E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BF7E8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BF7EC: addiu       $s0, $s0, -0x7A50
    ctx->r16 = ADD32(ctx->r16, -0X7A50);
    // 0x800BF7F0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x800BF7F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BF7F8: beql        $t6, $zero, L_800BF838
    if (ctx->r14 == 0) {
        // 0x800BF7FC: lw          $t7, 0x34($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X34);
            goto L_800BF838;
    }
    goto skip_0;
    // 0x800BF7FC: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x800BF800: jal         0x800BEB64
    // 0x800BF804: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEB64(rdram, ctx);
        goto after_0;
    // 0x800BF804: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800BF808: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800BF80C: jal         0x800BEBD4
    // 0x800BF810: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEBD4(rdram, ctx);
        goto after_1;
    // 0x800BF810: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800BF814: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800BF818: jal         0x800BEB98
    // 0x800BF81C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEB98(rdram, ctx);
        goto after_2;
    // 0x800BF81C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800BF820: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x800BF824: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800BF828: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800BF82C: jal         0x800890A8
    // 0x800BF830: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    _rtlight_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x800BF830: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x800BF834: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
L_800BF838:
    // 0x800BF838: beql        $t7, $zero, L_800BF878
    if (ctx->r15 == 0) {
        // 0x800BF83C: lw          $a0, 0x1C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X1C);
            goto L_800BF878;
    }
    goto skip_1;
    // 0x800BF83C: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    skip_1:
    // 0x800BF840: jal         0x800BEB64
    // 0x800BF844: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEB64(rdram, ctx);
        goto after_4;
    // 0x800BF844: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800BF848: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800BF84C: jal         0x800BEBD4
    // 0x800BF850: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEBD4(rdram, ctx);
        goto after_5;
    // 0x800BF850: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x800BF854: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800BF858: jal         0x800BEB98
    // 0x800BF85C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEB98(rdram, ctx);
        goto after_6;
    // 0x800BF85C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800BF860: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x800BF864: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800BF868: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800BF86C: jal         0x800890A8
    // 0x800BF870: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    _rtlight_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x800BF870: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_7:
    // 0x800BF874: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
L_800BF878:
    // 0x800BF878: beql        $a0, $zero, L_800BF88C
    if (ctx->r4 == 0) {
        // 0x800BF87C: lw          $a0, 0x48($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X48);
            goto L_800BF88C;
    }
    goto skip_2;
    // 0x800BF87C: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    skip_2:
    // 0x800BF880: jal         0x800890C0
    // 0x800BF884: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    _vpmodule_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x800BF884: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_8:
    // 0x800BF888: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
L_800BF88C:
    // 0x800BF88C: beql        $a0, $zero, L_800BF8A0
    if (ctx->r4 == 0) {
        // 0x800BF890: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800BF8A0;
    }
    goto skip_3;
    // 0x800BF890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800BF894: jal         0x800890C0
    // 0x800BF898: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    _vpmodule_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x800BF898: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    after_9:
    // 0x800BF89C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800BF8A0:
    // 0x800BF8A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BF8A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BF8A8: jr          $ra
    // 0x800BF8AC: nop

    return;
    // 0x800BF8AC: nop

;}
RECOMP_FUNC void func_80800020_bashoes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800028: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x8080002C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800030: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80800034: jal         0x800917A8
    // 0x80800038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bastatetimer_set(rdram, ctx);
        goto after_0;
    // 0x80800038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080003C: jal         0x800EA068
    // 0x80800040: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    func_800EA068(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_1:
    // 0x80800044: beq         $v0, $zero, L_80800070
    if (ctx->r2 == 0) {
        // 0x80800048: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80800070;
    }
    // 0x80800048: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: lw          $t7, 0x10C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X10C);
    // 0x80800050: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800054: lbu         $t8, 0x4($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X4);
    // 0x80800058: bnel        $t8, $at, L_808000C8
    if (ctx->r24 != ctx->r1) {
        // 0x8080005C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000C8;
    }
    goto skip_0;
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800060: jal         0x800FC660
    // 0x80800064: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x80800064: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_2:
    // 0x80800068: b           L_808000C8
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000C8;
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800070:
    // 0x80800070: lw          $t9, 0x10C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X10C);
    // 0x80800074: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800078: lbu         $v0, 0x4($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X4);
    // 0x8080007C: beq         $v0, $at, L_8080009C
    if (ctx->r2 == ctx->r1) {
        // 0x80800080: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080009C;
    }
    // 0x80800080: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800084: beq         $v0, $at, L_808000AC
    if (ctx->r2 == ctx->r1) {
        // 0x80800088: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808000AC;
    }
    // 0x80800088: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080008C: beq         $v0, $at, L_808000BC
    if (ctx->r2 == ctx->r1) {
        // 0x80800090: nop
    
            goto L_808000BC;
    }
    // 0x80800090: nop

    // 0x80800094: b           L_808000C8
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000C8;
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080009C:
    // 0x8080009C: jal         0x800C77DC
    // 0x808000A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800C77DC(rdram, ctx);
        goto after_3;
    // 0x808000A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x808000A4: b           L_808000C8
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000C8;
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000AC:
    // 0x808000AC: jal         0x800C77DC
    // 0x808000B0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800C77DC(rdram, ctx);
        goto after_4;
    // 0x808000B0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_4:
    // 0x808000B4: b           L_808000C8
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000C8;
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000BC:
    // 0x808000BC: jal         0x800C77DC
    // 0x808000C0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800C77DC(rdram, ctx);
        goto after_5;
    // 0x808000C0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C8:
    // 0x808000C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_8009CCFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CCFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CD00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CD04: lw          $v0, 0xF0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CD08: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8009CD0C: lbu         $t6, 0x80($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X80);
    // 0x8009CD10: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8009CD14: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8009CD18: sb          $a1, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r5;
    // 0x8009CD1C: lw          $v0, 0xF0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CD20: lbu         $t9, 0x80($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X80);
    // 0x8009CD24: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8009CD28: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8009CD2C: sb          $zero, 0x1($t1)
    MEM_B(0X1, ctx->r9) = 0;
    // 0x8009CD30: lw          $v0, 0xF0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CD34: lbu         $t2, 0x80($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X80);
    // 0x8009CD38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8009CD3C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8009CD40: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x8009CD44: jal         0x800EFD24
    // 0x8009CD48: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8009CD48: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8009CD4C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8009CD50: lw          $v0, 0xF0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XF0);
    // 0x8009CD54: lbu         $t4, 0x80($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X80);
    // 0x8009CD58: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8009CD5C: sb          $t5, 0x80($v0)
    MEM_B(0X80, ctx->r2) = ctx->r13;
    // 0x8009CD60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CD64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CD68: jr          $ra
    // 0x8009CD6C: nop

    return;
    // 0x8009CD6C: nop

;}
RECOMP_FUNC void func_80800A44_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A44: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800A48: addiu       $at, $zero, 0x43C
    ctx->r1 = ADD32(0, 0X43C);
    // 0x80800A4C: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x80800A50: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80800A54: beq         $t7, $at, L_80800A6C
    if (ctx->r15 == ctx->r1) {
        // 0x80800A58: addiu       $at, $zero, 0x43D
        ctx->r1 = ADD32(0, 0X43D);
            goto L_80800A6C;
    }
    // 0x80800A58: addiu       $at, $zero, 0x43D
    ctx->r1 = ADD32(0, 0X43D);
    // 0x80800A5C: beq         $t7, $at, L_80800A74
    if (ctx->r15 == ctx->r1) {
        // 0x80800A60: addiu       $v0, $zero, 0xAF
        ctx->r2 = ADD32(0, 0XAF);
            goto L_80800A74;
    }
    // 0x80800A60: addiu       $v0, $zero, 0xAF
    ctx->r2 = ADD32(0, 0XAF);
    // 0x80800A64: b           L_80800A7C
    // 0x80800A68: nop

        goto L_80800A7C;
    // 0x80800A68: nop

L_80800A6C:
    // 0x80800A6C: jr          $ra
    // 0x80800A70: addiu       $v0, $zero, 0xB0
    ctx->r2 = ADD32(0, 0XB0);
    return;
    // 0x80800A70: addiu       $v0, $zero, 0xB0
    ctx->r2 = ADD32(0, 0XB0);
L_80800A74:
    // 0x80800A74: jr          $ra
    // 0x80800A78: addiu       $v0, $zero, 0xB1
    ctx->r2 = ADD32(0, 0XB1);
    return;
    // 0x80800A78: addiu       $v0, $zero, 0xB1
    ctx->r2 = ADD32(0, 0XB1);
L_80800A7C:
    // 0x80800A7C: jr          $ra
    // 0x80800A80: nop

    return;
    // 0x80800A80: nop

;}
RECOMP_FUNC void func_808018EC_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018F4: jal         0x8009E6EC
    // 0x808018F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808018F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808018FC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80801900: bne         $v0, $at, L_80801918
    if (ctx->r2 != ctx->r1) {
        // 0x80801904: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801918;
    }
    // 0x80801904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801908: jal         0x80099B94
    // 0x8080190C: nop

    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x8080190C: nop

    after_1:
    // 0x80801910: b           L_80801924
    // 0x80801914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801924;
    // 0x80801914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801918:
    // 0x80801918: jal         0x80099AA8
    // 0x8080191C: nop

    func_80099AA8(rdram, ctx);
        goto after_2;
    // 0x8080191C: nop

    after_2:
    // 0x80801920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801924:
    // 0x80801924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801928: jr          $ra
    // 0x8080192C: nop

    return;
    // 0x8080192C: nop

;}
RECOMP_FUNC void func_80800050_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x8080005C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800060: addiu       $at, $zero, 0x368
    ctx->r1 = ADD32(0, 0X368);
    // 0x80800064: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800068: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x8080006C: bne         $t8, $at, L_8080007C
    if (ctx->r24 != ctx->r1) {
        // 0x80800070: addiu       $a0, $zero, 0xCC
        ctx->r4 = ADD32(0, 0XCC);
            goto L_8080007C;
    }
    // 0x80800070: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    // 0x80800074: b           L_8080007C
    // 0x80800078: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
        goto L_8080007C;
    // 0x80800078: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
L_8080007C:
    // 0x8080007C: jal         0x800DA298
    // 0x80800080: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800080: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800084: beq         $v0, $zero, L_80800094
    if (ctx->r2 == 0) {
        // 0x80800088: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800094;
    }
    // 0x80800088: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: jal         0x800FFAB0
    // 0x80800090: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800090: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
L_80800094:
    // 0x80800094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void func_80018444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001844C: jal         0x800D8FF8
    // 0x80018450: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80018450: nop

    after_0:
    // 0x80018454: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018458: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001845C: addiu       $v1, $v1, -0x4B20
    ctx->r3 = ADD32(ctx->r3, -0X4B20);
    // 0x80018460: addiu       $v0, $v0, -0x4D30
    ctx->r2 = ADD32(ctx->r2, -0X4D30);
    // 0x80018464: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_80018468:
    // 0x80018468: beql        $t6, $zero, L_8001849C
    if (ctx->r14 == 0) {
        // 0x8001846C: lw          $t7, 0x84($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X84);
            goto L_8001849C;
    }
    goto skip_0;
    // 0x8001846C: lw          $t7, 0x84($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X84);
    skip_0:
    // 0x80018470: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80018474: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80018478: add.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8001847C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80018480: nop

    // 0x80018484: bc1fl       L_80018498
    if (!c1cs) {
        // 0x80018488: swc1        $f12, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
            goto L_80018498;
    }
    goto skip_1;
    // 0x80018488: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    skip_1:
    // 0x8001848C: b           L_80018498
    // 0x80018490: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
        goto L_80018498;
    // 0x80018490: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x80018494: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
L_80018498:
    // 0x80018498: lw          $t7, 0x84($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X84);
L_8001849C:
    // 0x8001849C: beql        $t7, $zero, L_800184D0
    if (ctx->r15 == 0) {
        // 0x800184A0: addiu       $v0, $v0, 0x108
        ctx->r2 = ADD32(ctx->r2, 0X108);
            goto L_800184D0;
    }
    goto skip_2;
    // 0x800184A0: addiu       $v0, $v0, 0x108
    ctx->r2 = ADD32(ctx->r2, 0X108);
    skip_2:
    // 0x800184A4: lwc1        $f6, 0x94($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X94);
    // 0x800184A8: lwc1        $f2, 0x90($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X90);
    // 0x800184AC: add.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800184B0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800184B4: nop

    // 0x800184B8: bc1fl       L_800184CC
    if (!c1cs) {
        // 0x800184BC: swc1        $f12, 0x94($v0)
        MEM_W(0X94, ctx->r2) = ctx->f12.u32l;
            goto L_800184CC;
    }
    goto skip_3;
    // 0x800184BC: swc1        $f12, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f12.u32l;
    skip_3:
    // 0x800184C0: b           L_800184CC
    // 0x800184C4: swc1        $f2, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f2.u32l;
        goto L_800184CC;
    // 0x800184C4: swc1        $f2, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f2.u32l;
    // 0x800184C8: swc1        $f12, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f12.u32l;
L_800184CC:
    // 0x800184CC: addiu       $v0, $v0, 0x108
    ctx->r2 = ADD32(ctx->r2, 0X108);
L_800184D0:
    // 0x800184D0: bnel        $v0, $v1, L_80018468
    if (ctx->r2 != ctx->r3) {
        // 0x800184D4: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_80018468;
    }
    goto skip_4;
    // 0x800184D4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_4:
    // 0x800184D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800184DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800184E0: jr          $ra
    // 0x800184E4: nop

    return;
    // 0x800184E4: nop

;}
