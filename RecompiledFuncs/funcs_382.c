#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _plcamera_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087908: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x80087908);
    return;
    // 0x8008790C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void bsdronesuckunder_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: jal         0x8009E6EC
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000F8: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x808000FC: beq         $v0, $at, L_80800120
    if (ctx->r2 == ctx->r1) {
        // 0x80800100: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800120;
    }
    // 0x80800100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80800108: beq         $v0, $at, L_80800120
    if (ctx->r2 == ctx->r1) {
        // 0x8080010C: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800120;
    }
    // 0x8080010C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800110: beq         $v0, $at, L_80800120
    if (ctx->r2 == ctx->r1) {
        // 0x80800114: addiu       $at, $zero, 0x6A
        ctx->r1 = ADD32(0, 0X6A);
            goto L_80800120;
    }
    // 0x80800114: addiu       $at, $zero, 0x6A
    ctx->r1 = ADD32(0, 0X6A);
    // 0x80800118: bne         $v0, $at, L_80800130
    if (ctx->r2 != ctx->r1) {
        // 0x8080011C: nop
    
            goto L_80800130;
    }
    // 0x8080011C: nop

L_80800120:
    // 0x80800120: jal         0x80099B94
    // 0x80800124: nop

    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x80800124: nop

    after_1:
    // 0x80800128: b           L_8080013C
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080013C;
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800130:
    // 0x80800130: jal         0x80099AA8
    // 0x80800134: nop

    func_80099AA8(rdram, ctx);
        goto after_2;
    // 0x80800134: nop

    after_2:
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080013C:
    // 0x8080013C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void _chbigfoot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086338: syscall     309
    recomp_syscall_handler(rdram, ctx, 0x80086338);
    return;
    // 0x8008633C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808012C4_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012CC: jal         0x80091E6C
    // 0x808012D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80091E6C(rdram, ctx);
        goto after_0;
    // 0x808012D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808012D4: jal         0x808004B8
    // 0x808012D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808012D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808012DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012E4: jr          $ra
    // 0x808012E8: nop

    return;
    // 0x808012E8: nop

;}
RECOMP_FUNC void func_808001A0_chfactoryentrydoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001AC: jal         0x800D90A4
    // 0x808001B0: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x808001B0: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x808001B4: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001B8: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_808001E0;
    }
    // 0x808001B8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808001BC: lwc1        $f4, 0x34($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X34);
    // 0x808001C0: addiu       $a0, $zero, 0x48B
    ctx->r4 = ADD32(0, 0X48B);
    // 0x808001C4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808001C8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001CC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808001D0: jal         0x80101180
    // 0x808001D4: nop

    func_80101180(rdram, ctx);
        goto after_1;
    // 0x808001D4: nop

    after_1:
    // 0x808001D8: jal         0x800FFAB0
    // 0x808001DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808001DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_808001E0:
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001E8: jr          $ra
    // 0x808001EC: nop

    return;
    // 0x808001EC: nop

;}
RECOMP_FUNC void basquash_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800568: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080056C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800574: lw          $a0, 0x11C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11C);
    // 0x80800578: jal         0x800D9078
    // 0x8080057C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x8080057C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800580: lw          $t6, 0x11C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X11C);
    // 0x80800584: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800588: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
    // 0x8080058C: beq         $v0, $at, L_8080061C
    if (ctx->r2 == ctx->r1) {
        // 0x80800590: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080061C;
    }
    // 0x80800590: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800594: beq         $v0, $at, L_808005AC
    if (ctx->r2 == ctx->r1) {
        // 0x80800598: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808005AC;
    }
    // 0x80800598: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080059C: beq         $v0, $at, L_808005E4
    if (ctx->r2 == ctx->r1) {
        // 0x808005A0: nop
    
            goto L_808005E4;
    }
    // 0x808005A0: nop

    // 0x808005A4: b           L_80800620
    // 0x808005A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800620;
    // 0x808005A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005AC:
    // 0x808005AC: jal         0x80800260
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800260_basquash(rdram, ctx);
        goto after_1;
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808005B4: lw          $t7, 0x11C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X11C);
    // 0x808005B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x808005C4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808005C8: nop

    // 0x808005CC: bc1fl       L_80800620
    if (!c1cs) {
        // 0x808005D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800620;
    }
    goto skip_0;
    // 0x808005D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808005D4: jal         0x80800008
    // 0x808005D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800008_basquash(rdram, ctx);
        goto after_2;
    // 0x808005D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808005DC: b           L_80800620
    // 0x808005E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800620;
    // 0x808005E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005E4:
    // 0x808005E4: jal         0x80800140
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800140_basquash(rdram, ctx);
        goto after_3;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005EC: jal         0x80800260
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800260_basquash(rdram, ctx);
        goto after_4;
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808005F4: lw          $t8, 0x11C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X11C);
    // 0x808005F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80800604: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80800608: nop

    // 0x8080060C: bc1fl       L_80800620
    if (!c1cs) {
        // 0x80800610: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800620;
    }
    goto skip_1;
    // 0x80800610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800614: jal         0x80800008
    // 0x80800618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800008_basquash(rdram, ctx);
        goto after_5;
    // 0x80800618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_8080061C:
    // 0x8080061C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800620:
    // 0x80800620: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800624: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800628: jr          $ra
    // 0x8080062C: nop

    return;
    // 0x8080062C: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808033D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808033D4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x808033D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_808033DC:
    // 0x808033DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808033E0: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x808033E4: sw          $zero, 0x184($v1)
    MEM_W(0X184, ctx->r3) = 0;
    // 0x808033E8: sw          $zero, 0x188($v1)
    MEM_W(0X188, ctx->r3) = 0;
    // 0x808033EC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x808033F0: bne         $v0, $a1, L_808033DC
    if (ctx->r2 != ctx->r5) {
        // 0x808033F4: sw          $zero, 0x16C($v1)
        MEM_W(0X16C, ctx->r3) = 0;
            goto L_808033DC;
    }
    // 0x808033F4: sw          $zero, 0x16C($v1)
    MEM_W(0X16C, ctx->r3) = 0;
    // 0x808033F8: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x808033FC: sb          $zero, 0x174($a0)
    MEM_B(0X174, ctx->r4) = 0;
    // 0x80803400: sb          $zero, 0x175($a0)
    MEM_B(0X175, ctx->r4) = 0;
    // 0x80803404: andi        $t7, $t6, 0xFB
    ctx->r15 = ctx->r14 & 0XFB;
    // 0x80803408: jr          $ra
    // 0x8080340C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x8080340C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80801128_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801128: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080112C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801130: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1640, 0X14BC) << 16);
    // 0x80801134: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801138: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080113C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801140: addiu       $t6, $t6, 0x14BC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1640, 0X14BC));
    // 0x80801144: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801148: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080114C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801150: jal         0x800BABB8
    // 0x80801154: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80801154: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80801158: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080115C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801160: jal         0x800BA3FC
    // 0x80801164: addiu       $a1, $zero, 0x9DD
    ctx->r5 = ADD32(0, 0X9DD);
    func_800BA3FC(rdram, ctx);
        goto after_1;
    // 0x80801164: addiu       $a1, $zero, 0x9DD
    ctx->r5 = ADD32(0, 0X9DD);
    after_1:
    // 0x80801168: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080116C: jal         0x800BA22C
    // 0x80801170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x80801170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801178: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080117C: jr          $ra
    // 0x80801180: nop

    return;
    // 0x80801180: nop

