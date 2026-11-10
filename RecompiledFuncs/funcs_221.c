#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800B9A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B9A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9A2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B9A30: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800B9A34: addiu       $t8, $t8, -0x5920
    ctx->r24 = ADD32(ctx->r24, -0X5920);
    // 0x800B9A38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B9A3C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B9A40: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800B9A44: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B9A48: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B9A4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B9A50: lui         $t2, 0xF800
    ctx->r10 = S32(0XF800 << 16);
    // 0x800B9A54: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B9A58: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B9A5C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B9A60: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800B9A64: lw          $t3, 0x8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8);
    // 0x800B9A68: lw          $t2, 0x4($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X4);
    // 0x800B9A6C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800B9A70: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800B9A74: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B9A78: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800B9A7C: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800B9A80: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x800B9A84: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800B9A88: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x800B9A8C: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800B9A90: or          $t5, $t6, $t7
    ctx->r13 = ctx->r14 | ctx->r15;
    // 0x800B9A94: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B9A98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B9A9C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B9AA0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B9AA4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800B9AA8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9AAC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800B9AB0: addu        $t5, $a3, $t7
    ctx->r13 = ADD32(ctx->r7, ctx->r15);
    // 0x800B9AB4: addu        $t9, $t2, $t3
    ctx->r25 = ADD32(ctx->r10, ctx->r11);
    // 0x800B9AB8: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800B9ABC: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x800B9AC0: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800B9AC4: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x800B9AC8: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x800B9ACC: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x800B9AD0: or          $t4, $t9, $t6
    ctx->r12 = ctx->r25 | ctx->r14;
    // 0x800B9AD4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B9AD8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800B9ADC: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x800B9AE0: andi        $t5, $t7, 0xFFF
    ctx->r13 = ctx->r15 & 0XFFF;
    // 0x800B9AE4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B9AE8: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x800B9AEC: sll         $t8, $t5, 12
    ctx->r24 = S32(ctx->r13 << 12);
    // 0x800B9AF0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800B9AF4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B9AF8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B9AFC: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x800B9B00: lui         $t3, 0x100
    ctx->r11 = S32(0X100 << 16);
    // 0x800B9B04: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B9B08: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B9B0C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B9B10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B9B14: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B9B18: ori         $t3, $t3, 0x100
    ctx->r11 = ctx->r11 | 0X100;
    // 0x800B9B1C: lui         $t2, 0xF100
    ctx->r10 = S32(0XF100 << 16);
    // 0x800B9B20: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B9B24: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B9B28: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800B9B2C: jal         0x800D2CC4
    // 0x800B9B30: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    func_800D2CC4(rdram, ctx);
        goto after_0;
    // 0x800B9B30: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x800B9B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B9B3C: jr          $ra
    // 0x800B9B40: nop

    return;
    // 0x800B9B40: nop

    // 0x800B9B44: nop

    // 0x800B9B48: nop

    // 0x800B9B4C: nop

;}
RECOMP_FUNC void func_800D5E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D5E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5E5C: jal         0x800D5440
    // 0x800D5E60: nop

    func_800D5440(rdram, ctx);
        goto after_0;
    // 0x800D5E60: nop

    after_0:
    // 0x800D5E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D5E6C: jr          $ra
    // 0x800D5E70: nop

    return;
    // 0x800D5E70: nop

;}
RECOMP_FUNC void _chhandcart_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B00: syscall     415
    recomp_syscall_handler(rdram, ctx, 0x80086B00);
    return;
    // 0x80086B04: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80804D40_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804D40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804D44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804D48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804D4C: jal         0x80800040
    // 0x80804D50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_0;
    // 0x80804D50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80804D54: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80804D58: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80804D5C: nop

    // 0x80804D60: bc1f        L_80804D80
    if (!c1cs) {
        // 0x80804D64: nop
    
            goto L_80804D80;
    }
    // 0x80804D64: nop

    // 0x80804D68: jal         0x808000C8
    // 0x80804D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C8_chstoneballcontrol(rdram, ctx);
        goto after_1;
    // 0x80804D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80804D70: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80804D74: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80804D78: b           L_80804D8C
    // 0x80804D7C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
        goto L_80804D8C;
    // 0x80804D7C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_80804D80:
    // 0x80804D80: jal         0x80800040
    // 0x80804D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_2;
    // 0x80804D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80804D88: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_80804D8C:
    // 0x80804D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804D90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804D94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804D98: jr          $ra
    // 0x80804D9C: nop

    return;
    // 0x80804D9C: nop

;}
RECOMP_FUNC void func_80800000_bsstonehead(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x80800010: jal         0x8009E74C
    // 0x80800014: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800018: bne         $v0, $zero, L_8080004C
    if (ctx->r2 != 0) {
        // 0x8080001C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080004C;
    }
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800024: jal         0x800947EC
    // 0x80800028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_1;
    // 0x80800028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080002C: jal         0x80095A40
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_2;
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: jal         0x80092864
    // 0x8080003C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_3;
    // 0x8080003C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: jal         0x80095A74
    // 0x80800048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80095A74(rdram, ctx);
        goto after_4;
    // 0x80800048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_8080004C:
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
RECOMP_FUNC void func_801110C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801110C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801110C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801110CC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801110D0: addiu       $a2, $a3, 0x74
    ctx->r6 = ADD32(ctx->r7, 0X74);
    // 0x801110D4: jal         0x800EFB24
    // 0x801110D8: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x801110D8: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    after_0:
    // 0x801110DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801110E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801110E4: jr          $ra
    // 0x801110E8: nop

    return;
    // 0x801110E8: nop

;}
RECOMP_FUNC void func_808001F8_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800200: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800204: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80800208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080020C: jal         0x80102FDC
    // 0x80800210: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800210: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_0:
    // 0x80800214: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800218: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080021C: jal         0x8010A3E8
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A3E8(rdram, ctx);
        goto after_1;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800224: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x80800228: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x8080022C: bgez        $t8, L_808002EC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800230: nop
    
            goto L_808002EC;
    }
    // 0x80800230: nop

    // 0x80800234: jal         0x80800678
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800678_chfactorybattery(rdram, ctx);
        goto after_2;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080023C: beql        $v0, $zero, L_808002B0
    if (ctx->r2 == 0) {
        // 0x80800240: lbu         $t2, 0x64($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X64);
            goto L_808002B0;
    }
    goto skip_0;
    // 0x80800240: lbu         $t2, 0x64($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X64);
    skip_0:
    // 0x80800244: jal         0x80800558
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800558_chfactorybattery(rdram, ctx);
        goto after_3;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080024C: bne         $v0, $zero, L_8080029C
    if (ctx->r2 != 0) {
        // 0x80800250: nop
    
            goto L_8080029C;
    }
    // 0x80800250: nop

    // 0x80800254: jal         0x80800678
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800678_chfactorybattery(rdram, ctx);
        goto after_4;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080025C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800260: addiu       $a2, $a2, 0x7480
    ctx->r6 = ADD32(ctx->r6, 0X7480);
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080026C: jal         0x8008A560
    // 0x80800270: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddietaxi_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x80800270: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80800274: beq         $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x80800278: nop
    
            goto L_8080028C;
    }
    // 0x80800278: nop

    // 0x8080027C: lbu         $t0, 0x64($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X64);
    // 0x80800280: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80800284: b           L_8080032C
    // 0x80800288: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
        goto L_8080032C;
    // 0x80800288: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
L_8080028C:
    // 0x8080028C: jal         0x800FFAB0
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800294: b           L_808003AC
    // 0x80800298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003AC;
    // 0x80800298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080029C:
    // 0x8080029C: jal         0x800FFAB0
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002A4: b           L_808003AC
    // 0x808002A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003AC;
    // 0x808002A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002AC: lbu         $t2, 0x64($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X64);
L_808002B0:
    // 0x808002B0: andi        $t4, $t2, 0xFFFE
    ctx->r12 = ctx->r10 & 0XFFFE;
    // 0x808002B4: sb          $t4, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r12;
    // 0x808002B8: andi        $t5, $t4, 0xE7
    ctx->r13 = ctx->r12 & 0XE7;
    // 0x808002BC: jal         0x80800444
    // 0x808002C0: sb          $t5, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r13;
    func_80800444_chfactorybattery(rdram, ctx);
        goto after_8;
    // 0x808002C0: sb          $t5, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r13;
    after_8:
    // 0x808002C4: beq         $v0, $zero, L_808002DC
    if (ctx->r2 == 0) {
        // 0x808002C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002DC;
    }
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002CC: jal         0x8080130C
    // 0x808002D0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_8080130C_chfactorybattery(rdram, ctx);
        goto after_9;
    // 0x808002D0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_9:
    // 0x808002D4: b           L_8080032C
    // 0x808002D8: nop

        goto L_8080032C;
    // 0x808002D8: nop

L_808002DC:
    // 0x808002DC: jal         0x800FFAB0
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808002E4: b           L_808003AC
    // 0x808002E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003AC;
    // 0x808002E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002EC:
    // 0x808002EC: jal         0x80800678
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800678_chfactorybattery(rdram, ctx);
        goto after_11;
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808002F4: beq         $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x808002F8: nop
    
            goto L_8080031C;
    }
    // 0x808002F8: nop

    // 0x808002FC: jal         0x80800558
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800558_chfactorybattery(rdram, ctx);
        goto after_12;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800304: beq         $v0, $zero, L_8080032C
    if (ctx->r2 == 0) {
        // 0x80800308: nop
    
            goto L_8080032C;
    }
    // 0x80800308: nop

    // 0x8080030C: jal         0x800FFAB0
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800314: b           L_808003AC
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003AC;
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080031C:
    // 0x8080031C: jal         0x800FFAB0
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800324: b           L_808003AC
    // 0x80800328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003AC;
    // 0x80800328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080032C:
    // 0x8080032C: jal         0x808006E4
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006E4_chfactorybattery(rdram, ctx);
        goto after_15;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800334: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: srl         $t6, $a1, 10
    ctx->r14 = S32(U32(ctx->r5) >> 10);
    // 0x80800340: jal         0x8080130C
    // 0x80800344: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8080130C_chfactorybattery(rdram, ctx);
        goto after_16;
    // 0x80800344: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_16:
    // 0x80800348: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080034C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800350: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800354: beq         $t7, $at, L_808003A8
    if (ctx->r15 == ctx->r1) {
        // 0x80800358: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808003A8;
    }
    // 0x80800358: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080035C: beq         $t7, $at, L_808003A8
    if (ctx->r15 == ctx->r1) {
        // 0x80800360: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808003A8;
    }
    // 0x80800360: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800364: beq         $t7, $at, L_808003A8
    if (ctx->r15 == ctx->r1) {
        // 0x80800368: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_808003A8;
    }
    // 0x80800368: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8080036C: beql        $t7, $at, L_808003AC
    if (ctx->r15 == ctx->r1) {
        // 0x80800370: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808003AC;
    }
    goto skip_1;
    // 0x80800370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800374: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x80800378: srl         $t8, $v0, 25
    ctx->r24 = S32(U32(ctx->r2) >> 25);
    // 0x8080037C: beq         $t8, $zero, L_80800390
    if (ctx->r24 == 0) {
        // 0x80800380: sll         $t9, $v0, 22
        ctx->r25 = S32(ctx->r2 << 22);
            goto L_80800390;
    }
    // 0x80800380: sll         $t9, $v0, 22
    ctx->r25 = S32(ctx->r2 << 22);
    // 0x80800384: srl         $t0, $t9, 26
    ctx->r8 = S32(U32(ctx->r25) >> 26);
    // 0x80800388: bne         $t0, $zero, L_808003A0
    if (ctx->r8 != 0) {
        // 0x8080038C: nop
    
            goto L_808003A0;
    }
    // 0x8080038C: nop

