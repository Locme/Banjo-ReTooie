#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chfantasycannon_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B78: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2392, 0XD30) << 16);
    // 0x80800B7C: jr          $ra
    // 0x80800B80: addiu       $v0, $v0, 0xD30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2392, 0XD30));
    return;
    // 0x80800B80: addiu       $v0, $v0, 0xD30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2392, 0XD30));
;}
RECOMP_FUNC void func_80800934_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080093C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800940: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800944: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80800948: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080094C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800950: beq         $v0, $zero, L_8080097C
    if (ctx->r2 == 0) {
        // 0x80800954: addiu       $a1, $zero, 0x16
        ctx->r5 = ADD32(0, 0X16);
            goto L_8080097C;
    }
    // 0x80800954: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80800958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080095C: beq         $v0, $at, L_8080098C
    if (ctx->r2 == ctx->r1) {
        // 0x80800960: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080098C;
    }
    // 0x80800960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800964: beq         $v0, $at, L_8080098C
    if (ctx->r2 == ctx->r1) {
        // 0x80800968: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080098C;
    }
    // 0x80800968: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080096C: beql        $v0, $at, L_80800998
    if (ctx->r2 == ctx->r1) {
        // 0x80800970: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_80800998;
    }
    goto skip_0;
    // 0x80800970: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x80800974: b           L_808009A8
    // 0x80800978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808009A8;
    // 0x80800978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080097C:
    // 0x8080097C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800980: jal         0x800856B0
    // 0x80800984: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800984: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800988: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8080098C:
    // 0x8080098C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800990: sw          $t6, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r14;
    // 0x80800994: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_80800998:
    // 0x80800998: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080099C: jal         0x80085740
    // 0x808009A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808009A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808009A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009A8:
    // 0x808009A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009AC: jr          $ra
    // 0x808009B0: nop

    return;
    // 0x808009B0: nop

;}
RECOMP_FUNC void func_80800294_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080029C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002A0: beq         $a1, $zero, L_808002C0
    if (ctx->r5 == 0) {
        // 0x808002A4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_808002C0;
    }
    // 0x808002A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808002A8: jal         0x800DA298
    // 0x808002AC: addiu       $a0, $zero, 0x9C8
    ctx->r4 = ADD32(0, 0X9C8);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808002AC: addiu       $a0, $zero, 0x9C8
    ctx->r4 = ADD32(0, 0X9C8);
    after_0:
    // 0x808002B0: beq         $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x808002B4: nop
    
            goto L_808002C0;
    }
    // 0x808002B4: nop

    // 0x808002B8: jal         0x800904C8
    // 0x808002BC: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800904C8(rdram, ctx);
        goto after_1;
    // 0x808002BC: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_1:
L_808002C0:
    // 0x808002C0: jal         0x800EA05C
    // 0x808002C4: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x808002C4: nop

    after_2:
    // 0x808002C8: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
    // 0x808002CC: beq         $v0, $at, L_80800310
    if (ctx->r2 == ctx->r1) {
        // 0x808002D0: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80800310;
    }
    // 0x808002D0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D4: beq         $t7, $zero, L_808002F0
    if (ctx->r15 == 0) {
        // 0x808002D8: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_808002F0;
    }
    // 0x808002D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808002DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808002E0: jal         0x80090734
    // 0x808002E4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80090734(rdram, ctx);
        goto after_3;
    // 0x808002E4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x808002E8: b           L_8080032C
    // 0x808002EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080032C;
    // 0x808002EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002F0:
    // 0x808002F0: jal         0x800DA298
    // 0x808002F4: addiu       $a0, $zero, 0x9C8
    ctx->r4 = ADD32(0, 0X9C8);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808002F4: addiu       $a0, $zero, 0x9C8
    ctx->r4 = ADD32(0, 0X9C8);
    after_4:
    // 0x808002F8: beql        $v0, $zero, L_8080032C
    if (ctx->r2 == 0) {
        // 0x808002FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080032C;
    }
    goto skip_0;
    // 0x808002FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800300: jal         0x80090708
    // 0x80800304: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_5;
    // 0x80800304: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800308: b           L_8080032C
    // 0x8080030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080032C;
    // 0x8080030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800310:
    // 0x80800310: jal         0x800DA298
    // 0x80800314: addiu       $a0, $zero, 0x9C8
    ctx->r4 = ADD32(0, 0X9C8);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800314: addiu       $a0, $zero, 0x9C8
    ctx->r4 = ADD32(0, 0X9C8);
    after_6:
    // 0x80800318: beql        $v0, $zero, L_8080032C
    if (ctx->r2 == 0) {
        // 0x8080031C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080032C;
    }
    goto skip_1;
    // 0x8080031C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800320: jal         0x80090658
    // 0x80800324: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80090658(rdram, ctx);
        goto after_7;
    // 0x80800324: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_7:
    // 0x80800328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080032C:
    // 0x8080032C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void func_808000AC_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B8: jal         0x80089F48
    // 0x808000BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000C0: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x808000C4: jal         0x800DA298
    // 0x808000C8: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808000C8: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    after_1:
    // 0x808000CC: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F4;
    }
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x80108B04
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E0: jal         0x80101FDC
    // 0x808000E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808000E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808000E8: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x808000EC: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x808000F0: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_808000F4:
    // 0x808000F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void chfactoryworkerdirty_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C04: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800C08: jal         0x80106790
    // 0x80800C0C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800C0C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800C10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C14: jal         0x80100094
    // 0x80800C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800C1C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800C20: jal         0x80101010
    // 0x80800C24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80101010(rdram, ctx);
        goto after_2;
    // 0x80800C24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800C28: jal         0x8010105C
    // 0x80800C2C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_8010105C(rdram, ctx);
        goto after_3;
    // 0x80800C2C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800C30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C34: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800C38: jal         0x80800068
    // 0x80800C3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800068_chfactoryworkerdirty(rdram, ctx);
        goto after_4;
    // 0x80800C3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C48: jr          $ra
    // 0x80800C4C: nop

    return;
    // 0x80800C4C: nop

;}
RECOMP_FUNC void func_808000B8_chcolldoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000D4: beq         $t6, $at, L_808000EC
    if (ctx->r14 == ctx->r1) {
        // 0x808000D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000EC;
    }
    // 0x808000D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000DC: beql        $t6, $at, L_808001C4
    if (ctx->r14 == ctx->r1) {
        // 0x808000E0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_808001C4;
    }
    goto skip_0;
    // 0x808000E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x808000E4: b           L_80800254
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000EC:
    // 0x808000EC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808000F0: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x808000F4: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x808000F8: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x808000FC: beq         $t7, $at, L_8080011C
    if (ctx->r15 == ctx->r1) {
        // 0x80800100: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_8080011C;
    }
    // 0x80800100: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80800104: beq         $t7, $at, L_80800144
    if (ctx->r15 == ctx->r1) {
        // 0x80800108: addiu       $at, $zero, 0x35
        ctx->r1 = ADD32(0, 0X35);
            goto L_80800144;
    }
    // 0x80800108: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x8080010C: beq         $t7, $at, L_8080016C
    if (ctx->r15 == ctx->r1) {
        // 0x80800110: nop
    
            goto L_8080016C;
    }
    // 0x80800110: nop

    // 0x80800114: b           L_80800190
    // 0x80800118: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_80800190;
    // 0x80800118: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_8080011C:
    // 0x8080011C: jal         0x800DA298
    // 0x80800120: addiu       $a0, $zero, 0x577
    ctx->r4 = ADD32(0, 0X577);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800120: addiu       $a0, $zero, 0x577
    ctx->r4 = ADD32(0, 0X577);
    after_0:
    // 0x80800124: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800128: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080012C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800130: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x80800134: jal         0x80088178
    // 0x80800138: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800138: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x8080013C: b           L_80800190
    // 0x80800140: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_80800190;
    // 0x80800140: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800144:
    // 0x80800144: jal         0x800DA298
    // 0x80800148: addiu       $a0, $zero, 0x368
    ctx->r4 = ADD32(0, 0X368);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800148: addiu       $a0, $zero, 0x368
    ctx->r4 = ADD32(0, 0X368);
    after_2:
    // 0x8080014C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800150: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800154: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800158: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x8080015C: jal         0x80088178
    // 0x80800160: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800160: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x80800164: b           L_80800190
    // 0x80800168: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_80800190;
    // 0x80800168: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_8080016C:
    // 0x8080016C: jal         0x800DA298
    // 0x80800170: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800170: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    after_4:
    // 0x80800174: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800178: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080017C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800180: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x80800184: jal         0x80088178
    // 0x80800188: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800188: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x8080018C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800190:
    // 0x80800190: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800194: beql        $t8, $zero, L_80800254
    if (ctx->r24 == 0) {
        // 0x80800198: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800254;
    }
    goto skip_1;
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080019C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808001A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001A4: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
    // 0x808001A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808001AC: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x808001B0: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x808001B4: sb          $t1, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r9;
    // 0x808001B8: b           L_80800250
    // 0x808001BC: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
        goto L_80800250;
    // 0x808001BC: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x808001C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_808001C4:
    // 0x808001C4: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001D0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x808001D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808001D8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1844, 0X270) << 16);
    // 0x808001DC: bc1f        L_8080023C
    if (!c1cs) {
        // 0x808001E0: nop
    
            goto L_8080023C;
    }
    // 0x808001E0: nop

    // 0x808001E4: jal         0x80089D50
    // 0x808001E8: addiu       $a3, $a3, 0x270
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1844, 0X270));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x808001E8: addiu       $a3, $a3, 0x270
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1844, 0X270));
    after_6:
    // 0x808001EC: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808001F0: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808001F4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808001F8: nop

    // 0x808001FC: bc1fl       L_8080022C
    if (!c1cs) {
        // 0x80800200: lbu         $t2, 0x72($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X72);
            goto L_8080022C;
    }
    goto skip_2;
    // 0x80800200: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
    skip_2:
    // 0x80800204: jal         0x800D8FF8
    // 0x80800208: nop

    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x80800208: nop

    after_7:
    // 0x8080020C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800210: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800214: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800218: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8080021C: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80800220: b           L_80800250
    // 0x80800224: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_80800250;
    // 0x80800224: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80800228: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
