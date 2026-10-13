#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800000_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $a1, $zero, 0x504
    ctx->r5 = ADD32(0, 0X504);
    // 0x8080000C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800010: jal         0x8009DF94
    // 0x80800014: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF94(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
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
RECOMP_FUNC void ncbasuck_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080004C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800050: jal         0x80111B8C
    // 0x80800054: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_0;
    // 0x80800054: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_0:
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: jal         0x801124D0
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800068: jal         0x80115858
    // 0x8080006C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80115858(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800074: jal         0x80115870
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80115870(rdram, ctx);
        goto after_3;
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void _bsdronebitten_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083008: syscall     39
    recomp_syscall_handler(rdram, ctx, 0x80083008);
    return;
    // 0x8008300C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bashoes_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800378: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x8080037C: jr          $ra
    // 0x80800380: sb          $a1, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r5;
    return;
    // 0x80800380: sb          $a1, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808002E0_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808002EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808002F4: jal         0x80100094
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002FC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: addiu       $a1, $v0, 0x2C
    ctx->r5 = ADD32(ctx->r2, 0X2C);
    // 0x80800308: jal         0x8008A2A0
    // 0x8080030C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080030C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800310: jal         0x800EA05C
    // 0x80800314: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80800314: nop

    after_2:
    // 0x80800318: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x8080031C: bnel        $v0, $at, L_8080033C
    if (ctx->r2 != ctx->r1) {
        // 0x80800320: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080033C;
    }
    goto skip_0;
    // 0x80800320: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80800324: jal         0x8010A624
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_3;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080032C: lbu         $t6, 0x7E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7E);
    // 0x80800330: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80800334: sb          $t7, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r15;
    // 0x80800338: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8080033C:
    // 0x8080033C: jal         0x800EE940
    // 0x80800340: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE940(rdram, ctx);
        goto after_4;
    // 0x80800340: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800344: addiu       $a0, $s1, 0x6
    ctx->r4 = ADD32(ctx->r17, 0X6);
    // 0x80800348: addiu       $a1, $zero, -0x206C
    ctx->r5 = ADD32(0, -0X206C);
    // 0x8080034C: addiu       $a2, $zero, 0xA73
    ctx->r6 = ADD32(0, 0XA73);
    // 0x80800350: jal         0x800EFA6C
    // 0x80800354: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800EFA6C(rdram, ctx);
        goto after_5;
    // 0x80800354: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80800358: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x8080035C: jal         0x800DA298
    // 0x80800360: addiu       $a0, $zero, 0x67E
    ctx->r4 = ADD32(0, 0X67E);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800360: addiu       $a0, $zero, 0x67E
    ctx->r4 = ADD32(0, 0X67E);
    after_6:
    // 0x80800364: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    // 0x80800368: jal         0x800DA298
    // 0x8080036C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x8080036C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_7:
    // 0x80800370: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800374: bne         $v1, $zero, L_808003AC
    if (ctx->r3 != 0) {
        // 0x80800378: nop
    
            goto L_808003AC;
    }
    // 0x80800378: nop

    // 0x8080037C: beq         $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x80800380: nop
    
            goto L_808003AC;
    }
    // 0x80800380: nop

    // 0x80800384: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800390: jal         0x8080070C
    // 0x80800394: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    func_8080070C_chcablecar(rdram, ctx);
        goto after_8;
    // 0x80800394: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    after_8:
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x80101FDC
    // 0x808003A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x808003A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808003A4: b           L_80800404
    // 0x808003A8: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
        goto L_80800404;
    // 0x808003A8: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
L_808003AC:
    // 0x808003AC: beq         $v1, $zero, L_808003EC
    if (ctx->r3 == 0) {
        // 0x808003B0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(972, 0XE8C) << 16);
            goto L_808003EC;
    }
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XE8C) << 16);
    // 0x808003B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003C4: jal         0x8080070C
    // 0x808003C8: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    func_8080070C_chcablecar(rdram, ctx);
        goto after_10;
    // 0x808003C8: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    after_10:
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: jal         0x80101FDC
    // 0x808003D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x808003D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: jal         0x8008A4B0
    // 0x808003E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x808003E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808003E4: b           L_80800404
    // 0x808003E8: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
        goto L_80800404;
    // 0x808003E8: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
L_808003EC:
    // 0x808003EC: lwc1        $f0, 0xE8C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE8C));
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003F8: jal         0x8080070C
    // 0x808003FC: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    func_8080070C_chcablecar(rdram, ctx);
        goto after_13;
    // 0x808003FC: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    after_13:
    // 0x80800400: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
L_80800404:
    // 0x80800404: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800408: jal         0x80088FA0
    // 0x8080040C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _mlwave_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x8080040C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_14:
    // 0x80800410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800414: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800418: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080041C: jr          $ra
    // 0x80800420: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800420: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800078_chfactorymaindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080007C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800080: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800084: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800088: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080008C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800090: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800094: beq         $t6, $at, L_808000B4
    if (ctx->r14 == ctx->r1) {
        // 0x80800098: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000B4;
    }
    // 0x80800098: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080009C: beq         $t6, $at, L_8080010C
    if (ctx->r14 == ctx->r1) {
        // 0x808000A0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080010C;
    }
    // 0x808000A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000A4: beq         $t6, $at, L_808001C8
    if (ctx->r14 == ctx->r1) {
        // 0x808000A8: nop
    
            goto L_808001C8;
    }
    // 0x808000A8: nop

    // 0x808000AC: b           L_808001E0
    // 0x808000B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001E0;
    // 0x808000B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000B4:
    // 0x808000B4: jal         0x800DA298
    // 0x808000B8: addiu       $a0, $zero, 0xA00
    ctx->r4 = ADD32(0, 0XA00);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000B8: addiu       $a0, $zero, 0xA00
    ctx->r4 = ADD32(0, 0XA00);
    after_0:
    // 0x808000BC: beql        $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808000C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808001E0;
    }
    goto skip_0;
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000C4: jal         0x800DA298
    // 0x808000C8: addiu       $a0, $zero, 0xA01
    ctx->r4 = ADD32(0, 0XA01);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808000C8: addiu       $a0, $zero, 0xA01
    ctx->r4 = ADD32(0, 0XA01);
    after_1:
    // 0x808000CC: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808000D0: addiu       $a0, $zero, 0x102
        ctx->r4 = ADD32(0, 0X102);
            goto L_808001DC;
    }
    // 0x808000D0: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    // 0x808000D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808000D8: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    // 0x808000DC: jal         0x8009EC88
    // 0x808000E0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_8009EC88(rdram, ctx);
        goto after_2;
    // 0x808000E0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_2:
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x80101FDC
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808000F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808000F8: addiu       $a3, $zero, 0x830
    ctx->r7 = ADD32(0, 0X830);
    // 0x808000FC: jal         0x80085708
    // 0x80800100: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800100: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_4:
    // 0x80800104: b           L_808001E0
    // 0x80800108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001E0;
    // 0x80800108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080010C:
    // 0x8080010C: jal         0x800D90A4
    // 0x80800110: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_5;
    // 0x80800110: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_5:
    // 0x80800114: beq         $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800168;
    }
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x80101FDC
    // 0x80800124: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800124: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800128: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2320, 0X4CC) << 16);
    // 0x8080012C: addiu       $a2, $a2, 0x4CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2320, 0X4CC));
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80089D18
    // 0x80800138: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800138: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x8080013C: jal         0x80089D40
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800144: jal         0x80103EF4
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_9;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080014C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2320, 0X4A4) << 16);
    // 0x80800150: lwc1        $f4, 0x4A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2320, 0X4A4));
    // 0x80800154: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800158: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080015C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800160: b           L_808001DC
    // 0x80800164: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_808001DC;
    // 0x80800164: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80800168:
    // 0x80800168: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2320, 0X4C0) << 16);
    // 0x8080016C: addiu       $a3, $a3, 0x4C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2320, 0X4C0));
    // 0x80800170: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800174: jal         0x80089D50
    // 0x80800178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x8080017C: jal         0x80103EF4
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_11;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800184: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800188: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8080018C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800190: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2320, 0X4A8) << 16);
    // 0x80800194: lwc1        $f16, 0x4A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2320, 0X4A8));
    // 0x80800198: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8080019C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001A0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808001A4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808001A8: jal         0x800F10B4
    // 0x808001AC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x808001AC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x808001B0: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808001B4: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808001B8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808001BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001C0: b           L_808001DC
    // 0x808001C4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_808001DC;
    // 0x808001C4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_808001C8:
    // 0x808001C8: jal         0x800DA544
    // 0x808001CC: addiu       $a0, $zero, 0x1AB
    ctx->r4 = ADD32(0, 0X1AB);
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x808001CC: addiu       $a0, $zero, 0x1AB
    ctx->r4 = ADD32(0, 0X1AB);
    after_13:
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: jal         0x80103110
    // 0x808001D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_14;
    // 0x808001D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
