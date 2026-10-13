#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808000EC_chfantasytrashcanbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000F8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800100: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800104: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800108: beq         $t6, $at, L_80800178
    if (ctx->r14 == ctx->r1) {
        // 0x8080010C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800178;
    }
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800114: bne         $t6, $at, L_80800180
    if (ctx->r14 != ctx->r1) {
        // 0x80800118: nop
    
            goto L_80800180;
    }
    // 0x80800118: nop

    // 0x8080011C: jal         0x800F54E4
    // 0x80800120: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800120: nop

    after_0:
    // 0x80800124: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800128: jal         0x800F5A00
    // 0x8080012C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x8080012C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x8008A4B0
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080013C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800140: jal         0x800EFC7C
    // 0x80800144: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EFC7C(rdram, ctx);
        goto after_3;
    // 0x80800144: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800148: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2352, 0X234) << 16);
    // 0x8080014C: lwc1        $f4, 0x234($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2352, 0X234));
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800158: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080015C: nop

    // 0x80800160: bc1f        L_80800180
    if (!c1cs) {
        // 0x80800164: nop
    
            goto L_80800180;
    }
    // 0x80800164: nop

    // 0x80800168: jal         0x8010108C
    // 0x8080016C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_4;
    // 0x8080016C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800170: b           L_80800180
    // 0x80800174: nop

        goto L_80800180;
    // 0x80800174: nop

L_80800178:
    // 0x80800178: jal         0x8008A4B0
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_80800180:
    // 0x80800180: jal         0x80086240
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080018C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800190: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800194: jr          $ra
    // 0x80800198: nop

    return;
    // 0x80800198: nop

;}
RECOMP_FUNC void func_80800228_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080022C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800230: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800234: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080023C: beq         $a1, $at, L_808003D8
    if (ctx->r5 == ctx->r1) {
        // 0x80800240: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_808003D8;
    }
    // 0x80800240: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800244: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800248: beq         $a1, $at, L_808003EC
    if (ctx->r5 == ctx->r1) {
        // 0x8080024C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808003EC;
    }
    // 0x8080024C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800250: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800254: beq         $a1, $at, L_808003C8
    if (ctx->r5 == ctx->r1) {
        // 0x80800258: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808003C8;
    }
    // 0x80800258: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080025C: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80800260: beq         $a1, $at, L_808003FC
    if (ctx->r5 == ctx->r1) {
        // 0x80800264: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_808003FC;
    }
    // 0x80800264: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800268: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080026C: beq         $a1, $at, L_8080028C
    if (ctx->r5 == ctx->r1) {
        // 0x80800270: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_8080028C;
    }
    // 0x80800270: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800274: bne         $a1, $at, L_80800420
    if (ctx->r5 != ctx->r1) {
        // 0x80800278: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800420;
    }
    // 0x80800278: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080027C: jal         0x80803D00
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80803D00_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800284: b           L_8080042C
    // 0x80800288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080042C;
    // 0x80800288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080028C:
    // 0x8080028C: slti        $at, $s0, 0x9
    ctx->r1 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x80800290: bne         $at, $zero, L_80800374
    if (ctx->r1 != 0) {
        // 0x80800294: addiu       $a0, $zero, 0x4A8
        ctx->r4 = ADD32(0, 0X4A8);
            goto L_80800374;
    }
    // 0x80800294: addiu       $a0, $zero, 0x4A8
    ctx->r4 = ADD32(0, 0X4A8);
    // 0x80800298: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(804, 0X8578) << 16);
    // 0x8080029C: addiu       $a1, $a1, -0x7A88
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(804, 0X8578));
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002A8: jal         0x80108528
    // 0x808002AC: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80108528(rdram, ctx);
        goto after_1;
    // 0x808002AC: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x808002B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808002B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808002B8: lbu         $t1, 0x79($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X79);
    // 0x808002BC: lbu         $t7, 0x79($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X79);
    // 0x808002C0: addiu       $at, $zero, 0x1E8
    ctx->r1 = ADD32(0, 0X1E8);
    // 0x808002C4: andi        $t2, $t1, 0xFF0F
    ctx->r10 = ctx->r9 & 0XFF0F;
    // 0x808002C8: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x808002CC: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x808002D0: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x808002D4: beq         $s0, $at, L_80800364
    if (ctx->r16 == ctx->r1) {
        // 0x808002D8: sb          $t3, 0x79($v0)
        MEM_B(0X79, ctx->r2) = ctx->r11;
            goto L_80800364;
    }
    // 0x808002D8: sb          $t3, 0x79($v0)
    MEM_B(0X79, ctx->r2) = ctx->r11;
    // 0x808002DC: addiu       $at, $zero, 0x4A9
    ctx->r1 = ADD32(0, 0X4A9);
    // 0x808002E0: beq         $s0, $at, L_80800340
    if (ctx->r16 == ctx->r1) {
        // 0x808002E4: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_80800340;
    }
    // 0x808002E4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x808002E8: addiu       $at, $zero, 0x4AA
    ctx->r1 = ADD32(0, 0X4AA);
    // 0x808002EC: beq         $s0, $at, L_80800334
    if (ctx->r16 == ctx->r1) {
        // 0x808002F0: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_80800334;
    }
    // 0x808002F0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808002F4: addiu       $at, $zero, 0x4AB
    ctx->r1 = ADD32(0, 0X4AB);
    // 0x808002F8: beq         $s0, $at, L_8080031C
    if (ctx->r16 == ctx->r1) {
        // 0x808002FC: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_8080031C;
    }
    // 0x808002FC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800300: addiu       $at, $zero, 0x4AC
    ctx->r1 = ADD32(0, 0X4AC);
    // 0x80800304: beq         $s0, $at, L_80800358
    if (ctx->r16 == ctx->r1) {
        // 0x80800308: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80800358;
    }
    // 0x80800308: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080030C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80800310: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80800314: b           L_808003B4
    // 0x80800318: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
        goto L_808003B4;
    // 0x80800318: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
L_8080031C:
    // 0x8080031C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800320: sw          $t6, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r14;
    // 0x80800324: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800328: lwc1        $f4, 0x38($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X38);
    // 0x8080032C: b           L_808003B4
    // 0x80800330: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
        goto L_808003B4;
    // 0x80800330: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
L_80800334:
    // 0x80800334: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800338: b           L_808003B4
    // 0x8080033C: sw          $t9, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r25;
        goto L_808003B4;
    // 0x8080033C: sw          $t9, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r25;
L_80800340:
    // 0x80800340: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80800344: sw          $t0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r8;
    // 0x80800348: lbu         $t4, 0x65($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X65);
    // 0x8080034C: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x80800350: b           L_808003B4
    // 0x80800354: sb          $t5, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r13;
        goto L_808003B4;
    // 0x80800354: sb          $t5, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r13;
L_80800358:
    // 0x80800358: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8080035C: b           L_808003B4
    // 0x80800360: sw          $t6, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r14;
        goto L_808003B4;
    // 0x80800360: sw          $t6, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r14;
L_80800364:
    // 0x80800364: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80800368: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8080036C: b           L_808003B4
    // 0x80800370: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
        goto L_808003B4;
    // 0x80800370: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
L_80800374:
    // 0x80800374: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(804, 0X8578) << 16);
    // 0x80800378: addiu       $a1, $a1, -0x7A88
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(804, 0X8578));
    // 0x8080037C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800380: jal         0x80108528
    // 0x80800384: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80108528(rdram, ctx);
        goto after_2;
    // 0x80800384: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800388: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080038C: lbu         $t3, 0x79($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X79);
    // 0x80800390: sll         $t2, $s0, 4
    ctx->r10 = S32(ctx->r16 << 4);
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x8080039C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808003A0: jal         0x80803D60
    // 0x808003A4: sb          $t5, 0x79($v0)
    MEM_B(0X79, ctx->r2) = ctx->r13;
    func_80803D60_chgameselect(rdram, ctx);
        goto after_3;
    // 0x808003A4: sb          $t5, 0x79($v0)
    MEM_B(0X79, ctx->r2) = ctx->r13;
    after_3:
    // 0x808003A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808003AC: jal         0x808020CC
    // 0x808003B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808020CC_chgameselect(rdram, ctx);
        goto after_4;
    // 0x808003B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
L_808003B4:
    // 0x808003B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808003B8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808003BC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x808003C0: b           L_80800428
    // 0x808003C4: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
        goto L_80800428;
    // 0x808003C4: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
L_808003C8:
    // 0x808003C8: jal         0x808005D4
    // 0x808003CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808005D4_chgameselect(rdram, ctx);
        goto after_5;
    // 0x808003CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x808003D0: b           L_8080042C
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080042C;
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D8:
    // 0x808003D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003DC: jal         0x808006A0
    // 0x808003E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808006A0_chgameselect(rdram, ctx);
        goto after_6;
    // 0x808003E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x808003E4: b           L_8080042C
    // 0x808003E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080042C;
    // 0x808003E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003EC:
    // 0x808003EC: jal         0x8080086C
    // 0x808003F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8080086C_chgameselect(rdram, ctx);
        goto after_7;
    // 0x808003F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x808003F4: b           L_8080042C
    // 0x808003F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080042C;
    // 0x808003F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003FC:
    // 0x808003FC: lhu         $t1, 0x72($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X72);
    // 0x80800400: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800404: srl         $t0, $t1, 10
    ctx->r8 = S32(U32(ctx->r9) >> 10);
    // 0x80800408: bnel        $t0, $at, L_8080042C
    if (ctx->r8 != ctx->r1) {
        // 0x8080040C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080042C;
    }
    goto skip_0;
    // 0x8080040C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800410: jal         0x808065F4
    // 0x80800414: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_808065F4_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80800414: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_8:
    // 0x80800418: b           L_8080042C
    // 0x8080041C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080042C;
    // 0x8080041C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800420:
    // 0x80800420: b           L_8080042C
    // 0x80800424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080042C;
    // 0x80800424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800428:
    // 0x80800428: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080042C:
    // 0x8080042C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800430: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800434: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800438: jr          $ra
    // 0x8080043C: nop

    return;
    // 0x8080043C: nop

;}
RECOMP_FUNC void _chmrsboggy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CE8: syscall     227
    recomp_syscall_handler(rdram, ctx, 0x80085CE8);
    return;
    // 0x80085CEC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DA564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA564: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DA568: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DA56C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DA570: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DA574: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800DA578: bltz        $a0, L_800DA6B4
    if (SIGNED(ctx->r4) < 0) {
        // 0x800DA57C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800DA6B4;
    }
    // 0x800DA57C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DA580: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x800DA584: beq         $at, $zero, L_800DA6B4
    if (ctx->r1 == 0) {
        // 0x800DA588: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800DA6B4;
    }
    // 0x800DA588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DA58C: blez        $a1, L_800DA6AC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800DA590: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800DA6AC;
    }
    // 0x800DA590: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800DA594: andi        $v0, $a1, 0x3
    ctx->r2 = ctx->r5 & 0X3;
    // 0x800DA598: beq         $v0, $zero, L_800DA5E0
    if (ctx->r2 == 0) {
        // 0x800DA59C: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800DA5E0;
    }
    // 0x800DA59C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800DA5A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800DA5A4: lw          $a2, -0x4670($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4670);
    // 0x800DA5A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_800DA5AC:
    // 0x800DA5AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DA5B0: sllv        $t7, $t6, $a1
    ctx->r15 = S32(ctx->r14 << (ctx->r5 & 31));
    // 0x800DA5B4: and         $t8, $t7, $a2
    ctx->r24 = ctx->r15 & ctx->r6;
    // 0x800DA5B8: beq         $t8, $zero, L_800DA5C8
    if (ctx->r24 == 0) {
        // 0x800DA5BC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800DA5C8;
    }
    // 0x800DA5BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800DA5C0: b           L_800DA5CC
    // 0x800DA5C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DA5CC;
    // 0x800DA5C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DA5C8:
    // 0x800DA5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DA5CC:
    // 0x800DA5CC: sllv        $t9, $v0, $v1
    ctx->r25 = S32(ctx->r2 << (ctx->r3 & 31));
    // 0x800DA5D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800DA5D4: bne         $a3, $v1, L_800DA5AC
    if (ctx->r7 != ctx->r3) {
        // 0x800DA5D8: or          $a0, $a0, $t9
        ctx->r4 = ctx->r4 | ctx->r25;
            goto L_800DA5AC;
    }
    // 0x800DA5D8: or          $a0, $a0, $t9
    ctx->r4 = ctx->r4 | ctx->r25;
    // 0x800DA5DC: beq         $v1, $s1, L_800DA6AC
    if (ctx->r3 == ctx->r17) {
        // 0x800DA5E0: addu        $a1, $s0, $v1
        ctx->r5 = ADD32(ctx->r16, ctx->r3);
            goto L_800DA6AC;
    }
L_800DA5E0:
    // 0x800DA5E0: addu        $a1, $s0, $v1
    ctx->r5 = ADD32(ctx->r16, ctx->r3);
    // 0x800DA5E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800DA5E8: lw          $a2, -0x4670($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4670);
    // 0x800DA5EC: addiu       $a3, $a1, 0x1
    ctx->r7 = ADD32(ctx->r5, 0X1);
    // 0x800DA5F0: addiu       $t0, $a1, 0x2
    ctx->r8 = ADD32(ctx->r5, 0X2);
    // 0x800DA5F4: addiu       $t1, $a1, 0x3
    ctx->r9 = ADD32(ctx->r5, 0X3);