L_8080022C:
    // 0x8080022C: andi        $t3, $t2, 0xFF03
    ctx->r11 = ctx->r10 & 0XFF03;
    // 0x80800230: ori         $t4, $t3, 0xC
    ctx->r12 = ctx->r11 | 0XC;
    // 0x80800234: b           L_80800250
    // 0x80800238: sb          $t4, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r12;
        goto L_80800250;
    // 0x80800238: sb          $t4, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r12;
L_8080023C:
    // 0x8080023C: jal         0x800D8FF8
    // 0x80800240: nop

    func_800D8FF8(rdram, ctx);
        goto after_8;
    // 0x80800240: nop

    after_8:
    // 0x80800244: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800248: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8080024C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80800250:
    // 0x80800250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800254:
    // 0x80800254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void func_80800070_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800074: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800078: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8080007C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X7004) << 16);
    // 0x80800080: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800084: jr          $ra
    // 0x80800088: lwc1        $f0, 0x7004($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X7004));
    return;
    // 0x80800088: lwc1        $f0, 0x7004($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X7004));
;}
RECOMP_FUNC void func_80800000_chdoormake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080000C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800014: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800018: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x8080001C: jal         0x80100074
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800028: lbu         $t0, 0x8($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X8);
    // 0x8080002C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800030: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800034: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x80800038: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8080003C: sb          $t2, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r10;
    // 0x80800040: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80800044: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80800048: addiu       $t4, $zero, 0x200
    ctx->r12 = ADD32(0, 0X200);
    // 0x8080004C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800050: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x80800054: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x80800058: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x8080005C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800060: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800064: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800068: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
L_8080006C:
    // 0x8080006C: lbu         $t5, 0x22($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X22);
    // 0x80800070: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800074: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80800078: andi        $t6, $t5, 0xFF7F
    ctx->r14 = ctx->r13 & 0XFF7F;
    // 0x8080007C: sb          $t6, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r14;
    // 0x80800080: bne         $a0, $a1, L_8080006C
    if (ctx->r4 != ctx->r5) {
        // 0x80800084: sb          $zero, 0x18($v1)
        MEM_B(0X18, ctx->r3) = 0;
            goto L_8080006C;
    }
    // 0x80800084: sb          $zero, 0x18($v1)
    MEM_B(0X18, ctx->r3) = 0;
    // 0x80800088: andi        $t7, $a3, 0x4
    ctx->r15 = ctx->r7 & 0X4;
    // 0x8080008C: beq         $t7, $zero, L_808000A4
    if (ctx->r15 == 0) {
        // 0x80800090: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000A4;
    }
    // 0x80800090: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800098: jal         0x80103110
    // 0x8080009C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x8080009C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x808000A0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_808000A4:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000AC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083238: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083238);
    return;
    // 0x8008323C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bssplitup_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AF0: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AF0);
    return;
    // 0x80083AF4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800D70_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D78: jal         0x808005F0
    // 0x80800D7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808005F0_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80800D7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D80: jal         0x800839C8
    // 0x80800D84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800D84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D8C: jal         0x8009BA9C
    // 0x80800D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_2;
    // 0x80800D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D9C: jr          $ra
    // 0x80800DA0: nop

    return;
    // 0x80800DA0: nop

;}
RECOMP_FUNC void cic_send_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E04C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001E050: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E054: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E05C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001E060: addiu       $v0, $v0, -0x27B0
    ctx->r2 = ADD32(ctx->r2, -0X27B0);
    // 0x8001E064: addiu       $a0, $a0, -0x2782
    ctx->r4 = ADD32(ctx->r4, -0X2782);
    // 0x8001E068: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_8001E06C:
    // 0x8001E06C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E070: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8001E074: bne         $at, $zero, L_8001E06C
    if (ctx->r1 != 0) {
        // 0x8001E078: sb          $v1, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r3;
            goto L_8001E06C;
    }
    // 0x8001E078: sb          $v1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r3;
    // 0x8001E07C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001E080: addiu       $a3, $a3, -0x27B0
    ctx->r7 = ADD32(ctx->r7, -0X27B0);
    // 0x8001E084: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8001E088: sb          $a0, 0x2E($a3)
    MEM_B(0X2E, ctx->r7) = ctx->r4;
    // 0x8001E08C: sb          $a0, 0x2F($a3)
    MEM_B(0X2F, ctx->r7) = ctx->r4;
    // 0x8001E090: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E094: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E098: addiu       $v0, $v0, -0x27B0
    ctx->r2 = ADD32(ctx->r2, -0X27B0);
    // 0x8001E09C: addiu       $a0, $a0, -0x27A0
    ctx->r4 = ADD32(ctx->r4, -0X27A0);
    // 0x8001E0A0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8001E0A4:
    // 0x8001E0A4: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8001E0A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001E0AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001E0B0: sb          $t6, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r14;
    // 0x8001E0B4: lbu         $t7, -0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, -0X3);
    // 0x8001E0B8: sb          $t7, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r15;
    // 0x8001E0BC: lbu         $t8, -0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, -0X2);
    // 0x8001E0C0: sb          $t8, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r24;
    // 0x8001E0C4: lbu         $t9, -0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, -0X1);
    // 0x8001E0C8: bne         $v0, $a0, L_8001E0A4
    if (ctx->r2 != ctx->r4) {
        // 0x8001E0CC: sb          $t9, 0x2F($v0)
        MEM_B(0X2F, ctx->r2) = ctx->r25;
            goto L_8001E0A4;
    }
    // 0x8001E0CC: sb          $t9, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r25;
    // 0x8001E0D0: jal         0x800319F0
    // 0x8001E0D4: nop

    __osSiGetAccess_recomp(rdram, ctx);
        goto after_0;
    // 0x8001E0D4: nop

    after_0:
    // 0x8001E0D8: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x8001E0DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E0E0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E0E4: sb          $t0, 0x10C0($at)
    MEM_B(0X10C0, ctx->r1) = ctx->r8;
    // 0x8001E0E8: addiu       $a0, $a0, -0x27B0
    ctx->r4 = ADD32(ctx->r4, -0X27B0);
    // 0x8001E0EC: jal         0x8002E660
    // 0x8001E0F0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x8001E0F0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x8001E0F4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001E0F8: addiu       $a1, $a1, -0x27B0
    ctx->r5 = ADD32(ctx->r5, -0X27B0);
    // 0x8001E0FC: jal         0x80031A60
    // 0x8001E100: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    __osSiRawStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x8001E100: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8001E104: jal         0x80031A34
    // 0x8001E108: nop

    __osSiRelAccess_recomp(rdram, ctx);
        goto after_3;
    // 0x8001E108: nop

    after_3:
    // 0x8001E10C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E114: jr          $ra
    // 0x8001E118: nop

    return;
    // 0x8001E118: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A630: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A630);
    return;
    // 0x8008A634: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void subaddiepalette_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800008: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080000C: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800018: jal         0x800D674C
    // 0x8080001C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800020: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800028: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    // 0x8080002C: jal         0x8001BBA0
    // 0x80800030: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x80800034: jal         0x800D6CEC
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800D6CEC(rdram, ctx);
        goto after_2;
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080003C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800040: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x80800044: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80800048: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8080004C: jal         0x808002BC
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    subaddiepalette_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800054: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800058: lhu         $a2, 0x2A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2A);
    // 0x8080005C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80800060: jal         0x801032B0
    // 0x80800064: lhu         $a1, 0x14($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X14);
    func_801032B0(rdram, ctx);
        goto after_4;
    // 0x80800064: lhu         $a1, 0x14($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X14);
    after_4:
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080006C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_800A336C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A336C: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3370: jr          $ra
    // 0x800A3374: lbu         $v0, 0x3C($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X3C);
    return;
    // 0x800A3374: lbu         $v0, 0x3C($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X3C);
;}
RECOMP_FUNC void func_80800870_sucoasterhit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800870: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800874: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800878: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080087C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800880: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800884: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800888: lw          $a0, 0x18($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X18);
    // 0x8080088C: srl         $t6, $a0, 28
    ctx->r14 = S32(U32(ctx->r4) >> 28);
    // 0x80800890: jal         0x8008A240
    // 0x80800894: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800894: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80800898: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8080089C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808008A0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x808008A4: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x808008A8: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x808008AC: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x808008B0: beql        $t9, $zero, L_80800990
    if (ctx->r25 == 0) {
        // 0x808008B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800990;
    }
    goto skip_0;
    // 0x808008B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808008B8: beql        $t0, $zero, L_80800978
    if (ctx->r8 == 0) {
        // 0x808008BC: lbu         $a0, 0x5F($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X5F);
            goto L_80800978;
    }
    goto skip_1;
    // 0x808008BC: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    skip_1:
    // 0x808008C0: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808008C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3302, 0XCDC) << 16);
    // 0x808008C8: addiu       $a2, $a2, 0xCDC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3302, 0XCDC));
    // 0x808008CC: bne         $a0, $zero, L_80800954
    if (ctx->r4 != 0) {
        // 0x808008D0: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80800954;
    }
    // 0x808008D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808008D4: jal         0x800C4350
    // 0x808008D8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x808008D8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_1:
    // 0x808008DC: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x808008E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3302, 0XCA0) << 16);
    // 0x808008E4: lwc1        $f12, 0xCA0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3302, 0XCA0));
    // 0x808008E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3302, 0XCA4) << 16);
    // 0x808008EC: jal         0x800DC178
    // 0x808008F0: lwc1        $f14, 0xCA4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3302, 0XCA4));
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x808008F0: lwc1        $f14, 0xCA4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3302, 0XCA4));
    after_2:
    // 0x808008F4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808008F8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808008FC: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800900: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800904: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x80800908: lh          $t2, 0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X8);
    // 0x8080090C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80800910: nop

    // 0x80800914: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800918: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080091C: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800920: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80800924: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x80800928: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x8080092C: jal         0x800C301C
    // 0x80800930: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800C301C(rdram, ctx);
        goto after_3;
    // 0x80800930: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800934: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800938: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x8080093C: jal         0x800C3058
    // 0x80800940: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    func_800C3058(rdram, ctx);
        goto after_4;
    // 0x80800940: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    after_4:
    // 0x80800944: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800948: jal         0x800C31DC
    // 0x8080094C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800C31DC(rdram, ctx);
        goto after_5;
    // 0x8080094C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800950: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