L_80800390:
    // 0x80800390: jal         0x8080000C
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080000C_chfactorybattery(rdram, ctx);
        goto after_17;
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800398: jal         0x8008A498
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_18;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
L_808003A0:
    // 0x808003A0: jal         0x80089F60
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_19;
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_808003A8:
    // 0x808003A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003AC:
    // 0x808003AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003B8: jr          $ra
    // 0x808003BC: nop

    return;
    // 0x808003BC: nop

;}
RECOMP_FUNC void func_80800364_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080036C: jal         0x80800448
    // 0x80800370: nop

    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800370: nop

    after_0:
    // 0x80800374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080037C: jr          $ra
    // 0x80800380: nop

    return;
    // 0x80800380: nop

;}
RECOMP_FUNC void boot___ll_div(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000291C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80002920: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80002924: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80002928: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8000292C: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x80002930: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80002934: ddiv        $zero, $t6, $t7
    DDIV(S64(ctx->r14), S64(ctx->r15), &lo, &hi);
    // 0x80002938: nop

    // 0x8000293C: bne         $t7, $zero, L_80002948
    if (ctx->r15 != 0) {
        // 0x80002940: nop
    
            goto L_80002948;
    }
    // 0x80002940: nop

    // 0x80002944: break       7
    do_break(2147494212);
L_80002948:
    // 0x80002948: daddiu      $at, $zero, -0x1
    ctx->r1 = 0 + -0X1;
    // 0x8000294C: bne         $t7, $at, L_80002964
    if (ctx->r15 != ctx->r1) {
        // 0x80002950: daddiu      $at, $zero, 0x1
        ctx->r1 = 0 + 0X1;
            goto L_80002964;
    }
    // 0x80002950: daddiu      $at, $zero, 0x1
    ctx->r1 = 0 + 0X1;
    // 0x80002954: dsll32      $at, $at, 31
    ctx->r1 = ctx->r1 << (31 + 32);
    // 0x80002958: bne         $t6, $at, L_80002964
    if (ctx->r14 != ctx->r1) {
        // 0x8000295C: nop
    
            goto L_80002964;
    }
    // 0x8000295C: nop

    // 0x80002960: break       6
    do_break(2147494240);
L_80002964:
    // 0x80002964: mflo        $v0
    ctx->r2 = lo;
    // 0x80002968: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x8000296C: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80002970: jr          $ra
    // 0x80002974: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80002974: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_80808630_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80808634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080863C: jal         0x800C6E38
    // 0x80808640: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x80808640: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_0:
    // 0x80808644: beq         $v0, $zero, L_80808664
    if (ctx->r2 == 0) {
        // 0x80808648: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80808664;
    }
    // 0x80808648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080864C: jal         0x80091A58
    // 0x80808650: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_1;
    // 0x80808650: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x80808654: beql        $v0, $zero, L_80808668
    if (ctx->r2 == 0) {
        // 0x80808658: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80808668;
    }
    goto skip_0;
    // 0x80808658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8080865C: b           L_80808668
    // 0x80808660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80808668;
    // 0x80808660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80808664:
    // 0x80808664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80808668:
    // 0x80808668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080866C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80808670: jr          $ra
    // 0x80808674: nop

    return;
    // 0x80808674: nop

;}
RECOMP_FUNC void func_80807754_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807754: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80807758: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080775C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80807760: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80807764: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80807768: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080776C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80807770: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80807774: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807778: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080777C: jal         0x80100094
    // 0x80807780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807784: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80807788: jal         0x80802228
    // 0x8080778C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x8080778C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80807790: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80807794: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80807798: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080779C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808077A0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808077A4: sb          $t6, 0xA3($s1)
    MEM_B(0XA3, ctx->r17) = ctx->r14;
    // 0x808077A8: sb          $zero, 0xA2($s1)
    MEM_B(0XA2, ctx->r17) = 0;
    // 0x808077AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808077B0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x808077B4: swc1        $f4, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f4.u32l;
    // 0x808077B8: swc1        $f6, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f6.u32l;
    // 0x808077BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808077C0:
    // 0x808077C0: jal         0x80805798
    // 0x808077C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80805798_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x808077C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808077C8: beql        $v0, $zero, L_808077E8
    if (ctx->r2 == 0) {
        // 0x808077CC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808077E8;
    }
    goto skip_0;
    // 0x808077CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x808077D0: lbu         $t7, 0xA2($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XA2);
    // 0x808077D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808077D8: sllv        $t9, $t8, $s0
    ctx->r25 = S32(ctx->r24 << (ctx->r16 & 31));
    // 0x808077DC: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808077E0: sb          $t0, 0xA2($s1)
    MEM_B(0XA2, ctx->r17) = ctx->r8;
    // 0x808077E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808077E8:
    // 0x808077E8: bnel        $s0, $s3, L_808077C0
    if (ctx->r16 != ctx->r19) {
        // 0x808077EC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808077C0;
    }
    goto skip_1;
    // 0x808077EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x808077F0: jal         0x808027F4
    // 0x808077F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_808027F4_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x808077F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x808077F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808077FC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80807800: jal         0x80803BE8
    // 0x80807804: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80807804: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80807808: jal         0x80802228
    // 0x8080780C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x8080780C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x80807810: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80807814: jal         0x808041E4
    // 0x80807818: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80807818: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x8080781C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80807820: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807824: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80807828: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080782C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80807830: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80807834: jr          $ra
    // 0x80807838: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80807838: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void chlightdemon_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(920, 0X140) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(920, 0X140));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(920, 0X140));
;}
RECOMP_FUNC void func_808007B8_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007C4: jal         0x80085808
    // 0x808007C8: addiu       $a1, $zero, 0x163
    ctx->r5 = ADD32(0, 0X163);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808007C8: addiu       $a1, $zero, 0x163
    ctx->r5 = ADD32(0, 0X163);
    after_0:
    // 0x808007CC: jal         0x80085818
    // 0x808007D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808007D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808007D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007DC: jr          $ra
    // 0x808007E0: nop

    return;
    // 0x808007E0: nop

;}
RECOMP_FUNC void func_808003C4_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003CC: jal         0x80800254
    // 0x808003D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800254_chintroticker(rdram, ctx);
        goto after_0;
    // 0x808003D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003D4: jal         0x800D395C
    // 0x808003D8: nop

    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x808003D8: nop

    after_1:
    // 0x808003DC: beq         $v0, $zero, L_808003FC
    if (ctx->r2 == 0) {
        // 0x808003E0: nop
    
            goto L_808003FC;
    }
    // 0x808003E0: nop

    // 0x808003E4: jal         0x80088180
    // 0x808003E8: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808003E8: nop

    after_2:
    // 0x808003EC: jal         0x800EA334
    // 0x808003F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EA334(rdram, ctx);
        goto after_3;
    // 0x808003F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x808003F4: b           L_8080049C
    // 0x808003F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080049C;
    // 0x808003F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003FC:
    // 0x808003FC: jal         0x800DB9B0
    // 0x80800400: nop

    func_800DB9B0(rdram, ctx);
        goto after_4;
    // 0x80800400: nop

    after_4:
    // 0x80800404: beq         $v0, $zero, L_80800424
    if (ctx->r2 == 0) {
        // 0x80800408: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800424;
    }
    // 0x80800408: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080040C: jal         0x80088808
    // 0x80800410: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _glcutDll_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x80800410: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80800414: jal         0x80088830
    // 0x80800418: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_6;
    // 0x80800418: nop

    after_6:
    // 0x8080041C: b           L_8080049C
    // 0x80800420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080049C;
    // 0x80800420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800424:
    // 0x80800424: lbu         $t7, 0x79($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X79);
    // 0x80800428: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x8080042C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800430: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x80800434: beq         $at, $zero, L_80800498
    if (ctx->r1 == 0) {
        // 0x80800438: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800498;
    }
    // 0x80800438: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8080043C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1648, 0X81C) << 16);
    // 0x80800440: addu        $at, $at, $t9
    gpr jr_addend_80800448 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800444: lw          $t9, 0x81C($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1648, 0X81C));
    // 0x80800448: jr          $t9
    // 0x8080044C: nop

    switch (jr_addend_80800448 >> 2) {
        case 0: goto L_80800468; break;
        case 1: goto L_80800450; break;
        case 2: goto L_80800498; break;
        case 3: goto L_80800478; break;
        case 4: goto L_80800490; break;
        default: switch_error(__func__, 0x80800448, 0x8080081C);
    }
    // 0x8080044C: nop

L_80800450:
    // 0x80800450: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    // 0x80800454: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800458: jal         0x800A7990
    // 0x8080045C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A7990(rdram, ctx);
        goto after_7;
    // 0x8080045C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80800460: b           L_8080049C
    // 0x80800464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080049C;
    // 0x80800464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800468:
    // 0x80800468: jal         0x80088C80
    // 0x8080046C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gsattract_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x8080046C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80800470: b           L_8080049C
    // 0x80800474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080049C;
    // 0x80800474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800478:
    // 0x80800478: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    // 0x8080047C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800480: jal         0x800A7990
    // 0x80800484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A7990(rdram, ctx);
        goto after_9;
    // 0x80800484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80800488: b           L_8080049C
    // 0x8080048C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080049C;
    // 0x8080048C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800490:
    // 0x80800490: jal         0x80088198
    // 0x80800494: nop

    _gcfrontend_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x80800494: nop

    after_10:
L_80800498:
    // 0x80800498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080049C:
    // 0x8080049C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004A0: jr          $ra
    // 0x808004A4: nop

    return;
    // 0x808004A4: nop

;}
RECOMP_FUNC void func_800C3EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3EE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3EE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3EEC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C3EF0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C3EF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C3EF8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800C3EFC: jal         0x800C2840
    // 0x800C3F00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C2840(rdram, ctx);
        goto after_0;
    // 0x800C3F00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800C3F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3F08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3F0C: jr          $ra
    // 0x800C3F10: nop

    return;
    // 0x800C3F10: nop

