#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void capod_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002EC: jal         0x8008FFE8
    // 0x808002F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x808002F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002F4: jal         0x80110024
    // 0x808002F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x808002F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808002FC: beq         $v0, $zero, L_80800310
    if (ctx->r2 == 0) {
        // 0x80800300: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800310;
    }
    // 0x80800300: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800304: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800308: jal         0x80089580
    // 0x8080030C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    _ncpod_entrypoint_24(rdram, ctx);
        goto after_2;
    // 0x8080030C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80800310:
    // 0x80800310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800318: jr          $ra
    // 0x8080031C: nop

    return;
    // 0x8080031C: nop

;}
RECOMP_FUNC void _chmadamegrunty_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D48: syscall     234
    recomp_syscall_handler(rdram, ctx, 0x80085D48);
    return;
    // 0x80085D4C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008F9C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F9C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F9C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F9CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F9D0: jal         0x800F54E4
    // 0x8008F9D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008F9D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008F9D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F9DC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008F9E0: jal         0x800F4A8C
    // 0x8008F9E4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F4A8C(rdram, ctx);
        goto after_1;
    // 0x8008F9E4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8008F9E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F9EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F9F0: jr          $ra
    // 0x8008F9F4: nop

    return;
    // 0x8008F9F4: nop

;}
RECOMP_FUNC void func_8009EB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EB18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EB1C: jr          $ra
    // 0x8009EB20: sb          $a0, 0x7075($at)
    MEM_B(0X7075, ctx->r1) = ctx->r4;
    return;
    // 0x8009EB20: sb          $a0, 0x7075($at)
    MEM_B(0X7075, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084010: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084010);
    return;
    // 0x80084014: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chpowerhutwitchy_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800934: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800938: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080093C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800940: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800944: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800948: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080094C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80800950: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800954: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800958: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080095C: jal         0x80106790
    // 0x80800960: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800960: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80800964: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800968: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080096C: lwc1        $f20, 0x28($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80800970: beq         $v1, $at, L_80800988
    if (ctx->r3 == ctx->r1) {
        // 0x80800974: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800988;
    }
    // 0x80800974: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800978: beq         $v1, $at, L_808009B8
    if (ctx->r3 == ctx->r1) {
        // 0x8080097C: nop
    
            goto L_808009B8;
    }
    // 0x8080097C: nop

    // 0x80800980: b           L_808009E4
    // 0x80800984: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808009E4;
    // 0x80800984: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800988:
    // 0x80800988: blezl       $s0, L_808009E4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8080098C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808009E4;
    }
    goto skip_0;
    // 0x8080098C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_80800990:
    // 0x80800990: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800994: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x80800998: jal         0x800F2FD0
    // 0x8080099C: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    func_800F2FD0(rdram, ctx);
        goto after_1;
    // 0x8080099C: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    after_1:
    // 0x808009A0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808009A4: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x808009A8: bgtz        $s0, L_80800990
    if (SIGNED(ctx->r16) > 0) {
        // 0x808009AC: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800990;
    }
    // 0x808009AC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808009B0: b           L_808009E4
    // 0x808009B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808009E4;
    // 0x808009B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808009B8:
    // 0x808009B8: blezl       $s0, L_808009E4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x808009BC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808009E4;
    }
    goto skip_1;
    // 0x808009BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_808009C0:
    // 0x808009C0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808009C4: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x808009C8: jal         0x800F2FD0
    // 0x808009CC: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    func_800F2FD0(rdram, ctx);
        goto after_2;
    // 0x808009CC: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    after_2:
    // 0x808009D0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808009D4: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x808009D8: bgtz        $s0, L_808009C0
    if (SIGNED(ctx->r16) > 0) {
        // 0x808009DC: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_808009C0;
    }
    // 0x808009DC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808009E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808009E4:
    // 0x808009E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808009E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009EC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808009F0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808009F4: jr          $ra
    // 0x808009F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808009F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800C7C_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C7C: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x80800C80: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2304, 0X2180) << 16);
    // 0x80800C84: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80800C88: sw          $s7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r23;
    // 0x80800C8C: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x80800C90: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x80800C94: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x80800C98: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80800C9C: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80800CA0: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80800CA4: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x80800CA8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80800CAC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800CB0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800CB4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800CB8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800CBC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800CC0: addiu       $t6, $t6, 0x2180
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2304, 0X2180));
    // 0x80800CC4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80800CC8: addiu       $s0, $sp, 0xD0
    ctx->r16 = ADD32(ctx->r29, 0XD0);
    // 0x80800CCC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2304, 0X218C) << 16);
    // 0x80800CD0: sw          $at, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r1;
    // 0x80800CD4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80800CD8: addiu       $t0, $t0, 0x218C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2304, 0X218C));
    // 0x80800CDC: addiu       $s1, $sp, 0xC4
    ctx->r17 = ADD32(ctx->r29, 0XC4);
    // 0x80800CE0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80800CE4: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80800CE8: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800CEC: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80800CF0: sw          $at, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r1;
    // 0x80800CF4: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80800CF8: sw          $at, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r1;
    // 0x80800CFC: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80800D00: sw          $t3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r11;
    // 0x80800D04: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80800D08: jal         0x800F54E4
    // 0x80800D0C: sw          $at, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r1;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800D0C: sw          $at, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r1;
    after_0:
    // 0x80800D10: addiu       $s2, $sp, 0xDC
    ctx->r18 = ADD32(ctx->r29, 0XDC);
    // 0x80800D14: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800D18: jal         0x800F5A00
    // 0x80800D1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80800D1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800D28: jal         0x800EFED0
    // 0x80800D2C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFED0(rdram, ctx);
        goto after_2;
    // 0x80800D2C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80800D30: beq         $v0, $zero, L_80800FF4
    if (ctx->r2 == 0) {
        // 0x80800D34: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800FF4;
    }
    // 0x80800D34: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800D38: jal         0x80100094
    // 0x80800D3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800D3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800D40: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80800D44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800D48: jal         0x80100094
    // 0x80800D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800D50: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2304, 0X2198) << 16);
    // 0x80800D54: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    // 0x80800D58: addiu       $t5, $t5, 0x2198
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2304, 0X2198));
    // 0x80800D5C: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80800D60: addiu       $t4, $sp, 0xB0
    ctx->r12 = ADD32(ctx->r29, 0XB0);
    // 0x80800D64: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80800D68: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80800D6C: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x80800D70: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80800D74: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x80800D78: jal         0x801039E4
    // 0x80800D7C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    func_801039E4(rdram, ctx);
        goto after_5;
    // 0x80800D7C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_5:
    // 0x80800D80: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80800D84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X213C) << 16);
    // 0x80800D88: lwc1        $f30, 0x213C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X213C));
    // 0x80800D8C: lwc1        $f12, 0x24($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X24);
    // 0x80800D90: lui         $a2, 0x402A
    ctx->r6 = S32(0X402A << 16);
    // 0x80800D94: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800D98: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800D9C: ori         $a2, $a2, 0xAAAB
    ctx->r6 = ctx->r6 | 0XAAAB;
    // 0x80800DA0: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    // 0x80800DA4: jal         0x800F10B4
    // 0x80800DA8: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800DA8: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    after_6:
    // 0x80800DAC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800DB0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800DB4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800DB8: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80800DBC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800DC0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800DC4: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x80800DC8: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2304, 0X21A4) << 16);
    // 0x80800DCC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800DD0: addiu       $s4, $s4, 0x21A4
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2304, 0X21A4));
    // 0x80800DD4: addiu       $s2, $s2, 0x17D0
    ctx->r18 = ADD32(ctx->r18, 0X17D0);
    // 0x80800DD8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800DDC: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
    // 0x80800DE0: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_80800DE4:
    // 0x80800DE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2140) << 16);
    // 0x80800DE8: lui         $a2, 0x45B9
    ctx->r6 = S32(0X45B9 << 16);
    // 0x80800DEC: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800DF0: ori         $a2, $a2, 0xF000
    ctx->r6 = ctx->r6 | 0XF000;
    // 0x80800DF4: lwc1        $f14, 0x2140($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2140));
    // 0x80800DF8: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x80800DFC: jal         0x800F10B4
    // 0x80800E00: swc1        $f12, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f12.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800E00: swc1        $f12, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f12.u32l;
    after_7:
    // 0x80800E04: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80800E08: lw          $at, 0x0($s4)
    ctx->r1 = MEM_W(ctx->r20, 0X0);
    // 0x80800E0C: lw          $t1, 0x4($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4);
    // 0x80800E10: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800E14: sw          $at, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r1;
    // 0x80800E18: lw          $at, 0x8($s4)
    ctx->r1 = MEM_W(ctx->r20, 0X8);
    // 0x80800E1C: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x80800E20: mul.s       $f12, $f4, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80800E24: jal         0x800138D0
    // 0x80800E28: sw          $at, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r1;
    func_800138D0(rdram, ctx);
        goto after_8;
    // 0x80800E28: sw          $at, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r1;
    after_8:
    // 0x80800E2C: mul.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80800E30: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800E34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800E38: mul.s       $f16, $f20, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80800E3C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800E40: mul.s       $f12, $f16, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80800E44: jal         0x800138D0
    // 0x80800E48: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    func_800138D0(rdram, ctx);
        goto after_9;
    // 0x80800E48: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80800E4C: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80800E50: sw          $s1, 0x4C($s7)
    MEM_W(0X4C, ctx->r23) = ctx->r17;
    // 0x80800E54: jal         0x800DF830
    // 0x80800E58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_10;
    // 0x80800E58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80800E5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E60: jal         0x800DF47C
    // 0x80800E64: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800DF47C(rdram, ctx);
        goto after_11;
    // 0x80800E64: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_11:
    // 0x80800E68: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800E6C: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x80800E70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800E74: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800E78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800E7C: jal         0x800DE498
    // 0x80800E80: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_800DE498(rdram, ctx);
        goto after_12;
    // 0x80800E80: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_12:
    // 0x80800E84: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80800E88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800E8C: slti        $at, $s1, 0xF
    ctx->r1 = SIGNED(ctx->r17) < 0XF ? 1 : 0;
    // 0x80800E90: bne         $at, $zero, L_80800DE4
    if (ctx->r1 != 0) {
        // 0x80800E94: add.s       $f12, $f12, $f30
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f30.fl;
            goto L_80800DE4;
    }
    // 0x80800E94: add.s       $f12, $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f30.fl;
    // 0x80800E98: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x80800E9C: swc1        $f12, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f12.u32l;
    // 0x80800EA0: beql        $a0, $zero, L_80800EC0
    if (ctx->r4 == 0) {
        // 0x80800EA4: lhu         $t0, 0x72($s5)
        ctx->r8 = MEM_HU(ctx->r21, 0X72);
            goto L_80800EC0;
    }
    goto skip_0;
    // 0x80800EA4: lhu         $t0, 0x72($s5)
    ctx->r8 = MEM_HU(ctx->r21, 0X72);
    skip_0:
    // 0x80800EA8: jal         0x80089888
    // 0x80800EAC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    _sumumbofx_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x80800EAC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_13:
    // 0x80800EB0: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x80800EB4: jal         0x80089880
    // 0x80800EB8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_14;
    // 0x80800EB8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_14:
    // 0x80800EBC: lhu         $t0, 0x72($s5)
    ctx->r8 = MEM_HU(ctx->r21, 0X72);
