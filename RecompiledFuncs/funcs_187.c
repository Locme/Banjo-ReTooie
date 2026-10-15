#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F424C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F424C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F4250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4254: lw          $t6, 0x17C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X17C);
    // 0x800F4258: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800F425C: bne         $t6, $zero, L_800F426C
    if (ctx->r14 != 0) {
        // 0x800F4260: nop
    
            goto L_800F426C;
    }
    // 0x800F4260: nop

    // 0x800F4264: b           L_800F4344
    // 0x800F4268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4344;
    // 0x800F4268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F426C:
    // 0x800F426C: jal         0x8009E674
    // 0x800F4270: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x800F4270: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F4274: beq         $v0, $zero, L_800F4284
    if (ctx->r2 == 0) {
        // 0x800F4278: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800F4284;
    }
    // 0x800F4278: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800F427C: b           L_800F4344
    // 0x800F4280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4344;
    // 0x800F4280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F4284:
    // 0x800F4284: jal         0x8009E674
    // 0x800F4288: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    func_8009E674(rdram, ctx);
        goto after_1;
    // 0x800F4288: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    after_1:
    // 0x800F428C: beq         $v0, $zero, L_800F429C
    if (ctx->r2 == 0) {
        // 0x800F4290: nop
    
            goto L_800F429C;
    }
    // 0x800F4290: nop

    // 0x800F4294: b           L_800F4344
    // 0x800F4298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4344;
    // 0x800F4298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F429C:
    // 0x800F429C: jal         0x8008E124
    // 0x800F42A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8008E124(rdram, ctx);
        goto after_2;
    // 0x800F42A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800F42A4: beq         $v0, $zero, L_800F42B4
    if (ctx->r2 == 0) {
        // 0x800F42A8: nop
    
            goto L_800F42B4;
    }
    // 0x800F42A8: nop

    // 0x800F42AC: b           L_800F4344
    // 0x800F42B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4344;
    // 0x800F42B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F42B4:
    // 0x800F42B4: jal         0x8008E974
    // 0x800F42B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8008E974(rdram, ctx);
        goto after_3;
    // 0x800F42B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x800F42BC: bne         $v0, $zero, L_800F42CC
    if (ctx->r2 != 0) {
        // 0x800F42C0: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_800F42CC;
    }
    // 0x800F42C0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800F42C4: b           L_800F4344
    // 0x800F42C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4344;
    // 0x800F42C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F42CC:
    // 0x800F42CC: jal         0x800F8004
    // 0x800F42D0: lw          $a0, 0x184($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X184);
    func_800F8004(rdram, ctx);
        goto after_4;
    // 0x800F42D0: lw          $a0, 0x184($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X184);
    after_4:
    // 0x800F42D4: beq         $v0, $zero, L_800F42E4
    if (ctx->r2 == 0) {
        // 0x800F42D8: nop
    
            goto L_800F42E4;
    }
    // 0x800F42D8: nop

    // 0x800F42DC: b           L_800F4344
    // 0x800F42E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4344;
    // 0x800F42E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F42E4:
    // 0x800F42E4: jal         0x8008DAA8
    // 0x800F42E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8008DAA8(rdram, ctx);
        goto after_5;
    // 0x800F42E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x800F42EC: bnel        $v0, $zero, L_800F4344
    if (ctx->r2 != 0) {
        // 0x800F42F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F4344;
    }
    goto skip_0;
    // 0x800F42F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800F42F4: jal         0x800F54E4
    // 0x800F42F8: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x800F42F8: nop

    after_6:
    // 0x800F42FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F4300: beq         $v0, $at, L_800F4340
    if (ctx->r2 == ctx->r1) {
        // 0x800F4304: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800F4340;
    }
    // 0x800F4304: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F4308: jal         0x800F5410
    // 0x800F430C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800F5410(rdram, ctx);
        goto after_7;
    // 0x800F430C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_7:
    // 0x800F4310: xori        $t8, $v0, 0x11
    ctx->r24 = ctx->r2 ^ 0X11;
    // 0x800F4314: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800F4318: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800F431C: jal         0x800F6D24
    // 0x800F4320: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F6D24(rdram, ctx);
        goto after_8;
    // 0x800F4320: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x800F4324: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4328: beql        $t9, $zero, L_800F4344
    if (ctx->r25 == 0) {
        // 0x800F432C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F4344;
    }
    goto skip_1;
    // 0x800F432C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x800F4330: beql        $v0, $zero, L_800F4344
    if (ctx->r2 == 0) {
        // 0x800F4334: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F4344;
    }
    goto skip_2;
    // 0x800F4334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x800F4338: b           L_800F4344
    // 0x800F433C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4344;
    // 0x800F433C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F4340:
    // 0x800F4340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F4344:
    // 0x800F4344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F434C: jr          $ra
    // 0x800F4350: nop

    return;
    // 0x800F4350: nop

;}
RECOMP_FUNC void func_80800164_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080016C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800170: jal         0x8009C908
    // 0x80800174: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_0;
    // 0x80800174: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800178: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080017C: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80800180: jal         0x8009C99C
    // 0x80800184: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_1;
    // 0x80800184: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    after_1:
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080018C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800190: jr          $ra
    // 0x80800194: nop

    return;
    // 0x80800194: nop

;}
RECOMP_FUNC void func_808000D8_chhotwatersteam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E8: lw          $a0, 0x70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70);
    // 0x808000EC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808000F0: srl         $t6, $a0, 25
    ctx->r14 = S32(U32(ctx->r4) >> 25);
    // 0x808000F4: jal         0x800CD08C
    // 0x808000F8: addiu       $a0, $t6, -0x1
    ctx->r4 = ADD32(ctx->r14, -0X1);
    func_800CD08C(rdram, ctx);
        goto after_0;
    // 0x808000F8: addiu       $a0, $t6, -0x1
    ctx->r4 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x808000FC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800104: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800108: jal         0x8080014C
    // 0x8080010C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_8080014C_chhotwatersteam(rdram, ctx);
        goto after_1;
    // 0x8080010C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800110: beq         $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x80800114: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800138;
    }
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: jal         0x80101FDC
    // 0x8080011C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x8080011C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800120: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1428, 0X230) << 16);
    // 0x80800124: lwc1        $f12, 0x230($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1428, 0X230));
    // 0x80800128: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1428, 0X234) << 16);
    // 0x8080012C: jal         0x800DC178
    // 0x80800130: lwc1        $f14, 0x234($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1428, 0X234));
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800130: lwc1        $f14, 0x234($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1428, 0X234));
    after_3:
    // 0x80800134: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800138:
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080013C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800140: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800144: jr          $ra
    // 0x80800148: nop

    return;
    // 0x80800148: nop

;}
RECOMP_FUNC void bskazstill_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808007CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(288, 0X8C4) << 16);
    // 0x808007D0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808007D4: jr          $ra
    // 0x808007D8: lw          $v0, 0x8C4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(288, 0X8C4));
    return;
    // 0x808007D8: lw          $v0, 0x8C4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(288, 0X8C4));
;}
RECOMP_FUNC void func_8080000C_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x8080001C: jal         0x80100094
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800028: jal         0x80800F8C
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F8C_chevilspirit(rdram, ctx);
        goto after_1;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800030: beq         $v0, $zero, L_8080004C
    if (ctx->r2 == 0) {
        // 0x80800034: nop
    
            goto L_8080004C;
    }
    // 0x80800034: nop

    // 0x80800038: jal         0x8008A490
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: jal         0x8010A828
    // 0x80800048: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8010A828(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
L_8080004C:
    // 0x8080004C: jal         0x80801344
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801344_chevilspirit(rdram, ctx);
        goto after_4;
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800054: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800058: jal         0x800EE7F8
    // 0x8080005C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8080005C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_5:
    // 0x80800060: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800064: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800068: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8080006C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800070: jal         0x800DC178
    // 0x80800074: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800074: nop

    after_6:
    // 0x80800078: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x8080007C: jal         0x8008A020
    // 0x80800080: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800080: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800084: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80800088: jal         0x800EA068
    // 0x8080008C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800EA068(rdram, ctx);
        goto after_8;
    // 0x8080008C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_8:
    // 0x80800090: beql        $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x80800094: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F4;
    }
    goto skip_0;
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800098: jal         0x800EA05C
    // 0x8080009C: nop

    func_800EA05C(rdram, ctx);
        goto after_9;
    // 0x8080009C: nop

    after_9:
    // 0x808000A0: addiu       $at, $zero, 0x141
    ctx->r1 = ADD32(0, 0X141);
    // 0x808000A4: bnel        $v0, $at, L_808000D8
    if (ctx->r2 != ctx->r1) {
        // 0x808000A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D8;
    }
    goto skip_1;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808000AC: jal         0x800DA298
    // 0x808000B0: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x808000B0: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_10:
    // 0x808000B4: bne         $v0, $zero, L_808000D4
    if (ctx->r2 != 0) {
        // 0x808000B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D4;
    }
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: jal         0x80102424
    // 0x808000C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808000C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808000C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808000C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000CC: b           L_808000F0
    // 0x808000D0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808000F0;
    // 0x808000D0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808000D4:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000D8:
    // 0x808000D8: jal         0x80102424
    // 0x808000DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x808000DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x808000E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808000E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000E8: nop

    // 0x808000EC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808000F0:
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F4:
    // 0x808000F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_80801320_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801324: sll         $a3, $a1, 2
    ctx->r7 = S32(ctx->r5 << 2);
    // 0x80801328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080132C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801330: subu        $a3, $a3, $a1
    ctx->r7 = SUB32(ctx->r7, ctx->r5);
    // 0x80801334: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x80801338: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8080133C: subu        $a3, $a3, $a1
    ctx->r7 = SUB32(ctx->r7, ctx->r5);
    // 0x80801340: sll         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7 << 3);
    // 0x80801344: addu        $v1, $t7, $a3
    ctx->r3 = ADD32(ctx->r15, ctx->r7);
    // 0x80801348: lw          $t8, 0x4C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4C);
    // 0x8080134C: addiu       $a0, $v1, 0x24
    ctx->r4 = ADD32(ctx->r3, 0X24);
    // 0x80801350: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80801354: bgezl       $t0, L_80801368
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80801358: lw          $a1, 0x30($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X30);
            goto L_80801368;
    }
    goto skip_0;
    // 0x80801358: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    skip_0:
    // 0x8080135C: b           L_808013B0
    // 0x80801360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808013B0;
    // 0x80801360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801364: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