;}
RECOMP_FUNC void func_808004C4_glsavegame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808004C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808004CC: jr          $ra
    // 0x808004D0: sb          $t6, 0x762A($at)
    MEM_B(0X762A, ctx->r1) = ctx->r14;
    return;
    // 0x808004D0: sb          $t6, 0x762A($at)
    MEM_B(0X762A, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80800000_chheggy(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x80800010: jal         0x8008F8B0
    // 0x80800014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8008F8B0(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800018: jal         0x8008F8D8
    // 0x8080001C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_1;
    // 0x8080001C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800020: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800028: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x8080002C: jal         0x8008F904
    // 0x80800030: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8008F904(rdram, ctx);
        goto after_2;
    // 0x80800030: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x80800034: jal         0x8008F938
    // 0x80800038: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_3;
    // 0x80800038: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8080003C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800040: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800044: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800048: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8080004C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80800050: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800054: jal         0x8008F990
    // 0x80800058: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    func_8008F990(rdram, ctx);
        goto after_4;
    // 0x80800058: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_4:
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800064: jr          $ra
    // 0x80800068: nop

    return;
    // 0x80800068: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B34: jal         0x8008CABC
    // 0x80800B38: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800B38: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800B3C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B44: jal         0x8009D3A8
    // 0x80800B48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x80800B48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800B4C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800B50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800B58: beq         $v0, $zero, L_80800B70
    if (ctx->r2 == 0) {
        // 0x80800B5C: lui         $a1, 0x3F2E
        ctx->r5 = S32(0X3F2E << 16);
            goto L_80800B70;
    }
    // 0x80800B5C: lui         $a1, 0x3F2E
    ctx->r5 = S32(0X3F2E << 16);
    // 0x80800B60: beq         $v0, $at, L_80800BA8
    if (ctx->r2 == ctx->r1) {
        // 0x80800B64: nop
    
            goto L_80800BA8;
    }
    // 0x80800B64: nop

    // 0x80800B68: b           L_80800BBC
    // 0x80800B6C: nop

        goto L_80800BBC;
    // 0x80800B6C: nop

L_80800B70:
    // 0x80800B70: jal         0x8008B348
    // 0x80800B74: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    anctrl_isAt(rdram, ctx);
        goto after_2;
    // 0x80800B74: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    after_2:
    // 0x80800B78: beq         $v0, $zero, L_80800B88
    if (ctx->r2 == 0) {
        // 0x80800B7C: nop
    
            goto L_80800B88;
    }
    // 0x80800B7C: nop

    // 0x80800B80: jal         0x800C3BDC
    // 0x80800B84: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    func_800C3BDC(rdram, ctx);
        goto after_3;
    // 0x80800B84: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    after_3:
L_80800B88:
    // 0x80800B88: jal         0x8008B324
    // 0x80800B8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_4;
    // 0x80800B8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800B90: beq         $v0, $zero, L_80800BBC
    if (ctx->r2 == 0) {
        // 0x80800B94: nop
    
            goto L_80800BBC;
    }
    // 0x80800B94: nop

    // 0x80800B98: jal         0x80800A18
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A18_bsblongleg(rdram, ctx);
        goto after_5;
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800BA0: b           L_80800BBC
    // 0x80800BA4: nop

        goto L_80800BBC;
    // 0x80800BA4: nop

L_80800BA8:
    // 0x80800BA8: jal         0x8008B324
    // 0x80800BAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_6;
    // 0x80800BAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800BB0: beq         $v0, $zero, L_80800BBC
    if (ctx->r2 == 0) {
        // 0x80800BB4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800BBC;
    }
    // 0x80800BB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800BB8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800BBC:
    // 0x80800BBC: jal         0x80800000
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsblongleg(rdram, ctx);
        goto after_7;
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800BC4: beq         $v0, $zero, L_80800BD4
    if (ctx->r2 == 0) {
        // 0x80800BC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD4;
    }
    // 0x80800BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BCC: addiu       $t7, $zero, 0x4C
    ctx->r15 = ADD32(0, 0X4C);
    // 0x80800BD0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800BD4:
    // 0x80800BD4: jal         0x8009E5C8
    // 0x80800BD8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80800BD8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80800BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BE8: jr          $ra
    // 0x80800BEC: nop

    return;
    // 0x80800BEC: nop

;}
RECOMP_FUNC void func_800F4F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4F34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F4F38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F4F3C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4F40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4F44: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4F48: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F4F4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F4F50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F4F54: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800F4F58: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800F4F5C: jal         0x800A3048
    // 0x800F4F60: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800A3048(rdram, ctx);
        goto after_0;
    // 0x800F4F60: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F4F64: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800F4F68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F4F6C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800F4F70: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800F4F74: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F4F78: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800F4F7C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800F4F80: jal         0x8009FA20
    // 0x800F4F84: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8009FA20(rdram, ctx);
        goto after_1;
    // 0x800F4F84: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800F4F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4F8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F4F90: jr          $ra
    // 0x800F4F94: nop

    return;
    // 0x800F4F94: nop

;}
RECOMP_FUNC void func_800F7B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7B9C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F7BA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7BAC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7BB0: jal         0x8009E7C8
    // 0x800F7BB4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009E7C8(rdram, ctx);
        goto after_0;
    // 0x800F7BB4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F7BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F7BC0: jr          $ra
    // 0x800F7BC4: nop

    return;
    // 0x800F7BC4: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897A8: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897A8);
    return;
    // 0x800897AC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080046C_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800470: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800478: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080047C: beq         $a1, $at, L_8080050C
    if (ctx->r5 == ctx->r1) {
        // 0x80800480: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080050C;
    }
    // 0x80800480: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800484: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800488: beq         $a1, $at, L_808004C8
    if (ctx->r5 == ctx->r1) {
        // 0x8080048C: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_808004C8;
    }
    // 0x8080048C: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800490: beq         $a1, $at, L_808004A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800494: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808004A8;
    }
    // 0x80800494: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800498: beq         $a1, $at, L_8080056C
    if (ctx->r5 == ctx->r1) {
        // 0x8080049C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8080056C;
    }
    // 0x8080049C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808004A0: b           L_80800624
    // 0x808004A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800624;
    // 0x808004A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004A8:
    // 0x808004A8: lbu         $t6, 0x79($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X79);
    // 0x808004AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004B0: andi        $t7, $t6, 0xFFFC
    ctx->r15 = ctx->r14 & 0XFFFC;
    // 0x808004B4: sb          $t7, 0x79($a3)
    MEM_B(0X79, ctx->r7) = ctx->r15;
    // 0x808004B8: jal         0x80800328
    // 0x808004BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800328_chhoney(rdram, ctx);
        goto after_0;
    // 0x808004BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x808004C0: b           L_80800624
    // 0x808004C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800624;
    // 0x808004C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004C8:
    // 0x808004C8: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x808004CC: addiu       $at, $zero, 0xCE6
    ctx->r1 = ADD32(0, 0XCE6);
    // 0x808004D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004D4: beq         $a1, $at, L_808004EC
    if (ctx->r5 == ctx->r1) {
        // 0x808004D8: addiu       $at, $zero, 0xCE7
        ctx->r1 = ADD32(0, 0XCE7);
            goto L_808004EC;
    }
    // 0x808004D8: addiu       $at, $zero, 0xCE7
    ctx->r1 = ADD32(0, 0XCE7);
    // 0x808004DC: beq         $a1, $at, L_808004FC
    if (ctx->r5 == ctx->r1) {
        // 0x808004E0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808004FC;
    }
    // 0x808004E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808004E4: b           L_80800624
    // 0x808004E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800624;
    // 0x808004E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004EC:
    // 0x808004EC: jal         0x808000C4
    // 0x808004F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808000C4_chhoney(rdram, ctx);
        goto after_1;
    // 0x808004F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808004F4: b           L_80800624
    // 0x808004F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800624;
    // 0x808004F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004FC:
    // 0x808004FC: jal         0x808000C4
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808000C4_chhoney(rdram, ctx);
        goto after_2;
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800504: b           L_80800624
    // 0x80800508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800624;
    // 0x80800508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080050C:
    // 0x8080050C: lw          $t8, 0x78($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X78);
    // 0x80800510: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800514: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800518: sll         $t0, $t8, 28
    ctx->r8 = S32(ctx->r24 << 28);
    // 0x8080051C: bgez        $t0, L_8080052C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800520: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8080052C;
    }
    // 0x80800520: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800524: b           L_8080052C
    // 0x80800528: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_8080052C;
    // 0x80800528: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8080052C:
    // 0x8080052C: jal         0x8010DD20
    // 0x80800530: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8010DD20(rdram, ctx);
        goto after_3;
    // 0x80800530: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800534: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800538: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x8080053C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80800540: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x80800544: srl         $t3, $t2, 22
    ctx->r11 = S32(U32(ctx->r10) >> 22);
    // 0x80800548: beql        $t3, $at, L_80800624
    if (ctx->r11 == ctx->r1) {
        // 0x8080054C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800624;
    }
    goto skip_0;
    // 0x8080054C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800550: lbu         $a1, 0x79($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X79);
    // 0x80800554: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800558: srl         $t4, $a1, 4
    ctx->r12 = S32(U32(ctx->r5) >> 4);
    // 0x8080055C: jal         0x800DF744
    // 0x80800560: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x80800560: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_4:
    // 0x80800564: b           L_80800624
    // 0x80800568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800624;
    // 0x80800568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080056C:
    // 0x8080056C: lw          $t7, 0x78($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X78);
    // 0x80800570: lbu         $t5, 0x65($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X65);
    // 0x80800574: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800578: sll         $t8, $t7, 28
    ctx->r24 = S32(ctx->r15 << 28);
    // 0x8080057C: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80800580: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x80800584: subu        $t2, $t0, $t9
    ctx->r10 = SUB32(ctx->r8, ctx->r25);
    // 0x80800588: sb          $t6, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r14;
    // 0x8080058C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80800590: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x80800594: andi        $t6, $t5, 0xEF
    ctx->r14 = ctx->r13 & 0XEF;
    // 0x80800598: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x8080059C: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x808005A0: sb          $t7, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r15;
    // 0x808005A4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x808005A8: jal         0x80109EEC
    // 0x808005AC: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_80109EEC(rdram, ctx);
        goto after_5;
    // 0x808005AC: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_5:
    // 0x808005B0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808005B4: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x808005B8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x808005BC: lw          $a1, 0x24($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X24);
    // 0x808005C0: srl         $t0, $a1, 22
    ctx->r8 = S32(U32(ctx->r5) >> 22);
    // 0x808005C4: beq         $t0, $at, L_808005DC
    if (ctx->r8 == ctx->r1) {
        // 0x808005C8: addiu       $at, $zero, 0x22B
        ctx->r1 = ADD32(0, 0X22B);
            goto L_808005DC;
    }
    // 0x808005C8: addiu       $at, $zero, 0x22B
    ctx->r1 = ADD32(0, 0X22B);
    // 0x808005CC: beq         $t0, $at, L_808005DC
    if (ctx->r8 == ctx->r1) {
        // 0x808005D0: addiu       $at, $zero, 0x22C
        ctx->r1 = ADD32(0, 0X22C);
            goto L_808005DC;
    }
    // 0x808005D0: addiu       $at, $zero, 0x22C
    ctx->r1 = ADD32(0, 0X22C);
    // 0x808005D4: bnel        $t0, $at, L_80800624
    if (ctx->r8 != ctx->r1) {
        // 0x808005D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800624;
    }
    goto skip_1;
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
L_808005DC:
    // 0x808005DC: lw          $t9, 0x78($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X78);
    // 0x808005E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x808005E4: addiu       $v0, $v0, 0x7194
    ctx->r2 = ADD32(ctx->r2, 0X7194);
    // 0x808005E8: sll         $t2, $t9, 26
    ctx->r10 = S32(ctx->r25 << 26);
    // 0x808005EC: bltzl       $t2, L_80800624
    if (SIGNED(ctx->r10) < 0) {
        // 0x808005F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800624;
    }
    goto skip_2;
    // 0x808005F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808005F4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x808005F8: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x808005FC: slti        $at, $t5, 0xB
    ctx->r1 = SIGNED(ctx->r13) < 0XB ? 1 : 0;
    // 0x80800600: bne         $at, $zero, L_80800620
    if (ctx->r1 != 0) {
        // 0x80800604: sw          $t5, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r13;
            goto L_80800620;
    }
    // 0x80800604: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80800608: jal         0x80800688
    // 0x8080060C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800688_chhoney(rdram, ctx);
        goto after_6;
    // 0x8080060C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x80800610: b           L_80800624
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800624;
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800618: b           L_80800624
    // 0x8080061C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800624;
    // 0x8080061C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800620:
    // 0x80800620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800624:
    // 0x80800624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080062C: jr          $ra
    // 0x80800630: nop

    return;
    // 0x80800630: nop