L_80800954:
    // 0x80800954: beq         $a0, $zero, L_8080098C
    if (ctx->r4 == 0) {
        // 0x80800958: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8080098C;
    }
    // 0x80800958: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080095C: jal         0x800C4350
    // 0x80800960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_6;
    // 0x80800960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800964: jal         0x800C3BDC
    // 0x80800968: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_7;
    // 0x80800968: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_7:
    // 0x8080096C: b           L_80800990
    // 0x80800970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800990;
    // 0x80800970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800974: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
L_80800978:
    // 0x80800978: beql        $a0, $zero, L_80800990
    if (ctx->r4 == 0) {
        // 0x8080097C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800990;
    }
    goto skip_2;
    // 0x8080097C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800980: jal         0x800C2FDC
    // 0x80800984: nop

    func_800C2FDC(rdram, ctx);
        goto after_8;
    // 0x80800984: nop

    after_8:
    // 0x80800988: sb          $zero, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = 0;
L_8080098C:
    // 0x8080098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800990:
    // 0x80800990: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800994: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800998: jr          $ra
    // 0x8080099C: nop

    return;
    // 0x8080099C: nop

;}
RECOMP_FUNC void func_800C65E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C65E0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800C65E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C65E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C65EC: lbu         $v1, 0x94($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X94);
    // 0x800C65F0: lbu         $t6, 0x8E($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8E);
    // 0x800C65F4: lbu         $t7, 0x8F($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X8F);
    // 0x800C65F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C65FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C6600: sb          $zero, 0x8F($a0)
    MEM_B(0X8F, ctx->r4) = 0;
    // 0x800C6604: sb          $zero, 0x8E($a0)
    MEM_B(0X8E, ctx->r4) = 0;
    // 0x800C6608: sb          $t6, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r14;
    // 0x800C660C: beq         $v1, $at, L_800C6620
    if (ctx->r3 == ctx->r1) {
        // 0x800C6610: sb          $t7, 0x91($a0)
        MEM_B(0X91, ctx->r4) = ctx->r15;
            goto L_800C6620;
    }
    // 0x800C6610: sb          $t7, 0x91($a0)
    MEM_B(0X91, ctx->r4) = ctx->r15;
    // 0x800C6614: lbu         $t9, 0x93($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X93);
    // 0x800C6618: beql        $t9, $zero, L_800C6694
    if (ctx->r25 == 0) {
        // 0x800C661C: addiu       $t3, $s0, 0x4C
        ctx->r11 = ADD32(ctx->r16, 0X4C);
            goto L_800C6694;
    }
    goto skip_0;
    // 0x800C661C: addiu       $t3, $s0, 0x4C
    ctx->r11 = ADD32(ctx->r16, 0X4C);
    skip_0:
L_800C6620:
    // 0x800C6620: lbu         $t0, 0x93($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X93);
    // 0x800C6624: lui         $a2, 0x45DA
    ctx->r6 = S32(0X45DA << 16);
    // 0x800C6628: lw          $a3, 0x88($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X88);
    // 0x800C662C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800C6630: sb          $t1, 0x93($s0)
    MEM_B(0X93, ctx->r16) = ctx->r9;
    // 0x800C6634: addiu       $t2, $sp, 0x3C
    ctx->r10 = ADD32(ctx->r29, 0X3C);
    // 0x800C6638: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C663C: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x800C6640: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x800C6644: jal         0x800C5BE4
    // 0x800C6648: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    func_800C5BE4(rdram, ctx);
        goto after_0;
    // 0x800C6648: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    after_0:
    // 0x800C664C: beq         $v0, $zero, L_800C6668
    if (ctx->r2 == 0) {
        // 0x800C6650: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C6668;
    }
    // 0x800C6650: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C6654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C6658: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800C665C: jal         0x800C5FCC
    // 0x800C6660: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_800C5FCC(rdram, ctx);
        goto after_1;
    // 0x800C6660: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x800C6664: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
L_800C6668:
    // 0x800C6668: beq         $a2, $zero, L_800C6684
    if (ctx->r6 == 0) {
        // 0x800C666C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C6684;
    }
    // 0x800C666C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C6670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C6674: jal         0x800C5A10
    // 0x800C6678: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C5A10(rdram, ctx);
        goto after_2;
    // 0x800C6678: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x800C667C: b           L_800C6690
    // 0x800C6680: lbu         $v1, 0x94($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X94);
        goto L_800C6690;
    // 0x800C6680: lbu         $v1, 0x94($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X94);
L_800C6684:
    // 0x800C6684: jal         0x800C5A10
    // 0x800C6688: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C5A10(rdram, ctx);
        goto after_3;
    // 0x800C6688: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x800C668C: lbu         $v1, 0x94($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X94);
L_800C6690:
    // 0x800C6690: addiu       $t3, $s0, 0x4C
    ctx->r11 = ADD32(ctx->r16, 0X4C);
L_800C6694:
    // 0x800C6694: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C6698: beq         $v1, $at, L_800C66BC
    if (ctx->r3 == ctx->r1) {
        // 0x800C669C: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_800C66BC;
    }
    // 0x800C669C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800C66A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C66A4: beq         $v1, $at, L_800C66CC
    if (ctx->r3 == ctx->r1) {
        // 0x800C66A8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800C66CC;
    }
    // 0x800C66A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C66AC: beq         $v1, $at, L_800C66DC
    if (ctx->r3 == ctx->r1) {
        // 0x800C66B0: nop
    
            goto L_800C66DC;
    }
    // 0x800C66B0: nop

    // 0x800C66B4: b           L_800C66E8
    // 0x800C66B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
        goto L_800C66E8;
    // 0x800C66B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
L_800C66BC:
    // 0x800C66BC: jal         0x800C6060
    // 0x800C66C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C6060(rdram, ctx);
        goto after_4;
    // 0x800C66C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800C66C4: b           L_800C66E8
    // 0x800C66C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
        goto L_800C66E8;
    // 0x800C66C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
L_800C66CC:
    // 0x800C66CC: jal         0x800C6320
    // 0x800C66D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C6320(rdram, ctx);
        goto after_5;
    // 0x800C66D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800C66D4: b           L_800C66E8
    // 0x800C66D8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
        goto L_800C66E8;
    // 0x800C66D8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
L_800C66DC:
    // 0x800C66DC: jal         0x800C6420
    // 0x800C66E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C6420(rdram, ctx);
        goto after_6;
    // 0x800C66E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800C66E4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
L_800C66E8:
    // 0x800C66E8: jal         0x800EE7F8
    // 0x800C66EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x800C66EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x800C66F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C66F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C66F8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800C66FC: jr          $ra
    // 0x800C6700: nop

    return;
    // 0x800C6700: nop

;}
RECOMP_FUNC void chflamer_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1088, 0XB20) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xB20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1088, 0XB20));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xB20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1088, 0XB20));
;}
RECOMP_FUNC void func_80800B28_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800B2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B34: jal         0x801022E4
    // 0x80800B38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80800B38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800B3C: addiu       $at, $zero, 0x3A9
    ctx->r1 = ADD32(0, 0X3A9);
    // 0x80800B40: bne         $v0, $at, L_80800B8C
    if (ctx->r2 != ctx->r1) {
        // 0x80800B44: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1296, 0X12B0) << 16);
            goto L_80800B8C;
    }
    // 0x80800B44: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1296, 0X12B0) << 16);
    // 0x80800B48: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800B4C: jal         0x800EE7F8
    // 0x80800B50: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800B50: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800B54: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800B58: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800B5C: jal         0x800EF1B8
    // 0x80800B60: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x80800B60: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    after_2:
    // 0x80800B64: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1296, 0X12A0) << 16);
    // 0x80800B68: addiu       $a0, $a0, 0x12A0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1296, 0X12A0));
    // 0x80800B6C: jal         0x80088090
    // 0x80800B70: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800B70: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x80800B74: jal         0x80088098
    // 0x80800B78: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800B78: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800B7C: jal         0x800880A0
    // 0x80800B80: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800B80: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_5:
    // 0x80800B84: b           L_80800BAC
    // 0x80800B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BAC;
    // 0x80800B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B8C:
    // 0x80800B8C: addiu       $a0, $a0, 0x12B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1296, 0X12B0));
    // 0x80800B90: jal         0x80088090
    // 0x80800B94: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800B94: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x80800B98: jal         0x80088098
    // 0x80800B9C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800B9C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800BA0: jal         0x800880A0
    // 0x80800BA4: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x80800BA4: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_8:
    // 0x80800BA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BAC:
    // 0x80800BAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800BB4: jr          $ra
    // 0x80800BB8: nop

    return;
    // 0x80800BB8: nop