L_80800EC0:
    // 0x80800EC0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800EC4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2304, 0X21B0) << 16);
    // 0x80800EC8: srl         $t3, $t0, 10
    ctx->r11 = S32(U32(ctx->r8) >> 10);
    // 0x80800ECC: bne         $t3, $at, L_80800FF4
    if (ctx->r11 != ctx->r1) {
        // 0x80800ED0: addiu       $t7, $t7, 0x21B0
        ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2304, 0X21B0));
            goto L_80800FF4;
    }
    // 0x80800ED0: addiu       $t7, $t7, 0x21B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2304, 0X21B0));
    // 0x80800ED4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800ED8: addiu       $s4, $sp, 0x8C
    ctx->r20 = ADD32(ctx->r29, 0X8C);
    // 0x80800EDC: addiu       $a0, $zero, 0x8D3
    ctx->r4 = ADD32(0, 0X8D3);
    // 0x80800EE0: sw          $at, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r1;
    // 0x80800EE4: lw          $t4, 0x4($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X4);
    // 0x80800EE8: sw          $t4, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r12;
    // 0x80800EEC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800EF0: jal         0x800D674C
    // 0x80800EF4: sw          $at, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r1;
    func_800D674C(rdram, ctx);
        goto after_15;
    // 0x80800EF4: sw          $at, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r1;
    after_15:
    // 0x80800EF8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800EFC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800F00: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80800F04: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800F08: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80800F0C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800F10: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800F14: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800F18: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
    // 0x80800F1C: addiu       $s5, $zero, 0x3C
    ctx->r21 = ADD32(0, 0X3C);
    // 0x80800F20: addiu       $s1, $sp, 0x80
    ctx->r17 = ADD32(ctx->r29, 0X80);
L_80800F24:
    // 0x80800F24: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80800F28: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80800F2C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800F30: srl         $t5, $v0, 25
    ctx->r13 = S32(U32(ctx->r2) >> 25);
    // 0x80800F34: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80800F38: sll         $t6, $v0, 7
    ctx->r14 = S32(ctx->r2 << 7);
    // 0x80800F3C: bgez        $t5, L_80800F50
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800F40: cvt.s.w     $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80800F50;
    }
    // 0x80800F40: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800F44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F48: nop

    // 0x80800F4C: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
L_80800F50:
    // 0x80800F50: srl         $t2, $t6, 25
    ctx->r10 = S32(U32(ctx->r14) >> 25);
    // 0x80800F54: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800F58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800F5C: bgez        $t2, L_80800F70
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800F60: cvt.s.w     $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800F70;
    }
    // 0x80800F60: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800F64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800F68: nop

    // 0x80800F6C: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
L_80800F70:
    // 0x80800F70: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80800F74: jal         0x800F10B4
    // 0x80800F78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x80800F78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_16:
    // 0x80800F7C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800F80: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800F84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F88: jal         0x800EFA4C
    // 0x80800F8C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_17;
    // 0x80800F8C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_17:
    // 0x80800F90: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80800F94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800F98: sll         $t0, $t9, 14
    ctx->r8 = S32(ctx->r25 << 14);
    // 0x80800F9C: bgezl       $t0, L_80800FB0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800FA0: swc1        $f28, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->f28.u32l;
            goto L_80800FB0;
    }
    goto skip_1;
    // 0x80800FA0: swc1        $f28, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f28.u32l;
    skip_1:
    // 0x80800FA4: b           L_80800FB0
    // 0x80800FA8: swc1        $f24, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f24.u32l;
        goto L_80800FB0;
    // 0x80800FA8: swc1        $f24, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f24.u32l;
    // 0x80800FAC: swc1        $f28, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f28.u32l;
L_80800FB0:
    // 0x80800FB0: jal         0x800DC128
    // 0x80800FB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_18;
    // 0x80800FB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
    // 0x80800FB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800FBC: jal         0x800DF744
    // 0x80800FC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DF744(rdram, ctx);
        goto after_19;
    // 0x80800FC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_19:
    // 0x80800FC4: jal         0x800DF830
    // 0x80800FC8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_20;
    // 0x80800FC8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_20:
    // 0x80800FCC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800FD0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800FD4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800FD8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80800FDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800FE0: jal         0x800DE498
    // 0x80800FE4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_800DE498(rdram, ctx);
        goto after_21;
    // 0x80800FE4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_21:
    // 0x80800FE8: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80800FEC: bne         $s2, $s5, L_80800F24
    if (ctx->r18 != ctx->r21) {
        // 0x80800FF0: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_80800F24;
    }
    // 0x80800FF0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_80800FF4:
    // 0x80800FF4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80800FF8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800FFC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801000: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80801004: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80801008: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8080100C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80801010: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80801014: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80801018: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x8080101C: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80801020: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x80801024: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80801028: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x8080102C: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x80801030: jr          $ra
    // 0x80801034: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x80801034: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_808093F8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808093F8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x808093FC: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80809400: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80809404: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80809408: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8080940C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80809410: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80809414: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80809418: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8080941C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80809420: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80809424: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80809428: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8080942C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80809430: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80809434: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x80809438: jal         0x80100094
    // 0x8080943C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080943C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80809440: lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB0);
    // 0x80809444: addiu       $s5, $sp, 0xA4
    ctx->r21 = ADD32(ctx->r29, 0XA4);
    // 0x80809448: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8080944C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80809450: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    // 0x80809454: jal         0x800EE7F8
    // 0x80809458: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80809458: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8080945C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80809460: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80809464: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80809468: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080946C: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x80809470: lw          $a0, 0xE8($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XE8);
    // 0x80809474: beq         $a0, $zero, L_80809484
    if (ctx->r4 == 0) {
        // 0x80809478: nop
    
            goto L_80809484;
    }
    // 0x80809478: nop

    // 0x8080947C: jal         0x800B5450
    // 0x80809480: nop

    func_800B5450(rdram, ctx);
        goto after_2;
    // 0x80809480: nop

    after_2:
L_80809484:
    // 0x80809484: lui         $t6, 0x8081
    ctx->r14 = S32(RELOC_HI16(1480, 0XA25C) << 16);
    // 0x80809488: addiu       $t6, $t6, -0x5DA4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1480, 0XA25C));
    // 0x8080948C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80809490: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80809494: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80809498: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x8080949C: jal         0x800BBCB8
    // 0x808094A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x808094A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x808094A4: lw          $a0, 0xEC($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XEC);
    // 0x808094A8: sw          $v0, 0xE8($s6)
    MEM_W(0XE8, ctx->r22) = ctx->r2;
    // 0x808094AC: beq         $a0, $zero, L_808094BC
    if (ctx->r4 == 0) {
        // 0x808094B0: nop
    
            goto L_808094BC;
    }
    // 0x808094B0: nop

    // 0x808094B4: jal         0x800B5450
    // 0x808094B8: nop

    func_800B5450(rdram, ctx);
        goto after_4;
    // 0x808094B8: nop

    after_4:
L_808094BC:
    // 0x808094BC: jal         0x800B53A4
    // 0x808094C0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B53A4(rdram, ctx);
        goto after_5;
    // 0x808094C0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_5:
    // 0x808094C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808094C8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x808094CC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808094D0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808094D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808094D8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808094DC: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808094E0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808094E4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x808094E8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808094EC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808094F0: lui         $s3, 0x8081
    ctx->r19 = S32(RELOC_HI16(1480, 0XA2B8) << 16);
    // 0x808094F4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808094F8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808094FC: sw          $v0, 0xEC($s6)
    MEM_W(0XEC, ctx->r22) = ctx->r2;
    // 0x80809500: addiu       $s3, $s3, -0x5D48
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1480, 0XA2B8));
    // 0x80809504: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80809508: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x8080950C: addiu       $s1, $sp, 0x8C
    ctx->r17 = ADD32(ctx->r29, 0X8C);
    // 0x80809510: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_80809514:
    // 0x80809514: jal         0x800DC178
    // 0x80809518: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80809518: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_6:
    // 0x8080951C: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x80809520: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80809524: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80809528: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080952C: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80809530: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80809534: jal         0x800EEB9C
    // 0x80809538: nop

    func_800EEB9C(rdram, ctx);
        goto after_7;
    // 0x80809538: nop

    after_7:
    // 0x8080953C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80809540: jal         0x800EF04C
    // 0x80809544: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x80809544: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_8:
    // 0x80809548: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x8080954C: jal         0x800DC178
    // 0x80809550: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80809550: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_9:
    // 0x80809554: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80809558: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8080955C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80809560: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80809564: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80809568: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8080956C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80809570: jal         0x800BABB8
    // 0x80809574: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    func_800BABB8(rdram, ctx);
        goto after_10;
    // 0x80809574: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80809578: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080957C: bnel        $s0, $s4, L_80809514
    if (ctx->r16 != ctx->r20) {
        // 0x80809580: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_80809514;
    }
    goto skip_0;
    // 0x80809580: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_0:
    // 0x80809584: lw          $a0, 0xF0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XF0);
    // 0x80809588: beq         $a0, $zero, L_80809598
    if (ctx->r4 == 0) {
        // 0x8080958C: nop
    
            goto L_80809598;
    }
    // 0x8080958C: nop

    // 0x80809590: jal         0x800B5450
    // 0x80809594: nop

    func_800B5450(rdram, ctx);
        goto after_11;
    // 0x80809594: nop

    after_11:
L_80809598:
    // 0x80809598: lui         $s0, 0x8081
    ctx->r16 = S32(RELOC_HI16(1480, 0XA294) << 16);
    // 0x8080959C: addiu       $s0, $s0, -0x5D6C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1480, 0XA294));
    // 0x808095A0: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x808095A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x808095A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808095AC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808095B0: jal         0x800BBCB8
    // 0x808095B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_12;
    // 0x808095B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x808095B8: lw          $a0, 0xF4($s6)
    ctx->r4 = MEM_W(ctx->r22, 0XF4);
    // 0x808095BC: sw          $v0, 0xF0($s6)
    MEM_W(0XF0, ctx->r22) = ctx->r2;
    // 0x808095C0: beq         $a0, $zero, L_808095D0
    if (ctx->r4 == 0) {
        // 0x808095C4: nop
    
            goto L_808095D0;
    }
    // 0x808095C4: nop

    // 0x808095C8: jal         0x800B5450
    // 0x808095CC: nop

    func_800B5450(rdram, ctx);
        goto after_13;
    // 0x808095CC: nop

    after_13:
L_808095D0:
    // 0x808095D0: jal         0x800E3A58
    // 0x808095D4: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    func_800E3A58(rdram, ctx);
        goto after_14;
    // 0x808095D4: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    after_14:
    // 0x808095D8: jal         0x800B53A4
    // 0x808095DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_15;
    // 0x808095DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x808095E0: sw          $v0, 0xF4($s6)
    MEM_W(0XF4, ctx->r22) = ctx->r2;
    // 0x808095E4: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x808095E8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808095EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x808095F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808095F4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808095F8: jal         0x800BABB8
    // 0x808095FC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800BABB8(rdram, ctx);
        goto after_16;
    // 0x808095FC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_16:
    // 0x80809600: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80809604: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80809608: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8080960C: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80809610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80809614: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80809618: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8080961C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80809620: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80809624: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80809628: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080962C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80809630: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x80809634: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80809638: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8080963C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80809640: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80809644: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x80809648: jal         0x800BA77C
    // 0x8080964C: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_17;
    // 0x8080964C: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    after_17:
    // 0x80809650: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80809654: jal         0x800BA22C
    // 0x80809658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_18;
    // 0x80809658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x8080965C: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA250) << 16);
    // 0x80809660: addiu       $a2, $a2, -0x5DB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA250));
    // 0x80809664: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80809668: jal         0x80089D18
    // 0x8080966C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x8080966C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_19:
    // 0x80809670: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0XA22C) << 16);
    // 0x80809674: addiu       $a3, $a3, -0x5DD4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0XA22C));
    // 0x80809678: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8080967C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80809680: jal         0x8010D930
    // 0x80809684: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    func_8010D930(rdram, ctx);
        goto after_20;
    // 0x80809684: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    after_20:
    // 0x80809688: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8080968C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80809690: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80809694: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80809698: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8080969C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x808096A0: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x808096A4: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x808096A8: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x808096AC: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x808096B0: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x808096B4: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x808096B8: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x808096BC: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x808096C0: jr          $ra
    // 0x808096C4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x808096C4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x808096C8: nop

    // 0x808096CC: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006E0: jal         0x8080051C
    // 0x808006E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x808006E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808006E8: bne         $v0, $zero, L_808006F8
    if (ctx->r2 != 0) {
        // 0x808006EC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808006F8;
    }
    // 0x808006EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006F0: b           L_80800704
    // 0x808006F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800704;
    // 0x808006F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006F8:
    // 0x808006F8: jal         0x80800318
    // 0x808006FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    gsmaker_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808006FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800704:
    // 0x80800704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080070C: jr          $ra
    // 0x80800710: nop

    return;
    // 0x80800710: nop

;}
RECOMP_FUNC void bskazjump_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B68: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800B6C: jal         0x800852F0
    // 0x80800B70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x80800B70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800B74: beq         $v0, $zero, L_80800B8C
    if (ctx->r2 == 0) {
        // 0x80800B78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B8C;
    }
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: addiu       $a1, $zero, 0x4667
    ctx->r5 = ADD32(0, 0X4667);
    // 0x80800B80: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800B84: jal         0x8009DF18
    // 0x80800B88: addiu       $a3, $zero, 0x7D00
    ctx->r7 = ADD32(0, 0X7D00);
    func_8009DF18(rdram, ctx);
        goto after_1;
    // 0x80800B88: addiu       $a3, $zero, 0x7D00
    ctx->r7 = ADD32(0, 0X7D00);
    after_1:
L_80800B8C:
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B90: jal         0x800852F0
    // 0x80800B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x80800B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800B98: jal         0x800834B0
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA4: jal         0x80085330
    // 0x80800BA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isZero(rdram, ctx);
        goto after_4;
    // 0x80800BA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800BAC: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800BB0: nop
    
            goto L_80800BD8;
    }
    // 0x80800BB0: nop

    // 0x80800BB4: jal         0x8009BFD8
    // 0x80800BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_5;
    // 0x80800BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800BBC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800BC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800BCC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800BD0: jal         0x8009BF5C
    // 0x80800BD4: nop

    func_8009BF5C(rdram, ctx);
        goto after_6;
    // 0x80800BD4: nop

    after_6:
L_80800BD8:
    // 0x80800BD8: jal         0x8008E35C
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_7;
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800BE0: beq         $v0, $zero, L_80800BEC
    if (ctx->r2 == 0) {
        // 0x80800BE4: addiu       $t6, $zero, 0x160
        ctx->r14 = ADD32(0, 0X160);
            goto L_80800BEC;
    }
    // 0x80800BE4: addiu       $t6, $zero, 0x160
    ctx->r14 = ADD32(0, 0X160);
    // 0x80800BE8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800BEC:
    // 0x80800BEC: jal         0x8008E078
    // 0x80800BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_8;
    // 0x80800BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800BF4: beq         $v0, $zero, L_80800C04
    if (ctx->r2 == 0) {
        // 0x80800BF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C04;
    }
    // 0x80800BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BFC: addiu       $t7, $zero, 0x176
    ctx->r15 = ADD32(0, 0X176);
    // 0x80800C00: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800C04:
    // 0x80800C04: jal         0x8009E5C8
    // 0x80800C08: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x80800C08: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x80800C0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C18: jr          $ra
    // 0x80800C1C: nop

    return;
    // 0x80800C1C: nop

;}
RECOMP_FUNC void func_80800014_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800020: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800024: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080002C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800030: beq         $t6, $at, L_8080005C
    if (ctx->r14 == ctx->r1) {
        // 0x80800034: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080005C;
    }
    // 0x80800034: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800038: beq         $t6, $at, L_8080006C
    if (ctx->r14 == ctx->r1) {
        // 0x8080003C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080006C;
    }
    // 0x8080003C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800040: beq         $t6, $at, L_80800084
    if (ctx->r14 == ctx->r1) {
        // 0x80800044: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800084;
    }
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080004C: beq         $t6, $at, L_8080009C
    if (ctx->r14 == ctx->r1) {
        // 0x80800050: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080009C;
    }
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: b           L_808000C4
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C4;
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080005C:
    // 0x8080005C: jal         0x8080058C
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080058C_chcheatomenu(rdram, ctx);
        goto after_0;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800064: b           L_808000C4
    // 0x80800068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C4;
    // 0x80800068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080006C:
    // 0x8080006C: jal         0x80800668
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800668_chcheatomenu(rdram, ctx);
        goto after_1;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800074: jal         0x80800720
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800720_chcheatomenu(rdram, ctx);
        goto after_2;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080007C: b           L_808000C4
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C4;
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800084:
    // 0x80800084: jal         0x80100094
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080008C: jal         0x80087C98
    // 0x80800090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800094: b           L_808000C4
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C4;
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080009C:
    // 0x8080009C: jal         0x80087CC8
    // 0x808000A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x808000A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808000A4: jal         0x808007B8
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007B8_chcheatomenu(rdram, ctx);
        goto after_6;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000AC: jal         0x80090708
    // 0x808000B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_7;
    // 0x808000B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x80101FDC
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C4:
    // 0x808000C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802AB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802ABC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802AC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802AC4: jal         0x80800538
    // 0x80802AC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80802AC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802ACC: jal         0x808029D8
    // 0x80802AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808029D8_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80802AD4: jal         0x80800DC4
    // 0x80802AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DC4_bsbtrot(rdram, ctx);
        goto after_2;
    // 0x80802AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802ADC: lui         $a2, 0x3F07
    ctx->r6 = S32(0X3F07 << 16);
    // 0x80802AE0: ori         $a2, $a2, 0xAE14
    ctx->r6 = ctx->r6 | 0XAE14;
    // 0x80802AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802AE8: jal         0x8008CB3C
    // 0x80802AEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_3;
    // 0x80802AEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80802AF0: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x80802AF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802AFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80802B00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80802B04: jal         0x8009FFD8
    // 0x80802B08: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_8009FFD8(rdram, ctx);
        goto after_4;
    // 0x80802B08: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_4:
    // 0x80802B0C: jal         0x80800DF4
    // 0x80802B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DF4_bsbtrot(rdram, ctx);
        goto after_5;
    // 0x80802B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802B14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802B18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802B1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802B20: jr          $ra
    // 0x80802B24: nop

    return;
    // 0x80802B24: nop

;}
RECOMP_FUNC void func_80800728_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800728: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080072C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800730: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800734: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800738: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080073C: jal         0x80100094
    // 0x80800740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800744: lw          $t6, 0x94($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X94);
    // 0x80800748: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080074C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800750: jal         0x80100094
    // 0x80800754: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800754: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_1:
    // 0x80800758: jal         0x80800E44
    // 0x8080075C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800E44_chquiz(rdram, ctx);
        goto after_2;
    // 0x8080075C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800760: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2484, 0X70B8) << 16);
    // 0x80800764: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800768: addiu       $t7, $t7, 0x70B8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2484, 0X70B8));
    // 0x8080076C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800770: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x80800774: sw          $at, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r1;
    // 0x80800778: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8080077C: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x80800780: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800784: sw          $at, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r1;
    // 0x80800788: jal         0x8008A830
    // 0x8080078C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    _suquiz_entrypoint_15(rdram, ctx);
        goto after_3;
    // 0x8080078C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x80800790: bne         $v0, $zero, L_80800834
    if (ctx->r2 != 0) {
        // 0x80800794: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800834;
    }
    // 0x80800794: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800798: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080079C: jal         0x800DC128
    // 0x808007A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x808007A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x808007A4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x808007A8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x808007AC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x808007B0: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x808007B4: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x808007B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808007BC: jal         0x80800C00
    // 0x808007C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800C00_chquiz(rdram, ctx);
        goto after_5;
    // 0x808007C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x808007C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808007C8: beq         $v0, $at, L_808007F0
    if (ctx->r2 == ctx->r1) {
        // 0x808007CC: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_808007F0;
    }
    // 0x808007CC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808007D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808007D4: jal         0x80800C00
    // 0x808007D8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80800C00_chquiz(rdram, ctx);
        goto after_6;
    // 0x808007D8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_6:
    // 0x808007DC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808007E0: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x808007E4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808007E8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808007EC: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
L_808007F0:
    // 0x808007F0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x808007F4: addu        $t7, $s0, $t8
    ctx->r15 = ADD32(ctx->r16, ctx->r24);
    // 0x808007F8: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x808007FC: beq         $t0, $zero, L_80800824
    if (ctx->r8 == 0) {
        // 0x80800800: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800824;
    }
    // 0x80800800: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800804:
    // 0x80800804: jal         0x800DC128
    // 0x80800808: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_7;
    // 0x80800808: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x8080080C: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80800810: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80800814: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x80800818: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080081C: bnel        $t1, $zero, L_80800804
    if (ctx->r9 != 0) {
        // 0x80800820: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800804;
    }
    goto skip_0;
    // 0x80800820: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