;}
RECOMP_FUNC void sukickball_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F54: beq         $a0, $zero, L_80800F7C
    if (ctx->r4 == 0) {
        // 0x80800F58: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800F7C;
    }
    // 0x80800F58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F5C: beq         $a0, $at, L_80800FB4
    if (ctx->r4 == ctx->r1) {
        // 0x80800F60: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800FB4;
    }
    // 0x80800F60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F64: beq         $a0, $at, L_80800F98
    if (ctx->r4 == ctx->r1) {
        // 0x80800F68: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800F98;
    }
    // 0x80800F68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800F6C: beql        $a0, $at, L_80800FD4
    if (ctx->r4 == ctx->r1) {
        // 0x80800F70: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80800FD4;
    }
    goto skip_0;
    // 0x80800F70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80800F74: jr          $ra
    // 0x80800F78: nop

    return;
    // 0x80800F78: nop

L_80800F7C:
    // 0x80800F7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800F80: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80800F84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F88: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80800F8C: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x80800F90: jr          $ra
    // 0x80800F94: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    return;
    // 0x80800F94: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_80800F98:
    // 0x80800F98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800F9C: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80800FA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800FA4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80800FA8: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80800FAC: jr          $ra
    // 0x80800FB0: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    return;
    // 0x80800FB0: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
L_80800FB4:
    // 0x80800FB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800FB8: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    // 0x80800FBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800FC0: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80800FC4: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x80800FC8: jr          $ra
    // 0x80800FCC: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x80800FCC: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80800FD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80800FD4:
    // 0x80800FD4: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    // 0x80800FD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800FDC: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80800FE0: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80800FE4: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    // 0x80800FE8: jr          $ra
    // 0x80800FEC: nop

    return;
    // 0x80800FEC: nop

;}
RECOMP_FUNC void func_80801324_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801324: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80801328: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080132C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801330: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80801334: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x80801338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080133C: bc1tl       L_80801358
    if (c1cs) {
        // 0x80801340: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801358;
    }
    goto skip_0;
    // 0x80801340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801344: div.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80801348: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080134C: jal         0x800EF334
    // 0x80801350: nop

    func_800EF334(rdram, ctx);
        goto after_0;
    // 0x80801350: nop

    after_0:
    // 0x80801354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801358:
    // 0x80801358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080135C: jr          $ra
    // 0x80801360: nop

    return;
    // 0x80801360: nop

;}
RECOMP_FUNC void _dbzone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087930: syscall     640
    recomp_syscall_handler(rdram, ctx, 0x80087930);
    return;
    // 0x80087934: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chballoonburst_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085ED0: syscall     257
    recomp_syscall_handler(rdram, ctx, 0x80085ED0);
    return;
    // 0x80085ED4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_bscrouch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: addiu       $a1, $zero, 0x10C
    ctx->r5 = ADD32(0, 0X10C);
    // 0x80800010: jal         0x8008CB3C
    // 0x80800014: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80800014: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80800018: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80800020: sw          $t6, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = ctx->r14;
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void _bsdrone_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FF0: syscall     38
    recomp_syscall_handler(rdram, ctx, 0x80082FF0);
    return;
    // 0x80082FF4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800000_chbanjocurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800F54E4
    // 0x8080000C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: jal         0x800F4C24
    // 0x80800014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4C24(rdram, ctx);
        goto after_1;
    // 0x80800014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void func_808004C4_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004D4: jal         0x8008CABC
    // 0x808004D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808004DC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808004E0: jal         0x8001210C
    // 0x808004E4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x808004E4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    ctx->r2 = tooie_paced_frame_mask(rdram, (uint32_t)ctx->r2, 7, 0);
    // 0x808004E8: bne         $v0, $zero, L_8080051C
    if (ctx->r2 != 0) {
        // 0x808004EC: nop
    
            goto L_8080051C;
    }
    // 0x808004EC: nop

    // 0x808004F0: jal         0x800DC0C0
    // 0x808004F4: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x808004F4: nop

    after_2:
    // 0x808004F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800508: nop

    // 0x8080050C: bc1f        L_8080051C
    if (!c1cs) {
        // 0x80800510: nop
    
            goto L_8080051C;
    }
    // 0x80800510: nop

    // 0x80800514: jal         0x8009FC34
    // 0x80800518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009FC34(rdram, ctx);
        goto after_3;
    // 0x80800518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_8080051C:
    // 0x8080051C: jal         0x8001210C
    // 0x80800520: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_4;
    // 0x80800520: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_4:
    ctx->r2 = tooie_paced_frame_mask(rdram, (uint32_t)ctx->r2, 7, 0);
    // 0x80800524: bnel        $v0, $zero, L_8080055C
    if (ctx->r2 != 0) {
        // 0x80800528: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_8080055C;
    }
    goto skip_0;
    // 0x80800528: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_0:
    // 0x8080052C: jal         0x800DC0C0
    // 0x80800530: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800530: nop

    after_5:
    // 0x80800534: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800538: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080053C: nop

    // 0x80800540: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800544: nop

    // 0x80800548: bc1fl       L_8080055C
    if (!c1cs) {
        // 0x8080054C: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_8080055C;
    }
    goto skip_1;
    // 0x8080054C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_1:
    // 0x80800550: jal         0x80800030
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsswim(rdram, ctx);
        goto after_6;
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800558: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_8080055C:
    // 0x8080055C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800560: jal         0x8008B348
    // 0x80800564: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80800564: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800568: beq         $v0, $zero, L_80800598
    if (ctx->r2 == 0) {
        // 0x8080056C: lui         $a2, 0x3F59
        ctx->r6 = S32(0X3F59 << 16);
            goto L_80800598;
    }
    // 0x8080056C: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800570: lui         $a3, 0x3F93
    ctx->r7 = S32(0X3F93 << 16);
    // 0x80800574: addiu       $t6, $zero, 0x3E80
    ctx->r14 = ADD32(0, 0X3E80);
    // 0x80800578: addiu       $t7, $zero, 0x3E80
    ctx->r15 = ADD32(0, 0X3E80);
    // 0x8080057C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800580: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800584: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800588: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: jal         0x8009DEC0
    // 0x80800594: addiu       $a1, $zero, 0x46F
    ctx->r5 = ADD32(0, 0X46F);
    func_8009DEC0(rdram, ctx);
        goto after_8;
    // 0x80800594: addiu       $a1, $zero, 0x46F
    ctx->r5 = ADD32(0, 0X46F);
    after_8:
L_80800598:
    // 0x80800598: lui         $a1, 0x3EDE
    ctx->r5 = S32(0X3EDE << 16);
    // 0x8080059C: ori         $a1, $a1, 0x9E1B
    ctx->r5 = ctx->r5 | 0X9E1B;
    // 0x808005A0: jal         0x8008B348
    // 0x808005A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x808005A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_9:
    // 0x808005A8: beq         $v0, $zero, L_808005B8
    if (ctx->r2 == 0) {
        // 0x808005AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005B8;
    }
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: jal         0x808000E0
    // 0x808005B4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_808000E0_bsswim(rdram, ctx);
        goto after_10;
    // 0x808005B4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_10:
L_808005B8:
    // 0x808005B8: jal         0x8009EF10
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_11;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808005C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005C4: bne         $v0, $at, L_808005D0
    if (ctx->r2 != ctx->r1) {
        // 0x808005C8: addiu       $t8, $zero, 0x2E
        ctx->r24 = ADD32(0, 0X2E);
            goto L_808005D0;
    }
    // 0x808005C8: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x808005CC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_808005D0:
    // 0x808005D0: jal         0x8008E35C
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_12;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808005D8: bne         $v0, $zero, L_808005E4
    if (ctx->r2 != 0) {
        // 0x808005DC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808005E4;
    }
    // 0x808005DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808005E0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_808005E4:
    // 0x808005E4: jal         0x80097AD0
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_13;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808005EC: beq         $v0, $zero, L_80800600
    if (ctx->r2 == 0) {
        // 0x808005F0: nop
    
            goto L_80800600;
    }
    // 0x808005F0: nop

    // 0x808005F4: jal         0x800848A8
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_14;
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808005FC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80800600:
    // 0x80800600: jal         0x80097F48
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_dive(rdram, ctx);
        goto after_15;
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800608: beq         $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x8080060C: nop
    
            goto L_8080061C;
    }
    // 0x8080060C: nop

    // 0x80800610: jal         0x80800000
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsswim(rdram, ctx);
        goto after_16;
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800618: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_8080061C:
    // 0x8080061C: jal         0x80096500
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096500(rdram, ctx);
        goto after_17;
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800624: beq         $v0, $zero, L_80800640
    if (ctx->r2 == 0) {
        // 0x80800628: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800640;
    }
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: jal         0x80091A58
    // 0x80800630: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_18;
    // 0x80800630: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_18:
    // 0x80800634: beq         $v0, $zero, L_80800640
    if (ctx->r2 == 0) {
        // 0x80800638: addiu       $t0, $zero, 0x5
        ctx->r8 = ADD32(0, 0X5);
            goto L_80800640;
    }
    // 0x80800638: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8080063C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80800640:
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800644: jal         0x80095738
    // 0x80800648: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baflag_isTrue(rdram, ctx);
        goto after_19;
    // 0x80800648: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_19:
    // 0x8080064C: bne         $v0, $zero, L_80800660
    if (ctx->r2 != 0) {
        // 0x80800650: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800660;
    }
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: jal         0x80095738
    // 0x80800658: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    baflag_isTrue(rdram, ctx);
        goto after_20;
    // 0x80800658: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_20:
    // 0x8080065C: beq         $v0, $zero, L_80800668
    if (ctx->r2 == 0) {
        // 0x80800660: addiu       $t1, $zero, 0xD
        ctx->r9 = ADD32(0, 0XD);
            goto L_80800668;
    }
L_80800660:
    // 0x80800660: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x80800664: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80800668:
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: jal         0x8009E5C8
    // 0x80800670: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_21;
    // 0x80800670: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_21:
    // 0x80800674: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800678: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080067C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800680: jr          $ra
    // 0x80800684: nop

    return;
    // 0x80800684: nop

;}
RECOMP_FUNC void func_800FE870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FE874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FE878: jal         0x800DA544
    // 0x800FE87C: addiu       $a0, $zero, 0x675
    ctx->r4 = ADD32(0, 0X675);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x800FE87C: addiu       $a0, $zero, 0x675
    ctx->r4 = ADD32(0, 0X675);
    after_0:
    // 0x800FE880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FE884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FE888: jr          $ra
    // 0x800FE88C: nop

    return;
    // 0x800FE88C: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083278: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083278);
    return;
    // 0x8008327C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800148_chplatuegrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080014C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800154: bne         $a1, $at, L_80800198
    if (ctx->r5 != ctx->r1) {
        // 0x80800158: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800198;
    }
    // 0x80800158: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080015C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800160: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800168: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080016C: bne         $t7, $at, L_80800190
    if (ctx->r15 != ctx->r1) {
        // 0x80800170: nop
    
            goto L_80800190;
    }
    // 0x80800170: nop

    // 0x80800174: jal         0x80103110
    // 0x80800178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x80800178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080017C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800180: jal         0x80102424
    // 0x80800184: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800184: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800188: jal         0x800FC660
    // 0x8080018C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x8080018C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_2:
L_80800190:
    // 0x80800190: b           L_8080019C
    // 0x80800194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080019C;
    // 0x80800194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800198:
    // 0x80800198: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080019C:
    // 0x8080019C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080060C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800610: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800614: jal         0x8080051C
    // 0x80800618: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x80800618: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080061C: bne         $v0, $zero, L_8080062C
    if (ctx->r2 != 0) {
        // 0x80800620: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080062C;
    }
    // 0x80800620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800624: b           L_8080063C
    // 0x80800628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080063C;
    // 0x80800628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080062C:
    // 0x8080062C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800630: jal         0x80800250
    // 0x80800634: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    gsmaker_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800634: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080063C:
    // 0x8080063C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800644: jr          $ra
    // 0x80800648: nop

    return;
    // 0x80800648: nop

;}
RECOMP_FUNC void func_80800084_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800088: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800094: beq         $a1, $at, L_808000B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800098: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808000B0;
    }
    // 0x80800098: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080009C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000A0: beq         $a1, $at, L_808000C0
    if (ctx->r5 == ctx->r1) {
        // 0x808000A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000C0;
    }
    // 0x808000A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000A8: b           L_80800100
    // 0x808000AC: nop

        goto L_80800100;
    // 0x808000AC: nop

L_808000B0:
    // 0x808000B0: jal         0x80800110
    // 0x808000B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800110_chpickups(rdram, ctx);
        goto after_0;
    // 0x808000B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x808000B8: b           L_80800100
    // 0x808000BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800100;
    // 0x808000BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C0:
    // 0x808000C0: lb          $t7, 0x65($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X65);
    // 0x808000C4: bgez        $t7, L_808000F8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808000C8: nop
    
            goto L_808000F8;
    }
    // 0x808000C8: nop

    // 0x808000CC: jal         0x800F54E4
    // 0x808000D0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808000D0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x808000D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000E4: jal         0x800F822C
    // 0x808000E8: nop

    func_800F822C(rdram, ctx);
        goto after_2;
    // 0x808000E8: nop

    after_2:
    // 0x808000EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000F0: jal         0x80101FDC
    // 0x808000F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808000F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
L_808000F8:
    // 0x808000F8: b           L_80800100
    // 0x808000FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800100;
    // 0x808000FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800100:
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
RECOMP_FUNC void bskazjump_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x8008CABC
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800018: jal         0x800832E0
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: jal         0x80095738
    // 0x80800028: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x80800028: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080002C: sw          $v0, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r2;
    // 0x80800030: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800034: jal         0x8008AF24
    // 0x80800038: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x80800038: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x8080003C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800040: jal         0x8008AED4
    // 0x80800044: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800044: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    after_4:
    // 0x80800048: lui         $a1, 0x3FF3
    ctx->r5 = S32(0X3FF3 << 16);
    // 0x8080004C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800050: jal         0x8008B1BC
    // 0x80800054: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80800054: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80800058: lui         $a1, 0x3E09
    ctx->r5 = S32(0X3E09 << 16);
    // 0x8080005C: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x80800060: jal         0x8008B1C8
    // 0x80800064: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008B1C8(rdram, ctx);
        goto after_6;
    // 0x80800064: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80800068: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8080006C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800070: jal         0x8008B24C
    // 0x80800074: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x80800074: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800078: lui         $a2, 0x3F01
    ctx->r6 = S32(0X3F01 << 16);
    // 0x8080007C: ori         $a2, $a2, 0x1340
    ctx->r6 = ctx->r6 | 0X1340;
    // 0x80800080: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800084: jal         0x8008B1D4
    // 0x80800088: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_8;
    // 0x80800088: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x8080008C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800090: jal         0x8008B134
    // 0x80800094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_9;
    // 0x80800094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800098: jal         0x8008B064
    // 0x8080009C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_10;
    // 0x8080009C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x808000A0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808000A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000B4: jal         0x8009FFD8
    // 0x808000B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_11;
    // 0x808000B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_11:
    // 0x808000BC: jal         0x8009EF04
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_12;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808000C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000C8: nop

    // 0x808000CC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808000D0: nop

    // 0x808000D4: bc1t        L_808000F0
    if (c1cs) {
        // 0x808000D8: nop
    
            goto L_808000F0;
    }
    // 0x808000D8: nop

    // 0x808000DC: jal         0x8009EEB8
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_13;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808000E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000E8: jal         0x8009C914
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_14;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_808000F0:
    // 0x808000F0: jal         0x8009C990
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_15;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808000F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000FC: jal         0x8009B9C0
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_16;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800104: jal         0x800834B0
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080010C: jal         0x8009C990
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_18;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800114: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800118: jal         0x8009BB00
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800120: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x8009BA68
    // 0x8080012C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_20;
    // 0x8080012C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_20:
    // 0x80800130: lw          $t7, 0x160($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X160);
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: lui         $a1, 0x4418
    ctx->r5 = S32(0X4418 << 16);
    // 0x8080013C: beq         $t7, $zero, L_8080015C
    if (ctx->r15 == 0) {
        // 0x80800140: nop
    
            goto L_8080015C;
    }
    // 0x80800140: nop

    // 0x80800144: lui         $a1, 0x4418
    ctx->r5 = S32(0X4418 << 16);
    // 0x80800148: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8080014C: jal         0x8009BA58
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_21;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800154: b           L_80800168
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800168;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080015C:
    // 0x8080015C: jal         0x8009BA58
    // 0x80800160: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_22;
    // 0x80800160: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    after_22:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800168:
    // 0x80800168: jal         0x8009BCB4
    // 0x8080016C: lui         $a1, 0xC47A
    ctx->r5 = S32(0XC47A << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_23;
    // 0x8080016C: lui         $a1, 0xC47A
    ctx->r5 = S32(0XC47A << 16);
    after_23:
    // 0x80800170: lw          $t8, 0x164($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X164);
    // 0x80800174: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: beq         $t8, $zero, L_80800198
    if (ctx->r24 == 0) {
        // 0x80800180: addiu       $a1, $zero, 0x4432
        ctx->r5 = ADD32(0, 0X4432);
            goto L_80800198;
    }
    // 0x80800180: addiu       $a1, $zero, 0x4432
    ctx->r5 = ADD32(0, 0X4432);
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x8009DE38
    // 0x8080018C: addiu       $a1, $zero, 0x4432
    ctx->r5 = ADD32(0, 0X4432);
    func_8009DE38(rdram, ctx);
        goto after_24;
    // 0x8080018C: addiu       $a1, $zero, 0x4432
    ctx->r5 = ADD32(0, 0X4432);
    after_24:
    // 0x80800190: b           L_808001A4
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808001A4;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800198:
    // 0x80800198: jal         0x8009DE38
    // 0x8080019C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_25;
    // 0x8080019C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_25:
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001A4:
    // 0x808001A4: jal         0x80095774
    // 0x808001A8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baflag_clear(rdram, ctx);
        goto after_26;
    // 0x808001A8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_26:
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x80095774
    // 0x808001B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_clear(rdram, ctx);
        goto after_27;
    // 0x808001B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_27:
    // 0x808001B8: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x808001BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001C8: jr          $ra
    // 0x808001CC: nop

    return;
    // 0x808001CC: nop

;}
RECOMP_FUNC void func_808006F4_chfantasylakebits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800700: jal         0x800DA298
    // 0x80800704: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800704: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    after_0:
    // 0x80800708: bnel        $v0, $zero, L_80800724
    if (ctx->r2 != 0) {
        // 0x8080070C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800724;
    }
    goto skip_0;
    // 0x8080070C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800710: jal         0x800DA298
    // 0x80800714: addiu       $a0, $zero, 0x9FC
    ctx->r4 = ADD32(0, 0X9FC);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800714: addiu       $a0, $zero, 0x9FC
    ctx->r4 = ADD32(0, 0X9FC);
    after_1:
    // 0x80800718: beql        $v0, $zero, L_80800730
    if (ctx->r2 == 0) {
        // 0x8080071C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800730;
    }
    goto skip_1;
    // 0x8080071C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800720: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
L_80800724:
    // 0x80800724: jal         0x800FFA88
    // 0x80800728: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80800728: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x8080072C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800730:
    // 0x80800730: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800734: jr          $ra
    // 0x80800738: nop

    return;
    // 0x80800738: nop

;}
RECOMP_FUNC void _mlwave_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FB0: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FB0);
    return;
    // 0x80088FB4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800B28_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B34: jal         0x80100094
    // 0x80800B38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800B3C: beq         $v0, $zero, L_80800B4C
    if (ctx->r2 == 0) {
        // 0x80800B40: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800B4C;
    }
    // 0x80800B40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B44: jal         0x800897C8
    // 0x80800B48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800B48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800B4C:
    // 0x80800B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B54: jr          $ra
    // 0x80800B58: nop

    return;
    // 0x80800B58: nop

;}
RECOMP_FUNC void _ncbabee_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896C8: syscall     787
    recomp_syscall_handler(rdram, ctx, 0x800896C8);
    return;
    // 0x800896CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080000C_chinflatablebossdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080001C: jal         0x800DA298
    // 0x80800020: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    after_0:
    // 0x80800024: jal         0x800F54E4
    // 0x80800028: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800028: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080002C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800030: jal         0x800F64A4
    // 0x80800034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_2;
    // 0x80800034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800038: jal         0x800D395C
    // 0x8080003C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800D395C(rdram, ctx);
        goto after_3;
    // 0x8080003C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800040: jal         0x80088848
    // 0x80800044: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800044: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800048: beq         $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x8080004C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800060;
    }
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x80101FDC
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800058: b           L_808000A0
    // 0x8080005C: nop

        goto L_808000A0;
    // 0x8080005C: nop

L_80800060:
    // 0x80800060: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80800064: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800068: bne         $v0, $zero, L_80800088
    if (ctx->r2 != 0) {
        // 0x8080006C: nop
    
            goto L_80800088;
    }
    // 0x8080006C: nop

    // 0x80800070: beq         $t6, $zero, L_80800088
    if (ctx->r14 == 0) {
        // 0x80800074: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800088;
    }
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: jal         0x80101FDC
    // 0x8080007C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x8080007C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800080: b           L_808000A0
    // 0x80800084: nop

        goto L_808000A0;
    // 0x80800084: nop