;}
RECOMP_FUNC void _inantab_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F78: syscall     750
    recomp_syscall_handler(rdram, ctx, 0x80088F78);
    return;
    // 0x80088F7C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void gsmaker_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808002CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808002D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002D4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808002D8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808002DC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808002E0: blez        $a2, L_80800300
    if (SIGNED(ctx->r6) <= 0) {
        // 0x808002E4: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80800300;
    }
    // 0x808002E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_808002E8:
    // 0x808002E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002EC: jal         0x808002A4
    // 0x808002F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gsmaker_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x808002F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x808002F4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808002F8: bgtz        $s0, L_808002E8
    if (SIGNED(ctx->r16) > 0) {
        // 0x808002FC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808002E8;
    }
    // 0x808002FC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80800300:
    // 0x80800300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800304: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800308: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080030C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800310: jr          $ra
    // 0x80800314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bskazjump_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800848: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080084C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800850: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800854: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800858: jal         0x8008CABC
    // 0x8080085C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080085C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800860: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800864: jal         0x800832E0
    // 0x80800868: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800868: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8080086C: jal         0x8008AF24
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800878: jal         0x8008AED4
    // 0x8080087C: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x8080087C: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    after_3:
    // 0x80800880: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800884: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800888: jal         0x8008B1C8
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800890: lui         $a1, 0x3FF3
    ctx->r5 = S32(0X3FF3 << 16);
    // 0x80800894: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800898: jal         0x8008B1BC
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808008A0: lui         $a1, 0x3F2A
    ctx->r5 = S32(0X3F2A << 16);
    // 0x808008A4: ori         $a1, $a1, 0xACDA
    ctx->r5 = ctx->r5 | 0XACDA;
    // 0x808008A8: jal         0x8008B24C
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B4: jal         0x8008B134
    // 0x808008B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x808008B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808008BC: jal         0x8008B064
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808008C4: jal         0x8009F308
    // 0x808008C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009F308(rdram, ctx);
        goto after_9;
    // 0x808008C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x808008CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808008D0: jal         0x8009C914
    // 0x808008D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_10;
    // 0x808008D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x808008D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008DC: jal         0x8008CA4C
    // 0x808008E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_11;
    // 0x808008E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808008E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008E8: jal         0x8009C908
    // 0x808008EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_12;
    // 0x808008EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808008F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008F4: jal         0x8009D2D8
    // 0x808008F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_13;
    // 0x808008F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x808008FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800900: jal         0x8009B800
    // 0x80800904: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_14;
    // 0x80800904: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_14:
    // 0x80800908: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080090C: jal         0x8009B9B0
    // 0x80800910: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_15;
    // 0x80800910: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_15:
    // 0x80800914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800918: jal         0x8009BA9C
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_16;
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800920: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800924: sw          $t6, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r14;
    // 0x80800928: jal         0x8008E944
    // 0x8080092C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008E944(rdram, ctx);
        goto after_17;
    // 0x8080092C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800934: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800938: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080093C: jr          $ra
    // 0x80800940: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800940: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chexploder_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801578: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080157C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801580: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801584: beq         $a1, $zero, L_8080159C
    if (ctx->r5 == 0) {
        // 0x80801588: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_8080159C;
    }
    // 0x80801588: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080158C: jal         0x800EE7F8
    // 0x80801590: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80801590: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80801594: b           L_808015AC
    // 0x80801598: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
        goto L_808015AC;
    // 0x80801598: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_8080159C:
    // 0x8080159C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808015A0: jal         0x80103DFC
    // 0x808015A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80103DFC(rdram, ctx);
        goto after_1;
    // 0x808015A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808015A8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_808015AC:
    // 0x808015AC: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x808015B0: beql        $t7, $zero, L_808015C4
    if (ctx->r15 == 0) {
        // 0x808015B4: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_808015C4;
    }
    goto skip_0;
    // 0x808015B4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x808015B8: jal         0x8010A570
    // 0x808015BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x808015BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x808015C0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_808015C4:
    // 0x808015C4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x808015C8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x808015CC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808015D0: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x808015D4: addiu       $a0, $a0, 0x6660
    ctx->r4 = ADD32(ctx->r4, 0X6660);
    // 0x808015D8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808015DC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808015E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808015E4: jal         0x80086D50
    // 0x808015E8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808015E8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_3:
    // 0x808015EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808015F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808015F4: jr          $ra
    // 0x808015F8: nop

    return;
    // 0x808015F8: nop

;}
RECOMP_FUNC void func_80807024_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807024: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80807028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080702C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807030: jal         0x8009E6EC
    // 0x80807034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80807034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80807038: slti        $at, $v0, 0x4F
    ctx->r1 = SIGNED(ctx->r2) < 0X4F ? 1 : 0;
    // 0x8080703C: bne         $at, $zero, L_8080706C
    if (ctx->r1 != 0) {
        // 0x80807040: addiu       $at, $zero, 0x4F
        ctx->r1 = ADD32(0, 0X4F);
            goto L_8080706C;
    }
    // 0x80807040: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x80807044: beq         $v0, $at, L_808070B4
    if (ctx->r2 == ctx->r1) {
        // 0x80807048: addiu       $at, $zero, 0x5F
        ctx->r1 = ADD32(0, 0X5F);
            goto L_808070B4;
    }
    // 0x80807048: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x8080704C: beq         $v0, $at, L_80807170
    if (ctx->r2 == ctx->r1) {
        // 0x80807050: addiu       $at, $zero, 0x7D
        ctx->r1 = ADD32(0, 0X7D);
            goto L_80807170;
    }
    // 0x80807050: addiu       $at, $zero, 0x7D
    ctx->r1 = ADD32(0, 0X7D);
    // 0x80807054: beq         $v0, $at, L_80807110
    if (ctx->r2 == ctx->r1) {
        // 0x80807058: addiu       $at, $zero, 0x8E
        ctx->r1 = ADD32(0, 0X8E);
            goto L_80807110;
    }
    // 0x80807058: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x8080705C: beq         $v0, $at, L_808070E0
    if (ctx->r2 == ctx->r1) {
        // 0x80807060: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808070E0;
    }
    // 0x80807060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807064: b           L_808071A8
    // 0x80807068: nop

        goto L_808071A8;
    // 0x80807068: nop

L_8080706C:
    // 0x8080706C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80807070: beq         $v0, $at, L_80807098
    if (ctx->r2 == ctx->r1) {
        // 0x80807074: addiu       $at, $zero, 0x21
        ctx->r1 = ADD32(0, 0X21);
            goto L_80807098;
    }
    // 0x80807074: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80807078: beq         $v0, $at, L_80807098
    if (ctx->r2 == ctx->r1) {
        // 0x8080707C: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_80807098;
    }
    // 0x8080707C: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80807080: beq         $v0, $at, L_80807098
    if (ctx->r2 == ctx->r1) {
        // 0x80807084: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80807098;
    }
    // 0x80807084: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80807088: beq         $v0, $at, L_80807098
    if (ctx->r2 == ctx->r1) {
        // 0x8080708C: addiu       $at, $zero, 0x4E
        ctx->r1 = ADD32(0, 0X4E);
            goto L_80807098;
    }
    // 0x8080708C: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x80807090: bne         $v0, $at, L_808071A8
    if (ctx->r2 != ctx->r1) {
        // 0x80807094: nop
    
            goto L_808071A8;
    }
    // 0x80807094: nop

L_80807098:
    // 0x80807098: jal         0x80082820
    // 0x8080709C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbabykaz_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x8080709C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808070A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808070A4: jal         0x8009E830
    // 0x808070A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x808070A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808070AC: b           L_808071B4
    // 0x808070B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808071B4;
    // 0x808070B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808070B4:
    // 0x808070B4: jal         0x80082820
    // 0x808070B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbabykaz_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x808070B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808070BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808070C0: jal         0x8009E830
    // 0x808070C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_4;
    // 0x808070C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808070C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808070CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808070D0: jal         0x80085338
    // 0x808070D4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_5;
    // 0x808070D4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_5:
    // 0x808070D8: b           L_808071B4
    // 0x808070DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808071B4;
    // 0x808070DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808070E0:
    // 0x808070E0: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x808070E4: jal         0x8009E5C8
    // 0x808070E8: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808070E8: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    after_6:
    // 0x808070EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808070F0: jal         0x8009E830
    // 0x808070F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_7;
    // 0x808070F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808070F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808070FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80807100: jal         0x80085338
    // 0x80807104: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_8;
    // 0x80807104: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x80807108: b           L_808071B4
    // 0x8080710C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808071B4;
    // 0x8080710C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807110:
    // 0x80807110: lw          $t6, 0x158($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X158);
    // 0x80807114: beq         $t6, $zero, L_80807160
    if (ctx->r14 == 0) {
        // 0x80807118: nop
    
            goto L_80807160;
    }
    // 0x80807118: nop

    // 0x8080711C: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x80807120: jal         0x800F53D0
    // 0x80807124: lw          $a0, 0x68($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X68);
    func_800F53D0(rdram, ctx);
        goto after_9;
    // 0x80807124: lw          $a0, 0x68($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X68);
    after_9:
    // 0x80807128: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080712C: jal         0x80099A58
    // 0x80807130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_10;
    // 0x80807130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80807134: jal         0x80085518
    // 0x80807138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _badeathmatch_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x80807138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8080713C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80807140: jal         0x80099A64
    // 0x80807144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A64(rdram, ctx);
        goto after_12;
    // 0x80807144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80807148: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080714C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80807150: jal         0x80085520
    // 0x80807154: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _badeathmatch_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x80807154: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_13:
    // 0x80807158: b           L_808071B4
    // 0x8080715C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808071B4;
    // 0x8080715C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807160:
    // 0x80807160: jal         0x80099B94
    // 0x80807164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_14;
    // 0x80807164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80807168: b           L_808071B4
    // 0x8080716C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808071B4;
    // 0x8080716C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807170:
    // 0x80807170: lw          $t7, 0x158($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X158);
    // 0x80807174: beql        $t7, $zero, L_808071B4
    if (ctx->r15 == 0) {
        // 0x80807178: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808071B4;
    }
    goto skip_0;
    // 0x80807178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080717C: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x80807180: jal         0x800F53D0
    // 0x80807184: lw          $a0, 0x68($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X68);
    func_800F53D0(rdram, ctx);
        goto after_15;
    // 0x80807184: lw          $a0, 0x68($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X68);
    after_15:
    // 0x80807188: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080718C: jal         0x80099A34
    // 0x80807190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A34(rdram, ctx);
        goto after_16;
    // 0x80807190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80807194: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80807198: jal         0x80802BE8
    // 0x8080719C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80802BE8_bsfirstp(rdram, ctx);
        goto after_17;
    // 0x8080719C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x808071A0: b           L_808071B4
    // 0x808071A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808071B4;
    // 0x808071A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808071A8:
    // 0x808071A8: jal         0x80099B94
    // 0x808071AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_18;
    // 0x808071AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808071B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808071B4:
    // 0x808071B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808071B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808071BC: jr          $ra
    // 0x808071C0: nop

    return;
    // 0x808071C0: nop