L_800DA5F8:
    // 0x800DA5F8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800DA5FC: sllv        $t3, $t2, $a1
    ctx->r11 = S32(ctx->r10 << (ctx->r5 & 31));
    // 0x800DA600: and         $t4, $t3, $a2
    ctx->r12 = ctx->r11 & ctx->r6;
    // 0x800DA604: beq         $t4, $zero, L_800DA614
    if (ctx->r12 == 0) {
        // 0x800DA608: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800DA614;
    }
    // 0x800DA608: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DA60C: b           L_800DA618
    // 0x800DA610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DA618;
    // 0x800DA610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DA614:
    // 0x800DA614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DA618:
    // 0x800DA618: sllv        $t7, $t6, $a3
    ctx->r15 = S32(ctx->r14 << (ctx->r7 & 31));
    // 0x800DA61C: and         $t8, $t7, $a2
    ctx->r24 = ctx->r15 & ctx->r6;
    // 0x800DA620: sllv        $t5, $v0, $v1
    ctx->r13 = S32(ctx->r2 << (ctx->r3 & 31));
    // 0x800DA624: beq         $t8, $zero, L_800DA634
    if (ctx->r24 == 0) {
        // 0x800DA628: or          $a0, $a0, $t5
        ctx->r4 = ctx->r4 | ctx->r13;
            goto L_800DA634;
    }
    // 0x800DA628: or          $a0, $a0, $t5
    ctx->r4 = ctx->r4 | ctx->r13;
    // 0x800DA62C: b           L_800DA638
    // 0x800DA630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DA638;
    // 0x800DA630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DA634:
    // 0x800DA634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DA638:
    // 0x800DA638: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800DA63C: sllv        $t4, $t3, $t0
    ctx->r12 = S32(ctx->r11 << (ctx->r8 & 31));
    // 0x800DA640: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x800DA644: sllv        $t2, $v0, $t9
    ctx->r10 = S32(ctx->r2 << (ctx->r25 & 31));
    // 0x800DA648: and         $t5, $t4, $a2
    ctx->r13 = ctx->r12 & ctx->r6;
    // 0x800DA64C: beq         $t5, $zero, L_800DA65C
    if (ctx->r13 == 0) {
        // 0x800DA650: or          $a0, $a0, $t2
        ctx->r4 = ctx->r4 | ctx->r10;
            goto L_800DA65C;
    }
    // 0x800DA650: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
    // 0x800DA654: b           L_800DA660
    // 0x800DA658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DA660;
    // 0x800DA658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DA65C:
    // 0x800DA65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DA660:
    // 0x800DA660: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DA664: sllv        $t9, $t8, $t1
    ctx->r25 = S32(ctx->r24 << (ctx->r9 & 31));
    // 0x800DA668: addiu       $t6, $v1, 0x2
    ctx->r14 = ADD32(ctx->r3, 0X2);
    // 0x800DA66C: sllv        $t7, $v0, $t6
    ctx->r15 = S32(ctx->r2 << (ctx->r14 & 31));
    // 0x800DA670: and         $t2, $t9, $a2
    ctx->r10 = ctx->r25 & ctx->r6;
    // 0x800DA674: beq         $t2, $zero, L_800DA684
    if (ctx->r10 == 0) {
        // 0x800DA678: or          $a0, $a0, $t7
        ctx->r4 = ctx->r4 | ctx->r15;
            goto L_800DA684;
    }
    // 0x800DA678: or          $a0, $a0, $t7
    ctx->r4 = ctx->r4 | ctx->r15;
    // 0x800DA67C: b           L_800DA688
    // 0x800DA680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DA688;
    // 0x800DA680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DA684:
    // 0x800DA684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DA688:
    // 0x800DA688: addiu       $t3, $v1, 0x3
    ctx->r11 = ADD32(ctx->r3, 0X3);
    // 0x800DA68C: sllv        $t4, $v0, $t3
    ctx->r12 = S32(ctx->r2 << (ctx->r11 & 31));
    // 0x800DA690: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800DA694: or          $a0, $a0, $t4
    ctx->r4 = ctx->r4 | ctx->r12;
    // 0x800DA698: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800DA69C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800DA6A0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800DA6A4: bne         $v1, $s1, L_800DA5F8
    if (ctx->r3 != ctx->r17) {
        // 0x800DA6A8: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_800DA5F8;
    }
    // 0x800DA6A8: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_800DA6AC:
    // 0x800DA6AC: b           L_800DA794
    // 0x800DA6B0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800DA794;
    // 0x800DA6B0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800DA6B4:
    // 0x800DA6B4: slti        $at, $s0, 0x29
    ctx->r1 = SIGNED(ctx->r16) < 0X29 ? 1 : 0;
    // 0x800DA6B8: bne         $at, $zero, L_800DA6E0
    if (ctx->r1 != 0) {
        // 0x800DA6BC: slti        $at, $s0, 0x5A5
        ctx->r1 = SIGNED(ctx->r16) < 0X5A5 ? 1 : 0;
            goto L_800DA6E0;
    }
    // 0x800DA6BC: slti        $at, $s0, 0x5A5
    ctx->r1 = SIGNED(ctx->r16) < 0X5A5 ? 1 : 0;
    // 0x800DA6C0: beq         $at, $zero, L_800DA6E0
    if (ctx->r1 == 0) {
        // 0x800DA6C4: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA6E0;
    }
    // 0x800DA6C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA6C8: lw          $a0, -0x3890($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3890);
    // 0x800DA6CC: addiu       $a1, $s0, -0x28
    ctx->r5 = ADD32(ctx->r16, -0X28);
    // 0x800DA6D0: jal         0x800D9EA0
    // 0x800DA6D4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    bitfield_get_n_bits(rdram, ctx);
        goto after_0;
    // 0x800DA6D4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x800DA6D8: b           L_800DA798
    // 0x800DA6DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DA798;
    // 0x800DA6DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DA6E0:
    // 0x800DA6E0: slti        $at, $s0, 0x641
    ctx->r1 = SIGNED(ctx->r16) < 0X641 ? 1 : 0;
    // 0x800DA6E4: bne         $at, $zero, L_800DA70C
    if (ctx->r1 != 0) {
        // 0x800DA6E8: slti        $at, $s0, 0x6ED
        ctx->r1 = SIGNED(ctx->r16) < 0X6ED ? 1 : 0;
            goto L_800DA70C;
    }
    // 0x800DA6E8: slti        $at, $s0, 0x6ED
    ctx->r1 = SIGNED(ctx->r16) < 0X6ED ? 1 : 0;
    // 0x800DA6EC: beq         $at, $zero, L_800DA70C
    if (ctx->r1 == 0) {
        // 0x800DA6F0: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA70C;
    }
    // 0x800DA6F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA6F4: lw          $a0, -0x388C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X388C);
    // 0x800DA6F8: addiu       $a1, $s0, -0x640
    ctx->r5 = ADD32(ctx->r16, -0X640);
    // 0x800DA6FC: jal         0x800D9EA0
    // 0x800DA700: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    bitfield_get_n_bits(rdram, ctx);
        goto after_1;
    // 0x800DA700: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x800DA704: b           L_800DA798
    // 0x800DA708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DA798;
    // 0x800DA708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DA70C:
    // 0x800DA70C: slti        $at, $s0, 0x9C5
    ctx->r1 = SIGNED(ctx->r16) < 0X9C5 ? 1 : 0;
    // 0x800DA710: bne         $at, $zero, L_800DA738
    if (ctx->r1 != 0) {
        // 0x800DA714: slti        $at, $s0, 0xAC4
        ctx->r1 = SIGNED(ctx->r16) < 0XAC4 ? 1 : 0;
            goto L_800DA738;
    }
    // 0x800DA714: slti        $at, $s0, 0xAC4
    ctx->r1 = SIGNED(ctx->r16) < 0XAC4 ? 1 : 0;
    // 0x800DA718: beq         $at, $zero, L_800DA738
    if (ctx->r1 == 0) {
        // 0x800DA71C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA738;
    }
    // 0x800DA71C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA720: lw          $a0, -0x3888($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3888);
    // 0x800DA724: addiu       $a1, $s0, -0x9C4
    ctx->r5 = ADD32(ctx->r16, -0X9C4);
    // 0x800DA728: jal         0x800D9EA0
    // 0x800DA72C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    bitfield_get_n_bits(rdram, ctx);
        goto after_2;
    // 0x800DA72C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x800DA730: b           L_800DA798
    // 0x800DA734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DA798;
    // 0x800DA734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DA738:
    // 0x800DA738: slti        $at, $s0, 0xBB9
    ctx->r1 = SIGNED(ctx->r16) < 0XBB9 ? 1 : 0;
    // 0x800DA73C: bne         $at, $zero, L_800DA764
    if (ctx->r1 != 0) {
        // 0x800DA740: slti        $at, $s0, 0xC16
        ctx->r1 = SIGNED(ctx->r16) < 0XC16 ? 1 : 0;
            goto L_800DA764;
    }
    // 0x800DA740: slti        $at, $s0, 0xC16
    ctx->r1 = SIGNED(ctx->r16) < 0XC16 ? 1 : 0;
    // 0x800DA744: beq         $at, $zero, L_800DA764
    if (ctx->r1 == 0) {
        // 0x800DA748: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA764;
    }
    // 0x800DA748: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA74C: addiu       $a0, $a0, -0x3880
    ctx->r4 = ADD32(ctx->r4, -0X3880);
    // 0x800DA750: addiu       $a1, $s0, -0xBB8
    ctx->r5 = ADD32(ctx->r16, -0XBB8);
    // 0x800DA754: jal         0x800D9EA0
    // 0x800DA758: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    bitfield_get_n_bits(rdram, ctx);
        goto after_3;
    // 0x800DA758: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_3:
    // 0x800DA75C: b           L_800DA798
    // 0x800DA760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DA798;
    // 0x800DA760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DA764:
    // 0x800DA764: slti        $at, $s0, 0xD49
    ctx->r1 = SIGNED(ctx->r16) < 0XD49 ? 1 : 0;
    // 0x800DA768: bne         $at, $zero, L_800DA794
    if (ctx->r1 != 0) {
        // 0x800DA76C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DA794;
    }
    // 0x800DA76C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DA770: slti        $at, $s0, 0xD75
    ctx->r1 = SIGNED(ctx->r16) < 0XD75 ? 1 : 0;
    // 0x800DA774: beq         $at, $zero, L_800DA794
    if (ctx->r1 == 0) {
        // 0x800DA778: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA794;
    }
    // 0x800DA778: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA77C: addiu       $a0, $a0, -0x3874
    ctx->r4 = ADD32(ctx->r4, -0X3874);
    // 0x800DA780: addiu       $a1, $s0, -0xD48
    ctx->r5 = ADD32(ctx->r16, -0XD48);
    // 0x800DA784: jal         0x800D9EA0
    // 0x800DA788: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    bitfield_get_n_bits(rdram, ctx);
        goto after_4;
    // 0x800DA788: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x800DA78C: b           L_800DA798
    // 0x800DA790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DA798;
    // 0x800DA790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DA794:
    // 0x800DA794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DA798:
    // 0x800DA798: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DA79C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DA7A0: jr          $ra
    // 0x800DA7A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800DA7A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _subaddieDll_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4E8: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4E8);
    return;
    // 0x8008A4EC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void gctransitionDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080095C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800960: jal         0x808000D8
    // 0x80800964: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808000D8_gctransitionDll(rdram, ctx);
        goto after_0;
    // 0x80800964: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080096C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800970: jr          $ra
    // 0x80800974: nop

    return;
    // 0x80800974: nop

;}
RECOMP_FUNC void gsworldDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: jal         0x80088038
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _gccollectDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800110: jal         0x800EA148
    // 0x80800114: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800EA148(rdram, ctx);
        goto after_1;
    // 0x80800114: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80800118: jal         0x800C00E0
    // 0x8080011C: nop

    func_800C00E0(rdram, ctx);
        goto after_2;
    // 0x8080011C: nop

    after_2:
    // 0x80800120: jal         0x8008A900
    // 0x80800124: nop

    _sufade_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800124: nop

    after_3:
    // 0x80800128: jal         0x80089F58
    // 0x8080012C: nop

    _subaddierouteDll_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8080012C: nop

    after_4:
    // 0x80800130: jal         0x800C7500
    // 0x80800134: nop

    func_800C7500(rdram, ctx);
        goto after_5;
    // 0x80800134: nop

    after_5:
    // 0x80800138: jal         0x800D8800
    // 0x8080013C: nop

    func_800D8800(rdram, ctx);
        goto after_6;
    // 0x8080013C: nop

    after_6:
    // 0x80800140: jal         0x800D743C
    // 0x80800144: nop

    func_800D743C(rdram, ctx);
        goto after_7;
    // 0x80800144: nop

    after_7:
    // 0x80800148: jal         0x800A5CC4
    // 0x8080014C: nop

    func_800A5CC4(rdram, ctx);
        goto after_8;
    // 0x8080014C: nop

    after_8:
    // 0x80800150: jal         0x800D8898
    // 0x80800154: nop

    func_800D8898(rdram, ctx);
        goto after_9;
    // 0x80800154: nop

    after_9:
    // 0x80800158: jal         0x800887D0
    // 0x8080015C: nop

    _glcutDll_entrypoint_5(rdram, ctx);
        goto after_10;
    // 0x8080015C: nop

    after_10:
    // 0x80800160: jal         0x800F732C
    // 0x80800164: nop

    func_800F732C(rdram, ctx);
        goto after_11;
    // 0x80800164: nop

    after_11:
    // 0x80800168: jal         0x800B5E04
    // 0x8080016C: nop

    func_800B5E04(rdram, ctx);
        goto after_12;
    // 0x8080016C: nop

    after_12:
    // 0x80800170: jal         0x800FA660
    // 0x80800174: nop

    func_800FA660(rdram, ctx);
        goto after_13;
    // 0x80800174: nop

    after_13:
    // 0x80800178: jal         0x800858D0
    // 0x8080017C: nop

    _chbounce_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x8080017C: nop

    after_14:
    // 0x80800180: jal         0x800E1748
    // 0x80800184: nop

    func_800E1748(rdram, ctx);
        goto after_15;
    // 0x80800184: nop

    after_15:
    // 0x80800188: jal         0x800A5630
    // 0x8080018C: nop

    func_800A5630(rdram, ctx);
        goto after_16;
    // 0x8080018C: nop

    after_16:
    // 0x80800190: jal         0x800B5AD4
    // 0x80800194: nop

    func_800B5AD4(rdram, ctx);
        goto after_17;
    // 0x80800194: nop

    after_17:
    // 0x80800198: jal         0x800B5824
    // 0x8080019C: nop

    func_800B5824(rdram, ctx);
        goto after_18;
    // 0x8080019C: nop

    after_18:
    // 0x808001A0: jal         0x800B5054
    // 0x808001A4: nop

    func_800B5054(rdram, ctx);
        goto after_19;
    // 0x808001A4: nop

    after_19:
    // 0x808001A8: jal         0x800B7CC4
    // 0x808001AC: nop

    func_800B7CC4(rdram, ctx);
        goto after_20;
    // 0x808001AC: nop

    after_20:
    // 0x808001B0: jal         0x80087AB0
    // 0x808001B4: nop

    _gcgoto_entrypoint_12(rdram, ctx);
        goto after_21;
    // 0x808001B4: nop

    after_21:
    // 0x808001B8: jal         0x800BD5DC
    // 0x808001BC: nop

    func_800BD5DC(rdram, ctx);
        goto after_22;
    // 0x808001BC: nop

    after_22:
    // 0x808001C0: jal         0x800CB9AC
    // 0x808001C4: nop

    func_800CB9AC(rdram, ctx);
        goto after_23;
    // 0x808001C4: nop

    after_23:
    // 0x808001C8: jal         0x800C5770
    // 0x808001CC: nop

    func_800C5770(rdram, ctx);
        goto after_24;
    // 0x808001CC: nop

    after_24:
    // 0x808001D0: jal         0x800BF420
    // 0x808001D4: nop

    func_800BF420(rdram, ctx);
        goto after_25;
    // 0x808001D4: nop

    after_25:
    // 0x808001D8: jal         0x800BFCB4
    // 0x808001DC: nop

    func_800BFCB4(rdram, ctx);
        goto after_26;
    // 0x808001DC: nop

    after_26:
    // 0x808001E0: jal         0x800C90D0
    // 0x808001E4: nop

    func_800C90D0(rdram, ctx);
        goto after_27;
    // 0x808001E4: nop

    after_27:
    // 0x808001E8: jal         0x800BFF28
    // 0x808001EC: nop

    func_800BFF28(rdram, ctx);
        goto after_28;
    // 0x808001EC: nop

    after_28:
    // 0x808001F0: jal         0x80088F38
    // 0x808001F4: nop

    _idworldmake_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x808001F4: nop

    after_29:
    // 0x808001F8: jal         0x80100610
    // 0x808001FC: nop

    func_80100610(rdram, ctx);
        goto after_30;
    // 0x808001FC: nop

    after_30:
    // 0x80800200: jal         0x80100B4C
    // 0x80800204: nop

    func_80100B4C(rdram, ctx);
        goto after_31;
    // 0x80800204: nop

    after_31:
    // 0x80800208: jal         0x8008A8E0
    // 0x8080020C: nop

    _sulights_entrypoint_8(rdram, ctx);
        goto after_32;
    // 0x8080020C: nop

    after_32:
    // 0x80800210: jal         0x800C7A60
    // 0x80800214: nop

    func_800C7A60(rdram, ctx);
        goto after_33;
    // 0x80800214: nop

    after_33:
    // 0x80800218: jal         0x800AB9D0
    // 0x8080021C: nop

    func_800AB9D0(rdram, ctx);
        goto after_34;
    // 0x8080021C: nop

    after_34:
    // 0x80800220: jal         0x800FFDBC
    // 0x80800224: nop

    func_800FFDBC(rdram, ctx);
        goto after_35;
    // 0x80800224: nop

    after_35:
    // 0x80800228: jal         0x8010D89C
    // 0x8080022C: nop

    func_8010D89C(rdram, ctx);
        goto after_36;
    // 0x8080022C: nop

    after_36:
    // 0x80800230: jal         0x800E4CE8
    // 0x80800234: nop

    func_800E4CE8(rdram, ctx);
        goto after_37;
    // 0x80800234: nop

    after_37:
    // 0x80800238: jal         0x800E9774
    // 0x8080023C: nop

    func_800E9774(rdram, ctx);
        goto after_38;
    // 0x8080023C: nop

    after_38:
    // 0x80800240: jal         0x800C6A60
    // 0x80800244: nop

    func_800C6A60(rdram, ctx);
        goto after_39;
    // 0x80800244: nop

    after_39:
    // 0x80800248: jal         0x800D2E4C
    // 0x8080024C: nop

    func_800D2E4C(rdram, ctx);
        goto after_40;
    // 0x8080024C: nop

    after_40:
    // 0x80800250: jal         0x800EBC04
    // 0x80800254: nop

    func_800EBC04(rdram, ctx);
        goto after_41;
    // 0x80800254: nop

    after_41:
    // 0x80800258: jal         0x80088748
    // 0x8080025C: nop

    _gldialog_entrypoint_3(rdram, ctx);
        goto after_42;
    // 0x8080025C: nop

    after_42:
    // 0x80800260: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800264: jal         0x800FF038
    // 0x80800268: lhu         $a0, 0x2($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X2);
    func_800FF038(rdram, ctx);
        goto after_43;
    // 0x80800268: lhu         $a0, 0x2($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X2);
    after_43:
    // 0x8080026C: jal         0x800DBB24
    // 0x80800270: nop

    func_800DBB24(rdram, ctx);
        goto after_44;
    // 0x80800270: nop

    after_44:
    // 0x80800274: jal         0x800E8B04
    // 0x80800278: nop

    func_800E8B04(rdram, ctx);
        goto after_45;
    // 0x80800278: nop

    after_45:
    // 0x8080027C: jal         0x800D2970
    // 0x80800280: nop

    func_800D2970(rdram, ctx);
        goto after_46;
    // 0x80800280: nop

    after_46:
    // 0x80800284: jal         0x800E86DC
    // 0x80800288: nop

    func_800E86DC(rdram, ctx);
        goto after_47;
    // 0x80800288: nop

    after_47:
    // 0x8080028C: jal         0x800BC8A0
    // 0x80800290: nop

    func_800BC8A0(rdram, ctx);
        goto after_48;
    // 0x80800290: nop

    after_48:
    // 0x80800294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080029C: jr          $ra
    // 0x808002A0: nop

    return;
    // 0x808002A0: nop

