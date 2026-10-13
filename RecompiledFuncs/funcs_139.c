#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsthrow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F00: syscall     97
    recomp_syscall_handler(rdram, ctx, 0x80083F00);
    return;
    // 0x80083F04: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800C8BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8BF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8BFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8C00: jal         0x800B2928
    // 0x800C8C04: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    vector_size(rdram, ctx);
        goto after_0;
    // 0x800C8C04: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    after_0:
    // 0x800C8C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8C10: jr          $ra
    // 0x800C8C14: nop

    return;
    // 0x800C8C14: nop

;}
RECOMP_FUNC void func_80800214_chfactoryprop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800218: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080021C: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800220: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800228: beq         $a1, $at, L_80800250
    if (ctx->r5 == ctx->r1) {
        // 0x8080022C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800250;
    }
    // 0x8080022C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800230: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x80800234: beq         $a1, $at, L_808002A0
    if (ctx->r5 == ctx->r1) {
        // 0x80800238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A0;
    }
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800240: beq         $a1, $at, L_808002B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800244: addiu       $a0, $zero, 0x18C
        ctx->r4 = ADD32(0, 0X18C);
            goto L_808002B0;
    }
    // 0x80800244: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    // 0x80800248: b           L_80800310
    // 0x8080024C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800310;
    // 0x8080024C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800250:
    // 0x80800250: jal         0x80088840
    // 0x80800254: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80800254: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_0:
    // 0x80800258: bne         $v0, $zero, L_80800268
    if (ctx->r2 != 0) {
        // 0x8080025C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800268;
    }
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: b           L_80800310
    // 0x80800264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800310;
    // 0x80800264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800268:
    // 0x80800268: jal         0x80101FDC
    // 0x8080026C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x8080026C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800270: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800274: addiu       $at, $zero, 0x3B2
    ctx->r1 = ADD32(0, 0X3B2);
    // 0x80800278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080027C: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800280: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800284: bne         $t8, $at, L_8080030C
    if (ctx->r24 != ctx->r1) {
        // 0x80800288: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8080030C;
    }
    // 0x80800288: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080028C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800290: jal         0x80085708
    // 0x80800294: addiu       $a3, $zero, 0x2910
    ctx->r7 = ADD32(0, 0X2910);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800294: addiu       $a3, $zero, 0x2910
    ctx->r7 = ADD32(0, 0X2910);
    after_2:
    // 0x80800298: b           L_80800310
    // 0x8080029C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800310;
    // 0x8080029C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002A0:
    // 0x808002A0: jal         0x80101FDC
    // 0x808002A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808002A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808002A8: b           L_80800310
    // 0x808002AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800310;
    // 0x808002AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002B0:
    // 0x808002B0: sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // 0x808002B4: jal         0x800DA298
    // 0x808002B8: sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808002B8: sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
    after_4:
    // 0x808002BC: beql        $v0, $zero, L_808002FC
    if (ctx->r2 == 0) {
        // 0x808002C0: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_808002FC;
    }
    goto skip_0;
    // 0x808002C0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    skip_0:
    // 0x808002C4: jal         0x80088840
    // 0x808002C8: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x808002C8: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_5:
    // 0x808002CC: bnel        $v0, $zero, L_808002FC
    if (ctx->r2 != 0) {
        // 0x808002D0: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_808002FC;
    }
    goto skip_1;
    // 0x808002D0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    skip_1:
    // 0x808002D4: jal         0x80088848
    // 0x808002D8: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x808002D8: nop

    after_6:
    // 0x808002DC: bne         $v0, $zero, L_808002F8
    if (ctx->r2 != 0) {
        // 0x808002E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F8;
    }
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: jal         0x80101FDC
    // 0x808002E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808002E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808002EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002F0: b           L_8080030C
    // 0x808002F4: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
        goto L_8080030C;
    // 0x808002F4: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_808002F8:
    // 0x808002F8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
L_808002FC:
    // 0x808002FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800300: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800304: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80800308: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8080030C:
    // 0x8080030C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800310:
    // 0x80800310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800314: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800318: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080031C: jr          $ra
    // 0x80800320: nop

    return;
    // 0x80800320: nop

;}
RECOMP_FUNC void func_800FF000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF000: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FF004: addiu       $v0, $v0, 0x59C0
    ctx->r2 = ADD32(ctx->r2, 0X59C0);
    // 0x800FF008: sb          $a0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r4;
    // 0x800FF00C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FF010: lwc1        $f4, 0x6420($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6420);
    // 0x800FF014: jr          $ra
    // 0x800FF018: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x800FF018: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80800170_glrtc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800174: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800178: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080017C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800180: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800184: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800188: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8080018C: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x80800190: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800194: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800198: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080019C: jal         0x80031BF0
    // 0x808001A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _bcopy(rdram, ctx);
        goto after_0;
    // 0x808001A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x808001A4: lhu         $t7, 0x44($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X44);
    // 0x808001A8: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x808001AC: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x808001B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808001B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808001B8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x808001BC: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
    // 0x808001C0: sh          $t9, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r25;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: ori         $a1, $zero, 0xF800
    ctx->r5 = 0 | 0XF800;
    // 0x808001CC: sh          $t7, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r15;
    // 0x808001D0: jal         0x808002C8
    // 0x808001D4: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    func_808002C8_glrtc(rdram, ctx);
        goto after_1;
    // 0x808001D4: sh          $t0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r8;
    after_1:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x808002C8
    // 0x808001E0: addiu       $a1, $zero, 0x7C0
    ctx->r5 = ADD32(0, 0X7C0);
    func_808002C8_glrtc(rdram, ctx);
        goto after_2;
    // 0x808001E0: addiu       $a1, $zero, 0x7C0
    ctx->r5 = ADD32(0, 0X7C0);
    after_2:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x808002C8
    // 0x808001EC: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    func_808002C8_glrtc(rdram, ctx);
        goto after_3;
    // 0x808001EC: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_3:
    // 0x808001F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808001F4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808001F8: jal         0x80031BF0
    // 0x808001FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _bcopy(rdram, ctx);
        goto after_4;
    // 0x808001FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x80800200: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800204: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800208: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080020C: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x80800210: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80800214: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80800218:
    // 0x80800218: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8080021C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800220: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x80800224: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80800228: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x8080022C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80800230: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x80800234: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800238: srl         $t8, $t7, 2
    ctx->r24 = S32(U32(ctx->r15) >> 2);
    // 0x8080023C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x80800240: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80800244: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80800248: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8080024C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80800250: sh          $t2, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r10;
    // 0x80800254: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80800258: srl         $t4, $t3, 2
    ctx->r12 = S32(U32(ctx->r11) >> 2);
    // 0x8080025C: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x80800260: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80800264: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80800268: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8080026C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80800270: sh          $t8, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r24;
    // 0x80800274: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80800278: srl         $t0, $t9, 2
    ctx->r8 = S32(U32(ctx->r25) >> 2);
    // 0x8080027C: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80800280: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80800284: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80800288: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8080028C: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80800290: sh          $t4, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r12;
    // 0x80800294: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80800298: addu        $s1, $s1, $a0
    ctx->r17 = ADD32(ctx->r17, ctx->r4);
    // 0x8080029C: srl         $t6, $t5, 2
    ctx->r14 = S32(U32(ctx->r13) >> 2);
    // 0x808002A0: bne         $v1, $a1, L_80800218
    if (ctx->r3 != ctx->r5) {
        // 0x808002A4: sw          $t6, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r14;
            goto L_80800218;
    }
    // 0x808002A4: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x808002A8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x808002AC: sw          $s2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r18;
    // 0x808002B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808002B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808002BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002C0: jr          $ra
    // 0x808002C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808002C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _bareact_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F78: syscall     145
    recomp_syscall_handler(rdram, ctx, 0x80084F78);
    return;
    // 0x80084F7C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80803248_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803248: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080324C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803250: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803254: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80803258: jal         0x80106790
    // 0x8080325C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080325C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80803260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803268: jal         0x80100094
    // 0x8080326C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080326C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80803270: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80803274: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80803278: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8080327C: lw          $t6, 0x2C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X2C);
    // 0x80803280: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80803284: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80803288: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8080328C: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x80803290: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80803294: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80803298: sb          $t0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r8;
    // 0x8080329C: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    // 0x808032A0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808032A4: sb          $t1, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r9;
    // 0x808032A8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x808032AC: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x808032B0: lw          $t3, 0x2C($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X2C);
    // 0x808032B4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x808032B8: sw          $t4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r12;
    // 0x808032BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808032C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808032C4: jr          $ra
    // 0x808032C8: nop

    return;
    // 0x808032C8: nop

;}
RECOMP_FUNC void func_80800820_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800828: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1356, 0XAF4) << 16);
    // 0x8080082C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800830: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800834: addiu       $a2, $a2, 0xAF4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1356, 0XAF4));
    // 0x80800838: jal         0x80089D20
    // 0x8080083C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080083C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800848: jr          $ra
    // 0x8080084C: nop

    return;
    // 0x8080084C: nop

;}
RECOMP_FUNC void func_8080092C_chnutsnbolts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080092C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800930: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800934: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800938: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080093C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800940: jal         0x80100094
    // 0x80800944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800948: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800950: jal         0x80102424
    // 0x80800954: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800954: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800958: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8080095C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800960: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80800964: beq         $at, $zero, L_80800A74
    if (ctx->r1 == 0) {
        // 0x80800968: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800A74;
    }
    // 0x80800968: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080096C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1304, 0XC90) << 16);
    // 0x80800970: addu        $at, $at, $t7
    gpr jr_addend_80800978 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800974: lw          $t7, 0xC90($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1304, 0XC90));
    // 0x80800978: jr          $t7
    // 0x8080097C: nop

    switch (jr_addend_80800978 >> 2) {
        case 0: goto L_80800980; break;
        case 1: goto L_80800990; break;
        case 2: goto L_80800A74; break;
        case 3: goto L_808009A0; break;
        case 4: goto L_80800A74; break;
        case 5: goto L_80800A74; break;
        case 6: goto L_808009CC; break;
        case 7: goto L_808009F0; break;
        default: switch_error(__func__, 0x80800978, 0x80800C90);
    }
    // 0x8080097C: nop

