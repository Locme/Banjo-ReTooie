#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _subaddievolume_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FA8: syscall     819
    recomp_syscall_handler(rdram, ctx, 0x80089FA8);
    return;
    // 0x80089FAC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800BE0_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800BE4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2372, 0X10FC) << 16);
    // 0x80800BE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BF0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800BF4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800BF8: addiu       $t7, $t7, 0x10FC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2372, 0X10FC));
    // 0x80800BFC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800C00: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x80800C04: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800C08: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800C0C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800C10: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800C14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C18: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800C1C: jal         0x80100094
    // 0x80800C20: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C20: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x80800C24: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800C28: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C2C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800C30: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C34: jal         0x800DC178
    // 0x80800C38: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800C38: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800C3C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80800C40: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C44: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80800C48: addu        $s0, $t1, $t3
    ctx->r16 = ADD32(ctx->r9, ctx->r11);
    // 0x80800C4C: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80800C50: jal         0x800DC090
    // 0x80800C54: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    func_800DC090(rdram, ctx);
        goto after_2;
    // 0x80800C54: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x80800C58: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x80800C5C: beq         $t4, $zero, L_80800C7C
    if (ctx->r12 == 0) {
        // 0x80800C60: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800C7C;
    }
    // 0x80800C60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800C64: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800C68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800C6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800C70: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80800C74: b           L_80800C8C
    // 0x80800C78: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
        goto L_80800C8C;
    // 0x80800C78: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
L_80800C7C:
    // 0x80800C7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C80: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800C84: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80800C88: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_80800C8C:
    // 0x80800C8C: jal         0x800D7520
    // 0x80800C90: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    func_800D7520(rdram, ctx);
        goto after_3;
    // 0x80800C90: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_3:
    // 0x80800C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C98: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80800C9C: jal         0x800C7A68
    // 0x80800CA0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800C7A68(rdram, ctx);
        goto after_4;
    // 0x80800CA0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80800CA4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800CA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800CAC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800CB0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800CB4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80800CB8: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80800CBC: bne         $a0, $zero, L_80800CE0
    if (ctx->r4 != 0) {
        // 0x80800CC0: nop
    
            goto L_80800CE0;
    }
    // 0x80800CC0: nop

    // 0x80800CC4: jal         0x800C8A98
    // 0x80800CC8: nop

    func_800C8A98(rdram, ctx);
        goto after_5;
    // 0x80800CC8: nop

    after_5:
    // 0x80800CCC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80800CD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CD4: jal         0x800C8F64
    // 0x80800CD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C8F64(rdram, ctx);
        goto after_6;
    // 0x80800CD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800CDC: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
L_80800CE0:
    // 0x80800CE0: jal         0x800C8FE0
    // 0x80800CE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_7;
    // 0x80800CE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800CE8: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80800CEC: jal         0x800C8E84
    // 0x80800CF0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800C8E84(rdram, ctx);
        goto after_8;
    // 0x80800CF0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_8:
    // 0x80800CF4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80800CF8: jal         0x800C8CB8
    // 0x80800CFC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800C8CB8(rdram, ctx);
        goto after_9;
    // 0x80800CFC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x80800D00: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80800D04: jal         0x800C8D4C
    // 0x80800D08: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    func_800C8D4C(rdram, ctx);
        goto after_10;
    // 0x80800D08: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    after_10:
    // 0x80800D0C: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80800D10: lw          $t5, 0x34($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X34);
    // 0x80800D14: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x80800D18: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
    // 0x80800D1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D24: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800D28: jr          $ra
    // 0x80800D2C: nop

    return;
    // 0x80800D2C: nop

;}
RECOMP_FUNC void _fxleaves_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088958: syscall     711
    recomp_syscall_handler(rdram, ctx, 0x80088958);
    return;
    // 0x8008895C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800C9C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9C08: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800C9C0C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9C10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C9C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9C18: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800C9C1C: jal         0x800C9E20
    // 0x800C9C20: addiu       $a1, $a1, -0x668C
    ctx->r5 = ADD32(ctx->r5, -0X668C);
    func_800C9E20(rdram, ctx);
        goto after_0;
    // 0x800C9C20: addiu       $a1, $a1, -0x668C
    ctx->r5 = ADD32(ctx->r5, -0X668C);
    after_0:
    // 0x800C9C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9C2C: jr          $ra
    // 0x800C9C30: nop

    return;
    // 0x800C9C30: nop

;}
RECOMP_FUNC void func_8080021C_chtntdetonator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800224: jal         0x8010D278
    // 0x80800228: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8010D278(rdram, ctx);
        goto after_0;
    // 0x80800228: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080022C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80800230: bne         $v0, $at, L_808002C8
    if (ctx->r2 != ctx->r1) {
        // 0x80800234: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808002C8;
    }
    // 0x80800234: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800238: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x8080023C: jal         0x800EEEA8
    // 0x80800240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EEEA8(rdram, ctx);
        goto after_1;
    // 0x80800240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800244: bnel        $v0, $zero, L_808002CC
    if (ctx->r2 != 0) {
        // 0x80800248: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002CC;
    }
    goto skip_0;
    // 0x80800248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080024C: jal         0x8010D254
    // 0x80800250: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D254(rdram, ctx);
        goto after_2;
    // 0x80800250: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80800254: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800258: jal         0x800EFC7C
    // 0x8080025C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EFC7C(rdram, ctx);
        goto after_3;
    // 0x8080025C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80800260: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(904, 0X684) << 16);
    // 0x80800264: lwc1        $f4, 0x684($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(904, 0X684));
    // 0x80800268: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8080026C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800270: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800274: nop

    // 0x80800278: bc1fl       L_808002CC
    if (!c1cs) {
        // 0x8080027C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002CC;
    }
    goto skip_1;
    // 0x8080027C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800280: lwc1        $f0, 0x1C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80800284: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800288: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080028C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80800290: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800294: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80800298: nop

    // 0x8080029C: bc1fl       L_808002CC
    if (!c1cs) {
        // 0x808002A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002CC;
    }
    goto skip_2;
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x808002A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808002A8: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x808002AC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808002B0: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x808002B4: nop

    // 0x808002B8: bc1fl       L_808002CC
    if (!c1cs) {
        // 0x808002BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002CC;
    }
    goto skip_3;
    // 0x808002BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x808002C0: jal         0x800904F4
    // 0x808002C4: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_800904F4(rdram, ctx);
        goto after_4;
    // 0x808002C4: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_4:
L_808002C8:
    // 0x808002C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002CC:
    // 0x808002CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002D0: jr          $ra
    // 0x808002D4: nop

    return;
    // 0x808002D4: nop

;}
RECOMP_FUNC void bsdronejump_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001F8: jal         0x80084DD8
    // 0x808001FC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bamovegoto_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808001FC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800200: beq         $v0, $zero, L_80800214
    if (ctx->r2 == 0) {
        // 0x80800204: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800214;
    }
    // 0x80800204: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800208: jal         0x80084750
    // 0x8080020C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _badata_entrypoint_34(rdram, ctx);
        goto after_1;
    // 0x8080020C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800210: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800214:
    // 0x80800214: jal         0x8009E5C8
    // 0x80800218: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800218: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080021C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800220: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800224: jr          $ra
    // 0x80800228: nop

    return;
    // 0x80800228: nop

    // 0x8080022C: nop

