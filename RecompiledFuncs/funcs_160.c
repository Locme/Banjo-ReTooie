#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800000_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800010: jal         0x800DA298
    // 0x80800014: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800014: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800018: bne         $v0, $zero, L_8080002C
    if (ctx->r2 != 0) {
        // 0x8080001C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080002C;
    }
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800024: jal         0x80089D18
    // 0x80800028: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800028: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_8080002C:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_800EDD20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDD20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EDD24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EDD28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EDD2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800EDD30: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800EDD34: jal         0x800EE010
    // 0x800EDD38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800EE010(rdram, ctx);
        goto after_0;
    // 0x800EDD38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800EDD3C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800EDD40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800EDD44: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800EDD48: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800EDD4C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800EDD50: jal         0x800EDC10
    // 0x800EDD54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800EDC10(rdram, ctx);
        goto after_1;
    // 0x800EDD54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800EDD58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EDD5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EDD60: jr          $ra
    // 0x800EDD64: nop

    return;
    // 0x800EDD64: nop

;}
RECOMP_FUNC void func_800016CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800016CC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800016D0: addiu       $v0, $v0, 0x4240
    ctx->r2 = ADD32(ctx->r2, 0X4240);
    // 0x800016D4: jr          $ra
    // 0x800016D8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    return;
    // 0x800016D8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
;}
RECOMP_FUNC void bsdrone_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080013C: jal         0x80800000
    // 0x80800140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_bsdrone(rdram, ctx);
        goto after_0;
    // 0x80800140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800144: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800148: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8080014C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800150: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(160, 0X190) << 16);
    // 0x80800154: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80800158: lw          $v1, 0x190($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(160, 0X190));
    // 0x8080015C: beql        $v1, $zero, L_80800170
    if (ctx->r3 == 0) {
        // 0x80800160: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800170;
    }
    goto skip_0;
    // 0x80800160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800164: jalr        $v1
    // 0x80800168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x80800168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800170:
    // 0x80800170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

    // 0x8080017C: nop

;}
RECOMP_FUNC void func_80112398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011239C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801123A0: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x801123A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801123A8: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x801123AC: jal         0x801124D0
    // 0x801123B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801124D0(rdram, ctx);
        goto after_0;
    // 0x801123B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801123B4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801123B8: lw          $a0, 0x30($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X30);
    // 0x801123BC: jal         0x800EFD24
    // 0x801123C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x801123C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x801123C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801123C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801123CC: jr          $ra
    // 0x801123D0: nop

    return;
    // 0x801123D0: nop

;}
RECOMP_FUNC void func_801151C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801151C4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801151C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801151CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801151D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801151D4: jal         0x8010FF80
    // 0x801151D8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_8010FF80(rdram, ctx);
        goto after_0;
    // 0x801151D8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x801151DC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x801151E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801151E4: jal         0x800CA7E4
    // 0x801151E8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800CA7E4(rdram, ctx);
        goto after_1;
    // 0x801151E8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x801151EC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x801151F0: jal         0x800BEAAC
    // 0x801151F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800BEAAC(rdram, ctx);
        goto after_2;
    // 0x801151F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x801151F8: bne         $v0, $zero, L_80115270
    if (ctx->r2 != 0) {
        // 0x801151FC: lwc1        $f10, 0x40($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80115270;
    }
    // 0x801151FC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80115200: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80115204: lwc1        $f6, 0x660C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X660C);
    // 0x80115208: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8011520C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80115210: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80115214: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80115218: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8011521C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80115220: jal         0x800EFA4C
    // 0x80115224: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80115224: nop

    after_3:
    // 0x80115228: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8011522C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80115230: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80115234: jal         0x800BEF00
    // 0x80115238: addiu       $a3, $zero, 0x1F00
    ctx->r7 = ADD32(0, 0X1F00);
    func_800BEF00(rdram, ctx);
        goto after_4;
    // 0x80115238: addiu       $a3, $zero, 0x1F00
    ctx->r7 = ADD32(0, 0X1F00);
    after_4:
    // 0x8011523C: beq         $v0, $zero, L_80115268
    if (ctx->r2 == 0) {
        // 0x80115240: nop
    
            goto L_80115268;
    }
    // 0x80115240: nop

    // 0x80115244: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80115248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8011524C: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80115250: bgez        $t7, L_80115260
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80115254: nop
    
            goto L_80115260;
    }
    // 0x80115254: nop

    // 0x80115258: b           L_80115260
    // 0x8011525C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80115260;
    // 0x8011525C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80115260:
    // 0x80115260: b           L_801152E8
    // 0x80115264: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
        goto L_801152E8;
    // 0x80115264: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
L_80115268:
    // 0x80115268: b           L_801152E8
    // 0x8011526C: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
        goto L_801152E8;
    // 0x8011526C: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
L_80115270:
    // 0x80115270: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80115274: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80115278: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8011527C: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80115280: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80115284: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80115288: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8011528C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80115290: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80115294: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80115298: addiu       $a3, $zero, 0x1F00
    ctx->r7 = ADD32(0, 0X1F00);
    // 0x8011529C: jal         0x800BEF00
    // 0x801152A0: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    func_800BEF00(rdram, ctx);
        goto after_5;
    // 0x801152A0: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x801152A4: beq         $v0, $zero, L_801152BC
    if (ctx->r2 == 0) {
        // 0x801152A8: lwc1        $f8, 0x30($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
            goto L_801152BC;
    }
    // 0x801152A8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801152AC: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x801152B0: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x801152B4: bltzl       $t9, L_801152C4
    if (SIGNED(ctx->r25) < 0) {
        // 0x801152B8: lwc1        $f10, 0x38($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
            goto L_801152C4;
    }
    goto skip_0;
    // 0x801152B8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    skip_0:
L_801152BC:
    // 0x801152BC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801152C0: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
L_801152C4:
    // 0x801152C4: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801152C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801152CC: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x801152D0: nop

    // 0x801152D4: bc1fl       L_801152E8
    if (!c1cs) {
        // 0x801152D8: sb          $zero, 0xC($s0)
        MEM_B(0XC, ctx->r16) = 0;
            goto L_801152E8;
    }
    goto skip_1;
    // 0x801152D8: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    skip_1:
    // 0x801152DC: b           L_801152E8
    // 0x801152E0: sb          $t0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r8;
        goto L_801152E8;
    // 0x801152E0: sb          $t0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r8;
    // 0x801152E4: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
L_801152E8:
    // 0x801152E8: lbu         $t1, 0xC($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XC);
    // 0x801152EC: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801152F0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801152F4: beql        $t1, $zero, L_80115314
    if (ctx->r9 == 0) {
        // 0x801152F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80115314;
    }
    goto skip_2;
    // 0x801152F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801152FC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80115300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80115304: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80115308: jal         0x80114EEC
    // 0x8011530C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80114EEC(rdram, ctx);
        goto after_6;
    // 0x8011530C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80115310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80115314:
    // 0x80115314: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80115318: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8011531C: jr          $ra
    // 0x80115320: nop

    return;
    // 0x80115320: nop

;}
RECOMP_FUNC void func_800F6204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F620C: jal         0x800F6140
    // 0x800F6210: nop

    func_800F6140(rdram, ctx);
        goto after_0;
    // 0x800F6210: nop

    after_0:
    // 0x800F6214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F621C: jr          $ra
    // 0x800F6220: nop

    return;
    // 0x800F6220: nop

;}
RECOMP_FUNC void func_8080052C_chcrystalbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080052C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800530: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800534: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800538: jal         0x80101080
    // 0x8080053C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x8080053C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800540: jal         0x80106790
    // 0x80800544: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800544: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800548: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080054C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800550: jal         0x800866B8
    // 0x80800554: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800554: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: jal         0x800866C8
    // 0x80800560: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _chexploder_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x80800560: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080056C: jal         0x800866A0
    // 0x80800570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080057C: jal         0x800866A0
    // 0x80800580: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800580: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800588: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080058C: jal         0x800866D0
    // 0x80800590: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_6;
    // 0x80800590: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_6:
    // 0x80800594: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1384, 0X6CC) << 16);
    // 0x80800598: addiu       $t6, $t6, 0x6CC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1384, 0X6CC));
    // 0x8080059C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808005A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808005A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808005A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005AC: jal         0x800BBCB8
    // 0x808005B0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_7;
    // 0x808005B0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_7:
    // 0x808005B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1384, 0X6BC) << 16);
    // 0x808005BC: addiu       $a2, $a2, 0x6BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1384, 0X6BC));
    // 0x808005C0: jal         0x80089D18
    // 0x808005C4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808005C4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_8:
    // 0x808005C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005CC: jal         0x80107070
    // 0x808005D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_9;
    // 0x808005D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808005D4: bnel        $v0, $zero, L_808005E8
    if (ctx->r2 != 0) {
        // 0x808005D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808005E8;
    }
    goto skip_0;
    // 0x808005D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808005DC: jal         0x800FFAB0
    // 0x808005E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808005E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x808005E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005E8:
    // 0x808005E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005F0: jr          $ra
    // 0x808005F4: nop

    return;
    // 0x808005F4: nop

    // 0x808005F8: nop

    // 0x808005FC: nop