L_80800824:
    // 0x80800824: jal         0x80087DE0
    // 0x80800828: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_8;
    // 0x80800828: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_8:
    // 0x8080082C: b           L_80800840
    // 0x80800830: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
        goto L_80800840;
    // 0x80800830: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_80800834:
    // 0x80800834: jal         0x80087DE0
    // 0x80800838: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_9;
    // 0x80800838: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x8080083C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_80800840:
    // 0x80800840: jal         0x80087D68
    // 0x80800844: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_26(rdram, ctx);
        goto after_10;
    // 0x80800844: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080084C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800850: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800854: jr          $ra
    // 0x80800858: nop

    return;
    // 0x80800858: nop

;}
RECOMP_FUNC void _chdrawbridgeswitches_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087158: syscall     523
    recomp_syscall_handler(rdram, ctx, 0x80087158);
    return;
    // 0x8008715C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _dbid_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879D0: syscall     646
    recomp_syscall_handler(rdram, ctx, 0x800879D0);
    return;
    // 0x800879D4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800EDA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDA24: jr          $ra
    // 0x800EDA28: lh          $v0, 0x4C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4C);
    return;
    // 0x800EDA28: lh          $v0, 0x4C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4C);
;}
RECOMP_FUNC void fxripple_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800238: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8080023C: jal         0x800B5BE4
    // 0x80800240: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800240: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800244: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800248: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080024C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800250: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800254: nop

    // 0x80800258: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8080025C: jal         0x800BA5D0
    // 0x80800260: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    func_800BA5D0(rdram, ctx);
        goto after_1;
    // 0x80800260: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80800264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

    // 0x80800274: nop

    // 0x80800278: nop

    // 0x8080027C: nop

;}
RECOMP_FUNC void func_80021574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021574: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80021578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002157C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80021580: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80021584: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80021588: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8002158C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80021590: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80021594: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80021598: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8002159C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800215A0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800215A4: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800215A8: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x800215AC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800215B0: bne         $t9, $zero, L_800215C8
    if (ctx->r25 != 0) {
        // 0x800215B4: nop
    
            goto L_800215C8;
    }
    // 0x800215B4: nop

    // 0x800215B8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800215BC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800215C0: b           L_80021780
    // 0x800215C4: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
        goto L_80021780;
    // 0x800215C4: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_800215C8:
    // 0x800215C8: jal         0x80021960
    // 0x800215CC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_80021960(rdram, ctx);
        goto after_0;
    // 0x800215CC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x800215D0: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800215D4: lw          $t1, 0x11F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F4);
    // 0x800215D8: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800215DC: sw          $v0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r2;
    // 0x800215E0: lw          $t2, 0x11F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11F4);
    // 0x800215E4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800215E8: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x800215EC: lw          $t4, 0x20($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X20);
    // 0x800215F0: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800215F4: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800215F8: beq         $at, $zero, L_80021684
    if (ctx->r1 == 0) {
        // 0x800215FC: nop
    
            goto L_80021684;
    }
    // 0x800215FC: nop

L_80021600:
    // 0x80021600: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80021604: lw          $t7, 0x11F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11F4);
    // 0x80021608: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8002160C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80021610: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80021614: sw          $t9, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r25;
    // 0x80021618: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8002161C: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x80021620: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80021624: jalr        $t9
    // 0x80021628: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80021628: nop

    after_1:
    // 0x8002162C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80021630: jal         0x800218C4
    // 0x80021634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800218C4(rdram, ctx);
        goto after_2;
    // 0x80021634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80021638: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8002163C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80021640: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x80021644: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80021648: sw          $t3, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r11;
    // 0x8002164C: jal         0x80021960
    // 0x80021650: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_80021960(rdram, ctx);
        goto after_3;
    // 0x80021650: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x80021654: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80021658: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x8002165C: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80021660: sw          $v0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r2;
    // 0x80021664: lw          $t5, 0x11F4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11F4);
    // 0x80021668: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8002166C: lw          $t6, 0x1C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C);
    // 0x80021670: lw          $t8, 0x20($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X20);
    // 0x80021674: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x80021678: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002167C: bne         $at, $zero, L_80021600
    if (ctx->r1 != 0) {
        // 0x80021680: nop
    
            goto L_80021600;
    }
    // 0x80021680: nop

L_80021684:
    // 0x80021684: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80021688: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x8002168C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80021690: lw          $t2, 0x1C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1C);
    // 0x80021694: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80021698: sw          $t3, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r11;
    // 0x8002169C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800216A0: blez        $t1, L_80021750
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800216A4: nop
    
            goto L_80021750;
    }
    // 0x800216A4: nop

L_800216A8:
    // 0x800216A8: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x800216AC: lw          $t4, 0x11F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F4);
    // 0x800216B0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800216B4: lw          $t5, 0x44($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X44);
    // 0x800216B8: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800216BC: beq         $at, $zero, L_800216CC
    if (ctx->r1 == 0) {
        // 0x800216C0: nop
    
            goto L_800216CC;
    }
    // 0x800216C0: nop

    // 0x800216C4: b           L_800216D4
    // 0x800216C8: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
        goto L_800216D4;
    // 0x800216C8: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
L_800216CC:
    // 0x800216CC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800216D0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_800216D4:
    // 0x800216D4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800216D8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800216DC: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800216E0: lw          $t2, 0x11F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11F4);
    // 0x800216E4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800216E8: sw          $t0, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->r8;
    // 0x800216EC: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x800216F0: lw          $t3, 0x11F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11F4);
    // 0x800216F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800216F8: jal         0x800295D0
    // 0x800216FC: lw          $a0, 0x20($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X20);
    func_800295D0(rdram, ctx);
        goto after_4;
    // 0x800216FC: lw          $a0, 0x20($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X20);
    after_4:
    // 0x80021700: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80021704: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80021708: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002170C: subu        $t4, $t9, $t1
    ctx->r12 = SUB32(ctx->r25, ctx->r9);
    // 0x80021710: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80021714: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80021718: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002171C: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x80021720: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x80021724: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x80021728: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8002172C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80021730: lw          $t2, 0x11F4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X11F4);
    // 0x80021734: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80021738: lw          $t3, 0x20($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X20);
    // 0x8002173C: addu        $t1, $t3, $t9
    ctx->r9 = ADD32(ctx->r11, ctx->r25);
    // 0x80021740: sw          $t1, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r9;
    // 0x80021744: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80021748: bgtz        $t4, L_800216A8
    if (SIGNED(ctx->r12) > 0) {
        // 0x8002174C: nop
    
            goto L_800216A8;
    }
    // 0x8002174C: nop

L_80021750:
    // 0x80021750: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80021754: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80021758: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8002175C: subu        $t6, $t5, $t8
    ctx->r14 = SUB32(ctx->r13, ctx->r24);
    // 0x80021760: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80021764: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80021768: jal         0x80021820
    // 0x8002176C: nop

    func_80021820(rdram, ctx);
        goto after_5;
    // 0x8002176C: nop

    after_5:
    // 0x80021770: b           L_80021780
    // 0x80021774: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_80021780;
    // 0x80021774: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80021778: b           L_80021780
    // 0x8002177C: nop

        goto L_80021780;
    // 0x8002177C: nop

L_80021780:
    // 0x80021780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80021784: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80021788: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002178C: jr          $ra
    // 0x80021790: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80021790: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bsbegghead_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000AC: jal         0x8008CABC
    // 0x808000B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808000B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808000B4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808000B8: jal         0x80094BC0
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094BC0(rdram, ctx);
        goto after_1;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000C0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000C4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x808000C8: jal         0x80097C3C
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_shoot_egg(rdram, ctx);
        goto after_2;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D0: beql        $v0, $zero, L_80800108
    if (ctx->r2 == 0) {
        // 0x808000D4: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80800108;
    }
    goto skip_0;
    // 0x808000D4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000D8: jal         0x80094B14
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094B14(rdram, ctx);
        goto after_3;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000E0: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800104;
    }
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x800944E0
    // 0x808000EC: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    func_800944E0(rdram, ctx);
        goto after_4;
    // 0x808000EC: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    after_4:
    // 0x808000F0: lw          $a0, 0x15C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X15C);
    // 0x808000F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000F8: jal         0x800F1418
    // 0x808000FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_800F1418(rdram, ctx);
        goto after_5;
    // 0x808000FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_5:
    // 0x80800100: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
L_80800104:
    // 0x80800104: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800108:
    // 0x80800108: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080010C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800110: beq         $t7, $zero, L_808001D0
    if (ctx->r15 == 0) {
        // 0x80800114: nop
    
            goto L_808001D0;
    }
    // 0x80800114: nop

    // 0x80800118: jal         0x8008B348
    // 0x8080011C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    anctrl_isAt(rdram, ctx);
        goto after_6;
    // 0x8080011C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_6:
    // 0x80800120: beql        $v0, $zero, L_80800134
    if (ctx->r2 == 0) {
        // 0x80800124: lui         $a1, 0x3ECC
        ctx->r5 = S32(0X3ECC << 16);
            goto L_80800134;
    }
    goto skip_1;
    // 0x80800124: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    skip_1:
    // 0x80800128: jal         0x80084A88
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggsetup_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800130: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
L_80800134:
    // 0x80800134: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800138: jal         0x8008B348
    // 0x8080013C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_8;
    // 0x8080013C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80800140: beq         $v0, $zero, L_80800150
    if (ctx->r2 == 0) {
        // 0x80800144: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800150;
    }
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x80084A78
    // 0x8080014C: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    _baeggsetup_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x8080014C: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    after_9:
L_80800150:
    // 0x80800150: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    // 0x80800154: ori         $a1, $a1, 0xD845
    ctx->r5 = ctx->r5 | 0XD845;
    // 0x80800158: jal         0x8008B348
    // 0x8080015C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x8080015C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x80800160: beq         $v0, $zero, L_80800180
    if (ctx->r2 == 0) {
        // 0x80800164: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800180;
    }
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    // 0x8080016C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x80800170: jal         0x80084A60
    // 0x80800174: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    _baeggsetup_entrypoint_5(rdram, ctx);
        goto after_11;
    // 0x80800174: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    after_11:
    // 0x80800178: jal         0x800C6DA0
    // 0x8080017C: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800C6DA0(rdram, ctx);
        goto after_12;
    // 0x8080017C: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_12:
L_80800180:
    // 0x80800180: lui         $a1, 0x3F17
    ctx->r5 = S32(0X3F17 << 16);
    // 0x80800184: ori         $a1, $a1, 0x86C2
    ctx->r5 = ctx->r5 | 0X86C2;
    // 0x80800188: jal         0x8008B348
    // 0x8080018C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_13;
    // 0x8080018C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x80800190: beq         $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x80800194: nop
    
            goto L_808001D0;
    }
    // 0x80800194: nop

    // 0x80800198: lw          $t8, 0x160($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X160);
    // 0x8080019C: lw          $t9, 0x15C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X15C);
    // 0x808001A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001A4: lui         $a1, 0x3EC6
    ctx->r5 = S32(0X3EC6 << 16);
    // 0x808001A8: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808001AC: beq         $at, $zero, L_808001D0
    if (ctx->r1 == 0) {
        // 0x808001B0: nop
    
            goto L_808001D0;
    }
    // 0x808001B0: nop

    // 0x808001B4: jal         0x8008B24C
    // 0x808001B8: ori         $a1, $a1, 0x8DB9
    ctx->r5 = ctx->r5 | 0X8DB9;
    anctrl_setStart(rdram, ctx);
        goto after_14;
    // 0x808001B8: ori         $a1, $a1, 0x8DB9
    ctx->r5 = ctx->r5 | 0X8DB9;
    after_14:
    // 0x808001BC: jal         0x8008B064
    // 0x808001C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_start(rdram, ctx);
        goto after_15;
    // 0x808001C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x808001C4: lw          $t0, 0x160($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X160);
    // 0x808001C8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x808001CC: sw          $t1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r9;
L_808001D0:
    // 0x808001D0: jal         0x8008DD04
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_16;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001D8: beq         $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808001DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E8;
    }
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: addiu       $t2, $zero, 0x2F
    ctx->r10 = ADD32(0, 0X2F);
    // 0x808001E4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_808001E8:
    // 0x808001E8: jal         0x800919F4
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_17;
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808001F0: beq         $v0, $zero, L_80800240
    if (ctx->r2 == 0) {
        // 0x808001F4: nop
    
            goto L_80800240;
    }
    // 0x808001F4: nop

    // 0x808001F8: jal         0x8008B324
    // 0x808001FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_18;
    // 0x808001FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x80800200: beq         $v0, $zero, L_8080020C
    if (ctx->r2 == 0) {
        // 0x80800204: addiu       $t3, $zero, 0x7
        ctx->r11 = ADD32(0, 0X7);
            goto L_8080020C;
    }
    // 0x80800204: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80800208: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_8080020C:
    // 0x8080020C: jal         0x8008B2B4
    // 0x80800210: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_19;
    // 0x80800210: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_19:
    // 0x80800214: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(87, 0X2D0) << 16);
    // 0x80800218: lwc1        $f4, 0x2D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(87, 0X2D0));
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800224: nop

    // 0x80800228: bc1fl       L_80800258
    if (!c1cs) {
        // 0x8080022C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800258;
    }
    goto skip_2;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800230: jal         0x80082F78
    // 0x80800234: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _bscrouch_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80800234: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_20:
    // 0x80800238: b           L_80800254
    // 0x8080023C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_80800254;
    // 0x8080023C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80800240:
    // 0x80800240: jal         0x8008B324
    // 0x80800244: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_21;
    // 0x80800244: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x80800248: beq         $v0, $zero, L_80800254
    if (ctx->r2 == 0) {
        // 0x8080024C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80800254;
    }
    // 0x8080024C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800250: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_80800254:
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800258:
    // 0x80800258: jal         0x8009E5C8
    // 0x8080025C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_22;
    // 0x8080025C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_22:
    // 0x80800260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void func_80800318_chicekeydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800318: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080031C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800324: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800328: beq         $a1, $at, L_80800350
    if (ctx->r5 == ctx->r1) {
        // 0x8080032C: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80800350;
    }
    // 0x8080032C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800330: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800334: beq         $a1, $at, L_808004A4
    if (ctx->r5 == ctx->r1) {
        // 0x80800338: addiu       $a0, $zero, 0x513
        ctx->r4 = ADD32(0, 0X513);
            goto L_808004A4;
    }
    // 0x80800338: addiu       $a0, $zero, 0x513
    ctx->r4 = ADD32(0, 0X513);
    // 0x8080033C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800340: beq         $a1, $at, L_808003C0
    if (ctx->r5 == ctx->r1) {
        // 0x80800344: nop
    
            goto L_808003C0;
    }
    // 0x80800344: nop

    // 0x80800348: b           L_8080056C
    // 0x8080034C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080056C;
    // 0x8080034C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800350:
    // 0x80800350: jal         0x800F54E4
    // 0x80800354: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800354: nop

    after_0:
    // 0x80800358: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080035C: jal         0x800F5A00
    // 0x80800360: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80800360: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80800364: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800368: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080036C: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80800370: jal         0x800EF1B8
    // 0x80800374: lw          $a1, 0x24($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X24);
    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x80800374: lw          $a1, 0x24($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X24);
    after_2:
    // 0x80800378: jal         0x800F54E4
    // 0x8080037C: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x8080037C: nop

    after_3:
    // 0x80800380: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800384: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800388: jal         0x800F8300
    // 0x8080038C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800F8300(rdram, ctx);
        goto after_4;
    // 0x8080038C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80800390: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800394: jal         0x80101FDC
    // 0x80800398: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800398: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x8080039C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003A4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x808003A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003AC: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
    // 0x808003B0: jal         0x8008A4B0
    // 0x808003B4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x808003B4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x808003B8: b           L_8080056C
    // 0x808003BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080056C;
    // 0x808003BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003C0:
    // 0x808003C0: jal         0x800DA298
    // 0x808003C4: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808003C4: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    after_7:
    // 0x808003C8: beq         $v0, $zero, L_808003FC
    if (ctx->r2 == 0) {
        // 0x808003CC: lui         $at, 0xC2B4
        ctx->r1 = S32(0XC2B4 << 16);
            goto L_808003FC;
    }
    // 0x808003CC: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808003D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003D4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x808003D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003DC: swc1        $f6, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f6.u32l;
    // 0x808003E0: jal         0x80108B04
    // 0x808003E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80108B04(rdram, ctx);
        goto after_8;
    // 0x808003E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_8:
    // 0x808003E8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808003EC: jal         0x80101FDC
    // 0x808003F0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x808003F0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x808003F4: b           L_8080056C
    // 0x808003F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080056C;
    // 0x808003F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003FC:
    // 0x808003FC: jal         0x800D1A04
    // 0x80800400: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800D1A04(rdram, ctx);
        goto after_10;
    // 0x80800400: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_10:
    // 0x80800404: beq         $v0, $zero, L_80800488
    if (ctx->r2 == 0) {
        // 0x80800408: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800488;
    }
    // 0x80800408: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080040C: addiu       $a0, $zero, 0x299
    ctx->r4 = ADD32(0, 0X299);
    // 0x80800410: jal         0x80088278
    // 0x80800414: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800414: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_11:
    // 0x80800418: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8080041C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800420: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800424: jal         0x80088C00
    // 0x80800428: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80800428: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_12:
    // 0x8080042C: jal         0x80088C08
    // 0x80800430: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_13;
    // 0x80800430: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_13:
    // 0x80800434: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80800438: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8080043C: addiu       $a0, $zero, 0x511
    ctx->r4 = ADD32(0, 0X511);
    // 0x80800440: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800444: swc1        $f10, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f10.u32l;
    // 0x80800448: jal         0x80088278
    // 0x8080044C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x8080044C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_14:
    // 0x80800450: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800454: jal         0x80088C00
    // 0x80800458: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80800458: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_15:
    // 0x8080045C: jal         0x80088498
    // 0x80800460: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    _glsplinefind_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80800460: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_16:
    // 0x80800464: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80800468: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8080046C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800470: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800474: swc1        $f18, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f18.u32l;
    // 0x80800478: jal         0x80101FDC
    // 0x8080047C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x8080047C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_17:
    // 0x80800480: b           L_8080056C
    // 0x80800484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080056C;
    // 0x80800484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800488:
    // 0x80800488: jal         0x80103110
    // 0x8080048C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_18;
    // 0x8080048C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80800490: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800494: jal         0x80101FDC
    // 0x80800498: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x80800498: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x8080049C: b           L_8080056C
    // 0x808004A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080056C;
    // 0x808004A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004A4:
    // 0x808004A4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808004A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004AC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x808004B0: jal         0x80108528
    // 0x808004B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_20;
    // 0x808004B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_20:
    // 0x808004B8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x808004BC: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x808004C0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x808004C4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x808004C8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x808004CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004D0: sw          $t2, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r10;
    // 0x808004D4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x808004D8: beq         $v1, $zero, L_808004F0
    if (ctx->r3 == 0) {
        // 0x808004DC: sw          $t3, 0x3C($t4)
        MEM_W(0X3C, ctx->r12) = ctx->r11;
            goto L_808004F0;
    }
    // 0x808004DC: sw          $t3, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r11;
    // 0x808004E0: beql        $v1, $at, L_80800538
    if (ctx->r3 == ctx->r1) {
        // 0x808004E4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800538;
    }
    goto skip_0;
    // 0x808004E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x808004E8: b           L_80800548
    // 0x808004EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
        goto L_80800548;
    // 0x808004EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_808004F0:
    // 0x808004F0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x808004F4: lwc1        $f4, 0x34($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X34);
    // 0x808004F8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x808004FC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800500: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800504: jal         0x800D7520
    // 0x80800508: nop

    func_800D7520(rdram, ctx);
        goto after_21;
    // 0x80800508: nop

    after_21:
    // 0x8080050C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800510: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800514: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800518: jal         0x800C7A68
    // 0x8080051C: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    func_800C7A68(rdram, ctx);
        goto after_22;
    // 0x8080051C: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    after_22:
    // 0x80800520: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2468, 0X900) << 16);
    // 0x80800524: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800528: lwc1        $f8, 0x900($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2468, 0X900));
    // 0x8080052C: b           L_80800544
    // 0x80800530: swc1        $f8, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f8.u32l;
        goto L_80800544;
    // 0x80800530: swc1        $f8, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f8.u32l;
    // 0x80800534: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800538:
    // 0x80800538: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080053C: nop

    // 0x80800540: swc1        $f10, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f10.u32l;
L_80800544:
    // 0x80800544: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80800548:
    // 0x80800548: jal         0x8010A570
    // 0x8080054C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8010A570(rdram, ctx);
        goto after_23;
    // 0x8080054C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_23:
    // 0x80800550: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800558: lbu         $t7, 0x65($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X65);
    // 0x8080055C: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80800560: b           L_8080056C
    // 0x80800564: sb          $t8, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r24;
        goto L_8080056C;
    // 0x80800564: sb          $t8, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r24;
    // 0x80800568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080056C:
    // 0x8080056C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800570: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800574: jr          $ra
    // 0x80800578: nop

    return;
    // 0x80800578: nop