;}
RECOMP_FUNC void func_80800750_chworlddoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800758: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8080075C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800760: beq         $v0, $zero, L_80800774
    if (ctx->r2 == 0) {
        // 0x80800764: addiu       $a0, $v0, -0x1
        ctx->r4 = ADD32(ctx->r2, -0X1);
            goto L_80800774;
    }
    // 0x80800764: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80800768: jal         0x800E1720
    // 0x8080076C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800E1720(rdram, ctx);
        goto after_0;
    // 0x8080076C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800770: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_80800774:
    // 0x80800774: lbu         $t6, 0x5F($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X5F);
    // 0x80800778: beql        $t6, $zero, L_8080078C
    if (ctx->r14 == 0) {
        // 0x8080077C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080078C;
    }
    goto skip_0;
    // 0x8080077C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800780: jal         0x80089D40
    // 0x80800784: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800784: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80800788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080078C:
    // 0x8080078C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800790: jr          $ra
    // 0x80800794: nop

    return;
    // 0x80800794: nop

;}
RECOMP_FUNC void func_80800028_bskazow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080002C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800030: jal         0x8008CABC
    // 0x80800034: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800034: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800038: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080003C: jal         0x800832E0
    // 0x80800040: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800040: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800044: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800048: jal         0x800845D8
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800050: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(264, 0X2C0) << 16);
    // 0x80800054: lwc1        $f4, 0x2C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(264, 0X2C0));
    // 0x80800058: lui         $a2, 0x3EF0
    ctx->r6 = S32(0X3EF0 << 16);
    // 0x8080005C: lui         $a3, 0x4006
    ctx->r7 = S32(0X4006 << 16);
    // 0x80800060: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800064: ori         $a2, $a2, 0x3AFB
    ctx->r6 = ctx->r6 | 0X3AFB;
    // 0x80800068: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080006C: addiu       $a1, $zero, 0xC9
    ctx->r5 = ADD32(0, 0XC9);
    // 0x80800070: jal         0x800845E8
    // 0x80800074: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _babounce_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800074: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800078: lui         $a1, 0x3E37
    ctx->r5 = S32(0X3E37 << 16);
    // 0x8080007C: ori         $a1, $a1, 0x8034
    ctx->r5 = ctx->r5 | 0X8034;
    // 0x80800080: jal         0x8008B10C
    // 0x80800084: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8008B10C(rdram, ctx);
        goto after_4;
    // 0x80800084: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080008C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void bafly_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080014C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800154: jal         0x80088368
    // 0x80800158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080015C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80800160: bne         $at, $zero, L_80800174
    if (ctx->r1 != 0) {
        // 0x80800164: nop
    
            goto L_80800174;
    }
    // 0x80800164: nop

    // 0x80800168: lw          $t6, 0x8C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8C);
    // 0x8080016C: b           L_80800194
    // 0x80800170: sb          $zero, 0x9($t6)
    MEM_B(0X9, ctx->r14) = 0;
        goto L_80800194;
    // 0x80800170: sb          $zero, 0x9($t6)
    MEM_B(0X9, ctx->r14) = 0;
L_80800174:
    // 0x80800174: jal         0x800C2E04
    // 0x80800178: nop

    func_800C2E04(rdram, ctx);
        goto after_1;
    // 0x80800178: nop

    after_1:
    // 0x8080017C: lw          $t7, 0x8C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8C);
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800184: sb          $v0, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r2;
    // 0x80800188: lw          $t8, 0x8C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8C);
    // 0x8080018C: jal         0x800C3418
    // 0x80800190: lbu         $a0, 0x9($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X9);
    func_800C3418(rdram, ctx);
        goto after_2;
    // 0x80800190: lbu         $a0, 0x9($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X9);
    after_2:
L_80800194:
    // 0x80800194: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800198: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080019C: lw          $t9, 0x8C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8C);
    // 0x808001A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808001A4: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x808001A8: lw          $t0, 0x8C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8C);
    // 0x808001AC: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x808001B0: lw          $t1, 0x8C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8C);
    // 0x808001B4: jal         0x800EA05C
    // 0x808001B8: sb          $zero, 0x8($t1)
    MEM_B(0X8, ctx->r9) = 0;
    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x808001B8: sb          $zero, 0x8($t1)
    MEM_B(0X8, ctx->r9) = 0;
    after_3:
    // 0x808001BC: addiu       $at, $zero, 0xE4
    ctx->r1 = ADD32(0, 0XE4);
    // 0x808001C0: beq         $v0, $at, L_808001DC
    if (ctx->r2 == ctx->r1) {
        // 0x808001C4: addiu       $at, $zero, 0x17B
        ctx->r1 = ADD32(0, 0X17B);
            goto L_808001DC;
    }
    // 0x808001C4: addiu       $at, $zero, 0x17B
    ctx->r1 = ADD32(0, 0X17B);
    // 0x808001C8: beql        $v0, $at, L_808001E0
    if (ctx->r2 == ctx->r1) {
        // 0x808001CC: lw          $t4, 0x8C($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X8C);
            goto L_808001E0;
    }
    goto skip_0;
    // 0x808001CC: lw          $t4, 0x8C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8C);
    skip_0:
    // 0x808001D0: lw          $t2, 0x8C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8C);
    // 0x808001D4: b           L_808001E8
    // 0x808001D8: sb          $zero, 0xE($t2)
    MEM_B(0XE, ctx->r10) = 0;
        goto L_808001E8;
    // 0x808001D8: sb          $zero, 0xE($t2)
    MEM_B(0XE, ctx->r10) = 0;
L_808001DC:
    // 0x808001DC: lw          $t4, 0x8C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8C);
L_808001E0:
    // 0x808001E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808001E4: sb          $t3, 0xE($t4)
    MEM_B(0XE, ctx->r12) = ctx->r11;
L_808001E8:
    // 0x808001E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void _bapulse_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F58: syscall     144
    recomp_syscall_handler(rdram, ctx, 0x80084F58);
    return;
    // 0x80084F5C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800124_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800134: jal         0x80100094
    // 0x80800138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080013C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800148: jal         0x80089F70
    // 0x8080014C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080014C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800150: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800154: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800158: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080015C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800160: jal         0x800DC178
    // 0x80800164: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800164: nop

    after_2:
    // 0x80800168: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080016C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800170: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800174: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800178: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080017C: jal         0x800DC178
    // 0x80800180: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800180: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    after_3:
    // 0x80800184: jal         0x80088848
    // 0x80800188: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800188: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    after_4:
    // 0x8080018C: beq         $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x80800190: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080019C;
    }
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: jal         0x80102424
    // 0x80800198: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800198: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
L_8080019C:
    // 0x8080019C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void func_8080196C_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080196C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801970: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801974: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801978: jal         0x80800030
    // 0x8080197C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_0;
    // 0x8080197C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801984: addiu       $a1, $zero, 0x131
    ctx->r5 = ADD32(0, 0X131);
    // 0x80801988: jal         0x8008CCBC
    // 0x8080198C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x8080198C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_1:
    // 0x80801990: jal         0x80800000
    // 0x80801994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbswim(rdram, ctx);
        goto after_2;
    // 0x80801994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080199C: jal         0x8009B94C
    // 0x808019A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_3;
    // 0x808019A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808019A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019A8: jal         0x8009BA9C
    // 0x808019AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x808019AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808019B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019B4: jal         0x8009BF5C
    // 0x808019B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_5;
    // 0x808019B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x808019BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019C0: jal         0x8009C4CC
    // 0x808019C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_6;
    // 0x808019C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808019C8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x808019CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808019D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808019D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808019D8: jr          $ra
    // 0x808019DC: nop

    return;
    // 0x808019DC: nop

;}
RECOMP_FUNC void func_80096544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009654C: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096550: jal         0x800C670C
    // 0x80096554: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C670C(rdram, ctx);
        goto after_0;
    // 0x80096554: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80096558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009655C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096560: jr          $ra
    // 0x80096564: nop

    return;
    // 0x80096564: nop

;}
RECOMP_FUNC void func_8009E4AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E4AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E4B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E4B4: lw          $t7, 0x114($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X114);
    // 0x8009E4B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009E4BC: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8009E4C0: sb          $t6, 0xF0($t7)
    MEM_B(0XF0, ctx->r15) = ctx->r14;
    // 0x8009E4C4: lw          $a1, 0x114($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X114);
    // 0x8009E4C8: jal         0x8001BBA0
    // 0x8009E4CC: addiu       $a0, $a1, 0x78
    ctx->r4 = ADD32(ctx->r5, 0X78);
    rare_memcpy(rdram, ctx);
        goto after_0;
    // 0x8009E4CC: addiu       $a0, $a1, 0x78
    ctx->r4 = ADD32(ctx->r5, 0X78);
    after_0:
    // 0x8009E4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E4D8: jr          $ra
    // 0x8009E4DC: nop

    return;
    // 0x8009E4DC: nop

;}
RECOMP_FUNC void func_800C9484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9484: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C9488: lbu         $v1, -0x54AC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X54AC);
    // 0x800C948C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9490: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C9494: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9498: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C949C: blez        $v1, L_800C94FC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C94A0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800C94FC;
    }
    // 0x800C94A0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800C94A4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C94A8: addiu       $s0, $s0, -0x54C0
    ctx->r16 = ADD32(ctx->r16, -0X54C0);
L_800C94AC:
    // 0x800C94AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800C94B0: beql        $a0, $zero, L_800C94F0
    if (ctx->r4 == 0) {
        // 0x800C94B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C94F0;
    }
    goto skip_0;
    // 0x800C94B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800C94B8: lw          $a1, 0x2C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2C);
    // 0x800C94BC: beq         $a1, $zero, L_800C94D8
    if (ctx->r5 == 0) {
        // 0x800C94C0: nop
    
            goto L_800C94D8;
    }
    // 0x800C94C0: nop

    // 0x800C94C4: jal         0x8008AEB4
    // 0x800C94C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8008AEB4(rdram, ctx);
        goto after_0;
    // 0x800C94C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800C94CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800C94D0: sw          $v0, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r2;
    // 0x800C94D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800C94D8:
    // 0x800C94D8: jal         0x8001BAFC
    // 0x800C94DC: nop

    defrag(rdram, ctx);
        goto after_1;
    // 0x800C94DC: nop

    after_1:
    // 0x800C94E0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800C94E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C94E8: lbu         $v1, -0x54AC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X54AC);
    // 0x800C94EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800C94F0:
    // 0x800C94F0: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C94F4: bne         $at, $zero, L_800C94AC
    if (ctx->r1 != 0) {
        // 0x800C94F8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800C94AC;
    }
    // 0x800C94F8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800C94FC:
    // 0x800C94FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9500: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C9504: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C9508: jr          $ra
    // 0x800C950C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C950C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bskazpaddle_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A24: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A28: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(268, 0XAA0) << 16);
    // 0x80800A2C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A30: jr          $ra
    // 0x80800A34: lw          $v0, 0xAA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(268, 0XAA0));
    return;
    // 0x80800A34: lw          $v0, 0xAA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(268, 0XAA0));
;}
RECOMP_FUNC void chjujubagfx_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080043C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800440: jal         0x80086D28
    // 0x80800444: addiu       $a0, $a0, 0x6C88
    ctx->r4 = ADD32(ctx->r4, 0X6C88);
    _chbaddiesetup_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800444: addiu       $a0, $a0, 0x6C88
    ctx->r4 = ADD32(ctx->r4, 0X6C88);
    after_0:
    // 0x80800448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080044C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800450: jr          $ra
    // 0x80800454: nop

    return;
    // 0x80800454: nop

    // 0x80800458: nop

    // 0x8080045C: nop

;}
RECOMP_FUNC void _bskazpaddle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083530: syscall     65
    recomp_syscall_handler(rdram, ctx, 0x80083530);
    return;
    // 0x80083534: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800F71D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F71D4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F71D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F71DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F71E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F71E4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F71E8: jal         0x8008E37C
    // 0x800F71EC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008E37C(rdram, ctx);
        goto after_0;
    // 0x800F71EC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F71F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F71F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F71F8: jr          $ra
    // 0x800F71FC: nop

    return;
    // 0x800F71FC: nop

;}
RECOMP_FUNC void yaw_setUpdateType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C908: lw          $t6, 0xF8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C90C: jr          $ra
    // 0x8009C910: sw          $a1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r5;
    return;
    // 0x8009C910: sw          $a1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_801067C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801067C4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801067C8: lw          $a1, 0x6EE0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6EE0);
    // 0x801067CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801067D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801067D4: bne         $a1, $zero, L_801067E4
    if (ctx->r5 != 0) {
        // 0x801067D8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_801067E4;
    }
    // 0x801067D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801067DC: b           L_8010681C
    // 0x801067E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010681C;
    // 0x801067E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801067E4:
    // 0x801067E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801067E8: jal         0x800B2928
    // 0x801067EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    vector_size(rdram, ctx);
        goto after_0;
    // 0x801067EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801067F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801067F4: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x801067F8: bltz        $v1, L_80106818
    if (SIGNED(ctx->r3) < 0) {
        // 0x801067FC: sw          $v1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r3;
            goto L_80106818;
    }
    // 0x801067FC: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80106800: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106804: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    // 0x80106808: jal         0x800B28CC
    // 0x8010680C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    vector_at(rdram, ctx);
        goto after_1;
    // 0x8010680C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_1:
    // 0x80106810: b           L_80106820
    // 0x80106814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80106820;
    // 0x80106814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106818:
    // 0x80106818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010681C:
    // 0x8010681C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106820:
    // 0x80106820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106824: jr          $ra
    // 0x80106828: nop

    return;
    // 0x80106828: nop

;}
RECOMP_FUNC void _ncbatarget_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089490: syscall     782
    recomp_syscall_handler(rdram, ctx, 0x80089490);
    return;
    // 0x80089494: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _gzreg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A968: syscall     880
    recomp_syscall_handler(rdram, ctx, 0x8008A968);
    return;
    // 0x8008A96C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800CCAB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCAB0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800CCAB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CCAB8: addiu       $v0, $v0, -0x5180
    ctx->r2 = ADD32(ctx->r2, -0X5180);
    // 0x800CCABC: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800CCAC0: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800CCAC4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800CCAC8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800CCACC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CCAD0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800CCAD4: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800CCAD8: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800CCADC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800CCAE0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800CCAE4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800CCAE8: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800CCAEC: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800CCAF0: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800CCAF4: lbu         $t8, 0x2($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X2);
    // 0x800CCAF8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800CCAFC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800CCB00: bnel        $t9, $zero, L_800CCB14
    if (ctx->r25 != 0) {
        // 0x800CCB04: lw          $t0, 0x14($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X14);
            goto L_800CCB14;
    }
    goto skip_0;
    // 0x800CCB04: lw          $t0, 0x14($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X14);
    skip_0:
    // 0x800CCB08: b           L_800CCDD0
    // 0x800CCB0C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800CCDD0;
    // 0x800CCB0C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800CCB10: lw          $t0, 0x14($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X14);
