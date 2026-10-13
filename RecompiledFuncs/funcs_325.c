#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808000B0_bscrashout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C4: beq         $a1, $at, L_808000E8
    if (ctx->r5 == ctx->r1) {
        // 0x808000C8: sw          $a1, 0x15C($a0)
        MEM_W(0X15C, ctx->r4) = ctx->r5;
            goto L_808000E8;
    }
    // 0x808000C8: sw          $a1, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r5;
    // 0x808000CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D0: beq         $a1, $at, L_80800150
    if (ctx->r5 == ctx->r1) {
        // 0x808000D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800150;
    }
    // 0x808000D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000D8: beq         $a1, $at, L_80800170
    if (ctx->r5 == ctx->r1) {
        // 0x808000DC: nop
    
            goto L_80800170;
    }
    // 0x808000DC: nop

    // 0x808000E0: b           L_808001B8
    // 0x808000E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001B8;
    // 0x808000E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000E8:
    // 0x808000E8: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x808000EC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x8008CCBC
    // 0x808000F8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x808000F8: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x808000FC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800100: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080010C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800110: jal         0x8009FFD8
    // 0x80800114: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800114: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800118: jal         0x8009C990
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_2;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800120: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800124: jal         0x8009B9C0
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_3;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: jal         0x8009B9B0
    // 0x80800134: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800134: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_4:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800140: jal         0x8009BA68
    // 0x80800144: lw          $a2, 0x16C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x80800144: lw          $a2, 0x16C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X16C);
    after_5:
    // 0x80800148: b           L_808001B8
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001B8;
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800150:
    // 0x80800150: jal         0x800951B4
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_6;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x80800160: jal         0x8008CCBC
    // 0x80800164: lui         $a2, 0x4010
    ctx->r6 = S32(0X4010 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_7;
    // 0x80800164: lui         $a2, 0x4010
    ctx->r6 = S32(0X4010 << 16);
    after_7:
    // 0x80800168: b           L_808001B8
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001B8;
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800170:
    // 0x80800170: jal         0x800A0180
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0180(rdram, ctx);
        goto after_8;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: jal         0x800A4DFC
    // 0x80800180: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DFC(rdram, ctx);
        goto after_9;
    // 0x80800180: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_9:
    // 0x80800184: jal         0x800A4CA8
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_10;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080018C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800190: jal         0x80089288
    // 0x80800194: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800194: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_11:
    // 0x80800198: jal         0x80085208
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001A0: lui         $a2, 0x404C
    ctx->r6 = S32(0X404C << 16);
    // 0x808001A4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80085338
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_13;
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x808001B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001B8:
    // 0x808001B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void func_800F7E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F7EA0: beq         $a1, $zero, L_800F7EBC
    if (ctx->r5 == 0) {
        // 0x800F7EA4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800F7EBC;
    }
    // 0x800F7EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7EA8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7EAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7EB0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7EB4: jal         0x800A4E74
    // 0x800F7EB8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A4E74(rdram, ctx);
        goto after_0;
    // 0x800F7EB8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
L_800F7EBC:
    // 0x800F7EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7EC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F7EC4: jr          $ra
    // 0x800F7EC8: nop

    return;
    // 0x800F7EC8: nop

;}
RECOMP_FUNC void func_800FE740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE740: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FE744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FE748: jal         0x800EA05C
    // 0x800FE74C: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800FE74C: nop

    after_0:
    // 0x800FE750: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FE754: addiu       $v1, $v1, 0x5A10
    ctx->r3 = ADD32(ctx->r3, 0X5A10);
    // 0x800FE758: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
    // 0x800FE75C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FE760: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800FE764: beq         $t6, $zero, L_800FE770
    if (ctx->r14 == 0) {
        // 0x800FE768: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800FE770;
    }
    // 0x800FE768: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE76C: sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
L_800FE770:
    // 0x800FE770: sw          $zero, 0x5A08($at)
    MEM_W(0X5A08, ctx->r1) = 0;
    // 0x800FE774: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE778: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE77C: swc1        $f4, 0x5A0C($at)
    MEM_W(0X5A0C, ctx->r1) = ctx->f4.u32l;
    // 0x800FE780: addiu       $a0, $a0, 0x59C0
    ctx->r4 = ADD32(ctx->r4, 0X59C0);
    // 0x800FE784: jal         0x80087870
    // 0x800FE788: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _cothemedll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800FE788: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800FE78C: jal         0x80087860
    // 0x800FE790: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _cothemedll_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x800FE790: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800FE794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FE798: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE79C: sh          $v0, 0x59E2($at)
    MEM_H(0X59E2, ctx->r1) = ctx->r2;
    // 0x800FE7A0: jr          $ra
    // 0x800FE7A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FE7A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80111154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80111158: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011115C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80111160: jal         0x800136E4
    // 0x80111164: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x80111164: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80111168: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8011116C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80111170: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80111174: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80111178: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    // 0x8011117C: jal         0x80112D90
    // 0x80111180: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80112D90(rdram, ctx);
        goto after_1;
    // 0x80111180: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x80111184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80111188: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8011118C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80111190: jr          $ra
    // 0x80111194: nop

    return;
    // 0x80111194: nop

;}
RECOMP_FUNC void _dbmorph_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087990: syscall     643
    recomp_syscall_handler(rdram, ctx, 0x80087990);
    return;
    // 0x80087994: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808005B8_chtimetable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005BC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808005C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808005C8: beq         $a1, $at, L_808005E4
    if (ctx->r5 == ctx->r1) {
        // 0x808005CC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808005E4;
    }
    // 0x808005CC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808005D0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808005D4: beq         $a1, $at, L_8080069C
    if (ctx->r5 == ctx->r1) {
        // 0x808005D8: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1592, 0X7BC) << 16);
            goto L_8080069C;
    }
    // 0x808005D8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1592, 0X7BC) << 16);
    // 0x808005DC: b           L_808006BC
    // 0x808005E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006BC;
    // 0x808005E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005E4:
    // 0x808005E4: lbu         $t6, 0x74($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X74);
    // 0x808005E8: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x808005EC: sb          $t7, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r15;
    // 0x808005F0: lh          $t8, 0x28($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X28);
    // 0x808005F4: addiu       $t9, $t8, -0xCF4
    ctx->r25 = ADD32(ctx->r24, -0XCF4);
    // 0x808005F8: sltiu       $at, $t9, 0x13
    ctx->r1 = ctx->r25 < 0X13 ? 1 : 0;
    // 0x808005FC: beq         $at, $zero, L_808006B8
    if (ctx->r1 == 0) {
        // 0x80800600: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808006B8;
    }
    // 0x80800600: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800604: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1592, 0X6E4) << 16);
    // 0x80800608: addu        $at, $at, $t9
    gpr jr_addend_80800610 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8080060C: lw          $t9, 0x6E4($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1592, 0X6E4));
    // 0x80800610: jr          $t9
    // 0x80800614: nop

    switch (jr_addend_80800610 >> 2) {
        case 0: goto L_8080068C; break;
        case 1: goto L_80800650; break;
        case 2: goto L_80800650; break;
        case 3: goto L_80800650; break;
        case 4: goto L_80800650; break;
        case 5: goto L_80800650; break;
        case 6: goto L_80800650; break;
        case 7: goto L_80800650; break;
        case 8: goto L_808006B8; break;
        case 9: goto L_808006B8; break;
        case 10: goto L_808006B8; break;
        case 11: goto L_808006B8; break;
        case 12: goto L_808006B8; break;
        case 13: goto L_808006B8; break;
        case 14: goto L_808006B8; break;
        case 15: goto L_808006B8; break;
        case 16: goto L_808006B8; break;
        case 17: goto L_808006B8; break;
        case 18: goto L_80800618; break;
        default: switch_error(__func__, 0x80800610, 0x808006E4);
    }
    // 0x80800614: nop

L_80800618:
    // 0x80800618: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x8080061C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800620: bnel        $t0, $at, L_808006BC
    if (ctx->r8 != ctx->r1) {
        // 0x80800624: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808006BC;
    }
    goto skip_0;
    // 0x80800624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800628: jal         0x80800308
    // 0x8080062C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80800308_chtimetable(rdram, ctx);
        goto after_0;
    // 0x8080062C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800630: jal         0x800EA05C
    // 0x80800634: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800634: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800638: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080063C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800640: jal         0x8080025C
    // 0x80800644: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_8080025C_chtimetable(rdram, ctx);
        goto after_2;
    // 0x80800644: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80800648: b           L_808006BC
    // 0x8080064C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006BC;
    // 0x8080064C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800650:
    // 0x80800650: jal         0x80800308
    // 0x80800654: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80800308_chtimetable(rdram, ctx);
        goto after_3;
    // 0x80800654: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800658: jal         0x800EA05C
    // 0x8080065C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_4;
    // 0x8080065C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800660: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800664: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800668: jal         0x8080016C
    // 0x8080066C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_8080016C_chtimetable(rdram, ctx);
        goto after_5;
    // 0x8080066C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80800670: beq         $v0, $zero, L_8080068C
    if (ctx->r2 == 0) {
        // 0x80800674: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080068C;
    }
    // 0x80800674: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800678: addiu       $a1, $zero, 0xD06
    ctx->r5 = ADD32(0, 0XD06);
    // 0x8080067C: jal         0x80800364
    // 0x80800680: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    func_80800364_chtimetable(rdram, ctx);
        goto after_6;
    // 0x80800680: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    after_6:
    // 0x80800684: b           L_808006BC
    // 0x80800688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006BC;
    // 0x80800688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080068C:
    // 0x8080068C: jal         0x800C0850
    // 0x80800690: nop

    func_800C0850(rdram, ctx);
        goto after_7;
    // 0x80800690: nop

    after_7:
    // 0x80800694: b           L_808006BC
    // 0x80800698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006BC;
    // 0x80800698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080069C:
    // 0x8080069C: addiu       $a0, $a0, 0x7BC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1592, 0X7BC));
    // 0x808006A0: jal         0x80088090
    // 0x808006A4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808006A4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_8:
    // 0x808006A8: b           L_808006BC
    // 0x808006AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006BC;
    // 0x808006AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808006B0: b           L_808006BC
    // 0x808006B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006BC;
    // 0x808006B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006B8:
    // 0x808006B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006BC:
    // 0x808006BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006C4: jr          $ra
    // 0x808006C8: nop

    return;
    // 0x808006C8: nop

;}
RECOMP_FUNC void func_80801058_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080105C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801060: lbu         $t6, 0x212($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X212);
    // 0x80801064: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80801068: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8080106C: beq         $t6, $zero, L_80801084
    if (ctx->r14 == 0) {
        // 0x80801070: nop
    
            goto L_80801084;
    }
    // 0x80801070: nop

    // 0x80801074: jal         0x80800338
    // 0x80801078: sb          $zero, 0x212($a0)
    MEM_B(0X212, ctx->r4) = 0;
    func_80800338_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x80801078: sb          $zero, 0x212($a0)
    MEM_B(0X212, ctx->r4) = 0;
    after_0:
    // 0x8080107C: b           L_80801088
    // 0x80801080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801088;
    // 0x80801080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801084:
    // 0x80801084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801088:
    // 0x80801088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080108C: jr          $ra
    // 0x80801090: nop

    return;
    // 0x80801090: nop

;}
RECOMP_FUNC void subaddiepalette_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808002C0: sh          $t6, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r14;
    // 0x808002C4: lh          $t7, 0x60($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X60);
    // 0x808002C8: beql        $t7, $zero, L_808002E4
    if (ctx->r15 == 0) {
        // 0x808002CC: lbu         $t0, 0x70($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X70);
            goto L_808002E4;
    }
    goto skip_0;
    // 0x808002CC: lbu         $t0, 0x70($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X70);
    skip_0:
    // 0x808002D0: lbu         $t8, 0x7B($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X7B);
    // 0x808002D4: srl         $t9, $t8, 6
    ctx->r25 = S32(U32(ctx->r24) >> 6);
    // 0x808002D8: bne         $t9, $zero, L_808002FC
    if (ctx->r25 != 0) {
        // 0x808002DC: nop
    
            goto L_808002FC;
    }
    // 0x808002DC: nop

    // 0x808002E0: lbu         $t0, 0x70($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X70);
L_808002E4:
    // 0x808002E4: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x808002E8: beq         $t1, $zero, L_808002FC
    if (ctx->r9 == 0) {
        // 0x808002EC: nop
    
            goto L_808002FC;
    }
    // 0x808002EC: nop

    // 0x808002F0: lh          $t2, 0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X6);
    // 0x808002F4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x808002F8: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
L_808002FC:
    // 0x808002FC: jr          $ra
    // 0x80800300: nop

    return;
    // 0x80800300: nop

    // 0x80800304: nop

    // 0x80800308: nop

    // 0x8080030C: nop

;}
RECOMP_FUNC void _chphlegm_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086020: syscall     271
    recomp_syscall_handler(rdram, ctx, 0x80086020);
    return;
    // 0x80086024: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80102F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102F7C: jal         0x80100368
    // 0x80102F80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80100368(rdram, ctx);
        goto after_0;
    // 0x80102F80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80102F84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102F88: jal         0x80102FA0
    // 0x80102F8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80102FA0(rdram, ctx);
        goto after_1;
    // 0x80102F8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80102F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102F94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102F98: jr          $ra
    // 0x80102F9C: nop

    return;
    // 0x80102F9C: nop

;}
RECOMP_FUNC void func_808015AC_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808015B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808015B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808015B8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808015BC: jal         0x80100094
    // 0x808015C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808015C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808015C4: lw          $t6, 0x128($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X128);
    // 0x808015C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808015CC: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x808015D0: bnel        $t7, $zero, L_80801650
    if (ctx->r15 != 0) {
        // 0x808015D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801650;
    }
    goto skip_0;
    // 0x808015D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808015D8: lbu         $t9, 0x128($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X128);
    // 0x808015DC: addiu       $a1, $v0, 0x110
    ctx->r5 = ADD32(ctx->r2, 0X110);
    // 0x808015E0: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x808015E4: sb          $t0, 0x128($v0)
    MEM_B(0X128, ctx->r2) = ctx->r8;
    // 0x808015E8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808015EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808015F0: jal         0x800EE7F8
    // 0x808015F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808015F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x808015F8: jal         0x800EFD24
    // 0x808015FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x808015FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80801600: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801604: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80801608: jal         0x800F18FC
    // 0x8080160C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800F18FC(rdram, ctx);
        goto after_3;
    // 0x8080160C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x80801610: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80801614: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80801618: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080161C: lwc1        $f4, 0x48($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X48);
    // 0x80801620: jal         0x800136E4
    // 0x80801624: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x80801624: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_4:
    // 0x80801628: swc1        $f0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f0.u32l;
    // 0x8080162C: swc1        $f0, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f0.u32l;
    // 0x80801630: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801634: jal         0x80013728
    // 0x80801638: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80013728(rdram, ctx);
        goto after_5;
    // 0x80801638: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_5:
    // 0x8080163C: swc1        $f0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f0.u32l;
    // 0x80801640: jal         0x800EEF94
    // 0x80801644: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EEF94(rdram, ctx);
        goto after_6;
    // 0x80801644: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80801648: swc1        $f0, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f0.u32l;
    // 0x8080164C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801650:
    // 0x80801650: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801654: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801658: jr          $ra
    // 0x8080165C: nop

    return;
    // 0x8080165C: nop