;}
RECOMP_FUNC void ncbaglide_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: jr          $ra
    // 0x80800078: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800078: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800188_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080018C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800190: beq         $a0, $zero, L_808001A8
    if (ctx->r4 == 0) {
        // 0x80800194: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_808001A8;
    }
    // 0x80800194: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800198: jal         0x800EE7F8
    // 0x8080019C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080019C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x808001A0: b           L_808001D8
    // 0x808001A4: nop

        goto L_808001D8;
    // 0x808001A4: nop

L_808001A8:
    // 0x808001A8: jal         0x800F54E4
    // 0x808001AC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808001AC: nop

    after_1:
    // 0x808001B0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808001B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001B8: jal         0x800F5A00
    // 0x808001BC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808001BC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x808001C0: jal         0x800F5F24
    // 0x808001C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F5F24(rdram, ctx);
        goto after_3;
    // 0x808001C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x808001C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001CC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001D0: jal         0x800EF1B8
    // 0x808001D4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x808001D4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_4:
L_808001D8:
    // 0x808001D8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2204, 0X25F8) << 16);
    // 0x808001DC: addiu       $t6, $t6, 0x25F8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2204, 0X25F8));
    // 0x808001E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001E4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001F0: jal         0x800BBCB8
    // 0x808001F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x808001F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x808001F8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2204, 0X2644) << 16);
    // 0x808001FC: addiu       $t7, $t7, 0x2644
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2204, 0X2644));
    // 0x80800200: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800204: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080020C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800210: jal         0x800BBCB8
    // 0x80800214: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_6;
    // 0x80800214: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080021C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_800F1198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1198: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800F119C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F11A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800F11A4: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F11A8: c.eq.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl == ctx->f14.fl;
    // 0x800F11AC: nop

    // 0x800F11B0: bc1t        L_800F11DC
    if (c1cs) {
        // 0x800F11B4: nop
    
            goto L_800F11DC;
    }
    // 0x800F11B4: nop

    // 0x800F11B8: sub.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800F11BC: lwc1        $f16, 0x10($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F11C0: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F11C4: sub.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800F11C8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800F11CC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800F11D0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800F11D4: jr          $ra
    // 0x800F11D8: add.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f18.fl;
    return;
    // 0x800F11D8: add.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f18.fl;
L_800F11DC:
    // 0x800F11DC: jr          $ra
    // 0x800F11E0: nop

    return;
    // 0x800F11E0: nop

;}
RECOMP_FUNC void func_80019994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019994: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80019998: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001999C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800199A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800199A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800199A8: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x800199AC: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800199B0: jal         0x80019C84
    // 0x800199B4: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    mlMtxTranslate(rdram, ctx);
        goto after_0;
    // 0x800199B4: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800199B8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800199BC: jal         0x8001907C
    // 0x800199C0: lwc1        $f12, 0x8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X8);
    mlMtxRotRoll(rdram, ctx);
        goto after_1;
    // 0x800199C0: lwc1        $f12, 0x8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X8);
    after_1:
    // 0x800199C4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800199C8: jal         0x80018F50
    // 0x800199CC: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    mlMtxRotPitch(rdram, ctx);
        goto after_2;
    // 0x800199CC: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x800199D0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800199D4: jal         0x80018FE8
    // 0x800199D8: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    mlMtxRotYaw(rdram, ctx);
        goto after_3;
    // 0x800199D8: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    after_3:
    // 0x800199DC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800199E0: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800199E4: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800199E8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800199EC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800199F0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800199F4: jal         0x80019C84
    // 0x800199F8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_4;
    // 0x800199F8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_4:
    // 0x800199FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80019A00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80019A04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80019A08: jr          $ra
    // 0x80019A0C: nop

    return;
    // 0x80019A0C: nop

;}
RECOMP_FUNC void func_8080026C_chdodgemdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080026C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800270: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800274: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800278: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080027C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800284: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800288: beq         $t6, $at, L_80800330
    if (ctx->r14 == ctx->r1) {
        // 0x8080028C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800330;
    }
    // 0x8080028C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800290: beq         $t6, $at, L_808002A8
    if (ctx->r14 == ctx->r1) {
        // 0x80800294: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808002A8;
    }
    // 0x80800294: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800298: beql        $t6, $at, L_80800334
    if (ctx->r14 == ctx->r1) {
        // 0x8080029C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800334;
    }
    goto skip_0;
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002A0: b           L_80800334
    // 0x808002A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800334;
    // 0x808002A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A8:
    // 0x808002A8: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002B4: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x808002B8: bltz        $t9, L_808002D4
    if (SIGNED(ctx->r25) < 0) {
        // 0x808002BC: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1756, 0X360) << 16);
            goto L_808002D4;
    }
    // 0x808002BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1756, 0X360) << 16);
    // 0x808002C0: jal         0x80089D18
    // 0x808002C4: addiu       $a2, $a2, 0x360
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1756, 0X360));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808002C4: addiu       $a2, $a2, 0x360
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1756, 0X360));
    after_0:
    // 0x808002C8: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x808002CC: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x808002D0: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
L_808002D4:
    // 0x808002D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1756, 0X358) << 16);
    // 0x808002D8: lwc1        $f6, 0x358($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1756, 0X358));
    // 0x808002DC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808002E8: nop

    // 0x808002EC: bc1f        L_80800318
    if (!c1cs) {
        // 0x808002F0: nop
    
            goto L_80800318;
    }
    // 0x808002F0: nop

    // 0x808002F4: jal         0x800D8FF8
    // 0x808002F8: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808002F8: nop

    after_1:
    // 0x808002FC: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x80800300: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800304: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800308: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8080030C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800310: b           L_80800330
    // 0x80800314: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
        goto L_80800330;
    // 0x80800314: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_80800318:
    // 0x80800318: jal         0x80101FDC
    // 0x8080031C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x8080031C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800320: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800324: srl         $t3, $a0, 7
    ctx->r11 = S32(U32(ctx->r4) >> 7);
    // 0x80800328: jal         0x800DA544
    // 0x8080032C: addiu       $a0, $t3, 0xAB
    ctx->r4 = ADD32(ctx->r11, 0XAB);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x8080032C: addiu       $a0, $t3, 0xAB
    ctx->r4 = ADD32(ctx->r11, 0XAB);
    after_3:
L_80800330:
    // 0x80800330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800334:
    // 0x80800334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080033C: jr          $ra
    // 0x80800340: nop

    return;
    // 0x80800340: nop

;}
RECOMP_FUNC void func_8001311C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001311C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80013120: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013124: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80013128: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001312C: jal         0x8002E660
    // 0x80013130: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80013130: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
    after_0:
    // 0x80013134: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80013138: addiu       $v0, $v0, -0x3390
    ctx->r2 = ADD32(ctx->r2, -0X3390);
    // 0x8001313C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80013140: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80013144: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80013148: addiu       $t0, $t0, 0x695C
    ctx->r8 = ADD32(ctx->r8, 0X695C);
    // 0x8001314C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80013150: addiu       $t9, $zero, 0x1800
    ctx->r25 = ADD32(0, 0X1800);
    // 0x80013154: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80013158: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001315C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80013160: addiu       $a0, $a0, 0x6940
    ctx->r4 = ADD32(ctx->r4, 0X6940);
    // 0x80013164: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80013168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001316C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013170: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80013174: jal         0x8002E450
    // 0x80013178: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x80013178: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8001317C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80013180: addiu       $a0, $a0, 0x695C
    ctx->r4 = ADD32(ctx->r4, 0X695C);
    // 0x80013184: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80013188: jal         0x8002E1F0
    // 0x8001318C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8001318C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80013190: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80013194: addiu       $v0, $v0, -0x3390
    ctx->r2 = ADD32(ctx->r2, -0X3390);
    // 0x80013198: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8001319C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800131A0: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
    // 0x800131A4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800131A8: jal         0x8002E6E0
    // 0x800131AC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    osInvalDCache_recomp(rdram, ctx);
        goto after_3;
    // 0x800131AC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_3:
    // 0x800131B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800131B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800131B8: jr          $ra
    // 0x800131BC: nop

    return;
    // 0x800131BC: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A00: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A00);
    return;
    // 0x80082A04: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _gsmaker_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825C0: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825C0);
    return;
    // 0x800825C4: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _bsrest_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839B8: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839B8);
    return;
    // 0x800839BC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void _gcegg_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883E8: syscall     680
    recomp_syscall_handler(rdram, ctx, 0x800883E8);
    return;
    // 0x800883EC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chpotogoldgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808018D8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808018DC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x808018E0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808018E4: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x808018E8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808018EC: addu        $s6, $t7, $a2
    ctx->r22 = ADD32(ctx->r15, ctx->r6);
    // 0x808018F0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808018F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808018F8: sltu        $at, $a2, $s6
    ctx->r1 = ctx->r6 < ctx->r22 ? 1 : 0;
    // 0x808018FC: andi        $s5, $s4, 0x10
    ctx->r21 = ctx->r20 & 0X10;
    // 0x80801900: andi        $t6, $s4, 0xF
    ctx->r14 = ctx->r20 & 0XF;
    // 0x80801904: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80801908: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080190C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801910: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801914: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801918: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080191C: beq         $at, $zero, L_80801970
    if (ctx->r1 == 0) {
        // 0x80801920: or          $s4, $t6, $zero
        ctx->r20 = ctx->r14 | 0;
            goto L_80801970;
    }
    // 0x80801920: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x80801924: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x80801928: addiu       $s2, $zero, 0x64
    ctx->r18 = ADD32(0, 0X64);
L_8080192C:
    // 0x8080192C: jal         0x80801998
    // 0x80801930: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801998_chpotogoldgame(rdram, ctx);
        goto after_0;
    // 0x80801930: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80801934: bnel        $v0, $s4, L_80801964
    if (ctx->r2 != ctx->r20) {
        // 0x80801938: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80801964;
    }
    goto skip_0;
    // 0x80801938: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_0:
    // 0x8080193C: beql        $s5, $zero, L_80801958
    if (ctx->r21 == 0) {
        // 0x80801940: sb          $s3, 0xC($s0)
        MEM_B(0XC, ctx->r16) = ctx->r19;
            goto L_80801958;
    }
    goto skip_1;
    // 0x80801940: sb          $s3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r19;
    skip_1:
    // 0x80801944: sb          $s2, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r18;
    // 0x80801948: sb          $s2, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r18;
    // 0x8080194C: b           L_80801960
    // 0x80801950: sb          $s2, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r18;
        goto L_80801960;
    // 0x80801950: sb          $s2, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r18;
    // 0x80801954: sb          $s3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r19;
L_80801958:
    // 0x80801958: sb          $s3, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r19;
    // 0x8080195C: sb          $s3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r19;
