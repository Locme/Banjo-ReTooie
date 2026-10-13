#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chpowerhutwitchy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086070: syscall     275
    recomp_syscall_handler(rdram, ctx, 0x80086070);
    return;
    // 0x80086074: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800008_batranslate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80092B04
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092B04(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: jal         0x800B27E0
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_1;
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800028: jal         0x80087A10
    // 0x8080002C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbskeleton_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080002C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800030: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800034: jal         0x800EF334
    // 0x80800038: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80800038: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8080003C: jal         0x8009C984
    // 0x80800040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x80800040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800044: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800048: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080004C: jal         0x800EF934
    // 0x80800050: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800EF934(rdram, ctx);
        goto after_5;
    // 0x80800050: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_80800190_chmoley(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800194: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800198: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080019C: jal         0x80104248
    // 0x808001A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x808001A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001A4: bne         $v0, $zero, L_808001B4
    if (ctx->r2 != 0) {
        // 0x808001A8: nop
    
            goto L_808001B4;
    }
    // 0x808001A8: nop

    // 0x808001AC: b           L_80800260
    // 0x808001B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x808001B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001B4:
    // 0x808001B4: jal         0x801022E4
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001BC: addiu       $at, $zero, 0x2BC
    ctx->r1 = ADD32(0, 0X2BC);
    // 0x808001C0: beq         $v0, $at, L_808001DC
    if (ctx->r2 == ctx->r1) {
        // 0x808001C4: addiu       $at, $zero, 0x2BF
        ctx->r1 = ADD32(0, 0X2BF);
            goto L_808001DC;
    }
    // 0x808001C4: addiu       $at, $zero, 0x2BF
    ctx->r1 = ADD32(0, 0X2BF);
    // 0x808001C8: beq         $v0, $at, L_808001E4
    if (ctx->r2 == ctx->r1) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E4;
    }
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: addiu       $at, $zero, 0x2C8
    ctx->r1 = ADD32(0, 0X2C8);
    // 0x808001D4: bne         $v0, $at, L_80800240
    if (ctx->r2 != ctx->r1) {
        // 0x808001D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800240;
    }
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001DC:
    // 0x808001DC: b           L_80800260
    // 0x808001E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x808001E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001E4:
    // 0x808001E4: lui         $a1, 0x3DBA
    ctx->r5 = S32(0X3DBA << 16);
    // 0x808001E8: jal         0x80101E14
    // 0x808001EC: ori         $a1, $a1, 0x29C7
    ctx->r5 = ctx->r5 | 0X29C7;
    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x808001EC: ori         $a1, $a1, 0x29C7
    ctx->r5 = ctx->r5 | 0X29C7;
    after_2:
    // 0x808001F0: beq         $v0, $zero, L_80800208
    if (ctx->r2 == 0) {
        // 0x808001F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800208;
    }
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808001FC: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800200: b           L_80800228
    // 0x80800204: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
        goto L_80800228;
    // 0x80800204: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_80800208:
    // 0x80800208: lui         $a1, 0x3F54
    ctx->r5 = S32(0X3F54 << 16);
    // 0x8080020C: jal         0x80101E14
    // 0x80800210: ori         $a1, $a1, 0x5A1D
    ctx->r5 = ctx->r5 | 0X5A1D;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x80800210: ori         $a1, $a1, 0x5A1D
    ctx->r5 = ctx->r5 | 0X5A1D;
    after_3:
    // 0x80800214: beq         $v0, $zero, L_80800228
    if (ctx->r2 == 0) {
        // 0x80800218: nop
    
            goto L_80800228;
    }
    // 0x80800218: nop

    // 0x8080021C: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800220: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80800224: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_80800228:
    // 0x80800228: jal         0x80101DDC
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_4;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800230: beql        $v0, $zero, L_80800260
    if (ctx->r2 == 0) {
        // 0x80800234: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800260;
    }
    goto skip_0;
    // 0x80800234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800238: b           L_80800260
    // 0x8080023C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x8080023C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800240:
    // 0x80800240: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800244: jal         0x80101E14
    // 0x80800248: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x80800248: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_5:
    // 0x8080024C: beql        $v0, $zero, L_80800260
    if (ctx->r2 == 0) {
        // 0x80800250: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800260;
    }
    goto skip_1;
    // 0x80800250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800254: b           L_80800260
    // 0x80800258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x80800258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080025C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800260:
    // 0x80800260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void _bsdronelook_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083138: syscall     45
    recomp_syscall_handler(rdram, ctx, 0x80083138);
    return;
    // 0x8008313C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800820_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800828: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080082C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800830: lbu         $a3, 0x5F($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X5F);
    // 0x80800834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800838: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(748, 0X1B10) << 16);
    // 0x8080083C: bnel        $a3, $zero, L_8080085C
    if (ctx->r7 != 0) {
        // 0x80800840: andi        $a0, $a3, 0xFF
        ctx->r4 = ctx->r7 & 0XFF;
            goto L_8080085C;
    }
    goto skip_0;
    // 0x80800840: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    skip_0:
    // 0x80800844: jal         0x800C4350
    // 0x80800848: addiu       $a2, $a2, 0x1B10
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(748, 0X1B10));
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x80800848: addiu       $a2, $a2, 0x1B10
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(748, 0X1B10));
    after_0:
    // 0x8080084C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800850: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    // 0x80800854: sb          $v0, 0x5F($v1)
    MEM_B(0X5F, ctx->r3) = ctx->r2;
    // 0x80800858: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
L_8080085C:
    // 0x8080085C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800860: jal         0x800C4350
    // 0x80800864: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x80800864: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080086C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800870: jr          $ra
    // 0x80800874: nop

    return;
    // 0x80800874: nop

;}
RECOMP_FUNC void func_80800D08_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D14: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800D18: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80800D1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D24: beq         $v0, $at, L_80800D3C
    if (ctx->r2 == ctx->r1) {
        // 0x80800D28: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800D3C;
    }
    // 0x80800D28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D2C: beq         $v0, $at, L_80800D5C
    if (ctx->r2 == ctx->r1) {
        // 0x80800D30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D5C;
    }
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D34: b           L_80800E18
    // 0x80800D38: nop

        goto L_80800E18;
    // 0x80800D38: nop

L_80800D3C:
    // 0x80800D3C: jal         0x80084DD8
    // 0x80800D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800D44: beq         $v0, $zero, L_80800E18
    if (ctx->r2 == 0) {
        // 0x80800D48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E18;
    }
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D4C: jal         0x80800B60
    // 0x80800D50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B60_bstnt(rdram, ctx);
        goto after_1;
    // 0x80800D50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800D54: b           L_80800E18
    // 0x80800D58: nop

        goto L_80800E18;
    // 0x80800D58: nop

L_80800D5C:
    // 0x80800D5C: lui         $a1, 0x3DF2
    ctx->r5 = S32(0X3DF2 << 16);
    // 0x80800D60: jal         0x8008CB10
    // 0x80800D64: ori         $a1, $a1, 0x4745
    ctx->r5 = ctx->r5 | 0X4745;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800D64: ori         $a1, $a1, 0x4745
    ctx->r5 = ctx->r5 | 0X4745;
    after_2:
    // 0x80800D68: beql        $v0, $zero, L_80800D7C
    if (ctx->r2 == 0) {
        // 0x80800D6C: lui         $a1, 0x3F17
        ctx->r5 = S32(0X3F17 << 16);
            goto L_80800D7C;
    }
    goto skip_0;
    // 0x80800D6C: lui         $a1, 0x3F17
    ctx->r5 = S32(0X3F17 << 16);
    skip_0:
    // 0x80800D70: jal         0x80800068
    // 0x80800D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800068_bstnt(rdram, ctx);
        goto after_3;
    // 0x80800D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800D78: lui         $a1, 0x3F17
    ctx->r5 = S32(0X3F17 << 16);
L_80800D7C:
    // 0x80800D7C: ori         $a1, $a1, 0x8D50
    ctx->r5 = ctx->r5 | 0X8D50;
    // 0x80800D80: jal         0x8008CB10
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800D88: beql        $v0, $zero, L_80800D9C
    if (ctx->r2 == 0) {
        // 0x80800D8C: lui         $a1, 0x3F26
        ctx->r5 = S32(0X3F26 << 16);
            goto L_80800D9C;
    }
    goto skip_1;
    // 0x80800D8C: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    skip_1:
    // 0x80800D90: jal         0x80800000
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bstnt(rdram, ctx);
        goto after_5;
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800D98: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
L_80800D9C:
    // 0x80800D9C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800DA0: jal         0x8008CB10
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800DA8: beql        $v0, $zero, L_80800DBC
    if (ctx->r2 == 0) {
        // 0x80800DAC: lui         $a1, 0x3F2A
        ctx->r5 = S32(0X3F2A << 16);
            goto L_80800DBC;
    }
    goto skip_2;
    // 0x80800DAC: lui         $a1, 0x3F2A
    ctx->r5 = S32(0X3F2A << 16);
    skip_2:
    // 0x80800DB0: jal         0x8009514C
    // 0x80800DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_7;
    // 0x80800DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800DB8: lui         $a1, 0x3F2A
    ctx->r5 = S32(0X3F2A << 16);
L_80800DBC:
    // 0x80800DBC: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    // 0x80800DC0: jal         0x8008CB10
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800DC8: beq         $v0, $zero, L_80800DE4
    if (ctx->r2 == 0) {
        // 0x80800DCC: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80800DE4;
    }
    // 0x80800DCC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800DD0: lw          $a0, 0x164($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X164);
    // 0x80800DD4: jal         0x8010114C
    // 0x80800DD8: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    func_8010114C(rdram, ctx);
        goto after_9;
    // 0x80800DD8: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    after_9:
    // 0x80800DDC: jal         0x8080009C
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_bstnt(rdram, ctx);
        goto after_10;
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80800DE4:
    // 0x80800DE4: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80800DE8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800DEC: jal         0x8008CB10
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_11;
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800DF4: beq         $v0, $zero, L_80800E04
    if (ctx->r2 == 0) {
        // 0x80800DF8: nop
    
            goto L_80800E04;
    }
    // 0x80800DF8: nop

    // 0x80800DFC: jal         0x800951B4
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_12;
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_80800E04:
    // 0x80800E04: jal         0x8008CAEC
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_13;
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800E0C: beq         $v0, $zero, L_80800E18
    if (ctx->r2 == 0) {
        // 0x80800E10: addiu       $t6, $zero, 0x10C
        ctx->r14 = ADD32(0, 0X10C);
            goto L_80800E18;
    }
    // 0x80800E10: addiu       $t6, $zero, 0x10C
    ctx->r14 = ADD32(0, 0X10C);
    // 0x80800E14: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800E18:
    // 0x80800E18: jal         0x80800F94
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstnt_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E24: jal         0x8009E5C8
    // 0x80800E28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x80800E28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x80800E2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E38: jr          $ra
    // 0x80800E3C: nop

    return;
    // 0x80800E3C: nop

;}
RECOMP_FUNC void func_80800680_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800688: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080068C: jal         0x80102424
    // 0x80800690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800694: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080069C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808006A0: bne         $t6, $at, L_808006E8
    if (ctx->r14 != ctx->r1) {
        // 0x808006A4: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_808006E8;
    }
    // 0x808006A4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808006A8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(896, 0X1354) << 16);
    // 0x808006AC: addiu       $a2, $a2, 0x1354
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(896, 0X1354));
    // 0x808006B0: jal         0x80089D18
    // 0x808006B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808006B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808006B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(896, 0X11E0) << 16);
    // 0x808006C0: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x808006C4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808006C8: bgez        $t9, L_808006E0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808006CC: nop
    
            goto L_808006E0;
    }
    // 0x808006CC: nop

    // 0x808006D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(896, 0X11DC) << 16);
    // 0x808006D4: lwc1        $f4, 0x11DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(896, 0X11DC));
    // 0x808006D8: b           L_808006E8
    // 0x808006DC: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
        goto L_808006E8;
    // 0x808006DC: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
L_808006E0:
    // 0x808006E0: lwc1        $f6, 0x11E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(896, 0X11E0));
    // 0x808006E4: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
L_808006E8:
    // 0x808006E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006F0: jr          $ra
    // 0x808006F4: nop

    return;
    // 0x808006F4: nop

;}
RECOMP_FUNC void func_800267F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800267F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800267F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800267F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800267FC: jal         0x8002FEC0
    // 0x80026800: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80026800: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80026804: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026808: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002680C: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x80026810: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80026814: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x80026818: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x8002681C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80026820: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80026824: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80026828: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8002682C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80026830: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80026834: lw          $t3, 0x11F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11F4);
    // 0x80026838: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002683C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80026840: jal         0x8002FEC0
    // 0x80026844: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80026844: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80026848: b           L_80026850
    // 0x8002684C: nop

        goto L_80026850;
    // 0x8002684C: nop

L_80026850:
    // 0x80026850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026854: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026858: jr          $ra
    // 0x8002685C: nop

    return;
    // 0x8002685C: nop

;}
RECOMP_FUNC void ncbajig_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x80800004: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801CA0_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801CA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801CA8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801CAC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801CB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801CB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801CB8: jal         0x80100094
    // 0x80801CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801CC0: jal         0x80101080
    // 0x80801CC4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_80101080(rdram, ctx);
        goto after_1;
    // 0x80801CC4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801CC8: jal         0x80106790
    // 0x80801CCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80801CCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801CD0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801CD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801CD8: jal         0x800866B8
    // 0x80801CDC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80801CDC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_3:
    // 0x80801CE0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801CE4: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    // 0x80801CE8: jal         0x80086688
    // 0x80801CEC: lui         $a2, 0x44C8
    ctx->r6 = S32(0X44C8 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80801CEC: lui         $a2, 0x44C8
    ctx->r6 = S32(0X44C8 << 16);
    after_4:
    // 0x80801CF0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801CF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801CF8: jal         0x800866D0
    // 0x80801CFC: lui         $a2, 0x3FA0
    ctx->r6 = S32(0X3FA0 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x80801CFC: lui         $a2, 0x3FA0
    ctx->r6 = S32(0X3FA0 << 16);
    after_5:
    // 0x80801D00: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80801D04: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801D08: addiu       $t8, $t7, -0x8
    ctx->r24 = ADD32(ctx->r15, -0X8);
    // 0x80801D0C: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x80801D10: beq         $at, $zero, L_80801DB0
    if (ctx->r1 == 0) {
        // 0x80801D14: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801DB0;
    }
    // 0x80801D14: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801D18: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X2570) << 16);
    // 0x80801D1C: addu        $at, $at, $t8
    gpr jr_addend_80801D24 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801D20: lw          $t8, 0x2570($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1312, 0X2570));
    // 0x80801D24: jr          $t8
    // 0x80801D28: nop

    switch (jr_addend_80801D24 >> 2) {
        case 0: goto L_80801D2C; break;
        case 1: goto L_80801DB0; break;
        case 2: goto L_80801DB0; break;
        case 3: goto L_80801DB0; break;
        case 4: goto L_80801D48; break;
        case 5: goto L_80801DB0; break;
        case 6: goto L_80801DB0; break;
        case 7: goto L_80801DB0; break;
        case 8: goto L_80801D64; break;
        case 9: goto L_80801DB0; break;
        case 10: goto L_80801DB0; break;
        case 11: goto L_80801DB0; break;
        case 12: goto L_80801D80; break;
        case 13: goto L_80801DB0; break;
        case 14: goto L_80801DB0; break;
        case 15: goto L_80801DB0; break;
        case 16: goto L_80801D9C; break;
        default: switch_error(__func__, 0x80801D24, 0x80802570);
    }
    // 0x80801D28: nop

L_80801D2C:
    // 0x80801D2C: addiu       $s1, $zero, 0x50
    ctx->r17 = ADD32(0, 0X50);
    // 0x80801D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801D38: jal         0x80801640
    // 0x80801D3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801640_chstatueboss(rdram, ctx);
        goto after_6;
    // 0x80801D3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80801D40: b           L_80801DB4
    // 0x80801D44: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_80801DB4;
    // 0x80801D44: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_80801D48:
    // 0x80801D48: addiu       $s1, $zero, 0x50
    ctx->r17 = ADD32(0, 0X50);
    // 0x80801D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801D54: jal         0x80801640
    // 0x80801D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801640_chstatueboss(rdram, ctx);
        goto after_7;
    // 0x80801D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80801D5C: b           L_80801DB4
    // 0x80801D60: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_80801DB4;
    // 0x80801D60: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_80801D64:
    // 0x80801D64: addiu       $s1, $zero, 0x50
    ctx->r17 = ADD32(0, 0X50);
    // 0x80801D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801D70: jal         0x80801640
    // 0x80801D74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801640_chstatueboss(rdram, ctx);
        goto after_8;
    // 0x80801D74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80801D78: b           L_80801DB4
    // 0x80801D7C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_80801DB4;
    // 0x80801D7C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_80801D80:
    // 0x80801D80: addiu       $s1, $zero, 0x50
    ctx->r17 = ADD32(0, 0X50);
    // 0x80801D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D88: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801D8C: jal         0x80801640
    // 0x80801D90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801640_chstatueboss(rdram, ctx);
        goto after_9;
    // 0x80801D90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80801D94: b           L_80801DB4
    // 0x80801D98: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_80801DB4;
    // 0x80801D98: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_80801D9C:
    // 0x80801D9C: addiu       $s1, $zero, 0x50
    ctx->r17 = ADD32(0, 0X50);
    // 0x80801DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DA4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801DA8: jal         0x80801640
    // 0x80801DAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801640_chstatueboss(rdram, ctx);
        goto after_10;
    // 0x80801DAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
L_80801DB0:
    // 0x80801DB0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_80801DB4:
    // 0x80801DB4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1312, 0X2894) << 16);
    // 0x80801DB8: addiu       $a2, $a2, 0x2894
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1312, 0X2894));
    // 0x80801DBC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80801DC0: jal         0x80089D18
    // 0x80801DC4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80801DC4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_11:
    // 0x80801DC8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801DCC: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1312, 0X285C) << 16);
    // 0x80801DD0: addiu       $t9, $t9, 0x285C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1312, 0X285C));
    // 0x80801DD4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801DD8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801DDC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80801DE0: jal         0x800BBCB8
    // 0x80801DE4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800BBCB8(rdram, ctx);
        goto after_12;
    // 0x80801DE4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_12:
    // 0x80801DE8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80801DEC: jal         0x80106790
    // 0x80801DF0: lw          $a0, 0x8C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8C);
    func_80106790(rdram, ctx);
        goto after_13;
    // 0x80801DF0: lw          $a0, 0x8C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8C);
    after_13:
    // 0x80801DF4: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x80801DF8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801DFC: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80801E00: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801E04: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80801E08: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80801E0C: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x80801E10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801E14: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801E18: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E1C: jr          $ra
    // 0x80801E20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801E20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_808009D4_charmouredcaveman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009DC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808009E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808009E4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808009E8: beq         $t6, $at, L_80800A10
    if (ctx->r14 == ctx->r1) {
        // 0x808009EC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800A10;
    }
    // 0x808009EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808009F0: bne         $t6, $at, L_80800A08
    if (ctx->r14 != ctx->r1) {
        // 0x808009F4: nop
    
            goto L_80800A08;
    }
    // 0x808009F4: nop

    // 0x808009F8: lbu         $t8, 0x65($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X65);
    // 0x808009FC: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800A00: b           L_80800A10
    // 0x80800A04: sb          $t9, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r25;
        goto L_80800A10;
    // 0x80800A04: sb          $t9, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r25;