;}
RECOMP_FUNC void chswitch_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D14: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800D18: jal         0x800DA298
    // 0x80800D1C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800D1C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800D20: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800D28: beq         $v0, $zero, L_80800D50
    if (ctx->r2 == 0) {
        // 0x80800D2C: sw          $t6, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r14;
            goto L_80800D50;
    }
    // 0x80800D2C: sw          $t6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r14;
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D34: jal         0x80102424
    // 0x80800D38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800D38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D40: jal         0x80101EE4
    // 0x80800D44: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101EE4(rdram, ctx);
        goto after_2;
    // 0x80800D44: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_2:
    // 0x80800D48: b           L_80800D60
    // 0x80800D4C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_80800D60;
    // 0x80800D4C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800D50:
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D54: jal         0x80102424
    // 0x80800D58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800D58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800D5C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800D60:
    // 0x80800D60: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D68: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800D6C: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x80800D70: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80800D74: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80800D78: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80800D7C: jal         0x80103110
    // 0x80800D80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x80800D80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800D84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D88: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800D8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D90: jr          $ra
    // 0x80800D94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800D94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800D98: nop

    // 0x80800D9C: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007E4: jal         0x8008CABC
    // 0x808007E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808007E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808007EC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808007F0: jal         0x808000C8
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C8_bsblongleg(rdram, ctx);
        goto after_1;
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800800: jal         0x8009D2F0
    // 0x80800804: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_2;
    // 0x80800804: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_2:
    // 0x80800808: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    // 0x8080080C: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800814: jal         0x800A2CE8
    // 0x80800818: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_3;
    // 0x80800818: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x8080081C: lui         $a1, 0x3F78
    ctx->r5 = S32(0X3F78 << 16);
    // 0x80800820: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800828: jal         0x800A2CE8
    // 0x8080082C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_4;
    // 0x8080082C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x80800830: lui         $a1, 0x3F47
    ctx->r5 = S32(0X3F47 << 16);
    // 0x80800834: ori         $a1, $a1, 0x3190
    ctx->r5 = ctx->r5 | 0X3190;
    // 0x80800838: jal         0x8008B348
    // 0x8080083C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x8080083C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800840: beq         $v0, $zero, L_80800850
    if (ctx->r2 == 0) {
        // 0x80800844: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    // 0x80800844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800848: jal         0x80800020
    // 0x8080084C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800020_bsblongleg(rdram, ctx);
        goto after_6;
    // 0x8080084C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_80800850:
    // 0x80800850: lui         $a1, 0x3E8E
    ctx->r5 = S32(0X3E8E << 16);
    // 0x80800854: ori         $a1, $a1, 0x6320
    ctx->r5 = ctx->r5 | 0X6320;
    // 0x80800858: jal         0x8008B348
    // 0x8080085C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x8080085C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80800860: beq         $v0, $zero, L_80800870
    if (ctx->r2 == 0) {
        // 0x80800864: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800870;
    }
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800868: jal         0x80800020
    // 0x8080086C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800020_bsblongleg(rdram, ctx);
        goto after_8;
    // 0x8080086C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_80800870:
    // 0x80800870: jal         0x80800064
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800064_bsblongleg(rdram, ctx);
        goto after_9;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080087C: jal         0x80091A58
    // 0x80800880: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_10;
    // 0x80800880: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_10:
    // 0x80800884: beq         $v0, $zero, L_808008B4
    if (ctx->r2 == 0) {
        // 0x80800888: nop
    
            goto L_808008B4;
    }
    // 0x80800888: nop

    // 0x8080088C: jal         0x8009BB00
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800894: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808008A0: nop

    // 0x808008A4: bc1f        L_808008B4
    if (!c1cs) {
        // 0x808008A8: nop
    
            goto L_808008B4;
    }
    // 0x808008A8: nop

    // 0x808008AC: jal         0x80091788
    // 0x808008B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_clear(rdram, ctx);
        goto after_12;
    // 0x808008B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
L_808008B4:
    // 0x808008B4: jal         0x8009EF10
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_13;
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808008BC: bne         $v0, $zero, L_808008D8
    if (ctx->r2 != 0) {
        // 0x808008C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008D8;
    }
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C4: jal         0x8009BCD4
    // 0x808008C8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_14;
    // 0x808008C8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_14:
    // 0x808008CC: beq         $v0, $zero, L_808008D8
    if (ctx->r2 == 0) {
        // 0x808008D0: addiu       $t6, $zero, 0x26
        ctx->r14 = ADD32(0, 0X26);
            goto L_808008D8;
    }
    // 0x808008D0: addiu       $t6, $zero, 0x26
    ctx->r14 = ADD32(0, 0X26);
    // 0x808008D4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808008D8:
    // 0x808008D8: jal         0x8008DF18
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_15;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808008E0: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x808008E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008F0;
    }
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E8: addiu       $t7, $zero, 0x55
    ctx->r15 = ADD32(0, 0X55);
    // 0x808008EC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808008F0:
    // 0x808008F0: jal         0x80091A58
    // 0x808008F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_16;
    // 0x808008F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_16:
    // 0x808008F8: beql        $v0, $zero, L_80800918
    if (ctx->r2 == 0) {
        // 0x808008FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800918;
    }
    goto skip_0;
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800900: jal         0x8008E078
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_17;
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800908: beq         $v0, $zero, L_80800914
    if (ctx->r2 == 0) {
        // 0x8080090C: addiu       $t8, $zero, 0x28
        ctx->r24 = ADD32(0, 0X28);
            goto L_80800914;
    }
    // 0x8080090C: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80800910: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800914:
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800918:
    // 0x80800918: jal         0x800915AC
    // 0x8080091C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_isDone(rdram, ctx);
        goto after_18;
    // 0x8080091C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x80800920: beq         $v0, $zero, L_8080092C
    if (ctx->r2 == 0) {
        // 0x80800924: addiu       $t9, $zero, 0x29
        ctx->r25 = ADD32(0, 0X29);
            goto L_8080092C;
    }
    // 0x80800924: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x80800928: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_8080092C:
    // 0x8080092C: jal         0x80800000
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsblongleg(rdram, ctx);
        goto after_19;
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800934: beq         $v0, $zero, L_80800944
    if (ctx->r2 == 0) {
        // 0x80800938: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800944;
    }
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080093C: addiu       $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
    // 0x80800940: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80800944:
    // 0x80800944: jal         0x8009E5C8
    // 0x80800948: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_20;
    // 0x80800948: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_20:
    // 0x8080094C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800950: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800954: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800958: jr          $ra
    // 0x8080095C: nop

    return;
    // 0x8080095C: nop

;}
RECOMP_FUNC void func_80800154_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080015C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800160: jal         0x8009EF10
    // 0x80800164: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x80800164: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800168: beq         $v0, $zero, L_80800190
    if (ctx->r2 == 0) {
        // 0x8080016C: addiu       $v1, $zero, 0x145
        ctx->r3 = ADD32(0, 0X145);
            goto L_80800190;
    }
    // 0x8080016C: addiu       $v1, $zero, 0x145
    ctx->r3 = ADD32(0, 0X145);
    // 0x80800170: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800174: beq         $v0, $at, L_80800198
    if (ctx->r2 == ctx->r1) {
        // 0x80800178: addiu       $v1, $zero, 0x146
        ctx->r3 = ADD32(0, 0X146);
            goto L_80800198;
    }
    // 0x80800178: addiu       $v1, $zero, 0x146
    ctx->r3 = ADD32(0, 0X146);
    // 0x8080017C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800180: beq         $v0, $at, L_808001A0
    if (ctx->r2 == ctx->r1) {
        // 0x80800184: addiu       $t6, $zero, 0x144
        ctx->r14 = ADD32(0, 0X144);
            goto L_808001A0;
    }
    // 0x80800184: addiu       $t6, $zero, 0x144
    ctx->r14 = ADD32(0, 0X144);
    // 0x80800188: b           L_808001A4
    // 0x8080018C: nop

        goto L_808001A4;
    // 0x8080018C: nop