;}
RECOMP_FUNC void func_808019A8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808019AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808019B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808019B4: jal         0x808027F4
    // 0x808019B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808027F4_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x808019B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808019BC: jal         0x80802EF8
    // 0x808019C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802EF8_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x808019C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808019C4: jal         0x80807B4C
    // 0x808019C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807B4C_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x808019C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808019CC: jal         0x8080666C
    // 0x808019D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080666C_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x808019D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808019D4: jal         0x808059CC
    // 0x808019D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808059CC_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x808019D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808019DC: jal         0x8080843C
    // 0x808019E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080843C_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x808019E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808019E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019E8: jal         0x800897C8
    // 0x808019EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808019EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808019F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808019F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808019F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808019FC: jr          $ra
    // 0x80801A00: nop

    return;
    // 0x80801A00: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083258: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083258);
    return;
    // 0x8008325C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chdippy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086488: syscall     327
    recomp_syscall_handler(rdram, ctx, 0x80086488);
    return;
    // 0x8008648C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800CE8_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CF0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800CF4: jal         0x80800B6C
    // 0x80800CF8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80800B6C_chquiz(rdram, ctx);
        goto after_0;
    // 0x80800CF8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800CFC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800D00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D04: jal         0x80088718
    // 0x80800D08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800D08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800D0C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800D10: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80800D14: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x80800D18: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    // 0x80800D1C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800D20: beq         $a0, $t7, L_80800D50
    if (ctx->r4 == ctx->r15) {
        // 0x80800D24: addiu       $a1, $sp, 0x20
        ctx->r5 = ADD32(ctx->r29, 0X20);
            goto L_80800D50;
    }
    // 0x80800D24: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800D28: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D2C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_80800D30:
    // 0x80800D30: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x80800D34: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80800D38: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x80800D3C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80800D40: addu        $v1, $v0, $t2
    ctx->r3 = ADD32(ctx->r2, ctx->r10);
    // 0x80800D44: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x80800D48: bnel        $a0, $t4, L_80800D30
    if (ctx->r4 != ctx->r12) {
        // 0x80800D4C: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_80800D30;
    }
    goto skip_0;
    // 0x80800D4C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_0:
L_80800D50:
    // 0x80800D50: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80800D54: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800D58: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800D5C: addiu       $t6, $t5, 0x3
    ctx->r14 = ADD32(ctx->r13, 0X3);
    // 0x80800D60: jal         0x80800C8C
    // 0x80800D64: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80800C8C_chquiz(rdram, ctx);
        goto after_2;
    // 0x80800D64: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_2:
    // 0x80800D68: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D6C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800D70: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800D74: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80800D78: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800D7C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80800D80: jal         0x80800C8C
    // 0x80800D84: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    func_80800C8C_chquiz(rdram, ctx);
        goto after_3;
    // 0x80800D84: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_3:
    // 0x80800D88: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80800D8C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80800D90: jal         0x80088728
    // 0x80800D94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800D94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80800D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800DA0: jr          $ra
    // 0x80800DA4: nop

    return;
    // 0x80800DA4: nop

;}
RECOMP_FUNC void func_80800B24_subaddiestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B24: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800B28: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800B2C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80800B30: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80800B34: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800B38: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800B3C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800B40: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800B44: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800B48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800B4C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80800B50: addiu       $s0, $a0, 0xB0
    ctx->r16 = ADD32(ctx->r4, 0XB0);
    // 0x80800B54: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800B58: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80800B5C: lh          $t7, 0x8C($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8C);
    // 0x80800B60: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80800B64: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x80800B68: sh          $t7, 0x8C($a0)
    MEM_H(0X8C, ctx->r4) = ctx->r15;
    // 0x80800B6C: lw          $t8, 0x7C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X7C);
    // 0x80800B70: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80800B74: beql        $t9, $zero, L_80800B88
    if (ctx->r25 == 0) {
        // 0x80800B78: lw          $t0, 0x94($s7)
        ctx->r8 = MEM_W(ctx->r23, 0X94);
            goto L_80800B88;
    }
    goto skip_0;
    // 0x80800B78: lw          $t0, 0x94($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X94);
    skip_0:
    // 0x80800B7C: jal         0x80105634
    // 0x80800B80: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80105634(rdram, ctx);
        goto after_0;
    // 0x80800B80: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800B84: lw          $t0, 0x94($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X94);
L_80800B88:
    // 0x80800B88: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800B8C: srl         $t2, $t1, 22
    ctx->r10 = S32(U32(ctx->r9) >> 22);
    // 0x80800B90: beql        $t2, $zero, L_80800BA4
    if (ctx->r10 == 0) {
        // 0x80800B94: lw          $t3, 0x7C($s6)
        ctx->r11 = MEM_W(ctx->r22, 0X7C);
            goto L_80800BA4;
    }
    goto skip_1;
    // 0x80800B94: lw          $t3, 0x7C($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X7C);
    skip_1:
    // 0x80800B98: jal         0x80106EE0
    // 0x80800B9C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80106EE0(rdram, ctx);
        goto after_1;
    // 0x80800B9C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x80800BA0: lw          $t3, 0x7C($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X7C);
L_80800BA4:
    // 0x80800BA4: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x80800BA8: beql        $t4, $zero, L_80800BE0
    if (ctx->r12 == 0) {
        // 0x80800BAC: lw          $t7, 0x94($s6)
        ctx->r15 = MEM_W(ctx->r22, 0X94);
            goto L_80800BE0;
    }
    goto skip_2;
    // 0x80800BAC: lw          $t7, 0x94($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X94);
    skip_2:
    // 0x80800BB0: lhu         $t5, 0x7E($s6)
    ctx->r13 = MEM_HU(ctx->r22, 0X7E);
    // 0x80800BB4: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80800BB8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800BBC: andi        $t6, $t5, 0xF000
    ctx->r14 = ctx->r13 & 0XF000;
    // 0x80800BC0: jal         0x8010556C
    // 0x80800BC4: sh          $t6, 0x7E($s6)
    MEM_H(0X7E, ctx->r22) = ctx->r14;
    func_8010556C(rdram, ctx);
        goto after_2;
    // 0x80800BC4: sh          $t6, 0x7E($s6)
    MEM_H(0X7E, ctx->r22) = ctx->r14;
    after_2:
    // 0x80800BC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BCC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800BD0: jal         0x8001BBA0
    // 0x80800BD4: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    rare_memcpy(rdram, ctx);
        goto after_3;
    // 0x80800BD4: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    after_3:
    // 0x80800BD8: addiu       $s5, $s1, 0x48
    ctx->r21 = ADD32(ctx->r17, 0X48);
    // 0x80800BDC: lw          $t7, 0x94($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X94);
L_80800BE0:
    // 0x80800BE0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800BE4: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80800BE8: beq         $t9, $zero, L_80800C1C
    if (ctx->r25 == 0) {
        // 0x80800BEC: nop
    
            goto L_80800C1C;
    }
    // 0x80800BEC: nop

    // 0x80800BF0: lhu         $t0, 0x94($s6)
    ctx->r8 = MEM_HU(ctx->r22, 0X94);
    // 0x80800BF4: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x80800BF8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800BFC: andi        $t1, $t0, 0xC00F
    ctx->r9 = ctx->r8 & 0XC00F;
    // 0x80800C00: jal         0x80106E88
    // 0x80800C04: sh          $t1, 0x94($s6)
    MEM_H(0X94, ctx->r22) = ctx->r9;
    func_80106E88(rdram, ctx);
        goto after_4;
    // 0x80800C04: sh          $t1, 0x94($s6)
    MEM_H(0X94, ctx->r22) = ctx->r9;
    after_4:
    // 0x80800C08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C0C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800C10: jal         0x8001BBA0
    // 0x80800C14: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    rare_memcpy(rdram, ctx);
        goto after_5;
    // 0x80800C14: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_5:
    // 0x80800C18: addiu       $s5, $s0, 0x18
    ctx->r21 = ADD32(ctx->r16, 0X18);
L_80800C1C:
    // 0x80800C1C: jal         0x80800F98
    // 0x80800C20: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80800F98_subaddiestore(rdram, ctx);
        goto after_6;
    // 0x80800C20: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_6:
    // 0x80800C24: beq         $v0, $zero, L_80800CA8
    if (ctx->r2 == 0) {
        // 0x80800C28: or          $s1, $s5, $zero
        ctx->r17 = ctx->r21 | 0;
            goto L_80800CA8;
    }
    // 0x80800C28: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80800C2C: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x80800C30: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800C34: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x80800C38: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80800C3C:
    // 0x80800C3C: lh          $a0, 0x82($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X82);
    // 0x80800C40: beql        $a0, $zero, L_80800C58
    if (ctx->r4 == 0) {
        // 0x80800C44: lw          $a1, 0x0($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X0);
            goto L_80800C58;
    }
    goto skip_3;
    // 0x80800C44: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x80800C48: jal         0x8001B754
    // 0x80800C4C: nop

    func_8001B754(rdram, ctx);
        goto after_7;
    // 0x80800C4C: nop

    after_7:
    // 0x80800C50: sh          $zero, 0x82($s2)
    MEM_H(0X82, ctx->r18) = 0;
    // 0x80800C54: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
L_80800C58:
    // 0x80800C58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C5C: blezl       $a1, L_80800C94
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80800C60: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80800C94;
    }
    goto skip_4;
    // 0x80800C60: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_4:
    // 0x80800C64: jal         0x8001B668
    // 0x80800C68: addu        $s0, $s6, $s3
    ctx->r16 = ADD32(ctx->r22, ctx->r19);
    func_8001B668(rdram, ctx);
        goto after_8;
    // 0x80800C68: addu        $s0, $s6, $s3
    ctx->r16 = ADD32(ctx->r22, ctx->r19);
    after_8:
    // 0x80800C6C: sh          $v0, 0x82($s0)
    MEM_H(0X82, ctx->r16) = ctx->r2;
    // 0x80800C70: jal         0x8001B798
    // 0x80800C74: lh          $a0, 0x82($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X82);
    func_8001B798(rdram, ctx);
        goto after_9;
    // 0x80800C74: lh          $a0, 0x82($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X82);
    after_9:
    // 0x80800C78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C7C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800C80: jal         0x8001BBA0
    // 0x80800C84: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    rare_memcpy(rdram, ctx);
        goto after_10;
    // 0x80800C84: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x80800C88: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80800C8C: addu        $s5, $t2, $s5
    ctx->r21 = ADD32(ctx->r10, ctx->r21);
    // 0x80800C90: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_80800C94:
    // 0x80800C94: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800C98: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80800C9C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80800CA0: bne         $s4, $at, L_80800C3C
    if (ctx->r20 != ctx->r1) {
        // 0x80800CA4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800C3C;
    }
    // 0x80800CA4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80800CA8:
    // 0x80800CA8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800CAC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800CB0: jal         0x8001BBA0
    // 0x80800CB4: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    rare_memcpy(rdram, ctx);
        goto after_11;
    // 0x80800CB4: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    after_11:
    // 0x80800CB8: lh          $t3, 0x8C($s7)
    ctx->r11 = MEM_H(ctx->r23, 0X8C);
    // 0x80800CBC: bne         $t3, $zero, L_80800CD0
    if (ctx->r11 != 0) {
        // 0x80800CC0: nop
    
            goto L_80800CD0;
    }
    // 0x80800CC0: nop

    // 0x80800CC4: lh          $t5, 0xAE($s6)
    ctx->r13 = MEM_H(ctx->r22, 0XAE);
    // 0x80800CC8: bgezl       $t5, L_80800E70
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800CCC: lw          $s0, 0x0($s7)
        ctx->r16 = MEM_W(ctx->r23, 0X0);
            goto L_80800E70;
    }
    goto skip_5;
    // 0x80800CCC: lw          $s0, 0x0($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X0);
    skip_5:
L_80800CD0:
    // 0x80800CD0: jal         0x80104248
    // 0x80800CD4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80104248(rdram, ctx);
        goto after_12;
    // 0x80800CD4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_12:
    // 0x80800CD8: lh          $t7, 0xAE($s6)
    ctx->r15 = MEM_H(ctx->r22, 0XAE);
    // 0x80800CDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800CE0: bgez        $t7, L_80800E64
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800CE4: nop
    
            goto L_80800E64;
    }
    // 0x80800CE4: nop

    // 0x80800CE8: bnel        $v0, $zero, L_80800D00
    if (ctx->r2 != 0) {
        // 0x80800CEC: lhu         $v0, 0x9C($s6)
        ctx->r2 = MEM_HU(ctx->r22, 0X9C);
            goto L_80800D00;
    }
    goto skip_6;
    // 0x80800CEC: lhu         $v0, 0x9C($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X9C);
    skip_6:
    // 0x80800CF0: jal         0x801042B8
    // 0x80800CF4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_801042B8(rdram, ctx);
        goto after_13;
    // 0x80800CF4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_13:
    // 0x80800CF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800CFC: lhu         $v0, 0x9C($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X9C);
L_80800D00:
    // 0x80800D00: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x80800D04: beq         $t8, $zero, L_80800D14
    if (ctx->r24 == 0) {
        // 0x80800D08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D14;
    }
    // 0x80800D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D0C: jal         0x8008B134
    // 0x80800D10: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    anctrl_setPlaybackType(rdram, ctx);
        goto after_14;
    // 0x80800D10: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_14:
L_80800D14:
    // 0x80800D14: lhu         $a1, 0x9E($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X9E);
    // 0x80800D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D1C: srl         $t9, $a1, 2
    ctx->r25 = S32(U32(ctx->r5) >> 2);
    // 0x80800D20: jal         0x8008AED4
    // 0x80800D24: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    anctrl_setIndex(rdram, ctx);
        goto after_15;
    // 0x80800D24: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_15:
    // 0x80800D28: lw          $a1, 0xAC($s6)
    ctx->r5 = MEM_W(ctx->r22, 0XAC);
    // 0x80800D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D30: srl         $t0, $a1, 31
    ctx->r8 = S32(U32(ctx->r5) >> 31);
    // 0x80800D34: jal         0x8008B188
    // 0x80800D38: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_8008B188(rdram, ctx);
        goto after_16;
    // 0x80800D38: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_16:
    // 0x80800D3C: lw          $a1, 0x9C($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X9C);
    // 0x80800D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D44: srl         $t1, $a1, 31
    ctx->r9 = S32(U32(ctx->r5) >> 31);
    // 0x80800D48: jal         0x8008B1A0
    // 0x80800D4C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_17;
    // 0x80800D4C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_17:
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D54: jal         0x8008B1BC
    // 0x80800D58: lw          $a1, 0xA0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0XA0);
    anctrl_setDuration(rdram, ctx);
        goto after_18;
    // 0x80800D58: lw          $a1, 0xA0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0XA0);
    after_18:
    // 0x80800D5C: lhu         $t2, 0xA8($s6)
    ctx->r10 = MEM_HU(ctx->r22, 0XA8);
    // 0x80800D60: lui         $at, 0x3800
    ctx->r1 = S32(0X3800 << 16);
    // 0x80800D64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800D68: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80800D6C: bgez        $t2, L_80800D84
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800D70: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800D84;
    }
    // 0x80800D70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800D74: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800D78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D7C: nop

    // 0x80800D80: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800D84:
    // 0x80800D84: lhu         $t3, 0xAA($s6)
    ctx->r11 = MEM_HU(ctx->r22, 0XAA);
    // 0x80800D88: mul.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80800D8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800D90: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80800D94: bgez        $t3, L_80800DA8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800D98: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80800DA8;
    }
    // 0x80800D98: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800D9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800DA0: nop

    // 0x80800DA4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80800DA8:
    // 0x80800DA8: lhu         $t4, 0xA4($s6)
    ctx->r12 = MEM_HU(ctx->r22, 0XA4);
    // 0x80800DAC: mul.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80800DB0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800DB4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800DB8: bgez        $t4, L_80800DCC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800DBC: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800DCC;
    }
    // 0x80800DBC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800DC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800DC4: nop

    // 0x80800DC8: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_80800DCC:
    // 0x80800DCC: mul.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80800DD0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800DD4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800DD8: jal         0x800F0D50
    // 0x80800DDC: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    func_800F0D50(rdram, ctx);
        goto after_19;
    // 0x80800DDC: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    after_19:
    // 0x80800DE0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800DE4: lhu         $t5, 0xA6($s6)
    ctx->r13 = MEM_HU(ctx->r22, 0XA6);
    // 0x80800DE8: lui         $at, 0x3800
    ctx->r1 = S32(0X3800 << 16);
    // 0x80800DEC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800DF0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80800DF4: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800DF8: bgez        $t5, L_80800E10
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800DFC: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80800E10;
    }
    // 0x80800DFC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800E00: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800E04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800E08: nop

    // 0x80800E0C: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_80800E10:
    // 0x80800E10: mul.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800E14: jal         0x800F0D50
    // 0x80800E18: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_800F0D50(rdram, ctx);
        goto after_20;
    // 0x80800E18: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_20:
    // 0x80800E1C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E24: jal         0x8008B10C
    // 0x80800E28: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_8008B10C(rdram, ctx);
        goto after_21;
    // 0x80800E28: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_21:
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E30: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800E34: jal         0x8008B1D4
    // 0x80800E38: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    anctrl_setSubrange(rdram, ctx);
        goto after_22;
    // 0x80800E38: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_22:
    // 0x80800E3C: jal         0x8008B064
    // 0x80800E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_23;
    // 0x80800E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E48: jal         0x8008B2DC
    // 0x80800E4C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_8008B2DC(rdram, ctx);
        goto after_24;
    // 0x80800E4C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_24:
    // 0x80800E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E54: jal         0x8008B10C
    // 0x80800E58: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_8008B10C(rdram, ctx);
        goto after_25;
    // 0x80800E58: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_25:
    // 0x80800E5C: b           L_80800E70
    // 0x80800E60: lw          $s0, 0x0($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X0);
        goto L_80800E70;
    // 0x80800E60: lw          $s0, 0x0($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X0);
L_80800E64:
    // 0x80800E64: jal         0x80104328
    // 0x80800E68: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80104328(rdram, ctx);
        goto after_26;
    // 0x80800E68: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_26:
    // 0x80800E6C: lw          $s0, 0x0($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X0);
L_80800E70:
    // 0x80800E70: lhu         $t7, 0xAC($s6)
    ctx->r15 = MEM_HU(ctx->r22, 0XAC);
    // 0x80800E74: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800E78: lhu         $t0, 0x12($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X12);
    // 0x80800E7C: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80800E80: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80800E84: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800E88: sh          $t2, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r10;
    // 0x80800E8C: lw          $a1, 0x9C($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X9C);
    // 0x80800E90: sll         $t3, $a1, 30
    ctx->r11 = S32(ctx->r5 << 30);
    // 0x80800E94: jal         0x8010A654
    // 0x80800E98: srl         $a1, $t3, 31
    ctx->r5 = S32(U32(ctx->r11) >> 31);
    func_8010A654(rdram, ctx);
        goto after_27;
    // 0x80800E98: srl         $a1, $t3, 31
    ctx->r5 = S32(U32(ctx->r11) >> 31);
    after_27:
    // 0x80800E9C: lw          $s0, 0x0($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X0);
    // 0x80800EA0: lw          $t5, 0x9C($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X9C);
    // 0x80800EA4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800EA8: lbu         $t9, 0x2A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2A);
    // 0x80800EAC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80800EB0: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80800EB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800EB8: andi        $t0, $t8, 0x4
    ctx->r8 = ctx->r24 & 0X4;
    // 0x80800EBC: andi        $t1, $t9, 0xFFFB
    ctx->r9 = ctx->r25 & 0XFFFB;
    // 0x80800EC0: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80800EC4: sb          $t2, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r10;
    // 0x80800EC8: lw          $s0, 0x0($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X0);
    // 0x80800ECC: lw          $t3, 0x9C($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X9C);
    // 0x80800ED0: lbu         $t8, 0x2A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2A);
    // 0x80800ED4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80800ED8: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x80800EDC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80800EE0: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80800EE4: andi        $t9, $t8, 0xFFFD
    ctx->r25 = ctx->r24 & 0XFFFD;
    // 0x80800EE8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800EEC: sb          $t0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r8;
    // 0x80800EF0: lbu         $t1, 0x7E($s7)
    ctx->r9 = MEM_BU(ctx->r23, 0X7E);
    // 0x80800EF4: lw          $s0, 0x0($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X0);
    // 0x80800EF8: andi        $t3, $t1, 0xFF7F
    ctx->r11 = ctx->r9 & 0XFF7F;
    // 0x80800EFC: sb          $t3, 0x7E($s7)
    MEM_B(0X7E, ctx->r23) = ctx->r11;
    // 0x80800F00: andi        $t4, $t3, 0xEF
    ctx->r12 = ctx->r11 & 0XEF;
    // 0x80800F04: sb          $t4, 0x7E($s7)
    MEM_B(0X7E, ctx->r23) = ctx->r12;
    // 0x80800F08: lw          $t5, 0xAC($s6)
    ctx->r13 = MEM_W(ctx->r22, 0XAC);
    // 0x80800F0C: lhu         $t0, 0x2A($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X2A);
    // 0x80800F10: sll         $t6, $t5, 17
    ctx->r14 = S32(ctx->r13 << 17);
    // 0x80800F14: srl         $t8, $t6, 26
    ctx->r24 = S32(U32(ctx->r14) >> 26);
    // 0x80800F18: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x80800F1C: andi        $t9, $t7, 0x1FE
    ctx->r25 = ctx->r15 & 0X1FE;
    // 0x80800F20: andi        $t1, $t0, 0xFE01
    ctx->r9 = ctx->r8 & 0XFE01;
    // 0x80800F24: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800F28: sh          $t2, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r10;
    // 0x80800F2C: lw          $s0, 0x0($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X0);
    // 0x80800F30: lbu         $t4, 0xAE($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0XAE);
    // 0x80800F34: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    // 0x80800F38: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80800F3C: andi        $t8, $t6, 0xFFFE
    ctx->r24 = ctx->r14 & 0XFFFE;
    // 0x80800F40: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x80800F44: sb          $t7, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r15;
    // 0x80800F48: lw          $s0, 0x0($s7)
    ctx->r16 = MEM_W(ctx->r23, 0X0);
    // 0x80800F4C: lbu         $t0, 0xAF($s6)
    ctx->r8 = MEM_BU(ctx->r22, 0XAF);
    // 0x80800F50: lbu         $t2, 0x1B($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1B);
    // 0x80800F54: srl         $t9, $t0, 7
    ctx->r25 = S32(U32(ctx->r8) >> 7);
    // 0x80800F58: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x80800F5C: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x80800F60: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800F64: jal         0x80103014
    // 0x80800F68: sb          $t4, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r12;
    func_80103014(rdram, ctx);
        goto after_28;
    // 0x80800F68: sb          $t4, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r12;
    after_28:
    // 0x80800F6C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800F70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800F74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800F78: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F7C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800F80: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800F84: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800F88: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F8C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80800F90: jr          $ra
    // 0x80800F94: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800F94: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80800040_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: jal         0x80100094
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800050: lbu         $t6, 0x14($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X14);
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800058: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4FFC) << 16);
    // 0x8080005C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800060: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800064: lwc1        $f0, 0x4FFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4FFC));
    // 0x80800068: jr          $ra
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80807B54_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807B54: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80807B58: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80807B5C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80807B60: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80807B64: jal         0x80100094
    // 0x80807B68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807B68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807B6C: lbu         $t6, 0xA4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA4);
    // 0x80807B70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80807B74: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80807B78: beq         $at, $zero, L_80807DAC
    if (ctx->r1 == 0) {
        // 0x80807B7C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80807DAC;
    }
    // 0x80807B7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80807B80: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C14) << 16);
    // 0x80807B84: addu        $at, $at, $t6
    gpr jr_addend_80807B8C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80807B88: lw          $t6, -0x63EC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C14));
    // 0x80807B8C: jr          $t6
    // 0x80807B90: nop

    switch (jr_addend_80807B8C >> 2) {
        case 0: goto L_80807B94; break;
        case 1: goto L_80807DAC; break;
        case 2: goto L_80807BD4; break;
        case 3: goto L_80807D2C; break;
        case 4: goto L_80807D60; break;
        default: switch_error(__func__, 0x80807B8C, 0x80809C14);
    }
    // 0x80807B90: nop

L_80807B94:
    // 0x80807B94: lbu         $t7, 0xA5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XA5);
    // 0x80807B98: beql        $t7, $zero, L_80807DB0
    if (ctx->r15 == 0) {
        // 0x80807B9C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80807DB0;
    }
    goto skip_0;
    // 0x80807B9C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80807BA0: jal         0x80089C68
    // 0x80807BA4: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80807BA4: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    after_1:
    // 0x80807BA8: lbu         $t8, 0xA6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XA6);
    // 0x80807BAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80807BB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80807BB4: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80807BB8: beql        $at, $zero, L_80807DB0
    if (ctx->r1 == 0) {
        // 0x80807BBC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80807DB0;
    }
    goto skip_1;
    // 0x80807BBC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80807BC0: sb          $t9, 0xA4($s0)
    MEM_B(0XA4, ctx->r16) = ctx->r25;
    // 0x80807BC4: jal         0x80108B04
    // 0x80807BC8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x80807BC8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_2:
    // 0x80807BCC: b           L_80807DB0
    // 0x80807BD0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80807DB0;
    // 0x80807BD0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80807BD4:
    // 0x80807BD4: jal         0x800D9078
    // 0x80807BD8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x80807BD8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    after_3:
    // 0x80807BDC: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80807BE0: jal         0x80106790
    // 0x80807BE4: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80807BE4: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    after_4:
    // 0x80807BE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80807BEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80807BF0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80807BF4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80807BF8: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80807BFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80807C00: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80807C04: jal         0x800F10B4
    // 0x80807C08: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80807C08: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x80807C0C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80807C10: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80807C14: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80807C18: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80807C1C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80807C20: addiu       $a1, $s0, 0xB4
    ctx->r5 = ADD32(ctx->r16, 0XB4);
    // 0x80807C24: jal         0x800EFE50
    // 0x80807C28: addiu       $a2, $s0, 0xA8
    ctx->r6 = ADD32(ctx->r16, 0XA8);
    func_800EFE50(rdram, ctx);
        goto after_6;
    // 0x80807C28: addiu       $a2, $s0, 0xA8
    ctx->r6 = ADD32(ctx->r16, 0XA8);
    after_6:
    // 0x80807C2C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C28) << 16);
    // 0x80807C30: lwc1        $f6, -0x63D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C28));
    // 0x80807C34: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80807C38: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80807C3C: jal         0x8001395C
    // 0x80807C40: nop

    func_8001395C(rdram, ctx);
        goto after_7;
    // 0x80807C40: nop

    after_7:
    // 0x80807C44: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80807C48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80807C4C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80807C50: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80807C54: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80807C58: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80807C5C: jal         0x800F54E4
    // 0x80807C60: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80807C60: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    after_8:
    // 0x80807C64: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80807C68: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80807C6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80807C70: lwc1        $f0, 0x38($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X38);
    // 0x80807C74: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80807C78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80807C7C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80807C80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80807C84: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80807C88: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80807C8C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80807C90: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80807C94: jal         0x800F4F34
    // 0x80807C98: nop

    func_800F4F34(rdram, ctx);
        goto after_9;
    // 0x80807C98: nop

    after_9:
    // 0x80807C9C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80807CA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80807CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80807CA8: beq         $t1, $zero, L_80807DAC
    if (ctx->r9 == 0) {
        // 0x80807CAC: lui         $a2, 0x8081
        ctx->r6 = S32(RELOC_HI16(1480, 0XA150) << 16);
            goto L_80807DAC;
    }
    // 0x80807CAC: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA150) << 16);
    // 0x80807CB0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C2C) << 16);
    // 0x80807CB4: lwc1        $f16, -0x63D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C2C));
    // 0x80807CB8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80807CBC: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x80807CC0: addiu       $t3, $zero, 0x96
    ctx->r11 = ADD32(0, 0X96);
    // 0x80807CC4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80807CC8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80807CCC: addiu       $a2, $a2, -0x5EB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA150));
    // 0x80807CD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80807CD4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80807CD8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80807CDC: jal         0x800B4470
    // 0x80807CE0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B4470(rdram, ctx);
        goto after_10;
    // 0x80807CE0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x80807CE4: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80807CE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80807CEC: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x80807CF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80807CF4: addiu       $a0, $zero, 0x419
    ctx->r4 = ADD32(0, 0X419);
    // 0x80807CF8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80807CFC: addiu       $a2, $zero, 0x6D60
    ctx->r6 = ADD32(0, 0X6D60);
    // 0x80807D00: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80807D04: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80807D08: jal         0x800C4104
    // 0x80807D0C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C4104(rdram, ctx);
        goto after_11;
    // 0x80807D0C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80807D10: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80807D14: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80807D18: lbu         $t6, 0x65($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X65);
    // 0x80807D1C: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80807D20: sb          $t7, 0x65($t4)
    MEM_B(0X65, ctx->r12) = ctx->r15;
    // 0x80807D24: b           L_80807DAC
    // 0x80807D28: sb          $t8, 0xA4($s0)
    MEM_B(0XA4, ctx->r16) = ctx->r24;
        goto L_80807DAC;
    // 0x80807D28: sb          $t8, 0xA4($s0)
    MEM_B(0XA4, ctx->r16) = ctx->r24;
L_80807D2C:
    // 0x80807D2C: jal         0x80106790
    // 0x80807D30: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    func_80106790(rdram, ctx);
        goto after_12;
    // 0x80807D30: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    after_12:
    // 0x80807D34: jal         0x8008A118
    // 0x80807D38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sucoaster_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x80807D38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80807D3C: lbu         $t9, 0xA5($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XA5);
    // 0x80807D40: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80807D44: beql        $t9, $zero, L_80807D58
    if (ctx->r25 == 0) {
        // 0x80807D48: sb          $t0, 0xA4($s0)
        MEM_B(0XA4, ctx->r16) = ctx->r8;
            goto L_80807D58;
    }
    goto skip_2;
    // 0x80807D48: sb          $t0, 0xA4($s0)
    MEM_B(0XA4, ctx->r16) = ctx->r8;
    skip_2:
    // 0x80807D4C: b           L_80807D58
    // 0x80807D50: sb          $zero, 0xA4($s0)
    MEM_B(0XA4, ctx->r16) = 0;
        goto L_80807D58;
    // 0x80807D50: sb          $zero, 0xA4($s0)
    MEM_B(0XA4, ctx->r16) = 0;
    // 0x80807D54: sb          $t0, 0xA4($s0)
    MEM_B(0XA4, ctx->r16) = ctx->r8;
