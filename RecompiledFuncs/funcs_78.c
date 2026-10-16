#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808002E4_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002EC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x808002F0: jal         0x80088738
    // 0x808002F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _gldialog_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808002F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002F8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808002FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800304: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x80800308: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080030C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800310: beq         $t6, $zero, L_80800348
    if (ctx->r14 == 0) {
        // 0x80800314: nop
    
            goto L_80800348;
    }
    // 0x80800314: nop

    // 0x80800318: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
L_8080031C:
    // 0x8080031C: beq         $v0, $zero, L_8080032C
    if (ctx->r2 == 0) {
        // 0x80800320: addiu       $v1, $zero, 0x7E
        ctx->r3 = ADD32(0, 0X7E);
            goto L_8080032C;
    }
    // 0x80800320: addiu       $v1, $zero, 0x7E
    ctx->r3 = ADD32(0, 0X7E);
    // 0x80800324: b           L_8080032C
    // 0x80800328: addiu       $v1, $zero, 0xAE
    ctx->r3 = ADD32(0, 0XAE);
        goto L_8080032C;
    // 0x80800328: addiu       $v1, $zero, 0xAE
    ctx->r3 = ADD32(0, 0XAE);
L_8080032C:
    // 0x8080032C: bnel        $v1, $a1, L_8080033C
    if (ctx->r3 != ctx->r5) {
        // 0x80800330: lbu         $a1, 0x1($a0)
        ctx->r5 = MEM_BU(ctx->r4, 0X1);
            goto L_8080033C;
    }
    goto skip_0;
    // 0x80800330: lbu         $a1, 0x1($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X1);
    skip_0:
    // 0x80800334: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80800338: lbu         $a1, 0x1($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X1);
L_8080033C:
    // 0x8080033C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800340: bne         $a1, $zero, L_8080031C
    if (ctx->r5 != 0) {
        // 0x80800344: nop
    
            goto L_8080031C;
    }
    // 0x80800344: nop

L_80800348:
    // 0x80800348: jr          $ra
    // 0x8080034C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x8080034C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}
RECOMP_FUNC void func_80801260_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801268: jal         0x80106790
    // 0x8080126C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080126C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801270: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80801274: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80801278: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x8080127C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80801280: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80801284: sw          $t8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r24;
    // 0x80801288: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
    // 0x8080128C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801294: jr          $ra
    // 0x80801298: nop

    return;
    // 0x80801298: nop

;}
RECOMP_FUNC void func_80800020_glsavegame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800024: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800028: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080002C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800030: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800034: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800038: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080003C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80800040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800044:
    // 0x80800044: jal         0x800884A8
    // 0x80800048: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _glgamestore_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800048: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x8080004C: beq         $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x80800050: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800060;
    }
    // 0x80800050: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800054: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80800058: bnel        $s0, $zero, L_80800044
    if (ctx->r16 != 0) {
        // 0x8080005C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800044;
    }
    goto skip_0;
    // 0x8080005C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80800060:
    // 0x80800060: bne         $v0, $zero, L_80800080
    if (ctx->r2 != 0) {
        // 0x80800064: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800080;
    }
    // 0x80800064: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800068: jal         0x80088598
    // 0x8080006C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    _glgamedata_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x8080006C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800070: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800074: bne         $v0, $at, L_80800080
    if (ctx->r2 != ctx->r1) {
        // 0x80800078: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_80800080;
    }
    // 0x80800078: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8080007C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80800080:
    // 0x80800080: bne         $v1, $zero, L_8080009C
    if (ctx->r3 != 0) {
        // 0x80800084: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080009C;
    }
    // 0x80800084: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800088: jal         0x80088590
    // 0x8080008C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    _glgamedata_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080008C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800090: bne         $v0, $zero, L_8080009C
    if (ctx->r2 != 0) {
        // 0x80800094: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_8080009C;
    }
    // 0x80800094: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800098: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8080009C:
    // 0x8080009C: beq         $v1, $zero, L_808000B0
    if (ctx->r3 == 0) {
        // 0x808000A0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808000B0;
    }
    // 0x808000A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000A4: jal         0x800885A0
    // 0x808000A8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    _glgamedata_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808000A8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_3:
    // 0x808000AC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_808000B0:
    // 0x808000B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808000C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000C4: jr          $ra
    // 0x808000C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808000C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808000F0_chjigsawdance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000FC: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800100: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800104: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800108: beql        $t7, $zero, L_80800174
    if (ctx->r15 == 0) {
        // 0x8080010C: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800174;
    }
    goto skip_0;
    // 0x8080010C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800110: jal         0x80101F24
    // 0x80800114: nop

    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x80800114: nop

    after_0:
    // 0x80800118: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(708, 0X440) << 16);
    // 0x8080011C: lwc1        $f4, 0x440($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(708, 0X440));
    // 0x80800120: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80800124: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800128: nop

    // 0x8080012C: bc1f        L_80800154
    if (!c1cs) {
        // 0x80800130: nop
    
            goto L_80800154;
    }
    // 0x80800130: nop

    // 0x80800134: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800138: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x8080013C: jal         0x800C8B84
    // 0x80800140: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x80800140: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x80800144: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800148: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x8080014C: b           L_80800170
    // 0x80800150: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
        goto L_80800170;
    // 0x80800150: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
L_80800154:
    // 0x80800154: jal         0x8008FE94
    // 0x80800158: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8008FE94(rdram, ctx);
        goto after_2;
    // 0x80800158: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x8080015C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800160: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800164: andi        $t1, $a0, 0x1FF
    ctx->r9 = ctx->r4 & 0X1FF;
    // 0x80800168: jal         0x800C8CB8
    // 0x8080016C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_3;
    // 0x8080016C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
L_80800170:
    // 0x80800170: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800174:
    // 0x80800174: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800178: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x8080017C: beq         $t2, $at, L_808002CC
    if (ctx->r10 == ctx->r1) {
        // 0x80800180: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808002CC;
    }
    // 0x80800180: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800184: beq         $t2, $at, L_808001A4
    if (ctx->r10 == ctx->r1) {
        // 0x80800188: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808001A4;
    }
    // 0x80800188: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080018C: beq         $t2, $at, L_8080021C
    if (ctx->r10 == ctx->r1) {
        // 0x80800190: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080021C;
    }
    // 0x80800190: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800194: beq         $t2, $at, L_80800270
    if (ctx->r10 == ctx->r1) {
        // 0x80800198: nop
    
            goto L_80800270;
    }
    // 0x80800198: nop

    // 0x8080019C: b           L_808002D0
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002D0;
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001A4:
    // 0x808001A4: jal         0x8010D254
    // 0x808001A8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_8010D254(rdram, ctx);
        goto after_4;
    // 0x808001A8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808001AC: jal         0x80090010
    // 0x808001B0: nop

    func_80090010(rdram, ctx);
        goto after_5;
    // 0x808001B0: nop

    after_5:
    // 0x808001B4: jal         0x8008FD20
    // 0x808001B8: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    func_8008FD20(rdram, ctx);
        goto after_6;
    // 0x808001B8: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    after_6:
    // 0x808001BC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808001C0: jal         0x80104248
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_7;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001D0: jal         0x8008B1A0
    // 0x808001D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_8;
    // 0x808001D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808001D8: jal         0x8008B264
    // 0x808001DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_getIndex(rdram, ctx);
        goto after_9;
    // 0x808001DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_9:
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x8008AED4
    // 0x808001E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    anctrl_setIndex(rdram, ctx);
        goto after_10;
    // 0x808001E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x808001EC: jal         0x8008B2B4
    // 0x808001F0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_11;
    // 0x808001F0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_11:
    // 0x808001F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001F8: jal         0x8008B24C
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_12;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x8008B1BC
    // 0x80800208: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_13;
    // 0x80800208: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    after_13:
    // 0x8080020C: jal         0x8008B064
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_14;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800214: b           L_808002D0
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002D0;
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080021C:
    // 0x8080021C: jal         0x8008FD20
    // 0x80800220: nop

    func_8008FD20(rdram, ctx);
        goto after_15;
    // 0x80800220: nop

    after_15:
    // 0x80800224: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800228: jal         0x80104248
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_16;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800230: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800234: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800238: jal         0x8008B1A0
    // 0x8080023C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_17;
    // 0x8080023C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800240: jal         0x8008B2B4
    // 0x80800244: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_18;
    // 0x80800244: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_18:
    // 0x80800248: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080024C: jal         0x8008B24C
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_19;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: jal         0x8008B1BC
    // 0x8080025C: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_20;
    // 0x8080025C: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    after_20:
    // 0x80800260: jal         0x8008B064
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_21;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800268: b           L_808002D0
    // 0x8080026C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002D0;
    // 0x8080026C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800270:
    // 0x80800270: jal         0x8010D254
    // 0x80800274: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_8010D254(rdram, ctx);
        goto after_22;
    // 0x80800274: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x80800278: jal         0x80090010
    // 0x8080027C: nop

    func_80090010(rdram, ctx);
        goto after_23;
    // 0x8080027C: nop

    after_23:
    // 0x80800280: jal         0x8008FD20
    // 0x80800284: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    func_8008FD20(rdram, ctx);
        goto after_24;
    // 0x80800284: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    after_24:
    // 0x80800288: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080028C: jal         0x80104248
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_25;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800294: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800298: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080029C: jal         0x8008B1A0
    // 0x808002A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_26;
    // 0x808002A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x808002A4: jal         0x8008B2B4
    // 0x808002A8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_27;
    // 0x808002A8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_27:
    // 0x808002AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002B0: jal         0x8008B24C
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_28;
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: jal         0x8008B1BC
    // 0x808002C0: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_29;
    // 0x808002C0: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    after_29:
    // 0x808002C4: jal         0x8008B064
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_30;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
L_808002CC:
    // 0x808002CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002D0:
    // 0x808002D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_80800150_chfactorylinkgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800154: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080015C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800160: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800164: bne         $a1, $at, L_80800184
    if (ctx->r5 != ctx->r1) {
        // 0x80800168: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800184;
    }
    // 0x80800168: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080016C: addiu       $a0, $zero, 0x3FA
    ctx->r4 = ADD32(0, 0X3FA);
    // 0x80800170: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800178: jal         0x80101180
    // 0x8080017C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x8080017C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800180: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800184:
    // 0x80800184: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800188: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8080018C: jal         0x80085820
    // 0x80800190: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800190: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080019C: jr          $ra
    // 0x808001A0: nop

    return;
    // 0x808001A0: nop

;}
RECOMP_FUNC void func_80800000_chmole_lagoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1780, 0XC0) << 16);
    // 0x8080000C: jal         0x800899E8
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1780, 0XC0));
    _sumole_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1780, 0XC0));
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
RECOMP_FUNC void func_80800770_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800770: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800774: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800778: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080077C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800780: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800784: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80800788: jal         0x8008A1D0
    // 0x8080078C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080078C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800790: beql        $v0, $zero, L_808007F4
    if (ctx->r2 == 0) {
        // 0x80800794: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808007F4;
    }
    goto skip_0;
    // 0x80800794: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800798: jal         0x80090178
    // 0x8080079C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_80090178(rdram, ctx);
        goto after_1;
    // 0x8080079C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_1:
    // 0x808007A0: bne         $v0, $zero, L_808007E8
    if (ctx->r2 != 0) {
        // 0x808007A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007E8;
    }
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A8: jal         0x80086B58
    // 0x808007AC: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808007AC: nop

    after_2:
    // 0x808007B0: jal         0x80800A8C
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A8C_chdumbwaiterlift(rdram, ctx);
        goto after_3;
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808007B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808007BC: addiu       $t6, $zero, 0xA3
    ctx->r14 = ADD32(0, 0XA3);
    // 0x808007C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808007C4: addiu       $a1, $zero, 0x133F
    ctx->r5 = ADD32(0, 0X133F);
    // 0x808007C8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808007CC: jal         0x8008A208
    // 0x808007D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808007D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: jal         0x80101FDC
    // 0x808007DC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x808007DC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x808007E0: b           L_808007F4
    // 0x808007E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808007F4;
    // 0x808007E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007E8:
    // 0x808007E8: jal         0x80101FDC
    // 0x808007EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x808007EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808007F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007F4:
    // 0x808007F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007FC: jr          $ra
    // 0x80800800: nop

    return;
    // 0x80800800: nop

