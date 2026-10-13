#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _dblight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879E8: syscall     647
    recomp_syscall_handler(rdram, ctx, 0x800879E8);
    return;
    // 0x800879EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _babounce_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845C0: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x800845C0);
    return;
    // 0x800845C4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsdronewaitbabykaz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800014: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800018: jal         0x80084658
    // 0x8080001C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    _badata_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800020: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800024: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: jal         0x8008CB3C
    // 0x8080002C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800030: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800034: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800038: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080003C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800044: jal         0x8009FFD8
    // 0x80800048: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8080004C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800050: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void chcactusofstrength_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(824, 0XD00) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xD00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(824, 0XD00));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xD00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(824, 0XD00));
;}
RECOMP_FUNC void sulights_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808008DC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808008E0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808008E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808008E8: jal         0x800D8FF8
    // 0x808008EC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808008EC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x808008F0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x808008F4: addiu       $s0, $s0, 0x7EF0
    ctx->r16 = ADD32(ctx->r16, 0X7EF0);
    // 0x808008F8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808008FC: jal         0x800B296C
    // 0x80800900: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_end(rdram, ctx);
        goto after_1;
    // 0x80800900: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80800904: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800908: jal         0x800B28C4
    // 0x8080090C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_begin(rdram, ctx);
        goto after_2;
    // 0x8080090C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80800910: sltu        $at, $v0, $s2
    ctx->r1 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x80800914: beq         $at, $zero, L_808009BC
    if (ctx->r1 == 0) {
        // 0x80800918: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808009BC;
    }
    // 0x80800918: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080091C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(3374, 0XA00) << 16);
    // 0x80800920: addiu       $s1, $s1, 0xA00
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(3374, 0XA00));
    // 0x80800924: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_80800928:
    // 0x80800928: beql        $t6, $zero, L_808009B0
    if (ctx->r14 == 0) {
        // 0x8080092C: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_808009B0;
    }
    goto skip_0;
    // 0x8080092C: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    skip_0:
    // 0x80800930: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800934: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800938: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8080093C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x80800940: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800944: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800948: nop

    // 0x8080094C: bc1fl       L_8080095C
    if (!c1cs) {
        // 0x80800950: lbu         $t7, 0x0($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X0);
            goto L_8080095C;
    }
    goto skip_1;
    // 0x80800950: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    skip_1:
    // 0x80800954: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800958: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
L_8080095C:
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800960: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800964: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80800968: lw          $t9, -0x8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X8);
    // 0x8080096C: jalr        $t9
    // 0x80800970: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80800970: nop

    after_3:
    // 0x80800974: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800978: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080097C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80800980: nop

    // 0x80800984: bc1fl       L_808009B0
    if (!c1cs) {
        // 0x80800988: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_808009B0;
    }
    goto skip_2;
    // 0x80800988: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    skip_2:
    // 0x8080098C: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x80800990: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80800994: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x80800998: lw          $v0, -0x4($t2)
    ctx->r2 = MEM_W(ctx->r10, -0X4);
    // 0x8080099C: beql        $v0, $zero, L_808009B0
    if (ctx->r2 == 0) {
        // 0x808009A0: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_808009B0;
    }
    goto skip_3;
    // 0x808009A0: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    skip_3:
    // 0x808009A4: jalr        $v0
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808009AC: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
L_808009B0:
    // 0x808009B0: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808009B4: bnel        $at, $zero, L_80800928
    if (ctx->r1 != 0) {
        // 0x808009B8: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_80800928;
    }
    goto skip_4;
    // 0x808009B8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_4:
L_808009BC:
    // 0x808009BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808009C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808009C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009C8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808009CC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808009D0: jr          $ra
    // 0x808009D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808009D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808009D8: nop

    // 0x808009DC: nop

;}
RECOMP_FUNC void baroll_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C47C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009C480: lw          $t6, 0xF4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF4);
    // 0x8009C484: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x8009C488: lw          $t7, 0xF4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XF4);
    // 0x8009C48C: jal         0x8009C570
    // 0x8009C490: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    baroll_resetAngularVelocity(rdram, ctx);
        goto after_0;
    // 0x8009C490: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    after_0:
    // 0x8009C494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C49C: jr          $ra
    // 0x8009C4A0: nop

    return;
    // 0x8009C4A0: nop

;}
RECOMP_FUNC void func_80803920_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803928: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080392C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80803930: lui         $a1, 0xC302
    ctx->r5 = S32(0XC302 << 16);
    // 0x80803934: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80803938: jal         0x800EFA4C
    // 0x8080393C: lui         $a3, 0xC3D7
    ctx->r7 = S32(0XC3D7 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x8080393C: lui         $a3, 0xC3D7
    ctx->r7 = S32(0XC3D7 << 16);
    after_0:
    // 0x80803940: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803944: jal         0x8080362C
    // 0x80803948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080362C_chevilmumbo(rdram, ctx);
        goto after_1;
    // 0x80803948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080394C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803954: jr          $ra
    // 0x80803958: nop

    return;
    // 0x80803958: nop

;}
RECOMP_FUNC void chwaspnestgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(776, 0X1F80) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(776, 0X1F80));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(776, 0X1F80));
;}
RECOMP_FUNC void func_80800670_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800678: jal         0x80800144
    // 0x8080067C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800144_chnests(rdram, ctx);
        goto after_0;
    // 0x8080067C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800680: jal         0x808000E8
    // 0x80800684: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000E8_chnests(rdram, ctx);
        goto after_1;
    // 0x80800684: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800688: jal         0x80088500
    // 0x8080068C: nop

    _gleeprom_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080068C: nop

    after_2:
    // 0x80800690: sra         $t6, $v0, 24
    ctx->r14 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80800694: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80800698: bne         $t6, $at, L_808006AC
    if (ctx->r14 != ctx->r1) {
        // 0x8080069C: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_808006AC;
    }
    // 0x8080069C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808006A0: lw          $a0, 0x20($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X20);
    // 0x808006A4: jal         0x800D0BD4
    // 0x808006A8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800D0BD4(rdram, ctx);
        goto after_3;
    // 0x808006A8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
L_808006AC:
    // 0x808006AC: jal         0x800FFAB0
    // 0x808006B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x808006B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x808006B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006BC: jr          $ra
    // 0x808006C0: nop

    return;
    // 0x808006C0: nop

;}
RECOMP_FUNC void suexpression_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080059C: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x808005A0: beql        $v0, $zero, L_808005B4
    if (ctx->r2 == 0) {
        // 0x808005A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005B4;
    }
    goto skip_0;
    // 0x808005A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808005A8: jal         0x80089B48
    // 0x808005AC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    _suexpressmorph_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808005AC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
    // 0x808005B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005B4:
    // 0x808005B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005B8: jr          $ra
    // 0x808005BC: nop

    return;
    // 0x808005BC: nop

;}
RECOMP_FUNC void func_800C673C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C673C: jr          $ra
    // 0x800C6740: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    return;
    // 0x800C6740: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
;}
RECOMP_FUNC void fxmumbo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800010: jal         0x800B5BE4
    // 0x80800014: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x80800018: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2814, 0X60) << 16);
    // 0x8080001C: addiu       $t6, $t6, 0x60
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2814, 0X60));
    // 0x80800020: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800028: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080002C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800030: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800034: jal         0x800BABB8
    // 0x80800038: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800038: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8080003C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800040: jal         0x800BA22C
    // 0x80800044: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x80800044: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080004C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

    // 0x80800058: nop

    // 0x8080005C: nop

;}
RECOMP_FUNC void _vpflicker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089038: syscall     757
    recomp_syscall_handler(rdram, ctx, 0x80089038);
    return;
    // 0x8008903C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void fxfontstring_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000EC: jal         0x80800000
    // 0x808000F0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80800000_fxfontstring(rdram, ctx);
        goto after_0;
    // 0x808000F0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x808000F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808000FC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800100: addiu       $t6, $zero, 0xFD
    ctx->r14 = ADD32(0, 0XFD);
    // 0x80800104: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
    // 0x80800108: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8080010C: bgtz        $a1, L_80800124
    if (SIGNED(ctx->r5) > 0) {
        // 0x80800110: sb          $t7, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r15;
            goto L_80800124;
    }
    // 0x80800110: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x80800114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800118: addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    // 0x8080011C: b           L_80800144
    // 0x80800120: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
        goto L_80800144;
    // 0x80800120: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
L_80800124:
    // 0x80800124: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80800128: bne         $at, $zero, L_80800138
    if (ctx->r1 != 0) {
        // 0x8080012C: addiu       $a0, $v0, 0x2
        ctx->r4 = ADD32(ctx->r2, 0X2);
            goto L_80800138;
    }
    // 0x8080012C: addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    // 0x80800130: b           L_8080013C
    // 0x80800134: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_8080013C;
    // 0x80800134: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80800138:
    // 0x80800138: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8080013C:
    // 0x8080013C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80800140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800144:
    // 0x80800144: bgtz        $a2, L_80800154
    if (SIGNED(ctx->r6) > 0) {
        // 0x80800148: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80800154;
    }
    // 0x80800148: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8080014C: b           L_8080016C
    // 0x80800150: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
        goto L_8080016C;
    // 0x80800150: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
L_80800154:
    // 0x80800154: slti        $at, $a2, 0x100
    ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
    // 0x80800158: bne         $at, $zero, L_80800168
    if (ctx->r1 != 0) {
        // 0x8080015C: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80800168;
    }
    // 0x8080015C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80800160: b           L_80800168
    // 0x80800164: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_80800168;
    // 0x80800164: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80800168:
    // 0x80800168: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8080016C:
    // 0x8080016C: bgtz        $a3, L_8080017C
    if (SIGNED(ctx->r7) > 0) {
        // 0x80800170: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8080017C;
    }
    // 0x80800170: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800174: b           L_80800194
    // 0x80800178: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
        goto L_80800194;
    // 0x80800178: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
L_8080017C:
    // 0x8080017C: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
    // 0x80800180: bne         $at, $zero, L_80800190
    if (ctx->r1 != 0) {
        // 0x80800184: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_80800190;
    }
    // 0x80800184: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80800188: b           L_80800190
    // 0x8080018C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_80800190;
    // 0x8080018C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80800190:
    // 0x80800190: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_80800194:
    // 0x80800194: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080019C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808001A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

;}
RECOMP_FUNC void func_800A9D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9D08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A9D0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A9D10: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A9D14: jal         0x800D39A8
    // 0x800A9D18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800D39A8(rdram, ctx);
        goto after_0;
    // 0x800A9D18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800A9D1C: jal         0x800D39DC
    // 0x800A9D20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D39DC(rdram, ctx);
        goto after_1;
    // 0x800A9D20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800A9D24: jal         0x800D3A88
    // 0x800A9D28: nop

    func_800D3A88(rdram, ctx);
        goto after_2;
    // 0x800A9D28: nop

    after_2:
    // 0x800A9D2C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9D30: addiu       $s0, $s0, -0x5B90
    ctx->r16 = ADD32(ctx->r16, -0X5B90);
    // 0x800A9D34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800A9D38:
    // 0x800A9D38: jal         0x800D3AF0
    // 0x800A9D3C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800D3AF0(rdram, ctx);
        goto after_3;
    // 0x800A9D3C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_3:
    // 0x800A9D40: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A9D44: sltiu       $at, $s1, 0x7
    ctx->r1 = ctx->r17 < 0X7 ? 1 : 0;
    // 0x800A9D48: bne         $at, $zero, L_800A9D38
    if (ctx->r1 != 0) {
        // 0x800A9D4C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800A9D38;
    }
    // 0x800A9D4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A9D50: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9D54: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A9D58: addiu       $s1, $s1, -0x5B84
    ctx->r17 = ADD32(ctx->r17, -0X5B84);
    // 0x800A9D5C: addiu       $s0, $s0, -0x5B88
    ctx->r16 = ADD32(ctx->r16, -0X5B88);
L_800A9D60:
    // 0x800A9D60: jal         0x800D3A20
    // 0x800A9D64: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800D3A20(rdram, ctx);
        goto after_4;
    // 0x800A9D64: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_4:
    // 0x800A9D68: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800A9D6C: bne         $s0, $s1, L_800A9D60
    if (ctx->r16 != ctx->r17) {
        // 0x800A9D70: nop
    
            goto L_800A9D60;
    }
    // 0x800A9D70: nop

    // 0x800A9D74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9D78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A9D7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A9D80: jr          $ra
    // 0x800A9D84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A9D84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A9D88: nop

    // 0x800A9D8C: nop

;}
RECOMP_FUNC void func_80107C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107C10: jr          $ra
    // 0x80107C14: nop

    return;
    // 0x80107C14: nop