L_80800A08:
    // 0x80800A08: jal         0x8080095C
    // 0x80800A0C: nop

    func_8080095C_charmouredcaveman(rdram, ctx);
        goto after_0;
    // 0x80800A0C: nop

    after_0:
L_80800A10:
    // 0x80800A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A18: jr          $ra
    // 0x80800A1C: nop

    return;
    // 0x80800A1C: nop

;}
RECOMP_FUNC void chjollyroger_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1036, 0X1358) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1358
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1036, 0X1358));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1358
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1036, 0X1358));
;}
RECOMP_FUNC void _baeggfire_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B18: syscall     129
    recomp_syscall_handler(rdram, ctx, 0x80084B18);
    return;
    // 0x80084B1C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gspropctrl_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C10: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088C10);
    return;
    // 0x80088C14: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _glglobalsettings_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886E0: syscall     699
    recomp_syscall_handler(rdram, ctx, 0x800886E0);
    return;
    // 0x800886E4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _glcutDll_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088840: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088840);
    return;
    // 0x80088844: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_8001608C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001608C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80016090: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016094: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016098: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001609C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800160A0: jal         0x8002FF70
    // 0x800160A4: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    osGetThreadPri_recomp(rdram, ctx);
        goto after_0;
    // 0x800160A4: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    after_0:
    // 0x800160A8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800160AC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800160B0: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    // 0x800160B4: jal         0x8002EC20
    // 0x800160B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_1;
    // 0x800160B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800160BC: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x800160C0: addiu       $s0, $s0, -0x64C0
    ctx->r16 = ADD32(ctx->r16, -0X64C0);
    // 0x800160C4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800160C8: lb          $t6, 0x2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X2);
    // 0x800160CC: lb          $t7, 0x3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X3);
    // 0x800160D0: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x800160D4: addiu       $v0, $v0, -0x64A8
    ctx->r2 = ADD32(ctx->r2, -0X64A8);
    // 0x800160D8: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x800160DC: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
    // 0x800160E0: jal         0x800A9CAC
    // 0x800160E4: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    func_800A9CAC(rdram, ctx);
        goto after_2;
    // 0x800160E4: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    after_2:
    // 0x800160E8: beq         $v0, $zero, L_80016118
    if (ctx->r2 == 0) {
        // 0x800160EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80016118;
    }
    // 0x800160EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800160F0: jal         0x80088698
    // 0x800160F4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    _glrecord_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x800160F4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_3:
    // 0x800160F8: bne         $v0, $zero, L_80016110
    if (ctx->r2 != 0) {
        // 0x800160FC: nop
    
            goto L_80016110;
    }
    // 0x800160FC: nop

    // 0x80016100: jal         0x800A9CDC
    // 0x80016104: nop

    func_800A9CDC(rdram, ctx);
        goto after_4;
    // 0x80016104: nop

    after_4:
    // 0x80016108: b           L_80016118
    // 0x8001610C: nop

        goto L_80016118;
    // 0x8001610C: nop

L_80016110:
    // 0x80016110: jal         0x800D8FA0
    // 0x80016114: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800D8FA0(rdram, ctx);
        goto after_5;
    // 0x80016114: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_5:
L_80016118:
    // 0x80016118: jal         0x800DC0C0
    // 0x8001611C: nop

    func_800DC0C0(rdram, ctx);
        goto after_6;
    // 0x8001611C: nop

    after_6:
    // 0x80016120: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80016124: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80016128: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001612C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80016130: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80016134: addiu       $t0, $t0, -0x6540
    ctx->r8 = ADD32(ctx->r8, -0X6540);
    // 0x80016138: addiu       $s0, $s0, -0x6508
    ctx->r16 = ADD32(ctx->r16, -0X6508);
    // 0x8001613C: addiu       $a3, $a3, -0x6620
    ctx->r7 = ADD32(ctx->r7, -0X6620);
    // 0x80016140: addiu       $t3, $t3, -0x6294
    ctx->r11 = ADD32(ctx->r11, -0X6294);
    // 0x80016144: addiu       $s1, $s1, -0x64C0
    ctx->r17 = ADD32(ctx->r17, -0X64C0);
    // 0x80016148: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001614C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
L_80016150:
    // 0x80016150: lbu         $t9, 0x4($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X4);
    // 0x80016154: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80016158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001615C: andi        $t5, $t9, 0x8
    ctx->r13 = ctx->r25 & 0X8;
    // 0x80016160: beq         $t5, $zero, L_80016170
    if (ctx->r13 == 0) {
        // 0x80016164: lui         $t7, 0x8008
        ctx->r15 = S32(0X8008 << 16);
            goto L_80016170;
    }
    // 0x80016164: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80016168: b           L_80016174
    // 0x8001616C: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
        goto L_80016174;
    // 0x8001616C: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
L_80016170:
    // 0x80016170: sb          $t6, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r14;
L_80016174:
    // 0x80016174: lhu         $t4, 0x0($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X0);
    // 0x80016178: sll         $t6, $t2, 3
    ctx->r14 = S32(ctx->r10 << 3);
    // 0x8001617C: addiu       $t7, $t7, -0x6640
    ctx->r15 = ADD32(ctx->r15, -0X6640);
    // 0x80016180: andi        $a2, $t4, 0x20
    ctx->r6 = ctx->r12 & 0X20;
    // 0x80016184: beq         $a2, $zero, L_800161C4
    if (ctx->r6 == 0) {
        // 0x80016188: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800161C4;
    }
    // 0x80016188: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8001618C: andi        $a1, $a0, 0x10
    ctx->r5 = ctx->r4 & 0X10;
    // 0x80016190: beq         $a1, $zero, L_800161C4
    if (ctx->r5 == 0) {
        // 0x80016194: andi        $v1, $a0, 0x4000
        ctx->r3 = ctx->r4 & 0X4000;
            goto L_800161C4;
    }
    // 0x80016194: andi        $v1, $a0, 0x4000
    ctx->r3 = ctx->r4 & 0X4000;
    // 0x80016198: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001619C: addiu       $t8, $t8, -0x6640
    ctx->r24 = ADD32(ctx->r24, -0X6640);
    // 0x800161A0: sll         $t7, $t2, 3
    ctx->r15 = S32(ctx->r10 << 3);
    // 0x800161A4: beq         $v1, $zero, L_800161BC
    if (ctx->r3 == 0) {
        // 0x800161A8: addu        $v0, $t7, $t8
        ctx->r2 = ADD32(ctx->r15, ctx->r24);
            goto L_800161BC;
    }
    // 0x800161A8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800161AC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800161B0: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x800161B4: b           L_800161E0
    // 0x800161B8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_800161E0;
    // 0x800161B8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800161BC:
    // 0x800161BC: b           L_800161E0
    // 0x800161C0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_800161E0;
    // 0x800161C0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800161C4:
    // 0x800161C4: andi        $a1, $a0, 0x10
    ctx->r5 = ctx->r4 & 0X10;
    // 0x800161C8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
L_800161CC:
    // 0x800161CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800161D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800161D4: bne         $v0, $t1, L_800161CC
    if (ctx->r2 != ctx->r9) {
        // 0x800161D8: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_800161CC;
    }
    // 0x800161D8: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x800161DC: andi        $v1, $a0, 0x4000
    ctx->r3 = ctx->r4 & 0X4000;
L_800161E0:
    // 0x800161E0: andi        $t8, $a0, 0x8000
    ctx->r24 = ctx->r4 & 0X8000;
    // 0x800161E4: beq         $t8, $zero, L_800161FC
    if (ctx->r24 == 0) {
        // 0x800161E8: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_800161FC;
    }
    // 0x800161E8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800161EC: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800161F0: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x800161F4: b           L_80016200
    // 0x800161F8: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
        goto L_80016200;
    // 0x800161F8: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_800161FC:
    // 0x800161FC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80016200:
    // 0x80016200: beq         $v1, $zero, L_80016218
    if (ctx->r3 == 0) {
        // 0x80016204: andi        $t8, $a0, 0x2
        ctx->r24 = ctx->r4 & 0X2;
            goto L_80016218;
    }
    // 0x80016204: andi        $t8, $a0, 0x2
    ctx->r24 = ctx->r4 & 0X2;
    // 0x80016208: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x8001620C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80016210: b           L_8001621C
    // 0x80016214: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
        goto L_8001621C;
    // 0x80016214: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
L_80016218:
    // 0x80016218: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
L_8001621C:
    // 0x8001621C: beq         $t8, $zero, L_80016234
    if (ctx->r24 == 0) {
        // 0x80016220: andi        $t6, $a0, 0x4
        ctx->r14 = ctx->r4 & 0X4;
            goto L_80016234;
    }
    // 0x80016220: andi        $t6, $a0, 0x4
    ctx->r14 = ctx->r4 & 0X4;
    // 0x80016224: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80016228: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8001622C: b           L_80016238
    // 0x80016230: sw          $t5, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r13;
        goto L_80016238;
    // 0x80016230: sw          $t5, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r13;
L_80016234:
    // 0x80016234: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_80016238:
    // 0x80016238: beq         $t6, $zero, L_80016250
    if (ctx->r14 == 0) {
        // 0x8001623C: andi        $t9, $a0, 0x8
        ctx->r25 = ctx->r4 & 0X8;
            goto L_80016250;
    }
    // 0x8001623C: andi        $t9, $a0, 0x8
    ctx->r25 = ctx->r4 & 0X8;
    // 0x80016240: lw          $t7, 0xC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XC);
    // 0x80016244: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80016248: b           L_80016254
    // 0x8001624C: sw          $t8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r24;
        goto L_80016254;
    // 0x8001624C: sw          $t8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r24;
L_80016250:
    // 0x80016250: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
L_80016254:
    // 0x80016254: beq         $t9, $zero, L_8001626C
    if (ctx->r25 == 0) {
        // 0x80016258: andi        $t7, $a0, 0x1
        ctx->r15 = ctx->r4 & 0X1;
            goto L_8001626C;
    }
    // 0x80016258: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    // 0x8001625C: lw          $t5, 0x10($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X10);
    // 0x80016260: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80016264: b           L_80016270
    // 0x80016268: sw          $t6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r14;
        goto L_80016270;
    // 0x80016268: sw          $t6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r14;
L_8001626C:
    // 0x8001626C: sw          $zero, 0x10($a3)
    MEM_W(0X10, ctx->r7) = 0;
L_80016270:
    // 0x80016270: beq         $t7, $zero, L_80016288
    if (ctx->r15 == 0) {
        // 0x80016274: andi        $t5, $a0, 0x2000
        ctx->r13 = ctx->r4 & 0X2000;
            goto L_80016288;
    }
    // 0x80016274: andi        $t5, $a0, 0x2000
    ctx->r13 = ctx->r4 & 0X2000;
    // 0x80016278: lw          $t8, 0x14($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14);
    // 0x8001627C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80016280: b           L_8001628C
    // 0x80016284: sw          $t9, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r25;
        goto L_8001628C;
    // 0x80016284: sw          $t9, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r25;
L_80016288:
    // 0x80016288: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
L_8001628C:
    // 0x8001628C: beql        $t5, $zero, L_800162A8
    if (ctx->r13 == 0) {
        // 0x80016290: sw          $zero, 0x18($a3)
        MEM_W(0X18, ctx->r7) = 0;
            goto L_800162A8;
    }
    goto skip_0;
    // 0x80016290: sw          $zero, 0x18($a3)
    MEM_W(0X18, ctx->r7) = 0;
    skip_0:
    // 0x80016294: lw          $t6, 0x18($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X18);
    // 0x80016298: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001629C: b           L_800162A8
    // 0x800162A0: sw          $t7, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r15;
        goto L_800162A8;
    // 0x800162A0: sw          $t7, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r15;
    // 0x800162A4: sw          $zero, 0x18($a3)
    MEM_W(0X18, ctx->r7) = 0;
L_800162A8:
    // 0x800162A8: beq         $a2, $zero, L_800162C0
    if (ctx->r6 == 0) {
        // 0x800162AC: andi        $t7, $a0, 0x800
        ctx->r15 = ctx->r4 & 0X800;
            goto L_800162C0;
    }
    // 0x800162AC: andi        $t7, $a0, 0x800
    ctx->r15 = ctx->r4 & 0X800;
    // 0x800162B0: lw          $t8, 0x1C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X1C);
    // 0x800162B4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800162B8: b           L_800162C4
    // 0x800162BC: sw          $t9, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r25;
        goto L_800162C4;
    // 0x800162BC: sw          $t9, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r25;
L_800162C0:
    // 0x800162C0: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800162C4:
    // 0x800162C4: beq         $a1, $zero, L_800162DC
    if (ctx->r5 == 0) {
        // 0x800162C8: addiu       $a2, $zero, 0x3B
        ctx->r6 = ADD32(0, 0X3B);
            goto L_800162DC;
    }
    // 0x800162C8: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    // 0x800162CC: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x800162D0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800162D4: b           L_800162E0
    // 0x800162D8: sw          $t6, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r14;
        goto L_800162E0;
    // 0x800162D8: sw          $t6, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r14;
L_800162DC:
    // 0x800162DC: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
L_800162E0:
    // 0x800162E0: beq         $t7, $zero, L_800162F8
    if (ctx->r15 == 0) {
        // 0x800162E4: andi        $t5, $a0, 0x400
        ctx->r13 = ctx->r4 & 0X400;
            goto L_800162F8;
    }
    // 0x800162E4: andi        $t5, $a0, 0x400
    ctx->r13 = ctx->r4 & 0X400;
    // 0x800162E8: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x800162EC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800162F0: b           L_800162FC
    // 0x800162F4: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
        goto L_800162FC;
    // 0x800162F4: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
L_800162F8:
    // 0x800162F8: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800162FC:
    // 0x800162FC: beq         $t5, $zero, L_80016314
    if (ctx->r13 == 0) {
        // 0x80016300: andi        $t8, $a0, 0x200
        ctx->r24 = ctx->r4 & 0X200;
            goto L_80016314;
    }
    // 0x80016300: andi        $t8, $a0, 0x200
    ctx->r24 = ctx->r4 & 0X200;
    // 0x80016304: lw          $t6, 0x28($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X28);
    // 0x80016308: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001630C: b           L_80016318
    // 0x80016310: sw          $t7, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r15;
        goto L_80016318;
    // 0x80016310: sw          $t7, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r15;
L_80016314:
    // 0x80016314: sw          $zero, 0x28($a3)
    MEM_W(0X28, ctx->r7) = 0;
L_80016318:
    // 0x80016318: beq         $t8, $zero, L_80016330
    if (ctx->r24 == 0) {
        // 0x8001631C: andi        $t6, $a0, 0x100
        ctx->r14 = ctx->r4 & 0X100;
            goto L_80016330;
    }
    // 0x8001631C: andi        $t6, $a0, 0x100
    ctx->r14 = ctx->r4 & 0X100;
    // 0x80016320: lw          $t9, 0x2C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X2C);
    // 0x80016324: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x80016328: b           L_80016334
    // 0x8001632C: sw          $t5, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r13;
        goto L_80016334;
    // 0x8001632C: sw          $t5, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r13;
L_80016330:
    // 0x80016330: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
L_80016334:
    // 0x80016334: beq         $t6, $zero, L_8001634C
    if (ctx->r14 == 0) {
        // 0x80016338: andi        $t9, $a0, 0x1000
        ctx->r25 = ctx->r4 & 0X1000;
            goto L_8001634C;
    }
    // 0x80016338: andi        $t9, $a0, 0x1000
    ctx->r25 = ctx->r4 & 0X1000;
    // 0x8001633C: lw          $t7, 0x30($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X30);
    // 0x80016340: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80016344: b           L_80016350
    // 0x80016348: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
        goto L_80016350;
    // 0x80016348: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
L_8001634C:
    // 0x8001634C: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