;}
RECOMP_FUNC void _basnowball_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850E8: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x800850E8);
    return;
    // 0x800850EC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808023A4_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_klungo_fade(rdram, ctx, 1)) return;
    // 0x808023A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808023A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808023AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808023B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808023B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808023B8: jal         0x80089C90
    // 0x808023BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808023BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808023C0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808023C4: nop

    // 0x808023C8: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808023CC: jal         0x800D8FF8
    // 0x808023D0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808023D0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x808023D4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808023D8: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x808023DC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808023E0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808023E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808023E8: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x808023EC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x808023F0: nop

    // 0x808023F4: bc1fl       L_80802408
    if (!c1cs) {
        // 0x808023F8: trunc.w.s   $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80802408;
    }
    goto skip_0;
    // 0x808023F8: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_0:
    // 0x808023FC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80802400: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80802404: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
L_80802408:
    // 0x80802408: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080240C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80802410: jal         0x80089C98
    // 0x80802414: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80802414: nop

    after_2:
    // 0x80802418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080241C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80802420: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802424: jr          $ra
    // 0x80802428: nop

    return;
    // 0x80802428: nop

;}
RECOMP_FUNC void _basub_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851A8: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851A8);
    return;
    // 0x800851AC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bashoes_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085008: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085008);
    return;
    // 0x8008500C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_8080078C_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800790: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800794: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080079C: jal         0x800878A0
    // 0x808007A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808007A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x808007A4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808007A8: jal         0x8008E078
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007B0: beql        $v0, $zero, L_808007D0
    if (ctx->r2 == 0) {
        // 0x808007B4: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_808007D0;
    }
    goto skip_0;
    // 0x808007B4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x808007B8: jal         0x8008E35C
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_2;
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808007C0: bne         $v0, $zero, L_808007CC
    if (ctx->r2 != 0) {
        // 0x808007C4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808007CC;
    }
    // 0x808007C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808007C8: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_808007CC:
    // 0x808007CC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_808007D0:
    // 0x808007D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808007D4: beql        $a0, $at, L_8080087C
    if (ctx->r4 == ctx->r1) {
        // 0x808007D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080087C;
    }
    goto skip_1;
    // 0x808007D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808007DC: jal         0x800F5A00
    // 0x808007E0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x808007E0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E8: jal         0x8009C128
    // 0x808007EC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_4;
    // 0x808007EC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x808007F0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808007F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808007F8: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808007FC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800800: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800804: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800808: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080080C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80800810: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80800814: jal         0x800EEB40
    // 0x80800818: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    func_800EEB40(rdram, ctx);
        goto after_5;
    // 0x80800818: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8080081C: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x80800820: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(296, 0X16A8) << 16);
    // 0x80800824: beq         $v0, $zero, L_8080085C
    if (ctx->r2 == 0) {
        // 0x80800828: nop
    
            goto L_8080085C;
    }
    // 0x80800828: nop

    // 0x8080082C: lui         $at, 0x4661
    ctx->r1 = S32(0X4661 << 16);
    // 0x80800830: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800834: nop

    // 0x80800838: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8080083C: nop

    // 0x80800840: bc1fl       L_8080087C
    if (!c1cs) {
        // 0x80800844: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080087C;
    }
    goto skip_2;
    // 0x80800844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800848: beq         $v0, $zero, L_80800854
    if (ctx->r2 == 0) {
        // 0x8080084C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800854;
    }
    // 0x8080084C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800850: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800854:
    // 0x80800854: b           L_80800878
    // 0x80800858: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
        goto L_80800878;
    // 0x80800858: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
L_8080085C:
    // 0x8080085C: lwc1        $f18, 0x16A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(296, 0X16A8));
    // 0x80800860: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800864: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800868: nop

    // 0x8080086C: bc1fl       L_8080087C
    if (!c1cs) {
        // 0x80800870: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080087C;
    }
    goto skip_3;
    // 0x80800870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800874: sw          $t8, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r24;
L_80800878:
    // 0x80800878: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080087C:
    // 0x8080087C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800880: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800884: jr          $ra
    // 0x80800888: nop

    return;
    // 0x80800888: nop

;}
RECOMP_FUNC void func_800FE850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FE854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FE858: jal         0x800DA544
    // 0x800FE85C: addiu       $a0, $zero, 0x674
    ctx->r4 = ADD32(0, 0X674);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x800FE85C: addiu       $a0, $zero, 0x674
    ctx->r4 = ADD32(0, 0X674);
    after_0:
    // 0x800FE860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FE864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FE868: jr          $ra
    // 0x800FE86C: nop

    return;
    // 0x800FE86C: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803210: jr          $ra
    // 0x80803214: lbu         $v0, 0x178($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X178);
    return;
    // 0x80803214: lbu         $v0, 0x178($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X178);
;}
RECOMP_FUNC void func_800ED424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ED428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800ED42C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800ED430: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800ED434: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ED438: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x800ED43C: lwc1        $f6, 0x9C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x800ED440: lwc1        $f2, 0x78($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800ED444: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x800ED448: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED44C: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x800ED450: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x800ED454: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800ED458: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800ED45C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ED460: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800ED464: div.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800ED468: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x800ED46C: lwc1        $f10, 0x8C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x800ED470: lwc1        $f12, 0x7C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x800ED474: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800ED478: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800ED47C: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800ED480: div.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800ED484: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x800ED488: lwc1        $f4, 0x90($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X90);
    // 0x800ED48C: lwc1        $f14, 0x80($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X80);
    // 0x800ED490: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800ED494: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED498: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800ED49C: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800ED4A0: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x800ED4A4: lwc1        $f6, 0x94($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X94);
    // 0x800ED4A8: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800ED4AC: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800ED4B0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800ED4B4: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ED4B8: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800ED4BC: beq         $at, $zero, L_800ED794
    if (ctx->r1 == 0) {
        // 0x800ED4C0: swc1        $f6, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
            goto L_800ED794;
    }
    // 0x800ED4C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
L_800ED4C4:
    // 0x800ED4C4: lbu         $t7, 0xC($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XC);
    // 0x800ED4C8: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800ED4CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ED4D0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800ED4D4: bgez        $t7, L_800ED4E8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800ED4D8: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800ED4E8;
    }
    // 0x800ED4D8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800ED4DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ED4E0: nop

    // 0x800ED4E4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800ED4E8:
    // 0x800ED4E8: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800ED4EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800ED4F0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ED4F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800ED4F8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800ED4FC: nop

    // 0x800ED500: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800ED504: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800ED508: nop

    // 0x800ED50C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800ED510: beql        $t9, $zero, L_800ED560
    if (ctx->r25 == 0) {
        // 0x800ED514: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_800ED560;
    }
    goto skip_0;
    // 0x800ED514: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x800ED518: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ED51C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800ED520: sub.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800ED524: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800ED528: nop

    // 0x800ED52C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800ED530: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800ED534: nop

    // 0x800ED538: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800ED53C: bne         $t9, $zero, L_800ED554
    if (ctx->r25 != 0) {
        // 0x800ED540: nop
    
            goto L_800ED554;
    }
    // 0x800ED540: nop

    // 0x800ED544: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800ED548: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ED54C: b           L_800ED56C
    // 0x800ED550: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800ED56C;
    // 0x800ED550: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800ED554:
    // 0x800ED554: b           L_800ED56C
    // 0x800ED558: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800ED56C;
    // 0x800ED558: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800ED55C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_800ED560:
    // 0x800ED560: nop

    // 0x800ED564: bltz        $t9, L_800ED554
    if (SIGNED(ctx->r25) < 0) {
        // 0x800ED568: nop
    
            goto L_800ED554;
    }
    // 0x800ED568: nop

L_800ED56C:
    // 0x800ED56C: sb          $t9, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r25;
    // 0x800ED570: lbu         $t0, 0xD($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XD);
    // 0x800ED574: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800ED578: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ED57C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800ED580: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ED584: bgez        $t0, L_800ED598
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800ED588: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800ED598;
    }
    // 0x800ED588: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800ED58C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ED590: nop

    // 0x800ED594: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_800ED598:
    // 0x800ED598: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ED59C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ED5A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ED5A4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800ED5A8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800ED5AC: nop

    // 0x800ED5B0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800ED5B4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800ED5B8: nop

    // 0x800ED5BC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800ED5C0: beql        $t2, $zero, L_800ED610
    if (ctx->r10 == 0) {
        // 0x800ED5C4: mfc1        $t2, $f6
        ctx->r10 = (int32_t)ctx->f6.u32l;
            goto L_800ED610;
    }
    goto skip_1;
    // 0x800ED5C4: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x800ED5C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ED5CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ED5D0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ED5D4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800ED5D8: nop

    // 0x800ED5DC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800ED5E0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800ED5E4: nop

    // 0x800ED5E8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800ED5EC: bne         $t2, $zero, L_800ED604
    if (ctx->r10 != 0) {
        // 0x800ED5F0: nop
    
            goto L_800ED604;
    }
    // 0x800ED5F0: nop

    // 0x800ED5F4: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800ED5F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ED5FC: b           L_800ED61C
    // 0x800ED600: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800ED61C;
    // 0x800ED600: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_800ED604:
    // 0x800ED604: b           L_800ED61C
    // 0x800ED608: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800ED61C;
    // 0x800ED608: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800ED60C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
L_800ED610:
    // 0x800ED610: nop

    // 0x800ED614: bltz        $t2, L_800ED604
    if (SIGNED(ctx->r10) < 0) {
        // 0x800ED618: nop
    
            goto L_800ED604;
    }
    // 0x800ED618: nop

L_800ED61C:
    // 0x800ED61C: sb          $t2, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r10;
    // 0x800ED620: lbu         $t3, 0xE($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XE);
    // 0x800ED624: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800ED628: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800ED62C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800ED630: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ED634: bgez        $t3, L_800ED648
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800ED638: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800ED648;
    }
    // 0x800ED638: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800ED63C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ED640: nop

    // 0x800ED644: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800ED648:
    // 0x800ED648: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800ED64C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ED650: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ED654: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800ED658: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800ED65C: nop

    // 0x800ED660: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800ED664: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800ED668: nop

    // 0x800ED66C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800ED670: beql        $t5, $zero, L_800ED6C0
    if (ctx->r13 == 0) {
        // 0x800ED674: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_800ED6C0;
    }
    goto skip_2;
    // 0x800ED674: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x800ED678: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ED67C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ED680: sub.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800ED684: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800ED688: nop

    // 0x800ED68C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800ED690: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800ED694: nop

    // 0x800ED698: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800ED69C: bne         $t5, $zero, L_800ED6B4
    if (ctx->r13 != 0) {
        // 0x800ED6A0: nop
    
            goto L_800ED6B4;
    }
    // 0x800ED6A0: nop

    // 0x800ED6A4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800ED6A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ED6AC: b           L_800ED6CC
    // 0x800ED6B0: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800ED6CC;
    // 0x800ED6B0: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800ED6B4:
    // 0x800ED6B4: b           L_800ED6CC
    // 0x800ED6B8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800ED6CC;
    // 0x800ED6B8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800ED6BC: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_800ED6C0:
    // 0x800ED6C0: nop

    // 0x800ED6C4: bltz        $t5, L_800ED6B4
    if (SIGNED(ctx->r13) < 0) {
        // 0x800ED6C8: nop
    
            goto L_800ED6B4;
    }
    // 0x800ED6C8: nop