L_80801960:
    // 0x80801960: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_80801964:
    // 0x80801964: sltu        $at, $s0, $s6
    ctx->r1 = ctx->r16 < ctx->r22 ? 1 : 0;
    // 0x80801968: bne         $at, $zero, L_8080192C
    if (ctx->r1 != 0) {
        // 0x8080196C: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_8080192C;
    }
    // 0x8080196C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80801970:
    // 0x80801970: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801974: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801978: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080197C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801980: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801984: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801988: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8080198C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80801990: jr          $ra
    // 0x80801994: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801994: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _bskazstilt_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836A8: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836A8);
    return;
    // 0x800836AC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_808009B8_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808009C4: jal         0x800848D8
    // 0x808009C8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _badrone_entrypoint_30(rdram, ctx);
        goto after_0;
    // 0x808009C8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808009CC: beq         $v0, $zero, L_808009D8
    if (ctx->r2 == 0) {
        // 0x808009D0: addiu       $t6, $zero, 0xBB
        ctx->r14 = ADD32(0, 0XBB);
            goto L_808009D8;
    }
    // 0x808009D0: addiu       $t6, $zero, 0xBB
    ctx->r14 = ADD32(0, 0XBB);
    // 0x808009D4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808009D8:
    // 0x808009D8: jal         0x80082FE8
    // 0x808009DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808009DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808009E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009E4: jal         0x8009E5C8
    // 0x808009E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x808009E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808009EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009F4: jr          $ra
    // 0x808009F8: nop

    return;
    // 0x808009F8: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894D8: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800894D8);
    return;
    // 0x800894DC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _gspropctrl_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BC8: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BC8);
    return;
    // 0x80088BCC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800F5898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5898: jr          $ra
    // 0x800F589C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x800F589C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void glgamedata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800018: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080001C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2730, 0X4F0) << 16);
    // 0x80800028: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2730, 0X544) << 16);
    // 0x8080002C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800030: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80800034: addiu       $s2, $s2, 0x544
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2730, 0X544));
    // 0x80800038: addiu       $s1, $s1, 0x4F0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2730, 0X4F0));
L_8080003C:
    // 0x8080003C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80800040: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800044: beq         $v0, $zero, L_8080005C
    if (ctx->r2 == 0) {
        // 0x80800048: nop
    
            goto L_8080005C;
    }
    // 0x80800048: nop

    // 0x8080004C: jalr        $v0
    // 0x80800050: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80800050: nop

    after_0:
    // 0x80800054: b           L_8080005C
    // 0x80800058: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080005C;
    // 0x80800058: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080005C:
    // 0x8080005C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800060: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x80800064: bne         $s1, $s2, L_8080003C
    if (ctx->r17 != ctx->r18) {
        // 0x80800068: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8080003C;
    }
    // 0x80800068: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8080006C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800074: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800078: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080007C: jr          $ra
    // 0x80800080: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800080: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800428_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800428: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080042C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800430: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800434: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800438: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080043C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800440: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800444: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800448: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080044C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800450: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80800454: addiu       $s4, $zero, 0xD
    ctx->r20 = ADD32(0, 0XD);
L_80800458:
    // 0x80800458: jal         0x800D3FC0
    // 0x8080045C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D3FC0(rdram, ctx);
        goto after_0;
    // 0x8080045C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800460: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80800464: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80800468: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8080046C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800470: jal         0x80087D90
    // 0x80800474: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_1;
    // 0x80800474: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800478: jal         0x800D3E14
    // 0x8080047C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D3E14(rdram, ctx);
        goto after_2;
    // 0x8080047C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800480: beq         $v0, $zero, L_808004D0
    if (ctx->r2 == 0) {
        // 0x80800484: nop
    
            goto L_808004D0;
    }
    // 0x80800484: nop

    // 0x80800488: jal         0x800D3E40
    // 0x8080048C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D3E40(rdram, ctx);
        goto after_3;
    // 0x8080048C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800490: beq         $v0, $zero, L_808004AC
    if (ctx->r2 == 0) {
        // 0x80800494: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808004AC;
    }
    // 0x80800494: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800498: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080049C: jal         0x80087D40
    // 0x808004A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_21(rdram, ctx);
        goto after_4;
    // 0x808004A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x808004A4: b           L_808004B8
    // 0x808004A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_808004B8;
    // 0x808004A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_808004AC:
    // 0x808004AC: jal         0x80087D48
    // 0x808004B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_22(rdram, ctx);
        goto after_5;
    // 0x808004B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x808004B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_808004B8:
    // 0x808004B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808004BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808004C0: jal         0x80800194
    // 0x808004C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800194_chcheatomenu(rdram, ctx);
        goto after_6;
    // 0x808004C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x808004C8: b           L_80800500
    // 0x808004CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80800500;
    // 0x808004CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808004D0:
    // 0x808004D0: jal         0x800D3DD0
    // 0x808004D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D3DD0(rdram, ctx);
        goto after_7;
    // 0x808004D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x808004D8: beq         $v0, $zero, L_80800500
    if (ctx->r2 == 0) {
        // 0x808004DC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800500;
    }
    // 0x808004DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004E0: jal         0x80087D50
    // 0x808004E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_23(rdram, ctx);
        goto after_8;
    // 0x808004E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x808004E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808004EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808004F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808004F4: jal         0x80800194
    // 0x808004F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800194_chcheatomenu(rdram, ctx);
        goto after_9;
    // 0x808004F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x808004FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800500:
    // 0x80800500: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800504: bne         $s1, $s4, L_80800458
    if (ctx->r17 != ctx->r20) {
        // 0x80800508: nop
    
            goto L_80800458;
    }
    // 0x80800508: nop

    // 0x8080050C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800510: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800514: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800518: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080051C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800520: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800524: jr          $ra
    // 0x80800528: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800528: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80104200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104200: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80104204: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80104208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010420C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80104214: beq         $t6, $zero, L_80104230
    if (ctx->r14 == 0) {
        // 0x80104218: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80104230;
    }
    // 0x80104218: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8010421C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104220: jal         0x800B301C
    // 0x80104224: lw          $a0, 0x6E70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E70);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x80104224: lw          $a0, 0x6E70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E70);
    after_0:
    // 0x80104228: b           L_80104234
    // 0x8010422C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80104234;
    // 0x8010422C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80104230:
    // 0x80104230: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80104234:
    // 0x80104234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010423C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80104240: jr          $ra
    // 0x80104244: nop

    return;
    // 0x80104244: nop

;}
RECOMP_FUNC void bamovehover_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D8: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x808001DC: jal         0x800EE7F8
    // 0x808001E0: addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808001E0: addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
    after_0:
    // 0x808001E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001EC: jr          $ra
    // 0x808001F0: nop

    return;
    // 0x808001F0: nop

;}
RECOMP_FUNC void basudie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800028: jal         0x800F8B64
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F8B64(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800030: bne         $v0, $zero, L_80800054
    if (ctx->r2 != 0) {
        // 0x80800034: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800054;
    }
    // 0x80800034: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    // 0x8080003C: jal         0x80101238
    // 0x80800040: lw          $a1, 0x184($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X184);
    func_80101238(rdram, ctx);
        goto after_1;
    // 0x80800040: lw          $a1, 0x184($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X184);
    after_1:
    // 0x80800044: jal         0x800F90F8
    // 0x80800048: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F90F8(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8080004C: jal         0x800C0658
    // 0x80800050: nop

    func_800C0658(rdram, ctx);
        goto after_3;
    // 0x80800050: nop

    after_3:
L_80800054:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_808053BC_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808053BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808053C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808053C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808053C8: jal         0x80100094
    // 0x808053CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808053CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808053D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808053D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808053D8: jal         0x8010A828
    // 0x808053DC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8010A828(rdram, ctx);
        goto after_1;
    // 0x808053DC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x808053E0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808053E4: jal         0x8008A7B8
    // 0x808053E8: sb          $zero, 0x98($t6)
    MEM_B(0X98, ctx->r14) = 0;
    _suquiz_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808053E8: sb          $zero, 0x98($t6)
    MEM_B(0X98, ctx->r14) = 0;
    after_2:
    // 0x808053EC: jal         0x80800C24
    // 0x808053F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800C24_chquiz(rdram, ctx);
        goto after_3;
    // 0x808053F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808053F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808053F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808053FC: jr          $ra
    // 0x80805400: nop

    return;
    // 0x80805400: nop

;}
RECOMP_FUNC void idworldmake_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800790: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800794: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80800798: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080079C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808007A0: addiu       $s1, $s1, 0x7EF0
    ctx->r17 = ADD32(ctx->r17, 0X7EF0);
    // 0x808007A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808007AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808007B0: jal         0x800B296C
    // 0x808007B4: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    vector_end(rdram, ctx);
        goto after_0;
    // 0x808007B4: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    after_0:
    // 0x808007B8: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x808007BC: jal         0x800B28C4
    // 0x808007C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x808007C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x808007C4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x808007C8: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2954, 0XAB0) << 16);
    // 0x808007CC: addiu       $s2, $s2, 0xAB0
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2954, 0XAB0));
    // 0x808007D0: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x808007D4: beq         $at, $zero, L_80800844
    if (ctx->r1 == 0) {
        // 0x808007D8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800844;
    }
    // 0x808007D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808007DC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_808007E0:
    // 0x808007E0: bnel        $s3, $t6, L_80800838
    if (ctx->r19 != ctx->r14) {
        // 0x808007E4: addiu       $s0, $s0, 0xA8
        ctx->r16 = ADD32(ctx->r16, 0XA8);
            goto L_80800838;
    }
    goto skip_0;
    // 0x808007E4: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
    skip_0:
    // 0x808007E8: lbu         $t7, 0x6($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6);
    // 0x808007EC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x808007F0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x808007F4: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x808007F8: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x808007FC: jalr        $t9
    // 0x80800800: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800800: nop

    after_2:
    // 0x80800804: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80800808: jal         0x800B28E8
    // 0x8080080C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    vector_index_of(rdram, ctx);
        goto after_3;
    // 0x8080080C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800810: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80800814: jal         0x800B2E30
    // 0x80800818: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    vector_erase(rdram, ctx);
        goto after_4;
    // 0x80800818: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8080081C: jal         0x800B28C4
    // 0x80800820: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    vector_begin(rdram, ctx);
        goto after_5;
    // 0x80800820: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    after_5:
    // 0x80800824: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800828: jal         0x800B296C
    // 0x8080082C: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    vector_end(rdram, ctx);
        goto after_6;
    // 0x8080082C: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    after_6:
    // 0x80800830: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800834: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
L_80800838:
    // 0x80800838: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x8080083C: bnel        $at, $zero, L_808007E0
    if (ctx->r1 != 0) {
        // 0x80800840: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_808007E0;
    }
    goto skip_1;
    // 0x80800840: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80800844:
    // 0x80800844: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800848: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080084C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800850: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800854: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800858: jr          $ra
    // 0x8080085C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080085C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_801150F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801150F0: jr          $ra
    // 0x801150F4: lbu         $v0, 0xC($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XC);
    return;
    // 0x801150F4: lbu         $v0, 0xC($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XC);