;}
RECOMP_FUNC void func_80800B5C_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800B68: jal         0x80107B70
    // 0x80800B6C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80107B70(rdram, ctx);
        goto after_0;
    // 0x80800B6C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800B70: beq         $v0, $zero, L_80800BAC
    if (ctx->r2 == 0) {
        // 0x80800B74: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800BAC;
    }
    // 0x80800B74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B78: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800B7C: jal         0x800EEB40
    // 0x80800B80: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x80800B80: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800B84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1516, 0XF44) << 16);
    // 0x80800B88: lwc1        $f4, 0xF44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1516, 0XF44));
    // 0x80800B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800B90: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800B94: nop

    // 0x80800B98: bc1fl       L_80800BB4
    if (!c1cs) {
        // 0x80800B9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800BB4;
    }
    goto skip_0;
    // 0x80800B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800BA4: b           L_80800BB4
    // 0x80800BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800BB4;
    // 0x80800BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BAC:
    // 0x80800BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BB4:
    // 0x80800BB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BB8: jr          $ra
    // 0x80800BBC: nop

    return;
    // 0x80800BBC: nop

;}
RECOMP_FUNC void baswim_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800510: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800514: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800518: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080051C: jal         0x8009BFCC
    // 0x80800520: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009BFCC(rdram, ctx);
        goto after_0;
    // 0x80800520: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800524: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800528: jal         0x8009C984
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800530: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800534: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800538: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080053C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80800540: lw          $t6, 0x134($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X134);
    // 0x80800544: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800548: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8080054C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80800550: jal         0x800EF4E4
    // 0x80800554: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_2;
    // 0x80800554: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800558: jal         0x800D8FF8
    // 0x8080055C: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x8080055C: nop

    after_3:
    // 0x80800560: lw          $v0, 0x134($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X134);
    // 0x80800564: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800568: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080056C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800570: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800574: jal         0x800F0E00
    // 0x80800578: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    func_800F0E00(rdram, ctx);
        goto after_4;
    // 0x80800578: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    after_4:
    // 0x8080057C: lw          $t7, 0x134($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X134);
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800588: jal         0x8009B94C
    // 0x8080058C: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    func_8009B94C(rdram, ctx);
        goto after_5;
    // 0x8080058C: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    after_5:
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800594: jal         0x8009BA9C
    // 0x80800598: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8009BA9C(rdram, ctx);
        goto after_6;
    // 0x80800598: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x8080059C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808005A8: jr          $ra
    // 0x808005AC: nop

    return;
    // 0x808005AC: nop

;}
RECOMP_FUNC void func_80801378_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080137C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801380: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801384: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80801388: jal         0x800D0B68
    // 0x8080138C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_0;
    // 0x8080138C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801390: bne         $v0, $zero, L_808013E8
    if (ctx->r2 != 0) {
        // 0x80801394: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808013E8;
    }
    // 0x80801394: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801398: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x8080139C: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808013A0: bgezl       $t8, L_808013EC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808013A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013EC;
    }
    goto skip_0;
    // 0x808013A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808013A8: jal         0x80100094
    // 0x808013AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808013AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808013B0: jal         0x8008A040
    // 0x808013B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808013B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808013B8: beq         $v0, $zero, L_808013E8
    if (ctx->r2 == 0) {
        // 0x808013BC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808013E8;
    }
    // 0x808013BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808013C0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x808013C4: jal         0x80801740
    // 0x808013C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80801740_chfantasyeyeball(rdram, ctx);
        goto after_3;
    // 0x808013C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x808013CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808013D0: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x808013D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808013D8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808013DC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808013E0: jal         0x8010C964
    // 0x808013E4: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    func_8010C964(rdram, ctx);
        goto after_4;
    // 0x808013E4: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    after_4:
L_808013E8:
    // 0x808013E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013EC:
    // 0x808013EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013F0: jr          $ra
    // 0x808013F4: nop

    return;
    // 0x808013F4: nop

;}
RECOMP_FUNC void _ncpoducam_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089660: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089660);
    return;
    // 0x80089664: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chshockjump_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F4: jal         0x80106790
    // 0x808000F8: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808000F8: nop

    after_0:
    // 0x808000FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800100: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80800104: lw          $a3, 0x48($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X48);
    // 0x80800108: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8080010C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800114: addiu       $a1, $zero, 0x756
    ctx->r5 = ADD32(0, 0X756);
    // 0x80800118: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x8080011C: jal         0x80086680
    // 0x80800120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800124: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800128: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(688, 0X340) << 16);
    // 0x8080012C: addiu       $a2, $a2, 0x340
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(688, 0X340));
    // 0x80800130: jal         0x80089D18
    // 0x80800134: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800134: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080013C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void func_808009F0_chflowerbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808009F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A00: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800A04: jal         0x800D8FF8
    // 0x80800A08: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800A08: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800A0C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800A10: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A18: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x80800A1C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800A20: bgez        $t8, L_80800A80
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800A24: nop
    
            goto L_80800A80;
    }
    // 0x80800A24: nop

    // 0x80800A28: jal         0x80089BF0
    // 0x80800A2C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800A2C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80800A30: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800A34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A38: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800A3C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800A48: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800A4C: jal         0x80102B2C
    // 0x80800A50: nop

    func_80102B2C(rdram, ctx);
        goto after_2;
    // 0x80800A50: nop

    after_2:
    // 0x80800A54: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800A58: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800A5C: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x80800A60: ori         $a1, $a1, 0x5025
    ctx->r5 = ctx->r5 | 0X5025;
    // 0x80800A64: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A6C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800A70: jal         0x8010C3A8
    // 0x80800A74: nop

    func_8010C3A8(rdram, ctx);
        goto after_3;
    // 0x80800A74: nop

    after_3:
    // 0x80800A78: b           L_80800B00
    // 0x80800A7C: nop

        goto L_80800B00;
    // 0x80800A7C: nop

L_80800A80:
    // 0x80800A80: jal         0x80089F78
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A88: beq         $v0, $zero, L_80800AD0
    if (ctx->r2 == 0) {
        // 0x80800A8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AD0;
    }
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A90: jal         0x80102D78
    // 0x80800A94: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_5;
    // 0x80800A94: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_5:
    // 0x80800A98: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800A9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800AA0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800AA4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800AA8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800AAC: addiu       $t9, $zero, 0x5000
    ctx->r25 = ADD32(0, 0X5000);
    // 0x80800AB0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800AB4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ABC: jal         0x80089F90
    // 0x80800AC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800AC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800AC4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800AC8: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x80800ACC: sw          $t1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r9;
L_80800AD0:
    // 0x80800AD0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800AD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800AD8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800AE4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800AE8: jal         0x80102B2C
    // 0x80800AEC: nop

    func_80102B2C(rdram, ctx);
        goto after_7;
    // 0x80800AEC: nop

    after_7:
    // 0x80800AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF4: addiu       $a1, $zero, 0x5325
    ctx->r5 = ADD32(0, 0X5325);
    // 0x80800AF8: jal         0x8010C3A8
    // 0x80800AFC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_8010C3A8(rdram, ctx);
        goto after_8;
    // 0x80800AFC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_8:
L_80800B00:
    // 0x80800B00: jal         0x808008D4
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008D4_chflowerbaddie(rdram, ctx);
        goto after_9;
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800B08: beql        $v0, $zero, L_80800B30
    if (ctx->r2 == 0) {
        // 0x80800B0C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800B30;
    }
    goto skip_0;
    // 0x80800B0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800B10: jal         0x80089D40
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B1C: jal         0x80102424
    // 0x80800B20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800B20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800B24: b           L_80800B30
    // 0x80800B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B30;
    // 0x80800B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B30:
    // 0x80800B30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B34: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B3C: jr          $ra
    // 0x80800B40: nop

    return;
    // 0x80800B40: nop

    // 0x80800B44: nop

    // 0x80800B48: nop

    // 0x80800B4C: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BB0: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BB0);
    return;
    // 0x80087BB4: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D00: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089D00);
    return;
    // 0x80089D04: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void subaddiedialog_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801334: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080133C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801340: sh          $a1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r5;
    // 0x80801344: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    // 0x80801348: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8080134C: jal         0x8010114C
    // 0x80801350: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80801350: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_0:
    // 0x80801354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080135C: jr          $ra
    // 0x80801360: nop

    return;
    // 0x80801360: nop

;}
RECOMP_FUNC void _chskeletonexplode_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E28: syscall     459
    recomp_syscall_handler(rdram, ctx, 0x80086E28);
    return;
    // 0x80086E2C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void sumole_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808012A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808012A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808012AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808012B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808012B4: beq         $a2, $at, L_80801334
    if (ctx->r6 == ctx->r1) {
        // 0x808012B8: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80801334;
    }
    // 0x808012B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808012BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808012C0: bnel        $a1, $at, L_808012E8
    if (ctx->r5 != ctx->r1) {
        // 0x808012C4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_808012E8;
    }
    goto skip_0;
    // 0x808012C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x808012C8: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
    // 0x808012CC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x808012D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808012D4: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x808012D8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808012DC: b           L_80801364
    // 0x808012E0: sb          $t1, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r9;
        goto L_80801364;
    // 0x808012E0: sb          $t1, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r9;
    // 0x808012E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_808012E8:
    // 0x808012E8: jal         0x80090178
    // 0x808012EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80090178(rdram, ctx);
        goto after_0;
    // 0x808012EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808012F0: beq         $v0, $zero, L_80801314
    if (ctx->r2 == 0) {
        // 0x808012F4: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_80801314;
    }
    // 0x808012F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808012F8: lbu         $t5, 0x72($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X72);
    // 0x808012FC: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x80801300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801304: andi        $t6, $t5, 0xFF03
    ctx->r14 = ctx->r13 & 0XFF03;
    // 0x80801308: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8080130C: b           L_80801364
    // 0x80801310: sb          $t7, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r15;
        goto L_80801364;
    // 0x80801310: sb          $t7, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r15;
L_80801314:
    // 0x80801314: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80801318: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
    // 0x8080131C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80801320: andi        $t3, $t2, 0xFF03
    ctx->r11 = ctx->r10 & 0XFF03;
    // 0x80801324: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x80801328: sb          $t5, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r13;
    // 0x8080132C: b           L_80801364
    // 0x80801330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801364;
    // 0x80801330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801334:
    // 0x80801334: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801338: bne         $a1, $at, L_80801348
    if (ctx->r5 != ctx->r1) {
        // 0x8080133C: nop
    
            goto L_80801348;
    }
    // 0x8080133C: nop

    // 0x80801340: b           L_80801364
    // 0x80801344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801364;
    // 0x80801344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801348:
    // 0x80801348: jal         0x80090178
    // 0x8080134C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80090178(rdram, ctx);
        goto after_1;
    // 0x8080134C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80801350: beql        $v0, $zero, L_80801364
    if (ctx->r2 == 0) {
        // 0x80801354: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801364;
    }
    goto skip_1;
    // 0x80801354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80801358: b           L_80801364
    // 0x8080135C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801364;
    // 0x8080135C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801364:
    // 0x80801364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801368: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080136C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801370: jr          $ra
    // 0x80801374: nop

    return;
    // 0x80801374: nop

;}
RECOMP_FUNC void func_80800600_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800600: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800608: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8080060C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800610: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800614: jal         0x80100094
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080061C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800620: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800624: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80800628: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080062C: jal         0x800EEAD4
    // 0x80800630: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EEAD4(rdram, ctx);
        goto after_1;
    // 0x80800630: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800634: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800638: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8080063C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800640: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80800644: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    // 0x80800648: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8080064C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800650: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800654: jal         0x800EEC30
    // 0x80800658: nop

    func_800EEC30(rdram, ctx);
        goto after_2;
    // 0x80800658: nop

    after_2:
    // 0x8080065C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800660: jal         0x800EF04C
    // 0x80800664: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80800664: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800668: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8080066C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1004, 0X998) << 16);
    // 0x80800670: addiu       $a1, $a1, 0x998
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1004, 0X998));
    // 0x80800674: beq         $t6, $zero, L_808006A4
    if (ctx->r14 == 0) {
        // 0x80800678: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_808006A4;
    }
    // 0x80800678: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8080067C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1004, 0X9A4) << 16);
    // 0x80800680: addiu       $a2, $a2, 0x9A4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1004, 0X9A4));
    // 0x80800684: jal         0x800F3214
    // 0x80800688: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    func_800F3214(rdram, ctx);
        goto after_4;
    // 0x80800688: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x8080068C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800690: jal         0x800C8E84
    // 0x80800694: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800C8E84(rdram, ctx);
        goto after_5;
    // 0x80800694: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x80800698: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080069C: jal         0x800C8CB8
    // 0x808006A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800C8CB8(rdram, ctx);
        goto after_6;
    // 0x808006A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
L_808006A4:
    // 0x808006A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808006B0: jr          $ra
    // 0x808006B4: nop

    return;
    // 0x808006B4: nop