L_80800088:
    // 0x80800088: beq         $v0, $zero, L_808000A0
    if (ctx->r2 == 0) {
        // 0x8080008C: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_808000A0;
    }
    // 0x8080008C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800090: beq         $t7, $zero, L_808000A0
    if (ctx->r15 == 0) {
        // 0x80800094: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A0;
    }
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x80101FDC
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_808000A0:
    // 0x808000A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1420, 0X130) << 16);
    // 0x808000A4: lwc1        $f6, 0x130($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1420, 0X130));
    // 0x808000A8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808000B4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808000B8: jal         0x80102FDC
    // 0x808000BC: nop

    func_80102FDC(rdram, ctx);
        goto after_8;
    // 0x808000BC: nop

    after_8:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x8010A800
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_9;
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808000CC: addiu       $t8, $zero, 0x822
    ctx->r24 = ADD32(0, 0X822);
    // 0x808000D0: addiu       $t9, $zero, 0x9C
    ctx->r25 = ADD32(0, 0X9C);
    // 0x808000D4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808000D8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808000E4: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x808000E8: jal         0x80086898
    // 0x808000EC: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808000EC: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    after_10:
    // 0x808000F0: beq         $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x808000F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800110;
    }
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: jal         0x800868A8
    // 0x808000FC: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_11;
    // 0x808000FC: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_11:
    // 0x80800100: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800104: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800108: jal         0x800868B0
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_80800110:
    // 0x80800110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800114: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800118: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_808008C8_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808008D4: jal         0x80100094
    // 0x808008D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808008E0: jal         0x80089D48
    // 0x808008E4: lbu         $a0, 0x38($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X38);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808008E4: lbu         $a0, 0x38($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X38);
    after_1:
    // 0x808008E8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808008EC: sb          $v0, 0x38($v1)
    MEM_B(0X38, ctx->r3) = ctx->r2;
    // 0x808008F0: jal         0x80089D48
    // 0x808008F4: lbu         $a0, 0x39($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X39);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808008F4: lbu         $a0, 0x39($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X39);
    after_2:
    // 0x808008F8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808008FC: sb          $v0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r2;
    // 0x80800900: jal         0x80801E80
    // 0x80800904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80801E80_chaliendad(rdram, ctx);
        goto after_3;
    // 0x80800904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080090C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800910: jr          $ra
    // 0x80800914: nop

    return;
    // 0x80800914: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080206C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80802070: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802074: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802078: jal         0x80800538
    // 0x8080207C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x8080207C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802080: jal         0x80099A58
    // 0x80802084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_1;
    // 0x80802084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80802088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080208C: jal         0x80084F78
    // 0x80802090: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bareact_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80802090: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80802094: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80802098: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080209C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020A0: jal         0x8008CDB8
    // 0x808020A4: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    baanim_playForDuration_once(rdram, ctx);
        goto after_3;
    // 0x808020A4: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    after_3:
    // 0x808020A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020AC: jal         0x8009D89C
    // 0x808020B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009D89C(rdram, ctx);
        goto after_4;
    // 0x808020B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x808020B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020B8: jal         0x8009C128
    // 0x808020BC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_5;
    // 0x808020BC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x808020C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020C4: jal         0x800A32C4
    // 0x808020C8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800A32C4(rdram, ctx);
        goto after_6;
    // 0x808020C8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x808020CC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808020D0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808020D4: jal         0x800F1E6C
    // 0x808020D8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800F1E6C(rdram, ctx);
        goto after_7;
    // 0x808020D8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x808020DC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808020E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808020E4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808020E8: jal         0x800136E4
    // 0x808020EC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_8;
    // 0x808020EC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x808020F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808020F4: jal         0x8009C914
    // 0x808020F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_9;
    // 0x808020F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808020FC: jal         0x8009C974
    // 0x80802100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_10;
    // 0x80802100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80802104: jal         0x80084F90
    // 0x80802108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x80802108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080210C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802110: jal         0x8009B9B0
    // 0x80802114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80802114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80802118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080211C: jal         0x8009B9C0
    // 0x80802120: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_13;
    // 0x80802120: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_13:
    // 0x80802124: jal         0x8009BB00
    // 0x80802128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x80802128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080212C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802134: jal         0x8009BA68
    // 0x80802138: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_15;
    // 0x80802138: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_15:
    // 0x8080213C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80802140: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080214C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80802150: jal         0x8009FFD8
    // 0x80802154: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_16;
    // 0x80802154: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_16:
    // 0x80802158: jal         0x80084F80
    // 0x8080215C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x8080215C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80802160: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802164: bne         $v0, $at, L_80802174
    if (ctx->r2 != ctx->r1) {
        // 0x80802168: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802174;
    }
    // 0x80802168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080216C: jal         0x8009B800
    // 0x80802170: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_18;
    // 0x80802170: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_18:
L_80802174:
    // 0x80802174: jal         0x80084F88
    // 0x80802178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80802178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080217C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802180: jal         0x8009BA58
    // 0x80802184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_20;
    // 0x80802184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80802188: jal         0x80084F98
    // 0x8080218C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_5(rdram, ctx);
        goto after_21;
    // 0x8080218C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80802190: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802194: jal         0x8009BCB4
    // 0x80802198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_22;
    // 0x80802198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8080219C: jal         0x8008E944
    // 0x808021A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_23;
    // 0x808021A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808021A4: jal         0x8009514C
    // 0x808021A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_24;
    // 0x808021A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808021AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808021B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808021B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808021B8: jr          $ra
    // 0x808021BC: nop

    return;
    // 0x808021BC: nop

;}
RECOMP_FUNC void sumole_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808021B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808021BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808021C0: jal         0x80106790
    // 0x808021C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808021C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808021C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808021CC: addiu       $a0, $zero, 0x247
    ctx->r4 = ADD32(0, 0X247);
    // 0x808021D0: jal         0x801084B0
    // 0x808021D4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x808021D4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808021D8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808021DC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808021E0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808021E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808021E8: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x808021EC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808021F0: jal         0x80086930
    // 0x808021F4: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    _chmolehill_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808021F4: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x808021F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808021FC: jal         0x80108944
    // 0x80802200: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80108944(rdram, ctx);
        goto after_3;
    // 0x80802200: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80802204: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80802208: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8080220C: beql        $t9, $zero, L_8080222C
    if (ctx->r25 == 0) {
        // 0x80802210: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080222C;
    }
    goto skip_0;
    // 0x80802210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802214: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80802218: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080221C: addiu       $a1, $zero, 0x629
    ctx->r5 = ADD32(0, 0X629);
    // 0x80802220: jal         0x80103140
    // 0x80802224: lhu         $a2, 0x16($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X16);
    func_80103140(rdram, ctx);
        goto after_4;
    // 0x80802224: lhu         $a2, 0x16($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X16);
    after_4:
    // 0x80802228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080222C:
    // 0x8080222C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802230: jr          $ra
    // 0x80802234: nop

    return;
    // 0x80802234: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800484: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x80800488: beql        $t6, $zero, L_8080049C
    if (ctx->r14 == 0) {
        // 0x8080048C: lh          $t7, 0x4($a0)
        ctx->r15 = MEM_H(ctx->r4, 0X4);
            goto L_8080049C;
    }
    goto skip_0;
    // 0x8080048C: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    skip_0:
    // 0x80800490: jr          $ra
    // 0x80800494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800498: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
L_8080049C:
    // 0x8080049C: beq         $a1, $t7, L_808004B0
    if (ctx->r5 == ctx->r15) {
        // 0x808004A0: nop
    
            goto L_808004B0;
    }
    // 0x808004A0: nop

    // 0x808004A4: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x808004A8: bnel        $a1, $t8, L_808004BC
    if (ctx->r5 != ctx->r24) {
        // 0x808004AC: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_808004BC;
    }
    goto skip_1;
    // 0x808004AC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_808004B0:
    // 0x808004B0: jr          $ra
    // 0x808004B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808004B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004B8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_808004BC:
    // 0x808004BC: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x808004C0: sh          $a1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r5;
    // 0x808004C4: beq         $v0, $at, L_808004D8
    if (ctx->r2 == ctx->r1) {
        // 0x808004C8: addiu       $t9, $zero, 0x67
        ctx->r25 = ADD32(0, 0X67);
            goto L_808004D8;
    }
    // 0x808004C8: addiu       $t9, $zero, 0x67
    ctx->r25 = ADD32(0, 0X67);
    // 0x808004CC: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x808004D0: bne         $v0, $at, L_808004E0
    if (ctx->r2 != ctx->r1) {
        // 0x808004D4: addiu       $t0, $zero, 0x65
        ctx->r8 = ADD32(0, 0X65);
            goto L_808004E0;
    }
    // 0x808004D4: addiu       $t0, $zero, 0x65
    ctx->r8 = ADD32(0, 0X65);
L_808004D8:
    // 0x808004D8: b           L_808004E4
    // 0x808004DC: sb          $t9, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r25;
        goto L_808004E4;
    // 0x808004DC: sb          $t9, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r25;
L_808004E0:
    // 0x808004E0: sb          $t0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r8;
L_808004E4:
    // 0x808004E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004E8: jr          $ra
    // 0x808004EC: nop

    return;
    // 0x808004EC: nop

;}
RECOMP_FUNC void func_80117A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117A08: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80117A0C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80117A10: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x80117A14: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x80117A18: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
    // 0x80117A1C: or          $t8, $a3, $zero
    ctx->r24 = ctx->r7 | 0;
    // 0x80117A20: addiu       $t2, $t2, 0x670C
    ctx->r10 = ADD32(ctx->r10, 0X670C);
    // 0x80117A24: sw          $ra, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r31;
    // 0x80117A28: sll         $v0, $t9, 1
    ctx->r2 = S32(ctx->r25 << 1);
    // 0x80117A2C: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80117A30: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x80117A34: addu        $t1, $t2, $t0
    ctx->r9 = ADD32(ctx->r10, ctx->r8);
    // 0x80117A38: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80117A3C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80117A40: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x80117A44: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
L_80117A48:
    // 0x80117A48: sltu        $at, $s5, $t9
    ctx->r1 = ctx->r21 < ctx->r25 ? 1 : 0;
L_80117A4C:
    // 0x80117A4C: beql        $at, $zero, L_80117A60
    if (ctx->r1 == 0) {
        // 0x80117A50: and         $v0, $s6, $t4
        ctx->r2 = ctx->r22 & ctx->r12;
            goto L_80117A60;
    }
    goto skip_0;
    // 0x80117A50: and         $v0, $s6, $t4
    ctx->r2 = ctx->r22 & ctx->r12;
    skip_0:
    // 0x80117A54: jal         0x80116F30
    // 0x80117A58: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_80116F30(rdram, ctx);
        goto after_0;
    // 0x80117A58: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80117A5C: and         $v0, $s6, $t4
    ctx->r2 = ctx->r22 & ctx->r12;