;}
RECOMP_FUNC void func_8009312C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009312C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093130: beq         $a1, $zero, L_8009315C
    if (ctx->r5 == 0) {
        // 0x80093134: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009315C;
    }
    // 0x80093134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093138: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x8009313C: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x80093140: beql        $a1, $t6, L_80093160
    if (ctx->r5 == ctx->r14) {
        // 0x80093144: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80093160;
    }
    goto skip_0;
    // 0x80093144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80093148: sh          $a1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r5;
    // 0x8009314C: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x80093150: lh          $a2, 0xC($v0)
    ctx->r6 = MEM_H(ctx->r2, 0XC);
    // 0x80093154: jal         0x80093070
    // 0x80093158: addiu       $a3, $v0, 0x12
    ctx->r7 = ADD32(ctx->r2, 0X12);
    func_80093070(rdram, ctx);
        goto after_0;
    // 0x80093158: addiu       $a3, $v0, 0x12
    ctx->r7 = ADD32(ctx->r2, 0X12);
    after_0:
L_8009315C:
    // 0x8009315C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80093160:
    // 0x80093160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80093164: jr          $ra
    // 0x80093168: nop

    return;
    // 0x80093168: nop

;}
RECOMP_FUNC void func_8010647C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010647C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106484: jal         0x801063EC
    // 0x80106488: lh          $a0, 0x90($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X90);
    func_801063EC(rdram, ctx);
        goto after_0;
    // 0x80106488: lh          $a0, 0x90($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X90);
    after_0:
    // 0x8010648C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106494: jr          $ra
    // 0x80106498: nop

    return;
    // 0x80106498: nop

;}
RECOMP_FUNC void _chbaddiesetup_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D40: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D40);
    return;
    // 0x80086D44: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _fxstep_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A40: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A40);
    return;
    // 0x80088A44: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_8080052C_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080052C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800530: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800534: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800538: jal         0x80105834
    // 0x8080053C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80105834(rdram, ctx);
        goto after_0;
    // 0x8080053C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: jal         0x80105230
    // 0x80800548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_1;
    // 0x80800548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080054C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800550: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800554: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80800558: jal         0x80089F18
    // 0x8080055C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080055C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_2:
    // 0x80800560: jal         0x80105A5C
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_3;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800568: beq         $v0, $zero, L_80800598
    if (ctx->r2 == 0) {
        // 0x8080056C: addiu       $a0, $zero, 0x8C
        ctx->r4 = ADD32(0, 0X8C);
            goto L_80800598;
    }
    // 0x8080056C: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x80800570: jal         0x800DA980
    // 0x80800574: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_4;
    // 0x80800574: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800578: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080057C: beq         $v0, $at, L_80800590
    if (ctx->r2 == ctx->r1) {
        // 0x80800580: addiu       $a0, $zero, 0x13F
        ctx->r4 = ADD32(0, 0X13F);
            goto L_80800590;
    }
    // 0x80800580: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80800584: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x80800588: jal         0x80101180
    // 0x8080058C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x8080058C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_80800590:
    // 0x80800590: jal         0x800FFAB0
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80800598:
    // 0x80800598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080059C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005A4: jr          $ra
    // 0x808005A8: nop

    return;
    // 0x808005A8: nop