;}
RECOMP_FUNC void _chdiggerbossdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867E0: syscall     378
    recomp_syscall_handler(rdram, ctx, 0x800867E0);
    return;
    // 0x800867E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800948_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080094C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800950: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800954: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800958: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080095C: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x80800960: beq         $at, $zero, L_80800998
    if (ctx->r1 == 0) {
        // 0x80800964: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800998;
    }
    // 0x80800964: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800968: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2276, 0X18C8) << 16);
    // 0x8080096C: addu        $at, $at, $t8
    gpr jr_addend_80800974 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800970: lw          $t8, 0x18C8($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2276, 0X18C8));
    // 0x80800974: jr          $t8
    // 0x80800978: nop

    switch (jr_addend_80800974 >> 2) {
        case 0: goto L_80800998; break;
        case 1: goto L_80800998; break;
        case 2: goto L_80800998; break;
        case 3: goto L_80800998; break;
        case 4: goto L_80800998; break;
        case 5: goto L_8080097C; break;
        case 6: goto L_80800998; break;
        case 7: goto L_8080097C; break;
        case 8: goto L_80800998; break;
        case 9: goto L_8080097C; break;
        default: switch_error(__func__, 0x80800974, 0x808018C8);
    }
    // 0x80800978: nop

L_8080097C:
    // 0x8080097C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2276, 0X1B60) << 16);
    // 0x80800980: addiu       $a2, $a2, 0x1B60
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2276, 0X1B60));
    // 0x80800984: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800988: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8080098C: jal         0x80089D20
    // 0x80800990: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800990: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800994: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800998:
    // 0x80800998: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
    // 0x8080099C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808009A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808009A4: srl         $t0, $t9, 4
    ctx->r8 = S32(U32(ctx->r25) >> 4);
    // 0x808009A8: beq         $t0, $zero, L_808009B8
    if (ctx->r8 == 0) {
        // 0x808009AC: lui         $a3, 0x8080
        ctx->r7 = S32(RELOC_HI16(2276, 0X1B78) << 16);
            goto L_808009B8;
    }
    // 0x808009AC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2276, 0X1B78) << 16);
    // 0x808009B0: jal         0x80089D50
    // 0x808009B4: addiu       $a3, $a3, 0x1B78
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2276, 0X1B78));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808009B4: addiu       $a3, $a3, 0x1B78
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2276, 0X1B78));
    after_1:
L_808009B8:
    // 0x808009B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009C0: jr          $ra
    // 0x808009C4: nop

    return;
    // 0x808009C4: nop

;}
RECOMP_FUNC void func_800CA7A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA7A4: jr          $ra
    // 0x800CA7A8: addiu       $v0, $a0, 0x64
    ctx->r2 = ADD32(ctx->r4, 0X64);
    return;
    // 0x800CA7A8: addiu       $v0, $a0, 0x64
    ctx->r2 = ADD32(ctx->r4, 0X64);
;}
RECOMP_FUNC void func_800F6968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6968: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F696C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6970: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6974: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6978: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F697C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6980: jal         0x800964DC
    // 0x800F6984: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800964DC(rdram, ctx);
        goto after_0;
    // 0x800F6984: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6988: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800F698C: jal         0x8009C150
    // 0x800F6990: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8009C150(rdram, ctx);
        goto after_1;
    // 0x800F6990: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800F6994: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F6998: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800F699C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F69A0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800F69A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F69A8: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800F69AC: nop

    // 0x800F69B0: bc1fl       L_800F69C0
    if (!c1cs) {
        // 0x800F69B4: sltu        $t7, $zero, $v0
        ctx->r15 = 0 < ctx->r2 ? 1 : 0;
            goto L_800F69C0;
    }
    goto skip_0;
    // 0x800F69B4: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    skip_0:
    // 0x800F69B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F69BC: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
L_800F69C0:
    // 0x800F69C0: beq         $t7, $zero, L_800F69D8
    if (ctx->r15 == 0) {
        // 0x800F69C4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800F69D8;
    }
    // 0x800F69C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F69C8: jal         0x800966BC
    // 0x800F69CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800966BC(rdram, ctx);
        goto after_2;
    // 0x800F69CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800F69D0: andi        $t8, $v0, 0x2000
    ctx->r24 = ctx->r2 & 0X2000;
    // 0x800F69D4: sltu        $v0, $zero, $t8
    ctx->r2 = 0 < ctx->r24 ? 1 : 0;
L_800F69D8:
    // 0x800F69D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F69DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F69E0: jr          $ra
    // 0x800F69E4: nop

    return;
    // 0x800F69E4: nop

;}
RECOMP_FUNC void func_80800000_suexpressmorph(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(3170, 0X1324) << 16);
    // 0x80800004: lh          $t6, 0x1324($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(3170, 0X1324));
    // 0x80800008: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3170, 0X132C) << 16);
    // 0x8080000C: addiu       $v0, $v0, 0x132C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3170, 0X132C));
    // 0x80800010: bne         $a0, $t6, L_80800020
    if (ctx->r4 != ctx->r14) {
        // 0x80800014: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80800020;
    }
    // 0x80800014: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800018: jr          $ra
    // 0x8080001C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8080001C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800020:
    // 0x80800020: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
L_80800024:
    // 0x80800024: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x80800028: bnel        $a0, $t7, L_8080003C
    if (ctx->r4 != ctx->r15) {
        // 0x8080002C: lh          $t8, 0x10($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X10);
            goto L_8080003C;
    }
    goto skip_0;
    // 0x8080002C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    skip_0:
    // 0x80800030: jr          $ra
    // 0x80800034: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800034: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800038: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
L_8080003C:
    // 0x8080003C: bnel        $a0, $t8, L_80800050
    if (ctx->r4 != ctx->r24) {
        // 0x80800040: lh          $t9, 0x1C($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X1C);
            goto L_80800050;
    }
    goto skip_1;
    // 0x80800040: lh          $t9, 0x1C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1C);
    skip_1:
    // 0x80800044: jr          $ra
    // 0x80800048: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x80800048: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8080004C: lh          $t9, 0x1C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1C);
L_80800050:
    // 0x80800050: bnel        $a0, $t9, L_80800064
    if (ctx->r4 != ctx->r25) {
        // 0x80800054: lh          $t0, 0x28($v0)
        ctx->r8 = MEM_H(ctx->r2, 0X28);
            goto L_80800064;
    }
    goto skip_2;
    // 0x80800054: lh          $t0, 0x28($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X28);
    skip_2:
    // 0x80800058: jr          $ra
    // 0x8080005C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x8080005C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80800060: lh          $t0, 0x28($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X28);
L_80800064:
    // 0x80800064: bnel        $a0, $t0, L_80800078
    if (ctx->r4 != ctx->r8) {
        // 0x80800068: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800078;
    }
    goto skip_3;
    // 0x80800068: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x8080006C: jr          $ra
    // 0x80800070: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x80800070: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x80800074: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80800078:
    // 0x80800078: bne         $v1, $a1, L_80800024
    if (ctx->r3 != ctx->r5) {
        // 0x8080007C: addiu       $v0, $v0, 0x30
        ctx->r2 = ADD32(ctx->r2, 0X30);
            goto L_80800024;
    }
    // 0x8080007C: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x80800080: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void _gldialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088740: syscall     702
    recomp_syscall_handler(rdram, ctx, 0x80088740);
    return;
    // 0x80088744: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800A94_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A98: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80800A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800AA4: beq         $a1, $v0, L_80800F78
    if (ctx->r5 == ctx->r2) {
        // 0x80800AA8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800F78;
    }
    // 0x80800AA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800AAC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800AB0: beq         $a1, $at, L_80800DBC
    if (ctx->r5 == ctx->r1) {
        // 0x80800AB4: addiu       $v1, $sp, 0x20
        ctx->r3 = ADD32(ctx->r29, 0X20);
            goto L_80800DBC;
    }
    // 0x80800AB4: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x80800AB8: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80800ABC: beq         $a1, $at, L_80800B54
    if (ctx->r5 == ctx->r1) {
        // 0x80800AC0: addiu       $v1, $sp, 0x20
        ctx->r3 = ADD32(ctx->r29, 0X20);
            goto L_80800B54;
    }
    // 0x80800AC0: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x80800AC4: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800AC8: beq         $a1, $at, L_80800AE4
    if (ctx->r5 == ctx->r1) {
        // 0x80800ACC: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800AE4;
    }
    // 0x80800ACC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800AD0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800AD4: beq         $a1, $at, L_80800FFC
    if (ctx->r5 == ctx->r1) {
        // 0x80800AD8: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80800FFC;
    }
    // 0x80800AD8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800ADC: b           L_80801034
    // 0x80800AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801034;
    // 0x80800AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AE4:
    // 0x80800AE4: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80800AE8: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    // 0x80800AEC: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    // 0x80800AF0: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800AF4: bltz        $t9, L_80800B4C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800AF8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800B4C;
    }
    // 0x80800AF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800AFC: jal         0x80108528
    // 0x80800B00: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x80800B00: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800B04: lhu         $t0, 0x76($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X76);
    // 0x80800B08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B0C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80800B10: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x80800B14: ori         $t2, $t1, 0x1900
    ctx->r10 = ctx->r9 | 0X1900;
    // 0x80800B18: sh          $t2, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r10;
    // 0x80800B1C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80800B20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B24: lbu         $t5, 0x65($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X65);
    // 0x80800B28: ori         $t7, $t5, 0x10
    ctx->r15 = ctx->r13 | 0X10;
    // 0x80800B2C: sb          $t7, 0x65($t3)
    MEM_B(0X65, ctx->r11) = ctx->r15;
    // 0x80800B30: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800B34: bne         $t8, $zero, L_80800B44
    if (ctx->r24 != 0) {
        // 0x80800B38: nop
    
            goto L_80800B44;
    }
    // 0x80800B38: nop

    // 0x80800B3C: jal         0x800862D8
    // 0x80800B40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800B40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
L_80800B44:
    // 0x80800B44: b           L_80801034
    // 0x80800B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B4C:
    // 0x80800B4C: b           L_80801034
    // 0x80800B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801034;
    // 0x80800B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B54:
    // 0x80800B54: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80800B58: slti        $at, $v0, 0x13DA
    ctx->r1 = SIGNED(ctx->r2) < 0X13DA ? 1 : 0;
    // 0x80800B5C: bne         $at, $zero, L_80800B88
    if (ctx->r1 != 0) {
        // 0x80800B60: addiu       $t6, $v0, -0x13CD
        ctx->r14 = ADD32(ctx->r2, -0X13CD);
            goto L_80800B88;
    }
    // 0x80800B60: addiu       $t6, $v0, -0x13CD
    ctx->r14 = ADD32(ctx->r2, -0X13CD);
    // 0x80800B64: addiu       $t9, $v0, -0x141E
    ctx->r25 = ADD32(ctx->r2, -0X141E);
    // 0x80800B68: sltiu       $at, $t9, 0x24
    ctx->r1 = ctx->r25 < 0X24 ? 1 : 0;
    // 0x80800B6C: beq         $at, $zero, L_80800DB4
    if (ctx->r1 == 0) {
        // 0x80800B70: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800DB4;
    }
    // 0x80800B70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800B74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X2334) << 16);
    // 0x80800B78: addu        $at, $at, $t9
    gpr jr_addend_80800B80 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800B7C: lw          $t9, 0x2334($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2336, 0X2334));
    // 0x80800B80: jr          $t9
    // 0x80800B84: nop

    switch (jr_addend_80800B80 >> 2) {
        case 0: goto L_80800BEC; break;
        case 1: goto L_80800BA8; break;
        case 2: goto L_80800BA8; break;
        case 3: goto L_80800BA8; break;
        case 4: goto L_80800BD0; break;
        case 5: goto L_80800BD0; break;
        case 6: goto L_80800BD0; break;
        case 7: goto L_80800BDC; break;
        case 8: goto L_80800DB4; break;
        case 9: goto L_80800DB4; break;
        case 10: goto L_80800DB4; break;
        case 11: goto L_80800DB4; break;
        case 12: goto L_80800DB4; break;
        case 13: goto L_80800DB4; break;
        case 14: goto L_80800DB4; break;
        case 15: goto L_80800DB4; break;
        case 16: goto L_80800DB4; break;
        case 17: goto L_80800DB4; break;
        case 18: goto L_80800DB4; break;
        case 19: goto L_80800DB4; break;
        case 20: goto L_80800DB4; break;
        case 21: goto L_80800DB4; break;
        case 22: goto L_80800DB4; break;
        case 23: goto L_80800DB4; break;
        case 24: goto L_80800DB4; break;
        case 25: goto L_80800DB4; break;
        case 26: goto L_80800C8C; break;
        case 27: goto L_80800CB0; break;
        case 28: goto L_80800CD4; break;
        case 29: goto L_80800D18; break;
        case 30: goto L_80800D0C; break;
        case 31: goto L_80800CE4; break;
        case 32: goto L_80800D7C; break;
        case 33: goto L_80800D50; break;
        case 34: goto L_80800D40; break;
        case 35: goto L_80800D88; break;
        default: switch_error(__func__, 0x80800B80, 0x80802334);
    }
    // 0x80800B84: nop

