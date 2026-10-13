#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _glgamestore_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884B8: syscall     688
    recomp_syscall_handler(rdram, ctx, 0x800884B8);
    return;
    // 0x800884BC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080003C_chlightdemon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: lui         $a1, 0x4422
    ctx->r5 = S32(0X4422 << 16);
    // 0x80800048: jal         0x80105A9C
    // 0x8080004C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    func_80105A9C(rdram, ctx);
        goto after_0;
    // 0x8080004C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    after_0:
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void suquiz_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800C58: lw          $t6, 0x7614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7614);
    // 0x80800C5C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80800C60: jr          $ra
    // 0x80800C64: sb          $a1, 0x2A($t7)
    MEM_B(0X2A, ctx->r15) = ctx->r5;
    return;
    // 0x80800C64: sb          $a1, 0x2A($t7)
    MEM_B(0X2A, ctx->r15) = ctx->r5;
;}
RECOMP_FUNC void func_808008F4_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808008FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800900: jal         0x80800238
    // 0x80800904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800238_bsledge(rdram, ctx);
        goto after_0;
    // 0x80800904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800908: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080090C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800914: jal         0x8008CCBC
    // 0x80800918: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80800918: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_1:
    // 0x8080091C: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x80800920: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800928: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080092C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800930: jal         0x8009FFD8
    // 0x80800934: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800934: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080093C: jal         0x80800488
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800488_bsledge(rdram, ctx);
        goto after_3;
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800944: jal         0x8009E710
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_4;
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080094C: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80800950: bne         $v0, $at, L_8080098C
    if (ctx->r2 != ctx->r1) {
        // 0x80800954: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080098C;
    }
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800958: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x8080095C: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800960: addiu       $t7, $zero, 0x6590
    ctx->r15 = ADD32(0, 0X6590);
    // 0x80800964: addiu       $t8, $zero, 0x6590
    ctx->r24 = ADD32(0, 0X6590);
    // 0x80800968: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8080096C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800970: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800974: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080097C: jal         0x8009DEC0
    // 0x80800980: addiu       $a1, $zero, 0x58E
    ctx->r5 = ADD32(0, 0X58E);
    func_8009DEC0(rdram, ctx);
        goto after_5;
    // 0x80800980: addiu       $a1, $zero, 0x58E
    ctx->r5 = ADD32(0, 0X58E);
    after_5:
    // 0x80800984: b           L_808009B8
    // 0x80800988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808009B8;
    // 0x80800988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080098C:
    // 0x8080098C: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800990: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800994: addiu       $t9, $zero, 0x2EE0
    ctx->r25 = ADD32(0, 0X2EE0);
    // 0x80800998: addiu       $t0, $zero, 0x2EE0
    ctx->r8 = ADD32(0, 0X2EE0);
    // 0x8080099C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808009A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808009A4: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808009A8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808009AC: jal         0x8009DEC0
    // 0x808009B0: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    func_8009DEC0(rdram, ctx);
        goto after_6;
    // 0x808009B0: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    after_6:
    // 0x808009B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009B8:
    // 0x808009B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009C0: jr          $ra
    // 0x808009C4: nop

    return;
    // 0x808009C4: nop

;}
RECOMP_FUNC void func_80106138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106138: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010613C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80106140: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80106144: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80106148: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010614C: jal         0x801063C0
    // 0x80106150: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_801063C0(rdram, ctx);
        goto after_0;
    // 0x80106150: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80106154: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80106158: jal         0x800B296C
    // 0x8010615C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    vector_end(rdram, ctx);
        goto after_1;
    // 0x8010615C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x80106160: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80106164: jal         0x800B28C4
    // 0x80106168: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    vector_begin(rdram, ctx);
        goto after_2;
    // 0x80106168: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x8010616C: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x80106170: beq         $at, $zero, L_801061AC
    if (ctx->r1 == 0) {
        // 0x80106174: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_801061AC;
    }
    // 0x80106174: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80106178: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8010617C: addiu       $s2, $s2, 0x4440
    ctx->r18 = ADD32(ctx->r18, 0X4440);
    // 0x80106180: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
L_80106184:
    // 0x80106184: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80106188: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8010618C: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x80106190: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80106194: jalr        $t9
    // 0x80106198: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80106198: nop

    after_3:
    // 0x8010619C: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
    // 0x801061A0: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x801061A4: bnel        $at, $zero, L_80106184
    if (ctx->r1 != 0) {
        // 0x801061A8: lh          $t6, 0x4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X4);
            goto L_80106184;
    }
    goto skip_0;
    // 0x801061A8: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    skip_0:
L_801061AC:
    // 0x801061AC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801061B0: jal         0x801060E4
    // 0x801061B4: lh          $a0, 0x90($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X90);
    func_801060E4(rdram, ctx);
        goto after_4;
    // 0x801061B4: lh          $a0, 0x90($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X90);
    after_4:
    // 0x801061B8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801061BC: sh          $zero, 0x90($t1)
    MEM_H(0X90, ctx->r9) = 0;
    // 0x801061C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801061C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801061C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801061CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801061D0: jr          $ra
    // 0x801061D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801061D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800334_changlerbossbubble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800334: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800338: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8080033C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800340: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800344: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80800348: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1340, 0X668) << 16);
    // 0x8080034C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800350: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800354: addiu       $a2, $a2, 0x668
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1340, 0X668));
    // 0x80800358: jal         0x80089D18
    // 0x8080035C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080035C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800360: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800364: jal         0x800DC128
    // 0x80800368: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80800368: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x8080036C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800370: jal         0x800B53A4
    // 0x80800374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80800374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800378: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080037C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1340, 0X618) << 16);
    // 0x80800380: lwc1        $f20, 0x38($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800384: addiu       $t6, $t6, 0x618
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1340, 0X618));
    // 0x80800388: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080038C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800390: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800394: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800398: jal         0x800BABB8
    // 0x8080039C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x8080039C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_3:
    // 0x808003A0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808003A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003A8: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808003B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808003B8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808003BC: nop

    // 0x808003C0: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x808003C4: jal         0x800BA568
    // 0x808003C8: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    func_800BA568(rdram, ctx);
        goto after_4;
    // 0x808003C8: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    after_4:
    // 0x808003CC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808003D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1340, 0X5B4) << 16);
    // 0x808003D8: lwc1        $f4, 0x5B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1340, 0X5B4));
    // 0x808003DC: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E4: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808003E8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808003EC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808003F0: jal         0x800BA7C4
    // 0x808003F4: nop

    func_800BA7C4(rdram, ctx);
        goto after_5;
    // 0x808003F4: nop

    after_5:
    // 0x808003F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1340, 0X5B8) << 16);
    // 0x808003FC: lwc1        $f8, 0x5B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1340, 0X5B8));
    // 0x80800400: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1340, 0X5BC) << 16);
    // 0x80800404: lwc1        $f16, 0x5BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1340, 0X5BC));
    // 0x80800408: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80800414: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800418: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8080041C: jal         0x800BA7FC
    // 0x80800420: nop

    func_800BA7FC(rdram, ctx);
        goto after_6;
    // 0x80800420: nop

    after_6:
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x800BA22C
    // 0x8080042C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x8080042C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x80800430: jal         0x800FFA88
    // 0x80800434: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x80800434: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_8:
    // 0x80800438: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080043C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800440: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800444: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800448: jr          $ra
    // 0x8080044C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080044C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_808018E8_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808018F4: jal         0x80100094
    // 0x808018F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808018F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808018FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801900: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801904: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801908: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080190C: swc1        $f4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f4.u32l;
    // 0x80801910: lbu         $t7, 0x12F($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X12F);
    // 0x80801914: beql        $t7, $zero, L_80801930
    if (ctx->r15 == 0) {
        // 0x80801918: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80801930;
    }
    goto skip_0;
    // 0x80801918: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x8080191C: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x80801920: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801924: b           L_80801938
    // 0x80801928: swc1        $f6, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f6.u32l;
        goto L_80801938;
    // 0x80801928: swc1        $f6, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f6.u32l;
    // 0x8080192C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80801930:
    // 0x80801930: nop

    // 0x80801934: swc1        $f8, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f8.u32l;
L_80801938:
    // 0x80801938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080193C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801940: jr          $ra
    // 0x80801944: nop

    return;
    // 0x80801944: nop

;}
RECOMP_FUNC void chfactorytoxiccloud_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2300, 0X1568) << 16);
    // 0x808013CC: jr          $ra
    // 0x808013D0: addiu       $v0, $v0, 0x1568
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2300, 0X1568));
    return;
    // 0x808013D0: addiu       $v0, $v0, 0x1568
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2300, 0X1568));
    // 0x808013D4: nop

    // 0x808013D8: nop

    // 0x808013DC: nop

;}
RECOMP_FUNC void _gcgoto_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AB8: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087AB8);
    return;
    // 0x80087ABC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800654_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800654: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080065C: jal         0x80800630
    // 0x80800660: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800630_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x80800660: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800664: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080066C: lh          $t7, 0x1A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1A);
    // 0x80800670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800674: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800678: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8080067C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80800680: jr          $ra
    // 0x80800684: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    return;
    // 0x80800684: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