L_80016350:
    // 0x80016350: beql        $t9, $zero, L_8001636C
    if (ctx->r25 == 0) {
        // 0x80016354: sw          $zero, 0x34($a3)
        MEM_W(0X34, ctx->r7) = 0;
            goto L_8001636C;
    }
    goto skip_1;
    // 0x80016354: sw          $zero, 0x34($a3)
    MEM_W(0X34, ctx->r7) = 0;
    skip_1:
    // 0x80016358: lw          $t5, 0x34($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X34);
    // 0x8001635C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80016360: b           L_8001636C
    // 0x80016364: sw          $t6, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r14;
        goto L_8001636C;
    // 0x80016364: sw          $t6, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r14;
    // 0x80016368: sw          $zero, 0x34($a3)
    MEM_W(0X34, ctx->r7) = 0;
L_8001636C:
    // 0x8001636C: bnel        $t2, $zero, L_8001653C
    if (ctx->r10 != 0) {
        // 0x80016370: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_8001653C;
    }
    goto skip_2;
    // 0x80016370: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_2:
    // 0x80016374: lhu         $v0, -0x64A8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X64A8);
    // 0x80016378: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x8001637C: beq         $t7, $zero, L_80016394
    if (ctx->r15 == 0) {
        // 0x80016380: andi        $a1, $v0, 0x4000
        ctx->r5 = ctx->r2 & 0X4000;
            goto L_80016394;
    }
    // 0x80016380: andi        $a1, $v0, 0x4000
    ctx->r5 = ctx->r2 & 0X4000;
    // 0x80016384: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80016388: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8001638C: b           L_80016398
    // 0x80016390: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_80016398;
    // 0x80016390: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80016394:
    // 0x80016394: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80016398:
    // 0x80016398: beq         $a1, $zero, L_800163B0
    if (ctx->r5 == 0) {
        // 0x8001639C: andi        $t7, $v0, 0x2
        ctx->r15 = ctx->r2 & 0X2;
            goto L_800163B0;
    }
    // 0x8001639C: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x800163A0: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x800163A4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800163A8: b           L_800163B4
    // 0x800163AC: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
        goto L_800163B4;
    // 0x800163AC: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
L_800163B0:
    // 0x800163B0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
L_800163B4:
    // 0x800163B4: beq         $t7, $zero, L_800163CC
    if (ctx->r15 == 0) {
        // 0x800163B8: andi        $t5, $v0, 0x4
        ctx->r13 = ctx->r2 & 0X4;
            goto L_800163CC;
    }
    // 0x800163B8: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x800163BC: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x800163C0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800163C4: b           L_800163D0
    // 0x800163C8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
        goto L_800163D0;
    // 0x800163C8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
L_800163CC:
    // 0x800163CC: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
L_800163D0:
    // 0x800163D0: beq         $t5, $zero, L_800163E8
    if (ctx->r13 == 0) {
        // 0x800163D4: andi        $t8, $v0, 0x8
        ctx->r24 = ctx->r2 & 0X8;
            goto L_800163E8;
    }
    // 0x800163D4: andi        $t8, $v0, 0x8
    ctx->r24 = ctx->r2 & 0X8;
    // 0x800163D8: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x800163DC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800163E0: b           L_800163EC
    // 0x800163E4: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
        goto L_800163EC;
    // 0x800163E4: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_800163E8:
    // 0x800163E8: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
L_800163EC:
    // 0x800163EC: beq         $t8, $zero, L_80016404
    if (ctx->r24 == 0) {
        // 0x800163F0: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_80016404;
    }
    // 0x800163F0: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800163F4: lw          $t9, 0x10($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X10);
    // 0x800163F8: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x800163FC: b           L_80016408
    // 0x80016400: sw          $t5, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r13;
        goto L_80016408;
    // 0x80016400: sw          $t5, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r13;
L_80016404:
    // 0x80016404: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
L_80016408:
    // 0x80016408: beq         $t6, $zero, L_80016420
    if (ctx->r14 == 0) {
        // 0x8001640C: andi        $t9, $v0, 0x2000
        ctx->r25 = ctx->r2 & 0X2000;
            goto L_80016420;
    }
    // 0x8001640C: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
    // 0x80016410: lw          $t7, 0x14($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X14);
    // 0x80016414: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80016418: b           L_80016424
    // 0x8001641C: sw          $t8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r24;
        goto L_80016424;
    // 0x8001641C: sw          $t8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r24;
L_80016420:
    // 0x80016420: sw          $zero, 0x14($t0)
    MEM_W(0X14, ctx->r8) = 0;
L_80016424:
    // 0x80016424: beq         $t9, $zero, L_8001643C
    if (ctx->r25 == 0) {
        // 0x80016428: andi        $a0, $v0, 0x20
        ctx->r4 = ctx->r2 & 0X20;
            goto L_8001643C;
    }
    // 0x80016428: andi        $a0, $v0, 0x20
    ctx->r4 = ctx->r2 & 0X20;
    // 0x8001642C: lw          $t5, 0x18($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X18);
    // 0x80016430: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80016434: b           L_80016440
    // 0x80016438: sw          $t6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r14;
        goto L_80016440;
    // 0x80016438: sw          $t6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r14;
L_8001643C:
    // 0x8001643C: sw          $zero, 0x18($t0)
    MEM_W(0X18, ctx->r8) = 0;
L_80016440:
    // 0x80016440: beq         $a0, $zero, L_80016458
    if (ctx->r4 == 0) {
        // 0x80016444: andi        $v1, $v0, 0x10
        ctx->r3 = ctx->r2 & 0X10;
            goto L_80016458;
    }
    // 0x80016444: andi        $v1, $v0, 0x10
    ctx->r3 = ctx->r2 & 0X10;
    // 0x80016448: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x8001644C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80016450: b           L_8001645C
    // 0x80016454: sw          $t8, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r24;
        goto L_8001645C;
    // 0x80016454: sw          $t8, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r24;
L_80016458:
    // 0x80016458: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
L_8001645C:
    // 0x8001645C: beq         $v1, $zero, L_80016474
    if (ctx->r3 == 0) {
        // 0x80016460: andi        $t6, $v0, 0x800
        ctx->r14 = ctx->r2 & 0X800;
            goto L_80016474;
    }
    // 0x80016460: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x80016464: lw          $t9, 0x20($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X20);
    // 0x80016468: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8001646C: b           L_80016478
    // 0x80016470: sw          $t5, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r13;
        goto L_80016478;
    // 0x80016470: sw          $t5, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r13;
L_80016474:
    // 0x80016474: sw          $zero, 0x20($t0)
    MEM_W(0X20, ctx->r8) = 0;
L_80016478:
    // 0x80016478: beq         $t6, $zero, L_80016490
    if (ctx->r14 == 0) {
        // 0x8001647C: andi        $t9, $v0, 0x400
        ctx->r25 = ctx->r2 & 0X400;
            goto L_80016490;
    }
    // 0x8001647C: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x80016480: lw          $t7, 0x24($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X24);
    // 0x80016484: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80016488: b           L_80016494
    // 0x8001648C: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
        goto L_80016494;
    // 0x8001648C: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
L_80016490:
    // 0x80016490: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_80016494:
    // 0x80016494: beq         $t9, $zero, L_800164AC
    if (ctx->r25 == 0) {
        // 0x80016498: andi        $t7, $v0, 0x200
        ctx->r15 = ctx->r2 & 0X200;
            goto L_800164AC;
    }
    // 0x80016498: andi        $t7, $v0, 0x200
    ctx->r15 = ctx->r2 & 0X200;
    // 0x8001649C: lw          $t5, 0x28($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X28);
    // 0x800164A0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800164A4: b           L_800164B0
    // 0x800164A8: sw          $t6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r14;
        goto L_800164B0;
    // 0x800164A8: sw          $t6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r14;
L_800164AC:
    // 0x800164AC: sw          $zero, 0x28($t0)
    MEM_W(0X28, ctx->r8) = 0;
L_800164B0:
    // 0x800164B0: beq         $t7, $zero, L_800164C8
    if (ctx->r15 == 0) {
        // 0x800164B4: andi        $t5, $v0, 0x100
        ctx->r13 = ctx->r2 & 0X100;
            goto L_800164C8;
    }
    // 0x800164B4: andi        $t5, $v0, 0x100
    ctx->r13 = ctx->r2 & 0X100;
    // 0x800164B8: lw          $t8, 0x2C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X2C);
    // 0x800164BC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800164C0: b           L_800164CC
    // 0x800164C4: sw          $t9, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->r25;
        goto L_800164CC;
    // 0x800164C4: sw          $t9, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->r25;
L_800164C8:
    // 0x800164C8: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
L_800164CC:
    // 0x800164CC: beq         $t5, $zero, L_800164E4
    if (ctx->r13 == 0) {
        // 0x800164D0: andi        $t8, $v0, 0x1000
        ctx->r24 = ctx->r2 & 0X1000;
            goto L_800164E4;
    }
    // 0x800164D0: andi        $t8, $v0, 0x1000
    ctx->r24 = ctx->r2 & 0X1000;
    // 0x800164D4: lw          $t6, 0x30($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X30);
    // 0x800164D8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800164DC: b           L_800164E8
    // 0x800164E0: sw          $t7, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r15;
        goto L_800164E8;
    // 0x800164E0: sw          $t7, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r15;
L_800164E4:
    // 0x800164E4: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
L_800164E8:
    // 0x800164E8: beql        $t8, $zero, L_80016504
    if (ctx->r24 == 0) {
        // 0x800164EC: sw          $zero, 0x34($t0)
        MEM_W(0X34, ctx->r8) = 0;
            goto L_80016504;
    }
    goto skip_3;
    // 0x800164EC: sw          $zero, 0x34($t0)
    MEM_W(0X34, ctx->r8) = 0;
    skip_3:
    // 0x800164F0: lw          $t9, 0x34($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X34);
    // 0x800164F4: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x800164F8: b           L_80016504
    // 0x800164FC: sw          $t5, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r13;
        goto L_80016504;
    // 0x800164FC: sw          $t5, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r13;
    // 0x80016500: sw          $zero, 0x34($t0)
    MEM_W(0X34, ctx->r8) = 0;
L_80016504:
    // 0x80016504: beql        $a0, $zero, L_8001653C
    if (ctx->r4 == 0) {
        // 0x80016508: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_8001653C;
    }
    goto skip_4;
    // 0x80016508: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_4:
    // 0x8001650C: beq         $v1, $zero, L_80016538
    if (ctx->r3 == 0) {
        // 0x80016510: sll         $t6, $t2, 3
        ctx->r14 = S32(ctx->r10 << 3);
            goto L_80016538;
    }
    // 0x80016510: sll         $t6, $t2, 3
    ctx->r14 = S32(ctx->r10 << 3);
    // 0x80016514: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80016518: addiu       $t7, $t7, -0x6640
    ctx->r15 = ADD32(ctx->r15, -0X6640);
    // 0x8001651C: beq         $a1, $zero, L_80016534
    if (ctx->r5 == 0) {
        // 0x80016520: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_80016534;
    }
    // 0x80016520: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80016524: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80016528: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8001652C: b           L_80016538
    // 0x80016530: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_80016538;
    // 0x80016530: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80016534:
    // 0x80016534: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_80016538:
    // 0x80016538: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
L_8001653C:
    // 0x8001653C: nor         $t8, $t4, $zero
    ctx->r24 = ~(ctx->r12 | 0);
    // 0x80016540: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x80016544: nor         $t6, $v0, $zero
    ctx->r14 = ~(ctx->r2 | 0);
    // 0x80016548: and         $t7, $t6, $t4
    ctx->r15 = ctx->r14 & ctx->r12;
    // 0x8001654C: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x80016550: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x80016554: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x80016558: lb          $a0, 0x2($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X2);
    // 0x8001655C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80016560: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80016564: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x80016568: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8001656C: jal         0x80015D60
    // 0x80016570: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    func_80015D60(rdram, ctx);
        goto after_7;
    // 0x80016570: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    after_7:
    // 0x80016574: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80016578: lb          $a0, 0x3($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X3);
    // 0x8001657C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80016580: jal         0x80015D60
    // 0x80016584: addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    func_80015D60(rdram, ctx);
        goto after_8;
    // 0x80016584: addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    after_8:
    // 0x80016588: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8001658C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80016590: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80016594: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80016598: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001659C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800165A0: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x800165A4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800165A8: addiu       $t0, $t0, -0x6540
    ctx->r8 = ADD32(ctx->r8, -0X6540);
    // 0x800165AC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800165B0: swc1        $f0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800165B4: addiu       $a3, $a3, 0x38
    ctx->r7 = ADD32(ctx->r7, 0X38);
    // 0x800165B8: bne         $t2, $at, L_80016150
    if (ctx->r10 != ctx->r1) {
        // 0x800165BC: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_80016150;
    }
    // 0x800165BC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800165C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800165C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800165C8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800165CC: sb          $t5, -0x6297($at)
    MEM_B(-0X6297, ctx->r1) = ctx->r13;
    // 0x800165D0: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    // 0x800165D4: jal         0x8002EC20
    // 0x800165D8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_9;
    // 0x800165D8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_9:
    // 0x800165DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800165E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800165E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800165E8: jr          $ra
    // 0x800165EC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800165EC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void mlMtx_push_translation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018E1C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80018E20: addiu       $v1, $v1, -0x4350
    ctx->r3 = ADD32(ctx->r3, -0X4350);
    // 0x80018E24: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80018E28: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80018E2C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80018E30: addiu       $v0, $t6, 0x40
    ctx->r2 = ADD32(ctx->r14, 0X40);
    // 0x80018E34: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80018E38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018E3C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80018E40: swc1        $f14, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f14.u32l;
    // 0x80018E44: swc1        $f12, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f12.u32l;
    // 0x80018E48: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    // 0x80018E4C: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x80018E50: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80018E54: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x80018E58: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x80018E5C: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x80018E60: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x80018E64: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    // 0x80018E68: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x80018E6C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80018E70: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x80018E74: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x80018E78: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80018E7C: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x80018E80: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80018E84: jr          $ra
    // 0x80018E88: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x80018E88: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void chmadamegrunty_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(916, 0XB50) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xB50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(916, 0XB50));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xB50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(916, 0XB50));
;}
RECOMP_FUNC void chterryegg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1112, 0X1370) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x1370
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1112, 0X1370));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x1370
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1112, 0X1370));
;}
RECOMP_FUNC void func_80800F70_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F70: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800F74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F78: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800F7C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800F80: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800F84: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800F88: jal         0x80100094
    // 0x80800F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800F94: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80800F98: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80800F9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FA0: jal         0x80102424
    // 0x80800FA4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800FA4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_1:
    // 0x80800FA8: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80800FAC: addiu       $t7, $t6, -0x3
    ctx->r15 = ADD32(ctx->r14, -0X3);
    // 0x80800FB0: sltiu       $at, $t7, 0x15
    ctx->r1 = ctx->r15 < 0X15 ? 1 : 0;
    // 0x80800FB4: beq         $at, $zero, L_808013E4
    if (ctx->r1 == 0) {
        // 0x80800FB8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808013E4;
    }
    // 0x80800FB8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800FBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X2998) << 16);
    // 0x80800FC0: addu        $at, $at, $t7
    gpr jr_addend_80800FC8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800FC4: lw          $t7, 0x2998($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1060, 0X2998));
    // 0x80800FC8: jr          $t7
    // 0x80800FCC: nop

    switch (jr_addend_80800FC8 >> 2) {
        case 0: goto L_80800FD0; break;
        case 1: goto L_80800FE0; break;
        case 2: goto L_80800FF8; break;
        case 3: goto L_80801008; break;
        case 4: goto L_80801038; break;
        case 5: goto L_8080108C; break;
        case 6: goto L_808010A4; break;
        case 7: goto L_808010C0; break;
        case 8: goto L_80801130; break;
        case 9: goto L_808011B4; break;
        case 10: goto L_80801224; break;
        case 11: goto L_80801270; break;
        case 12: goto L_8080128C; break;
        case 13: goto L_808013AC; break;
        case 14: goto L_808013B8; break;
        case 15: goto L_808013CC; break;
        case 16: goto L_808013DC; break;
        case 17: goto L_808013E4; break;
        case 18: goto L_808013E4; break;
        case 19: goto L_808013E4; break;
        case 20: goto L_808012F0; break;
        default: switch_error(__func__, 0x80800FC8, 0x80802998);
    }
    // 0x80800FCC: nop

L_80800FD0:
    // 0x80800FD0: jal         0x800FDC28
    // 0x80800FD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_2;
    // 0x80800FD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800FD8: b           L_808013E8
    // 0x80800FDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808013E8;
    // 0x80800FDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800FE0:
    // 0x80800FE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800FE8: jal         0x8080248C
    // 0x80800FEC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_3;
    // 0x80800FEC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_3:
    // 0x80800FF0: b           L_808013E8
    // 0x80800FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808013E8;
    // 0x80800FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800FF8:
    // 0x80800FF8: jal         0x800DA544
    // 0x80800FFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800FFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80801000: b           L_808013E8
    // 0x80801004: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808013E8;
    // 0x80801004: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801008:
    // 0x80801008: jal         0x800DA298
    // 0x8080100C: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x8080100C: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    after_5:
    // 0x80801010: bne         $v0, $zero, L_80801028
    if (ctx->r2 != 0) {
        // 0x80801014: addiu       $a0, $zero, 0x18B9
        ctx->r4 = ADD32(0, 0X18B9);
            goto L_80801028;
    }
    // 0x80801014: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x80801018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080101C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801020: jal         0x800861A0
    // 0x80801024: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80801024: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