;}
RECOMP_FUNC void func_80800898_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800898_chfactorytoxicpools");
    // 0x80800898: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080089C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008A0: jal         0x800F54E4
    // 0x808008A4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808008A4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008AC: jal         0x800F5A00
    // 0x808008B0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x808008B0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x808008B4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1156, 0XA38) << 16);
    // 0x808008B8: addiu       $t6, $t6, 0xA38
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1156, 0XA38));
    // 0x808008BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808008C0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808008C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008C8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808008CC: jal         0x800BBCB8
    // 0x808008D0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x808008D0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x808008D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1156, 0XAC8) << 16);
    // 0x808008D8: addiu       $a2, $a2, 0xAC8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1156, 0XAC8));
    // 0x808008DC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808008E0: jal         0x800EE780
    // 0x808008E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE780(rdram, ctx);
        goto after_3;
    // 0x808008E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x808008E8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1156, 0XA74) << 16);
    // 0x808008EC: addiu       $t7, $t7, 0xA74
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1156, 0XA74));
    // 0x808008F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808008F4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808008F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808008FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800900: jal         0x800BBCB8
    // 0x80800904: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x80800904: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_4:
    // 0x80800908: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1156, 0XAB0) << 16);
    // 0x8080090C: addiu       $a2, $a2, 0xAB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1156, 0XAB0));
    // 0x80800910: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800914: jal         0x80089D18
    // 0x80800918: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800918: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x8080091C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800920: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800924: jr          $ra
    // 0x80800928: nop

    return;
    // 0x80800928: nop

    // 0x8080092C: nop

;}
RECOMP_FUNC void func_808000AC_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808000B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000BC: jal         0x80100094
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000C4: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x80100094
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000D4: beq         $v0, $zero, L_80800108
    if (ctx->r2 == 0) {
        // 0x808000D8: sw          $v0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r2;
            goto L_80800108;
    }
    // 0x808000D8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x808000DC: jal         0x801022E4
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_2;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000E4: addiu       $at, $zero, 0x367
    ctx->r1 = ADD32(0, 0X367);
    // 0x808000E8: beq         $v0, $at, L_808000F8
    if (ctx->r2 == ctx->r1) {
        // 0x808000EC: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_808000F8;
    }
    // 0x808000EC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x808000F0: jal         0x80089818
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_3;
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808000F8:
    // 0x808000F8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x808000FC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800100: jal         0x800897D8
    // 0x80800104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80800108:
    // 0x80800108: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080010C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800110: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80800114: sltiu       $at, $t8, 0xD
    ctx->r1 = ctx->r24 < 0XD ? 1 : 0;
    // 0x80800118: beq         $at, $zero, L_808007FC
    if (ctx->r1 == 0) {
        // 0x8080011C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808007FC;
    }
    // 0x8080011C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800120: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X2480) << 16);
    // 0x80800124: addu        $at, $at, $t8
    gpr jr_addend_8080012C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800128: lw          $t8, 0x2480($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1364, 0X2480));
    // 0x8080012C: jr          $t8
    // 0x80800130: nop

    switch (jr_addend_8080012C >> 2) {
        case 0: goto L_80800134; break;
        case 1: goto L_80800300; break;
        case 2: goto L_80800358; break;
        case 3: goto L_808003B0; break;
        case 4: goto L_808007FC; break;
        case 5: goto L_808004A4; break;
        case 6: goto L_808004C4; break;
        case 7: goto L_808005AC; break;
        case 8: goto L_808007FC; break;
        case 9: goto L_8080053C; break;
        case 10: goto L_808005BC; break;
        case 11: goto L_808006B4; break;
        case 12: goto L_80800718; break;
        default: switch_error(__func__, 0x8080012C, 0x80802480);
    }
    // 0x80800130: nop

L_80800134:
    // 0x80800134: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800138: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080013C: jal         0x800EE7F8
    // 0x80800140: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800140: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x80800144: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X2764) << 16);
    // 0x80800148: lui         $a3, 0x3F0C
    ctx->r7 = S32(0X3F0C << 16);
    // 0x8080014C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800150: addiu       $a2, $a2, 0x2764
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X2764));
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: jal         0x80089D20
    // 0x8080015C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x8080015C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80800160: beq         $v0, $zero, L_8080017C
    if (ctx->r2 == 0) {
        // 0x80800164: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080017C;
    }
    // 0x80800164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800168: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8080016C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800170: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800174: jal         0x80018820
    // 0x80800178: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80018820(rdram, ctx);
        goto after_7;
    // 0x80800178: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_7:
L_8080017C:
    // 0x8080017C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X2774) << 16);
    // 0x80800180: lui         $a3, 0x3F35
    ctx->r7 = S32(0X3F35 << 16);
    // 0x80800184: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x80800188: addiu       $a2, $a2, 0x2774
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X2774));
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: jal         0x80089D20
    // 0x80800194: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80800194: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80800198: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x8080019C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808001B0;
    }
    // 0x8080019C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001A0: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x808001A4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808001A8: jal         0x80018820
    // 0x808001AC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_9;
    // 0x808001AC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
L_808001B0:
    // 0x808001B0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X2784) << 16);
    // 0x808001B4: lui         $a3, 0x3F6B
    ctx->r7 = S32(0X3F6B << 16);
    // 0x808001B8: ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // 0x808001BC: addiu       $a2, $a2, 0x2784
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X2784));
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: jal         0x80089D20
    // 0x808001C8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808001C8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x808001CC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X2794) << 16);
    // 0x808001D0: lui         $a3, 0x3F0F
    ctx->r7 = S32(0X3F0F << 16);
    // 0x808001D4: ori         $a3, $a3, 0x5C29
    ctx->r7 = ctx->r7 | 0X5C29;
    // 0x808001D8: addiu       $a2, $a2, 0x2794
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X2794));
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: jal         0x80089D20
    // 0x808001E4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x808001E4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x808001E8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X27A4) << 16);
    // 0x808001EC: addiu       $a2, $a2, 0x27A4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X27A4));
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808001F8: jal         0x80089D20
    // 0x808001FC: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x808001FC: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_12:
    // 0x80800200: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800204: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x80102320
    // 0x80800210: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80102320(rdram, ctx);
        goto after_13;
    // 0x80800210: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_13:
    // 0x80800214: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80800218: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    // 0x8080021C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1364, 0X27B4) << 16);
    // 0x80800220: lbu         $a0, 0x39($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X39);
    // 0x80800224: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80800228: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080022C: addiu       $a3, $a3, 0x27B4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1364, 0X27B4));
    // 0x80800230: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800234: jal         0x80089D68
    // 0x80800238: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_14;
    // 0x80800238: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_14:
    // 0x8080023C: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x80101DDC
    // 0x80800248: sb          $v0, 0x39($t4)
    MEM_B(0X39, ctx->r12) = ctx->r2;
    func_80101DDC(rdram, ctx);
        goto after_15;
    // 0x80800248: sb          $v0, 0x39($t4)
    MEM_B(0X39, ctx->r12) = ctx->r2;
    after_15:
    // 0x8080024C: beq         $v0, $zero, L_808007FC
    if (ctx->r2 == 0) {
        // 0x80800250: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_808007FC;
    }
    // 0x80800250: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800254: jal         0x800EE88C
    // 0x80800258: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_800EE88C(rdram, ctx);
        goto after_16;
    // 0x80800258: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_16:
    // 0x8080025C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X24B4) << 16);
    // 0x80800260: lwc1        $f6, 0x24B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X24B4));
    // 0x80800264: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800270: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800274: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80800278: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8080027C: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x80800280: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80800284: nop

    // 0x80800288: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080028C: jal         0x80102424
    // 0x80800290: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x80800290: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    after_17:
    // 0x80800294: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800298: addiu       $t7, $zero, 0x62
    ctx->r15 = ADD32(0, 0X62);
    // 0x8080029C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808002A0: addiu       $a1, $zero, 0x1288
    ctx->r5 = ADD32(0, 0X1288);
    // 0x808002A4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x808002A8: jal         0x8008A208
    // 0x808002AC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x808002AC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_18:
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808002B8: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    // 0x808002BC: jal         0x80801D40
    // 0x808002C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801D40_chaliendad(rdram, ctx);
        goto after_19;
    // 0x808002C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_19:
    // 0x808002C4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808002C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808002CC: addiu       $a0, $zero, 0x45B
    ctx->r4 = ADD32(0, 0X45B);
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002D4: jal         0x80089C30
    // 0x808002D8: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_20;
    // 0x808002D8: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    after_20:
    // 0x808002DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002E4: jal         0x80102424
    // 0x808002E8: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    func_80102424(rdram, ctx);
        goto after_21;
    // 0x808002E8: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    after_21:
    // 0x808002EC: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x808002F0: lbu         $t9, 0x65($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X65);
    // 0x808002F4: ori         $t2, $t9, 0x1
    ctx->r10 = ctx->r25 | 0X1;
    // 0x808002F8: b           L_808007FC
    // 0x808002FC: sb          $t2, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r10;
        goto L_808007FC;
    // 0x808002FC: sb          $t2, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r10;