;}
RECOMP_FUNC void func_80800000_chjigsawdance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800018: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080001C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800020: jal         0x800CFA70
    // 0x80800024: nop

    func_800CFA70(rdram, ctx);
        goto after_0;
    // 0x80800024: nop

    after_0:
    // 0x80800028: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080002C: beql        $v0, $at, L_80800090
    if (ctx->r2 == ctx->r1) {
        // 0x80800030: lhu         $t5, 0x6E($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X6E);
            goto L_80800090;
    }
    goto skip_0;
    // 0x80800030: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    skip_0:
    // 0x80800034: jal         0x800C8A98
    // 0x80800038: nop

    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x80800038: nop

    after_1:
    // 0x8080003C: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800040: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800044: andi        $t8, $v0, 0x1FF
    ctx->r24 = ctx->r2 & 0X1FF;
    // 0x80800048: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x8080004C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800050: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800054: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
    // 0x80800058: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800060: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80800064: andi        $t3, $a2, 0x1FF
    ctx->r11 = ctx->r6 & 0X1FF;
    // 0x80800068: jal         0x800CF9E4
    // 0x8080006C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    func_800CF9E4(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_2:
    // 0x80800070: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800074: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800078: andi        $t4, $a0, 0x1FF
    ctx->r12 = ctx->r4 & 0X1FF;
    // 0x8080007C: jal         0x800C8CB8
    // 0x80800080: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_3;
    // 0x80800080: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x80800084: b           L_8080009C
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080009C;
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080008C: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
L_80800090:
    // 0x80800090: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x80800094: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
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
RECOMP_FUNC void _bsstonehead_entrypoint_42(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D30: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083D30);
    return;
    // 0x80083D34: addi        $t0, $zero, 0xA8
    ctx->r8 = ADD32(0, 0XA8);
;}
RECOMP_FUNC void func_80020BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020BB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020BBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020BC0: jal         0x80020AD0
    // 0x80020BC4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_80020AD0(rdram, ctx);
        goto after_0;
    // 0x80020BC4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x80020BC8: b           L_80020BD0
    // 0x80020BCC: nop

        goto L_80020BD0;
    // 0x80020BCC: nop

L_80020BD0:
    // 0x80020BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020BD8: jr          $ra
    // 0x80020BDC: nop

    return;
    // 0x80020BDC: nop

;}
RECOMP_FUNC void func_80800450_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800458: jal         0x8080021C
    // 0x8080045C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8080021C_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x8080045C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800460: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800464: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080046C: jal         0x8008CCBC
    // 0x80800470: addiu       $a1, $zero, 0x295
    ctx->r5 = ADD32(0, 0X295);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80800470: addiu       $a1, $zero, 0x295
    ctx->r5 = ADD32(0, 0X295);
    after_1:
    // 0x80800474: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800478: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080047C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800488: jal         0x8009FFD8
    // 0x8080048C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080048C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800490: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800494: jal         0x8009B9B0
    // 0x80800498: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800498: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080049C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004A4: jr          $ra
    // 0x808004A8: nop

    return;
    // 0x808004A8: nop

;}
RECOMP_FUNC void chpickups_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0X8B0) << 16);
    // 0x80800034: jr          $ra
    // 0x80800038: addiu       $v0, $v0, 0x8B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X8B0));
    return;
    // 0x80800038: addiu       $v0, $v0, 0x8B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X8B0));
;}
RECOMP_FUNC void bsdronebitten_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800160: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800168: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080016C: jal         0x80800000
    // 0x80800170: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_80800000_bsdronebitten(rdram, ctx);
        goto after_0;
    // 0x80800170: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80800174: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80800178: jal         0x800F64A4
    // 0x8080017C: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x8080017C: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_1:
    // 0x80800180: beq         $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x80800184: nop
    
            goto L_8080019C;
    }
    // 0x80800184: nop

    // 0x80800188: jal         0x8008DA24
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DA24(rdram, ctx);
        goto after_2;
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800190: beq         $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x80800194: addiu       $t6, $zero, 0xA8
        ctx->r14 = ADD32(0, 0XA8);
            goto L_8080019C;
    }
    // 0x80800194: addiu       $t6, $zero, 0xA8
    ctx->r14 = ADD32(0, 0XA8);
    // 0x80800198: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_8080019C:
    // 0x8080019C: jal         0x8009BB50
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_3;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001A8: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808001B4: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x808001B8: bc1f        L_808001C4
    if (!c1cs) {
        // 0x808001BC: nop
    
            goto L_808001C4;
    }
    // 0x808001BC: nop

    // 0x808001C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_808001C4:
    // 0x808001C4: jal         0x8008DF8C
    // 0x808001C8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_8008DF8C(rdram, ctx);
        goto after_4;
    // 0x808001C8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_4:
    // 0x808001CC: bne         $v0, $zero, L_808001EC
    if (ctx->r2 != 0) {
        // 0x808001D0: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_808001EC;
    }
    // 0x808001D0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808001D4: beql        $t8, $zero, L_808001FC
    if (ctx->r24 == 0) {
        // 0x808001D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001DC: jal         0x8008E35C
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_5;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001E4: beql        $v0, $zero, L_808001FC
    if (ctx->r2 == 0) {
        // 0x808001E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001FC;
    }
    goto skip_1;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_808001EC:
    // 0x808001EC: jal         0x80084700
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_24(rdram, ctx);
        goto after_6;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001FC:
    // 0x808001FC: jal         0x8009E5C8
    // 0x80800200: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80800200: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080020C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void func_80801A18_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A1C: addiu       $at, $zero, 0xFB3
    ctx->r1 = ADD32(0, 0XFB3);
    // 0x80801A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801A28: bne         $a1, $at, L_80801A40
    if (ctx->r5 != ctx->r1) {
        // 0x80801A2C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801A40;
    }
    // 0x80801A2C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801A30: jal         0x800D211C
    // 0x80801A34: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800D211C(rdram, ctx);
        goto after_0;
    // 0x80801A34: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_0:
    // 0x80801A38: b           L_80801A48
    // 0x80801A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801A48;
    // 0x80801A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801A40:
    // 0x80801A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801A48:
    // 0x80801A48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A4C: jr          $ra
    // 0x80801A50: nop

    return;
    // 0x80801A50: nop

;}
RECOMP_FUNC void func_80800104_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080010C: jal         0x8001211C
    // 0x80800110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x80800110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800114: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080011C: lw          $t7, 0x168($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X168);
    // 0x80800120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800124: xor         $v0, $v0, $t7
    ctx->r2 = ctx->r2 ^ ctx->r15;
    // 0x80800128: jr          $ra
    // 0x8080012C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8080012C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void babuzz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001E0: jal         0x800D8FF8
    // 0x808001E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808001E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001E8: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x808001EC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x808001F0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808001F4: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x808001F8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808001FC: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x80800200: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80800204: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800208: jal         0x80800074
    // 0x8080020C: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
    func_80800074_babuzz(rdram, ctx);
        goto after_1;
    // 0x8080020C: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
    after_1:
    // 0x80800210: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x80800214: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80800218: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    // 0x8080021C: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80800220: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80800224: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80800228: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8080022C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80800230: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800234: jal         0x80800074
    // 0x80800238: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_80800074_babuzz(rdram, ctx);
        goto after_2;
    // 0x80800238: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_2:
    // 0x8080023C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800240: lw          $t1, 0x34($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X34);
    // 0x80800244: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80800248: nop

    // 0x8080024C: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x80800250: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x80800254: jal         0x80800008
    // 0x80800258: lwc1        $f12, 0x14($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X14);
    func_80800008_babuzz(rdram, ctx);
        goto after_3;
    // 0x80800258: lwc1        $f12, 0x14($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X14);
    after_3:
    // 0x8080025C: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80800260: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800264: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80800268: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8080026C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800270: jal         0x800C31DC
    // 0x80800274: nop

    func_800C31DC(rdram, ctx);
        goto after_4;
    // 0x80800274: nop

    after_4:
    // 0x80800278: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x8080027C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80800280: jal         0x800C3058
    // 0x80800284: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    func_800C3058(rdram, ctx);
        goto after_5;
    // 0x80800284: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    after_5:
    // 0x80800288: lw          $t3, 0x34($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X34);
    // 0x8080028C: jal         0x800C3BDC
    // 0x80800290: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    func_800C3BDC(rdram, ctx);
        goto after_6;
    // 0x80800290: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    after_6:
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080029C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002A0: jr          $ra
    // 0x808002A4: nop

    return;
    // 0x808002A4: nop

;}
RECOMP_FUNC void ch2dbaddy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1356, 0XA9C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xA9C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1356, 0XA9C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xA9C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1356, 0XA9C));
;}
RECOMP_FUNC void func_800F690C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F690C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6914: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F691C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6920: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6924: jal         0x80095738
    // 0x800F6928: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x800F6928: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_0:
    // 0x800F692C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6934: jr          $ra
    // 0x800F6938: nop

    return;
    // 0x800F6938: nop

;}
RECOMP_FUNC void fxstep_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808005EC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808005F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005F8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808005FC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80800600: jal         0x80800344
    // 0x80800604: lbu         $a3, 0x27($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X27);
    func_80800344_fxstep(rdram, ctx);
        goto after_0;
    // 0x80800604: lbu         $a3, 0x27($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X27);
    after_0:
    // 0x80800608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080060C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800610: jr          $ra
    // 0x80800614: nop

    return;
    // 0x80800614: nop

;}
RECOMP_FUNC void func_80801060_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801060: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801064: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801068: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080106C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801070: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801074: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80801078: jal         0x800EEB9C
    // 0x8080107C: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_0;
    // 0x8080107C: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_0:
    // 0x80801080: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801084: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801088: jal         0x800EF04C
    // 0x8080108C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x8080108C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80801090: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
    // 0x80801094: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80801098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080109C: jal         0x80108528
    // 0x808010A0: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80108528(rdram, ctx);
        goto after_2;
    // 0x808010A0: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x808010A4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808010A8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808010AC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808010B0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808010B4: jal         0x800F1DCC
    // 0x808010B8: lwc1        $f12, 0x48($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x808010B8: lwc1        $f12, 0x48($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X48);
    after_3:
    // 0x808010BC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808010C0: swc1        $f0, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f0.u32l;
    // 0x808010C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808010CC: jr          $ra
    // 0x808010D0: nop

    return;
    // 0x808010D0: nop

    // 0x808010D4: nop

    // 0x808010D8: nop

    // 0x808010DC: nop