;}
RECOMP_FUNC void func_8080015C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800164: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800168: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080016C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800170: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800174: beq         $t6, $at, L_8080018C
    if (ctx->r14 == ctx->r1) {
        // 0x80800178: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8080018C;
    }
    // 0x80800178: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080017C: beq         $t6, $at, L_808001C0
    if (ctx->r14 == ctx->r1) {
        // 0x80800180: addiu       $a0, $a2, 0x58
        ctx->r4 = ADD32(ctx->r6, 0X58);
            goto L_808001C0;
    }
    // 0x80800180: addiu       $a0, $a2, 0x58
    ctx->r4 = ADD32(ctx->r6, 0X58);
    // 0x80800184: b           L_8080021C
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080021C;
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080018C:
    // 0x8080018C: jal         0x80803E40
    // 0x80800190: nop

    func_80803E40_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80800190: nop

    after_0:
    // 0x80800194: beql        $v0, $zero, L_8080021C
    if (ctx->r2 == 0) {
        // 0x80800198: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080021C;
    }
    goto skip_0;
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080019C: jal         0x80088360
    // 0x808001A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808001A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A8: beql        $v0, $a0, L_8080021C
    if (ctx->r2 == ctx->r4) {
        // 0x808001AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080021C;
    }
    goto skip_1;
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808001B0: jal         0x80088320
    // 0x808001B4: nop

    _gcstatusDll_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808001B4: nop

    after_2:
    // 0x808001B8: b           L_8080021C
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080021C;
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001C0:
    // 0x808001C0: jal         0x800D9078
    // 0x808001C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x808001C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x808001C8: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x808001CC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800218;
    }
    // 0x808001CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808001D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x808001D4: lw          $t7, -0x5C10($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5C10);
    // 0x808001D8: beql        $t7, $zero, L_808001F0
    if (ctx->r15 == 0) {
        // 0x808001DC: lbu         $a1, 0x79($a2)
        ctx->r5 = MEM_BU(ctx->r6, 0X79);
            goto L_808001F0;
    }
    goto skip_2;
    // 0x808001DC: lbu         $a1, 0x79($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X79);
    skip_2:
    // 0x808001E0: jal         0x80803C80
    // 0x808001E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80803C80_chgameselect(rdram, ctx);
        goto after_4;
    // 0x808001E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x808001E8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808001EC: lbu         $a1, 0x79($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X79);
L_808001F0:
    // 0x808001F0: lw          $a0, 0x28($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X28);
    // 0x808001F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001F8: srl         $t8, $a1, 4
    ctx->r24 = S32(U32(ctx->r5) >> 4);
    // 0x808001FC: jal         0x808016E8
    // 0x80800200: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_808016E8_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80800200: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_5:
    // 0x80800204: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800208: lw          $a1, 0x6C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X6C);
    // 0x8080020C: andi        $t9, $a1, 0x1FF
    ctx->r25 = ctx->r5 & 0X1FF;
    // 0x80800210: jal         0x80800478
    // 0x80800214: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_80800478_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80800214: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_6:
L_80800218:
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080021C:
    // 0x8080021C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_8080010C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800110: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800114: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800118: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8080011C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80800120: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80800124: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800128: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8080012C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800130: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800134: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800138: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080013C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800140: jal         0x80100094
    // 0x80800144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800148: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8080014C: lhu         $v1, 0x72($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X72);
    // 0x80800150: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80800154: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800158: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080015C: beq         $t6, $s7, L_80800188
    if (ctx->r14 == ctx->r23) {
        // 0x80800160: nop
    
            goto L_80800188;
    }
    // 0x80800160: nop

    // 0x80800164: beq         $t6, $at, L_8080031C
    if (ctx->r14 == ctx->r1) {
        // 0x80800168: addiu       $fp, $zero, 0x3
        ctx->r30 = ADD32(0, 0X3);
            goto L_8080031C;
    }
    // 0x80800168: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x8080016C: beq         $t6, $fp, L_80800198
    if (ctx->r14 == ctx->r30) {
        // 0x80800170: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800198;
    }
    // 0x80800170: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800174: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800178: beq         $t6, $at, L_80800314
    if (ctx->r14 == ctx->r1) {
        // 0x8080017C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800314;
    }
    // 0x8080017C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800180: b           L_80800320
    // 0x80800184: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80800320;
    // 0x80800184: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800188:
    // 0x80800188: jal         0x8080160C
    // 0x8080018C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8080160C_chdodgemcontrol(rdram, ctx);
        goto after_1;
    // 0x8080018C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80800190: b           L_80800320
    // 0x80800194: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80800320;
    // 0x80800194: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800198:
    // 0x80800198: jal         0x80801A8C
    // 0x8080019C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801A8C_chdodgemcontrol(rdram, ctx);
        goto after_2;
    // 0x8080019C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808001A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001A4: jal         0x800CEB54
    // 0x808001A8: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    func_800CEB54(rdram, ctx);
        goto after_3;
    // 0x808001A8: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_3:
    // 0x808001AC: bnel        $v0, $zero, L_808001D0
    if (ctx->r2 != 0) {
        // 0x808001B0: lw          $a3, 0x54($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X54);
            goto L_808001D0;
    }
    goto skip_0;
    // 0x808001B0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x808001B4: jal         0x800CEAD0
    // 0x808001B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_4;
    // 0x808001B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x808001BC: beql        $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x808001C0: lw          $a3, 0x54($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X54);
            goto L_808001D0;
    }
    goto skip_1;
    // 0x808001C0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x808001C4: jal         0x80800CA0
    // 0x808001C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800CA0_chdodgemcontrol(rdram, ctx);
        goto after_5;
    // 0x808001C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x808001CC: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