L_80801368:
    // 0x80801368: jal         0x800EFFB4
    // 0x8080136C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800EFFB4(rdram, ctx);
        goto after_0;
    // 0x8080136C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801370: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801374: beq         $v0, $zero, L_808013AC
    if (ctx->r2 == 0) {
        // 0x80801378: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_808013AC;
    }
    // 0x80801378: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8080137C: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    // 0x80801380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801384: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x80801388: lbu         $t3, 0x4C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4C);
    // 0x8080138C: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80801390: sb          $t4, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r12;
    // 0x80801394: lw          $t5, 0x68($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X68);
    // 0x80801398: addu        $v1, $t5, $a3
    ctx->r3 = ADD32(ctx->r13, ctx->r7);
    // 0x8080139C: lbu         $t7, 0x4C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4C);
    // 0x808013A0: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x808013A4: b           L_808013B0
    // 0x808013A8: sb          $t8, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r24;
        goto L_808013B0;
    // 0x808013A8: sb          $t8, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r24;
L_808013AC:
    // 0x808013AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808013B0:
    // 0x808013B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013B8: jr          $ra
    // 0x808013BC: nop

    return;
    // 0x808013BC: nop

;}
RECOMP_FUNC void func_80806000_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806000: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80806004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806008: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080600C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80806010: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x80806014: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80806018: jal         0x80802458
    // 0x8080601C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_80802458_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080601C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80806020: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80806024: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80806028: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080602C: lwc1        $f4, 0x1D4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1D4);
    // 0x80806030: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806034: swc1        $f6, 0x1BC($v1)
    MEM_W(0X1BC, ctx->r3) = ctx->f6.u32l;
    // 0x80806038: jal         0x8009BB00
    // 0x8080603C: swc1        $f4, 0x1B8($v1)
    MEM_W(0X1B8, ctx->r3) = ctx->f4.u32l;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x8080603C: swc1        $f4, 0x1B8($v1)
    MEM_W(0X1B8, ctx->r3) = ctx->f4.u32l;
    after_1:
    // 0x80806040: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80806044: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806048: addiu       $s0, $v1, 0x1B8
    ctx->r16 = ADD32(ctx->r3, 0X1B8);
    // 0x8080604C: jal         0x8009BB18
    // 0x80806050: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    func_8009BB18(rdram, ctx);
        goto after_2;
    // 0x80806050: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x80806054: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80806058: jal         0x8009C984
    // 0x8080605C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_get(rdram, ctx);
        goto after_3;
    // 0x8080605C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80806060: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80806064: jal         0x80013728
    // 0x80806068: sub.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_4;
    // 0x80806068: sub.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f0.fl;
    after_4:
    // 0x8080606C: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80806070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806074: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80806078: jal         0x800EF934
    // 0x8080607C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF934(rdram, ctx);
        goto after_5;
    // 0x8080607C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80806080: jal         0x800EEFFC
    // 0x80806084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEFFC(rdram, ctx);
        goto after_6;
    // 0x80806084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80806088: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8080608C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80806090: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80806094: jal         0x800F0E00
    // 0x80806098: lwc1        $f12, 0x2C($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X2C);
    func_800F0E00(rdram, ctx);
        goto after_7;
    // 0x80806098: lwc1        $f12, 0x2C($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X2C);
    after_7:
    // 0x8080609C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808060A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808060A4: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808060A8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808060AC: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808060B0: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x808060B4: nop

    // 0x808060B8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808060BC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x808060C0: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808060C4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x808060C8: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808060CC: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x808060D0: jal         0x800F2100
    // 0x808060D4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    mlAbsF(rdram, ctx);
        goto after_8;
    // 0x808060D4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    after_8:
    // 0x808060D8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808060DC: jal         0x800F2100
    // 0x808060E0: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    mlAbsF(rdram, ctx);
        goto after_9;
    // 0x808060E0: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    after_9:
    // 0x808060E4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808060E8: jal         0x80013B7C
    // 0x808060EC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_80013B7C(rdram, ctx);
        goto after_10;
    // 0x808060EC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_10:
    // 0x808060F0: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808060F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808060F8: nop

    // 0x808060FC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80806100: nop

    // 0x80806104: bc1fl       L_80806118
    if (!c1cs) {
        // 0x80806108: neg.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
            goto L_80806118;
    }
    goto skip_0;
    // 0x80806108: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    skip_0:
    // 0x8080610C: b           L_8080611C
    // 0x80806110: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
        goto L_8080611C;
    // 0x80806110: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80806114: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
L_80806118:
    // 0x80806118: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_8080611C:
    // 0x8080611C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80806120: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80806124: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80806128: jr          $ra
    // 0x8080612C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8080612C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _gccubesearch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088280: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x80088280);
    return;
    // 0x80088284: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080021C_changlerbossflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80800220: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80800224: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80800228: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8080022C: addiu       $fp, $sp, 0x94
    ctx->r30 = ADD32(ctx->r29, 0X94);
    // 0x80800230: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80800234: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80800238: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8080023C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80800240: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80800244: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80800248: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8080024C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80800250: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800254: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800258: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8080025C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800260: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80800264: jal         0x800F1A88
    // 0x80800268: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800F1A88(rdram, ctx);
        goto after_0;
    // 0x80800268: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x8080026C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800270: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800274: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80800278: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8080027C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800280: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800284: swc1        $f22, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f22.u32l;
    // 0x80800288: jal         0x8001210C
    // 0x8080028C: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x8080028C: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800290: bnel        $v0, $zero, L_80800368
    if (ctx->r2 != 0) {
        // 0x80800294: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80800368;
    }
    goto skip_0;
    // 0x80800294: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x80800298: jal         0x80103EAC
    // 0x8080029C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80103EAC(rdram, ctx);
        goto after_2;
    // 0x8080029C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_2:
    // 0x808002A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1336, 0X470) << 16);
    // 0x808002A4: lwc1        $f10, 0x470($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1336, 0X470));
    // 0x808002A8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808002AC: mul.s       $f26, $f0, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808002B0: jal         0x800B53A4
    // 0x808002B4: nop

    func_800B53A4(rdram, ctx);
        goto after_3;
    // 0x808002B4: nop

    after_3:
    // 0x808002B8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808002BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002C0: jal         0x800BA3FC
    // 0x808002C4: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    func_800BA3FC(rdram, ctx);
        goto after_4;
    // 0x808002C4: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    after_4:
    // 0x808002C8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808002CC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808002D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002D4: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x808002D8: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1336, 0X550) << 16);
    // 0x808002DC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808002E0: addiu       $s3, $s3, 0x550
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1336, 0X550));
    // 0x808002E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808002E8: addiu       $s6, $s7, 0x4
    ctx->r22 = ADD32(ctx->r23, 0X4);
    // 0x808002EC: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x808002F0: addiu       $s2, $sp, 0x88
    ctx->r18 = ADD32(ctx->r29, 0X88);
    // 0x808002F4: addiu       $s0, $sp, 0x7C
    ctx->r16 = ADD32(ctx->r29, 0X7C);