L_80800300:
    // 0x80800300: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X274C) << 16);
    // 0x80800304: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800308: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080030C: addiu       $a2, $a2, 0x274C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X274C));
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: jal         0x80089D20
    // 0x80800318: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x80800318: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x8080031C: jal         0x800D8FF8
    // 0x80800320: nop

    func_800D8FF8(rdram, ctx);
        goto after_23;
    // 0x80800320: nop

    after_23:
    // 0x80800324: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800328: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080032C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800330: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800334: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800338: jal         0x800D8FF8
    // 0x8080033C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_24;
    // 0x8080033C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    after_24:
    // 0x80800340: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800344: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800348: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8080034C: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80800350: b           L_808007FC
    // 0x80800354: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_808007FC;
    // 0x80800354: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_80800358:
    // 0x80800358: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X274C) << 16);
    // 0x8080035C: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800360: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800364: addiu       $a2, $a2, 0x274C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X274C));
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: jal         0x80089D20
    // 0x80800370: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x80800370: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_25:
    // 0x80800374: jal         0x800D8FF8
    // 0x80800378: nop

    func_800D8FF8(rdram, ctx);
        goto after_26;
    // 0x80800378: nop

    after_26:
    // 0x8080037C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800380: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800384: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800388: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080038C: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800390: jal         0x800D8FF8
    // 0x80800394: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_27;
    // 0x80800394: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    after_27:
    // 0x80800398: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080039C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808003A0: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808003A4: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x808003A8: b           L_808007FC
    // 0x808003AC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_808007FC;
    // 0x808003AC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_808003B0:
    // 0x808003B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808003B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X27C0) << 16);
    // 0x808003B8: lui         $a3, 0x3E1E
    ctx->r7 = S32(0X3E1E << 16);
    // 0x808003BC: ori         $a3, $a3, 0xB852
    ctx->r7 = ctx->r7 | 0XB852;
    // 0x808003C0: addiu       $a2, $a2, 0x27C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X27C0));
    // 0x808003C4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808003C8: jal         0x80089D20
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_28;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808003D0: beq         $v0, $zero, L_80800458
    if (ctx->r2 == 0) {
        // 0x808003D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800458;
    }
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X27CC) << 16);
    // 0x808003DC: addiu       $a2, $a2, 0x27CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X27CC));
    // 0x808003E0: jal         0x80089D18
    // 0x808003E4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_29;
    // 0x808003E4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_29:
    // 0x808003E8: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x808003EC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808003F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003F4: jal         0x80018820
    // 0x808003F8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80018820(rdram, ctx);
        goto after_30;
    // 0x808003F8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_30:
    // 0x808003FC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800400: jal         0x800EE7F8
    // 0x80800404: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_31;
    // 0x80800404: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_31:
    // 0x80800408: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8080040C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800410: jal         0x800EF1B8
    // 0x80800414: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_32;
    // 0x80800414: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    after_32:
    // 0x80800418: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1364, 0X27D4) << 16);
    // 0x8080041C: addiu       $t3, $t3, 0x27D4
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1364, 0X27D4));
    // 0x80800420: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800424: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800428: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080042C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800434: jal         0x800BBCB8
    // 0x80800438: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_33;
    // 0x80800438: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_33:
    // 0x8080043C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800440: addiu       $t4, $zero, 0x62
    ctx->r12 = ADD32(0, 0X62);
    // 0x80800444: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800448: addiu       $a1, $zero, 0x1289
    ctx->r5 = ADD32(0, 0X1289);
    // 0x8080044C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800450: jal         0x8008A208
    // 0x80800454: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_34;
    // 0x80800454: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_34:
L_80800458:
    // 0x80800458: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x8080045C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800460: jal         0x80101E14
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_35;
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80800468: beq         $v0, $zero, L_80800478
    if (ctx->r2 == 0) {
        // 0x8080046C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800478;
    }
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: jal         0x80801324
    // 0x80800474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801324_chaliendad(rdram, ctx);
        goto after_36;
    // 0x80800474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_36:
L_80800478:
    // 0x80800478: jal         0x80101DDC
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_37;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800480: beq         $v0, $zero, L_808007FC
    if (ctx->r2 == 0) {
        // 0x80800484: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007FC;
    }
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: jal         0x80102424
    // 0x8080048C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_38;
    // 0x8080048C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_38:
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: jal         0x8008A4B0
    // 0x80800498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_39;
    // 0x80800498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x8080049C: b           L_80800800
    // 0x808004A0: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
        goto L_80800800;
    // 0x808004A0: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
L_808004A4:
    // 0x808004A4: jal         0x800D9078
    // 0x808004A8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_40;
    // 0x808004A8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_40:
    // 0x808004AC: beq         $v0, $zero, L_808007FC
    if (ctx->r2 == 0) {
        // 0x808004B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007FC;
    }
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: jal         0x80102424
    // 0x808004B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_41;
    // 0x808004B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_41:
    // 0x808004BC: b           L_80800800
    // 0x808004C0: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
        goto L_80800800;
    // 0x808004C0: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
L_808004C4:
    // 0x808004C4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808004C8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808004CC: jal         0x80101E14
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_42;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x808004D4: beq         $v0, $zero, L_808004E4
    if (ctx->r2 == 0) {
        // 0x808004D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E4;
    }
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: jal         0x80801324
    // 0x808004E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801324_chaliendad(rdram, ctx);
        goto after_43;
    // 0x808004E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_43:
L_808004E4:
    // 0x808004E4: jal         0x80101DDC
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_44;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x808004EC: beql        $v0, $zero, L_80800800
    if (ctx->r2 == 0) {
        // 0x808004F0: lw          $v0, 0x74($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X74);
            goto L_80800800;
    }
    goto skip_0;
    // 0x808004F0: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x808004F4: jal         0x800DA544
    // 0x808004F8: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    func_800DA544(rdram, ctx);
        goto after_45;
    // 0x808004F8: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    after_45:
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800504: jal         0x80801C9C
    // 0x80800508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801C9C_chaliendad(rdram, ctx);
        goto after_46;
    // 0x80800508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_46:
    // 0x8080050C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800510: addiu       $t5, $zero, 0x62
    ctx->r13 = ADD32(0, 0X62);
    // 0x80800514: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800518: addiu       $a1, $zero, 0x1287
    ctx->r5 = ADD32(0, 0X1287);
    // 0x8080051C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800520: jal         0x8008A208
    // 0x80800524: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_47;
    // 0x80800524: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_47:
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: jal         0x80102424
    // 0x80800530: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80102424(rdram, ctx);
        goto after_48;
    // 0x80800530: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_48:
    // 0x80800534: b           L_80800800
    // 0x80800538: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
        goto L_80800800;
    // 0x80800538: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
L_8080053C:
    // 0x8080053C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800540: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800544: jal         0x80101E14
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_49;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x8080054C: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x80800550: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080055C;
    }
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: jal         0x80108B04
    // 0x80800558: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80108B04(rdram, ctx);
        goto after_50;
    // 0x80800558: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_50:
L_8080055C:
    // 0x8080055C: jal         0x80101DDC
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_51;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80800564: beql        $v0, $zero, L_80800800
    if (ctx->r2 == 0) {
        // 0x80800568: lw          $v0, 0x74($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X74);
            goto L_80800800;
    }
    goto skip_1;
    // 0x80800568: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    skip_1:
    // 0x8080056C: jal         0x800D9078
    // 0x80800570: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_52;
    // 0x80800570: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_52:
    // 0x80800574: beql        $v0, $zero, L_80800800
    if (ctx->r2 == 0) {
        // 0x80800578: lw          $v0, 0x74($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X74);
            goto L_80800800;
    }
    goto skip_2;
    // 0x80800578: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    skip_2:
    // 0x8080057C: jal         0x80801C60
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C60_chaliendad(rdram, ctx);
        goto after_53;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80800584: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80800588: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x8080058C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800590: jal         0x8010114C
    // 0x80800594: lw          $a0, 0x28($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X28);
    func_8010114C(rdram, ctx);
        goto after_54;
    // 0x80800594: lw          $a0, 0x28($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X28);
    after_54:
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: jal         0x80102424
    // 0x808005A0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_55;
    // 0x808005A0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_55:
    // 0x808005A4: b           L_80800800
    // 0x808005A8: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
        goto L_80800800;
    // 0x808005A8: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
L_808005AC:
    // 0x808005AC: jal         0x80801B9C
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B9C_chaliendad(rdram, ctx);
        goto after_56;
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x808005B4: b           L_80800800
    // 0x808005B8: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
        goto L_80800800;
    // 0x808005B8: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