L_80800B88:
    // 0x80800B88: sltiu       $at, $t6, 0xD
    ctx->r1 = ctx->r14 < 0XD ? 1 : 0;
    // 0x80800B8C: beq         $at, $zero, L_80800DB4
    if (ctx->r1 == 0) {
        // 0x80800B90: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800DB4;
    }
    // 0x80800B90: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800B94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X23C4) << 16);
    // 0x80800B98: addu        $at, $at, $t6
    gpr jr_addend_80800BA0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800B9C: lw          $t6, 0x23C4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2336, 0X23C4));
    // 0x80800BA0: jr          $t6
    // 0x80800BA4: nop

    switch (jr_addend_80800BA0 >> 2) {
        case 0: goto L_80800C28; break;
        case 1: goto L_80800DB4; break;
        case 2: goto L_80800C28; break;
        case 3: goto L_80800C60; break;
        case 4: goto L_80800C7C; break;
        case 5: goto L_80800BEC; break;
        case 6: goto L_80800BEC; break;
        case 7: goto L_80800BEC; break;
        case 8: goto L_80800BEC; break;
        case 9: goto L_80800BEC; break;
        case 10: goto L_80800BFC; break;
        case 11: goto L_80800BFC; break;
        case 12: goto L_80800BEC; break;
        default: switch_error(__func__, 0x80800BA0, 0x808023C4);
    }
    // 0x80800BA4: nop

L_80800BA8:
    // 0x80800BA8: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x80800BAC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80800BB0: beq         $t0, $zero, L_80800BC8
    if (ctx->r8 == 0) {
        // 0x80800BB4: nop
    
            goto L_80800BC8;
    }
    // 0x80800BB4: nop

    // 0x80800BB8: jal         0x800D211C
    // 0x80800BBC: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_800D211C(rdram, ctx);
        goto after_2;
    // 0x80800BBC: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_2:
    // 0x80800BC0: b           L_80801038
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BC8:
    // 0x80800BC8: b           L_80801034
    // 0x80800BCC: lw          $v0, 0x20($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X20);
        goto L_80801034;
    // 0x80800BCC: lw          $v0, 0x20($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X20);
L_80800BD0:
    // 0x80800BD0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800BD4: b           L_80801034
    // 0x80800BD8: lw          $v0, 0x20($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X20);
        goto L_80801034;
    // 0x80800BD8: lw          $v0, 0x20($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X20);
L_80800BDC:
    // 0x80800BDC: jal         0x800D211C
    // 0x80800BE0: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_800D211C(rdram, ctx);
        goto after_3;
    // 0x80800BE0: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_3:
    // 0x80800BE4: b           L_80801038
    // 0x80800BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BEC:
    // 0x80800BEC: jal         0x8080206C
    // 0x80800BF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_4;
    // 0x80800BF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800BF4: b           L_80801038
    // 0x80800BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BFC:
    // 0x80800BFC: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x80800C00: beq         $t4, $zero, L_80800C18
    if (ctx->r12 == 0) {
        // 0x80800C04: nop
    
            goto L_80800C18;
    }
    // 0x80800C04: nop

    // 0x80800C08: jal         0x800D211C
    // 0x80800C0C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_5;
    // 0x80800C0C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_5:
    // 0x80800C10: b           L_80801038
    // 0x80800C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C18:
    // 0x80800C18: jal         0x8080206C
    // 0x80800C1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_6;
    // 0x80800C1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x80800C20: b           L_80801038
    // 0x80800C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C28:
    // 0x80800C28: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x80800C2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C30: beq         $v0, $at, L_80800C48
    if (ctx->r2 == ctx->r1) {
        // 0x80800C34: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C48;
    }
    // 0x80800C34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C38: beq         $v0, $at, L_80800C50
    if (ctx->r2 == ctx->r1) {
        // 0x80800C3C: nop
    
            goto L_80800C50;
    }
    // 0x80800C3C: nop

    // 0x80800C40: b           L_80801034
    // 0x80800C44: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
        goto L_80801034;
    // 0x80800C44: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
L_80800C48:
    // 0x80800C48: b           L_80801034
    // 0x80800C4C: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
        goto L_80801034;
    // 0x80800C4C: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_80800C50:
    // 0x80800C50: b           L_80801034
    // 0x80800C54: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
        goto L_80801034;
    // 0x80800C54: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x80800C58: b           L_80801034
    // 0x80800C5C: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
        goto L_80801034;
    // 0x80800C5C: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
L_80800C60:
    // 0x80800C60: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x80800C64: beq         $t5, $zero, L_80800C74
    if (ctx->r13 == 0) {
        // 0x80800C68: nop
    
            goto L_80800C74;
    }
    // 0x80800C68: nop

    // 0x80800C6C: b           L_80801034
    // 0x80800C70: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
        goto L_80801034;
    // 0x80800C70: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_80800C74:
    // 0x80800C74: b           L_80801034
    // 0x80800C78: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
        goto L_80801034;
    // 0x80800C78: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
L_80800C7C:
    // 0x80800C7C: jal         0x800D211C
    // 0x80800C80: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_7;
    // 0x80800C80: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_7:
    // 0x80800C84: b           L_80801038
    // 0x80800C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C8C:
    // 0x80800C8C: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x80800C90: beq         $t7, $zero, L_80800CA8
    if (ctx->r15 == 0) {
        // 0x80800C94: nop
    
            goto L_80800CA8;
    }
    // 0x80800C94: nop

    // 0x80800C98: jal         0x800D211C
    // 0x80800C9C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_8;
    // 0x80800C9C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_8:
    // 0x80800CA0: b           L_80801038
    // 0x80800CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CA8:
    // 0x80800CA8: b           L_80801034
    // 0x80800CAC: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
        goto L_80801034;
    // 0x80800CAC: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_80800CB0:
    // 0x80800CB0: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80800CB4: beq         $t3, $zero, L_80800CCC
    if (ctx->r11 == 0) {
        // 0x80800CB8: nop
    
            goto L_80800CCC;
    }
    // 0x80800CB8: nop

    // 0x80800CBC: jal         0x800D211C
    // 0x80800CC0: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_800D211C(rdram, ctx);
        goto after_9;
    // 0x80800CC0: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_9:
    // 0x80800CC4: b           L_80801038
    // 0x80800CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CCC:
    // 0x80800CCC: b           L_80801034
    // 0x80800CD0: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
        goto L_80801034;
    // 0x80800CD0: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
L_80800CD4:
    // 0x80800CD4: jal         0x8080206C
    // 0x80800CD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_10;
    // 0x80800CD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_10:
    // 0x80800CDC: b           L_80801038
    // 0x80800CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CE4:
    // 0x80800CE4: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80800CE8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800CEC: beq         $t8, $zero, L_80800D04
    if (ctx->r24 == 0) {
        // 0x80800CF0: nop
    
            goto L_80800D04;
    }
    // 0x80800CF0: nop

    // 0x80800CF4: jal         0x800D211C
    // 0x80800CF8: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_800D211C(rdram, ctx);
        goto after_11;
    // 0x80800CF8: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_11:
    // 0x80800CFC: b           L_80801038
    // 0x80800D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D04:
    // 0x80800D04: b           L_80801034
    // 0x80800D08: lw          $v0, 0x20($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X20);
        goto L_80801034;
    // 0x80800D08: lw          $v0, 0x20($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X20);
L_80800D0C:
    // 0x80800D0C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800D10: b           L_80801034
    // 0x80800D14: lw          $v0, 0x20($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X20);
        goto L_80801034;
    // 0x80800D14: lw          $v0, 0x20($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X20);
L_80800D18:
    // 0x80800D18: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x80800D1C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80800D20: beq         $t0, $zero, L_80800D38
    if (ctx->r8 == 0) {
        // 0x80800D24: nop
    
            goto L_80800D38;
    }
    // 0x80800D24: nop

    // 0x80800D28: jal         0x800D211C
    // 0x80800D2C: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    func_800D211C(rdram, ctx);
        goto after_12;
    // 0x80800D2C: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_12:
    // 0x80800D30: b           L_80801038
    // 0x80800D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D38:
    // 0x80800D38: b           L_80801034
    // 0x80800D3C: lw          $v0, 0x20($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X20);
        goto L_80801034;
    // 0x80800D3C: lw          $v0, 0x20($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X20);
L_80800D40:
    // 0x80800D40: jal         0x8080206C
    // 0x80800D44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_13;
    // 0x80800D44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_13:
    // 0x80800D48: b           L_80801038
    // 0x80800D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D50:
    // 0x80800D50: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x80800D54: beq         $t2, $zero, L_80800D6C
    if (ctx->r10 == 0) {
        // 0x80800D58: nop
    
            goto L_80800D6C;
    }
    // 0x80800D58: nop

    // 0x80800D5C: jal         0x800D211C
    // 0x80800D60: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_14;
    // 0x80800D60: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_14:
    // 0x80800D64: b           L_80801038
    // 0x80800D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D6C:
    // 0x80800D6C: jal         0x8080206C
    // 0x80800D70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_15;
    // 0x80800D70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_15:
    // 0x80800D74: b           L_80801038
    // 0x80800D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D7C:
    // 0x80800D7C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80800D80: b           L_80801034
    // 0x80800D84: lw          $v0, 0x20($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X20);
        goto L_80801034;
    // 0x80800D84: lw          $v0, 0x20($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X20);
L_80800D88:
    // 0x80800D88: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x80800D8C: beq         $t5, $zero, L_80800DA4
    if (ctx->r13 == 0) {
        // 0x80800D90: nop
    
            goto L_80800DA4;
    }
    // 0x80800D90: nop

    // 0x80800D94: jal         0x800D211C
    // 0x80800D98: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_16;
    // 0x80800D98: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_16:
    // 0x80800D9C: b           L_80801038
    // 0x80800DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DA4:
    // 0x80800DA4: jal         0x8080206C
    // 0x80800DA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_17;
    // 0x80800DA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_17:
    // 0x80800DAC: b           L_80801038
    // 0x80800DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801038;
    // 0x80800DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DB4:
    // 0x80800DB4: b           L_80801034
    // 0x80800DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DBC:
    // 0x80800DBC: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80800DC0: slti        $at, $v0, 0x13DA
    ctx->r1 = SIGNED(ctx->r2) < 0X13DA ? 1 : 0;
    // 0x80800DC4: bne         $at, $zero, L_80800DEC
    if (ctx->r1 != 0) {
        // 0x80800DC8: addiu       $t7, $v0, -0x141D
        ctx->r15 = ADD32(ctx->r2, -0X141D);
            goto L_80800DEC;
    }
    // 0x80800DC8: addiu       $t7, $v0, -0x141D
    ctx->r15 = ADD32(ctx->r2, -0X141D);
    // 0x80800DCC: sltiu       $at, $t7, 0x26
    ctx->r1 = ctx->r15 < 0X26 ? 1 : 0;
    // 0x80800DD0: beq         $at, $zero, L_80800F70
    if (ctx->r1 == 0) {
        // 0x80800DD4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800F70;
    }
    // 0x80800DD4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800DD8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X23F8) << 16);
    // 0x80800DDC: addu        $at, $at, $t7
    gpr jr_addend_80800DE4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800DE0: lw          $t7, 0x23F8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2336, 0X23F8));
    // 0x80800DE4: jr          $t7
    // 0x80800DE8: nop

    switch (jr_addend_80800DE4 >> 2) {
        case 0: goto L_80800ED8; break;
        case 1: goto L_80800EBC; break;
        case 2: goto L_80800EBC; break;
        case 3: goto L_80800EBC; break;
        case 4: goto L_80800EBC; break;
        case 5: goto L_80800EBC; break;
        case 6: goto L_80800E84; break;
        case 7: goto L_80800EA0; break;
        case 8: goto L_80800E34; break;
        case 9: goto L_80800F70; break;
        case 10: goto L_80800F70; break;
        case 11: goto L_80800F70; break;
        case 12: goto L_80800F70; break;
        case 13: goto L_80800F70; break;
        case 14: goto L_80800F70; break;
        case 15: goto L_80800F70; break;
        case 16: goto L_80800F70; break;
        case 17: goto L_80800F70; break;
        case 18: goto L_80800F70; break;
        case 19: goto L_80800F70; break;
        case 20: goto L_80800F70; break;
        case 21: goto L_80800F70; break;
        case 22: goto L_80800F70; break;
        case 23: goto L_80800F70; break;
        case 24: goto L_80800F70; break;
        case 25: goto L_80800F70; break;
        case 26: goto L_80800F70; break;
        case 27: goto L_80800EFC; break;
        case 28: goto L_80800EFC; break;
        case 29: goto L_80800F10; break;
        case 30: goto L_80800F10; break;
        case 31: goto L_80800F10; break;
        case 32: goto L_80800F10; break;
        case 33: goto L_80800F10; break;
        case 34: goto L_80800F10; break;
        case 35: goto L_80800F10; break;
        case 36: goto L_80800F10; break;
        case 37: goto L_80800F30; break;
        default: switch_error(__func__, 0x80800DE4, 0x808023F8);
    }
    // 0x80800DE8: nop