L_80117A60:
    // 0x80117A60: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80117A64: addu        $t6, $s1, $v0
    ctx->r14 = ADD32(ctx->r17, ctx->r2);
    // 0x80117A68: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80117A6C: slti        $at, $t7, 0x11
    ctx->r1 = SIGNED(ctx->r15) < 0X11 ? 1 : 0;
    // 0x80117A70: bnel        $at, $zero, L_80117AC8
    if (ctx->r1 != 0) {
        // 0x80117A74: lbu         $v0, 0x1($t6)
        ctx->r2 = MEM_BU(ctx->r14, 0X1);
            goto L_80117AC8;
    }
    goto skip_1;
    // 0x80117A74: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
    skip_1:
    // 0x80117A78: lb          $v1, 0x1($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X1);
L_80117A7C:
    // 0x80117A7C: addi        $t7, $t7, -0x10
    ctx->r15 = ADD32(ctx->r15, -0X10);
    // 0x80117A80: sub         $s5, $s5, $v1
    ctx->r21 = SUB32(ctx->r21, ctx->r3);
    // 0x80117A84: sltu        $at, $s5, $t7
    ctx->r1 = ctx->r21 < ctx->r15 ? 1 : 0;
    // 0x80117A88: beq         $at, $zero, L_80117A98
    if (ctx->r1 == 0) {
        // 0x80117A8C: srlv        $s6, $s6, $v1
        ctx->r22 = S32(U32(ctx->r22) >> (ctx->r3 & 31));
            goto L_80117A98;
    }
    // 0x80117A8C: srlv        $s6, $s6, $v1
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r3 & 31));
    // 0x80117A90: jal         0x80116F30
    // 0x80117A94: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80116F30(rdram, ctx);
        goto after_1;
    // 0x80117A94: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
L_80117A98:
    // 0x80117A98: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    // 0x80117A9C: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80117AA0: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x80117AA4: lw          $t0, 0x4($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X4);
    // 0x80117AA8: and         $t1, $t1, $s6
    ctx->r9 = ctx->r9 & ctx->r22;
    // 0x80117AAC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80117AB0: add         $t6, $t0, $t1
    ctx->r14 = ADD32(ctx->r8, ctx->r9);
    // 0x80117AB4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80117AB8: sltiu       $at, $t7, 0x11
    ctx->r1 = ctx->r15 < 0X11 ? 1 : 0;
    // 0x80117ABC: beql        $at, $zero, L_80117A7C
    if (ctx->r1 == 0) {
        // 0x80117AC0: lb          $v1, 0x1($t6)
        ctx->r3 = MEM_B(ctx->r14, 0X1);
            goto L_80117A7C;
    }
    goto skip_2;
    // 0x80117AC0: lb          $v1, 0x1($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X1);
    skip_2:
    // 0x80117AC4: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
L_80117AC8:
    // 0x80117AC8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80117ACC: srlv        $s6, $s6, $v0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r2 & 31));
    // 0x80117AD0: bne         $t7, $at, L_80117AE8
    if (ctx->r15 != ctx->r1) {
        // 0x80117AD4: sub         $s5, $s5, $v0
        ctx->r21 = SUB32(ctx->r21, ctx->r2);
            goto L_80117AE8;
    }
    // 0x80117AD4: sub         $s5, $s5, $v0
    ctx->r21 = SUB32(ctx->r21, ctx->r2);
    // 0x80117AD8: lhu         $v0, 0x4($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X4);
    // 0x80117ADC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80117AE0: j           L_80117A48
    // 0x80117AE4: sb          $v0, -0x1($s7)
    MEM_B(-0X1, ctx->r23) = ctx->r2;
        goto L_80117A48;
    // 0x80117AE4: sb          $v0, -0x1($s7)
    MEM_B(-0X1, ctx->r23) = ctx->r2;
L_80117AE8:
    // 0x80117AE8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80117AEC: beq         $t7, $at, L_80117C40
    if (ctx->r15 == ctx->r1) {
        // 0x80117AF0: sltu        $at, $s5, $t7
        ctx->r1 = ctx->r21 < ctx->r15 ? 1 : 0;
            goto L_80117C40;
    }
    // 0x80117AF0: sltu        $at, $s5, $t7
    ctx->r1 = ctx->r21 < ctx->r15 ? 1 : 0;
    // 0x80117AF4: beql        $at, $zero, L_80117B08
    if (ctx->r1 == 0) {
        // 0x80117AF8: sll         $v0, $t7, 1
        ctx->r2 = S32(ctx->r15 << 1);
            goto L_80117B08;
    }
    goto skip_3;
    // 0x80117AF8: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    skip_3:
    // 0x80117AFC: jal         0x80116F30
    // 0x80117B00: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80116F30(rdram, ctx);
        goto after_2;
    // 0x80117B00: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x80117B04: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
L_80117B08:
    // 0x80117B08: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80117B0C: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x80117B10: lhu         $t0, 0x4($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X4);
    // 0x80117B14: sub         $s5, $s5, $t7
    ctx->r21 = SUB32(ctx->r21, ctx->r15);
    // 0x80117B18: sltu        $at, $s5, $t8
    ctx->r1 = ctx->r21 < ctx->r24 ? 1 : 0;
    // 0x80117B1C: and         $t1, $t1, $s6
    ctx->r9 = ctx->r9 & ctx->r22;
    // 0x80117B20: srlv        $s6, $s6, $t7
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r15 & 31));
    // 0x80117B24: beq         $at, $zero, L_80117B34
    if (ctx->r1 == 0) {
        // 0x80117B28: addu        $t5, $t0, $t1
        ctx->r13 = ADD32(ctx->r8, ctx->r9);
            goto L_80117B34;
    }
    // 0x80117B28: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x80117B2C: jal         0x80116F30
    // 0x80117B30: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80116F30(rdram, ctx);
        goto after_3;
    // 0x80117B30: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_3:
L_80117B34:
    // 0x80117B34: and         $v0, $t3, $s6
    ctx->r2 = ctx->r11 & ctx->r22;
    // 0x80117B38: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80117B3C: addu        $t6, $s0, $v0
    ctx->r14 = ADD32(ctx->r16, ctx->r2);
    // 0x80117B40: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80117B44: slti        $at, $t7, 0x11
    ctx->r1 = SIGNED(ctx->r15) < 0X11 ? 1 : 0;
    // 0x80117B48: bnel        $at, $zero, L_80117BA0
    if (ctx->r1 != 0) {
        // 0x80117B4C: lbu         $v0, 0x1($t6)
        ctx->r2 = MEM_BU(ctx->r14, 0X1);
            goto L_80117BA0;
    }
    goto skip_4;
    // 0x80117B4C: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
    skip_4:
    // 0x80117B50: lbu         $t0, 0x1($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X1);
L_80117B54:
    // 0x80117B54: addi        $t7, $t7, -0x10
    ctx->r15 = ADD32(ctx->r15, -0X10);
    // 0x80117B58: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x80117B5C: sltu        $at, $s5, $t7
    ctx->r1 = ctx->r21 < ctx->r15 ? 1 : 0;
    // 0x80117B60: beq         $at, $zero, L_80117B70
    if (ctx->r1 == 0) {
        // 0x80117B64: srlv        $s6, $s6, $t0
        ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
            goto L_80117B70;
    }
    // 0x80117B64: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x80117B68: jal         0x80116F30
    // 0x80117B6C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80116F30(rdram, ctx);
        goto after_4;
    // 0x80117B6C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
L_80117B70:
    // 0x80117B70: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    // 0x80117B74: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80117B78: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x80117B7C: lw          $t0, 0x4($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X4);
    // 0x80117B80: and         $t1, $t1, $s6
    ctx->r9 = ctx->r9 & ctx->r22;
    // 0x80117B84: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80117B88: addu        $t6, $t0, $t1
    ctx->r14 = ADD32(ctx->r8, ctx->r9);
    // 0x80117B8C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80117B90: sltiu       $at, $t7, 0x11
    ctx->r1 = ctx->r15 < 0X11 ? 1 : 0;
    // 0x80117B94: beql        $at, $zero, L_80117B54
    if (ctx->r1 == 0) {
        // 0x80117B98: lbu         $t0, 0x1($t6)
        ctx->r8 = MEM_BU(ctx->r14, 0X1);
            goto L_80117B54;
    }
    goto skip_5;
    // 0x80117B98: lbu         $t0, 0x1($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X1);
    skip_5:
    // 0x80117B9C: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
L_80117BA0:
    // 0x80117BA0: sub         $s5, $s5, $v0
    ctx->r21 = SUB32(ctx->r21, ctx->r2);
    // 0x80117BA4: sltu        $at, $s5, $t7
    ctx->r1 = ctx->r21 < ctx->r15 ? 1 : 0;
    // 0x80117BA8: beq         $at, $zero, L_80117BB8
    if (ctx->r1 == 0) {
        // 0x80117BAC: srlv        $s6, $s6, $v0
        ctx->r22 = S32(U32(ctx->r22) >> (ctx->r2 & 31));
            goto L_80117BB8;
    }
    // 0x80117BAC: srlv        $s6, $s6, $v0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r2 & 31));
    // 0x80117BB0: jal         0x80116F30
    // 0x80117BB4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80116F30(rdram, ctx);
        goto after_5;
    // 0x80117BB4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_5:
L_80117BB8:
    // 0x80117BB8: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    // 0x80117BBC: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80117BC0: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x80117BC4: lhu         $v1, 0x4($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X4);
    // 0x80117BC8: sub         $s5, $s5, $t7
    ctx->r21 = SUB32(ctx->r21, ctx->r15);
    // 0x80117BCC: and         $t1, $t1, $s6
    ctx->r9 = ctx->r9 & ctx->r22;
    // 0x80117BD0: sub         $t0, $s7, $v1
    ctx->r8 = SUB32(ctx->r23, ctx->r3);
    // 0x80117BD4: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80117BD8: andi        $t1, $t5, 0x3
    ctx->r9 = ctx->r13 & 0X3;
    // 0x80117BDC: beq         $t1, $zero, L_80117C08
    if (ctx->r9 == 0) {
        // 0x80117BE0: srlv        $s6, $s6, $t7
        ctx->r22 = S32(U32(ctx->r22) >> (ctx->r15 & 31));
            goto L_80117C08;
    }
    // 0x80117BE0: srlv        $s6, $s6, $t7
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r15 & 31));
    // 0x80117BE4: sub         $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
