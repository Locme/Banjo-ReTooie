#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800C0A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0A34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C0A38: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C0A3C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800C0A40: lbu         $s1, 0x762C($s1)
    ctx->r17 = MEM_BU(ctx->r17, 0X762C);
    // 0x800C0A44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C0A48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C0A4C: sltu        $t6, $zero, $s1
    ctx->r14 = 0 < ctx->r17 ? 1 : 0;
    // 0x800C0A50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C0A54: beq         $t6, $zero, L_800C0A90
    if (ctx->r14 == 0) {
        // 0x800C0A58: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_800C0A90;
    }
    // 0x800C0A58: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800C0A5C: jal         0x800C95D4
    // 0x800C0A60: nop

    func_800C95D4(rdram, ctx);
        goto after_0;
    // 0x800C0A60: nop

    after_0:
    // 0x800C0A64: sltu        $s1, $zero, $v0
    ctx->r17 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C0A68: beq         $s1, $zero, L_800C0A90
    if (ctx->r17 == 0) {
        // 0x800C0A6C: nop
    
            goto L_800C0A90;
    }
    // 0x800C0A6C: nop

    // 0x800C0A70: jal         0x800C9510
    // 0x800C0A74: nop

    func_800C9510(rdram, ctx);
        goto after_1;
    // 0x800C0A74: nop

    after_1:
    // 0x800C0A78: sltiu       $s1, $v0, 0x1
    ctx->r17 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800C0A7C: beq         $s1, $zero, L_800C0A90
    if (ctx->r17 == 0) {
        // 0x800C0A80: nop
    
            goto L_800C0A90;
    }
    // 0x800C0A80: nop

    // 0x800C0A84: jal         0x800C0638
    // 0x800C0A88: nop

    func_800C0638(rdram, ctx);
        goto after_2;
    // 0x800C0A88: nop

    after_2:
    // 0x800C0A8C: sltiu       $s1, $v0, 0x1
    ctx->r17 = ctx->r2 < 0X1 ? 1 : 0;
L_800C0A90:
    // 0x800C0A90: jal         0x800D3948
    // 0x800C0A94: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    func_800D3948(rdram, ctx);
        goto after_3;
    // 0x800C0A94: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    after_3:
    // 0x800C0A98: bne         $v0, $zero, L_800C0B08
    if (ctx->r2 != 0) {
        // 0x800C0A9C: nop
    
            goto L_800C0B08;
    }
    // 0x800C0A9C: nop

    // 0x800C0AA0: jal         0x800F54E4
    // 0x800C0AA4: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x800C0AA4: nop

    after_4:
    // 0x800C0AA8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800C0AAC: jal         0x800F6438
    // 0x800C0AB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_5;
    // 0x800C0AB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800C0AB4: sltu        $s1, $zero, $v0
    ctx->r17 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C0AB8: beql        $s1, $zero, L_800C0AD0
    if (ctx->r17 == 0) {
        // 0x800C0ABC: and         $s0, $s0, $s1
        ctx->r16 = ctx->r16 & ctx->r17;
            goto L_800C0AD0;
    }
    goto skip_0;
    // 0x800C0ABC: and         $s0, $s0, $s1
    ctx->r16 = ctx->r16 & ctx->r17;
    skip_0:
    // 0x800C0AC0: jal         0x800DB9B0
    // 0x800C0AC4: nop

    func_800DB9B0(rdram, ctx);
        goto after_6;
    // 0x800C0AC4: nop

    after_6:
    // 0x800C0AC8: sltiu       $s1, $v0, 0x1
    ctx->r17 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800C0ACC: and         $s0, $s0, $s1
    ctx->r16 = ctx->r16 & ctx->r17;
L_800C0AD0:
    // 0x800C0AD0: beql        $s0, $zero, L_800C0B9C
    if (ctx->r16 == 0) {
        // 0x800C0AD4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C0B9C;
    }
    goto skip_1;
    // 0x800C0AD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800C0AD8: jal         0x800F6774
    // 0x800C0ADC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800F6774(rdram, ctx);
        goto after_7;
    // 0x800C0ADC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x800C0AE0: beql        $v0, $zero, L_800C0B9C
    if (ctx->r2 == 0) {
        // 0x800C0AE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C0B9C;
    }
    goto skip_2;
    // 0x800C0AE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800C0AE8: jal         0x80015FA0
    // 0x800C0AEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015FA0(rdram, ctx);
        goto after_8;
    // 0x800C0AEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800C0AF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C0AF4: bne         $v0, $at, L_800C0B98
    if (ctx->r2 != ctx->r1) {
        // 0x800C0AF8: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800C0B98;
    }
    // 0x800C0AF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0AFC: sw          $zero, -0x750C($at)
    MEM_W(-0X750C, ctx->r1) = 0;
    // 0x800C0B00: b           L_800C0B9C
    // 0x800C0B04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C0B9C;
    // 0x800C0B04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C0B08:
    // 0x800C0B08: beql        $s1, $zero, L_800C0B9C
    if (ctx->r17 == 0) {
        // 0x800C0B0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C0B9C;
    }
    goto skip_3;
    // 0x800C0B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x800C0B10: jal         0x80088368
    // 0x800C0B14: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x800C0B14: nop

    after_9:
    // 0x800C0B18: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800C0B1C: jal         0x800DA298
    // 0x800C0B20: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x800C0B20: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_10:
    // 0x800C0B24: sltu        $s1, $zero, $v0
    ctx->r17 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C0B28: beq         $s1, $zero, L_800C0B3C
    if (ctx->r17 == 0) {
        // 0x800C0B2C: nop
    
            goto L_800C0B3C;
    }
    // 0x800C0B2C: nop

    // 0x800C0B30: jal         0x800DA298
    // 0x800C0B34: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x800C0B34: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    after_11:
    // 0x800C0B38: sltiu       $s1, $v0, 0x1
    ctx->r17 = ctx->r2 < 0X1 ? 1 : 0;
L_800C0B3C:
    // 0x800C0B3C: blez        $s2, L_800C0B98
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800C0B40: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800C0B98;
    }
    // 0x800C0B40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800C0B44:
    // 0x800C0B44: jal         0x80015FA0
    // 0x800C0B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80015FA0(rdram, ctx);
        goto after_12;
    // 0x800C0B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800C0B4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C0B50: bnel        $v0, $at, L_800C0B90
    if (ctx->r2 != ctx->r1) {
        // 0x800C0B54: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C0B90;
    }
    goto skip_4;
    // 0x800C0B54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x800C0B58: bne         $s1, $zero, L_800C0B7C
    if (ctx->r17 != 0) {
        // 0x800C0B5C: nop
    
            goto L_800C0B7C;
    }
    // 0x800C0B5C: nop

    // 0x800C0B60: jal         0x800F6438
    // 0x800C0B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_13;
    // 0x800C0B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800C0B68: beql        $v0, $zero, L_800C0B90
    if (ctx->r2 == 0) {
        // 0x800C0B6C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C0B90;
    }
    goto skip_5;
    // 0x800C0B6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_5:
    // 0x800C0B70: jal         0x800F6774
    // 0x800C0B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6774(rdram, ctx);
        goto after_14;
    // 0x800C0B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800C0B78: beq         $v0, $zero, L_800C0B8C
    if (ctx->r2 == 0) {
        // 0x800C0B7C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800C0B8C;
    }
L_800C0B7C:
    // 0x800C0B7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0B80: sw          $s0, -0x750C($at)
    MEM_W(-0X750C, ctx->r1) = ctx->r16;
    // 0x800C0B84: b           L_800C0B9C
    // 0x800C0B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C0B9C;
    // 0x800C0B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C0B8C:
    // 0x800C0B8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C0B90:
    // 0x800C0B90: bne         $s0, $s2, L_800C0B44
    if (ctx->r16 != ctx->r18) {
        // 0x800C0B94: nop
    
            goto L_800C0B44;
    }
    // 0x800C0B94: nop

L_800C0B98:
    // 0x800C0B98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0B9C:
    // 0x800C0B9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C0BA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C0BA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0BA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C0BAC: jr          $ra
    // 0x800C0BB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C0BB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chfactoryempspell_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087528: syscall     584
    recomp_syscall_handler(rdram, ctx, 0x80087528);
    return;
    // 0x8008752C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _ncfixposrot_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089210: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x80089210);
    return;
    // 0x80089214: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8080006C_chflysaucerdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800070: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080007C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800080: beq         $a1, $at, L_8080009C
    if (ctx->r5 == ctx->r1) {
        // 0x80800084: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8080009C;
    }
    // 0x80800084: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800088: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080008C: beq         $a1, $at, L_808000F8
    if (ctx->r5 == ctx->r1) {
        // 0x80800090: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000F8;
    }
    // 0x80800090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800094: b           L_80800130
    // 0x80800098: nop

        goto L_80800130;
    // 0x80800098: nop

L_8080009C:
    // 0x8080009C: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000A4: jal         0x800DA9E4
    // 0x808000A8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800DA9E4(rdram, ctx);
        goto after_0;
    // 0x808000A8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808000AC: bne         $v0, $zero, L_808000E0
    if (ctx->r2 != 0) {
        // 0x808000B0: addiu       $a0, $zero, 0xD6
        ctx->r4 = ADD32(0, 0XD6);
            goto L_808000E0;
    }
    // 0x808000B0: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x808000B4: jal         0x800887D8
    // 0x808000B8: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808000B8: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_1:
    // 0x808000BC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808000C8: addiu       $a3, $zero, 0x830
    ctx->r7 = ADD32(0, 0X830);
    // 0x808000CC: jal         0x80085708
    // 0x808000D0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x808000D0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x808000D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: jal         0x8008A4B0
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808000E0:
    // 0x808000E0: addiu       $a0, $zero, 0x30C
    ctx->r4 = ADD32(0, 0X30C);
    // 0x808000E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E8: jal         0x80101180
    // 0x808000EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_80101180(rdram, ctx);
        goto after_4;
    // 0x808000EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808000F0: b           L_80800134
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800134;
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F8:
    // 0x808000F8: jal         0x80088830
    // 0x808000FC: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x808000FC: nop

    after_5:
    // 0x80800100: jal         0x800DA298
    // 0x80800104: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800104: addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    after_6:
    // 0x80800108: beq         $v0, $zero, L_80800120
    if (ctx->r2 == 0) {
        // 0x8080010C: addiu       $a0, $zero, 0xCA
        ctx->r4 = ADD32(0, 0XCA);
            goto L_80800120;
    }
    // 0x8080010C: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    // 0x80800110: jal         0x800887D8
    // 0x80800114: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80800114: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_7:
    // 0x80800118: b           L_80800130
    // 0x8080011C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800130;
    // 0x8080011C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800120:
    // 0x80800120: jal         0x80085710
    // 0x80800124: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_8;
    // 0x80800124: nop

    after_8:
    // 0x80800128: b           L_80800130
    // 0x8080012C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800130;
    // 0x8080012C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800130:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800134:
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_800A3D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3D78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3D80: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x800A3D84: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x800A3D88: beql        $a1, $t6, L_800A3DA0
    if (ctx->r5 == ctx->r14) {
        // 0x800A3D8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3DA0;
    }
    goto skip_0;
    // 0x800A3D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A3D90: sb          $a1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r5;
    // 0x800A3D94: jal         0x800A3BA8
    // 0x800A3D98: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800A3BA8(rdram, ctx);
        goto after_0;
    // 0x800A3D98: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800A3D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3DA0:
    // 0x800A3DA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3DA4: jr          $ra
    // 0x800A3DA8: nop

    return;
    // 0x800A3DA8: nop

;}
RECOMP_FUNC void _gccubesearch_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882C0: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882C0);
    return;
    // 0x800882C4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800CD820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD820: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x800CD824: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800CD828: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800CD82C: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x800CD830: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800CD834: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800CD838: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800CD83C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800CD840: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800CD844: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800CD848: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800CD84C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800CD850: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800CD854: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800CD858: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800CD85C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800CD860: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800CD864: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800CD868: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800CD86C: jal         0x800CB854
    // 0x800CD870: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_0;
    // 0x800CD870: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800CD874: beql        $v0, $zero, L_800CD89C
    if (ctx->r2 == 0) {
        // 0x800CD878: sw          $zero, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = 0;
            goto L_800CD89C;
    }
    goto skip_0;
    // 0x800CD878: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    skip_0:
    // 0x800CD87C: jal         0x800CB854
    // 0x800CD880: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_1;
    // 0x800CD880: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800CD884: addiu       $t6, $v0, 0x1F
    ctx->r14 = ADD32(ctx->r2, 0X1F);
    // 0x800CD888: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CD88C: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800CD890: b           L_800CD89C
    // 0x800CD894: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
        goto L_800CD89C;
    // 0x800CD894: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x800CD898: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