L_80800190:
    // 0x80800190: b           L_808001A4
    // 0x80800194: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
        goto L_808001A4;
    // 0x80800194: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_80800198:
    // 0x80800198: b           L_808001A4
    // 0x8080019C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
        goto L_808001A4;
    // 0x8080019C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_808001A0:
    // 0x808001A0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808001A4:
    // 0x808001A4: jal         0x8009E6F8
    // 0x808001A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_getCurrentState(rdram, ctx);
        goto after_1;
    // 0x808001A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808001AC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001B0: beq         $v0, $v1, L_808001BC
    if (ctx->r2 == ctx->r3) {
        // 0x808001B4: nop
    
            goto L_808001BC;
    }
    // 0x808001B4: nop

    // 0x808001B8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_808001BC:
    // 0x808001BC: jal         0x80800000
    // 0x808001C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800000_bstrexsmall(rdram, ctx);
        goto after_2;
    // 0x808001C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808001C4: beq         $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x808001C8: addiu       $t7, $zero, 0x143
        ctx->r15 = ADD32(0, 0X143);
            goto L_808001D0;
    }
    // 0x808001C8: addiu       $t7, $zero, 0x143
    ctx->r15 = ADD32(0, 0X143);
    // 0x808001CC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808001D0:
    // 0x808001D0: jal         0x8008DD04
    // 0x808001D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008DD04(rdram, ctx);
        goto after_3;
    // 0x808001D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808001D8: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x808001DC: addiu       $t8, $zero, 0x13E
        ctx->r24 = ADD32(0, 0X13E);
            goto L_808001E4;
    }
    // 0x808001DC: addiu       $t8, $zero, 0x13E
    ctx->r24 = ADD32(0, 0X13E);
    // 0x808001E0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808001E4:
    // 0x808001E4: jal         0x8080003C
    // 0x808001E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8080003C_bstrexsmall(rdram, ctx);
        goto after_4;
    // 0x808001E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808001EC: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001F0: addiu       $t9, $zero, 0x13F
        ctx->r25 = ADD32(0, 0X13F);
            goto L_808001F8;
    }
    // 0x808001F0: addiu       $t9, $zero, 0x13F
    ctx->r25 = ADD32(0, 0X13F);
    // 0x808001F4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_808001F8:
    // 0x808001F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001FC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void func_800F1574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1574: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F1578: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F157C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800F1580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F1584: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F1588: nop

    // 0x800F158C: bc1f        L_800F15BC
    if (!c1cs) {
        // 0x800F1590: nop
    
            goto L_800F15BC;
    }
    // 0x800F1590: nop

    // 0x800F1594: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800F1598: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800F159C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F15A0: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x800F15A4: nop

    // 0x800F15A8: bc1f        L_800F15BC
    if (!c1cs) {
        // 0x800F15AC: nop
    
            goto L_800F15BC;
    }
    // 0x800F15AC: nop

    // 0x800F15B0: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x800F15B4: jr          $ra
    // 0x800F15B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800F15B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F15BC:
    // 0x800F15BC: jr          $ra
    // 0x800F15C0: nop

    return;
    // 0x800F15C0: nop

;}
RECOMP_FUNC void badata_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007EC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808007F0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808007F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808007F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007FC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X1CB8) << 16);
    // 0x80800800: jal         0x808006AC
    // 0x80800804: addiu       $a1, $a1, 0x1CB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1CB8));
    func_808006AC_badata(rdram, ctx);
        goto after_0;
    // 0x80800804: addiu       $a1, $a1, 0x1CB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1CB8));
    after_0:
    // 0x80800808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080080C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800810: jr          $ra
    // 0x80800814: nop

    return;
    // 0x80800814: nop

;}
RECOMP_FUNC void _bsdronefalldie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830A0: syscall     41
    recomp_syscall_handler(rdram, ctx, 0x800830A0);
    return;
    // 0x800830A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800E3BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3BD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3BE0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3BE4: jal         0x800CA5D8
    // 0x800E3BE8: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA5D8(rdram, ctx);
        goto after_0;
    // 0x800E3BE8: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3BF4: jr          $ra
    // 0x800E3BF8: nop

    return;
    // 0x800E3BF8: nop

;}
RECOMP_FUNC void func_8080009C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A4: lbu         $a1, 0x160($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X160);
    // 0x808000A8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000AC: beq         $a1, $zero, L_808000C0
    if (ctx->r5 == 0) {
        // 0x808000B0: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_808000C0;
    }
    // 0x808000B0: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x808000B4: jal         0x800C2FDC
    // 0x808000B8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x808000B8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000BC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_808000C0:
    // 0x808000C0: sb          $zero, 0x160($a2)
    MEM_B(0X160, ctx->r6) = 0;
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_800A0DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0DA0: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0DA4: jr          $ra
    // 0x800A0DA8: sb          $a1, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r5;
    return;
    // 0x800A0DA8: sb          $a1, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _bsbabykaz_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082820: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x80082820);
    return;
    // 0x80082824: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80029F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029F5C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80029F60: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80029F64: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x80029F68: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80029F6C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80029F70: bltz        $t8, L_80029F88
    if (SIGNED(ctx->r24) < 0) {
        // 0x80029F74: nop
    
            goto L_80029F88;
    }
    // 0x80029F74: nop

    // 0x80029F78: b           L_80029F98
    // 0x80029F7C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
        goto L_80029F98;
    // 0x80029F7C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80029F80: b           L_80029F90
    // 0x80029F84: nop

        goto L_80029F90;
    // 0x80029F84: nop

L_80029F88:
    // 0x80029F88: b           L_80029F98
    // 0x80029F8C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
        goto L_80029F98;
    // 0x80029F8C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_80029F90:
    // 0x80029F90: b           L_80029F98
    // 0x80029F94: nop

        goto L_80029F98;
    // 0x80029F94: nop

L_80029F98:
    // 0x80029F98: jr          $ra
    // 0x80029F9C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80029F9C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void bstaxi_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801CBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801CC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801CC4: jal         0x80800144
    // 0x80801CC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstaxi_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801CC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CD0: addiu       $a1, $zero, 0x124
    ctx->r5 = ADD32(0, 0X124);
    // 0x80801CD4: jal         0x8008CB3C
    // 0x80801CD8: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801CD8: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    after_1:
    // 0x80801CDC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801CE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801CEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801CF0: jal         0x8009FFD8
    // 0x80801CF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801CF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CFC: jal         0x8009B9B0
    // 0x80801D00: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80801D00: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80801D04: jal         0x800909CC
    // 0x80801D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_4;
    // 0x80801D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801D0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801D10: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801D14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801D18: jr          $ra
    // 0x80801D1C: nop

    return;
    // 0x80801D1C: nop

;}
RECOMP_FUNC void func_80800934_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800934: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080093C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800940: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800944: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800948: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8080094C: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80800950: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800954: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800958: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X2464) << 16);
    // 0x8080095C: lwc1        $f16, 0x2464($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X2464));
    // 0x80800960: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800964: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X2468) << 16);
    // 0x80800968: lwc1        $f4, 0x2468($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X2468));
    // 0x8080096C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800970: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80800974: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800978: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080097C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80800980: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80800984: jal         0x8010D254
    // 0x80800988: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800988: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8080098C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800990: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800994: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800998: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8080099C: nop

    // 0x808009A0: bc1t        L_808009BC
    if (c1cs) {
        // 0x808009A4: nop
    
            goto L_808009BC;
    }
    // 0x808009A4: nop

    // 0x808009A8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808009AC: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808009B0: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808009B4: bc1fl       L_808009C8
    if (!c1cs) {
        // 0x808009B8: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_808009C8;
    }
    goto skip_0;
    // 0x808009B8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_0:
L_808009BC:
    // 0x808009BC: b           L_80800A40
    // 0x808009C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A40;
    // 0x808009C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808009C4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_808009C8:
    // 0x808009C8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808009CC: bc1t        L_808009E4
    if (c1cs) {
        // 0x808009D0: nop
    
            goto L_808009E4;
    }
    // 0x808009D0: nop

    // 0x808009D4: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x808009D8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808009DC: bc1f        L_808009EC
    if (!c1cs) {
        // 0x808009E0: nop
    
            goto L_808009EC;
    }
    // 0x808009E0: nop

L_808009E4:
    // 0x808009E4: b           L_80800A40
    // 0x808009E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A40;
    // 0x808009E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009EC:
    // 0x808009EC: jal         0x8008FA60
    // 0x808009F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8008FA60(rdram, ctx);
        goto after_1;
    // 0x808009F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x808009F4: bne         $v0, $zero, L_80800A04
    if (ctx->r2 != 0) {
        // 0x808009F8: nop
    
            goto L_80800A04;
    }
    // 0x808009F8: nop

    // 0x808009FC: b           L_80800A40
    // 0x80800A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A40;
    // 0x80800A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A04:
    // 0x80800A04: jal         0x80090080
    // 0x80800A08: nop

    func_80090080(rdram, ctx);
        goto after_2;
    // 0x80800A08: nop

    after_2:
    // 0x80800A0C: beq         $v0, $zero, L_80800A3C
    if (ctx->r2 == 0) {
        // 0x80800A10: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800A3C;
    }
    // 0x80800A10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800A14: jal         0x80016B30
    // 0x80800A18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_3;
    // 0x80800A18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800A1C: beq         $v0, $zero, L_80800A2C
    if (ctx->r2 == 0) {
        // 0x80800A20: nop
    
            goto L_80800A2C;
    }
    // 0x80800A20: nop

    // 0x80800A24: b           L_80800A40
    // 0x80800A28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A40;
    // 0x80800A28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A2C:
    // 0x80800A2C: jal         0x800F54E4
    // 0x80800A30: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800A30: nop

    after_4:
    // 0x80800A34: jal         0x800F5FE0
    // 0x80800A38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5FE0(rdram, ctx);
        goto after_5;
    // 0x80800A38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