L_80800980:
    // 0x80800980: lbu         $t8, 0x64($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X64);
    // 0x80800984: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80800988: b           L_80800A74
    // 0x8080098C: sb          $t9, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r25;
        goto L_80800A74;
    // 0x8080098C: sb          $t9, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r25;
L_80800990:
    // 0x80800990: lbu         $t1, 0x64($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X64);
    // 0x80800994: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80800998: b           L_80800A74
    // 0x8080099C: sb          $t2, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r10;
        goto L_80800A74;
    // 0x8080099C: sb          $t2, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r10;
L_808009A0:
    // 0x808009A0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x808009A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808009A8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808009AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009B0: jal         0x800DC178
    // 0x808009B4: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x808009B4: nop

    after_2:
    // 0x808009B8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x808009BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808009C0: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x808009C4: b           L_80800A74
    // 0x808009C8: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_80800A74;
    // 0x808009C8: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_808009CC:
    // 0x808009CC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808009D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808009D4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808009D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009DC: jal         0x800DC178
    // 0x808009E0: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808009E0: nop

    after_3:
    // 0x808009E4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x808009E8: b           L_80800A74
    // 0x808009EC: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
        goto L_80800A74;
    // 0x808009EC: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
L_808009F0:
    // 0x808009F0: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
    // 0x808009F4: lbu         $t2, 0x70($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X70);
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009FC: andi        $t6, $t5, 0xFC0F
    ctx->r14 = ctx->r13 & 0XFC0F;
    // 0x80800A00: sh          $t6, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r14;
    // 0x80800A04: lw          $t7, 0x70($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X70);
    // 0x80800A08: lbu         $t5, 0x71($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X71);
    // 0x80800A0C: andi        $t3, $t2, 0xFF01
    ctx->r11 = ctx->r10 & 0XFF01;
    // 0x80800A10: sll         $t8, $t7, 22
    ctx->r24 = S32(ctx->r15 << 22);
    // 0x80800A14: srl         $t9, $t8, 26
    ctx->r25 = S32(U32(ctx->r24) >> 26);
    // 0x80800A18: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x80800A1C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800A20: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x80800A24: sb          $t4, 0x70($s0)
    MEM_B(0X70, ctx->r16) = ctx->r12;
    // 0x80800A28: sb          $t6, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r14;
    // 0x80800A2C: lhu         $t8, 0x70($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X70);
    // 0x80800A30: lbu         $t2, 0x64($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X64);
    // 0x80800A34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800A38: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800A3C: andi        $t1, $t2, 0xFF7F
    ctx->r9 = ctx->r10 & 0XFF7F;
    // 0x80800A40: or          $t5, $t0, $t1
    ctx->r13 = ctx->r8 | ctx->r9;
    // 0x80800A44: andi        $t6, $t5, 0xFE
    ctx->r14 = ctx->r13 & 0XFE;
    // 0x80800A48: andi        $t4, $t8, 0x1
    ctx->r12 = ctx->r24 & 0X1;
    // 0x80800A4C: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80800A50: sb          $t5, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r13;
    // 0x80800A54: jal         0x80107070
    // 0x80800A58: sb          $t7, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r15;
    func_80107070(rdram, ctx);
        goto after_4;
    // 0x80800A58: sb          $t7, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r15;
    after_4:
    // 0x80800A5C: bnel        $v0, $zero, L_80800A78
    if (ctx->r2 != 0) {
        // 0x80800A60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A78;
    }
    goto skip_0;
    // 0x80800A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800A64: jal         0x8010A570
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800A6C: jal         0x80089CA8
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80800A74:
    // 0x80800A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A78:
    // 0x80800A78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A80: jr          $ra
    // 0x80800A84: nop

    return;
    // 0x80800A84: nop

;}
RECOMP_FUNC void idglowa_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800114: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x80800118: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8080011C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800120: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800124: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800130: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800134: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800138: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8080013C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2914, 0X270) << 16);
    // 0x80800140: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80800144: lwc1        $f10, 0x270($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2914, 0X270));
    // 0x80800148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080014C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800150: jal         0x808000E8
    // 0x80800154: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    func_808000E8_idglowa(rdram, ctx);
        goto after_0;
    // 0x80800154: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    after_0:
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080015C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void func_8008F904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F90C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F910: jal         0x800F54E4
    // 0x8008F914: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008F914: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008F918: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F91C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008F920: jal         0x800F49D4
    // 0x8008F924: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F49D4(rdram, ctx);
        goto after_1;
    // 0x8008F924: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8008F928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F92C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F930: jr          $ra
    // 0x8008F934: nop

    return;
    // 0x8008F934: nop

;}
RECOMP_FUNC void func_8080002C_ncbaspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x80800038: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080003C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800040: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80800044: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    // 0x80800048: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080004C: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x80800050: lw          $t9, 0x44($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X44);
    // 0x80800054: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
    // 0x80800058: lw          $t0, 0x44($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X44);
    // 0x8080005C: sw          $zero, 0x28($t0)
    MEM_W(0X28, ctx->r8) = 0;
    // 0x80800060: lw          $t1, 0x44($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X44);
    // 0x80800064: sb          $zero, 0x2C($t1)
    MEM_B(0X2C, ctx->r9) = 0;
    // 0x80800068: lw          $t2, 0x44($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X44);
    // 0x8080006C: sb          $zero, 0x2F($t2)
    MEM_B(0X2F, ctx->r10) = 0;
    // 0x80800070: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x80800074: lbu         $t3, 0x2F($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2F);
    // 0x80800078: sb          $t3, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r11;
    // 0x8080007C: lw          $a0, 0x44($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X44);
    // 0x80800080: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80800084: jal         0x800EFD24
    // 0x80800088: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80800088: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x8080008C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
    // 0x80800094: jal         0x800EFD24
    // 0x80800098: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800098: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8080009C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000A4: lw          $t4, 0x44($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X44);
    // 0x808000A8: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    // 0x808000AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void func_8008FA2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FA2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FA30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FA34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FA38: jal         0x800F54E4
    // 0x8008FA3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FA3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008FA40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FA44: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008FA48: jal         0x800F4B8C
    // 0x8008FA4C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F4B8C(rdram, ctx);
        goto after_1;
    // 0x8008FA4C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8008FA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FA54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FA58: jr          $ra
    // 0x8008FA5C: nop

    return;
    // 0x8008FA5C: nop

;}
RECOMP_FUNC void chdoormake_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006A8: jal         0x80100094
    // 0x808006AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006B0: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x808006B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006B8: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808006BC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808006C0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808006C4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x808006C8: nop

    // 0x808006CC: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    // 0x808006D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006D8: jr          $ra
    // 0x808006DC: nop

    return;
    // 0x808006DC: nop

;}
RECOMP_FUNC void func_808002E0_chboxingglove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808002E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808002F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808002F8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808002FC: jal         0x80106790
    // 0x80800300: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800300: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80800304: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800308: beq         $s2, $at, L_80800338
    if (ctx->r18 == ctx->r1) {
        // 0x8080030C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80800338;
    }
    // 0x8080030C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800310: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800314: beq         $s2, $at, L_8080037C
    if (ctx->r18 == ctx->r1) {
        // 0x80800318: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080037C;
    }
    // 0x80800318: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080031C: beq         $s2, $at, L_80800438
    if (ctx->r18 == ctx->r1) {
        // 0x80800320: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800438;
    }
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800328: beql        $s2, $at, L_808004A0
    if (ctx->r18 == ctx->r1) {
        // 0x8080032C: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_808004A0;
    }
    goto skip_0;
    // 0x8080032C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    skip_0:
    // 0x80800330: b           L_808004E4
    // 0x80800334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004E4;
    // 0x80800334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800338:
    // 0x80800338: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080033C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800340: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800344: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800348: jal         0x800DC178
    // 0x8080034C: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x8080034C: nop

    after_1:
    // 0x80800350: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x80102424
    // 0x8080035C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x8080035C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800364: jal         0x80101FDC
    // 0x80800368: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800368: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x8080036C: lbu         $t6, 0x65($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X65);
    // 0x80800370: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80800374: b           L_808004E0
    // 0x80800378: sb          $t7, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r15;
        goto L_808004E0;
    // 0x80800378: sb          $t7, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r15;
L_8080037C:
    // 0x8080037C: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800380: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800384: bgezl       $t0, L_808003F4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800388: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_808003F4;
    }
    goto skip_1;
    // 0x80800388: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_1:
    // 0x8080038C: jal         0x800F54E4
    // 0x80800390: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800390: nop

    after_4:
    // 0x80800394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800398: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8080039C: jal         0x8010D09C
    // 0x808003A0: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    func_8010D09C(rdram, ctx);
        goto after_5;
    // 0x808003A0: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_5:
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: jal         0x80800544
    // 0x808003AC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80800544_chboxingglove(rdram, ctx);
        goto after_6;
    // 0x808003AC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x808003B0: bnel        $v0, $zero, L_808003D8
    if (ctx->r2 != 0) {
        // 0x808003B4: lwc1        $f0, 0x40($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
            goto L_808003D8;
    }
    goto skip_2;
    // 0x808003B4: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    skip_2:
    // 0x808003B8: jal         0x8010D254
    // 0x808003BC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_8010D254(rdram, ctx);
        goto after_7;
    // 0x808003BC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_7:
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: jal         0x80800544
    // 0x808003C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80800544_chboxingglove(rdram, ctx);
        goto after_8;
    // 0x808003C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x808003CC: beql        $v0, $zero, L_808004E4
    if (ctx->r2 == 0) {
        // 0x808003D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808004E4;
    }
    goto skip_3;
    // 0x808003D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x808003D4: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
L_808003D8:
    // 0x808003D8: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x808003DC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x808003E0: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808003E4: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x808003E8: b           L_808003FC
    // 0x808003EC: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
        goto L_808003FC;
    // 0x808003EC: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x808003F0: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_808003F4:
    // 0x808003F4: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x808003F8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_808003FC:
    // 0x808003FC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800404: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80800410: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800414: jal         0x80102424
    // 0x80800418: swc1        $f6, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f6.u32l;
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800418: swc1        $f6, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f6.u32l;
    after_9:
    // 0x8080041C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800420: jal         0x80101FDC
    // 0x80800424: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x80800424: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_10:
    // 0x80800428: lbu         $t5, 0x65($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X65);
    // 0x8080042C: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80800430: b           L_808004E0
    // 0x80800434: sb          $t6, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r14;
        goto L_808004E0;
    // 0x80800434: sb          $t6, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r14;