L_808005BC:
    // 0x808005BC: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x808005C0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x808005C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x808005C8: addiu       $a0, $v1, 0xC
    ctx->r4 = ADD32(ctx->r3, 0XC);
    // 0x808005CC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808005D0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_808005D4:
    // 0x808005D4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808005D8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x808005DC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x808005E0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x808005E4: jal         0x800D9078
    // 0x808005E8: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    func_800D9078(rdram, ctx);
        goto after_57;
    // 0x808005E8: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    after_57:
    // 0x808005EC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x808005F0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808005F4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x808005F8: beq         $v0, $zero, L_80800644
    if (ctx->r2 == 0) {
        // 0x808005FC: lw          $t1, 0x58($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X58);
            goto L_80800644;
    }
    // 0x808005FC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80800600: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    // 0x80800604: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x80800608: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8080060C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80800610: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80800614: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x80800618: jal         0x8010114C
    // 0x8080061C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_58;
    // 0x8080061C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_58:
    // 0x80800620: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800624: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800628: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8080062C: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80800630: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800634: sb          $t7, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r15;
    // 0x80800638: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x8080063C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800640: sb          $t8, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r24;
L_80800644:
    // 0x80800644: lbu         $t2, 0x8($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X8);
    // 0x80800648: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8080064C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80800650: beq         $t2, $zero, L_8080065C
    if (ctx->r10 == 0) {
        // 0x80800654: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_8080065C;
    }
    // 0x80800654: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80800658: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8080065C:
    // 0x8080065C: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80800660: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800664: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80800668: bne         $t0, $at, L_808005D4
    if (ctx->r8 != ctx->r1) {
        // 0x8080066C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808005D4;
    }
    // 0x8080066C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800670: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800674: bne         $t1, $at, L_808007FC
    if (ctx->r9 != ctx->r1) {
        // 0x80800678: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007FC;
    }
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x80800680: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80800684: jal         0x80801D40
    // 0x80800688: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801D40_chaliendad(rdram, ctx);
        goto after_59;
    // 0x80800688: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_59:
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: jal         0x80102424
    // 0x80800694: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80102424(rdram, ctx);
        goto after_60;
    // 0x80800694: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_60:
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: jal         0x80108B04
    // 0x808006A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_61;
    // 0x808006A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_61:
    // 0x808006A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808006A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808006AC: b           L_808007FC
    // 0x808006B0: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_808007FC;
    // 0x808006B0: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_808006B4:
    // 0x808006B4: jal         0x80101DDC
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_62;
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x808006BC: beql        $v0, $zero, L_80800800
    if (ctx->r2 == 0) {
        // 0x808006C0: lw          $v0, 0x74($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X74);
            goto L_80800800;
    }
    goto skip_3;
    // 0x808006C0: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    skip_3:
    // 0x808006C4: jal         0x800D9078
    // 0x808006C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_63;
    // 0x808006C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_63:
    // 0x808006CC: beq         $v0, $zero, L_808007FC
    if (ctx->r2 == 0) {
        // 0x808006D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007FC;
    }
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X27FC) << 16);
    // 0x808006D8: addiu       $a2, $a2, 0x27FC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X27FC));
    // 0x808006DC: jal         0x80089D18
    // 0x808006E0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_64;
    // 0x808006E0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_64:
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E8: jal         0x80102424
    // 0x808006EC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80102424(rdram, ctx);
        goto after_65;
    // 0x808006EC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_65:
    // 0x808006F0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808006F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006F8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808006FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800700: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800704: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800708: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x8080070C: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80800710: b           L_808007FC
    // 0x80800714: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
        goto L_808007FC;
    // 0x80800714: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
L_80800718:
    // 0x80800718: jal         0x800D9078
    // 0x8080071C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_66;
    // 0x8080071C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_66:
    // 0x80800720: jal         0x800D8FF8
    // 0x80800724: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_67;
    // 0x80800724: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_67:
    // 0x80800728: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080072C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800730: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800734: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800738: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8080073C: jal         0x800D8FF8
    // 0x80800740: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_68;
    // 0x80800740: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    after_68:
    // 0x80800744: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800748: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080074C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800750: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800754: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80800758: jal         0x800D9078
    // 0x8080075C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    func_800D9078(rdram, ctx);
        goto after_69;
    // 0x8080075C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_69:
    // 0x80800760: beq         $v0, $zero, L_80800778
    if (ctx->r2 == 0) {
        // 0x80800764: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800778;
    }
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800768: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X2808) << 16);
    // 0x8080076C: addiu       $a2, $a2, 0x2808
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X2808));
    // 0x80800770: jal         0x80089D18
    // 0x80800774: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_70;
    // 0x80800774: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_70:
L_80800778:
    // 0x80800778: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8080077C: addiu       $a0, $zero, 0x45B
    ctx->r4 = ADD32(0, 0X45B);
    // 0x80800780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800784: beq         $t5, $zero, L_808007FC
    if (ctx->r13 == 0) {
        // 0x80800788: addiu       $t6, $s0, 0x4
        ctx->r14 = ADD32(ctx->r16, 0X4);
            goto L_808007FC;
    }
    // 0x80800788: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x8080078C: jal         0x80089C30
    // 0x80800790: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_71;
    // 0x80800790: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_71:
    // 0x80800794: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800798: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080079C: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x808007A0: jal         0x8010114C
    // 0x808007A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_72;
    // 0x808007A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_72:
    // 0x808007A8: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x808007AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808007B0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808007B4: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x808007B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007BC: jal         0x800D1000
    // 0x808007C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800D1000(rdram, ctx);
        goto after_73;
    // 0x808007C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_73:
    // 0x808007C4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007CC: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    // 0x808007D0: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    // 0x808007D4: jal         0x80801D40
    // 0x808007D8: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    func_80801D40_chaliendad(rdram, ctx);
        goto after_74;
    // 0x808007D8: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    after_74:
    // 0x808007DC: jal         0x808022CC
    // 0x808007E0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_808022CC_chaliendad(rdram, ctx);
        goto after_75;
    // 0x808007E0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_75:
    // 0x808007E4: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007EC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x808007F0: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x808007F4: jal         0x80102424
    // 0x808007F8: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_80102424(rdram, ctx);
        goto after_76;
    // 0x808007F8: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_76:
L_808007FC:
    // 0x808007FC: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
L_80800800:
    // 0x80800800: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    // 0x80800804: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1364, 0X2814) << 16);
    // 0x80800808: lbu         $a0, 0x38($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X38);
    // 0x8080080C: lbu         $a2, 0xB($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0XB);
    // 0x80800810: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80800814: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800818: addiu       $a3, $a3, 0x2814
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1364, 0X2814));
    // 0x8080081C: jal         0x80089D68
    // 0x80800820: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_77;
    // 0x80800820: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_77:
    // 0x80800824: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80800830: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800834: jal         0x8008A0D0
    // 0x80800838: sb          $v0, 0x38($t4)
    MEM_B(0X38, ctx->r12) = ctx->r2;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_78;
    // 0x80800838: sb          $v0, 0x38($t4)
    MEM_B(0X38, ctx->r12) = ctx->r2;
    after_78:
    // 0x8080083C: beq         $v0, $zero, L_80800854
    if (ctx->r2 == 0) {
        // 0x80800840: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_80800854;
    }
    // 0x80800840: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800844: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800848: lui         $a2, 0x42FA
    ctx->r6 = S32(0X42FA << 16);
    // 0x8080084C: jal         0x80089F18
    // 0x80800850: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_79;
    // 0x80800850: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_79:
L_80800854:
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080085C: jal         0x8008A0D0
    // 0x80800860: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_80;
    // 0x80800860: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_80:
    // 0x80800864: beq         $v0, $zero, L_8080087C
    if (ctx->r2 == 0) {
        // 0x80800868: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_8080087C;
    }
    // 0x80800868: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080086C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800870: lui         $a2, 0x42FA
    ctx->r6 = S32(0X42FA << 16);
    // 0x80800874: jal         0x80089F18
    // 0x80800878: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_81;
    // 0x80800878: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_81:
L_8080087C:
    // 0x8080087C: jal         0x808012AC
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808012AC_chaliendad(rdram, ctx);
        goto after_82;
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_82:
    // 0x80800884: lw          $t5, 0x7C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X7C);
    // 0x80800888: sll         $t7, $t5, 19
    ctx->r15 = S32(ctx->r13 << 19);
    // 0x8080088C: bgezl       $t7, L_808008B8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800890: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008B8;
    }
    goto skip_4;
    // 0x80800890: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80800894: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808008A0: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808008A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808008A8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808008AC: jal         0x80085778
    // 0x808008B0: nop

    _chbadshad_entrypoint_2(rdram, ctx);
        goto after_83;
    // 0x808008B0: nop

    after_83:
    // 0x808008B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008B8:
    // 0x808008B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008BC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x808008C0: jr          $ra
    // 0x808008C4: nop

    return;
    // 0x808008C4: nop