L_80800A3C:
    // 0x80800A3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A40:
    // 0x80800A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800A48: jr          $ra
    // 0x80800A4C: nop

    return;
    // 0x80800A4C: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080021C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800220: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800224: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800228: jal         0x8010F9C0
    // 0x8080022C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8010F9C0(rdram, ctx);
        goto after_0;
    // 0x8080022C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800230: jal         0x8011001C
    // 0x80800234: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8011001C(rdram, ctx);
        goto after_1;
    // 0x80800234: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800238: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080023C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800240: jal         0x800EE7F8
    // 0x80800244: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800244: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800248: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080024C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800250: jal         0x800EE7F8
    // 0x80800254: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800254: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_3:
    // 0x80800258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080025C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800260: jr          $ra
    // 0x80800264: nop

    return;
    // 0x80800264: nop

;}
RECOMP_FUNC void func_80801364_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801364: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801368: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080136C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801370: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801374: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801378: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080137C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801380: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801384: bne         $t7, $at, L_8080139C
    if (ctx->r15 != ctx->r1) {
        // 0x80801388: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8080139C;
    }
    // 0x80801388: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080138C: beql        $a1, $at, L_808013A0
    if (ctx->r5 == ctx->r1) {
        // 0x80801390: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_808013A0;
    }
    goto skip_0;
    // 0x80801390: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80801394: jal         0x8010DCB4
    // 0x80801398: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8010DCB4(rdram, ctx);
        goto after_0;
    // 0x80801398: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
L_8080139C:
    // 0x8080139C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808013A0:
    // 0x808013A0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x808013A4: sltiu       $at, $t0, 0x7
    ctx->r1 = ctx->r8 < 0X7 ? 1 : 0;
    // 0x808013A8: beq         $at, $zero, L_8080149C
    if (ctx->r1 == 0) {
        // 0x808013AC: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8080149C;
    }
    // 0x808013AC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808013B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(776, 0X1EF0) << 16);
    // 0x808013B4: addu        $at, $at, $t0
    gpr jr_addend_808013BC = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808013B8: lw          $t0, 0x1EF0($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(776, 0X1EF0));
    // 0x808013BC: jr          $t0
    // 0x808013C0: nop

    switch (jr_addend_808013BC >> 2) {
        case 0: goto L_808013D4; break;
        case 1: goto L_808013C4; break;
        case 2: goto L_80801448; break;
        case 3: goto L_80801468; break;
        case 4: goto L_80801438; break;
        case 5: goto L_80801484; break;
        case 6: goto L_80801494; break;
        default: switch_error(__func__, 0x808013BC, 0x80801EF0);
    }
    // 0x808013C0: nop

L_808013C4:
    // 0x808013C4: jal         0x8010DC50
    // 0x808013C8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8010DC50(rdram, ctx);
        goto after_1;
    // 0x808013C8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x808013CC: b           L_808014A0
    // 0x808013D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808014A0;
    // 0x808013D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808013D4:
    // 0x808013D4: jal         0x8008FE68
    // 0x808013D8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008FE68(rdram, ctx);
        goto after_2;
    // 0x808013D8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x808013DC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808013E0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808013E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808013E8: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808013EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808013F0: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x808013F4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808013F8: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x808013FC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801400: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80801404: jal         0x800EF2A0
    // 0x80801408: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    func_800EF2A0(rdram, ctx);
        goto after_3;
    // 0x80801408: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8080140C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801410: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801414: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801418: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080141C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801420: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801424: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80801428: jal         0x800EE7F8
    // 0x8080142C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080142C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x80801430: b           L_808014A0
    // 0x80801434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808014A0;
    // 0x80801434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801438:
    // 0x80801438: jal         0x8010A570
    // 0x8080143C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x8080143C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801440: b           L_808014A0
    // 0x80801444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808014A0;
    // 0x80801444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801448:
    // 0x80801448: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(776, 0X2024) << 16);
    // 0x8080144C: addiu       $a1, $a1, 0x2024
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(776, 0X2024));
    // 0x80801450: jal         0x800C4AF0
    // 0x80801454: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800C4AF0(rdram, ctx);
        goto after_6;
    // 0x80801454: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80801458: jal         0x8010A570
    // 0x8080145C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x8080145C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801460: b           L_808014A0
    // 0x80801464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808014A0;
    // 0x80801464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801468:
    // 0x80801468: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(776, 0X2038) << 16);
    // 0x8080146C: addiu       $a1, $a1, 0x2038
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(776, 0X2038));
    // 0x80801470: jal         0x800C4AF0
    // 0x80801474: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800C4AF0(rdram, ctx);
        goto after_8;
    // 0x80801474: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80801478: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080147C: b           L_8080149C
    // 0x80801480: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
        goto L_8080149C;
    // 0x80801480: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
L_80801484:
    // 0x80801484: jal         0x800EFD24
    // 0x80801488: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EFD24(rdram, ctx);
        goto after_9;
    // 0x80801488: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_9:
    // 0x8080148C: b           L_808014A0
    // 0x80801490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808014A0;
    // 0x80801490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801494:
    // 0x80801494: jal         0x80089CA8
    // 0x80801498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80801498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_8080149C:
    // 0x8080149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808014A0:
    // 0x808014A0: jal         0x80102424
    // 0x808014A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x808014A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x808014A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808014AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808014B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808014B4: jr          $ra
    // 0x808014B8: nop

    return;
    // 0x808014B8: nop

;}
RECOMP_FUNC void bastick_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EFF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009EFFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009F000: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009F004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009F008: lw          $a1, 0x128($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X128);
    // 0x8009F00C: jal         0x800919D0
    // 0x8009F010: addiu       $a1, $a1, 0x54
    ctx->r5 = ADD32(ctx->r5, 0X54);
    bakey_getStick(rdram, ctx);
        goto after_0;
    // 0x8009F010: addiu       $a1, $a1, 0x54
    ctx->r5 = ADD32(ctx->r5, 0X54);
    after_0:
    // 0x8009F014: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
    // 0x8009F018: lbu         $t6, 0x64($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X64);
    // 0x8009F01C: bnel        $t6, $zero, L_8009F058
    if (ctx->r14 != 0) {
        // 0x8009F020: sb          $zero, 0x67($v0)
        MEM_B(0X67, ctx->r2) = 0;
            goto L_8009F058;
    }
    goto skip_0;
    // 0x8009F020: sb          $zero, 0x67($v0)
    MEM_B(0X67, ctx->r2) = 0;
    skip_0:
    // 0x8009F024: lbu         $t7, 0x65($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X65);
    // 0x8009F028: bnel        $t7, $zero, L_8009F058
    if (ctx->r15 != 0) {
        // 0x8009F02C: sb          $zero, 0x67($v0)
        MEM_B(0X67, ctx->r2) = 0;
            goto L_8009F058;
    }
    goto skip_1;
    // 0x8009F02C: sb          $zero, 0x67($v0)
    MEM_B(0X67, ctx->r2) = 0;
    skip_1:
    // 0x8009F030: lbu         $t8, 0x67($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X67);
    // 0x8009F034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009F038: bnel        $t8, $zero, L_8009F058
    if (ctx->r24 != 0) {
        // 0x8009F03C: sb          $zero, 0x67($v0)
        MEM_B(0X67, ctx->r2) = 0;
            goto L_8009F058;
    }
    goto skip_2;
    // 0x8009F03C: sb          $zero, 0x67($v0)
    MEM_B(0X67, ctx->r2) = 0;
    skip_2:
    // 0x8009F040: jal         0x80091E80
    // 0x8009F044: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80091E80(rdram, ctx);
        goto after_1;
    // 0x8009F044: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x8009F048: bnel        $v0, $zero, L_8009F078
    if (ctx->r2 != 0) {
        // 0x8009F04C: lw          $v0, 0x128($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X128);
            goto L_8009F078;
    }
    goto skip_3;
    // 0x8009F04C: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
    skip_3:
    // 0x8009F050: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
    // 0x8009F054: sb          $zero, 0x67($v0)
    MEM_B(0X67, ctx->r2) = 0;
L_8009F058:
    // 0x8009F058: lw          $t9, 0x128($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X128);
    // 0x8009F05C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009F060: nop

    // 0x8009F064: swc1        $f4, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f4.u32l;
    // 0x8009F068: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
    // 0x8009F06C: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8009F070: swc1        $f6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f6.u32l;
    // 0x8009F074: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
L_8009F078:
    // 0x8009F078: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8009F07C: lwc1        $f2, 0x54($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8009F080: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8009F084: nop

    // 0x8009F088: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8009F08C: jal         0x8002DCA0
    // 0x8009F090: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8009F090: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x8009F094: lw          $t0, 0x128($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X128);
    // 0x8009F098: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F09C: swc1        $f0, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f0.u32l;
    // 0x8009F0A0: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
    // 0x8009F0A4: lwc1        $f2, 0x60($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8009F0A8: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
    // 0x8009F0AC: nop

    // 0x8009F0B0: bc1tl       L_8009F0DC
    if (c1cs) {
        // 0x8009F0B4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8009F0DC;
    }
    goto skip_4;
    // 0x8009F0B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_4:
    // 0x8009F0B8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8009F0BC: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8009F0C0: jal         0x80013B70
    // 0x8009F0C4: lwc1        $f14, 0x54($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X54);
    func_80013B70(rdram, ctx);
        goto after_3;
    // 0x8009F0C4: lwc1        $f14, 0x54($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X54);
    after_3:
    // 0x8009F0C8: lw          $t1, 0x128($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X128);
    // 0x8009F0CC: swc1        $f0, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f0.u32l;
    // 0x8009F0D0: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
    // 0x8009F0D4: lwc1        $f2, 0x60($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8009F0D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8009F0DC:
    // 0x8009F0DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009F0E0: nop

    // 0x8009F0E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8009F0E8: nop

    // 0x8009F0EC: bc1f        L_8009F0F8
    if (!c1cs) {
        // 0x8009F0F0: nop
    
            goto L_8009F0F8;
    }
    // 0x8009F0F0: nop

    // 0x8009F0F4: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