L_80117BE8:
    // 0x80117BE8: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80117BEC: addi        $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80117BF0: addi        $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80117BF4: addi        $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80117BF8: bne         $t1, $zero, L_80117BE8
    if (ctx->r9 != 0) {
        // 0x80117BFC: sb          $v0, -0x1($s7)
        MEM_B(-0X1, ctx->r23) = ctx->r2;
            goto L_80117BE8;
    }
    // 0x80117BFC: sb          $v0, -0x1($s7)
    MEM_B(-0X1, ctx->r23) = ctx->r2;
    // 0x80117C00: beql        $t5, $zero, L_80117A4C
    if (ctx->r13 == 0) {
        // 0x80117C04: sltu        $at, $s5, $t9
        ctx->r1 = ctx->r21 < ctx->r25 ? 1 : 0;
            goto L_80117A4C;
    }
    goto skip_6;
    // 0x80117C04: sltu        $at, $s5, $t9
    ctx->r1 = ctx->r21 < ctx->r25 ? 1 : 0;
    skip_6:
L_80117C08:
    // 0x80117C08: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80117C0C: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
    // 0x80117C10: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80117C14: sb          $v0, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r2;
    // 0x80117C18: lbu         $v1, -0x3($t0)
    ctx->r3 = MEM_BU(ctx->r8, -0X3);
    // 0x80117C1C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80117C20: sb          $v1, -0x3($s7)
    MEM_B(-0X3, ctx->r23) = ctx->r3;
    // 0x80117C24: lbu         $v0, -0x2($t0)
    ctx->r2 = MEM_BU(ctx->r8, -0X2);
    // 0x80117C28: sb          $v0, -0x2($s7)
    MEM_B(-0X2, ctx->r23) = ctx->r2;
    // 0x80117C2C: lbu         $v1, -0x1($t0)
    ctx->r3 = MEM_BU(ctx->r8, -0X1);
    // 0x80117C30: bne         $t5, $zero, L_80117C08
    if (ctx->r13 != 0) {
        // 0x80117C34: sb          $v1, -0x1($s7)
        MEM_B(-0X1, ctx->r23) = ctx->r3;
            goto L_80117C08;
    }
    // 0x80117C34: sb          $v1, -0x1($s7)
    MEM_B(-0X1, ctx->r23) = ctx->r3;
    // 0x80117C38: j           L_80117A48
    // 0x80117C3C: nop

        goto L_80117A48;
    // 0x80117C3C: nop

L_80117C40:
    // 0x80117C40: lw          $ra, 0x8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8);
    // 0x80117C44: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x80117C48: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x80117C4C: jr          $ra
    // 0x80117C50: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80117C50: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void gcdialogexec_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801CEC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80801CF0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80801CF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801CF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801CFC: jal         0x808011A4
    // 0x80801D00: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_808011A4_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x80801D00: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80801D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D0C: jr          $ra
    // 0x80801D10: nop

    return;
    // 0x80801D10: nop

;}
RECOMP_FUNC void func_800BD2D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD2D0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800BD2D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BD2D8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800BD2DC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800BD2E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800BD2E4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800BD2E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BD2EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800BD2F0: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x800BD2F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BD2F8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800BD2FC: bnel        $v0, $at, L_800BD448
    if (ctx->r2 != ctx->r1) {
        // 0x800BD300: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800BD448;
    }
    goto skip_0;
    // 0x800BD300: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x800BD304: lbu         $a0, 0x6($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X6);
    // 0x800BD308: jal         0x80015F84
    // 0x800BD30C: sw          $a0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r4;
    func_80015F84(rdram, ctx);
        goto after_0;
    // 0x800BD30C: sw          $a0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BD310: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800BD314: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x800BD318: jal         0x80015F28
    // 0x800BD31C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80015F28(rdram, ctx);
        goto after_1;
    // 0x800BD31C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_1:
    // 0x800BD320: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x800BD324: jal         0x80015FFC
    // 0x800BD328: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_80015FFC(rdram, ctx);
        goto after_2;
    // 0x800BD328: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_2:
    // 0x800BD32C: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x800BD330: jal         0x80015E80
    // 0x800BD334: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80015E80(rdram, ctx);
        goto after_3;
    // 0x800BD334: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x800BD338: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800BD33C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BD340: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x800BD344: addiu       $s5, $sp, 0x80
    ctx->r21 = ADD32(ctx->r29, 0X80);
L_800BD348:
    // 0x800BD348: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BD34C: jal         0x800BCCC0
    // 0x800BD350: lbu         $a1, 0x8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X8);
    static_16_800BCCC0(rdram, ctx);
        goto after_4;
    // 0x800BD350: lbu         $a1, 0x8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X8);
    after_4:
    // 0x800BD354: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800BD358: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800BD35C: addu        $t7, $v0, $s2
    ctx->r15 = ADD32(ctx->r2, ctx->r18);
    // 0x800BD360: beq         $t6, $zero, L_800BD370
    if (ctx->r14 == 0) {
        // 0x800BD364: nop
    
            goto L_800BD370;
    }
    // 0x800BD364: nop

    // 0x800BD368: b           L_800BD370
    // 0x800BD36C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_800BD370;
    // 0x800BD36C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800BD370:
    // 0x800BD370: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x800BD374: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x800BD378: xor         $t9, $s1, $t8
    ctx->r25 = ctx->r17 ^ ctx->r24;
    // 0x800BD37C: beq         $t9, $zero, L_800BD418
    if (ctx->r25 == 0) {
        // 0x800BD380: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800BD418;
    }
    // 0x800BD380: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800BD384: lbu         $t0, 0x8($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X8);
    // 0x800BD388: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BD38C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800BD390: sb          $t1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r9;
    // 0x800BD394: lbu         $t3, 0x4($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X4);
    // 0x800BD398: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800BD39C: div         $zero, $t2, $t3
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r11)));
    // 0x800BD3A0: mfhi        $t4
    ctx->r12 = hi;
    // 0x800BD3A4: sb          $t4, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r12;
    // 0x800BD3A8: bne         $t3, $zero, L_800BD3B4
    if (ctx->r11 != 0) {
        // 0x800BD3AC: nop
    
            goto L_800BD3B4;
    }
    // 0x800BD3AC: nop

    // 0x800BD3B0: break       7
    do_break(2148258736);
L_800BD3B4:
    // 0x800BD3B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD3B8: bne         $t3, $at, L_800BD3CC
    if (ctx->r11 != ctx->r1) {
        // 0x800BD3BC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD3CC;
    }
    // 0x800BD3BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD3C0: bne         $t2, $at, L_800BD3CC
    if (ctx->r10 != ctx->r1) {
        // 0x800BD3C4: nop
    
            goto L_800BD3CC;
    }
    // 0x800BD3C4: nop

    // 0x800BD3C8: break       6
    do_break(2148258760);
L_800BD3CC:
    // 0x800BD3CC: andi        $a1, $t4, 0xFF
    ctx->r5 = ctx->r12 & 0XFF;
    // 0x800BD3D0: jal         0x800BCCC0
    // 0x800BD3D4: nop

    static_16_800BCCC0(rdram, ctx);
        goto after_5;
    // 0x800BD3D4: nop

    after_5:
    // 0x800BD3D8: addu        $v1, $v0, $s2
    ctx->r3 = ADD32(ctx->r2, ctx->r18);
    // 0x800BD3DC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800BD3E0: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800BD3E4: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800BD3E8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800BD3EC: srl         $t7, $a0, 1
    ctx->r15 = S32(U32(ctx->r4) >> 1);
    // 0x800BD3F0: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800BD3F4: xor         $t8, $t6, $t7
    ctx->r24 = ctx->r14 ^ ctx->r15;
    // 0x800BD3F8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BD3FC: xor         $t0, $t9, $a0
    ctx->r8 = ctx->r25 ^ ctx->r4;
    // 0x800BD400: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800BD404: lbu         $t3, 0x3($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X3);
    // 0x800BD408: andi        $t2, $s1, 0x1
    ctx->r10 = ctx->r17 & 0X1;
    // 0x800BD40C: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x800BD410: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800BD414: sb          $t5, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r13;
L_800BD418:
    // 0x800BD418: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800BD41C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BD420: bne         $s3, $s5, L_800BD348
    if (ctx->r19 != ctx->r21) {
        // 0x800BD424: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800BD348;
    }
    // 0x800BD424: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800BD428: jal         0x800BCCD8
    // 0x800BD42C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    static_16_800BCCD8(rdram, ctx);
        goto after_6;
    // 0x800BD42C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x800BD430: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x800BD434: jal         0x80016068
    // 0x800BD438: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80016068(rdram, ctx);
        goto after_7;
    // 0x800BD438: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x800BD43C: b           L_800BD540
    // 0x800BD440: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
        goto L_800BD540;
    // 0x800BD440: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800BD444: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800BD448:
    // 0x800BD448: bne         $v0, $at, L_800BD53C
    if (ctx->r2 != ctx->r1) {
        // 0x800BD44C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800BD53C;
    }
    // 0x800BD44C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BD450: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800BD454: addiu       $s5, $zero, 0xE
    ctx->r21 = ADD32(0, 0XE);
L_800BD458:
    // 0x800BD458: lbu         $t6, 0x16($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X16);
    // 0x800BD45C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BD460: sll         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18 << 2);
    // 0x800BD464: beql        $t6, $zero, L_800BD534
    if (ctx->r14 == 0) {
        // 0x800BD468: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800BD534;
    }
    goto skip_1;
    // 0x800BD468: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x800BD46C: jal         0x800BCCC0
    // 0x800BD470: lbu         $a1, 0x8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X8);
    static_16_800BCCC0(rdram, ctx);
        goto after_8;
    // 0x800BD470: lbu         $a1, 0x8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X8);
    after_8:
    // 0x800BD474: lbu         $t9, 0x16($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X16);
    // 0x800BD478: addu        $t7, $v0, $s1
    ctx->r15 = ADD32(ctx->r2, ctx->r17);
    // 0x800BD47C: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x800BD480: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800BD484: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800BD488: andi        $t8, $s3, 0x1
    ctx->r24 = ctx->r19 & 0X1;
    // 0x800BD48C: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x800BD490: bne         $t1, $zero, L_800BD530
    if (ctx->r9 != 0) {
        // 0x800BD494: sb          $t0, 0x16($s0)
        MEM_B(0X16, ctx->r16) = ctx->r8;
            goto L_800BD530;
    }
    // 0x800BD494: sb          $t0, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r8;
    // 0x800BD498: lbu         $t3, 0x8($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X8);
    // 0x800BD49C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800BD4A0: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x800BD4A4: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800BD4A8: lbu         $t5, 0x4($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X4);
    // 0x800BD4AC: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x800BD4B0: div         $zero, $t4, $t5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r13)));
    // 0x800BD4B4: mfhi        $t6
    ctx->r14 = hi;
    // 0x800BD4B8: sb          $t6, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r14;
    // 0x800BD4BC: bne         $t5, $zero, L_800BD4C8
    if (ctx->r13 != 0) {
        // 0x800BD4C0: nop
    
            goto L_800BD4C8;
    }
    // 0x800BD4C0: nop

    // 0x800BD4C4: break       7
    do_break(2148259012);