;}
RECOMP_FUNC void func_80800444_glhittableDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080044C: beq         $a0, $zero, L_808004C4
    if (ctx->r4 == 0) {
        // 0x80800450: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_808004C4;
    }
    // 0x80800450: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800454: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80800458: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x8080045C: bnel        $t7, $zero, L_808004B8
    if (ctx->r15 != 0) {
        // 0x80800460: lw          $v0, 0x24($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X24);
            goto L_808004B8;
    }
    goto skip_0;
    // 0x80800460: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    skip_0:
    // 0x80800464: lhu         $a0, 0x1A($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1A);
    // 0x80800468: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080046C: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x80800470: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80800474: jal         0x800F52B8
    // 0x80800478: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_800F52B8(rdram, ctx);
        goto after_0;
    // 0x80800478: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x8080047C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800480: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800484: bne         $v0, $at, L_80800494
    if (ctx->r2 != ctx->r1) {
        // 0x80800488: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800494;
    }
    // 0x80800488: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080048C: b           L_808004C8
    // 0x80800490: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_808004C8;
    // 0x80800490: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800494:
    // 0x80800494: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // 0x80800498: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x8080049C: jal         0x800F64A4
    // 0x808004A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x808004A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x808004A4: beq         $v0, $zero, L_808004B4
    if (ctx->r2 == 0) {
        // 0x808004A8: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_808004B4;
    }
    // 0x808004A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808004AC: b           L_808004C8
    // 0x808004B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_808004C8;
    // 0x808004B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_808004B4:
    // 0x808004B4: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
L_808004B8:
    // 0x808004B8: srl         $t9, $v0, 22
    ctx->r25 = S32(U32(ctx->r2) >> 22);
    // 0x808004BC: b           L_808004C8
    // 0x808004C0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_808004C8;
    // 0x808004C0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_808004C4:
    // 0x808004C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_808004C8:
    // 0x808004C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004D0: jr          $ra
    // 0x808004D4: nop

    return;
    // 0x808004D4: nop

;}
RECOMP_FUNC void func_8009CC68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CC68: lw          $v1, 0xF0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CC6C: lbu         $a1, 0x80($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X80);
    // 0x8009CC70: bne         $a1, $zero, L_8009CC80
    if (ctx->r5 != 0) {
        // 0x8009CC74: sll         $t6, $a1, 4
        ctx->r14 = S32(ctx->r5 << 4);
            goto L_8009CC80;
    }
    // 0x8009CC74: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8009CC78: jr          $ra
    // 0x8009CC7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8009CC7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009CC80:
    // 0x8009CC80: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8009CC84: lbu         $v0, -0x10($t7)
    ctx->r2 = MEM_BU(ctx->r15, -0X10);
    // 0x8009CC88: jr          $ra
    // 0x8009CC8C: nop

    return;
    // 0x8009CC8C: nop

;}
RECOMP_FUNC void _chtrashcangame_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876A8: syscall     604
    recomp_syscall_handler(rdram, ctx, 0x800876A8);
    return;
    // 0x800876AC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bsmum_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800D48: jal         0x80084600
    // 0x80800D4C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800D4C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800D50: beq         $v0, $zero, L_80800D5C
    if (ctx->r2 == 0) {
        // 0x80800D54: addiu       $t6, $zero, 0xE5
        ctx->r14 = ADD32(0, 0XE5);
            goto L_80800D5C;
    }
    // 0x80800D54: addiu       $t6, $zero, 0xE5
    ctx->r14 = ADD32(0, 0XE5);
    // 0x80800D58: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800D5C:
    // 0x80800D5C: jal         0x8008E35C
    // 0x80800D60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_inWater(rdram, ctx);
        goto after_1;
    // 0x80800D60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800D64: beql        $v0, $zero, L_80800D94
    if (ctx->r2 == 0) {
        // 0x80800D68: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800D94;
    }
    goto skip_0;
    // 0x80800D68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800D6C: jal         0x8009BB50
    // 0x80800D70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_2;
    // 0x80800D70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800D74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800D78: addiu       $t7, $zero, 0xF4
    ctx->r15 = ADD32(0, 0XF4);
    // 0x80800D7C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80800D80: nop

    // 0x80800D84: bc1fl       L_80800D94
    if (!c1cs) {
        // 0x80800D88: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800D94;
    }
    goto skip_1;
    // 0x80800D88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80800D8C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80800D90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800D94:
    // 0x80800D94: jal         0x8009E5C8
    // 0x80800D98: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80800D98: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DA4: jr          $ra
    // 0x80800DA8: nop

    return;
    // 0x80800DA8: nop

;}
RECOMP_FUNC void func_800F5754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5754: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F575C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5764: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5768: jal         0x80084D40
    // 0x800F576C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _bahold_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800F576C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5770: beq         $v0, $zero, L_800F5788
    if (ctx->r2 == 0) {
        // 0x800F5774: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F5788;
    }
    // 0x800F5774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5778: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x800F577C: srl         $t7, $v0, 22
    ctx->r15 = S32(U32(ctx->r2) >> 22);
    // 0x800F5780: b           L_800F578C
    // 0x800F5784: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800F578C;
    // 0x800F5784: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800F5788:
    // 0x800F5788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F578C:
    // 0x800F578C: jr          $ra
    // 0x800F5790: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F5790: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800CA8F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA8F4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CA8F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800CA8FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA900: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800CA904: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_800CA908:
    // 0x800CA908: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800CA90C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CA910: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800CA914: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800CA918: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800CA91C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800CA920: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800CA924: bne         $v0, $a0, L_800CA908
    if (ctx->r2 != ctx->r4) {
        // 0x800CA928: swc1        $f6, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->f6.u32l;
            goto L_800CA908;
    }
    // 0x800CA928: swc1        $f6, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f6.u32l;
    // 0x800CA92C: jr          $ra
    // 0x800CA930: nop

    return;
    // 0x800CA930: nop

;}
RECOMP_FUNC void func_80803E50_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803E50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803E54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803E58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803E5C: jal         0x80100094
    // 0x80803E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803E64: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80803E68: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803E6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803E70: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80803E74: jal         0x808041C4
    // 0x80803E78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808041C4_chweldarboss(rdram, ctx);
        goto after_1;
    // 0x80803E78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80803E7C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80803E80: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80803E84: jal         0x8008A028
    // 0x80803E88: lw          $a1, 0x3C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X3C);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80803E88: lw          $a1, 0x3C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X3C);
    after_2:
    // 0x80803E8C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80803E90: sw          $zero, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = 0;
    // 0x80803E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803E98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803E9C: jr          $ra
    // 0x80803EA0: nop

    return;
    // 0x80803EA0: nop

;}
RECOMP_FUNC void ncba1p_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800474: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800478: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080047C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800480: jal         0x80110840
    // 0x80800484: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x80800484: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800488: jal         0x800878C0
    // 0x8080048C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plcamera_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080048C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800490: bnel        $v0, $zero, L_8080051C
    if (ctx->r2 != 0) {
        // 0x80800494: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080051C;
    }
    goto skip_0;
    // 0x80800494: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800498: jal         0x800EFD24
    // 0x8080049C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x8080049C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x808004A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004A4: jal         0x800EFD24
    // 0x808004A8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x808004A8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_3:
    // 0x808004AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004B0: jal         0x800EFD24
    // 0x808004B4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x808004B4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_4:
    // 0x808004B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004BC: jal         0x800EFD24
    // 0x808004C0: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_5;
    // 0x808004C0: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_5:
    // 0x808004C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004C8: jal         0x800EFD24
    // 0x808004CC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_800EFD24(rdram, ctx);
        goto after_6;
    // 0x808004CC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_6:
    // 0x808004D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004D4: jal         0x800EFD24
    // 0x808004D8: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_800EFD24(rdram, ctx);
        goto after_7;
    // 0x808004D8: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_7:
    // 0x808004DC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808004E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808004E4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808004E8: sw          $zero, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = 0;
    // 0x808004EC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x808004F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: sb          $t7, 0x50($t8)
    MEM_B(0X50, ctx->r24) = ctx->r15;
    // 0x808004FC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800500: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80800504: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800508: sb          $zero, 0x51($t9)
    MEM_B(0X51, ctx->r25) = 0;
    // 0x8080050C: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x80800510: jal         0x80111590
    // 0x80800514: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80111590(rdram, ctx);
        goto after_8;
    // 0x80800514: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80800518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080051C:
    // 0x8080051C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800520: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800524: jr          $ra
    // 0x80800528: nop

    return;
    // 0x80800528: nop

;}
RECOMP_FUNC void _chglowbo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AC8: syscall     414
    recomp_syscall_handler(rdram, ctx, 0x80086AC8);
    return;
    // 0x80086ACC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8001DC6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC6C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001DC70: addiu       $v0, $v0, -0x2E90
    ctx->r2 = ADD32(ctx->r2, -0X2E90);
    // 0x8001DC74: lw          $t6, 0x6A0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6A0);
    // 0x8001DC78: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001DC7C: beql        $t6, $zero, L_8001DC90
    if (ctx->r14 == 0) {
        // 0x8001DC80: sw          $t7, 0x6A0($v0)
        MEM_W(0X6A0, ctx->r2) = ctx->r15;
            goto L_8001DC90;
    }
    goto skip_0;
    // 0x8001DC80: sw          $t7, 0x6A0($v0)
    MEM_W(0X6A0, ctx->r2) = ctx->r15;
    skip_0:
    // 0x8001DC84: jr          $ra
    // 0x8001DC88: sw          $zero, 0x6A0($v0)
    MEM_W(0X6A0, ctx->r2) = 0;
    return;
    // 0x8001DC88: sw          $zero, 0x6A0($v0)
    MEM_W(0X6A0, ctx->r2) = 0;
    // 0x8001DC8C: sw          $t7, 0x6A0($v0)
    MEM_W(0X6A0, ctx->r2) = ctx->r15;