;}
RECOMP_FUNC void _sccustom_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A660: syscall     846
    recomp_syscall_handler(rdram, ctx, 0x8008A660);
    return;
    // 0x8008A664: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void sumumbofx_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080134C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80801350: nop

    // 0x80801354: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
    // 0x80801358: jr          $ra
    // 0x8080135C: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x8080135C: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800137C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800137C4: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800137C8: addiu       $t0, $t0, -0x3370
    ctx->r8 = ADD32(ctx->r8, -0X3370);
    // 0x800137CC: jr          $ra
    // 0x800137D0: lwc1        $f0, 0x4($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
    return;
    // 0x800137D0: lwc1        $f0, 0x4($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
;}
RECOMP_FUNC void func_80800098_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080009C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A8: jal         0x80100094
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000B0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808000B4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808000B8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000BC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000C0: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x808000C4: beq         $at, $zero, L_808001E8
    if (ctx->r1 == 0) {
        // 0x808000C8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808001E8;
    }
    // 0x808000C8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1008, 0X1BE0) << 16);
    // 0x808000D0: addu        $at, $at, $t8
    gpr jr_addend_808000D8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000D4: lw          $t8, 0x1BE0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1008, 0X1BE0));
    // 0x808000D8: jr          $t8
    // 0x808000DC: nop

    switch (jr_addend_808000D8 >> 2) {
        case 0: goto L_808001E8; break;
        case 1: goto L_808001E8; break;
        case 2: goto L_808000E0; break;
        case 3: goto L_80800194; break;
        case 4: goto L_808001E8; break;
        case 5: goto L_808001E8; break;
        default: switch_error(__func__, 0x808000D8, 0x80801BE0);
    }
    // 0x808000DC: nop

L_808000E0:
    // 0x808000E0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x808000E4: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    // 0x808000E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000EC: jal         0x800D24E8
    // 0x808000F0: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    func_800D24E8(rdram, ctx);
        goto after_1;
    // 0x808000F0: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    after_1:
    // 0x808000F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800100: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800104: jal         0x800DC178
    // 0x80800108: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800108: nop

    after_2:
    // 0x8080010C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800110: jal         0x800D9154
    // 0x80800114: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9154(rdram, ctx);
        goto after_3;
    // 0x80800114: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x80800118: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x8080011C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800128;
    }
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x80108B04
    // 0x80800124: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80108B04(rdram, ctx);
        goto after_4;
    // 0x80800124: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_4:
L_80800128:
    // 0x80800128: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8080012C: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x80800130: jal         0x800CEAD0
    // 0x80800134: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_5;
    // 0x80800134: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_5:
    // 0x80800138: beq         $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x8080013C: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_808001E8;
    }
    // 0x8080013C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x80800A7C
    // 0x80800148: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    func_80800A7C_chballoonburst(rdram, ctx);
        goto after_6;
    // 0x80800148: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_6:
    // 0x8080014C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80800150: jal         0x800F54E4
    // 0x80800154: sw          $v0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800154: sw          $v0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r2;
    after_7:
    // 0x80800158: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080015C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800160: jal         0x800F8300
    // 0x80800164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F8300(rdram, ctx);
        goto after_8;
    // 0x80800164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80800168: jal         0x800F54E4
    // 0x8080016C: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x8080016C: nop

    after_9:
    // 0x80800170: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800174: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x80800178: jal         0x800F7C0C
    // 0x8080017C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7C0C(rdram, ctx);
        goto after_10;
    // 0x8080017C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_10:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x80101FDC
    // 0x80800188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80800188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x8080018C: b           L_808001EC
    // 0x80800190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001EC;
    // 0x80800190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800194:
    // 0x80800194: jal         0x8008A2E8
    // 0x80800198: nop

    _susubgame_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80800198: nop

    after_12:
    // 0x8080019C: beq         $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E8;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808001A8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808001AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808001B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808001B4: jal         0x8008A2C8
    // 0x808001B8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x808001B8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_13:
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x80101FDC
    // 0x808001C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x808001C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
    // 0x808001C8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x808001CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001D0: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x808001D4: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x808001D8: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x808001DC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808001E0: jal         0x8008A208
    // 0x808001E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x808001E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
L_808001E8:
    // 0x808001E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001EC:
    // 0x808001EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void vector_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B28B8: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800B28BC: jr          $ra
    // 0x800B28C0: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    return;
    // 0x800B28C0: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80800124_chlavahand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800128: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800130: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800138: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080013C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800140: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80800144: beq         $at, $zero, L_808008F4
    if (ctx->r1 == 0) {
        // 0x80800148: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808008F4;
    }
    // 0x80800148: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080014C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1230) << 16);
    // 0x80800150: addu        $at, $at, $t8
    gpr jr_addend_80800158 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800154: lw          $t8, 0x1230($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1230));
    // 0x80800158: jr          $t8
    // 0x8080015C: nop

    switch (jr_addend_80800158 >> 2) {
        case 0: goto L_80800160; break;
        case 1: goto L_80800210; break;
        case 2: goto L_80800210; break;
        case 3: goto L_8080058C; break;
        case 4: goto L_8080058C; break;
        case 5: goto L_808007EC; break;
        case 6: goto L_808007EC; break;
        case 7: goto L_808008E0; break;
        case 8: goto L_808008F4; break;
        default: switch_error(__func__, 0x80800158, 0x80801230);
    }
    // 0x8080015C: nop

L_80800160:
    // 0x80800160: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8080016C: bgez        $t1, L_80800194
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800170: nop
    
            goto L_80800194;
    }
    // 0x80800170: nop

    // 0x80800174: jal         0x80089BD8
    // 0x80800178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080017C: beq         $v0, $zero, L_80800200
    if (ctx->r2 == 0) {
        // 0x80800180: nop
    
            goto L_80800200;
    }
    // 0x80800180: nop

    // 0x80800184: jal         0x80800024
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800024_chlavahand(rdram, ctx);
        goto after_1;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080018C: b           L_80800200
    // 0x80800190: nop

        goto L_80800200;
    // 0x80800190: nop

L_80800194:
    // 0x80800194: jal         0x800D90A4
    // 0x80800198: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_2;
    // 0x80800198: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x8080019C: beq         $v0, $zero, L_80800200
    if (ctx->r2 == 0) {
        // 0x808001A0: nop
    
            goto L_80800200;
    }
    // 0x808001A0: nop

    // 0x808001A4: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
    // 0x808001A8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808001B0: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x808001B4: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x808001B8: bgez        $t3, L_808001CC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808001BC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808001CC;
    }
    // 0x808001BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001C4: nop

    // 0x808001C8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808001CC:
    // 0x808001CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808001D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001D4: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x808001D8: addiu       $a3, $zero, -0xC8
    ctx->r7 = ADD32(0, -0XC8);
    // 0x808001DC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808001E0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808001E4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808001E8: jal         0x8010C9FC
    // 0x808001EC: nop

    func_8010C9FC(rdram, ctx);
        goto after_3;
    // 0x808001EC: nop

    after_3:
    // 0x808001F0: beq         $v0, $zero, L_80800200
    if (ctx->r2 == 0) {
        // 0x808001F4: nop
    
            goto L_80800200;
    }
    // 0x808001F4: nop

    // 0x808001F8: jal         0x80800024
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800024_chlavahand(rdram, ctx);
        goto after_4;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80800200:
    // 0x80800200: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1254) << 16);
    // 0x80800204: lwc1        $f4, 0x1254($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1254));
    // 0x80800208: b           L_808008F4
    // 0x8080020C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
        goto L_808008F4;
    // 0x8080020C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
L_80800210:
    // 0x80800210: jal         0x80101F24
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_5;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x8010C754
    // 0x80800220: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_8010C754(rdram, ctx);
        goto after_6;
    // 0x80800220: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80800224: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1258) << 16);
    // 0x80800228: lwc1        $f0, 0x1258($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1258));
    // 0x8080022C: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800230: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800234: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800238: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8080023C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800240: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X125C) << 16);
    // 0x80800244: bc1f        L_80800268
    if (!c1cs) {
        // 0x80800248: nop
    
            goto L_80800268;
    }
    // 0x80800248: nop

    // 0x8080024C: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800250: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800254: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800258: jal         0x800F10B4
    // 0x8080025C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x8080025C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x80800260: b           L_808002A4
    // 0x80800264: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
        goto L_808002A4;
    // 0x80800264: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
L_80800268:
    // 0x80800268: lwc1        $f14, 0x125C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X125C));
    // 0x8080026C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1260) << 16);
    // 0x80800270: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800274: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x80800278: nop

    // 0x8080027C: bc1fl       L_808002A0
    if (!c1cs) {
        // 0x80800280: lwc1        $f10, 0x54($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
            goto L_808002A0;
    }
    goto skip_0;
    // 0x80800280: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    skip_0:
    // 0x80800284: lwc1        $f6, 0x1260($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1260));
    // 0x80800288: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x8080028C: jal         0x800F10B4
    // 0x80800290: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800290: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80800294: b           L_808002A4
    // 0x80800298: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
        goto L_808002A4;
    // 0x80800298: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8080029C: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
L_808002A0:
    // 0x808002A0: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