L_80800438:
    // 0x80800438: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080043C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(944, 0X7A0) << 16);
    // 0x80800440: addiu       $a2, $a2, 0x7A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(944, 0X7A0));
    // 0x80800444: jal         0x80089D18
    // 0x80800448: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800448: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_11:
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: jal         0x80102424
    // 0x80800454: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80800454: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_12:
    // 0x80800458: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080045C: jal         0x80101FDC
    // 0x80800460: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x80800460: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_13:
    // 0x80800464: jal         0x8010A590
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_14;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080046C: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800470: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80800474: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800478: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8080047C: jal         0x8010D254
    // 0x80800480: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_8010D254(rdram, ctx);
        goto after_15;
    // 0x80800480: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_15:
    // 0x80800484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800488: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080048C: jal         0x800F1E6C
    // 0x80800490: addiu       $a2, $s0, 0x48
    ctx->r6 = ADD32(ctx->r16, 0X48);
    func_800F1E6C(rdram, ctx);
        goto after_16;
    // 0x80800490: addiu       $a2, $s0, 0x48
    ctx->r6 = ADD32(ctx->r16, 0X48);
    after_16:
    // 0x80800494: b           L_808004E4
    // 0x80800498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004E4;
    // 0x80800498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080049C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_808004A0:
    // 0x808004A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808004AC: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x808004B0: jal         0x80102424
    // 0x808004B4: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x808004B4: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    after_17:
    // 0x808004B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004BC: jal         0x80101FDC
    // 0x808004C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80101FDC(rdram, ctx);
        goto after_18;
    // 0x808004C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x808004C4: jal         0x8010A570
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_19;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808004CC: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x808004D8: jal         0x808004F8
    // 0x808004DC: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_808004F8_chboxingglove(rdram, ctx);
        goto after_20;
    // 0x808004DC: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_20:
L_808004E0:
    // 0x808004E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004E4:
    // 0x808004E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808004EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808004F0: jr          $ra
    // 0x808004F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808004F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_808011C0_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808011C4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x808011C8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808011CC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808011D0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x808011D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808011D8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x808011DC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808011E0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808011E4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808011E8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808011EC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808011F0: jal         0x80100094
    // 0x808011F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808011F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808011F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808011FC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80801200: lwc1        $f26, 0x18($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80801204: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801208: beq         $s0, $zero, L_80801218
    if (ctx->r16 == 0) {
        // 0x8080120C: mov.s       $f22, $f28
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    ctx->f22.fl = ctx->f28.fl;
            goto L_80801218;
    }
    // 0x8080120C: mov.s       $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    ctx->f22.fl = ctx->f28.fl;
    // 0x80801210: b           L_8080121C
    // 0x80801214: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
        goto L_8080121C;
    // 0x80801214: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
L_80801218:
    // 0x80801218: lwc1        $f24, 0x48($s1)
    ctx->f24.u32l = MEM_W(ctx->r17, 0X48);
L_8080121C:
    // 0x8080121C: bnel        $s0, $zero, L_80801254
    if (ctx->r16 != 0) {
        // 0x80801220: sub.s       $f20, $f24, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f22.fl;
            goto L_80801254;
    }
    goto skip_0;
    // 0x80801220: sub.s       $f20, $f24, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f22.fl;
    skip_0:
    // 0x80801224: add.s       $f20, $f24, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f24.fl + ctx->f22.fl;
    // 0x80801228: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8080122C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801230: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801234: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801238: jal         0x8080110C
    // 0x8080123C: nop

    func_8080110C_chdragonbrothers(rdram, ctx);
        goto after_1;
    // 0x8080123C: nop

    after_1:
    // 0x80801240: beql        $v0, $zero, L_80801254
    if (ctx->r2 == 0) {
        // 0x80801244: sub.s       $f20, $f24, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f22.fl;
            goto L_80801254;
    }
    goto skip_1;
    // 0x80801244: sub.s       $f20, $f24, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f22.fl;
    skip_1:
    // 0x80801248: b           L_80801288
    // 0x8080124C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_80801288;
    // 0x8080124C: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80801250: sub.s       $f20, $f24, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f22.fl;
L_80801254:
    // 0x80801254: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80801258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080125C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80801260: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801264: jal         0x8080110C
    // 0x80801268: nop

    func_8080110C_chdragonbrothers(rdram, ctx);
        goto after_2;
    // 0x80801268: nop

    after_2:
    // 0x8080126C: beq         $v0, $zero, L_8080127C
    if (ctx->r2 == 0) {
        // 0x80801270: nop
    
            goto L_8080127C;
    }
    // 0x80801270: nop

    // 0x80801274: b           L_80801288
    // 0x80801278: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_80801288;
    // 0x80801278: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8080127C:
    // 0x8080127C: beq         $s2, $zero, L_8080121C
    if (ctx->r18 == 0) {
        // 0x80801280: add.s       $f22, $f22, $f28
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f28.fl;
            goto L_8080121C;
    }
    // 0x80801280: add.s       $f22, $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f28.fl;
    // 0x80801284: mov.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.fl = ctx->f24.fl;
L_80801288:
    // 0x80801288: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8080128C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801290: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801294: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80801298: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080129C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808012A0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x808012A4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x808012A8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x808012AC: jr          $ra
    // 0x808012B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808012B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800E41CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E41CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E41D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E41D4: jal         0x800CA334
    // 0x800E41D8: nop

    func_800CA334(rdram, ctx);
        goto after_0;
    // 0x800E41D8: nop

    after_0:
    // 0x800E41DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E41E0: addiu       $v1, $v1, -0x2AFC
    ctx->r3 = ADD32(ctx->r3, -0X2AFC);
    // 0x800E41E4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800E41E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800E41EC: lw          $a1, -0x2B00($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2B00);
    // 0x800E41F0: jal         0x800CA314
    // 0x800E41F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800CA314(rdram, ctx);
        goto after_1;
    // 0x800E41F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800E41F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E41FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E4200: jr          $ra
    // 0x800E4204: nop

    return;
    // 0x800E4204: nop

;}
RECOMP_FUNC void func_808001C8_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001D8: jal         0x800C6DA0
    // 0x808001DC: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    func_800C6DA0(rdram, ctx);
        goto after_0;
    // 0x808001DC: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_0:
    // 0x808001E0: lui         $a2, 0x3FD9
    ctx->r6 = S32(0X3FD9 << 16);
    // 0x808001E4: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808001E8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808001EC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: jal         0x8008CD30
    // 0x808001F8: addiu       $a1, $zero, 0x27D
    ctx->r5 = ADD32(0, 0X27D);
    baanim_playForDuration_onceSmoothStartingAt(rdram, ctx);
        goto after_1;
    // 0x808001F8: addiu       $a1, $zero, 0x27D
    ctx->r5 = ADD32(0, 0X27D);
    after_1:
    // 0x808001FC: jal         0x80800000
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbanswim(rdram, ctx);
        goto after_2;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x8080020C: jal         0x8009C99C
    // 0x80800210: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80800210: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_3:
    // 0x80800214: jal         0x80800030
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsbanswim(rdram, ctx);
        goto after_4;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: jal         0x800852B8
    // 0x80800224: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800224: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: jal         0x800852A8
    // 0x80800230: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    _baswim_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800230: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_6:
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x8080023C: jal         0x8009BFE4
    // 0x80800240: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_7;
    // 0x80800240: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    after_7:
    // 0x80800244: sb          $zero, 0x164($s0)
    MEM_B(0X164, ctx->r16) = 0;
    // 0x80800248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080024C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800254: jr          $ra
    // 0x80800258: nop

    return;
    // 0x80800258: nop

;}
RECOMP_FUNC void func_80801110_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801110: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801114: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801118: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080111C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801120: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801124: beq         $a1, $at, L_80801148
    if (ctx->r5 == ctx->r1) {
        // 0x80801128: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80801148;
    }
    // 0x80801128: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8080112C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801130: bne         $a1, $at, L_808011EC
    if (ctx->r5 != ctx->r1) {
        // 0x80801134: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808011EC;
    }
    // 0x80801134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801138: jal         0x80801200
    // 0x8080113C: nop

    func_80801200_chdippy(rdram, ctx);
        goto after_0;
    // 0x8080113C: nop

    after_0:
    // 0x80801140: b           L_808011EC
    // 0x80801144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011EC;
    // 0x80801144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801148:
    // 0x80801148: lhu         $t6, 0x64($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X64);
    // 0x8080114C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80801150: beq         $t7, $zero, L_808011E4
    if (ctx->r15 == 0) {
        // 0x80801154: nop
    
            goto L_808011E4;
    }
    // 0x80801154: nop

    // 0x80801158: jal         0x801015D0
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801160: jal         0x800E3980
    // 0x80801164: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800E3980(rdram, ctx);
        goto after_2;
    // 0x80801164: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80801168: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080116C: jal         0x800F1DF4
    // 0x80801170: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x80801170: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80801174: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801178: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080117C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801180: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80801184: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801188: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8080118C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80801190: bc1fl       L_808011D0
    if (!c1cs) {
        // 0x80801194: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_808011D0;
    }
    goto skip_0;
    // 0x80801194: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x80801198: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X1474) << 16);
    // 0x8080119C: lwc1        $f4, 0x1474($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X1474));
    // 0x808011A0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x808011A4: jal         0x800F10B4
    // 0x808011A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808011A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x808011AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808011B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808011B4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x808011B8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x808011BC: jal         0x800DF500
    // 0x808011C0: nop

    func_800DF500(rdram, ctx);
        goto after_5;
    // 0x808011C0: nop

    after_5:
    // 0x808011C4: b           L_808011EC
    // 0x808011C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011EC;
    // 0x808011C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808011CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_808011D0:
    // 0x808011D0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808011D4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808011D8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x808011DC: jal         0x800DF500
    // 0x808011E0: nop

    func_800DF500(rdram, ctx);
        goto after_6;
    // 0x808011E0: nop

    after_6:
L_808011E4:
    // 0x808011E4: b           L_808011EC
    // 0x808011E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011EC;
    // 0x808011E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011EC:
    // 0x808011EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808011F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808011F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808011F8: jr          $ra
    // 0x808011FC: nop

    return;
    // 0x808011FC: nop

;}
RECOMP_FUNC void _vplight_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089010: syscall     755
    recomp_syscall_handler(rdram, ctx, 0x80089010);
    return;
    // 0x80089014: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800920C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800920C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800920CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800920D0: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x800920D4: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    // 0x800920D8: jal         0x80093504
    // 0x800920DC: addiu       $a2, $v0, 0x50
    ctx->r6 = ADD32(ctx->r2, 0X50);
    func_80093504(rdram, ctx);
        goto after_0;
    // 0x800920DC: addiu       $a2, $v0, 0x50
    ctx->r6 = ADD32(ctx->r2, 0X50);
    after_0:
    // 0x800920E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800920E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800920E8: jr          $ra
    // 0x800920EC: nop

    return;
    // 0x800920EC: nop

;}
RECOMP_FUNC void ncpoddialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801148: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080114C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801150: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80801154: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80801158: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080115C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80801160: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801164: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801168: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080116C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801170: jal         0x8001B668
    // 0x80801174: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    func_8001B668(rdram, ctx);
        goto after_0;
    // 0x80801174: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    after_0:
    // 0x80801178: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8080117C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80801180: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
    // 0x80801184: jal         0x80801094
    // 0x80801188: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    ncpoddialog_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801188: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x8080118C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801190: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80801194: sb          $t7, 0x210($v0)
    MEM_B(0X210, ctx->r2) = ctx->r15;
    // 0x80801198: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080119C: addiu       $s1, $v0, 0x58
    ctx->r17 = ADD32(ctx->r2, 0X58);
    // 0x808011A0: addiu       $s2, $v0, 0xD0
    ctx->r18 = ADD32(ctx->r2, 0XD0);
    // 0x808011A4: addiu       $s3, $v0, 0x188
    ctx->r19 = ADD32(ctx->r2, 0X188);
    // 0x808011A8: addiu       $s4, $zero, 0x78
    ctx->r20 = ADD32(0, 0X78);
L_808011AC:
    // 0x808011AC: jal         0x800EFD24
    // 0x808011B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x808011B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808011B4: jal         0x800EFD24
    // 0x808011B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x808011B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x808011BC: jal         0x800EFD24
    // 0x808011C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x808011C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x808011C4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x808011C8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x808011CC: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x808011D0: bne         $s0, $s4, L_808011AC
    if (ctx->r16 != ctx->r20) {
        // 0x808011D4: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_808011AC;
    }
    // 0x808011D4: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x808011D8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808011DC: addiu       $a0, $s5, 0x148
    ctx->r4 = ADD32(ctx->r21, 0X148);
    // 0x808011E0: jal         0x800EFD24
    // 0x808011E4: swc1        $f20, 0x20C($s5)
    MEM_W(0X20C, ctx->r21) = ctx->f20.u32l;
    func_800EFD24(rdram, ctx);
        goto after_5;
    // 0x808011E4: swc1        $f20, 0x20C($s5)
    MEM_W(0X20C, ctx->r21) = ctx->f20.u32l;
    after_5:
    // 0x808011E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808011EC: swc1        $f20, 0x154($s5)
    MEM_W(0X154, ctx->r21) = ctx->f20.u32l;
    // 0x808011F0: sb          $t8, 0x211($s5)
    MEM_B(0X211, ctx->r21) = ctx->r24;
    // 0x808011F4: sb          $zero, 0x212($s5)
    MEM_B(0X212, ctx->r21) = 0;
    // 0x808011F8: sb          $zero, 0x213($s5)
    MEM_B(0X213, ctx->r21) = 0;
    // 0x808011FC: sb          $zero, 0x214($s5)
    MEM_B(0X214, ctx->r21) = 0;
    // 0x80801200: sb          $zero, 0x215($s5)
    MEM_B(0X215, ctx->r21) = 0;
    // 0x80801204: sb          $zero, 0x217($s5)
    MEM_B(0X217, ctx->r21) = 0;
    // 0x80801208: jal         0x800EFD24
    // 0x8080120C: addiu       $a0, $s5, 0x170
    ctx->r4 = ADD32(ctx->r21, 0X170);
    func_800EFD24(rdram, ctx);
        goto after_6;
    // 0x8080120C: addiu       $a0, $s5, 0x170
    ctx->r4 = ADD32(ctx->r21, 0X170);
    after_6:
    // 0x80801210: jal         0x800EFD24
    // 0x80801214: addiu       $a0, $s5, 0x17C
    ctx->r4 = ADD32(ctx->r21, 0X17C);
    func_800EFD24(rdram, ctx);
        goto after_7;
    // 0x80801214: addiu       $a0, $s5, 0x17C
    ctx->r4 = ADD32(ctx->r21, 0X17C);
    after_7:
    // 0x80801218: jal         0x800EFD24
    // 0x8080121C: addiu       $a0, $s5, 0x200
    ctx->r4 = ADD32(ctx->r21, 0X200);
    func_800EFD24(rdram, ctx);
        goto after_8;
    // 0x8080121C: addiu       $a0, $s5, 0x200
    ctx->r4 = ADD32(ctx->r21, 0X200);
    after_8:
    // 0x80801220: addiu       $s2, $s5, 0x28
    ctx->r18 = ADD32(ctx->r21, 0X28);
    // 0x80801224: addiu       $s3, $s5, 0x40
    ctx->r19 = ADD32(ctx->r21, 0X40);
    // 0x80801228: or          $s4, $s5, $zero
    ctx->r20 = ctx->r21 | 0;
    // 0x8080122C: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x80801230: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // 0x80801234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80801238:
    // 0x80801238: jal         0x800EFD24
    // 0x8080123C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFD24(rdram, ctx);
        goto after_9;
    // 0x8080123C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80801240: jal         0x800EFD24
    // 0x80801244: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFD24(rdram, ctx);
        goto after_10;
    // 0x80801244: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x80801248: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8080124C: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x80801250: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    // 0x80801254: swc1        $f20, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f20.u32l;
    // 0x80801258: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x8080125C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80801260: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x80801264: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80801268: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8080126C: bne         $s1, $s5, L_80801238
    if (ctx->r17 != ctx->r21) {
        // 0x80801270: swc1        $f20, 0x1C($s4)
        MEM_W(0X1C, ctx->r20) = ctx->f20.u32l;
            goto L_80801238;
    }
    // 0x80801270: swc1        $f20, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f20.u32l;
    // 0x80801274: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801278: lh          $v0, 0x3E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X3E);
    // 0x8080127C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80801280: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801284: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801288: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8080128C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80801290: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80801294: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80801298: jr          $ra
    // 0x8080129C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080129C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _chtoxicroomprops_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087808: syscall     631
    recomp_syscall_handler(rdram, ctx, 0x80087808);
    return;
    // 0x8008780C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DA188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DA18C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DA190: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DA194: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800DA198: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800DA19C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DA1A0: addiu       $s1, $s1, -0x3884
    ctx->r17 = ADD32(ctx->r17, -0X3884);
    // 0x800DA1A4: addiu       $s0, $s0, -0x3890
    ctx->r16 = ADD32(ctx->r16, -0X3890);
    // 0x800DA1A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800DA1AC:
    // 0x800DA1AC: beql        $a0, $zero, L_800DA1C4
    if (ctx->r4 == 0) {
        // 0x800DA1B0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800DA1C4;
    }
    goto skip_0;
    // 0x800DA1B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800DA1B4: jal         0x8001B084
    // 0x800DA1B8: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800DA1B8: nop

    after_0:
    // 0x800DA1BC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800DA1C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800DA1C4:
    // 0x800DA1C4: bnel        $s0, $s1, L_800DA1AC
    if (ctx->r16 != ctx->r17) {
        // 0x800DA1C8: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800DA1AC;
    }
    goto skip_1;
    // 0x800DA1C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800DA1CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA1D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DA1D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DA1D8: jr          $ra
    // 0x800DA1DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800DA1DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808027C4_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808027C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808027CC: jal         0x80104248
    // 0x808027D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x808027D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808027D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808027D8: jal         0x8008AED4
    // 0x808027DC: addiu       $a1, $zero, 0x108
    ctx->r5 = ADD32(0, 0X108);
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x808027DC: addiu       $a1, $zero, 0x108
    ctx->r5 = ADD32(0, 0X108);
    after_1:
    // 0x808027E0: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808027E4: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808027E8: jal         0x80101CDC
    // 0x808027EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101CDC(rdram, ctx);
        goto after_2;
    // 0x808027EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808027F0: jal         0x808026D0
    // 0x808027F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808026D0_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x808027F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808027F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808027FC: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80802800: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80802804: bgezl       $t9, L_80802818
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80802808: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802818;
    }
    goto skip_0;
    // 0x80802808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080280C: jal         0x808000B8
    // 0x80802810: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_808000B8_chdodgemcontrol(rdram, ctx);
        goto after_4;
    // 0x80802810: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80802814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802818:
    // 0x80802818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080281C: jr          $ra
    // 0x80802820: nop

    return;
    // 0x80802820: nop

;}
RECOMP_FUNC void _baduo_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084938: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084938);
    return;
    // 0x8008493C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800D5D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D5D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5D78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5D7C: jal         0x800D55A0
    // 0x800D5D80: sb          $zero, -0x481A($at)
    MEM_B(-0X481A, ctx->r1) = 0;
    func_800D55A0(rdram, ctx);
        goto after_0;
    // 0x800D5D80: sb          $zero, -0x481A($at)
    MEM_B(-0X481A, ctx->r1) = 0;
    after_0:
    // 0x800D5D84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5D88: sb          $zero, -0x481C($at)
    MEM_B(-0X481C, ctx->r1) = 0;
    // 0x800D5D8C: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x800D5D90: addiu       $t6, $t6, 0x5180
    ctx->r14 = ADD32(ctx->r14, 0X5180);
    // 0x800D5D94: ori         $at, $zero, 0xD9A4
    ctx->r1 = 0 | 0XD9A4;
    // 0x800D5D98: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800D5D9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5DA0: jal         0x800E4CE8
    // 0x800D5DA4: sw          $t7, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = ctx->r15;
    func_800E4CE8(rdram, ctx);
        goto after_1;
    // 0x800D5DA4: sw          $t7, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = ctx->r15;
    after_1:
    // 0x800D5DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D5DB0: jr          $ra
    // 0x800D5DB4: nop

    return;
    // 0x800D5DB4: nop