L_800ED6CC:
    // 0x800ED6CC: sb          $t5, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r13;
    // 0x800ED6D0: lbu         $t6, 0xF($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF);
    // 0x800ED6D4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800ED6D8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED6DC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800ED6E0: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800ED6E4: bgez        $t6, L_800ED6FC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800ED6E8: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800ED6FC;
    }
    // 0x800ED6E8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800ED6EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ED6F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ED6F4: nop

    // 0x800ED6F8: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_800ED6FC:
    // 0x800ED6FC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ED700: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ED704: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800ED708: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800ED70C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800ED710: nop

    // 0x800ED714: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800ED718: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800ED71C: nop

    // 0x800ED720: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800ED724: beql        $t8, $zero, L_800ED774
    if (ctx->r24 == 0) {
        // 0x800ED728: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_800ED774;
    }
    goto skip_3;
    // 0x800ED728: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800ED72C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ED730: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ED734: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ED738: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800ED73C: nop

    // 0x800ED740: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800ED744: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800ED748: nop

    // 0x800ED74C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800ED750: bne         $t8, $zero, L_800ED768
    if (ctx->r24 != 0) {
        // 0x800ED754: nop
    
            goto L_800ED768;
    }
    // 0x800ED754: nop

    // 0x800ED758: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800ED75C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ED760: b           L_800ED780
    // 0x800ED764: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800ED780;
    // 0x800ED764: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800ED768:
    // 0x800ED768: b           L_800ED780
    // 0x800ED76C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800ED780;
    // 0x800ED76C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800ED770: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_800ED774:
    // 0x800ED774: nop

    // 0x800ED778: bltz        $t8, L_800ED768
    if (SIGNED(ctx->r24) < 0) {
        // 0x800ED77C: nop
    
            goto L_800ED768;
    }
    // 0x800ED77C: nop

L_800ED780:
    // 0x800ED780: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800ED784: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800ED788: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800ED78C: bne         $at, $zero, L_800ED4C4
    if (ctx->r1 != 0) {
        // 0x800ED790: sb          $t8, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r24;
            goto L_800ED4C4;
    }
    // 0x800ED790: sb          $t8, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r24;
L_800ED794:
    // 0x800ED794: jr          $ra
    // 0x800ED798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800ED798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chappearfx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862D8: syscall     303
    recomp_syscall_handler(rdram, ctx, 0x800862D8);
    return;
    // 0x800862DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A9924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9924: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9928: addiu       $v0, $v0, 0x7760
    ctx->r2 = ADD32(ctx->r2, 0X7760);
    // 0x800A992C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x800A9930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A993C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A9940: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800A9944: jal         0x800D3D28
    // 0x800A9948: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    func_800D3D28(rdram, ctx);
        goto after_0;
    // 0x800A9948: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x800A994C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9950: addiu       $v0, $v0, 0x7760
    ctx->r2 = ADD32(ctx->r2, 0X7760);
    // 0x800A9954: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800A9958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A995C: beq         $v1, $at, L_800A996C
    if (ctx->r3 == ctx->r1) {
        // 0x800A9960: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A996C;
    }
    // 0x800A9960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9964: bne         $v1, $at, L_800A9978
    if (ctx->r3 != ctx->r1) {
        // 0x800A9968: nop
    
            goto L_800A9978;
    }
    // 0x800A9968: nop

L_800A996C:
    // 0x800A996C: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x800A9970: jal         0x800886B0
    // 0x800A9974: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    _glrecord_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800A9974: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    after_1:
L_800A9978:
    // 0x800A9978: jal         0x800A9D08
    // 0x800A997C: nop

    func_800A9D08(rdram, ctx);
        goto after_2;
    // 0x800A997C: nop

    after_2:
    // 0x800A9980: jal         0x8001608C
    // 0x800A9984: nop

    func_8001608C(rdram, ctx);
        goto after_3;
    // 0x800A9984: nop

    after_3:
    // 0x800A9988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A998C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9990: jr          $ra
    // 0x800A9994: nop

    return;
    // 0x800A9994: nop

;}
RECOMP_FUNC void fxspgold_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8080000C: jal         0x800B58D4
    // 0x80800010: lbu         $a0, 0x7120($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7120);
    func_800B58D4(rdram, ctx);
        goto after_0;
    // 0x80800010: lbu         $a0, 0x7120($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7120);
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
RECOMP_FUNC void func_800AA0B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA0B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AA0BC: jr          $ra
    // 0x800AA0C0: lbu         $v0, 0x7783($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7783);
    return;
    // 0x800AA0C0: lbu         $v0, 0x7783($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7783);
;}
RECOMP_FUNC void func_8080110C_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080110C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801110: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801114: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801118: jal         0x800D8FF8
    // 0x8080111C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080111C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801120: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801128: nop

    // 0x8080112C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80801130: nop

    // 0x80801134: bc1fl       L_8080114C
    if (!c1cs) {
        // 0x80801138: lw          $a0, 0x6C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X6C);
            goto L_8080114C;
    }
    goto skip_0;
    // 0x80801138: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x8080113C: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80801140: b           L_808012E4
    // 0x80801144: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_808012E4;
    // 0x80801144: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80801148: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
L_8080114C:
    // 0x8080114C: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80801150: jal         0x800DA298
    // 0x80801154: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801154: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80801158: beql        $v0, $zero, L_80801198
    if (ctx->r2 == 0) {
        // 0x8080115C: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80801198;
    }
    goto skip_1;
    // 0x8080115C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x80801160: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801164: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801168: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x8080116C: beq         $t7, $at, L_808011C4
    if (ctx->r15 == ctx->r1) {
        // 0x80801170: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_808011C4;
    }
    // 0x80801170: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80801174: lbu         $t8, 0x72($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X72);
    // 0x80801178: andi        $t9, $t8, 0xFF03
    ctx->r25 = ctx->r24 & 0XFF03;
    // 0x8080117C: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x80801180: sb          $t0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r8;
    // 0x80801184: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801188: srl         $t1, $v0, 10
    ctx->r9 = S32(U32(ctx->r2) >> 10);
    // 0x8080118C: b           L_808011C4
    // 0x80801190: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_808011C4;
    // 0x80801190: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80801194: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80801198:
    // 0x80801198: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080119C: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x808011A0: beq         $t2, $at, L_808011C4
    if (ctx->r10 == ctx->r1) {
        // 0x808011A4: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_808011C4;
    }
    // 0x808011A4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x808011A8: lbu         $t3, 0x72($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X72);
    // 0x808011AC: andi        $t4, $t3, 0xFF03
    ctx->r12 = ctx->r11 & 0XFF03;
    // 0x808011B0: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x808011B4: sb          $t5, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r13;
    // 0x808011B8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808011BC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808011C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_808011C4:
    // 0x808011C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808011C8: beq         $v0, $at, L_808011E0
    if (ctx->r2 == ctx->r1) {
        // 0x808011CC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808011E0;
    }
    // 0x808011CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808011D0: beq         $v0, $at, L_80801224
    if (ctx->r2 == ctx->r1) {
        // 0x808011D4: nop
    
            goto L_80801224;
    }
    // 0x808011D4: nop

    // 0x808011D8: b           L_80801260
    // 0x808011DC: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
        goto L_80801260;
    // 0x808011DC: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
L_808011E0:
    // 0x808011E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1544) << 16);
    // 0x808011E4: lwc1        $f8, 0x1544($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1544));
    // 0x808011E8: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808011EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1548) << 16);
    // 0x808011F0: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x808011F4: nop

    // 0x808011F8: bc1fl       L_80801214
    if (!c1cs) {
        // 0x808011FC: lbu         $t7, 0x72($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X72);
            goto L_80801214;
    }
    goto skip_2;
    // 0x808011FC: lbu         $t7, 0x72($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X72);
    skip_2:
    // 0x80801200: lwc1        $f10, 0x1548($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1548));
    // 0x80801204: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80801208: b           L_8080125C
    // 0x8080120C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
        goto L_8080125C;
    // 0x8080120C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x80801210: lbu         $t7, 0x72($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X72);
L_80801214:
    // 0x80801214: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x80801218: ori         $t9, $t8, 0xC
    ctx->r25 = ctx->r24 | 0XC;
    // 0x8080121C: b           L_8080125C
    // 0x80801220: sb          $t9, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r25;
        goto L_8080125C;
    // 0x80801220: sb          $t9, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r25;
L_80801224:
    // 0x80801224: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X154C) << 16);
    // 0x80801228: lwc1        $f2, 0x154C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X154C));
    // 0x8080122C: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80801230: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80801234: nop

    // 0x80801238: bc1fl       L_80801250
    if (!c1cs) {
        // 0x8080123C: lbu         $t0, 0x72($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X72);
            goto L_80801250;
    }
    goto skip_3;
    // 0x8080123C: lbu         $t0, 0x72($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X72);
    skip_3:
    // 0x80801240: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80801244: b           L_8080125C
    // 0x80801248: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
        goto L_8080125C;
    // 0x80801248: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    // 0x8080124C: lbu         $t0, 0x72($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X72);
L_80801250:
    // 0x80801250: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x80801254: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x80801258: sb          $t2, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r10;
L_8080125C:
    // 0x8080125C: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
L_80801260:
    // 0x80801260: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80801264: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80801268: nop

    // 0x8080126C: bc1tl       L_808012E8
    if (c1cs) {
        // 0x80801270: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808012E8;
    }
    goto skip_4;
    // 0x80801270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80801274: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80801278: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8080127C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801280: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80801284: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80801288: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8080128C: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80801290: jal         0x8080105C
    // 0x80801294: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    func_8080105C_chfiregen(rdram, ctx);
        goto after_2;
    // 0x80801294: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80801298: beq         $v0, $zero, L_808012B0
    if (ctx->r2 == 0) {
        // 0x8080129C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808012B0;
    }
    // 0x8080129C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808012A4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808012A8: jal         0x800EDDDC
    // 0x808012AC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    func_800EDDDC(rdram, ctx);
        goto after_3;
    // 0x808012AC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_3:
L_808012B0:
    // 0x808012B0: jal         0x808010B4
    // 0x808012B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808010B4_chfiregen(rdram, ctx);
        goto after_4;
    // 0x808012B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808012B8: beq         $v0, $zero, L_808012D0
    if (ctx->r2 == 0) {
        // 0x808012BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808012D0;
    }
    // 0x808012BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012C0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x808012C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808012C8: jal         0x800EDDDC
    // 0x808012CC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    func_800EDDDC(rdram, ctx);
        goto after_5;
    // 0x808012CC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_5:
L_808012D0:
    // 0x808012D0: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808012D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1550) << 16);
    // 0x808012D8: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x808012DC: lwc1        $f18, 0x1550($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1550));
    // 0x808012E0: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_808012E4:
    // 0x808012E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808012E8:
    // 0x808012E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808012EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808012F0: jr          $ra
    // 0x808012F4: nop

    return;
    // 0x808012F4: nop