L_8001DC90:
    // 0x8001DC90: jr          $ra
    // 0x8001DC94: nop

    return;
    // 0x8001DC94: nop

    // 0x8001DC98: nop

    // 0x8001DC9C: nop

;}
RECOMP_FUNC void func_8080019C_gcsectionskip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808001A0: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x808001A4: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x808001A8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808001AC: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x808001B0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808001B4: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x808001B8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808001BC: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x808001C0: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x808001C4: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x808001C8: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x808001CC: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x808001D0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x808001D4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808001D8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808001DC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808001E0: jal         0x800EE7F8
    // 0x808001E4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808001E4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x808001E8: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x808001EC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808001F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808001F4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001FC: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80800200: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x80800204: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x80800208: nop

    // 0x8080020C: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
L_80800210:
    // 0x80800210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800214: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800218: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080021C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800220: div.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80800224: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800228: jal         0x800EFE50
    // 0x8080022C: nop

    func_800EFE50(rdram, ctx);
        goto after_1;
    // 0x8080022C: nop

    after_1:
    // 0x80800230: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800238: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8080023C: jal         0x80800000
    // 0x80800240: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_80800000_gcsectionskip(rdram, ctx);
        goto after_2;
    // 0x80800240: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_2:
    // 0x80800244: beq         $v0, $zero, L_80800260
    if (ctx->r2 == 0) {
        // 0x80800248: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80800260;
    }
    // 0x80800248: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8080024C: jal         0x800EE7F8
    // 0x80800250: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800250: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800254: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800258: bnel        $s0, $s5, L_80800210
    if (ctx->r16 != ctx->r21) {
        // 0x8080025C: mtc1        $s0, $f8
        ctx->f8.u32l = ctx->r16;
            goto L_80800210;
    }
    goto skip_0;
    // 0x8080025C: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    skip_0:
L_80800260:
    // 0x80800260: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800264: jal         0x800EE7F8
    // 0x80800268: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800268: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_4:
    // 0x8080026C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800270: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800274: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800278: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8080027C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800280: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800284: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800288: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8080028C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80800290: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80800294: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80800298: jr          $ra
    // 0x8080029C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8080029C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800E0ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0ACC: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800E0AD0: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800E0AD4: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800E0AD8: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800E0ADC: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x800E0AE0: sb          $zero, 0x8($a0)
    MEM_B(0X8, ctx->r4) = 0;
    // 0x800E0AE4: sb          $zero, 0x9($a0)
    MEM_B(0X9, ctx->r4) = 0;
    // 0x800E0AE8: jr          $ra
    // 0x800E0AEC: sb          $zero, 0xA($a0)
    MEM_B(0XA, ctx->r4) = 0;
    return;
    // 0x800E0AEC: sb          $zero, 0xA($a0)
    MEM_B(0XA, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800F8DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8DE0: jal         0x800F9A24
    // 0x800F8DE4: nop

    func_800F9A24(rdram, ctx);
        goto after_0;
    // 0x800F8DE4: nop

    after_0:
    // 0x800F8DE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8DEC: jal         0x800B2D28
    // 0x800F8DF0: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    vector_free(rdram, ctx);
        goto after_1;
    // 0x800F8DF0: lw          $a0, 0x54F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54F0);
    after_1:
    // 0x800F8DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8DF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8DFC: sw          $zero, 0x54F0($at)
    MEM_W(0X54F0, ctx->r1) = 0;
    // 0x800F8E00: jr          $ra
    // 0x800F8E04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F8E04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080038C_chcrystalbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800394: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800398: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080039C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003A0: jal         0x800DF744
    // 0x808003A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x808003A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x808003A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003AC: jal         0x80101870
    // 0x808003B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x808003B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003BC: jr          $ra
    // 0x808003C0: nop

    return;
    // 0x808003C0: nop

;}
RECOMP_FUNC void func_80801910_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080191C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80801920: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801924: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801928: lwc1        $f0, 0x38($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X38);
    // 0x8080192C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80801930: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801934: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801938: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080193C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80801940: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80801944: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801948: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8080194C: jal         0x80089F18
    // 0x80801950: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801950: nop

    after_0:
    // 0x80801954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080195C: jr          $ra
    // 0x80801960: nop

    return;
    // 0x80801960: nop

;}
RECOMP_FUNC void func_808009E8_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808009F4: jal         0x80100094
    // 0x808009F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009FC: beq         $v0, $zero, L_80800A0C
    if (ctx->r2 == 0) {
        // 0x80800A00: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800A0C;
    }
    // 0x80800A00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A04: jal         0x80087CC8
    // 0x80800A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80800A0C:
    // 0x80800A0C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800A10: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A18: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80800A1C: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800A20: bnel        $t8, $at, L_80800A34
    if (ctx->r24 != ctx->r1) {
        // 0x80800A24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800A34;
    }
    goto skip_0;
    // 0x80800A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800A28: jal         0x80800398
    // 0x80800A2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800398_chsilo(rdram, ctx);
        goto after_2;
    // 0x80800A2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A34:
    // 0x80800A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A38: jr          $ra
    // 0x80800A3C: nop

    return;
    // 0x80800A3C: nop

;}
RECOMP_FUNC void _chfreezy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F88: syscall     266
    recomp_syscall_handler(rdram, ctx, 0x80085F88);
    return;
    // 0x80085F8C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chtntdetonator_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D28: syscall     231
    recomp_syscall_handler(rdram, ctx, 0x80085D28);
    return;
    // 0x80085D2C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsjig_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831E8: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x800831E8);
    return;
    // 0x800831EC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80017778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017778: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001777C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80017780: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80017784: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80017788: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001778C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80017790: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80017794: addiu       $t7, $t7, -0x6060
    ctx->r15 = ADD32(ctx->r15, -0X6060);
    // 0x80017798: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001779C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800177A0: lw          $v0, 0x20C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20C);
    // 0x800177A4: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800177A8: beq         $t8, $zero, L_800177BC
    if (ctx->r24 == 0) {
        // 0x800177AC: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800177BC;
    }
    // 0x800177AC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800177B0: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x800177B4: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800177B8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800177BC:
    // 0x800177BC: jr          $ra
    // 0x800177C0: nop

    return;
    // 0x800177C0: nop

;}
RECOMP_FUNC void func_800DAC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAC10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DAC14: slti        $at, $a1, 0xB1
    ctx->r1 = SIGNED(ctx->r5) < 0XB1 ? 1 : 0;
    // 0x800DAC18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DAC1C: bne         $at, $zero, L_800DAC2C
    if (ctx->r1 != 0) {
        // 0x800DAC20: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800DAC2C;
    }
    // 0x800DAC20: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800DAC24: b           L_800DAC30
    // 0x800DAC28: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
        goto L_800DAC30;
    // 0x800DAC28: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
L_800DAC2C:
    // 0x800DAC2C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800DAC30:
    // 0x800DAC30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DAC34: lw          $a0, -0x3890($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3890);
    // 0x800DAC38: jal         0x8001BBA0
    // 0x800DAC3C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    rare_memcpy(rdram, ctx);
        goto after_0;
    // 0x800DAC3C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800DAC40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DAC44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DAC48: jr          $ra
    // 0x800DAC4C: nop

    return;
    // 0x800DAC4C: nop

;}
RECOMP_FUNC void func_800CF700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF708: jal         0x800DA544
    // 0x800CF70C: addiu       $a0, $zero, 0x1BF
    ctx->r4 = ADD32(0, 0X1BF);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x800CF70C: addiu       $a0, $zero, 0x1BF
    ctx->r4 = ADD32(0, 0X1BF);
    after_0:
    // 0x800CF710: jal         0x800CF6D0
    // 0x800CF714: nop

    func_800CF6D0(rdram, ctx);
        goto after_1;
    // 0x800CF714: nop

    after_1:
    // 0x800CF718: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CF71C: jal         0x800CE9E8
    // 0x800CF720: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800CE9E8(rdram, ctx);
        goto after_2;
    // 0x800CF720: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x800CF724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF72C: jr          $ra
    // 0x800CF730: nop

    return;
    // 0x800CF730: nop

;}
RECOMP_FUNC void func_80804D80_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804D88: jal         0x80807C8C
    // 0x80804D8C: nop

    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804D8C: nop

    after_0:
    // 0x80804D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804D98: jr          $ra
    // 0x80804D9C: nop

    return;
    // 0x80804D9C: nop

;}
RECOMP_FUNC void _chmole_factory_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E88: syscall     465
    recomp_syscall_handler(rdram, ctx, 0x80086E88);
    return;
    // 0x80086E8C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8008FF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FF6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FF70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FF74: jal         0x800F54E4
    // 0x8008FF78: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FF78: nop

    after_0:
    // 0x8008FF7C: jal         0x800F5C94
    // 0x8008FF80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5C94(rdram, ctx);
        goto after_1;
    // 0x8008FF80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FF88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FF8C: jr          $ra
    // 0x8008FF90: nop

    return;
    // 0x8008FF90: nop