L_808002F8:
    // 0x808002F8: lwc1        $f16, 0x18($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X18);
    // 0x808002FC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80800308: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080030C: jal         0x800EEB9C
    // 0x80800310: nop

    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x80800310: nop

    after_5:
    // 0x80800314: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80800320: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80800324: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    // 0x80800328: jal         0x800EF5A0
    // 0x8080032C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_6;
    // 0x8080032C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800330: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800334: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800338: jal         0x800EE780
    // 0x8080033C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_7;
    // 0x8080033C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80800340: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800344: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800348: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8080034C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800350: jal         0x800BABB8
    // 0x80800354: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800BABB8(rdram, ctx);
        goto after_8;
    // 0x80800354: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_8:
    // 0x80800358: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080035C: bne         $s1, $s4, L_808002F8
    if (ctx->r17 != ctx->r20) {
        // 0x80800360: add.s       $f20, $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
            goto L_808002F8;
    }
    // 0x80800360: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x80800364: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80800368:
    // 0x80800368: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8080036C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800370: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800374: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800378: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8080037C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80800380: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80800384: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80800388: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8080038C: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80800390: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80800394: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80800398: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8080039C: jr          $ra
    // 0x808003A0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x808003A0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80800080_chbonfirecavern(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800084: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800088: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x8080008C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800090: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800094: beq         $a1, $at, L_808000DC
    if (ctx->r5 == ctx->r1) {
        // 0x80800098: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_808000DC;
    }
    // 0x80800098: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8080009C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808000A0: bne         $a1, $at, L_80800168
    if (ctx->r5 != ctx->r1) {
        // 0x808000A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800168;
    }
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: lhu         $t6, 0x18($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X18);
    // 0x808000AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000B0: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x808000B4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808000B8: beql        $t7, $zero, L_808000CC
    if (ctx->r15 == 0) {
        // 0x808000BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000CC;
    }
    goto skip_0;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000C0: jal         0x8010114C
    // 0x808000C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x808000C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000CC:
    // 0x808000CC: jal         0x80101FDC
    // 0x808000D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x808000D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808000D4: b           L_8080017C
    // 0x808000D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080017C;
    // 0x808000D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000DC:
    // 0x808000DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808000E0: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x808000E4: lhu         $t8, 0x18($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X18);
    // 0x808000E8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x808000EC: beql        $t9, $zero, L_80800100
    if (ctx->r25 == 0) {
        // 0x808000F0: lhu         $t0, 0x72($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X72);
            goto L_80800100;
    }
    goto skip_1;
    // 0x808000F0: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x808000F4: jal         0x8010114C
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_2;
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808000FC: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
L_80800100:
    // 0x80800100: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x8080010C: bne         $t1, $at, L_80800144
    if (ctx->r9 != ctx->r1) {
        // 0x80800110: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80800144;
    }
    // 0x80800110: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800114: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1108, 0X2A0) << 16);
    // 0x80800118: addiu       $a2, $a2, 0x2A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1108, 0X2A0));
    // 0x8080011C: jal         0x80089D18
    // 0x80800120: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800120: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_3:
    // 0x80800124: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1108, 0X248) << 16);
    // 0x80800128: addiu       $t2, $t2, 0x248
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1108, 0X248));
    // 0x8080012C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800130: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800138: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080013C: jal         0x800BABB8
    // 0x80800140: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800140: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
L_80800144:
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x80101FDC
    // 0x8080014C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x8080014C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800150: jal         0x8010A570
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800158: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8080015C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800160: b           L_80800178
    // 0x80800164: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_80800178;
    // 0x80800164: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80800168:
    // 0x80800168: jal         0x80086158
    // 0x8080016C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    _chfirefx_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x8080016C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_7:
    // 0x80800170: b           L_80800180
    // 0x80800174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800180;
    // 0x80800174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800178:
    // 0x80800178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080017C:
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800180:
    // 0x80800180: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800184: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void func_800934C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800934C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800934C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800934CC: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x800934D0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800934D4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x800934D8: beq         $a1, $zero, L_800934F4
    if (ctx->r5 == 0) {
        // 0x800934DC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800934F4;
    }
    // 0x800934DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800934E0: jal         0x800DC060
    // 0x800934E4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DC060(rdram, ctx);
        goto after_0;
    // 0x800934E4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800934E8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800934EC: lw          $t7, 0x50($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X50);
    // 0x800934F0: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
L_800934F4:
    // 0x800934F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800934F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800934FC: jr          $ra
    // 0x80093500: nop

    return;
    // 0x80093500: nop

;}
RECOMP_FUNC void func_80800E4C_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E54: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800E58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800E5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800E64: jal         0x80800064
    // 0x80800E68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800064_bssnowball(rdram, ctx);
        goto after_0;
    // 0x80800E68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E70: jal         0x8009D3A8
    // 0x80800E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x80800E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800E78: jal         0x8008DD04
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_2;
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800E80: beq         $v0, $zero, L_80800E8C
    if (ctx->r2 == 0) {
        // 0x80800E84: nop
    
            goto L_80800E8C;
    }
    // 0x80800E84: nop

    // 0x80800E88: addiu       $s1, $zero, 0x180
    ctx->r17 = ADD32(0, 0X180);
L_80800E8C:
    // 0x80800E8C: jal         0x8009BB00
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800E94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E9C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800EA0: nop

    // 0x80800EA4: bc1f        L_80800EB0
    if (!c1cs) {
        // 0x80800EA8: nop
    
            goto L_80800EB0;
    }
    // 0x80800EA8: nop

    // 0x80800EAC: addiu       $s1, $zero, 0x17E
    ctx->r17 = ADD32(0, 0X17E);
L_80800EB0:
    // 0x80800EB0: jal         0x8080010C
    // 0x80800EB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080010C_bssnowball(rdram, ctx);
        goto after_4;
    // 0x80800EB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EBC: jal         0x800A02DC
    // 0x80800EC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A02DC(rdram, ctx);
        goto after_5;
    // 0x80800EC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80800EC4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800EC8: jal         0x808002F8
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bssnowball_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED4: jal         0x8009E5C8
    // 0x80800ED8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80800ED8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80800EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EE0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800EE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800EE8: jr          $ra
    // 0x80800EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8080086C_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080086C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800874: lw          $a1, 0x18($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X18);
    // 0x80800878: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080087C: beq         $a1, $zero, L_80800894
    if (ctx->r5 == 0) {
        // 0x80800880: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800894;
    }
    // 0x80800880: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800884: jal         0x800C8B84
    // 0x80800888: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x80800888: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080088C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800890: sw          $zero, 0x18($a2)
    MEM_W(0X18, ctx->r6) = 0;
L_80800894:
    // 0x80800894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080089C: jr          $ra
    // 0x808008A0: nop

    return;
    // 0x808008A0: nop

;}
RECOMP_FUNC void func_8080009C_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A4: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x808000A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808000B4: jal         0x8009FFD8
    // 0x808000B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_0;
    // 0x808000B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void func_8080024C_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800254: jal         0x8009EF34
    // 0x80800258: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getY(rdram, ctx);
        goto after_0;
    // 0x80800258: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080025C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800260: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800264: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800268: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080026C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800270: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x80800274: bc1fl       L_808002B8
    if (!c1cs) {
        // 0x80800278: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_808002B8;
    }
    goto skip_0;
    // 0x80800278: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x8080027C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800280: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800284: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800288: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080028C: lui         $a3, 0x4389
    ctx->r7 = S32(0X4389 << 16);
    // 0x80800290: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800294: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800298: jal         0x800F10B4
    // 0x8080029C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x8080029C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x808002A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002A4: jal         0x8009BF5C
    // 0x808002A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8009BF5C(rdram, ctx);
        goto after_2;
    // 0x808002A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808002AC: b           L_808002D4
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002D4;
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_808002B8:
    // 0x808002B8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002BC: jal         0x800F10B4
    // 0x808002C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808002C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x808002C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002C8: jal         0x8009BF5C
    // 0x808002CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8009BF5C(rdram, ctx);
        goto after_4;
    // 0x808002CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808002D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002D4:
    // 0x808002D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void bareact_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: lw          $t6, 0xEC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XEC);
    // 0x80800078: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8080007C: jr          $ra
    // 0x80800080: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    return;
    // 0x80800080: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
;}
RECOMP_FUNC void func_8009EAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EAA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EAA4: jr          $ra
    // 0x8009EAA8: sb          $a0, 0x7077($at)
    MEM_B(0X7077, ctx->r1) = ctx->r4;
    return;
    // 0x8009EAA8: sb          $a0, 0x7077($at)
    MEM_B(0X7077, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800D5B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5B34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D5B38: addiu       $v0, $v0, -0x481A
    ctx->r2 = ADD32(ctx->r2, -0X481A);
    // 0x800D5B3C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800D5B40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D5B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5B48: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D5B4C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800D5B50: jal         0x800D5AB4
    // 0x800D5B54: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_800D5AB4(rdram, ctx);
        goto after_0;
    // 0x800D5B54: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x800D5B58: bgez        $v0, L_800D5B68
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D5B5C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D5B68;
    }
    // 0x800D5B5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D5B60: b           L_800D5D60
    // 0x800D5B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D5D60;
    // 0x800D5B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D5B68:
    // 0x800D5B68: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D5B6C: lbu         $t7, -0x481C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X481C);
    // 0x800D5B70: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D5B74: addiu       $t8, $t8, 0x79E0
    if (tooie_more_memory()) ctx->r24 = ADD32(ctx->r24, 0X79E0); else ctx->r24 = ADD32(ctx->r24, -0X49A8);
    // 0x800D5B78: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D5B7C: beq         $at, $zero, L_800D5BA4
    if (ctx->r1 == 0) {
        // 0x800D5B80: addu        $v1, $a0, $t8
        ctx->r3 = ADD32(ctx->r4, ctx->r24);
            goto L_800D5BA4;
    }
    // 0x800D5B80: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x800D5B84: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800D5B88: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x800D5B8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D5B90: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800D5B94: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x800D5B98: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800D5B9C: b           L_800D5D60
    // 0x800D5BA0: lw          $v0, 0x7AD0($v0)
    if (tooie_more_memory()) ctx->r2 = MEM_W(ctx->r2, 0X7AD0); else ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
        goto L_800D5D60;
    // 0x800D5BA0: lw          $v0, 0x7AD0($v0)
    if (tooie_more_memory()) ctx->r2 = MEM_W(ctx->r2, 0X7AD0); else ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