L_80807D58:
    // 0x80807D58: b           L_80807DAC
    // 0x80807D5C: sw          $zero, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = 0;
        goto L_80807DAC;
    // 0x80807D5C: sw          $zero, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = 0;
L_80807D60:
    // 0x80807D60: lbu         $v1, 0xA7($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XA7);
    // 0x80807D64: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x80807D68: beq         $v1, $zero, L_80807D78
    if (ctx->r3 == 0) {
        // 0x80807D6C: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80807D78;
    }
    // 0x80807D6C: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80807D70: b           L_80807DAC
    // 0x80807D74: sb          $t1, 0xA7($v0)
    MEM_B(0XA7, ctx->r2) = ctx->r9;
        goto L_80807DAC;
    // 0x80807D74: sb          $t1, 0xA7($v0)
    MEM_B(0XA7, ctx->r2) = ctx->r9;
L_80807D78:
    // 0x80807D78: jal         0x80089C30
    // 0x80807D7C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x80807D7C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_14:
    // 0x80807D80: beq         $v0, $zero, L_80807DA8
    if (ctx->r2 == 0) {
        // 0x80807D84: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80807DA8;
    }
    // 0x80807D84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80807D88:
    // 0x80807D88: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    // 0x80807D8C: jal         0x8010108C
    // 0x80807D90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_15;
    // 0x80807D90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80807D94: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x80807D98: jal         0x80089C38
    // 0x80807D9C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80807D9C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_16:
    // 0x80807DA0: bne         $v0, $zero, L_80807D88
    if (ctx->r2 != 0) {
        // 0x80807DA4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80807D88;
    }
    // 0x80807DA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80807DA8:
    // 0x80807DA8: sb          $zero, 0xA4($s0)
    MEM_B(0XA4, ctx->r16) = 0;
L_80807DAC:
    // 0x80807DAC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80807DB0:
    // 0x80807DB0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80807DB4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80807DB8: jr          $ra
    // 0x80807DBC: nop

    return;
    // 0x80807DBC: nop

;}
RECOMP_FUNC void func_80801108_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080110C: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80801110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801114: beq         $a1, $at, L_80801138
    if (ctx->r5 == ctx->r1) {
        // 0x80801118: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801138;
    }
    // 0x80801118: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080111C: addiu       $at, $zero, 0x1348
    ctx->r1 = ADD32(0, 0X1348);
    // 0x80801120: beq         $a1, $at, L_80801148
    if (ctx->r5 == ctx->r1) {
        // 0x80801124: addiu       $at, $zero, 0x1349
        ctx->r1 = ADD32(0, 0X1349);
            goto L_80801148;
    }
    // 0x80801124: addiu       $at, $zero, 0x1349
    ctx->r1 = ADD32(0, 0X1349);
    // 0x80801128: beq         $a1, $at, L_80801148
    if (ctx->r5 == ctx->r1) {
        // 0x8080112C: nop
    
            goto L_80801148;
    }
    // 0x8080112C: nop

    // 0x80801130: b           L_80801168
    // 0x80801134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801168;
    // 0x80801134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801138:
    // 0x80801138: jal         0x808006C0
    // 0x8080113C: nop

    func_808006C0_chfactorytwinklies(rdram, ctx);
        goto after_0;
    // 0x8080113C: nop

    after_0:
    // 0x80801140: b           L_80801168
    // 0x80801144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801168;
    // 0x80801144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801148:
    // 0x80801148: jal         0x8008A098
    // 0x8080114C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiemulti_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080114C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80801150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801154: jal         0x80101FDC
    // 0x80801158: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80801158: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x8080115C: jal         0x80088180
    // 0x80801160: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80801160: nop

    after_3:
    // 0x80801164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801168:
    // 0x80801168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080116C: jr          $ra
    // 0x80801170: nop

    return;
    // 0x80801170: nop

;}
RECOMP_FUNC void func_80106790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106798: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8010679C: lhu         $a1, 0x1A($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X1A);
    // 0x801067A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801067A4: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    // 0x801067A8: srl         $t6, $a1, 5
    ctx->r14 = S32(U32(ctx->r5) >> 5);
    // 0x801067AC: jal         0x800B28CC
    // 0x801067B0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    vector_at(rdram, ctx);
        goto after_0;
    // 0x801067B0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x801067B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801067B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801067BC: jr          $ra
    // 0x801067C0: nop

    return;
    // 0x801067C0: nop

;}
RECOMP_FUNC void func_80800908_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800908: lui         $at, 0x7800
    ctx->r1 = S32(0X7800 << 16);
    // 0x8080090C: and         $t6, $a0, $at
    ctx->r14 = ctx->r4 & ctx->r1;
    // 0x80800910: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80800914: beq         $t6, $at, L_80800944
    if (ctx->r14 == ctx->r1) {
        // 0x80800918: lui         $at, 0x1000
        ctx->r1 = S32(0X1000 << 16);
            goto L_80800944;
    }
    // 0x80800918: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8080091C: beq         $t6, $at, L_8080094C
    if (ctx->r14 == ctx->r1) {
        // 0x80800920: lui         $at, 0x1800
        ctx->r1 = S32(0X1800 << 16);
            goto L_8080094C;
    }
    // 0x80800920: lui         $at, 0x1800
    ctx->r1 = S32(0X1800 << 16);
    // 0x80800924: beq         $t6, $at, L_80800954
    if (ctx->r14 == ctx->r1) {
        // 0x80800928: lui         $at, 0x2000
        ctx->r1 = S32(0X2000 << 16);
            goto L_80800954;
    }
    // 0x80800928: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x8080092C: beq         $t6, $at, L_8080095C
    if (ctx->r14 == ctx->r1) {
        // 0x80800930: lui         $at, 0x2800
        ctx->r1 = S32(0X2800 << 16);
            goto L_8080095C;
    }
    // 0x80800930: lui         $at, 0x2800
    ctx->r1 = S32(0X2800 << 16);
    // 0x80800934: bne         $t6, $at, L_80800964
    if (ctx->r14 != ctx->r1) {
        // 0x80800938: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800964;
    }
    // 0x80800938: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8080093C: jr          $ra
    // 0x80800940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800944:
    // 0x80800944: jr          $ra
    // 0x80800948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080094C:
    // 0x8080094C: jr          $ra
    // 0x80800950: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80800950: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800954:
    // 0x80800954: jr          $ra
    // 0x80800958: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80800958: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080095C:
    // 0x8080095C: jr          $ra
    // 0x80800960: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800960: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800964:
    // 0x80800964: jr          $ra
    // 0x80800968: nop

    return;
    // 0x80800968: nop

;}
RECOMP_FUNC void func_800E2530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2530: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2534: jr          $ra
    // 0x800E2538: swc1        $f12, -0x2B68($at)
    MEM_W(-0X2B68, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800E2538: swc1        $f12, -0x2B68($at)
    MEM_W(-0X2B68, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800590_gccubesearch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800590: addiu       $sp, $sp, -0x230
    ctx->r29 = ADD32(ctx->r29, -0X230);
    // 0x80800594: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800598: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8080059C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x808005A0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808005A4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808005A8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808005AC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808005B0: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x808005B4: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x808005B8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808005BC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808005C0: jal         0x800EFD24
    // 0x808005C4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x808005C4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x808005C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2670, 0XEA0) << 16);
    // 0x808005CC: lwc1        $f20, 0xEA0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2670, 0XEA0));
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808005D8: jal         0x808004E0
    // 0x808005DC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    gccubesearch_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808005DC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_1:
    // 0x808005E0: bne         $v0, $zero, L_808005F0
    if (ctx->r2 != 0) {
        // 0x808005E4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_808005F0;
    }
    // 0x808005E4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808005E8: b           L_80800654
    // 0x808005EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800654;
    // 0x808005EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005F0:
    // 0x808005F0: blez        $v0, L_80800630
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808005F4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80800630;
    }
    // 0x808005F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808005F8: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
L_808005FC:
    // 0x808005FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800600: jalr        $s5
    // 0x80800604: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r21)(rdram, ctx);
        goto after_2;
    // 0x80800604: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800608: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8080060C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800610: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800614: bc1fl       L_80800628
    if (!c1cs) {
        // 0x80800618: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800628;
    }
    goto skip_0;
    // 0x80800618: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8080061C: jal         0x800EE7F8
    // 0x80800620: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800620: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x80800624: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800628:
    // 0x80800628: bne         $s1, $s2, L_808005FC
    if (ctx->r17 != ctx->r18) {
        // 0x8080062C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808005FC;
    }
    // 0x8080062C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80800630:
    // 0x80800630: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2670, 0XEA4) << 16);
    // 0x80800634: lwc1        $f4, 0xEA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2670, 0XEA4));
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080063C: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80800640: nop

    // 0x80800644: bc1f        L_80800654
    if (!c1cs) {
        // 0x80800648: nop
    
            goto L_80800654;
    }
    // 0x80800648: nop

    // 0x8080064C: b           L_80800654
    // 0x80800650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800654;
    // 0x80800650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800654:
    // 0x80800654: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800658: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8080065C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800660: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800664: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800668: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8080066C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800670: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800674: jr          $ra
    // 0x80800678: addiu       $sp, $sp, 0x230
    ctx->r29 = ADD32(ctx->r29, 0X230);
    return;
    // 0x80800678: addiu       $sp, $sp, 0x230
    ctx->r29 = ADD32(ctx->r29, 0X230);
;}
RECOMP_FUNC void _mlwave_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FD0: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FD0);
    return;
    // 0x80088FD4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808003DC_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808003E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003E4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808003E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003F0: beq         $a1, $at, L_80800448
    if (ctx->r5 == ctx->r1) {
        // 0x808003F4: sw          $a2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r6;
            goto L_80800448;
    }
    // 0x808003F4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x808003F8: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808003FC: beq         $a1, $at, L_808004DC
    if (ctx->r5 == ctx->r1) {
        // 0x80800400: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_808004DC;
    }
    // 0x80800400: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800404: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800408: beq         $a1, $at, L_80800434
    if (ctx->r5 == ctx->r1) {
        // 0x8080040C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800434;
    }
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800414: beq         $a1, $at, L_80800538
    if (ctx->r5 == ctx->r1) {
        // 0x80800418: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800538;
    }
    // 0x80800418: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x8080041C: beq         $a1, $at, L_808005C0
    if (ctx->r5 == ctx->r1) {
        // 0x80800420: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808005C0;
    }
    // 0x80800420: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800424: beq         $a1, $at, L_808005B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800428: nop
    
            goto L_808005B0;
    }
    // 0x80800428: nop

    // 0x8080042C: b           L_80800604
    // 0x80800430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800604;
    // 0x80800430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800434:
    // 0x80800434: lh          $a1, 0x58($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X58);
    // 0x80800438: jal         0x808007F0
    // 0x8080043C: lh          $a2, 0x5A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X5A);
    func_808007F0_chpoolkids(rdram, ctx);
        goto after_0;
    // 0x8080043C: lh          $a2, 0x5A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X5A);
    after_0:
    // 0x80800440: b           L_80800604
    // 0x80800444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800604;
    // 0x80800444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800448:
    // 0x80800448: jal         0x800DA298
    // 0x8080044C: addiu       $a0, $zero, 0x166
    ctx->r4 = ADD32(0, 0X166);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080044C: addiu       $a0, $zero, 0x166
    ctx->r4 = ADD32(0, 0X166);
    after_1:
    // 0x80800450: addiu       $a0, $zero, 0x167
    ctx->r4 = ADD32(0, 0X167);
    // 0x80800454: jal         0x800DA298
    // 0x80800458: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800458: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080045C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80800460: beq         $v1, $zero, L_80800490
    if (ctx->r3 == 0) {
        // 0x80800464: nop
    
            goto L_80800490;
    }
    // 0x80800464: nop

    // 0x80800468: beq         $v0, $zero, L_80800490
    if (ctx->r2 == 0) {
        // 0x8080046C: addiu       $a1, $zero, 0x1022
        ctx->r5 = ADD32(0, 0X1022);
            goto L_80800490;
    }
    // 0x8080046C: addiu       $a1, $zero, 0x1022
    ctx->r5 = ADD32(0, 0X1022);
    // 0x80800470: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800474: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x80800478: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080047C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800480: jal         0x8008A208
    // 0x80800484: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800484: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800488: b           L_80800604
    // 0x8080048C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800604;
    // 0x8080048C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800490:
    // 0x80800490: beq         $v1, $zero, L_808004BC
    if (ctx->r3 == 0) {
        // 0x80800494: addiu       $a1, $zero, 0x1020
        ctx->r5 = ADD32(0, 0X1020);
            goto L_808004BC;
    }
    // 0x80800494: addiu       $a1, $zero, 0x1020
    ctx->r5 = ADD32(0, 0X1020);
    // 0x80800498: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080049C: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x808004A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808004A4: addiu       $a1, $zero, 0x1021
    ctx->r5 = ADD32(0, 0X1021);
    // 0x808004A8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808004AC: jal         0x8008A208
    // 0x808004B0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808004B0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808004B4: b           L_80800604
    // 0x808004B8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800604;
    // 0x808004B8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808004BC:
    // 0x808004BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004C0: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x808004C4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808004C8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808004CC: jal         0x8008A208
    // 0x808004D0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808004D0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808004D4: b           L_80800604
    // 0x808004D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800604;
    // 0x808004D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808004DC:
    // 0x808004DC: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808004E0: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x808004E4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808004E8: jal         0x800B2768
    // 0x808004EC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800B2768(rdram, ctx);
        goto after_6;
    // 0x808004EC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x808004F0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: jal         0x80103CB8
    // 0x808004FC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80103CB8(rdram, ctx);
        goto after_7;
    // 0x808004FC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x80800500: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800504: jal         0x800B2840
    // 0x80800508: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800B2840(rdram, ctx);
        goto after_8;
    // 0x80800508: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_8:
    // 0x8080050C: addiu       $t9, $sp, 0x40
    ctx->r25 = ADD32(ctx->r29, 0X40);
    // 0x80800510: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800514: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800518: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080051C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800520: jal         0x80087990
    // 0x80800524: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _dbmorph_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800524: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x80800528: jal         0x801015D0
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_10;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800530: b           L_80800604
    // 0x80800534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800604;
    // 0x80800534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800538:
    // 0x80800538: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x8080053C: addiu       $at, $zero, 0x3A3
    ctx->r1 = ADD32(0, 0X3A3);
    // 0x80800540: sll         $t1, $t0, 11
    ctx->r9 = S32(ctx->r8 << 11);
    // 0x80800544: srl         $t2, $t1, 20
    ctx->r10 = S32(U32(ctx->r9) >> 20);
    // 0x80800548: beq         $t2, $at, L_80800558
    if (ctx->r10 == ctx->r1) {
        // 0x8080054C: nop
    
            goto L_80800558;
    }
    // 0x8080054C: nop

    // 0x80800550: b           L_80800604
    // 0x80800554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800604;
    // 0x80800554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800558:
    // 0x80800558: jal         0x80088840
    // 0x8080055C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_11;
    // 0x8080055C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_11:
    // 0x80800560: beq         $v0, $zero, L_80800580
    if (ctx->r2 == 0) {
        // 0x80800564: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800580;
    }
    // 0x80800564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800568: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080056C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80800570: jal         0x80085708
    // 0x80800574: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    _capod_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x80800574: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    after_12:
    // 0x80800578: b           L_80800604
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800604;
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800580:
    // 0x80800580: jal         0x80088840
    // 0x80800584: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_13;
    // 0x80800584: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_13:
    // 0x80800588: beq         $v0, $zero, L_808005A8
    if (ctx->r2 == 0) {
        // 0x8080058C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808005A8;
    }
    // 0x8080058C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800590: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800594: addiu       $a2, $zero, 0x2A
    ctx->r6 = ADD32(0, 0X2A);
    // 0x80800598: jal         0x80085708
    // 0x8080059C: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    _capod_entrypoint_13(rdram, ctx);
        goto after_14;
    // 0x8080059C: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    after_14:
    // 0x808005A0: b           L_80800604
    // 0x808005A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800604;
    // 0x808005A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005A8:
    // 0x808005A8: b           L_80800604
    // 0x808005AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800604;
    // 0x808005AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005B0:
    // 0x808005B0: jal         0x808006F8
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006F8_chpoolkids(rdram, ctx);
        goto after_15;
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808005B8: b           L_80800604
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800604;
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005C0:
    // 0x808005C0: lw          $t3, 0x6C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X6C);
    // 0x808005C4: addiu       $at, $zero, 0x3A3
    ctx->r1 = ADD32(0, 0X3A3);
    // 0x808005C8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1092, 0X14F8) << 16);
    // 0x808005CC: sll         $t4, $t3, 11
    ctx->r12 = S32(ctx->r11 << 11);
    // 0x808005D0: srl         $t5, $t4, 20
    ctx->r13 = S32(U32(ctx->r12) >> 20);
    // 0x808005D4: bne         $t5, $at, L_808005E8
    if (ctx->r13 != ctx->r1) {
        // 0x808005D8: addiu       $a0, $a0, 0x14F8
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1092, 0X14F8));
            goto L_808005E8;
    }
    // 0x808005D8: addiu       $a0, $a0, 0x14F8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1092, 0X14F8));
    // 0x808005DC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1092, 0X14E8) << 16);
    // 0x808005E0: b           L_808005E8
    // 0x808005E4: addiu       $a0, $a0, 0x14E8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1092, 0X14E8));
        goto L_808005E8;
    // 0x808005E4: addiu       $a0, $a0, 0x14E8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1092, 0X14E8));