;}
RECOMP_FUNC void _bsvanswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841A8: syscall     106
    recomp_syscall_handler(rdram, ctx, 0x800841A8);
    return;
    // 0x800841AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808001C0_bawobble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808001C4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808001C8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x808001CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808001D0: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x808001D4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x808001D8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x808001DC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808001E0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808001E4: jal         0x80092AD8
    // 0x808001E8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    func_80092AD8(rdram, ctx);
        goto after_0;
    // 0x808001E8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001EC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x808001F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001F4: jal         0x800E0AF0
    // 0x808001F8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_1;
    // 0x808001F8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_1:
    // 0x808001FC: lw          $a0, 0x154($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X154);
    // 0x80800200: jal         0x800D91B8
    // 0x80800204: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800D91B8(rdram, ctx);
        goto after_2;
    // 0x80800204: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_2:
    // 0x80800208: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080020C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800210: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(646, 0X3E0) << 16);
    // 0x80800214: lwc1        $f20, 0x3E0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(646, 0X3E0));
    // 0x80800218: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080021C: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x80800220: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_80800224:
    // 0x80800224: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x80800228: lw          $t6, 0x154($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X154);
    // 0x8080022C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800230: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800234: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80800238: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x8080023C: nop

    // 0x80800240: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80800244: jal         0x800F101C
    // 0x80800248: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    func_800F101C(rdram, ctx);
        goto after_3;
    // 0x80800248: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_3:
    // 0x8080024C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x80800250: lw          $v0, 0x154($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X154);
    // 0x80800254: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800258: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8080025C: jal         0x800F1214
    // 0x80800260: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    func_800F1214(rdram, ctx);
        goto after_4;
    // 0x80800260: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    after_4:
    // 0x80800264: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800268: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8080026C: bne         $s0, $s3, L_80800224
    if (ctx->r16 != ctx->r19) {
        // 0x80800270: swc1        $f0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f0.u32l;
            goto L_80800224;
    }
    // 0x80800270: swc1        $f0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80800274: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800278: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8080027C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800280: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800284: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80800288: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8080028C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800290: jal         0x800E0B8C
    // 0x80800294: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_5;
    // 0x80800294: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80800298: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8080029C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808002A0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808002A4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x808002A8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x808002AC: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x808002B0: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x808002B4: jr          $ra
    // 0x808002B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808002B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _bafly_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C58: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C58);
    return;
    // 0x80084C5C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_8080016C_chtimetable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800174: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800178: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080017C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800180: jal         0x800DA298
    // 0x80800184: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800184: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_0:
    // 0x80800188: bne         $v0, $zero, L_80800198
    if (ctx->r2 != 0) {
        // 0x8080018C: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80800198;
    }
    // 0x8080018C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800190: b           L_8080024C
    // 0x80800194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080024C;
    // 0x80800194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800198:
    // 0x80800198: addiu       $at, $zero, 0x12A
    ctx->r1 = ADD32(0, 0X12A);
    // 0x8080019C: bne         $t6, $at, L_808001BC
    if (ctx->r14 != ctx->r1) {
        // 0x808001A0: nop
    
            goto L_808001BC;
    }
    // 0x808001A0: nop

    // 0x808001A4: jal         0x800DA298
    // 0x808001A8: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808001A8: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    after_1:
    // 0x808001AC: bne         $v0, $zero, L_808001BC
    if (ctx->r2 != 0) {
        // 0x808001B0: nop
    
            goto L_808001BC;
    }
    // 0x808001B0: nop

    // 0x808001B4: b           L_8080024C
    // 0x808001B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080024C;
    // 0x808001B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001BC:
    // 0x808001BC: jal         0x808000B0
    // 0x808001C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808000B0_chtimetable(rdram, ctx);
        goto after_2;
    // 0x808001C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808001C4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x808001C8: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001CC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1592, 0X730) << 16);
    // 0x808001D0: addiu       $a1, $a1, 0x730
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1592, 0X730));
    // 0x808001D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808001DC: mflo        $t7
    ctx->r15 = lo;
    // 0x808001E0: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x808001E4: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x808001E8: beql        $t9, $at, L_8080021C
    if (ctx->r25 == ctx->r1) {
        // 0x808001EC: addiu       $a2, $zero, 0x14
        ctx->r6 = ADD32(0, 0X14);
            goto L_8080021C;
    }
    goto skip_0;
    // 0x808001EC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    skip_0:
    // 0x808001F0: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001F4: mflo        $t0
    ctx->r8 = lo;
    // 0x808001F8: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x808001FC: lw          $a0, 0x10($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X10);
    // 0x80800200: jal         0x800DA298
    // 0x80800204: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800204: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800208: bne         $v0, $zero, L_80800218
    if (ctx->r2 != 0) {
        // 0x8080020C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800218;
    }
    // 0x8080020C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800210: b           L_8080024C
    // 0x80800214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080024C;
    // 0x80800214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800218:
    // 0x80800218: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_8080021C:
    // 0x8080021C: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800220: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1592, 0X730) << 16);
    // 0x80800224: addiu       $a1, $a1, 0x730
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1592, 0X730));
    // 0x80800228: mflo        $t2
    ctx->r10 = lo;
    // 0x8080022C: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x80800230: jal         0x800DA298
    // 0x80800234: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800234: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    after_4:
    // 0x80800238: beql        $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x8080023C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080024C;
    }
    goto skip_1;
    // 0x8080023C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800240: b           L_8080024C
    // 0x80800244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080024C;
    // 0x80800244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080024C:
    // 0x8080024C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800254: jr          $ra
    // 0x80800258: nop

    return;
    // 0x80800258: nop

;}
RECOMP_FUNC void bastick_getAngleRelativeToBanjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EEB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009EEBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EEC0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009EEC4: jal         0x8009C128
    // 0x8009EEC8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009EEC8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8009EECC: jal         0x800A4C48
    // 0x8009EED0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800A4C48(rdram, ctx);
        goto after_1;
    // 0x8009EED0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8009EED4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009EED8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009EEDC: lw          $t7, 0x128($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X128);
    // 0x8009EEE0: jal         0x800CAF00
    // 0x8009EEE4: lw          $a1, 0x5C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X5C);
    func_800CAF00(rdram, ctx);
        goto after_2;
    // 0x8009EEE4: lw          $a1, 0x5C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X5C);
    after_2:
    // 0x8009EEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EEEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009EEF0: jr          $ra
    // 0x8009EEF4: nop

    return;
    // 0x8009EEF4: nop

;}
RECOMP_FUNC void func_800ED064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED064: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800ED068: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x800ED06C: sll         $t9, $a3, 4
    ctx->r25 = S32(ctx->r7 << 4);
    // 0x800ED070: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
    // 0x800ED074: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800ED078: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800ED07C: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800ED080: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800ED084: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED088: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800ED08C: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800ED090: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800ED094: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800ED098: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800ED09C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800ED0A0: nop

    // 0x800ED0A4: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800ED0A8: beq         $at, $zero, L_800ED0CC
    if (ctx->r1 == 0) {
        // 0x800ED0AC: sra         $v0, $t7, 16
        ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
            goto L_800ED0CC;
    }
    // 0x800ED0AC: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
L_800ED0B0:
    // 0x800ED0B0: lh          $t1, 0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2);
    // 0x800ED0B4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED0B8: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800ED0BC: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800ED0C0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800ED0C4: bne         $at, $zero, L_800ED0B0
    if (ctx->r1 != 0) {
        // 0x800ED0C8: sh          $t2, -0xE($a2)
        MEM_H(-0XE, ctx->r6) = ctx->r10;
            goto L_800ED0B0;
    }
    // 0x800ED0C8: sh          $t2, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r10;
L_800ED0CC:
    // 0x800ED0CC: jr          $ra
    // 0x800ED0D0: nop

    return;
    // 0x800ED0D0: nop

;}
RECOMP_FUNC void func_80800088_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080008C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800090: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800094: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80800098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080009C: beql        $t6, $zero, L_80800260
    if (ctx->r14 == 0) {
        // 0x808000A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800260;
    }
    goto skip_0;
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000A4: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x808000A8: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808000AC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x808000B0: sltiu       $at, $t9, 0xD
    ctx->r1 = ctx->r25 < 0XD ? 1 : 0;
    // 0x808000B4: beq         $at, $zero, L_8080025C
    if (ctx->r1 == 0) {
        // 0x808000B8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8080025C;
    }
    // 0x808000B8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808000BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1604, 0XCC0) << 16);
    // 0x808000C0: addu        $at, $at, $t9
    gpr jr_addend_808000C8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808000C4: lw          $t9, 0xCC0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1604, 0XCC0));
    // 0x808000C8: jr          $t9
    // 0x808000CC: nop

    switch (jr_addend_808000C8 >> 2) {
        case 0: goto L_808000D0; break;
        case 1: goto L_808000E0; break;
        case 2: goto L_808000F0; break;
        case 3: goto L_80800104; break;
        case 4: goto L_80800114; break;
        case 5: goto L_8080019C; break;
        case 6: goto L_80800130; break;
        case 7: goto L_8080025C; break;
        case 8: goto L_80800210; break;
        case 9: goto L_808001BC; break;
        case 10: goto L_80800220; break;
        case 11: goto L_80800230; break;
        case 12: goto L_80800240; break;
        default: switch_error(__func__, 0x808000C8, 0x80800CC0);
    }
    // 0x808000CC: nop