L_808001DC:
    // 0x808001DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001E0:
    // 0x808001E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001E8: jr          $ra
    // 0x808001EC: nop

    return;
    // 0x808001EC: nop

;}
RECOMP_FUNC void func_808000B4_chgoldstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000C4: jal         0x80100094
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808000D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000D4: jal         0x80101870
    // 0x808000D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x808000D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808000DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E0: beql        $a0, $zero, L_80800144
    if (ctx->r4 == 0) {
        // 0x808000E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800144;
    }
    goto skip_0;
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000E8: jal         0x80089890
    // 0x808000EC: nop

    _sumumbofx_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808000EC: nop

    after_2:
    // 0x808000F0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808000F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F8: jal         0x80089880
    // 0x808000FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808000FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800100: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800108: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080010C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800110: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80800114: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800118: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080011C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80800120: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80800124: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80800128: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080012C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800130: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800134: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800138: jal         0x800DF5D8
    // 0x8080013C: nop

    func_800DF5D8(rdram, ctx);
        goto after_4;
    // 0x8080013C: nop

    after_4:
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800144:
    // 0x80800144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void func_808002E4_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002F0: jal         0x8009E704
    // 0x808002F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x808002F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800300: jal         0x8009CA70
    // 0x80800304: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x80800304: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    after_1:
    // 0x80800308: bne         $v0, $zero, L_80800388
    if (ctx->r2 != 0) {
        // 0x8080030C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800388;
    }
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x80093360
    // 0x80800314: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_2;
    // 0x80800314: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: jal         0x8009C4CC
    // 0x80800320: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_3;
    // 0x80800320: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: jal         0x8009BF5C
    // 0x8080032C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_4;
    // 0x8080032C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800330: jal         0x800A4E30
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_5;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800338: jal         0x8009BC6C
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_6;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800340: jal         0x8009BC90
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_7;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: jal         0x800845A8
    // 0x80800350: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baboost_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800350: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800354: jal         0x80084798
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babuzz_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080035C: jal         0x80084568
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_5(rdram, ctx);
        goto after_10;
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800364: jal         0x80084BE8
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: jal         0x80084D08
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafpctrl_entrypoint_18(rdram, ctx);
        goto after_12;
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800380: jal         0x800947EC
    // 0x80800384: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_13;
    // 0x80800384: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
L_80800388:
    // 0x80800388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080038C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800390: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800394: jr          $ra
    // 0x80800398: nop

    return;
    // 0x80800398: nop

;}
RECOMP_FUNC void func_8080076C_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080076C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800774: jal         0x80084DB0
    // 0x80800778: nop

    _bakaztorpedo_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800778: nop

    after_0:
    // 0x8080077C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800784: jr          $ra
    // 0x80800788: nop

    return;
    // 0x80800788: nop

;}
RECOMP_FUNC void func_80108454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010845C: jal         0x80108C90
    // 0x80108460: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80108C90(rdram, ctx);
        goto after_0;
    // 0x80108460: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80108464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010846C: jr          $ra
    // 0x80108470: nop

    return;
    // 0x80108470: nop

;}
RECOMP_FUNC void subaddiefade_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800494: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080049C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808004A0: jal         0x800C87DC
    // 0x808004A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800C87DC(rdram, ctx);
        goto after_0;
    // 0x808004A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808004A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004AC: jal         0x80800370
    // 0x808004B0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    subaddiefade_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808004B0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x808004B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004BC: jr          $ra
    // 0x808004C0: nop

    return;
    // 0x808004C0: nop

    // 0x808004C4: nop

    // 0x808004C8: nop

    // 0x808004CC: nop

;}
RECOMP_FUNC void func_80800580_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800584: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800588: jal         0x808006F0
    // 0x8080058C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080058C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800590: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800594: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800598: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080059C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808005A4: jal         0x8009FFD8
    // 0x808005A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x808005A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x808005AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005B0: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808005B4: jal         0x8009C99C
    // 0x808005B8: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_2;
    // 0x808005B8: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_2:
    // 0x808005BC: jal         0x80800000
    // 0x808005C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800000_bstrexlarge(rdram, ctx);
        goto after_3;
    // 0x808005C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808005C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005CC: jr          $ra
    // 0x808005D0: nop

    return;
    // 0x808005D0: nop

;}
RECOMP_FUNC void func_800BAB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAB80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BAB84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BAB88: jal         0x800F2EBC
    // 0x800BAB8C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800F2EBC(rdram, ctx);
        goto after_0;
    // 0x800BAB8C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x800BAB90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BAB94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BAB98: jr          $ra
    // 0x800BAB9C: nop

    return;
    // 0x800BAB9C: nop

;}
RECOMP_FUNC void func_800CF870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF870: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CF874: jr          $ra
    // 0x800CF878: sw          $a0, -0x51A0($at)
    MEM_W(-0X51A0, ctx->r1) = ctx->r4;
    return;
    // 0x800CF878: sw          $a0, -0x51A0($at)
    MEM_W(-0X51A0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800030_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800038: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080003C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800040: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x80800044: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800048: jal         0x800DA298
    // 0x8080004C: addiu       $a0, $t6, 0x143
    ctx->r4 = ADD32(ctx->r14, 0X143);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a0, $t6, 0x143
    ctx->r4 = ADD32(ctx->r14, 0X143);
    after_0:
    // 0x80800050: bne         $v0, $zero, L_80800068
    if (ctx->r2 != 0) {
        // 0x80800054: nop
    
            goto L_80800068;
    }
    // 0x80800054: nop

    // 0x80800058: jal         0x80801138
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801138_chterryegg(rdram, ctx);
        goto after_1;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800060: beq         $v0, $zero, L_80800078
    if (ctx->r2 == 0) {
        // 0x80800064: addiu       $a0, $zero, 0x357
        ctx->r4 = ADD32(0, 0X357);
            goto L_80800078;
    }
    // 0x80800064: addiu       $a0, $zero, 0x357
    ctx->r4 = ADD32(0, 0X357);
L_80800068:
    // 0x80800068: jal         0x800FFAB0
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800070: b           L_80800098
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800098;
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800078:
    // 0x80800078: jal         0x80088480
    // 0x8080007C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080007C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800080: jal         0x80103014
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_4;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x80800CF4
    // 0x80800090: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80800CF4_chterryegg(rdram, ctx);
        goto after_5;
    // 0x80800090: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_5:
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800098:
    // 0x80800098: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_800D0594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0598: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D059C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D05A0: bne         $a1, $at, L_800D05D4
    if (ctx->r5 != ctx->r1) {
        // 0x800D05A4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800D05D4;
    }
    // 0x800D05A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D05A8: jal         0x800CFC5C
    // 0x800D05AC: nop

    func_800CFC5C(rdram, ctx);
        goto after_0;
    // 0x800D05AC: nop

    after_0:
    // 0x800D05B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D05B4: beq         $v0, $at, L_800D05D4
    if (ctx->r2 == ctx->r1) {
        // 0x800D05B8: lh          $t6, 0x22($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X22);
            goto L_800D05D4;
    }
    // 0x800D05B8: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x800D05BC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800D05C0: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x800D05C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D05C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D05CC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D05D0: sh          $t6, -0x4E70($at)
    MEM_H(-0X4E70, ctx->r1) = ctx->r14;
L_800D05D4:
    // 0x800D05D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D05D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D05DC: jr          $ra
    // 0x800D05E0: nop

    return;
    // 0x800D05E0: nop

;}
RECOMP_FUNC void func_808099A8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808099A8: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x808099AC: jr          $ra
    // 0x808099B0: sh          $a1, 0x248($v0)
    MEM_H(0X248, ctx->r2) = ctx->r5;
    return;
    // 0x808099B0: sh          $a1, 0x248($v0)
    MEM_H(0X248, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void _susplinet_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E80: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E80);
    return;
    // 0x80089E84: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_808009FC_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A04: jal         0x800EA05C
    // 0x80800A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A0C: addiu       $at, $zero, 0xD6
    ctx->r1 = ADD32(0, 0XD6);
    // 0x80800A10: bnel        $v0, $at, L_80800A38
    if (ctx->r2 != ctx->r1) {
        // 0x80800A14: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800A38;
    }
    goto skip_0;
    // 0x80800A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800A18: jal         0x800BEA88
    // 0x80800A1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_1;
    // 0x80800A1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A24: addiu       $a1, $zero, 0x89D
    ctx->r5 = ADD32(0, 0X89D);
    // 0x80800A28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800A2C: jal         0x80088F28
    // 0x80800A30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800A30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800A34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800A38:
    // 0x80800A38: jal         0x80100094
    // 0x80800A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800A40: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800A44: sb          $t6, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r14;
    // 0x80800A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A50: jr          $ra
    // 0x80800A54: nop

    return;
    // 0x80800A54: nop