L_808005E8:
    // 0x808005E8: jal         0x80088090
    // 0x808005EC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x808005EC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_16:
    // 0x808005F0: b           L_80800604
    // 0x808005F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800604;
    // 0x808005F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005F8: b           L_80800604
    // 0x808005FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800604;
    // 0x808005FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800604:
    // 0x80800604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800608: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080060C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800610: jr          $ra
    // 0x80800614: nop

    return;
    // 0x80800614: nop

;}
RECOMP_FUNC void func_80801760_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801760: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801764: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801768: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080176C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801770: jal         0x80100094
    // 0x80801774: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801774: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801778: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080177C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1584, 0X1A00) << 16);
    // 0x80801780: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801784: addiu       $a1, $a1, 0x1A00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1584, 0X1A00));
    // 0x80801788: jal         0x800EE7F8
    // 0x8080178C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080178C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80801790: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801794: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080179C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808017A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x808017A4: jal         0x800897C0
    // 0x808017A8: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808017A8: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x808017AC: jal         0x8010D278
    // 0x808017B0: nop

    func_8010D278(rdram, ctx);
        goto after_3;
    // 0x808017B0: nop

    after_3:
    // 0x808017B4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808017B8: bne         $v0, $at, L_808017E0
    if (ctx->r2 != ctx->r1) {
        // 0x808017BC: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_808017E0;
    }
    // 0x808017BC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x808017C0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808017C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808017C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017CC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x808017D0: jal         0x80800264
    // 0x808017D4: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_4;
    // 0x808017D4: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    after_4:
    // 0x808017D8: b           L_80801858
    // 0x808017DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_80801858;
    // 0x808017DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_808017E0:
    // 0x808017E0: jal         0x8080011C
    // 0x808017E4: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    func_8080011C_chnewmumbo(rdram, ctx);
        goto after_5;
    // 0x808017E4: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    after_5:
    // 0x808017E8: jal         0x800DA298
    // 0x808017EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808017EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808017F0: bne         $v0, $zero, L_80801804
    if (ctx->r2 != 0) {
        // 0x808017F4: nop
    
            goto L_80801804;
    }
    // 0x808017F4: nop

    // 0x808017F8: jal         0x80088848
    // 0x808017FC: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_7;
    // 0x808017FC: nop

    after_7:
    // 0x80801800: beq         $v0, $zero, L_80801828
    if (ctx->r2 == 0) {
        // 0x80801804: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1584, 0X19F4) << 16);
            goto L_80801828;
    }
L_80801804:
    // 0x80801804: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1584, 0X19F4) << 16);
    // 0x80801808: addiu       $a1, $a1, 0x19F4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1584, 0X19F4));
    // 0x8080180C: jal         0x800EE7F8
    // 0x80801810: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80801810: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80801814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801818: jal         0x80800264
    // 0x8080181C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_9;
    // 0x8080181C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_9:
    // 0x80801820: b           L_80801858
    // 0x80801824: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_80801858;
    // 0x80801824: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80801828:
    // 0x80801828: jal         0x800DA298
    // 0x8080182C: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x8080182C: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    after_10:
    // 0x80801830: beq         $v0, $zero, L_8080184C
    if (ctx->r2 == 0) {
        // 0x80801834: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080184C;
    }
    // 0x80801834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080183C: jal         0x80800264
    // 0x80801840: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_11;
    // 0x80801840: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_11:
    // 0x80801844: b           L_80801858
    // 0x80801848: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_80801858;
    // 0x80801848: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8080184C:
    // 0x8080184C: jal         0x80800264
    // 0x80801850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_12;
    // 0x80801850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80801854: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80801858:
    // 0x80801858: nop

    // 0x8080185C: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x80801860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801864: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801868: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080186C: jr          $ra
    // 0x80801870: nop

    return;
    // 0x80801870: nop

;}
RECOMP_FUNC void func_8080010C_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800110: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800114: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800118: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080011C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800120: jal         0x800B53A4
    // 0x80800124: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800124: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80800128: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080012C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800130: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800134: jal         0x8080000C
    // 0x80800138: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_8080000C_chbadjinjo(rdram, ctx);
        goto after_1;
    // 0x80800138: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8080013C: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80800140: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800144: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800148: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080014C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800150: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800154: addiu       $t9, $zero, -0x5
    ctx->r25 = ADD32(0, -0X5);
    // 0x80800158: addiu       $t2, $zero, 0x1C2
    ctx->r10 = ADD32(0, 0X1C2);
    // 0x8080015C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80800160: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80800164: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800168: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080016C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800170: addiu       $a1, $zero, -0xF
    ctx->r5 = ADD32(0, -0XF);
    // 0x80800174: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800178: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080017C: addiu       $a3, $zero, 0x15E
    ctx->r7 = ADD32(0, 0X15E);
    // 0x80800180: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80800184: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80800188: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8080018C: jal         0x800BA994
    // 0x80800190: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_800BA994(rdram, ctx);
        goto after_2;
    // 0x80800190: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_2:
    // 0x80800194: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800198: jal         0x800BA22C
    // 0x8080019C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x8080019C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x808001A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B0: jal         0x8080038C
    // 0x808004B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    gsmaker_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x808004B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x808004B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004C0: jr          $ra
    // 0x808004C4: nop

    return;
    // 0x808004C4: nop

;}
RECOMP_FUNC void func_80110D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110D10: jal         0x80115864
    // 0x80110D14: nop

    func_80115864(rdram, ctx);
        goto after_0;
    // 0x80110D14: nop

    after_0:
    // 0x80110D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110D1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110D20: jr          $ra
    // 0x80110D24: nop

    return;
    // 0x80110D24: nop

;}
RECOMP_FUNC void func_80800A48_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A54: jal         0x80100094
    // 0x80800A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A5C: jal         0x800EA05C
    // 0x80800A60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800A60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800A64: addiu       $at, $zero, 0x157
    ctx->r1 = ADD32(0, 0X157);
    // 0x80800A68: bne         $v0, $at, L_80800A80
    if (ctx->r2 != ctx->r1) {
        // 0x80800A6C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800A80;
    }
    // 0x80800A6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A70: lbu         $t7, 0x74($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X74);
    // 0x80800A74: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80800A78: b           L_80800A8C
    // 0x80800A7C: sb          $t8, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r24;
        goto L_80800A8C;
    // 0x80800A7C: sb          $t8, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r24;
L_80800A80:
    // 0x80800A80: lbu         $t9, 0x74($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X74);
    // 0x80800A84: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x80800A88: sb          $t0, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r8;
L_80800A8C:
    // 0x80800A8C: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x80800A90: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800A94: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80800A98: bgezl       $t3, L_80800AB4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800A9C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800AB4;
    }
    goto skip_0;
    // 0x80800A9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x80800AA0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800AA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800AA8: b           L_80800ABC
    // 0x80800AAC: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
        goto L_80800ABC;
    // 0x80800AAC: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80800AB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800AB4:
    // 0x80800AB4: nop

    // 0x80800AB8: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
L_80800ABC:
    // 0x80800ABC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800AC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800AC4: jal         0x800C8A98
    // 0x80800AC8: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80800AC8: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    after_2:
    // 0x80800ACC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AD0: lui         $a2, 0x443B
    ctx->r6 = S32(0X443B << 16);
    // 0x80800AD4: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80800AD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800ADC: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800AE0: jal         0x800C8E54
    // 0x80800AE4: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    func_800C8E54(rdram, ctx);
        goto after_3;
    // 0x80800AE4: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    after_3:
    // 0x80800AE8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AEC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800AF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800AF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800AF8: sb          $t6, 0x16($t5)
    MEM_B(0X16, ctx->r13) = ctx->r14;
    // 0x80800AFC: swc1        $f10, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f10.u32l;
    // 0x80800B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B08: jr          $ra
    // 0x80800B0C: nop

    return;
    // 0x80800B0C: nop

;}
RECOMP_FUNC void chexploder_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080173C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801740: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801744: jal         0x80100094
    // 0x80801748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080174C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80801750: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801754: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80801758: nop

    // 0x8080175C: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x80801760: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801764: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801768: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8080176C: nop

    // 0x80801770: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80801774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080177C: jr          $ra
    // 0x80801780: nop

    return;
    // 0x80801780: nop

;}
RECOMP_FUNC void func_800B7BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7BA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7BA8: jr          $ra
    // 0x800B7BAC: swc1        $f12, -0x7E68($at)
    MEM_W(-0X7E68, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800B7BAC: swc1        $f12, -0x7E68($at)
    MEM_W(-0X7E68, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bsbansnooze_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082740: syscall     9
    recomp_syscall_handler(rdram, ctx, 0x80082740);
    return;
    // 0x80082744: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chswitch_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800760: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800764: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800768: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8080076C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800770: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80800774: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800778: beq         $a1, $at, L_808007A4
    if (ctx->r5 == ctx->r1) {
        // 0x8080077C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_808007A4;
    }
    // 0x8080077C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800780: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800784: beq         $a1, $at, L_808007B4
    if (ctx->r5 == ctx->r1) {
        // 0x80800788: addiu       $at, $zero, 0x91
        ctx->r1 = ADD32(0, 0X91);
            goto L_808007B4;
    }
    // 0x80800788: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8080078C: beq         $a1, $at, L_8080080C
    if (ctx->r5 == ctx->r1) {
        // 0x80800790: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_8080080C;
    }
    // 0x80800790: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800794: beq         $a1, $at, L_8080090C
    if (ctx->r5 == ctx->r1) {
        // 0x80800798: nop
    
            goto L_8080090C;
    }
    // 0x80800798: nop

    // 0x8080079C: b           L_80800924
    // 0x808007A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800924;
    // 0x808007A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007A4:
    // 0x808007A4: jal         0x8080093C
    // 0x808007A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8080093C_chswitch(rdram, ctx);
        goto after_0;
    // 0x808007A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x808007AC: b           L_80800928
    // 0x808007B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800928;
    // 0x808007B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007B4:
    // 0x808007B4: jal         0x800F5410
    // 0x808007B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x808007B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x808007BC: sw          $v0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r2;
    // 0x808007C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(696, 0XDA4) << 16);
    // 0x808007C4: lwc1        $f4, 0xDA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(696, 0XDA4));
    // 0x808007C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007CC: jal         0x800880D0
    // 0x808007D0: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808007D0: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    after_2:
    // 0x808007D4: lui         $at, 0x3EC0
    ctx->r1 = S32(0X3EC0 << 16);
    // 0x808007D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808007E4: jal         0x80102424
    // 0x808007E8: swc1        $f6, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f6.u32l;
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808007E8: swc1        $f6, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f6.u32l;
    after_3:
    // 0x808007EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007F0: jal         0x80103110
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808007F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808007FC: jal         0x800F7F98
    // 0x80800800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_5;
    // 0x80800800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800804: b           L_80800924
    // 0x80800808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800924;
    // 0x80800808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080080C:
    // 0x8080080C: jal         0x800F55FC
    // 0x80800810: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800F55FC(rdram, ctx);
        goto after_6;
    // 0x80800810: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80800814: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80800818: and         $s0, $v0, $at
    ctx->r16 = ctx->r2 & ctx->r1;
    // 0x8080081C: jal         0x800DA298
    // 0x80800820: addiu       $a0, $zero, 0x9D4
    ctx->r4 = ADD32(0, 0X9D4);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800820: addiu       $a0, $zero, 0x9D4
    ctx->r4 = ADD32(0, 0X9D4);
    after_7:
    // 0x80800824: lhu         $t8, 0x6E($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X6E);
    // 0x80800828: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x8080082C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800830: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800834: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800838: jal         0x800F5410
    // 0x8080083C: sh          $t0, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r8;
    func_800F5410(rdram, ctx);
        goto after_8;
    // 0x8080083C: sh          $t0, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r8;
    after_8:
    // 0x80800840: bne         $s0, $zero, L_80800904
    if (ctx->r16 != 0) {
        // 0x80800844: sw          $v0, 0x50($s1)
        MEM_W(0X50, ctx->r17) = ctx->r2;
            goto L_80800904;
    }
    // 0x80800844: sw          $v0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r2;
    // 0x80800848: lhu         $t1, 0x72($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X72);
    // 0x8080084C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800850: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800854: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80800858: bne         $t2, $at, L_80800904
    if (ctx->r10 != ctx->r1) {
        // 0x8080085C: nop
    
            goto L_80800904;
    }
    // 0x8080085C: nop

    // 0x80800860: jal         0x800F64A4
    // 0x80800864: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    func_800F64A4(rdram, ctx);
        goto after_9;
    // 0x80800864: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    after_9:
    // 0x80800868: beq         $v0, $zero, L_80800904
    if (ctx->r2 == 0) {
        // 0x8080086C: nop
    
            goto L_80800904;
    }
    // 0x8080086C: nop

    // 0x80800870: jal         0x800DA298
    // 0x80800874: addiu       $a0, $zero, 0x9D4
    ctx->r4 = ADD32(0, 0X9D4);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800874: addiu       $a0, $zero, 0x9D4
    ctx->r4 = ADD32(0, 0X9D4);
    after_10:
    // 0x80800878: beq         $v0, $zero, L_80800904
    if (ctx->r2 == 0) {
        // 0x8080087C: nop
    
            goto L_80800904;
    }
    // 0x8080087C: nop

    // 0x80800880: jal         0x800F54E4
    // 0x80800884: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80800884: nop

    after_11:
    // 0x80800888: bne         $v0, $s2, L_80800904
    if (ctx->r2 != ctx->r18) {
        // 0x8080088C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800904;
    }
    // 0x8080088C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800890: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80800894:
    // 0x80800894: jal         0x800F6438
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_12;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080089C: beql        $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808008A0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808008DC;
    }
    goto skip_0;
    // 0x808008A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x808008A4: beql        $s0, $s2, L_808008DC
    if (ctx->r16 == ctx->r18) {
        // 0x808008A8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808008DC;
    }
    goto skip_1;
    // 0x808008A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x808008AC: jal         0x800F6C5C
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_13;
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808008B4: beql        $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808008B8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808008DC;
    }
    goto skip_2;
    // 0x808008B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x808008BC: jal         0x800F55D0
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F55D0(rdram, ctx);
        goto after_14;
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808008C4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x808008C8: bne         $v0, $t3, L_808008D8
    if (ctx->r2 != ctx->r11) {
        // 0x808008CC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_808008D8;
    }
    // 0x808008CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808008D0: b           L_808008E8
    // 0x808008D4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
        goto L_808008E8;
    // 0x808008D4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_808008D8:
    // 0x808008D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808008DC:
    // 0x808008DC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808008E0: bne         $s0, $at, L_80800894
    if (ctx->r16 != ctx->r1) {
        // 0x808008E4: nop
    
            goto L_80800894;
    }
    // 0x808008E4: nop