L_808000D0:
    // 0x808000D0: jal         0x80800270
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800270_chmole_training(rdram, ctx);
        goto after_0;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000D8: b           L_80800260
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000E0:
    // 0x808000E0: jal         0x808003D4
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003D4_chmole_training(rdram, ctx);
        goto after_1;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000E8: b           L_80800260
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F0:
    // 0x808000F0: lbu         $t0, 0x72($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X72);
    // 0x808000F4: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x808000F8: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x808000FC: b           L_8080025C
    // 0x80800100: sb          $t2, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r10;
        goto L_8080025C;
    // 0x80800100: sb          $t2, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r10;
L_80800104:
    // 0x80800104: jal         0x80800A48
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A48_chmole_training(rdram, ctx);
        goto after_2;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080010C: b           L_80800260
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800114:
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: jal         0x80100094
    // 0x8080011C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x8080011C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800120: jal         0x80087C98
    // 0x80800124: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800124: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800128: b           L_80800260
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800130:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80087CC8
    // 0x80800138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080013C: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800140: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1604, 0XE34) << 16);
    // 0x80800144: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800148: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080014C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80800150: nop

    // 0x80800154: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80800158: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8080015C: lb          $a0, 0xE34($a0)
    ctx->r4 = MEM_B(ctx->r4, (int16_t)RELOC_LO16(1604, 0XE34));
    // 0x80800160: beql        $a0, $at, L_8080018C
    if (ctx->r4 == ctx->r1) {
        // 0x80800164: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080018C;
    }
    goto skip_1;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800168: jal         0x800C6E38
    // 0x8080016C: nop

    func_800C6E38(rdram, ctx);
        goto after_6;
    // 0x8080016C: nop

    after_6:
    // 0x80800170: bne         $v0, $zero, L_80800188
    if (ctx->r2 != 0) {
        // 0x80800174: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800188;
    }
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80101FDC
    // 0x8080017C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x8080017C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x80800180: b           L_80800260
    // 0x80800184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x80800184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800188:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080018C:
    // 0x8080018C: jal         0x80101FDC
    // 0x80800190: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80800190: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_8:
    // 0x80800194: b           L_80800260
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080019C:
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: jal         0x80087CC8
    // 0x808001A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x808001A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80101FDC
    // 0x808001B0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x808001B0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_10:
    // 0x808001B4: b           L_80800260
    // 0x808001B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x808001B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001BC:
    // 0x808001BC: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808001C0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1604, 0XE32) << 16);
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808001CC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x808001D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808001D4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x808001D8: nop

    // 0x808001DC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x808001E0: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x808001E4: jal         0x80089A58
    // 0x808001E8: lh          $a1, 0xE32($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1604, 0XE32));
    _sumole_entrypoint_17(rdram, ctx);
        goto after_11;
    // 0x808001E8: lh          $a1, 0xE32($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1604, 0XE32));
    after_11:
    // 0x808001EC: beq         $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x808001F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080025C;
    }
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: jal         0x80089A68
    // 0x808001F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumole_entrypoint_19(rdram, ctx);
        goto after_12;
    // 0x808001F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: jal         0x80101FDC
    // 0x80800204: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x80800204: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_13:
    // 0x80800208: b           L_80800260
    // 0x8080020C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x8080020C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800210:
    // 0x80800210: jal         0x80800BA8
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BA8_chmole_training(rdram, ctx);
        goto after_14;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800218: b           L_80800260
    // 0x8080021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x8080021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800220:
    // 0x80800220: jal         0x80800C28
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C28_chmole_training(rdram, ctx);
        goto after_15;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800228: b           L_80800260
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800230:
    // 0x80800230: jal         0x80800C3C
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C3C_chmole_training(rdram, ctx);
        goto after_16;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800238: b           L_80800260
    // 0x8080023C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x8080023C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800240:
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x80089A68
    // 0x80800248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumole_entrypoint_19(rdram, ctx);
        goto after_17;
    // 0x80800248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x8080024C: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
    // 0x80800250: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x80800254: ori         $t1, $t0, 0x30
    ctx->r9 = ctx->r8 | 0X30;
    // 0x80800258: sb          $t1, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r9;
L_8080025C:
    // 0x8080025C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800260:
    // 0x80800260: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800268: jr          $ra
    // 0x8080026C: nop

    return;
    // 0x8080026C: nop

;}
RECOMP_FUNC void func_8080000C_chjadestatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: jal         0x80102FDC
    // 0x80800020: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800020: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_0:
    // 0x80800024: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800028: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080002C: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800030: jal         0x800D0B68
    // 0x80800034: addiu       $a0, $t6, -0x32
    ctx->r4 = ADD32(ctx->r14, -0X32);
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a0, $t6, -0x32
    ctx->r4 = ADD32(ctx->r14, -0X32);
    after_1:
    // 0x80800038: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080003C: jal         0x800D035C
    // 0x80800040: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800D035C(rdram, ctx);
        goto after_2;
    // 0x80800040: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x80800044: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800048: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8080004C: bne         $t7, $zero, L_8080005C
    if (ctx->r15 != 0) {
        // 0x80800050: nop
    
            goto L_8080005C;
    }
    // 0x80800050: nop

    // 0x80800054: bnel        $at, $zero, L_80800068
    if (ctx->r1 != 0) {
        // 0x80800058: lbu         $t8, 0x65($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X65);
            goto L_80800068;
    }
    goto skip_0;
    // 0x80800058: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    skip_0:
L_8080005C:
    // 0x8080005C: jal         0x800FFA88
    // 0x80800060: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_3;
    // 0x80800060: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80800064: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
L_80800068:
    // 0x80800068: addiu       $a0, $zero, 0x680
    ctx->r4 = ADD32(0, 0X680);
    // 0x8080006C: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x80800070: jal         0x800DA298
    // 0x80800074: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800074: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_4:
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: jal         0x8010A5B0
    // 0x80800080: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    func_8010A5B0(rdram, ctx);
        goto after_5;
    // 0x80800080: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    after_5:
    // 0x80800084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800088: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void _sucoasterdata_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A260: syscall     831
    recomp_syscall_handler(rdram, ctx, 0x8008A260);
    return;
    // 0x8008A264: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void glsavegame_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800488: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080048C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800490: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800494: jr          $ra
    // 0x80800498: lw          $v0, 0x7618($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7618);
    return;
    // 0x80800498: lw          $v0, 0x7618($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7618);
;}
RECOMP_FUNC void _chhoney_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B68: syscall     424
    recomp_syscall_handler(rdram, ctx, 0x80086B68);
    return;
    // 0x80086B6C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808000B0_chtnthut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808000C0: beq         $a1, $at, L_808000E4
    if (ctx->r5 == ctx->r1) {
        // 0x808000C4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808000E4;
    }
    // 0x808000C4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808000C8: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808000CC: beq         $a1, $at, L_80800134
    if (ctx->r5 == ctx->r1) {
        // 0x808000D0: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800134;
    }
    // 0x808000D0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000D4: beq         $a1, $at, L_80800144
    if (ctx->r5 == ctx->r1) {
        // 0x808000D8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800144;
    }
    // 0x808000D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808000DC: b           L_80800160
    // 0x808000E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800160;
    // 0x808000E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000E4:
    // 0x808000E4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808000E8: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x808000EC: jal         0x800EE7F8
    // 0x808000F0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808000F0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x808000F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808000F8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808000FC: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    // 0x80800100: jal         0x800EF1B8
    // 0x80800104: lw          $a1, 0x48($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800104: lw          $a1, 0x48($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X48);
    after_1:
    // 0x80800108: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x8080010C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800110: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800114: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800118: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080011C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800124: jal         0x80086670
    // 0x80800128: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800128: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8080012C: b           L_80800160
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800160;
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800134:
    // 0x80800134: jal         0x80800170
    // 0x80800138: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800170_chtnthut(rdram, ctx);
        goto after_3;
    // 0x80800138: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x8080013C: b           L_80800160
    // 0x80800140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800160;
    // 0x80800140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800144:
    // 0x80800144: jal         0x80085D28
    // 0x80800148: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    _chtntdetonator_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800148: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    after_4:
    // 0x8080014C: b           L_80800160
    // 0x80800150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800160;
    // 0x80800150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800154: b           L_80800160
    // 0x80800158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800160;
    // 0x80800158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080015C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800160:
    // 0x80800160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800164: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800168: jr          $ra
    // 0x8080016C: nop

    return;
    // 0x8080016C: nop