;}
RECOMP_FUNC void boot_osSendMesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_808005DC_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808005E8: lw          $a2, 0x30($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X30);
    // 0x808005EC: lwc1        $f14, 0x2C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x808005F0: lwc1        $f12, 0x28($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X28);
    // 0x808005F4: jal         0x800DF500
    // 0x808005F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DF500(rdram, ctx);
        goto after_0;
    // 0x808005F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800600: jal         0x80101870
    // 0x80800604: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80800604: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080060C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800610: jr          $ra
    // 0x80800614: nop

    return;
    // 0x80800614: nop

;}
RECOMP_FUNC void func_800E9A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9A2C: jal         0x800E9898
    // 0x800E9A30: nop

    func_800E9898(rdram, ctx);
        goto after_0;
    // 0x800E9A30: nop

    after_0:
    // 0x800E9A34: lhu         $t6, 0x6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X6);
    // 0x800E9A38: lbu         $t3, 0x12($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X12);
    // 0x800E9A3C: sb          $zero, 0xB($v0)
    MEM_B(0XB, ctx->r2) = 0;
    // 0x800E9A40: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x800E9A44: ori         $t8, $t7, 0x1900
    ctx->r24 = ctx->r15 | 0X1900;
    // 0x800E9A48: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x800E9A4C: lbu         $t9, 0x7($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X7);
    // 0x800E9A50: lbu         $t8, 0x13($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X13);
    // 0x800E9A54: andi        $t6, $t3, 0xFFFD
    ctx->r14 = ctx->r11 & 0XFFFD;
    // 0x800E9A58: andi        $t1, $t9, 0xFF81
    ctx->r9 = ctx->r25 & 0XFF81;
    // 0x800E9A5C: sb          $t1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r9;
    // 0x800E9A60: andi        $t2, $t1, 0xFE
    ctx->r10 = ctx->r9 & 0XFE;
    // 0x800E9A64: sb          $t2, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r10;
    // 0x800E9A68: andi        $t0, $t8, 0xFF7F
    ctx->r8 = ctx->r24 & 0XFF7F;
    // 0x800E9A6C: andi        $t2, $t0, 0xBF
    ctx->r10 = ctx->r8 & 0XBF;
    // 0x800E9A70: sb          $t6, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r14;
    // 0x800E9A74: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800E9A78: sb          $t0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r8;
    // 0x800E9A7C: andi        $t4, $t2, 0xDF
    ctx->r12 = ctx->r10 & 0XDF;
    // 0x800E9A80: sb          $t2, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r10;
    // 0x800E9A84: andi        $t6, $t4, 0xEF
    ctx->r14 = ctx->r12 & 0XEF;
    // 0x800E9A88: sb          $t4, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r12;
    // 0x800E9A8C: andi        $t8, $t6, 0xF3
    ctx->r24 = ctx->r14 & 0XF3;
    // 0x800E9A90: sb          $t6, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r14;
    // 0x800E9A94: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
    // 0x800E9A98: andi        $t9, $t8, 0xFC
    ctx->r25 = ctx->r24 & 0XFC;
    // 0x800E9A9C: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    // 0x800E9AA0: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800E9AA4: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800E9AA8: sb          $t7, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r15;
    // 0x800E9AAC: sb          $t9, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r25;
    // 0x800E9AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9AB8: jr          $ra
    // 0x800E9ABC: nop

    return;
    // 0x800E9ABC: nop

;}
RECOMP_FUNC void func_80802C80_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C80: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80802C84: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80802C88: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80802C8C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80802C90: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80802C94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802C98: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80802C9C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80802CA0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80802CA4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80802CA8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80802CAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80802CB0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80802CB4: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x80802CB8: sb          $zero, 0x178($a0)
    MEM_B(0X178, ctx->r4) = 0;
    // 0x80802CBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802CC0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80802CC4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80802CC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80802CCC:
    // 0x80802CCC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802CD0: sb          $zero, 0x144($s1)
    MEM_B(0X144, ctx->r17) = 0;
    // 0x80802CD4: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x80802CD8: sh          $zero, 0x160($s2)
    MEM_H(0X160, ctx->r18) = 0;
    // 0x80802CDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80802CE0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80802CE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80802CE8: bne         $at, $zero, L_80802CCC
    if (ctx->r1 != 0) {
        // 0x80802CEC: swc1        $f0, 0x148($v0)
        MEM_W(0X148, ctx->r2) = ctx->f0.u32l;
            goto L_80802CCC;
    }
    // 0x80802CEC: swc1        $f0, 0x148($v0)
    MEM_W(0X148, ctx->r2) = ctx->f0.u32l;
    // 0x80802CF0: lbu         $t6, 0x176($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X176);
    // 0x80802CF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802CF8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80802CFC: beq         $t6, $at, L_80802DD0
    if (ctx->r14 == ctx->r1) {
        // 0x80802D00: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80802DD0;
    }
    // 0x80802D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802D04: addiu       $t7, $s5, 0x14C
    ctx->r15 = ADD32(ctx->r21, 0X14C);
    // 0x80802D08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802D0C: addiu       $a2, $sp, 0x62
    ctx->r6 = ADD32(ctx->r29, 0X62);
    // 0x80802D10: jal         0x80088430
    // 0x80802D14: addiu       $a3, $s5, 0x160
    ctx->r7 = ADD32(ctx->r21, 0X160);
    _gczoomboxdata_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80802D14: addiu       $a3, $s5, 0x160
    ctx->r7 = ADD32(ctx->r21, 0X160);
    after_0:
    // 0x80802D18: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80802D1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802D20: lwc1        $f6, 0x14C($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X14C);
    // 0x80802D24: lh          $t8, 0x62($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X62);
    // 0x80802D28: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80802D2C: nop

    // 0x80802D30: bc1f        L_80802D40
    if (!c1cs) {
        // 0x80802D34: nop
    
            goto L_80802D40;
    }
    // 0x80802D34: nop

    // 0x80802D38: b           L_80802DD0
    // 0x80802D3C: sb          $t8, 0x144($s5)
    MEM_B(0X144, ctx->r21) = ctx->r24;
        goto L_80802DD0;
    // 0x80802D3C: sb          $t8, 0x144($s5)
    MEM_B(0X144, ctx->r21) = ctx->r24;
L_80802D40:
    // 0x80802D40: jal         0x80088428
    // 0x80802D44: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    _gczoomboxdata_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80802D44: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_1:
    // 0x80802D48: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80802D4C: blez        $v0, L_80802DC0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80802D50: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80802DC0;
    }
    // 0x80802D50: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802D54: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    // 0x80802D58: addiu       $s3, $s5, 0x160
    ctx->r19 = ADD32(ctx->r21, 0X160);
    // 0x80802D5C: addiu       $s4, $s5, 0x14C
    ctx->r20 = ADD32(ctx->r21, 0X14C);
    // 0x80802D60: addiu       $s6, $sp, 0x5A
    ctx->r22 = ADD32(ctx->r29, 0X5A);
L_80802D64:
    // 0x80802D64: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80802D68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802D6C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80802D70: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80802D74: jal         0x80088430
    // 0x80802D78: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    _gczoomboxdata_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80802D78: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x80802D7C: lh          $t9, 0x160($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X160);
    // 0x80802D80: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80802D84: lh          $a1, 0x5A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X5A);
    // 0x80802D88: beq         $t9, $zero, L_80802DA8
    if (ctx->r25 == 0) {
        // 0x80802D8C: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_80802DA8;
    }
    // 0x80802D8C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80802D90: jal         0x808008F4
    // 0x80802D94: addu        $s1, $s5, $s0
    ctx->r17 = ADD32(ctx->r21, ctx->r16);
    func_808008F4_gczoombox(rdram, ctx);
        goto after_3;
    // 0x80802D94: addu        $s1, $s5, $s0
    ctx->r17 = ADD32(ctx->r21, ctx->r16);
    after_3:
    // 0x80802D98: sb          $v0, 0x144($s1)
    MEM_B(0X144, ctx->r17) = ctx->r2;
    // 0x80802D9C: lbu         $t0, 0x178($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X178);
    // 0x80802DA0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80802DA4: sb          $t1, 0x178($s5)
    MEM_B(0X178, ctx->r21) = ctx->r9;