L_80801028:
    // 0x80801028: jal         0x808015AC
    // 0x8080102C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808015AC_chdinoboss(rdram, ctx);
        goto after_7;
    // 0x8080102C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80801030: b           L_808013E8
    // 0x80801034: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808013E8;
    // 0x80801034: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801038:
    // 0x80801038: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080103C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801040: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801044: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X29EC) << 16);
    // 0x80801048: swc1        $f4, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f4.u32l;
    // 0x8080104C: lwc1        $f6, 0x29EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1060, 0X29EC));
    // 0x80801050: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80801054: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80801058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080105C: jal         0x80801660
    // 0x80801060: swc1        $f6, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f6.u32l;
    func_80801660_chdinoboss(rdram, ctx);
        goto after_8;
    // 0x80801060: swc1        $f6, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f6.u32l;
    after_8:
    // 0x80801064: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801068: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080106C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801070: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801074: jal         0x800DC178
    // 0x80801078: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80801078: nop

    after_9:
    // 0x8080107C: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    // 0x80801080: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801084: b           L_808013E4
    // 0x80801088: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
        goto L_808013E4;
    // 0x80801088: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_8080108C:
    // 0x8080108C: lw          $t9, 0x120($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X120);
    // 0x80801090: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801094: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80801098: sw          $t0, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->r8;
    // 0x8080109C: b           L_808013E4
    // 0x808010A0: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
        goto L_808013E4;
    // 0x808010A0: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
L_808010A4:
    // 0x808010A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X29F0) << 16);
    // 0x808010A8: lwc1        $f8, 0x29F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1060, 0X29F0));
    // 0x808010AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808010B0: swc1        $f8, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f8.u32l;
    // 0x808010B4: sh          $zero, 0x11E($s0)
    MEM_H(0X11E, ctx->r16) = 0;
    // 0x808010B8: b           L_808013E4
    // 0x808010BC: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
        goto L_808013E4;
    // 0x808010BC: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
L_808010C0:
    // 0x808010C0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808010C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808010C8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808010CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X29F4) << 16);
    // 0x808010D0: swc1        $f10, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f10.u32l;
    // 0x808010D4: lwc1        $f16, 0x29F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1060, 0X29F4));
    // 0x808010D8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808010DC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808010E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010E4: jal         0x80801660
    // 0x808010E8: swc1        $f16, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f16.u32l;
    func_80801660_chdinoboss(rdram, ctx);
        goto after_10;
    // 0x808010E8: swc1        $f16, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f16.u32l;
    after_10:
    // 0x808010EC: lbu         $t3, 0x12A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X12A);
    // 0x808010F0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808010F4: addiu       $a1, $zero, 0x17FC
    ctx->r5 = ADD32(0, 0X17FC);
    // 0x808010F8: bne         $t3, $zero, L_80801118
    if (ctx->r11 != 0) {
        // 0x808010FC: addiu       $a2, $zero, 0x44
        ctx->r6 = ADD32(0, 0X44);
            goto L_80801118;
    }
    // 0x808010FC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80801100: sb          $t4, 0x12A($s0)
    MEM_B(0X12A, ctx->r16) = ctx->r12;
    // 0x80801104: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80801108: addiu       $t5, $zero, 0x57
    ctx->r13 = ADD32(0, 0X57);
    // 0x8080110C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80801110: jal         0x8008A208
    // 0x80801114: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80801114: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    after_11:
L_80801118:
    // 0x80801118: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080111C: jal         0x80109FE8
    // 0x80801120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_12;
    // 0x80801120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80801124: lbu         $t6, 0x5E($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X5E);
    // 0x80801128: b           L_808013E4
    // 0x8080112C: sh          $t6, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = ctx->r14;
        goto L_808013E4;
    // 0x8080112C: sh          $t6, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = ctx->r14;
L_80801130:
    // 0x80801130: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801134: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801138: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080113C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X29F8) << 16);
    // 0x80801140: swc1        $f18, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f18.u32l;
    // 0x80801144: lwc1        $f4, 0x29F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1060, 0X29F8));
    // 0x80801148: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080114C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80801150: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801154: jal         0x80801660
    // 0x80801158: swc1        $f4, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f4.u32l;
    func_80801660_chdinoboss(rdram, ctx);
        goto after_13;
    // 0x80801158: swc1        $f4, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f4.u32l;
    after_13:
    // 0x8080115C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801160: jal         0x80109FE8
    // 0x80801164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_14;
    // 0x80801164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80801168: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080116C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801170: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801174: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801178: jal         0x800DC178
    // 0x8080117C: nop

    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x8080117C: nop

    after_15:
    // 0x80801180: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    // 0x80801184: jal         0x80801C28
    // 0x80801188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801C28_chdinoboss(rdram, ctx);
        goto after_16;
    // 0x80801188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x8080118C: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80801190: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x80801194: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801198: jal         0x80801AE4
    // 0x8080119C: sw          $t7, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->r15;
    func_80801AE4_chdinoboss(rdram, ctx);
        goto after_17;
    // 0x8080119C: sw          $t7, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->r15;
    after_17:
    // 0x808011A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808011A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808011A8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x808011AC: b           L_808013E4
    // 0x808011B0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_808013E4;
    // 0x808011B0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_808011B4:
    // 0x808011B4: lw          $t0, 0x128($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X128);
    // 0x808011B8: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x808011BC: bltzl       $t2, L_80801208
    if (SIGNED(ctx->r10) < 0) {
        // 0x808011C0: lw          $t7, 0x120($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X120);
            goto L_80801208;
    }
    goto skip_0;
    // 0x808011C0: lw          $t7, 0x120($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X120);
    skip_0:
    // 0x808011C4: lbu         $t4, 0x128($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X128);
    // 0x808011C8: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x808011CC: jal         0x800C064C
    // 0x808011D0: sb          $t5, 0x128($s0)
    MEM_B(0X128, ctx->r16) = ctx->r13;
    func_800C064C(rdram, ctx);
        goto after_18;
    // 0x808011D0: sb          $t5, 0x128($s0)
    MEM_B(0X128, ctx->r16) = ctx->r13;
    after_18:
    // 0x808011D4: addiu       $at, $zero, 0x17FC
    ctx->r1 = ADD32(0, 0X17FC);
    // 0x808011D8: bnel        $v0, $at, L_808011EC
    if (ctx->r2 != ctx->r1) {
        // 0x808011DC: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_808011EC;
    }
    goto skip_1;
    // 0x808011DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x808011E0: jal         0x800C067C
    // 0x808011E4: addiu       $a0, $zero, 0x17FC
    ctx->r4 = ADD32(0, 0X17FC);
    func_800C067C(rdram, ctx);
        goto after_19;
    // 0x808011E4: addiu       $a0, $zero, 0x17FC
    ctx->r4 = ADD32(0, 0X17FC);
    after_19:
    // 0x808011E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_808011EC:
    // 0x808011EC: addiu       $t6, $zero, 0x57
    ctx->r14 = ADD32(0, 0X57);
    // 0x808011F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808011F4: addiu       $a1, $zero, 0x17B4
    ctx->r5 = ADD32(0, 0X17B4);
    // 0x808011F8: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x808011FC: jal         0x8008A208
    // 0x80801200: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_20;
    // 0x80801200: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    after_20:
    // 0x80801204: lw          $t7, 0x120($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X120);
L_80801208:
    // 0x80801208: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080120C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801210: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80801214: sw          $t8, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->r24;
    // 0x80801218: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8080121C: b           L_808013E4
    // 0x80801220: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_808013E4;
    // 0x80801220: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_80801224:
    // 0x80801224: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80801228: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080122C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801230: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X29FC) << 16);
    // 0x80801234: swc1        $f6, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f6.u32l;
    // 0x80801238: lwc1        $f8, 0x29FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1060, 0X29FC));
    // 0x8080123C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80801240: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80801244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801248: jal         0x80801660
    // 0x8080124C: swc1        $f8, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f8.u32l;
    func_80801660_chdinoboss(rdram, ctx);
        goto after_21;
    // 0x8080124C: swc1        $f8, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f8.u32l;
    after_21:
    // 0x80801250: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801254: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801258: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8080125C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801260: swc1        $f10, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f10.u32l;
    // 0x80801264: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80801268: b           L_808013E4
    // 0x8080126C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_808013E4;
    // 0x8080126C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_80801270:
    // 0x80801270: lbu         $t3, 0x65($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X65);
    // 0x80801274: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801278: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080127C: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x80801280: sb          $t4, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r12;
    // 0x80801284: b           L_808013E4
    // 0x80801288: swc1        $f16, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f16.u32l;
        goto L_808013E4;
    // 0x80801288: swc1        $f16, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f16.u32l;
L_8080128C:
    // 0x8080128C: lw          $t5, 0x128($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X128);
    // 0x80801290: addiu       $a1, $zero, 0x1802
    ctx->r5 = ADD32(0, 0X1802);
    // 0x80801294: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80801298: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8080129C: bltzl       $t7, L_808012C8
    if (SIGNED(ctx->r15) < 0) {
        // 0x808012A0: lbu         $t3, 0x65($s1)
        ctx->r11 = MEM_BU(ctx->r17, 0X65);
            goto L_808012C8;
    }
    goto skip_2;
    // 0x808012A0: lbu         $t3, 0x65($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X65);
    skip_2:
    // 0x808012A4: lbu         $t9, 0x128($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X128);
    // 0x808012A8: addiu       $t1, $zero, 0x57
    ctx->r9 = ADD32(0, 0X57);
    // 0x808012AC: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    // 0x808012B0: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x808012B4: sb          $t0, 0x128($s0)
    MEM_B(0X128, ctx->r16) = ctx->r8;
    // 0x808012B8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808012BC: jal         0x8008A208
    // 0x808012C0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_22;
    // 0x808012C0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_22:
    // 0x808012C4: lbu         $t3, 0x65($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X65);
L_808012C8:
    // 0x808012C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808012CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808012D0: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x808012D4: sb          $t4, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r12;
    // 0x808012D8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x808012DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808012E0: swc1        $f18, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f18.u32l;
    // 0x808012E4: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x808012E8: b           L_808013E4
    // 0x808012EC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_808013E4;
    // 0x808012EC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_808012F0:
    // 0x808012F0: jal         0x800EFD24
    // 0x808012F4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EFD24(rdram, ctx);
        goto after_23;
    // 0x808012F4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_23:
    // 0x808012F8: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x808012FC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80801300: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80801304: jal         0x800F18FC
    // 0x80801308: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800F18FC(rdram, ctx);
        goto after_24;
    // 0x80801308: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_24:
    // 0x8080130C: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801310: jal         0x800136E4
    // 0x80801314: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_800136E4(rdram, ctx);
        goto after_25;
    // 0x80801314: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_25:
    // 0x80801318: swc1        $f0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f0.u32l;
    // 0x8080131C: jal         0x800EEF94
    // 0x80801320: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800EEF94(rdram, ctx);
        goto after_26;
    // 0x80801320: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_26:
    // 0x80801324: swc1        $f0, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f0.u32l;
    // 0x80801328: jal         0x80013728
    // 0x8080132C: lwc1        $f12, 0x124($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X124);
    func_80013728(rdram, ctx);
        goto after_27;
    // 0x8080132C: lwc1        $f12, 0x124($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X124);
    after_27:
    // 0x80801330: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801334: swc1        $f0, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f0.u32l;
    // 0x80801338: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080133C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80801340: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80801344: jal         0x80801660
    // 0x80801348: nop

    func_80801660_chdinoboss(rdram, ctx);
        goto after_28;
    // 0x80801348: nop

    after_28:
    // 0x8080134C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801350: jal         0x80109EEC
    // 0x80801354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109EEC(rdram, ctx);
        goto after_29;
    // 0x80801354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80801358: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080135C: jal         0x80109FE8
    // 0x80801360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_30;
    // 0x80801360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
    // 0x80801364: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80801368: addiu       $t7, $zero, 0x57
    ctx->r15 = ADD32(0, 0X57);
    // 0x8080136C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801370: addiu       $a1, $zero, 0x17B5
    ctx->r5 = ADD32(0, 0X17B5);
    // 0x80801374: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80801378: jal         0x8008A208
    // 0x8080137C: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_31;
    // 0x8080137C: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    after_31:
    // 0x80801380: jal         0x800DA544
    // 0x80801384: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    func_800DA544(rdram, ctx);
        goto after_32;
    // 0x80801384: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    after_32:
    // 0x80801388: jal         0x800DA524
    // 0x8080138C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA524(rdram, ctx);
        goto after_33;
    // 0x8080138C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_33:
    // 0x80801390: jal         0x800FDC28
    // 0x80801394: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_34;
    // 0x80801394: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x80801398: sb          $zero, 0x5E($s1)
    MEM_B(0X5E, ctx->r17) = 0;
    // 0x8080139C: jal         0x80801CDC
    // 0x808013A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801CDC_chdinoboss(rdram, ctx);
        goto after_35;
    // 0x808013A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_35:
    // 0x808013A4: b           L_808013E8
    // 0x808013A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808013E8;
    // 0x808013A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808013AC:
    // 0x808013AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808013B0: b           L_808013E4
    // 0x808013B4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_808013E4;
    // 0x808013B4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_808013B8:
    // 0x808013B8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x808013BC: jal         0x800EE7F8
    // 0x808013C0: addiu       $a1, $s0, 0x104
    ctx->r5 = ADD32(ctx->r16, 0X104);
    func_800EE7F8(rdram, ctx);
        goto after_36;
    // 0x808013C0: addiu       $a1, $s0, 0x104
    ctx->r5 = ADD32(ctx->r16, 0X104);
    after_36:
    // 0x808013C4: b           L_808013E8
    // 0x808013C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808013E8;
    // 0x808013C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808013CC:
    // 0x808013CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808013D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808013D4: b           L_808013E4
    // 0x808013D8: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
        goto L_808013E4;
    // 0x808013D8: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
L_808013DC:
    // 0x808013DC: jal         0x800C964C
    // 0x808013E0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800C964C(rdram, ctx);
        goto after_37;
    // 0x808013E0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_37:
L_808013E4:
    // 0x808013E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808013E8:
    // 0x808013E8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x808013EC: jal         0x80801FAC
    // 0x808013F0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_80801FAC_chdinoboss(rdram, ctx);
        goto after_38;
    // 0x808013F0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_38:
    // 0x808013F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808013F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808013FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801400: jr          $ra
    // 0x80801404: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801404: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8008C1D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1D4: jr          $ra
    // 0x8008C1D8: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    return;
    // 0x8008C1D8: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_808003BC_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808003C0: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x808003C4: jr          $ra
    // 0x808003C8: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808003C8: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800D389C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D389C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D38A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D38A4: jal         0x800D3770
    // 0x800D38A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800D3770(rdram, ctx);
        goto after_0;
    // 0x800D38A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800D38AC: beq         $v0, $zero, L_800D38C0
    if (ctx->r2 == 0) {
        // 0x800D38B0: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800D38C0;
    }
    // 0x800D38B0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800D38B4: addiu       $s0, $s0, -0x4C10
    ctx->r16 = ADD32(ctx->r16, -0X4C10);
    // 0x800D38B8: jal         0x80088550
    // 0x800D38BC: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    _glsavegame_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x800D38BC: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    after_1:
L_800D38C0:
    // 0x800D38C0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800D38C4: addiu       $s0, $s0, -0x4C10
    ctx->r16 = ADD32(ctx->r16, -0X4C10);
    // 0x800D38C8: lbu         $t6, 0x9($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X9);
    // 0x800D38CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D38D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D38D4: bnel        $t6, $at, L_800D3924
    if (ctx->r14 != ctx->r1) {
        // 0x800D38D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D3924;
    }
    goto skip_0;
    // 0x800D38D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800D38DC: jal         0x8001B668
    // 0x800D38E0: addiu       $a1, $zero, 0x1C0
    ctx->r5 = ADD32(0, 0X1C0);
    func_8001B668(rdram, ctx);
        goto after_2;
    // 0x800D38E0: addiu       $a1, $zero, 0x1C0
    ctx->r5 = ADD32(0, 0X1C0);
    after_2:
    // 0x800D38E4: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x800D38E8: jal         0x8001B798
    // 0x800D38EC: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    func_8001B798(rdram, ctx);
        goto after_3;
    // 0x800D38EC: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    after_3:
    // 0x800D38F0: jal         0x80088578
    // 0x800D38F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _glgamedata_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x800D38F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800D38F8: lb          $t7, 0x1($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1);
    // 0x800D38FC: lbu         $t8, 0x3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3);
    // 0x800D3900: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x800D3904: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800D3908: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800D390C: sb          $t0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r8;
    // 0x800D3910: sb          $t1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r9;
    // 0x800D3914: sb          $t7, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r15;
    // 0x800D3918: sb          $t8, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r24;
    // 0x800D391C: sb          $t9, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r25;
    // 0x800D3920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D3924:
    // 0x800D3924: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D3928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D392C: jr          $ra
    // 0x800D3930: nop

    return;
    // 0x800D3930: nop

;}
RECOMP_FUNC void _baalarm_new(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084428: syscall     110
    recomp_syscall_handler(rdram, ctx, 0x80084428);
    return;
    // 0x8008442C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chcollballcontrol_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803234: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1840, 0X4FA0) << 16);
    // 0x80803238: jr          $ra
    // 0x8080323C: addiu       $v0, $v0, 0x4FA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4FA0));
    return;
    // 0x8080323C: addiu       $v0, $v0, 0x4FA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4FA0));
;}
RECOMP_FUNC void func_800D73CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D73CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D73D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D73D4: jal         0x800D6254
    // 0x800D73D8: nop

    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D73D8: nop

    after_0:
    // 0x800D73DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D73E0: bne         $v0, $at, L_800D73F0
    if (ctx->r2 != ctx->r1) {
        // 0x800D73E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D73F0;
    }
    // 0x800D73E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D73E8: b           L_800D73F4
    // 0x800D73EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800D73F4;
    // 0x800D73EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D73F0:
    // 0x800D73F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D73F4:
    // 0x800D73F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D73F8: jr          $ra
    // 0x800D73FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D73FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800248_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800248: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080024C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800250: jal         0x8008DE24
    // 0x80800254: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8008DE24(rdram, ctx);
        goto after_0;
    // 0x80800254: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800258: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x8080025C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080026C;
    }
    // 0x8080025C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800260: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2DE8) << 16);
    // 0x80800264: b           L_80800294
    // 0x80800268: lwc1        $f0, 0x2DE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2DE8));
        goto L_80800294;
    // 0x80800268: lwc1        $f0, 0x2DE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2DE8));