;}
RECOMP_FUNC void func_808014F8_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014F8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808014FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801500: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801504: jal         0x808005F0
    // 0x80801508: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808005F0_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80801508: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080150C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801510: jal         0x80084DA0
    // 0x80801514: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _bakaztorpedo_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80801514: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80801518: jal         0x80099A58
    // 0x8080151C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_2;
    // 0x8080151C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801524: jal         0x80084F78
    // 0x80801528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bareact_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80801528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8080152C: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80801530: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801538: jal         0x8008CDB8
    // 0x8080153C: addiu       $a1, $zero, 0x134
    ctx->r5 = ADD32(0, 0X134);
    baanim_playForDuration_once(rdram, ctx);
        goto after_4;
    // 0x8080153C: addiu       $a1, $zero, 0x134
    ctx->r5 = ADD32(0, 0X134);
    after_4:
    // 0x80801540: jal         0x8009DA40
    // 0x80801544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009DA40(rdram, ctx);
        goto after_5;
    // 0x80801544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080154C: jal         0x8009C128
    // 0x80801550: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_6;
    // 0x80801550: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x80801554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801558: jal         0x800A32C4
    // 0x8080155C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800A32C4(rdram, ctx);
        goto after_7;
    // 0x8080155C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80801560: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801564: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80801568: jal         0x800F1E6C
    // 0x8080156C: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800F1E6C(rdram, ctx);
        goto after_8;
    // 0x8080156C: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_8:
    // 0x80801570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801574: jal         0x8009C914
    // 0x80801578: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    yaw_setIdeal(rdram, ctx);
        goto after_9;
    // 0x80801578: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_9:
    // 0x8080157C: jal         0x8009C974
    // 0x80801580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_10;
    // 0x80801580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801588: jal         0x8009C4CC
    // 0x8080158C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_11;
    // 0x8080158C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x80801590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801594: jal         0x8009BF5C
    // 0x80801598: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_12;
    // 0x80801598: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_12:
    // 0x8080159C: jal         0x80084F90
    // 0x808015A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x808015A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808015A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808015A8: jal         0x8009B9B0
    // 0x808015AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x808015AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808015B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015B4: jal         0x8009B9C0
    // 0x808015B8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_15;
    // 0x808015B8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_15:
    // 0x808015BC: jal         0x8009BB00
    // 0x808015C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x808015C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808015C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808015C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015CC: jal         0x8009BA68
    // 0x808015D0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x808015D0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_17:
    // 0x808015D4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x808015D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808015DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808015E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808015E8: jal         0x8009FFD8
    // 0x808015EC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_18;
    // 0x808015EC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_18:
    // 0x808015F0: jal         0x8008E944
    // 0x808015F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_19;
    // 0x808015F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808015F8: jal         0x8009514C
    // 0x808015FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_20;
    // 0x808015FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801604: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801608: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8080160C: jr          $ra
    // 0x80801610: nop

    return;
    // 0x80801610: nop

;}
RECOMP_FUNC void gcdialogcamera_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800104: jal         0x800856C0
    // 0x80800108: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _capod_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800108: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080010C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800110: beq         $v0, $at, L_8080014C
    if (ctx->r2 == ctx->r1) {
        // 0x80800114: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8080014C;
    }
    // 0x80800114: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800118: beq         $v0, $at, L_8080014C
    if (ctx->r2 == ctx->r1) {
        // 0x8080011C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8080014C;
    }
    // 0x8080011C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800120: bne         $v0, $at, L_8080013C
    if (ctx->r2 != ctx->r1) {
        // 0x80800124: addiu       $a0, $zero, 0x57
        ctx->r4 = ADD32(0, 0X57);
            goto L_8080013C;
    }
    // 0x80800124: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x80800128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080012C: jal         0x800856D8
    // 0x80800130: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    _capod_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800130: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_1:
    // 0x80800134: b           L_80800150
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800150;
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080013C:
    // 0x8080013C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800140: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80800144: jal         0x800856A0
    // 0x80800148: lw          $a2, 0x168($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X168);
    _capod_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800148: lw          $a2, 0x168($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X168);
    after_2:
L_8080014C:
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800150:
    // 0x80800150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void func_808014E8_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808014EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808014F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808014F4: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x808014F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808014FC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801500: jal         0x8008CCBC
    // 0x80801504: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x80801504: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x80801508: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8080150C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801518: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080151C: jal         0x8009FFD8
    // 0x80801520: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80801520: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801528: jal         0x800A0CF4
    // 0x8080152C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x8080152C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801530: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80801534: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080153C: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80801540: jal         0x8009DF18
    // 0x80801544: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF18(rdram, ctx);
        goto after_3;
    // 0x80801544: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_3:
    // 0x80801548: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x8080154C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801550: jal         0x8009D820
    // 0x80801554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D820(rdram, ctx);
        goto after_4;
    // 0x80801554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801558: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080155C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801564: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80801568: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080156C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801570: jal         0x80085490
    // 0x80801574: nop

    _bamotor_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80801574: nop

    after_5:
    // 0x80801578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080157C: jal         0x800A17A8
    // 0x80801580: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_6;
    // 0x80801580: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_6:
    // 0x80801584: jal         0x800A1718
    // 0x80801588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_7;
    // 0x80801588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080158C: bne         $v0, $zero, L_8080159C
    if (ctx->r2 != 0) {
        // 0x80801590: nop
    
            goto L_8080159C;
    }
    // 0x80801590: nop

    // 0x80801594: jal         0x80085208
    // 0x80801598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80801598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_8080159C:
    // 0x8080159C: jal         0x8080145C
    // 0x808015A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080145C_bsbfly(rdram, ctx);
        goto after_9;
    // 0x808015A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808015A4: jal         0x8008E944
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_10;
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808015AC: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x808015B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808015B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808015B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808015BC: jr          $ra
    // 0x808015C0: nop

    return;
    // 0x808015C0: nop

;}
RECOMP_FUNC void bapulse_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: jr          $ra
    // 0x80800048: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800048: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80801A50_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801A54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801A5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801A60: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801A64: jal         0x800B53A4
    // 0x80801A68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80801A68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80801A6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801A70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801A74: jal         0x800BA670
    // 0x80801A78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800BA670(rdram, ctx);
        goto after_1;
    // 0x80801A78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80801A7C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80801A80: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1008, 0X1D5C) << 16);
    // 0x80801A84: addiu       $t6, $t6, 0x1D5C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1008, 0X1D5C));
    // 0x80801A88: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80801A8C: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x80801A90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801A94: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801A98: jal         0x800BABB8
    // 0x80801A9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80801A9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80801AA0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801AA4: jal         0x800BA22C
    // 0x80801AA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80801AA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80801AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801AB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801AB4: jr          $ra
    // 0x80801AB8: nop

    return;
    // 0x80801AB8: nop