L_800CCB14:
    // 0x800CCB14: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x800CCB18: lbu         $t2, 0x18($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X18);
    // 0x800CCB1C: bne         $t2, $zero, L_800CCB2C
    if (ctx->r10 != 0) {
        // 0x800CCB20: nop
    
            goto L_800CCB2C;
    }
    // 0x800CCB20: nop

    // 0x800CCB24: b           L_800CCDD0
    // 0x800CCB28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800CCDD0;
    // 0x800CCB28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CCB2C:
    // 0x800CCB2C: jal         0x800CB8F0
    // 0x800CCB30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800CB8F0(rdram, ctx);
        goto after_0;
    // 0x800CCB30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800CCB34: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x800CCB38: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CCB3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CCB40: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800CCB44: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800CCB48: lw          $s3, 0x70($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X70);
    // 0x800CCB4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CCB50: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800CCB54: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800CCB58: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800CCB5C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800CCB60: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800CCB64: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800CCB68: addu        $v1, $t4, $v0
    ctx->r3 = ADD32(ctx->r12, ctx->r2);
    // 0x800CCB6C: andi        $t6, $s3, 0x1
    ctx->r14 = ctx->r19 & 0X1;
    // 0x800CCB70: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800CCB74: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800CCB78: add.s       $f20, $f12, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800CCB7C: beq         $t6, $zero, L_800CCBE4
    if (ctx->r14 == 0) {
        // 0x800CCB80: sub.s       $f22, $f12, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_800CCBE4;
    }
    // 0x800CCB80: sub.s       $f22, $f12, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800CCB84: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
    // 0x800CCB88: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800CCB8C: srl         $t0, $t9, 29
    ctx->r8 = S32(U32(ctx->r25) >> 29);
    // 0x800CCB90: and         $t1, $t0, $s3
    ctx->r9 = ctx->r8 & ctx->r19;
    // 0x800CCB94: beq         $t1, $zero, L_800CCC64
    if (ctx->r9 == 0) {
        // 0x800CCB98: nop
    
            goto L_800CCC64;
    }
    // 0x800CCB98: nop

    // 0x800CCB9C: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800CCBA0: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800CCBA4: nop

    // 0x800CCBA8: bc1f        L_800CCC64
    if (!c1cs) {
        // 0x800CCBAC: nop
    
            goto L_800CCC64;
    }
    // 0x800CCBAC: nop

    // 0x800CCBB0: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800CCBB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CCBB8: bc1f        L_800CCC64
    if (!c1cs) {
        // 0x800CCBBC: nop
    
            goto L_800CCC64;
    }
    // 0x800CCBBC: nop

    // 0x800CCBC0: jal         0x800EFC7C
    // 0x800CCBC4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_1;
    // 0x800CCBC4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800CCBC8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CCBCC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CCBD0: nop

    // 0x800CCBD4: bc1f        L_800CCC64
    if (!c1cs) {
        // 0x800CCBD8: nop
    
            goto L_800CCC64;
    }
    // 0x800CCBD8: nop

    // 0x800CCBDC: b           L_800CCDD0
    // 0x800CCBE0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
        goto L_800CCDD0;
    // 0x800CCBE0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
L_800CCBE4:
    // 0x800CCBE4: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x800CCBE8: sll         $t2, $v0, 12
    ctx->r10 = S32(ctx->r2 << 12);
    // 0x800CCBEC: srl         $t3, $t2, 29
    ctx->r11 = S32(U32(ctx->r10) >> 29);
    // 0x800CCBF0: and         $t4, $t3, $s3
    ctx->r12 = ctx->r11 & ctx->r19;
    // 0x800CCBF4: beq         $t4, $zero, L_800CCC64
    if (ctx->r12 == 0) {
        // 0x800CCBF8: andi        $t5, $t3, 0x2
        ctx->r13 = ctx->r11 & 0X2;
            goto L_800CCC64;
    }
    // 0x800CCBF8: andi        $t5, $t3, 0x2
    ctx->r13 = ctx->r11 & 0X2;
    // 0x800CCBFC: bne         $t5, $zero, L_800CCC40
    if (ctx->r13 != 0) {
        // 0x800CCC00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800CCC40;
    }
    // 0x800CCC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CCC04: lh          $t6, 0xE($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XE);
    // 0x800CCC08: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800CCC0C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800CCC10: nop

    // 0x800CCC14: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CCC18: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800CCC1C: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x800CCC20: nop

    // 0x800CCC24: bc1f        L_800CCC64
    if (!c1cs) {
        // 0x800CCC28: nop
    
            goto L_800CCC64;
    }
    // 0x800CCC28: nop

    // 0x800CCC2C: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CCC30: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800CCC34: nop

    // 0x800CCC38: bc1f        L_800CCC64
    if (!c1cs) {
        // 0x800CCC3C: nop
    
            goto L_800CCC64;
    }
    // 0x800CCC3C: nop

L_800CCC40:
    // 0x800CCC40: jal         0x800EFC7C
    // 0x800CCC44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_2;
    // 0x800CCC44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800CCC48: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CCC4C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800CCC50: nop

    // 0x800CCC54: bc1f        L_800CCC64
    if (!c1cs) {
        // 0x800CCC58: nop
    
            goto L_800CCC64;
    }
    // 0x800CCC58: nop

    // 0x800CCC5C: b           L_800CCDD0
    // 0x800CCC60: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
        goto L_800CCDD0;
    // 0x800CCC60: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
L_800CCC64:
    // 0x800CCC64: jal         0x800CB910
    // 0x800CCC68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800CB910(rdram, ctx);
        goto after_3;
    // 0x800CCC68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800CCC6C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800CCC70: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x800CCC74: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CCC78: beq         $t7, $zero, L_800CCD1C
    if (ctx->r15 == 0) {
        // 0x800CCC7C: sltu        $at, $s0, $v0
        ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
            goto L_800CCD1C;
    }
    // 0x800CCC7C: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800CCC80: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x800CCC84: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800CCC88: beql        $at, $zero, L_800CCDD0
    if (ctx->r1 == 0) {
        // 0x800CCC8C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800CCDD0;
    }
    goto skip_1;
    // 0x800CCC8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x800CCC90: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
L_800CCC94:
    // 0x800CCC94: sll         $t0, $t9, 12
    ctx->r8 = S32(ctx->r25 << 12);
    // 0x800CCC98: srl         $t1, $t0, 29
    ctx->r9 = S32(U32(ctx->r8) >> 29);
    // 0x800CCC9C: and         $t2, $t1, $s3
    ctx->r10 = ctx->r9 & ctx->r19;
    // 0x800CCCA0: beql        $t2, $zero, L_800CCD08
    if (ctx->r10 == 0) {
        // 0x800CCCA4: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CCD08;
    }
    goto skip_2;
    // 0x800CCCA4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_2:
    // 0x800CCCA8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CCCAC: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800CCCB0: nop

    // 0x800CCCB4: bc1fl       L_800CCD08
    if (!c1cs) {
        // 0x800CCCB8: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CCD08;
    }
    goto skip_3;
    // 0x800CCCB8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_3:
    // 0x800CCCBC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800CCCC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CCCC4: bc1fl       L_800CCD08
    if (!c1cs) {
        // 0x800CCCC8: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CCD08;
    }
    goto skip_4;
    // 0x800CCCC8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_4:
    // 0x800CCCCC: jal         0x800EFC7C
    // 0x800CCCD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_4;
    // 0x800CCCD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800CCCD4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CCCD8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800CCCDC: nop

    // 0x800CCCE0: bc1fl       L_800CCD08
    if (!c1cs) {
        // 0x800CCCE4: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CCD08;
    }
    goto skip_5;
    // 0x800CCCE4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_5:
    // 0x800CCCE8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800CCCEC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800CCCF0: subu        $v0, $s0, $t3
    ctx->r2 = SUB32(ctx->r16, ctx->r11);
    // 0x800CCCF4: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CCCF8: mflo        $v0
    ctx->r2 = lo;
    // 0x800CCCFC: b           L_800CCDD4
    // 0x800CCD00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800CCDD4;
    // 0x800CCD00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800CCD04: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800CCD08:
    // 0x800CCD08: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800CCD0C: bnel        $at, $zero, L_800CCC94
    if (ctx->r1 != 0) {
        // 0x800CCD10: lw          $t9, 0x14($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X14);
            goto L_800CCC94;
    }
    goto skip_6;
    // 0x800CCD10: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    skip_6:
    // 0x800CCD14: b           L_800CCDD0
    // 0x800CCD18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800CCDD0;
    // 0x800CCD18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CCD1C:
    // 0x800CCD1C: beql        $at, $zero, L_800CCDD0
    if (ctx->r1 == 0) {
        // 0x800CCD20: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800CCDD0;
    }
    goto skip_7;
    // 0x800CCD20: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_7:
    // 0x800CCD24: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_800CCD28:
    // 0x800CCD28: sll         $t6, $v0, 12
    ctx->r14 = S32(ctx->r2 << 12);
    // 0x800CCD2C: srl         $t7, $t6, 29
    ctx->r15 = S32(U32(ctx->r14) >> 29);
    // 0x800CCD30: and         $t8, $t7, $s3
    ctx->r24 = ctx->r15 & ctx->r19;
    // 0x800CCD34: beq         $t8, $zero, L_800CCDBC
    if (ctx->r24 == 0) {
        // 0x800CCD38: andi        $t9, $t7, 0x2
        ctx->r25 = ctx->r15 & 0X2;
            goto L_800CCDBC;
    }
    // 0x800CCD38: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x800CCD3C: bne         $t9, $zero, L_800CCD84
    if (ctx->r25 != 0) {
        // 0x800CCD40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800CCD84;
    }
    // 0x800CCD40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CCD44: lh          $t0, 0xE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XE);
    // 0x800CCD48: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CCD4C: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x800CCD50: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800CCD54: nop

    // 0x800CCD58: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CCD5C: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800CCD60: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x800CCD64: nop

    // 0x800CCD68: bc1fl       L_800CCDC0
    if (!c1cs) {
        // 0x800CCD6C: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CCDC0;
    }
    goto skip_8;
    // 0x800CCD6C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_8:
    // 0x800CCD70: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CCD74: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x800CCD78: nop

    // 0x800CCD7C: bc1fl       L_800CCDC0
    if (!c1cs) {
        // 0x800CCD80: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CCDC0;
    }
    goto skip_9;
    // 0x800CCD80: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_9:
L_800CCD84:
    // 0x800CCD84: jal         0x800EFC7C
    // 0x800CCD88: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_5;
    // 0x800CCD88: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x800CCD8C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CCD90: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800CCD94: nop

    // 0x800CCD98: bc1fl       L_800CCDC0
    if (!c1cs) {
        // 0x800CCD9C: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CCDC0;
    }
    goto skip_10;
    // 0x800CCD9C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_10:
    // 0x800CCDA0: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800CCDA4: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800CCDA8: subu        $v0, $s0, $t1
    ctx->r2 = SUB32(ctx->r16, ctx->r9);
    // 0x800CCDAC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CCDB0: mflo        $v0
    ctx->r2 = lo;
    // 0x800CCDB4: b           L_800CCDD4
    // 0x800CCDB8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800CCDD4;
    // 0x800CCDB8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800CCDBC:
    // 0x800CCDBC: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800CCDC0:
    // 0x800CCDC0: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800CCDC4: bnel        $at, $zero, L_800CCD28
    if (ctx->r1 != 0) {
        // 0x800CCDC8: lw          $v0, 0x14($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X14);
            goto L_800CCD28;
    }
    goto skip_11;
    // 0x800CCDC8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    skip_11:
    // 0x800CCDCC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CCDD0:
    // 0x800CCDD0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800CCDD4:
    // 0x800CCDD4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800CCDD8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800CCDDC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800CCDE0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800CCDE4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800CCDE8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800CCDEC: jr          $ra
    // 0x800CCDF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800CCDF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80800104_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800108: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800110: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800114: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800118: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080011C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800120: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800124: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800128: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080012C: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80800130: beq         $at, $zero, L_80800524
    if (ctx->r1 == 0) {
        // 0x80800134: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800524;
    }
    // 0x80800134: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800138: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2412, 0X1244) << 16);
    // 0x8080013C: addu        $at, $at, $t8
    gpr jr_addend_80800144 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800140: lw          $t8, 0x1244($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2412, 0X1244));
    // 0x80800144: jr          $t8
    // 0x80800148: nop

    switch (jr_addend_80800144 >> 2) {
        case 0: goto L_8080014C; break;
        case 1: goto L_80800524; break;
        case 2: goto L_80800524; break;
        case 3: goto L_8080015C; break;
        case 4: goto L_808002A0; break;
        case 5: goto L_808002F8; break;
        case 6: goto L_808004BC; break;
        case 7: goto L_808004CC; break;
        case 8: goto L_808004DC; break;
        default: switch_error(__func__, 0x80800144, 0x80801244);
    }
    // 0x80800148: nop

L_8080014C:
    // 0x8080014C: jal         0x800FFAB0
    // 0x80800150: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_0;
    // 0x80800150: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80800154: b           L_80800528
    // 0x80800158: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
        goto L_80800528;
    // 0x80800158: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_8080015C:
    // 0x8080015C: lhu         $t9, 0x76($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X76);
    // 0x80800160: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2412, 0X130C) << 16);
    // 0x80800164: addiu       $s0, $s0, 0x130C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2412, 0X130C));
    // 0x80800168: srl         $t1, $t9, 7
    ctx->r9 = S32(U32(ctx->r25) >> 7);
    // 0x8080016C: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80800170: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80800174: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80800178: jal         0x800D91EC
    // 0x8080017C: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    func_800D91EC(rdram, ctx);
        goto after_1;
    // 0x8080017C: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    after_1:
    // 0x80800180: lhu         $v1, 0x76($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X76);
    // 0x80800184: lwc1        $f12, 0x58($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X58);
    // 0x80800188: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080018C: srl         $t4, $v1, 7
    ctx->r12 = S32(U32(ctx->r3) >> 7);
    // 0x80800190: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80800194: addu        $t0, $s0, $t6
    ctx->r8 = ADD32(ctx->r16, ctx->r14);
    // 0x80800198: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8080019C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x808001A0: addu        $a0, $s0, $t5
    ctx->r4 = ADD32(ctx->r16, ctx->r13);
    // 0x808001A4: lwc1        $f14, -0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, -0X10);
    // 0x808001A8: lw          $a3, -0xC($a0)
    ctx->r7 = MEM_W(ctx->r4, -0XC);
    // 0x808001AC: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x808001B0: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x808001B4: jal         0x800F10B4
    // 0x808001B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808001B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808001BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808001C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808001C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001CC: lwc1        $f16, 0x58($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X58);
    // 0x808001D0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808001D4: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x808001D8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x808001DC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808001E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808001E4: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x808001E8: bc1f        L_80800214
    if (!c1cs) {
        // 0x808001EC: swc1        $f8, 0x34($s2)
        MEM_W(0X34, ctx->r18) = ctx->f8.u32l;
            goto L_80800214;
    }
    // 0x808001EC: swc1        $f8, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f8.u32l;
    // 0x808001F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808001F4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001F8: lwc1        $f12, 0x34($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X34);
    // 0x808001FC: jal         0x800F10B4
    // 0x80800200: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800200: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80800204: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800208: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080020C: jal         0x808007DC
    // 0x80800210: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808007DC_choildrill(rdram, ctx);
        goto after_4;
    // 0x80800210: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_80800214:
    // 0x80800214: beql        $s1, $zero, L_80800528
    if (ctx->r17 == 0) {
        // 0x80800218: lw          $t1, 0x0($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X0);
            goto L_80800528;
    }
    goto skip_0;
    // 0x80800218: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x8080021C: lhu         $v0, 0x76($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X76);
    // 0x80800220: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800224: srl         $v1, $v0, 7
    ctx->r3 = S32(U32(ctx->r2) >> 7);
    // 0x80800228: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8080022C: addu        $t0, $s0, $t7
    ctx->r8 = ADD32(ctx->r16, ctx->r15);
    // 0x80800230: lbu         $a1, 0x8($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X8);
    // 0x80800234: beql        $a1, $zero, L_80800250
    if (ctx->r5 == 0) {
        // 0x80800238: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_80800250;
    }
    goto skip_1;
    // 0x80800238: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x8080023C: jal         0x80800CF0
    // 0x80800240: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    func_80800CF0_choildrill(rdram, ctx);
        goto after_5;
    // 0x80800240: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    after_5:
    // 0x80800244: lhu         $v0, 0x76($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X76);
    // 0x80800248: srl         $v1, $v0, 7
    ctx->r3 = S32(U32(ctx->r2) >> 7);
    // 0x8080024C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