L_800D5BA4:
    // 0x800D5BA4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800D5BA8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800D5BAC: lw          $t3, -0x4700($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4700);
    // 0x800D5BB0: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800D5BB4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5BB8: addiu       $a1, $a1, -0x4BC0
    ctx->r5 = ADD32(ctx->r5, -0X4BC0);
    // 0x800D5BBC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800D5BC0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800D5BC4: jal         0x8001E210
    // 0x800D5BC8: addu        $a0, $t3, $t2
    ctx->r4 = ADD32(ctx->r11, ctx->r10);
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x800D5BC8: addu        $a0, $t3, $t2
    ctx->r4 = ADD32(ctx->r11, ctx->r10);
    after_1:
    // 0x800D5BCC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800D5BD0: lw          $t4, -0x4BC0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4BC0);
    // 0x800D5BD4: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x800D5BD8: bne         $t5, $zero, L_800D5BF4
    if (ctx->r13 != 0) {
        // 0x800D5BDC: nop
    
            goto L_800D5BF4;
    }
    // 0x800D5BDC: nop

    // 0x800D5BE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D5BE4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800D5BE8: bne         $t6, $zero, L_800D5BF4
    if (ctx->r14 != 0) {
        // 0x800D5BEC: nop
    
            goto L_800D5BF4;
    }
    // 0x800D5BEC: nop

    // 0x800D5BF0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800D5BF4:
    if (tooie_asset_replace(rdram, ctx)) goto L_800D5D0C;
    // 0x800D5BF4: jal         0x800E4AF0
    // 0x800D5BF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800E4AF0(rdram, ctx);
        goto after_2;
    // 0x800D5BF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x800D5BFC: beq         $v0, $zero, L_800D5C14
    if (ctx->r2 == 0) {
        // 0x800D5C00: nop
    
            goto L_800D5C14;
    }
    // 0x800D5C00: nop

    // 0x800D5C04: jal         0x800E4BF4
    // 0x800D5C08: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800E4BF4(rdram, ctx);
        goto after_3;
    // 0x800D5C08: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800D5C0C: b           L_800D5D0C
    // 0x800D5C10: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800D5D0C;
    // 0x800D5C10: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800D5C14:
    // 0x800D5C14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D5C18: lw          $v0, -0x4BC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BC0);
    // 0x800D5C1C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800D5C20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800D5C24: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x800D5C28: bne         $t8, $at, L_800D5C44
    if (ctx->r24 != ctx->r1) {
        // 0x800D5C2C: sll         $t9, $v0, 26
        ctx->r25 = S32(ctx->r2 << 26);
            goto L_800D5C44;
    }
    // 0x800D5C2C: sll         $t9, $v0, 26
    ctx->r25 = S32(ctx->r2 << 26);
    // 0x800D5C30: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5C34: jal         0x800888A8
    // 0x800D5C38: addiu       $a1, $a1, -0x4818
    ctx->r5 = ADD32(ctx->r5, -0X4818);
    _gldbDll_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x800D5C38: addiu       $a1, $a1, -0x4818
    ctx->r5 = ADD32(ctx->r5, -0X4818);
    after_4:
    // 0x800D5C3C: b           L_800D5D0C
    // 0x800D5C40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800D5D0C;
    // 0x800D5C40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800D5C44:
    // 0x800D5C44: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x800D5C48: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800D5C4C: beq         $t1, $zero, L_800D5C6C
    if (ctx->r9 == 0) {
        // 0x800D5C50: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800D5C6C;
    }
    // 0x800D5C50: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800D5C54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800D5C58: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800D5C5C: jal         0x800E6950
    // 0x800D5C60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800E6950(rdram, ctx);
        goto after_5;
    // 0x800D5C60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x800D5C64: b           L_800D5D0C
    // 0x800D5C68: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800D5D0C;
    // 0x800D5C68: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800D5C6C:
    // 0x800D5C6C: lw          $t2, -0x4700($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4700);
    // 0x800D5C70: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800D5C74: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5C78: addiu       $a1, $a1, -0x4BBC
    ctx->r5 = ADD32(ctx->r5, -0X4BBC);
    // 0x800D5C7C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x800D5C80: jal         0x8001E210
    // 0x800D5C84: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    rom_read_word(rdram, ctx);
        goto after_6;
    // 0x800D5C84: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_6:
    // 0x800D5C88: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800D5C8C: lw          $t4, -0x4700($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4700);
    // 0x800D5C90: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800D5C94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5C98: addiu       $a1, $a1, -0x4BC0
    ctx->r5 = ADD32(ctx->r5, -0X4BC0);
    // 0x800D5C9C: jal         0x8001E210
    // 0x800D5CA0: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    rom_read_word(rdram, ctx);
        goto after_7;
    // 0x800D5CA0: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_7:
    // 0x800D5CA4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D5CA8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D5CAC: lw          $t8, -0x4BC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BC0);
    // 0x800D5CB0: lw          $t6, -0x4BBC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BBC);
    // 0x800D5CB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5CB8: srl         $t9, $t8, 6
    ctx->r25 = S32(U32(ctx->r24) >> 6);
    // 0x800D5CBC: srl         $t7, $t6, 6
    ctx->r15 = S32(U32(ctx->r14) >> 6);
    // 0x800D5CC0: subu        $a2, $t7, $t9
    ctx->r6 = SUB32(ctx->r15, ctx->r25);
    // 0x800D5CC4: andi        $t0, $a2, 0x1
    ctx->r8 = ctx->r6 & 0X1;
    // 0x800D5CC8: beq         $t0, $zero, L_800D5CD4
    if (ctx->r8 == 0) {
        // 0x800D5CCC: sw          $a2, -0x4818($at)
        MEM_W(-0X4818, ctx->r1) = ctx->r6;
            goto L_800D5CD4;
    }
    // 0x800D5CCC: sw          $a2, -0x4818($at)
    MEM_W(-0X4818, ctx->r1) = ctx->r6;
    // 0x800D5CD0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800D5CD4:
    // 0x800D5CD4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D5CD8: jal         0x8001ACCC
    // 0x800D5CDC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    heap_alloc(rdram, ctx);
        goto after_8;
    // 0x800D5CDC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_8:
    // 0x800D5CE0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800D5CE4: lw          $t2, -0x4BC0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4BC0);
    // 0x800D5CE8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800D5CEC: lw          $t1, -0x4BB8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4BB8);
    // 0x800D5CF0: srl         $t3, $t2, 6
    ctx->r11 = S32(U32(ctx->r10) >> 6);
    // 0x800D5CF4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800D5CF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D5CFC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800D5D00: jal         0x80012F78
    // 0x800D5D04: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    rom_dma_read(rdram, ctx);
        goto after_9;
    // 0x800D5D04: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    after_9:
    // 0x800D5D08: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_800D5D0C:
    // 0x800D5D0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D5D10: addiu       $a0, $a0, -0x481C
    ctx->r4 = ADD32(ctx->r4, -0X481C);
    // 0x800D5D14: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800D5D18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5D1C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D5D20: sb          $v1, -0x481B($at)
    MEM_B(-0X481B, ctx->r1) = ctx->r3;
    // 0x800D5D24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5D28: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800D5D2C: sb          $t4, 0x79E0($at)
    if (tooie_more_memory()) MEM_B(0X79E0, ctx->r1) = ctx->r12; else MEM_B(-0X49A8, ctx->r1) = ctx->r12;
    // 0x800D5D30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5D34: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x800D5D38: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800D5D3C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800D5D40: sw          $a3, 0x7AD0($at)
    if (tooie_more_memory()) MEM_W(0X7AD0, ctx->r1) = ctx->r7; else MEM_W(-0X4BB0, ctx->r1) = ctx->r7;
    // 0x800D5D44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5D48: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800D5D4C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800D5D50: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800D5D54: sh          $t6, 0x7800($at)
    if (tooie_more_memory()) MEM_H(0X7800, ctx->r1) = ctx->r14; else MEM_H(-0X4920, ctx->r1) = ctx->r14;
    // 0x800D5D58: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x800D5D5C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800D5D60:
    // 0x800D5D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5D64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D5D68: jr          $ra
    // 0x800D5D6C: nop

    return;
    // 0x800D5D6C: nop

;}
RECOMP_FUNC void func_80800B80_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800B8C: jal         0x8008FE68
    // 0x80800B90: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008FE68(rdram, ctx);
        goto after_0;
    // 0x80800B90: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800B94: jal         0x80090010
    // 0x80800B98: nop

    func_80090010(rdram, ctx);
        goto after_1;
    // 0x80800B98: nop

    after_1:
    // 0x80800B9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BA0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800BA4: jal         0x800EEB9C
    // 0x80800BA8: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x80800BA8: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_2:
    // 0x80800BAC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800BB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BB4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800BB8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800BBC: jal         0x800EF04C
    // 0x80800BC0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80800BC0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800BC4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800BC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800BCC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800BD0: jal         0x80800AF8
    // 0x80800BD4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80800AF8_chwaspnestgame(rdram, ctx);
        goto after_4;
    // 0x80800BD4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_4:
    // 0x80800BD8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800BDC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800BE0: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x80800BE4: lbu         $t8, 0x75($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X75);
    // 0x80800BE8: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x80800BEC: sb          $t9, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r25;
    // 0x80800BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800BF8: jr          $ra
    // 0x80800BFC: nop

    return;
    // 0x80800BFC: nop