L_80800DEC:
    // 0x80800DEC: slti        $at, $v0, 0xCED
    ctx->r1 = SIGNED(ctx->r2) < 0XCED ? 1 : 0;
    // 0x80800DF0: bne         $at, $zero, L_80800E18
    if (ctx->r1 != 0) {
        // 0x80800DF4: addiu       $t3, $v0, -0x13CD
        ctx->r11 = ADD32(ctx->r2, -0X13CD);
            goto L_80800E18;
    }
    // 0x80800DF4: addiu       $t3, $v0, -0x13CD
    ctx->r11 = ADD32(ctx->r2, -0X13CD);
    // 0x80800DF8: sltiu       $at, $t3, 0xD
    ctx->r1 = ctx->r11 < 0XD ? 1 : 0;
    // 0x80800DFC: beq         $at, $zero, L_80800F70
    if (ctx->r1 == 0) {
        // 0x80800E00: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80800F70;
    }
    // 0x80800E00: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800E04: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X2490) << 16);
    // 0x80800E08: addu        $at, $at, $t3
    gpr jr_addend_80800E10 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80800E0C: lw          $t3, 0x2490($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2336, 0X2490));
    // 0x80800E10: jr          $t3
    // 0x80800E14: nop

    switch (jr_addend_80800E10 >> 2) {
        case 0: goto L_80800E34; break;
        case 1: goto L_80800F70; break;
        case 2: goto L_80800E34; break;
        case 3: goto L_80800E34; break;
        case 4: goto L_80800E34; break;
        case 5: goto L_80800EBC; break;
        case 6: goto L_80800E68; break;
        case 7: goto L_80800EA0; break;
        case 8: goto L_80800EBC; break;
        case 9: goto L_80800E84; break;
        case 10: goto L_80800EBC; break;
        case 11: goto L_80800EBC; break;
        case 12: goto L_80800EBC; break;
        default: switch_error(__func__, 0x80800E10, 0x80802490);
    }
    // 0x80800E14: nop

L_80800E18:
    // 0x80800E18: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80800E1C: bne         $v0, $at, L_80800F70
    if (ctx->r2 != ctx->r1) {
        // 0x80800E20: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800F70;
    }
    // 0x80800E20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E24: jal         0x80800434
    // 0x80800E28: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_18;
    // 0x80800E28: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_18:
    // 0x80800E2C: b           L_80801034
    // 0x80800E30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800E30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E34:
    // 0x80800E34: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80800E38: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800E3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E40: beq         $t8, $zero, L_80800E58
    if (ctx->r24 == 0) {
        // 0x80800E44: nop
    
            goto L_80800E58;
    }
    // 0x80800E44: nop

    // 0x80800E48: jal         0x80800434
    // 0x80800E4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_19;
    // 0x80800E4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_19:
    // 0x80800E50: b           L_80801034
    // 0x80800E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E58:
    // 0x80800E58: jal         0x80800434
    // 0x80800E5C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_20;
    // 0x80800E5C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_20:
    // 0x80800E60: b           L_80801034
    // 0x80800E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E68:
    // 0x80800E68: jal         0x808010A0
    // 0x80800E6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808010A0_chpotogoldgame(rdram, ctx);
        goto after_21;
    // 0x80800E6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_21:
    // 0x80800E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E74: jal         0x80800434
    // 0x80800E78: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_22;
    // 0x80800E78: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_22:
    // 0x80800E7C: b           L_80801034
    // 0x80800E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E84:
    // 0x80800E84: jal         0x808010A0
    // 0x80800E88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808010A0_chpotogoldgame(rdram, ctx);
        goto after_23;
    // 0x80800E88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_23:
    // 0x80800E8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E90: jal         0x80800434
    // 0x80800E94: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_24;
    // 0x80800E94: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_24:
    // 0x80800E98: b           L_80801034
    // 0x80800E9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800E9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EA0:
    // 0x80800EA0: jal         0x808010A0
    // 0x80800EA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808010A0_chpotogoldgame(rdram, ctx);
        goto after_25;
    // 0x80800EA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_25:
    // 0x80800EA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EAC: jal         0x80800434
    // 0x80800EB0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_26;
    // 0x80800EB0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_26:
    // 0x80800EB4: b           L_80801034
    // 0x80800EB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800EB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EBC:
    // 0x80800EBC: jal         0x808010A0
    // 0x80800EC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808010A0_chpotogoldgame(rdram, ctx);
        goto after_27;
    // 0x80800EC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_27:
    // 0x80800EC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EC8: jal         0x80800434
    // 0x80800ECC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_28;
    // 0x80800ECC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_28:
    // 0x80800ED0: b           L_80801034
    // 0x80800ED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800ED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800ED8:
    // 0x80800ED8: jal         0x8080227C
    // 0x80800EDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080227C_chpotogoldgame(rdram, ctx);
        goto after_29;
    // 0x80800EDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_29:
    // 0x80800EE0: jal         0x800F54E4
    // 0x80800EE4: nop

    func_800F54E4(rdram, ctx);
        goto after_30;
    // 0x80800EE4: nop

    after_30:
    // 0x80800EE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800EEC: jal         0x800F7B9C
    // 0x80800EF0: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    func_800F7B9C(rdram, ctx);
        goto after_31;
    // 0x80800EF0: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    after_31:
    // 0x80800EF4: b           L_80801034
    // 0x80800EF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800EF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EFC:
    // 0x80800EFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F00: jal         0x80800434
    // 0x80800F04: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_32;
    // 0x80800F04: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_32:
    // 0x80800F08: b           L_80801034
    // 0x80800F0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800F0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F10:
    // 0x80800F10: jal         0x808010A0
    // 0x80800F14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808010A0_chpotogoldgame(rdram, ctx);
        goto after_33;
    // 0x80800F14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_33:
    // 0x80800F18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F1C: addiu       $a1, $zero, 0x1442
    ctx->r5 = ADD32(0, 0X1442);
    // 0x80800F20: jal         0x8080219C
    // 0x80800F24: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_8080219C_chpotogoldgame(rdram, ctx);
        goto after_34;
    // 0x80800F24: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_34:
    // 0x80800F28: b           L_80801034
    // 0x80800F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F30:
    // 0x80800F30: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80800F34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F38: beq         $t9, $zero, L_80800F50
    if (ctx->r25 == 0) {
        // 0x80800F3C: nop
    
            goto L_80800F50;
    }
    // 0x80800F3C: nop

    // 0x80800F40: jal         0x80800434
    // 0x80800F44: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_35;
    // 0x80800F44: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_35:
    // 0x80800F48: b           L_80801034
    // 0x80800F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F50:
    // 0x80800F50: jal         0x8080227C
    // 0x80800F54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080227C_chpotogoldgame(rdram, ctx);
        goto after_36;
    // 0x80800F54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_36:
    // 0x80800F58: jal         0x800C0850
    // 0x80800F5C: nop

    func_800C0850(rdram, ctx);
        goto after_37;
    // 0x80800F5C: nop

    after_37:
    // 0x80800F60: jal         0x80088180
    // 0x80800F64: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_38;
    // 0x80800F64: nop

    after_38:
    // 0x80800F68: b           L_80801034
    // 0x80800F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F70:
    // 0x80800F70: b           L_80801034
    // 0x80800F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80800F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F78:
    // 0x80800F78: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800F7C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80800F80: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800F84: bne         $t6, $v1, L_80800FAC
    if (ctx->r14 != ctx->r3) {
        // 0x80800F88: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_80800FAC;
    }
    // 0x80800F88: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80800F8C: lhu         $t1, 0x72($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X72);
    // 0x80800F90: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80800F94: bne         $v0, $t2, L_80800FAC
    if (ctx->r2 != ctx->r10) {
        // 0x80800F98: nop
    
            goto L_80800FAC;
    }
    // 0x80800F98: nop

    // 0x80800F9C: jal         0x8080111C
    // 0x80800FA0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_8080111C_chpotogoldgame(rdram, ctx);
        goto after_39;
    // 0x80800FA0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_39:
    // 0x80800FA4: b           L_80801034
    // 0x80800FA8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801034;
    // 0x80800FA8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800FAC:
    // 0x80800FAC: bne         $t4, $zero, L_80800FC8
    if (ctx->r12 != 0) {
        // 0x80800FB0: lw          $t5, 0x20($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X20);
            goto L_80800FC8;
    }
    // 0x80800FB0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80800FB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FB8: jal         0x80800434
    // 0x80800FBC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_40;
    // 0x80800FBC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_40:
    // 0x80800FC0: b           L_80801034
    // 0x80800FC4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801034;
    // 0x80800FC4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800FC8:
    // 0x80800FC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800FCC: beq         $t5, $at, L_80800FDC
    if (ctx->r13 == ctx->r1) {
        // 0x80800FD0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800FDC;
    }
    // 0x80800FD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FD4: bne         $t5, $v1, L_80800FEC
    if (ctx->r13 != ctx->r3) {
        // 0x80800FD8: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80800FEC;
    }
    // 0x80800FD8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80800FDC:
    // 0x80800FDC: jal         0x80800434
    // 0x80800FE0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_41;
    // 0x80800FE0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_41:
    // 0x80800FE4: b           L_80801034
    // 0x80800FE8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801034;
    // 0x80800FE8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800FEC:
    // 0x80800FEC: jal         0x80800434
    // 0x80800FF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_42;
    // 0x80800FF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_42:
    // 0x80800FF4: b           L_80801034
    // 0x80800FF8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801034;
    // 0x80800FF8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800FFC:
    // 0x80800FFC: lhu         $t3, 0x72($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X72);
    // 0x80801000: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801004: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80801008: srl         $t8, $t3, 10
    ctx->r24 = S32(U32(ctx->r11) >> 10);
    // 0x8080100C: bne         $t8, $at, L_8080102C
    if (ctx->r24 != ctx->r1) {
        // 0x80801010: nop
    
            goto L_8080102C;
    }
    // 0x80801010: nop

    // 0x80801014: jal         0x80108B04
    // 0x80801018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_43;
    // 0x80801018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_43:
    // 0x8080101C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80801020: lbu         $t6, 0x65($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X65);
    // 0x80801024: andi        $t1, $t6, 0xFFEF
    ctx->r9 = ctx->r14 & 0XFFEF;
    // 0x80801028: sb          $t1, 0x65($t9)
    MEM_B(0X65, ctx->r25) = ctx->r9;
L_8080102C:
    // 0x8080102C: b           L_80801034
    // 0x80801030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801034;
    // 0x80801030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801034:
    // 0x80801034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801038:
    // 0x80801038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080103C: jr          $ra
    // 0x80801040: nop

    return;
    // 0x80801040: nop

;}
RECOMP_FUNC void func_808007B4_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007BC: jal         0x8080078C
    // 0x808007C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080078C_chlagoonufoint(rdram, ctx);
        goto after_0;
    // 0x808007C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808007C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808007C8: jal         0x80088848
    // 0x808007CC: sw          $v0, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r2;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808007CC: sw          $v0, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r2;
    after_1:
    // 0x808007D0: beq         $v0, $zero, L_808007E0
    if (ctx->r2 == 0) {
        // 0x808007D4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007E0;
    }
    // 0x808007D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007D8: jal         0x80102424
    // 0x808007DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808007DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
L_808007E0:
    // 0x808007E0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808007E4: addiu       $at, $zero, 0x1C7
    ctx->r1 = ADD32(0, 0X1C7);
    // 0x808007E8: lw          $t8, 0x6C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X6C);
    // 0x808007EC: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x808007F0: srl         $t0, $t9, 20
    ctx->r8 = S32(U32(ctx->r25) >> 20);
    // 0x808007F4: bnel        $t0, $at, L_80800814
    if (ctx->r8 != ctx->r1) {
        // 0x808007F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800814;
    }
    goto skip_0;
    // 0x808007F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808007FC: jal         0x800DC0C0
    // 0x80800800: nop

    func_800DC0C0(rdram, ctx);
        goto after_3;
    // 0x80800800: nop

    after_3:
    // 0x80800804: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800808: jal         0x80101EE4
    // 0x8080080C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101EE4(rdram, ctx);
        goto after_4;
    // 0x8080080C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800814:
    // 0x80800814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800818: jr          $ra
    // 0x8080081C: nop

    return;
    // 0x8080081C: nop

;}
RECOMP_FUNC void _gzthread_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A978: syscall     881
    recomp_syscall_handler(rdram, ctx, 0x8008A978);
    return;
    // 0x8008A97C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808003D0_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003D4: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x808003D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003DC: sltiu       $at, $t7, 0x11
    ctx->r1 = ctx->r15 < 0X11 ? 1 : 0;
    // 0x808003E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003E8: beq         $at, $zero, L_80800708
    if (ctx->r1 == 0) {
        // 0x808003EC: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_80800708;
    }
    // 0x808003EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808003F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808003F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2D70) << 16);
    // 0x808003F8: addu        $at, $at, $t7
    gpr jr_addend_80800400 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808003FC: lw          $t7, 0x2D70($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2D70));
    // 0x80800400: jr          $t7
    // 0x80800404: nop

    switch (jr_addend_80800400 >> 2) {
        case 0: goto L_80800408; break;
        case 1: goto L_80800428; break;
        case 2: goto L_80800458; break;
        case 3: goto L_80800474; break;
        case 4: goto L_808004AC; break;
        case 5: goto L_808004C4; break;
        case 6: goto L_808004F4; break;
        case 7: goto L_80800584; break;
        case 8: goto L_808005D8; break;
        case 9: goto L_808005E8; break;
        case 10: goto L_80800634; break;
        case 11: goto L_80800644; break;
        case 12: goto L_80800678; break;
        case 13: goto L_80800688; break;
        case 14: goto L_80800698; break;
        case 15: goto L_808006CC; break;
        case 16: goto L_808006F8; break;
        default: switch_error(__func__, 0x80800400, 0x80802D70);
    }
    // 0x80800404: nop