L_80802DA8:
    // 0x80802DA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802DAC: slt         $at, $s0, $s7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80802DB0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80802DB4: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80802DB8: bne         $at, $zero, L_80802D64
    if (ctx->r1 != 0) {
        // 0x80802DBC: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80802D64;
    }
    // 0x80802DBC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_80802DC0:
    // 0x80802DC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802DC4: jal         0x800DC214
    // 0x80802DC8: lbu         $a1, 0x178($s5)
    ctx->r5 = MEM_BU(ctx->r21, 0X178);
    func_800DC214(rdram, ctx);
        goto after_4;
    // 0x80802DC8: lbu         $a1, 0x178($s5)
    ctx->r5 = MEM_BU(ctx->r21, 0X178);
    after_4:
    // 0x80802DCC: sb          $v0, 0x1D3($s5)
    MEM_B(0X1D3, ctx->r21) = ctx->r2;
L_80802DD0:
    // 0x80802DD0: jal         0x80802BF4
    // 0x80802DD4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80802BF4_gczoombox(rdram, ctx);
        goto after_5;
    // 0x80802DD4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x80802DD8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80802DDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802DE0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80802DE4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80802DE8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80802DEC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80802DF0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80802DF4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80802DF8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80802DFC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80802E00: jr          $ra
    // 0x80802E04: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80802E04: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8010E2C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E2C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010E2C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E2CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010E2D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010E2D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010E2D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010E2DC: sw          $a0, 0x7060($at)
    MEM_W(0X7060, ctx->r1) = ctx->r4;
    // 0x8010E2E0: jal         0x800DF8D4
    // 0x8010E2E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DF8D4(rdram, ctx);
        goto after_0;
    // 0x8010E2E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010E2E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8010E2EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010E2F0: addiu       $v1, $v1, 0x7060
    ctx->r3 = ADD32(ctx->r3, 0X7060);
    // 0x8010E2F4: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
    // 0x8010E2F8: beq         $a1, $zero, L_8010E310
    if (ctx->r5 == 0) {
        // 0x8010E2FC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8010E310;
    }
    // 0x8010E2FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010E300: jal         0x800B37E4
    // 0x8010E304: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    func_800B37E4(rdram, ctx);
        goto after_1;
    // 0x8010E304: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    after_1:
    // 0x8010E308: b           L_8010E31C
    // 0x8010E30C: nop

        goto L_8010E31C;
    // 0x8010E30C: nop

L_8010E310:
    // 0x8010E310: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8010E314: jal         0x8010E204
    // 0x8010E318: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_8010E204(rdram, ctx);
        goto after_2;
    // 0x8010E318: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
L_8010E31C:
    // 0x8010E31C: jal         0x8010E070
    // 0x8010E320: nop

    func_8010E070(rdram, ctx);
        goto after_3;
    // 0x8010E320: nop

    after_3:
    // 0x8010E324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010E328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010E32C: jr          $ra
    // 0x8010E330: nop

    return;
    // 0x8010E330: nop

;}
RECOMP_FUNC void _vplight_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089008: syscall     755
    recomp_syscall_handler(rdram, ctx, 0x80089008);
    return;
    // 0x8008900C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _baduo_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084940: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084940);
    return;
    // 0x80084944: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80801958_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801958: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080195C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801960: slti        $at, $a1, 0x1088
    ctx->r1 = SIGNED(ctx->r5) < 0X1088 ? 1 : 0;
    // 0x80801964: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801968: bne         $at, $zero, L_80801984
    if (ctx->r1 != 0) {
        // 0x8080196C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80801984;
    }
    // 0x8080196C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801970: addiu       $at, $zero, 0x10CC
    ctx->r1 = ADD32(0, 0X10CC);
    // 0x80801974: beql        $a1, $at, L_80801AC8
    if (ctx->r5 == ctx->r1) {
        // 0x80801978: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801AC8;
    }
    goto skip_0;
    // 0x80801978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080197C: b           L_80801AAC
    // 0x80801980: nop

        goto L_80801AAC;
    // 0x80801980: nop

L_80801984:
    // 0x80801984: slti        $at, $a1, 0xCEC
    ctx->r1 = SIGNED(ctx->r5) < 0XCEC ? 1 : 0;
    // 0x80801988: bne         $at, $zero, L_808019B0
    if (ctx->r1 != 0) {
        // 0x8080198C: addiu       $t6, $a1, -0x1082
        ctx->r14 = ADD32(ctx->r5, -0X1082);
            goto L_808019B0;
    }
    // 0x8080198C: addiu       $t6, $a1, -0x1082
    ctx->r14 = ADD32(ctx->r5, -0X1082);
    // 0x80801990: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80801994: beq         $at, $zero, L_80801AAC
    if (ctx->r1 == 0) {
        // 0x80801998: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801AAC;
    }
    // 0x80801998: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080199C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2D50) << 16);
    // 0x808019A0: addu        $at, $at, $t6
    gpr jr_addend_808019A8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808019A4: lw          $t6, 0x2D50($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(832, 0X2D50));
    // 0x808019A8: jr          $t6
    // 0x808019AC: nop

    switch (jr_addend_808019A8 >> 2) {
        case 0: goto L_808019C4; break;
        case 1: goto L_80801A14; break;
        case 2: goto L_80801A34; break;
        case 3: goto L_80801A24; break;
        case 4: goto L_80801A24; break;
        case 5: goto L_808019D8; break;
        default: switch_error(__func__, 0x808019A8, 0x80802D50);
    }
    // 0x808019AC: nop

L_808019B0:
    // 0x808019B0: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x808019B4: beq         $a1, $at, L_80801A8C
    if (ctx->r5 == ctx->r1) {
        // 0x808019B8: nop
    
            goto L_80801A8C;
    }
    // 0x808019B8: nop

    // 0x808019BC: b           L_80801AAC
    // 0x808019C0: nop

        goto L_80801AAC;
    // 0x808019C0: nop

L_808019C4:
    // 0x808019C4: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x808019C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808019CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808019D0: jal         0x800861A0
    // 0x808019D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808019D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
L_808019D8:
    // 0x808019D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019DC: jal         0x80800F84
    // 0x808019E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_1;
    // 0x808019E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x808019E4: jal         0x80104248
    // 0x808019E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_2;
    // 0x808019E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808019EC: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808019F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808019F4: jal         0x8008B1C8
    // 0x808019F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_3;
    // 0x808019F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808019FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A00: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801A04: jal         0x80802A00
    // 0x80801A08: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_4;
    // 0x80801A08: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_4:
    // 0x80801A0C: b           L_80801AAC
    // 0x80801A10: nop

        goto L_80801AAC;
    // 0x80801A10: nop

L_80801A14:
    // 0x80801A14: jal         0x80802910
    // 0x80801A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802910_chinflatableboss(rdram, ctx);
        goto after_5;
    // 0x80801A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801A1C: b           L_80801AAC
    // 0x80801A20: nop

        goto L_80801AAC;
    // 0x80801A20: nop

L_80801A24:
    // 0x80801A24: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x80801A28: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x80801A2C: b           L_80801AAC
    // 0x80801A30: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
        goto L_80801AAC;
    // 0x80801A30: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
L_80801A34:
    // 0x80801A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A38: jal         0x801020DC
    // 0x80801A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_801020DC(rdram, ctx);
        goto after_6;
    // 0x80801A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80801A40: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801A44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801A48: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A50: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801A54: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801A58: jal         0x80102FDC
    // 0x80801A5C: nop

    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x80801A5C: nop

    after_7:
    // 0x80801A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A64: jal         0x80800F84
    // 0x80801A68: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_8;
    // 0x80801A68: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_8:
    // 0x80801A6C: jal         0x8080267C
    // 0x80801A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080267C_chinflatableboss(rdram, ctx);
        goto after_9;
    // 0x80801A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A78: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80801A7C: jal         0x80802A00
    // 0x80801A80: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_10;
    // 0x80801A80: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_10:
    // 0x80801A84: b           L_80801AAC
    // 0x80801A88: nop

        goto L_80801AAC;
    // 0x80801A88: nop