;}
RECOMP_FUNC void func_80801944_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801944: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801948: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080194C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80801950: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801954: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801958: jal         0x80100094
    // 0x8080195C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080195C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801960: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80801964: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80801968: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080196C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80801970: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80801974: bne         $t6, $at, L_808019E0
    if (ctx->r14 != ctx->r1) {
        // 0x80801978: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_808019E0;
    }
    // 0x80801978: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8080197C: beql        $t7, $t6, L_808019E4
    if (ctx->r15 == ctx->r14) {
        // 0x80801980: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808019E4;
    }
    goto skip_0;
    // 0x80801980: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x80801984: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801988: beql        $a0, $zero, L_808019E4
    if (ctx->r4 == 0) {
        // 0x8080198C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808019E4;
    }
    goto skip_1;
    // 0x8080198C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x80801990: jal         0x80106790
    // 0x80801994: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801994: nop

    after_1:
    // 0x80801998: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8080199C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808019A0: jal         0x80089AC8
    // 0x808019A4: lbu         $a1, 0x20($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X20);
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808019A4: lbu         $a1, 0x20($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X20);
    after_2:
    // 0x808019A8: beq         $v0, $zero, L_808019BC
    if (ctx->r2 == 0) {
        // 0x808019AC: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_808019BC;
    }
    // 0x808019AC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x808019B0: lbu         $a0, 0x20($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X20);
    // 0x808019B4: jal         0x800F4F98
    // 0x808019B8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F4F98(rdram, ctx);
        goto after_3;
    // 0x808019B8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
L_808019BC:
    // 0x808019BC: jal         0x80106790
    // 0x808019C0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x808019C0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_4:
    // 0x808019C4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x808019C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808019CC: jal         0x80089AF0
    // 0x808019D0: lbu         $a1, 0x20($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808019D0: lbu         $a1, 0x20($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X20);
    after_5:
    // 0x808019D4: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808019D8: srl         $t1, $v1, 10
    ctx->r9 = S32(U32(ctx->r3) >> 10);
    // 0x808019DC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_808019E0:
    // 0x808019E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_808019E4:
    // 0x808019E4: bne         $v1, $at, L_80801A40
    if (ctx->r3 != ctx->r1) {
        // 0x808019E8: lw          $t2, 0x44($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X44);
            goto L_80801A40;
    }
    // 0x808019E8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x808019EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808019F0: bnel        $t2, $at, L_80801A44
    if (ctx->r10 != ctx->r1) {
        // 0x808019F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A44;
    }
    goto skip_2;
    // 0x808019F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808019F8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x808019FC: addiu       $at, $zero, 0x253
    ctx->r1 = ADD32(0, 0X253);
    // 0x80801A00: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80801A04: lw          $t4, 0x24($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X24);
    // 0x80801A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A0C: srl         $t5, $t4, 22
    ctx->r13 = S32(U32(ctx->r12) >> 22);
    // 0x80801A10: bne         $t5, $at, L_80801A40
    if (ctx->r13 != ctx->r1) {
        // 0x80801A14: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80801A40;
    }
    // 0x80801A14: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80801A18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801A1C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801A20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801A24: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
    // 0x80801A28: jal         0x80089CA8
    // 0x80801A2C: swc1        $f6, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f6.u32l;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80801A2C: swc1        $f6, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f6.u32l;
    after_6:
    // 0x80801A30: jal         0x808024F8
    // 0x80801A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808024F8_chstoneballcontrol(rdram, ctx);
        goto after_7;
    // 0x80801A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801A38: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80801A3C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_80801A40:
    // 0x80801A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801A44:
    // 0x80801A44: jal         0x80101FDC
    // 0x80801A48: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80801A48: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_8:
    // 0x80801A4C: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80801A50: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801A54: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80801A58: bnel        $t9, $at, L_80801AF0
    if (ctx->r25 != ctx->r1) {
        // 0x80801A5C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801AF0;
    }
    goto skip_3;
    // 0x80801A5C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x80801A60: jal         0x808024F8
    // 0x80801A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808024F8_chstoneballcontrol(rdram, ctx);
        goto after_9;
    // 0x80801A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801A68: jal         0x80089CA8
    // 0x80801A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80801A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801A70: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801A74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801A78: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801A7C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1608, 0X511C) << 16);
    // 0x80801A80: addiu       $t0, $zero, 0x7D
    ctx->r8 = ADD32(0, 0X7D);
    // 0x80801A84: addiu       $t1, $zero, 0xFA
    ctx->r9 = ADD32(0, 0XFA);
    // 0x80801A88: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80801A8C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80801A90: addiu       $a2, $a2, 0x511C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1608, 0X511C));
    // 0x80801A94: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801A98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801A9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801AA0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80801AA4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80801AA8: jal         0x800B4470
    // 0x80801AAC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B4470(rdram, ctx);
        goto after_11;
    // 0x80801AAC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80801AB0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80801AB4: addiu       $at, $zero, 0x254
    ctx->r1 = ADD32(0, 0X254);
    // 0x80801AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801ABC: lw          $v0, 0x24($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X24);
    // 0x80801AC0: srl         $t3, $v0, 22
    ctx->r11 = S32(U32(ctx->r2) >> 22);
    // 0x80801AC4: beq         $t3, $at, L_80801AE4
    if (ctx->r11 == ctx->r1) {
        // 0x80801AC8: addiu       $at, $zero, 0x267
        ctx->r1 = ADD32(0, 0X267);
            goto L_80801AE4;
    }
    // 0x80801AC8: addiu       $at, $zero, 0x267
    ctx->r1 = ADD32(0, 0X267);
    // 0x80801ACC: bne         $t3, $at, L_80801AEC
    if (ctx->r11 != ctx->r1) {
        // 0x80801AD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801AEC;
    }
    // 0x80801AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AD4: jal         0x80802588
    // 0x80801AD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802588_chstoneballcontrol(rdram, ctx);
        goto after_12;
    // 0x80801AD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80801ADC: b           L_80801AF0
    // 0x80801AE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80801AF0;
    // 0x80801AE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80801AE4:
    // 0x80801AE4: jal         0x80802588
    // 0x80801AE8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80802588_chstoneballcontrol(rdram, ctx);
        goto after_13;
    // 0x80801AE8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
L_80801AEC:
    // 0x80801AEC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80801AF0:
    // 0x80801AF0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80801AF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801AF8: jr          $ra
    // 0x80801AFC: nop

    return;
    // 0x80801AFC: nop

;}
RECOMP_FUNC void func_8009E97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E97C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E980: jr          $ra
    // 0x8009E984: lwc1        $f0, 0x7040($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7040);
    return;
    // 0x8009E984: lwc1        $f0, 0x7040($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7040);