L_80800408:
    // 0x80800408: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8080040C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800410: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800414: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800418: jal         0x800DC178
    // 0x8080041C: nop

    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8080041C: nop

    after_0:
    // 0x80800420: b           L_80800708
    // 0x80800424: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800708;
    // 0x80800424: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800428:
    // 0x80800428: addiu       $a0, $zero, 0x13FE
    ctx->r4 = ADD32(0, 0X13FE);
    // 0x8080042C: jal         0x800DC128
    // 0x80800430: addiu       $a1, $zero, 0x1401
    ctx->r5 = ADD32(0, 0X1401);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80800430: addiu       $a1, $zero, 0x1401
    ctx->r5 = ADD32(0, 0X1401);
    after_1:
    // 0x80800434: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800438: addiu       $t8, $zero, 0x6A
    ctx->r24 = ADD32(0, 0X6A);
    // 0x8080043C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800440: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800444: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800448: jal         0x8008A208
    // 0x8080044C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x8080044C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800450: b           L_8080070C
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800458:
    // 0x80800458: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8080045C: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x80800460: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x80800464: jal         0x8080189C
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080189C_chtrashcangame(rdram, ctx);
        goto after_3;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080046C: b           L_8080070C
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800474:
    // 0x80800474: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800478: jal         0x800DC128
    // 0x8080047C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x8080047C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800480: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x80800484: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x80800490: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800494: sb          $t5, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r13;
    // 0x80800498: addiu       $a1, $zero, 0x13F1
    ctx->r5 = ADD32(0, 0X13F1);
    // 0x8080049C: jal         0x808017F0
    // 0x808004A0: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_5;
    // 0x808004A0: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_5:
    // 0x808004A4: b           L_8080070C
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004AC:
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: addiu       $a1, $zero, 0x13F2
    ctx->r5 = ADD32(0, 0X13F2);
    // 0x808004B4: jal         0x808017F0
    // 0x808004B8: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_6;
    // 0x808004B8: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_6:
    // 0x808004BC: b           L_8080070C
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004C4:
    // 0x808004C4: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x808004C8: jal         0x800D0A9C
    // 0x808004CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_7;
    // 0x808004CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808004D0: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x808004D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E0;
    }
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: b           L_808004E4
    // 0x808004DC: addiu       $a1, $zero, 0x13FD
    ctx->r5 = ADD32(0, 0X13FD);
        goto L_808004E4;
    // 0x808004DC: addiu       $a1, $zero, 0x13FD
    ctx->r5 = ADD32(0, 0X13FD);
L_808004E0:
    // 0x808004E0: addiu       $a1, $zero, 0x13F3
    ctx->r5 = ADD32(0, 0X13F3);
L_808004E4:
    // 0x808004E4: jal         0x808017F0
    // 0x808004E8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_8;
    // 0x808004E8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_8:
    // 0x808004EC: b           L_8080070C
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004F4:
    // 0x808004F4: jal         0x800D395C
    // 0x808004F8: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    func_800D395C(rdram, ctx);
        goto after_9;
    // 0x808004F8: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    after_9:
    // 0x808004FC: beq         $v0, $zero, L_8080052C
    if (ctx->r2 == 0) {
        // 0x80800500: addiu       $a0, $zero, 0x4E
        ctx->r4 = ADD32(0, 0X4E);
            goto L_8080052C;
    }
    // 0x80800500: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x80800504: addiu       $t6, $zero, 0x1444
    ctx->r14 = ADD32(0, 0X1444);
    // 0x80800508: jal         0x800F54E4
    // 0x8080050C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x8080050C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_10:
    // 0x80800510: jal         0x800F53D0
    // 0x80800514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_11;
    // 0x80800514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80800518: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080051C: jal         0x800946C4
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800946C4(rdram, ctx);
        goto after_12;
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800524: b           L_80800550
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800550;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080052C:
    // 0x8080052C: jal         0x800D0A9C
    // 0x80800530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_13;
    // 0x80800530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800534: beq         $v0, $zero, L_80800548
    if (ctx->r2 == 0) {
        // 0x80800538: addiu       $t8, $zero, 0x13F4
        ctx->r24 = ADD32(0, 0X13F4);
            goto L_80800548;
    }
    // 0x80800538: addiu       $t8, $zero, 0x13F4
    ctx->r24 = ADD32(0, 0X13F4);
    // 0x8080053C: addiu       $t7, $zero, 0x13F5
    ctx->r15 = ADD32(0, 0X13F5);
    // 0x80800540: b           L_8080054C
    // 0x80800544: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_8080054C;
    // 0x80800544: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80800548:
    // 0x80800548: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8080054C:
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800550:
    // 0x80800550: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800554: jal         0x808017F0
    // 0x80800558: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_14;
    // 0x80800558: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_14:
    // 0x8080055C: jal         0x80800000
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chtrashcangame(rdram, ctx);
        goto after_15;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800564: jal         0x80088178
    // 0x80800568: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_16;
    // 0x80800568: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    after_16:
    // 0x8080056C: addiu       $a0, $zero, 0x533
    ctx->r4 = ADD32(0, 0X533);
    // 0x80800570: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800574: jal         0x80101180
    // 0x80800578: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_17;
    // 0x80800578: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x8080057C: b           L_8080070C
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800584:
    // 0x80800584: jal         0x8080189C
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080189C_chtrashcangame(rdram, ctx);
        goto after_18;
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080058C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800590: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800594: jal         0x800CE8D8
    // 0x80800598: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_800CE8D8(rdram, ctx);
        goto after_19;
    // 0x80800598: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_19:
    // 0x8080059C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005A0: jal         0x800CE88C
    // 0x808005A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_20;
    // 0x808005A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808005A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2DB4) << 16);
    // 0x808005AC: lwc1        $f4, 0x2DB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2DB4));
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005BC: jal         0x80800098
    // 0x808005C0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80800098_chtrashcangame(rdram, ctx);
        goto after_21;
    // 0x808005C0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_21:
    // 0x808005C4: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x808005C8: jal         0x800FDC28
    // 0x808005CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800FDC28(rdram, ctx);
        goto after_22;
    // 0x808005CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_22:
    // 0x808005D0: b           L_8080070C
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005D8:
    // 0x808005D8: jal         0x800FC6B0
    // 0x808005DC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_23;
    // 0x808005DC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_23:
    // 0x808005E0: b           L_8080070C
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005E8:
    // 0x808005E8: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x808005EC: jal         0x800D0A9C
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_24;
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x808005F4: beq         $v0, $zero, L_80800604
    if (ctx->r2 == 0) {
        // 0x808005F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800604;
    }
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: b           L_80800608
    // 0x80800600: addiu       $a1, $zero, 0x13FC
    ctx->r5 = ADD32(0, 0X13FC);
        goto L_80800608;
    // 0x80800600: addiu       $a1, $zero, 0x13FC
    ctx->r5 = ADD32(0, 0X13FC);
L_80800604:
    // 0x80800604: addiu       $a1, $zero, 0x13FB
    ctx->r5 = ADD32(0, 0X13FB);
L_80800608:
    // 0x80800608: jal         0x808017F0
    // 0x8080060C: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_25;
    // 0x8080060C: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_25:
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: jal         0x80800014
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_26;
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x8080061C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800620: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x80800624: jal         0x800D2054
    // 0x80800628: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800D2054(rdram, ctx);
        goto after_27;
    // 0x80800628: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_27:
    // 0x8080062C: b           L_8080070C
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800634:
    // 0x80800634: jal         0x800FC6B0
    // 0x80800638: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_28;
    // 0x80800638: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_28:
    // 0x8080063C: b           L_8080070C
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800644:
    // 0x80800644: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x80800648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080064C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800650: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80800654: jal         0x800D1000
    // 0x80800658: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_29;
    // 0x80800658: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_29:
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800660: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800664: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800668: jal         0x808016B4
    // 0x8080066C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_808016B4_chtrashcangame(rdram, ctx);
        goto after_30;
    // 0x8080066C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_30:
    // 0x80800670: b           L_8080070C
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800678:
    // 0x80800678: jal         0x8080189C
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080189C_chtrashcangame(rdram, ctx);
        goto after_31;
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800680: b           L_8080070C
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800688:
    // 0x80800688: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080068C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800690: b           L_80800708
    // 0x80800694: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800708;
    // 0x80800694: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800698:
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: addiu       $a1, $zero, 0x13FC
    ctx->r5 = ADD32(0, 0X13FC);
    // 0x808006A0: jal         0x808017F0
    // 0x808006A4: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_32;
    // 0x808006A4: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_32:
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006AC: jal         0x80800014
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_33;
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x808006B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808006B8: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x808006BC: jal         0x800D2054
    // 0x808006C0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800D2054(rdram, ctx);
        goto after_34;
    // 0x808006C0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_34:
    // 0x808006C4: b           L_8080070C
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006CC:
    // 0x808006CC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x808006D0: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x808006D4: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x808006D8: jal         0x8080189C
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080189C_chtrashcangame(rdram, ctx);
        goto after_35;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: addiu       $a1, $zero, 0x1443
    ctx->r5 = ADD32(0, 0X1443);
    // 0x808006E8: jal         0x808017F0
    // 0x808006EC: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_36;
    // 0x808006EC: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_36:
    // 0x808006F0: b           L_8080070C
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080070C;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006F8:
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006FC: addiu       $a1, $zero, 0x1451
    ctx->r5 = ADD32(0, 0X1451);
    // 0x80800700: jal         0x808017F0
    // 0x80800704: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_37;
    // 0x80800704: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_37:
L_80800708:
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080070C:
    // 0x8080070C: jal         0x80102424
    // 0x80800710: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80102424(rdram, ctx);
        goto after_38;
    // 0x80800710: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_38:
    // 0x80800714: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800718: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080071C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800720: jr          $ra
    // 0x80800724: nop

    return;
    // 0x80800724: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080018C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800190: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800198: jal         0x8010F9C0
    // 0x8080019C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8010F9C0(rdram, ctx);
        goto after_0;
    // 0x8080019C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808001A0: jal         0x8011001C
    // 0x808001A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8011001C(rdram, ctx);
        goto after_1;
    // 0x808001A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001AC: jal         0x80800150
    // 0x808001B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    ncfixposrot_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808001B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808001B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
RECOMP_FUNC void func_80800A48_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A50: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800A54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800A58: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800A5C: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80800A60: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800A64: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800A68: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800A6C: nop

    // 0x80800A70: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800A74: beql        $t7, $zero, L_80800AC4
    if (ctx->r15 == 0) {
        // 0x80800A78: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_80800AC4;
    }
    goto skip_0;
    // 0x80800A78: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80800A7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800A84: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800A88: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800A8C: nop

    // 0x80800A90: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800A94: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800A98: nop

    // 0x80800A9C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800AA0: bne         $t7, $zero, L_80800AB8
    if (ctx->r15 != 0) {
        // 0x80800AA4: nop
    
            goto L_80800AB8;
    }
    // 0x80800AA4: nop

    // 0x80800AA8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800AAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800AB0: b           L_80800AD0
    // 0x80800AB4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80800AD0;
    // 0x80800AB4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800AB8:
    // 0x80800AB8: b           L_80800AD0
    // 0x80800ABC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80800AD0;
    // 0x80800ABC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800AC0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_80800AC4:
    // 0x80800AC4: nop

    // 0x80800AC8: bltz        $t7, L_80800AB8
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800ACC: nop
    
            goto L_80800AB8;
    }
    // 0x80800ACC: nop