L_8080026C:
    // 0x8080026C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2DEC) << 16);
    // 0x80800270: lwc1        $f4, 0x2DEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2DEC));
    // 0x80800274: lui         $a1, 0x3F0F
    ctx->r5 = S32(0X3F0F << 16);
    // 0x80800278: lui         $a2, 0x3F02
    ctx->r6 = S32(0X3F02 << 16);
    // 0x8080027C: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x80800280: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800284: ori         $a2, $a2, 0x8F5C
    ctx->r6 = ctx->r6 | 0X8F5C;
    // 0x80800288: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x8080028C: jal         0x80800070
    // 0x80800290: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80800070_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80800290: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
L_80800294:
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800298: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080029C: jr          $ra
    // 0x808002A0: nop

    return;
    // 0x808002A0: nop

;}
RECOMP_FUNC void func_808005F0_bsstonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808005F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800600: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800604: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800608: beq         $a1, $at, L_80800630
    if (ctx->r5 == ctx->r1) {
        // 0x8080060C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80800630;
    }
    // 0x8080060C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800610: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800614: beq         $a1, $at, L_808006C8
    if (ctx->r5 == ctx->r1) {
        // 0x80800618: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808006C8;
    }
    // 0x80800618: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080061C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800620: beql        $a1, $at, L_80800704
    if (ctx->r5 == ctx->r1) {
        // 0x80800624: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80800704;
    }
    goto skip_0;
    // 0x80800624: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800628: b           L_80800704
    // 0x8080062C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_80800704;
    // 0x8080062C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800630:
    // 0x80800630: jal         0x8008CABC
    // 0x80800634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800638: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8080063C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800640: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800648: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080064C: lui         $a2, 0x43D2
    ctx->r6 = S32(0X43D2 << 16);
    // 0x80800650: lui         $a3, 0xC496
    ctx->r7 = S32(0XC496 << 16);
    // 0x80800654: jal         0x80085210
    // 0x80800658: swc1        $f0, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f0.u32l;
    _basudie_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800658: swc1        $f0, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f0.u32l;
    after_1:
    // 0x8080065C: jal         0x8008AF24
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: jal         0x8008B1A0
    // 0x8080066C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_3;
    // 0x8080066C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800674: jal         0x8008AED4
    // 0x80800678: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800678: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_4:
    // 0x8080067C: lui         $a2, 0x3EEB
    ctx->r6 = S32(0X3EEB << 16);
    // 0x80800680: ori         $a2, $a2, 0x851F
    ctx->r6 = ctx->r6 | 0X851F;
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: jal         0x8008B1D4
    // 0x8080068C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x8080068C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800694: jal         0x8008B1BC
    // 0x80800698: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x80800698: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    after_6:
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A0: jal         0x8008B134
    // 0x808006A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x808006A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808006A8: jal         0x8008B064
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808006B0: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x808006B4: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808006B8: jal         0x8009D820
    // 0x808006BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009D820(rdram, ctx);
        goto after_9;
    // 0x808006BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x808006C0: b           L_80800704
    // 0x808006C4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_80800704;
    // 0x808006C4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_808006C8:
    // 0x808006C8: jal         0x8008CED4
    // 0x808006CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_10;
    // 0x808006CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
    // 0x808006D0: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808006D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808006D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006DC: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x808006E0: jal         0x8009DF94
    // 0x808006E4: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_11;
    // 0x808006E4: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_11:
    // 0x808006E8: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x808006EC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808006F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006F4: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x808006F8: jal         0x8009DF18
    // 0x808006FC: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_12;
    // 0x808006FC: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_12:
    // 0x80800700: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800704:
    // 0x80800704: sw          $t7, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r15;
    // 0x80800708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080070C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800710: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800714: jr          $ra
    // 0x80800718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8009E830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E830: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E834: jr          $ra
    // 0x8009E838: sh          $a1, 0xE($t6)
    MEM_H(0XE, ctx->r14) = ctx->r5;
    return;
    // 0x8009E838: sh          $a1, 0xE($t6)
    MEM_H(0XE, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800A7180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7180: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7184: jr          $ra
    // 0x800A7188: addiu       $v0, $v0, 0x7658
    ctx->r2 = ADD32(ctx->r2, 0X7658);
    return;
    // 0x800A7188: addiu       $v0, $v0, 0x7658
    ctx->r2 = ADD32(ctx->r2, 0X7658);
;}
RECOMP_FUNC void func_80800048_chjadesnake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080004C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800050: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800058: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8080005C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800060: addiu       $a2, $t6, 0x28
    ctx->r6 = ADD32(ctx->r14, 0X28);
    // 0x80800064: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080006C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800070: jal         0x800D1000
    // 0x80800074: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800D1000(rdram, ctx);
        goto after_0;
    // 0x80800074: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80800078: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1868, 0X938) << 16);
    // 0x8080007C: addiu       $a2, $a2, 0x938
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1868, 0X938));
    // 0x80800080: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800084: jal         0x80089D18
    // 0x80800088: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800088: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_800C8760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8760: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C8764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8768: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C876C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8770: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800C8774: jal         0x800C85A0
    // 0x800C8778: lw          $a0, -0x5640($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5640);
    func_800C85A0(rdram, ctx);
        goto after_0;
    // 0x800C8778: lw          $a0, -0x5640($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5640);
    after_0:
    // 0x800C877C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8784: jr          $ra
    // 0x800C8788: nop

    return;
    // 0x800C8788: nop

;}
RECOMP_FUNC void func_808013DC_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013E4: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x808013E8: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x808013EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(924, 0X21A4) << 16);
    // 0x808013F0: lwc1        $f14, 0x21A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(924, 0X21A4));
    // 0x808013F4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808013F8: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808013FC: lwc1        $f16, 0x1C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80801400: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80801404: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80801408: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8080140C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80801410: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801414: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80801418: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x8080141C: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    // 0x80801420: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80801424: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80801428: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8080142C: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80801430: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80801434: mul.s       $f16, $f14, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80801438: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x8080143C: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x80801440: jal         0x80102BF8
    // 0x80801444: swc1        $f18, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f18.u32l;
    func_80102BF8(rdram, ctx);
        goto after_0;
    // 0x80801444: swc1        $f18, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f18.u32l;
    after_0:
    // 0x80801448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080144C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801450: jr          $ra
    // 0x80801454: nop

    return;
    // 0x80801454: nop

;}
RECOMP_FUNC void func_80800000_dbshift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800014: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800018: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8080001C: jal         0x800F2290
    // 0x80800020: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800F2290(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80800024: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800028: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080002C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800030: jal         0x800F2388
    // 0x80800034: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800F2388(rdram, ctx);
        goto after_1;
    // 0x80800034: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800038: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080003C: jal         0x800F2290
    // 0x80800040: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800F2290(rdram, ctx);
        goto after_2;
    // 0x80800040: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x80800044: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800048: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8080004C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800050: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800054: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80800058: jal         0x800F2290
    // 0x8080005C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F2290(rdram, ctx);
        goto after_3;
    // 0x8080005C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800060: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800064: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800068: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080006C: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800074: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void func_80800A98_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800A9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800AA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800AAC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800AB0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800AB4: jal         0x800EFA4C
    // 0x80800AB8: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800AB8: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    after_0:
    // 0x80800ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AC4: jr          $ra
    // 0x80800AC8: nop

    return;
    // 0x80800AC8: nop

;}
RECOMP_FUNC void _ncbasuck_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089720: syscall     790
    recomp_syscall_handler(rdram, ctx, 0x80089720);
    return;
    // 0x80089724: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void gcmapsects_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D7C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801D80: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80801D84: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80801D88: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80801D8C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80801D90: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80801D94: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80801D98: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80801D9C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80801DA0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80801DA4: lbu         $v1, 0x77($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X77);
    // 0x80801DA8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801DAC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801DB0: blez        $v1, L_80801EFC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80801DB4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80801EFC;
    }
    // 0x80801DB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801DB8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801DBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2610, 0X29A0) << 16);
    // 0x80801DC0: lwc1        $f20, 0x29A0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2610, 0X29A0));
    // 0x80801DC4: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
L_80801DC8:
    // 0x80801DC8: addu        $v0, $t6, $s1
    ctx->r2 = ADD32(ctx->r14, ctx->r17);
    // 0x80801DCC: lw          $t7, 0x4C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4C);
    // 0x80801DD0: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80801DD4: bnel        $t8, $zero, L_80801DF8
    if (ctx->r24 != 0) {
        // 0x80801DD8: lhu         $s0, 0x40($v0)
        ctx->r16 = MEM_HU(ctx->r2, 0X40);
            goto L_80801DF8;
    }
    goto skip_0;
    // 0x80801DD8: lhu         $s0, 0x40($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X40);
    skip_0:
    // 0x80801DDC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80801DE0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801DE4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80801DE8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801DEC: b           L_80801EEC
    // 0x80801DF0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_80801EEC;
    // 0x80801DF0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80801DF4: lhu         $s0, 0x40($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X40);
L_80801DF8:
    // 0x80801DF8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80801DFC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801E00: bne         $s0, $zero, L_80801E14
    if (ctx->r16 != 0) {
        // 0x80801E04: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_80801E14;
    }
    // 0x80801E04: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80801E08: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801E0C: b           L_80801EEC
    // 0x80801E10: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_80801EEC;
    // 0x80801E10: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80801E14:
    // 0x80801E14: jal         0x800D674C
    // 0x80801E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80801E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801E1C: bne         $v0, $zero, L_80801E40
    if (ctx->r2 != 0) {
        // 0x80801E20: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80801E40;
    }
    // 0x80801E20: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80801E24: lbu         $v1, 0x77($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X77);
    // 0x80801E28: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80801E2C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801E30: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80801E34: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801E38: b           L_80801EEC
    // 0x80801E3C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_80801EEC;
    // 0x80801E3C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80801E40:
    // 0x80801E40: jal         0x800B2840
    // 0x80801E44: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800B2840(rdram, ctx);
        goto after_1;
    // 0x80801E44: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80801E48: jal         0x800BF774
    // 0x80801E4C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    func_800BF774(rdram, ctx);
        goto after_2;
    // 0x80801E4C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_2:
    // 0x80801E50: jal         0x800DF830
    // 0x80801E54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_3;
    // 0x80801E54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80801E58: jal         0x800D731C
    // 0x80801E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D731C(rdram, ctx);
        goto after_4;
    // 0x80801E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801E60: beq         $v0, $zero, L_80801E70
    if (ctx->r2 == 0) {
        // 0x80801E64: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_80801E70;
    }
    // 0x80801E64: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80801E68: jal         0x800DF7E8
    // 0x80801E6C: nop

    func_800DF7E8(rdram, ctx);
        goto after_5;
    // 0x80801E6C: nop

    after_5:
L_80801E70:
    // 0x80801E70: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x80801E74: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80801E78: jal         0x800DF7DC
    // 0x80801E7C: lw          $a0, 0x44($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X44);
    func_800DF7DC(rdram, ctx);
        goto after_6;
    // 0x80801E7C: lw          $a0, 0x44($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X44);
    after_6:
    // 0x80801E80: jal         0x800DF818
    // 0x80801E84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800DF818(rdram, ctx);
        goto after_7;
    // 0x80801E84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x80801E88: jal         0x800DF440
    // 0x80801E8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_8;
    // 0x80801E8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80801E90: jal         0x800DF428
    // 0x80801E94: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DF428(rdram, ctx);
        goto after_9;
    // 0x80801E94: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_9:
    // 0x80801E98: jal         0x800DF4B0
    // 0x80801E9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF4B0(rdram, ctx);
        goto after_10;
    // 0x80801E9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x80801EA0: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x80801EA4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80801EA8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80801EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801EB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801EB4: jal         0x800DE448
    // 0x80801EB8: addu        $a0, $t1, $s1
    ctx->r4 = ADD32(ctx->r9, ctx->r17);
    func_800DE448(rdram, ctx);
        goto after_11;
    // 0x80801EB8: addu        $a0, $t1, $s1
    ctx->r4 = ADD32(ctx->r9, ctx->r17);
    after_11:
    // 0x80801EBC: bnel        $v0, $zero, L_80801ED8
    if (ctx->r2 != 0) {
        // 0x80801EC0: lbu         $v1, 0x77($s2)
        ctx->r3 = MEM_BU(ctx->r18, 0X77);
            goto L_80801ED8;
    }
    goto skip_1;
    // 0x80801EC0: lbu         $v1, 0x77($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X77);
    skip_1:
    // 0x80801EC4: lw          $t2, 0x68($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X68);
    // 0x80801EC8: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80801ECC: jal         0x800D62E4
    // 0x80801ED0: lhu         $a0, 0x40($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X40);
    func_800D62E4(rdram, ctx);
        goto after_12;
    // 0x80801ED0: lhu         $a0, 0x40($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X40);
    after_12:
    // 0x80801ED4: lbu         $v1, 0x77($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X77);
L_80801ED8:
    // 0x80801ED8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80801EDC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801EE0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80801EE4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801EE8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80801EEC:
    // 0x80801EEC: addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    // 0x80801EF0: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801EF4: bnel        $at, $zero, L_80801DC8
    if (ctx->r1 != 0) {
        // 0x80801EF8: lw          $t6, 0x68($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X68);
            goto L_80801DC8;
    }
    goto skip_2;
    // 0x80801EF8: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    skip_2:
L_80801EFC:
    // 0x80801EFC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80801F00: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801F04: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80801F08: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80801F0C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80801F10: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80801F14: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80801F18: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80801F1C: jr          $ra
    // 0x80801F20: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80801F20: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void gcsectionskip_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808003E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808003E8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808003EC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808003F0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808003F4: jal         0x80087AC8
    // 0x808003F8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    _gcgoto_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x808003F8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x808003FC: beq         $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x80800400: nop
    
            goto L_8080040C;
    }
    // 0x80800400: nop

    // 0x80800404: b           L_80800D2C
    // 0x80800408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080040C:
    // 0x8080040C: jal         0x800F54E4
    // 0x80800410: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800410: nop

    after_1:
    // 0x80800414: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80800418: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080041C: beq         $v1, $zero, L_8080043C
    if (ctx->r3 == 0) {
        // 0x80800420: nop
    
            goto L_8080043C;
    }
    // 0x80800420: nop

    // 0x80800424: lhu         $t7, 0x1A($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1A);
    // 0x80800428: srl         $t8, $t7, 5
    ctx->r24 = S32(U32(ctx->r15) >> 5);
    // 0x8080042C: beq         $v0, $t8, L_8080043C
    if (ctx->r2 == ctx->r24) {
        // 0x80800430: nop
    
            goto L_8080043C;
    }
    // 0x80800430: nop

    // 0x80800434: b           L_80800D2C
    // 0x80800438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080043C:
    // 0x8080043C: jal         0x800F5410
    // 0x80800440: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800F5410(rdram, ctx);
        goto after_2;
    // 0x80800440: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800444: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800448: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080044C: jal         0x80087A50
    // 0x80800450: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _gcgoto_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800450: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x80800454: jal         0x800F6D24
    // 0x80800458: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F6D24(rdram, ctx);
        goto after_4;
    // 0x80800458: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8080045C: bnel        $v0, $zero, L_808004B0
    if (ctx->r2 != 0) {
        // 0x80800460: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808004B0;
    }
    goto skip_0;
    // 0x80800460: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80800464: jal         0x800F8004
    // 0x80800468: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F8004(rdram, ctx);
        goto after_5;
    // 0x80800468: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8080046C: bnel        $v0, $zero, L_808004B0
    if (ctx->r2 != 0) {
        // 0x80800470: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808004B0;
    }
    goto skip_1;
    // 0x80800470: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800474: jal         0x800F6CC8
    // 0x80800478: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F6CC8(rdram, ctx);
        goto after_6;
    // 0x80800478: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x8080047C: bnel        $v0, $zero, L_808004B0
    if (ctx->r2 != 0) {
        // 0x80800480: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808004B0;
    }
    goto skip_2;
    // 0x80800480: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80800484: jal         0x800F66F0
    // 0x80800488: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F66F0(rdram, ctx);
        goto after_7;
    // 0x80800488: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x8080048C: bnel        $v0, $zero, L_808004B0
    if (ctx->r2 != 0) {
        // 0x80800490: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808004B0;
    }
    goto skip_3;
    // 0x80800490: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_3:
    // 0x80800494: jal         0x800F54E4
    // 0x80800498: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800498: nop

    after_8:
    // 0x8080049C: jal         0x800F70BC
    // 0x808004A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F70BC(rdram, ctx);
        goto after_9;
    // 0x808004A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x808004A4: beq         $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x808004A8: nop
    
            goto L_808004C0;
    }
    // 0x808004A8: nop

    // 0x808004AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_808004B0:
    // 0x808004B0: jal         0x808002A0
    // 0x808004B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_10;
    // 0x808004B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x808004B8: b           L_80800D2C
    // 0x808004BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808004BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004C0:
    // 0x808004C0: jal         0x800F8B88
    // 0x808004C4: nop

    func_800F8B88(rdram, ctx);
        goto after_11;
    // 0x808004C4: nop

    after_11:
    // 0x808004C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808004CC: bne         $v0, $at, L_808004F0
    if (ctx->r2 != ctx->r1) {
        // 0x808004D0: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_808004F0;
    }
    // 0x808004D0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808004D4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x808004D8: bne         $v1, $v0, L_808004F0
    if (ctx->r3 != ctx->r2) {
        // 0x808004DC: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808004F0;
    }
    // 0x808004DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004E0: jal         0x800F7B9C
    // 0x808004E4: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    func_800F7B9C(rdram, ctx);
        goto after_12;
    // 0x808004E4: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    after_12:
    // 0x808004E8: b           L_80800D2C
    // 0x808004EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808004EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004F0:
    // 0x808004F0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x808004F4: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x808004F8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808004FC: sltiu       $at, $t9, 0x21
    ctx->r1 = ctx->r25 < 0X21 ? 1 : 0;
    // 0x80800500: beq         $at, $zero, L_80800C5C
    if (ctx->r1 == 0) {
        // 0x80800504: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800C5C;
    }
    // 0x80800504: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800508: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2574, 0XF40) << 16);
    // 0x8080050C: addu        $at, $at, $t9
    gpr jr_addend_80800514 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800510: lw          $t9, 0xF40($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2574, 0XF40));
    // 0x80800514: jr          $t9
    // 0x80800518: nop

    switch (jr_addend_80800514 >> 2) {
        case 0: goto L_8080051C; break;
        case 1: goto L_80800544; break;
        case 2: goto L_80800568; break;
        case 3: goto L_8080058C; break;
        case 4: goto L_808005AC; break;
        case 5: goto L_808005F0; break;
        case 6: goto L_80800608; break;
        case 7: goto L_8080062C; break;
        case 8: goto L_8080064C; break;
        case 9: goto L_808007CC; break;
        case 10: goto L_80800C5C; break;
        case 11: goto L_80800690; break;
        case 12: goto L_808006B0; break;
        case 13: goto L_808007A0; break;
        case 14: goto L_80800670; break;
        case 15: goto L_80800C5C; break;
        case 16: goto L_8080081C; break;
        case 17: goto L_80800848; break;
        case 18: goto L_80800864; break;
        case 19: goto L_80800898; break;
        case 20: goto L_808008C0; break;
        case 21: goto L_80800974; break;
        case 22: goto L_80800990; break;
        case 23: goto L_808009C8; break;
        case 24: goto L_80800A3C; break;
        case 25: goto L_80800A58; break;
        case 26: goto L_80800AA8; break;
        case 27: goto L_80800B04; break;
        case 28: goto L_80800B9C; break;
        case 29: goto L_808005C8; break;
        case 30: goto L_80800BC4; break;
        case 31: goto L_80800BEC; break;
        case 32: goto L_80800C30; break;
        default: switch_error(__func__, 0x80800514, 0x80800F40);
    }
    // 0x80800518: nop