L_80801A8C:
    // 0x80801A8C: blez        $a2, L_80801AA4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80801A90: nop
    
            goto L_80801AA4;
    }
    // 0x80801A90: nop

    // 0x80801A94: jal         0x80088188
    // 0x80801A98: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80801A98: nop

    after_11:
    // 0x80801A9C: b           L_80801AAC
    // 0x80801AA0: nop

        goto L_80801AAC;
    // 0x80801AA0: nop

L_80801AA4:
    // 0x80801AA4: jal         0x80088180
    // 0x80801AA8: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x80801AA8: nop

    after_12:
L_80801AAC:
    // 0x80801AAC: jal         0x80104248
    // 0x80801AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_13;
    // 0x80801AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80801AB4: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80801AB8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801ABC: jal         0x8008B1C8
    // 0x80801AC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_14;
    // 0x80801AC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x80801AC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801AC8:
    // 0x80801AC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801ACC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801AD0: jr          $ra
    // 0x80801AD4: nop

    return;
    // 0x80801AD4: nop

;}
RECOMP_FUNC void init_crc_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E848: jal         0x8001E868
    // 0x8001E84C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_crc_entry(rdram, ctx);
        goto after_0;
    // 0x8001E84C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8001E850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E854: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001E858: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E85C: sw          $t6, -0x164C($at)
    MEM_W(-0X164C, ctx->r1) = ctx->r14;
    // 0x8001E860: jr          $ra
    // 0x8001E864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001E864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808007DC_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007E4: beq         $a2, $zero, L_80800854
    if (ctx->r6 == 0) {
        // 0x808007E8: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80800854;
    }
    // 0x808007E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808007EC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2412, 0X138C) << 16);
    // 0x808007F0: addiu       $a3, $a3, 0x138C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2412, 0X138C));
    // 0x808007F4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808007F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808007FC: jal         0x80089D50
    // 0x80800800: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800800: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800804: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800808: jal         0x80089D30
    // 0x8080080C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080080C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800810: jal         0x800DC0C0
    // 0x80800814: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80800814: nop

    after_2:
    // 0x80800818: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2412, 0X1274) << 16);
    // 0x8080081C: lwc1        $f4, 0x1274($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2412, 0X1274));
    // 0x80800820: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2412, 0X13D0) << 16);
    // 0x80800824: addiu       $a0, $a0, 0x13D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2412, 0X13D0));
    // 0x80800828: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080082C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800830: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800834: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800838: bc1f        L_8080085C
    if (!c1cs) {
        // 0x8080083C: lui         $t6, 0x8080
        ctx->r14 = S32(RELOC_HI16(2412, 0X1398) << 16);
            goto L_8080085C;
    }
    // 0x8080083C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2412, 0X1398) << 16);
    // 0x80800840: addiu       $t6, $t6, 0x1398
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2412, 0X1398));
    // 0x80800844: jal         0x800BBCB8
    // 0x80800848: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800848: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x8080084C: b           L_80800860
    // 0x80800850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800860;
    // 0x80800850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800854:
    // 0x80800854: jal         0x80089D40
    // 0x80800858: nop

    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800858: nop

    after_4:
L_8080085C:
    // 0x8080085C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800860:
    // 0x80800860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800864: jr          $ra
    // 0x80800868: nop

    return;
    // 0x80800868: nop

;}
RECOMP_FUNC void func_8009B98C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B98C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B994: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B998: jal         0x800EE7F8
    // 0x8009B99C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009B99C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8009B9A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B9A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B9A8: jr          $ra
    // 0x8009B9AC: nop

    return;
    // 0x8009B9AC: nop

;}
RECOMP_FUNC void bstnt_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808021F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X25CC) << 16);
    // 0x808021F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808021F8: jr          $ra
    // 0x808021FC: lw          $v0, 0x25CC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X25CC));
    return;
    // 0x808021FC: lw          $v0, 0x25CC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X25CC));
;}
RECOMP_FUNC void func_80801EBC_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EBC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801EC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801EC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801EC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801ECC: jal         0x800DA298
    // 0x80801ED0: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80801ED0: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_0:
    // 0x80801ED4: beq         $v0, $zero, L_80801F6C
    if (ctx->r2 == 0) {
        // 0x80801ED8: nop
    
            goto L_80801F6C;
    }
    // 0x80801ED8: nop

    // 0x80801EDC: jal         0x80103EF4
    // 0x80801EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_1;
    // 0x80801EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801EE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X2904) << 16);
    // 0x80801EE8: lwc1        $f4, 0x2904($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X2904));
    // 0x80801EEC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801EF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801EF4: mul.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801EF8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801EFC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80801F00: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80801F04: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80801F08: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80801F0C: sub.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x80801F10: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    // 0x80801F14: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80801F18: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80801F1C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80801F20: jal         0x800EFA4C
    // 0x80801F24: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80801F24: nop

    after_2:
    // 0x80801F28: jal         0x800F54E4
    // 0x80801F2C: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80801F2C: nop

    after_3:
    // 0x80801F30: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80801F34: jal         0x80013970
    // 0x80801F38: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    func_80013970(rdram, ctx);
        goto after_4;
    // 0x80801F38: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    after_4:
    // 0x80801F3C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801F40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801F44: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801F48: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801F4C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80801F50: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80801F54: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80801F58: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80801F5C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80801F60: add.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80801F64: jal         0x800F4D74
    // 0x80801F68: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F4D74(rdram, ctx);
        goto after_5;
    // 0x80801F68: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
L_80801F6C:
    // 0x80801F6C: jal         0x80106790
    // 0x80801F70: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80801F70: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_6:
    // 0x80801F74: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801F78: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801F7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801F80: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80801F84: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80801F88: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    // 0x80801F8C: jal         0x800F12D4
    // 0x80801F90: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F12D4(rdram, ctx);
        goto after_7;
    // 0x80801F90: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x80801F94: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80801F98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801F9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801FA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801FA4: jr          $ra
    // 0x80801FA8: nop

    return;
    // 0x80801FA8: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082560: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082560);
    return;
    // 0x80082564: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bacough_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x8080000C: jr          $ra
    // 0x80800010: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    return;
    // 0x80800010: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
;}
RECOMP_FUNC void chcrate_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8080029C: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x808002A0: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x808002A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808002A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002AC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x808002B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002B4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x808002B8: addiu       $t7, $t6, -0x33
    ctx->r15 = ADD32(ctx->r14, -0X33);
    // 0x808002BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808002C0: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x808002C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808002C8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x808002CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808002D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808002D4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x808002D8: beq         $at, $zero, L_8080035C
    if (ctx->r1 == 0) {
        // 0x808002DC: swc1        $f18, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
            goto L_8080035C;
    }
    // 0x808002DC: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x808002E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1912, 0X3E0) << 16);
    // 0x808002E4: addu        $at, $at, $t7
    gpr jr_addend_808002EC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808002E8: lw          $t7, 0x3E0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1912, 0X3E0));
    // 0x808002EC: jr          $t7
    // 0x808002F0: nop

    switch (jr_addend_808002EC >> 2) {
        case 0: goto L_808002F4; break;
        case 1: goto L_808002F4; break;
        case 2: goto L_808002F4; break;
        case 3: goto L_808002F4; break;
        case 4: goto L_808002F4; break;
        case 5: goto L_808002F4; break;
        case 6: goto L_80800324; break;
        case 7: goto L_808002F4; break;
        case 8: goto L_808002F4; break;
        default: switch_error(__func__, 0x808002EC, 0x808003E0);
    }
    // 0x808002F0: nop

L_808002F4:
    // 0x808002F4: jal         0x808003AC
    // 0x808002F8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_808003AC_chcrate(rdram, ctx);
        goto after_0;
    // 0x808002F8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x808002FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800300: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800304: jal         0x80108474
    // 0x80800308: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_80108474(rdram, ctx);
        goto after_1;
    // 0x80800308: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x8080030C: lhu         $t8, 0x76($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X76);
    // 0x80800310: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800314: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80800318: ori         $t0, $t9, 0x1900
    ctx->r8 = ctx->r25 | 0X1900;
    // 0x8080031C: b           L_8080035C
    // 0x80800320: sh          $t0, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r8;
        goto L_8080035C;
    // 0x80800320: sh          $t0, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r8;