L_808008E8:
    // 0x808008E8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x808008EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808008F0: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    // 0x808008F4: bne         $t5, $zero, L_80800904
    if (ctx->r13 != 0) {
        // 0x808008F8: nop
    
            goto L_80800904;
    }
    // 0x808008F8: nop

    // 0x808008FC: jal         0x800F7874
    // 0x80800900: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_800F7874(rdram, ctx);
        goto after_15;
    // 0x80800900: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_15:
L_80800904:
    // 0x80800904: b           L_80800924
    // 0x80800908: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800924;
    // 0x80800908: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080090C:
    // 0x8080090C: jal         0x80800694
    // 0x80800910: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800694_chswitch(rdram, ctx);
        goto after_16;
    // 0x80800910: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800914: b           L_80800924
    // 0x80800918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800924;
    // 0x80800918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080091C: b           L_80800924
    // 0x80800920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800924;
    // 0x80800920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800924:
    // 0x80800924: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800928:
    // 0x80800928: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080092C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800930: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800934: jr          $ra
    // 0x80800938: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800938: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void chstoneballcontrol_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080369C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1608, 0X52CC) << 16);
    // 0x808036A0: jr          $ra
    // 0x808036A4: addiu       $v0, $v0, 0x52CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1608, 0X52CC));
    return;
    // 0x808036A4: addiu       $v0, $v0, 0x52CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1608, 0X52CC));
;}
RECOMP_FUNC void func_800CAA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAA24: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CAA28: addiu       $t0, $a0, 0x24
    ctx->r8 = ADD32(ctx->r4, 0X24);
    // 0x800CAA2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800CAA30: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800CAA34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CAA38:
    // 0x800CAA38: lwc1        $f2, 0x24($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X24);
    // 0x800CAA3C: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800CAA40: lwc1        $f14, 0x2C($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x800CAA44: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x800CAA48: nop

    // 0x800CAA4C: bc1fl       L_800CAA60
    if (!c1cs) {
        // 0x800CAA50: lwc1        $f16, 0x0($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
            goto L_800CAA60;
    }
    goto skip_0;
    // 0x800CAA50: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x800CAA54: b           L_800CAA60
    // 0x800CAA58: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
        goto L_800CAA60;
    // 0x800CAA58: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800CAA5C: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
L_800CAA60:
    // 0x800CAA60: lwc1        $f12, 0x28($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X28);
    // 0x800CAA64: mul.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800CAA68: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x800CAA6C: nop

    // 0x800CAA70: bc1fl       L_800CAA84
    if (!c1cs) {
        // 0x800CAA74: lwc1        $f16, 0x4($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
            goto L_800CAA84;
    }
    goto skip_1;
    // 0x800CAA74: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    skip_1:
    // 0x800CAA78: b           L_800CAA84
    // 0x800CAA7C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
        goto L_800CAA84;
    // 0x800CAA7C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800CAA80: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
L_800CAA84:
    // 0x800CAA84: c.le.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl <= ctx->f14.fl;
    // 0x800CAA88: mul.s       $f2, $f12, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800CAA8C: bc1fl       L_800CAAA0
    if (!c1cs) {
        // 0x800CAA90: lwc1        $f16, 0x8($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
            goto L_800CAAA0;
    }
    goto skip_2;
    // 0x800CAA90: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    skip_2:
    // 0x800CAA94: b           L_800CAAA0
    // 0x800CAA98: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
        goto L_800CAAA0;
    // 0x800CAA98: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800CAA9C: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
L_800CAAA0:
    // 0x800CAAA0: mul.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800CAAA4: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CAAA8: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800CAAAC: addiu       $t0, $t0, 0x20
    ctx->r8 = ADD32(ctx->r8, 0X20);
    // 0x800CAAB0: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800CAAB4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800CAAB8: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x800CAABC: nop

    // 0x800CAAC0: bc1fl       L_800CAAD4
    if (!c1cs) {
        // 0x800CAAC4: lwc1        $f0, 0x34($a3)
        ctx->f0.u32l = MEM_W(ctx->r7, 0X34);
            goto L_800CAAD4;
    }
    goto skip_3;
    // 0x800CAAC4: lwc1        $f0, 0x34($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X34);
    skip_3:
    // 0x800CAAC8: jr          $ra
    // 0x800CAACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CAACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CAAD0: lwc1        $f0, 0x34($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X34);
L_800CAAD4:
    // 0x800CAAD4: lwc1        $f2, 0x38($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X38);
    // 0x800CAAD8: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x800CAADC: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x800CAAE0: addiu       $v0, $a3, 0x34
    ctx->r2 = ADD32(ctx->r7, 0X34);
    // 0x800CAAE4: bc1fl       L_800CAAF8
    if (!c1cs) {
        // 0x800CAAE8: lwc1        $f16, 0x0($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
            goto L_800CAAF8;
    }
    goto skip_4;
    // 0x800CAAE8: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    skip_4:
    // 0x800CAAEC: b           L_800CAAF8
    // 0x800CAAF0: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
        goto L_800CAAF8;
    // 0x800CAAF0: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800CAAF4: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
L_800CAAF8:
    // 0x800CAAF8: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x800CAAFC: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800CAB00: bc1fl       L_800CAB14
    if (!c1cs) {
        // 0x800CAB04: lwc1        $f16, 0x4($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
            goto L_800CAB14;
    }
    goto skip_5;
    // 0x800CAB04: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    skip_5:
    // 0x800CAB08: b           L_800CAB14
    // 0x800CAB0C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
        goto L_800CAB14;
    // 0x800CAB0C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800CAB10: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
L_800CAB14:
    // 0x800CAB14: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x800CAB18: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800CAB1C: bc1fl       L_800CAB30
    if (!c1cs) {
        // 0x800CAB20: lwc1        $f16, 0x8($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
            goto L_800CAB30;
    }
    goto skip_6;
    // 0x800CAB20: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    skip_6:
    // 0x800CAB24: b           L_800CAB30
    // 0x800CAB28: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
        goto L_800CAB30;
    // 0x800CAB28: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800CAB2C: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
L_800CAB30:
    // 0x800CAB30: mul.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800CAB34: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CAB38: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CAB3C: add.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800CAB40: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CAB44: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x800CAB48: nop

    // 0x800CAB4C: bc1f        L_800CAB5C
    if (!c1cs) {
        // 0x800CAB50: nop
    
            goto L_800CAB5C;
    }
    // 0x800CAB50: nop

    // 0x800CAB54: jr          $ra
    // 0x800CAB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CAB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CAB5C:
    // 0x800CAB5C: bne         $v1, $a0, L_800CAA38
    if (ctx->r3 != ctx->r4) {
        // 0x800CAB60: addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
            goto L_800CAA38;
    }
    // 0x800CAB60: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800CAB64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CAB68: jr          $ra
    // 0x800CAB6C: nop

    return;
    // 0x800CAB6C: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808022F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808022F4: jal         0x808004B4
    // 0x808022F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x808022F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808022FC: jal         0x80800538
    // 0x80802300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800538_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80802304: jal         0x80082FE0
    // 0x80802308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80802308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080230C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802314: jr          $ra
    // 0x80802318: nop

    return;
    // 0x80802318: nop

;}
RECOMP_FUNC void func_80800110_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800114: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800118: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080011C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800120: beq         $a0, $zero, L_8080017C
    if (ctx->r4 == 0) {
        // 0x80800124: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8080017C;
    }
    // 0x80800124: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800128: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080012C: beq         $a0, $at, L_8080017C
    if (ctx->r4 == ctx->r1) {
        // 0x80800130: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080017C;
    }
    // 0x80800130: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800134: beq         $a0, $at, L_80800144
    if (ctx->r4 == ctx->r1) {
        // 0x80800138: nop
    
            goto L_80800144;
    }
    // 0x80800138: nop

    // 0x8080013C: b           L_808001B0
    // 0x80800140: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
        goto L_808001B0;
    // 0x80800140: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
L_80800144:
    // 0x80800144: jal         0x800EA05C
    // 0x80800148: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800148: nop

    after_0:
    // 0x8080014C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800150: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800154: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_80800158:
    // 0x80800158: jal         0x8080000C
    // 0x8080015C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8080000C_chchuffy(rdram, ctx);
        goto after_1;
    // 0x8080015C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800160: beql        $v0, $s0, L_808001B4
    if (ctx->r2 == ctx->r16) {
        // 0x80800164: sltiu       $at, $s1, 0x7
        ctx->r1 = ctx->r17 < 0X7 ? 1 : 0;
            goto L_808001B4;
    }
    goto skip_0;
    // 0x80800164: sltiu       $at, $s1, 0x7
    ctx->r1 = ctx->r17 < 0X7 ? 1 : 0;
    skip_0:
    // 0x80800168: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080016C: bne         $s1, $s2, L_80800158
    if (ctx->r17 != ctx->r18) {
        // 0x80800170: nop
    
            goto L_80800158;
    }
    // 0x80800170: nop

    // 0x80800174: b           L_808001B4
    // 0x80800178: sltiu       $at, $s1, 0x7
    ctx->r1 = ctx->r17 < 0X7 ? 1 : 0;
        goto L_808001B4;
    // 0x80800178: sltiu       $at, $s1, 0x7
    ctx->r1 = ctx->r17 < 0X7 ? 1 : 0;
L_8080017C:
    // 0x8080017C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1700, 0X247C) << 16);
    // 0x80800180: addiu       $t7, $t7, 0x247C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1700, 0X247C));
    // 0x80800184: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80800188: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x8080018C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800190: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_80800194:
    // 0x80800194: jal         0x800DA298
    // 0x80800198: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800198: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_2:
    // 0x8080019C: bnel        $v0, $zero, L_808001B4
    if (ctx->r2 != 0) {
        // 0x808001A0: sltiu       $at, $s1, 0x7
        ctx->r1 = ctx->r17 < 0X7 ? 1 : 0;
            goto L_808001B4;
    }
    goto skip_1;
    // 0x808001A0: sltiu       $at, $s1, 0x7
    ctx->r1 = ctx->r17 < 0X7 ? 1 : 0;
    skip_1:
    // 0x808001A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808001A8: bne         $s1, $s2, L_80800194
    if (ctx->r17 != ctx->r18) {
        // 0x808001AC: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80800194;
    }
    // 0x808001AC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_808001B0:
    // 0x808001B0: sltiu       $at, $s1, 0x7
    ctx->r1 = ctx->r17 < 0X7 ? 1 : 0;
L_808001B4:
    // 0x808001B4: bne         $at, $zero, L_808001C4
    if (ctx->r1 != 0) {
        // 0x808001B8: lw          $s0, 0x18($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X18);
            goto L_808001C4;
    }
    // 0x808001B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001BC: b           L_808001C8
    // 0x808001C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_808001C8;
    // 0x808001C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_808001C4:
    // 0x808001C4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_808001C8:
    // 0x808001C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808001D4: jr          $ra
    // 0x808001D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808001D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808000B0_vpwibble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000BC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x808000C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808000C4: jal         0x80800000
    // 0x808000C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800000_vpwibble(rdram, ctx);
        goto after_0;
    // 0x808000C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x808000D4: lbu         $t7, 0xD($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XD);
    // 0x808000D8: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x808000DC: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x808000E0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808000E4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808000E8: mfhi        $a1
    ctx->r5 = hi;
    // 0x808000EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808000F4: swc1        $f6, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f6.u32l;
    // 0x808000F8: lbu         $t9, 0xD($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XD);
    // 0x808000FC: beql        $t9, $zero, L_80800114
    if (ctx->r25 == 0) {
        // 0x80800100: sb          $zero, 0x33($a2)
        MEM_B(0X33, ctx->r6) = 0;
            goto L_80800114;
    }
    goto skip_0;
    // 0x80800100: sb          $zero, 0x33($a2)
    MEM_B(0X33, ctx->r6) = 0;
    skip_0:
    // 0x80800104: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800108: b           L_80800114
    // 0x8080010C: sb          $v1, 0x33($a2)
    MEM_B(0X33, ctx->r6) = ctx->r3;
        goto L_80800114;
    // 0x8080010C: sb          $v1, 0x33($a2)
    MEM_B(0X33, ctx->r6) = ctx->r3;
    // 0x80800110: sb          $zero, 0x33($a2)
    MEM_B(0X33, ctx->r6) = 0;
L_80800114:
    // 0x80800114: lwc1        $f2, 0x10($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80800118: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8080011C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800120: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800124: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80800128: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080012C: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800130: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800134: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80800138: nop

    // 0x8080013C: sh          $t1, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r9;
    // 0x80800140: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800144: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80800148: nop

    // 0x8080014C: bc1fl       L_80800174
    if (!c1cs) {
        // 0x80800150: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80800174;
    }
    goto skip_1;
    // 0x80800150: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_1:
    // 0x80800154: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80800158: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8080015C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800160: sb          $t4, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r12;
    // 0x80800164: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80800168: b           L_808001B4
    // 0x8080016C: sh          $t3, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r11;
        goto L_808001B4;
    // 0x8080016C: sh          $t3, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r11;
    // 0x80800170: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80800174:
    // 0x80800174: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800178: bc1fl       L_80800198
    if (!c1cs) {
        // 0x8080017C: sub.s       $f10, $f2, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_80800198;
    }
    goto skip_2;
    // 0x8080017C: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    skip_2:
    // 0x80800180: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800184: sb          $zero, 0x31($a2)
    MEM_B(0X31, ctx->r6) = 0;
    // 0x80800188: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8080018C: b           L_808001B4
    // 0x80800190: sh          $t6, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r14;
        goto L_808001B4;
    // 0x80800190: sh          $t6, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r14;
    // 0x80800194: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