L_80800AD0:
    // 0x80800AD0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800AD4: sltiu       $at, $t7, 0x1B
    ctx->r1 = ctx->r15 < 0X1B ? 1 : 0;
    // 0x80800AD8: beq         $at, $zero, L_80800B98
    if (ctx->r1 == 0) {
        // 0x80800ADC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800B98;
    }
    // 0x80800ADC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800AE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1604, 0XD74) << 16);
    // 0x80800AE4: addu        $at, $at, $t7
    gpr jr_addend_80800AEC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800AE8: lw          $t7, 0xD74($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1604, 0XD74));
    // 0x80800AEC: jr          $t7
    // 0x80800AF0: nop

    switch (jr_addend_80800AEC >> 2) {
        case 0: goto L_80800B30; break;
        case 1: goto L_80800AF4; break;
        case 2: goto L_80800B08; break;
        case 3: goto L_80800B44; break;
        case 4: goto L_80800B1C; break;
        case 5: goto L_80800B6C; break;
        case 6: goto L_80800B80; break;
        case 7: goto L_80800B58; break;
        case 8: goto L_80800B98; break;
        case 9: goto L_80800B98; break;
        case 10: goto L_80800B90; break;
        case 11: goto L_80800B90; break;
        case 12: goto L_80800B90; break;
        case 13: goto L_80800B90; break;
        case 14: goto L_80800B90; break;
        case 15: goto L_80800B90; break;
        case 16: goto L_80800B90; break;
        case 17: goto L_80800B90; break;
        case 18: goto L_80800B90; break;
        case 19: goto L_80800B90; break;
        case 20: goto L_80800B90; break;
        case 21: goto L_80800B90; break;
        case 22: goto L_80800B90; break;
        case 23: goto L_80800B90; break;
        case 24: goto L_80800B90; break;
        case 25: goto L_80800B90; break;
        case 26: goto L_80800B90; break;
        default: switch_error(__func__, 0x80800AEC, 0x80800D74);
    }
    // 0x80800AF0: nop

L_80800AF4:
    // 0x80800AF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800AF8: jal         0x80800988
    // 0x80800AFC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80800988_chmole_training(rdram, ctx);
        goto after_0;
    // 0x80800AFC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80800B00: b           L_80800B9C
    // 0x80800B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B9C;
    // 0x80800B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B08:
    // 0x80800B08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800B0C: jal         0x80800988
    // 0x80800B10: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80800988_chmole_training(rdram, ctx);
        goto after_1;
    // 0x80800B10: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80800B14: b           L_80800B9C
    // 0x80800B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B9C;
    // 0x80800B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B1C:
    // 0x80800B1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800B20: jal         0x80800988
    // 0x80800B24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80800988_chmole_training(rdram, ctx);
        goto after_2;
    // 0x80800B24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80800B28: b           L_80800B9C
    // 0x80800B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B9C;
    // 0x80800B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B30:
    // 0x80800B30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B34: jal         0x80800988
    // 0x80800B38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800988_chmole_training(rdram, ctx);
        goto after_3;
    // 0x80800B38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x80800B3C: b           L_80800B9C
    // 0x80800B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B9C;
    // 0x80800B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B44:
    // 0x80800B44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B48: jal         0x80800988
    // 0x80800B4C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800988_chmole_training(rdram, ctx);
        goto after_4;
    // 0x80800B4C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80800B50: b           L_80800B9C
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B9C;
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B58:
    // 0x80800B58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B5C: jal         0x80800988
    // 0x80800B60: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800988_chmole_training(rdram, ctx);
        goto after_5;
    // 0x80800B60: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x80800B64: b           L_80800B9C
    // 0x80800B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B9C;
    // 0x80800B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B6C:
    // 0x80800B6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B70: jal         0x80800988
    // 0x80800B74: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800988_chmole_training(rdram, ctx);
        goto after_6;
    // 0x80800B74: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x80800B78: b           L_80800B9C
    // 0x80800B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B9C;
    // 0x80800B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B80:
    // 0x80800B80: jal         0x80101FDC
    // 0x80800B84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800B84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x80800B88: b           L_80800B9C
    // 0x80800B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B9C;
    // 0x80800B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B90:
    // 0x80800B90: jal         0x80101FDC
    // 0x80800B94: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80800B94: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
L_80800B98:
    // 0x80800B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B9C:
    // 0x80800B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BA0: jr          $ra
    // 0x80800BA4: nop

    return;
    // 0x80800BA4: nop

;}
RECOMP_FUNC void _gspropprop_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C28: syscall     729
    recomp_syscall_handler(rdram, ctx, 0x80088C28);
    return;
    // 0x80088C2C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800668_chsunlightspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800668: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080066C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800670: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800674: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800678: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8080067C: jal         0x800BFFB4
    // 0x80800680: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BFFB4(rdram, ctx);
        goto after_0;
    // 0x80800680: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800684: beql        $v0, $zero, L_808006F8
    if (ctx->r2 == 0) {
        // 0x80800688: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808006F8;
    }
    goto skip_0;
    // 0x80800688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080068C: jal         0x800E3980
    // 0x80800690: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800E3980(rdram, ctx);
        goto after_1;
    // 0x80800690: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800694: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800698: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080069C: jal         0x800F18FC
    // 0x808006A0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800F18FC(rdram, ctx);
        goto after_2;
    // 0x808006A0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x808006A4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808006A8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x808006AC: jal         0x800EEBF0
    // 0x808006B0: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    func_800EEBF0(rdram, ctx);
        goto after_3;
    // 0x808006B0: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    after_3:
    // 0x808006B4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808006B8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808006BC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x808006C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808006C4: jal         0x800EE780
    // 0x808006C8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800EE780(rdram, ctx);
        goto after_4;
    // 0x808006C8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_4:
    // 0x808006CC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2244, 0X8B0) << 16);
    // 0x808006D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808006D4: addiu       $a1, $a1, 0x8B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2244, 0X8B0));
    // 0x808006D8: jal         0x800F18FC
    // 0x808006DC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800F18FC(rdram, ctx);
        goto after_5;
    // 0x808006DC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x808006E0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808006E4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808006E8: swc1        $f4, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f4.u32l;
    // 0x808006EC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808006F0: swc1        $f6, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f6.u32l;
    // 0x808006F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006F8:
    // 0x808006F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808006FC: jr          $ra
    // 0x80800700: nop

    return;
    // 0x80800700: nop

;}
RECOMP_FUNC void func_8010A2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A2FC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8010A300: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8010A304: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8010A308: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8010A30C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8010A310: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010A314: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8010A318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010A31C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8010A320: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8010A324: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010A328: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010A32C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8010A330: jal         0x8010108C
    // 0x8010A334: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    func_8010108C(rdram, ctx);
        goto after_0;
    // 0x8010A334: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    after_0:
    // 0x8010A338: blez        $v0, L_8010A3B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8010A33C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8010A3B4;
    }
    // 0x8010A33C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8010A340: jal         0x80101080
    // 0x8010A344: nop

    func_80101080(rdram, ctx);
        goto after_1;
    // 0x8010A344: nop

    after_1:
    // 0x8010A348: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x8010A34C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A350: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010A354: lwc1        $f22, 0x64B4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X64B4);
    // 0x8010A358: beq         $s2, $zero, L_8010A3C0
    if (ctx->r18 == 0) {
        // 0x8010A35C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8010A3C0;
    }
    // 0x8010A35C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8010A360: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
L_8010A364:
    // 0x8010A364: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010A368: jal         0x800EE7F8
    // 0x8010A36C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8010A36C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8010A370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010A374: jal         0x800EEB40
    // 0x8010A378: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x8010A378: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x8010A37C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8010A380: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8010A384: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8010A388: bc1fl       L_8010A3A0
    if (!c1cs) {
        // 0x8010A38C: or          $v1, $s2, $zero
        ctx->r3 = ctx->r18 | 0;
            goto L_8010A3A0;
    }
    goto skip_0;
    // 0x8010A38C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    skip_0:
    // 0x8010A390: jal         0x800EE7F8
    // 0x8010A394: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8010A394: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8010A398: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x8010A39C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_8010A3A0:
    // 0x8010A3A0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8010A3A4: bne         $s2, $zero, L_8010A364
    if (ctx->r18 != 0) {
        // 0x8010A3A8: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8010A364;
    }
    // 0x8010A3A8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8010A3AC: b           L_8010A3C4
    // 0x8010A3B0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8010A3C4;
    // 0x8010A3B0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8010A3B4:
    // 0x8010A3B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8010A3B8: jal         0x800EC75C
    // 0x8010A3BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EC75C(rdram, ctx);
        goto after_5;
    // 0x8010A3BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
L_8010A3C0:
    // 0x8010A3C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8010A3C4:
    // 0x8010A3C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010A3C8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010A3CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8010A3D0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8010A3D4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8010A3D8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8010A3DC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8010A3E0: jr          $ra
    // 0x8010A3E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8010A3E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80800424_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080042C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800430: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800434: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800438: jal         0x801040D0
    // 0x8080043C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_801040D0(rdram, ctx);
        goto after_0;
    // 0x8080043C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800440: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800444: jal         0x801015D0
    // 0x80800448: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x80800448: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8080044C: jal         0x800DF41C
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF41C(rdram, ctx);
        goto after_2;
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800454: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800458: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080045C: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x80800460: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800464: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800468: jal         0x800EFA4C
    // 0x8080046C: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x8080046C: nop

    after_3:
    // 0x80800470: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800474: jal         0x800D93A0
    // 0x80800478: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800D93A0(rdram, ctx);
        goto after_4;
    // 0x80800478: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80800484: jal         0x800DFF2C
    // 0x80800488: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800DFF2C(rdram, ctx);
        goto after_5;
    // 0x80800488: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x8080048C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800490: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800494: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x80800498: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080049C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808004A0: jal         0x800EFA4C
    // 0x808004A4: nop

    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x808004A4: nop

    after_6:
    // 0x808004A8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808004AC: jal         0x800D93A0
    // 0x808004B0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800D93A0(rdram, ctx);
        goto after_7;
    // 0x808004B0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_7:
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x808004BC: jal         0x800DFF2C
    // 0x808004C0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800DFF2C(rdram, ctx);
        goto after_8;
    // 0x808004C0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_8:
    // 0x808004C4: jal         0x800B27E0
    // 0x808004C8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800B27E0(rdram, ctx);
        goto after_9;
    // 0x808004C8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_9:
    // 0x808004CC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x808004D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808004D8: jal         0x800AE1E8
    // 0x808004DC: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_800AE1E8(rdram, ctx);
        goto after_10;
    // 0x808004DC: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_10:
    // 0x808004E0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x808004E4: jal         0x800AE080
    // 0x808004E8: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    func_800AE080(rdram, ctx);
        goto after_11;
    // 0x808004E8: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    after_11:
    // 0x808004EC: jal         0x800DF72C
    // 0x808004F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF72C(rdram, ctx);
        goto after_12;
    // 0x808004F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x808004F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808004FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800500: jr          $ra
    // 0x80800504: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800504: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bsjump_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A7C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800A80: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800A84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800A88: jal         0x8008CABC
    // 0x80800A8C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800A8C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800A90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A98: jal         0x8009BB24
    // 0x80800A9C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_1;
    // 0x80800A9C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800AA0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800AA4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800AA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AAC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800AB0: nop

    // 0x80800AB4: bc1fl       L_80800AC8
    if (!c1cs) {
        // 0x80800AB8: lw          $v0, 0x15C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X15C);
            goto L_80800AC8;
    }
    goto skip_0;
    // 0x80800AB8: lw          $v0, 0x15C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X15C);
    skip_0:
    // 0x80800ABC: jal         0x800961AC
    // 0x80800AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_2;
    // 0x80800AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800AC4: lw          $v0, 0x15C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X15C);
L_80800AC8:
    // 0x80800AC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800ACC: beq         $v0, $zero, L_80800AF0
    if (ctx->r2 == 0) {
        // 0x80800AD0: nop
    
            goto L_80800AF0;
    }
    // 0x80800AD0: nop

    // 0x80800AD4: beq         $v0, $at, L_80800B78
    if (ctx->r2 == ctx->r1) {
        // 0x80800AD8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800B78;
    }
    // 0x80800AD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800ADC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AE0: beq         $v0, $at, L_80800BB4
    if (ctx->r2 == ctx->r1) {
        // 0x80800AE4: nop
    
            goto L_80800BB4;
    }
    // 0x80800AE4: nop

    // 0x80800AE8: b           L_80800BB4
    // 0x80800AEC: nop

        goto L_80800BB4;
    // 0x80800AEC: nop

L_80800AF0:
    // 0x80800AF0: jal         0x8008B324
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_3;
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800AF8: beq         $v0, $zero, L_80800B30
    if (ctx->r2 == 0) {
        // 0x80800AFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B30;
    }
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B00: lui         $a2, 0x3F2A
    ctx->r6 = S32(0X3F2A << 16);
    // 0x80800B04: ori         $a2, $a2, 0xACDA
    ctx->r6 = ctx->r6 | 0XACDA;
    // 0x80800B08: jal         0x8008B1D4
    // 0x80800B0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x80800B0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B14: jal         0x8008B1BC
    // 0x80800B18: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80800B18: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_5:
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B20: jal         0x8008B134
    // 0x80800B24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800B24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800B28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800B2C: sw          $t6, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r14;
L_80800B30:
    // 0x80800B30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B34: jal         0x8008DF8C
    // 0x80800B38: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_7;
    // 0x80800B38: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_7:
    // 0x80800B3C: beq         $v0, $zero, L_80800BB4
    if (ctx->r2 == 0) {
        // 0x80800B40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BB4;
    }
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B44: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800B48: jal         0x8008B1D4
    // 0x80800B4C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_8;
    // 0x80800B4C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_8:
    // 0x80800B50: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800B54: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800B58: jal         0x8008B1BC
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_9;
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B64: jal         0x8008B134
    // 0x80800B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_10;
    // 0x80800B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800B6C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800B70: b           L_80800BB4
    // 0x80800B74: sw          $t7, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r15;
        goto L_80800BB4;
    // 0x80800B74: sw          $t7, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r15;