L_808001D0:
    // 0x808001D0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x808001D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001D8: lbu         $v0, 0xC5($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XC5);
    // 0x808001DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X49B0) << 16);
    // 0x808001E0: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x808001E4: blez        $v0, L_808002F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808001E8: or          $s1, $a3, $zero
        ctx->r17 = ctx->r7 | 0;
            goto L_808002F4;
    }
    // 0x808001E8: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x808001EC: lwc1        $f20, 0x49B0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X49B0));
    // 0x808001F0: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_808001F4:
    // 0x808001F4: lbu         $v1, 0xAC($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XAC);
    // 0x808001F8: beql        $v1, $zero, L_808002E4
    if (ctx->r3 == 0) {
        // 0x808001FC: sw          $s7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r23;
            goto L_808002E4;
    }
    goto skip_2;
    // 0x808001FC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    skip_2:
    // 0x80800200: bnel        $v1, $s7, L_808002E8
    if (ctx->r3 != ctx->r23) {
        // 0x80800204: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_808002E8;
    }
    goto skip_3;
    // 0x80800204: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_3:
    // 0x80800208: lbu         $s4, 0xC2($a3)
    ctx->r20 = MEM_BU(ctx->r7, 0XC2);
    // 0x8080020C: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80800210: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80800214: blez        $s4, L_808002E4
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80800218: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808002E4;
    }
    // 0x80800218: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080021C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800220: addu        $s2, $a3, $t7
    ctx->r18 = ADD32(ctx->r7, ctx->r15);
    // 0x80800224: addiu       $s2, $s2, 0x34
    ctx->r18 = ADD32(ctx->r18, 0X34);
    // 0x80800228: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8080022C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800230:
    // 0x80800230: jal         0x8080000C
    // 0x80800234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8080000C_chdodgemcontrol(rdram, ctx);
        goto after_6;
    // 0x80800234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800238: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8080023C: jal         0x800EEB40
    // 0x80800240: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEB40(rdram, ctx);
        goto after_7;
    // 0x80800240: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80800244: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800248: nop

    // 0x8080024C: bc1fl       L_808002C8
    if (!c1cs) {
        // 0x80800250: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808002C8;
    }
    goto skip_4;
    // 0x80800250: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x80800254: lbu         $v1, 0x79($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X79);
    // 0x80800258: srl         $t8, $v1, 4
    ctx->r24 = S32(U32(ctx->r3) >> 4);
    // 0x8080025C: beq         $t8, $zero, L_80800284
    if (ctx->r24 == 0) {
        // 0x80800260: nop
    
            goto L_80800284;
    }
    // 0x80800260: nop

    // 0x80800264: beq         $t8, $s7, L_80800284
    if (ctx->r24 == ctx->r23) {
        // 0x80800268: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800284;
    }
    // 0x80800268: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080026C: beq         $t8, $at, L_80800284
    if (ctx->r24 == ctx->r1) {
        // 0x80800270: nop
    
            goto L_80800284;
    }
    // 0x80800270: nop

    // 0x80800274: beql        $t8, $fp, L_80800298
    if (ctx->r24 == ctx->r30) {
        // 0x80800278: lbu         $a0, 0xB6($s1)
        ctx->r4 = MEM_BU(ctx->r17, 0XB6);
            goto L_80800298;
    }
    goto skip_5;
    // 0x80800278: lbu         $a0, 0xB6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XB6);
    skip_5:
    // 0x8080027C: b           L_808002C8
    // 0x80800280: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_808002C8;
    // 0x80800280: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800284:
    // 0x80800284: beql        $s0, $zero, L_80800298
    if (ctx->r16 == 0) {
        // 0x80800288: lbu         $a0, 0xB6($s1)
        ctx->r4 = MEM_BU(ctx->r17, 0XB6);
            goto L_80800298;
    }
    goto skip_6;
    // 0x80800288: lbu         $a0, 0xB6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XB6);
    skip_6:
    // 0x8080028C: b           L_808002C4
    // 0x80800290: sb          $s6, 0xAC($s1)
    MEM_B(0XAC, ctx->r17) = ctx->r22;
        goto L_808002C4;
    // 0x80800290: sb          $s6, 0xAC($s1)
    MEM_B(0XAC, ctx->r17) = ctx->r22;
    // 0x80800294: lbu         $a0, 0xB6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XB6);
L_80800298:
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080029C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808002A0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x808002A4: jal         0x80086468
    // 0x808002A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    _chscorepoints_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808002A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_8:
    // 0x808002AC: lbu         $a2, 0xB6($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0XB6);
    // 0x808002B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808002B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808002B8: jal         0x80800FC4
    // 0x808002BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    func_80800FC4_chdodgemcontrol(rdram, ctx);
        goto after_9;
    // 0x808002BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_9:
    // 0x808002C0: sb          $s5, 0xAC($s1)
    MEM_B(0XAC, ctx->r17) = ctx->r21;
L_808002C4:
    // 0x808002C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808002C8:
    // 0x808002C8: bnel        $s0, $s4, L_80800230
    if (ctx->r16 != ctx->r20) {
        // 0x808002CC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800230;
    }
    goto skip_7;
    // 0x808002CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_7:
    // 0x808002D0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x808002D4: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x808002D8: b           L_808002E4
    // 0x808002DC: lbu         $v0, 0xC5($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XC5);
        goto L_808002E4;
    // 0x808002DC: lbu         $v0, 0xC5($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XC5);
    // 0x808002E0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
L_808002E4:
    // 0x808002E4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_808002E8:
    // 0x808002E8: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808002EC: bne         $at, $zero, L_808001F4
    if (ctx->r1 != 0) {
        // 0x808002F0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808001F4;
    }
    // 0x808002F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808002F4:
    // 0x808002F4: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x808002F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808002FC: beql        $t0, $zero, L_80800320
    if (ctx->r8 == 0) {
        // 0x80800300: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80800320;
    }
    goto skip_8;
    // 0x80800300: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_8:
    // 0x80800304: jal         0x80108B04
    // 0x80800308: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80108B04(rdram, ctx);
        goto after_10;
    // 0x80800308: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_10:
    // 0x8080030C: b           L_80800320
    // 0x80800310: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80800320;
    // 0x80800310: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800314:
    // 0x80800314: jal         0x80801A8C
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801A8C_chdodgemcontrol(rdram, ctx);
        goto after_11;
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
L_8080031C:
    // 0x8080031C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800320:
    // 0x80800320: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800324: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800328: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8080032C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800330: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800334: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800338: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8080033C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80800340: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80800344: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80800348: jr          $ra
    // 0x8080034C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080034C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800744_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800748: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080074C: addiu       $at, $zero, 0x14F6
    ctx->r1 = ADD32(0, 0X14F6);
    // 0x80800750: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800758: beq         $a1, $at, L_808007A0
    if (ctx->r5 == ctx->r1) {
        // 0x8080075C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808007A0;
    }
    // 0x8080075C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800760: addiu       $at, $zero, 0x14FC
    ctx->r1 = ADD32(0, 0X14FC);
    // 0x80800764: beq         $a1, $at, L_808007C4
    if (ctx->r5 == ctx->r1) {
        // 0x80800768: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808007C4;
    }
    // 0x80800768: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080076C: addiu       $at, $zero, 0x1511
    ctx->r1 = ADD32(0, 0X1511);
    // 0x80800770: beq         $a1, $at, L_808007D4
    if (ctx->r5 == ctx->r1) {
        // 0x80800774: addiu       $at, $zero, 0x155B
        ctx->r1 = ADD32(0, 0X155B);
            goto L_808007D4;
    }
    // 0x80800774: addiu       $at, $zero, 0x155B
    ctx->r1 = ADD32(0, 0X155B);
    // 0x80800778: beq         $a1, $at, L_808007C4
    if (ctx->r5 == ctx->r1) {
        // 0x8080077C: addiu       $at, $zero, 0x155C
        ctx->r1 = ADD32(0, 0X155C);
            goto L_808007C4;
    }
    // 0x8080077C: addiu       $at, $zero, 0x155C
    ctx->r1 = ADD32(0, 0X155C);
    // 0x80800780: beq         $a1, $at, L_808007C4
    if (ctx->r5 == ctx->r1) {
        // 0x80800784: addiu       $at, $zero, 0x155D
        ctx->r1 = ADD32(0, 0X155D);
            goto L_808007C4;
    }
    // 0x80800784: addiu       $at, $zero, 0x155D
    ctx->r1 = ADD32(0, 0X155D);
    // 0x80800788: beq         $a1, $at, L_808007C4
    if (ctx->r5 == ctx->r1) {
        // 0x8080078C: addiu       $at, $zero, 0x155E
        ctx->r1 = ADD32(0, 0X155E);
            goto L_808007C4;
    }
    // 0x8080078C: addiu       $at, $zero, 0x155E
    ctx->r1 = ADD32(0, 0X155E);
    // 0x80800790: beq         $a1, $at, L_808007C4
    if (ctx->r5 == ctx->r1) {
        // 0x80800794: nop
    
            goto L_808007C4;
    }
    // 0x80800794: nop

    // 0x80800798: b           L_808007E4
    // 0x8080079C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007E4;
    // 0x8080079C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007A0:
    // 0x808007A0: jal         0x80085710
    // 0x808007A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808007A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808007A8: jal         0x800DA544
    // 0x808007AC: addiu       $a0, $zero, 0x35B
    ctx->r4 = ADD32(0, 0X35B);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808007AC: addiu       $a0, $zero, 0x35B
    ctx->r4 = ADD32(0, 0X35B);
    after_1:
    // 0x808007B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007B4: jal         0x80800220
    // 0x808007B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_2;
    // 0x808007B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808007BC: b           L_808007E4
    // 0x808007C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007E4;
    // 0x808007C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007C4:
    // 0x808007C4: jal         0x80800220
    // 0x808007C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_3;
    // 0x808007C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808007CC: b           L_808007E4
    // 0x808007D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007E4;
    // 0x808007D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007D4:
    // 0x808007D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808007D8: jal         0x80800220
    // 0x808007DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_4;
    // 0x808007DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x808007E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007E4:
    // 0x808007E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007E8: jr          $ra
    // 0x808007EC: nop

    return;
    // 0x808007EC: nop