L_80800250:
    // 0x80800250: sll         $t1, $t8, 7
    ctx->r9 = S32(ctx->r24 << 7);
    // 0x80800254: andi        $t2, $v0, 0x7F
    ctx->r10 = ctx->r2 & 0X7F;
    // 0x80800258: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8080025C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x80800260: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x80800264: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80800268: sh          $t3, 0x76($s2)
    MEM_H(0X76, ctx->r18) = ctx->r11;
    // 0x8080026C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80800270: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800274: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800278: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8080027C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800280: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800284: nop

    // 0x80800288: bc1fl       L_80800528
    if (!c1cs) {
        // 0x8080028C: lw          $t1, 0x0($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X0);
            goto L_80800528;
    }
    goto skip_2;
    // 0x8080028C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    skip_2:
    // 0x80800290: jal         0x808009F8
    // 0x80800294: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808009F8_choildrill(rdram, ctx);
        goto after_6;
    // 0x80800294: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80800298: b           L_80800528
    // 0x8080029C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
        goto L_80800528;
    // 0x8080029C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_808002A0:
    // 0x808002A0: jal         0x800D90A4
    // 0x808002A4: addiu       $a0, $s2, 0x24
    ctx->r4 = ADD32(ctx->r18, 0X24);
    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x808002A4: addiu       $a0, $s2, 0x24
    ctx->r4 = ADD32(ctx->r18, 0X24);
    after_7:
    // 0x808002A8: beq         $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x808002AC: lui         $a0, 0x8CBB
        ctx->r4 = S32(0X8CBB << 16);
            goto L_808002D8;
    }
    // 0x808002AC: lui         $a0, 0x8CBB
    ctx->r4 = S32(0X8CBB << 16);
    // 0x808002B0: jal         0x800C3F48
    // 0x808002B4: ori         $a0, $a0, 0x5BE9
    ctx->r4 = ctx->r4 | 0X5BE9;
    func_800C3F48(rdram, ctx);
        goto after_8;
    // 0x808002B4: ori         $a0, $a0, 0x5BE9
    ctx->r4 = ctx->r4 | 0X5BE9;
    after_8:
    // 0x808002B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2412, 0X1268) << 16);
    // 0x808002BC: lwc1        $f12, 0x1268($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2412, 0X1268));
    // 0x808002C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002C8: jal         0x800DC178
    // 0x808002CC: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x808002CC: nop

    after_9:
    // 0x808002D0: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
    // 0x808002D4: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
L_808002D8:
    // 0x808002D8: jal         0x800D90A4
    // 0x808002DC: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_10;
    // 0x808002DC: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    after_10:
    // 0x808002E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002E4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x808002E8: jal         0x808007DC
    // 0x808002EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808007DC_choildrill(rdram, ctx);
        goto after_11;
    // 0x808002EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x808002F0: b           L_80800528
    // 0x808002F4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
        goto L_80800528;
    // 0x808002F4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_808002F8:
    // 0x808002F8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2412, 0X1300) << 16);
    // 0x808002FC: addiu       $t9, $t9, 0x1300
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2412, 0X1300));
    // 0x80800300: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80800304: addiu       $t8, $sp, 0x7C
    ctx->r24 = ADD32(ctx->r29, 0X7C);
    // 0x80800308: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x8080030C: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80800310: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x80800314: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    // 0x80800318: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x8080031C: jal         0x800D90A4
    // 0x80800320: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    func_800D90A4(rdram, ctx);
        goto after_12;
    // 0x80800320: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    after_12:
    // 0x80800324: beql        $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x80800328: lbu         $t2, 0x79($s2)
        ctx->r10 = MEM_BU(ctx->r18, 0X79);
            goto L_808003AC;
    }
    goto skip_3;
    // 0x80800328: lbu         $t2, 0x79($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X79);
    skip_3:
    // 0x8080032C: lbu         $v0, 0x79($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X79);
    // 0x80800330: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80800334: srl         $t3, $v0, 4
    ctx->r11 = S32(U32(ctx->r2) >> 4);
    // 0x80800338: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8080033C: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80800340: andi        $t7, $v0, 0xFF0F
    ctx->r15 = ctx->r2 & 0XFF0F;
    // 0x80800344: or          $t1, $t6, $t7
    ctx->r9 = ctx->r14 | ctx->r15;
    // 0x80800348: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x8080034C: srl         $t9, $t8, 4
    ctx->r25 = S32(U32(ctx->r24) >> 4);
    // 0x80800350: bne         $t9, $zero, L_80800388
    if (ctx->r25 != 0) {
        // 0x80800354: sb          $t1, 0x79($s2)
        MEM_B(0X79, ctx->r18) = ctx->r9;
            goto L_80800388;
    }
    // 0x80800354: sb          $t1, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r9;
    // 0x80800358: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x8080035C: jal         0x800C3F48
    // 0x80800360: ori         $a0, $a0, 0xFC09
    ctx->r4 = ctx->r4 | 0XFC09;
    func_800C3F48(rdram, ctx);
        goto after_13;
    // 0x80800360: ori         $a0, $a0, 0xFC09
    ctx->r4 = ctx->r4 | 0XFC09;
    after_13:
    // 0x80800364: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800368: jal         0x808009F8
    // 0x8080036C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808009F8_choildrill(rdram, ctx);
        goto after_14;
    // 0x8080036C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_14:
    // 0x80800370: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: jal         0x800EE7F8
    // 0x8080037C: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x8080037C: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    after_15:
    // 0x80800380: b           L_808003A0
    // 0x80800384: nop

        goto L_808003A0;
    // 0x80800384: nop

L_80800388:
    // 0x80800388: jal         0x800C3F48
    // 0x8080038C: ori         $a0, $a0, 0xFC0A
    ctx->r4 = ctx->r4 | 0XFC0A;
    func_800C3F48(rdram, ctx);
        goto after_16;
    // 0x8080038C: ori         $a0, $a0, 0xFC0A
    ctx->r4 = ctx->r4 | 0XFC0A;
    after_16:
    // 0x80800390: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800394: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800398: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x8080039C: swc1        $f8, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f8.u32l;
L_808003A0:
    // 0x808003A0: jal         0x808008AC
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008AC_choildrill(rdram, ctx);
        goto after_17;
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808003A8: lbu         $t2, 0x79($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X79);
L_808003AC:
    // 0x808003AC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808003B0: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    // 0x808003B4: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x808003B8: beq         $t3, $zero, L_808004B4
    if (ctx->r11 == 0) {
        // 0x808003BC: addiu       $s0, $s2, 0x4
        ctx->r16 = ADD32(ctx->r18, 0X4);
            goto L_808004B4;
    }
    // 0x808003BC: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x808003C0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808003C4: lwc1        $f12, 0x58($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X58);
    // 0x808003C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003CC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808003D0: addiu       $s1, $s2, 0x18
    ctx->r17 = ADD32(ctx->r18, 0X18);
    // 0x808003D4: jal         0x800F10B4
    // 0x808003D8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800F10B4(rdram, ctx);
        goto after_18;
    // 0x808003D8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_18:
    // 0x808003DC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x808003E0: lbu         $t4, 0x79($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X79);
    // 0x808003E4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808003E8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808003EC: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x808003F0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x808003F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808003F8: bgez        $t5, L_8080040C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808003FC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8080040C;
    }
    // 0x808003FC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800400: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800404: nop

    // 0x80800408: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8080040C:
    // 0x8080040C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800410: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800414: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800418: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080041C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800420: jal         0x800F10B4
    // 0x80800424: sub.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f4.fl;
    func_800F10B4(rdram, ctx);
        goto after_19;
    // 0x80800424: sub.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f4.fl;
    after_19:
    // 0x80800428: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800434: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800438: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x8080043C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800440: jal         0x800EFE50
    // 0x80800444: nop

    func_800EFE50(rdram, ctx);
        goto after_20;
    // 0x80800444: nop

    after_20:
    // 0x80800448: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8080044C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800450: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800454: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800458: lwc1        $f12, 0x58($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X58);
    // 0x8080045C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800460: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800464: jal         0x800F10B4
    // 0x80800468: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_21;
    // 0x80800468: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x8080046C: jal         0x80013970
    // 0x80800470: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_22;
    // 0x80800470: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_22:
    // 0x80800474: lbu         $t6, 0x79($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X79);
    // 0x80800478: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080047C: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80800480: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80800484: bgez        $t7, L_80800498
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800488: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80800498;
    }
    // 0x80800488: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080048C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800490: nop

    // 0x80800494: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80800498:
    // 0x80800498: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080049C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808004A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004A4: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x808004A8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808004AC: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x808004B0: swc1        $f4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f4.u32l;
L_808004B4:
    // 0x808004B4: b           L_80800528
    // 0x808004B8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
        goto L_80800528;
    // 0x808004B8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_808004BC:
    // 0x808004BC: jal         0x8080097C
    // 0x808004C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8080097C_choildrill(rdram, ctx);
        goto after_23;
    // 0x808004C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_23:
    // 0x808004C4: b           L_80800528
    // 0x808004C8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
        goto L_80800528;
    // 0x808004C8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_808004CC:
    // 0x808004CC: jal         0x8080097C
    // 0x808004D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8080097C_choildrill(rdram, ctx);
        goto after_24;
    // 0x808004D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_24:
    // 0x808004D4: b           L_80800528
    // 0x808004D8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
        goto L_80800528;
    // 0x808004D8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_808004DC:
    // 0x808004DC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808004E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808004E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004E8: lwc1        $f12, 0x58($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X58);
    // 0x808004EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808004F0: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    // 0x808004F4: jal         0x800F10B4
    // 0x808004F8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800F10B4(rdram, ctx);
        goto after_25;
    // 0x808004F8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_25:
    // 0x808004FC: swc1        $f0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f0.u32l;
    // 0x80800500: jal         0x800D90A4
    // 0x80800504: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_26;
    // 0x80800504: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    after_26:
    // 0x80800508: beq         $v0, $zero, L_80800524
    if (ctx->r2 == 0) {
        // 0x8080050C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800524;
    }
    // 0x8080050C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800510: jal         0x808009F8
    // 0x80800514: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808009F8_choildrill(rdram, ctx);
        goto after_27;
    // 0x80800514: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_27:
    // 0x80800518: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080051C: jal         0x80103110
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_28;
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
L_80800524:
    // 0x80800524: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_80800528:
    // 0x80800528: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8080052C: addiu       $at, $zero, 0x91F
    ctx->r1 = ADD32(0, 0X91F);
    // 0x80800530: lhu         $t8, 0x14($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X14);
    // 0x80800534: bnel        $t8, $at, L_80800700
    if (ctx->r24 != ctx->r1) {
        // 0x80800538: lw          $t3, 0x7C($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X7C);
            goto L_80800700;
    }
    goto skip_4;
    // 0x80800538: lw          $t3, 0x7C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X7C);
    skip_4:
    // 0x8080053C: jal         0x800D8FF8
    // 0x80800540: nop

    func_800D8FF8(rdram, ctx);
        goto after_29;
    // 0x80800540: nop

    after_29:
    // 0x80800544: lwc1        $f12, 0x34($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X34);
    // 0x80800548: lwc1        $f16, 0x50($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X50);
    // 0x8080054C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800550: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80800554: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800558: lui         $at, 0x4388
    ctx->r1 = S32(0X4388 << 16);
    // 0x8080055C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800560: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800564: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800568: lui         $at, 0x42B8
    ctx->r1 = S32(0X42B8 << 16);
    // 0x8080056C: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80800570: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x80800574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800578: swc1        $f8, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f8.u32l;
    // 0x8080057C: lwc1        $f2, 0x50($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X50);
    // 0x80800580: c.le.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl <= ctx->f2.fl;
    // 0x80800584: nop

    // 0x80800588: bc1fl       L_808005A4
    if (!c1cs) {
        // 0x8080058C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_808005A4;
    }
    goto skip_5;
    // 0x8080058C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_5:
    // 0x80800590: sub.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80800594: lwc1        $f12, 0x34($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X34);
    // 0x80800598: swc1        $f18, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f18.u32l;
    // 0x8080059C: lwc1        $f2, 0x50($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X50);
    // 0x808005A0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_808005A4:
    // 0x808005A4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x808005A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808005AC: bc1f        L_808005D0
    if (!c1cs) {
        // 0x808005B0: nop
    
            goto L_808005D0;
    }
    // 0x808005B0: nop

    // 0x808005B4: lwc1        $f10, 0x54($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X54);
    // 0x808005B8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808005BC: nop

    // 0x808005C0: bc1f        L_808005D0
    if (!c1cs) {
        // 0x808005C4: nop
    
            goto L_808005D0;
    }
    // 0x808005C4: nop

    // 0x808005C8: b           L_808005D0
    // 0x808005CC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_808005D0;
    // 0x808005CC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_808005D0:
    // 0x808005D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808005D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808005D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005DC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808005E0: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x808005E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808005E8: bc1f        L_8080060C
    if (!c1cs) {
        // 0x808005EC: nop
    
            goto L_8080060C;
    }
    // 0x808005EC: nop

    // 0x808005F0: lwc1        $f4, 0x54($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X54);
    // 0x808005F4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808005F8: nop

    // 0x808005FC: bc1f        L_8080060C
    if (!c1cs) {
        // 0x80800600: nop
    
            goto L_8080060C;
    }
    // 0x80800600: nop

    // 0x80800604: b           L_8080060C
    // 0x80800608: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
        goto L_8080060C;
    // 0x80800608: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
L_8080060C:
    // 0x8080060C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80800610: nop

    // 0x80800614: bc1f        L_8080063C
    if (!c1cs) {
        // 0x80800618: nop
    
            goto L_8080063C;
    }
    // 0x80800618: nop

    // 0x8080061C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800620: nop

    // 0x80800624: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80800628: nop

    // 0x8080062C: bc1f        L_8080063C
    if (!c1cs) {
        // 0x80800630: nop
    
            goto L_8080063C;
    }
    // 0x80800630: nop

    // 0x80800634: b           L_8080063C
    // 0x80800638: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_8080063C;
    // 0x80800638: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_8080063C:
    // 0x8080063C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2412, 0X126C) << 16);
    // 0x80800640: lwc1        $f8, 0x126C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2412, 0X126C));
    // 0x80800644: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800648: jal         0x800F10B4
    // 0x8080064C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_30;
    // 0x8080064C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_30:
    // 0x80800650: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80800654: or          $t9, $s0, $s1
    ctx->r25 = ctx->r16 | ctx->r17;
    // 0x80800658: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080065C: or          $a1, $t9, $v0
    ctx->r5 = ctx->r25 | ctx->r2;
    // 0x80800660: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x80800664: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80800668: jal         0x80800CF0
    // 0x8080066C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800CF0_choildrill(rdram, ctx);
        goto after_31;
    // 0x8080066C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_31:
    // 0x80800670: lwc1        $f18, 0x50($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X50);
    // 0x80800674: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80800678: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080067C: jal         0x8010262C
    // 0x80800680: swc1        $f18, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f18.u32l;
    func_8010262C(rdram, ctx);
        goto after_32;
    // 0x80800680: swc1        $f18, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f18.u32l;
    after_32:
    // 0x80800684: beq         $v0, $zero, L_808007C0
    if (ctx->r2 == 0) {
        // 0x80800688: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808007C0;
    }
    // 0x80800688: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080068C: jal         0x80013970
    // 0x80800690: lwc1        $f12, 0x50($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
    func_80013970(rdram, ctx);
        goto after_33;
    // 0x80800690: lwc1        $f12, 0x50($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
    after_33:
    // 0x80800694: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800698: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080069C: nop

    // 0x808006A0: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808006A4: jal         0x800136E4
    // 0x808006A8: nop

    func_800136E4(rdram, ctx);
        goto after_34;
    // 0x808006A8: nop

    after_34:
    // 0x808006AC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x808006B0: jal         0x800136E4
    // 0x808006B4: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_35;
    // 0x808006B4: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_35:
    // 0x808006B8: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x808006C4: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x808006C8: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x808006CC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808006D0: jal         0x800E0AFC
    // 0x808006D4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_36;
    // 0x808006D4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_36:
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x808006E0: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x808006E4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x808006E8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808006EC: jal         0x800E0AFC
    // 0x808006F0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_37;
    // 0x808006F0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_37:
    // 0x808006F4: b           L_808007C4
    // 0x808006F8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808007C4;
    // 0x808006F8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808006FC: lw          $t3, 0x7C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X7C);
L_80800700:
    // 0x80800700: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800704: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
    // 0x80800708: sll         $t5, $t3, 19
    ctx->r13 = S32(ctx->r11 << 19);
    // 0x8080070C: bgez        $t5, L_80800794
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800710: nop
    
            goto L_80800794;
    }
    // 0x80800710: nop

L_80800714:
    // 0x80800714: jal         0x800DC0C0
    // 0x80800718: nop

    func_800DC0C0(rdram, ctx);
        goto after_38;
    // 0x80800718: nop

    after_38:
    // 0x8080071C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2412, 0X1270) << 16);
    // 0x80800720: lwc1        $f4, 0x1270($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2412, 0X1270));
    // 0x80800724: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800728: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080072C: nop

    // 0x80800730: bc1fl       L_80800788
    if (!c1cs) {
        // 0x80800734: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800788;
    }
    goto skip_6;
    // 0x80800734: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_6:
    // 0x80800738: jal         0x80103DFC
    // 0x8080073C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80103DFC(rdram, ctx);
        goto after_39;
    // 0x8080073C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_39:
    // 0x80800740: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800744: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800748: jal         0x800DC178
    // 0x8080074C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_40;
    // 0x8080074C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_40:
    // 0x80800750: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800754: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800758: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8080075C: jal         0x800DC178
    // 0x80800760: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_41;
    // 0x80800760: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_41:
    // 0x80800764: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080076C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80800770: jal         0x800EF214
    // 0x80800774: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_800EF214(rdram, ctx);
        goto after_42;
    // 0x80800774: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_42:
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080077C: jal         0x80088AB8
    // 0x80800780: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    _fxtwinkle_entrypoint_2(rdram, ctx);
        goto after_43;
    // 0x80800780: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    after_43:
    // 0x80800784: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800788:
    // 0x80800788: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080078C: bne         $s1, $at, L_80800714
    if (ctx->r17 != ctx->r1) {
        // 0x80800790: nop
    
            goto L_80800714;
    }
    // 0x80800790: nop