;}
RECOMP_FUNC void func_8080070C_chbadbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080070C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800710: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800714: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800718: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080071C: beq         $a1, $at, L_8080084C
    if (ctx->r5 == ctx->r1) {
        // 0x80800720: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_8080084C;
    }
    // 0x80800720: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800724: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800728: beq         $a1, $at, L_80800860
    if (ctx->r5 == ctx->r1) {
        // 0x8080072C: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_80800860;
    }
    // 0x8080072C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800730: beq         $a1, $at, L_808008A4
    if (ctx->r5 == ctx->r1) {
        // 0x80800734: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_808008A4;
    }
    // 0x80800734: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80800738: beq         $a1, $at, L_808008C0
    if (ctx->r5 == ctx->r1) {
        // 0x8080073C: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1760, 0XABC) << 16);
            goto L_808008C0;
    }
    // 0x8080073C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1760, 0XABC) << 16);
    // 0x80800740: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800744: beq         $a1, $at, L_80800778
    if (ctx->r5 == ctx->r1) {
        // 0x80800748: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_80800778;
    }
    // 0x80800748: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8080074C: beq         $a1, $at, L_808007A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800750: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808007A8;
    }
    // 0x80800750: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800754: bne         $a1, $at, L_808008D0
    if (ctx->r5 != ctx->r1) {
        // 0x80800758: nop
    
            goto L_808008D0;
    }
    // 0x80800758: nop

    // 0x8080075C: jal         0x800C2E04
    // 0x80800760: nop

    func_800C2E04(rdram, ctx);
        goto after_0;
    // 0x80800760: nop

    after_0:
    // 0x80800764: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x80800768: jal         0x80089F60
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800770: b           L_808008DC
    // 0x80800774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x80800774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800778:
    // 0x80800778: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x8080077C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800780: jal         0x800EE88C
    // 0x80800784: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80800784: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800788: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800790: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800794: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80800798: jal         0x80086670
    // 0x8080079C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080079C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808007A0: b           L_808008DC
    // 0x808007A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x808007A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007A8:
    // 0x808007A8: jal         0x80101080
    // 0x808007AC: nop

    func_80101080(rdram, ctx);
        goto after_4;
    // 0x808007AC: nop

    after_4:
    // 0x808007B0: jal         0x80106790
    // 0x808007B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x808007B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808007B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808007BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1760, 0XAFC) << 16);
    // 0x808007C0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808007C4: addiu       $a2, $a2, 0xAFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1760, 0XAFC));
    // 0x808007C8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x808007CC: jal         0x80089D18
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808007D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1760, 0XB0C) << 16);
    // 0x808007D8: addiu       $a2, $a2, 0xB0C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1760, 0XB0C));
    // 0x808007DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E0: jal         0x80089D18
    // 0x808007E4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x808007E4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x808007E8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1760, 0XBE4) << 16);
    // 0x808007EC: addiu       $t6, $t6, 0xBE4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1760, 0XBE4));
    // 0x808007F0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808007F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808007F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800800: jal         0x800BBCB8
    // 0x80800804: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_8;
    // 0x80800804: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080080C: jal         0x80107070
    // 0x80800810: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_9;
    // 0x80800810: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800814: bnel        $v0, $zero, L_80800828
    if (ctx->r2 != 0) {
        // 0x80800818: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800828;
    }
    goto skip_0;
    // 0x80800818: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x8080081C: jal         0x800FFAB0
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800824: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80800828:
    // 0x80800828: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080082C: jal         0x800866D0
    // 0x80800830: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_11;
    // 0x80800830: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
    // 0x80800834: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800838: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080083C: jal         0x800866A0
    // 0x80800840: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80800840: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_12:
    // 0x80800844: b           L_808008DC
    // 0x80800848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x80800848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080084C:
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800850: jal         0x808008F8
    // 0x80800854: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808008F8_chbadbeehive(rdram, ctx);
        goto after_13;
    // 0x80800854: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80800858: b           L_808008DC
    // 0x8080085C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x8080085C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800860:
    // 0x80800860: jal         0x8008A4A8
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800868: bne         $v0, $zero, L_80800894
    if (ctx->r2 != 0) {
        // 0x8080086C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800894;
    }
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: jal         0x80107070
    // 0x80800878: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_15;
    // 0x80800878: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x8080087C: bnel        $v0, $zero, L_808008DC
    if (ctx->r2 != 0) {
        // 0x80800880: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808008DC;
    }
    goto skip_1;
    // 0x80800880: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800884: jal         0x80089CA8
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080088C: b           L_808008DC
    // 0x80800890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x80800890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800894:
    // 0x80800894: jal         0x808008F8
    // 0x80800898: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808008F8_chbadbeehive(rdram, ctx);
        goto after_17;
    // 0x80800898: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x8080089C: b           L_808008DC
    // 0x808008A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x808008A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008A4:
    // 0x808008A4: jal         0x801015D0
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_18;
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808008AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808008B0: jal         0x800DF744
    // 0x808008B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_19;
    // 0x808008B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_19:
    // 0x808008B8: b           L_808008DC
    // 0x808008BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x808008BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008C0:
    // 0x808008C0: jal         0x80101074
    // 0x808008C4: addiu       $a0, $a0, 0xABC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1760, 0XABC));
    func_80101074(rdram, ctx);
        goto after_20;
    // 0x808008C4: addiu       $a0, $a0, 0xABC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1760, 0XABC));
    after_20:
    // 0x808008C8: b           L_808008DC
    // 0x808008CC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808008DC;
    // 0x808008CC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808008D0:
    // 0x808008D0: b           L_808008DC
    // 0x808008D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008DC;
    // 0x808008D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008DC:
    // 0x808008DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808008E8: jr          $ra
    // 0x808008EC: nop

    return;
    // 0x808008EC: nop

;}
RECOMP_FUNC void _ncbadie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089288: syscall     769
    recomp_syscall_handler(rdram, ctx, 0x80089288);
    return;
    // 0x8008928C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8009DC98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DC98: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009DC9C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8009DCA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009DCA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DCA8: addiu       $t6, $zero, 0x55F0
    ctx->r14 = ADD32(0, 0X55F0);
    // 0x8009DCAC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8009DCB0: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8009DCB4: jal         0x8009DBB0
    // 0x8009DCB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_8009DBB0(rdram, ctx);
        goto after_0;
    // 0x8009DCB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8009DCBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DCC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009DCC4: jr          $ra
    // 0x8009DCC8: nop

    return;
    // 0x8009DCC8: nop

;}
RECOMP_FUNC void _ncpodfixpos_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089698: syscall     786
    recomp_syscall_handler(rdram, ctx, 0x80089698);
    return;
    // 0x8008969C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800C98_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C98: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800C9C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800CA0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800CA4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CAC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80800CB0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800CB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CB8: jal         0x800EE7F8
    // 0x80800CBC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800CBC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80800CC0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CC4: jal         0x800EE7F8
    // 0x80800CC8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800CC8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80800CCC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800CD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800CD4: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800CD8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800CDC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800CE0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800CE4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800CE8: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80800CEC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800CF0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80800CF4: jal         0x8010A624
    // 0x80800CF8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    func_8010A624(rdram, ctx);
        goto after_2;
    // 0x80800CF8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80800CFC: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80800D00: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80800D04: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800D08: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800D0C: jal         0x800C6A7C
    // 0x80800D10: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800C6A7C(rdram, ctx);
        goto after_3;
    // 0x80800D10: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80800D14: beq         $v0, $zero, L_80800D24
    if (ctx->r2 == 0) {
        // 0x80800D18: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800D24;
    }
    // 0x80800D18: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800D1C: b           L_80800D28
    // 0x80800D20: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800D28;
    // 0x80800D20: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800D24:
    // 0x80800D24: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800D28:
    // 0x80800D28: jal         0x8010A63C
    // 0x80800D2C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8010A63C(rdram, ctx);
        goto after_4;
    // 0x80800D2C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_4:
    // 0x80800D30: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800D34: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800D38: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800D3C: beql        $v1, $zero, L_80800D4C
    if (ctx->r3 == 0) {
        // 0x80800D40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800D4C;
    }
    goto skip_0;
    // 0x80800D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800D44: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80800D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D4C:
    // 0x80800D4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800D50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800D54: jr          $ra
    // 0x80800D58: nop

    return;
    // 0x80800D58: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808017DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2E90) << 16);
    // 0x808017E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808017E4: jr          $ra
    // 0x808017E8: lw          $v0, 0x2E90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2E90));
    return;
    // 0x808017E8: lw          $v0, 0x2E90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2E90));
;}
RECOMP_FUNC void func_80802E38_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802E38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802E3C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80802E40: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80802E44: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80802E48: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80802E4C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80802E50: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80802E54: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80802E58: jal         0x80106790
    // 0x80802E5C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802E5C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802E60: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80802E64: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80802E68: addiu       $a2, $a2, 0x7DB0
    ctx->r6 = ADD32(ctx->r6, 0X7DB0);
    // 0x80802E6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802E70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802E74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802E78: jal         0x80087CB8
    // 0x80802E7C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80802E7C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_1:
    // 0x80802E80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802E84: jal         0x80100094
    // 0x80802E88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80802E88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80802E8C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802E90: jal         0x80087DB8
    // 0x80802E94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_36(rdram, ctx);
        goto after_3;
    // 0x80802E94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80802E98: bgtzl       $s0, L_80802EA8
    if (SIGNED(ctx->r16) > 0) {
        // 0x80802E9C: lw          $v0, 0x2C($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X2C);
            goto L_80802EA8;
    }
    goto skip_0;
    // 0x80802E9C: lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X2C);
    skip_0:
    // 0x80802EA0: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80802EA4: lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X2C);
L_80802EA8:
    // 0x80802EA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802EAC: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80802EB0: beq         $at, $zero, L_80802EC0
    if (ctx->r1 == 0) {
        // 0x80802EB4: nop
    
            goto L_80802EC0;
    }
    // 0x80802EB4: nop

    // 0x80802EB8: b           L_80802EC0
    // 0x80802EBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80802EC0;
    // 0x80802EBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80802EC0:
    // 0x80802EC0: jal         0x80087CD8
    // 0x80802EC4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80802EC4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x80802EC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802ECC: jal         0x80087CE0
    // 0x80802ED0: lw          $a1, 0x2C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X2C);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80802ED0: lw          $a1, 0x2C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X2C);
    after_5:
    // 0x80802ED4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802ED8: jal         0x80087CE8
    // 0x80802EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80802EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80802EE0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80802EE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802EE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802EEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802EF0: jal         0x80100094
    // 0x80802EF4: sw          $t6, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r14;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80802EF4: sw          $t6, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r14;
    after_7:
    // 0x80802EF8: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x80802EFC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80802F00: blez        $t7, L_80802F2C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80802F04: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80802F2C;
    }
    // 0x80802F04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80802F08:
    // 0x80802F08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802F0C: jal         0x80087D90
    // 0x80802F10: lh          $a2, 0x4($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X4);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_8;
    // 0x80802F10: lh          $a2, 0x4($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X4);
    after_8:
    // 0x80802F14: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x80802F18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802F1C: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x80802F20: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80802F24: bnel        $at, $zero, L_80802F08
    if (ctx->r1 != 0) {
        // 0x80802F28: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80802F08;
    }
    goto skip_1;
    // 0x80802F28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_1:
L_80802F2C:
    // 0x80802F2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CC8) << 16);
    // 0x80802F30: lwc1        $f4, 0x7CC8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CC8));
    // 0x80802F34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802F38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802F3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802F40: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x80802F44: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80802F48: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80802F4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80802F50: jal         0x80087DD8
    // 0x80802F54: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_9;
    // 0x80802F54: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80802F58: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80802F5C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802F60: jal         0x80087DE8
    // 0x80802F64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_42(rdram, ctx);
        goto after_10;
    // 0x80802F64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x80802F68: jal         0x80087CF0
    // 0x80802F6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80802F6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x80802F70: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80802F74: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80802F78: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80802F7C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80802F80: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80802F84: jr          $ra
    // 0x80802F88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80802F88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bstaxi_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808012F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(392, 0X21B8) << 16);
    // 0x808012F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808012F8: jr          $ra
    // 0x808012FC: lw          $v0, 0x21B8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21B8));
    return;
    // 0x808012FC: lw          $v0, 0x21B8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X21B8));
;}
RECOMP_FUNC void _chpawnbroker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085EF0: syscall     258
    recomp_syscall_handler(rdram, ctx, 0x80085EF0);
    return;
    // 0x80085EF4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80802248_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802248: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080224C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802250: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802254: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80802258: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8080225C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802260: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80802264: bgezl       $t8, L_80802298
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80802268: lw          $t1, 0x18($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X18);
            goto L_80802298;
    }
    goto skip_0;
    // 0x80802268: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x8080226C: lbu         $v1, 0x79($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X79);
    // 0x80802270: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802274: srl         $t9, $v1, 4
    ctx->r25 = S32(U32(ctx->r3) >> 4);
    // 0x80802278: beq         $t9, $zero, L_8080228C
    if (ctx->r25 == 0) {
        // 0x8080227C: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_8080228C;
    }
    // 0x8080227C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80802280: beq         $t9, $at, L_8080228C
    if (ctx->r25 == ctx->r1) {
        // 0x80802284: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080228C;
    }
    // 0x80802284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802288: bne         $t9, $at, L_80802294
    if (ctx->r25 != ctx->r1) {
        // 0x8080228C: addiu       $t0, $v1, 0x1
        ctx->r8 = ADD32(ctx->r3, 0X1);
            goto L_80802294;
    }
L_8080228C:
    // 0x8080228C: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x80802290: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_80802294:
    // 0x80802294: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
L_80802298:
    // 0x80802298: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8080229C: beq         $t1, $zero, L_808022CC
    if (ctx->r9 == 0) {
        // 0x808022A0: nop
    
            goto L_808022CC;
    }
    // 0x808022A0: nop

    // 0x808022A4: jal         0x80087B70
    // 0x808022A8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_18(rdram, ctx);
        goto after_0;
    // 0x808022A8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_0:
    // 0x808022AC: jal         0x80087B60
    // 0x808022B0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x808022B0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_1:
    // 0x808022B4: jal         0x80087B28
    // 0x808022B8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808022B8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_2:
    // 0x808022BC: jal         0x80087B38
    // 0x808022C0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808022C0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_3:
    // 0x808022C4: b           L_80802460
    // 0x808022C8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
        goto L_80802460;
    // 0x808022C8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
L_808022CC:
    // 0x808022CC: beq         $t2, $zero, L_8080243C
    if (ctx->r10 == 0) {
        // 0x808022D0: nop
    
            goto L_8080243C;
    }
    // 0x808022D0: nop

    // 0x808022D4: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x808022D8: beql        $t2, $t3, L_80802460
    if (ctx->r10 == ctx->r11) {
        // 0x808022DC: lw          $t6, 0x3C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X3C);
            goto L_80802460;
    }
    goto skip_1;
    // 0x808022DC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x808022E0: jal         0x80087B70
    // 0x808022E4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_18(rdram, ctx);
        goto after_4;
    // 0x808022E4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_4:
    // 0x808022E8: jal         0x80087B60
    // 0x808022EC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_16(rdram, ctx);
        goto after_5;
    // 0x808022EC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_5:
    // 0x808022F0: jal         0x80087B28
    // 0x808022F4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x808022F4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_6:
    // 0x808022F8: jal         0x80087B38
    // 0x808022FC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808022FC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_7:
    // 0x80802300: jal         0x800E73D4
    // 0x80802304: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800E73D4(rdram, ctx);
        goto after_8;
    // 0x80802304: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_8:
    // 0x80802308: jal         0x800E73D4
    // 0x8080230C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800E73D4(rdram, ctx);
        goto after_9;
    // 0x8080230C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_9:
    // 0x80802310: lbu         $t4, 0x79($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X79);
    // 0x80802314: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80802318: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8080231C: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x80802320: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80802324: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80802328: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x8080232C: srl         $t7, $a0, 4
    ctx->r15 = S32(U32(ctx->r4) >> 4);
    // 0x80802330: jal         0x80803738
    // 0x80802334: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80803738_chgameselect(rdram, ctx);
        goto after_10;
    // 0x80802334: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_10:
    // 0x80802338: beq         $v0, $zero, L_808023CC
    if (ctx->r2 == 0) {
        // 0x8080233C: addiu       $a1, $zero, 0x18F3
        ctx->r5 = ADD32(0, 0X18F3);
            goto L_808023CC;
    }
    // 0x8080233C: addiu       $a1, $zero, 0x18F3
    ctx->r5 = ADD32(0, 0X18F3);
    // 0x80802340: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80802344: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80802348: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080234C: addiu       $a1, $zero, 0x18F3
    ctx->r5 = ADD32(0, 0X18F3);
    // 0x80802350: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80802354: jal         0x80803E94
    // 0x80802358: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80803E94_chgameselect(rdram, ctx);
        goto after_11;
    // 0x80802358: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x8080235C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80802360: jal         0x800DB8BC
    // 0x80802364: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800DB8BC(rdram, ctx);
        goto after_12;
    // 0x80802364: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_12:
    // 0x80802368: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8080236C: jal         0x800E6A58
    // 0x80802370: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_800E6A58(rdram, ctx);
        goto after_13;
    // 0x80802370: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_13:
    // 0x80802374: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80802378: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080237C: addiu       $a1, $zero, 0x18F3
    ctx->r5 = ADD32(0, 0X18F3);
    // 0x80802380: bne         $v0, $at, L_808023AC
    if (ctx->r2 != ctx->r1) {
        // 0x80802384: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_808023AC;
    }
    // 0x80802384: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80802388: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8080238C: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x80802390: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802394: addiu       $a1, $zero, 0x18F3
    ctx->r5 = ADD32(0, 0X18F3);
    // 0x80802398: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080239C: jal         0x80803E94
    // 0x808023A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80803E94_chgameselect(rdram, ctx);
        goto after_14;
    // 0x808023A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x808023A4: b           L_808023E4
    // 0x808023A8: nop

        goto L_808023E4;
    // 0x808023A8: nop

L_808023AC:
    // 0x808023AC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x808023B0: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x808023B4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808023B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808023BC: jal         0x80803E94
    // 0x808023C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80803E94_chgameselect(rdram, ctx);
        goto after_15;
    // 0x808023C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x808023C4: b           L_808023E4
    // 0x808023C8: nop

        goto L_808023E4;
    // 0x808023C8: nop

L_808023CC:
    // 0x808023CC: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x808023D0: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x808023D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808023D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808023DC: jal         0x80803E94
    // 0x808023E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80803E94_chgameselect(rdram, ctx);
        goto after_16;
    // 0x808023E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_16:
L_808023E4:
    // 0x808023E4: jal         0x80087BE0
    // 0x808023E8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_32(rdram, ctx);
        goto after_17;
    // 0x808023E8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_17:
    // 0x808023EC: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x808023F0: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x808023F4: beql        $t3, $zero, L_8080242C
    if (ctx->r11 == 0) {
        // 0x808023F8: lw          $a0, 0x28($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X28);
            goto L_8080242C;
    }
    goto skip_2;
    // 0x808023F8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    skip_2:
    // 0x808023FC: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80802400: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(804, 0X8558) << 16);
    // 0x80802404: addiu       $a2, $a2, -0x7AA8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(804, 0X8558));
    // 0x80802408: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8080240C: lw          $t5, 0x34($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X34);
    // 0x80802410: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80802414: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x80802418: jal         0x80087B18
    // 0x8080241C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_7(rdram, ctx);
        goto after_18;
    // 0x8080241C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_18:
    // 0x80802420: b           L_80802460
    // 0x80802424: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
        goto L_80802460;
    // 0x80802424: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80802428: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
L_8080242C:
    // 0x8080242C: jal         0x80087B20
    // 0x80802430: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_19;
    // 0x80802430: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    after_19:
    // 0x80802434: b           L_80802460
    // 0x80802438: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
        goto L_80802460;
    // 0x80802438: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
L_8080243C:
    // 0x8080243C: jal         0x80087B58
    // 0x80802440: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_15(rdram, ctx);
        goto after_20;
    // 0x80802440: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_20:
    // 0x80802444: jal         0x80087B68
    // 0x80802448: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_17(rdram, ctx);
        goto after_21;
    // 0x80802448: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_21:
    // 0x8080244C: jal         0x80087B40
    // 0x80802450: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_22;
    // 0x80802450: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_22:
    // 0x80802454: jal         0x80087B30
    // 0x80802458: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_23;
    // 0x80802458: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_23:
    // 0x8080245C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
L_80802460:
    // 0x80802460: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80802464: jal         0x80087B00
    // 0x80802468: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    _gczoombox_entrypoint_4(rdram, ctx);
        goto after_24;
    // 0x80802468: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    after_24:
    // 0x8080246C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802470: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802474: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802478: jr          $ra
    // 0x8080247C: nop

    return;
    // 0x8080247C: nop

;}
RECOMP_FUNC void func_800FC1A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC1A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC1AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC1B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FC1B4: jal         0x800FB774
    // 0x800FC1B8: addiu       $a0, $a0, 0x5960
    ctx->r4 = ADD32(ctx->r4, 0X5960);
    func_800FB774(rdram, ctx);
        goto after_0;
    // 0x800FC1B8: addiu       $a0, $a0, 0x5960
    ctx->r4 = ADD32(ctx->r4, 0X5960);
    after_0:
    // 0x800FC1BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC1C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC1C4: jr          $ra
    // 0x800FC1C8: nop

    return;
    // 0x800FC1C8: nop

;}
RECOMP_FUNC void func_800FE6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE6F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FE6FC: bne         $a0, $zero, L_800FE720
    if (ctx->r4 != 0) {
        // 0x800FE700: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800FE720;
    }
    // 0x800FE700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FE704: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FE708: lbu         $t6, 0x59D6($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X59D6);
    // 0x800FE70C: beql        $t6, $zero, L_800FE724
    if (ctx->r14 == 0) {
        // 0x800FE710: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FE724;
    }
    goto skip_0;
    // 0x800FE710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FE714: jal         0x800FE4E4
    // 0x800FE718: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800FE4E4(rdram, ctx);
        goto after_0;
    // 0x800FE718: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800FE71C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_800FE720:
    // 0x800FE720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FE724:
    // 0x800FE724: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE728: sb          $a0, 0x59D6($at)
    MEM_B(0X59D6, ctx->r1) = ctx->r4;
    // 0x800FE72C: jr          $ra
    // 0x800FE730: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FE730: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D8870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8878: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x800D887C: jal         0x800B3268
    // 0x800D8880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x800D8880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800D8884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8888: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D888C: sw          $v0, -0x3FE0($at)
    MEM_W(-0X3FE0, ctx->r1) = ctx->r2;
    // 0x800D8890: jr          $ra
    // 0x800D8894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D8894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801064_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801068: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080106C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1640, 0X13FC) << 16);
    // 0x80801070: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801078: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080107C: addiu       $t6, $t6, 0x13FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1640, 0X13FC));
    // 0x80801080: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801084: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80801088: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080108C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801090: jal         0x800BABB8
    // 0x80801094: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80801094: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80801098: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080109C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X1330) << 16);
    // 0x808010A0: lwc1        $f6, 0x1330($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X1330));
    // 0x808010A4: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x808010A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1640, 0X1450) << 16);
    // 0x808010B0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808010B4: addiu       $v0, $v0, 0x1450
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1640, 0X1450));
    // 0x808010B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808010BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808010C0: bc1f        L_808010D4
    if (!c1cs) {
        // 0x808010C4: nop
    
            goto L_808010D4;
    }
    // 0x808010C4: nop

    // 0x808010C8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1640, 0X143C) << 16);
    // 0x808010CC: b           L_808010D4
    // 0x808010D0: addiu       $v0, $v0, 0x143C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1640, 0X143C));
        goto L_808010D4;
    // 0x808010D0: addiu       $v0, $v0, 0x143C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1640, 0X143C));