L_8080051C:
    // 0x8080051C: jal         0x800F4BE4
    // 0x80800520: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F4BE4(rdram, ctx);
        goto after_13;
    // 0x80800520: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x80800524: bne         $v0, $zero, L_8080053C
    if (ctx->r2 != 0) {
        // 0x80800528: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080053C;
    }
    // 0x80800528: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080052C: jal         0x80800374
    // 0x80800530: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_14;
    // 0x80800530: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_14:
    // 0x80800534: b           L_80800D2C
    // 0x80800538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080053C:
    // 0x8080053C: b           L_80800C5C
    // 0x80800540: nop

        goto L_80800C5C;
    // 0x80800540: nop

L_80800544:
    // 0x80800544: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800548: jal         0x80086C30
    // 0x8080054C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _chchuffycont_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x8080054C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_15:
    // 0x80800550: bne         $v0, $zero, L_80800560
    if (ctx->r2 != 0) {
        // 0x80800554: nop
    
            goto L_80800560;
    }
    // 0x80800554: nop

    // 0x80800558: b           L_80800D2C
    // 0x8080055C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x8080055C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800560:
    // 0x80800560: b           L_80800C5C
    // 0x80800564: nop

        goto L_80800C5C;
    // 0x80800564: nop

L_80800568:
    // 0x80800568: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080056C: jal         0x80086C38
    // 0x80800570: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _chchuffycont_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x80800570: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_16:
    // 0x80800574: bne         $v0, $zero, L_80800584
    if (ctx->r2 != 0) {
        // 0x80800578: nop
    
            goto L_80800584;
    }
    // 0x80800578: nop

    // 0x8080057C: b           L_80800D2C
    // 0x80800580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800584:
    // 0x80800584: b           L_80800C5C
    // 0x80800588: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
        goto L_80800C5C;
    // 0x80800588: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8080058C:
    // 0x8080058C: jal         0x800DA298
    // 0x80800590: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x80800590: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_17:
    // 0x80800594: bne         $v0, $zero, L_808005A4
    if (ctx->r2 != 0) {
        // 0x80800598: nop
    
            goto L_808005A4;
    }
    // 0x80800598: nop

    // 0x8080059C: b           L_80800D2C
    // 0x808005A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808005A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005A4:
    // 0x808005A4: b           L_80800C5C
    // 0x808005A8: nop

        goto L_80800C5C;
    // 0x808005A8: nop

L_808005AC:
    // 0x808005AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005B0: beq         $v1, $at, L_80800C5C
    if (ctx->r3 == ctx->r1) {
        // 0x808005B4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C5C;
    }
    // 0x808005B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005B8: jal         0x80800374
    // 0x808005BC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_18;
    // 0x808005BC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_18:
    // 0x808005C0: b           L_80800D2C
    // 0x808005C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808005C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005C8:
    // 0x808005C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005CC: beq         $v1, $at, L_80800C5C
    if (ctx->r3 == ctx->r1) {
        // 0x808005D0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C5C;
    }
    // 0x808005D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005D4: jal         0x808002A0
    // 0x808005D8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_19;
    // 0x808005D8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_19:
    // 0x808005DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005E0: jal         0x800F7E3C
    // 0x808005E4: addiu       $a1, $zero, 0x1228
    ctx->r5 = ADD32(0, 0X1228);
    func_800F7E3C(rdram, ctx);
        goto after_20;
    // 0x808005E4: addiu       $a1, $zero, 0x1228
    ctx->r5 = ADD32(0, 0X1228);
    after_20:
    // 0x808005E8: b           L_80800D2C
    // 0x808005EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808005EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005F0:
    // 0x808005F0: beq         $v1, $v0, L_80800C5C
    if (ctx->r3 == ctx->r2) {
        // 0x808005F4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C5C;
    }
    // 0x808005F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005F8: jal         0x80800374
    // 0x808005FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_21;
    // 0x808005FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_21:
    // 0x80800600: b           L_80800D2C
    // 0x80800604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800608:
    // 0x80800608: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080060C: beq         $v1, $at, L_80800624
    if (ctx->r3 == ctx->r1) {
        // 0x80800610: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800624;
    }
    // 0x80800610: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800614: jal         0x80800374
    // 0x80800618: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_22;
    // 0x80800618: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_22:
    // 0x8080061C: b           L_80800D2C
    // 0x80800620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800624:
    // 0x80800624: b           L_80800C5C
    // 0x80800628: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
        goto L_80800C5C;
    // 0x80800628: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8080062C:
    // 0x8080062C: jal         0x800DA298
    // 0x80800630: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    func_800DA298(rdram, ctx);
        goto after_23;
    // 0x80800630: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    after_23:
    // 0x80800634: beq         $v0, $zero, L_80800644
    if (ctx->r2 == 0) {
        // 0x80800638: nop
    
            goto L_80800644;
    }
    // 0x80800638: nop

    // 0x8080063C: b           L_80800D2C
    // 0x80800640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800644:
    // 0x80800644: b           L_80800C5C
    // 0x80800648: nop

        goto L_80800C5C;
    // 0x80800648: nop

L_8080064C:
    // 0x8080064C: addiu       $a0, $zero, 0xA34
    ctx->r4 = ADD32(0, 0XA34);
    // 0x80800650: jal         0x800DA564
    // 0x80800654: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_24;
    // 0x80800654: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_24:
    // 0x80800658: beq         $v0, $zero, L_80800668
    if (ctx->r2 == 0) {
        // 0x8080065C: nop
    
            goto L_80800668;
    }
    // 0x8080065C: nop

    // 0x80800660: b           L_80800D2C
    // 0x80800664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800668:
    // 0x80800668: b           L_80800C5C
    // 0x8080066C: nop

        goto L_80800C5C;
    // 0x8080066C: nop

L_80800670:
    // 0x80800670: addiu       $a0, $zero, 0x3A4
    ctx->r4 = ADD32(0, 0X3A4);
    // 0x80800674: jal         0x800DA564
    // 0x80800678: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_25;
    // 0x80800678: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_25:
    // 0x8080067C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2574, 0X1040) << 16);
    // 0x80800680: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80800684: lbu         $t0, 0x1040($t0)
    ctx->r8 = MEM_BU(ctx->r8, (int16_t)RELOC_LO16(2574, 0X1040));
    // 0x80800688: b           L_80800C5C
    // 0x8080068C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
        goto L_80800C5C;
    // 0x8080068C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_80800690:
    // 0x80800690: jal         0x800DA298
    // 0x80800694: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    func_800DA298(rdram, ctx);
        goto after_26;
    // 0x80800694: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    after_26:
    // 0x80800698: beq         $v0, $zero, L_808006A8
    if (ctx->r2 == 0) {
        // 0x8080069C: lw          $t1, 0x38($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X38);
            goto L_808006A8;
    }
    // 0x8080069C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x808006A0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x808006A4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
L_808006A8:
    // 0x808006A8: b           L_80800C5C
    // 0x808006AC: nop

        goto L_80800C5C;
    // 0x808006AC: nop

L_808006B0:
    // 0x808006B0: addiu       $a0, $zero, 0x409
    ctx->r4 = ADD32(0, 0X409);
    // 0x808006B4: jal         0x800DA9E4
    // 0x808006B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_27;
    // 0x808006B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x808006BC: bne         $v0, $zero, L_808006E8
    if (ctx->r2 != 0) {
        // 0x808006C0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808006E8;
    }
    // 0x808006C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808006C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808006C8: jal         0x800DC298
    // 0x808006CC: nop

    func_800DC298(rdram, ctx);
        goto after_28;
    // 0x808006CC: nop

    after_28:
    // 0x808006D0: beq         $v0, $zero, L_808006E0
    if (ctx->r2 == 0) {
        // 0x808006D4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808006E0;
    }
    // 0x808006D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006D8: b           L_808006E0
    // 0x808006DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_808006E0;
    // 0x808006DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808006E0:
    // 0x808006E0: jal         0x800DA3B8
    // 0x808006E4: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    func_800DA3B8(rdram, ctx);
        goto after_29;
    // 0x808006E4: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    after_29:
L_808006E8:
    // 0x808006E8: jal         0x800EA05C
    // 0x808006EC: nop

    func_800EA05C(rdram, ctx);
        goto after_30;
    // 0x808006EC: nop

    after_30:
    // 0x808006F0: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    // 0x808006F4: beq         $v0, $at, L_80800718
    if (ctx->r2 == ctx->r1) {
        // 0x808006F8: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_80800718;
    }
    // 0x808006F8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808006FC: addiu       $at, $zero, 0x13E
    ctx->r1 = ADD32(0, 0X13E);
    // 0x80800700: beq         $v0, $at, L_8080076C
    if (ctx->r2 == ctx->r1) {
        // 0x80800704: addiu       $at, $zero, 0x13F
        ctx->r1 = ADD32(0, 0X13F);
            goto L_8080076C;
    }
    // 0x80800704: addiu       $at, $zero, 0x13F
    ctx->r1 = ADD32(0, 0X13F);
    // 0x80800708: beq         $v0, $at, L_80800784
    if (ctx->r2 == ctx->r1) {
        // 0x8080070C: nop
    
            goto L_80800784;
    }
    // 0x8080070C: nop

    // 0x80800710: b           L_80800798
    // 0x80800714: nop

        goto L_80800798;
    // 0x80800714: nop

L_80800718:
    // 0x80800718: addiu       $at, $zero, 0x13E
    ctx->r1 = ADD32(0, 0X13E);
    // 0x8080071C: beq         $a1, $at, L_80800734
    if (ctx->r5 == ctx->r1) {
        // 0x80800720: addiu       $at, $zero, 0x13F
        ctx->r1 = ADD32(0, 0X13F);
            goto L_80800734;
    }
    // 0x80800720: addiu       $at, $zero, 0x13F
    ctx->r1 = ADD32(0, 0X13F);
    // 0x80800724: beq         $a1, $at, L_8080074C
    if (ctx->r5 == ctx->r1) {
        // 0x80800728: nop
    
            goto L_8080074C;
    }
    // 0x80800728: nop

    // 0x8080072C: b           L_80800D2C
    // 0x80800730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800734:
    // 0x80800734: jal         0x800DA298
    // 0x80800738: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    func_800DA298(rdram, ctx);
        goto after_31;
    // 0x80800738: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    after_31:
    // 0x8080073C: bne         $v0, $zero, L_80800798
    if (ctx->r2 != 0) {
        // 0x80800740: addiu       $a1, $zero, 0x13F
        ctx->r5 = ADD32(0, 0X13F);
            goto L_80800798;
    }
    // 0x80800740: addiu       $a1, $zero, 0x13F
    ctx->r5 = ADD32(0, 0X13F);
    // 0x80800744: b           L_80800798
    // 0x80800748: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
        goto L_80800798;
    // 0x80800748: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
L_8080074C:
    // 0x8080074C: jal         0x800DA298
    // 0x80800750: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    func_800DA298(rdram, ctx);
        goto after_32;
    // 0x80800750: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    after_32:
    // 0x80800754: bne         $v0, $zero, L_80800798
    if (ctx->r2 != 0) {
        // 0x80800758: addiu       $a1, $zero, 0x13E
        ctx->r5 = ADD32(0, 0X13E);
            goto L_80800798;
    }
    // 0x80800758: addiu       $a1, $zero, 0x13E
    ctx->r5 = ADD32(0, 0X13E);
    // 0x8080075C: b           L_80800798
    // 0x80800760: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
        goto L_80800798;
    // 0x80800760: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800764: b           L_80800D2C
    // 0x80800768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080076C:
    // 0x8080076C: jal         0x800DA298
    // 0x80800770: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    func_800DA298(rdram, ctx);
        goto after_33;
    // 0x80800770: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    after_33:
    // 0x80800774: bne         $v0, $zero, L_80800798
    if (ctx->r2 != 0) {
        // 0x80800778: addiu       $t3, $zero, 0x9
        ctx->r11 = ADD32(0, 0X9);
            goto L_80800798;
    }
    // 0x80800778: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x8080077C: b           L_80800798
    // 0x80800780: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
        goto L_80800798;
    // 0x80800780: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_80800784:
    // 0x80800784: jal         0x800DA298
    // 0x80800788: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    func_800DA298(rdram, ctx);
        goto after_34;
    // 0x80800788: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    after_34:
    // 0x8080078C: bne         $v0, $zero, L_80800798
    if (ctx->r2 != 0) {
        // 0x80800790: addiu       $t4, $zero, 0x16
        ctx->r12 = ADD32(0, 0X16);
            goto L_80800798;
    }
    // 0x80800790: addiu       $t4, $zero, 0x16
    ctx->r12 = ADD32(0, 0X16);
    // 0x80800794: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_80800798:
    // 0x80800798: b           L_80800C5C
    // 0x8080079C: nop

        goto L_80800C5C;
    // 0x8080079C: nop

L_808007A0:
    // 0x808007A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808007A4: jal         0x80800D3C
    // 0x808007A8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80800D3C_gcsectionskip(rdram, ctx);
        goto after_35;
    // 0x808007A8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_35:
    // 0x808007AC: bne         $v0, $zero, L_808007C4
    if (ctx->r2 != 0) {
        // 0x808007B0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808007C4;
    }
    // 0x808007B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007B4: jal         0x80800374
    // 0x808007B8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_36;
    // 0x808007B8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_36:
    // 0x808007BC: b           L_80800D2C
    // 0x808007C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808007C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007C4:
    // 0x808007C4: b           L_80800C5C
    // 0x808007C8: nop

        goto L_80800C5C;
    // 0x808007C8: nop

L_808007CC:
    // 0x808007CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007D0: beq         $v1, $at, L_808007E8
    if (ctx->r3 == ctx->r1) {
        // 0x808007D4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808007E8;
    }
    // 0x808007D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007D8: jal         0x808002A0
    // 0x808007DC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_37;
    // 0x808007DC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_37:
    // 0x808007E0: b           L_80800D2C
    // 0x808007E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808007E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007E8:
    // 0x808007E8: jal         0x800C6E38
    // 0x808007EC: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800C6E38(rdram, ctx);
        goto after_38;
    // 0x808007EC: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_38:
    // 0x808007F0: bne         $v0, $zero, L_80800814
    if (ctx->r2 != 0) {
        // 0x808007F4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800814;
    }
    // 0x808007F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007F8: jal         0x808002A0
    // 0x808007FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_39;
    // 0x808007FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_39:
    // 0x80800800: addiu       $a0, $zero, 0x10FB
    ctx->r4 = ADD32(0, 0X10FB);
    // 0x80800804: jal         0x80800EF8
    // 0x80800808: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_40;
    // 0x80800808: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_40:
    // 0x8080080C: b           L_80800D2C
    // 0x80800810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800814:
    // 0x80800814: b           L_80800C5C
    // 0x80800818: nop

        goto L_80800C5C;
    // 0x80800818: nop