L_80800794:
    // 0x80800794: jal         0x800D8FF8
    // 0x80800798: nop

    func_800D8FF8(rdram, ctx);
        goto after_44;
    // 0x80800798: nop

    after_44:
    // 0x8080079C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x808007A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007A4: lwc1        $f16, 0x48($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X48);
    // 0x808007A8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808007AC: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x808007B0: swc1        $f18, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f18.u32l;
    // 0x808007B4: jal         0x800136E4
    // 0x808007B8: lwc1        $f12, 0x48($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X48);
    func_800136E4(rdram, ctx);
        goto after_45;
    // 0x808007B8: lwc1        $f12, 0x48($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X48);
    after_45:
    // 0x808007BC: swc1        $f0, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f0.u32l;
L_808007C0:
    // 0x808007C0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808007C4:
    // 0x808007C4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808007C8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808007CC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808007D0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808007D4: jr          $ra
    // 0x808007D8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x808007D8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_808007D8_gccollectDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808007DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007E8: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x808007EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007F0: srl         $t6, $a0, 23
    ctx->r14 = S32(U32(ctx->r4) >> 23);
    // 0x808007F4: jal         0x800D0A9C
    // 0x808007F8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x808007F8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x808007FC: beql        $v0, $zero, L_8080085C
    if (ctx->r2 == 0) {
        // 0x80800800: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_8080085C;
    }
    goto skip_0;
    // 0x80800800: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    skip_0:
    // 0x80800804: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80800808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080080C: srl         $t7, $a0, 23
    ctx->r15 = S32(U32(ctx->r4) >> 23);
    // 0x80800810: jal         0x800D0B68
    // 0x80800814: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x80800814: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x80800818: bnel        $v0, $zero, L_8080085C
    if (ctx->r2 != 0) {
        // 0x8080081C: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_8080085C;
    }
    goto skip_1;
    // 0x8080081C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    skip_1:
    // 0x80800820: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80800824: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800828: srl         $t8, $a0, 23
    ctx->r24 = S32(U32(ctx->r4) >> 23);
    // 0x8080082C: jal         0x800D0634
    // 0x80800830: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800D0634(rdram, ctx);
        goto after_2;
    // 0x80800830: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x80800834: bnel        $v0, $zero, L_8080085C
    if (ctx->r2 != 0) {
        // 0x80800838: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_8080085C;
    }
    goto skip_2;
    // 0x80800838: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    skip_2:
    // 0x8080083C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80800840: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800844: srl         $t9, $a0, 23
    ctx->r25 = S32(U32(ctx->r4) >> 23);
    // 0x80800848: jal         0x808005BC
    // 0x8080084C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_808005BC_gccollectDll(rdram, ctx);
        goto after_3;
    // 0x8080084C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x80800850: b           L_80800880
    // 0x80800854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800880;
    // 0x80800854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800858: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
L_8080085C:
    // 0x8080085C: jal         0x800EE88C
    // 0x80800860: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE88C(rdram, ctx);
        goto after_4;
    // 0x80800860: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800864: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80800868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080086C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800870: srl         $t0, $a0, 23
    ctx->r8 = S32(U32(ctx->r4) >> 23);
    // 0x80800874: jal         0x800D0778
    // 0x80800878: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800D0778(rdram, ctx);
        goto after_5;
    // 0x80800878: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_5:
    // 0x8080087C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800880:
    // 0x80800880: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800884: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800888: jr          $ra
    // 0x8080088C: nop

    return;
    // 0x8080088C: nop

;}
RECOMP_FUNC void sucoasterdata_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: sltiu       $at, $a0, 0x8
    ctx->r1 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x80800220: beq         $at, $zero, L_80800318
    if (ctx->r1 == 0) {
        // 0x80800224: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80800318;
    }
    // 0x80800224: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800228: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3282, 0X39C) << 16);
    // 0x8080022C: addu        $at, $at, $t6
    gpr jr_addend_80800234 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800230: lw          $t6, 0x39C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3282, 0X39C));
    // 0x80800234: jr          $t6
    // 0x80800238: nop

    switch (jr_addend_80800234 >> 2) {
        case 0: goto L_8080023C; break;
        case 1: goto L_80800250; break;
        case 2: goto L_80800318; break;
        case 3: goto L_80800264; break;
        case 4: goto L_80800318; break;
        case 5: goto L_808002DC; break;
        case 6: goto L_808002F0; break;
        case 7: goto L_80800304; break;
        default: switch_error(__func__, 0x80800234, 0x8080039C);
    }
    // 0x80800238: nop

L_8080023C:
    // 0x8080023C: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80800240: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3282, 0X84C) << 16);
    // 0x80800244: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80800248: jr          $ra
    // 0x8080024C: addiu       $v0, $v0, 0x84C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X84C));
    return;
    // 0x8080024C: addiu       $v0, $v0, 0x84C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X84C));
L_80800250:
    // 0x80800250: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80800254: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3282, 0X990) << 16);
    // 0x80800258: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8080025C: jr          $ra
    // 0x80800260: addiu       $v0, $v0, 0x990
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X990));
    return;
    // 0x80800260: addiu       $v0, $v0, 0x990
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X990));
L_80800264:
    // 0x80800264: addiu       $at, $zero, 0x327
    ctx->r1 = ADD32(0, 0X327);
    // 0x80800268: beq         $a1, $at, L_8080029C
    if (ctx->r5 == ctx->r1) {
        // 0x8080026C: addiu       $t9, $zero, 0x7
        ctx->r25 = ADD32(0, 0X7);
            goto L_8080029C;
    }
    // 0x8080026C: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80800270: addiu       $at, $zero, 0x328
    ctx->r1 = ADD32(0, 0X328);
    // 0x80800274: beq         $a1, $at, L_808002AC
    if (ctx->r5 == ctx->r1) {
        // 0x80800278: addiu       $t0, $zero, 0x7
        ctx->r8 = ADD32(0, 0X7);
            goto L_808002AC;
    }
    // 0x80800278: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8080027C: addiu       $at, $zero, 0x329
    ctx->r1 = ADD32(0, 0X329);
    // 0x80800280: beq         $a1, $at, L_808002BC
    if (ctx->r5 == ctx->r1) {
        // 0x80800284: addiu       $t1, $zero, 0x7
        ctx->r9 = ADD32(0, 0X7);
            goto L_808002BC;
    }
    // 0x80800284: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80800288: addiu       $at, $zero, 0x32A
    ctx->r1 = ADD32(0, 0X32A);
    // 0x8080028C: beq         $a1, $at, L_808002CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800290: addiu       $t2, $zero, 0x7
        ctx->r10 = ADD32(0, 0X7);
            goto L_808002CC;
    }
    // 0x80800290: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80800294: b           L_8080031C
    // 0x80800298: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8080031C;
    // 0x80800298: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8080029C:
    // 0x8080029C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3282, 0X6FC) << 16);
    // 0x808002A0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x808002A4: jr          $ra
    // 0x808002A8: addiu       $v0, $v0, 0x6FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X6FC));
    return;
    // 0x808002A8: addiu       $v0, $v0, 0x6FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X6FC));
L_808002AC:
    // 0x808002AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3282, 0X750) << 16);
    // 0x808002B0: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x808002B4: jr          $ra
    // 0x808002B8: addiu       $v0, $v0, 0x750
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X750));
    return;
    // 0x808002B8: addiu       $v0, $v0, 0x750
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X750));
L_808002BC:
    // 0x808002BC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3282, 0X7A4) << 16);
    // 0x808002C0: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x808002C4: jr          $ra
    // 0x808002C8: addiu       $v0, $v0, 0x7A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X7A4));
    return;
    // 0x808002C8: addiu       $v0, $v0, 0x7A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X7A4));
L_808002CC:
    // 0x808002CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3282, 0X7F8) << 16);
    // 0x808002D0: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x808002D4: jr          $ra
    // 0x808002D8: addiu       $v0, $v0, 0x7F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X7F8));
    return;
    // 0x808002D8: addiu       $v0, $v0, 0x7F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X7F8));
L_808002DC:
    // 0x808002DC: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x808002E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3282, 0X8A0) << 16);
    // 0x808002E4: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x808002E8: jr          $ra
    // 0x808002EC: addiu       $v0, $v0, 0x8A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X8A0));
    return;
    // 0x808002EC: addiu       $v0, $v0, 0x8A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X8A0));
L_808002F0:
    // 0x808002F0: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x808002F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3282, 0X8F4) << 16);
    // 0x808002F8: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x808002FC: jr          $ra
    // 0x80800300: addiu       $v0, $v0, 0x8F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X8F4));
    return;
    // 0x80800300: addiu       $v0, $v0, 0x8F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X8F4));
L_80800304:
    // 0x80800304: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80800308: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3282, 0X948) << 16);
    // 0x8080030C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80800310: jr          $ra
    // 0x80800314: addiu       $v0, $v0, 0x948
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X948));
    return;
    // 0x80800314: addiu       $v0, $v0, 0x948
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3282, 0X948));
L_80800318:
    // 0x80800318: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8080031C:
    // 0x8080031C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800320: jr          $ra
    // 0x80800324: nop

    return;
    // 0x80800324: nop

    // 0x80800328: nop

    // 0x8080032C: nop

;}
RECOMP_FUNC void func_800BDC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDC5C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BDC60: jr          $ra
    // 0x800BDC64: lh          $v0, -0x7BB4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X7BB4);
    return;
    // 0x800BDC64: lh          $v0, -0x7BB4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X7BB4);
;}
RECOMP_FUNC void func_8009EB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EB24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EB28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009EB2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009EB30: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8009EB34: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8009EB38: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EB3C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EB40: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8009EB44: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8009EB48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EB4C: addiu       $v1, $v1, 0x7040
    ctx->r3 = ADD32(ctx->r3, 0X7040);
    // 0x8009EB50: addiu       $v0, $v0, 0x704C
    ctx->r2 = ADD32(ctx->r2, 0X704C);
L_8009EB54:
    // 0x8009EB54: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x8009EB58: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8009EB5C: bne         $v0, $v1, L_8009EB54
    if (ctx->r2 != ctx->r3) {
        // 0x8009EB60: sw          $t0, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r8;
            goto L_8009EB54;
    }
    // 0x8009EB60: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
    // 0x8009EB64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EB68: addiu       $v0, $v0, 0x7040
    ctx->r2 = ADD32(ctx->r2, 0X7040);
    // 0x8009EB6C: lbu         $t1, 0x20($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X20);
    // 0x8009EB70: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8009EB74: jal         0x8009EC60
    // 0x8009EB78: sb          $t2, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r10;
    func_8009EC60(rdram, ctx);
        goto after_0;
    // 0x8009EB78: sb          $t2, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r10;
    after_0:
    // 0x8009EB7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EB80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EB84: jr          $ra
    // 0x8009EB88: nop

    return;
    // 0x8009EB88: nop

;}
RECOMP_FUNC void func_80800D18_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D18: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800D1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D20: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800D24: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800D28: addiu       $a1, $a2, 0x98
    ctx->r5 = ADD32(ctx->r6, 0X98);
    // 0x80800D2C: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800D30: bgez        $t8, L_80800DB8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800D34: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_80800DB8;
    }
    // 0x80800D34: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800D38: jal         0x800F2EA0
    // 0x80800D3C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_800F2EA0(rdram, ctx);
        goto after_0;
    // 0x80800D3C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800D40: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800D44: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80800D48: sb          $t9, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r25;
    // 0x80800D4C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80800D50: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800D54: jal         0x800EE7F8
    // 0x80800D58: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800D58: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800D5C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800D60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D64: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800D68: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800D6C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800D70: jal         0x800B53A4
    // 0x80800D74: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80800D74: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800D78: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1516, 0X1074) << 16);
    // 0x80800D7C: addiu       $t0, $t0, 0x1074
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1516, 0X1074));
    // 0x80800D80: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800D84: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800D88: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800D8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800D90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D94: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800D98: jal         0x800BABB8
    // 0x80800D9C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80800D9C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800DA0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800DA4: jal         0x800BAB60
    // 0x80800DA8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800BAB60(rdram, ctx);
        goto after_4;
    // 0x80800DA8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80800DAC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800DB0: jal         0x800BA22C
    // 0x80800DB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x80800DB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
L_80800DB8:
    // 0x80800DB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DBC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800DC0: jr          $ra
    // 0x80800DC4: nop

    return;
    // 0x80800DC4: nop

;}
RECOMP_FUNC void func_80801600_bstaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801600: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801604: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801608: sltiu       $at, $a1, 0x6
    ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
    // 0x8080160C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801610: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801614: beq         $at, $zero, L_80801758
    if (ctx->r1 == 0) {
        // 0x80801618: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_80801758;
    }
    // 0x80801618: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080161C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80801620: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X1F34) << 16);
    // 0x80801624: addu        $at, $at, $t6
    gpr jr_addend_8080162C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801628: lw          $t6, 0x1F34($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(392, 0X1F34));
    // 0x8080162C: jr          $t6
    // 0x80801630: nop

    switch (jr_addend_8080162C >> 2) {
        case 0: goto L_80801634; break;
        case 1: goto L_80801684; break;
        case 2: goto L_808016BC; break;
        case 3: goto L_80801700; break;
        case 4: goto L_8080172C; break;
        case 5: goto L_80801748; break;
        default: switch_error(__func__, 0x8080162C, 0x80801F34);
    }
    // 0x80801630: nop

L_80801634:
    // 0x80801634: jal         0x8008E0C8
    // 0x80801638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0C8(rdram, ctx);
        goto after_0;
    // 0x80801638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080163C: beq         $v0, $zero, L_8080164C
    if (ctx->r2 == 0) {
        // 0x80801640: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080164C;
    }
    // 0x80801640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801644: jal         0x80084788
    // 0x80801648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80801648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8080164C:
    // 0x8080164C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801650: jal         0x80095774
    // 0x80801654: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x80801654: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_2:
    // 0x80801658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080165C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801660: jal         0x8009E55C
    // 0x80801664: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_3;
    // 0x80801664: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
    // 0x80801668: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x8080166C: beql        $a0, $zero, L_8080175C
    if (ctx->r4 == 0) {
        // 0x80801670: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_8080175C;
    }
    goto skip_0;
    // 0x80801670: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80801674: jal         0x800FFA88
    // 0x80801678: nop

    func_800FFA88(rdram, ctx);
        goto after_4;
    // 0x80801678: nop

    after_4:
    // 0x8080167C: b           L_80801758
    // 0x80801680: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
        goto L_80801758;
    // 0x80801680: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
L_80801684:
    // 0x80801684: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801688: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x8080168C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801690: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801694: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80801698: jal         0x8009E55C
    // 0x8080169C: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    func_8009E55C(rdram, ctx);
        goto after_5;
    // 0x8080169C: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x808016A0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808016A4: addiu       $a2, $a2, 0x4518
    ctx->r6 = ADD32(ctx->r6, 0X4518);
    // 0x808016A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016AC: jal         0x8009E4E0
    // 0x808016B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E4E0(rdram, ctx);
        goto after_6;
    // 0x808016B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808016B4: b           L_8080175C
    // 0x808016B8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
        goto L_8080175C;
    // 0x808016B8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_808016BC:
    // 0x808016BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016C0: jal         0x80084780
    // 0x808016C4: lbu         $a1, 0x164($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X164);
    _bapackctrl_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x808016C4: lbu         $a1, 0x164($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X164);
    after_7:
    // 0x808016C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016CC: jal         0x80095774
    // 0x808016D0: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    baflag_clear(rdram, ctx);
        goto after_8;
    // 0x808016D0: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_8:
    // 0x808016D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808016DC: jal         0x80085338
    // 0x808016E0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_set(rdram, ctx);
        goto after_9;
    // 0x808016E0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_9:
    // 0x808016E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016E8: jal         0x8009C128
    // 0x808016EC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_10;
    // 0x808016EC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_10:
    // 0x808016F0: jal         0x8008A530
    // 0x808016F4: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    _subaddietaxi_entrypoint_7(rdram, ctx);
        goto after_11;
    // 0x808016F4: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    after_11:
    // 0x808016F8: b           L_8080175C
    // 0x808016FC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
        goto L_8080175C;
    // 0x808016FC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80801700:
    // 0x80801700: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80801704: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x80801708: addiu       $t7, $zero, 0x3E80
    ctx->r15 = ADD32(0, 0X3E80);
    // 0x8080170C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801710: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801714: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080171C: jal         0x8009DBB0
    // 0x80801720: addiu       $a1, $zero, 0x5AD
    ctx->r5 = ADD32(0, 0X5AD);
    func_8009DBB0(rdram, ctx);
        goto after_12;
    // 0x80801720: addiu       $a1, $zero, 0x5AD
    ctx->r5 = ADD32(0, 0X5AD);
    after_12:
    // 0x80801724: b           L_8080175C
    // 0x80801728: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
        goto L_8080175C;
    // 0x80801728: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_8080172C:
    // 0x8080172C: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    // 0x80801730: jal         0x800CB698
    // 0x80801734: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800CB698(rdram, ctx);
        goto after_13;
    // 0x80801734: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80801738: jal         0x800FFA88
    // 0x8080173C: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    func_800FFA88(rdram, ctx);
        goto after_14;
    // 0x8080173C: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    after_14:
    // 0x80801740: b           L_80801758
    // 0x80801744: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
        goto L_80801758;
    // 0x80801744: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