L_80800198:
    // 0x80800198: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080019C: sb          $v1, 0x31($a2)
    MEM_B(0X31, ctx->r6) = ctx->r3;
    // 0x808001A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808001A4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808001A8: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x808001AC: nop

    // 0x808001B0: sh          $t8, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r24;
L_808001B4:
    // 0x808001B4: lbu         $t9, 0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XC);
    // 0x808001B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808001BC: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x808001C0: bgez        $t9, L_808001D4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808001C4: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_808001D4;
    }
    // 0x808001C4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808001C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001CC: nop

    // 0x808001D0: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_808001D4:
    // 0x808001D4: lh          $t0, 0x1A($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X1A);
    // 0x808001D8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x808001DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2982, 0X6F0) << 16);
    // 0x808001E0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x808001E4: nop

    // 0x808001E8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808001EC: div.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x808001F0: swc1        $f4, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f4.u32l;
    // 0x808001F4: lbu         $t1, 0xC($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XC);
    // 0x808001F8: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x808001FC: sb          $t3, 0x30($a2)
    MEM_B(0X30, ctx->r6) = ctx->r11;
    // 0x80800200: lbu         $t4, 0xC($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XC);
    // 0x80800204: beql        $t4, $zero, L_80800218
    if (ctx->r12 == 0) {
        // 0x80800208: sb          $zero, 0x32($a2)
        MEM_B(0X32, ctx->r6) = 0;
            goto L_80800218;
    }
    goto skip_3;
    // 0x80800208: sb          $zero, 0x32($a2)
    MEM_B(0X32, ctx->r6) = 0;
    skip_3:
    // 0x8080020C: b           L_80800218
    // 0x80800210: sb          $v1, 0x32($a2)
    MEM_B(0X32, ctx->r6) = ctx->r3;
        goto L_80800218;
    // 0x80800210: sb          $v1, 0x32($a2)
    MEM_B(0X32, ctx->r6) = ctx->r3;
    // 0x80800214: sb          $zero, 0x32($a2)
    MEM_B(0X32, ctx->r6) = 0;
L_80800218:
    // 0x80800218: swc1        $f14, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f14.u32l;
    // 0x8080021C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800220: lwc1        $f6, 0x6F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2982, 0X6F0));
    // 0x80800224: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800228: swc1        $f16, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f16.u32l;
    // 0x8080022C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800230: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80800234: nop

    // 0x80800238: bc1fl       L_80800250
    if (!c1cs) {
        // 0x8080023C: mtc1        $a1, $f18
        ctx->f18.u32l = ctx->r5;
            goto L_80800250;
    }
    goto skip_4;
    // 0x8080023C: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    skip_4:
    // 0x80800240: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80800244: b           L_80800260
    // 0x80800248: swc1        $f8, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f8.u32l;
        goto L_80800260;
    // 0x80800248: swc1        $f8, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f8.u32l;
    // 0x8080024C: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
L_80800250:
    // 0x80800250: nop

    // 0x80800254: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800258: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8080025C: swc1        $f6, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f6.u32l;
L_80800260:
    // 0x80800260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800268: jr          $ra
    // 0x8080026C: nop

    return;
    // 0x8080026C: nop

;}
RECOMP_FUNC void gcdialogexec_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808016A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808016A8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808016AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808016B0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808016B4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808016B8: jal         0x800C0638
    // 0x808016BC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_800C0638(rdram, ctx);
        goto after_0;
    // 0x808016BC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808016C0: bne         $v0, $zero, L_80801798
    if (ctx->r2 != 0) {
        // 0x808016C4: lw          $v1, 0x48($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X48);
            goto L_80801798;
    }
    // 0x808016C4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x808016C8: jal         0x800F54E4
    // 0x808016CC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808016CC: nop

    after_1:
    // 0x808016D0: sw          $v0, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->r2;
    // 0x808016D4: lh          $t9, 0x62($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X62);
    // 0x808016D8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x808016DC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x808016E0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x808016E4: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x808016E8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x808016EC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808016F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016F4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x808016F8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808016FC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801700: jal         0x80801268
    // 0x80801704: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80801268_gcdialogexec(rdram, ctx);
        goto after_2;
    // 0x80801704: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x80801708: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8080170C: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x80801710: beq         $t1, $zero, L_80801788
    if (ctx->r9 == 0) {
        // 0x80801714: nop
    
            goto L_80801788;
    }
    // 0x80801714: nop

    // 0x80801718: jal         0x800A9C98
    // 0x8080171C: nop

    func_800A9C98(rdram, ctx);
        goto after_3;
    // 0x8080171C: nop

    after_3:
    // 0x80801720: beq         $v0, $zero, L_80801738
    if (ctx->r2 == 0) {
        // 0x80801724: lw          $a2, 0x4C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X4C);
            goto L_80801738;
    }
    // 0x80801724: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80801728: lw          $t2, 0x15C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X15C);
    // 0x8080172C: sll         $t4, $t2, 20
    ctx->r12 = S32(ctx->r10 << 20);
    // 0x80801730: bltz        $t4, L_80801788
    if (SIGNED(ctx->r12) < 0) {
        // 0x80801734: nop
    
            goto L_80801788;
    }
    // 0x80801734: nop

L_80801738:
    // 0x80801738: beql        $a2, $zero, L_8080176C
    if (ctx->r6 == 0) {
        // 0x8080173C: lh          $t6, 0x11A($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X11A);
            goto L_8080176C;
    }
    goto skip_0;
    // 0x8080173C: lh          $t6, 0x11A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X11A);
    skip_0:
    // 0x80801740: lh          $t5, 0x11A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X11A);
    // 0x80801744: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801748: bgez        $t5, L_80801758
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8080174C: nop
    
            goto L_80801758;
    }
    // 0x8080174C: nop

    // 0x80801750: b           L_80801758
    // 0x80801754: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80801758;
    // 0x80801754: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80801758:
    // 0x80801758: jal         0x800F8300
    // 0x8080175C: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    func_800F8300(rdram, ctx);
        goto after_4;
    // 0x8080175C: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    after_4:
    // 0x80801760: b           L_80801788
    // 0x80801764: nop

        goto L_80801788;
    // 0x80801764: nop

    // 0x80801768: lh          $t6, 0x11A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X11A);
L_8080176C:
    // 0x8080176C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801770: bgez        $t6, L_80801780
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80801774: nop
    
            goto L_80801780;
    }
    // 0x80801774: nop

    // 0x80801778: b           L_80801780
    // 0x8080177C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80801780;
    // 0x8080177C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80801780:
    // 0x80801780: jal         0x800F82D4
    // 0x80801784: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    func_800F82D4(rdram, ctx);
        goto after_5;
    // 0x80801784: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    after_5:
L_80801788:
    // 0x80801788: jal         0x800FEC60
    // 0x8080178C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FEC60(rdram, ctx);
        goto after_6;
    // 0x8080178C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80801790: b           L_80801984
    // 0x80801794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801984;
    // 0x80801794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801798:
    // 0x80801798: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8080179C: beql        $v0, $zero, L_808017E0
    if (ctx->r2 == 0) {
        // 0x808017A0: andi        $t3, $v1, 0x4
        ctx->r11 = ctx->r3 & 0X4;
            goto L_808017E0;
    }
    goto skip_1;
    // 0x808017A0: andi        $t3, $v1, 0x4
    ctx->r11 = ctx->r3 & 0X4;
    skip_1:
    // 0x808017A4: lhu         $t7, 0x15A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X15A);
    // 0x808017A8: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x808017AC: bnel        $t8, $zero, L_808017CC
    if (ctx->r24 != 0) {
        // 0x808017B0: lbu         $t9, 0x161($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X161);
            goto L_808017CC;
    }
    goto skip_2;
    // 0x808017B0: lbu         $t9, 0x161($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X161);
    skip_2:
    // 0x808017B4: jal         0x800C0658
    // 0x808017B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800C0658(rdram, ctx);
        goto after_7;
    // 0x808017B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_7:
    // 0x808017BC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x808017C0: b           L_808017DC
    // 0x808017C4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
        goto L_808017DC;
    // 0x808017C4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x808017C8: lbu         $t9, 0x161($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X161);
L_808017CC:
    // 0x808017CC: andi        $t1, $t9, 0xFF0F
    ctx->r9 = ctx->r25 & 0XFF0F;
    // 0x808017D0: sb          $t1, 0x161($s0)
    MEM_B(0X161, ctx->r16) = ctx->r9;
    // 0x808017D4: andi        $t2, $t1, 0xF0
    ctx->r10 = ctx->r9 & 0XF0;
    // 0x808017D8: sb          $t2, 0x161($s0)
    MEM_B(0X161, ctx->r16) = ctx->r10;
L_808017DC:
    // 0x808017DC: andi        $t3, $v1, 0x4
    ctx->r11 = ctx->r3 & 0X4;
L_808017E0:
    // 0x808017E0: bne         $t3, $zero, L_808017F0
    if (ctx->r11 != 0) {
        // 0x808017E4: lw          $a1, 0x4C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X4C);
            goto L_808017F0;
    }
    // 0x808017E4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x808017E8: beql        $v0, $zero, L_80801984
    if (ctx->r2 == 0) {
        // 0x808017EC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801984;
    }
    goto skip_3;
    // 0x808017EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
L_808017F0:
    // 0x808017F0: lhu         $t4, 0x160($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X160);
    // 0x808017F4: lbu         $t6, 0x161($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X161);
    // 0x808017F8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x808017FC: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x80801800: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80801804: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x80801808: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8080180C: bnel        $at, $zero, L_8080181C
    if (ctx->r1 != 0) {
        // 0x80801810: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8080181C;
    }
    goto skip_4;
    // 0x80801810: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    skip_4:
    // 0x80801814: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80801818: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
L_8080181C:
    // 0x8080181C: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80801820: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801824: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80801828: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080182C: addu        $a3, $s0, $t8
    ctx->r7 = ADD32(ctx->r16, ctx->r24);
    // 0x80801830: sh          $t9, 0x184($a3)
    MEM_H(0X184, ctx->r7) = ctx->r25;
    // 0x80801834: beq         $a1, $zero, L_80801850
    if (ctx->r5 == 0) {
        // 0x80801838: sh          $v1, 0x186($a3)
        MEM_H(0X186, ctx->r7) = ctx->r3;
            goto L_80801850;
    }
    // 0x80801838: sh          $v1, 0x186($a3)
    MEM_H(0X186, ctx->r7) = ctx->r3;
    // 0x8080183C: addiu       $a0, $a3, 0x188
    ctx->r4 = ADD32(ctx->r7, 0X188);
    // 0x80801840: jal         0x800EE7F8
    // 0x80801844: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80801844: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_8:
    // 0x80801848: b           L_80801860
    // 0x8080184C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
        goto L_80801860;
    // 0x8080184C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
L_80801850:
    // 0x80801850: addiu       $a0, $a3, 0x188
    ctx->r4 = ADD32(ctx->r7, 0X188);
    // 0x80801854: jal         0x800EFD24
    // 0x80801858: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800EFD24(rdram, ctx);
        goto after_9;
    // 0x80801858: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_9:
    // 0x8080185C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
L_80801860:
    // 0x80801860: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80801864: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80801868: sw          $v1, 0x194($a3)
    MEM_W(0X194, ctx->r7) = ctx->r3;
    // 0x8080186C: lh          $t0, 0x62($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X62);
    // 0x80801870: beq         $v1, $zero, L_8080189C
    if (ctx->r3 == 0) {
        // 0x80801874: sh          $t0, 0x198($a3)
        MEM_H(0X198, ctx->r7) = ctx->r8;
            goto L_8080189C;
    }
    // 0x80801874: sh          $t0, 0x198($a3)
    MEM_H(0X198, ctx->r7) = ctx->r8;
    // 0x80801878: lhu         $v0, 0x12($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X12);
    // 0x8080187C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80801880: srl         $t1, $v0, 1
    ctx->r9 = S32(U32(ctx->r2) >> 1);
    // 0x80801884: beq         $t1, $zero, L_80801894
    if (ctx->r9 == 0) {
        // 0x80801888: nop
    
            goto L_80801894;
    }
    // 0x80801888: nop

    // 0x8080188C: b           L_80801894
    // 0x80801890: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
        goto L_80801894;
    // 0x80801890: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80801894:
    // 0x80801894: b           L_808018A0
    // 0x80801898: sw          $a1, 0x19C($a3)
    MEM_W(0X19C, ctx->r7) = ctx->r5;
        goto L_808018A0;
    // 0x80801898: sw          $a1, 0x19C($a3)
    MEM_W(0X19C, ctx->r7) = ctx->r5;
L_8080189C:
    // 0x8080189C: sw          $t2, 0x19C($a3)
    MEM_W(0X19C, ctx->r7) = ctx->r10;
L_808018A0:
    // 0x808018A0: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x808018A4: sw          $t3, 0x1A0($a3)
    MEM_W(0X1A0, ctx->r7) = ctx->r11;
    // 0x808018A8: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x808018AC: sw          $t4, 0x1A4($a3)
    MEM_W(0X1A4, ctx->r7) = ctx->r12;
    // 0x808018B0: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x808018B4: sw          $t6, 0x1A8($a3)
    MEM_W(0X1A8, ctx->r7) = ctx->r14;
    // 0x808018B8: jal         0x800F54E4
    // 0x808018BC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x808018BC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_10:
    // 0x808018C0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808018C4: sw          $v0, 0x1AC($a3)
    MEM_W(0X1AC, ctx->r7) = ctx->r2;
    // 0x808018C8: lbu         $v1, 0x161($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X161);
    // 0x808018CC: srl         $t5, $v1, 4
    ctx->r13 = S32(U32(ctx->r3) >> 4);
    // 0x808018D0: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x808018D4: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x808018D8: andi        $t0, $v1, 0xFF0F
    ctx->r8 = ctx->r3 & 0XFF0F;
    // 0x808018DC: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x808018E0: sb          $t1, 0x161($s0)
    MEM_B(0X161, ctx->r16) = ctx->r9;
    // 0x808018E4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x808018E8: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x808018EC: beq         $t3, $zero, L_80801978
    if (ctx->r11 == 0) {
        // 0x808018F0: nop
    
            goto L_80801978;
    }
    // 0x808018F0: nop

    // 0x808018F4: jal         0x800A9C98
    // 0x808018F8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800A9C98(rdram, ctx);
        goto after_11;
    // 0x808018F8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_11:
    // 0x808018FC: beq         $v0, $zero, L_80801914
    if (ctx->r2 == 0) {
        // 0x80801900: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_80801914;
    }
    // 0x80801900: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80801904: lw          $t4, 0x15C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X15C);
    // 0x80801908: sll         $t5, $t4, 20
    ctx->r13 = S32(ctx->r12 << 20);
    // 0x8080190C: bltz        $t5, L_80801978
    if (SIGNED(ctx->r13) < 0) {
        // 0x80801910: nop
    
            goto L_80801978;
    }
    // 0x80801910: nop