L_8009F0F8:
    // 0x8009F0F8: jal         0x8009ED20
    // 0x8009F0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_updateZone(rdram, ctx);
        goto after_4;
    // 0x8009F0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8009F100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009F104: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009F108: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009F10C: jr          $ra
    // 0x8009F110: nop

    return;
    // 0x8009F110: nop

;}
RECOMP_FUNC void func_8008D750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D75C: jal         0x800C6E38
    // 0x8008D760: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D760: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_0:
    // 0x8008D764: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D768: beq         $t6, $zero, L_8008D780
    if (ctx->r14 == 0) {
        // 0x8008D76C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D780;
    }
    // 0x8008D76C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D770: jal         0x800A3304
    // 0x8008D774: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D774: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D778: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D77C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D780:
    // 0x8008D780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D788: jr          $ra
    // 0x8008D78C: nop

    return;
    // 0x8008D78C: nop

;}
RECOMP_FUNC void func_800C0850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0850: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0854: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    // 0x800C0858: lbu         $t6, 0x11C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X11C);
    // 0x800C085C: lbu         $t8, 0x11D($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X11D);
    // 0x800C0860: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0868: andi        $t7, $t6, 0xFF3F
    ctx->r15 = ctx->r14 & 0XFF3F;
    // 0x800C086C: andi        $t9, $t8, 0xFF3F
    ctx->r25 = ctx->r24 & 0XFF3F;
    // 0x800C0870: sb          $t7, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r15;
    // 0x800C0874: sb          $t9, 0x11D($a0)
    MEM_B(0X11D, ctx->r4) = ctx->r25;
    // 0x800C0878: jal         0x80087E58
    // 0x800C087C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _gcdialogexec_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x800C087C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x800C0880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0888: jr          $ra
    // 0x800C088C: nop

    return;
    // 0x800C088C: nop

;}
RECOMP_FUNC void func_808026D0_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808026D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808026D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808026D8: jal         0x80104248
    // 0x808026DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x808026DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808026E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808026E4: jal         0x8008B134
    // 0x808026E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_1;
    // 0x808026E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808026EC: jal         0x80104248
    // 0x808026F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80104248(rdram, ctx);
        goto after_2;
    // 0x808026F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808026F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808026F8: jal         0x8008B188
    // 0x808026FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_3;
    // 0x808026FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80802700: jal         0x80104248
    // 0x80802704: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80104248(rdram, ctx);
        goto after_4;
    // 0x80802704: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80802708: jal         0x8008B064
    // 0x8080270C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x8080270C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80802710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802718: jr          $ra
    // 0x8080271C: nop

    return;
    // 0x8080271C: nop

;}
RECOMP_FUNC void ncpoducam_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000FC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80800100: jal         0x8001B798
    // 0x80800104: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80800104: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080010C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void func_80800E30_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E38: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80800E3C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800E40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800E44: beql        $t6, $zero, L_80800E60
    if (ctx->r14 == 0) {
        // 0x80800E48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800E60;
    }
    goto skip_0;
    // 0x80800E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800E4C: jal         0x800856B8
    // 0x80800E50: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800E50: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800E54: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800E58: sw          $zero, 0x28($a1)
    MEM_W(0X28, ctx->r5) = 0;
    // 0x80800E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E60:
    // 0x80800E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E64: jr          $ra
    // 0x80800E68: nop

    return;
    // 0x80800E68: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B18: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B18);
    return;
    // 0x80087B1C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bsstand_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B48: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B48);
    return;
    // 0x80083B4C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bstaxi_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EC8: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083EC8);
    return;
    // 0x80083ECC: addi        $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
;}
RECOMP_FUNC void bsbswim_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801524: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801528: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1EF0) << 16);
    // 0x8080152C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801530: jr          $ra
    // 0x80801534: lw          $v0, 0x1EF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1EF0));
    return;
    // 0x80801534: lw          $v0, 0x1EF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1EF0));
;}
RECOMP_FUNC void func_80800084_chjigsawbitcont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800088: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080008C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800090: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800094: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800098: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8080009C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808000A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000A8: jal         0x80100094
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808000B4: beq         $s0, $at, L_80800190
    if (ctx->r16 == ctx->r1) {
        // 0x808000B8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80800190;
    }
    // 0x808000B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808000BC: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808000C0: bne         $s0, $at, L_808001EC
    if (ctx->r16 != ctx->r1) {
        // 0x808000C4: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_808001EC;
    }
    // 0x808000C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000C8: bne         $s3, $at, L_80800104
    if (ctx->r19 != ctx->r1) {
        // 0x808000CC: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_80800104;
    }
    // 0x808000CC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808000D0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808000D4: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1644, 0X9A8) << 16);
    // 0x808000D8: addiu       $s2, $s2, 0x9A8
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1644, 0X9A8));
    // 0x808000DC: lhu         $t7, 0x76($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X76);
    // 0x808000E0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808000E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000E8: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808000EC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x808000F0: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x808000F4: jal         0x800867B8
    // 0x808000F8: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    _chjigsawcollect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000F8: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    after_1:
    // 0x808000FC: b           L_808001F8
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001F8;
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800104:
    // 0x80800104: lhu         $t2, 0x76($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X76);
    // 0x80800108: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1644, 0X9A8) << 16);
    // 0x8080010C: addiu       $s2, $s2, 0x9A8
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1644, 0X9A8));
    // 0x80800110: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x80800114: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80800118: addu        $v0, $s2, $t4
    ctx->r2 = ADD32(ctx->r18, ctx->r12);
    // 0x8080011C: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x80800120: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800124: blezl       $t5, L_808001F8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80800128: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808001F8;
    }
    goto skip_0;
    // 0x80800128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080012C: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
L_80800130:
    // 0x80800130: jal         0x800DA298
    // 0x80800134: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800134: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    after_2:
    // 0x80800138: bne         $v0, $zero, L_80800154
    if (ctx->r2 != 0) {
        // 0x8080013C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800154;
    }
    // 0x8080013C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800140: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800144: jal         0x80800890
    // 0x80800148: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80800890_chjigsawbitcont(rdram, ctx);
        goto after_3;
    // 0x80800148: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_3:
    // 0x8080014C: b           L_80800164
    // 0x80800150: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
        goto L_80800164;
    // 0x80800150: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_80800154:
    // 0x80800154: lh          $t7, 0x24($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X24);
    // 0x80800158: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8080015C: sh          $t8, 0x24($s1)
    MEM_H(0X24, ctx->r17) = ctx->r24;
    // 0x80800160: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_80800164:
    // 0x80800164: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800168: lhu         $t0, 0x76($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X76);
    // 0x8080016C: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x80800170: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80800174: addu        $v0, $s2, $t2
    ctx->r2 = ADD32(ctx->r18, ctx->r10);
    // 0x80800178: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x8080017C: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80800180: bnel        $at, $zero, L_80800130
    if (ctx->r1 != 0) {
        // 0x80800184: lh          $t6, 0xE($v0)
        ctx->r14 = MEM_H(ctx->r2, 0XE);
            goto L_80800130;
    }
    goto skip_1;
    // 0x80800184: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    skip_1:
    // 0x80800188: b           L_808001F8
    // 0x8080018C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001F8;
    // 0x8080018C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800190:
    // 0x80800190: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80800194: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x80800198: sll         $t7, $t5, 10
    ctx->r15 = S32(ctx->r13 << 10);
    // 0x8080019C: bltzl       $t7, L_808001B0
    if (SIGNED(ctx->r15) < 0) {
        // 0x808001A0: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_808001B0;
    }
    goto skip_2;
    // 0x808001A0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x808001A4: jal         0x80100120
    // 0x808001A8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_80100120(rdram, ctx);
        goto after_4;
    // 0x808001A8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_4:
    // 0x808001AC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
L_808001B0:
    // 0x808001B0: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1644, 0X9A8) << 16);
    // 0x808001B4: addiu       $s2, $s2, 0x9A8
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1644, 0X9A8));
    // 0x808001B8: lhu         $v0, 0x76($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X76);
    // 0x808001BC: srl         $t9, $v0, 7
    ctx->r25 = S32(U32(ctx->r2) >> 7);
    // 0x808001C0: bne         $s3, $t9, L_808001F4
    if (ctx->r19 != ctx->r25) {
        // 0x808001C4: sll         $t0, $t9, 4
        ctx->r8 = S32(ctx->r25 << 4);
            goto L_808001F4;
    }
    // 0x808001C4: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x808001C8: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x808001CC: jal         0x800DA298
    // 0x808001D0: lh          $a0, 0xC($t1)
    ctx->r4 = MEM_H(ctx->r9, 0XC);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808001D0: lh          $a0, 0xC($t1)
    ctx->r4 = MEM_H(ctx->r9, 0XC);
    after_5:
    // 0x808001D4: bne         $v0, $zero, L_808001F4
    if (ctx->r2 != 0) {
        // 0x808001D8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808001F4;
    }
    // 0x808001D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001DC: jal         0x80800000
    // 0x808001E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_chjigsawbitcont(rdram, ctx);
        goto after_6;
    // 0x808001E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808001E4: b           L_808001F8
    // 0x808001E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001F8;
    // 0x808001E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001EC:
    // 0x808001EC: b           L_808001F8
    // 0x808001F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001F8;
    // 0x808001F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001F4:
    // 0x808001F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001F8:
    // 0x808001F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800200: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800204: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800208: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080020C: jr          $ra
    // 0x80800210: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800210: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