L_800CD89C:
    // 0x800CD89C: addiu       $s0, $sp, 0x100
    ctx->r16 = ADD32(ctx->r29, 0X100);
    // 0x800CD8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CD8A4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800CD8A8: jal         0x800EFB24
    // 0x800CD8AC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x800CD8AC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x800CD8B0: jal         0x800EEF94
    // 0x800CD8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x800CD8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800CD8B8: addiu       $s3, $sp, 0xF4
    ctx->r19 = ADD32(ctx->r29, 0XF4);
    // 0x800CD8BC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800CD8C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800CD8C4: jal         0x800EF410
    // 0x800CD8C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF410(rdram, ctx);
        goto after_4;
    // 0x800CD8C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800CD8CC: add.s       $f20, $f26, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f26.fl + ctx->f26.fl;
    // 0x800CD8D0: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x800CD8D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CD8D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800CD8DC: div.s       $f22, $f24, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800CD8E0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x800CD8E4: trunc.w.s   $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    ctx->f4.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x800CD8E8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800CD8EC: nop

    // 0x800CD8F0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800CD8F4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800CD8F8: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CD8FC: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800CD900: nop

    // 0x800CD904: bc1f        L_800CD910
    if (!c1cs) {
        // 0x800CD908: nop
    
            goto L_800CD910;
    }
    // 0x800CD908: nop

    // 0x800CD90C: addiu       $s4, $v0, 0x1
    ctx->r20 = ADD32(ctx->r2, 0X1);
L_800CD910:
    // 0x800CD910: jal         0x800EFE50
    // 0x800CD914: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    func_800EFE50(rdram, ctx);
        goto after_5;
    // 0x800CD914: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800CD918: jal         0x800BE444
    // 0x800CD91C: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    func_800BE444(rdram, ctx);
        goto after_6;
    // 0x800CD91C: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    after_6:
    // 0x800CD920: addiu       $s0, $sp, 0xDC
    ctx->r16 = ADD32(ctx->r29, 0XDC);
    // 0x800CD924: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800CD928: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800CD92C: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    // 0x800CD930: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800CD934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CD938: jal         0x800EFA20
    // 0x800CD93C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EFA20(rdram, ctx);
        goto after_7;
    // 0x800CD93C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x800CD940: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800CD944: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CD948: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800CD94C: sub.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x800CD950: addiu       $s2, $sp, 0xE8
    ctx->r18 = ADD32(ctx->r29, 0XE8);
    // 0x800CD954: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CD958: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CD95C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CD960: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800CD964: jal         0x800EFA20
    // 0x800CD968: nop

    func_800EFA20(rdram, ctx);
        goto after_8;
    // 0x800CD968: nop

    after_8:
    // 0x800CD96C: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x800CD970: jal         0x800EE7F8
    // 0x800CD974: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x800CD974: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x800CD978: addiu       $s3, $sp, 0xC0
    ctx->r19 = ADD32(ctx->r29, 0XC0);
    // 0x800CD97C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800CD980: jal         0x800EE88C
    // 0x800CD984: addiu       $a1, $s6, 0x1E
    ctx->r5 = ADD32(ctx->r22, 0X1E);
    func_800EE88C(rdram, ctx);
        goto after_10;
    // 0x800CD984: addiu       $a1, $s6, 0x1E
    ctx->r5 = ADD32(ctx->r22, 0X1E);
    after_10:
    // 0x800CD988: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800CD98C: jal         0x800EF04C
    // 0x800CD990: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x800CD990: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x800CD994: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800CD998: jal         0x800EF04C
    // 0x800CD99C: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x800CD99C: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    after_12:
    // 0x800CD9A0: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x800CD9A4: jal         0x800EE7F8
    // 0x800CD9A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x800CD9A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x800CD9AC: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x800CD9B0: ori         $fp, $zero, 0xFFFF
    ctx->r30 = 0 | 0XFFFF;
    // 0x800CD9B4: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
    // 0x800CD9B8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800CD9BC: beql        $a0, $zero, L_800CDB68
    if (ctx->r4 == 0) {
        // 0x800CD9C0: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_800CDB68;
    }
    goto skip_1;
    // 0x800CD9C0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_1:
L_800CD9C4:
    // 0x800CD9C4: jal         0x800E9E88
    // 0x800CD9C8: nop

    func_800E9E88(rdram, ctx);
        goto after_14;
    // 0x800CD9C8: nop

    after_14:
    // 0x800CD9CC: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x800CD9D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CD9D4: jal         0x800E9EB4
    // 0x800CD9D8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_15;
    // 0x800CD9D8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_15:
    // 0x800CD9DC: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800CD9E0: beq         $at, $zero, L_800CDB4C
    if (ctx->r1 == 0) {
        // 0x800CD9E4: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_800CDB4C;
    }
    // 0x800CD9E4: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800CD9E8: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_800CD9EC:
    // 0x800CD9EC: sll         $t3, $v0, 27
    ctx->r11 = S32(ctx->r2 << 27);
    // 0x800CD9F0: bgez        $t3, L_800CDB3C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800CD9F4: andi        $t4, $v0, 0x1
        ctx->r12 = ctx->r2 & 0X1;
            goto L_800CDB3C;
    }
    // 0x800CD9F4: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x800CD9F8: beql        $t4, $zero, L_800CDB40
    if (ctx->r12 == 0) {
        // 0x800CD9FC: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_2;
    // 0x800CD9FC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x800CDA00: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800CDA04: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x800CDA08: sll         $t6, $t5, 22
    ctx->r14 = S32(ctx->r13 << 22);
    // 0x800CDA0C: bgezl       $t6, L_800CDB40
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800CDA10: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_3;
    // 0x800CDA10: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_3:
    // 0x800CDA14: beql        $s6, $s0, L_800CDB40
    if (ctx->r22 == ctx->r16) {
        // 0x800CDA18: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_4;
    // 0x800CDA18: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_4:
    // 0x800CDA1C: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x800CDA20: beql        $v0, $zero, L_800CDB40
    if (ctx->r2 == 0) {
        // 0x800CDA24: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_5;
    // 0x800CDA24: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_5:
    // 0x800CDA28: beql        $fp, $v0, L_800CDB40
    if (ctx->r30 == ctx->r2) {
        // 0x800CDA2C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_6;
    // 0x800CDA2C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_6:
    // 0x800CDA30: lhu         $t8, 0x18($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X18);
    // 0x800CDA34: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800CDA38: beql        $t9, $zero, L_800CDB40
    if (ctx->r25 == 0) {
        // 0x800CDA3C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_7;
    // 0x800CDA3C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_7:
    // 0x800CDA40: jal         0x80106790
    // 0x800CDA44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_16;
    // 0x800CDA44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800CDA48: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x800CDA4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CDA50: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x800CDA54: sll         $t2, $t0, 14
    ctx->r10 = S32(ctx->r8 << 14);
    // 0x800CDA58: bltzl       $t2, L_800CDB40
    if (SIGNED(ctx->r10) < 0) {
        // 0x800CDA5C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_8;
    // 0x800CDA5C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_8:
    // 0x800CDA60: lhu         $t3, 0x66($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X66);
    // 0x800CDA64: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x800CDA68: bnel        $t5, $zero, L_800CDB40
    if (ctx->r13 != 0) {
        // 0x800CDA6C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_9;
    // 0x800CDA6C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_9:
    // 0x800CDA70: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x800CDA74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CDA78: lwc1        $f10, 0x59A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X59A0);
    // 0x800CDA7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CDA80: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800CDA84: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800CDA88: nop

    // 0x800CDA8C: mul.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800CDA90: jal         0x8008A018
    // 0x800CDA94: nop

    _subaddiecustomhits_entrypoint_5(rdram, ctx);
        goto after_17;
    // 0x800CDA94: nop

    after_17:
    // 0x800CDA98: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800CDA9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CDAA0: jal         0x800EEB40
    // 0x800CDAA4: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    func_800EEB40(rdram, ctx);
        goto after_18;
    // 0x800CDAA4: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    after_18:
    // 0x800CDAA8: add.s       $f2, $f22, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x800CDAAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CDAB0: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800CDAB4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800CDAB8: nop

    // 0x800CDABC: bc1tl       L_800CDB40
    if (c1cs) {
        // 0x800CDAC0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_10;
    // 0x800CDAC0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_10:
    // 0x800CDAC4: jal         0x800EEB40
    // 0x800CDAC8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_19;
    // 0x800CDAC8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_19:
    // 0x800CDACC: beq         $s5, $zero, L_800CDAE4
    if (ctx->r21 == 0) {
        // 0x800CDAD0: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800CDAE4;
    }
    // 0x800CDAD0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800CDAD4: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800CDAD8: nop

    // 0x800CDADC: bc1tl       L_800CDB40
    if (c1cs) {
        // 0x800CDAE0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_11;
    // 0x800CDAE0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_11:
L_800CDAE4:
    // 0x800CDAE4: jal         0x800EC3C4
    // 0x800CDAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EC3C4(rdram, ctx);
        goto after_20;
    // 0x800CDAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x800CDAEC: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x800CDAF0: beql        $t7, $zero, L_800CDB18
    if (ctx->r15 == 0) {
        // 0x800CDAF4: mfc1        $a2, $f26
        ctx->r6 = (int32_t)ctx->f26.u32l;
            goto L_800CDB18;
    }
    goto skip_12;
    // 0x800CDAF4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    skip_12:
    // 0x800CDAF8: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x800CDAFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CDB00: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800CDB04: jalr        $t9
    // 0x800CDB08: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_21;
    // 0x800CDB08: nop

    after_21:
    // 0x800CDB0C: beql        $v0, $zero, L_800CDB40
    if (ctx->r2 == 0) {
        // 0x800CDB10: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_13;
    // 0x800CDB10: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_13:
    // 0x800CDB14: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
L_800CDB18:
    // 0x800CDB18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CDB1C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800CDB20: addiu       $a3, $sp, 0xCC
    ctx->r7 = ADD32(ctx->r29, 0XCC);
    // 0x800CDB24: jal         0x800CD6B4
    // 0x800CDB28: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800CD6B4(rdram, ctx);
        goto after_22;
    // 0x800CDB28: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_22:
    // 0x800CDB2C: beql        $v0, $zero, L_800CDB40
    if (ctx->r2 == 0) {
        // 0x800CDB30: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDB40;
    }
    goto skip_14;
    // 0x800CDB30: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_14:
    // 0x800CDB34: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x800CDB38: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
L_800CDB3C:
    // 0x800CDB3C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_800CDB40:
    // 0x800CDB40: sltu        $at, $s1, $s7
    ctx->r1 = ctx->r17 < ctx->r23 ? 1 : 0;
    // 0x800CDB44: bnel        $at, $zero, L_800CD9EC
    if (ctx->r1 != 0) {
        // 0x800CDB48: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_800CD9EC;
    }
    goto skip_15;
    // 0x800CDB48: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_15:
L_800CDB4C:
    // 0x800CDB4C: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x800CDB50: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800CDB54: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800CDB58: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    // 0x800CDB5C: bne         $a0, $zero, L_800CD9C4
    if (ctx->r4 != 0) {
        // 0x800CDB60: nop
    
            goto L_800CD9C4;
    }
    // 0x800CDB60: nop

    // 0x800CDB64: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_800CDB68:
    // 0x800CDB68: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x800CDB6C: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800CDB70: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800CDB74: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800CDB78: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800CDB7C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800CDB80: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800CDB84: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800CDB88: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800CDB8C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800CDB90: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800CDB94: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800CDB98: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800CDB9C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800CDBA0: jr          $ra
    // 0x800CDBA4: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x800CDBA4: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_80800768_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080076C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800774: jal         0x800EB854
    // 0x80800778: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EB854(rdram, ctx);
        goto after_0;
    // 0x80800778: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080077C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800780: bne         $v0, $at, L_808007A8
    if (ctx->r2 != ctx->r1) {
        // 0x80800784: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007A8;
    }
    // 0x80800784: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800788: jal         0x80100094
    // 0x8080078C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080078C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800790: beq         $v0, $zero, L_808007B0
    if (ctx->r2 == 0) {
        // 0x80800794: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808007B0;
    }
    // 0x80800794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800798: jal         0x80087CA0
    // 0x8080079C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080079C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808007A0: b           L_808007B4
    // 0x808007A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007B4;
    // 0x808007A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007A8:
    // 0x808007A8: jal         0x80101870
    // 0x808007AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_3;
    // 0x808007AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_808007B0:
    // 0x808007B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007B4:
    // 0x808007B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007B8: jr          $ra
    // 0x808007BC: nop

    return;
    // 0x808007BC: nop

;}
RECOMP_FUNC void func_808064CC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808064CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808064D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808064D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808064D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808064DC: jal         0x80100094
    // 0x808064E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808064E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808064E4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x808064E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808064EC: lbu         $a0, 0x24($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X24);
    // 0x808064F0: lw          $t6, 0x70($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X70);
    // 0x808064F4: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0XA0EC) << 16);
    // 0x808064F8: addiu       $a3, $a3, -0x5F14
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0XA0EC));
    // 0x808064FC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80806500: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80806504: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80806508: jal         0x80089D68
    // 0x8080650C: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x8080650C: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    after_1:
    // 0x80806510: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80806514: sb          $v0, 0x24($t8)
    MEM_B(0X24, ctx->r24) = ctx->r2;
    // 0x80806518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080651C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80806520: jr          $ra
    // 0x80806524: nop

    return;
    // 0x80806524: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_42(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C30: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087C30);
    return;
    // 0x80087C34: addi        $t0, $zero, 0xA8
    ctx->r8 = ADD32(0, 0XA8);
;}
RECOMP_FUNC void glcutDll_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080065C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800664: jal         0x800DA544
    // 0x80800668: addiu       $a0, $zero, 0xA52
    ctx->r4 = ADD32(0, 0XA52);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800668: addiu       $a0, $zero, 0xA52
    ctx->r4 = ADD32(0, 0XA52);
    after_0:
    // 0x8080066C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800674: jr          $ra
    // 0x80800678: nop

    return;
    // 0x80800678: nop

;}
RECOMP_FUNC void func_8080078C_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800790: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800794: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800798: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080079C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007A0: beq         $a1, $at, L_80800A64
    if (ctx->r5 == ctx->r1) {
        // 0x808007A4: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800A64;
    }
    // 0x808007A4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808007A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007AC: beq         $a1, $at, L_80800A78
    if (ctx->r5 == ctx->r1) {
        // 0x808007B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A78;
    }
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B4: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808007B8: beq         $a1, $at, L_808007D0
    if (ctx->r5 == ctx->r1) {
        // 0x808007BC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808007D0;
    }
    // 0x808007BC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808007C0: beq         $a1, $at, L_80800A88
    if (ctx->r5 == ctx->r1) {
        // 0x808007C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A88;
    }
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C8: b           L_80800AB0
    // 0x808007CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AB0;
    // 0x808007CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007D0:
    // 0x808007D0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808007D4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x808007D8: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x808007DC: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x808007E0: beq         $t7, $zero, L_80800810
    if (ctx->r15 == 0) {
        // 0x808007E4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800810;
    }
    // 0x808007E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x808007E8: sltiu       $at, $t7, 0xD
    ctx->r1 = ctx->r15 < 0XD ? 1 : 0;
    // 0x808007EC: beq         $at, $zero, L_80800810
    if (ctx->r1 == 0) {
        // 0x808007F0: addiu       $a3, $zero, 0xC
        ctx->r7 = ADD32(0, 0XC);
            goto L_80800810;
    }
    // 0x808007F0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x808007F4: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808007F8: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2232, 0XFB4) << 16);
    // 0x808007FC: addiu       $v1, $v1, 0xFB4
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2232, 0XFB4));
    // 0x80800800: mflo        $t8
    ctx->r24 = lo;
    // 0x80800804: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80800808: b           L_80800820
    // 0x8080080C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
        goto L_80800820;
    // 0x8080080C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
L_80800810:
    // 0x80800810: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2232, 0XFB4) << 16);
    // 0x80800814: addiu       $v1, $v1, 0xFB4
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2232, 0XFB4));
    // 0x80800818: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080081C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
L_80800820:
    // 0x80800820: addiu       $at, $zero, 0x21F
    ctx->r1 = ADD32(0, 0X21F);
    // 0x80800824: bne         $a0, $at, L_8080086C
    if (ctx->r4 != ctx->r1) {
        // 0x80800828: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8080086C;
    }
    // 0x80800828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080082C: jal         0x800D0B68
    // 0x80800830: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800D0B68(rdram, ctx);
        goto after_0;
    // 0x80800830: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_0:
    // 0x80800834: bne         $v0, $zero, L_80800864
    if (ctx->r2 != 0) {
        // 0x80800838: addiu       $a0, $zero, 0x26
        ctx->r4 = ADD32(0, 0X26);
            goto L_80800864;
    }
    // 0x80800838: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x8080083C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800844: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800848: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8080084C: jal         0x800D10D4
    // 0x80800850: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800D10D4(rdram, ctx);
        goto after_1;
    // 0x80800850: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x80800854: jal         0x80106790
    // 0x80800858: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800858: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080085C: b           L_8080098C
    // 0x80800860: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080098C;
    // 0x80800860: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800864:
    // 0x80800864: b           L_80800AB0
    // 0x80800868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AB0;
    // 0x80800868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080086C:
    // 0x8080086C: beq         $v0, $zero, L_80800890
    if (ctx->r2 == 0) {
        // 0x80800870: sltiu       $at, $v0, 0xD
        ctx->r1 = ctx->r2 < 0XD ? 1 : 0;
            goto L_80800890;
    }
    // 0x80800870: sltiu       $at, $v0, 0xD
    ctx->r1 = ctx->r2 < 0XD ? 1 : 0;
    // 0x80800874: beql        $at, $zero, L_80800894
    if (ctx->r1 == 0) {
        // 0x80800878: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800894;
    }
    goto skip_0;
    // 0x80800878: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x8080087C: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800880: mflo        $t1
    ctx->r9 = lo;
    // 0x80800884: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80800888: b           L_80800894
    // 0x8080088C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
        goto L_80800894;
    // 0x8080088C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
L_80800890:
    // 0x80800890: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800894:
    // 0x80800894: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    // 0x80800898: bne         $a0, $at, L_808008E0
    if (ctx->r4 != ctx->r1) {
        // 0x8080089C: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_808008E0;
    }
    // 0x8080089C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808008A0: jal         0x800D0B68
    // 0x808008A4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D0B68(rdram, ctx);
        goto after_3;
    // 0x808008A4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_3:
    // 0x808008A8: bne         $v0, $zero, L_808008D8
    if (ctx->r2 != 0) {
        // 0x808008AC: addiu       $a0, $zero, 0xB
        ctx->r4 = ADD32(0, 0XB);
            goto L_808008D8;
    }
    // 0x808008AC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x808008B0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x808008B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808008B8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808008BC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808008C0: jal         0x800D10D4
    // 0x808008C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800D10D4(rdram, ctx);
        goto after_4;
    // 0x808008C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x808008C8: jal         0x80106790
    // 0x808008CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x808008CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808008D0: b           L_8080098C
    // 0x808008D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080098C;
    // 0x808008D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808008D8:
    // 0x808008D8: b           L_80800AB0
    // 0x808008DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AB0;
    // 0x808008DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008E0:
    // 0x808008E0: beq         $v0, $zero, L_80800904
    if (ctx->r2 == 0) {
        // 0x808008E4: sltiu       $at, $v0, 0xD
        ctx->r1 = ctx->r2 < 0XD ? 1 : 0;
            goto L_80800904;
    }
    // 0x808008E4: sltiu       $at, $v0, 0xD
    ctx->r1 = ctx->r2 < 0XD ? 1 : 0;
    // 0x808008E8: beql        $at, $zero, L_80800908
    if (ctx->r1 == 0) {
        // 0x808008EC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800908;
    }
    goto skip_1;
    // 0x808008EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x808008F0: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808008F4: mflo        $t4
    ctx->r12 = lo;
    // 0x808008F8: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x808008FC: b           L_80800908
    // 0x80800900: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
        goto L_80800908;
    // 0x80800900: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
L_80800904:
    // 0x80800904: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800908:
    // 0x80800908: addiu       $at, $zero, 0x220
    ctx->r1 = ADD32(0, 0X220);
    // 0x8080090C: bne         $a0, $at, L_80800958
    if (ctx->r4 != ctx->r1) {
        // 0x80800910: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80800958;
    }
    // 0x80800910: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800914: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800918: jal         0x800D0B68
    // 0x8080091C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800D0B68(rdram, ctx);
        goto after_6;
    // 0x8080091C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800920: bne         $v0, $zero, L_80800950
    if (ctx->r2 != 0) {
        // 0x80800924: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80800950;
    }
    // 0x80800924: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800928: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8080092C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800930: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800934: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800938: jal         0x800D10D4
    // 0x8080093C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800D10D4(rdram, ctx);
        goto after_7;
    // 0x8080093C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_7:
    // 0x80800940: jal         0x80106790
    // 0x80800944: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_8;
    // 0x80800944: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800948: b           L_8080098C
    // 0x8080094C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080098C;
    // 0x8080094C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800950:
    // 0x80800950: b           L_80800AB0
    // 0x80800954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800AB0;
    // 0x80800954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800958:
    // 0x80800958: beq         $v0, $zero, L_8080097C
    if (ctx->r2 == 0) {
        // 0x8080095C: sltiu       $at, $v0, 0xD
        ctx->r1 = ctx->r2 < 0XD ? 1 : 0;
            goto L_8080097C;
    }
    // 0x8080095C: sltiu       $at, $v0, 0xD
    ctx->r1 = ctx->r2 < 0XD ? 1 : 0;
    // 0x80800960: beql        $at, $zero, L_80800980
    if (ctx->r1 == 0) {
        // 0x80800964: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800980;
    }
    goto skip_2;
    // 0x80800964: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_2:
    // 0x80800968: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080096C: mflo        $t7
    ctx->r15 = lo;
    // 0x80800970: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80800974: b           L_80800980
    // 0x80800978: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
        goto L_80800980;
    // 0x80800978: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
L_8080097C:
    // 0x8080097C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800980:
    // 0x80800980: jal         0x80108474
    // 0x80800984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_9;
    // 0x80800984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800988: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080098C:
    // 0x8080098C: lbu         $t9, 0x77($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X77);
    // 0x80800990: lbu         $t1, 0x75($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X75);
    // 0x80800994: lbu         $t3, 0x71($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X71);
    // 0x80800998: lbu         $t5, 0x64($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X64);
    // 0x8080099C: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x808009A0: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x808009A4: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x808009A8: andi        $t6, $t5, 0xFF7F
    ctx->r14 = ctx->r13 & 0XFF7F;
    // 0x808009AC: sb          $t0, 0x77($v1)
    MEM_B(0X77, ctx->r3) = ctx->r8;
    // 0x808009B0: sb          $t2, 0x75($v1)
    MEM_B(0X75, ctx->r3) = ctx->r10;
    // 0x808009B4: sb          $t4, 0x71($v1)
    MEM_B(0X71, ctx->r3) = ctx->r12;
    // 0x808009B8: sb          $t6, 0x64($v1)
    MEM_B(0X64, ctx->r3) = ctx->r14;
    // 0x808009BC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x808009C0: jal         0x80106790
    // 0x808009C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80106790(rdram, ctx);
        goto after_10;
    // 0x808009C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x808009C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009D0: jal         0x80100094
    // 0x808009D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x808009D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x808009D8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808009DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009E0: jal         0x8008A028
    // 0x808009E4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x808009E4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_12:
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808009F0: jal         0x80800AC4
    // 0x808009F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800AC4_chtransparentfish(rdram, ctx);
        goto after_13;
    // 0x808009F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x808009F8: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x808009FC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A00: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800A04: beq         $t7, $zero, L_80800A50
    if (ctx->r15 == 0) {
        // 0x80800A08: sltiu       $at, $t7, 0xD
        ctx->r1 = ctx->r15 < 0XD ? 1 : 0;
            goto L_80800A50;
    }
    // 0x80800A08: sltiu       $at, $t7, 0xD
    ctx->r1 = ctx->r15 < 0XD ? 1 : 0;
    // 0x80800A0C: beq         $at, $zero, L_80800A50
    if (ctx->r1 == 0) {
        // 0x80800A10: sll         $t8, $t7, 2
        ctx->r24 = S32(ctx->r15 << 2);
            goto L_80800A50;
    }
    // 0x80800A10: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800A14: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800A18: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A1C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2232, 0XFBC) << 16);
    // 0x80800A20: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80800A24: lw          $t9, 0xFBC($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(2232, 0XFBC));
    // 0x80800A28: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800A2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800A30: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800A34: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800A3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800A40: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800A44: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800A48: b           L_80800AB0
    // 0x80800A4C: swc1        $f18, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f18.u32l;
        goto L_80800AB0;
    // 0x80800A4C: swc1        $f18, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f18.u32l;
L_80800A50:
    // 0x80800A50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A54: nop

    // 0x80800A58: swc1        $f4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f4.u32l;
    // 0x80800A5C: b           L_80800AB0
    // 0x80800A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AB0;
    // 0x80800A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A64:
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A68: jal         0x80102424
    // 0x80800A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800A70: b           L_80800AB0
    // 0x80800A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AB0;
    // 0x80800A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A78:
    // 0x80800A78: jal         0x80107070
    // 0x80800A7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_15;
    // 0x80800A7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800A80: b           L_80800AB0
    // 0x80800A84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AB0;
    // 0x80800A84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A88:
    // 0x80800A88: jal         0x80100094
    // 0x80800A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x80800A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800A90: jal         0x8008A038
    // 0x80800A94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80800A94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x80800A98: bne         $v0, $zero, L_80800AA8
    if (ctx->r2 != 0) {
        // 0x80800A9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AA8;
    }
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA0: jal         0x80108B04
    // 0x80800AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_18;
    // 0x80800AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
L_80800AA8:
    // 0x80800AA8: b           L_80800AB0
    // 0x80800AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AB0;
    // 0x80800AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AB0:
    // 0x80800AB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800AB4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800AB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800ABC: jr          $ra
    // 0x80800AC0: nop

    return;
    // 0x80800AC0: nop

;}
RECOMP_FUNC void basudie_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004BC: jal         0x8009E6EC
    // 0x808004C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808004C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004C4: jal         0x80099AA8
    // 0x808004C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099AA8(rdram, ctx);
        goto after_1;
    // 0x808004C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808004CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004D4: jr          $ra
    // 0x808004D8: nop

    return;
    // 0x808004D8: nop