;}
RECOMP_FUNC void chplatuegrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2460, 0X1D0) << 16);
    // 0x80800098: jr          $ra
    // 0x8080009C: addiu       $v0, $v0, 0x1D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2460, 0X1D0));
    return;
    // 0x8080009C: addiu       $v0, $v0, 0x1D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2460, 0X1D0));
;}
RECOMP_FUNC void func_8080074C_scradar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080074C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800750: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800754: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80800758: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8080075C: sb          $a2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r6;
    // 0x80800760: jr          $ra
    // 0x80800764: sb          $a3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r7;
    return;
    // 0x80800764: sb          $a3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_80800640_chicekeydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800640: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800644: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800648: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080064C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800650: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800654: lwc1        $f4, 0x48($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X48);
    // 0x80800658: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080065C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x80800660: jal         0x800D90A4
    // 0x80800664: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80800664: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800668: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080066C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800670: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800674: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800678: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080067C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800680: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800684: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800688: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080068C: lwc1        $f12, 0x58($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X58);
    // 0x80800690: jal         0x800F10B4
    // 0x80800694: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800694: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80800698: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8080069C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808006A0: lwc1        $f8, 0x34($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X34);
    // 0x808006A4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808006A8: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x808006AC: jal         0x800D7520
    // 0x808006B0: nop

    func_800D7520(rdram, ctx);
        goto after_2;
    // 0x808006B0: nop

    after_2:
    // 0x808006B4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808006B8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808006BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808006C0: jal         0x800C7A68
    // 0x808006C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C7A68(rdram, ctx);
        goto after_3;
    // 0x808006C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808006C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808006CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2468, 0X904) << 16);
    // 0x808006D0: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2468, 0X978) << 16);
    // 0x808006D4: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x808006D8: lwc1        $f18, 0x904($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2468, 0X904));
    // 0x808006DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808006E0: addiu       $t9, $t9, 0x978
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2468, 0X978));
    // 0x808006E4: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x808006E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808006EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808006F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808006F4: bc1f        L_80800738
    if (!c1cs) {
        // 0x808006F8: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80800738;
    }
    // 0x808006F8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808006FC: jal         0x800BBCB8
    // 0x80800700: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x80800700: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
    // 0x80800704: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2468, 0X908) << 16);
    // 0x80800708: lwc1        $f4, 0x908($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2468, 0X908));
    // 0x8080070C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800710: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800714: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800718: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8080071C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800720: jal         0x800F12D4
    // 0x80800724: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_5;
    // 0x80800724: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80800728: jal         0x800136E4
    // 0x8080072C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x8080072C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x80800730: b           L_80800744
    // 0x80800734: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
        goto L_80800744;
    // 0x80800734: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
L_80800738:
    // 0x80800738: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080073C: nop

    // 0x80800740: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
L_80800744:
    // 0x80800744: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800748: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080074C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800750: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800754: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800758: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080075C: bc1fl       L_8080078C
    if (!c1cs) {
        // 0x80800760: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8080078C;
    }
    goto skip_0;
    // 0x80800760: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x80800764: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800768: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080076C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800770: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800774: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800778: jal         0x800F12D4
    // 0x8080077C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F12D4(rdram, ctx);
        goto after_7;
    // 0x8080077C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x80800780: b           L_80800794
    // 0x80800784: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
        goto L_80800794;
    // 0x80800784: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800788: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8080078C:
    // 0x8080078C: nop

    // 0x80800790: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
L_80800794:
    // 0x80800794: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80800798: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080079C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808007A0: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x808007A4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808007A8: nop

    // 0x808007AC: bc1fl       L_808007CC
    if (!c1cs) {
        // 0x808007B0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_808007CC;
    }
    goto skip_1;
    // 0x808007B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x808007B4: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808007B8: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x808007BC: nop

    // 0x808007C0: bc1tl       L_808007F4
    if (c1cs) {
        // 0x808007C4: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_808007F4;
    }
    goto skip_2;
    // 0x808007C4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_2:
    // 0x808007C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_808007CC:
    // 0x808007CC: nop

    // 0x808007D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808007D4: nop

    // 0x808007D8: bc1fl       L_808008CC
    if (!c1cs) {
        // 0x808007DC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808008CC;
    }
    goto skip_3;
    // 0x808007DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808007E0: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808007E4: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x808007E8: nop

    // 0x808007EC: bc1f        L_808008C8
    if (!c1cs) {
        // 0x808007F0: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_808008C8;
    }
    // 0x808007F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_808007F4:
    // 0x808007F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007F8: nop

    // 0x808007FC: mul.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x80800800: jal         0x80013970
    // 0x80800804: nop

    func_80013970(rdram, ctx);
        goto after_8;
    // 0x80800804: nop

    after_8:
    // 0x80800808: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2468, 0X90C) << 16);
    // 0x8080080C: lwc1        $f6, 0x90C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2468, 0X90C));
    // 0x80800810: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2468, 0X910) << 16);
    // 0x80800814: lwc1        $f10, 0x910($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2468, 0X910));
    // 0x80800818: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080081C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800820: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800824: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800828: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080082C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800830: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800834: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800838: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8080083C: nop

    // 0x80800840: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800844: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800848: nop

    // 0x8080084C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800850: beql        $a0, $zero, L_808008A0
    if (ctx->r4 == 0) {
        // 0x80800854: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_808008A0;
    }
    goto skip_4;
    // 0x80800854: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_4:
    // 0x80800858: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080085C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800860: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800864: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800868: nop

    // 0x8080086C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800870: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800874: nop

    // 0x80800878: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8080087C: bne         $a0, $zero, L_80800894
    if (ctx->r4 != 0) {
        // 0x80800880: nop
    
            goto L_80800894;
    }
    // 0x80800880: nop

    // 0x80800884: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80800888: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080088C: b           L_808008AC
    // 0x80800890: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808008AC;
    // 0x80800890: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800894:
    // 0x80800894: b           L_808008AC
    // 0x80800898: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808008AC;
    // 0x80800898: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8080089C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_808008A0:
    // 0x808008A0: nop

    // 0x808008A4: bltz        $a0, L_80800894
    if (SIGNED(ctx->r4) < 0) {
        // 0x808008A8: nop
    
            goto L_80800894;
    }
    // 0x808008A8: nop

L_808008AC:
    // 0x808008AC: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x808008B0: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x808008B4: ori         $at, $at, 0x5E64
    ctx->r1 = ctx->r1 | 0X5E64;
    // 0x808008B8: sll         $t2, $t1, 21
    ctx->r10 = S32(ctx->r9 << 21);
    // 0x808008BC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808008C0: jal         0x800C4140
    // 0x808008C4: addu        $a0, $t2, $at
    ctx->r4 = ADD32(ctx->r10, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_9;
    // 0x808008C4: addu        $a0, $t2, $at
    ctx->r4 = ADD32(ctx->r10, ctx->r1);
    after_9:
L_808008C8:
    // 0x808008C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808008CC:
    // 0x808008CC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x808008D0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808008D4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808008D8: jr          $ra
    // 0x808008DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808008DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _chweldarboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865E0: syscall     346
    recomp_syscall_handler(rdram, ctx, 0x800865E0);
    return;
    // 0x800865E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void sujiggy_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080059C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808005AC: jal         0x800DA298
    // 0x808005B0: addiu       $a0, $zero, 0x58A
    ctx->r4 = ADD32(0, 0X58A);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808005B0: addiu       $a0, $zero, 0x58A
    ctx->r4 = ADD32(0, 0X58A);
    after_0:
    // 0x808005B4: beq         $v0, $zero, L_808005F4
    if (ctx->r2 == 0) {
        // 0x808005B8: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_808005F4;
    }
    // 0x808005B8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808005BC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808005C0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3354, 0X8EC) << 16);
    // 0x808005C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808005C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x808005CC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x808005D0: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x808005D4: jal         0x80800000
    // 0x808005D8: lw          $a0, 0x8EC($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(3354, 0X8EC));
    func_80800000_sujiggy(rdram, ctx);
        goto after_1;
    // 0x808005D8: lw          $a0, 0x8EC($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(3354, 0X8EC));
    after_1:
    // 0x808005DC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808005E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005E4: jal         0x800887D8
    // 0x808005E8: addiu       $a1, $a1, 0x7A
    ctx->r5 = ADD32(ctx->r5, 0X7A);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808005E8: addiu       $a1, $a1, 0x7A
    ctx->r5 = ADD32(ctx->r5, 0X7A);
    after_2:
    // 0x808005EC: b           L_8080064C
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080064C;
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005F4:
    // 0x808005F4: beq         $t8, $zero, L_8080060C
    if (ctx->r24 == 0) {
        // 0x808005F8: addiu       $a0, $zero, 0x14F
        ctx->r4 = ADD32(0, 0X14F);
            goto L_8080060C;
    }
    // 0x808005F8: addiu       $a0, $zero, 0x14F
    ctx->r4 = ADD32(0, 0X14F);
    // 0x808005FC: jal         0x800887D8
    // 0x80800600: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800600: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    after_3:
    // 0x80800604: b           L_8080064C
    // 0x80800608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080064C;
    // 0x80800608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080060C:
    // 0x8080060C: jal         0x800DA544
    // 0x80800610: addiu       $a0, $zero, 0x58A
    ctx->r4 = ADD32(0, 0X58A);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800610: addiu       $a0, $zero, 0x58A
    ctx->r4 = ADD32(0, 0X58A);
    after_4:
    // 0x80800614: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800618: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3354, 0X8EC) << 16);
    // 0x8080061C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80800620: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80800624: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80800628: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8080062C: jal         0x80800000
    // 0x80800630: lw          $a0, 0x8EC($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(3354, 0X8EC));
    func_80800000_sujiggy(rdram, ctx);
        goto after_5;
    // 0x80800630: lw          $a0, 0x8EC($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(3354, 0X8EC));
    after_5:
    // 0x80800634: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800638: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080063C: addiu       $a1, $zero, 0x151
    ctx->r5 = ADD32(0, 0X151);
    // 0x80800640: jal         0x80088868
    // 0x80800644: addiu       $a2, $a2, 0x7A
    ctx->r6 = ADD32(ctx->r6, 0X7A);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_6;
    // 0x80800644: addiu       $a2, $a2, 0x7A
    ctx->r6 = ADD32(ctx->r6, 0X7A);
    after_6:
    // 0x80800648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080064C:
    // 0x8080064C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800650: jr          $ra
    // 0x80800654: nop

    return;
    // 0x80800654: nop

;}
RECOMP_FUNC void func_80800374_gcsectionskip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080037C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800384: jal         0x800F7E3C
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7E3C(rdram, ctx);
        goto after_0;
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080038C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800390: jal         0x808002A0
    // 0x80800394: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_808002A0_gcsectionskip(rdram, ctx);
        goto after_1;
    // 0x80800394: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080039C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