;}
RECOMP_FUNC void _bskazstilt_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836E8: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836E8);
    return;
    // 0x800836EC: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void anctrl_setIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AED4: jr          $ra
    // 0x8008AED8: sh          $a1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r5;
    return;
    // 0x8008AED8: sh          $a1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void bsbwhirl_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A70: jal         0x8008CABC
    // 0x80800A74: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800A74: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800A78: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800A7C: jal         0x80800200
    // 0x80800A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800200_bsbwhirl(rdram, ctx);
        goto after_1;
    // 0x80800A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A84: jal         0x80800114
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800114_bsbwhirl(rdram, ctx);
        goto after_2;
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A90: jal         0x8009BB24
    // 0x80800A94: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_3;
    // 0x80800A94: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A9C: jal         0x80091A30
    // 0x80800AA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_4;
    // 0x80800AA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x80800AA4: beq         $v0, $zero, L_80800ACC
    if (ctx->r2 == 0) {
        // 0x80800AA8: lwc1        $f6, 0x28($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800ACC;
    }
    // 0x80800AA8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800AAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800AB0: nop

    // 0x80800AB4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800AB8: nop

    // 0x80800ABC: bc1fl       L_80800AD0
    if (!c1cs) {
        // 0x80800AC0: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_80800AD0;
    }
    goto skip_0;
    // 0x80800AC0: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x80800AC4: jal         0x8009BC6C
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_5;
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80800ACC:
    // 0x80800ACC: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_80800AD0:
    // 0x80800AD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD8: beq         $v0, $zero, L_80800AF8
    if (ctx->r2 == 0) {
        // 0x80800ADC: nop
    
            goto L_80800AF8;
    }
    // 0x80800ADC: nop

    // 0x80800AE0: beq         $v0, $at, L_80800B3C
    if (ctx->r2 == ctx->r1) {
        // 0x80800AE4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800B3C;
    }
    // 0x80800AE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AE8: beq         $v0, $at, L_80800B74
    if (ctx->r2 == ctx->r1) {
        // 0x80800AEC: nop
    
            goto L_80800B74;
    }
    // 0x80800AEC: nop

    // 0x80800AF0: b           L_80800B9C
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B9C;
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AF8:
    // 0x80800AF8: jal         0x8008DF8C
    // 0x80800AFC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_6;
    // 0x80800AFC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_6:
    // 0x80800B00: beq         $v0, $zero, L_80800B98
    if (ctx->r2 == 0) {
        // 0x80800B04: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800B98;
    }
    // 0x80800B04: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800B08: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800B0C: jal         0x8008B1D4
    // 0x80800B10: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_7;
    // 0x80800B10: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x80800B14: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800B18: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800B1C: jal         0x8008B1BC
    // 0x80800B20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_8;
    // 0x80800B20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x80800B24: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800B28: jal         0x8008B134
    // 0x80800B2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_9;
    // 0x80800B2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800B30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800B34: b           L_80800B98
    // 0x80800B38: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800B98;
    // 0x80800B38: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800B3C:
    // 0x80800B3C: jal         0x8008E35C
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_10;
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800B44: beq         $v0, $zero, L_80800B50
    if (ctx->r2 == 0) {
        // 0x80800B48: addiu       $t7, $zero, 0x2D
        ctx->r15 = ADD32(0, 0X2D);
            goto L_80800B50;
    }
    // 0x80800B48: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x80800B4C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80800B50:
    // 0x80800B50: jal         0x8008E078
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_11;
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800B58: beq         $v0, $zero, L_80800B98
    if (ctx->r2 == 0) {
        // 0x80800B5C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80800B98;
    }
    // 0x80800B5C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80800B60: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x80800B64: jal         0x8009FE58
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_12;
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800B6C: b           L_80800B9C
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B9C;
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B74:
    // 0x80800B74: jal         0x8008B324
    // 0x80800B78: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_13;
    // 0x80800B78: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_13:
    // 0x80800B7C: beq         $v0, $zero, L_80800B8C
    if (ctx->r2 == 0) {
        // 0x80800B80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B8C;
    }
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B84: addiu       $t9, $zero, 0x1B
    ctx->r25 = ADD32(0, 0X1B);
    // 0x80800B88: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800B8C:
    // 0x80800B8C: jal         0x808003A8
    // 0x80800B90: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_808003A8_bsbwhirl(rdram, ctx);
        goto after_14;
    // 0x80800B90: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_14:
    // 0x80800B94: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80800B98:
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B9C:
    // 0x80800B9C: jal         0x80800430
    // 0x80800BA0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80800430_bsbwhirl(rdram, ctx);
        goto after_15;
    // 0x80800BA0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_15:
    // 0x80800BA4: jal         0x80800008
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_bsbwhirl(rdram, ctx);
        goto after_16;
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800BAC: jal         0x8008DA24
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DA24(rdram, ctx);
        goto after_17;
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800BB4: beq         $v0, $zero, L_80800BC0
    if (ctx->r2 == 0) {
        // 0x80800BB8: addiu       $t0, $zero, 0xA8
        ctx->r8 = ADD32(0, 0XA8);
            goto L_80800BC0;
    }
    // 0x80800BB8: addiu       $t0, $zero, 0xA8
    ctx->r8 = ADD32(0, 0XA8);
    // 0x80800BBC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80800BC0:
    // 0x80800BC0: jal         0x8008E35C
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_18;
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800BC8: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800BCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BD8;
    }
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD0: addiu       $t1, $zero, 0x4C
    ctx->r9 = ADD32(0, 0X4C);
    // 0x80800BD4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80800BD8:
    // 0x80800BD8: jal         0x8009E5C8
    // 0x80800BDC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x80800BDC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_19:
    // 0x80800BE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800BEC: jr          $ra
    // 0x80800BF0: nop

    return;
    // 0x80800BF0: nop

;}
RECOMP_FUNC void func_800C3920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3924: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3928: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C392C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3930: bne         $t6, $zero, L_800C3940
    if (ctx->r14 != 0) {
        // 0x800C3934: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C3940;
    }
    // 0x800C3934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3938: b           L_800C394C
    // 0x800C393C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C394C;
    // 0x800C393C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C3940:
    // 0x800C3940: jal         0x800C1414
    // 0x800C3944: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3944: nop

    after_0:
    // 0x800C3948: lh          $v0, 0x5A($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5A);
L_800C394C:
    // 0x800C394C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3954: jr          $ra
    // 0x800C3958: nop

    return;
    // 0x800C3958: nop

;}
RECOMP_FUNC void func_80800214_chboggykidshome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800218: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080021C: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800220: addiu       $at, $zero, 0x34E
    ctx->r1 = ADD32(0, 0X34E);
    // 0x80800224: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800228: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x8080022C: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80800230: beq         $t7, $at, L_80800298
    if (ctx->r15 == ctx->r1) {
        // 0x80800234: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1396, 0X590) << 16);
            goto L_80800298;
    }
    // 0x80800234: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1396, 0X590) << 16);
    // 0x80800238: addiu       $at, $zero, 0x3E4
    ctx->r1 = ADD32(0, 0X3E4);
    // 0x8080023C: beq         $t7, $at, L_80800274
    if (ctx->r15 == ctx->r1) {
        // 0x80800240: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_80800274;
    }
    // 0x80800240: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800244: addiu       $at, $zero, 0x41D
    ctx->r1 = ADD32(0, 0X41D);
    // 0x80800248: bne         $t7, $at, L_808002B0
    if (ctx->r15 != ctx->r1) {
        // 0x8080024C: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_808002B0;
    }
    // 0x8080024C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800250: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1396, 0X570) << 16);
    // 0x80800254: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1396, 0X3C0) << 16);
    // 0x80800258: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8080025C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800260: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1396, 0X3C0));
    // 0x80800264: jal         0x8008A1F0
    // 0x80800268: addiu       $a2, $a2, 0x570
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1396, 0X570));
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800268: addiu       $a2, $a2, 0x570
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1396, 0X570));
    after_0:
    // 0x8080026C: b           L_808002B4
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002B4;
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800274:
    // 0x80800274: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1396, 0X580) << 16);
    // 0x80800278: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1396, 0X3E8) << 16);
    // 0x8080027C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80800280: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800284: addiu       $a3, $a3, 0x3E8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1396, 0X3E8));
    // 0x80800288: jal         0x8008A1F0
    // 0x8080028C: addiu       $a2, $a2, 0x580
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1396, 0X580));
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080028C: addiu       $a2, $a2, 0x580
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1396, 0X580));
    after_1:
    // 0x80800290: b           L_808002B4
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002B4;
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800298:
    // 0x80800298: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1396, 0X408) << 16);
    // 0x8080029C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x808002A0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808002A4: addiu       $a3, $a3, 0x408
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1396, 0X408));
    // 0x808002A8: jal         0x8008A1F0
    // 0x808002AC: addiu       $a2, $a2, 0x590
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1396, 0X590));
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808002AC: addiu       $a2, $a2, 0x590
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1396, 0X590));
    after_2:
L_808002B0:
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002B4:
    // 0x808002B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002B8: jr          $ra
    // 0x808002BC: nop

    return;
    // 0x808002BC: nop

;}
RECOMP_FUNC void func_800AE0E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE0E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE0EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800AE0F0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800AE0F4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AE0F8: beq         $a0, $zero, L_800AE110
    if (ctx->r4 == 0) {
        // 0x800AE0FC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE110;
    }
    // 0x800AE0FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE100: jal         0x800AE080
    // 0x800AE104: nop

    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x800AE104: nop

    after_0:
    // 0x800AE108: b           L_800AE114
    // 0x800AE10C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
        goto L_800AE114;
    // 0x800AE10C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800AE110:
    // 0x800AE110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AE114:
    // 0x800AE114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE11C: jr          $ra
    // 0x800AE120: nop

    return;
    // 0x800AE120: nop

;}
RECOMP_FUNC void func_80800768_scradar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080076C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800770: jal         0x800F5410
    // 0x80800774: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F5410(rdram, ctx);
        goto after_0;
    // 0x80800774: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800778: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080077C: beq         $v0, $at, L_80800794
    if (ctx->r2 == ctx->r1) {
        // 0x80800780: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80800794;
    }
    // 0x80800780: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800784: bne         $v0, $at, L_8080079C
    if (ctx->r2 != ctx->r1) {
        // 0x80800788: nop
    
            goto L_8080079C;
    }
    // 0x80800788: nop

    // 0x8080078C: b           L_808007C4
    // 0x80800790: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808007C4;
    // 0x80800790: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800794:
    // 0x80800794: b           L_808007C4
    // 0x80800798: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808007C4;
    // 0x80800798: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080079C:
    // 0x8080079C: jal         0x800F53D0
    // 0x808007A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x808007A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808007A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007A8: jal         0x8009E674
    // 0x808007AC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8009E674(rdram, ctx);
        goto after_2;
    // 0x808007AC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_2:
    // 0x808007B0: beql        $v0, $zero, L_808007C4
    if (ctx->r2 == 0) {
        // 0x808007B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808007C4;
    }
    goto skip_0;
    // 0x808007B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808007B8: b           L_808007C4
    // 0x808007BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808007C4;
    // 0x808007BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x808007C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007C4:
    // 0x808007C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007CC: jr          $ra
    // 0x808007D0: nop

    return;
    // 0x808007D0: nop

;}
RECOMP_FUNC void func_80807280_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807280: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80807284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807288: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080728C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80807290: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80807294: jal         0x80100094
    // 0x80807298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080729C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808072A0: addiu       $a0, $v0, 0x88
    ctx->r4 = ADD32(ctx->r2, 0X88);
    // 0x808072A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808072A8: jal         0x8001BBA0
    // 0x808072AC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x808072AC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // 0x808072B0: jal         0x808027F4
    // 0x808072B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808027F4_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x808072B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808072B8: jal         0x80802C0C
    // 0x808072BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80802C0C_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x808072BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808072C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808072C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808072C8: jal         0x80803BE8
    // 0x808072CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x808072CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x808072D0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808072D4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808072D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808072DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808072E0: sh          $t6, 0x7C($v0)
    MEM_H(0X7C, ctx->r2) = ctx->r14;
    // 0x808072E4: swc1        $f4, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->f4.u32l;
    // 0x808072E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808072EC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x808072F0: sh          $t8, 0x7E($v0)
    MEM_H(0X7E, ctx->r2) = ctx->r24;
    // 0x808072F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808072F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808072FC: jr          $ra
    // 0x80807300: nop

    return;
    // 0x80807300: nop