;}
RECOMP_FUNC void func_800BC690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC690: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800BC694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BC698: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BC69C: jal         0x800EA05C
    // 0x800BC6A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800BC6A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800BC6A4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800BC6A8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800BC6AC: addiu       $v1, $v1, -0x5840
    ctx->r3 = ADD32(ctx->r3, -0X5840);
    // 0x800BC6B0: addiu       $s0, $s0, -0x58A0
    ctx->r16 = ADD32(ctx->r16, -0X58A0);
    // 0x800BC6B4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
L_800BC6B8:
    // 0x800BC6B8: beq         $v0, $t6, L_800BC6CC
    if (ctx->r2 == ctx->r14) {
        // 0x800BC6BC: nop
    
            goto L_800BC6CC;
    }
    // 0x800BC6BC: nop

    // 0x800BC6C0: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x800BC6C4: bnel        $s0, $v1, L_800BC6B8
    if (ctx->r16 != ctx->r3) {
        // 0x800BC6C8: lh          $t6, 0x0($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X0);
            goto L_800BC6B8;
    }
    goto skip_0;
    // 0x800BC6C8: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    skip_0:
L_800BC6CC:
    // 0x800BC6CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800BC6D0: addiu       $t7, $t7, -0x5840
    ctx->r15 = ADD32(ctx->r15, -0X5840);
    // 0x800BC6D4: beql        $s0, $t7, L_800BC890
    if (ctx->r16 == ctx->r15) {
        // 0x800BC6D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800BC890;
    }
    goto skip_1;
    // 0x800BC6D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800BC6DC: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800BC6E0: beq         $t8, $zero, L_800BC6FC
    if (ctx->r24 == 0) {
        // 0x800BC6E4: nop
    
            goto L_800BC6FC;
    }
    // 0x800BC6E4: nop

    // 0x800BC6E8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800BC6EC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BC6F0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800BC6F4: jal         0x800B5680
    // 0x800BC6F8: nop

    func_800B5680(rdram, ctx);
        goto after_1;
    // 0x800BC6F8: nop

    after_1:
L_800BC6FC:
    // 0x800BC6FC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BC700: addiu       $s1, $s1, -0x7D20
    ctx->r17 = ADD32(ctx->r17, -0X7D20);
    // 0x800BC704: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x800BC708: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x800BC70C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800BC710: sb          $t1, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r9;
    // 0x800BC714: sb          $t1, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r9;
    // 0x800BC718: sb          $zero, 0xE($s1)
    MEM_B(0XE, ctx->r17) = 0;
    // 0x800BC71C: sb          $zero, 0xF($s1)
    MEM_B(0XF, ctx->r17) = 0;
    // 0x800BC720: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    // 0x800BC724: sh          $t3, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r11;
    // 0x800BC728: jal         0x8001ACCC
    // 0x800BC72C: sb          $t4, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r12;
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x800BC72C: sb          $t4, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r12;
    after_2:
    // 0x800BC730: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800BC734: jal         0x8001ACCC
    // 0x800BC738: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    heap_alloc(rdram, ctx);
        goto after_3;
    // 0x800BC738: addiu       $a0, $zero, 0x5DC0
    ctx->r4 = ADD32(0, 0X5DC0);
    after_3:
    // 0x800BC73C: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800BC740: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800BC744: jal         0x800EF410
    // 0x800BC748: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    func_800EF410(rdram, ctx);
        goto after_4;
    // 0x800BC748: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    after_4:
    // 0x800BC74C: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BC750: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800BC754: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800BC758: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800BC75C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BC760: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BC764: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
    // 0x800BC768: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800BC76C: add.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x800BC770: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800BC774: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800BC778: neg.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = -ctx->f12.fl;
    // 0x800BC77C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800BC780: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800BC784: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800BC788: add.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f18.fl;
    // 0x800BC78C: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x800BC790: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x800BC794: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800BC798: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800BC79C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800BC7A0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800BC7A4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BC7A8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800BC7AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BC7B0: add.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f8.fl;
    // 0x800BC7B4: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800BC7B8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800BC7BC: swc1        $f6, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f6.u32l;
    // 0x800BC7C0: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800BC7C4: nop

    // 0x800BC7C8: mul.s       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800BC7CC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800BC7D0: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
    // 0x800BC7D4: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800BC7D8: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800BC7DC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BC7E0: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
    // 0x800BC7E4: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BC7E8: add.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800BC7EC: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800BC7F0: swc1        $f10, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f10.u32l;
    // 0x800BC7F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BC7F8: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x800BC7FC: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BC800: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BC804: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x800BC808: swc1        $f4, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f4.u32l;
    // 0x800BC80C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800BC810: lwc1        $f10, 0x40($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X40);
    // 0x800BC814: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800BC818: swc1        $f8, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f8.u32l;
    // 0x800BC81C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800BC820: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800BC824: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x800BC828: jal         0x800EEAA4
    // 0x800BC82C: swc1        $f6, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f6.u32l;
    func_800EEAA4(rdram, ctx);
        goto after_5;
    // 0x800BC82C: swc1        $f6, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f6.u32l;
    after_5:
    // 0x800BC830: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800BC834: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x800BC838: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BC83C: addiu       $a0, $a0, -0x7CDC
    ctx->r4 = ADD32(ctx->r4, -0X7CDC);
    // 0x800BC840: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800BC844: jal         0x800EFA20
    // 0x800BC848: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EFA20(rdram, ctx);
        goto after_6;
    // 0x800BC848: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800BC84C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BC850: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BC854: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BC858: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BC85C: addiu       $a1, $a1, -0x7CC8
    ctx->r5 = ADD32(ctx->r5, -0X7CC8);
    // 0x800BC860: addiu       $a0, $a0, -0x7D0C
    ctx->r4 = ADD32(ctx->r4, -0X7D0C);
    // 0x800BC864: jal         0x8002ED00
    // 0x800BC868: swc1        $f10, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f10.u32l;
    guMtxF2L(rdram, ctx);
        goto after_7;
    // 0x800BC868: swc1        $f10, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f10.u32l;
    after_7:
    // 0x800BC86C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BC870: addiu       $a0, $a0, -0x7C7C
    ctx->r4 = ADD32(ctx->r4, -0X7C7C);
    // 0x800BC874: jal         0x800EE7F8
    // 0x800BC878: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x800BC878: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800BC87C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BC880: addiu       $a0, $a0, -0x7C88
    ctx->r4 = ADD32(ctx->r4, -0X7C88);
    // 0x800BC884: jal         0x800EE7F8
    // 0x800BC888: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x800BC888: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x800BC88C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800BC890:
    // 0x800BC890: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800BC894: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800BC898: jr          $ra
    // 0x800BC89C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800BC89C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void chglowbo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E1C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1628, 0X1588) << 16);
    // 0x80800E20: jr          $ra
    // 0x80800E24: addiu       $v0, $v0, 0x1588
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1628, 0X1588));
    return;
    // 0x80800E24: addiu       $v0, $v0, 0x1588
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1628, 0X1588));
;}
RECOMP_FUNC void func_80800144_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080014C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800150: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x80800154: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(752, 0X1118) << 16);
    // 0x80800158: addiu       $t8, $t8, 0x1118
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(752, 0X1118));
    // 0x8080015C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800160: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800164: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80800168: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8080016C: lh          $a2, 0x4($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X4);
    // 0x80800170: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800174: beq         $a2, $zero, L_80800188
    if (ctx->r6 == 0) {
        // 0x80800178: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80800188;
    }
    // 0x80800178: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080017C: jal         0x800888C8
    // 0x80800180: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800180: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80800184: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80800188:
    // 0x80800188: lh          $a0, 0x6($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X6);
    // 0x8080018C: beql        $a0, $zero, L_808001A4
    if (ctx->r4 == 0) {
        // 0x80800190: lbu         $t9, 0xA($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0XA);
            goto L_808001A4;
    }
    goto skip_0;
    // 0x80800190: lbu         $t9, 0xA($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XA);
    skip_0:
    // 0x80800194: jal         0x800FC660
    // 0x80800198: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800FC660(rdram, ctx);
        goto after_1;
    // 0x80800198: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8080019C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A0: lbu         $t9, 0xA($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XA);
L_808001A4:
    // 0x808001A4: beql        $t9, $zero, L_808001E4
    if (ctx->r25 == 0) {
        // 0x808001A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001E4;
    }
    goto skip_1;
    // 0x808001A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808001AC: jal         0x80088500
    // 0x808001B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    _gleeprom_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808001B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x808001B4: sra         $t0, $v0, 24
    ctx->r8 = S32(SIGNED(ctx->r2) >> 24);
    // 0x808001B8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x808001BC: bne         $t0, $at, L_808001E0
    if (ctx->r8 != ctx->r1) {
        // 0x808001C0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808001E0;
    }
    // 0x808001C0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808001C8: lbu         $a1, 0xA($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0XA);
    // 0x808001CC: lbu         $a2, 0xB($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0XB);
    // 0x808001D0: lhu         $a0, 0x1A($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X1A);
    // 0x808001D4: srl         $t2, $a0, 5
    ctx->r10 = S32(U32(ctx->r4) >> 5);
    // 0x808001D8: jal         0x800F7664
    // 0x808001DC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800F7664(rdram, ctx);
        goto after_3;
    // 0x808001DC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_3:
L_808001E0:
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001E4:
    // 0x808001E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001E8: jr          $ra
    // 0x808001EC: nop

    return;
    // 0x808001EC: nop

;}
RECOMP_FUNC void func_800A4E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4E7C: jal         0x800A3F14
    // 0x800A4E80: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800A3F14(rdram, ctx);
        goto after_0;
    // 0x800A4E80: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x800A4E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4E88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4E8C: jr          $ra
    // 0x800A4E90: nop

    return;
    // 0x800A4E90: nop

;}
RECOMP_FUNC void bakey_func_80091940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091948: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8009194C: jal         0x800BCD78
    // 0x80091950: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BCD78(rdram, ctx);
        goto after_0;
    // 0x80091950: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80091954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009195C: jr          $ra
    // 0x80091960: nop

    return;
    // 0x80091960: nop

;}
RECOMP_FUNC void func_808004D8_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004E0: jal         0x800974FC
    // 0x808004E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800974FC(rdram, ctx);
        goto after_0;
    // 0x808004E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004EC: jal         0x8009C914
    // 0x808004F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    yaw_setIdeal(rdram, ctx);
        goto after_1;
    // 0x808004F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808004F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004FC: jr          $ra
    // 0x80800500: nop

    return;
    // 0x80800500: nop

;}
RECOMP_FUNC void func_80802CC0_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802CC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802CC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802CCC: jal         0x80103EF4
    // 0x80802CD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80103EF4(rdram, ctx);
        goto after_0;
    // 0x80802CD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802CD4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80802CD8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80802CDC: addiu       $t6, $zero, 0x802
    ctx->r14 = ADD32(0, 0X802);
    // 0x80802CE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802CE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80802CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802CEC: jal         0x80086898
    // 0x80802CF0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80802CF0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_1:
    // 0x80802CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802CF8: jal         0x800868C0
    // 0x80802CFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80802CFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80802D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D04: jal         0x800868A8
    // 0x80802D08: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80802D08: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_3:
    // 0x80802D0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802D10: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802D14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802D18: jr          $ra
    // 0x80802D1C: nop

    return;
    // 0x80802D1C: nop

;}
RECOMP_FUNC void _capod_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856E0: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856E0);
    return;
    // 0x800856E4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_8001B7B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B7BC: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8001B7C0: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001B7C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001B7C8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001B7CC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8001B7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B7D4: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8001B7D8: jal         0x8001B388
    // 0x8001B7DC: lw          $a0, -0x40F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X40F0);
    heap_get_allocation_size(rdram, ctx);
        goto after_0;
    // 0x8001B7DC: lw          $a0, -0x40F0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X40F0);
    after_0:
    // 0x8001B7E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B7E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001B7E8: jr          $ra
    // 0x8001B7EC: nop

    return;
    // 0x8001B7EC: nop

;}
RECOMP_FUNC void _subaddieaudioquick_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D08: syscall     809
    recomp_syscall_handler(rdram, ctx, 0x80089D08);
    return;
    // 0x80089D0C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801D94_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801D98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801DA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801DA4: jal         0x80100094
    // 0x80801DA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801DA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801DAC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1700, 0X2630) << 16);
    // 0x80801DB0: addiu       $t6, $t6, 0x2630
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1700, 0X2630));
    // 0x80801DB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801DB8: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x80801DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801DC0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801DC4: jal         0x800BBCB8
    // 0x80801DC8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80801DC8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80801DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801DD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801DD4: jr          $ra
    // 0x80801DD8: nop

    return;
    // 0x80801DD8: nop