L_800BD4C8:
    // 0x800BD4C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD4CC: bne         $t5, $at, L_800BD4E0
    if (ctx->r13 != ctx->r1) {
        // 0x800BD4D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD4E0;
    }
    // 0x800BD4D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD4D4: bne         $t4, $at, L_800BD4E0
    if (ctx->r12 != ctx->r1) {
        // 0x800BD4D8: nop
    
            goto L_800BD4E0;
    }
    // 0x800BD4D8: nop

    // 0x800BD4DC: break       6
    do_break(2148259036);
L_800BD4E0:
    // 0x800BD4E0: andi        $a1, $t6, 0xFF
    ctx->r5 = ctx->r14 & 0XFF;
    // 0x800BD4E4: jal         0x800BCCC0
    // 0x800BD4E8: nop

    static_16_800BCCC0(rdram, ctx);
        goto after_9;
    // 0x800BD4E8: nop

    after_9:
    // 0x800BD4EC: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x800BD4F0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800BD4F4: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800BD4F8: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800BD4FC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800BD500: srl         $t9, $a0, 1
    ctx->r25 = S32(U32(ctx->r4) >> 1);
    // 0x800BD504: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800BD508: xor         $t0, $t8, $t9
    ctx->r8 = ctx->r24 ^ ctx->r25;
    // 0x800BD50C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800BD510: xor         $t3, $t1, $a0
    ctx->r11 = ctx->r9 ^ ctx->r4;
    // 0x800BD514: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800BD518: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x800BD51C: xori        $t4, $s3, 0x1
    ctx->r12 = ctx->r19 ^ 0X1;
    // 0x800BD520: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800BD524: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x800BD528: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800BD52C: sb          $t8, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r24;
L_800BD530:
    // 0x800BD530: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800BD534:
    // 0x800BD534: bne         $s2, $s5, L_800BD458
    if (ctx->r18 != ctx->r21) {
        // 0x800BD538: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800BD458;
    }
    // 0x800BD538: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800BD53C:
    // 0x800BD53C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
L_800BD540:
    // 0x800BD540: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BD544: sw          $t0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r8;
    // 0x800BD548: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD54C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800BD550: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800BD554: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800BD558: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD55C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800BD560: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800BD564: jr          $ra
    // 0x800BD568: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800BD568: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void _bsjump_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832A0: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x800832A0);
    return;
    // 0x800832A4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void chappearfx_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800710: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800714: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80800718: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8080071C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800720: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800724: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800728: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8080072C: jal         0x80106790
    // 0x80800730: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800730: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800734: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800738: addiu       $a0, $zero, 0x3D9
    ctx->r4 = ADD32(0, 0X3D9);
    // 0x8080073C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80800740: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800744: jal         0x80108528
    // 0x80800748: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    func_80108528(rdram, ctx);
        goto after_1;
    // 0x80800748: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x8080074C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800750: jal         0x80103EAC
    // 0x80800754: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_80103EAC(rdram, ctx);
        goto after_2;
    // 0x80800754: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x80800758: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080075C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800760: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800764: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80800768: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8080076C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800770: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800774: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800778: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080077C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80800780: nop

    // 0x80800784: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80800788: lh          $t9, 0x8A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8A);
    // 0x8080078C: lwc1        $f8, 0x38($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X38);
    // 0x80800790: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800794: nop

    // 0x80800798: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080079C: mul.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808007A0: jal         0x800F0E00
    // 0x808007A4: nop

    func_800F0E00(rdram, ctx);
        goto after_3;
    // 0x808007A4: nop

    after_3:
    // 0x808007A8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808007AC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x808007B0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808007B4: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x808007B8: nop

    // 0x808007BC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x808007C0: lh          $t3, 0x88($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X88);
    // 0x808007C4: lwc1        $f4, 0x38($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X38);
    // 0x808007C8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x808007CC: nop

    // 0x808007D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808007D4: mul.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808007D8: jal         0x800F13F0
    // 0x808007DC: nop

    func_800F13F0(rdram, ctx);
        goto after_4;
    // 0x808007DC: nop

    after_4:
    // 0x808007E0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808007E4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x808007E8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808007EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007F0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x808007F4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808007F8: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x808007FC: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80800800: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80800804: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80800808: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8080080C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800810: jal         0x800F10B4
    // 0x80800814: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800814: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_5:
    // 0x80800818: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800824: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80800828: nop

    // 0x8080082C: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x80800830: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80800834: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80800838: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    // 0x8080083C: jal         0x80100074
    // 0x80800840: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80100074(rdram, ctx);
        goto after_6;
    // 0x80800840: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_6:
    // 0x80800844: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800848: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080084C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80800850: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800854: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80800858: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8080085C: addiu       $t8, $v1, 0x190
    ctx->r24 = ADD32(ctx->r3, 0X190);
    // 0x80800860: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80800864: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
    // 0x80800868: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x8080086C: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x80800870: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80800874: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800878: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8080087C: addiu       $a0, $v0, 0x14
    ctx->r4 = ADD32(ctx->r2, 0X14);
    // 0x80800880: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    // 0x80800884: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80800888: sb          $t3, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r11;
    // 0x8080088C: sh          $t1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r9;
    // 0x80800890: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80800894: jal         0x8008A020
    // 0x80800898: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800898: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    after_7:
    // 0x8080089C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x808008A0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x808008A4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1188, 0X974) << 16);
    // 0x808008A8: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x808008AC: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x808008B0: sh          $v0, 0xE($t4)
    MEM_H(0XE, ctx->r12) = ctx->r2;
    // 0x808008B4: lw          $a1, 0x974($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1188, 0X974));
    // 0x808008B8: jal         0x80102FDC
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_8;
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808008C0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808008CC: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x808008D0: beq         $t7, $zero, L_808008E0
    if (ctx->r15 == 0) {
        // 0x808008D4: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1188, 0X9D8) << 16);
            goto L_808008E0;
    }
    // 0x808008D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1188, 0X9D8) << 16);
    // 0x808008D8: jal         0x80089D18
    // 0x808008DC: addiu       $a2, $a2, 0x9D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1188, 0X9D8));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x808008DC: addiu       $a2, $a2, 0x9D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1188, 0X9D8));
    after_9:
L_808008E0:
    // 0x808008E0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x808008E4: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x808008E8: beql        $t8, $zero, L_808008FC
    if (ctx->r24 == 0) {
        // 0x808008EC: lw          $t0, 0x4C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X4C);
            goto L_808008FC;
    }
    goto skip_0;
    // 0x808008EC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x808008F0: jal         0x800FC660
    // 0x808008F4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_10;
    // 0x808008F4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_10:
    // 0x808008F8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_808008FC:
    // 0x808008FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800900: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80800904: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x80800908: beq         $t1, $zero, L_80800918
    if (ctx->r9 == 0) {
        // 0x8080090C: addiu       $a0, $a0, 0x14
        ctx->r4 = ADD32(ctx->r4, 0X14);
            goto L_80800918;
    }
    // 0x8080090C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80800910: jal         0x8008A028
    // 0x80800914: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800914: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    after_11:
L_80800918:
    // 0x80800918: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8080091C: andi        $t4, $t2, 0x20
    ctx->r12 = ctx->r10 & 0X20;
    // 0x80800920: beql        $t4, $zero, L_80800934
    if (ctx->r12 == 0) {
        // 0x80800924: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800934;
    }
    goto skip_1;
    // 0x80800924: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800928: jal         0x80089CA0
    // 0x8080092C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x8080092C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_12:
    // 0x80800930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800934:
    // 0x80800934: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800938: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080093C: jr          $ra
    // 0x80800940: nop

    return;
    // 0x80800940: nop

    // 0x80800944: nop

    // 0x80800948: nop

    // 0x8080094C: nop

;}
RECOMP_FUNC void _bstimeout_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F10: syscall     98
    recomp_syscall_handler(rdram, ctx, 0x80083F10);
    return;
    // 0x80083F14: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chgoldsnakehead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085960: syscall     183
    recomp_syscall_handler(rdram, ctx, 0x80085960);
    return;
    // 0x80085964: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gspropctrl_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x808000BC: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x808000C0: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x808000C4: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x808000C8: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x808000CC: jr          $ra
    // 0x808000D0: sh          $t8, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r24;
    return;
    // 0x808000D0: sh          $t8, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void bsblongleg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004DC: jal         0x8008CABC
    // 0x808004E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808004E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808004E8: jal         0x808000C8
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C8_bsblongleg(rdram, ctx);
        goto after_1;
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004F8: jal         0x8009D2F0
    // 0x808004FC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_2;
    // 0x808004FC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_2:
    // 0x80800500: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800508: beq         $v0, $zero, L_80800520
    if (ctx->r2 == 0) {
        // 0x8080050C: nop
    
            goto L_80800520;
    }
    // 0x8080050C: nop

    // 0x80800510: beq         $v0, $at, L_80800540
    if (ctx->r2 == ctx->r1) {
        // 0x80800514: nop
    
            goto L_80800540;
    }
    // 0x80800514: nop

    // 0x80800518: b           L_80800558
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800558;
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800520:
    // 0x80800520: jal         0x8008B324
    // 0x80800524: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_3;
    // 0x80800524: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800528: beql        $v0, $zero, L_80800558
    if (ctx->r2 == 0) {
        // 0x8080052C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800558;
    }
    goto skip_0;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800530: jal         0x808002D8
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D8_bsblongleg(rdram, ctx);
        goto after_4;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800538: b           L_80800558
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800558;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800540:
    // 0x80800540: jal         0x8008B324
    // 0x80800544: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_5;
    // 0x80800544: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800548: beq         $v0, $zero, L_80800554
    if (ctx->r2 == 0) {
        // 0x8080054C: addiu       $t6, $zero, 0x26
        ctx->r14 = ADD32(0, 0X26);
            goto L_80800554;
    }
    // 0x8080054C: addiu       $t6, $zero, 0x26
    ctx->r14 = ADD32(0, 0X26);
    // 0x80800550: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800554:
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800558:
    // 0x80800558: jal         0x8009E5C8
    // 0x8080055C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x8080055C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800564: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080056C: jr          $ra
    // 0x80800570: nop

    return;
    // 0x80800570: nop

;}
RECOMP_FUNC void _baboost_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084590: syscall     115
    recomp_syscall_handler(rdram, ctx, 0x80084590);
    return;
    // 0x80084594: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gcnewoption_entrypoint_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B14: lbu         $t7, 0x1C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1C);
    // 0x80802B18: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80802B1C: jr          $ra
    // 0x80802B20: sb          $t8, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r24;
    return;
    // 0x80802B20: sb          $t8, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void _chcrusher_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A98: syscall     413
    recomp_syscall_handler(rdram, ctx, 0x80086A98);
    return;
    // 0x80086A9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