L_80800B78:
    // 0x80800B78: jal         0x8008DF8C
    // 0x80800B7C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_11;
    // 0x80800B7C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_11:
    // 0x80800B80: beq         $v0, $zero, L_80800BB4
    if (ctx->r2 == 0) {
        // 0x80800B84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BB4;
    }
    // 0x80800B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B88: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800B8C: jal         0x8008B1D4
    // 0x80800B90: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_12;
    // 0x80800B90: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_12:
    // 0x80800B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B98: jal         0x8008B1BC
    // 0x80800B9C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_13;
    // 0x80800B9C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_13:
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA4: jal         0x8008B134
    // 0x80800BA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_14;
    // 0x80800BA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800BAC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80800BB0: sw          $t8, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r24;
L_80800BB4:
    // 0x80800BB4: jal         0x8008DA24
    // 0x80800BB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008DA24(rdram, ctx);
        goto after_15;
    // 0x80800BB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800BBC: beq         $v0, $zero, L_80800BC8
    if (ctx->r2 == 0) {
        // 0x80800BC0: addiu       $t9, $zero, 0xA8
        ctx->r25 = ADD32(0, 0XA8);
            goto L_80800BC8;
    }
    // 0x80800BC0: addiu       $t9, $zero, 0xA8
    ctx->r25 = ADD32(0, 0XA8);
    // 0x80800BC4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800BC8:
    // 0x80800BC8: jal         0x8008E078
    // 0x80800BCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    player_isStable(rdram, ctx);
        goto after_16;
    // 0x80800BCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800BD0: beql        $v0, $zero, L_80800BEC
    if (ctx->r2 == 0) {
        // 0x80800BD4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800BEC;
    }
    goto skip_1;
    // 0x80800BD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x80800BD8: jal         0x8009FE58
    // 0x80800BDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009FE58(rdram, ctx);
        goto after_17;
    // 0x80800BDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800BE0: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x80800BE4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80800BE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800BEC:
    // 0x80800BEC: jal         0x8009E5C8
    // 0x80800BF0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_18;
    // 0x80800BF0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_18:
    // 0x80800BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BF8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800BFC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800C00: jr          $ra
    // 0x80800C04: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800C04: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void vpglow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x808001E4: addu        $v0, $t6, $a2
    ctx->r2 = ADD32(ctx->r14, ctx->r6);
    // 0x808001E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808001EC: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x808001F0: beq         $at, $zero, L_80800408
    if (ctx->r1 == 0) {
        // 0x808001F4: lwc1        $f0, 0x0($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
            goto L_80800408;
    }
    // 0x808001F4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_808001F8:
    // 0x808001F8: lbu         $t7, 0xC($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0XC);
    // 0x808001FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800200: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800204: bgez        $t7, L_80800218
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800208: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800218;
    }
    // 0x80800208: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080020C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800210: nop

    // 0x80800214: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800218:
    // 0x80800218: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8080021C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800220: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800224: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800228: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8080022C: nop

    // 0x80800230: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800234: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800238: nop

    // 0x8080023C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800240: beql        $t9, $zero, L_80800290
    if (ctx->r25 == 0) {
        // 0x80800244: mfc1        $t9, $f16
        ctx->r25 = (int32_t)ctx->f16.u32l;
            goto L_80800290;
    }
    goto skip_0;
    // 0x80800244: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80800248: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080024C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800250: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800254: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800258: nop

    // 0x8080025C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800260: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800264: nop

    // 0x80800268: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8080026C: bne         $t9, $zero, L_80800284
    if (ctx->r25 != 0) {
        // 0x80800270: nop
    
            goto L_80800284;
    }
    // 0x80800270: nop

    // 0x80800274: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80800278: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080027C: b           L_8080029C
    // 0x80800280: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8080029C;
    // 0x80800280: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80800284:
    // 0x80800284: b           L_8080029C
    // 0x80800288: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8080029C;
    // 0x80800288: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8080028C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
L_80800290:
    // 0x80800290: nop

    // 0x80800294: bltz        $t9, L_80800284
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800298: nop
    
            goto L_80800284;
    }
    // 0x80800298: nop

L_8080029C:
    // 0x8080029C: lbu         $t0, 0xD($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XD);
    // 0x808002A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x808002A4: sb          $t9, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r25;
    // 0x808002A8: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x808002AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808002B0: bgez        $t0, L_808002C4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808002B4: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_808002C4;
    }
    // 0x808002B4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808002B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002BC: nop

    // 0x808002C0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_808002C4:
    // 0x808002C4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808002C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808002CC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808002D0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x808002D4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x808002D8: nop

    // 0x808002DC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808002E0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x808002E4: nop

    // 0x808002E8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x808002EC: beql        $t2, $zero, L_8080033C
    if (ctx->r10 == 0) {
        // 0x808002F0: mfc1        $t2, $f10
        ctx->r10 = (int32_t)ctx->f10.u32l;
            goto L_8080033C;
    }
    goto skip_1;
    // 0x808002F0: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x808002F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002F8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808002FC: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800300: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800304: nop

    // 0x80800308: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8080030C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800310: nop

    // 0x80800314: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80800318: bne         $t2, $zero, L_80800330
    if (ctx->r10 != 0) {
        // 0x8080031C: nop
    
            goto L_80800330;
    }
    // 0x8080031C: nop

    // 0x80800320: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80800324: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800328: b           L_80800348
    // 0x8080032C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80800348;
    // 0x8080032C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80800330:
    // 0x80800330: b           L_80800348
    // 0x80800334: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80800348;
    // 0x80800334: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80800338: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
L_8080033C:
    // 0x8080033C: nop

    // 0x80800340: bltz        $t2, L_80800330
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800344: nop
    
            goto L_80800330;
    }
    // 0x80800344: nop

L_80800348:
    // 0x80800348: lbu         $t3, 0xE($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XE);
    // 0x8080034C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800350: sb          $t2, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r10;
    // 0x80800354: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80800358: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080035C: bgez        $t3, L_80800370
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800360: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80800370;
    }
    // 0x80800360: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800364: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800368: nop

    // 0x8080036C: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80800370:
    // 0x80800370: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800374: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800378: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080037C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800380: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800384: nop

    // 0x80800388: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8080038C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80800390: nop

    // 0x80800394: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80800398: beql        $t5, $zero, L_808003E8
    if (ctx->r13 == 0) {
        // 0x8080039C: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_808003E8;
    }
    goto skip_2;
    // 0x8080039C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x808003A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808003A8: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808003AC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x808003B0: nop

    // 0x808003B4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808003B8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x808003BC: nop

    // 0x808003C0: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x808003C4: bne         $t5, $zero, L_808003DC
    if (ctx->r13 != 0) {
        // 0x808003C8: nop
    
            goto L_808003DC;
    }
    // 0x808003C8: nop

    // 0x808003CC: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x808003D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808003D4: b           L_808003F4
    // 0x808003D8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_808003F4;
    // 0x808003D8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_808003DC:
    // 0x808003DC: b           L_808003F4
    // 0x808003E0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_808003F4;
    // 0x808003E0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808003E4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_808003E8:
    // 0x808003E8: nop

    // 0x808003EC: bltz        $t5, L_808003DC
    if (SIGNED(ctx->r13) < 0) {
        // 0x808003F0: nop
    
            goto L_808003DC;
    }
    // 0x808003F0: nop

L_808003F4:
    // 0x808003F4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x808003F8: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x808003FC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80800400: bne         $at, $zero, L_808001F8
    if (ctx->r1 != 0) {
        // 0x80800404: sb          $t5, -0x2($a2)
        MEM_B(-0X2, ctx->r6) = ctx->r13;
            goto L_808001F8;
    }
    // 0x80800404: sb          $t5, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r13;
L_80800408:
    // 0x80800408: jr          $ra
    // 0x8080040C: nop

    return;
    // 0x8080040C: nop

;}
RECOMP_FUNC void func_80800054_choctopus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800058: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800060: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800064: jal         0x80100094
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080006C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800070: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: jal         0x80089F40
    // 0x8080007C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _subaddiesect_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080007C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80800080: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80800084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800088: beq         $t6, $zero, L_80800098
    if (ctx->r14 == 0) {
        // 0x8080008C: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80800098;
    }
    // 0x8080008C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800090: jal         0x800897D8
    // 0x80800094: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800094: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_2:
L_80800098:
    // 0x80800098: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
    // 0x8080009C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1028, 0X93C) << 16);
    // 0x808000A0: addiu       $t9, $t9, 0x93C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1028, 0X93C));
    // 0x808000A4: srl         $t7, $a2, 10
    ctx->r15 = S32(U32(ctx->r6) >> 10);
    // 0x808000A8: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x808000AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808000B4: sltiu       $a2, $t8, 0x1
    ctx->r6 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x808000B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: jal         0x80089D58
    // 0x808000C4: addiu       $a3, $zero, 0x1194
    ctx->r7 = ADD32(0, 0X1194);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808000C4: addiu       $a3, $zero, 0x1194
    ctx->r7 = ADD32(0, 0X1194);
    after_3:
    // 0x808000C8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808000CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000D0: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x808000D4: beq         $t0, $at, L_808001FC
    if (ctx->r8 == ctx->r1) {
        // 0x808000D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001FC;
    }
    // 0x808000D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000DC: beq         $t0, $at, L_80800100
    if (ctx->r8 == ctx->r1) {
        // 0x808000E0: lui         $a2, 0x3FA0
        ctx->r6 = S32(0X3FA0 << 16);
            goto L_80800100;
    }
    // 0x808000E0: lui         $a2, 0x3FA0
    ctx->r6 = S32(0X3FA0 << 16);
    // 0x808000E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000E8: beq         $t0, $at, L_80800150
    if (ctx->r8 == ctx->r1) {
        // 0x808000EC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800150;
    }
    // 0x808000EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000F0: beq         $t0, $at, L_80800198
    if (ctx->r8 == ctx->r1) {
        // 0x808000F4: lui         $a2, 0x4070
        ctx->r6 = S32(0X4070 << 16);
            goto L_80800198;
    }
    // 0x808000F4: lui         $a2, 0x4070
    ctx->r6 = S32(0X4070 << 16);
    // 0x808000F8: b           L_80800200
    // 0x808000FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800200;
    // 0x808000FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800100:
    // 0x80800100: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1028, 0X8D4) << 16);
    // 0x80800104: lwc1        $f4, 0x8D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1028, 0X8D4));
    // 0x80800108: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080010C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800110: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80800114: jal         0x800F10B4
    // 0x80800118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8080011C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800120: jal         0x80101CDC
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_5;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800128: jal         0x800D9078
    // 0x8080012C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x8080012C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x80800130: beq         $v0, $zero, L_808001FC
    if (ctx->r2 == 0) {
        // 0x80800134: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001FC;
    }
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x80102424
    // 0x8080013C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x8080013C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800140: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800144: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800148: b           L_808001FC
    // 0x8080014C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808001FC;
    // 0x8080014C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800150:
    // 0x80800150: jal         0x800D9078
    // 0x80800154: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x80800154: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x80800158: beq         $v0, $zero, L_808001FC
    if (ctx->r2 == 0) {
        // 0x8080015C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001FC;
    }
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1028, 0X8C0) << 16);
    // 0x80800164: addiu       $a2, $a2, 0x8C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1028, 0X8C0));
    // 0x80800168: jal         0x80089D18
    // 0x8080016C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x8080016C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x80102424
    // 0x80800178: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x80800178: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: jal         0x80101CDC
    // 0x80800184: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    func_80101CDC(rdram, ctx);
        goto after_11;
    // 0x80800184: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_11:
    // 0x80800188: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x8080018C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800190: b           L_808001FC
    // 0x80800194: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_808001FC;
    // 0x80800194: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800198:
    // 0x80800198: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080019C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001A0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001A8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1028, 0X8D4) << 16);
    // 0x808001AC: lw          $a3, 0x8D4($a3)
    ctx->r7 = MEM_W(ctx->r7, (int16_t)RELOC_LO16(1028, 0X8D4));
    // 0x808001B0: jal         0x800F10B4
    // 0x808001B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x808001B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x808001B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001BC: jal         0x80101CDC
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_13;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001C4: jal         0x800D9078
    // 0x808001C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_14;
    // 0x808001C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_14:
    // 0x808001CC: beq         $v0, $zero, L_808001FC
    if (ctx->r2 == 0) {
        // 0x808001D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001FC;
    }
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: jal         0x80102424
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808001DC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x808001E0: beq         $t1, $zero, L_808001F0
    if (ctx->r9 == 0) {
        // 0x808001E4: or          $a0, $t1, $zero
        ctx->r4 = ctx->r9 | 0;
            goto L_808001F0;
    }
    // 0x808001E4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x808001E8: jal         0x80089818
    // 0x808001EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_16;
    // 0x808001EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