;}
RECOMP_FUNC void _chrainbow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087628: syscall     598
    recomp_syscall_handler(rdram, ctx, 0x80087628);
    return;
    // 0x8008762C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void cadbfunc_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BAC: jal         0x80800AD8
    // 0x80800BB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800AD8_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800BB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BB4: bne         $v0, $zero, L_80800BC4
    if (ctx->r2 != 0) {
        // 0x80800BB8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800BC4;
    }
    // 0x80800BB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800BBC: b           L_80800BD0
    // 0x80800BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BD0;
    // 0x80800BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BC4:
    // 0x80800BC4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800BCC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80800BD0:
    // 0x80800BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BD8: jr          $ra
    // 0x80800BDC: nop

    return;
    // 0x80800BDC: nop

;}
RECOMP_FUNC void func_8080024C_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800254: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80800258: jal         0x80800180
    // 0x8080025C: addiu       $a1, $a1, -0x646C
    ctx->r5 = ADD32(ctx->r5, -0X646C);
    func_80800180_bstrexlarge(rdram, ctx);
        goto after_0;
    // 0x8080025C: addiu       $a1, $a1, -0x646C
    ctx->r5 = ADD32(ctx->r5, -0X646C);
    after_0:
    // 0x80800260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800268: jr          $ra
    // 0x8080026C: nop

    return;
    // 0x8080026C: nop

;}
RECOMP_FUNC void baeggcursor_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080036C: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80800370: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800374: lbu         $v0, 0x9($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X9);
    // 0x80800378: beql        $v0, $zero, L_8080039C
    if (ctx->r2 == 0) {
        // 0x8080037C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080039C;
    }
    goto skip_0;
    // 0x8080037C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800380: beq         $v0, $at, L_80800398
    if (ctx->r2 == ctx->r1) {
        // 0x80800384: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800398;
    }
    // 0x80800384: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800388: beql        $v0, $at, L_8080039C
    if (ctx->r2 == ctx->r1) {
        // 0x8080038C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080039C;
    }
    goto skip_1;
    // 0x8080038C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800390: jr          $ra
    // 0x80800394: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800394: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800398:
    // 0x80800398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080039C:
    // 0x8080039C: jr          $ra
    // 0x808003A0: nop

    return;
    // 0x808003A0: nop

;}
RECOMP_FUNC void gsattract_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080033C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800340: jal         0x800A8264
    // 0x80800344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A8264(rdram, ctx);
        goto after_0;
    // 0x80800344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800348: bne         $v0, $zero, L_808003C0
    if (ctx->r2 != 0) {
        // 0x8080034C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003C0;
    }
    // 0x8080034C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800350: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80800354: lh          $t6, -0x6648($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6648);
    // 0x80800358: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8080035C: beq         $t6, $zero, L_80800368
    if (ctx->r14 == 0) {
        // 0x80800360: nop
    
            goto L_80800368;
    }
    // 0x80800360: nop

    // 0x80800364: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80800368:
    // 0x80800368: lbu         $t7, 0x5470($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5470);
    // 0x8080036C: beq         $a0, $t7, L_8080037C
    if (ctx->r4 == ctx->r15) {
        // 0x80800370: nop
    
            goto L_8080037C;
    }
    // 0x80800370: nop

    // 0x80800374: jal         0x80800274
    // 0x80800378: nop

    func_80800274_gsattract(rdram, ctx);
        goto after_1;
    // 0x80800378: nop

    after_1:
L_8080037C:
    // 0x8080037C: jal         0x800FE4E4
    // 0x80800380: nop

    func_800FE4E4(rdram, ctx);
        goto after_2;
    // 0x80800380: nop

    after_2:
    // 0x80800384: jal         0x800A9B84
    // 0x80800388: nop

    func_800A9B84(rdram, ctx);
        goto after_3;
    // 0x80800388: nop

    after_3:
    // 0x8080038C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80800390: lbu         $t8, 0x5470($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5470);
    // 0x80800394: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2882, 0X490) << 16);
    // 0x80800398: addiu       $t0, $t0, 0x490
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2882, 0X490));
    // 0x8080039C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808003A0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808003A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808003A8: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x808003AC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x808003B0: jal         0x800A9B8C
    // 0x808003B4: lbu         $a1, 0x2($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X2);
    func_800A9B8C(rdram, ctx);
        goto after_4;
    // 0x808003B4: lbu         $a1, 0x2($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X2);
    after_4:
    // 0x808003B8: jal         0x808001FC
    // 0x808003BC: nop

    gsattract_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808003BC: nop

    after_5:
L_808003C0:
    // 0x808003C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003C8: jr          $ra
    // 0x808003CC: nop

    return;
    // 0x808003CC: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5C8: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5C8);
    return;
    // 0x8008A5CC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800B5758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5758: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B575C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800B5760: addiu       $a1, $a1, 0x7F34
    ctx->r5 = ADD32(ctx->r5, 0X7F34);
    // 0x800B5764: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B5768: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_800B576C:
    // 0x800B576C: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x800B5770: srl         $t6, $a0, 31
    ctx->r14 = S32(U32(ctx->r4) >> 31);
    // 0x800B5774: bnel        $t6, $zero, L_800B57BC
    if (ctx->r14 != 0) {
        // 0x800B5778: lw          $a0, 0x14($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X14);
            goto L_800B57BC;
    }
    goto skip_0;
    // 0x800B5778: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    skip_0:
    // 0x800B577C: lbu         $t0, 0x8($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X8);
    // 0x800B5780: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B5784: sll         $t9, $t7, 7
    ctx->r25 = S32(ctx->r15 << 7);
    // 0x800B5788: andi        $t1, $t0, 0xFF7F
    ctx->r9 = ctx->r8 & 0XFF7F;
    // 0x800B578C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x800B5790: sb          $t2, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r10;
    // 0x800B5794: lhu         $t6, 0x8($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X8);
    // 0x800B5798: sll         $t4, $a2, 5
    ctx->r12 = S32(ctx->r6 << 5);
    // 0x800B579C: andi        $t5, $t4, 0x7FE0
    ctx->r13 = ctx->r12 & 0X7FE0;
    // 0x800B57A0: andi        $t7, $t6, 0x801F
    ctx->r15 = ctx->r14 & 0X801F;
    // 0x800B57A4: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800B57A8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800B57AC: sh          $t8, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r24;
    // 0x800B57B0: jr          $ra
    // 0x800B57B4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x800B57B4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B57B8: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