;}
RECOMP_FUNC void func_8080215C_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080215C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802164: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802168: jal         0x80100094
    // 0x8080216C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080216C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80802170: beq         $v0, $zero, L_8080218C
    if (ctx->r2 == 0) {
        // 0x80802174: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080218C;
    }
    // 0x80802174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802178: jal         0x80100094
    // 0x8080217C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080217C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80802180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802184: jal         0x80089818
    // 0x80802188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x80802188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_8080218C:
    // 0x8080218C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802194: jr          $ra
    // 0x80802198: nop

    return;
    // 0x80802198: nop

;}
RECOMP_FUNC void _bsdronebubbled_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083060: syscall     40
    recomp_syscall_handler(rdram, ctx, 0x80083060);
    return;
    // 0x80083064: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void idworld_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800168: lw          $t6, 0x7EF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EF8);
    // 0x8080016C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800174: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800178: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080017C: bne         $t6, $zero, L_8080018C
    if (ctx->r14 != 0) {
        // 0x80800180: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_8080018C;
    }
    // 0x80800180: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80800184: b           L_80800208
    // 0x80800188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800208;
    // 0x80800188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080018C:
    // 0x8080018C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800190: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800194: jal         0x800B296C
    // 0x80800198: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    vector_end(rdram, ctx);
        goto after_0;
    // 0x80800198: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080019C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808001A0: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x808001A4: jal         0x800B28C4
    // 0x808001A8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x808001A8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001AC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808001B0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808001B4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808001B8: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x808001BC: beq         $at, $zero, L_80800204
    if (ctx->r1 == 0) {
        // 0x808001C0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800204;
    }
    // 0x808001C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808001C4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x808001C8: lbu         $t7, 0x6($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X6);
L_808001CC:
    // 0x808001CC: bnel        $v0, $t7, L_808001F8
    if (ctx->r2 != ctx->r15) {
        // 0x808001D0: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_808001F8;
    }
    goto skip_0;
    // 0x808001D0: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_0:
    // 0x808001D4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x808001D8: bnel        $a2, $t8, L_808001F8
    if (ctx->r6 != ctx->r24) {
        // 0x808001DC: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_808001F8;
    }
    goto skip_1;
    // 0x808001DC: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_1:
    // 0x808001E0: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x808001E4: bnel        $a3, $t9, L_808001F8
    if (ctx->r7 != ctx->r25) {
        // 0x808001E8: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_808001F8;
    }
    goto skip_2;
    // 0x808001E8: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_2:
    // 0x808001EC: b           L_80800208
    // 0x808001F0: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
        goto L_80800208;
    // 0x808001F0: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x808001F4: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
L_808001F8:
    // 0x808001F8: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x808001FC: bnel        $at, $zero, L_808001CC
    if (ctx->r1 != 0) {
        // 0x80800200: lbu         $t7, 0x6($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X6);
            goto L_808001CC;
    }
    goto skip_3;
    // 0x80800200: lbu         $t7, 0x6($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X6);
    skip_3:
L_80800204:
    // 0x80800204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800208:
    // 0x80800208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080020C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void func_80019BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019BB8: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80019BBC: addiu       $t0, $t0, -0x4350
    ctx->r8 = ADD32(ctx->r8, -0X4350);
    // 0x80019BC0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80019BC4: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x80019BC8: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x80019BCC: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x80019BD0: nop

    // 0x80019BD4: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x80019BD8: nop

    // 0x80019BDC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019BE0: lwc1        $f1, 0x4($a0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r4, 0X4);
    // 0x80019BE4: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019BE8: lwc1        $f3, 0xC($a0)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r4, 0XC);
    // 0x80019BEC: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80019BF0: lwc1        $f5, 0x14($a0)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r4, 0X14);
    // 0x80019BF4: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80019BF8: lwc1        $f7, 0x1C($a0)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r4, 0X1C);
    // 0x80019BFC: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80019C00: addiu       $t0, $a1, 0xC
    ctx->r8 = ADD32(ctx->r5, 0XC);
L_80019C04:
    // 0x80019C04: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019C08: lwc1        $f13, 0x10($a1)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r5, 0X10);
    // 0x80019C0C: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80019C10: lwc1        $f14, 0x20($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80019C14: mul.s       $f17, $f1, $f13
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f17.fl = MUL_S(ctx->f1.fl, ctx->f13.fl);
    // 0x80019C18: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80019C1C: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80019C20: add.s       $f17, $f17, $f16
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f17.fl = ctx->f17.fl + ctx->f16.fl;
    // 0x80019C24: mul.s       $f16, $f3, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f3.fl, ctx->f12.fl);
    // 0x80019C28: add.s       $f18, $f18, $f17
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f17.fl;
    // 0x80019C2C: mul.s       $f17, $f4, $f13
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f17.fl = MUL_S(ctx->f4.fl, ctx->f13.fl);
    // 0x80019C30: swc1        $f18, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f18.u32l;
    // 0x80019C34: mul.s       $f18, $f5, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 5);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f5.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f5.fl, ctx->f14.fl);
    // 0x80019C38: add.s       $f17, $f17, $f16
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f17.fl = ctx->f17.fl + ctx->f16.fl;
    // 0x80019C3C: mul.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80019C40: add.s       $f18, $f18, $f17
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f17.fl;
    // 0x80019C44: mul.s       $f17, $f7, $f13
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 7);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f7.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f17.fl = MUL_S(ctx->f7.fl, ctx->f13.fl);
    // 0x80019C48: swc1        $f18, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f18.u32l;
    // 0x80019C4C: mul.s       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80019C50: add.s       $f17, $f17, $f16
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f17.fl = ctx->f17.fl + ctx->f16.fl;
    // 0x80019C54: add.s       $f18, $f18, $f17
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f17.fl;
    // 0x80019C58: bne         $a1, $t0, L_80019C04
    if (ctx->r5 != ctx->r8) {
        // 0x80019C5C: swc1        $f18, 0x1C($a1)
        MEM_W(0X1C, ctx->r5) = ctx->f18.u32l;
            goto L_80019C04;
    }
    // 0x80019C5C: swc1        $f18, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f18.u32l;
    // 0x80019C60: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x80019C64: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x80019C68: nor         $t1, $t1, $zero
    ctx->r9 = ~(ctx->r9 | 0);
    // 0x80019C6C: and         $t0, $t0, $t1
    ctx->r8 = ctx->r8 & ctx->r9;
    // 0x80019C70: nop

    // 0x80019C74: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x80019C78: nop

    // 0x80019C7C: jr          $ra
    // 0x80019C80: nop

    return;
    // 0x80019C80: nop

;}
RECOMP_FUNC void func_800DBEFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBEFC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800DBF00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DBF04: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800DBF08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DBF0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800DBF10: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800DBF14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBF18: addu        $a1, $a3, $t7
    ctx->r5 = ADD32(ctx->r7, ctx->r15);
    // 0x800DBF1C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800DBF20: jal         0x800EE7F8
    // 0x800DBF24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800DBF24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800DBF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DBF2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DBF30: jr          $ra
    // 0x800DBF34: nop

    return;
    // 0x800DBF34: nop

;}
RECOMP_FUNC void func_800B4470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4470: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800B4474: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800B4478: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800B447C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B4480: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B4484: addiu       $t6, $zero, 0x228
    ctx->r14 = ADD32(0, 0X228);
    // 0x800B4488: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800B448C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B4490: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800B4494: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800B4498: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800B449C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800B44A0: jal         0x800B56D0
    // 0x800B44A4: lbu         $a0, 0x7F00($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7F00);
    func_800B56D0(rdram, ctx);
        goto after_0;
    // 0x800B44A4: lbu         $a0, 0x7F00($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7F00);
    after_0:
    // 0x800B44A8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800B44AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800B44B0: addiu       $t0, $t0, -0x5A50
    ctx->r8 = ADD32(ctx->r8, -0X5A50);
    // 0x800B44B4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B44B8: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x800B44BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B44C0: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x800B44C4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800B44C8: jal         0x800BA3FC
    // 0x800B44CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BA3FC(rdram, ctx);
        goto after_1;
    // 0x800B44CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800B44D0: lui         $a1, 0x3D99
    ctx->r5 = S32(0X3D99 << 16);
    // 0x800B44D4: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x800B44D8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B44DC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800B44E0: jal         0x800BA594
    // 0x800B44E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BA594(rdram, ctx);
        goto after_2;
    // 0x800B44E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800B44E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B44EC: jal         0x800BA75C
    // 0x800B44F0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800BA75C(rdram, ctx);
        goto after_3;
    // 0x800B44F0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_3:
    // 0x800B44F4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800B44F8: beq         $a1, $zero, L_800B4510
    if (ctx->r5 == 0) {
        // 0x800B44FC: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_800B4510;
    }
    // 0x800B44FC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800B4500: jal         0x800EFA20
    // 0x800B4504: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    func_800EFA20(rdram, ctx);
        goto after_4;
    // 0x800B4504: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_4:
    // 0x800B4508: b           L_800B4520
    // 0x800B450C: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
        goto L_800B4520;
    // 0x800B450C: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_800B4510:
    // 0x800B4510: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B4514: nop

    // 0x800B4518: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800B451C: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
L_800B4520:
    // 0x800B4520: lwc1        $f0, 0x6C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B4524: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B4528: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B452C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800B4530: nop

    // 0x800B4534: bc1tl       L_800B4548
    if (c1cs) {
        // 0x800B4538: trunc.w.s   $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_800B4548;
    }
    goto skip_0;
    // 0x800B4538: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_0:
    // 0x800B453C: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800B4540: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800B4544: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
L_800B4548:
    // 0x800B4548: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B454C: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B4550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4554: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800B4558: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800B455C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800B4560: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800B4564: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800B4568: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x800B456C: sra         $a2, $t5, 16
    ctx->r6 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800B4570: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800B4574: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x800B4578: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800B457C: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x800B4580: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800B4584: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x800B4588: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x800B458C: jal         0x800BA930
    // 0x800B4590: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800BA930(rdram, ctx);
        goto after_5;
    // 0x800B4590: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_5:
    // 0x800B4594: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800B4598: beql        $a1, $zero, L_800B45AC
    if (ctx->r5 == 0) {
        // 0x800B459C: lw          $t0, 0x64($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X64);
            goto L_800B45AC;
    }
    goto skip_1;
    // 0x800B459C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x800B45A0: jal         0x800BAB80
    // 0x800B45A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BAB80(rdram, ctx);
        goto after_6;
    // 0x800B45A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800B45A8: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
L_800B45AC:
    // 0x800B45AC: addiu       $t1, $zero, 0x238
    ctx->r9 = ADD32(0, 0X238);
    // 0x800B45B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B45B4: bne         $t0, $zero, L_800B45C0
    if (ctx->r8 != 0) {
        // 0x800B45B8: nop
    
            goto L_800B45C0;
    }
    // 0x800B45B8: nop

    // 0x800B45BC: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
L_800B45C0:
    // 0x800B45C0: jal         0x800BA5A8
    // 0x800B45C4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800BA5A8(rdram, ctx);
        goto after_7;
    // 0x800B45C4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x800B45C8: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B45CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B45D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B45D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B45D8: jal         0x800BA8F8
    // 0x800B45DC: nop

    func_800BA8F8(rdram, ctx);
        goto after_8;
    // 0x800B45DC: nop

    after_8:
    // 0x800B45E0: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x800B45E4: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x800B45E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B45EC: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800B45F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B45F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B45F8: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800B45FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B4600: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B4604: jal         0x800BA7C4
    // 0x800B4608: nop

    func_800BA7C4(rdram, ctx);
        goto after_9;
    // 0x800B4608: nop

    after_9:
    // 0x800B460C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800B4610: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800B4614: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x800B4618: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B461C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B4620: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800B4624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4628: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B462C: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B4630: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B4634: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B4638: jal         0x800BA7FC
    // 0x800B463C: nop

    func_800BA7FC(rdram, ctx);
        goto after_10;
    // 0x800B463C: nop

    after_10:
    // 0x800B4640: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B4644: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800B4648: addiu       $t7, $t7, -0x5A50
    ctx->r15 = ADD32(ctx->r15, -0X5A50);
    // 0x800B464C: bne         $t6, $t7, L_800B4680
    if (ctx->r14 != ctx->r15) {
        // 0x800B4650: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800B4680;
    }
    // 0x800B4650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4654: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800B4658: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B465C: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B4660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4664: div.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B4668: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B466C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B4670: jal         0x800BA5BC
    // 0x800B4674: nop

    func_800BA5BC(rdram, ctx);
        goto after_11;
    // 0x800B4674: nop

    after_11:
    // 0x800B4678: b           L_800B4690
    // 0x800B467C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800B4690;
    // 0x800B467C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800B4680:
    // 0x800B4680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B4684: jal         0x800BA5B0
    // 0x800B4688: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_800BA5B0(rdram, ctx);
        goto after_12;
    // 0x800B4688: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_12:
    // 0x800B468C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800B4690:
    // 0x800B4690: jal         0x800BA22C
    // 0x800B4694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_13;
    // 0x800B4694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x800B4698: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B469C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B46A0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800B46A4: jr          $ra
    // 0x800B46A8: nop

    return;
    // 0x800B46A8: nop

    // 0x800B46AC: nop