L_808002A4:
    // 0x808002A4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x808002A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002AC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2332, 0X1324) << 16);
    // 0x808002B0: slti        $t5, $a2, 0x3E8
    ctx->r13 = SIGNED(ctx->r6) < 0X3E8 ? 1 : 0;
    // 0x808002B4: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x808002B8: addiu       $a3, $a3, 0x1324
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2332, 0X1324));
    // 0x808002BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808002C0: jal         0x80089D50
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002C8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x808002CC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808002D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1264) << 16);
    // 0x808002D8: lwc1        $f18, 0x1264($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1264));
    // 0x808002DC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x808002E0: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x808002E4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808002E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808002EC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x808002F0: jal         0x800F10B4
    // 0x808002F4: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x808002F4: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_10:
    // 0x808002F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002FC: jal         0x80089D30
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800304: jal         0x80101F24
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_12;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080030C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800310: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800314: nop

    // 0x80800318: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080031C: jal         0x80013970
    // 0x80800320: nop

    func_80013970(rdram, ctx);
        goto after_13;
    // 0x80800320: nop

    after_13:
    // 0x80800324: lui         $at, 0x467A
    ctx->r1 = S32(0X467A << 16);
    // 0x80800328: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800334: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800338: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080033C: jal         0x80089D38
    // 0x80800340: nop

    _subaddieaudioloop_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80800340: nop

    after_14:
    // 0x80800344: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800348: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080034C: jal         0x80101E14
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800354: beq         $v0, $zero, L_8080042C
    if (ctx->r2 == 0) {
        // 0x80800358: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080042C;
    }
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1268) << 16);
    // 0x80800360: lwc1        $f12, 0x1268($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1268));
    // 0x80800364: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X126C) << 16);
    // 0x80800368: jal         0x800DC178
    // 0x8080036C: lwc1        $f14, 0x126C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X126C));
    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x8080036C: lwc1        $f14, 0x126C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X126C));
    after_16:
    // 0x80800370: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1270) << 16);
    // 0x80800374: lwc1        $f16, 0x1270($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1270));
    // 0x80800378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080037C: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800380: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800384: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800388: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080038C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800390: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800394: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800398: nop

    // 0x8080039C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808003A0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808003A4: nop

    // 0x808003A8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808003AC: beql        $a0, $zero, L_808003FC
    if (ctx->r4 == 0) {
        // 0x808003B0: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_808003FC;
    }
    goto skip_1;
    // 0x808003B0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x808003B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808003BC: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808003C0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808003C4: nop

    // 0x808003C8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808003CC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808003D0: nop

    // 0x808003D4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808003D8: bne         $a0, $zero, L_808003F0
    if (ctx->r4 != 0) {
        // 0x808003DC: nop
    
            goto L_808003F0;
    }
    // 0x808003DC: nop

    // 0x808003E0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x808003E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808003E8: b           L_80800408
    // 0x808003EC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800408;
    // 0x808003EC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808003F0:
    // 0x808003F0: b           L_80800408
    // 0x808003F4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800408;
    // 0x808003F4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808003F8: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_808003FC:
    // 0x808003FC: nop

    // 0x80800400: bltz        $a0, L_808003F0
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800404: nop
    
            goto L_808003F0;
    }
    // 0x80800404: nop

L_80800408:
    // 0x80800408: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x8080040C: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x80800410: ori         $at, $at, 0x5E01
    ctx->r1 = ctx->r1 | 0X5E01;
    // 0x80800414: sll         $t0, $t9, 21
    ctx->r8 = S32(ctx->r25 << 21);
    // 0x80800418: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8080041C: jal         0x800C4140
    // 0x80800420: addu        $a0, $t0, $at
    ctx->r4 = ADD32(ctx->r8, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_17;
    // 0x80800420: addu        $a0, $t0, $at
    ctx->r4 = ADD32(ctx->r8, ctx->r1);
    after_17:
    // 0x80800424: b           L_80800564
    // 0x80800428: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
        goto L_80800564;
    // 0x80800428: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_8080042C:
    // 0x8080042C: lui         $a1, 0x3F05
    ctx->r5 = S32(0X3F05 << 16);
    // 0x80800430: jal         0x80101E14
    // 0x80800434: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    func_80101E14(rdram, ctx);
        goto after_18;
    // 0x80800434: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    after_18:
    // 0x80800438: beq         $v0, $zero, L_80800510
    if (ctx->r2 == 0) {
        // 0x8080043C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2332, 0X1274) << 16);
            goto L_80800510;
    }
    // 0x8080043C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1274) << 16);
    // 0x80800440: lwc1        $f12, 0x1274($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1274));
    // 0x80800444: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800448: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080044C: jal         0x800DC178
    // 0x80800450: nop

    func_800DC178(rdram, ctx);
        goto after_19;
    // 0x80800450: nop

    after_19:
    // 0x80800454: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1278) << 16);
    // 0x80800458: lwc1        $f8, 0x1278($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1278));
    // 0x8080045C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800460: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800464: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800468: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x8080046C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800470: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800474: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80800478: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8080047C: nop

    // 0x80800480: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800484: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800488: nop

    // 0x8080048C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800490: beql        $a0, $zero, L_808004E0
    if (ctx->r4 == 0) {
        // 0x80800494: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_808004E0;
    }
    goto skip_2;
    // 0x80800494: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_2:
    // 0x80800498: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080049C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808004A0: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x808004A4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808004A8: nop

    // 0x808004AC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x808004B0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808004B4: nop

    // 0x808004B8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808004BC: bne         $a0, $zero, L_808004D4
    if (ctx->r4 != 0) {
        // 0x808004C0: nop
    
            goto L_808004D4;
    }
    // 0x808004C0: nop

    // 0x808004C4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x808004C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808004CC: b           L_808004EC
    // 0x808004D0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808004EC;
    // 0x808004D0: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808004D4:
    // 0x808004D4: b           L_808004EC
    // 0x808004D8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808004EC;
    // 0x808004D8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808004DC: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_808004E0:
    // 0x808004E0: nop

    // 0x808004E4: bltz        $a0, L_808004D4
    if (SIGNED(ctx->r4) < 0) {
        // 0x808004E8: nop
    
            goto L_808004D4;
    }
    // 0x808004E8: nop

L_808004EC:
    // 0x808004EC: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x808004F0: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x808004F4: ori         $at, $at, 0x5E01
    ctx->r1 = ctx->r1 | 0X5E01;
    // 0x808004F8: sll         $t3, $t2, 21
    ctx->r11 = S32(ctx->r10 << 21);
    // 0x808004FC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800500: jal         0x800C4140
    // 0x80800504: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_20;
    // 0x80800504: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    after_20:
    // 0x80800508: b           L_80800564
    // 0x8080050C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
        goto L_80800564;
    // 0x8080050C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_80800510:
    // 0x80800510: jal         0x80101DDC
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_21;
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800518: beq         $v0, $zero, L_80800560
    if (ctx->r2 == 0) {
        // 0x8080051C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800560;
    }
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80800524: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800528: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8080052C: bgezl       $t6, L_80800548
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800530: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80800548;
    }
    goto skip_3;
    // 0x80800530: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_3:
    // 0x80800534: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800538: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080053C: b           L_80800550
    // 0x80800540: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_80800550;
    // 0x80800540: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80800544: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80800548:
    // 0x80800548: nop

    // 0x8080054C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80800550:
    // 0x80800550: jal         0x80102424
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80800558: jal         0x80089D40
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_23;
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
L_80800560:
    // 0x80800560: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_80800564:
    // 0x80800564: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800568: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080056C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800570: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800574: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800578: nop

    // 0x8080057C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800580: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80800584: b           L_808008F4
    // 0x80800588: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
        goto L_808008F4;
    // 0x80800588: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_8080058C:
    // 0x8080058C: jal         0x80101F24
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_24;
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800594: jal         0x800DC0C0
    // 0x80800598: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_25;
    // 0x80800598: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x8080059C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X127C) << 16);
    // 0x808005A0: lwc1        $f16, 0x127C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X127C));
    // 0x808005A4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808005A8: nop

    // 0x808005AC: bc1fl       L_808005C0
    if (!c1cs) {
        // 0x808005B0: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_808005C0;
    }
    goto skip_4;
    // 0x808005B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    skip_4:
    // 0x808005B4: jal         0x80800A30
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A30_chlavahand(rdram, ctx);
        goto after_26;
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808005BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
L_808005C0:
    // 0x808005C0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2332, 0X1324) << 16);
    // 0x808005C4: addiu       $a3, $a3, 0x1324
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2332, 0X1324));
    // 0x808005C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: jal         0x80089D50
    // 0x808005D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x808005D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_27:
    // 0x808005D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1280) << 16);
    // 0x808005DC: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808005E0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808005E4: lwc1        $f14, 0x1280($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1280));
    // 0x808005E8: jal         0x800F1214
    // 0x808005EC: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    func_800F1214(rdram, ctx);
        goto after_28;
    // 0x808005EC: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    after_28:
    // 0x808005F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005F4: jal         0x80089D30
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_29;
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808005FC: lui         $at, 0x467A
    ctx->r1 = S32(0X467A << 16);
    // 0x80800600: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800604: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080060C: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800610: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800614: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800618: jal         0x80089D38
    // 0x8080061C: nop

    _subaddieaudioloop_entrypoint_1(rdram, ctx);
        goto after_30;
    // 0x8080061C: nop

    after_30:
    // 0x80800620: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800624: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800628: lwc1        $f12, 0x38($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080062C: jal         0x800F15F8
    // 0x80800630: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    func_800F15F8(rdram, ctx);
        goto after_31;
    // 0x80800630: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    after_31:
    // 0x80800634: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x80800638: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8080063C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800640: jal         0x80101E14
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_32;
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800648: beq         $v0, $zero, L_80800724
    if (ctx->r2 == 0) {
        // 0x8080064C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800724;
    }
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1284) << 16);
    // 0x80800654: lwc1        $f12, 0x1284($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1284));
    // 0x80800658: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080065C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800660: jal         0x800DC178
    // 0x80800664: nop

    func_800DC178(rdram, ctx);
        goto after_33;
    // 0x80800664: nop

    after_33:
    // 0x80800668: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1288) << 16);
    // 0x8080066C: lwc1        $f10, 0x1288($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1288));
    // 0x80800670: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800674: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800678: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080067C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800680: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800684: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800688: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8080068C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800690: nop

    // 0x80800694: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800698: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8080069C: nop

    // 0x808006A0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808006A4: beql        $a0, $zero, L_808006F4
    if (ctx->r4 == 0) {
        // 0x808006A8: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_808006F4;
    }
    goto skip_5;
    // 0x808006A8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_5:
    // 0x808006AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808006B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808006B4: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808006B8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808006BC: nop

    // 0x808006C0: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808006C4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808006C8: nop

    // 0x808006CC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808006D0: bne         $a0, $zero, L_808006E8
    if (ctx->r4 != 0) {
        // 0x808006D4: nop
    
            goto L_808006E8;
    }
    // 0x808006D4: nop

    // 0x808006D8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x808006DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808006E0: b           L_80800700
    // 0x808006E4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800700;
    // 0x808006E4: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808006E8:
    // 0x808006E8: b           L_80800700
    // 0x808006EC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800700;
    // 0x808006EC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808006F0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_808006F4:
    // 0x808006F4: nop

    // 0x808006F8: bltz        $a0, L_808006E8
    if (SIGNED(ctx->r4) < 0) {
        // 0x808006FC: nop
    
            goto L_808006E8;
    }
    // 0x808006FC: nop