;}
RECOMP_FUNC void func_80800C70_glsplineDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C70: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2714, 0XFC8) << 16);
    // 0x80800C74: addiu       $a2, $a2, 0xFC8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2714, 0XFC8));
    // 0x80800C78: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800C7C: lbu         $v0, 0x762C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X762C);
    // 0x80800C80: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x80800C84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800C88: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2714, 0XFC8) << 16);
    // 0x80800C8C: beql        $v0, $t6, L_80800CC8
    if (ctx->r2 == ctx->r14) {
        // 0x80800C90: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80800CC8;
    }
    goto skip_0;
    // 0x80800C90: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    skip_0:
    // 0x80800C94: lh          $t7, 0xFC8($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(2714, 0XFC8));
    // 0x80800C98: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80800C9C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x80800CA0: beq         $a3, $t7, L_80800CC4
    if (ctx->r7 == ctx->r15) {
        // 0x80800CA4: addu        $a0, $a2, $t8
        ctx->r4 = ADD32(ctx->r6, ctx->r24);
            goto L_80800CC4;
    }
    // 0x80800CA4: addu        $a0, $a2, $t8
    ctx->r4 = ADD32(ctx->r6, ctx->r24);
    // 0x80800CA8: lh          $a1, 0x4($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X4);
L_80800CAC:
    // 0x80800CAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800CB0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800CB4: beql        $v0, $a1, L_80800CC8
    if (ctx->r2 == ctx->r5) {
        // 0x80800CB8: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80800CC8;
    }
    goto skip_1;
    // 0x80800CB8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    skip_1:
    // 0x80800CBC: bnel        $a3, $a1, L_80800CAC
    if (ctx->r7 != ctx->r5) {
        // 0x80800CC0: lh          $a1, 0x4($a0)
        ctx->r5 = MEM_H(ctx->r4, 0X4);
            goto L_80800CAC;
    }
    goto skip_2;
    // 0x80800CC0: lh          $a1, 0x4($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X4);
    skip_2:
L_80800CC4:
    // 0x80800CC4: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_80800CC8:
    // 0x80800CC8: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x80800CCC: jr          $ra
    // 0x80800CD0: lh          $v0, 0x2($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X2);
    return;
    // 0x80800CD0: lh          $v0, 0x2($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X2);
;}
RECOMP_FUNC void func_800B2808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2808: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x800B280C: bne         $v1, $zero, L_800B281C
    if (ctx->r3 != 0) {
        // 0x800B2810: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B281C;
    }
    // 0x800B2810: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B2814: jr          $ra
    // 0x800B2818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B2818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B281C:
    // 0x800B281C: jr          $ra
    // 0x800B2820: nop

    return;
    // 0x800B2820: nop

;}
RECOMP_FUNC void func_8080000C_chflowerbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80100094
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800028: jal         0x80089F70
    // 0x8080002C: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800038: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080003C: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x80800040: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x80800044: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800048: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082558: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082558);
    return;
    // 0x8008255C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chfactoryworkerdirty_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087318: syscall     550
    recomp_syscall_handler(rdram, ctx, 0x80087318);
    return;
    // 0x8008731C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chtntmineshoot_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802444: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2204, 0X28E4) << 16);
    // 0x80802448: jr          $ra
    // 0x8080244C: addiu       $v0, $v0, 0x28E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2204, 0X28E4));
    return;
    // 0x8080244C: addiu       $v0, $v0, 0x28E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2204, 0X28E4));
;}
RECOMP_FUNC void _fxripple_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889C0: syscall     715
    recomp_syscall_handler(rdram, ctx, 0x800889C0);
    return;
    // 0x800889C4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800EC058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EC05C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EC060: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EC064: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x800EC068: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800EC06C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800EC070: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800EC074: beq         $t7, $zero, L_800EC084
    if (ctx->r15 == 0) {
        // 0x800EC078: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800EC084;
    }
    // 0x800EC078: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800EC07C: b           L_800EC094
    // 0x800EC080: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_800EC094;
    // 0x800EC080: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800EC084:
    // 0x800EC084: jal         0x800BD97C
    // 0x800EC088: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800BD97C(rdram, ctx);
        goto after_0;
    // 0x800EC088: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800EC08C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800EC090: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800EC094:
    // 0x800EC094: lh          $t8, 0x1C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1C);
    // 0x800EC098: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800EC09C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EC0A0: bne         $a2, $t8, L_800EC0B8
    if (ctx->r6 != ctx->r24) {
        // 0x800EC0A4: nop
    
            goto L_800EC0B8;
    }
    // 0x800EC0A4: nop

    // 0x800EC0A8: jal         0x800EC030
    // 0x800EC0AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EC030(rdram, ctx);
        goto after_1;
    // 0x800EC0AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800EC0B0: b           L_800EC0C4
    // 0x800EC0B4: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
        goto L_800EC0C4;
    // 0x800EC0B4: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
L_800EC0B8:
    // 0x800EC0B8: jal         0x800EBD2C
    // 0x800EC0BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EBD2C(rdram, ctx);
        goto after_2;
    // 0x800EC0BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x800EC0C0: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
L_800EC0C4:
    // 0x800EC0C4: sll         $t1, $t9, 21
    ctx->r9 = S32(ctx->r25 << 21);
    // 0x800EC0C8: bgezl       $t1, L_800EC0DC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800EC0CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800EC0DC;
    }
    goto skip_0;
    // 0x800EC0CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800EC0D0: jal         0x800CDFD0
    // 0x800EC0D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800CDFD0(rdram, ctx);
        goto after_3;
    // 0x800EC0D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800EC0D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EC0DC:
    // 0x800EC0DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EC0E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EC0E4: jr          $ra
    // 0x800EC0E8: nop

    return;
    // 0x800EC0E8: nop

;}
RECOMP_FUNC void func_800F6604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6604: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F660C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6614: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6618: jal         0x80084618
    // 0x800F661C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _bacough_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800F661C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F6620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6624: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F6628: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F662C: jr          $ra
    // 0x800F6630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F6630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800E9574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E957C: jal         0x800E94E4
    // 0x800E9580: nop

    func_800E94E4(rdram, ctx);
        goto after_0;
    // 0x800E9580: nop

    after_0:
    // 0x800E9584: jal         0x800E93CC
    // 0x800E9588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E93CC(rdram, ctx);
        goto after_1;
    // 0x800E9588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800E958C: jal         0x800E9438
    // 0x800E9590: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E9438(rdram, ctx);
        goto after_2;
    // 0x800E9590: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800E9594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9598: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800E959C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800E95A0: sw          $t6, 0x3510($at)
    MEM_W(0X3510, ctx->r1) = ctx->r14;
    // 0x800E95A4: jr          $ra
    // 0x800E95A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800E95A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _sueggmisc_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A340: syscall     837
    recomp_syscall_handler(rdram, ctx, 0x8008A340);
    return;
    // 0x8008A344: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chbounce_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858C8: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x800858C8);
    return;
    // 0x800858CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8009C038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C03C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009C044: lw          $a0, 0xE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE4);
    // 0x8009C048: jal         0x800EFD24
    // 0x8009C04C: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8009C04C: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_0:
    // 0x8009C050: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8009C054: jal         0x800EFD24
    // 0x8009C058: lw          $a0, 0xE4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XE4);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8009C058: lw          $a0, 0xE4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XE4);
    after_1:
    // 0x8009C05C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8009C060: lw          $a0, 0xE4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XE4);
    // 0x8009C064: jal         0x800EFD24
    // 0x8009C068: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x8009C068: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_2:
    // 0x8009C06C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8009C070: lw          $a0, 0xE4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XE4);
    // 0x8009C074: jal         0x800EFD24
    // 0x8009C078: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x8009C078: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_3:
    // 0x8009C07C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C084: jr          $ra
    // 0x8009C088: nop

    return;
    // 0x8009C088: nop

;}
RECOMP_FUNC void _chicestationbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086350: syscall     311
    recomp_syscall_handler(rdram, ctx, 0x80086350);
    return;
    // 0x80086354: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void batimer_get_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