;}
RECOMP_FUNC void func_800C13A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C13A0: lhu         $t6, 0x7C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X7C);
    // 0x800C13A4: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x800C13A8: jr          $ra
    // 0x800C13AC: sh          $t7, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r15;
    return;
    // 0x800C13AC: sh          $t7, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80800D20_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800D2C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800D30: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800D34: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800D38: jal         0x800DA298
    // 0x80800D3C: addiu       $a0, $a0, 0x16E
    ctx->r4 = ADD32(ctx->r4, 0X16E);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800D3C: addiu       $a0, $a0, 0x16E
    ctx->r4 = ADD32(ctx->r4, 0X16E);
    after_0:
    // 0x80800D40: bne         $v0, $zero, L_80800D78
    if (ctx->r2 != 0) {
        // 0x80800D44: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80800D78;
    }
    // 0x80800D44: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D48: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80800D4C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800D50: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800D54: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80800D58: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x80800D5C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80800D60: addiu       $a0, $a0, -0x5A88
    ctx->r4 = ADD32(ctx->r4, -0X5A88);
    // 0x80800D64: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800D68: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800D6C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800D70: jal         0x80086D58
    // 0x80800D74: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800D74: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
L_80800D78:
    // 0x80800D78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800D7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800D80: jr          $ra
    // 0x80800D84: nop

    return;
    // 0x80800D84: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089910: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089910);
    return;
    // 0x80089914: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void ncbaspiral_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080004C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800054: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800058: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x8080005C: jal         0x80111B8C
    // 0x80800060: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_0;
    // 0x80800060: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_0:
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: jal         0x801124D0
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_1;
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: jal         0x80115858
    // 0x80800078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80115858(rdram, ctx);
        goto after_2;
    // 0x80800078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: jal         0x80115870
    // 0x80800084: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80115870(rdram, ctx);
        goto after_3;
    // 0x80800084: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_3:
    // 0x80800088: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x8080008C: jal         0x800EFD24
    // 0x80800090: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x80800090: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x80800094: lw          $t7, 0x48($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X48);
    // 0x80800098: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080009C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_8010649C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010649C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801064A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801064A4: jal         0x801063C0
    // 0x801064A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_801063C0(rdram, ctx);
        goto after_0;
    // 0x801064A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801064AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801064B0: jal         0x800B296C
    // 0x801064B4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    vector_end(rdram, ctx);
        goto after_1;
    // 0x801064B4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x801064B8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801064BC: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x801064C0: jal         0x800B28C4
    // 0x801064C4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_2;
    // 0x801064C4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x801064C8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801064CC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801064D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801064D4: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x801064D8: beq         $at, $zero, L_80106514
    if (ctx->r1 == 0) {
        // 0x801064DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106514;
    }
    // 0x801064DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801064E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801064E4: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
L_801064E8:
    // 0x801064E8: bnel        $v0, $t7, L_80106508
    if (ctx->r2 != ctx->r15) {
        // 0x801064EC: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_80106508;
    }
    goto skip_0;
    // 0x801064EC: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_0:
    // 0x801064F0: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x801064F4: bnel        $a2, $t8, L_80106508
    if (ctx->r6 != ctx->r24) {
        // 0x801064F8: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_80106508;
    }
    goto skip_1;
    // 0x801064F8: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_1:
    // 0x801064FC: b           L_80106518
    // 0x80106500: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
        goto L_80106518;
    // 0x80106500: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80106504: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
L_80106508:
    // 0x80106508: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8010650C: bnel        $at, $zero, L_801064E8
    if (ctx->r1 != 0) {
        // 0x80106510: lh          $t7, 0x4($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X4);
            goto L_801064E8;
    }
    goto skip_2;
    // 0x80106510: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    skip_2:
L_80106514:
    // 0x80106514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80106518:
    // 0x80106518: jr          $ra
    // 0x8010651C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8010651C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _subaddieDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4C8: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4C8);
    return;
    // 0x8008A4CC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bssplitup_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AB0: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AB0);
    return;
    // 0x80083AB4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chloggo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1292, 0X648) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x648
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1292, 0X648));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x648
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1292, 0X648));
;}
RECOMP_FUNC void func_80800154_chintrotext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800154: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800158: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080015C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800160: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800164: jal         0x80100094
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080016C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800170: jal         0x800D9078
    // 0x80800174: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80800174: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800178: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8080017C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800180: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x80800184: lbu         $t7, 0x3F($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3F);
    // 0x80800188: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1120, 0X7A0) << 16);
    // 0x8080018C: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80800190: addiu       $t9, $t9, 0x7A0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1120, 0X7A0));
    // 0x80800194: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80800198: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8080019C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x808001A0: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x808001A4: beq         $at, $zero, L_808003D8
    if (ctx->r1 == 0) {
        // 0x808001A8: lw          $a2, 0xC($v1)
        ctx->r6 = MEM_W(ctx->r3, 0XC);
            goto L_808003D8;
    }
    // 0x808001A8: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    // 0x808001AC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808001B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1120, 0X780) << 16);
    // 0x808001B4: addu        $at, $at, $t2
    gpr jr_addend_808001BC = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x808001B8: lw          $t2, 0x780($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1120, 0X780));
    // 0x808001BC: jr          $t2
    // 0x808001C0: nop

    switch (jr_addend_808001BC >> 2) {
        case 0: goto L_808001C4; break;
        case 1: goto L_808002D4; break;
        case 2: goto L_808002FC; break;
        case 3: goto L_80800368; break;
        case 4: goto L_80800390; break;
        default: switch_error(__func__, 0x808001BC, 0x80800780);
    }
    // 0x808001C0: nop

L_808001C4:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001CC: jal         0x80100094
    // 0x808001D0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808001D0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_2:
    // 0x808001D4: lbu         $v1, 0x3E($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3E);
    // 0x808001D8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808001DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001E0: beq         $v1, $zero, L_80800200
    if (ctx->r3 == 0) {
        // 0x808001E4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800200;
    }
    // 0x808001E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808001E8: beq         $v1, $at, L_80800254
    if (ctx->r3 == ctx->r1) {
        // 0x808001EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800254;
    }
    // 0x808001EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001F0: beq         $v1, $at, L_80800274
    if (ctx->r3 == ctx->r1) {
        // 0x808001F4: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_80800274;
    }
    // 0x808001F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808001F8: b           L_80800298
    // 0x808001FC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
        goto L_80800298;
    // 0x808001FC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
L_80800200:
    // 0x80800200: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80800204: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80800208: addiu       $t4, $zero, 0xE4
    ctx->r12 = ADD32(0, 0XE4);
    // 0x8080020C: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800210: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800214: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800218: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080021C: nop

    // 0x80800220: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800224: mflo        $t3
    ctx->r11 = lo;
    // 0x80800228: subu        $a3, $t4, $t3
    ctx->r7 = SUB32(ctx->r12, ctx->r11);
    // 0x8080022C: sra         $t5, $a3, 1
    ctx->r13 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80800230: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x80800234: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80800238: nop

    // 0x8080023C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800240: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80800244: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800248: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8080024C: b           L_80800298
    // 0x80800250: nop

        goto L_80800298;
    // 0x80800250: nop

L_80800254:
    // 0x80800254: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80800258: addiu       $t8, $zero, 0x72
    ctx->r24 = ADD32(0, 0X72);
    // 0x8080025C: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800260: mflo        $t7
    ctx->r15 = lo;
    // 0x80800264: subu        $a3, $t8, $t7
    ctx->r7 = SUB32(ctx->r24, ctx->r15);
    // 0x80800268: sra         $t9, $a3, 1
    ctx->r25 = S32(SIGNED(ctx->r7) >> 1);
    // 0x8080026C: b           L_80800298
    // 0x80800270: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
        goto L_80800298;
    // 0x80800270: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
L_80800274:
    // 0x80800274: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80800278: addiu       $t1, $zero, 0xE4
    ctx->r9 = ADD32(0, 0XE4);
    // 0x8080027C: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800280: mflo        $t0
    ctx->r8 = lo;
    // 0x80800284: subu        $a3, $t1, $t0
    ctx->r7 = SUB32(ctx->r9, ctx->r8);
    // 0x80800288: sra         $t2, $a3, 1
    ctx->r10 = S32(SIGNED(ctx->r7) >> 1);
    // 0x8080028C: b           L_80800298
    // 0x80800290: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
        goto L_80800298;
    // 0x80800290: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80800294: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