;}
RECOMP_FUNC void bsjig_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800378: jal         0x8009E6EC
    // 0x8080037C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x8080037C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800380: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x80800384: bne         $v0, $at, L_8080039C
    if (ctx->r2 != ctx->r1) {
        // 0x80800388: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080039C;
    }
    // 0x80800388: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080038C: jal         0x80099B94
    // 0x80800390: nop

    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x80800390: nop

    after_1:
    // 0x80800394: b           L_808003A8
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003A8;
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080039C:
    // 0x8080039C: jal         0x80099AA8
    // 0x808003A0: nop

    func_80099AA8(rdram, ctx);
        goto after_2;
    // 0x808003A0: nop

    after_2:
    // 0x808003A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003A8:
    // 0x808003A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003AC: jr          $ra
    // 0x808003B0: nop

    return;
    // 0x808003B0: nop

;}
RECOMP_FUNC void func_80800D48_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D50: jal         0x800839B8
    // 0x80800D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D58: jal         0x80800508
    // 0x80800D5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800508_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x80800D5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D68: jr          $ra
    // 0x80800D6C: nop

    return;
    // 0x80800D6C: nop

;}
RECOMP_FUNC void gcgoto_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808006FC: jr          $ra
    // 0x80800700: sb          $a0, 0x75C0($at)
    MEM_B(0X75C0, ctx->r1) = ctx->r4;
    return;
    // 0x80800700: sb          $a0, 0x75C0($at)
    MEM_B(0X75C0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800BD594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD59C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BD5A0: jal         0x800EA068
    // 0x800BD5A4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_800EA068(rdram, ctx);
        goto after_0;
    // 0x800BD5A4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_0:
    // 0x800BD5A8: beq         $v0, $zero, L_800BD5C0
    if (ctx->r2 == 0) {
        // 0x800BD5AC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800BD5C0;
    }
    // 0x800BD5AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BD5B0: jal         0x8010A874
    // 0x800BD5B4: nop

    func_8010A874(rdram, ctx);
        goto after_1;
    // 0x800BD5B4: nop

    after_1:
    // 0x800BD5B8: b           L_800BD5D0
    // 0x800BD5BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800BD5D0;
    // 0x800BD5BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BD5C0:
    // 0x800BD5C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BD5C4: jal         0x800D3104
    // 0x800BD5C8: addiu       $a1, $a1, -0x7BF0
    ctx->r5 = ADD32(ctx->r5, -0X7BF0);
    func_800D3104(rdram, ctx);
        goto after_2;
    // 0x800BD5C8: addiu       $a1, $a1, -0x7BF0
    ctx->r5 = ADD32(ctx->r5, -0X7BF0);
    after_2:
    // 0x800BD5CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BD5D0:
    // 0x800BD5D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BD5D4: jr          $ra
    // 0x800BD5D8: nop

    return;
    // 0x800BD5D8: nop

;}
RECOMP_FUNC void func_800F7C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7C0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7C10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F7C14: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7C18: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F7C1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7C20: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7C24: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7C28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F7C2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7C30: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800F7C34: jal         0x8009ACF4
    // 0x800F7C38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009ACF4(rdram, ctx);
        goto after_0;
    // 0x800F7C38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7C3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7C40: jal         0x8009E7C8
    // 0x800F7C44: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009E7C8(rdram, ctx);
        goto after_1;
    // 0x800F7C44: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800F7C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7C50: jr          $ra
    // 0x800F7C54: nop

    return;
    // 0x800F7C54: nop

;}
RECOMP_FUNC void _chgameselect_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BC8: syscall     205
    recomp_syscall_handler(rdram, ctx, 0x80085BC8);
    return;
    // 0x80085BCC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _subaddiebounce_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A88: syscall     801
    recomp_syscall_handler(rdram, ctx, 0x80089A88);
    return;
    // 0x80089A8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _ncbapivot_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089488: syscall     781
    recomp_syscall_handler(rdram, ctx, 0x80089488);
    return;
    // 0x8008948C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080000C_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bsbeemain_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082898: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x80082898);
    return;
    // 0x8008289C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800270_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080027C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800280: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800284: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800288: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x8080028C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800290: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800294: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800298: nop

    // 0x8080029C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x808002A0: beql        $t8, $zero, L_808002F0
    if (ctx->r24 == 0) {
        // 0x808002A4: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_808002F0;
    }
    goto skip_0;
    // 0x808002A4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x808002A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808002B0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808002B4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x808002B8: nop

    // 0x808002BC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808002C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808002C4: nop

    // 0x808002C8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x808002CC: bne         $t8, $zero, L_808002E4
    if (ctx->r24 != 0) {
        // 0x808002D0: nop
    
            goto L_808002E4;
    }
    // 0x808002D0: nop

    // 0x808002D4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x808002D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808002DC: b           L_808002FC
    // 0x808002E0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_808002FC;
    // 0x808002E0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_808002E4:
    // 0x808002E4: b           L_808002FC
    // 0x808002E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_808002FC;
    // 0x808002E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808002EC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_808002F0:
    // 0x808002F0: nop

    // 0x808002F4: bltz        $t8, L_808002E4
    if (SIGNED(ctx->r24) < 0) {
        // 0x808002F8: nop
    
            goto L_808002E4;
    }
    // 0x808002F8: nop

L_808002FC:
    // 0x808002FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800300: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80800304: beq         $at, $zero, L_808003C4
    if (ctx->r1 == 0) {
        // 0x80800308: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808003C4;
    }
    // 0x80800308: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080030C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1604, 0XCF4) << 16);
    // 0x80800310: addu        $at, $at, $t8
    gpr jr_addend_80800318 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800314: lw          $t8, 0xCF4($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1604, 0XCF4));
    // 0x80800318: jr          $t8
    // 0x8080031C: nop

    switch (jr_addend_80800318 >> 2) {
        case 0: goto L_80800390; break;
        case 1: goto L_80800390; break;
        case 2: goto L_80800390; break;
        case 3: goto L_80800390; break;
        case 4: goto L_80800390; break;
        case 5: goto L_80800390; break;
        case 6: goto L_80800320; break;
        case 7: goto L_80800390; break;
        default: switch_error(__func__, 0x80800318, 0x80800CF4);
    }
    // 0x8080031C: nop

L_80800320:
    // 0x80800320: jal         0x800DA298
    // 0x80800324: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800324: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_0:
    // 0x80800328: bne         $v0, $zero, L_80800354
    if (ctx->r2 != 0) {
        // 0x8080032C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800354;
    }
    // 0x8080032C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800330: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800334: jal         0x80089A00
    // 0x80800338: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    _sumole_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800338: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    after_1:
    // 0x8080033C: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x80800340: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003C4;
    }
    // 0x80800340: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800344: jal         0x80101FDC
    // 0x80800348: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800348: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080034C: b           L_808003C8
    // 0x80800350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003C8;
    // 0x80800350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800354:
    // 0x80800354: jal         0x8008FD70
    // 0x80800358: nop

    func_8008FD70(rdram, ctx);
        goto after_3;
    // 0x80800358: nop

    after_3:
    // 0x8080035C: andi        $t9, $v0, 0x701
    ctx->r25 = ctx->r2 & 0X701;
    // 0x80800360: beq         $t9, $zero, L_808003C4
    if (ctx->r25 == 0) {
        // 0x80800364: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003C4;
    }
    // 0x80800364: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800368: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8080036C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800370: jal         0x800899D8
    // 0x80800374: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _sumole_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800374: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80800378: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x8080037C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003C4;
    }
    // 0x8080037C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800380: jal         0x80101FDC
    // 0x80800384: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800384: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800388: b           L_808003C8
    // 0x8080038C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003C8;
    // 0x8080038C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800390:
    // 0x80800390: jal         0x8008FD70
    // 0x80800394: nop

    func_8008FD70(rdram, ctx);
        goto after_6;
    // 0x80800394: nop

    after_6:
    // 0x80800398: andi        $t0, $v0, 0x701
    ctx->r8 = ctx->r2 & 0X701;
    // 0x8080039C: beq         $t0, $zero, L_808003C4
    if (ctx->r8 == 0) {
        // 0x808003A0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003C4;
    }
    // 0x808003A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808003A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003AC: jal         0x800899D8
    // 0x808003B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _sumole_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808003B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x808003B4: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x808003B8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808003C4;
    }
    // 0x808003B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003BC: jal         0x80101FDC
    // 0x808003C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x808003C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
L_808003C4:
    // 0x808003C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003C8:
    // 0x808003C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