;}
RECOMP_FUNC void func_800B1F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1F8C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B1F90: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800B1F94: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800B1F98: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800B1F9C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B1FA0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B1FA4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B1FA8: beq         $t6, $zero, L_800B20A4
    if (ctx->r14 == 0) {
        // 0x800B1FAC: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_800B20A4;
    }
    // 0x800B1FAC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B1FB0: jal         0x80019CD4
    // 0x800B1FB4: nop

    func_80019CD4(rdram, ctx);
        goto after_0;
    // 0x800B1FB4: nop

    after_0:
    // 0x800B1FB8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800B1FBC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B1FC0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800B1FC4: jal         0x80019750
    // 0x800B1FC8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    func_80019750(rdram, ctx);
        goto after_1;
    // 0x800B1FC8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x800B1FCC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B1FD0: jal         0x80018AD0
    // 0x800B1FD4: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    mlMtxGet(rdram, ctx);
        goto after_2;
    // 0x800B1FD4: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    after_2:
    // 0x800B1FD8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800B1FDC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800B1FE0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800B1FE4: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B1FE8: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800B1FEC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800B1FF0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B1FF4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B1FF8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B1FFC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800B2000: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800B2004: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800B2008: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800B200C: jal         0x800B1D3C
    // 0x800B2010: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_800B1D3C(rdram, ctx);
        goto after_3;
    // 0x800B2010: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_3:
    // 0x800B2014: bne         $v0, $zero, L_800B205C
    if (ctx->r2 != 0) {
        // 0x800B2018: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800B205C;
    }
    // 0x800B2018: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B201C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800B2020: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800B2024: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800B2028: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B202C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800B2030: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800B2034: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B2038: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B203C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B2040: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800B2044: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800B2048: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800B204C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800B2050: jal         0x800B1508
    // 0x800B2054: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    func_800B1508(rdram, ctx);
        goto after_4;
    // 0x800B2054: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_4:
    // 0x800B2058: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B205C:
    // 0x800B205C: bne         $v0, $zero, L_800B2154
    if (ctx->r2 != 0) {
        // 0x800B2060: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800B2154;
    }
    // 0x800B2060: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B2064: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800B2068: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800B206C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800B2070: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B2074: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800B2078: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800B207C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B2080: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B2084: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800B2088: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800B208C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800B2090: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800B2094: jal         0x800B196C
    // 0x800B2098: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_800B196C(rdram, ctx);
        goto after_5;
    // 0x800B2098: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_5:
    // 0x800B209C: b           L_800B2154
    // 0x800B20A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800B2154;
    // 0x800B20A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B20A4:
    // 0x800B20A4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800B20A8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800B20AC: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B20B0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800B20B4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800B20B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B20BC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B20C0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B20C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800B20C8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800B20CC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800B20D0: jal         0x800B1328
    // 0x800B20D4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    func_800B1328(rdram, ctx);
        goto after_6;
    // 0x800B20D4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_6:
    // 0x800B20D8: bne         $v0, $zero, L_800B2118
    if (ctx->r2 != 0) {
        // 0x800B20DC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800B2118;
    }
    // 0x800B20DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B20E0: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800B20E4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800B20E8: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B20EC: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800B20F0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800B20F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B20F8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B20FC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B2100: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800B2104: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800B2108: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x800B210C: jal         0x800B0ECC
    // 0x800B2110: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    func_800B0ECC(rdram, ctx);
        goto after_7;
    // 0x800B2110: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_7:
    // 0x800B2114: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B2118:
    // 0x800B2118: bne         $v0, $zero, L_800B2154
    if (ctx->r2 != 0) {
        // 0x800B211C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800B2154;
    }
    // 0x800B211C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B2120: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800B2124: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800B2128: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B212C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800B2130: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800B2134: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800B2138: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B213C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800B2140: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800B2144: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x800B2148: jal         0x800B1110
    // 0x800B214C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800B1110(rdram, ctx);
        goto after_8;
    // 0x800B214C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_8:
    // 0x800B2150: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B2154:
    // 0x800B2154: beql        $v0, $zero, L_800B2180
    if (ctx->r2 == 0) {
        // 0x800B2158: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800B2180;
    }
    goto skip_0;
    // 0x800B2158: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800B215C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B2160: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800B2164: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B2168: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B216C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800B2170: jal         0x800EFA4C
    // 0x800B2174: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x800B2174: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_9:
    // 0x800B2178: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B217C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800B2180:
    // 0x800B2180: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800B2184: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B2188: jr          $ra
    // 0x800B218C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B218C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80800000_chbottlesdead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1992, 0XA0) << 16);
    // 0x8080000C: lwc1        $f6, 0xA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1992, 0XA0));
    // 0x80800010: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800014: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800018: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080001C: jal         0x80102FDC
    // 0x80800020: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800020: nop

    after_0:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void bsmumattack_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(312, 0X700) << 16);
    // 0x808006D4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006D8: jr          $ra
    // 0x808006DC: lw          $v0, 0x700($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(312, 0X700));
    return;
    // 0x808006DC: lw          $v0, 0x700($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(312, 0X700));
;}
RECOMP_FUNC void func_80800078_chcaptainblubber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080007C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800080: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800088: jal         0x801000D8
    // 0x8080008C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_801000D8(rdram, ctx);
        goto after_0;
    // 0x8080008C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x80800090: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800094: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800098: addiu       $a1, $zero, 0x4E4
    ctx->r5 = ADD32(0, 0X4E4);
    // 0x8080009C: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    // 0x808000A0: jal         0x80089FD0
    // 0x808000A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddieitem_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808000A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x808000A8: jal         0x80089FE0
    // 0x808000AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808000AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808000B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000B4: jal         0x80102424
    // 0x808000B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808000B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void func_808007C4_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007D0: jal         0x8008CABC
    // 0x808007D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808007D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808007D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808007DC: jal         0x80082838
    // 0x808007E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808007E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808007E4: jal         0x8008AF24
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: jal         0x8008AED4
    // 0x808007F4: addiu       $a1, $zero, 0x1E2
    ctx->r5 = ADD32(0, 0X1E2);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x808007F4: addiu       $a1, $zero, 0x1E2
    ctx->r5 = ADD32(0, 0X1E2);
    after_3:
    // 0x808007F8: lui         $a1, 0x3EAE
    ctx->r5 = S32(0X3EAE << 16);
    // 0x808007FC: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80800800: jal         0x8008B24C
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080080C: jal         0x8008B1BC
    // 0x80800810: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80800810: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_5:
    // 0x80800814: lui         $a2, 0x3F02
    ctx->r6 = S32(0X3F02 << 16);
    // 0x80800818: ori         $a2, $a2, 0x8F5C
    ctx->r6 = ctx->r6 | 0X8F5C;
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800820: jal         0x8008B1D4
    // 0x80800824: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x80800824: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: jal         0x8008B134
    // 0x80800830: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80800830: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800834: jal         0x8008B064
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080083C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800840: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800844: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800848: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080084C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800850: jal         0x8009FFD8
    // 0x80800854: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80800854: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x80800858: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080085C: sw          $zero, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = 0;
    // 0x80800860: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800864: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800868: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080086C: jr          $ra
    // 0x80800870: nop

    return;
    // 0x80800870: nop

;}
RECOMP_FUNC void bsrest_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800668: jal         0x808003FC
    // 0x8080066C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    static_344_808003FC(rdram, ctx);
        goto after_0;
    // 0x8080066C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800670: jal         0x8080003C
    // 0x80800674: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    static_344_8080003C(rdram, ctx);
        goto after_1;
    // 0x80800674: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080067C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800680: jr          $ra
    // 0x80800684: nop

    return;
    // 0x80800684: nop

;}
RECOMP_FUNC void func_80103EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103EAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103EB4: jal         0x80103328
    // 0x80103EB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103328(rdram, ctx);
        goto after_0;
    // 0x80103EB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80103EBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80103EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103EC4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80103EC8: lhu         $t6, 0x62($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X62);
    // 0x80103ECC: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80103ED0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80103ED4: bgez        $t6, L_80103EE8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80103ED8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80103EE8;
    }
    // 0x80103ED8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80103EDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80103EE0: nop

    // 0x80103EE4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80103EE8:
    // 0x80103EE8: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80103EEC: jr          $ra
    // 0x80103EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800272B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800272B0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800272B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800272B8: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800272BC: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800272C0: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800272C4: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x800272C8: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800272CC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800272D0: lw          $t7, 0x11F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11F4);
    // 0x800272D4: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x800272D8: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x800272DC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800272E0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800272E4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800272E8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800272EC: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x800272F0: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x800272F4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800272F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800272FC: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x80027300: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80027304: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80027308: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x8002730C: jal         0x8002BD40
    // 0x80027310: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_8002BD40(rdram, ctx);
        goto after_0;
    // 0x80027310: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x80027314: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80027318: addiu       $t4, $zero, 0x7C0
    ctx->r12 = ADD32(0, 0X7C0);
    // 0x8002731C: sh          $t4, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r12;
    // 0x80027320: addiu       $t5, $zero, 0x930
    ctx->r13 = ADD32(0, 0X930);
    // 0x80027324: sh          $t5, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r13;
    // 0x80027328: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x8002732C: addiu       $t6, $zero, 0x170
    ctx->r14 = ADD32(0, 0X170);
    // 0x80027330: sh          $t6, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r14;
    // 0x80027334: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x80027338: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8002733C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80027340: lbu         $t9, -0x15CD($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X15CD);
    // 0x80027344: bne         $t9, $zero, L_800273BC
    if (ctx->r25 != 0) {
        // 0x80027348: nop
    
            goto L_800273BC;
    }
    // 0x80027348: nop

    // 0x8002734C: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80027350: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x80027354: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x80027358: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x8002735C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80027360: lui         $t1, 0xC00
    ctx->r9 = S32(0XC00 << 16);
    // 0x80027364: ori         $t1, $t1, 0xC000
    ctx->r9 = ctx->r9 | 0XC000;
    // 0x80027368: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8002736C: lh          $t3, 0x70($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X70);
    // 0x80027370: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80027374: lui         $at, 0x7C0
    ctx->r1 = S32(0X7C0 << 16);
    // 0x80027378: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8002737C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80027380: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80027384: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80027388: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8002738C: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x80027390: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80027394: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80027398: lui         $t8, 0xC00
    ctx->r24 = S32(0XC00 << 16);
    // 0x8002739C: ori         $t8, $t8, 0x4000
    ctx->r24 = ctx->r24 | 0X4000;
    // 0x800273A0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800273A4: lh          $t1, 0x70($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X70);
    // 0x800273A8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800273AC: lui         $at, 0x930
    ctx->r1 = S32(0X930 << 16);
    // 0x800273B0: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800273B4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800273B8: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_800273BC:
    // 0x800273BC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800273C0: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800273C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800273C8: lw          $a2, 0x28($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X28);
    // 0x800273CC: lh          $a3, 0x70($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X70);
    // 0x800273D0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800273D4: jal         0x80028520
    // 0x800273D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80028520(rdram, ctx);
        goto after_1;
    // 0x800273D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800273DC: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x800273E0: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800273E4: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800273E8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800273EC: lbu         $t9, -0x15CD($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X15CD);
    // 0x800273F0: beq         $t9, $zero, L_8002741C
    if (ctx->r25 == 0) {
        // 0x800273F4: nop
    
            goto L_8002741C;
    }
    // 0x800273F4: nop

    // 0x800273F8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800273FC: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80027400: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80027404: lw          $a2, 0x2C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X2C);
    // 0x80027408: addiu       $a3, $zero, 0x930
    ctx->r7 = ADD32(0, 0X930);
    // 0x8002740C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80027410: jal         0x80028520
    // 0x80027414: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80028520(rdram, ctx);
        goto after_2;
    // 0x80027414: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x80027418: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_8002741C:
    // 0x8002741C: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80027420: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80027424: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80027428: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002742C: lbu         $t2, -0x15CD($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X15CD);