L_80800324:
    // 0x80800324: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800328: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080032C: jal         0x800D0B68
    // 0x80800330: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800330: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800334: bne         $v0, $zero, L_8080035C
    if (ctx->r2 != 0) {
        // 0x80800338: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_8080035C;
    }
    // 0x80800338: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8080033C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800340: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800344: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80800348: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8080034C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800350: jal         0x800D1000
    // 0x80800354: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_800D1000(rdram, ctx);
        goto after_3;
    // 0x80800354: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_3:
    // 0x80800358: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_8080035C:
    // 0x8080035C: beql        $v1, $zero, L_80800374
    if (ctx->r3 == 0) {
        // 0x80800360: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800374;
    }
    goto skip_0;
    // 0x80800360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800364: lbu         $t2, 0x71($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X71);
    // 0x80800368: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8080036C: sb          $t3, 0x71($v1)
    MEM_B(0X71, ctx->r3) = ctx->r11;
    // 0x80800370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800374:
    // 0x80800374: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800378: jr          $ra
    // 0x8080037C: nop

    return;
    // 0x8080037C: nop

;}
RECOMP_FUNC void func_808010E8_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010F0: jal         0x800845D0
    // 0x808010F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808010F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808010F8: jal         0x80800448
    // 0x808010FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808010FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801108: jr          $ra
    // 0x8080110C: nop

    return;
    // 0x8080110C: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083980: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083980);
    return;
    // 0x80083984: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void chlaundry_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808002A0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808002A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002A8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x808002AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002B4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x808002B8: lui         $a3, 0x242
    ctx->r7 = S32(0X242 << 16);
    // 0x808002BC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808002C0: ori         $a3, $a3, 0xA1
    ctx->r7 = ctx->r7 | 0XA1;
    // 0x808002C4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x808002C8: jal         0x800FAB50
    // 0x808002CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FAB50(rdram, ctx);
        goto after_0;
    // 0x808002CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808002D0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808002D4: jal         0x800EE904
    // 0x808002D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE904(rdram, ctx);
        goto after_1;
    // 0x808002D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x808002DC: addiu       $a0, $zero, 0x162
    ctx->r4 = ADD32(0, 0X162);
    // 0x808002E0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808002E4: jal         0x80108454
    // 0x808002E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108454(rdram, ctx);
        goto after_2;
    // 0x808002E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808002EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002F4: jal         0x80100094
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808002FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800300: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800304: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x80800308: jal         0x800EE7F8
    // 0x8080030C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080030C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800310: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800314: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800318: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8080031C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800320: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800324: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x80800328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080032C: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80800330: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80800334: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80800338: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2140, 0X3F0) << 16);
    // 0x8080033C: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    // 0x80800340: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x80800344: lwc1        $f16, 0x3F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2140, 0X3F0));
    // 0x80800348: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080034C: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80800350: jal         0x800EE7F8
    // 0x80800354: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800354: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_5:
    // 0x80800358: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8080035C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800360: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80800364: jal         0x800B5BE4
    // 0x80800368: swc1        $f18, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f18.u32l;
    func_800B5BE4(rdram, ctx);
        goto after_6;
    // 0x80800368: swc1        $f18, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f18.u32l;
    after_6:
    // 0x8080036C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2140, 0X448) << 16);
    // 0x80800370: addiu       $t7, $t7, 0x448
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2140, 0X448));
    // 0x80800374: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080037C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800380: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800384: jal         0x800BABB8
    // 0x80800388: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800388: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x8080038C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800390: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800394: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800398: jr          $ra
    // 0x8080039C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8080039C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800214_chworlddoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800218: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x8080021C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800220: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800224: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800228: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080022C: beq         $at, $zero, L_80800368
    if (ctx->r1 == 0) {
        // 0x80800230: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800368;
    }
    // 0x80800230: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800234: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800238: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2476, 0X940) << 16);
    // 0x8080023C: addu        $at, $at, $t7
    gpr jr_addend_80800244 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800240: lw          $t7, 0x940($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2476, 0X940));
    // 0x80800244: jr          $t7
    // 0x80800248: nop

    switch (jr_addend_80800244 >> 2) {
        case 0: goto L_8080024C; break;
        case 1: goto L_80800284; break;
        case 2: goto L_80800298; break;
        case 3: goto L_808002BC; break;
        case 4: goto L_808002F0; break;
        case 5: goto L_80800328; break;
        default: switch_error(__func__, 0x80800244, 0x80800940);
    }
    // 0x80800248: nop

L_8080024C:
    // 0x8080024C: jal         0x80800068
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800068_chworlddoors(rdram, ctx);
        goto after_0;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800254: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800258: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080025C: jal         0x800EE7F8
    // 0x80800260: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800260: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_1:
    // 0x80800264: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800268: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8080026C: addiu       $a3, $zero, 0x6830
    ctx->r7 = ADD32(0, 0X6830);
    // 0x80800270: jal         0x80085708
    // 0x80800274: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800274: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_2:
    // 0x80800278: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080027C: b           L_80800368
    // 0x80800280: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800368;
    // 0x80800280: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800284:
    // 0x80800284: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800288: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080028C: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x80800290: b           L_80800368
    // 0x80800294: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800368;
    // 0x80800294: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800298:
    // 0x80800298: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2476, 0X958) << 16);
    // 0x8080029C: lwc1        $f8, 0x958($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2476, 0X958));
    // 0x808002A0: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x808002A4: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x808002A8: ori         $a0, $a0, 0xFC90
    ctx->r4 = ctx->r4 | 0XFC90;
    // 0x808002AC: jal         0x800C3F48
    // 0x808002B0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_800C3F48(rdram, ctx);
        goto after_3;
    // 0x808002B0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x808002B4: b           L_8080036C
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080036C;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002BC:
    // 0x808002BC: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x808002C0: jal         0x800E1720
    // 0x808002C4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800E1720(rdram, ctx);
        goto after_4;
    // 0x808002C4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_4:
    // 0x808002C8: jal         0x80089D40
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808002D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808002E0: jal         0x8010A800
    // 0x808002E4: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_8010A800(rdram, ctx);
        goto after_6;
    // 0x808002E4: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_6:
    // 0x808002E8: b           L_8080036C
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080036C;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002F0:
    // 0x808002F0: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x808002F4: srl         $t8, $a0, 4
    ctx->r24 = S32(U32(ctx->r4) >> 4);
    // 0x808002F8: jal         0x8008A750
    // 0x808002FC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _sujiggy_entrypoint_23(rdram, ctx);
        goto after_7;
    // 0x808002FC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_7:
    // 0x80800300: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800304: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800308: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080030C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800310: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800314: jal         0x80101180
    // 0x80800318: nop

    func_80101180(rdram, ctx);
        goto after_8;
    // 0x80800318: nop

    after_8:
    // 0x8080031C: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800320: b           L_80800368
    // 0x80800324: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800368;
    // 0x80800324: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800328:
    // 0x80800328: lbu         $t0, 0x79($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X79);
    // 0x8080032C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800330: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80800334: srl         $t1, $t0, 4
    ctx->r9 = S32(U32(ctx->r8) >> 4);
    // 0x80800338: bnel        $t1, $zero, L_80800364
    if (ctx->r9 != 0) {
        // 0x8080033C: lwc1        $f6, 0x54($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
            goto L_80800364;
    }
    goto skip_0;
    // 0x8080033C: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    skip_0:
    // 0x80800340: jal         0x800E15CC
    // 0x80800344: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_800E15CC(rdram, ctx);
        goto after_9;
    // 0x80800344: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_9:
    // 0x80800348: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8080034C: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80800350: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800354: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800358: jal         0x80018820
    // 0x8080035C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_10;
    // 0x8080035C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
    // 0x80800360: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
L_80800364:
    // 0x80800364: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800368:
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080036C:
    // 0x8080036C: jal         0x80101FDC
    // 0x80800370: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80800370: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x80800374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