L_80800700:
    // 0x80800700: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x80800704: lui         $at, 0x1D
    ctx->r1 = S32(0X1D << 16);
    // 0x80800708: ori         $at, $at, 0x4E05
    ctx->r1 = ctx->r1 | 0X4E05;
    // 0x8080070C: sll         $t0, $t9, 21
    ctx->r8 = S32(ctx->r25 << 21);
    // 0x80800710: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800714: jal         0x800C4140
    // 0x80800718: addu        $a0, $t0, $at
    ctx->r4 = ADD32(ctx->r8, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_34;
    // 0x80800718: addu        $a0, $t0, $at
    ctx->r4 = ADD32(ctx->r8, ctx->r1);
    after_34:
    // 0x8080071C: b           L_8080074C
    // 0x80800720: nop

        goto L_8080074C;
    // 0x80800720: nop

L_80800724:
    // 0x80800724: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800728: jal         0x80101E14
    // 0x8080072C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_35;
    // 0x8080072C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_35:
    // 0x80800730: beq         $v0, $zero, L_8080074C
    if (ctx->r2 == 0) {
        // 0x80800734: lui         $a0, 0x665F
        ctx->r4 = S32(0X665F << 16);
            goto L_8080074C;
    }
    // 0x80800734: lui         $a0, 0x665F
    ctx->r4 = S32(0X665F << 16);
    // 0x80800738: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x8080073C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800740: ori         $a0, $a0, 0x4601
    ctx->r4 = ctx->r4 | 0X4601;
    // 0x80800744: jal         0x800C4140
    // 0x80800748: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C4140(rdram, ctx);
        goto after_36;
    // 0x80800748: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_36:
L_8080074C:
    // 0x8080074C: jal         0x80101DDC
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_37;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800754: beq         $v0, $zero, L_808007AC
    if (ctx->r2 == 0) {
        // 0x80800758: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808007AC;
    }
    // 0x80800758: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080075C: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800768: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x8080076C: jal         0x8010A800
    // 0x80800770: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    func_8010A800(rdram, ctx);
        goto after_38;
    // 0x80800770: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    after_38:
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800778: jal         0x80107070
    // 0x8080077C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80107070(rdram, ctx);
        goto after_39;
    // 0x8080077C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_39:
    // 0x80800780: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80800784: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800788: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080078C: bne         $t3, $at, L_8080079C
    if (ctx->r11 != ctx->r1) {
        // 0x80800790: nop
    
            goto L_8080079C;
    }
    // 0x80800790: nop

    // 0x80800794: b           L_8080079C
    // 0x80800798: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_8080079C;
    // 0x80800798: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_8080079C:
    // 0x8080079C: jal         0x80102424
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_40;
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x808007A4: b           L_808008F4
    // 0x808007A8: nop

        goto L_808008F4;
    // 0x808007A8: nop

L_808007AC:
    // 0x808007AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007B0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808007B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007B8: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808007BC: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808007C0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808007C4: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808007C8: add.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808007CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808007D0: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x808007D4: nop

    // 0x808007D8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808007DC: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x808007E0: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x808007E4: b           L_808008F4
    // 0x808007E8: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
        goto L_808008F4;
    // 0x808007E8: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
L_808007EC:
    // 0x808007EC: lbu         $t4, 0x9B($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X9B);
    // 0x808007F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808007F4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x808007F8: bgez        $t4, L_8080080C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808007FC: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8080080C;
    }
    // 0x808007FC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800800: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800804: nop

    // 0x80800808: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8080080C:
    // 0x8080080C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800810: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800814: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2332, 0X1324) << 16);
    // 0x80800818: addiu       $a3, $a3, 0x1324
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2332, 0X1324));
    // 0x8080081C: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800824: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800828: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080082C: jal         0x80089D50
    // 0x80800830: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_41;
    // 0x80800830: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_41:
    // 0x80800834: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X128C) << 16);
    // 0x80800838: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x8080083C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800840: lwc1        $f14, 0x128C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X128C));
    // 0x80800844: jal         0x800F1214
    // 0x80800848: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    func_800F1214(rdram, ctx);
        goto after_42;
    // 0x80800848: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    after_42:
    // 0x8080084C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800850: jal         0x80089D30
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_43;
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80800858: lui         $at, 0x467A
    ctx->r1 = S32(0X467A << 16);
    // 0x8080085C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800860: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800868: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8080086C: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800870: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800874: jal         0x80089D38
    // 0x80800878: nop

    _subaddieaudioloop_entrypoint_1(rdram, ctx);
        goto after_44;
    // 0x80800878: nop

    after_44:
    // 0x8080087C: jal         0x800DC0C0
    // 0x80800880: nop

    func_800DC0C0(rdram, ctx);
        goto after_45;
    // 0x80800880: nop

    after_45:
    // 0x80800884: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800888: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8080088C: nop

    // 0x80800890: bc1fl       L_808008A8
    if (!c1cs) {
        // 0x80800894: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_808008A8;
    }
    goto skip_6;
    // 0x80800894: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    skip_6:
    // 0x80800898: jal         0x80800A30
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A30_chlavahand(rdram, ctx);
        goto after_46;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x808008A0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808008A4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_808008A8:
    // 0x808008A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808008AC: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808008B0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808008B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008B8: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808008BC: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808008C0: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x808008C4: nop

    // 0x808008C8: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808008CC: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x808008D0: add.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x808008D4: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x808008D8: b           L_808008F4
    // 0x808008DC: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
        goto L_808008F4;
    // 0x808008DC: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_808008E0:
    // 0x808008E0: lbu         $t6, 0x5F($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5F);
    // 0x808008E4: beq         $t6, $zero, L_808008F4
    if (ctx->r14 == 0) {
        // 0x808008E8: nop
    
            goto L_808008F4;
    }
    // 0x808008E8: nop

    // 0x808008EC: jal         0x80089D40
    // 0x808008F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_47;
    // 0x808008F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
L_808008F4:
    // 0x808008F4: jal         0x80800910
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800910_chlavahand(rdram, ctx);
        goto after_48;
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x808008FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800900: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800904: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800908: jr          $ra
    // 0x8080090C: nop

    return;
    // 0x8080090C: nop

;}
RECOMP_FUNC void func_800FC788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC78C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC790: jal         0x800FB5F8
    // 0x800FC794: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FC794: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FC798: beq         $v0, $zero, L_800FC7B4
    if (ctx->r2 == 0) {
        // 0x800FC79C: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_800FC7B4;
    }
    // 0x800FC79C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC7A0: lbu         $t0, 0x30($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X30);
    // 0x800FC7A4: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800FC7A8: andi        $t1, $t0, 0xFF0F
    ctx->r9 = ctx->r8 & 0XFF0F;
    // 0x800FC7AC: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x800FC7B0: sb          $t2, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r10;
L_800FC7B4:
    // 0x800FC7B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC7B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC7BC: jr          $ra
    // 0x800FC7C0: nop

    return;
    // 0x800FC7C0: nop

;}
RECOMP_FUNC void func_800F4EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4EC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F4ECC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F4ED0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4ED4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4ED8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4EDC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F4EE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F4EE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F4EE8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800F4EEC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800F4EF0: jal         0x800A3048
    // 0x800F4EF4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800A3048(rdram, ctx);
        goto after_0;
    // 0x800F4EF4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F4EF8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800F4EFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F4F00: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F4F04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800F4F08: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800F4F0C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800F4F10: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800F4F14: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800F4F18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800F4F1C: jal         0x8009F860
    // 0x800F4F20: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_8009F860(rdram, ctx);
        goto after_1;
    // 0x800F4F20: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800F4F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4F28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F4F2C: jr          $ra
    // 0x800F4F30: nop

    return;
    // 0x800F4F30: nop

;}
RECOMP_FUNC void func_800D1490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1490: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800D1494: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D1498: addiu       $a0, $a0, 0x1A04
    ctx->r4 = ADD32(ctx->r4, 0X1A04);
    // 0x800D149C: addiu       $a2, $a2, -0x4DB0
    ctx->r6 = ADD32(ctx->r6, -0X4DB0);
    // 0x800D14A0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D14A4: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800D14A8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800D14AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800D14B0: addiu       $a3, $zero, 0xA8
    ctx->r7 = ADD32(0, 0XA8);
    // 0x800D14B4: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