;}
RECOMP_FUNC void func_80801DF0_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DF0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801DF4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80801DF8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801DFC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80801E00: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80801E04: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80801E08: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80801E0C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80801E10: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80801E14: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80801E18: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80801E1C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80801E20: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801E24: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801E28: jal         0x80100094
    // 0x80801E2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801E2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801E30: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80801E34: jal         0x80106790
    // 0x80801E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801E3C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80801E40: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80801E44: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80801E48: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x80801E4C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80801E50: or          $s7, $t6, $zero
    ctx->r23 = ctx->r14 | 0;
    // 0x80801E54: blez        $v1, L_80801EEC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80801E58: addiu       $s6, $t6, 0x568
        ctx->r22 = ADD32(ctx->r14, 0X568);
            goto L_80801EEC;
    }
    // 0x80801E58: addiu       $s6, $t6, 0x568
    ctx->r22 = ADD32(ctx->r14, 0X568);
    // 0x80801E5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2216, 0X2194) << 16);
    // 0x80801E60: lwc1        $f20, 0x2194($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2216, 0X2194));
L_80801E64:
    // 0x80801E64: lw          $t7, 0x568($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X568);
    // 0x80801E68: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x80801E6C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801E70: blez        $t7, L_80801ED8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80801E74: lw          $s4, 0x48($sp)
        ctx->r20 = MEM_W(ctx->r29, 0X48);
            goto L_80801ED8;
    }
    // 0x80801E74: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80801E78: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80801E7C: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
L_80801E80:
    // 0x80801E80: jal         0x80106790
    // 0x80801E84: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80801E84: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_2:
    // 0x80801E88: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801E8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80801E90: jal         0x800EEB40
    // 0x80801E94: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x80801E94: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_3:
    // 0x80801E98: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80801E9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801EA0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80801EA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801EA8: bc1fl       L_80801EBC
    if (!c1cs) {
        // 0x80801EAC: lw          $t8, 0x0($s3)
        ctx->r24 = MEM_W(ctx->r19, 0X0);
            goto L_80801EBC;
    }
    goto skip_0;
    // 0x80801EAC: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x80801EB0: jal         0x8010108C
    // 0x80801EB4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    func_8010108C(rdram, ctx);
        goto after_4;
    // 0x80801EB4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    after_4:
    // 0x80801EB8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
L_80801EBC:
    // 0x80801EBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801EC0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80801EC4: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80801EC8: bne         $at, $zero, L_80801E80
    if (ctx->r1 != 0) {
        // 0x80801ECC: nop
    
            goto L_80801E80;
    }
    // 0x80801ECC: nop

    // 0x80801ED0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80801ED4: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
L_80801ED8:
    // 0x80801ED8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80801EDC: slt         $at, $fp, $v1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80801EE0: addiu       $s7, $s7, 0x54
    ctx->r23 = ADD32(ctx->r23, 0X54);
    // 0x80801EE4: bne         $at, $zero, L_80801E64
    if (ctx->r1 != 0) {
        // 0x80801EE8: addiu       $s6, $s6, 0x54
        ctx->r22 = ADD32(ctx->r22, 0X54);
            goto L_80801E64;
    }
    // 0x80801EE8: addiu       $s6, $s6, 0x54
    ctx->r22 = ADD32(ctx->r22, 0X54);
L_80801EEC:
    // 0x80801EEC: beq         $s5, $zero, L_80801F00
    if (ctx->r21 == 0) {
        // 0x80801EF0: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80801F00;
    }
    // 0x80801EF0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80801EF4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80801EF8: jal         0x8010108C
    // 0x80801EFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_5;
    // 0x80801EFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_80801F00:
    // 0x80801F00: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80801F04: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801F08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801F0C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80801F10: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80801F14: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80801F18: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80801F1C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80801F20: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80801F24: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80801F28: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80801F2C: jr          $ra
    // 0x80801F30: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801F30: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8080000C_chmricecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800020: jal         0x800EE7F8
    // 0x80800024: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80800028: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080002C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800030: addiu       $a0, $zero, 0x1C9
    ctx->r4 = ADD32(0, 0X1C9);
    // 0x80800034: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80800038: jal         0x800DA298
    // 0x8080003C: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080003C: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: jal         0x8010A5B0
    // 0x80800048: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010A5B0(rdram, ctx);
        goto after_2;
    // 0x80800048: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8080004C: jal         0x80088848
    // 0x80800050: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800050: nop

    after_3:
    // 0x80800054: beq         $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x80800058: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800080;
    }
    // 0x80800058: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080005C: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800060: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8080006C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800070: jal         0x80102424
    // 0x80800074: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800074: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x80800078: b           L_8080009C
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080009C;
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800080:
    // 0x80800080: jal         0x800DA298
    // 0x80800084: addiu       $a0, $zero, 0x31B
    ctx->r4 = ADD32(0, 0X31B);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800084: addiu       $a0, $zero, 0x31B
    ctx->r4 = ADD32(0, 0X31B);
    after_5:
    // 0x80800088: beql        $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
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
        goto after_6;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080009C:
    // 0x8080009C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void func_8080000C_glcutDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: sb          $a0, 0x75F1($at)
    MEM_B(0X75F1, ctx->r1) = ctx->r4;
    return;
    // 0x80800014: sb          $a0, 0x75F1($at)
    MEM_B(0X75F1, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _batimer_incrementBy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852E8: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x800852E8);
    return;
    // 0x800852EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsbtrot_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D10: jal         0x80800C20
    // 0x80800D14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800C20_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80800D14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D1C: jal         0x808002A4
    // 0x80800D20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808002A4_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80800D20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800D24: jal         0x80800120
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800120_bsbtrot(rdram, ctx);
        goto after_2;
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800D2C: jal         0x808004B4
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_3;
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800D34: jal         0x8008E3E8
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E3E8(rdram, ctx);
        goto after_4;
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800D3C: beql        $v0, $zero, L_80800D50
    if (ctx->r2 == 0) {
        // 0x80800D40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D50;
    }
    goto skip_0;
    // 0x80800D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800D44: jal         0x80085078
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D50:
    // 0x80800D50: jal         0x8009D3A8
    // 0x80800D54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_6;
    // 0x80800D54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D5C: jal         0x808007E0
    // 0x80800D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808007E0_bsbtrot(rdram, ctx);
        goto after_7;
    // 0x80800D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D68: jal         0x800A02DC
    // 0x80800D6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A02DC(rdram, ctx);
        goto after_8;
    // 0x80800D6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x80800D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D74: jal         0x8009E5C8
    // 0x80800D78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x80800D78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80800D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D88: jr          $ra
    // 0x80800D8C: nop

    return;
    // 0x80800D8C: nop

;}
RECOMP_FUNC void func_80800E0C_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800E14: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800E18: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800E1C: jal         0x800EA05C
    // 0x80800E20: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800E20: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800E24: addiu       $at, $zero, 0x113
    ctx->r1 = ADD32(0, 0X113);
    // 0x80800E28: bnel        $v0, $at, L_80800E58
    if (ctx->r2 != ctx->r1) {
        // 0x80800E2C: addiu       $a0, $zero, 0x17E0
        ctx->r4 = ADD32(0, 0X17E0);
            goto L_80800E58;
    }
    goto skip_0;
    // 0x80800E2C: addiu       $a0, $zero, 0x17E0
    ctx->r4 = ADD32(0, 0X17E0);
    skip_0:
    // 0x80800E30: jal         0x800CBD84
    // 0x80800E34: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800CBD84(rdram, ctx);
        goto after_1;
    // 0x80800E34: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800E38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800E3C: beq         $v0, $at, L_80800E54
    if (ctx->r2 == ctx->r1) {
        // 0x80800E40: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800E54;
    }
    // 0x80800E40: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800E44: jal         0x80800D88
    // 0x80800E48: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800D88_chterryegg(rdram, ctx);
        goto after_2;
    // 0x80800E48: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80800E4C: b           L_80800E78
    // 0x80800E50: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800E78;
    // 0x80800E50: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800E54:
    // 0x80800E54: addiu       $a0, $zero, 0x17E0
    ctx->r4 = ADD32(0, 0X17E0);
L_80800E58:
    // 0x80800E58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800E60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800E64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800E68: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800E6C: jal         0x800C05B8
    // 0x80800E70: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800C05B8(rdram, ctx);
        goto after_3;
    // 0x80800E70: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_3:
    // 0x80800E74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E78:
    // 0x80800E78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800E7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E80: jr          $ra
    // 0x80800E84: nop

    return;
    // 0x80800E84: nop

;}
RECOMP_FUNC void _bsbanshack_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082728: syscall     8
    recomp_syscall_handler(rdram, ctx, 0x80082728);
    return;
    // 0x8008272C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800E28_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800E2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800E30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800E34: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800E38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E3C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80800E40: jal         0x80100094
    // 0x80800E44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E48: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800E4C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800E50: jal         0x80102424
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800E58: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800E5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E60: beq         $a2, $at, L_80800F68
    if (ctx->r6 == ctx->r1) {
        // 0x80800E64: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800F68;
    }
    // 0x80800E64: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800E68: beq         $a2, $at, L_80800E90
    if (ctx->r6 == ctx->r1) {
        // 0x80800E6C: addiu       $a0, $zero, 0x57
        ctx->r4 = ADD32(0, 0X57);
            goto L_80800E90;
    }
    // 0x80800E6C: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x80800E70: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800E74: beq         $a2, $at, L_80800EDC
    if (ctx->r6 == ctx->r1) {
        // 0x80800E78: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80800EDC;
    }
    // 0x80800E78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E7C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800E80: beql        $a2, $at, L_80800F04
    if (ctx->r6 == ctx->r1) {
        // 0x80800E84: lhu         $t6, 0x72($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X72);
            goto L_80800F04;
    }
    goto skip_0;
    // 0x80800E84: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800E88: b           L_80800F6C
    // 0x80800E8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800F6C;
    // 0x80800E8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E90:
    // 0x80800E90: jal         0x800DA9E4
    // 0x80800E94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_2;
    // 0x80800E94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800E98: bne         $v0, $zero, L_80800EC0
    if (ctx->r2 != 0) {
        // 0x80800E9C: nop
    
            goto L_80800EC0;
    }
    // 0x80800E9C: nop

    // 0x80800EA0: jal         0x80800DF8
    // 0x80800EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DF8_chbadjinjo(rdram, ctx);
        goto after_3;
    // 0x80800EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800EA8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800EAC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80800EB0: addiu       $a1, $zero, 0xCE8
    ctx->r5 = ADD32(0, 0XCE8);
    // 0x80800EB4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800EB8: jal         0x8008A208
    // 0x80800EBC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800EBC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
L_80800EC0:
    // 0x80800EC0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1576, 0X12F8) << 16);
    // 0x80800EC4: addiu       $a1, $a1, 0x12F8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X12F8));
    // 0x80800EC8: jal         0x80801090
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801090_chbadjinjo(rdram, ctx);
        goto after_5;
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800ED0: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800ED4: b           L_80800F68
    // 0x80800ED8: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
        goto L_80800F68;
    // 0x80800ED8: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_80800EDC:
    // 0x80800EDC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800EE0: jal         0x800EE7F8
    // 0x80800EE4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800EE4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_6:
    // 0x80800EE8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800EEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800EF0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800EF4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800EF8: b           L_80800F68
    // 0x80800EFC: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
        goto L_80800F68;
    // 0x80800EFC: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80800F00: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_80800F04:
    // 0x80800F04: lbu         $t3, 0x70($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X70);
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F0C: andi        $t7, $t6, 0xFC0F
    ctx->r15 = ctx->r14 & 0XFC0F;
    // 0x80800F10: sh          $t7, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r15;
    // 0x80800F14: lw          $t8, 0x70($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X70);
    // 0x80800F18: lbu         $t6, 0x64($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X64);
    // 0x80800F1C: andi        $t4, $t3, 0xFF01
    ctx->r12 = ctx->r11 & 0XFF01;
    // 0x80800F20: sll         $t9, $t8, 22
    ctx->r25 = S32(ctx->r24 << 22);
    // 0x80800F24: srl         $t0, $t9, 26
    ctx->r8 = S32(U32(ctx->r25) >> 26);
    // 0x80800F28: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80800F2C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800F30: andi        $t2, $t6, 0xFFBF
    ctx->r10 = ctx->r14 & 0XFFBF;
    // 0x80800F34: sb          $t2, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r10;
    // 0x80800F38: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800F3C: sb          $t5, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r13;
    // 0x80800F40: andi        $t4, $t2, 0x7F
    ctx->r12 = ctx->r10 & 0X7F;
    // 0x80800F44: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80800F48: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80800F4C: sll         $t3, $t0, 7
    ctx->r11 = S32(ctx->r8 << 7);
    // 0x80800F50: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80800F54: jal         0x8010A570
    // 0x80800F58: sb          $t5, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r13;
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x80800F58: sb          $t5, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r13;
    after_7:
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F60: jal         0x8008A4B0
    // 0x80800F64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800F64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_80800F68:
    // 0x80800F68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F6C:
    // 0x80800F6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800F74: jr          $ra
    // 0x80800F78: nop

    return;
    // 0x80800F78: nop