L_800B57BC:
    // 0x800B57BC: srl         $t0, $a0, 31
    ctx->r8 = S32(U32(ctx->r4) >> 31);
    // 0x800B57C0: bnel        $t0, $zero, L_800B5810
    if (ctx->r8 != 0) {
        // 0x800B57C4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800B5810;
    }
    goto skip_1;
    // 0x800B57C4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_1:
    // 0x800B57C8: lbu         $t3, 0x14($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X14);
    // 0x800B57CC: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800B57D0: sll         $t2, $t9, 7
    ctx->r10 = S32(ctx->r25 << 7);
    // 0x800B57D4: andi        $t4, $t3, 0xFF7F
    ctx->r12 = ctx->r11 & 0XFF7F;
    // 0x800B57D8: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x800B57DC: sb          $t6, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r14;
    // 0x800B57E0: lhu         $t0, 0x14($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X14);
    // 0x800B57E4: sll         $t7, $a2, 5
    ctx->r15 = S32(ctx->r6 << 5);
    // 0x800B57E8: andi        $t8, $t7, 0x7FE0
    ctx->r24 = ctx->r15 & 0X7FE0;
    // 0x800B57EC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800B57F0: andi        $t9, $t0, 0x801F
    ctx->r25 = ctx->r8 & 0X801F;
    // 0x800B57F4: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x800B57F8: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x800B57FC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800B5800: sh          $t1, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r9;
    // 0x800B5804: jr          $ra
    // 0x800B5808: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    return;
    // 0x800B5808: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x800B580C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_800B5810:
    // 0x800B5810: bne         $v1, $v0, L_800B576C
    if (ctx->r3 != ctx->r2) {
        // 0x800B5814: addiu       $a1, $a1, 0x18
        ctx->r5 = ADD32(ctx->r5, 0X18);
            goto L_800B576C;
    }
    // 0x800B5814: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x800B5818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B581C: jr          $ra
    // 0x800B5820: nop

    return;
    // 0x800B5820: nop

;}
RECOMP_FUNC void func_800E7FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7FB0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E7FB4: addiu       $v0, $v0, -0x2A30
    ctx->r2 = ADD32(ctx->r2, -0X2A30);
    // 0x800E7FB8: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x800E7FBC: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x800E7FC0: sh          $a2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r6;
    // 0x800E7FC4: jr          $ra
    // 0x800E7FC8: sh          $a3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r7;
    return;
    // 0x800E7FC8: sh          $a3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r7;
;}
RECOMP_FUNC void func_80802F8C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802F94: jal         0x80106790
    // 0x80802F98: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802F98: nop

    after_0:
    // 0x80802F9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802FA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802FA4: jal         0x80100094
    // 0x80802FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80802FAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802FB0: jal         0x80087DC0
    // 0x80802FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_2;
    // 0x80802FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80802FB8: beq         $v0, $zero, L_80802FD0
    if (ctx->r2 == 0) {
        // 0x80802FBC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80802FD0;
    }
    // 0x80802FBC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80802FC0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80802FC4: lbu         $t6, 0x65($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X65);
    // 0x80802FC8: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80802FCC: sb          $t7, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r15;
L_80802FD0:
    // 0x80802FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802FD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80802FDC: jr          $ra
    // 0x80802FE0: nop

    return;
    // 0x80802FE0: nop

;}
RECOMP_FUNC void func_80800098_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080009C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A8: jal         0x8009E77C
    // 0x808000AC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x808000AC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x808000B0: bne         $v0, $zero, L_80800114
    if (ctx->r2 != 0) {
        // 0x808000B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800114;
    }
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x800A0CD0
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CD0(rdram, ctx);
        goto after_1;
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80084538
    // 0x808000C8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _babackpack_set_state(rdram, ctx);
        goto after_2;
    // 0x808000C8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x808000CC: jal         0x8009EFA8
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_3;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000D4: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x808000D8: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E0: jal         0x8009F1C8
    // 0x808000E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x808000E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F0: jal         0x8009F1C8
    // 0x808000F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_5;
    // 0x808000F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800100: jal         0x800959C8
    // 0x80800104: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    func_800959C8(rdram, ctx);
        goto after_6;
    // 0x80800104: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_6:
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x800A4DA4
    // 0x80800110: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800A4DA4(rdram, ctx);
        goto after_7;
    // 0x80800110: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
L_80800114:
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void susplinet_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: lh          $t6, 0x30($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X30);
    // 0x80800348: jr          $ra
    // 0x8080034C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    return;
    // 0x8080034C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
;}
RECOMP_FUNC void func_80800000_fxkern(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800004: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800008: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8080000C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80800010: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2854, 0X420) << 16);
    // 0x80800014: lbu         $t8, 0x420($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(2854, 0X420));
    // 0x80800018: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8080001C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80800020: beq         $t8, $zero, L_8080007C
    if (ctx->r24 == 0) {
        // 0x80800024: andi        $t6, $a0, 0xFF
        ctx->r14 = ctx->r4 & 0XFF;
            goto L_8080007C;
    }
    // 0x80800024: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80800028: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2854, 0X420) << 16);
    // 0x8080002C: addiu       $v1, $v1, 0x420
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2854, 0X420));
    // 0x80800030: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800034: addiu       $t0, $zero, 0x2A
    ctx->r8 = ADD32(0, 0X2A);
    // 0x80800038: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
L_8080003C:
    // 0x8080003C: bnel        $v0, $t9, L_80800070
    if (ctx->r2 != ctx->r25) {
        // 0x80800040: lbu         $t3, 0x4($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X4);
            goto L_80800070;
    }
    goto skip_0;
    // 0x80800040: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    skip_0:
    // 0x80800044: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80800048: beql        $a1, $a0, L_8080005C
    if (ctx->r5 == ctx->r4) {
        // 0x8080004C: lb          $t1, 0x2($v1)
        ctx->r9 = MEM_B(ctx->r3, 0X2);
            goto L_8080005C;
    }
    goto skip_1;
    // 0x8080004C: lb          $t1, 0x2($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X2);
    skip_1:
    // 0x80800050: bnel        $t0, $a0, L_80800070
    if (ctx->r8 != ctx->r4) {
        // 0x80800054: lbu         $t3, 0x4($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X4);
            goto L_80800070;
    }
    goto skip_2;
    // 0x80800054: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    skip_2:
    // 0x80800058: lb          $t1, 0x2($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X2);
L_8080005C:
    // 0x8080005C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80800060: lb          $t2, 0x3($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X3);
    // 0x80800064: jr          $ra
    // 0x80800068: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    return;
    // 0x80800068: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x8080006C: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
L_80800070:
    // 0x80800070: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800074: bnel        $t3, $zero, L_8080003C
    if (ctx->r11 != 0) {
        // 0x80800078: lbu         $t9, 0x1($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X1);
            goto L_8080003C;
    }
    goto skip_3;
    // 0x80800078: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    skip_3:
L_8080007C:
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E48: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E48);
    return;
    // 0x80082E4C: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void func_800C710C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C710C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C7110: addiu       $t7, $t7, -0x5530
    ctx->r15 = ADD32(ctx->r15, -0X5530);
    // 0x800C7114: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C7118: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800C711C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C7120: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C7124: lw          $a1, -0x5520($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5520);
    // 0x800C7128: addiu       $t9, $t8, 0x5
    ctx->r25 = ADD32(ctx->r24, 0X5);
    // 0x800C712C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C7130: sltu        $at, $t9, $a1
    ctx->r1 = ctx->r25 < ctx->r5 ? 1 : 0;
    // 0x800C7134: beql        $at, $zero, L_800C7148
    if (ctx->r1 == 0) {
        // 0x800C7138: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C7148;
    }
    goto skip_0;
    // 0x800C7138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800C713C: jr          $ra
    // 0x800C7140: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    return;
    // 0x800C7140: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800C7144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C7148:
    // 0x800C7148: jr          $ra
    // 0x800C714C: nop

    return;
    // 0x800C714C: nop

;}
RECOMP_FUNC void chcrusher_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1624, 0XD20) << 16);
    // 0x80800AF8: jr          $ra
    // 0x80800AFC: addiu       $v0, $v0, 0xD20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1624, 0XD20));
    return;
    // 0x80800AFC: addiu       $v0, $v0, 0xD20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1624, 0XD20));
;}