L_808001F0:
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: jal         0x8008A4B0
    // 0x808001F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x808001F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
L_808001FC:
    // 0x808001FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800200:
    // 0x80800200: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800204: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void chbouncycastle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1000, 0X9C0) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x9C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1000, 0X9C0));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x9C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1000, 0X9C0));
;}
RECOMP_FUNC void func_800F13F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F13F0: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x800F13F4: nop

    // 0x800F13F8: bc1fl       L_800F1410
    if (!c1cs) {
        // 0x800F13FC: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_800F1410;
    }
    goto skip_0;
    // 0x800F13FC: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_0:
    // 0x800F1400: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800F1404: jr          $ra
    // 0x800F1408: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x800F1408: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F140C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_800F1410:
    // 0x800F1410: jr          $ra
    // 0x800F1414: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800F1414: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80800284_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080028C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800290: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800294: jal         0x8010C9B0
    // 0x80800298: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010C9B0(rdram, ctx);
        goto after_0;
    // 0x80800298: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_0:
    // 0x8080029C: bne         $v0, $zero, L_808002AC
    if (ctx->r2 != 0) {
        // 0x808002A0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002AC;
    }
    // 0x808002A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002A4: jal         0x80102424
    // 0x808002A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808002A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
L_808002AC:
    // 0x808002AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002B4: jr          $ra
    // 0x808002B8: nop

    return;
    // 0x808002B8: nop

;}
RECOMP_FUNC void _ncba1p_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089420: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x80089420);
    return;
    // 0x80089424: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800034_chbanjocurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80800038: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8080003C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800040: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80800044: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80800048: jr          $ra
    // 0x8080004C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    return;
    // 0x8080004C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800E7188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7188: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800E718C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E7190: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E7194: beq         $v0, $zero, L_800E71B0
    if (ctx->r2 == 0) {
        // 0x800E7198: nop
    
            goto L_800E71B0;
    }
    // 0x800E7198: nop

    // 0x800E719C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800E71A0:
    // 0x800E71A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E71A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E71A8: bnel        $v0, $zero, L_800E71A0
    if (ctx->r2 != 0) {
        // 0x800E71AC: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800E71A0;
    }
    goto skip_0;
    // 0x800E71AC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_0:
L_800E71B0:
    // 0x800E71B0: jr          $ra
    // 0x800E71B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800E71B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800E7928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7928: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E792C: addiu       $v0, $v0, -0x2A80
    ctx->r2 = ADD32(ctx->r2, -0X2A80);
    // 0x800E7930: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800E7934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E793C: beql        $a1, $t6, L_800E797C
    if (ctx->r5 == ctx->r14) {
        // 0x800E7940: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E797C;
    }
    goto skip_0;
    // 0x800E7940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E7944: sw          $a1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r5;
    // 0x800E7948: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E794C: jal         0x800E765C
    // 0x800E7950: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800E765C(rdram, ctx);
        goto after_0;
    // 0x800E7950: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E7954: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E7958: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800E795C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800E7960: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E7964: ori         $t8, $t8, 0x1001
    ctx->r24 = ctx->r24 | 0X1001;
    // 0x800E7968: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800E796C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800E7970: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x800E7974: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800E7978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E797C:
    // 0x800E797C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7980: jr          $ra
    // 0x800E7984: nop

    return;
    // 0x800E7984: nop

;}
RECOMP_FUNC void bsvan_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080074C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800750: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(427, 0X1C8C) << 16);
    // 0x80800754: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800758: jr          $ra
    // 0x8080075C: lw          $v0, 0x1C8C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1C8C));
    return;
    // 0x8080075C: lw          $v0, 0x1C8C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1C8C));
;}
RECOMP_FUNC void func_8009D2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D2F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009D2F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D2F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009D2FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009D300: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8009D304: jal         0x80096628
    // 0x8009D308: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_80096628(rdram, ctx);
        goto after_0;
    // 0x8009D308: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x8009D30C: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8009D310: bne         $t6, $zero, L_8009D394
    if (ctx->r14 != 0) {
        // 0x8009D314: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009D394;
    }
    // 0x8009D314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009D318: jal         0x800963C0
    // 0x8009D31C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800963C0(rdram, ctx);
        goto after_1;
    // 0x8009D31C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x8009D320: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8009D324: beq         $t7, $zero, L_8009D360
    if (ctx->r15 == 0) {
        // 0x8009D328: nop
    
            goto L_8009D360;
    }
    // 0x8009D328: nop

    // 0x8009D32C: jal         0x8009C984
    // 0x8009D330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_2;
    // 0x8009D330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8009D334: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009D338: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009D33C: jal         0x800136E4
    // 0x8009D340: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x8009D340: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_3:
    // 0x8009D344: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009D348: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8009D34C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8009D350: jal         0x800F1B78
    // 0x8009D354: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_800F1B78(rdram, ctx);
        goto after_4;
    // 0x8009D354: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x8009D358: b           L_8009D380
    // 0x8009D35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8009D380;
    // 0x8009D35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009D360:
    // 0x8009D360: jal         0x8009C984
    // 0x8009D364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_5;
    // 0x8009D364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8009D368: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009D36C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8009D370: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8009D374: jal         0x800F1B78
    // 0x8009D378: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_800F1B78(rdram, ctx);
        goto after_6;
    // 0x8009D378: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_6:
    // 0x8009D37C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009D380:
    // 0x8009D380: jal         0x8009BF5C
    // 0x8009D384: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009BF5C(rdram, ctx);
        goto after_7;
    // 0x8009D384: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x8009D388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009D38C: jal         0x8009C4CC
    // 0x8009D390: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    baroll_setIdeal(rdram, ctx);
        goto after_8;
    // 0x8009D390: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_8:
L_8009D394:
    // 0x8009D394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009D39C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8009D3A0: jr          $ra
    // 0x8009D3A4: nop

    return;
    // 0x8009D3A4: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085590: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085590);
    return;
    // 0x80085594: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808001C4_chcauldronenergybars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808001C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001CC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808001D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001D8: beq         $a1, $at, L_808001F4
    if (ctx->r5 == ctx->r1) {
        // 0x808001DC: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_808001F4;
    }
    // 0x808001DC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808001E0: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x808001E4: beq         $a1, $at, L_8080025C
    if (ctx->r5 == ctx->r1) {
        // 0x808001E8: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8080025C;
    }
    // 0x808001E8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808001EC: b           L_80800290
    // 0x808001F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800290;
    // 0x808001F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001F4:
    // 0x808001F4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800200: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800204: nop

    // 0x80800208: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080020C: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x80800210: jal         0x80101FDC
    // 0x80800214: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800214: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
    after_0:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x8008A4B0
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800224: jal         0x8010A570
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080022C: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
    // 0x80800230: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800234: addiu       $a0, $zero, 0x39B
    ctx->r4 = ADD32(0, 0X39B);
    // 0x80800238: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x8080023C: bne         $t8, $at, L_8080024C
    if (ctx->r24 != ctx->r1) {
        // 0x80800240: nop
    
            goto L_8080024C;
    }
    // 0x80800240: nop

    // 0x80800244: b           L_8080024C
    // 0x80800248: addiu       $a0, $zero, 0x39A
    ctx->r4 = ADD32(0, 0X39A);
        goto L_8080024C;
    // 0x80800248: addiu       $a0, $zero, 0x39A
    ctx->r4 = ADD32(0, 0X39A);
L_8080024C:
    // 0x8080024C: jal         0x800DA544
    // 0x80800250: nop

    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800250: nop

    after_3:
    // 0x80800254: b           L_80800290
    // 0x80800258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800290;
    // 0x80800258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080025C:
    // 0x8080025C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800260: jal         0x800EC75C
    // 0x80800264: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800EC75C(rdram, ctx);
        goto after_4;
    // 0x80800264: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_4:
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: jal         0x800862B8
    // 0x80800270: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _chelectricfence_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800270: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x80800274: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2024, 0X2B4) << 16);
    // 0x80800278: lwc1        $f6, 0x2B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2024, 0X2B4));
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x8010A570
    // 0x80800284: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x80800284: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x80800288: b           L_80800290
    // 0x8080028C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800290;
    // 0x8080028C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800290:
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800294: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800298: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080029C: jr          $ra
    // 0x808002A0: nop

    return;
    // 0x808002A0: nop

;}
RECOMP_FUNC void func_800908A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800908A8: beq         $a0, $zero, L_800908D0
    if (ctx->r4 == 0) {
        // 0x800908AC: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800908D0;
    }
    // 0x800908AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800908B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800908B4: beq         $a0, $at, L_800908D8
    if (ctx->r4 == ctx->r1) {
        // 0x800908B8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800908D8;
    }
    // 0x800908B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800908BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800908C0: beq         $a0, $at, L_800908E0
    if (ctx->r4 == ctx->r1) {
        // 0x800908C4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800908E0;
    }
    // 0x800908C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800908C8: b           L_800908E8
    // 0x800908CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800908E8;
    // 0x800908CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800908D0:
    // 0x800908D0: jr          $ra
    // 0x800908D4: addiu       $v0, $v0, 0x7D80
    ctx->r2 = ADD32(ctx->r2, 0X7D80);
    return;
    // 0x800908D4: addiu       $v0, $v0, 0x7D80
    ctx->r2 = ADD32(ctx->r2, 0X7D80);
L_800908D8:
    // 0x800908D8: jr          $ra
    // 0x800908DC: addiu       $v0, $v0, 0x7CFC
    ctx->r2 = ADD32(ctx->r2, 0X7CFC);
    return;
    // 0x800908DC: addiu       $v0, $v0, 0x7CFC
    ctx->r2 = ADD32(ctx->r2, 0X7CFC);
L_800908E0:
    // 0x800908E0: jr          $ra
    // 0x800908E4: addiu       $v0, $v0, 0x7CC0
    ctx->r2 = ADD32(ctx->r2, 0X7CC0);
    return;
    // 0x800908E4: addiu       $v0, $v0, 0x7CC0
    ctx->r2 = ADD32(ctx->r2, 0X7CC0);
L_800908E8:
    // 0x800908E8: jr          $ra
    // 0x800908EC: nop

    return;
    // 0x800908EC: nop

;}
RECOMP_FUNC void _chdinofamilysick_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876E8: syscall     610
    recomp_syscall_handler(rdram, ctx, 0x800876E8);
    return;
    // 0x800876EC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_chcolldoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x8080000C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800010: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800014: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800018: beq         $t6, $at, L_80800040
    if (ctx->r14 == ctx->r1) {
        // 0x8080001C: addiu       $a0, $zero, 0x577
        ctx->r4 = ADD32(0, 0X577);
            goto L_80800040;
    }
    // 0x8080001C: addiu       $a0, $zero, 0x577
    ctx->r4 = ADD32(0, 0X577);
    // 0x80800020: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80800024: beq         $t6, $at, L_80800054
    if (ctx->r14 == ctx->r1) {
        // 0x80800028: addiu       $a0, $zero, 0x368
        ctx->r4 = ADD32(0, 0X368);
            goto L_80800054;
    }
    // 0x80800028: addiu       $a0, $zero, 0x368
    ctx->r4 = ADD32(0, 0X368);
    // 0x8080002C: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80800030: beq         $t6, $at, L_80800068
    if (ctx->r14 == ctx->r1) {
        // 0x80800034: addiu       $a0, $zero, 0x369
        ctx->r4 = ADD32(0, 0X369);
            goto L_80800068;
    }
    // 0x80800034: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    // 0x80800038: b           L_8080007C
    // 0x8080003C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
        goto L_8080007C;
    // 0x8080003C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_80800040:
    // 0x80800040: jal         0x800DA298
    // 0x80800044: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800048: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080004C: b           L_80800078
    // 0x80800050: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80800078;
    // 0x80800050: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80800054:
    // 0x80800054: jal         0x800DA298
    // 0x80800058: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800058: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080005C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800060: b           L_80800078
    // 0x80800064: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80800078;
    // 0x80800064: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80800068:
    // 0x80800068: jal         0x800DA298
    // 0x8080006C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080006C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800070: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800074: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80800078:
    // 0x80800078: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_8080007C:
    // 0x8080007C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800080: beql        $t7, $zero, L_808000AC
    if (ctx->r15 == 0) {
        // 0x80800084: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800088: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8080008C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800090: lbu         $t8, 0x72($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X72);
    // 0x80800094: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800098: andi        $t9, $t8, 0xFF03
    ctx->r25 = ctx->r24 & 0XFF03;
    // 0x8080009C: ori         $t0, $t9, 0xC
    ctx->r8 = ctx->r25 | 0XC;
    // 0x808000A0: sb          $t0, 0x72($a1)
    MEM_B(0X72, ctx->r5) = ctx->r8;
    // 0x808000A4: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000AC:
    // 0x808000AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void yaw_getIdeal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C990: lw          $t6, 0xF8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C994: jr          $ra
    // 0x8009C998: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    return;
    // 0x8009C998: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
;}