L_8080081C:
    // 0x8080081C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800820: beq         $v1, $at, L_80800840
    if (ctx->r3 == ctx->r1) {
        // 0x80800824: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800840;
    }
    // 0x80800824: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800828: beq         $v1, $at, L_80800840
    if (ctx->r3 == ctx->r1) {
        // 0x8080082C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800840;
    }
    // 0x8080082C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800830: jal         0x80800374
    // 0x80800834: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_41;
    // 0x80800834: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_41:
    // 0x80800838: b           L_80800D2C
    // 0x8080083C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x8080083C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800840:
    // 0x80800840: b           L_80800C5C
    // 0x80800844: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
        goto L_80800C5C;
    // 0x80800844: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80800848:
    // 0x80800848: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8080084C: beq         $v1, $at, L_80800C5C
    if (ctx->r3 == ctx->r1) {
        // 0x80800850: addiu       $a0, $zero, 0x1219
        ctx->r4 = ADD32(0, 0X1219);
            goto L_80800C5C;
    }
    // 0x80800850: addiu       $a0, $zero, 0x1219
    ctx->r4 = ADD32(0, 0X1219);
    // 0x80800854: jal         0x80800EF8
    // 0x80800858: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_42;
    // 0x80800858: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_42:
    // 0x8080085C: b           L_80800D2C
    // 0x80800860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800864:
    // 0x80800864: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800868: bne         $v1, $at, L_80800880
    if (ctx->r3 != ctx->r1) {
        // 0x8080086C: addiu       $a0, $zero, 0x1545
        ctx->r4 = ADD32(0, 0X1545);
            goto L_80800880;
    }
    // 0x8080086C: addiu       $a0, $zero, 0x1545
    ctx->r4 = ADD32(0, 0X1545);
    // 0x80800870: jal         0x80800EF8
    // 0x80800874: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_43;
    // 0x80800874: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
    after_43:
    // 0x80800878: b           L_80800D2C
    // 0x8080087C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x8080087C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800880:
    // 0x80800880: bne         $v1, $v0, L_80800C5C
    if (ctx->r3 != ctx->r2) {
        // 0x80800884: addiu       $a0, $zero, 0x1544
        ctx->r4 = ADD32(0, 0X1544);
            goto L_80800C5C;
    }
    // 0x80800884: addiu       $a0, $zero, 0x1544
    ctx->r4 = ADD32(0, 0X1544);
    // 0x80800888: jal         0x80800EF8
    // 0x8080088C: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_44;
    // 0x8080088C: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
    after_44:
    // 0x80800890: b           L_80800D2C
    // 0x80800894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800898:
    // 0x80800898: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8080089C: beq         $v1, $at, L_80800C5C
    if (ctx->r3 == ctx->r1) {
        // 0x808008A0: addiu       $a0, $zero, 0xF56
        ctx->r4 = ADD32(0, 0XF56);
            goto L_80800C5C;
    }
    // 0x808008A0: addiu       $a0, $zero, 0xF56
    ctx->r4 = ADD32(0, 0XF56);
    // 0x808008A4: jal         0x80800EF8
    // 0x808008A8: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_45;
    // 0x808008A8: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
    after_45:
    // 0x808008AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008B0: jal         0x808002A0
    // 0x808008B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_46;
    // 0x808008B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_46:
    // 0x808008B8: b           L_80800D2C
    // 0x808008BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808008BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008C0:
    // 0x808008C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008C4: beq         $v1, $at, L_808008E8
    if (ctx->r3 == ctx->r1) {
        // 0x808008C8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808008E8;
    }
    // 0x808008C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008CC: jal         0x808002A0
    // 0x808008D0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_47;
    // 0x808008D0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_47:
    // 0x808008D4: addiu       $a0, $zero, 0x1221
    ctx->r4 = ADD32(0, 0X1221);
    // 0x808008D8: jal         0x80800EF8
    // 0x808008DC: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_48;
    // 0x808008DC: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_48:
    // 0x808008E0: b           L_80800D2C
    // 0x808008E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808008E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008E8:
    // 0x808008E8: jal         0x800C6E38
    // 0x808008EC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800C6E38(rdram, ctx);
        goto after_49;
    // 0x808008EC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_49:
    // 0x808008F0: bne         $v0, $zero, L_80800914
    if (ctx->r2 != 0) {
        // 0x808008F4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800914;
    }
    // 0x808008F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008F8: jal         0x808002A0
    // 0x808008FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_50;
    // 0x808008FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_50:
    // 0x80800900: addiu       $a0, $zero, 0x1227
    ctx->r4 = ADD32(0, 0X1227);
    // 0x80800904: jal         0x80800EF8
    // 0x80800908: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_51;
    // 0x80800908: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_51:
    // 0x8080090C: b           L_80800D2C
    // 0x80800910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800914:
    // 0x80800914: jal         0x800C6E38
    // 0x80800918: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    func_800C6E38(rdram, ctx);
        goto after_52;
    // 0x80800918: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_52:
    // 0x8080091C: bne         $v0, $zero, L_80800940
    if (ctx->r2 != 0) {
        // 0x80800920: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800940;
    }
    // 0x80800920: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800924: jal         0x808002A0
    // 0x80800928: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_53;
    // 0x80800928: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_53:
    // 0x8080092C: addiu       $a0, $zero, 0x122A
    ctx->r4 = ADD32(0, 0X122A);
    // 0x80800930: jal         0x80800EF8
    // 0x80800934: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_54;
    // 0x80800934: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_54:
    // 0x80800938: b           L_80800D2C
    // 0x8080093C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x8080093C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800940:
    // 0x80800940: jal         0x800DA298
    // 0x80800944: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    func_800DA298(rdram, ctx);
        goto after_55;
    // 0x80800944: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_55:
    // 0x80800948: beq         $v0, $zero, L_8080096C
    if (ctx->r2 == 0) {
        // 0x8080094C: nop
    
            goto L_8080096C;
    }
    // 0x8080094C: nop

    // 0x80800950: jal         0x800DA298
    // 0x80800954: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800DA298(rdram, ctx);
        goto after_56;
    // 0x80800954: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_56:
    // 0x80800958: bne         $v0, $zero, L_8080096C
    if (ctx->r2 != 0) {
        // 0x8080095C: addiu       $a1, $zero, 0x19A
        ctx->r5 = ADD32(0, 0X19A);
            goto L_8080096C;
    }
    // 0x8080095C: addiu       $a1, $zero, 0x19A
    ctx->r5 = ADD32(0, 0X19A);
    // 0x80800960: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800964: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80800968: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
L_8080096C:
    // 0x8080096C: b           L_80800C5C
    // 0x80800970: nop

        goto L_80800C5C;
    // 0x80800970: nop

L_80800974:
    // 0x80800974: jal         0x800DA298
    // 0x80800978: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA298(rdram, ctx);
        goto after_57;
    // 0x80800978: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_57:
    // 0x8080097C: beq         $v0, $zero, L_80800988
    if (ctx->r2 == 0) {
        // 0x80800980: addiu       $a1, $zero, 0x19B
        ctx->r5 = ADD32(0, 0X19B);
            goto L_80800988;
    }
    // 0x80800980: addiu       $a1, $zero, 0x19B
    ctx->r5 = ADD32(0, 0X19B);
    // 0x80800984: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
L_80800988:
    // 0x80800988: b           L_80800C5C
    // 0x8080098C: nop

        goto L_80800C5C;
    // 0x8080098C: nop

L_80800990:
    // 0x80800990: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800994: jal         0x800F64A4
    // 0x80800998: addiu       $a1, $zero, 0x601
    ctx->r5 = ADD32(0, 0X601);
    func_800F64A4(rdram, ctx);
        goto after_58;
    // 0x80800998: addiu       $a1, $zero, 0x601
    ctx->r5 = ADD32(0, 0X601);
    after_58:
    // 0x8080099C: bne         $v0, $zero, L_808009C0
    if (ctx->r2 != 0) {
        // 0x808009A0: addiu       $a0, $zero, 0x1211
        ctx->r4 = ADD32(0, 0X1211);
            goto L_808009C0;
    }
    // 0x808009A0: addiu       $a0, $zero, 0x1211
    ctx->r4 = ADD32(0, 0X1211);
    // 0x808009A4: jal         0x80800EF8
    // 0x808009A8: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_59;
    // 0x808009A8: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    after_59:
    // 0x808009AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009B0: jal         0x808002A0
    // 0x808009B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_60;
    // 0x808009B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_60:
    // 0x808009B8: b           L_80800D2C
    // 0x808009BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808009BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009C0:
    // 0x808009C0: b           L_80800C5C
    // 0x808009C4: nop

        goto L_80800C5C;
    // 0x808009C4: nop

L_808009C8:
    // 0x808009C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009CC: jal         0x800F64A4
    // 0x808009D0: addiu       $a1, $zero, 0x801
    ctx->r5 = ADD32(0, 0X801);
    func_800F64A4(rdram, ctx);
        goto after_61;
    // 0x808009D0: addiu       $a1, $zero, 0x801
    ctx->r5 = ADD32(0, 0X801);
    after_61:
    // 0x808009D4: bne         $v0, $zero, L_808009F8
    if (ctx->r2 != 0) {
        // 0x808009D8: addiu       $a0, $zero, 0x1223
        ctx->r4 = ADD32(0, 0X1223);
            goto L_808009F8;
    }
    // 0x808009D8: addiu       $a0, $zero, 0x1223
    ctx->r4 = ADD32(0, 0X1223);
    // 0x808009DC: jal         0x80800EF8
    // 0x808009E0: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_62;
    // 0x808009E0: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    after_62:
    // 0x808009E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009E8: jal         0x808002A0
    // 0x808009EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_63;
    // 0x808009EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_63:
    // 0x808009F0: b           L_80800D2C
    // 0x808009F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x808009F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009F8:
    // 0x808009F8: jal         0x800C6E38
    // 0x808009FC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    func_800C6E38(rdram, ctx);
        goto after_64;
    // 0x808009FC: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_64:
    // 0x80800A00: beql        $v0, $zero, L_80800A18
    if (ctx->r2 == 0) {
        // 0x80800A04: addiu       $a0, $zero, 0x1226
        ctx->r4 = ADD32(0, 0X1226);
            goto L_80800A18;
    }
    goto skip_4;
    // 0x80800A04: addiu       $a0, $zero, 0x1226
    ctx->r4 = ADD32(0, 0X1226);
    skip_4:
    // 0x80800A08: jal         0x800C6E38
    // 0x80800A0C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_800C6E38(rdram, ctx);
        goto after_65;
    // 0x80800A0C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_65:
    // 0x80800A10: bne         $v0, $zero, L_80800A34
    if (ctx->r2 != 0) {
        // 0x80800A14: addiu       $a0, $zero, 0x1226
        ctx->r4 = ADD32(0, 0X1226);
            goto L_80800A34;
    }
    // 0x80800A14: addiu       $a0, $zero, 0x1226
    ctx->r4 = ADD32(0, 0X1226);
L_80800A18:
    // 0x80800A18: jal         0x80800EF8
    // 0x80800A1C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    func_80800EF8_gcsectionskip(rdram, ctx);
        goto after_66;
    // 0x80800A1C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    after_66:
    // 0x80800A20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A24: jal         0x808002A0
    // 0x80800A28: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_67;
    // 0x80800A28: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_67:
    // 0x80800A2C: b           L_80800D2C
    // 0x80800A30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800A30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A34:
    // 0x80800A34: b           L_80800C5C
    // 0x80800A38: nop

        goto L_80800C5C;
    // 0x80800A38: nop

L_80800A3C:
    // 0x80800A3C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800A40: bne         $v1, $at, L_80800C5C
    if (ctx->r3 != ctx->r1) {
        // 0x80800A44: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C5C;
    }
    // 0x80800A44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A48: jal         0x80800374
    // 0x80800A4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_68;
    // 0x80800A4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_68:
    // 0x80800A50: b           L_80800D2C
    // 0x80800A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A58:
    // 0x80800A58: jal         0x800F54E4
    // 0x80800A5C: nop

    func_800F54E4(rdram, ctx);
        goto after_69;
    // 0x80800A5C: nop

    after_69:
    // 0x80800A60: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800A64: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A6C: bne         $t6, $at, L_80800A84
    if (ctx->r14 != ctx->r1) {
        // 0x80800A70: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_80800A84;
    }
    // 0x80800A70: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800A74: jal         0x80800374
    // 0x80800A78: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_70;
    // 0x80800A78: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_70:
    // 0x80800A7C: b           L_80800D2C
    // 0x80800A80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800A80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A84:
    // 0x80800A84: jal         0x800EA05C
    // 0x80800A88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_71;
    // 0x80800A88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_71:
    // 0x80800A8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A90: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    // 0x80800A94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800A98: jal         0x800F7C9C
    // 0x80800A9C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800F7C9C(rdram, ctx);
        goto after_72;
    // 0x80800A9C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_72:
    // 0x80800AA0: b           L_80800C5C
    // 0x80800AA4: nop

        goto L_80800C5C;
    // 0x80800AA4: nop

L_80800AA8:
    // 0x80800AA8: jal         0x800F54E4
    // 0x80800AAC: nop

    func_800F54E4(rdram, ctx);
        goto after_73;
    // 0x80800AAC: nop

    after_73:
    // 0x80800AB0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800AB4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800AB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800ABC: bne         $t7, $at, L_80800AD4
    if (ctx->r15 != ctx->r1) {
        // 0x80800AC0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800AD4;
    }
    // 0x80800AC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AC4: jal         0x80800374
    // 0x80800AC8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_74;
    // 0x80800AC8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_74:
    // 0x80800ACC: b           L_80800D2C
    // 0x80800AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AD4:
    // 0x80800AD4: jal         0x800EA05C
    // 0x80800AD8: nop

    func_800EA05C(rdram, ctx);
        goto after_75;
    // 0x80800AD8: nop

    after_75:
    // 0x80800ADC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AE0: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    // 0x80800AE4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800AE8: jal         0x800F7C9C
    // 0x80800AEC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800F7C9C(rdram, ctx);
        goto after_76;
    // 0x80800AEC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_76:
    // 0x80800AF0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AF4: jal         0x800F7B9C
    // 0x80800AF8: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    func_800F7B9C(rdram, ctx);
        goto after_77;
    // 0x80800AF8: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    after_77:
    // 0x80800AFC: b           L_80800C5C
    // 0x80800B00: nop

        goto L_80800C5C;
    // 0x80800B00: nop

L_80800B04:
    // 0x80800B04: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800B08: bne         $v1, $at, L_80800B20
    if (ctx->r3 != ctx->r1) {
        // 0x80800B0C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800B20;
    }
    // 0x80800B0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B10: jal         0x80800374
    // 0x80800B14: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_78;
    // 0x80800B14: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_78:
    // 0x80800B18: b           L_80800D2C
    // 0x80800B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B20:
    // 0x80800B20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B24: beq         $v1, $at, L_80800B58
    if (ctx->r3 == ctx->r1) {
        // 0x80800B28: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800B58;
    }
    // 0x80800B28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B2C: jal         0x800F7E3C
    // 0x80800B30: addiu       $a1, $zero, 0x1224
    ctx->r5 = ADD32(0, 0X1224);
    func_800F7E3C(rdram, ctx);
        goto after_79;
    // 0x80800B30: addiu       $a1, $zero, 0x1224
    ctx->r5 = ADD32(0, 0X1224);
    after_79:
    // 0x80800B34: beql        $v0, $zero, L_80800B48
    if (ctx->r2 == 0) {
        // 0x80800B38: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800B48;
    }
    goto skip_5;
    // 0x80800B38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_5:
    // 0x80800B3C: jal         0x80086B58
    // 0x80800B40: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_80;
    // 0x80800B40: nop

    after_80:
    // 0x80800B44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800B48:
    // 0x80800B48: jal         0x808002A0
    // 0x80800B4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_81;
    // 0x80800B4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_81:
    // 0x80800B50: b           L_80800D2C
    // 0x80800B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B58:
    // 0x80800B58: jal         0x800C6E38
    // 0x80800B5C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_800C6E38(rdram, ctx);
        goto after_82;
    // 0x80800B5C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_82:
    // 0x80800B60: bne         $v0, $zero, L_80800B94
    if (ctx->r2 != 0) {
        // 0x80800B64: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800B94;
    }
    // 0x80800B64: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B68: jal         0x800F7E3C
    // 0x80800B6C: addiu       $a1, $zero, 0x122B
    ctx->r5 = ADD32(0, 0X122B);
    func_800F7E3C(rdram, ctx);
        goto after_83;
    // 0x80800B6C: addiu       $a1, $zero, 0x122B
    ctx->r5 = ADD32(0, 0X122B);
    after_83:
    // 0x80800B70: beql        $v0, $zero, L_80800B84
    if (ctx->r2 == 0) {
        // 0x80800B74: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800B84;
    }
    goto skip_6;
    // 0x80800B74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_6:
    // 0x80800B78: jal         0x80086B58
    // 0x80800B7C: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_84;
    // 0x80800B7C: nop

    after_84:
    // 0x80800B80: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800B84:
    // 0x80800B84: jal         0x808002A0
    // 0x80800B88: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_85;
    // 0x80800B88: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_85:
    // 0x80800B8C: b           L_80800D2C
    // 0x80800B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B94:
    // 0x80800B94: b           L_80800C5C
    // 0x80800B98: nop

        goto L_80800C5C;
    // 0x80800B98: nop