;}
RECOMP_FUNC void func_80803418_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803418: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080341C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803420: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80803424: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80803428: jal         0x80100094
    // 0x8080342C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080342C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80803430: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80803434: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80803438: jal         0x80803388
    // 0x8080343C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80803388_chintrochar(rdram, ctx);
        goto after_1;
    // 0x8080343C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80803440: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80803444: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80803448: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8080344C: bne         $t6, $zero, L_8080345C
    if (ctx->r14 != 0) {
        // 0x80803450: addiu       $a3, $sp, 0x28
        ctx->r7 = ADD32(ctx->r29, 0X28);
            goto L_8080345C;
    }
    // 0x80803450: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80803454: b           L_80803460
    // 0x80803458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80803460;
    // 0x80803458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8080345C:
    // 0x8080345C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80803460:
    // 0x80803460: lw          $a0, 0xCC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XCC);
    // 0x80803464: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x80803468: jal         0x80088A58
    // 0x8080346C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    _fxstep_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x8080346C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x80803470: beql        $v0, $zero, L_808034B8
    if (ctx->r2 == 0) {
        // 0x80803474: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808034B8;
    }
    goto skip_0;
    // 0x80803474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80803478: jal         0x800C4B64
    // 0x8080347C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_800C4B64(rdram, ctx);
        goto after_3;
    // 0x8080347C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80803480: jal         0x800C4B70
    // 0x80803484: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800C4B70(rdram, ctx);
        goto after_4;
    // 0x80803484: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80803488: jal         0x800C4B7C
    // 0x8080348C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800C4B7C(rdram, ctx);
        goto after_5;
    // 0x8080348C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80803490: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80803494: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1732, 0X52F8) << 16);
    // 0x80803498: addiu       $a3, $a3, 0x52F8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1732, 0X52F8));
    // 0x8080349C: lw          $a1, 0x70($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X70);
    // 0x808034A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808034A4: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x808034A8: andi        $t9, $a1, 0x1
    ctx->r25 = ctx->r5 & 0X1;
    // 0x808034AC: jal         0x8010D930
    // 0x808034B0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_8010D930(rdram, ctx);
        goto after_6;
    // 0x808034B0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_6:
    // 0x808034B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808034B8:
    // 0x808034B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808034BC: jr          $ra
    // 0x808034C0: nop

    return;
    // 0x808034C0: nop

;}
RECOMP_FUNC void _sueggmisc_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A358: syscall     837
    recomp_syscall_handler(rdram, ctx, 0x8008A358);
    return;
    // 0x8008A35C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801418_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801418: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080141C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801420: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801424: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801428: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080142C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80801430: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801434: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801438: jal         0x80100094
    // 0x8080143C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080143C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801440: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801444: jal         0x80103D48
    // 0x80801448: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80103D48(rdram, ctx);
        goto after_1;
    // 0x80801448: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8080144C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801450: jal         0x80100094
    // 0x80801454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80801454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801458: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080145C: jal         0x80089820
    // 0x80801460: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _suexpression_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80801460: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x80801464: lw          $t6, 0x64($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X64);
    // 0x80801468: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x8080146C: bltz        $t8, L_8080147C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801470: nop
    
            goto L_8080147C;
    }
    // 0x80801470: nop

    // 0x80801474: jal         0x8080267C
    // 0x80801478: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8080267C_chinflatableboss(rdram, ctx);
        goto after_4;
    // 0x80801478: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
L_8080147C:
    // 0x8080147C: jal         0x801040A8
    // 0x80801480: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_801040A8(rdram, ctx);
        goto after_5;
    // 0x80801480: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x80801484: jal         0x800DF72C
    // 0x80801488: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF72C(rdram, ctx);
        goto after_6;
    // 0x80801488: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8080148C: jal         0x800DF830
    // 0x80801490: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_7;
    // 0x80801490: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80801494: jal         0x80104130
    // 0x80801498: nop

    func_80104130(rdram, ctx);
        goto after_8;
    // 0x80801498: nop

    after_8:
    // 0x8080149C: jal         0x800DF738
    // 0x808014A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF738(rdram, ctx);
        goto after_9;
    // 0x808014A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x808014A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808014A8: jal         0x80103CDC
    // 0x808014AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80103CDC(rdram, ctx);
        goto after_10;
    // 0x808014AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x808014B0: jal         0x800DF818
    // 0x808014B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF818(rdram, ctx);
        goto after_11;
    // 0x808014B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x808014B8: jal         0x80089C90
    // 0x808014BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x808014BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x808014C0: lbu         $a1, 0x7B($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X7B);
    // 0x808014C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808014C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808014CC: srl         $t9, $a1, 6
    ctx->r25 = S32(U32(ctx->r5) >> 6);
    // 0x808014D0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x808014D4: jal         0x800DF660
    // 0x808014D8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800DF660(rdram, ctx);
        goto after_13;
    // 0x808014D8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_13:
    // 0x808014DC: jal         0x80100AC4
    // 0x808014E0: lh          $a0, 0x60($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X60);
    func_80100AC4(rdram, ctx);
        goto after_14;
    // 0x808014E0: lh          $a0, 0x60($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X60);
    after_14:
    // 0x808014E4: jal         0x800DF720
    // 0x808014E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_15;
    // 0x808014E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x808014EC: jal         0x80101934
    // 0x808014F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80101934(rdram, ctx);
        goto after_16;
    // 0x808014F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_16:
    // 0x808014F4: jal         0x80103D70
    // 0x808014F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80103D70(rdram, ctx);
        goto after_17;
    // 0x808014F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_17:
    // 0x808014FC: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80801500: addiu       $s2, $zero, 0xF
    ctx->r18 = ADD32(0, 0XF);
    // 0x80801504: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80801508:
    // 0x80801508: addiu       $a0, $s0, 0x3
    ctx->r4 = ADD32(ctx->r16, 0X3);
    // 0x8080150C: jal         0x800DF744
    // 0x80801510: lbu         $a1, 0x478($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X478);
    func_800DF744(rdram, ctx);
        goto after_18;
    // 0x80801510: lbu         $a1, 0x478($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X478);
    after_18:
    // 0x80801514: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801518: bne         $s0, $s2, L_80801508
    if (ctx->r16 != ctx->r18) {
        // 0x8080151C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80801508;
    }
    // 0x8080151C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801520: lbu         $t1, 0x7E($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X7E);
    // 0x80801524: lbu         $t3, 0x65($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X65);
    // 0x80801528: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8080152C: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x80801530: sb          $t2, 0x7E($s3)
    MEM_B(0X7E, ctx->r19) = ctx->r10;
    // 0x80801534: sb          $t4, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r12;
    // 0x80801538: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080153C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801540: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801544: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801548: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080154C: jr          $ra
    // 0x80801550: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801550: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8008F8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F8B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F8B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F8B8: jal         0x800F54E4
    // 0x8008F8BC: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008F8BC: nop

    after_0:
    // 0x8008F8C0: jal         0x800F497C
    // 0x8008F8C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F497C(rdram, ctx);
        goto after_1;
    // 0x8008F8C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008F8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F8CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F8D0: jr          $ra
    // 0x8008F8D4: nop

    return;
    // 0x8008F8D4: nop

;}
RECOMP_FUNC void baflameline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800434: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800438: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8080043C: jr          $ra
    // 0x80800440: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800440: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800F4924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4924: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F492C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4934: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4938: jal         0x800A17A8
    // 0x800F493C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A17A8(rdram, ctx);
        goto after_0;
    // 0x800F493C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4948: jr          $ra
    // 0x800F494C: nop

    return;
    // 0x800F494C: nop