L_800D14B8:
    // 0x800D14B8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D14BC: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800D14C0: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800D14C4: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x800D14C8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800D14CC: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x800D14D0: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x800D14D4: lh          $t1, 0x8($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X8);
    // 0x800D14D8: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800D14DC: sh          $t1, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r9;
    // 0x800D14E0: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800D14E4: lh          $t4, 0x10($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X10);
    // 0x800D14E8: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800D14EC: sh          $t4, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r12;
    // 0x800D14F0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D14F4: lh          $t7, 0x18($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X18);
    // 0x800D14F8: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800D14FC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800D1500: bne         $a1, $a3, L_800D14B8
    if (ctx->r5 != ctx->r7) {
        // 0x800D1504: sh          $t7, 0x6($t8)
        MEM_H(0X6, ctx->r24) = ctx->r15;
            goto L_800D14B8;
    }
    // 0x800D1504: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x800D1508: jr          $ra
    // 0x800D150C: nop

    return;
    // 0x800D150C: nop

;}
RECOMP_FUNC void func_80800DF8_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E00: jal         0x80100094
    // 0x80800E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E08: lbu         $t6, 0x24($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X24);
    // 0x80800E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E10: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1576, 0X1384) << 16);
    // 0x80800E14: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80800E18: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80800E1C: lh          $v0, 0x1384($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1576, 0X1384));
    // 0x80800E20: jr          $ra
    // 0x80800E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bsdie_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FB0: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082FB0);
    return;
    // 0x80082FB4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _baeggaim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A90: syscall     127
    recomp_syscall_handler(rdram, ctx, 0x80084A90);
    return;
    // 0x80084A94: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_8080018C_chcanarymarycage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800190: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800194: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800198: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080019C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808001A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A8: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808001AC: beq         $t6, $at, L_808001D0
    if (ctx->r14 == ctx->r1) {
        // 0x808001B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001D0;
    }
    // 0x808001B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001B4: beq         $t6, $at, L_80800268
    if (ctx->r14 == ctx->r1) {
        // 0x808001B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800268;
    }
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808001C0: beql        $t6, $at, L_80800274
    if (ctx->r14 == ctx->r1) {
        // 0x808001C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800274;
    }
    goto skip_0;
    // 0x808001C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001C8: b           L_80800274
    // 0x808001CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800274;
    // 0x808001CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001D0:
    // 0x808001D0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808001D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001D8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001DC: addiu       $s1, $s0, 0x18
    ctx->r17 = ADD32(ctx->r16, 0X18);
    // 0x808001E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001E8: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x808001EC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808001F0: jal         0x800EEB9C
    // 0x808001F4: nop

    func_800EEB9C(rdram, ctx);
        goto after_0;
    // 0x808001F4: nop

    after_0:
    // 0x808001F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800200: jal         0x800EF04C
    // 0x80800204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80800204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080020C: lui         $a1, 0x43DC
    ctx->r5 = S32(0X43DC << 16);
    // 0x80800210: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800214: jal         0x8008FB10
    // 0x80800218: lui         $a3, 0x438C
    ctx->r7 = S32(0X438C << 16);
    func_8008FB10(rdram, ctx);
        goto after_2;
    // 0x80800218: lui         $a3, 0x438C
    ctx->r7 = S32(0X438C << 16);
    after_2:
    // 0x8080021C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800220: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800224: jal         0x800EEB9C
    // 0x80800228: lui         $a2, 0x4311
    ctx->r6 = S32(0X4311 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_3;
    // 0x80800228: lui         $a2, 0x4311
    ctx->r6 = S32(0X4311 << 16);
    after_3:
    // 0x8080022C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800230: jal         0x800EF04C
    // 0x80800234: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80800234: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800238: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8080023C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800240: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800248: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080024C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80800250: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80800254: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80800258: jal         0x8008FAC8
    // 0x8080025C: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    func_8008FAC8(rdram, ctx);
        goto after_5;
    // 0x8080025C: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x80800260: b           L_80800274
    // 0x80800264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800274;
    // 0x80800264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800268:
    // 0x80800268: jal         0x80800000
    // 0x8080026C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800000_chcanarymarycage(rdram, ctx);
        goto after_6;
    // 0x8080026C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800274:
    // 0x80800274: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800278: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080027C: jr          $ra
    // 0x80800280: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800280: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _babee_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084540: syscall     114
    recomp_syscall_handler(rdram, ctx, 0x80084540);
    return;
    // 0x80084544: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_800DDDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDDC4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800DDDC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DDDCC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DDDD0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DDDD4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800DDDD8: lh          $t6, 0x12($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X12);
    // 0x800DDDDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DDDE0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DDDE4: bne         $t6, $at, L_800DDE60
    if (ctx->r14 != ctx->r1) {
        // 0x800DDDE8: addiu       $s1, $sp, 0x34
        ctx->r17 = ADD32(ctx->r29, 0X34);
            goto L_800DDE60;
    }
    // 0x800DDDE8: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x800DDDEC: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x800DDDF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DDDF4: jal         0x800EE88C
    // 0x800DDDF8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x800DDDF8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_0:
    // 0x800DDDFC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DDE00: lw          $a1, -0x36B8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X36B8);
    // 0x800DDE04: jal         0x800EF334
    // 0x800DDE08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF334(rdram, ctx);
        goto after_1;
    // 0x800DDE08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800DDE0C: lh          $t7, 0xE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE);
    // 0x800DDE10: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DDE14: addiu       $v0, $v0, -0x36B8
    ctx->r2 = ADD32(ctx->r2, -0X36B8);
    // 0x800DDE18: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800DDE1C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DDE20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DDE24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DDE28: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800DDE2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800DDE30: jal         0x800E3E8C
    // 0x800DDE34: nop

    func_800E3E8C(rdram, ctx);
        goto after_2;
    // 0x800DDE34: nop

    after_2:
    // 0x800DDE38: beql        $v0, $zero, L_800DDF04
    if (ctx->r2 == 0) {
        // 0x800DDE3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDF04;
    }
    goto skip_0;
    // 0x800DDE3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800DDE40: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x800DDE44: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800DDE48: beql        $v0, $zero, L_800DDF04
    if (ctx->r2 == 0) {
        // 0x800DDE4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDF04;
    }
    goto skip_1;
    // 0x800DDE4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800DDE50: jal         0x800DE2A4
    // 0x800DDE54: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_3;
    // 0x800DDE54: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_3:
    // 0x800DDE58: b           L_800DDF04
    // 0x800DDE5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DDF04;
    // 0x800DDE5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DDE60:
    // 0x800DDE60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DDE64: jal         0x800EE88C
    // 0x800DDE68: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    func_800EE88C(rdram, ctx);
        goto after_4;
    // 0x800DDE68: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_4:
    // 0x800DDE6C: lh          $t8, 0xE($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XE);
    // 0x800DDE70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DDE74: addiu       $v0, $v0, -0x36B8
    ctx->r2 = ADD32(ctx->r2, -0X36B8);
    // 0x800DDE78: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800DDE7C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DDE80: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    // 0x800DDE84: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DDE88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DDE8C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800DDE90: beq         $a0, $zero, L_800DDECC
    if (ctx->r4 == 0) {
        // 0x800DDE94: swc1        $f4, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
            goto L_800DDECC;
    }
    // 0x800DDE94: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800DDE98: jal         0x800ADE2C
    // 0x800DDE9C: lh          $a1, 0x12($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X12);
    func_800ADE2C(rdram, ctx);
        goto after_5;
    // 0x800DDE9C: lh          $a1, 0x12($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X12);
    after_5:
    // 0x800DDEA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DDEA4: addiu       $a0, $a0, -0x31A8
    ctx->r4 = ADD32(ctx->r4, -0X31A8);
    // 0x800DDEA8: jal         0x80019AA0
    // 0x800DDEAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_6;
    // 0x800DDEAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x800DDEB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DDEB4: jal         0x80019224
    // 0x800DDEB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80019224(rdram, ctx);
        goto after_7;
    // 0x800DDEB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800DDEBC: jal         0x80018DAC
    // 0x800DDEC0: nop

    mlMtxPop(rdram, ctx);
        goto after_8;
    // 0x800DDEC0: nop

    after_8:
    // 0x800DDEC4: b           L_800DDED8
    // 0x800DDEC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800DDED8;
    // 0x800DDEC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800DDECC:
    // 0x800DDECC: jal         0x80019224
    // 0x800DDED0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80019224(rdram, ctx);
        goto after_9;
    // 0x800DDED0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x800DDED4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800DDED8:
    // 0x800DDED8: jal         0x800E3E8C
    // 0x800DDEDC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800E3E8C(rdram, ctx);
        goto after_10;
    // 0x800DDEDC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x800DDEE0: beql        $v0, $zero, L_800DDF04
    if (ctx->r2 == 0) {
        // 0x800DDEE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDF04;
    }
    goto skip_2;
    // 0x800DDEE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800DDEE8: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x800DDEEC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800DDEF0: beql        $v0, $zero, L_800DDF04
    if (ctx->r2 == 0) {
        // 0x800DDEF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDF04;
    }
    goto skip_3;
    // 0x800DDEF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800DDEF8: jal         0x800DE2A4
    // 0x800DDEFC: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_11;
    // 0x800DDEFC: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_11:
    // 0x800DDF00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DDF04:
    // 0x800DDF04: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DDF08: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DDF0C: jr          $ra
    // 0x800DDF10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800DDF10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _chminisubgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B80: syscall     202
    recomp_syscall_handler(rdram, ctx, 0x80085B80);
    return;
    // 0x80085B84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808001FC_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: jal         0x80090A2C
    // 0x80800208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090A2C(rdram, ctx);
        goto after_0;
    // 0x80800208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080020C: jal         0x80082830
    // 0x80800210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080021C: jr          $ra
    // 0x80800220: nop

    return;
    // 0x80800220: nop

;}
RECOMP_FUNC void func_808003F0_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808003FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800400: jal         0x8008CABC
    // 0x80800404: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800404: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800408: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080040C: jal         0x80082838
    // 0x80800410: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800410: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800414: jal         0x8008AF24
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x8008B1A0
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_3;
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: jal         0x8008AED4
    // 0x80800430: addiu       $a1, $zero, 0x1E2
    ctx->r5 = ADD32(0, 0X1E2);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800430: addiu       $a1, $zero, 0x1E2
    ctx->r5 = ADD32(0, 0X1E2);
    after_4:
    // 0x80800434: lui         $a2, 0x3EAE
    ctx->r6 = S32(0X3EAE << 16);
    // 0x80800438: ori         $a2, $a2, 0x147B
    ctx->r6 = ctx->r6 | 0X147B;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x8008B1D4
    // 0x80800444: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x80800444: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800448: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8080044C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800450: jal         0x8008B24C
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800458: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x8080045C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800460: jal         0x8008B1BC
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: jal         0x8008B134
    // 0x80800470: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800470: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800474: jal         0x8008B064
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080047C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800480: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080048C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800490: jal         0x8009FFD8
    // 0x80800494: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x80800494: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_10:
    // 0x80800498: jal         0x8009EF04
    // 0x8080049C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_11;
    // 0x8080049C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x808004A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808004A4: nop

    // 0x808004A8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808004AC: nop

    // 0x808004B0: bc1t        L_808004CC
    if (c1cs) {
        // 0x808004B4: nop
    
            goto L_808004CC;
    }
    // 0x808004B4: nop

    // 0x808004B8: jal         0x8009EEB8
    // 0x808004BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_12;
    // 0x808004BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x808004C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004C4: jal         0x8009C914
    // 0x808004C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_13;
    // 0x808004C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