;}
RECOMP_FUNC void _bakaztorpedo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D70: syscall     136
    recomp_syscall_handler(rdram, ctx, 0x80084D70);
    return;
    // 0x80084D74: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80800094_bsbkflamethrower(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800098: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080009C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A4: jal         0x8008CABC
    // 0x808000A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808000A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000AC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808000B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000B4: sltiu       $at, $v1, 0x5
    ctx->r1 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x808000B8: beq         $at, $zero, L_8080021C
    if (ctx->r1 == 0) {
        // 0x808000BC: sw          $v1, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r3;
            goto L_8080021C;
    }
    // 0x808000BC: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
    // 0x808000C0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x808000C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(100, 0X430) << 16);
    // 0x808000C8: addu        $at, $at, $t6
    gpr jr_addend_808000D0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808000CC: lw          $t6, 0x430($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(100, 0X430));
    // 0x808000D0: jr          $t6
    // 0x808000D4: nop

    switch (jr_addend_808000D0 >> 2) {
        case 0: goto L_80800208; break;
        case 1: goto L_808000D8; break;
        case 2: goto L_80800180; break;
        case 3: goto L_808001C8; break;
        case 4: goto L_808001EC; break;
        default: switch_error(__func__, 0x808000D0, 0x80800430);
    }
    // 0x808000D4: nop

L_808000D8:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x808000E0: jal         0x8008CCBC
    // 0x808000E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x808000E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x808000E8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808000EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808000FC: jal         0x8009FFD8
    // 0x80800100: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800100: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x80800104: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x80800108: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: jal         0x8009C99C
    // 0x80800114: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80800114: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_3:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x8009B9B0
    // 0x80800120: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800120: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x800A0CF4
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_5;
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800130: jal         0x8009D874
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_6;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800138: jal         0x800C6E38
    // 0x8080013C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800C6E38(rdram, ctx);
        goto after_7;
    // 0x8080013C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_7:
    // 0x80800140: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x80800144: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800154;
    }
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(100, 0X444) << 16);
    // 0x8080014C: b           L_8080015C
    // 0x80800150: lwc1        $f0, 0x444($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(100, 0X444));
        goto L_8080015C;
    // 0x80800150: lwc1        $f0, 0x444($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(100, 0X444));
L_80800154:
    // 0x80800154: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800158: nop

L_8080015C:
    // 0x8080015C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800160: jal         0x80085338
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_8;
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800168: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8080016C: addiu       $a1, $a1, 0x29A0
    ctx->r5 = ADD32(ctx->r5, 0X29A0);
    // 0x80800170: jal         0x80084BA8
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflamethrower_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800178: b           L_80800220
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800220;
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800180:
    // 0x80800180: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800184: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80800188: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080018C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800190: jal         0x8008B1D4
    // 0x80800194: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    anctrl_setSubrange(rdram, ctx);
        goto after_10;
    // 0x80800194: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_10:
    // 0x80800198: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080019C: jal         0x8008B134
    // 0x808001A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_11;
    // 0x808001A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x808001A4: lui         $a2, 0x3E0F
    ctx->r6 = S32(0X3E0F << 16);
    // 0x808001A8: ori         $a2, $a2, 0x5C29
    ctx->r6 = ctx->r6 | 0X5C29;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x80085338
    // 0x808001B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_set(rdram, ctx);
        goto after_12;
    // 0x808001B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x808001B8: jal         0x80084BB0
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflamethrower_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001C0: b           L_80800220
    // 0x808001C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800220;
    // 0x808001C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001C8:
    // 0x808001C8: jal         0x80084BB8
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflamethrower_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808001D0: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x808001D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x80085338
    // 0x808001E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_15;
    // 0x808001E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808001E4: b           L_80800220
    // 0x808001E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800220;
    // 0x808001E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001EC:
    // 0x808001EC: jal         0x8008B134
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_16;
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x8008CED4
    // 0x808001FC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_17;
    // 0x808001FC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_17:
    // 0x80800200: b           L_80800220
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800220;
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800208:
    // 0x80800208: jal         0x80084BA0
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflamethrower_entrypoint_1(rdram, ctx);
        goto after_18;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: jal         0x800A0CF4
    // 0x80800218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_19;
    // 0x80800218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
L_8080021C:
    // 0x8080021C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800220:
    // 0x80800220: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800224: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800228: jr          $ra
    // 0x8080022C: nop

    return;
    // 0x8080022C: nop

;}
RECOMP_FUNC void func_80800350_chfactoryworkerwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800354: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80800358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080035C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800360: beq         $a1, $at, L_8080037C
    if (ctx->r5 == ctx->r1) {
        // 0x80800364: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080037C;
    }
    // 0x80800364: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800368: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x8080036C: beq         $a1, $at, L_808003D8
    if (ctx->r5 == ctx->r1) {
        // 0x80800370: nop
    
            goto L_808003D8;
    }
    // 0x80800370: nop

    // 0x80800374: b           L_808003E4
    // 0x80800378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003E4;
    // 0x80800378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080037C:
    // 0x8080037C: lh          $v1, 0x20($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X20);
    // 0x80800380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800384: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800388: beq         $v1, $at, L_808003A8
    if (ctx->r3 == ctx->r1) {
        // 0x8080038C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003A8;
    }
    // 0x8080038C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800390: beq         $v1, $at, L_808003B8
    if (ctx->r3 == ctx->r1) {
        // 0x80800394: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808003B8;
    }
    // 0x80800394: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800398: beq         $v1, $at, L_808003C8
    if (ctx->r3 == ctx->r1) {
        // 0x8080039C: nop
    
            goto L_808003C8;
    }
    // 0x8080039C: nop

    // 0x808003A0: b           L_808003E4
    // 0x808003A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003E4;
    // 0x808003A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003A8:
    // 0x808003A8: jal         0x80800260
    // 0x808003AC: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    func_80800260_chfactoryworkerwear(rdram, ctx);
        goto after_0;
    // 0x808003AC: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x808003B0: b           L_808003E4
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003E4;
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B8:
    // 0x808003B8: jal         0x80800320
    // 0x808003BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800320_chfactoryworkerwear(rdram, ctx);
        goto after_1;
    // 0x808003BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x808003C0: b           L_808003E4
    // 0x808003C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003E4;
    // 0x808003C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003C8:
    // 0x808003C8: jal         0x808002E4
    // 0x808003CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_808002E4_chfactoryworkerwear(rdram, ctx);
        goto after_2;
    // 0x808003CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x808003D0: b           L_808003E4
    // 0x808003D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003E4;
    // 0x808003D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003D8:
    // 0x808003D8: jal         0x800FFA88
    // 0x808003DC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_3;
    // 0x808003DC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    after_3:
    // 0x808003E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003E4:
    // 0x808003E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003EC: jr          $ra
    // 0x808003F0: nop

    return;
    // 0x808003F0: nop

    // 0x808003F4: nop

    // 0x808003F8: nop

    // 0x808003FC: nop

;}
RECOMP_FUNC void func_80800904_chflysaucercrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800904: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800908: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080090C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800910: jal         0x800DC0C0
    // 0x80800914: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80800914: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800918: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCCC) << 16);
    // 0x8080091C: lwc1        $f4, 0xCCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCCC));
    // 0x80800920: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80800924: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800928: nop

    // 0x8080092C: bc1fl       L_80800950
    if (!c1cs) {
        // 0x80800930: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800950;
    }
    goto skip_0;
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800934: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800938: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080093C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800940: jal         0x800DC178
    // 0x80800944: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800944: nop

    after_1:
    // 0x80800948: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800950:
    // 0x80800950: jal         0x80102B6C
    // 0x80800954: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102B6C(rdram, ctx);
        goto after_2;
    // 0x80800954: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800958: jal         0x800DC0C0
    // 0x8080095C: nop

    func_800DC0C0(rdram, ctx);
        goto after_3;
    // 0x8080095C: nop

    after_3:
    // 0x80800960: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCD0) << 16);
    // 0x80800964: lwc1        $f6, 0xCD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCD0));
    // 0x80800968: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8080096C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800970: nop

    // 0x80800974: bc1fl       L_80800998
    if (!c1cs) {
        // 0x80800978: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800998;
    }
    goto skip_1;
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080097C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800980: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800984: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800988: jal         0x800DC178
    // 0x8080098C: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x8080098C: nop

    after_4:
    // 0x80800990: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800998:
    // 0x80800998: jal         0x80102B2C
    // 0x8080099C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102B2C(rdram, ctx);
        goto after_5;
    // 0x8080099C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x808009A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808009A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009A8: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808009AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808009B0: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x808009B4: nop

    // 0x808009B8: bc1fl       L_808009E4
    if (!c1cs) {
        // 0x808009BC: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_808009E4;
    }
    goto skip_2;
    // 0x808009BC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_2:
    // 0x808009C0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808009C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009C8: jal         0x800DC178
    // 0x808009CC: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808009CC: nop

    after_6:
    // 0x808009D0: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808009D4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x808009D8: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x808009DC: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808009E0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
L_808009E4:
    // 0x808009E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808009E8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x808009EC: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x808009F0: nop

    // 0x808009F4: bc1fl       L_80800A1C
    if (!c1cs) {
        // 0x808009F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A1C;
    }
    goto skip_3;
    // 0x808009F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808009FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800A00: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800A04: jal         0x800DC178
    // 0x80800A08: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800A08: nop

    after_7:
    // 0x80800A0C: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800A10: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800A14: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x80800A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A1C:
    // 0x80800A1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A24: jr          $ra
    // 0x80800A28: nop

    return;
    // 0x80800A28: nop

;}