;}
RECOMP_FUNC void func_800C2718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2718: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C271C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C2720: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C2724: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C2728: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C272C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C2730: jal         0x800C0638
    // 0x800C2734: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800C0638(rdram, ctx);
        goto after_0;
    // 0x800C2734: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C2738: beq         $v0, $zero, L_800C2780
    if (ctx->r2 == 0) {
        // 0x800C273C: nop
    
            goto L_800C2780;
    }
    // 0x800C273C: nop

    // 0x800C2740: jal         0x800D8FF8
    // 0x800C2744: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x800C2744: nop

    after_1:
    // 0x800C2748: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C274C: addiu       $v0, $v0, -0x5788
    ctx->r2 = ADD32(ctx->r2, -0X5788);
    // 0x800C2750: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C2754: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C2758: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C275C: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800C2760: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800C2764: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C2768: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x800C276C: nop

    // 0x800C2770: bc1f        L_800C27BC
    if (!c1cs) {
        // 0x800C2774: nop
    
            goto L_800C27BC;
    }
    // 0x800C2774: nop

    // 0x800C2778: b           L_800C27BC
    // 0x800C277C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
        goto L_800C27BC;
    // 0x800C277C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_800C2780:
    // 0x800C2780: jal         0x800D8FF8
    // 0x800C2784: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x800C2784: nop

    after_2:
    // 0x800C2788: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C278C: addiu       $v0, $v0, -0x5788
    ctx->r2 = ADD32(ctx->r2, -0X5788);
    // 0x800C2790: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C2794: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C2798: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C279C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800C27A0: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x800C27A4: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C27A8: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x800C27AC: nop

    // 0x800C27B0: bc1f        L_800C27BC
    if (!c1cs) {
        // 0x800C27B4: nop
    
            goto L_800C27BC;
    }
    // 0x800C27B4: nop

    // 0x800C27B8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_800C27BC:
    // 0x800C27BC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C27C0: addiu       $s2, $s2, -0x73F0
    ctx->r18 = ADD32(ctx->r18, -0X73F0);
    // 0x800C27C4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800C27C8: addiu       $s4, $zero, 0x3C
    ctx->r20 = ADD32(0, 0X3C);
    // 0x800C27CC: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_800C27D0:
    // 0x800C27D0: lbu         $t6, 0x78($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X78);
    // 0x800C27D4: beql        $t6, $zero, L_800C2818
    if (ctx->r14 == 0) {
        // 0x800C27D8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C2818;
    }
    goto skip_0;
    // 0x800C27D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800C27DC: lw          $t7, 0x78($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X78);
    // 0x800C27E0: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x800C27E4: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x800C27E8: beql        $s3, $t9, L_800C27FC
    if (ctx->r19 == ctx->r25) {
        // 0x800C27EC: andi        $s0, $s1, 0xFF
        ctx->r16 = ctx->r17 & 0XFF;
            goto L_800C27FC;
    }
    goto skip_1;
    // 0x800C27EC: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    skip_1:
    // 0x800C27F0: jal         0x800C2000
    // 0x800C27F4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    func_800C2000(rdram, ctx);
        goto after_3;
    // 0x800C27F4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_3:
    // 0x800C27F8: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
L_800C27FC:
    // 0x800C27FC: jal         0x800C269C
    // 0x800C2800: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C269C(rdram, ctx);
        goto after_4;
    // 0x800C2800: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_4:
    // 0x800C2804: beql        $v0, $zero, L_800C2818
    if (ctx->r2 == 0) {
        // 0x800C2808: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C2818;
    }
    goto skip_2;
    // 0x800C2808: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x800C280C: jal         0x800C16A4
    // 0x800C2810: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C16A4(rdram, ctx);
        goto after_5;
    // 0x800C2810: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_5:
    // 0x800C2814: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800C2818:
    // 0x800C2818: bne         $s1, $s4, L_800C27D0
    if (ctx->r17 != ctx->r20) {
        // 0x800C281C: addiu       $s2, $s2, 0x80
        ctx->r18 = ADD32(ctx->r18, 0X80);
            goto L_800C27D0;
    }
    // 0x800C281C: addiu       $s2, $s2, 0x80
    ctx->r18 = ADD32(ctx->r18, 0X80);
    // 0x800C2820: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2824: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C2828: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C282C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C2830: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C2834: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C2838: jr          $ra
    // 0x800C283C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C283C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80104410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104418: lh          $a1, 0x8E($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X8E);
    // 0x8010441C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104420: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80104424: bne         $a1, $zero, L_80104448
    if (ctx->r5 != 0) {
        // 0x80104428: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80104448;
    }
    // 0x80104428: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010442C: sb          $zero, 0x6E8B($at)
    MEM_B(0X6E8B, ctx->r1) = 0;
    // 0x80104430: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104434: sw          $zero, 0x6EAC($at)
    MEM_W(0X6EAC, ctx->r1) = 0;
    // 0x80104438: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010443C: sb          $zero, 0x6EB0($at)
    MEM_B(0X6EB0, ctx->r1) = 0;
    // 0x80104440: b           L_80104450
    // 0x80104444: addiu       $v0, $v0, 0x6E88
    ctx->r2 = ADD32(ctx->r2, 0X6E88);
        goto L_80104450;
    // 0x80104444: addiu       $v0, $v0, 0x6E88
    ctx->r2 = ADD32(ctx->r2, 0X6E88);
L_80104448:
    // 0x80104448: jal         0x800B301C
    // 0x8010444C: lw          $a0, 0x6E80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E80);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x8010444C: lw          $a0, 0x6E80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E80);
    after_0:
L_80104450:
    // 0x80104450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80104458: jr          $ra
    // 0x8010445C: nop

    return;
    // 0x8010445C: nop

;}
RECOMP_FUNC void func_80800000_chrainbow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800DA298
    // 0x80800010: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    after_0:
    // 0x80800014: beq         $v0, $zero, L_80800024
    if (ctx->r2 == 0) {
        // 0x80800018: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800024;
    }
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080001C: b           L_80800024
    // 0x80800020: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
        goto L_80800024;
    // 0x80800020: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
L_80800024:
    // 0x80800024: jal         0x80800270
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800270_chrainbow(rdram, ctx);
        goto after_1;
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_808012EC_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012EC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808012F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808012F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808012F8: jal         0x8008CABC
    // 0x808012FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808012FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801300: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80801304: jal         0x8008B2B4
    // 0x80801308: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_1;
    // 0x80801308: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080130C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80801310: jal         0x8080081C
    // 0x80801314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801318: lbu         $t6, 0x15E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15E);
    // 0x8080131C: beq         $t6, $zero, L_808013A0
    if (ctx->r14 == 0) {
        // 0x80801320: nop
    
            goto L_808013A0;
    }
    // 0x80801320: nop

    // 0x80801324: jal         0x80092AD8
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092AD8(rdram, ctx);
        goto after_3;
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080132C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801334: jal         0x800E0AF0
    // 0x80801338: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_4;
    // 0x80801338: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x8080133C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801340: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801344: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801348: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080134C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801350: lui         $a3, 0xC1C8
    ctx->r7 = S32(0XC1C8 << 16);
    // 0x80801354: jal         0x800F10B4
    // 0x80801358: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80801358: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8080135C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801360: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801364: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80801368: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080136C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801370: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801374: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80801378: jal         0x800E0AFC
    // 0x8080137C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_6;
    // 0x8080137C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x80801380: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801384: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801388: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8080138C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801390: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80801394: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80801398: jal         0x800E0AFC
    // 0x8080139C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_7;
    // 0x8080139C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_7:
L_808013A0:
    // 0x808013A0: jal         0x800DB9B0
    // 0x808013A4: nop

    func_800DB9B0(rdram, ctx);
        goto after_8;
    // 0x808013A4: nop

    after_8:
    // 0x808013A8: beq         $v0, $zero, L_808013CC
    if (ctx->r2 == 0) {
        // 0x808013AC: nop
    
            goto L_808013CC;
    }
    // 0x808013AC: nop

    // 0x808013B0: jal         0x8009D2E4
    // 0x808013B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D2E4(rdram, ctx);
        goto after_9;
    // 0x808013B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808013B8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808013BC: bne         $v0, $at, L_808013CC
    if (ctx->r2 != ctx->r1) {
        // 0x808013C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013CC;
    }
    // 0x808013C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013C4: jal         0x8009D2D8
    // 0x808013C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009D2D8(rdram, ctx);
        goto after_10;
    // 0x808013C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
L_808013CC:
    // 0x808013CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(412, 0X1984) << 16);
    // 0x808013D0: lwc1        $f8, 0x1984($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(412, 0X1984));
    // 0x808013D4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808013D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(412, 0X1988) << 16);
    // 0x808013DC: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x808013E0: nop

    // 0x808013E4: bc1fl       L_80801420
    if (!c1cs) {
        // 0x808013E8: lui         $a1, 0x3E05
        ctx->r5 = S32(0X3E05 << 16);
            goto L_80801420;
    }
    goto skip_0;
    // 0x808013E8: lui         $a1, 0x3E05
    ctx->r5 = S32(0X3E05 << 16);
    skip_0:
    // 0x808013EC: lwc1        $f10, 0x1988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(412, 0X1988));
    // 0x808013F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013F4: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x808013F8: nop

    // 0x808013FC: bc1fl       L_80801420
    if (!c1cs) {
        // 0x80801400: lui         $a1, 0x3E05
        ctx->r5 = S32(0X3E05 << 16);
            goto L_80801420;
    }
    goto skip_1;
    // 0x80801400: lui         $a1, 0x3E05
    ctx->r5 = S32(0X3E05 << 16);
    skip_1:
    // 0x80801404: jal         0x8009C128
    // 0x80801408: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009C128(rdram, ctx);
        goto after_11;
    // 0x80801408: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_11:
    // 0x8080140C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801410: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80801414: jal         0x801013A8
    // 0x80801418: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    func_801013A8(rdram, ctx);
        goto after_12;
    // 0x80801418: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    after_12:
    // 0x8080141C: lui         $a1, 0x3E05
    ctx->r5 = S32(0X3E05 << 16);
L_80801420:
    // 0x80801420: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    // 0x80801424: jal         0x8008CB10
    // 0x80801428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_13;
    // 0x80801428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080142C: beql        $v0, $zero, L_80801440
    if (ctx->r2 == 0) {
        // 0x80801430: lui         $a1, 0x3F66
        ctx->r5 = S32(0X3F66 << 16);
            goto L_80801440;
    }
    goto skip_2;
    // 0x80801430: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    skip_2:
    // 0x80801434: jal         0x80801110
    // 0x80801438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801110_bstrexlarge(rdram, ctx);
        goto after_14;
    // 0x80801438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080143C: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
L_80801440:
    // 0x80801440: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801444: jal         0x8008CB10
    // 0x80801448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_15;
    // 0x80801448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080144C: beq         $v0, $zero, L_8080145C
    if (ctx->r2 == 0) {
        // 0x80801450: nop
    
            goto L_8080145C;
    }
    // 0x80801450: nop

    // 0x80801454: jal         0x808011A8
    // 0x80801458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808011A8_bstrexlarge(rdram, ctx);
        goto after_16;
    // 0x80801458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_8080145C:
    // 0x8080145C: jal         0x8008CAEC
    // 0x80801460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_17;
    // 0x80801460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801464: beq         $v0, $zero, L_80801474
    if (ctx->r2 == 0) {
        // 0x80801468: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801474;
    }
    // 0x80801468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080146C: addiu       $t7, $zero, 0x151
    ctx->r15 = ADD32(0, 0X151);
    // 0x80801470: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_80801474:
    // 0x80801474: jal         0x8009E5C8
    // 0x80801478: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    bs_setState(rdram, ctx);
        goto after_18;
    // 0x80801478: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_18:
    // 0x8080147C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801480: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801484: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801488: jr          $ra
    // 0x8080148C: nop

    return;
    // 0x8080148C: nop

;}
RECOMP_FUNC void _cheggice_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087230: syscall     538
    recomp_syscall_handler(rdram, ctx, 0x80087230);
    return;
    // 0x80087234: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _idwater_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E58: syscall     744
    recomp_syscall_handler(rdram, ctx, 0x80088E58);
    return;
    // 0x80088E5C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800F5FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5FA8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5FAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5FB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5FB8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5FBC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F5FC0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800F5FC4: jal         0x80091C80
    // 0x800F5FC8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    bakey_setState(rdram, ctx);
        goto after_0;
    // 0x800F5FC8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800F5FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5FD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5FD8: jr          $ra
    // 0x800F5FDC: nop

    return;
    // 0x800F5FDC: nop