L_80027430:
    // 0x80027430: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80027434: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80027438: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x8002743C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80027440: lh          $t5, 0x6E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6E);
    // 0x80027444: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80027448: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002744C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80027450: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80027454: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x80027458: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002745C: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80027460: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80027464: addiu       $t8, $zero, 0x170
    ctx->r24 = ADD32(0, 0X170);
    // 0x80027468: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8002746C: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80027470: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x80027474: lbu         $t2, 0x8($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X8);
    // 0x80027478: blez        $t2, L_80027910
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8002747C: nop
    
            goto L_80027910;
    }
    // 0x8002747C: nop

L_80027480:
    // 0x80027480: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80027484: lh          $t5, 0x76($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X76);
    // 0x80027488: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8002748C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80027490: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80027494: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80027498: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8002749C: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800274A0: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800274A4: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800274A8: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800274AC: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800274B0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800274B4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800274B8: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x800274BC: negu        $t4, $t5
    ctx->r12 = SUB32(0, ctx->r13);
    // 0x800274C0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800274C4: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x800274C8: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800274CC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800274D0: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800274D4: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800274D8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800274DC: lw          $t4, 0x4($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X4);
    // 0x800274E0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800274E4: lw          $t3, 0x28($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X28);
    // 0x800274E8: negu        $t2, $t4
    ctx->r10 = SUB32(0, ctx->r12);
    // 0x800274EC: sll         $t6, $t2, 1
    ctx->r14 = S32(ctx->r10 << 1);
    // 0x800274F0: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800274F4: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x800274F8: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x800274FC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80027500: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x80027504: lbu         $t8, -0x15CC($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X15CC);
    // 0x80027508: beq         $t8, $zero, L_80027544
    if (ctx->r24 == 0) {
        // 0x8002750C: nop
    
            goto L_80027544;
    }
    // 0x8002750C: nop

    // 0x80027510: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80027514: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80027518: lbu         $t0, -0x15CD($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X15CD);
    // 0x8002751C: beq         $t0, $zero, L_80027544
    if (ctx->r8 == 0) {
        // 0x80027520: nop
    
            goto L_80027544;
    }
    // 0x80027520: nop

    // 0x80027524: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80027528: lh          $t5, 0x8($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X8);
    // 0x8002752C: negu        $t4, $t5
    ctx->r12 = SUB32(0, ctx->r13);
    // 0x80027530: sh          $t4, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r12;
    // 0x80027534: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80027538: lh          $t3, 0xA($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XA);
    // 0x8002753C: negu        $t6, $t3
    ctx->r14 = SUB32(0, ctx->r11);
    // 0x80027540: sh          $t6, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r14;
L_80027544:
    // 0x80027544: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80027548: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8002754C: bne         $t7, $t8, L_80027574
    if (ctx->r15 != ctx->r24) {
        // 0x80027550: nop
    
            goto L_80027574;
    }
    // 0x80027550: nop

    // 0x80027554: lh          $t9, 0x72($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X72);
    // 0x80027558: sh          $t9, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r25;
    // 0x8002755C: lh          $t0, 0x74($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X74);
    // 0x80027560: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x80027564: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x80027568: sh          $t5, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r13;
    // 0x8002756C: b           L_8002759C
    // 0x80027570: nop

        goto L_8002759C;
    // 0x80027570: nop

L_80027574:
    // 0x80027574: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80027578: addiu       $t4, $zero, 0xB8
    ctx->r12 = ADD32(0, 0XB8);
    // 0x8002757C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80027580: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80027584: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80027588: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8002758C: lh          $a3, 0x74($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X74);
    // 0x80027590: jal         0x80028328
    // 0x80027594: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_80028328(rdram, ctx);
        goto after_3;
    // 0x80027594: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_3:
    // 0x80027598: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_8002759C:
    // 0x8002759C: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800275A0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800275A4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800275A8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800275AC: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
    // 0x800275B0: jal         0x80028010
    // 0x800275B4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_80028010(rdram, ctx);
        goto after_4;
    // 0x800275B4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x800275B8: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x800275BC: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800275C0: lh          $t2, 0x8($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X8);
    // 0x800275C4: beq         $t2, $zero, L_80027654
    if (ctx->r10 == 0) {
        // 0x800275C8: nop
    
            goto L_80027654;
    }
    // 0x800275C8: nop

    // 0x800275CC: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800275D0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800275D4: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x800275D8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x800275DC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800275E0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800275E4: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x800275E8: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x800275EC: andi        $t5, $t0, 0xFFFF
    ctx->r13 = ctx->r8 & 0XFFFF;
    // 0x800275F0: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x800275F4: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800275F8: lh          $t3, 0x74($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X74);
    // 0x800275FC: lh          $t7, 0x72($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X72);
    // 0x80027600: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80027604: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x80027608: sll         $t2, $t6, 16
    ctx->r10 = S32(ctx->r14 << 16);
    // 0x8002760C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80027610: or          $t9, $t2, $t8
    ctx->r25 = ctx->r10 | ctx->r24;
    // 0x80027614: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80027618: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8002761C: lw          $t4, 0x24($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X24);
    // 0x80027620: bne         $t4, $zero, L_80027654
    if (ctx->r12 != 0) {
        // 0x80027624: nop
    
            goto L_80027654;
    }
    // 0x80027624: nop

    // 0x80027628: lw          $t1, 0x20($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X20);
    // 0x8002762C: bne         $t1, $zero, L_80027654
    if (ctx->r9 != 0) {
        // 0x80027630: nop
    
            goto L_80027654;
    }
    // 0x80027630: nop

    // 0x80027634: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80027638: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8002763C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80027640: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x80027644: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
    // 0x80027648: jal         0x80028520
    // 0x8002764C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_80028520(rdram, ctx);
        goto after_5;
    // 0x8002764C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_5:
    // 0x80027650: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_80027654:
    // 0x80027654: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80027658: lh          $t7, 0xA($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XA);
    // 0x8002765C: beq         $t7, $zero, L_800276D0
    if (ctx->r15 == 0) {
        // 0x80027660: nop
    
            goto L_800276D0;
    }
    // 0x80027660: nop

    // 0x80027664: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80027668: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x8002766C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80027670: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80027674: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80027678: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8002767C: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80027680: lhu         $t0, 0xA($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XA);
    // 0x80027684: andi        $t4, $t0, 0xFFFF
    ctx->r12 = ctx->r8 & 0XFFFF;
    // 0x80027688: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8002768C: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80027690: lh          $t3, 0x72($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X72);
    // 0x80027694: lh          $t2, 0x74($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X74);
    // 0x80027698: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8002769C: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x800276A0: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800276A4: andi        $t8, $t2, 0xFFFF
    ctx->r24 = ctx->r10 & 0XFFFF;
    // 0x800276A8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800276AC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800276B0: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800276B4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800276B8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800276BC: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800276C0: lh          $a3, 0x74($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X74);
    // 0x800276C4: jal         0x80028520
    // 0x800276C8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_80028520(rdram, ctx);
        goto after_6;
    // 0x800276C8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_6:
    // 0x800276CC: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_800276D0:
    // 0x800276D0: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800276D4: lw          $t1, 0x20($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X20);
    // 0x800276D8: beq         $t1, $zero, L_800276FC
    if (ctx->r9 == 0) {
        // 0x800276DC: nop
    
            goto L_800276FC;
    }
    // 0x800276DC: nop

    // 0x800276E0: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800276E4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800276E8: lh          $a2, 0x72($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X72);
    // 0x800276EC: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x800276F0: jal         0x800286FC
    // 0x800276F4: lw          $a0, 0x20($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X20);
    func_800286FC(rdram, ctx);
        goto after_7;
    // 0x800276F4: lw          $a0, 0x20($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X20);
    after_7:
    // 0x800276F8: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_800276FC:
    // 0x800276FC: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80027700: lw          $t2, 0x24($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X24);
    // 0x80027704: bne         $t2, $zero, L_8002772C
    if (ctx->r10 != 0) {
        // 0x80027708: nop
    
            goto L_8002772C;
    }
    // 0x80027708: nop

    // 0x8002770C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80027710: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80027714: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80027718: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8002771C: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
    // 0x80027720: jal         0x80028520
    // 0x80027724: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80028520(rdram, ctx);
        goto after_8;
    // 0x80027724: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_8:
    // 0x80027728: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_8002772C:
    // 0x8002772C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80027730: lh          $t9, 0xC($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XC);
    // 0x80027734: beq         $t9, $zero, L_800278C0
    if (ctx->r25 == 0) {
        // 0x80027738: nop
    
            goto L_800278C0;
    }
    // 0x80027738: nop

    // 0x8002773C: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80027740: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80027744: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x80027748: lbu         $t4, -0x15CD($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X15CD);
    // 0x8002774C: beq         $t4, $zero, L_800277A8
    if (ctx->r12 == 0) {
        // 0x80027750: nop
    
            goto L_800277A8;
    }
    // 0x80027750: nop

    // 0x80027754: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80027758: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x8002775C: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x80027760: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80027764: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80027768: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8002776C: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80027770: lhu         $t6, 0xC($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0XC);
    // 0x80027774: andi        $t2, $t6, 0xFFFF
    ctx->r10 = ctx->r14 & 0XFFFF;
    // 0x80027778: or          $t7, $t2, $at
    ctx->r15 = ctx->r10 | ctx->r1;
    // 0x8002777C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80027780: lh          $t9, 0x72($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X72);
    // 0x80027784: lh          $t5, 0x6E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6E);
    // 0x80027788: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8002778C: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80027790: sll         $t4, $t0, 16
    ctx->r12 = S32(ctx->r8 << 16);
    // 0x80027794: andi        $t1, $t5, 0xFFFF
    ctx->r9 = ctx->r13 & 0XFFFF;
    // 0x80027798: or          $t3, $t4, $t1
    ctx->r11 = ctx->r12 | ctx->r9;
    // 0x8002779C: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800277A0: b           L_800278C0
    // 0x800277A4: nop

        goto L_800278C0;
    // 0x800277A4: nop