L_80800298:
    // 0x80800298: blez        $a0, L_808002C0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8080029C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808002C0;
    }
    // 0x8080029C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808002A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_808002A4:
    // 0x808002A4: sh          $a0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r4;
    // 0x808002A8: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x808002AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808002B0: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x808002B4: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808002B8: bne         $at, $zero, L_808002A4
    if (ctx->r1 != 0) {
        // 0x808002BC: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_808002A4;
    }
    // 0x808002BC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_808002C0:
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: jal         0x8080051C
    // 0x808002C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080051C_chintrotext(rdram, ctx);
        goto after_3;
    // 0x808002C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808002CC: b           L_808003DC
    // 0x808002D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003DC;
    // 0x808002D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002D4:
    // 0x808002D4: jal         0x800DA544
    // 0x808002D8: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x808002D8: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_4:
    // 0x808002DC: jal         0x800C954C
    // 0x808002E0: nop

    func_800C954C(rdram, ctx);
        goto after_5;
    // 0x808002E0: nop

    after_5:
    // 0x808002E4: bne         $v0, $zero, L_808003D8
    if (ctx->r2 != 0) {
        // 0x808002E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D8;
    }
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002EC: jal         0x8080051C
    // 0x808002F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080051C_chintrotext(rdram, ctx);
        goto after_6;
    // 0x808002F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808002F4: b           L_808003DC
    // 0x808002F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003DC;
    // 0x808002F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002FC:
    // 0x808002FC: jal         0x800DA544
    // 0x80800300: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x80800300: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_7:
    // 0x80800304: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80800308: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080030C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1120, 0X7A0) << 16);
    // 0x80800310: lbu         $t5, 0x3F($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X3F);
    // 0x80800314: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800318: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080031C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80800320: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x80800324: lw          $a2, 0x7A0($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(1120, 0X7A0));
    // 0x80800328: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x8080032C: jal         0x800F12D4
    // 0x80800330: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F12D4(rdram, ctx);
        goto after_8;
    // 0x80800330: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80800334: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800340: jal         0x80089C98
    // 0x80800344: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800344: nop

    after_9:
    // 0x80800348: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: beql        $t7, $zero, L_808003DC
    if (ctx->r15 == 0) {
        // 0x80800354: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003DC;
    }
    goto skip_0;
    // 0x80800354: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800358: jal         0x8080051C
    // 0x8080035C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080051C_chintrotext(rdram, ctx);
        goto after_10;
    // 0x8080035C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x80800360: b           L_808003DC
    // 0x80800364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003DC;
    // 0x80800364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800368:
    // 0x80800368: jal         0x800DA544
    // 0x8080036C: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x8080036C: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_11:
    // 0x80800370: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: beql        $t9, $zero, L_808003DC
    if (ctx->r25 == 0) {
        // 0x8080037C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003DC;
    }
    goto skip_1;
    // 0x8080037C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800380: jal         0x8080051C
    // 0x80800384: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080051C_chintrotext(rdram, ctx);
        goto after_12;
    // 0x80800384: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_12:
    // 0x80800388: b           L_808003DC
    // 0x8080038C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003DC;
    // 0x8080038C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800390:
    // 0x80800390: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800394: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800398: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080039C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003A0: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x808003A4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808003A8: jal         0x800F12D4
    // 0x808003AC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F12D4(rdram, ctx);
        goto after_13;
    // 0x808003AC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_13:
    // 0x808003B0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808003BC: jal         0x80089C98
    // 0x808003C0: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x808003C0: nop

    after_14:
    // 0x808003C4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x808003C8: beql        $t0, $zero, L_808003DC
    if (ctx->r8 == 0) {
        // 0x808003CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003DC;
    }
    goto skip_2;
    // 0x808003CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808003D0: jal         0x800FFAB0
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_15;
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_808003D8:
    // 0x808003D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003DC:
    // 0x808003DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

;}
RECOMP_FUNC void func_8009EA14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EA18: jr          $ra
    // 0x8009EA1C: lwc1        $f0, 0x706C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X706C);
    return;
    // 0x8009EA1C: lwc1        $f0, 0x706C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X706C);
;}
RECOMP_FUNC void func_8008F6B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F6B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008F6BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F6C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008F6C4: jal         0x80084D40
    // 0x8008F6C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _bahold_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x8008F6C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008F6CC: beq         $v0, $zero, L_8008F6E8
    if (ctx->r2 == 0) {
        // 0x8008F6D0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8008F6E8;
    }
    // 0x8008F6D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8008F6D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F6D8: jal         0x80106790
    // 0x8008F6DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8008F6DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8008F6E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F6E4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_8008F6E8:
    // 0x8008F6E8: beq         $a1, $zero, L_8008F718
    if (ctx->r5 == 0) {
        // 0x8008F6EC: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_8008F718;
    }
    // 0x8008F6EC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008F6F0: lw          $t8, 0x6C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X6C);
    // 0x8008F6F4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8008F6F8: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x8008F6FC: srl         $t0, $t9, 20
    ctx->r8 = S32(U32(ctx->r25) >> 20);
    // 0x8008F700: bne         $t6, $t0, L_8008F718
    if (ctx->r14 != ctx->r8) {
        // 0x8008F704: nop
    
            goto L_8008F718;
    }
    // 0x8008F704: nop

    // 0x8008F708: jal         0x80084D48
    // 0x8008F70C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bahold_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x8008F70C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8008F710: b           L_8008F73C
    // 0x8008F714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F73C;
    // 0x8008F714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F718:
    // 0x8008F718: jal         0x8008E9AC
    // 0x8008F71C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008E9AC(rdram, ctx);
        goto after_3;
    // 0x8008F71C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8008F720: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8008F724: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8008F728: addiu       $a0, $a0, -0x9D4
    ctx->r4 = ADD32(ctx->r4, -0X9D4);
    // 0x8008F72C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8008F730: jal         0x80086D38
    // 0x8008F734: lw          $a1, 0x184($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X184);
    _chbaddiesetup_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8008F734: lw          $a1, 0x184($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X184);
    after_4:
    // 0x8008F738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F73C:
    // 0x8008F73C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008F740: jr          $ra
    // 0x8008F744: nop

    return;
    // 0x8008F744: nop

;}
RECOMP_FUNC void func_800F7270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7270: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800F7274: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7278: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F727C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F7280: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F7284: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7288: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F728C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F7290: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800F7294: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F7298: jal         0x8008DEA4
    // 0x800F729C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008DEA4(rdram, ctx);
        goto after_0;
    // 0x800F729C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F72A0: beq         $v0, $zero, L_800F72C8
    if (ctx->r2 == 0) {
        // 0x800F72A4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800F72C8;
    }
    // 0x800F72A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F72A8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800F72AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800F72B0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800F72B4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800F72B8: jal         0x800F7200
    // 0x800F72BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800F7200(rdram, ctx);
        goto after_1;
    // 0x800F72BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x800F72C0: b           L_800F72D0
    // 0x800F72C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800F72D0;
    // 0x800F72C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F72C8:
    // 0x800F72C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F72CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F72D0:
    // 0x800F72D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F72D4: jr          $ra
    // 0x800F72D8: nop

    return;
    // 0x800F72D8: nop

;}
RECOMP_FUNC void chexploder_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808019F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808019F8: jal         0x80100094
    // 0x808019FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808019FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801A00: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A04: sb          $t6, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r14;
    // 0x80801A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A10: jr          $ra
    // 0x80801A14: nop

    return;
    // 0x80801A14: nop

;}
RECOMP_FUNC void func_80800F74_chbounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F7C: lbu         $t6, 0x7B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7B);
    // 0x80800F80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800F84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800F88: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x80800F8C: jal         0x80100074
    // 0x80800F90: sb          $t7, 0x7B($a0)
    MEM_B(0X7B, ctx->r4) = ctx->r15;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800F90: sb          $t7, 0x7B($a0)
    MEM_B(0X7B, ctx->r4) = ctx->r15;
    after_0:
    // 0x80800F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F9C: jr          $ra
    // 0x80800FA0: nop

    return;
    // 0x80800FA0: nop

    // 0x80800FA4: nop

    // 0x80800FA8: nop

    // 0x80800FAC: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804474: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80804478: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB4F0) << 16);
    // 0x8080447C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80804480: jr          $ra
    // 0x80804484: lw          $v0, -0x4B10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB4F0));
    return;
    // 0x80804484: lw          $v0, -0x4B10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB4F0));
;}
RECOMP_FUNC void _chexploder_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866D0: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x800866D0);
    return;
    // 0x800866D4: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_800B7C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7C98: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7C9C: jr          $ra
    // 0x800B7CA0: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
    return;
    // 0x800B7CA0: lw          $v0, -0x7D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D4C);
;}
RECOMP_FUNC void _gcmapsects_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F88: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F88);
    return;
    // 0x80087F8C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_80803DC8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803DC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803DD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80803DD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80803DD8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80803DDC: jal         0x80100094
    // 0x80803DE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803DE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803DE4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80803DE8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80803DEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80803DF0: beq         $a1, $at, L_80803E00
    if (ctx->r5 == ctx->r1) {
        // 0x80803DF4: sb          $t6, 0x4($v0)
        MEM_B(0X4, ctx->r2) = ctx->r14;
            goto L_80803E00;
    }
    // 0x80803DF4: sb          $t6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r14;
    // 0x80803DF8: jal         0x8080041C
    // 0x80803DFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80803DFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80803E00:
    // 0x80803E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803E04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803E08: jr          $ra
    // 0x80803E0C: nop

    return;
    // 0x80803E0C: nop

;}
RECOMP_FUNC void _chexploder_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086670: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x80086670);
    return;
    // 0x80086674: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800000_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $a0, $zero, 0xA37
    ctx->r4 = ADD32(0, 0XA37);
    // 0x8080000C: jal         0x800DA564
    // 0x80800010: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
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