L_80800B9C:
    // 0x80800B9C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800BA0: bne         $v1, $at, L_80800C5C
    if (ctx->r3 != ctx->r1) {
        // 0x80800BA4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C5C;
    }
    // 0x80800BA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BA8: jal         0x80800374
    // 0x80800BAC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_86;
    // 0x80800BAC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_86:
    // 0x80800BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BB4: jal         0x808002A0
    // 0x80800BB8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_87;
    // 0x80800BB8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_87:
    // 0x80800BBC: b           L_80800D2C
    // 0x80800BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BC4:
    // 0x80800BC4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800BC8: bne         $v1, $at, L_80800C5C
    if (ctx->r3 != ctx->r1) {
        // 0x80800BCC: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C5C;
    }
    // 0x80800BCC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BD0: jal         0x800F7E3C
    // 0x80800BD4: addiu       $a1, $zero, 0x1215
    ctx->r5 = ADD32(0, 0X1215);
    func_800F7E3C(rdram, ctx);
        goto after_88;
    // 0x80800BD4: addiu       $a1, $zero, 0x1215
    ctx->r5 = ADD32(0, 0X1215);
    after_88:
    // 0x80800BD8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BDC: jal         0x808002A0
    // 0x80800BE0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_89;
    // 0x80800BE0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_89:
    // 0x80800BE4: b           L_80800D2C
    // 0x80800BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BEC:
    // 0x80800BEC: jal         0x800DA298
    // 0x80800BF0: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA298(rdram, ctx);
        goto after_90;
    // 0x80800BF0: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_90:
    // 0x80800BF4: bne         $v0, $zero, L_80800C28
    if (ctx->r2 != 0) {
        // 0x80800BF8: nop
    
            goto L_80800C28;
    }
    // 0x80800BF8: nop

    // 0x80800BFC: jal         0x800DA298
    // 0x80800C00: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_91;
    // 0x80800C00: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_91:
    // 0x80800C04: bne         $v0, $zero, L_80800C28
    if (ctx->r2 != 0) {
        // 0x80800C08: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C28;
    }
    // 0x80800C08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C0C: jal         0x800F7E3C
    // 0x80800C10: addiu       $a1, $zero, 0x1566
    ctx->r5 = ADD32(0, 0X1566);
    func_800F7E3C(rdram, ctx);
        goto after_92;
    // 0x80800C10: addiu       $a1, $zero, 0x1566
    ctx->r5 = ADD32(0, 0X1566);
    after_92:
    // 0x80800C14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C18: jal         0x808002A0
    // 0x80800C1C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_93;
    // 0x80800C1C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_93:
    // 0x80800C20: b           L_80800D2C
    // 0x80800C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C28:
    // 0x80800C28: b           L_80800C5C
    // 0x80800C2C: nop

        goto L_80800C5C;
    // 0x80800C2C: nop

L_80800C30:
    // 0x80800C30: jal         0x800C6E38
    // 0x80800C34: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_800C6E38(rdram, ctx);
        goto after_94;
    // 0x80800C34: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_94:
    // 0x80800C38: bne         $v0, $zero, L_80800C5C
    if (ctx->r2 != 0) {
        // 0x80800C3C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C5C;
    }
    // 0x80800C3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C40: jal         0x800F7E3C
    // 0x80800C44: addiu       $a1, $zero, 0x122C
    ctx->r5 = ADD32(0, 0X122C);
    func_800F7E3C(rdram, ctx);
        goto after_95;
    // 0x80800C44: addiu       $a1, $zero, 0x122C
    ctx->r5 = ADD32(0, 0X122C);
    after_95:
    // 0x80800C48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C4C: jal         0x808002A0
    // 0x80800C50: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_96;
    // 0x80800C50: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_96:
    // 0x80800C54: b           L_80800D2C
    // 0x80800C58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800C58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C5C:
    // 0x80800C5C: jal         0x800D395C
    // 0x80800C60: nop

    func_800D395C(rdram, ctx);
        goto after_97;
    // 0x80800C60: nop

    after_97:
    // 0x80800C64: bnel        $v0, $zero, L_80800C80
    if (ctx->r2 != 0) {
        // 0x80800C68: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800C80;
    }
    goto skip_7;
    // 0x80800C68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_7:
    // 0x80800C6C: jal         0x800D3948
    // 0x80800C70: nop

    func_800D3948(rdram, ctx);
        goto after_98;
    // 0x80800C70: nop

    after_98:
    // 0x80800C74: beq         $v0, $zero, L_80800C90
    if (ctx->r2 == 0) {
        // 0x80800C78: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_80800C90;
    }
    // 0x80800C78: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800C80:
    // 0x80800C80: jal         0x808002A0
    // 0x80800C84: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_99;
    // 0x80800C84: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_99:
    // 0x80800C88: b           L_80800D2C
    // 0x80800C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C90:
    // 0x80800C90: beq         $t8, $zero, L_80800D04
    if (ctx->r24 == 0) {
        // 0x80800C94: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80800D04;
    }
    // 0x80800C94: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800C98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C9C: beq         $t9, $at, L_80800D04
    if (ctx->r25 == ctx->r1) {
        // 0x80800CA0: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_80800D04;
    }
    // 0x80800CA0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80800CA4: lbu         $a2, 0x762C($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X762C);
    // 0x80800CA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800CAC: jal         0x80088268
    // 0x80800CB0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_100;
    // 0x80800CB0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_100:
    // 0x80800CB4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800CB8: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80800CBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800CC0: xor         $v1, $v0, $a2
    ctx->r3 = ctx->r2 ^ ctx->r6;
    // 0x80800CC4: sltiu       $a1, $v1, 0x1
    ctx->r5 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800CC8: beq         $a1, $zero, L_80800CDC
    if (ctx->r5 == 0) {
        // 0x80800CCC: nop
    
            goto L_80800CDC;
    }
    // 0x80800CCC: nop

    // 0x80800CD0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800CD4: xori        $t0, $a1, 0xD
    ctx->r8 = ctx->r5 ^ 0XD;
    // 0x80800CD8: sltiu       $a1, $t0, 0x1
    ctx->r5 = ctx->r8 < 0X1 ? 1 : 0;
L_80800CDC:
    // 0x80800CDC: bne         $a2, $v0, L_80800CF4
    if (ctx->r6 != ctx->r2) {
        // 0x80800CE0: nop
    
            goto L_80800CF4;
    }
    // 0x80800CE0: nop

    // 0x80800CE4: bne         $a2, $at, L_80800D04
    if (ctx->r6 != ctx->r1) {
        // 0x80800CE8: nop
    
            goto L_80800D04;
    }
    // 0x80800CE8: nop

    // 0x80800CEC: bne         $a1, $zero, L_80800D04
    if (ctx->r5 != 0) {
        // 0x80800CF0: nop
    
            goto L_80800D04;
    }
    // 0x80800CF0: nop

L_80800CF4:
    // 0x80800CF4: jal         0x80800374
    // 0x80800CF8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800374_gcsectionskip(rdram, ctx);
        goto after_101;
    // 0x80800CF8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_101:
    // 0x80800CFC: b           L_80800D2C
    // 0x80800D00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800D00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D04:
    // 0x80800D04: jal         0x800A8264
    // 0x80800D08: nop

    func_800A8264(rdram, ctx);
        goto after_102;
    // 0x80800D08: nop

    after_102:
    // 0x80800D0C: beq         $v0, $zero, L_80800D1C
    if (ctx->r2 == 0) {
        // 0x80800D10: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_80800D1C;
    }
    // 0x80800D10: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800D14: b           L_80800D2C
    // 0x80800D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D2C;
    // 0x80800D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D1C:
    // 0x80800D1C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800D20: jal         0x80087A68
    // 0x80800D24: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    _gcgoto_entrypoint_3(rdram, ctx);
        goto after_103;
    // 0x80800D24: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_103:
    // 0x80800D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D2C:
    // 0x80800D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800D34: jr          $ra
    // 0x80800D38: nop

    return;
    // 0x80800D38: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A70: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A70);
    return;
    // 0x80082A74: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_808014A8_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808014AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808014B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808014B4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808014B8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808014BC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808014C0: lh          $t6, 0x172($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X172);
    // 0x808014C4: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x808014C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808014CC: beq         $t6, $at, L_80801558
    if (ctx->r14 == ctx->r1) {
        // 0x808014D0: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80801558;
    }
    // 0x808014D0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x808014D4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808014D8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808014DC: lwc1        $f0, 0x1DC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1DC);
    // 0x808014E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808014E4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x808014E8: lb          $a2, 0x1CF($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1CF);
    // 0x808014EC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808014F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808014F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808014F8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808014FC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80801500: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80801504: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801508: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8080150C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801510: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80801514: lh          $t0, 0x1BC($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1BC);
    // 0x80801518: lh          $t9, 0x1AC($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1AC);
    // 0x8080151C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801520: mflo        $t1
    ctx->r9 = lo;
    // 0x80801524: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80801528: nop

    // 0x8080152C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801530: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801534: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80801538: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8080153C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80801540: nop

    // 0x80801544: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801548: lbu         $t4, 0x1E4($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1E4);
    // 0x8080154C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80801550: jal         0x80088B50
    // 0x80801554: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    _fxdialog_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80801554: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_0:
L_80801558:
    // 0x80801558: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080155C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801560: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801564: jr          $ra
    // 0x80801568: nop

    return;
    // 0x80801568: nop

;}
RECOMP_FUNC void func_80800ECC_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800ED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800ED4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800ED8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EDC: jal         0x80100094
    // 0x80800EE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800EE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800EE4: lbu         $t6, 0x93($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X93);
    // 0x80800EE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EEC: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80800EF0: beql        $at, $zero, L_80800F20
    if (ctx->r1 == 0) {
        // 0x80800EF4: lhu         $t2, 0x6E($a0)
        ctx->r10 = MEM_HU(ctx->r4, 0X6E);
            goto L_80800F20;
    }
    goto skip_0;
    // 0x80800EF4: lhu         $t2, 0x6E($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X6E);
    skip_0:
    // 0x80800EF8: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x80800EFC: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800F00: bnel        $t8, $zero, L_80800F30
    if (ctx->r24 != 0) {
        // 0x80800F04: lw          $t5, 0x1C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X1C);
            goto L_80800F30;
    }
    goto skip_1;
    // 0x80800F04: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800F08: lhu         $t9, 0x6E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800F0C: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800F10: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80800F14: b           L_80800F2C
    // 0x80800F18: sh          $t1, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r9;
        goto L_80800F2C;
    // 0x80800F18: sh          $t1, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r9;
    // 0x80800F1C: lhu         $t2, 0x6E($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X6E);
L_80800F20:
    // 0x80800F20: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80800F24: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x80800F28: sh          $t4, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r12;
L_80800F2C:
    // 0x80800F2C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
L_80800F30:
    // 0x80800F30: beq         $t5, $zero, L_80800F48
    if (ctx->r13 == 0) {
        // 0x80800F34: nop
    
            goto L_80800F48;
    }
    // 0x80800F34: nop

    // 0x80800F38: jal         0x808007C4
    // 0x80800F3C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_1;
    // 0x80800F3C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x80800F40: b           L_80800F54
    // 0x80800F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F54;
    // 0x80800F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F48:
    // 0x80800F48: jal         0x808007C4
    // 0x80800F4C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808007C4_chevilmumbo(rdram, ctx);
        goto after_2;
    // 0x80800F4C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80800F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F54:
    // 0x80800F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F58: jr          $ra
    // 0x80800F5C: nop

    return;
    // 0x80800F5C: nop

;}
RECOMP_FUNC void _chstatictorch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C58: syscall     435
    recomp_syscall_handler(rdram, ctx, 0x80086C58);
    return;
    // 0x80086C5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800B0D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0D60: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800B0D64: jr          $ra
    // 0x800B0D68: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    return;
    // 0x800B0D68: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
;}
RECOMP_FUNC void func_80800000_chfactoryentrydoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x8008A738
    // 0x80800014: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    _sujiggy_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x80800018: beq         $v0, $zero, L_80800028
    if (ctx->r2 == 0) {
        // 0x8080001C: nop
    
            goto L_80800028;
    }
    // 0x8080001C: nop

    // 0x80800020: jal         0x800DA544
    // 0x80800024: addiu       $a0, $zero, 0x397
    ctx->r4 = ADD32(0, 0X397);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a0, $zero, 0x397
    ctx->r4 = ADD32(0, 0X397);
    after_1:
L_80800028:
    // 0x80800028: jal         0x800D3E40
    // 0x8080002C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_2;
    // 0x8080002C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x80800030: beql        $v0, $zero, L_80800064
    if (ctx->r2 == 0) {
        // 0x80800034: addiu       $a3, $zero, 0x397
        ctx->r7 = ADD32(0, 0X397);
            goto L_80800064;
    }
    goto skip_0;
    // 0x80800034: addiu       $a3, $zero, 0x397
    ctx->r7 = ADD32(0, 0X397);
    skip_0:
    // 0x80800038: jal         0x80088840
    // 0x8080003C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x8080003C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_3:
    // 0x80800040: bne         $v0, $zero, L_80800060
    if (ctx->r2 != 0) {
        // 0x80800044: addiu       $a3, $zero, -0x1
        ctx->r7 = ADD32(0, -0X1);
            goto L_80800060;
    }
    // 0x80800044: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800050: jal         0x80101FDC
    // 0x80800054: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800054: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800058: b           L_80800064
    // 0x8080005C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
        goto L_80800064;
    // 0x8080005C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_80800060:
    // 0x80800060: addiu       $a3, $zero, 0x397
    ctx->r7 = ADD32(0, 0X397);
L_80800064:
    // 0x80800064: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800068: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800074: bne         $t7, $at, L_80800088
    if (ctx->r15 != ctx->r1) {
        // 0x80800078: lui         $at, 0xC296
        ctx->r1 = S32(0XC296 << 16);
            goto L_80800088;
    }
    // 0x80800078: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x8080007C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800080: b           L_80800098
    // 0x80800084: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_80800098;
    // 0x80800084: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80800088:
    // 0x80800088: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x8080008C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800090: nop

    // 0x80800094: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80800098:
    // 0x80800098: jal         0x80086880
    // 0x8080009C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chdoormake_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080009C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: jal         0x800868C0
    // 0x808000A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808000A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x800868A8
    // 0x808000B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x808000B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x808000B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void func_800E1410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1410: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800E1414: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E1418: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800E141C: addiu       $t7, $t7, -0x3070
    ctx->r15 = ADD32(ctx->r15, -0X3070);
    // 0x800E1420: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E1424: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800E1428: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E142C: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800E1430: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800E1434: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800E1438: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x800E143C: swc1        $f14, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f14.u32l;
    // 0x800E1440: swc1        $f14, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f14.u32l;
    // 0x800E1444: jr          $ra
    // 0x800E1448: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x800E1448: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void subaddiemulti_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080027C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800284: jal         0x8008A340
    // 0x80800288: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sueggmisc_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800288: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080028C: beq         $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x80800290: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002A4;
    }
    // 0x80800290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800294: jal         0x8008A3B0
    // 0x80800298: nop

    _suegg_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800298: nop

    after_1:
    // 0x8080029C: b           L_808002D0
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002D0;
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002A4:
    // 0x808002A4: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x808002A8: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x808002AC: bne         $t7, $zero, L_808002C4
    if (ctx->r15 != 0) {
        // 0x808002B0: nop
    
            goto L_808002C4;
    }
    // 0x808002B0: nop

    // 0x808002B4: lhu         $v0, 0x1A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1A);
    // 0x808002B8: srl         $t8, $v0, 5
    ctx->r24 = S32(U32(ctx->r2) >> 5);
    // 0x808002BC: b           L_808002CC
    // 0x808002C0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_808002CC;
    // 0x808002C0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_808002C4:
    // 0x808002C4: jal         0x800F54E4
    // 0x808002C8: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808002C8: nop

    after_2:
L_808002CC:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D0:
    // 0x808002D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void func_800EFDE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFDE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EFDEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EFDF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800EFDF4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800EFDF8: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x800EFDFC: jal         0x800EFA20
    // 0x800EFE00: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFA20(rdram, ctx);
        goto after_0;
    // 0x800EFE00: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800EFE04: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800EFE08: jal         0x800EEAA4
    // 0x800EFE0C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EEAA4(rdram, ctx);
        goto after_1;
    // 0x800EFE0C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800EFE10: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800EFE14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800EFE18: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800EFE1C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800EFE20: jal         0x800EFA20
    // 0x800EFE24: nop

    func_800EFA20(rdram, ctx);
        goto after_2;
    // 0x800EFE24: nop

    after_2:
    // 0x800EFE28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800EFE2C: jal         0x800EF3DC
    // 0x800EFE30: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EF3DC(rdram, ctx);
        goto after_3;
    // 0x800EFE30: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x800EFE34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EFE38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800EFE3C: jr          $ra
    // 0x800EFE40: nop

    return;
    // 0x800EFE40: nop

    // 0x800EFE44: nop

    // 0x800EFE48: nop

    // 0x800EFE4C: nop

;}
RECOMP_FUNC void func_80801E60_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801E64: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80801E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801E6C: bne         $a1, $at, L_80801E84
    if (ctx->r5 != ctx->r1) {
        // 0x80801E70: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801E84;
    }
    // 0x80801E70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801E74: jal         0x80801790
    // 0x80801E78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801790_chlakemonster(rdram, ctx);
        goto after_0;
    // 0x80801E78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80801E7C: b           L_80801E8C
    // 0x80801E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E8C;
    // 0x80801E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E84:
    // 0x80801E84: b           L_80801E8C
    // 0x80801E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801E8C;
    // 0x80801E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801E8C:
    // 0x80801E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801E90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801E94: jr          $ra
    // 0x80801E98: nop

    return;
    // 0x80801E98: nop

;}
RECOMP_FUNC void capod_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002AC: jal         0x8008FFE8
    // 0x808002B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x808002B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002B4: jal         0x80110024
    // 0x808002B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x808002B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808002BC: beq         $v0, $zero, L_808002D0
    if (ctx->r2 == 0) {
        // 0x808002C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808002D0;
    }
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808002C8: jal         0x80089578
    // 0x808002CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    _ncpod_entrypoint_23(rdram, ctx);
        goto after_2;
    // 0x808002CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_808002D0:
    // 0x808002D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