L_808010D4:
    // 0x808010D4: jal         0x800BABB8
    // 0x808010D8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x808010D8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x808010DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808010E4: jr          $ra
    // 0x808010E8: nop

    return;
    // 0x808010E8: nop

;}
RECOMP_FUNC void badust_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080058C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC7C) << 16);
    // 0x80800590: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800594: lwc1        $f4, 0xC7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC7C));
    // 0x80800598: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080059C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005A0: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x808005A4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808005A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808005AC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x808005B0: jal         0x8009C128
    // 0x808005B4: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808005B4: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808005B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808005BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005C0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808005C4: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808005C8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808005CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808005D0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x808005D4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808005D8: jal         0x800EFCD8
    // 0x808005DC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    func_800EFCD8(rdram, ctx);
        goto after_1;
    // 0x808005DC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x808005E0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808005E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC80) << 16);
    // 0x808005EC: lwc1        $f18, 0xC80($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC80));
    // 0x808005F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005F8: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808005FC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800600: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800604: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800608: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8080060C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80800610: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800614: jal         0x80800260
    // 0x80800618: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    badust_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800618: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8080061C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800620: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800624: jr          $ra
    // 0x80800628: nop

    return;
    // 0x80800628: nop

;}
RECOMP_FUNC void func_808000B4_chdiggerbossshell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000CC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000D0: bnel        $t7, $at, L_80800178
    if (ctx->r15 != ctx->r1) {
        // 0x808000D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800178;
    }
    goto skip_0;
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000D8: jal         0x800D8FF8
    // 0x808000DC: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000DC: nop

    after_0:
    // 0x808000E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000E4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x808000E8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808000EC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808000F0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808000F4: jal         0x80088A88
    // 0x808000F8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _fxegg_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808000F8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x808000FC: jal         0x800D8FF8
    // 0x80800100: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800100: nop

    after_2:
    // 0x80800104: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800108: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080010C: jal         0x800EF174
    // 0x80800110: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EF174(rdram, ctx);
        goto after_3;
    // 0x80800110: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800114: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800118: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800124: nop

    // 0x80800128: bc1f        L_80800138
    if (!c1cs) {
        // 0x8080012C: nop
    
            goto L_80800138;
    }
    // 0x8080012C: nop

    // 0x80800130: jal         0x808001EC
    // 0x80800134: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    func_808001EC_chdiggerbossshell(rdram, ctx);
        goto after_4;
    // 0x80800134: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    after_4:
L_80800138:
    // 0x80800138: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1492, 0X554) << 16);
    // 0x8080013C: lwc1        $f6, 0x554($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1492, 0X554));
    // 0x80800140: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800144: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800148: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x8080014C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800150: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80800154: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x80800158: jal         0x800F1A88
    // 0x8080015C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F1A88(rdram, ctx);
        goto after_5;
    // 0x8080015C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800160: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800164: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800168: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080016C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800170: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x80800174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800178:
    // 0x80800178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080017C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void func_8080069C_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A4: jal         0x80082FE8
    // 0x808006A8: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808006A8: nop

    after_0:
    // 0x808006AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006B4: jr          $ra
    // 0x808006B8: nop

    return;
    // 0x808006B8: nop

;}
RECOMP_FUNC void func_800EF7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF7B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EF7B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EF7B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800EF7BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800EF7C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800EF7C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800EF7C8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800EF7CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EF7D0: jal         0x800137AC
    // 0x800EF7D4: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    func_800137AC(rdram, ctx);
        goto after_0;
    // 0x800EF7D4: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    after_0:
    // 0x800EF7D8: jal         0x800137C4
    // 0x800EF7DC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800137C4(rdram, ctx);
        goto after_1;
    // 0x800EF7DC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x800EF7E0: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800EF7E4: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800EF7E8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800EF7EC: mul.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF7F0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800EF7F4: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800EF7F8: nop

    // 0x800EF7FC: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF800: nop

    // 0x800EF804: mul.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800EF808: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800EF80C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800EF810: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800EF814: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800EF818: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800EF81C: jal         0x800137AC
    // 0x800EF820: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    func_800137AC(rdram, ctx);
        goto after_2;
    // 0x800EF820: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x800EF824: jal         0x800137C4
    // 0x800EF828: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800137C4(rdram, ctx);
        goto after_3;
    // 0x800EF828: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x800EF82C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800EF830: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800EF834: mul.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF838: nop

    // 0x800EF83C: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800EF840: nop

    // 0x800EF844: mul.s       $f18, $f14, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800EF848: nop

    // 0x800EF84C: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF850: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800EF854: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x800EF858: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800EF85C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800EF860: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800EF864: jal         0x800137AC
    // 0x800EF868: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    func_800137AC(rdram, ctx);
        goto after_4;
    // 0x800EF868: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    after_4:
    // 0x800EF86C: jal         0x800137C4
    // 0x800EF870: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800137C4(rdram, ctx);
        goto after_5;
    // 0x800EF870: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x800EF874: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800EF878: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800EF87C: mul.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800EF880: nop

    // 0x800EF884: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF888: nop

    // 0x800EF88C: mul.s       $f18, $f2, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF890: nop

    // 0x800EF894: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800EF898: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800EF89C: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x800EF8A0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800EF8A4: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800EF8A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EF8AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800EF8B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800EF8B4: jr          $ra
    // 0x800EF8B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800EF8B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bsledge_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837C0: syscall     74
    recomp_syscall_handler(rdram, ctx, 0x800837C0);
    return;
    // 0x800837C4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800094_chmermaidstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: jr          $ra
    // 0x80800098: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800098: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bstaxi_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E30: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E30);
    return;
    // 0x80083E34: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_808004B0_gztrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808004B4: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x808004B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x808004BC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x808004C0: addiu       $t6, $t0, -0x8
    ctx->r14 = ADD32(ctx->r8, -0X8);
    // 0x808004C4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x808004C8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x808004CC: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x808004D0: ori         $t4, $zero, 0x8FBF
    ctx->r12 = 0 | 0X8FBF;
    // 0x808004D4: addiu       $t3, $zero, 0x27BD
    ctx->r11 = ADD32(0, 0X27BD);
    // 0x808004D8: addiu       $t2, $zero, 0x3E0
    ctx->r10 = ADD32(0, 0X3E0);
    // 0x808004DC: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
L_808004E0:
    // 0x808004E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808004E4: srl         $a3, $a2, 16
    ctx->r7 = S32(U32(ctx->r6) >> 16);
    // 0x808004E8: beql        $t2, $a3, L_80800528
    if (ctx->r10 == ctx->r7) {
        // 0x808004EC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80800528;
    }
    goto skip_0;
    // 0x808004EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_0:
    // 0x808004F0: beq         $a3, $t3, L_80800510
    if (ctx->r7 == ctx->r11) {
        // 0x808004F4: sll         $t5, $a2, 16
        ctx->r13 = S32(ctx->r6 << 16);
            goto L_80800510;
    }
    // 0x808004F4: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x808004F8: bne         $a3, $t4, L_80800528
    if (ctx->r7 != ctx->r12) {
        // 0x808004FC: sll         $t7, $a2, 16
        ctx->r15 = S32(ctx->r6 << 16);
            goto L_80800528;
    }
    // 0x808004FC: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80800500: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800504: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80800508: b           L_80800528
    // 0x8080050C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
        goto L_80800528;
    // 0x8080050C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
L_80800510:
    // 0x80800510: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80800514: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80800518: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8080051C: b           L_80800528
    // 0x80800520: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
        goto L_80800528;
    // 0x80800520: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800524: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80800528:
    // 0x80800528: beql        $t1, $zero, L_808004E0
    if (ctx->r9 == 0) {
        // 0x8080052C: lw          $a2, 0x0($v1)
        ctx->r6 = MEM_W(ctx->r3, 0X0);
            goto L_808004E0;
    }
    goto skip_1;
    // 0x8080052C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x80800530: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80800534: srl         $t9, $a2, 16
    ctx->r25 = S32(U32(ctx->r6) >> 16);
    // 0x80800538: bne         $t3, $t9, L_80800550
    if (ctx->r11 != ctx->r25) {
        // 0x8080053C: sll         $t5, $a2, 16
        ctx->r13 = S32(ctx->r6 << 16);
            goto L_80800550;
    }
    // 0x8080053C: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x80800540: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80800544: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80800548: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8080054C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
L_80800550:
    // 0x80800550: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80800554: beq         $t0, $zero, L_808005B8
    if (ctx->r8 == 0) {
        // 0x80800558: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_808005B8;
    }
    // 0x80800558: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8080055C: lw          $a2, -0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, -0X8);
    // 0x80800560: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800564: srl         $v0, $a2, 26
    ctx->r2 = S32(U32(ctx->r6) >> 26);
    // 0x80800568: beq         $v0, $zero, L_8080059C
    if (ctx->r2 == 0) {
        // 0x8080056C: andi        $t8, $a2, 0x3F
        ctx->r24 = ctx->r6 & 0X3F;
            goto L_8080059C;
    }
    // 0x8080056C: andi        $t8, $a2, 0x3F
    ctx->r24 = ctx->r6 & 0X3F;
    // 0x80800570: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800574: bne         $v0, $at, L_808005B0
    if (ctx->r2 != ctx->r1) {
        // 0x80800578: lw          $t7, 0x8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8);
            goto L_808005B0;
    }
    // 0x80800578: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8080057C: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80800580: addu        $t9, $a2, $at
    ctx->r25 = ADD32(ctx->r6, ctx->r1);
    // 0x80800584: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80800588: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080058C: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80800590: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80800594: jr          $ra
    // 0x80800598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080059C:
    // 0x8080059C: bne         $t8, $at, L_808005B8
    if (ctx->r24 != ctx->r1) {
        // 0x808005A0: lw          $t9, 0x8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X8);
            goto L_808005B8;
    }
    // 0x808005A0: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x808005A4: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x808005A8: jr          $ra
    // 0x808005AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808005AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B0:
    // 0x808005B0: jr          $ra
    // 0x808005B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808005B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005B8:
    // 0x808005B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808005BC: jr          $ra
    // 0x808005C0: nop

    return;
    // 0x808005C0: nop

;}
RECOMP_FUNC void chmineprospector_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(892, 0X102C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x102C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(892, 0X102C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x102C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(892, 0X102C));
;}
RECOMP_FUNC void gcnewoption_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801218: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x8080121C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80801220: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x80801224: lh          $t9, 0xEC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XEC);
    // 0x80801228: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8080122C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80801230: beq         $t7, $t9, L_8080123C
    if (ctx->r15 == ctx->r25) {
        // 0x80801234: nop
    
            goto L_8080123C;
    }
    // 0x80801234: nop

    // 0x80801238: sh          $t7, 0xEC($v0)
    MEM_H(0XEC, ctx->r2) = ctx->r15;
L_8080123C:
    // 0x8080123C: jr          $ra
    // 0x80801240: nop

    return;
    // 0x80801240: nop