L_80801914:
    // 0x80801914: lw          $a0, 0x1AC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1AC);
    // 0x80801918: jal         0x800F5B0C
    // 0x8080191C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800F5B0C(rdram, ctx);
        goto after_12;
    // 0x8080191C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_12:
    // 0x80801920: bne         $v0, $zero, L_8080195C
    if (ctx->r2 != 0) {
        // 0x80801924: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_8080195C;
    }
    // 0x80801924: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80801928: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8080192C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801930: beq         $t7, $zero, L_8080194C
    if (ctx->r15 == 0) {
        // 0x80801934: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_8080194C;
    }
    // 0x80801934: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80801938: lw          $a0, 0x1AC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1AC);
    // 0x8080193C: jal         0x800F8300
    // 0x80801940: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F8300(rdram, ctx);
        goto after_13;
    // 0x80801940: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80801944: b           L_80801984
    // 0x80801948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801984;
    // 0x80801948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080194C:
    // 0x8080194C: jal         0x800F82D4
    // 0x80801950: lw          $a0, 0x1AC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1AC);
    func_800F82D4(rdram, ctx);
        goto after_14;
    // 0x80801950: lw          $a0, 0x1AC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1AC);
    after_14:
    // 0x80801954: b           L_80801984
    // 0x80801958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801984;
    // 0x80801958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080195C:
    // 0x8080195C: lw          $a0, 0x1AC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1AC);
    // 0x80801960: jal         0x800F5B0C
    // 0x80801964: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800F5B0C(rdram, ctx);
        goto after_15;
    // 0x80801964: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_15:
    // 0x80801968: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8080196C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801970: jal         0x800F82D4
    // 0x80801974: lw          $a0, 0x1AC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1AC);
    func_800F82D4(rdram, ctx);
        goto after_16;
    // 0x80801974: lw          $a0, 0x1AC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1AC);
    after_16:
L_80801978:
    // 0x80801978: b           L_80801984
    // 0x8080197C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801984;
    // 0x8080197C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801984:
    // 0x80801984: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801988: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080198C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801990: jr          $ra
    // 0x80801994: nop

    return;
    // 0x80801994: nop

;}
RECOMP_FUNC void func_80800BDC_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800BE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BEC: jal         0x800878B0
    // 0x80800BF0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800BF0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800BF4: bne         $v0, $zero, L_80800C38
    if (ctx->r2 != 0) {
        // 0x80800BF8: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80800C38;
    }
    // 0x80800BF8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800BFC: jal         0x800D90A4
    // 0x80800C00: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x80800C00: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800C04: beql        $v0, $zero, L_80800C3C
    if (ctx->r2 == 0) {
        // 0x80800C08: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80800C3C;
    }
    goto skip_0;
    // 0x80800C08: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800C0C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800C10: lui         $a0, 0x731C
    ctx->r4 = S32(0X731C << 16);
    // 0x80800C14: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800C18: bltzl       $t8, L_80800C3C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800C1C: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80800C3C;
    }
    goto skip_1;
    // 0x80800C1C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800C20: jal         0x800C3F48
    // 0x80800C24: ori         $a0, $a0, 0x5699
    ctx->r4 = ctx->r4 | 0X5699;
    func_800C3F48(rdram, ctx);
        goto after_2;
    // 0x80800C24: ori         $a0, $a0, 0x5699
    ctx->r4 = ctx->r4 | 0X5699;
    after_2:
    // 0x80800C28: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800C2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C30: nop

    // 0x80800C34: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800C38:
    // 0x80800C38: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_80800C3C:
    // 0x80800C3C: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800C40: sltiu       $t1, $t9, 0x1
    ctx->r9 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80800C44: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80800C48: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80800C4C: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x80800C50: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800C54: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x80800C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C64: jr          $ra
    // 0x80800C68: nop

    return;
    // 0x80800C68: nop

;}
RECOMP_FUNC void func_8080035C_chdiggergroundgen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800360: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800364: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800368: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080036C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800370: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800374: jal         0x80100094
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080037C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800380: jal         0x8008A040
    // 0x80800384: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800384: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800388: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080038C: jal         0x800D9078
    // 0x80800390: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80800390: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    after_2:
    // 0x80800394: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800398: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8080039C: lwc1        $f12, 0x58($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X58);
    // 0x808003A0: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x808003A4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808003A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808003AC: jal         0x800F10B4
    // 0x808003B0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808003B0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x808003B4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x808003B8: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x808003BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808003C0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x808003C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003C8: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x808003CC: jal         0x800EFE50
    // 0x808003D0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    func_800EFE50(rdram, ctx);
        goto after_4;
    // 0x808003D0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    after_4:
    // 0x808003D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(860, 0X4EC) << 16);
    // 0x808003D8: lwc1        $f6, 0x4EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(860, 0X4EC));
    // 0x808003DC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808003E0: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808003E4: jal         0x8001395C
    // 0x808003E8: nop

    func_8001395C(rdram, ctx);
        goto after_5;
    // 0x808003E8: nop

    after_5:
    // 0x808003EC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808003F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003F4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808003F8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808003FC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800404: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x80800408: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8080040C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800410: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800414: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80800418: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8080041C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800420: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80800424: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800428: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8080042C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800430: jal         0x8008FB10
    // 0x80800434: nop

    func_8008FB10(rdram, ctx);
        goto after_6;
    // 0x80800434: nop

    after_6:
    // 0x80800438: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8080043C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800444: beq         $t6, $zero, L_808004C4
    if (ctx->r14 == 0) {
        // 0x80800448: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(860, 0X554) << 16);
            goto L_808004C4;
    }
    // 0x80800448: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(860, 0X554) << 16);
    // 0x8080044C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(860, 0X4F0) << 16);
    // 0x80800450: lwc1        $f4, 0x4F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(860, 0X4F0));
    // 0x80800454: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800458: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8080045C: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x80800460: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80800464: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800468: addiu       $a2, $a2, 0x554
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(860, 0X554));
    // 0x8080046C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800470: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80800474: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800478: jal         0x800B4470
    // 0x8080047C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B4470(rdram, ctx);
        goto after_7;
    // 0x8080047C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80800480: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(860, 0X4F4) << 16);
    // 0x80800484: lwc1        $f10, 0x4F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(860, 0X4F4));
    // 0x80800488: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(860, 0X4F8) << 16);
    // 0x8080048C: lwc1        $f8, 0x4F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(860, 0X4F8));
    // 0x80800490: addiu       $a0, $zero, 0x419
    ctx->r4 = ADD32(0, 0X419);
    // 0x80800494: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800498: addiu       $a2, $zero, 0x6D60
    ctx->r6 = ADD32(0, 0X6D60);
    // 0x8080049C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x808004A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x808004A4: jal         0x800C4104
    // 0x808004A8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800C4104(rdram, ctx);
        goto after_8;
    // 0x808004A8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x808004AC: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808004B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004B8: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x808004BC: jal         0x80101FDC
    // 0x808004C0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x808004C0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_9:
L_808004C4:
    // 0x808004C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808004C8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808004CC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808004D0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x808004D4: jr          $ra
    // 0x808004D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808004D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808004DC: nop

;}
RECOMP_FUNC void chchuffyglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1772, 0X5B0) << 16);
    // 0x8080050C: jr          $ra
    // 0x80800510: addiu       $v0, $v0, 0x5B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1772, 0X5B0));
    return;
    // 0x80800510: addiu       $v0, $v0, 0x5B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1772, 0X5B0));
    // 0x80800514: nop

    // 0x80800518: nop

    // 0x8080051C: nop

;}
RECOMP_FUNC void badata_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800918: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8080091C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800920: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800928: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X2138) << 16);
    // 0x8080092C: jal         0x808006AC
    // 0x80800930: addiu       $a1, $a1, 0x2138
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X2138));
    func_808006AC_badata(rdram, ctx);
        goto after_0;
    // 0x80800930: addiu       $a1, $a1, 0x2138
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X2138));
    after_0:
    // 0x80800934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080093C: jr          $ra
    // 0x80800940: nop

    return;
    // 0x80800940: nop

;}
RECOMP_FUNC void func_800C76E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C76E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C76EC: addiu       $a1, $a1, 0x760C
    ctx->r5 = ADD32(ctx->r5, 0X760C);
    // 0x800C76F0: lb          $v1, 0x1($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1);
    // 0x800C76F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C76F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C76FC: bnel        $v1, $zero, L_800C774C
    if (ctx->r3 != 0) {
        // 0x800C7700: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C774C;
    }
    goto skip_0;
    // 0x800C7700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C7704: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x800C7708: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C770C: beql        $a0, $zero, L_800C774C
    if (ctx->r4 == 0) {
        // 0x800C7710: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C774C;
    }
    goto skip_1;
    // 0x800C7710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800C7714: beql        $a0, $at, L_800C774C
    if (ctx->r4 == ctx->r1) {
        // 0x800C7718: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C774C;
    }
    goto skip_2;
    // 0x800C7718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800C771C: jal         0x800C75A0
    // 0x800C7720: nop

    func_800C75A0(rdram, ctx);
        goto after_0;
    // 0x800C7720: nop

    after_0:
    // 0x800C7724: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C7728: jal         0x800C7618
    // 0x800C772C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7618(rdram, ctx);
        goto after_1;
    // 0x800C772C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800C7730: jal         0x800FECB8
    // 0x800C7734: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800FECB8(rdram, ctx);
        goto after_2;
    // 0x800C7734: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x800C7738: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800C773C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C7740: addiu       $a1, $a1, 0x760C
    ctx->r5 = ADD32(ctx->r5, 0X760C);
    // 0x800C7744: lb          $v1, 0x760D($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X760D);
    // 0x800C7748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C774C:
    // 0x800C774C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800C7750: sb          $t6, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r14;
    // 0x800C7754: jr          $ra
    // 0x800C7758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8011413C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011413C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114144: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80114148: beq         $a3, $zero, L_80114160
    if (ctx->r7 == 0) {
        // 0x8011414C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80114160;
    }
    // 0x8011414C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80114150: jal         0x800CB0E8
    // 0x80114154: addiu       $a2, $a3, -0x1
    ctx->r6 = ADD32(ctx->r7, -0X1);
    func_800CB0E8(rdram, ctx);
        goto after_0;
    // 0x80114154: addiu       $a2, $a3, -0x1
    ctx->r6 = ADD32(ctx->r7, -0X1);
    after_0:
    // 0x80114158: b           L_8011416C
    // 0x8011415C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_8011416C;
    // 0x8011415C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80114160:
    // 0x80114160: jal         0x800CA740
    // 0x80114164: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800CA740(rdram, ctx);
        goto after_1;
    // 0x80114164: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80114168: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_8011416C:
    // 0x8011416C: jal         0x800EF334
    // 0x80114170: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EF334(rdram, ctx);
        goto after_2;
    // 0x80114170: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80114174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011417C: jr          $ra
    // 0x80114180: nop

    return;
    // 0x80114180: nop

;}
RECOMP_FUNC void _chjujubagfx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C88: syscall     439
    recomp_syscall_handler(rdram, ctx, 0x80086C88);
    return;
    // 0x80086C8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80802CD8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802CE0: lw          $t6, 0x158($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X158);
    // 0x80802CE4: bne         $t6, $zero, L_80802CFC
    if (ctx->r14 != 0) {
        // 0x80802CE8: nop
    
            goto L_80802CFC;
    }
    // 0x80802CE8: nop

    // 0x80802CEC: jal         0x80094C0C
    // 0x80802CF0: nop

    func_80094C0C(rdram, ctx);
        goto after_0;
    // 0x80802CF0: nop

    after_0:
    // 0x80802CF4: b           L_80802D08
    // 0x80802CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802D08;
    // 0x80802CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802CFC:
    // 0x80802CFC: jal         0x80085520
    // 0x80802D00: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _badeathmatch_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80802D00: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_1:
    // 0x80802D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802D08:
    // 0x80802D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802D0C: jr          $ra
    // 0x80802D10: nop

    return;
    // 0x80802D10: nop

;}
RECOMP_FUNC void func_800DDB38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDB38: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800DDB3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800DDB40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800DDB44: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800DDB48: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800DDB4C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800DDB50: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800DDB54: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800DDB58: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800DDB5C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800DDB60: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800DDB64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DDB68: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800DDB6C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DDB70: jal         0x80018C28
    // 0x800DDB74: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_0;
    // 0x800DDB74: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    after_0:
    // 0x800DDB78: lui         $fp, 0xDA38
    ctx->r30 = S32(0XDA38 << 16);
    // 0x800DDB7C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800DDB80: addiu       $s7, $s7, -0x36B8
    ctx->r23 = ADD32(ctx->r23, -0X36B8);
    // 0x800DDB84: ori         $fp, $fp, 0x2
    ctx->r30 = ctx->r30 | 0X2;
    // 0x800DDB88: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x800DDB8C: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800DDB90: lui         $s6, 0xDE00
    ctx->r22 = S32(0XDE00 << 16);
    // 0x800DDB94: lw          $s4, 0x0($s1)
    ctx->r20 = MEM_W(ctx->r17, 0X0);
L_800DDB98:
    // 0x800DDB98: addiu       $t6, $s4, 0x8
    ctx->r14 = ADD32(ctx->r20, 0X8);
    // 0x800DDB9C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800DDBA0: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x800DDBA4: lh          $t7, 0x8($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X8);
    // 0x800DDBA8: lw          $t9, 0x18($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X18);
    // 0x800DDBAC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800DDBB0: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800DDBB4: jal         0x8002E330
    // 0x800DDBB8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800DDBB8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x800DDBBC: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x800DDBC0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800DDBC4: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800DDBC8: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800DDBCC: addiu       $t0, $s0, 0x8
    ctx->r8 = ADD32(ctx->r16, 0X8);
    // 0x800DDBD0: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x800DDBD4: sw          $fp, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r30;
    // 0x800DDBD8: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x800DDBDC: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x800DDBE0: lh          $t2, 0x8($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X8);
    // 0x800DDBE4: bnel        $t2, $zero, L_800DDB98
    if (ctx->r10 != 0) {
        // 0x800DDBE8: lw          $s4, 0x0($s1)
        ctx->r20 = MEM_W(ctx->r17, 0X0);
            goto L_800DDB98;
    }
    goto skip_0;
    // 0x800DDBE8: lw          $s4, 0x0($s1)
    ctx->r20 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x800DDBEC: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x800DDBF0: addiu       $t4, $t3, 0x40
    ctx->r12 = ADD32(ctx->r11, 0X40);
    // 0x800DDBF4: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x800DDBF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800DDBFC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800DDC00: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800DDC04: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800DDC08: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800DDC0C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800DDC10: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800DDC14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800DDC18: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800DDC1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DDC20: jr          $ra
    // 0x800DDC24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800DDC24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80000670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000670: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x80000674: lui         $t6, 0x1E4
    ctx->r14 = S32(0X1E4 << 16);
    // 0x80000678: lui         $t7, 0x1E9
    ctx->r15 = S32(0X1E9 << 16);
    // 0x8000067C: addiu       $v0, $v0, 0x2010
    ctx->r2 = ADD32(ctx->r2, 0X2010);
    // 0x80000680: addiu       $t6, $t6, 0x2550
    ctx->r14 = ADD32(ctx->r14, 0X2550);
    // 0x80000684: addiu       $t7, $t7, -0x6650
    ctx->r15 = ADD32(ctx->r15, -0X6650);
    // 0x80000688: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000068C: jr          $ra
    // 0x80000690: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    return;
    // 0x80000690: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
;}