;}
RECOMP_FUNC void bsbfly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808009C0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(96, 0X1D58) << 16);
    // 0x808009C4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808009C8: jr          $ra
    // 0x808009CC: lw          $v0, 0x1D58($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D58));
    return;
    // 0x808009CC: lw          $v0, 0x1D58($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D58));
;}
RECOMP_FUNC void func_8080070C_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080070C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800710: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800714: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80800718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080071C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800720: jal         0x80100094
    // 0x80800724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800728: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080072C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800730: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800734: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800738: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080073C: addiu       $a1, $a2, 0x6
    ctx->r5 = ADD32(ctx->r6, 0X6);
    // 0x80800740: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800744: bc1fl       L_8080075C
    if (!c1cs) {
        // 0x80800748: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8080075C;
    }
    goto skip_0;
    // 0x80800748: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8080074C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800750: b           L_80800778
    // 0x80800754: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800778;
    // 0x80800754: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800758: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8080075C:
    // 0x8080075C: nop

    // 0x80800760: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800764: nop

    // 0x80800768: bc1fl       L_8080077C
    if (!c1cs) {
        // 0x8080076C: sw          $v1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r3;
            goto L_8080077C;
    }
    goto skip_1;
    // 0x8080076C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    skip_1:
    // 0x80800770: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800774: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800778:
    // 0x80800778: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
L_8080077C:
    // 0x8080077C: jal         0x800EE88C
    // 0x80800780: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x80800780: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800784: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800788: jal         0x800EE88C
    // 0x8080078C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x8080078C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x80800790: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800794: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800798: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8080079C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808007A0: jal         0x800EFE50
    // 0x808007A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFE50(rdram, ctx);
        goto after_3;
    // 0x808007A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x808007A8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x808007AC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x808007B0: swc1        $f20, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f20.u32l;
    // 0x808007B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007B8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808007BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808007C0: jr          $ra
    // 0x808007C4: nop

    return;
    // 0x808007C4: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808B10: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80808B14: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB5C0) << 16);
    // 0x80808B18: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80808B1C: jr          $ra
    // 0x80808B20: lw          $v0, -0x4A40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB5C0));
    return;
    // 0x80808B20: lw          $v0, -0x4A40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB5C0));
;}
RECOMP_FUNC void func_80800A88_chdinoswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A8C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800A90: beq         $a1, $at, L_80800AAC
    if (ctx->r5 == ctx->r1) {
        // 0x80800A94: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800AAC;
    }
    // 0x80800A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A98: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800A9C: beql        $a1, $at, L_80800AE8
    if (ctx->r5 == ctx->r1) {
        // 0x80800AA0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800AE8;
    }
    goto skip_0;
    // 0x80800AA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x80800AA4: b           L_80800B00
    // 0x80800AA8: nop

        goto L_80800B00;
    // 0x80800AA8: nop

L_80800AAC:
    // 0x80800AAC: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80800AB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800AB4: bne         $t6, $at, L_80800ADC
    if (ctx->r14 != ctx->r1) {
        // 0x80800AB8: addiu       $at, $zero, 0x23
        ctx->r1 = ADD32(0, 0X23);
            goto L_80800ADC;
    }
    // 0x80800AB8: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80800ABC: bne         $a2, $at, L_80800ADC
    if (ctx->r6 != ctx->r1) {
        // 0x80800AC0: nop
    
            goto L_80800ADC;
    }
    // 0x80800AC0: nop

    // 0x80800AC4: jal         0x80088840
    // 0x80800AC8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80800AC8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_0:
    // 0x80800ACC: beq         $v0, $zero, L_80800ADC
    if (ctx->r2 == 0) {
        // 0x80800AD0: nop
    
            goto L_80800ADC;
    }
    // 0x80800AD0: nop

    // 0x80800AD4: jal         0x80088830
    // 0x80800AD8: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80800AD8: nop

    after_1:
L_80800ADC:
    // 0x80800ADC: b           L_80800B08
    // 0x80800AE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800B08;
    // 0x80800AE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800AE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80800AE8:
    // 0x80800AE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800AEC: jal         0x80800A48
    // 0x80800AF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800A48_chdinoswitches(rdram, ctx);
        goto after_2;
    // 0x80800AF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x80800AF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800AF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AFC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80800B00:
    // 0x80800B00: jal         0x80086248
    // 0x80800B04: nop

    _chdoor_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800B04: nop

    after_3:
L_80800B08:
    // 0x80800B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B10: jr          $ra
    // 0x80800B14: nop

    return;
    // 0x80800B14: nop

    // 0x80800B18: nop

    // 0x80800B1C: nop

;}
RECOMP_FUNC void _bswasher_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084410: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x80084410);
    return;
    // 0x80084414: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_808000A0_bsmumsplat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B0: jal         0x8008CABC
    // 0x808000B4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808000B4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808000B8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808000BC: jal         0x8009BB00
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000C4: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x808000C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000CC: nop

    // 0x808000D0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808000D4: nop

    // 0x808000D8: bc1f        L_808000E8
    if (!c1cs) {
        // 0x808000DC: nop
    
            goto L_808000E8;
    }
    // 0x808000DC: nop

    // 0x808000E0: jal         0x80084A10
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_808000E8:
    // 0x808000E8: jal         0x8008DD04
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_3;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000F0: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x808000F4: lui         $a1, 0x3EF5
        ctx->r5 = S32(0X3EF5 << 16);
            goto L_80800100;
    }
    // 0x808000F4: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x808000F8: addiu       $t6, $zero, 0xE9
    ctx->r14 = ADD32(0, 0XE9);
    // 0x808000FC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800100:
    // 0x80800100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800104: jal         0x8008B348
    // 0x80800108: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x80800108: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    after_4:
    // 0x8080010C: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x80800110: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800128;
    }
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800118: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080011C: addiu       $a1, $zero, 0x4B1
    ctx->r5 = ADD32(0, 0X4B1);
    // 0x80800120: jal         0x8009DB04
    // 0x80800124: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DB04(rdram, ctx);
        goto after_5;
    // 0x80800124: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_5:
L_80800128:
    // 0x80800128: lui         $a1, 0x3F3D
    ctx->r5 = S32(0X3F3D << 16);
    // 0x8080012C: ori         $a1, $a1, 0xCC64
    ctx->r5 = ctx->r5 | 0XCC64;
    // 0x80800130: jal         0x8008B348
    // 0x80800134: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_6;
    // 0x80800134: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800138: beq         $v0, $zero, L_80800144
    if (ctx->r2 == 0) {
        // 0x8080013C: addiu       $t7, $zero, 0xEF
        ctx->r15 = ADD32(0, 0XEF);
            goto L_80800144;
    }
    // 0x8080013C: addiu       $t7, $zero, 0xEF
    ctx->r15 = ADD32(0, 0XEF);
    // 0x80800140: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800144:
    // 0x80800144: jal         0x8008E078
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_7;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080014C: bne         $v0, $zero, L_80800168
    if (ctx->r2 != 0) {
        // 0x80800150: nop
    
            goto L_80800168;
    }
    // 0x80800150: nop

    // 0x80800154: jal         0x8008E35C
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_8;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080015C: beq         $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x80800160: addiu       $t8, $zero, 0xF0
        ctx->r24 = ADD32(0, 0XF0);
            goto L_80800168;
    }
    // 0x80800160: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x80800164: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800168:
    // 0x80800168: jal         0x800A1718
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_9;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800170: bne         $v0, $zero, L_80800180
    if (ctx->r2 != 0) {
        // 0x80800174: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800180;
    }
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: addiu       $t9, $zero, 0xEB
    ctx->r25 = ADD32(0, 0XEB);
    // 0x8080017C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800180:
    // 0x80800180: jal         0x8009E5C8
    // 0x80800184: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x80800184: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80800188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080018C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800190: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800194: jr          $ra
    // 0x80800198: nop

    return;
    // 0x80800198: nop