;}
RECOMP_FUNC void func_808006BC_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808006C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006C8: jal         0x80800234
    // 0x808006CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bssnowball_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808006CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x808006D8: jal         0x8008CB3C
    // 0x808006DC: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808006DC: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_1:
    // 0x808006E0: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x808006E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808006F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808006F4: jal         0x8009FFD8
    // 0x808006F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808006F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x808006FC: jal         0x8008CABC
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_3;
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800704: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800708: jal         0x8008B134
    // 0x8080070C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x8080070C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800710: jal         0x80800164
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bssnowball(rdram, ctx);
        goto after_5;
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800718: jal         0x8009EF04
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_6;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800720: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800724: nop

    // 0x80800728: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8080072C: nop

    // 0x80800730: bc1t        L_8080074C
    if (c1cs) {
        // 0x80800734: nop
    
            goto L_8080074C;
    }
    // 0x80800734: nop

    // 0x80800738: jal         0x8009EEB8
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_7;
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800740: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800744: jal         0x8009C914
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_8;
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_8080074C:
    // 0x8080074C: jal         0x8009C990
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_9;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800754: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800758: jal         0x8009B9C0
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_10;
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: jal         0x80800064
    // 0x80800768: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800064_bssnowball(rdram, ctx);
        goto after_11;
    // 0x80800768: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8080076C: jal         0x8009C990
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_12;
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800774: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800778: jal         0x8009BB00
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_13;
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800780: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800788: jal         0x8009BA68
    // 0x8080078C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x8080078C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_14:
    // 0x80800790: lui         $a1, 0x442D
    ctx->r5 = S32(0X442D << 16);
    // 0x80800794: ori         $a1, $a1, 0x6000
    ctx->r5 = ctx->r5 | 0X6000;
    // 0x80800798: jal         0x8009BA58
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_15;
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A4: jal         0x8009BCB4
    // 0x808007A8: lui         $a1, 0xC516
    ctx->r5 = S32(0XC516 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_16;
    // 0x808007A8: lui         $a1, 0xC516
    ctx->r5 = S32(0XC516 << 16);
    after_16:
    // 0x808007AC: lui         $a1, 0x3FAC
    ctx->r5 = S32(0X3FAC << 16);
    // 0x808007B0: lui         $a2, 0x3FB9
    ctx->r6 = S32(0X3FB9 << 16);
    // 0x808007B4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808007B8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808007BC: jal         0x8009D7A4
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D7A4(rdram, ctx);
        goto after_17;
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808007C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808007D0: jr          $ra
    // 0x808007D4: nop

    return;
    // 0x808007D4: nop

;}
RECOMP_FUNC void func_80800074_chmumbohealspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800078: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080007C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800080: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800084: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800088: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080008C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800090: sltiu       $at, $t8, 0xB
    ctx->r1 = ctx->r24 < 0XB ? 1 : 0;
    // 0x80800094: beq         $at, $zero, L_80800394
    if (ctx->r1 == 0) {
        // 0x80800098: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800394;
    }
    // 0x80800098: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080009C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2424, 0X870) << 16);
    // 0x808000A0: addu        $at, $at, $t8
    gpr jr_addend_808000A8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000A4: lw          $t8, 0x870($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2424, 0X870));
    // 0x808000A8: jr          $t8
    // 0x808000AC: nop

    switch (jr_addend_808000A8 >> 2) {
        case 0: goto L_80800394; break;
        case 1: goto L_808000B0; break;
        case 2: goto L_808000D0; break;
        case 3: goto L_80800128; break;
        case 4: goto L_80800198; break;
        case 5: goto L_808001F0; break;
        case 6: goto L_80800248; break;
        case 7: goto L_80800394; break;
        case 8: goto L_80800258; break;
        case 9: goto L_808002FC; break;
        case 10: goto L_80800394; break;
        default: switch_error(__func__, 0x808000A8, 0x80800870);
    }
    // 0x808000AC: nop

L_808000B0:
    // 0x808000B0: jal         0x800DA298
    // 0x808000B4: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000B4: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_0:
    // 0x808000B8: beq         $v0, $zero, L_80800394
    if (ctx->r2 == 0) {
        // 0x808000BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800394;
    }
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: jal         0x80800450
    // 0x808000C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800450_chmumbohealspell(rdram, ctx);
        goto after_1;
    // 0x808000C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808000C8: b           L_80800398
    // 0x808000CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800398;
    // 0x808000CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808000D0:
    // 0x808000D0: jal         0x80800740
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800740_chmumbohealspell(rdram, ctx);
        goto after_2;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x80100094
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808000E4: jal         0x800898B0
    // 0x808000E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x808000E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x80100094
    // 0x808000F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x808000F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808000F8: jal         0x800898E8
    // 0x808000FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_6;
    // 0x808000FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800100: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8080010C: nop

    // 0x80800110: bc1fl       L_80800398
    if (!c1cs) {
        // 0x80800114: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800398;
    }
    goto skip_0;
    // 0x80800114: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800118: jal         0x80800450
    // 0x8080011C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800450_chmumbohealspell(rdram, ctx);
        goto after_7;
    // 0x8080011C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x80800120: b           L_80800398
    // 0x80800124: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800398;
    // 0x80800124: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800128:
    // 0x80800128: jal         0x80800740
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800740_chmumbohealspell(rdram, ctx);
        goto after_8;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80100094
    // 0x80800138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8080013C: jal         0x800898B0
    // 0x80800140: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_10;
    // 0x80800140: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x80100094
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800150: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800154: jal         0x80089868
    // 0x80800158: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_12;
    // 0x80800158: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_12:
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: jal         0x80100094
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800168: jal         0x800898E8
    // 0x8080016C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_14;
    // 0x8080016C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x80800170: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8080017C: nop

    // 0x80800180: bc1fl       L_80800398
    if (!c1cs) {
        // 0x80800184: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800398;
    }
    goto skip_1;
    // 0x80800184: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800188: jal         0x80800450
    // 0x8080018C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800450_chmumbohealspell(rdram, ctx);
        goto after_15;
    // 0x8080018C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
    // 0x80800190: b           L_80800398
    // 0x80800194: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800398;
    // 0x80800194: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800198:
    // 0x80800198: jal         0x80800740
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800740_chmumbohealspell(rdram, ctx);
        goto after_16;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x80100094
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_17;
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x808001AC: jal         0x800898B0
    // 0x808001B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_18;
    // 0x808001B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: jal         0x80100094
    // 0x808001BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_19;
    // 0x808001BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x808001C0: jal         0x800898E8
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_20;
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x808001C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x808001D4: nop

    // 0x808001D8: bc1fl       L_80800398
    if (!c1cs) {
        // 0x808001DC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800398;
    }
    goto skip_2;
    // 0x808001DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x808001E0: jal         0x80800450
    // 0x808001E4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800450_chmumbohealspell(rdram, ctx);
        goto after_21;
    // 0x808001E4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_21:
    // 0x808001E8: b           L_80800398
    // 0x808001EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800398;
    // 0x808001EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808001F0:
    // 0x808001F0: jal         0x80800740
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800740_chmumbohealspell(rdram, ctx);
        goto after_22;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: jal         0x80100094
    // 0x80800200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_23;
    // 0x80800200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x80800204: jal         0x800898B0
    // 0x80800208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_24;
    // 0x80800208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_24:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x80100094
    // 0x80800214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_25;
    // 0x80800214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80800218: jal         0x800898E8
    // 0x8080021C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_26;
    // 0x8080021C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x80800220: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8080022C: nop

    // 0x80800230: bc1fl       L_80800398
    if (!c1cs) {
        // 0x80800234: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800398;
    }
    goto skip_3;
    // 0x80800234: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80800238: jal         0x80800450
    // 0x8080023C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800450_chmumbohealspell(rdram, ctx);
        goto after_27;
    // 0x8080023C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_27:
    // 0x80800240: b           L_80800398
    // 0x80800244: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800398;
    // 0x80800244: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800248:
    // 0x80800248: jal         0x800FFA88
    // 0x8080024C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_28;
    // 0x8080024C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_28:
    // 0x80800250: b           L_80800398
    // 0x80800254: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800398;
    // 0x80800254: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800258:
    // 0x80800258: addiu       $a0, $zero, 0x52D
    ctx->r4 = ADD32(0, 0X52D);
    // 0x8080025C: jal         0x80089C30
    // 0x80800260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_29;
    // 0x80800260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80800264: beq         $v0, $zero, L_808002AC
    if (ctx->r2 == 0) {
        // 0x80800268: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_808002AC;
    }
    // 0x80800268: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x80100094
    // 0x80800274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_30;
    // 0x80800274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
    // 0x80800278: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080027C: jal         0x80103EAC
    // 0x80800280: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_80103EAC(rdram, ctx);
        goto after_31;
    // 0x80800280: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_31:
    // 0x80800284: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80800288: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080028C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800290: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80800294: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800298: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080029C: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x808002A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808002A4: jal         0x80089878
    // 0x808002A8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_32;
    // 0x808002A8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_32:
L_808002AC:
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x80100094
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_33;
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x808002B8: jal         0x800898B0
    // 0x808002BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_34;
    // 0x808002BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_34:
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: jal         0x80100094
    // 0x808002C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_35;
    // 0x808002C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_35:
    // 0x808002CC: jal         0x800898E8
    // 0x808002D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_36;
    // 0x808002D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_36:
    // 0x808002D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x808002E0: nop

    // 0x808002E4: bc1fl       L_80800398
    if (!c1cs) {
        // 0x808002E8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800398;
    }
    goto skip_4;
    // 0x808002E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x808002EC: jal         0x80800450
    // 0x808002F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800450_chmumbohealspell(rdram, ctx);
        goto after_37;
    // 0x808002F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_37:
    // 0x808002F4: b           L_80800398
    // 0x808002F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800398;
    // 0x808002F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808002FC:
    // 0x808002FC: addiu       $a0, $zero, 0x52D
    ctx->r4 = ADD32(0, 0X52D);
    // 0x80800300: jal         0x80089C30
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_38;
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x80800308: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x80100094
    // 0x80800314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_39;
    // 0x80800314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x80800318: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080031C: jal         0x80103EAC
    // 0x80800320: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80103EAC(rdram, ctx);
        goto after_40;
    // 0x80800320: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_40:
    // 0x80800324: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80800328: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080032C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800330: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80800334: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800338: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080033C: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x80800340: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800344: jal         0x80089878
    // 0x80800348: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_41;
    // 0x80800348: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_41:
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: jal         0x80100094
    // 0x80800354: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_42;
    // 0x80800354: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_42:
    // 0x80800358: jal         0x800898B0
    // 0x8080035C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_43;
    // 0x8080035C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_43:
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x80100094
    // 0x80800368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_44;
    // 0x80800368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_44:
    // 0x8080036C: jal         0x800898E8
    // 0x80800370: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_45;
    // 0x80800370: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_45:
    // 0x80800374: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80800380: nop

    // 0x80800384: bc1fl       L_80800398
    if (!c1cs) {
        // 0x80800388: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800398;
    }
    goto skip_5;
    // 0x80800388: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x8080038C: jal         0x80800450
    // 0x80800390: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800450_chmumbohealspell(rdram, ctx);
        goto after_46;
    // 0x80800390: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_46:
L_80800394:
    // 0x80800394: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800398:
    // 0x80800398: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080039C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A108: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A108);
    return;
    // 0x8008A10C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808015DC_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808015E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808015E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808015E8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808015EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808015F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808015F4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808015F8: beq         $t6, $at, L_80801628
    if (ctx->r14 == ctx->r1) {
        // 0x808015FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801628;
    }
    // 0x808015FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801600: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801604: beq         $t6, $at, L_80801638
    if (ctx->r14 == ctx->r1) {
        // 0x80801608: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801638;
    }
    // 0x80801608: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080160C: beq         $t6, $at, L_808016F0
    if (ctx->r14 == ctx->r1) {
        // 0x80801610: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808016F0;
    }
    // 0x80801610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801614: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801618: beq         $t6, $at, L_808016A0
    if (ctx->r14 == ctx->r1) {
        // 0x8080161C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808016A0;
    }
    // 0x8080161C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801620: b           L_80801758
    // 0x80801624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801758;
    // 0x80801624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801628:
    // 0x80801628: jal         0x80101FDC
    // 0x8080162C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x8080162C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80801630: b           L_80801758
    // 0x80801634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801758;
    // 0x80801634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801638:
    // 0x80801638: jal         0x80801358
    // 0x8080163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801358_chfishshootgame(rdram, ctx);
        goto after_1;
    // 0x8080163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801640: jal         0x808013B8
    // 0x80801644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808013B8_chfishshootgame(rdram, ctx);
        goto after_2;
    // 0x80801644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801648: jal         0x800DA298
    // 0x8080164C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080164C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80801650: beq         $v0, $zero, L_8080166C
    if (ctx->r2 == 0) {
        // 0x80801654: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080166C;
    }
    // 0x80801654: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080165C: jal         0x80801424
    // 0x80801660: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801424_chfishshootgame(rdram, ctx);
        goto after_4;
    // 0x80801660: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80801664: b           L_80801758
    // 0x80801668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801758;
    // 0x80801668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080166C:
    // 0x8080166C: jal         0x800EEAD4
    // 0x80801670: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EEAD4(rdram, ctx);
        goto after_5;
    // 0x80801670: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_5:
    // 0x80801674: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801678: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080167C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801680: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801684: nop

    // 0x80801688: bc1fl       L_80801758
    if (!c1cs) {
        // 0x8080168C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801758;
    }
    goto skip_0;
    // 0x8080168C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801690: jal         0x80801424
    // 0x80801694: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801424_chfishshootgame(rdram, ctx);
        goto after_6;
    // 0x80801694: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80801698: b           L_80801758
    // 0x8080169C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801758;
    // 0x8080169C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808016A0:
    // 0x808016A0: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808016A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808016A8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808016AC: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808016B0: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x808016B4: nop

    // 0x808016B8: bc1t        L_808016D0
    if (c1cs) {
        // 0x808016BC: nop
    
            goto L_808016D0;
    }
    // 0x808016BC: nop

    // 0x808016C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808016C4: nop

    // 0x808016C8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808016CC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_808016D0:
    // 0x808016D0: jal         0x80101E14
    // 0x808016D4: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_7;
    // 0x808016D4: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_7:
    // 0x808016D8: beql        $v0, $zero, L_80801758
    if (ctx->r2 == 0) {
        // 0x808016DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801758;
    }
    goto skip_1;
    // 0x808016DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808016E0: jal         0x80089CA8
    // 0x808016E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808016E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808016E8: b           L_80801758
    // 0x808016EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801758;
    // 0x808016EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808016F0:
    // 0x808016F0: lui         $a1, 0x3F0A
    ctx->r5 = S32(0X3F0A << 16);
    // 0x808016F4: jal         0x80101E14
    // 0x808016F8: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    func_80101E14(rdram, ctx);
        goto after_9;
    // 0x808016F8: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    after_9:
    // 0x808016FC: beql        $v0, $zero, L_80801738
    if (ctx->r2 == 0) {
        // 0x80801700: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_80801738;
    }
    goto skip_2;
    // 0x80801700: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    skip_2:
    // 0x80801704: jal         0x80106790
    // 0x80801708: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_10;
    // 0x80801708: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_10:
    // 0x8080170C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801710: jal         0x808003B0
    // 0x80801714: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808003B0_chfishshootgame(rdram, ctx);
        goto after_11;
    // 0x80801714: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x80801718: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(740, 0X1A74) << 16);
    // 0x8080171C: addiu       $a2, $a2, 0x1A74
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(740, 0X1A74));
    // 0x80801720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801724: jal         0x80089D18
    // 0x80801728: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80801728: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x8080172C: jal         0x8010A570
    // 0x80801730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_13;
    // 0x80801730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80801734: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
L_80801738:
    // 0x80801738: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x8080173C: jal         0x80101E14
    // 0x80801740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x80801740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801744: beql        $v0, $zero, L_80801758
    if (ctx->r2 == 0) {
        // 0x80801748: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801758;
    }
    goto skip_3;
    // 0x80801748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8080174C: jal         0x80089CA8
    // 0x80801750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80801750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801758:
    // 0x80801758: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080175C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801760: jr          $ra
    // 0x80801764: nop

    return;
    // 0x80801764: nop

;}
RECOMP_FUNC void basub_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808009CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808009D0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808009D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009D8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808009DC: jal         0x800D8FF8
    // 0x808009E0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808009E0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    after_0:
    // 0x808009E4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808009E8: jal         0x80092AD8
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092AD8(rdram, ctx);
        goto after_1;
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808009F0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808009F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009F8: jal         0x800E0AF0
    // 0x808009FC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_2;
    // 0x808009FC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800A00: lw          $a0, 0x130($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X130);
    // 0x80800A04: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80800A08: jal         0x800F1574
    // 0x80800A0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F1574(rdram, ctx);
        goto after_3;
    // 0x80800A0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x80800A10: lw          $v1, 0x130($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X130);
    // 0x80800A14: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80800A18: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80800A1C: nop

    // 0x80800A20: bc1fl       L_80800A34
    if (!c1cs) {
        // 0x80800A24: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80800A34;
    }
    goto skip_0;
    // 0x80800A24: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80800A28: b           L_80800A34
    // 0x80800A2C: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
        goto L_80800A34;
    // 0x80800A2C: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    // 0x80800A30: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800A34:
    // 0x80800A34: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80800A38: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800A3C: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80800A40: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800A44: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x80800A48: lw          $v1, 0x130($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X130);
    // 0x80800A4C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800A50: lwc1        $f8, 0x24($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80800A54: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80800A58: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80800A5C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800A60: swc1        $f16, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f16.u32l;
    // 0x80800A64: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800A68: lw          $t6, 0x130($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X130);
    // 0x80800A6C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800A70: lwc1        $f18, 0x20($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80800A74: jal         0x800E0AFC
    // 0x80800A78: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_4;
    // 0x80800A78: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80800A7C: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80800A80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A84: lw          $v1, 0x130($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X130);
    // 0x80800A88: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80800A8C: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80800A90: lwc1        $f14, 0x18($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800A94: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800A98: jal         0x800F15F8
    // 0x80800A9C: nop

    func_800F15F8(rdram, ctx);
        goto after_5;
    // 0x80800A9C: nop

    after_5:
    // 0x80800AA0: lw          $t7, 0x130($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X130);
    // 0x80800AA4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x80800AA8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800AAC: swc1        $f0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f0.u32l;
    // 0x80800AB0: lw          $t8, 0x130($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X130);
    // 0x80800AB4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800AB8: lw          $a3, 0x14($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X14);
    // 0x80800ABC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800AC0: jal         0x800E0AFC
    // 0x80800AC4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_6;
    // 0x80800AC4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x80800AC8: lw          $t9, 0x130($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X130);
    // 0x80800ACC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800AD0: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x80800AD4: lw          $a3, 0x14($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X14);
    // 0x80800AD8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800ADC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800AE0: jal         0x800E0AFC
    // 0x80800AE4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800E0AFC(rdram, ctx);
        goto after_7;
    // 0x80800AE4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AEC: jal         0x8009C128
    // 0x80800AF0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_8009C128(rdram, ctx);
        goto after_8;
    // 0x80800AF0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_8:
    // 0x80800AF4: lw          $t0, 0x130($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X130);
    // 0x80800AF8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800AFC: jal         0x800C35E8
    // 0x80800B00: lbu         $a0, 0xC($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XC);
    func_800C35E8(rdram, ctx);
        goto after_9;
    // 0x80800B00: lbu         $a0, 0xC($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XC);
    after_9:
    // 0x80800B04: lw          $t1, 0x130($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X130);
    // 0x80800B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B0C: jal         0x800C33DC
    // 0x80800B10: lbu         $a0, 0xC($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0XC);
    func_800C33DC(rdram, ctx);
        goto after_10;
    // 0x80800B10: lbu         $a0, 0xC($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0XC);
    after_10:
    // 0x80800B14: lw          $t2, 0x130($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X130);
    // 0x80800B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B1C: jal         0x800C368C
    // 0x80800B20: lbu         $a0, 0xC($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0XC);
    func_800C368C(rdram, ctx);
        goto after_11;
    // 0x80800B20: lbu         $a0, 0xC($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0XC);
    after_11:
    // 0x80800B24: lw          $v1, 0x130($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X130);
    // 0x80800B28: lbu         $a0, 0xC($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC);
    // 0x80800B2C: jal         0x800C31DC
    // 0x80800B30: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    func_800C31DC(rdram, ctx);
        goto after_12;
    // 0x80800B30: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    after_12:
    // 0x80800B34: lw          $t3, 0x130($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X130);
    // 0x80800B38: jal         0x800C3BDC
    // 0x80800B3C: lbu         $a0, 0xC($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0XC);
    func_800C3BDC(rdram, ctx);
        goto after_13;
    // 0x80800B3C: lbu         $a0, 0xC($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0XC);
    after_13:
    // 0x80800B40: jal         0x80800110
    // 0x80800B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800110_basub(rdram, ctx);
        goto after_14;
    // 0x80800B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800B48: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800B4C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800B50: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800B54: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800B58: jr          $ra
    // 0x80800B5C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800B5C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800214_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800218: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080021C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800220: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800224: jal         0x80100094
    // 0x80800228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080022C: lbu         $v1, 0xF($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XF);
    // 0x80800230: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: beq         $v1, $zero, L_8080025C
    if (ctx->r3 == 0) {
        // 0x8080023C: nop
    
            goto L_8080025C;
    }
    // 0x8080023C: nop

    // 0x80800240: beq         $v1, $at, L_80800274
    if (ctx->r3 == ctx->r1) {
        // 0x80800244: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800274;
    }
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080024C: beq         $v1, $at, L_80800294
    if (ctx->r3 == ctx->r1) {
        // 0x80800250: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800294;
    }
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: b           L_808002A8
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002A8;
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080025C:
    // 0x8080025C: jal         0x808001D0
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808001D0_chhandcart(rdram, ctx);
        goto after_1;
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800264: jal         0x808000B4
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080026C: b           L_808002A8
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002A8;
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800274:
    // 0x80800274: jal         0x808001D0
    // 0x80800278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808001D0_chhandcart(rdram, ctx);
        goto after_3;
    // 0x80800278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8080027C: jal         0x800880E0
    // 0x80800280: nop

    _gcintrotext_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800280: nop

    after_4:
    // 0x80800284: jal         0x808000B4
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chhandcart(rdram, ctx);
        goto after_5;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080028C: b           L_808002A8
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002A8;
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800294:
    // 0x80800294: jal         0x808001D0
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808001D0_chhandcart(rdram, ctx);
        goto after_6;
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080029C: jal         0x80800024
    // 0x808002A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800024_chhandcart(rdram, ctx);
        goto after_7;
    // 0x808002A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808002A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A8:
    // 0x808002A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002B0: jr          $ra
    // 0x808002B4: nop

    return;
    // 0x808002B4: nop

;}