;}
RECOMP_FUNC void func_80800030_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080003C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800040: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800044: jal         0x80100094
    // 0x80800048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080004C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800050: jal         0x800DA524
    // 0x80800054: addiu       $a0, $zero, 0x670
    ctx->r4 = ADD32(0, 0X670);
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a0, $zero, 0x670
    ctx->r4 = ADD32(0, 0X670);
    after_1:
    // 0x80800058: jal         0x800DA298
    // 0x8080005C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080005C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_2:
    // 0x80800060: beql        $v0, $zero, L_80800094
    if (ctx->r2 == 0) {
        // 0x80800064: lwc1        $f4, 0x48($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X48);
            goto L_80800094;
    }
    goto skip_0;
    // 0x80800064: lwc1        $f4, 0x48($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X48);
    skip_0:
    // 0x80800068: jal         0x80088848
    // 0x8080006C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x8080006C: nop

    after_3:
    // 0x80800070: bnel        $v0, $zero, L_80800094
    if (ctx->r2 != 0) {
        // 0x80800074: lwc1        $f4, 0x48($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X48);
            goto L_80800094;
    }
    goto skip_1;
    // 0x80800074: lwc1        $f4, 0x48($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X48);
    skip_1:
    // 0x80800078: jal         0x800861A8
    // 0x8080007C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8080007C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800080: jal         0x800FFAB0
    // 0x80800084: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800084: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80800088: b           L_808002F4
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002F4;
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: lwc1        $f4, 0x48($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X48);
L_80800094:
    // 0x80800094: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80800098: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8080009C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x808000A0: sb          $t7, 0x5E($s1)
    MEM_B(0X5E, ctx->r17) = ctx->r15;
    // 0x808000A4: sw          $t6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r14;
    // 0x808000A8: swc1        $f4, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f4.u32l;
    // 0x808000AC: lbu         $t9, 0x2A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2A);
    // 0x808000B0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(932, 0X2B4C) << 16);
    // 0x808000B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000B8: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x808000BC: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
    // 0x808000C0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x808000C4: lw          $v1, 0x28($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X28);
    // 0x808000C8: lbu         $t5, 0x2A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2A);
    // 0x808000CC: sll         $t1, $v1, 20
    ctx->r9 = S32(ctx->r3 << 20);
    // 0x808000D0: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x808000D4: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x808000D8: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x808000DC: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x808000E0: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x808000E4: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x808000E8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x808000EC: sll         $t8, $t2, 5
    ctx->r24 = S32(ctx->r10 << 5);
    // 0x808000F0: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x808000F4: lbu         $t0, 0x2A($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2A);
    // 0x808000F8: andi        $t1, $t0, 0xFFDF
    ctx->r9 = ctx->r8 & 0XFFDF;
    // 0x808000FC: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800100: sb          $t2, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r10;
    // 0x80800104: jal         0x80105A9C
    // 0x80800108: lw          $a1, 0x2B4C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(932, 0X2B4C));
    func_80105A9C(rdram, ctx);
        goto after_6;
    // 0x80800108: lw          $a1, 0x2B4C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(932, 0X2B4C));
    after_6:
    // 0x8080010C: jal         0x80105BAC
    // 0x80800110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80105BAC(rdram, ctx);
        goto after_7;
    // 0x80800110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80800114: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800118: jal         0x80109FE8
    // 0x8080011C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_8;
    // 0x8080011C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800128: jal         0x800897C0
    // 0x8080012C: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x8080012C: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    after_9:
    // 0x80800130: addiu       $a0, $zero, 0x3DA
    ctx->r4 = ADD32(0, 0X3DA);
    // 0x80800134: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800138: jal         0x800882C0
    // 0x8080013C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x8080013C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x80800140: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800144: blez        $v0, L_808001BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800148: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_808001BC;
    }
    // 0x80800148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080014C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80800150: addiu       $s0, $s0, 0x68
    ctx->r16 = ADD32(ctx->r16, 0X68);
L_80800154:
    // 0x80800154: blez        $a3, L_80800184
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80800158: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800184;
    }
    // 0x80800158: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080015C: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
L_80800160:
    // 0x80800160: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80800164: addiu       $t3, $a2, 0x32
    ctx->r11 = ADD32(ctx->r6, 0X32);
    // 0x80800168: lhu         $t4, 0x6($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X6);
    // 0x8080016C: srl         $t6, $t4, 7
    ctx->r14 = S32(U32(ctx->r12) >> 7);
    // 0x80800170: beql        $t3, $t6, L_80800188
    if (ctx->r11 == ctx->r14) {
        // 0x80800174: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_80800188;
    }
    goto skip_2;
    // 0x80800174: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    skip_2:
    // 0x80800178: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080017C: bne         $v1, $a3, L_80800160
    if (ctx->r3 != ctx->r7) {
        // 0x80800180: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80800160;
    }
    // 0x80800180: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80800184:
    // 0x80800184: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
L_80800188:
    // 0x80800188: addu        $a1, $sp, $t7
    ctx->r5 = ADD32(ctx->r29, ctx->r15);
    // 0x8080018C: lw          $a1, 0x3C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3C);
    // 0x80800190: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80800194: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800198: jal         0x800EE88C
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE88C(rdram, ctx);
        goto after_11;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001A0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808001A4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808001A8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x808001AC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x808001B0: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x808001B4: bne         $at, $zero, L_80800154
    if (ctx->r1 != 0) {
        // 0x808001B8: nop
    
            goto L_80800154;
    }
    // 0x808001B8: nop

L_808001BC:
    // 0x808001BC: jal         0x800F54E4
    // 0x808001C0: nop

    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x808001C0: nop

    after_12:
    // 0x808001C4: jal         0x80088848
    // 0x808001C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_13;
    // 0x808001C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_13:
    // 0x808001CC: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x808001D0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001E4;
    }
    // 0x808001D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001D4: jal         0x80102424
    // 0x808001D8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x808001D8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_14:
    // 0x808001DC: b           L_808002F4
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002F4;
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001E4:
    // 0x808001E4: jal         0x800DA298
    // 0x808001E8: addiu       $a0, $zero, 0x179
    ctx->r4 = ADD32(0, 0X179);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x808001E8: addiu       $a0, $zero, 0x179
    ctx->r4 = ADD32(0, 0X179);
    after_15:
    // 0x808001EC: beq         $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x808001F0: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_80800268;
    }
    // 0x808001F0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x808001F4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x808001F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: sw          $a1, 0x60($t8)
    MEM_W(0X60, ctx->r24) = ctx->r5;
    // 0x80800208: sh          $a1, 0x66($t8)
    MEM_H(0X66, ctx->r24) = ctx->r5;
    // 0x8080020C: jal         0x800F608C
    // 0x80800210: sb          $t0, 0x56($t8)
    MEM_B(0X56, ctx->r24) = ctx->r8;
    func_800F608C(rdram, ctx);
        goto after_16;
    // 0x80800210: sb          $t0, 0x56($t8)
    MEM_B(0X56, ctx->r24) = ctx->r8;
    after_16:
    // 0x80800214: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x800F8294
    // 0x80800220: addiu       $a1, $a1, 0x74
    ctx->r5 = ADD32(ctx->r5, 0X74);
    func_800F8294(rdram, ctx);
        goto after_17;
    // 0x80800220: addiu       $a1, $a1, 0x74
    ctx->r5 = ADD32(ctx->r5, 0X74);
    after_17:
    // 0x80800224: jal         0x800F497C
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F497C(rdram, ctx);
        goto after_18;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080022C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800230: addiu       $a1, $zero, 0xF9E
    ctx->r5 = ADD32(0, 0XF9E);
    // 0x80800234: jal         0x8080238C
    // 0x80800238: addiu       $a2, $zero, 0x10F
    ctx->r6 = ADD32(0, 0X10F);
    func_8080238C_chboilerboss(rdram, ctx);
        goto after_19;
    // 0x80800238: addiu       $a2, $zero, 0x10F
    ctx->r6 = ADD32(0, 0X10F);
    after_19:
    // 0x8080023C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800240: jal         0x80800F34
    // 0x80800244: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_20;
    // 0x80800244: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_20:
    // 0x80800248: jal         0x808024B8
    // 0x8080024C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808024B8_chboilerboss(rdram, ctx);
        goto after_21;
    // 0x8080024C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x80800250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800254: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800258: jal         0x80802730
    // 0x8080025C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802730_chboilerboss(rdram, ctx);
        goto after_22;
    // 0x8080025C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
    // 0x80800260: b           L_808002F4
    // 0x80800264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002F4;
    // 0x80800264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800268:
    // 0x80800268: sw          $zero, 0x60($t9)
    MEM_W(0X60, ctx->r25) = 0;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x800F608C
    // 0x80800274: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_23;
    // 0x80800274: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800278: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x800F8294
    // 0x80800284: addiu       $a1, $a1, 0x68
    ctx->r5 = ADD32(ctx->r5, 0X68);
    func_800F8294(rdram, ctx);
        goto after_24;
    // 0x80800284: addiu       $a1, $a1, 0x68
    ctx->r5 = ADD32(ctx->r5, 0X68);
    after_24:
    // 0x80800288: jal         0x800F497C
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F497C(rdram, ctx);
        goto after_25;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x800F49A8
    // 0x80800298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F49A8(rdram, ctx);
        goto after_26;
    // 0x80800298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x8080029C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x808002A0: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: jal         0x800F49D4
    // 0x808002AC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_27;
    // 0x808002AC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    after_27:
    // 0x808002B0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x808002BC: jal         0x800F4A58
    // 0x808002C0: addiu       $a1, $a1, 0x74
    ctx->r5 = ADD32(ctx->r5, 0X74);
    func_800F4A58(rdram, ctx);
        goto after_28;
    // 0x808002C0: addiu       $a1, $a1, 0x74
    ctx->r5 = ADD32(ctx->r5, 0X74);
    after_28:
    // 0x808002C4: jal         0x800861A8
    // 0x808002C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_29;
    // 0x808002C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_29:
    // 0x808002CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002D0: addiu       $a1, $zero, 0xFA8
    ctx->r5 = ADD32(0, 0XFA8);
    // 0x808002D4: jal         0x8080238C
    // 0x808002D8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8080238C_chboilerboss(rdram, ctx);
        goto after_30;
    // 0x808002D8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_30:
    // 0x808002DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002E0: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x808002E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x808002E8: jal         0x808027E4
    // 0x808002EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808027E4_chboilerboss(rdram, ctx);
        goto after_31;
    // 0x808002EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_31:
    // 0x808002F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002F4:
    // 0x808002F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002FC: jr          $ra
    // 0x80800300: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800300: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _ncbaglide_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896F0: syscall     788
    recomp_syscall_handler(rdram, ctx, 0x800896F0);
    return;
    // 0x800896F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chbigterrysbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FF8: syscall     269
    recomp_syscall_handler(rdram, ctx, 0x80085FF8);
    return;
    // 0x80085FFC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void suegg_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D90: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D98: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(3322, 0XE64) << 16);
    // 0x80800D9C: addiu       $a3, $a3, 0xE64
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(3322, 0XE64));
    // 0x80800DA0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800DA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DA8: jal         0x8010D930
    // 0x80800DAC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_8010D930(rdram, ctx);
        goto after_0;
    // 0x80800DAC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_0:
    // 0x80800DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DB8: jr          $ra
    // 0x80800DBC: nop

    return;
    // 0x80800DBC: nop

;}
RECOMP_FUNC void func_80806218_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806218: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080621C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806220: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80806224: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80806228: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080622C: jal         0x80087D58
    // 0x80806230: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _gcnewoption_entrypoint_24(rdram, ctx);
        goto after_0;
    // 0x80806230: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80806234: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80806238: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080623C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806240: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80806244: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80806248: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8080624C: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80806250: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80806254: jal         0x80087CF8
    // 0x80806258: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80806258: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x8080625C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80806260: lui         $t1, 0x8081
    ctx->r9 = S32(RELOC_HI16(804, 0X841C) << 16);
    // 0x80806264: addiu       $t1, $t1, -0x7BE4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(804, 0X841C));
    // 0x80806268: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8080626C: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x80806270: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80806274: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806278: jal         0x80087D90
    // 0x8080627C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_2;
    // 0x8080627C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80806280: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80806284: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80806288: beql        $t2, $zero, L_8080629C
    if (ctx->r10 == 0) {
        // 0x8080628C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080629C;
    }
    goto skip_0;
    // 0x8080628C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80806290: jal         0x80088410
    // 0x80806294: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    _gczoomboxdata_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80806294: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    after_3:
    // 0x80806298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080629C:
    // 0x8080629C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808062A0: jr          $ra
    // 0x808062A4: nop

    return;
    // 0x808062A4: nop

;}