L_80801748:
    // 0x80801748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080174C: addiu       $a1, $zero, 0x126
    ctx->r5 = ADD32(0, 0X126);
    // 0x80801750: jal         0x8008CCBC
    // 0x80801754: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_15;
    // 0x80801754: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    after_15:
L_80801758:
    // 0x80801758: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_8080175C:
    // 0x8080175C: sb          $t8, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r24;
    // 0x80801760: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801764: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801768: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080176C: jr          $ra
    // 0x80801770: nop

    return;
    // 0x80801770: nop

;}
RECOMP_FUNC void chhandcart_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080438C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804394: jal         0x80106790
    // 0x80804398: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80804398: nop

    after_0:
    // 0x8080439C: jal         0x80101F24
    // 0x808043A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80101F24(rdram, ctx);
        goto after_1;
    // 0x808043A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808043A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808043A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808043AC: jr          $ra
    // 0x808043B0: nop

    return;
    // 0x808043B0: nop

;}
RECOMP_FUNC void sudialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080004C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800054: jal         0x800DA298
    // 0x80800058: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800058: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080005C: beq         $v0, $zero, L_8080006C
    if (ctx->r2 == 0) {
        // 0x80800060: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3290, 0XE0) << 16);
            goto L_8080006C;
    }
    // 0x80800060: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3290, 0XE0) << 16);
    // 0x80800064: b           L_808000D0
    // 0x80800068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000D0;
    // 0x80800068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080006C:
    // 0x8080006C: addiu       $a0, $a0, 0xE0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3290, 0XE0));
    // 0x80800070: jal         0x80800000
    // 0x80800074: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800000_sudialog(rdram, ctx);
        goto after_1;
    // 0x80800074: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800078: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080007C: beq         $v0, $at, L_808000CC
    if (ctx->r2 == ctx->r1) {
        // 0x80800080: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_808000CC;
    }
    // 0x80800080: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800084: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3290, 0XE2) << 16);
    // 0x80800088: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8080008C: lh          $a0, 0xE2($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(3290, 0XE2));
    // 0x80800090: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800098: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080009C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808000A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808000A4: jal         0x800C05B8
    // 0x808000A8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800C05B8(rdram, ctx);
        goto after_2;
    // 0x808000A8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
    // 0x808000AC: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x808000B0: nop
    
            goto L_808000BC;
    }
    // 0x808000B0: nop

    // 0x808000B4: jal         0x800DA544
    // 0x808000B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x808000B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
L_808000BC:
    // 0x808000BC: jal         0x800DA298
    // 0x808000C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808000C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808000C4: b           L_808000D4
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808000D4;
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000CC:
    // 0x808000CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000D0:
    // 0x808000D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000D4:
    // 0x808000D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void bsjig_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800164: jal         0x800F53D0
    // 0x80800168: nop

    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80800168: nop

    after_0:
    // 0x8080016C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800170: jal         0x800A32F8
    // 0x80800174: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A32F8(rdram, ctx);
        goto after_1;
    // 0x80800174: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800178: beql        $v0, $zero, L_808001A0
    if (ctx->r2 == 0) {
        // 0x8080017C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001A0;
    }
    goto skip_0;
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800180: jal         0x800A32F8
    // 0x80800184: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800A32F8(rdram, ctx);
        goto after_2;
    // 0x80800184: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800188: jal         0x80106790
    // 0x8080018C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x8080018C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800190: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800194: jal         0x800858B8
    // 0x80800198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chjigsawdance_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x8080019C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001A0:
    // 0x808001A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

;}
RECOMP_FUNC void func_80803928_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803928: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080392C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803930: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803934: jal         0x800E81D0
    // 0x80803938: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800E81D0(rdram, ctx);
        goto after_0;
    // 0x80803938: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080393C: beq         $v0, $zero, L_80803984
    if (ctx->r2 == 0) {
        // 0x80803940: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80803984;
    }
    // 0x80803940: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803944: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80803948: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x8080394C: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x80803950: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80803954: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80803958: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8080395C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80803960: jal         0x8002E330
    // 0x80803964: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80803964: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80803968: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8080396C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80803970: jal         0x80106790
    // 0x80803974: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80803974: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80803978: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080397C: jal         0x80101870
    // 0x80803980: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101870(rdram, ctx);
        goto after_3;
    // 0x80803980: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
L_80803984:
    // 0x80803984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803988: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080398C: jr          $ra
    // 0x80803990: nop

    return;
    // 0x80803990: nop

    // 0x80803994: nop

    // 0x80803998: nop

    // 0x8080399C: nop

;}
RECOMP_FUNC void func_8011329C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011329C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801132A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801132A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801132A8: jal         0x80110898
    // 0x801132AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80110898(rdram, ctx);
        goto after_0;
    // 0x801132AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x801132B0: jal         0x8010FFD0
    // 0x801132B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FFD0(rdram, ctx);
        goto after_1;
    // 0x801132B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801132B8: beq         $v0, $zero, L_801132C8
    if (ctx->r2 == 0) {
        // 0x801132BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801132C8;
    }
    // 0x801132BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801132C0: b           L_8011330C
    // 0x801132C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8011330C;
    // 0x801132C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801132C8:
    // 0x801132C8: jal         0x801107F0
    // 0x801132CC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_801107F0(rdram, ctx);
        goto after_2;
    // 0x801132CC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x801132D0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x801132D4: jal         0x800EE7F8
    // 0x801132D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x801132D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x801132DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801132E0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x801132E4: jal         0x80113688
    // 0x801132E8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_80113688(rdram, ctx);
        goto after_4;
    // 0x801132E8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x801132EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801132F0: jal         0x80110770
    // 0x801132F4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80110770(rdram, ctx);
        goto after_5;
    // 0x801132F4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x801132F8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x801132FC: jal         0x800EECE0
    // 0x80113300: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EECE0(rdram, ctx);
        goto after_6;
    // 0x80113300: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x80113304: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80113308: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8011330C:
    // 0x8011330C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80113310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80113314: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80113318: jr          $ra
    // 0x8011331C: nop

    return;
    // 0x8011331C: nop

;}
RECOMP_FUNC void _chlensflare_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087508: syscall     582
    recomp_syscall_handler(rdram, ctx, 0x80087508);
    return;
    // 0x8008750C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8002C5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C5F0: jr          $ra
    // 0x8002C5F4: nop

    return;
    // 0x8002C5F4: nop

;}
RECOMP_FUNC void mlspline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080051C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800520: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800524: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800528: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080052C: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x80800530: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800534: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800538: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080053C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800540: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800544: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80800548: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080054C: jal         0x800F0D50
    // 0x80800550: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_800F0D50(rdram, ctx);
        goto after_0;
    // 0x80800550: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800554: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800558: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8080055C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80800560: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80800564: nop

    // 0x80800568: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080056C: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800570: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80800574: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80800578: nop

    // 0x8080057C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800580: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800584: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80800588: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080058C: bne         $v0, $zero, L_80800644
    if (ctx->r2 != 0) {
        // 0x80800590: sub.s       $f20, $f2, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_80800644;
    }
    // 0x80800590: sub.s       $f20, $f2, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80800594: beq         $at, $zero, L_808008A4
    if (ctx->r1 == 0) {
        // 0x80800598: sll         $a0, $a1, 2
        ctx->r4 = S32(ctx->r5 << 2);
            goto L_808008A4;
    }
    // 0x80800598: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x8080059C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808005A0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808005A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3006, 0X1C50) << 16);
    // 0x808005A8: lwc1        $f18, 0x1C50($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3006, 0X1C50));
    // 0x808005AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808005B4: addu        $v1, $s0, $a0
    ctx->r3 = ADD32(ctx->r16, ctx->r4);
    // 0x808005B8: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
L_808005BC:
    // 0x808005BC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808005C0: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808005C4: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x808005C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808005CC: sub.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x808005D0: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x808005D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808005D8: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x808005DC: mul.s       $f14, $f6, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x808005E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808005E4: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x808005E8: sub.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x808005EC: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808005F0: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x808005F4: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x808005F8: lwc1        $f10, -0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808005FC: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800600: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800604: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800608: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x8080060C: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80800610: lwc1        $f10, -0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800614: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800618: nop

    // 0x8080061C: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80800620: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800624: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800628: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8080062C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800630: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80800634: bne         $at, $zero, L_808005BC
    if (ctx->r1 != 0) {
        // 0x80800638: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_808005BC;
    }
    // 0x80800638: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8080063C: b           L_808008A8
    // 0x80800640: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808008A8;
    // 0x80800640: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800644:
    // 0x80800644: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80800648: addiu       $t0, $a1, 0x2
    ctx->r8 = ADD32(ctx->r5, 0X2);
    // 0x8080064C: bne         $v1, $t0, L_8080067C
    if (ctx->r3 != ctx->r8) {
        // 0x80800650: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8080067C;
    }
    // 0x80800650: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800654: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800658: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080065C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800660: mflo        $t1
    ctx->r9 = lo;
    // 0x80800664: addiu       $t2, $t1, -0x3
    ctx->r10 = ADD32(ctx->r9, -0X3);
    // 0x80800668: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8080066C: jal         0x800EE7F8
    // 0x80800670: addu        $a1, $s0, $t3
    ctx->r5 = ADD32(ctx->r16, ctx->r11);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800670: addu        $a1, $s0, $t3
    ctx->r5 = ADD32(ctx->r16, ctx->r11);
    after_1:
    // 0x80800674: b           L_808008A8
    // 0x80800678: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808008A8;
    // 0x80800678: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8080067C:
    // 0x8080067C: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800680: addiu       $t6, $a1, 0x3
    ctx->r14 = ADD32(ctx->r5, 0X3);
    // 0x80800684: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080068C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80800690: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3006, 0X1C5C) << 16);
    // 0x80800694: mflo        $t4
    ctx->r12 = lo;
    // 0x80800698: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8080069C: bne         $v1, $t6, L_808007EC
    if (ctx->r3 != ctx->r14) {
        // 0x808006A0: addu        $s0, $s0, $t5
        ctx->r16 = ADD32(ctx->r16, ctx->r13);
            goto L_808007EC;
    }
    // 0x808006A0: addu        $s0, $s0, $t5
    ctx->r16 = ADD32(ctx->r16, ctx->r13);
    // 0x808006A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3006, 0X1C54) << 16);
    // 0x808006A8: lwc1        $f24, 0x1C54($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3006, 0X1C54));
    // 0x808006AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3006, 0X1C58) << 16);
    // 0x808006B0: lwc1        $f18, 0x1C58($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3006, 0X1C58));
    // 0x808006B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808006B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808006BC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x808006C0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x808006C4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x808006C8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808006CC: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x808006D0: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808006D4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808006D8: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x808006DC: sub.s       $f2, $f14, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x808006E0: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x808006E4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808006E8: mul.s       $f22, $f2, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x808006EC: beq         $a0, $a1, L_80800784
    if (ctx->r4 == ctx->r5) {
        // 0x808006F0: nop
    
            goto L_80800784;
    }
    // 0x808006F0: nop

L_808006F4:
    // 0x808006F4: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x808006F8: add.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x808006FC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800700: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800704: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800708: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8080070C: sub.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x80800710: add.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800714: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80800718: nop

    // 0x8080071C: mul.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800720: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800724: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800728: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8080072C: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800730: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800734: add.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80800738: mul.s       $f6, $f14, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x8080073C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800740: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800744: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800748: add.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8080074C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800750: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800754: add.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800758: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8080075C: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800760: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800764: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800768: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8080076C: sub.s       $f2, $f14, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80800770: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80800774: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800778: mul.s       $f22, $f2, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8080077C: bne         $a0, $a1, L_808006F4
    if (ctx->r4 != ctx->r5) {
        // 0x80800780: nop
    
            goto L_808006F4;
    }
    // 0x80800780: nop

L_80800784:
    // 0x80800784: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80800788: add.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8080078C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800790: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800794: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800798: sub.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8080079C: add.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808007A0: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x808007A4: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x808007A8: mul.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x808007AC: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808007B0: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808007B4: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x808007B8: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808007BC: add.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x808007C0: mul.s       $f6, $f14, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x808007C4: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x808007C8: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808007CC: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808007D0: add.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x808007D4: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x808007D8: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808007DC: add.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808007E0: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x808007E4: b           L_808008A8
    // 0x808007E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808008A8;
    // 0x808007E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808007EC:
    // 0x808007EC: lwc1        $f24, 0x1C5C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3006, 0X1C5C));
    // 0x808007F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3006, 0X1C60) << 16);
    // 0x808007F4: lwc1        $f18, 0x1C60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3006, 0X1C60));
    // 0x808007F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808007FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800800: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80800804:
    // 0x80800804: lwc1        $f22, 0x0($v1)
    ctx->f22.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800808: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8080080C: lwc1        $f14, 0x18($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800810: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80800814: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800818: sub.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x8080081C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800820: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800824: sub.s       $f10, $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x80800828: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8080082C: add.s       $f6, $f22, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f22.fl + ctx->f14.fl;
    // 0x80800830: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800834: add.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800838: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8080083C: sub.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800840: mul.s       $f8, $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800844: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80800848: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080084C: add.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800850: sub.s       $f22, $f14, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f14.fl - ctx->f22.fl;
    // 0x80800854: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800858: lwc1        $f10, -0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8080085C: mul.s       $f22, $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x80800860: nop

    // 0x80800864: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80800868: nop

    // 0x8080086C: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800870: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800874: lwc1        $f10, -0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800878: add.s       $f22, $f10, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x8080087C: mul.s       $f16, $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80800880: swc1        $f22, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f22.u32l;
    // 0x80800884: lwc1        $f22, -0x4($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800888: mul.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8080088C: add.s       $f16, $f6, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80800890: swc1        $f22, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f22.u32l;
    // 0x80800894: lwc1        $f22, -0x4($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800898: add.s       $f16, $f22, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x8080089C: bne         $a1, $a2, L_80800804
    if (ctx->r5 != ctx->r6) {
        // 0x808008A0: swc1        $f16, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
            goto L_80800804;
    }
    // 0x808008A0: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
L_808008A4:
    // 0x808008A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808008A8:
    // 0x808008A8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808008AC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808008B0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808008B4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808008B8: jr          $ra
    // 0x808008BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808008BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bsvan_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012F8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808012FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(427, 0X1CEC) << 16);
    // 0x80801300: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801304: jr          $ra
    // 0x80801308: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CEC));
    return;
    // 0x80801308: lw          $v0, 0x1CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CEC));
;}
RECOMP_FUNC void func_801043A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801043A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801043A4: lw          $a0, 0x6E80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E80);
    // 0x801043A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801043AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801043B0: beql        $a0, $zero, L_801043CC
    if (ctx->r4 == 0) {
        // 0x801043B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801043CC;
    }
    goto skip_0;
    // 0x801043B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801043B8: jal         0x800B32E4
    // 0x801043BC: nop

    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x801043BC: nop

    after_0:
    // 0x801043C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801043C4: sw          $v0, 0x6E80($at)
    MEM_W(0X6E80, ctx->r1) = ctx->r2;
    // 0x801043C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801043CC:
    // 0x801043CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801043D0: jr          $ra
    // 0x801043D4: nop

    return;
    // 0x801043D4: nop