L_808004CC:
    // 0x808004CC: jal         0x8009C990
    // 0x808004D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x808004D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x808004D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004D8: jal         0x8009B9C0
    // 0x808004DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_15;
    // 0x808004DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x808004E0: jal         0x80800058
    // 0x808004E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800058_bsbeemain(rdram, ctx);
        goto after_16;
    // 0x808004E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x808004E8: jal         0x8009C990
    // 0x808004EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_17;
    // 0x808004EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x808004F0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808004F4: jal         0x8009BB00
    // 0x808004F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x808004F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x808004FC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800504: jal         0x8009BA68
    // 0x80800508: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x80800508: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x8080050C: lui         $a1, 0x442D
    ctx->r5 = S32(0X442D << 16);
    // 0x80800510: ori         $a1, $a1, 0x6000
    ctx->r5 = ctx->r5 | 0X6000;
    // 0x80800514: jal         0x8009BA58
    // 0x80800518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_20;
    // 0x80800518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x8080051C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800520: jal         0x8009BCB4
    // 0x80800524: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_21;
    // 0x80800524: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_21:
    // 0x80800528: jal         0x8080002C
    // 0x8080052C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8080002C_bsbeemain(rdram, ctx);
        goto after_22;
    // 0x8080052C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x80800530: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800534: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800538: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080053C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800540: jr          $ra
    // 0x80800544: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800544: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80801254_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801258: addiu       $at, $zero, 0x10CF
    ctx->r1 = ADD32(0, 0X10CF);
    // 0x8080125C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801260: bne         $a1, $at, L_8080127C
    if (ctx->r5 != ctx->r1) {
        // 0x80801264: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080127C;
    }
    // 0x80801264: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801268: jal         0x80100094
    // 0x8080126C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080126C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801270: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x80801274: b           L_80801280
    // 0x80801278: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80801280;
    // 0x80801278: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8080127C:
    // 0x8080127C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801280:
    // 0x80801280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801288: jr          $ra
    // 0x8080128C: nop

    return;
    // 0x8080128C: nop

;}
RECOMP_FUNC void func_800F1344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1344: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F1348: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F134C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x800F1350: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800F1354: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F1358: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F135C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F1360: bc1f        L_800F13A0
    if (!c1cs) {
        // 0x800F1364: lwc1        $f14, 0x24($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
            goto L_800F13A0;
    }
    // 0x800F1364: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F1368: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F136C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F1370: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F1374: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800F1378: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800F137C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F1380: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800F1384: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800F1388: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800F138C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800F1390: jal         0x800F10B4
    // 0x800F1394: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x800F1394: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_0:
    // 0x800F1398: b           L_800F13B8
    // 0x800F139C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800F13B8;
    // 0x800F139C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F13A0:
    // 0x800F13A0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F13A4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800F13A8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800F13AC: jal         0x800F10B4
    // 0x800F13B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x800F13B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800F13B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F13B8:
    // 0x800F13B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F13BC: jr          $ra
    // 0x800F13C0: nop

    return;
    // 0x800F13C0: nop

;}
RECOMP_FUNC void func_800A0FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0FE4: lw          $t6, 0x150($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X150);
    // 0x800A0FE8: jr          $ra
    // 0x800A0FEC: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
    return;
    // 0x800A0FEC: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
;}
RECOMP_FUNC void func_800169B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800169B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800169B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800169BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800169C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800169C4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800169C8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800169CC: sw          $t6, -0xA10($at)
    MEM_W(-0XA10, ctx->r1) = ctx->r14;
    // 0x800169D0: addiu       $a1, $a1, -0x6078
    ctx->r5 = ADD32(ctx->r5, -0X6078);
    // 0x800169D4: addiu       $a0, $a0, -0x6090
    ctx->r4 = ADD32(ctx->r4, -0X6090);
    // 0x800169D8: jal         0x8002E070
    // 0x800169DC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800169DC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x800169E0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800169E4: addiu       $a0, $a0, -0x6090
    ctx->r4 = ADD32(ctx->r4, -0X6090);
    // 0x800169E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800169EC: jal         0x8002EAD0
    // 0x800169F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800169F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800169F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800169F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800169FC: jr          $ra
    // 0x80016A00: nop

    return;
    // 0x80016A00: nop

;}
RECOMP_FUNC void func_80800000_glcutDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: sb          $a0, 0x75EE($at)
    MEM_B(0X75EE, ctx->r1) = ctx->r4;
    return;
    // 0x80800008: sb          $a0, 0x75EE($at)
    MEM_B(0X75EE, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _cosectionstor_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087850: syscall     634
    recomp_syscall_handler(rdram, ctx, 0x80087850);
    return;
    // 0x80087854: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800624_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800628: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080062C: addiu       $at, $zero, 0x1002
    ctx->r1 = ADD32(0, 0X1002);
    // 0x80800630: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800634: beq         $a1, $at, L_8080065C
    if (ctx->r5 == ctx->r1) {
        // 0x80800638: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_8080065C;
    }
    // 0x80800638: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080063C: addiu       $at, $zero, 0x1004
    ctx->r1 = ADD32(0, 0X1004);
    // 0x80800640: beq         $a1, $at, L_80800760
    if (ctx->r5 == ctx->r1) {
        // 0x80800644: addiu       $a0, $zero, 0x36A
        ctx->r4 = ADD32(0, 0X36A);
            goto L_80800760;
    }
    // 0x80800644: addiu       $a0, $zero, 0x36A
    ctx->r4 = ADD32(0, 0X36A);
    // 0x80800648: addiu       $at, $zero, 0x1041
    ctx->r1 = ADD32(0, 0X1041);
    // 0x8080064C: beq         $a1, $at, L_80800728
    if (ctx->r5 == ctx->r1) {
        // 0x80800650: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800728;
    }
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: b           L_80800784
    // 0x80800658: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
        goto L_80800784;
    // 0x80800658: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
L_8080065C:
    // 0x8080065C: blez        $a2, L_80800708
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800660: addiu       $a1, $zero, 0x1003
        ctx->r5 = ADD32(0, 0X1003);
            goto L_80800708;
    }
    // 0x80800660: addiu       $a1, $zero, 0x1003
    ctx->r5 = ADD32(0, 0X1003);
    // 0x80800664: jal         0x800D1A04
    // 0x80800668: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x80800668: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_0:
    // 0x8080066C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80800670: beq         $at, $zero, L_80800698
    if (ctx->r1 == 0) {
        // 0x80800674: addiu       $a1, $zero, 0x1005
        ctx->r5 = ADD32(0, 0X1005);
            goto L_80800698;
    }
    // 0x80800674: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    // 0x80800678: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080067C: addiu       $t6, $zero, 0x55
    ctx->r14 = ADD32(0, 0X55);
    // 0x80800680: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800684: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800688: jal         0x8008A208
    // 0x8080068C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080068C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800690: b           L_80800920
    // 0x80800694: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800920;
    // 0x80800694: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800698:
    // 0x80800698: jal         0x800F54E4
    // 0x8080069C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080069C: nop

    after_2:
    // 0x808006A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006A4: jal         0x800F64A4
    // 0x808006A8: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x808006A8: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_3:
    // 0x808006AC: beq         $v0, $zero, L_808006E8
    if (ctx->r2 == 0) {
        // 0x808006B0: addiu       $a1, $zero, 0x1225
        ctx->r5 = ADD32(0, 0X1225);
            goto L_808006E8;
    }
    // 0x808006B0: addiu       $a1, $zero, 0x1225
    ctx->r5 = ADD32(0, 0X1225);
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x808006BC: jal         0x80800FBC
    // 0x808006C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800FBC_chjollyroger(rdram, ctx);
        goto after_4;
    // 0x808006C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808006C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006C8: addiu       $t7, $zero, 0x55
    ctx->r15 = ADD32(0, 0X55);
    // 0x808006CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808006D0: addiu       $a1, $zero, 0x1041
    ctx->r5 = ADD32(0, 0X1041);
    // 0x808006D4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808006D8: jal         0x8008A208
    // 0x808006DC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808006DC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808006E0: b           L_80800920
    // 0x808006E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800920;
    // 0x808006E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006E8:
    // 0x808006E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006EC: addiu       $t8, $zero, 0x55
    ctx->r24 = ADD32(0, 0X55);
    // 0x808006F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808006F4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808006F8: jal         0x8008A208
    // 0x808006FC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808006FC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800700: b           L_80800920
    // 0x80800704: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800920;
    // 0x80800704: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800708:
    // 0x80800708: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080070C: addiu       $t9, $zero, 0x55
    ctx->r25 = ADD32(0, 0X55);
    // 0x80800710: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800714: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800718: jal         0x8008A208
    // 0x8080071C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x8080071C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800720: b           L_80800920
    // 0x80800724: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800920;
    // 0x80800724: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800728:
    // 0x80800728: jal         0x80100094
    // 0x8080072C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x8080072C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800730: jal         0x80089FE0
    // 0x80800734: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800734: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80800738: jal         0x800DA298
    // 0x8080073C: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x8080073C: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_10:
    // 0x80800740: beq         $v0, $zero, L_80800750
    if (ctx->r2 == 0) {
        // 0x80800744: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80800750;
    }
    // 0x80800744: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800748: b           L_80800750
    // 0x8080074C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
        goto L_80800750;
    // 0x8080074C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_80800750:
    // 0x80800750: jal         0x80102424
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800758: b           L_80800920
    // 0x8080075C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800920;
    // 0x8080075C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800760:
    // 0x80800760: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800764: jal         0x80101180
    // 0x80800768: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_12;
    // 0x80800768: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800770: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800774: jal         0x80800F3C
    // 0x80800778: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80800F3C_chjollyroger(rdram, ctx);
        goto after_13;
    // 0x80800778: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_13:
    // 0x8080077C: b           L_80800920
    // 0x80800780: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800920;
    // 0x80800780: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800784:
    // 0x80800784: jal         0x800DA298
    // 0x80800788: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80800788: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_14:
    // 0x8080078C: beq         $v0, $zero, L_8080088C
    if (ctx->r2 == 0) {
        // 0x80800790: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8080088C;
    }
    // 0x80800790: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800794: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1036, 0X1238) << 16);
    // 0x80800798: addiu       $a2, $a2, 0x1238
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1036, 0X1238));
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: jal         0x8008A1F8
    // 0x808007A4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_15;
    // 0x808007A4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_15:
    // 0x808007A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007AC: beq         $v0, $at, L_808007C8
    if (ctx->r2 == ctx->r1) {
        // 0x808007B0: addiu       $a0, $zero, 0x24
        ctx->r4 = ADD32(0, 0X24);
            goto L_808007C8;
    }
    // 0x808007B0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x808007B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007B8: beq         $v0, $at, L_8080081C
    if (ctx->r2 == ctx->r1) {
        // 0x808007BC: nop
    
            goto L_8080081C;
    }
    // 0x808007BC: nop

    // 0x808007C0: b           L_80800870
    // 0x808007C4: nop

        goto L_80800870;
    // 0x808007C4: nop