;}
RECOMP_FUNC void func_80800008_bapackctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x80800080
    // 0x80800014: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    bapackctrl_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800018: beq         $v0, $zero, L_80800048
    if (ctx->r2 == 0) {
        // 0x8080001C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800048;
    }
    // 0x8080001C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800020: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(477, 0X380) << 16);
    // 0x80800024: lwc1        $f0, 0x380($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(477, 0X380));
    // 0x80800028: lui         $a3, 0x4026
    ctx->r7 = S32(0X4026 << 16);
    // 0x8080002C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800030: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800034: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800038: jal         0x800EFA4C
    // 0x8080003C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x8080003C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800040: b           L_80800068
    // 0x80800044: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80800068;
    // 0x80800044: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800048:
    // 0x80800048: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080004C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800050: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800054: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800058: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080005C: jal         0x800EFA4C
    // 0x80800060: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80800060: nop

    after_2:
    // 0x80800064: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800068:
    // 0x80800068: jal         0x800984F0
    // 0x8080006C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800984F0(rdram, ctx);
        goto after_3;
    // 0x8080006C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800074: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void _chkingjinjo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864B8: syscall     330
    recomp_syscall_handler(rdram, ctx, 0x800864B8);
    return;
    // 0x800864BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80807DD4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807DD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80807DD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807DDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807DE0: jal         0x800A3404
    // 0x80807DE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A3404(rdram, ctx);
        goto after_0;
    // 0x80807DE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80807DE8: beq         $v0, $zero, L_80807E3C
    if (ctx->r2 == 0) {
        // 0x80807DEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80807E3C;
    }
    // 0x80807DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807DF0: jal         0x808078F4
    // 0x80807DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808078F4_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80807DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80807DF8: jal         0x80807D70
    // 0x80807DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807D70_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80807DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80807E00: jal         0x8080053C
    // 0x80807E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080053C_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80807E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80807E08: jal         0x8009B4FC
    // 0x80807E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B4FC(rdram, ctx);
        goto after_4;
    // 0x80807E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80807E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807E14: jal         0x800936E8
    // 0x80807E18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800936E8(rdram, ctx);
        goto after_5;
    // 0x80807E18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80807E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807E20: jal         0x8009337C
    // 0x80807E24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009337C(rdram, ctx);
        goto after_6;
    // 0x80807E24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80807E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807E2C: jal         0x80093370
    // 0x80807E30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80093370(rdram, ctx);
        goto after_7;
    // 0x80807E30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80807E34: b           L_80807EDC
    // 0x80807E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80807EDC;
    // 0x80807E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807E3C:
    // 0x80807E3C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80807E40: addiu       $a2, $sp, 0x26
    ctx->r6 = ADD32(ctx->r29, 0X26);
    // 0x80807E44: jal         0x80084F38
    // 0x80807E48: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    _bapreload_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80807E48: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_8:
    // 0x80807E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807E50: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80807E54: addiu       $a2, $sp, 0x22
    ctx->r6 = ADD32(ctx->r29, 0X22);
    // 0x80807E58: jal         0x80084F38
    // 0x80807E5C: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    _bapreload_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80807E5C: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_9:
    // 0x80807E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807E64: jal         0x800936CC
    // 0x80807E68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800936CC(rdram, ctx);
        goto after_10;
    // 0x80807E68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80807E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807E70: jal         0x80092EC8
    // 0x80807E74: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    func_80092EC8(rdram, ctx);
        goto after_11;
    // 0x80807E74: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_11:
    // 0x80807E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807E7C: jal         0x80093230
    // 0x80807E80: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80093230(rdram, ctx);
        goto after_12;
    // 0x80807E80: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_12:
    // 0x80807E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807E88: jal         0x8009337C
    // 0x80807E8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009337C(rdram, ctx);
        goto after_13;
    // 0x80807E8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80807E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807E94: jal         0x8009359C
    // 0x80807E98: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    func_8009359C(rdram, ctx);
        goto after_14;
    // 0x80807E98: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    after_14:
    // 0x80807E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807EA0: jal         0x800936D8
    // 0x80807EA4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800936D8(rdram, ctx);
        goto after_15;
    // 0x80807EA4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_15:
    // 0x80807EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807EAC: jal         0x800936E8
    // 0x80807EB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800936E8(rdram, ctx);
        goto after_16;
    // 0x80807EB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80807EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807EB8: jal         0x800A34E4
    // 0x80807EBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A34E4(rdram, ctx);
        goto after_17;
    // 0x80807EBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80807EC0: jal         0x8008CF7C
    // 0x80807EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008CF7C(rdram, ctx);
        goto after_18;
    // 0x80807EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80807EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807ECC: addiu       $a1, $zero, 0x310
    ctx->r5 = ADD32(0, 0X310);
    // 0x80807ED0: jal         0x808003B4
    // 0x80807ED4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_808003B4_bsfirstp(rdram, ctx);
        goto after_19;
    // 0x80807ED4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_19:
    // 0x80807ED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807EDC:
    // 0x80807EDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807EE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80807EE4: jr          $ra
    // 0x80807EE8: nop

    return;
    // 0x80807EE8: nop

;}
RECOMP_FUNC void func_800997BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800997BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800997C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800997C4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800997C8: jal         0x8009C128
    // 0x800997CC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800997CC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800997D0: jal         0x8009C984
    // 0x800997D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x800997D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x800997D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800997DC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800997E0: jal         0x800EEB9C
    // 0x800997E4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x800997E4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_2:
    // 0x800997E8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800997EC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800997F0: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800997F4: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800997F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800997FC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80099800: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80099804: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80099808: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8009980C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80099810: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80099814: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80099818: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8009981C: jal         0x800A34AC
    // 0x80099820: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    func_800A34AC(rdram, ctx);
        goto after_3;
    // 0x80099820: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80099824: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80099828: jal         0x800A17A8
    // 0x8009982C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_4;
    // 0x8009982C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_4:
    // 0x80099830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099834: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80099838: jr          $ra
    // 0x8009983C: nop

    return;
    // 0x8009983C: nop

;}
RECOMP_FUNC void func_8008ADE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ADE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008ADE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008ADEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008ADF0: lbu         $t6, 0x1A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1A);
    // 0x8008ADF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008ADF8: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8008ADFC: beq         $at, $zero, L_8008AEA0
    if (ctx->r1 == 0) {
        // 0x8008AE00: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8008AEA0;
    }
    // 0x8008AE00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008AE04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AE08: addu        $at, $at, $t6
    gpr jr_addend_8008AE10 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008AE0C: lw          $t6, 0x4A9C($at)
    ctx->r14 = ADD32(ctx->r1, 0X4A9C);
    // 0x8008AE10: jr          $t6
    // 0x8008AE14: nop

    switch (jr_addend_8008AE10 >> 2) {
        case 0: goto L_8008AEA0; break;
        case 1: goto L_8008AE18; break;
        case 2: goto L_8008AE3C; break;
        case 3: goto L_8008AE84; break;
        case 4: goto L_8008AE60; break;
        default: switch_error(__func__, 0x8008AE10, 0x80124A9C);
    }
    // 0x8008AE14: nop

L_8008AE18:
    // 0x8008AE18: jal         0x8008AC4C
    // 0x8008AE1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AC4C(rdram, ctx);
        goto after_0;
    // 0x8008AE1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8008AE20: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8008AE24: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8008AE28: sll         $t7, $a1, 29
    ctx->r15 = S32(ctx->r5 << 29);
    // 0x8008AE2C: jal         0x8008C1CC
    // 0x8008AE30: srl         $a1, $t7, 31
    ctx->r5 = S32(U32(ctx->r15) >> 31);
    func_8008C1CC(rdram, ctx);
        goto after_1;
    // 0x8008AE30: srl         $a1, $t7, 31
    ctx->r5 = S32(U32(ctx->r15) >> 31);
    after_1:
    // 0x8008AE34: b           L_8008AEA4
    // 0x8008AE38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008AEA4;
    // 0x8008AE38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AE3C:
    // 0x8008AE3C: jal         0x8008AAC0
    // 0x8008AE40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AAC0(rdram, ctx);
        goto after_2;
    // 0x8008AE40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008AE44: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8008AE48: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8008AE4C: sll         $t9, $a1, 29
    ctx->r25 = S32(ctx->r5 << 29);
    // 0x8008AE50: jal         0x8008C1CC
    // 0x8008AE54: srl         $a1, $t9, 31
    ctx->r5 = S32(U32(ctx->r25) >> 31);
    func_8008C1CC(rdram, ctx);
        goto after_3;
    // 0x8008AE54: srl         $a1, $t9, 31
    ctx->r5 = S32(U32(ctx->r25) >> 31);
    after_3:
    // 0x8008AE58: b           L_8008AEA4
    // 0x8008AE5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008AEA4;
    // 0x8008AE5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AE60:
    // 0x8008AE60: jal         0x8008AB84
    // 0x8008AE64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AB84(rdram, ctx);
        goto after_4;
    // 0x8008AE64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008AE68: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8008AE6C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8008AE70: sll         $t1, $a1, 29
    ctx->r9 = S32(ctx->r5 << 29);
    // 0x8008AE74: jal         0x8008C1CC
    // 0x8008AE78: srl         $a1, $t1, 31
    ctx->r5 = S32(U32(ctx->r9) >> 31);
    func_8008C1CC(rdram, ctx);
        goto after_5;
    // 0x8008AE78: srl         $a1, $t1, 31
    ctx->r5 = S32(U32(ctx->r9) >> 31);
    after_5:
    // 0x8008AE7C: b           L_8008AEA4
    // 0x8008AE80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008AEA4;
    // 0x8008AE80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AE84:
    // 0x8008AE84: jal         0x8008AA0C
    // 0x8008AE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AA0C(rdram, ctx);
        goto after_6;
    // 0x8008AE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8008AE8C: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8008AE90: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8008AE94: sll         $t3, $a1, 29
    ctx->r11 = S32(ctx->r5 << 29);
    // 0x8008AE98: jal         0x8008C1CC
    // 0x8008AE9C: srl         $a1, $t3, 31
    ctx->r5 = S32(U32(ctx->r11) >> 31);
    func_8008C1CC(rdram, ctx);
        goto after_7;
    // 0x8008AE9C: srl         $a1, $t3, 31
    ctx->r5 = S32(U32(ctx->r11) >> 31);
    after_7:
L_8008AEA0:
    // 0x8008AEA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008AEA4:
    // 0x8008AEA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AEA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008AEAC: jr          $ra
    // 0x8008AEB0: nop

    return;
    // 0x8008AEB0: nop

;}