;}
RECOMP_FUNC void func_8011458C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011458C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80114590: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80114594: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80114598: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8011459C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x801145A0: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x801145A4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x801145A8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x801145AC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x801145B0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801145B4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801145B8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801145BC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801145C0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801145C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801145C8: jal         0x800BE444
    // 0x801145CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800BE444(rdram, ctx);
        goto after_0;
    // 0x801145CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801145D0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801145D4: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x801145D8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x801145DC: beq         $t6, $zero, L_80114714
    if (ctx->r14 == 0) {
        // 0x801145E0: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80114714;
    }
    // 0x801145E0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x801145E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801145E8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801145EC: lwc1        $f22, 0x65EC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X65EC);
    // 0x801145F0: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x801145F4: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
L_801145F8:
    // 0x801145F8: jal         0x800E9E88
    // 0x801145FC: nop

    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x801145FC: nop

    after_1:
    // 0x80114600: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80114604: jal         0x800E9EB4
    // 0x80114608: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x80114608: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    after_2:
    // 0x8011460C: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80114610: beq         $at, $zero, L_801146F8
    if (ctx->r1 == 0) {
        // 0x80114614: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_801146F8;
    }
    // 0x80114614: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80114618: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_8011461C:
    // 0x8011461C: sll         $t8, $v0, 27
    ctx->r24 = S32(ctx->r2 << 27);
    // 0x80114620: bgez        $t8, L_801146E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80114624: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_801146E8;
    }
    // 0x80114624: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80114628: beq         $t9, $zero, L_801146E8
    if (ctx->r25 == 0) {
        // 0x8011462C: sll         $t1, $v0, 28
        ctx->r9 = S32(ctx->r2 << 28);
            goto L_801146E8;
    }
    // 0x8011462C: sll         $t1, $v0, 28
    ctx->r9 = S32(ctx->r2 << 28);
    // 0x80114630: bltzl       $t1, L_801146EC
    if (SIGNED(ctx->r9) < 0) {
        // 0x80114634: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_801146EC;
    }
    goto skip_0;
    // 0x80114634: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_0:
    // 0x80114638: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8011463C: lhu         $t2, 0x18($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X18);
    // 0x80114640: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80114644: beql        $t3, $zero, L_801146EC
    if (ctx->r11 == 0) {
        // 0x80114648: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_801146EC;
    }
    goto skip_1;
    // 0x80114648: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x8011464C: lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X14);
    // 0x80114650: beql        $v0, $zero, L_801146EC
    if (ctx->r2 == 0) {
        // 0x80114654: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_801146EC;
    }
    goto skip_2;
    // 0x80114654: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x80114658: beql        $s5, $v0, L_801146EC
    if (ctx->r21 == ctx->r2) {
        // 0x8011465C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_801146EC;
    }
    goto skip_3;
    // 0x8011465C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_3:
    // 0x80114660: jal         0x80106790
    // 0x80114664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80114664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80114668: lw          $t4, 0x94($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X94);
    // 0x8011466C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80114670: sll         $t6, $t4, 17
    ctx->r14 = S32(ctx->r12 << 17);
    // 0x80114674: bgezl       $t6, L_801146EC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80114678: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_801146EC;
    }
    goto skip_4;
    // 0x80114678: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_4:
    // 0x8011467C: lw          $t7, 0x64($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X64);
    // 0x80114680: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x80114684: bltzl       $t9, L_801146EC
    if (SIGNED(ctx->r25) < 0) {
        // 0x80114688: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_801146EC;
    }
    goto skip_5;
    // 0x80114688: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_5:
    // 0x8011468C: jal         0x801072A8
    // 0x80114690: nop

    func_801072A8(rdram, ctx);
        goto after_4;
    // 0x80114690: nop

    after_4:
    // 0x80114694: bne         $v0, $zero, L_801146E8
    if (ctx->r2 != 0) {
        // 0x80114698: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801146E8;
    }
    // 0x80114698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011469C: jal         0x800EC75C
    // 0x801146A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EC75C(rdram, ctx);
        goto after_5;
    // 0x801146A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x801146A4: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x801146A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801146AC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801146B0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x801146B4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801146B8: jal         0x801143A4
    // 0x801146BC: nop

    func_801143A4(rdram, ctx);
        goto after_6;
    // 0x801146BC: nop

    after_6:
    // 0x801146C0: beql        $v0, $zero, L_801146EC
    if (ctx->r2 == 0) {
        // 0x801146C4: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_801146EC;
    }
    goto skip_6;
    // 0x801146C4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_6:
    // 0x801146C8: lwc1        $f6, 0x0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X0);
    // 0x801146CC: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x801146D0: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x801146D4: nop

    // 0x801146D8: bc1fl       L_801146EC
    if (!c1cs) {
        // 0x801146DC: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_801146EC;
    }
    goto skip_7;
    // 0x801146DC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_7:
    // 0x801146E0: b           L_801146F8
    // 0x801146E4: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
        goto L_801146F8;
    // 0x801146E4: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
L_801146E8:
    // 0x801146E8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_801146EC:
    // 0x801146EC: sltu        $at, $s1, $s4
    ctx->r1 = ctx->r17 < ctx->r20 ? 1 : 0;
    // 0x801146F0: bnel        $at, $zero, L_8011461C
    if (ctx->r1 != 0) {
        // 0x801146F4: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_8011461C;
    }
    goto skip_8;
    // 0x801146F4: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_8:
L_801146F8:
    // 0x801146F8: sltu        $at, $s1, $s4
    ctx->r1 = ctx->r17 < ctx->r20 ? 1 : 0;
    // 0x801146FC: bne         $at, $zero, L_80114714
    if (ctx->r1 != 0) {
        // 0x80114700: nop
    
            goto L_80114714;
    }
    // 0x80114700: nop

    // 0x80114704: lw          $a0, 0x4($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X4);
    // 0x80114708: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8011470C: bne         $a0, $zero, L_801145F8
    if (ctx->r4 != 0) {
        // 0x80114710: nop
    
            goto L_801145F8;
    }
    // 0x80114710: nop

L_80114714:
    // 0x80114714: beq         $s7, $zero, L_8011473C
    if (ctx->r23 == 0) {
        // 0x80114718: or          $v0, $s7, $zero
        ctx->r2 = ctx->r23 | 0;
            goto L_8011473C;
    }
    // 0x80114718: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x8011471C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80114720: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80114724: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80114728: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8011472C: nop

    // 0x80114730: bc1fl       L_80114740
    if (!c1cs) {
        // 0x80114734: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80114740;
    }
    goto skip_9;
    // 0x80114734: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_9:
    // 0x80114738: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
L_8011473C:
    // 0x8011473C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80114740:
    // 0x80114740: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80114744: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80114748: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8011474C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80114750: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80114754: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80114758: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8011475C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80114760: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80114764: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80114768: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8011476C: jr          $ra
    // 0x80114770: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80114770: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void bainput_should_enter_first_person(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097AD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097ADC: jal         0x80091A58
    // 0x80097AE0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097AE0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80097AE4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097AE8: beq         $t6, $zero, L_80097B18
    if (ctx->r14 == 0) {
        // 0x80097AEC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097B18;
    }
    // 0x80097AEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097AF0: jal         0x8008D9A4
    // 0x80097AF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D9A4(rdram, ctx);
        goto after_1;
    // 0x80097AF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80097AF8: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097AFC: beq         $t7, $zero, L_80097B18
    if (ctx->r15 == 0) {
        // 0x80097B00: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80097B18;
    }
    // 0x80097B00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80097B04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80097B08: jal         0x80098024
    // 0x80097B0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bainput_isEnabled(rdram, ctx);
        goto after_2;
    // 0x80097B0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80097B10: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097B14: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80097B18:
    // 0x80097B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097B20: jr          $ra
    // 0x80097B24: nop

    return;
    // 0x80097B24: nop

;}
RECOMP_FUNC void func_8080078C_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800790: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800794: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800798: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080079C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808007A0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808007A4: jal         0x80100094
    // 0x808007A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007AC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808007B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808007B4: slti        $at, $a3, 0xCED
    ctx->r1 = SIGNED(ctx->r7) < 0XCED ? 1 : 0;
    // 0x808007B8: bne         $at, $zero, L_808007E0
    if (ctx->r1 != 0) {
        // 0x808007BC: addiu       $t6, $a3, -0x17F2
        ctx->r14 = ADD32(ctx->r7, -0X17F2);
            goto L_808007E0;
    }
    // 0x808007BC: addiu       $t6, $a3, -0x17F2
    ctx->r14 = ADD32(ctx->r7, -0X17F2);
    // 0x808007C0: sltiu       $at, $t6, 0x29
    ctx->r1 = ctx->r14 < 0X29 ? 1 : 0;
    // 0x808007C4: beq         $at, $zero, L_808009B0
    if (ctx->r1 == 0) {
        // 0x808007C8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808009B0;
    }
    // 0x808007C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808007CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1D88) << 16);
    // 0x808007D0: addu        $at, $at, $t6
    gpr jr_addend_808007D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808007D4: lw          $t6, 0x1D88($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1D88));
    // 0x808007D8: jr          $t6
    // 0x808007DC: nop

    switch (jr_addend_808007D8 >> 2) {
        case 0: goto L_808007FC; break;
        case 1: goto L_80800880; break;
        case 2: goto L_808009B0; break;
        case 3: goto L_808009B0; break;
        case 4: goto L_808009B0; break;
        case 5: goto L_80800990; break;
        case 6: goto L_808009B0; break;
        case 7: goto L_808009B0; break;
        case 8: goto L_80800958; break;
        case 9: goto L_808009B0; break;
        case 10: goto L_808009B0; break;
        case 11: goto L_808009B0; break;
        case 12: goto L_808009B0; break;
        case 13: goto L_808009B0; break;
        case 14: goto L_808009B0; break;
        case 15: goto L_808009B0; break;
        case 16: goto L_808009B0; break;
        case 17: goto L_808009B0; break;
        case 18: goto L_808009B0; break;
        case 19: goto L_808009B0; break;
        case 20: goto L_808009B0; break;
        case 21: goto L_80800990; break;
        case 22: goto L_80800990; break;
        case 23: goto L_80800990; break;
        case 24: goto L_808009B0; break;
        case 25: goto L_808009B0; break;
        case 26: goto L_808009B0; break;
        case 27: goto L_808009B0; break;
        case 28: goto L_808009B0; break;
        case 29: goto L_808009B0; break;
        case 30: goto L_808009B0; break;
        case 31: goto L_808009B0; break;
        case 32: goto L_808009B0; break;
        case 33: goto L_808009B0; break;
        case 34: goto L_808009B0; break;
        case 35: goto L_808009B0; break;
        case 36: goto L_808009B0; break;
        case 37: goto L_808009B0; break;
        case 38: goto L_808009B0; break;
        case 39: goto L_808009B0; break;
        case 40: goto L_808007FC; break;
        default: switch_error(__func__, 0x808007D8, 0x80801D88);
    }
    // 0x808007DC: nop

L_808007E0:
    // 0x808007E0: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x808007E4: beq         $a3, $at, L_808008C0
    if (ctx->r7 == ctx->r1) {
        // 0x808007E8: addiu       $at, $zero, 0xCEC
        ctx->r1 = ADD32(0, 0XCEC);
            goto L_808008C0;
    }
    // 0x808007E8: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x808007EC: beq         $a3, $at, L_80800948
    if (ctx->r7 == ctx->r1) {
        // 0x808007F0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800948;
    }
    // 0x808007F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007F4: b           L_808009B4
    // 0x808007F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B4;
    // 0x808007F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007FC:
    // 0x808007FC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800800: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800804: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800808: blez        $t7, L_8080085C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8080080C: addiu       $a2, $zero, 0x7
        ctx->r6 = ADD32(0, 0X7);
            goto L_8080085C;
    }
    // 0x8080080C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800810: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800814: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    // 0x80800818: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080081C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800820: jal         0x8008A2D0
    // 0x80800824: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800824: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80800828: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8080082C: addiu       $t9, $zero, 0xB3
    ctx->r25 = ADD32(0, 0XB3);
    // 0x80800830: addiu       $a1, $zero, 0x17F3
    ctx->r5 = ADD32(0, 0X17F3);
    // 0x80800834: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800838: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080083C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800840: jal         0x8008A208
    // 0x80800844: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800844: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80800848: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080084C: jal         0x80108B04
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800854: b           L_80800870
    // 0x80800858: nop

        goto L_80800870;
    // 0x80800858: nop

L_8080085C:
    // 0x8080085C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80800860: addiu       $t1, $zero, 0xB3
    ctx->r9 = ADD32(0, 0XB3);
    // 0x80800864: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800868: jal         0x8008A208
    // 0x8080086C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080086C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_80800870:
    // 0x80800870: jal         0x80088178
    // 0x80800874: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800874: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    after_5:
    // 0x80800878: b           L_808009B4
    // 0x8080087C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B4;
    // 0x8080087C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800880:
    // 0x80800880: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800884: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    // 0x80800888: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8080088C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800890: jal         0x8008A2C8
    // 0x80800894: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800894: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80800898: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8080089C: addiu       $t3, $zero, 0xB3
    ctx->r11 = ADD32(0, 0XB3);
    // 0x808008A0: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x808008A4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x808008A8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808008AC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808008B0: jal         0x8008A208
    // 0x808008B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808008B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x808008B8: b           L_808009B4
    // 0x808008BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B4;
    // 0x808008BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008C0:
    // 0x808008C0: jal         0x800F54E4
    // 0x808008C4: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x808008C4: nop

    after_8:
    // 0x808008C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008CC: jal         0x800F82D4
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_9;
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808008D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008D8: jal         0x80101FDC
    // 0x808008DC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x808008DC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x808008E0: jal         0x800D395C
    // 0x808008E4: nop

    func_800D395C(rdram, ctx);
        goto after_11;
    // 0x808008E4: nop

    after_11:
    // 0x808008E8: beq         $v0, $zero, L_8080091C
    if (ctx->r2 == 0) {
        // 0x808008EC: lw          $t5, 0x28($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X28);
            goto L_8080091C;
    }
    // 0x808008EC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x808008F0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x808008F4: blez        $t4, L_8080090C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x808008F8: nop
    
            goto L_8080090C;
    }
    // 0x808008F8: nop

    // 0x808008FC: jal         0x80088188
    // 0x80800900: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80800900: nop

    after_12:
    // 0x80800904: b           L_808009B4
    // 0x80800908: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B4;
    // 0x80800908: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080090C:
    // 0x8080090C: jal         0x80088180
    // 0x80800910: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_13;
    // 0x80800910: nop

    after_13:
    // 0x80800914: b           L_808009B4
    // 0x80800918: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B4;
    // 0x80800918: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080091C:
    // 0x8080091C: blez        $t5, L_80800938
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80800920: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800938;
    }
    // 0x80800920: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800924: addiu       $a0, $zero, 0x123
    ctx->r4 = ADD32(0, 0X123);
    // 0x80800928: jal         0x80087A58
    // 0x8080092C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x8080092C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800930: b           L_808009B4
    // 0x80800934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B4;
    // 0x80800934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800938:
    // 0x80800938: jal         0x80108BD4
    // 0x8080093C: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    func_80108BD4(rdram, ctx);
        goto after_15;
    // 0x8080093C: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    after_15:
    // 0x80800940: b           L_808009B4
    // 0x80800944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B4;
    // 0x80800944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800948:
    // 0x80800948: jal         0x80108BD4
    // 0x8080094C: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    func_80108BD4(rdram, ctx);
        goto after_16;
    // 0x8080094C: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    after_16:
    // 0x80800950: b           L_808009B4
    // 0x80800954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B4;
    // 0x80800954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800958:
    // 0x80800958: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080095C: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    // 0x80800960: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800964: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800968: jal         0x8008A2D0
    // 0x8080096C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_17;
    // 0x8080096C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_17:
    // 0x80800970: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80800974: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800978: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080097C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800980: jal         0x800D1000
    // 0x80800984: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_18;
    // 0x80800984: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_18:
    // 0x80800988: b           L_808009B4
    // 0x8080098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B4;
    // 0x8080098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800990:
    // 0x80800990: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800994: addiu       $t7, $zero, 0xB3
    ctx->r15 = ADD32(0, 0XB3);
    // 0x80800998: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x8080099C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x808009A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808009A4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x808009A8: jal         0x8008A208
    // 0x808009AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_19;
    // 0x808009AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_19:
L_808009B0:
    // 0x808009B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009B4:
    // 0x808009B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009B8: jr          $ra
    // 0x808009BC: nop

    return;
    // 0x808009BC: nop

;}
RECOMP_FUNC void _bskazjump_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083498: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083498);
    return;
    // 0x8008349C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _rtlight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890A0: syscall     760
    recomp_syscall_handler(rdram, ctx, 0x800890A0);
    return;
    // 0x800890A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sujiggy_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6C8: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6C8);
    return;
    // 0x8008A6CC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855F8: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855F8);
    return;
    // 0x800855FC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _sumumbofx_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089888: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089888);
    return;
    // 0x8008988C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