L_808007C8:
    // 0x808007C8: jal         0x800D0A9C
    // 0x808007CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_16;
    // 0x808007CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808007D0: bne         $v0, $zero, L_8080081C
    if (ctx->r2 != 0) {
        // 0x808007D4: nop
    
            goto L_8080081C;
    }
    // 0x808007D4: nop

    // 0x808007D8: jal         0x800F54E4
    // 0x808007DC: nop

    func_800F54E4(rdram, ctx);
        goto after_17;
    // 0x808007DC: nop

    after_17:
    // 0x808007E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007E4: jal         0x800F7F98
    // 0x808007E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_18;
    // 0x808007E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007F4: jal         0x80800F3C
    // 0x808007F8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80800F3C_chjollyroger(rdram, ctx);
        goto after_19;
    // 0x808007F8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_19:
    // 0x808007FC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80800800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800804: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800808: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080080C: jal         0x800D1000
    // 0x80800810: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_20;
    // 0x80800810: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_20:
    // 0x80800814: b           L_80800920
    // 0x80800818: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800920;
    // 0x80800818: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080081C:
    // 0x8080081C: jal         0x800DA298
    // 0x80800820: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    func_800DA298(rdram, ctx);
        goto after_21;
    // 0x80800820: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    after_21:
    // 0x80800824: bnel        $v0, $zero, L_80800860
    if (ctx->r2 != 0) {
        // 0x80800828: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_80800860;
    }
    goto skip_0;
    // 0x80800828: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    skip_0:
    // 0x8080082C: jal         0x800DA298
    // 0x80800830: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    func_800DA298(rdram, ctx);
        goto after_22;
    // 0x80800830: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_22:
    // 0x80800834: bne         $v0, $zero, L_8080085C
    if (ctx->r2 != 0) {
        // 0x80800838: addiu       $a1, $zero, 0x1002
        ctx->r5 = ADD32(0, 0X1002);
            goto L_8080085C;
    }
    // 0x80800838: addiu       $a1, $zero, 0x1002
    ctx->r5 = ADD32(0, 0X1002);
    // 0x8080083C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800840: addiu       $t0, $zero, 0x55
    ctx->r8 = ADD32(0, 0X55);
    // 0x80800844: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800848: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x8080084C: jal         0x8008A208
    // 0x80800850: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_23;
    // 0x80800850: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_23:
    // 0x80800854: b           L_80800920
    // 0x80800858: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800920;
    // 0x80800858: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080085C:
    // 0x8080085C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
L_80800860:
    // 0x80800860: jal         0x800C01A8
    // 0x80800864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_24;
    // 0x80800864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x80800868: jal         0x800C0850
    // 0x8080086C: nop

    func_800C0850(rdram, ctx);
        goto after_25;
    // 0x8080086C: nop

    after_25:
L_80800870:
    // 0x80800870: jal         0x80800E30
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E30_chjollyroger(rdram, ctx);
        goto after_26;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080087C: jal         0x80102424
    // 0x80800880: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_27;
    // 0x80800880: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_27:
    // 0x80800884: b           L_80800920
    // 0x80800888: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800920;
    // 0x80800888: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080088C:
    // 0x8080088C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1036, 0X1200) << 16);
    // 0x80800890: addiu       $a2, $a2, 0x1200
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1036, 0X1200));
    // 0x80800894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800898: jal         0x8008A1F8
    // 0x8080089C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_28;
    // 0x8080089C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_28:
    // 0x808008A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008A4: beq         $v0, $at, L_808008B4
    if (ctx->r2 == ctx->r1) {
        // 0x808008A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808008B4;
    }
    // 0x808008A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008AC: bne         $v0, $at, L_80800908
    if (ctx->r2 != ctx->r1) {
        // 0x808008B0: nop
    
            goto L_80800908;
    }
    // 0x808008B0: nop

L_808008B4:
    // 0x808008B4: jal         0x800DA298
    // 0x808008B8: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    func_800DA298(rdram, ctx);
        goto after_29;
    // 0x808008B8: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    after_29:
    // 0x808008BC: bnel        $v0, $zero, L_808008F8
    if (ctx->r2 != 0) {
        // 0x808008C0: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_808008F8;
    }
    goto skip_1;
    // 0x808008C0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    skip_1:
    // 0x808008C4: jal         0x800DA298
    // 0x808008C8: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    func_800DA298(rdram, ctx);
        goto after_30;
    // 0x808008C8: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_30:
    // 0x808008CC: bne         $v0, $zero, L_808008F4
    if (ctx->r2 != 0) {
        // 0x808008D0: addiu       $a1, $zero, 0x1002
        ctx->r5 = ADD32(0, 0X1002);
            goto L_808008F4;
    }
    // 0x808008D0: addiu       $a1, $zero, 0x1002
    ctx->r5 = ADD32(0, 0X1002);
    // 0x808008D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808008D8: addiu       $t1, $zero, 0x55
    ctx->r9 = ADD32(0, 0X55);
    // 0x808008DC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808008E0: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x808008E4: jal         0x8008A208
    // 0x808008E8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_31;
    // 0x808008E8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_31:
    // 0x808008EC: b           L_80800920
    // 0x808008F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800920;
    // 0x808008F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008F4:
    // 0x808008F4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
L_808008F8:
    // 0x808008F8: jal         0x800C01A8
    // 0x808008FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_32;
    // 0x808008FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80800900: jal         0x800C0850
    // 0x80800904: nop

    func_800C0850(rdram, ctx);
        goto after_33;
    // 0x80800904: nop

    after_33:
L_80800908:
    // 0x80800908: jal         0x80800E30
    // 0x8080090C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E30_chjollyroger(rdram, ctx);
        goto after_34;
    // 0x8080090C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800914: jal         0x80102424
    // 0x80800918: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_35;
    // 0x80800918: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x8080091C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800920:
    // 0x80800920: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800924: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800928: jr          $ra
    // 0x8080092C: nop

    return;
    // 0x8080092C: nop

;}
RECOMP_FUNC void func_80019CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019CD4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80019CD8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80019CDC: addiu       $v0, $v0, -0x4B10
    ctx->r2 = ADD32(ctx->r2, -0X4B10);
    // 0x80019CE0: addiu       $v1, $v1, -0x4350
    ctx->r3 = ADD32(ctx->r3, -0X4350);
    // 0x80019CE4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80019CE8: lui         $t0, 0x3F80
    ctx->r8 = S32(0X3F80 << 16);
    // 0x80019CEC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80019CF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80019CF4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80019CF8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80019CFC: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80019D00: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
    // 0x80019D04: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80019D08: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80019D0C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80019D10: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80019D14: sw          $t0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r8;
    // 0x80019D18: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80019D1C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80019D20: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x80019D24: sw          $zero, 0x38($v0)
    MEM_W(0X38, ctx->r2) = 0;
    // 0x80019D28: jr          $ra
    // 0x80019D2C: sw          $t0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r8;
    return;
    // 0x80019D2C: sw          $t0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void func_80800030_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800038: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1080, 0XB00) << 16);
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800040: jal         0x80086038
    // 0x80800044: addiu       $a1, $a1, 0xB00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1080, 0XB00));
    _chpowerhut_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a1, $a1, 0xB00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1080, 0XB00));
    after_0:
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: jal         0x80100094
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800054: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