;}
RECOMP_FUNC void _bsbansack_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826C8: syscall     7
    recomp_syscall_handler(rdram, ctx, 0x800826C8);
    return;
    // 0x800826CC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _fxkern_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B18: syscall     724
    recomp_syscall_handler(rdram, ctx, 0x80088B18);
    return;
    // 0x80088B1C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8009EA7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EA80: jr          $ra
    // 0x8009EA84: lwc1        $f0, 0x7068($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7068);
    return;
    // 0x8009EA84: lwc1        $f0, 0x7068($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7068);
;}
RECOMP_FUNC void func_808005D8_chwallsnakebaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005DC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808005E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005E4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808005E8: beq         $a1, $at, L_80800604
    if (ctx->r5 == ctx->r1) {
        // 0x808005EC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800604;
    }
    // 0x808005EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808005F0: addiu       $at, $zero, 0x97
    ctx->r1 = ADD32(0, 0X97);
    // 0x808005F4: beq         $a1, $at, L_80800618
    if (ctx->r5 == ctx->r1) {
        // 0x808005F8: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80800618;
    }
    // 0x808005F8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808005FC: b           L_80800640
    // 0x80800600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800640;
    // 0x80800600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800604:
    // 0x80800604: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800608: jal         0x808004FC
    // 0x8080060C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808004FC_chwallsnakebaddy(rdram, ctx);
        goto after_0;
    // 0x8080060C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80800610: b           L_80800640
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800640;
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800618:
    // 0x80800618: lw          $a1, 0x48($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X48);
    // 0x8080061C: jal         0x800EEB9C
    // 0x80800620: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x80800620: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_1:
    // 0x80800624: jal         0x80101010
    // 0x80800628: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_80101010(rdram, ctx);
        goto after_2;
    // 0x80800628: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8080062C: b           L_80800640
    // 0x80800630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800640;
    // 0x80800630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800634: b           L_80800640
    // 0x80800638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800640;
    // 0x80800638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080063C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800640:
    // 0x80800640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800644: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800648: jr          $ra
    // 0x8080064C: nop

    return;
    // 0x8080064C: nop

;}
RECOMP_FUNC void func_80801384_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801384: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080138C: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80801390: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801398: beql        $t6, $at, L_808014BC
    if (ctx->r14 == ctx->r1) {
        // 0x8080139C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808014BC;
    }
    goto skip_0;
    // 0x8080139C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808013A0: jal         0x800852F0
    // 0x808013A4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x808013A4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808013AC: jal         0x80085330
    // 0x808013B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isZero(rdram, ctx);
        goto after_1;
    // 0x808013B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808013B4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808013B8: jal         0x8009CC68
    // 0x808013BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8009CC68(rdram, ctx);
        goto after_2;
    // 0x808013BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x808013C0: bnel        $v0, $zero, L_808014BC
    if (ctx->r2 != 0) {
        // 0x808013C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808014BC;
    }
    goto skip_1;
    // 0x808013C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808013C8: jal         0x800DB9B0
    // 0x808013CC: nop

    func_800DB9B0(rdram, ctx);
        goto after_3;
    // 0x808013CC: nop

    after_3:
    // 0x808013D0: bnel        $v0, $zero, L_808014BC
    if (ctx->r2 != 0) {
        // 0x808013D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808014BC;
    }
    goto skip_2;
    // 0x808013D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x808013D8: jal         0x800F54E4
    // 0x808013DC: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808013DC: nop

    after_4:
    // 0x808013E0: jal         0x800F6D24
    // 0x808013E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6D24(rdram, ctx);
        goto after_5;
    // 0x808013E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808013E8: bne         $v0, $zero, L_808014B8
    if (ctx->r2 != 0) {
        // 0x808013EC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808014B8;
    }
    // 0x808013EC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808013F0: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x808013F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808013F8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x808013FC: beq         $v0, $at, L_80801420
    if (ctx->r2 == ctx->r1) {
        // 0x80801400: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801420;
    }
    // 0x80801400: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801404: beq         $v0, $at, L_80801484
    if (ctx->r2 == ctx->r1) {
        // 0x80801408: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_80801484;
    }
    // 0x80801408: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8080140C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801410: beql        $v0, $at, L_808014BC
    if (ctx->r2 == ctx->r1) {
        // 0x80801414: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808014BC;
    }
    goto skip_3;
    // 0x80801414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80801418: b           L_808014BC
    // 0x8080141C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808014BC;
    // 0x8080141C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801420:
    // 0x80801420: beql        $t7, $zero, L_808014BC
    if (ctx->r15 == 0) {
        // 0x80801424: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808014BC;
    }
    goto skip_4;
    // 0x80801424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80801428: jal         0x800F3BB0
    // 0x8080142C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F3BB0(rdram, ctx);
        goto after_6;
    // 0x8080142C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x80801430: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80801434: lbu         $t8, 0x762C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X762C);
    // 0x80801438: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8080143C: addiu       $a0, $zero, 0x418
    ctx->r4 = ADD32(0, 0X418);
    // 0x80801440: bne         $t8, $at, L_8080145C
    if (ctx->r24 != ctx->r1) {
        // 0x80801444: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8080145C;
    }
    // 0x80801444: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801448: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x8080144C: jal         0x80101180
    // 0x80801450: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80801450: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80801454: b           L_8080145C
    // 0x80801458: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080145C;
    // 0x80801458: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080145C:
    // 0x8080145C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801460: beql        $v1, $at, L_80801474
    if (ctx->r3 == ctx->r1) {
        // 0x80801464: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80801474;
    }
    goto skip_5;
    // 0x80801464: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    skip_5:
    // 0x80801468: jal         0x800F9ADC
    // 0x8080146C: nop

    func_800F9ADC(rdram, ctx);
        goto after_8;
    // 0x8080146C: nop

    after_8:
    // 0x80801470: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_80801474:
    // 0x80801474: jal         0x80801134
    // 0x80801478: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801134_bsbabykaz(rdram, ctx);
        goto after_9;
    // 0x80801478: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x8080147C: b           L_808014BC
    // 0x80801480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808014BC;
    // 0x80801480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801484:
    // 0x80801484: beql        $t9, $zero, L_808014BC
    if (ctx->r25 == 0) {
        // 0x80801488: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808014BC;
    }
    goto skip_6;
    // 0x80801488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8080148C: jal         0x800F3BB0
    // 0x80801490: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F3BB0(rdram, ctx);
        goto after_10;
    // 0x80801490: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_10:
    // 0x80801494: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80801498: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x8080149C: jal         0x801013A8
    // 0x808014A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_801013A8(rdram, ctx);
        goto after_11;
    // 0x808014A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x808014A4: jal         0x800F9ADC
    // 0x808014A8: nop

    func_800F9ADC(rdram, ctx);
        goto after_12;
    // 0x808014A8: nop

    after_12:
    // 0x808014AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808014B0: jal         0x80801134
    // 0x808014B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801134_bsbabykaz(rdram, ctx);
        goto after_13;
    // 0x808014B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