L_800277A8:
    // 0x800277A8: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800277AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800277B0: lwc1        $f8, 0x1CE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1CE0);
    // 0x800277B4: lh          $t7, 0xC($t2)
    ctx->r15 = MEM_H(ctx->r10, 0XC);
    // 0x800277B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800277BC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800277C0: nop

    // 0x800277C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800277C8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800277CC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800277D0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800277D4: nop

    // 0x800277D8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800277DC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800277E0: nop

    // 0x800277E4: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800277E8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800277EC: beq         $t9, $zero, L_80027840
    if (ctx->r25 == 0) {
        // 0x800277F0: nop
    
            goto L_80027840;
    }
    // 0x800277F0: nop

    // 0x800277F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800277F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800277FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80027800: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80027804: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80027808: nop

    // 0x8002780C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80027810: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80027814: nop

    // 0x80027818: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8002781C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80027820: bne         $t9, $zero, L_80027838
    if (ctx->r25 != 0) {
        // 0x80027824: nop
    
            goto L_80027838;
    }
    // 0x80027824: nop

    // 0x80027828: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8002782C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80027830: b           L_80027850
    // 0x80027834: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80027850;
    // 0x80027834: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80027838:
    // 0x80027838: b           L_80027850
    // 0x8002783C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80027850;
    // 0x8002783C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80027840:
    // 0x80027840: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80027844: nop

    // 0x80027848: bltz        $t9, L_80027838
    if (SIGNED(ctx->r25) < 0) {
        // 0x8002784C: nop
    
            goto L_80027838;
    }
    // 0x8002784C: nop

L_80027850:
    // 0x80027850: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80027854: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80027858: nop

    // 0x8002785C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80027860: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80027864: sltu        $at, $t0, $at
    ctx->r1 = ctx->r8 < ctx->r1 ? 1 : 0;
    // 0x80027868: bne         $at, $zero, L_80027878
    if (ctx->r1 != 0) {
        // 0x8002786C: nop
    
            goto L_80027878;
    }
    // 0x8002786C: nop

    // 0x80027870: addiu       $t5, $zero, 0x7FFF
    ctx->r13 = ADD32(0, 0X7FFF);
    // 0x80027874: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_80027878:
    // 0x80027878: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8002787C: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x80027880: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x80027884: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80027888: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
    // 0x8002788C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80027890: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80027894: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x80027898: or          $t2, $t6, $at
    ctx->r10 = ctx->r14 | ctx->r1;
    // 0x8002789C: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800278A0: lh          $t8, 0x72($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X72);
    // 0x800278A4: lh          $t5, 0x6E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6E);
    // 0x800278A8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800278AC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800278B0: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x800278B4: andi        $t4, $t5, 0xFFFF
    ctx->r12 = ctx->r13 & 0XFFFF;
    // 0x800278B8: or          $t1, $t0, $t4
    ctx->r9 = ctx->r8 | ctx->r12;
    // 0x800278BC: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
L_800278C0:
    // 0x800278C0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800278C4: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800278C8: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800278CC: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800278D0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800278D4: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x800278D8: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x800278DC: sll         $t4, $t0, 1
    ctx->r12 = S32(ctx->r8 << 1);
    // 0x800278E0: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x800278E4: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x800278E8: lh          $t3, 0x76($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X76);
    // 0x800278EC: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800278F0: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x800278F4: sh          $t2, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r10;
    // 0x800278F8: lbu         $t5, 0x8($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X8);
    // 0x800278FC: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x80027900: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80027904: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80027908: bne         $at, $zero, L_80027480
    if (ctx->r1 != 0) {
        // 0x8002790C: nop
    
            goto L_80027480;
    }
    // 0x8002790C: nop

L_80027910:
    // 0x80027910: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80027914: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80027918: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8002791C: lbu         $t9, -0x15CD($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X15CD);
    // 0x80027920: beq         $t9, $zero, L_800279F8
    if (ctx->r25 == 0) {
        // 0x80027924: nop
    
            goto L_800279F8;
    }
    // 0x80027924: nop

    // 0x80027928: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8002792C: bne         $t4, $zero, L_800279F8
    if (ctx->r12 != 0) {
        // 0x80027930: nop
    
            goto L_800279F8;
    }
    // 0x80027930: nop

    // 0x80027934: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80027938: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8002793C: addiu       $t3, $zero, 0xB8
    ctx->r11 = ADD32(0, 0XB8);
    // 0x80027940: lw          $a2, 0x2C($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X2C);
    // 0x80027944: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80027948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002794C: lh          $a3, 0x70($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X70);
    // 0x80027950: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80027954: jal         0x80028328
    // 0x80027958: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    func_80028328(rdram, ctx);
        goto after_9;
    // 0x80027958: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_9:
    // 0x8002795C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80027960: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80027964: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80027968: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8002796C: lbu         $t8, -0x15CC($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X15CC);
    // 0x80027970: beq         $t8, $zero, L_800279B8
    if (ctx->r24 == 0) {
        // 0x80027974: nop
    
            goto L_800279B8;
    }
    // 0x80027974: nop

    // 0x80027978: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8002797C: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x80027980: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x80027984: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80027988: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002798C: lui         $t0, 0xC00
    ctx->r8 = S32(0XC00 << 16);
    // 0x80027990: ori         $t0, $t0, 0x5A82
    ctx->r8 = ctx->r8 | 0X5A82;
    // 0x80027994: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80027998: lh          $t4, 0x6E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6E);
    // 0x8002799C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800279A0: andi        $t1, $t4, 0xFFFF
    ctx->r9 = ctx->r12 & 0XFFFF;
    // 0x800279A4: sll         $t3, $t1, 16
    ctx->r11 = S32(ctx->r9 << 16);
    // 0x800279A8: ori         $t2, $t3, 0x650
    ctx->r10 = ctx->r11 | 0X650;
    // 0x800279AC: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
    // 0x800279B0: b           L_800279F0
    // 0x800279B4: nop

        goto L_800279F0;
    // 0x800279B4: nop

L_800279B8:
    // 0x800279B8: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800279BC: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x800279C0: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800279C4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800279C8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800279CC: lui         $t5, 0xC00
    ctx->r13 = S32(0XC00 << 16);
    // 0x800279D0: ori         $t5, $t5, 0x5A82
    ctx->r13 = ctx->r13 | 0X5A82;
    // 0x800279D4: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800279D8: lh          $t9, 0x6E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6E);
    // 0x800279DC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800279E0: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800279E4: sll         $t1, $t4, 16
    ctx->r9 = S32(ctx->r12 << 16);
    // 0x800279E8: ori         $t3, $t1, 0x4E0
    ctx->r11 = ctx->r9 | 0X4E0;
    // 0x800279EC: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
L_800279F0:
    // 0x800279F0: b           L_800279F8
    // 0x800279F4: nop

        goto L_800279F8;
    // 0x800279F4: nop

L_800279F8:
    // 0x800279F8: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800279FC: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x80027A00: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80027A04: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80027A08: lh          $t7, 0x6E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6E);
    // 0x80027A0C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80027A10: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80027A14: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80027A18: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x80027A1C: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x80027A20: or          $t0, $t5, $at
    ctx->r8 = ctx->r13 | ctx->r1;
    // 0x80027A24: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80027A28: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80027A2C: lui         $t4, 0x7C0
    ctx->r12 = S32(0X7C0 << 16);
    // 0x80027A30: ori         $t4, $t4, 0x170
    ctx->r12 = ctx->r12 | 0X170;
    // 0x80027A34: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x80027A38: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80027A3C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80027A40: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x80027A44: addu        $t8, $t3, $t6
    ctx->r24 = ADD32(ctx->r11, ctx->r14);
    // 0x80027A48: lw          $t7, 0x28($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X28);
    // 0x80027A4C: addiu       $t5, $t7, 0x170
    ctx->r13 = ADD32(ctx->r15, 0X170);
    // 0x80027A50: sw          $t5, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r13;
    // 0x80027A54: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80027A58: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80027A5C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80027A60: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80027A64: addu        $t1, $t0, $t4
    ctx->r9 = ADD32(ctx->r8, ctx->r12);
    // 0x80027A68: lw          $t3, 0x20($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X20);
    // 0x80027A6C: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x80027A70: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80027A74: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x80027A78: sltu        $at, $t5, $t2
    ctx->r1 = ctx->r13 < ctx->r10 ? 1 : 0;
    // 0x80027A7C: beq         $at, $zero, L_80027AA8
    if (ctx->r1 == 0) {
        // 0x80027A80: nop
    
            goto L_80027AA8;
    }
    // 0x80027A80: nop

    // 0x80027A84: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80027A88: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80027A8C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80027A90: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80027A94: addu        $t1, $t8, $t4
    ctx->r9 = ADD32(ctx->r24, ctx->r12);
    // 0x80027A98: lw          $t0, 0x28($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X28);
    // 0x80027A9C: sll         $t3, $t6, 1
    ctx->r11 = S32(ctx->r14 << 1);
    // 0x80027AA0: subu        $t7, $t0, $t3
    ctx->r15 = SUB32(ctx->r8, ctx->r11);
    // 0x80027AA4: sw          $t7, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r15;
L_80027AA8:
    // 0x80027AA8: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x80027AAC: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80027AB0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80027AB4: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x80027AB8: lbu         $t4, -0x15CD($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X15CD);
    // 0x80027ABC: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x80027AC0: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x80027AC4: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x80027AC8: beq         $at, $zero, L_80027430
    if (ctx->r1 == 0) {
        // 0x80027ACC: nop
    
            goto L_80027430;
    }
    // 0x80027ACC: nop

    // 0x80027AD0: b           L_80027AE0
    // 0x80027AD4: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_80027AE0;
    // 0x80027AD4: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x80027AD8: b           L_80027AE0
    // 0x80027ADC: nop

        goto L_80027AE0;
    // 0x80027ADC: nop

L_80027AE0:
    // 0x80027AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80027AE4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80027AE8: jr          $ra
    // 0x80027AEC: nop

    return;
    // 0x80027AEC: nop

;}