L_808014B8:
    // 0x808014B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014BC:
    // 0x808014BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808014C0: jr          $ra
    // 0x808014C4: nop

    return;
    // 0x808014C4: nop

;}
RECOMP_FUNC void _bawasher_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085430: syscall     161
    recomp_syscall_handler(rdram, ctx, 0x80085430);
    return;
    // 0x80085434: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800000_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080000C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80800010: jal         0x80100094
    // 0x80800014: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800014: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800018: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8080001C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800020: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: beq         $a0, $t6, L_80800030
    if (ctx->r4 == ctx->r14) {
        // 0x80800028: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800030;
    }
    // 0x80800028: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080002C: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_80800030:
    // 0x80800030: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x80800034: beql        $a0, $t7, L_80800044
    if (ctx->r4 == ctx->r15) {
        // 0x80800038: lbu         $t8, 0x2($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X2);
            goto L_80800044;
    }
    goto skip_0;
    // 0x80800038: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    skip_0:
    // 0x8080003C: sb          $a2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r6;
    // 0x80800040: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
L_80800044:
    // 0x80800044: beql        $a0, $t8, L_80800054
    if (ctx->r4 == ctx->r24) {
        // 0x80800048: lbu         $t9, 0x3($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X3);
            goto L_80800054;
    }
    goto skip_1;
    // 0x80800048: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    skip_1:
    // 0x8080004C: sb          $a2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r6;
    // 0x80800050: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
L_80800054:
    // 0x80800054: beql        $a0, $t9, L_80800064
    if (ctx->r4 == ctx->r25) {
        // 0x80800058: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800064;
    }
    goto skip_2;
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8080005C: sb          $a2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r6;
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800064:
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void _bsvan_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084150: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084150);
    return;
    // 0x80084154: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808031F4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808031F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808031F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808031FC: jal         0x80106790
    // 0x80803200: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80803200: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80803204: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80803208: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080320C: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80803210: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
    // 0x80803214: subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    // 0x80803218: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8080321C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803224: jal         0x80100074
    // 0x80803228: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x80803228: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    after_1:
    // 0x8080322C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80803230: jal         0x80101FDC
    // 0x80803234: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80803234: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80803238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080323C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803240: jr          $ra
    // 0x80803244: nop

    return;
    // 0x80803244: nop

;}
RECOMP_FUNC void _chdiggerbossbattery_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086808: syscall     381
    recomp_syscall_handler(rdram, ctx, 0x80086808);
    return;
    // 0x8008680C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chnewshovel_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086838: syscall     386
    recomp_syscall_handler(rdram, ctx, 0x80086838);
    return;
    // 0x8008683C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808003A8_chgoldsnakehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003AC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808003B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B4: bne         $a1, $at, L_808003CC
    if (ctx->r5 != ctx->r1) {
        // 0x808003B8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808003CC;
    }
    // 0x808003B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003BC: jal         0x80800324
    // 0x808003C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800324_chgoldsnakehead(rdram, ctx);
        goto after_0;
    // 0x808003C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808003C4: b           L_808003D0
    // 0x808003C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003D0;
    // 0x808003C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003CC:
    // 0x808003CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003D0:
    // 0x808003D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D8: jr          $ra
    // 0x808003DC: nop

    return;
    // 0x808003DC: nop

;}
RECOMP_FUNC void func_800DC454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC454: andi        $a2, $a1, 0xFFFF
    ctx->r6 = ctx->r5 & 0XFFFF;
    // 0x800DC458: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800DC45C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC460: slt         $at, $a2, $at
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800DC464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC468: bne         $at, $zero, L_800DC474
    if (ctx->r1 != 0) {
        // 0x800DC46C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800DC474;
    }
    // 0x800DC46C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DC470: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
L_800DC474:
    // 0x800DC474: jal         0x80020C08
    // 0x800DC478: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80020C08(rdram, ctx);
        goto after_0;
    // 0x800DC478: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x800DC47C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC484: jr          $ra
    // 0x800DC488: nop

    return;
    // 0x800DC488: nop

;}
RECOMP_FUNC void func_80800E64_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E6C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1860, 0X11D0) << 16);
    // 0x80800E70: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1860, 0X135C) << 16);
    // 0x80800E74: addiu       $a3, $a3, 0x135C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1860, 0X135C));
    // 0x80800E78: addiu       $a2, $a2, 0x11D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1860, 0X11D0));
    // 0x80800E7C: jal         0x80089D28
    // 0x80800E80: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800E80: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E8C: jr          $ra
    // 0x80800E90: nop

    return;
    // 0x80800E90: nop

;}
RECOMP_FUNC void func_8010486C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010486C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80104870: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80104874: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80104878: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8010487C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80104880: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80104884: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80104888: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8010488C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80104890: beql        $v0, $a0, L_801048C8
    if (ctx->r2 == ctx->r4) {
        // 0x80104894: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_801048C8;
    }
    goto skip_0;
    // 0x80104894: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_0:
    // 0x80104898: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_8010489C:
    // 0x8010489C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801048A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801048A4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801048A8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801048AC: nop

    // 0x801048B0: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
    // 0x801048B4: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801048B8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801048BC: bnel        $v0, $a0, L_8010489C
    if (ctx->r2 != ctx->r4) {
        // 0x801048C0: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_8010489C;
    }
    goto skip_1;
    // 0x801048C0: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_1:
    // 0x801048C4: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_801048C8:
    // 0x801048C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801048CC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801048D0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801048D4: nop

    // 0x801048D8: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
    // 0x801048DC: jr          $ra
    // 0x801048E0: nop

    return;
    // 0x801048E0: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084328: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084328);
    return;
    // 0x8008432C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_801072E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801072E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801072E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801072EC: jal         0x80106F30
    // 0x801072F0: nop

    func_80106F30(rdram, ctx);
        goto after_0;
    // 0x801072F0: nop

    after_0:
    // 0x801072F4: bne         $v0, $zero, L_80107304
    if (ctx->r2 != 0) {
        // 0x801072F8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80107304;
    }
    // 0x801072F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801072FC: b           L_80107310
    // 0x80107300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80107310;
    // 0x80107300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80107304:
    // 0x80107304: lh          $v0, 0xA($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XA);
    // 0x80107308: xori        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 ^ 0X4;
    // 0x8010730C: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
L_80107310:
    // 0x80107310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107318: jr          $ra
    // 0x8010731C: nop

    return;
    // 0x8010731C: nop

;}
RECOMP_FUNC void func_80098778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009877C: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80098780: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80098784: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80098788: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009878C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80098790: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80098794: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80098798: jal         0x80098658
    // 0x8009879C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_80098658(rdram, ctx);
        goto after_0;
    // 0x8009879C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x800987A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800987A4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800987A8: lw          $t9, 0xE0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XE0);
    // 0x800987AC: sb          $t8, 0x2E($t9)
    MEM_B(0X2E, ctx->r25) = ctx->r24;
    // 0x800987B0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800987B4: lw          $t0, 0xE0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XE0);
    // 0x800987B8: swc1        $f4, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f4.u32l;
    // 0x800987BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800987C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800987C4: jr          $ra
    // 0x800987C8: nop

    return;
    // 0x800987C8: nop

;}
RECOMP_FUNC void _suegg_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3E0: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3E0);
    return;
    // 0x8008A3E4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void chstatuebossbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1424, 0X738) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x738
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1424, 0X738));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x738
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1424, 0X738));
;}
RECOMP_FUNC void _sucoasterfly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089ED8: syscall     813
    recomp_syscall_handler(rdram, ctx, 0x80089ED8);
    return;
    // 0x80089EDC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
