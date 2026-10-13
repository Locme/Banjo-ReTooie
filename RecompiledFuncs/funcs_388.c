#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsstonehead_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C30: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C30);
    return;
    // 0x80083C34: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _suspline_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DD0: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DD0);
    return;
    // 0x80089DD4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void bsstatue_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080039C: jal         0x808000C0
    // 0x808003A0: lui         $a1, 0x4296
    ctx->r5 = S32(0X4296 << 16);
    func_808000C0_bsstatue(rdram, ctx);
        goto after_0;
    // 0x808003A0: lui         $a1, 0x4296
    ctx->r5 = S32(0X4296 << 16);
    after_0:
    // 0x808003A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003AC: jr          $ra
    // 0x808003B0: nop

    return;
    // 0x808003B0: nop

;}
RECOMP_FUNC void func_801065E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801065E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801065E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801065E8: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    // 0x801065EC: jal         0x800B2D70
    // 0x801065F0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    vector_new(rdram, ctx);
        goto after_0;
    // 0x801065F0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x801065F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801065F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801065FC: sw          $v0, 0x6EE0($at)
    MEM_W(0X6EE0, ctx->r1) = ctx->r2;
    // 0x80106600: jr          $ra
    // 0x80106604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _badrone_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848B8: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848B8);
    return;
    // 0x800848BC: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void func_80800108_chdinoswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080010C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800110: jal         0x800EA05C
    // 0x80800114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800118: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1048, 0XB44) << 16);
    // 0x8080011C: lhu         $t6, 0xB44($t6)
    ctx->r14 = MEM_HU(ctx->r14, (int16_t)RELOC_LO16(1048, 0XB44));
    // 0x80800120: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800124: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1048, 0XB34) << 16);
    // 0x80800128: bne         $v0, $t6, L_8080014C
    if (ctx->r2 != ctx->r14) {
        // 0x8080012C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080014C;
    }
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800130: lhu         $t7, 0x76($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X76);
    // 0x80800134: lhu         $t9, 0xB34($t9)
    ctx->r25 = MEM_HU(ctx->r25, (int16_t)RELOC_LO16(1048, 0XB34));
    // 0x80800138: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x8080013C: bne         $t8, $t9, L_8080014C
    if (ctx->r24 != ctx->r25) {
        // 0x80800140: nop
    
            goto L_8080014C;
    }
    // 0x80800140: nop

    // 0x80800144: b           L_80800268
    // 0x80800148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800268;
    // 0x80800148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080014C:
    // 0x8080014C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1048, 0XB58) << 16);
    // 0x80800150: lhu         $t0, 0xB58($t0)
    ctx->r8 = MEM_HU(ctx->r8, (int16_t)RELOC_LO16(1048, 0XB58));
    // 0x80800154: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1048, 0XB48) << 16);
    // 0x80800158: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(1048, 0XB6C) << 16);
    // 0x8080015C: bne         $v0, $t0, L_80800180
    if (ctx->r2 != ctx->r8) {
        // 0x80800160: nop
    
            goto L_80800180;
    }
    // 0x80800160: nop

    // 0x80800164: lhu         $t1, 0x76($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X76);
    // 0x80800168: lhu         $t3, 0xB48($t3)
    ctx->r11 = MEM_HU(ctx->r11, (int16_t)RELOC_LO16(1048, 0XB48));
    // 0x8080016C: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x80800170: bne         $t2, $t3, L_80800180
    if (ctx->r10 != ctx->r11) {
        // 0x80800174: nop
    
            goto L_80800180;
    }
    // 0x80800174: nop

    // 0x80800178: b           L_80800268
    // 0x8080017C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800268;
    // 0x8080017C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800180:
    // 0x80800180: lhu         $t4, 0xB6C($t4)
    ctx->r12 = MEM_HU(ctx->r12, (int16_t)RELOC_LO16(1048, 0XB6C));
    // 0x80800184: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1048, 0XB5C) << 16);
    // 0x80800188: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8080018C: bne         $v0, $t4, L_808001B0
    if (ctx->r2 != ctx->r12) {
        // 0x80800190: lui         $v1, 0x8080
        ctx->r3 = S32(RELOC_HI16(1048, 0XB70) << 16);
            goto L_808001B0;
    }
    // 0x80800190: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1048, 0XB70) << 16);
    // 0x80800194: lhu         $t5, 0x76($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X76);
    // 0x80800198: lhu         $t7, 0xB5C($t7)
    ctx->r15 = MEM_HU(ctx->r15, (int16_t)RELOC_LO16(1048, 0XB5C));
    // 0x8080019C: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x808001A0: bne         $t6, $t7, L_808001B0
    if (ctx->r14 != ctx->r15) {
        // 0x808001A4: nop
    
            goto L_808001B0;
    }
    // 0x808001A4: nop

    // 0x808001A8: b           L_80800268
    // 0x808001AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800268;
    // 0x808001AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808001B0:
    // 0x808001B0: addiu       $v1, $v1, 0xB70
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1048, 0XB70));
    // 0x808001B4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
L_808001B8:
    // 0x808001B8: lhu         $t8, 0x10($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X10);
    // 0x808001BC: bnel        $v0, $t8, L_808001E4
    if (ctx->r2 != ctx->r24) {
        // 0x808001C0: lhu         $t2, 0x24($v1)
        ctx->r10 = MEM_HU(ctx->r3, 0X24);
            goto L_808001E4;
    }
    goto skip_0;
    // 0x808001C0: lhu         $t2, 0x24($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X24);
    skip_0:
    // 0x808001C4: lhu         $t9, 0x76($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X76);
    // 0x808001C8: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x808001CC: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x808001D0: bnel        $t0, $t1, L_808001E4
    if (ctx->r8 != ctx->r9) {
        // 0x808001D4: lhu         $t2, 0x24($v1)
        ctx->r10 = MEM_HU(ctx->r3, 0X24);
            goto L_808001E4;
    }
    goto skip_1;
    // 0x808001D4: lhu         $t2, 0x24($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X24);
    skip_1:
    // 0x808001D8: b           L_80800268
    // 0x808001DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80800268;
    // 0x808001DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x808001E0: lhu         $t2, 0x24($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X24);
L_808001E4:
    // 0x808001E4: bnel        $v0, $t2, L_8080020C
    if (ctx->r2 != ctx->r10) {
        // 0x808001E8: lhu         $t6, 0x38($v1)
        ctx->r14 = MEM_HU(ctx->r3, 0X38);
            goto L_8080020C;
    }
    goto skip_2;
    // 0x808001E8: lhu         $t6, 0x38($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X38);
    skip_2:
    // 0x808001EC: lhu         $t3, 0x76($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X76);
    // 0x808001F0: lhu         $t5, 0x14($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X14);
    // 0x808001F4: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x808001F8: bnel        $t4, $t5, L_8080020C
    if (ctx->r12 != ctx->r13) {
        // 0x808001FC: lhu         $t6, 0x38($v1)
        ctx->r14 = MEM_HU(ctx->r3, 0X38);
            goto L_8080020C;
    }
    goto skip_3;
    // 0x808001FC: lhu         $t6, 0x38($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X38);
    skip_3:
    // 0x80800200: b           L_80800268
    // 0x80800204: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_80800268;
    // 0x80800204: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80800208: lhu         $t6, 0x38($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X38);
L_8080020C:
    // 0x8080020C: bnel        $v0, $t6, L_80800234
    if (ctx->r2 != ctx->r14) {
        // 0x80800210: lhu         $t0, 0x4C($v1)
        ctx->r8 = MEM_HU(ctx->r3, 0X4C);
            goto L_80800234;
    }
    goto skip_4;
    // 0x80800210: lhu         $t0, 0x4C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4C);
    skip_4:
    // 0x80800214: lhu         $t7, 0x76($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X76);
    // 0x80800218: lhu         $t9, 0x28($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X28);
    // 0x8080021C: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80800220: bnel        $t8, $t9, L_80800234
    if (ctx->r24 != ctx->r25) {
        // 0x80800224: lhu         $t0, 0x4C($v1)
        ctx->r8 = MEM_HU(ctx->r3, 0X4C);
            goto L_80800234;
    }
    goto skip_5;
    // 0x80800224: lhu         $t0, 0x4C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4C);
    skip_5:
    // 0x80800228: b           L_80800268
    // 0x8080022C: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
        goto L_80800268;
    // 0x8080022C: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x80800230: lhu         $t0, 0x4C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4C);
L_80800234:
    // 0x80800234: bnel        $v0, $t0, L_8080025C
    if (ctx->r2 != ctx->r8) {
        // 0x80800238: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8080025C;
    }
    goto skip_6;
    // 0x80800238: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    skip_6:
    // 0x8080023C: lhu         $t1, 0x76($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X76);
    // 0x80800240: lhu         $t3, 0x3C($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X3C);
    // 0x80800244: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x80800248: bnel        $t2, $t3, L_8080025C
    if (ctx->r10 != ctx->r11) {
        // 0x8080024C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8080025C;
    }
    goto skip_7;
    // 0x8080024C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    skip_7:
    // 0x80800250: b           L_80800268
    // 0x80800254: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
        goto L_80800268;
    // 0x80800254: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
    // 0x80800258: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8080025C:
    // 0x8080025C: bne         $a0, $a2, L_808001B8
    if (ctx->r4 != ctx->r6) {
        // 0x80800260: addiu       $v1, $v1, 0x50
        ctx->r3 = ADD32(ctx->r3, 0X50);
            goto L_808001B8;
    }
    // 0x80800260: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // 0x80800264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800268:
    // 0x80800268: jr          $ra
    // 0x8080026C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080026C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800540_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800544: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800548: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080054C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800550: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x80800554: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80800558: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1732, 0X4790) << 16);
    // 0x8080055C: srl         $t9, $v1, 7
    ctx->r25 = S32(U32(ctx->r3) >> 7);
    // 0x80800560: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80800564: addiu       $t1, $t1, 0x4790
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1732, 0X4790));
    // 0x80800568: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x8080056C: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    // 0x80800570: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80800574: lw          $t2, -0x630($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X630);
    // 0x80800578: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080057C: lh          $a1, -0x63C($v0)
    ctx->r5 = MEM_H(ctx->r2, -0X63C);
    // 0x80800580: jal         0x800859B0
    // 0x80800584: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    _chanim_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800584: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x80800588: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080058C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800590: jal         0x80100074
    // 0x80800594: addiu       $a2, $zero, 0x10C
    ctx->r6 = ADD32(0, 0X10C);
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x80800594: addiu       $a2, $zero, 0x10C
    ctx->r6 = ADD32(0, 0X10C);
    after_1:
    // 0x80800598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080059C: jal         0x80100094
    // 0x808005A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808005A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808005A4: jal         0x80082648
    // 0x808005A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    _anseq_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808005A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_3:
    // 0x808005AC: sh          $v0, 0xC0($s0)
    MEM_H(0XC0, ctx->r16) = ctx->r2;
    // 0x808005B0: sw          $zero, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = 0;
    // 0x808005B4: jal         0x80800484
    // 0x808005B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800484_chintrochar(rdram, ctx);
        goto after_4;
    // 0x808005B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x808005BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005C0: jal         0x80105BE0
    // 0x808005C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80105BE0(rdram, ctx);
        goto after_5;
    // 0x808005C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808005C8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808005CC: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x808005D0: beql        $t3, $zero, L_808005F0
    if (ctx->r11 == 0) {
        // 0x808005D4: sh          $zero, 0xC2($s0)
        MEM_H(0XC2, ctx->r16) = 0;
            goto L_808005F0;
    }
    goto skip_0;
    // 0x808005D4: sh          $zero, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = 0;
    skip_0:
    // 0x808005D8: jal         0x800857B0
    // 0x808005DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _chblink_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808005DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x808005E0: sh          $v0, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r2;
    // 0x808005E4: b           L_808005F0
    // 0x808005E8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_808005F0;
    // 0x808005E8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808005EC: sh          $zero, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = 0;
L_808005F0:
    // 0x808005F0: andi        $t4, $v0, 0x400
    ctx->r12 = ctx->r2 & 0X400;
    // 0x808005F4: beq         $t4, $zero, L_8080060C
    if (ctx->r12 == 0) {
        // 0x808005F8: andi        $t5, $v0, 0x4000
        ctx->r13 = ctx->r2 & 0X4000;
            goto L_8080060C;
    }
    // 0x808005F8: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
    // 0x808005FC: jal         0x800857B0
    // 0x80800600: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chblink_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800600: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80800604: b           L_80800628
    // 0x80800608: sh          $v0, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = ctx->r2;
        goto L_80800628;
    // 0x80800608: sh          $v0, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = ctx->r2;
L_8080060C:
    // 0x8080060C: beql        $t5, $zero, L_80800628
    if (ctx->r13 == 0) {
        // 0x80800610: sh          $zero, 0xC4($s0)
        MEM_H(0XC4, ctx->r16) = 0;
            goto L_80800628;
    }
    goto skip_1;
    // 0x80800610: sh          $zero, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = 0;
    skip_1:
    // 0x80800614: jal         0x800857B0
    // 0x80800618: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _chblink_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800618: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x8080061C: b           L_80800628
    // 0x80800620: sh          $v0, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = ctx->r2;
        goto L_80800628;
    // 0x80800620: sh          $v0, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = ctx->r2;
    // 0x80800624: sh          $zero, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = 0;
L_80800628:
    // 0x80800628: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080062C: jal         0x80108B04
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_9;
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800638: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080063C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800640: jr          $ra
    // 0x80800644: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800644: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800CA3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA3A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA3A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CA3AC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800CA3B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CA3B4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CA3B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CA3BC: lw          $a2, 0x1C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X1C);
    // 0x800CA3C0: lw          $a1, 0x18($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X18);
    // 0x800CA3C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800CA3C8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800CA3CC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800CA3D0: jal         0x800EF4E4
    // 0x800CA3D4: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_0;
    // 0x800CA3D4: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800CA3D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800CA3DC: jal         0x800EF04C
    // 0x800CA3E0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x800CA3E0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800CA3E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA3E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA3EC: jr          $ra
    // 0x800CA3F0: nop

    return;
    // 0x800CA3F0: nop

;}
RECOMP_FUNC void bssnowball_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D9C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800DA0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(356, 0X10C4) << 16);
    // 0x80800DA4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800DA8: jr          $ra
    // 0x80800DAC: lw          $v0, 0x10C4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X10C4));
    return;
    // 0x80800DAC: lw          $v0, 0x10C4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X10C4));
;}
RECOMP_FUNC void func_8008EE04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EE04: beq         $a0, $zero, L_8008EE14
    if (ctx->r4 == 0) {
        // 0x8008EE08: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008EE14;
    }
    // 0x8008EE08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008EE0C: jr          $ra
    // 0x8008EE10: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x8008EE10: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8008EE14:
    // 0x8008EE14: jr          $ra
    // 0x8008EE18: nop

    return;
    // 0x8008EE18: nop

;}
RECOMP_FUNC void func_80801424_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080142C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801430: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801434: jal         0x80088B30
    // 0x80801438: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _fxdialog_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801438: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080143C: lh          $a0, 0x1AE($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1AE);
    // 0x80801440: jal         0x80088B38
    // 0x80801444: lh          $a1, 0x1B0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1B0);
    _fxdialog_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801444: lh          $a1, 0x1B0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1B0);
    after_1:
    // 0x80801448: jal         0x80088B40
    // 0x8080144C: lwc1        $f12, 0x1DC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1DC);
    _fxdialog_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080144C: lwc1        $f12, 0x1DC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1DC);
    after_2:
    // 0x80801450: lbu         $t6, 0x1E4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E4);
    // 0x80801454: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x80801458: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080145C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80801460: beq         $t7, $zero, L_80801470
    if (ctx->r15 == 0) {
        // 0x80801464: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80801470;
    }
    // 0x80801464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801468: b           L_80801470
    // 0x8080146C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_80801470;
    // 0x8080146C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80801470:
    // 0x80801470: lwc1        $f6, 0x1DC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1DC);
    // 0x80801474: lwc1        $f10, 0x1EC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1EC);
    // 0x80801478: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080147C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801480: lh          $a3, 0x1BC($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X1BC);
    // 0x80801484: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80801488: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080148C: jal         0x80088B48
    // 0x80801490: nop

    _fxdialog_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80801490: nop

    after_3:
    // 0x80801494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801498: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080149C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808014A0: jr          $ra
    // 0x808014A4: nop

    return;
    // 0x808014A4: nop

;}
RECOMP_FUNC void func_808005F0_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0X1000) << 16);
    // 0x808005FC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(940, 0X100C) << 16);
    // 0x80800600: addiu       $a3, $a3, 0x100C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(940, 0X100C));
    // 0x80800604: addiu       $a2, $a2, 0x1000
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0X1000));
    // 0x80800608: jal         0x80089D28
    // 0x8080060C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080060C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800618: jr          $ra
    // 0x8080061C: nop

    return;
    // 0x8080061C: nop

;}
RECOMP_FUNC void func_80804878_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080487C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804880: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804884: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80804888: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x8080488C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80804890: beq         $t6, $zero, L_808048E0
    if (ctx->r14 == 0) {
        // 0x80804894: nop
    
            goto L_808048E0;
    }
    // 0x80804894: nop

    // 0x80804898: jal         0x80804A38
    // 0x8080489C: nop

    func_80804A38_chgameselect(rdram, ctx);
        goto after_0;
    // 0x8080489C: nop

    after_0:
    // 0x808048A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808048A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808048A8: bne         $a0, $zero, L_808048C0
    if (ctx->r4 != 0) {
        // 0x808048AC: nop
    
            goto L_808048C0;
    }
    // 0x808048AC: nop

    // 0x808048B0: jal         0x800886F0
    // 0x808048B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _glglobalsettings_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808048B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808048B8: b           L_808048EC
    // 0x808048BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808048EC;
    // 0x808048BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808048C0:
    // 0x808048C0: jal         0x80804948
    // 0x808048C4: nop

    func_80804948_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808048C4: nop

    after_2:
    // 0x808048C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808048CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808048D0: jal         0x808049E8
    // 0x808048D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_808049E8_chgameselect(rdram, ctx);
        goto after_3;
    // 0x808048D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x808048D8: b           L_808048EC
    // 0x808048DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808048EC;
    // 0x808048DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808048E0:
    // 0x808048E0: jal         0x80802C7C
    // 0x808048E4: lw          $a0, 0x30($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X30);
    func_80802C7C_chgameselect(rdram, ctx);
        goto after_4;
    // 0x808048E4: lw          $a0, 0x30($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X30);
    after_4:
    // 0x808048E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808048EC:
    // 0x808048EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808048F0: jr          $ra
    // 0x808048F4: nop

    return;
    // 0x808048F4: nop

;}
RECOMP_FUNC void func_800B5B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5B0C: jal         0x800B5B88
    // 0x800B5B10: nop

    func_800B5B88(rdram, ctx);
        goto after_0;
    // 0x800B5B10: nop

    after_0:
    // 0x800B5B14: jal         0x800888D8
    // 0x800B5B18: nop

    _fxsparkle_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800B5B18: nop

    after_1:
    // 0x800B5B1C: jal         0x800B43E0
    // 0x800B5B20: nop

    func_800B43E0(rdram, ctx);
        goto after_2;
    // 0x800B5B20: nop

    after_2:
    // 0x800B5B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B5B2C: jr          $ra
    // 0x800B5B30: nop

    return;
    // 0x800B5B30: nop

    // 0x800B5B34: nop

    // 0x800B5B38: nop

    // 0x800B5B3C: nop

;}
RECOMP_FUNC void func_80114774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114774: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80114778: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8011477C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80114780: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80114784: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80114788: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8011478C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80114790: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80114794: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80114798: jal         0x800F0E00
    // 0x8011479C: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    func_800F0E00(rdram, ctx);
        goto after_0;
    // 0x8011479C: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    after_0:
    // 0x801147A0: lui         $t7, 0x82
    ctx->r15 = S32(0X82 << 16);
    // 0x801147A4: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x801147A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801147AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801147B0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x801147B4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x801147B8: jal         0x80114184
    // 0x801147BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80114184(rdram, ctx);
        goto after_1;
    // 0x801147BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x801147C0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x801147C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801147C8: beq         $v0, $at, L_80114808
    if (ctx->r2 == ctx->r1) {
        // 0x801147CC: lwc1        $f20, 0xC($t8)
        ctx->f20.u32l = MEM_W(ctx->r24, 0XC);
            goto L_80114808;
    }
    // 0x801147CC: lwc1        $f20, 0xC($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0XC);
    // 0x801147D0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801147D4: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x801147D8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801147DC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801147E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801147E4: lwc1        $f6, 0x65F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X65F0);
    // 0x801147E8: lwc1        $f4, 0x4C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4C);
    // 0x801147EC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801147F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801147F4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801147F8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x801147FC: jal         0x800F13F0
    // 0x80114800: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    func_800F13F0(rdram, ctx);
        goto after_2;
    // 0x80114800: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x80114804: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80114808:
    // 0x80114808: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8011480C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80114810: jal         0x8011447C
    // 0x80114814: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    func_8011447C(rdram, ctx);
        goto after_3;
    // 0x80114814: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80114818: beq         $v0, $zero, L_80114848
    if (ctx->r2 == 0) {
        // 0x8011481C: lwc1        $f14, 0x44($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80114848;
    }
    // 0x8011481C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80114820: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80114824: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80114828: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8011482C: nop

    // 0x80114830: bc1f        L_8011483C
    if (!c1cs) {
        // 0x80114834: nop
    
            goto L_8011483C;
    }
    // 0x80114834: nop

    // 0x80114838: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8011483C:
    // 0x8011483C: jal         0x800F13F0
    // 0x80114840: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    func_800F13F0(rdram, ctx);
        goto after_4;
    // 0x80114840: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x80114844: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80114848:
    // 0x80114848: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8011484C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80114850: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x80114854: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80114858: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8011485C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80114860: bc1f        L_80114884
    if (!c1cs) {
        // 0x80114864: nop
    
            goto L_80114884;
    }
    // 0x80114864: nop

    // 0x80114868: jal         0x8011458C
    // 0x8011486C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_8011458C(rdram, ctx);
        goto after_5;
    // 0x8011486C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_5:
    // 0x80114870: beq         $v0, $zero, L_80114884
    if (ctx->r2 == 0) {
        // 0x80114874: lwc1        $f14, 0x44($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80114884;
    }
    // 0x80114874: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80114878: jal         0x800F13F0
    // 0x8011487C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800F13F0(rdram, ctx);
        goto after_6;
    // 0x8011487C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_6:
    // 0x80114880: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80114884:
    // 0x80114884: jal         0x800C954C
    // 0x80114888: nop

    func_800C954C(rdram, ctx);
        goto after_7;
    // 0x80114888: nop

    after_7:
    // 0x8011488C: beql        $v0, $zero, L_801148BC
    if (ctx->r2 == 0) {
        // 0x80114890: lw          $t1, 0x48($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X48);
            goto L_801148BC;
    }
    goto skip_0;
    // 0x80114890: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x80114894: jal         0x800C9588
    // 0x80114898: nop

    func_800C9588(rdram, ctx);
        goto after_8;
    // 0x80114898: nop

    after_8:
    // 0x8011489C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801148A0: lwc1        $f18, 0x65F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X65F4);
    // 0x801148A4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x801148A8: mul.s       $f14, $f0, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801148AC: jal         0x800F13F0
    // 0x801148B0: nop

    func_800F13F0(rdram, ctx);
        goto after_9;
    // 0x801148B0: nop

    after_9:
    // 0x801148B4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801148B8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
L_801148BC:
    // 0x801148BC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801148C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801148C4: lbu         $t2, 0x2($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2);
    // 0x801148C8: beql        $t2, $zero, L_801148E4
    if (ctx->r10 == 0) {
        // 0x801148CC: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_801148E4;
    }
    goto skip_1;
    // 0x801148CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x801148D0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801148D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801148D8: b           L_801148EC
    // 0x801148DC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
        goto L_801148EC;
    // 0x801148DC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x801148E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_801148E4:
    // 0x801148E4: nop

    // 0x801148E8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
L_801148EC:
    // 0x801148EC: nop

    // 0x801148F0: bc1fl       L_80114900
    if (!c1cs) {
        // 0x801148F4: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_80114900;
    }
    goto skip_2;
    // 0x801148F4: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_2:
    // 0x801148F8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801148FC: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_80114900:
    // 0x80114900: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80114904: jr          $ra
    // 0x80114908: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80114908: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800CA768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA76C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800CA770: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800CA774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA778: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CA77C: jal         0x800EEAD4
    // 0x800CA780: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_0;
    // 0x800CA780: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800CA784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA78C: jr          $ra
    // 0x800CA790: nop

    return;
    // 0x800CA790: nop

;}
RECOMP_FUNC void func_8080179C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080179C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808017A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808017A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808017A8: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x808017AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808017B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808017B4: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x808017B8: beq         $t6, $at, L_808017D4
    if (ctx->r14 == ctx->r1) {
        // 0x808017BC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808017D4;
    }
    // 0x808017BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808017C0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808017C4: beq         $t6, $at, L_808018B4
    if (ctx->r14 == ctx->r1) {
        // 0x808017C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808018B4;
    }
    // 0x808017C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017CC: b           L_80801990
    // 0x808017D0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
        goto L_80801990;
    // 0x808017D0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
L_808017D4:
    // 0x808017D4: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(804, 0X8288) << 16);
    // 0x808017D8: addiu       $a1, $a1, -0x7D78
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(804, 0X8288));
    // 0x808017DC: jal         0x80101E4C
    // 0x808017E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_0;
    // 0x808017E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808017E4: beq         $v0, $zero, L_808018A4
    if (ctx->r2 == 0) {
        // 0x808017E8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(804, 0X7CA0) << 16);
            goto L_808018A4;
    }
    // 0x808017E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CA0) << 16);
    // 0x808017EC: lwc1        $f12, 0x7CA0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CA0));
    // 0x808017F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CA4) << 16);
    // 0x808017F4: jal         0x800DC178
    // 0x808017F8: lwc1        $f14, 0x7CA4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CA4));
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808017F8: lwc1        $f14, 0x7CA4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CA4));
    after_1:
    // 0x808017FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CA8) << 16);
    // 0x80801800: lwc1        $f4, 0x7CA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CA8));
    // 0x80801804: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801808: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080180C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801810: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80801814: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801818: nop

    // 0x8080181C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801820: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801824: nop

    // 0x80801828: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8080182C: beql        $a0, $zero, L_8080187C
    if (ctx->r4 == 0) {
        // 0x80801830: mfc1        $a0, $f8
        ctx->r4 = (int32_t)ctx->f8.u32l;
            goto L_8080187C;
    }
    goto skip_0;
    // 0x80801830: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80801834: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801838: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080183C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801840: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801844: nop

    // 0x80801848: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8080184C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801850: nop

    // 0x80801854: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801858: bne         $a0, $zero, L_80801870
    if (ctx->r4 != 0) {
        // 0x8080185C: nop
    
            goto L_80801870;
    }
    // 0x8080185C: nop

    // 0x80801860: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80801864: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801868: b           L_80801888
    // 0x8080186C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80801888;
    // 0x8080186C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80801870:
    // 0x80801870: b           L_80801888
    // 0x80801874: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80801888;
    // 0x80801874: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801878: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
L_8080187C:
    // 0x8080187C: nop

    // 0x80801880: bltz        $a0, L_80801870
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801884: nop
    
            goto L_80801870;
    }
    // 0x80801884: nop

L_80801888:
    // 0x80801888: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x8080188C: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80801890: ori         $at, $at, 0xA4D5
    ctx->r1 = ctx->r1 | 0XA4D5;
    // 0x80801894: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80801898: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8080189C: jal         0x800C3F48
    // 0x808018A0: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    func_800C3F48(rdram, ctx);
        goto after_2;
    // 0x808018A0: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    after_2:
L_808018A4:
    // 0x808018A4: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x808018A8: srl         $t0, $v0, 4
    ctx->r8 = S32(U32(ctx->r2) >> 4);
    // 0x808018AC: b           L_8080198C
    // 0x808018B0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8080198C;
    // 0x808018B0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_808018B4:
    // 0x808018B4: lui         $a1, 0x3F45
    ctx->r5 = S32(0X3F45 << 16);
    // 0x808018B8: jal         0x80101E14
    // 0x808018BC: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x808018BC: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    after_3:
    // 0x808018C0: beq         $v0, $zero, L_80801980
    if (ctx->r2 == 0) {
        // 0x808018C4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(804, 0X7CAC) << 16);
            goto L_80801980;
    }
    // 0x808018C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CAC) << 16);
    // 0x808018C8: lwc1        $f12, 0x7CAC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CAC));
    // 0x808018CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CB0) << 16);
    // 0x808018D0: jal         0x800DC178
    // 0x808018D4: lwc1        $f14, 0x7CB0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CB0));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808018D4: lwc1        $f14, 0x7CB0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CB0));
    after_4:
    // 0x808018D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CB4) << 16);
    // 0x808018DC: lwc1        $f10, 0x7CB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CB4));
    // 0x808018E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808018E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808018E8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808018EC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x808018F0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808018F4: nop

    // 0x808018F8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808018FC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80801900: nop

    // 0x80801904: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801908: beql        $a0, $zero, L_80801958
    if (ctx->r4 == 0) {
        // 0x8080190C: mfc1        $a0, $f18
        ctx->r4 = (int32_t)ctx->f18.u32l;
            goto L_80801958;
    }
    goto skip_1;
    // 0x8080190C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x80801910: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801914: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801918: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8080191C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80801920: nop

    // 0x80801924: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80801928: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8080192C: nop

    // 0x80801930: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80801934: bne         $a0, $zero, L_8080194C
    if (ctx->r4 != 0) {
        // 0x80801938: nop
    
            goto L_8080194C;
    }
    // 0x80801938: nop

    // 0x8080193C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80801940: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801944: b           L_80801964
    // 0x80801948: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80801964;
    // 0x80801948: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_8080194C:
    // 0x8080194C: b           L_80801964
    // 0x80801950: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80801964;
    // 0x80801950: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801954: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
L_80801958:
    // 0x80801958: nop

    // 0x8080195C: bltz        $a0, L_8080194C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80801960: nop
    
            goto L_8080194C;
    }
    // 0x80801960: nop

L_80801964:
    // 0x80801964: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80801968: lui         $at, 0xD
    ctx->r1 = S32(0XD << 16);
    // 0x8080196C: ori         $at, $at, 0xACD5
    ctx->r1 = ctx->r1 | 0XACD5;
    // 0x80801970: sll         $t3, $t2, 21
    ctx->r11 = S32(ctx->r10 << 21);
    // 0x80801974: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80801978: jal         0x800C3F48
    // 0x8080197C: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    func_800C3F48(rdram, ctx);
        goto after_5;
    // 0x8080197C: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    after_5:
L_80801980:
    // 0x80801980: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80801984: srl         $t4, $v0, 4
    ctx->r12 = S32(U32(ctx->r2) >> 4);
    // 0x80801988: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8080198C:
    // 0x8080198C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
L_80801990:
    // 0x80801990: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80801994: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80801998: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8080199C: lui         $t6, 0x8081
    ctx->r14 = S32(RELOC_HI16(804, 0X8110) << 16);
    // 0x808019A0: addiu       $t6, $t6, -0x7EF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(804, 0X8110));
    // 0x808019A4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x808019A8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x808019AC: jal         0x80101E4C
    // 0x808019B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_6;
    // 0x808019B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808019B4: beq         $v0, $zero, L_80801AB0
    if (ctx->r2 == 0) {
        // 0x808019B8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(804, 0X7CB8) << 16);
            goto L_80801AB0;
    }
    // 0x808019B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CB8) << 16);
    // 0x808019BC: lwc1        $f12, 0x7CB8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CB8));
    // 0x808019C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CBC) << 16);
    // 0x808019C4: jal         0x800DC178
    // 0x808019C8: lwc1        $f14, 0x7CBC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CBC));
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x808019C8: lwc1        $f14, 0x7CBC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CBC));
    after_7:
    // 0x808019CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CC0) << 16);
    // 0x808019D0: lwc1        $f4, 0x7CC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CC0));
    // 0x808019D4: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x808019D8: lui         $t9, 0x8081
    ctx->r25 = S32(RELOC_HI16(804, 0X8270) << 16);
    // 0x808019DC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808019E0: nop

    // 0x808019E4: srl         $t7, $v0, 4
    ctx->r15 = S32(U32(ctx->r2) >> 4);
    // 0x808019E8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x808019EC: lui         $t1, 0x8081
    ctx->r9 = S32(RELOC_HI16(804, 0X8280) << 16);
    // 0x808019F0: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x808019F4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808019F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x808019FC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80801A00: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801A04: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80801A08: lbu         $t1, -0x7D80($t1)
    ctx->r9 = MEM_BU(ctx->r9, (int16_t)RELOC_LO16(804, 0X8280));
    // 0x80801A0C: lhu         $t9, -0x7D90($t9)
    ctx->r25 = MEM_HU(ctx->r25, (int16_t)RELOC_LO16(804, 0X8270));
    // 0x80801A10: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801A14: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80801A18: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80801A1C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80801A20: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80801A24: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80801A28: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80801A2C: sra         $t3, $t2, 5
    ctx->r11 = S32(SIGNED(ctx->r10) >> 5);
    // 0x80801A30: andi        $t4, $t3, 0x3FF
    ctx->r12 = ctx->r11 & 0X3FF;
    // 0x80801A34: sll         $t5, $t4, 11
    ctx->r13 = S32(ctx->r12 << 11);
    // 0x80801A38: andi        $t0, $t9, 0x7FF
    ctx->r8 = ctx->r25 & 0X7FF;
    // 0x80801A3C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80801A40: beq         $t8, $zero, L_80801A90
    if (ctx->r24 == 0) {
        // 0x80801A44: addu        $t6, $t0, $t5
        ctx->r14 = ADD32(ctx->r8, ctx->r13);
            goto L_80801A90;
    }
    // 0x80801A44: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x80801A48: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801A4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801A50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801A54: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801A58: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80801A5C: nop

    // 0x80801A60: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80801A64: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80801A68: nop

    // 0x80801A6C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80801A70: bne         $t8, $zero, L_80801A88
    if (ctx->r24 != 0) {
        // 0x80801A74: nop
    
            goto L_80801A88;
    }
    // 0x80801A74: nop

    // 0x80801A78: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80801A7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801A80: b           L_80801AA0
    // 0x80801A84: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80801AA0;
    // 0x80801A84: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80801A88:
    // 0x80801A88: b           L_80801AA0
    // 0x80801A8C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80801AA0;
    // 0x80801A8C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80801A90:
    // 0x80801A90: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80801A94: nop

    // 0x80801A98: bltz        $t8, L_80801A88
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801A9C: nop
    
            goto L_80801A88;
    }
    // 0x80801A9C: nop

L_80801AA0:
    // 0x80801AA0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80801AA4: sll         $t1, $t8, 21
    ctx->r9 = S32(ctx->r24 << 21);
    // 0x80801AA8: jal         0x800C3F48
    // 0x80801AAC: addu        $a0, $t1, $t6
    ctx->r4 = ADD32(ctx->r9, ctx->r14);
    func_800C3F48(rdram, ctx);
        goto after_8;
    // 0x80801AAC: addu        $a0, $t1, $t6
    ctx->r4 = ADD32(ctx->r9, ctx->r14);
    after_8:
L_80801AB0:
    // 0x80801AB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801AB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801AB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801ABC: jr          $ra
    // 0x80801AC0: nop

    return;
    // 0x80801AC0: nop

;}
RECOMP_FUNC void _chprisonbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FF8: syscall     491
    recomp_syscall_handler(rdram, ctx, 0x80086FF8);
    return;
    // 0x80086FFC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800140_basquash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800144: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800148: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080014C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800150: lw          $v1, 0x11C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X11C);
    // 0x80800154: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(600, 0X634) << 16);
    // 0x80800158: lwc1        $f6, 0x634($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(600, 0X634));
    // 0x8080015C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800160: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x80800164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800168: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800170: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(600, 0X6B0) << 16);
    // 0x80800174: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800178: mfc1        $s1, $f10
    ctx->r17 = (int32_t)ctx->f10.u32l;
    // 0x8080017C: nop

    // 0x80800180: beql        $s1, $t7, L_808001BC
    if (ctx->r17 == ctx->r15) {
        // 0x80800184: sb          $s1, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r17;
            goto L_808001BC;
    }
    goto skip_0;
    // 0x80800184: sb          $s1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r17;
    skip_0:
    // 0x80800188: jal         0x8009D454
    // 0x8080018C: addiu       $a2, $a2, 0x6B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(600, 0X6B0));
    func_8009D454(rdram, ctx);
        goto after_0;
    // 0x8080018C: addiu       $a2, $a2, 0x6B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(600, 0X6B0));
    after_0:
    // 0x80800190: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80800194: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80800198: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(600, 0X6C4) << 16);
    // 0x8080019C: addiu       $t9, $t9, 0x6C4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(600, 0X6C4));
    // 0x808001A0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808001A4: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x8009D454
    // 0x808001B0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    func_8009D454(rdram, ctx);
        goto after_1;
    // 0x808001B0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_1:
    // 0x808001B4: lw          $v1, 0x11C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X11C);
    // 0x808001B8: sb          $s1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r17;
L_808001BC:
    // 0x808001BC: lw          $t0, 0x11C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X11C);
    // 0x808001C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(600, 0X638) << 16);
    // 0x808001C4: lwc1        $f14, 0x638($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(600, 0X638));
    // 0x808001C8: jal         0x800F13C4
    // 0x808001CC: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    func_800F13C4(rdram, ctx);
        goto after_2;
    // 0x808001CC: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    after_2:
    // 0x808001D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(600, 0X63C) << 16);
    // 0x808001D4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808001D8: lwc1        $f14, 0x63C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(600, 0X63C));
    // 0x808001DC: jal         0x800F0F9C
    // 0x808001E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F0F9C(rdram, ctx);
        goto after_3;
    // 0x808001E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x808001E4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808001E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001EC: nop

    // 0x808001F0: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808001F4: jal         0x80013970
    // 0x808001F8: nop

    func_80013970(rdram, ctx);
        goto after_4;
    // 0x808001F8: nop

    after_4:
    // 0x808001FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800200: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(600, 0X640) << 16);
    // 0x80800204: lwc1        $f18, 0x640($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(600, 0X640));
    // 0x80800208: lui         $a2, 0x3F11
    ctx->r6 = S32(0X3F11 << 16);
    // 0x8080020C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800210: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800214: ori         $a2, $a2, 0x1111
    ctx->r6 = ctx->r6 | 0X1111;
    // 0x80800218: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080021C: jal         0x800F10B4
    // 0x80800220: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800220: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80800224: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80800228: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080022C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800230: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800234: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800238: lw          $t1, 0x11C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X11C);
    // 0x8080023C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800240: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800244: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80800248: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x8080024C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800250: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800254: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800258: jr          $ra
    // 0x8080025C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080025C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void chwaterfallgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002E0: jal         0x800EA05C
    // 0x808002E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808002E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002E8: addiu       $at, $zero, 0xC7
    ctx->r1 = ADD32(0, 0XC7);
    // 0x808002EC: bne         $v0, $at, L_80800308
    if (ctx->r2 != ctx->r1) {
        // 0x808002F0: addiu       $a0, $zero, 0x11B
        ctx->r4 = ADD32(0, 0X11B);
            goto L_80800308;
    }
    // 0x808002F0: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    // 0x808002F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808002F8: jal         0x80101180
    // 0x808002FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_1;
    // 0x808002FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800300: b           L_80800314
    // 0x80800304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800314;
    // 0x80800304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800308:
    // 0x80800308: jal         0x800DA524
    // 0x8080030C: addiu       $a0, $zero, 0x9F2
    ctx->r4 = ADD32(0, 0X9F2);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x8080030C: addiu       $a0, $zero, 0x9F2
    ctx->r4 = ADD32(0, 0X9F2);
    after_2:
    // 0x80800310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800314:
    // 0x80800314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800318: jr          $ra
    // 0x8080031C: nop

    return;
    // 0x8080031C: nop

;}
RECOMP_FUNC void func_80800828_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800828: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080082C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800830: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80800834: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80800838: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8080083C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80800840: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80800844: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800848: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080084C: jal         0x800D8FF8
    // 0x80800850: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800850: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800854: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800858: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080085C: jal         0x80100094
    // 0x80800860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800864: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800868: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080086C: addiu       $s0, $v0, 0x4
    ctx->r16 = ADD32(ctx->r2, 0X4);
    // 0x80800870: blez        $t6, L_8080092C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800874: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8080092C;
    }
    // 0x80800874: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800878: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8080087C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800880: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800884: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800888: addiu       $s3, $zero, 0x24
    ctx->r19 = ADD32(0, 0X24);
L_8080088C:
    // 0x8080088C: jal         0x800D90A4
    // 0x80800890: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    func_800D90A4(rdram, ctx);
        goto after_2;
    // 0x80800890: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_2:
    // 0x80800894: beql        $v0, $zero, L_80800918
    if (ctx->r2 == 0) {
        // 0x80800898: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_80800918;
    }
    goto skip_0;
    // 0x80800898: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    skip_0:
    // 0x8080089C: jal         0x800D90A4
    // 0x808008A0: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x808008A0: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_3:
    // 0x808008A4: beql        $v0, $zero, L_808008C0
    if (ctx->r2 == 0) {
        // 0x808008A8: lwc1        $f10, 0x10($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
            goto L_808008C0;
    }
    goto skip_1;
    // 0x808008A8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x808008AC: mul.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x808008B0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808008B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808008B8: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x808008BC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
L_808008C0:
    // 0x808008C0: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x808008C4: nop

    // 0x808008C8: bc1fl       L_80800904
    if (!c1cs) {
        // 0x808008CC: lwc1        $f18, 0x1C($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_80800904;
    }
    goto skip_2;
    // 0x808008CC: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    skip_2:
    // 0x808008D0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808008DC: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808008E0: mflo        $t8
    ctx->r24 = lo;
    // 0x808008E4: addu        $a1, $s1, $t8
    ctx->r5 = ADD32(ctx->r17, ctx->r24);
    // 0x808008E8: jal         0x8001BBA0
    // 0x808008EC: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    rare_memcpy(rdram, ctx);
        goto after_4;
    // 0x808008EC: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    after_4:
    // 0x808008F0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x808008F4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x808008F8: b           L_8080091C
    // 0x808008FC: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
        goto L_8080091C;
    // 0x808008FC: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x80800900: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
L_80800904:
    // 0x80800904: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800908: mul.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8080090C: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80800910: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80800914: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
L_80800918:
    // 0x80800918: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8080091C:
    // 0x8080091C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80800920: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800924: bne         $at, $zero, L_8080088C
    if (ctx->r1 != 0) {
        // 0x80800928: nop
    
            goto L_8080088C;
    }
    // 0x80800928: nop

L_8080092C:
    // 0x8080092C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800930: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800934: lhu         $t2, 0x72($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X72);
    // 0x80800938: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x8080093C: bnel        $t3, $at, L_8080095C
    if (ctx->r11 != ctx->r1) {
        // 0x80800940: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8080095C;
    }
    goto skip_3;
    // 0x80800940: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x80800944: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80800948: bnel        $v0, $zero, L_8080095C
    if (ctx->r2 != 0) {
        // 0x8080094C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8080095C;
    }
    goto skip_4;
    // 0x8080094C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x80800950: jal         0x800FFAB0
    // 0x80800954: nop

    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800954: nop

    after_5:
    // 0x80800958: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8080095C:
    // 0x8080095C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800960: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800964: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80800968: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8080096C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80800970: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80800974: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80800978: jr          $ra
    // 0x8080097C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080097C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void anctrl_setStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B24C: lbu         $t6, 0x1B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008B250: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008B254: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x8008B258: sb          $t7, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r15;
    // 0x8008B25C: jr          $ra
    // 0x8008B260: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x8008B260: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void sudeflect_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800174: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80800178: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8080017C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x80800180: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800184: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800188: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080018C: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80800190: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80800194: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80800198: addiu       $s1, $s1, 0x1020
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x8080019C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x808001A0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x808001A4: andi        $t7, $t6, 0x18
    ctx->r15 = ctx->r14 & 0X18;
    // 0x808001A8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808001AC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808001B0: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x808001B4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x808001B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808001BC: beq         $t7, $zero, L_808001D0
    if (ctx->r15 == 0) {
        // 0x808001C0: sw          $zero, 0x24($s1)
        MEM_W(0X24, ctx->r17) = 0;
            goto L_808001D0;
    }
    // 0x808001C0: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x808001C4: jal         0x800BE3F8
    // 0x808001C8: nop

    func_800BE3F8(rdram, ctx);
        goto after_0;
    // 0x808001C8: nop

    after_0:
    // 0x808001CC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_808001D0:
    // 0x808001D0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x808001D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001D8: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x808001DC: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x808001E0: beql        $t9, $zero, L_80800248
    if (ctx->r25 == 0) {
        // 0x808001E4: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_80800248;
    }
    goto skip_0;
    // 0x808001E4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_808001E8:
    // 0x808001E8: jal         0x800F6438
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001F0: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x808001F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800238;
    }
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808001FC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800200: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800204: jal         0x800F4EC8
    // 0x80800208: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_2;
    // 0x80800208: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_2:
    // 0x8080020C: beql        $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x80800210: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080023C;
    }
    goto skip_1;
    // 0x80800210: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80800214: lw          $t0, 0x24($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X24);
    // 0x80800218: ori         $t5, $s2, 0x2
    ctx->r13 = ctx->r18 | 0X2;
    // 0x8080021C: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x80800220: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800224: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x80800228: sw          $s0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r16;
    // 0x8080022C: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x80800230: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80800234: sw          $t4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r12;
L_80800238:
    // 0x80800238: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8080023C:
    // 0x8080023C: bne         $s0, $s3, L_808001E8
    if (ctx->r16 != ctx->r19) {
        // 0x80800240: nop
    
            goto L_808001E8;
    }
    // 0x80800240: nop

    // 0x80800244: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
L_80800248:
    // 0x80800248: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8080024C: beql        $t7, $zero, L_8080026C
    if (ctx->r15 == 0) {
        // 0x80800250: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_8080026C;
    }
    goto skip_2;
    // 0x80800250: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    skip_2:
    // 0x80800254: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800258: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8080025C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800260: jal         0x800A5298
    // 0x80800264: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800A5298(rdram, ctx);
        goto after_3;
    // 0x80800264: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x80800268: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_8080026C:
    // 0x8080026C: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x80800270: beql        $t9, $zero, L_8080029C
    if (ctx->r25 == 0) {
        // 0x80800274: lw          $t1, 0x60($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X60);
            goto L_8080029C;
    }
    goto skip_3;
    // 0x80800274: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    skip_3:
    // 0x80800278: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080027C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800280: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800284: jal         0x808007F4
    // 0x80800288: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_808007F4_sudeflect(rdram, ctx);
        goto after_4;
    // 0x80800288: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x8080028C: beq         $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x80800290: ori         $t0, $s2, 0x8
        ctx->r8 = ctx->r18 | 0X8;
            goto L_80800298;
    }
    // 0x80800290: ori         $t0, $s2, 0x8
    ctx->r8 = ctx->r18 | 0X8;
    // 0x80800294: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
L_80800298:
    // 0x80800298: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
L_8080029C:
    // 0x8080029C: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x808002A0: beql        $t2, $zero, L_808002CC
    if (ctx->r10 == 0) {
        // 0x808002A4: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_808002CC;
    }
    goto skip_4;
    // 0x808002A4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_4:
    // 0x808002A8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808002AC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808002B0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808002B4: jal         0x80800A98
    // 0x808002B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80800A98_sudeflect(rdram, ctx);
        goto after_5;
    // 0x808002B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x808002BC: beq         $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x808002C0: ori         $t3, $s2, 0x10
        ctx->r11 = ctx->r18 | 0X10;
            goto L_808002C8;
    }
    // 0x808002C0: ori         $t3, $s2, 0x10
    ctx->r11 = ctx->r18 | 0X10;
    // 0x808002C4: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
L_808002C8:
    // 0x808002C8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_808002CC:
    // 0x808002CC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x808002D0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x808002D4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x808002D8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808002DC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808002E0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808002E4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808002E8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808002EC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x808002F0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x808002F4: jr          $ra
    // 0x808002F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808002F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bafpctrl_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CC8: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CC8);
    return;
    // 0x80084CCC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void bskazshock_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80092C24
    // 0x8080000C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80092C24(rdram, ctx);
        goto after_0;
    // 0x8080000C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800010: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(272, 0X770) << 16);
    // 0x80800014: addiu       $t6, $t6, 0x770
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(272, 0X770));
    // 0x80800018: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080001C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800024: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800028: jal         0x800BBCB8
    // 0x8080002C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80800030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800034: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void _chjiggygamenew_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B20: syscall     197
    recomp_syscall_handler(rdram, ctx, 0x80085B20);
    return;
    // 0x80085B24: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800AA4_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AAC: jal         0x8008E35C
    // 0x80800AB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    player_inWater(rdram, ctx);
        goto after_0;
    // 0x80800AB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AB4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800AB8: beq         $t6, $zero, L_80800AE4
    if (ctx->r14 == 0) {
        // 0x80800ABC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800AE4;
    }
    // 0x80800ABC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800AC0: jal         0x8009BB50
    // 0x80800AC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_1;
    // 0x80800AC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800AC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800ACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800AD0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800AD4: nop

    // 0x80800AD8: bc1fl       L_80800AE8
    if (!c1cs) {
        // 0x80800ADC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800AE8;
    }
    goto skip_0;
    // 0x80800ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AE4:
    // 0x80800AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AE8:
    // 0x80800AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AEC: jr          $ra
    // 0x80800AF0: nop

    return;
    // 0x80800AF0: nop

;}
RECOMP_FUNC void chhotwaterpoolbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1268, 0X978) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x978
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1268, 0X978));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x978
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1268, 0X978));
;}
RECOMP_FUNC void _mlspline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890F0: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x800890F0);
    return;
    // 0x800890F4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _fxgenlist_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AF8: syscall     723
    recomp_syscall_handler(rdram, ctx, 0x80088AF8);
    return;
    // 0x80088AFC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsmumcast_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083880: syscall     77
    recomp_syscall_handler(rdram, ctx, 0x80083880);
    return;
    // 0x80083884: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8009CB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CB90: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8009CB94: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8009CB98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009CB9C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8009CBA0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8009CBA4: lw          $v0, 0x7F38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7F38);
    // 0x8009CBA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CBAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CBB0: beq         $v0, $zero, L_8009CBC8
    if (ctx->r2 == 0) {
        // 0x8009CBB4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8009CBC8;
    }
    // 0x8009CBB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009CBB8: jalr        $v0
    // 0x8009CBBC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8009CBBC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8009CBC0: b           L_8009CBD0
    // 0x8009CBC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009CBD0;
    // 0x8009CBC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CBC8:
    // 0x8009CBC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009CBCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CBD0:
    // 0x8009CBD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CBD4: jr          $ra
    // 0x8009CBD8: nop

    return;
    // 0x8009CBD8: nop

;}
RECOMP_FUNC void _bafly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BC8: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084BC8);
    return;
    // 0x80084BCC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void badronemem_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x8001ACCC
    // 0x80800010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800014: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800018: sw          $v0, 0x18C($t6)
    MEM_W(0X18C, ctx->r14) = ctx->r2;
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void bainvisible_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: lw          $t6, 0xA8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA8);
    // 0x80800430: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800434: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80800438: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8080043C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800440: jr          $ra
    // 0x80800444: lwc1        $f0, 0x28($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X28);
    return;
    // 0x80800444: lwc1        $f0, 0x28($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X28);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C20: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C20);
    return;
    // 0x80083C24: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _chgruntyfireballbig_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086810: syscall     382
    recomp_syscall_handler(rdram, ctx, 0x80086810);
    return;
    // 0x80086814: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void scinfobar_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C8: jr          $ra
    // 0x808005CC: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    return;
    // 0x808005CC: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
;}
RECOMP_FUNC void func_801106A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801106A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801106AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801106B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801106B4: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x801106B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x801106BC: beq         $a1, $v0, L_80110710
    if (ctx->r5 == ctx->r2) {
        // 0x801106C0: sll         $t7, $v0, 4
        ctx->r15 = S32(ctx->r2 << 4);
            goto L_80110710;
    }
    // 0x801106C0: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x801106C4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x801106C8: lw          $v1, 0x47A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X47A8);
    // 0x801106CC: beql        $v1, $zero, L_801106E4
    if (ctx->r3 == 0) {
        // 0x801106D0: sll         $t8, $a1, 4
        ctx->r24 = S32(ctx->r5 << 4);
            goto L_801106E4;
    }
    goto skip_0;
    // 0x801106D0: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    skip_0:
    // 0x801106D4: jalr        $v1
    // 0x801106D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x801106D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801106DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801106E0: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
L_801106E4:
    // 0x801106E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x801106E8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x801106EC: lw          $v0, 0x47A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X47A0);
    // 0x801106F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801106F4: beql        $v0, $zero, L_8011070C
    if (ctx->r2 == 0) {
        // 0x801106F8: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_8011070C;
    }
    goto skip_1;
    // 0x801106F8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x801106FC: jalr        $v0
    // 0x80110700: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80110700: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80110704: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80110708: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_8011070C:
    // 0x8011070C: sw          $a1, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->r5;
L_80110710:
    // 0x80110710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110718: jr          $ra
    // 0x8011071C: nop

    return;
    // 0x8011071C: nop

;}
RECOMP_FUNC void func_8001C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C2F0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001C2F4: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x8001C2F8: jal         0x800304C0
    // 0x8001C2FC: nop

    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C2FC: nop

    after_0:
    // 0x8001C300: sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
    // 0x8001C304: jal         0x8001C324
    // 0x8001C308: nop

    func_8001C324(rdram, ctx);
        goto after_1;
    // 0x8001C308: nop

    after_1:
    // 0x8001C30C: lw          $a0, 0x8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8);
    // 0x8001C310: jal         0x80030530
    // 0x8001C314: nop

    __osRestoreInt_recomp(rdram, ctx);
        goto after_2;
    // 0x8001C314: nop

    after_2:
    // 0x8001C318: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x8001C31C: jr          $ra
    // 0x8001C320: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001C320: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void cheggclockwork_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808005D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2104, 0X8B8) << 16);
    // 0x808005DC: lwc1        $f12, 0x8B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2104, 0X8B8));
    // 0x808005E0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808005E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2104, 0X8BC) << 16);
    // 0x808005EC: lwc1        $f6, 0x8BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2104, 0X8BC));
    // 0x808005F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808005F4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808005F8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808005FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800600: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800604: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800608: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    // 0x8080060C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800610: addiu       $a1, $zero, 0x5F3
    ctx->r5 = ADD32(0, 0X5F3);
    // 0x80800614: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80800618: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8080061C: jal         0x800C9C70
    // 0x80800620: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_800C9C70(rdram, ctx);
        goto after_0;
    // 0x80800620: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80800624: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2104, 0X908) << 16);
    // 0x80800628: addiu       $t6, $t6, 0x908
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2104, 0X908));
    // 0x8080062C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800638: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080063C: jal         0x800BBCB8
    // 0x80800640: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80800640: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80800644: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2104, 0X950) << 16);
    // 0x80800648: addiu       $t7, $t7, 0x950
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2104, 0X950));
    // 0x8080064C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800658: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080065C: jal         0x800BBCB8
    // 0x80800660: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800660: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_2:
    // 0x80800664: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2104, 0X998) << 16);
    // 0x80800668: addiu       $t8, $t8, 0x998
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2104, 0X998));
    // 0x8080066C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800678: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080067C: jal         0x800BBCB8
    // 0x80800680: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800680: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x80800684: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2104, 0X9E0) << 16);
    // 0x80800688: addiu       $t9, $t9, 0x9E0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2104, 0X9E0));
    // 0x8080068C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800698: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080069C: jal         0x800BBCB8
    // 0x808006A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x808006A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x808006A4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x808006A8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x808006AC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x808006B0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808006B4: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x808006B8: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x808006BC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808006C0: addiu       $a0, $a0, 0x71D0
    ctx->r4 = ADD32(ctx->r4, 0X71D0);
    // 0x808006C4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808006C8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808006CC: jal         0x80086D58
    // 0x808006D0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x808006D0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_5:
    // 0x808006D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808006D8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808006DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006E0: jr          $ra
    // 0x808006E4: nop

    return;
    // 0x808006E4: nop

;}
RECOMP_FUNC void fxegg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080018C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800190: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800194: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800198: jal         0x800B5BE4
    // 0x8080019C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x8080019C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x808001A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808001A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001A8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808001AC: addiu       $a2, $zero, 0x9E0
    ctx->r6 = ADD32(0, 0X9E0);
    // 0x808001B0: jal         0x808000F8
    // 0x808001B4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_808000F8_fxegg(rdram, ctx);
        goto after_1;
    // 0x808001B4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001BC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_800B3CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3CDC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B3CE0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B3CE4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800B3CE8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800B3CEC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B3CF0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B3CF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B3CF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B3CFC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800B3D00: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x800B3D04: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800B3D08: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B3D0C: lh          $t7, 0x4($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X4);
    // 0x800B3D10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B3D14: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x800B3D18: bnel        $t7, $zero, L_800B3D38
    if (ctx->r15 != 0) {
        // 0x800B3D1C: lh          $v0, 0x0($s5)
        ctx->r2 = MEM_H(ctx->r21, 0X0);
            goto L_800B3D38;
    }
    goto skip_0;
    // 0x800B3D1C: lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X0);
    skip_0:
    // 0x800B3D20: jal         0x800B3C40
    // 0x800B3D24: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800B3C40(rdram, ctx);
        goto after_0;
    // 0x800B3D24: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x800B3D28: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800B3D2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3D30: lw          $s2, 0x0($t8)
    ctx->r18 = MEM_W(ctx->r24, 0X0);
    // 0x800B3D34: lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X0);
L_800B3D38:
    // 0x800B3D38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B3D3C: bnel        $v0, $zero, L_800B3D60
    if (ctx->r2 != 0) {
        // 0x800B3D40: lh          $a1, 0x0($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X0);
            goto L_800B3D60;
    }
    goto skip_1;
    // 0x800B3D40: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    skip_1:
    // 0x800B3D44: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800B3D48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3D4C: jal         0x800B3BDC
    // 0x800B3D50: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
    func_800B3BDC(rdram, ctx);
        goto after_1;
    // 0x800B3D50: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
    after_1:
    // 0x800B3D54: b           L_800B3EA8
    // 0x800B3D58: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
        goto L_800B3EA8;
    // 0x800B3D58: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800B3D5C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
L_800B3D60:
    // 0x800B3D60: lh          $t0, 0x2($s5)
    ctx->r8 = MEM_H(ctx->r21, 0X2);
    // 0x800B3D64: beq         $a1, $zero, L_800B3D94
    if (ctx->r5 == 0) {
        // 0x800B3D68: addu        $s1, $v0, $t0
        ctx->r17 = ADD32(ctx->r2, ctx->r8);
            goto L_800B3D94;
    }
    // 0x800B3D68: addu        $s1, $v0, $t0
    ctx->r17 = ADD32(ctx->r2, ctx->r8);
    // 0x800B3D6C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
L_800B3D70:
    // 0x800B3D70: beq         $s1, $a1, L_800B3D94
    if (ctx->r17 == ctx->r5) {
        // 0x800B3D74: nop
    
            goto L_800B3D94;
    }
    // 0x800B3D74: nop

    // 0x800B3D78: jal         0x800B39D0
    // 0x800B3D7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800B39D0(rdram, ctx);
        goto after_2;
    // 0x800B3D7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800B3D80: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800B3D84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3D88: bnel        $t1, $zero, L_800B3D70
    if (ctx->r9 != 0) {
        // 0x800B3D8C: lh          $a1, 0x0($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X0);
            goto L_800B3D70;
    }
    goto skip_2;
    // 0x800B3D8C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    skip_2:
    // 0x800B3D90: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
L_800B3D94:
    // 0x800B3D94: beq         $a1, $zero, L_800B3DAC
    if (ctx->r5 == 0) {
        // 0x800B3D98: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B3DAC;
    }
    // 0x800B3D98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B3D9C: jal         0x800B3BDC
    // 0x800B3DA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800B3BDC(rdram, ctx);
        goto after_3;
    // 0x800B3DA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800B3DA4: b           L_800B3EA8
    // 0x800B3DA8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
        goto L_800B3EA8;
    // 0x800B3DA8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_800B3DAC:
    // 0x800B3DAC: lh          $t2, 0x0($s5)
    ctx->r10 = MEM_H(ctx->r21, 0X0);
    // 0x800B3DB0: lh          $s1, 0x2($s5)
    ctx->r17 = MEM_H(ctx->r21, 0X2);
    // 0x800B3DB4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B3DB8: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x800B3DBC: lh          $t3, 0x4($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X4);
    // 0x800B3DC0: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x800B3DC4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B3DC8: beq         $t3, $zero, L_800B3E00
    if (ctx->r11 == 0) {
        // 0x800B3DCC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B3E00;
    }
    // 0x800B3DCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800B3DD0:
    // 0x800B3DD0: jal         0x800B39D0
    // 0x800B3DD4: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    func_800B39D0(rdram, ctx);
        goto after_4;
    // 0x800B3DD4: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    after_4:
    // 0x800B3DD8: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x800B3DDC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800B3DE0: slt         $at, $t4, $s1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800B3DE4: beq         $at, $zero, L_800B3E00
    if (ctx->r1 == 0) {
        // 0x800B3DE8: nop
    
            goto L_800B3E00;
    }
    // 0x800B3DE8: nop

    // 0x800B3DEC: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x800B3DF0: lh          $s3, 0x0($s0)
    ctx->r19 = MEM_H(ctx->r16, 0X0);
    // 0x800B3DF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3DF8: bnel        $t5, $zero, L_800B3DD0
    if (ctx->r13 != 0) {
        // 0x800B3DFC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B3DD0;
    }
    goto skip_3;
    // 0x800B3DFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_3:
L_800B3E00:
    // 0x800B3E00: beq         $s4, $zero, L_800B3E14
    if (ctx->r20 == 0) {
        // 0x800B3E04: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_800B3E14;
    }
    // 0x800B3E04: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800B3E08: lh          $t7, 0x2($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X2);
    // 0x800B3E0C: slt         $at, $t7, $s1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800B3E10: beq         $at, $zero, L_800B3E2C
    if (ctx->r1 == 0) {
        // 0x800B3E14: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_800B3E2C;
    }
L_800B3E14:
    // 0x800B3E14: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800B3E18: jal         0x800B3C40
    // 0x800B3E1C: addiu       $a2, $s1, 0x5
    ctx->r6 = ADD32(ctx->r17, 0X5);
    func_800B3C40(rdram, ctx);
        goto after_5;
    // 0x800B3E1C: addiu       $a2, $s1, 0x5
    ctx->r6 = ADD32(ctx->r17, 0X5);
    after_5:
    // 0x800B3E20: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800B3E24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3E28: lw          $s2, 0x0($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X0);
L_800B3E2C:
    // 0x800B3E2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B3E30: jal         0x800B39D0
    // 0x800B3E34: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    func_800B39D0(rdram, ctx);
        goto after_6;
    // 0x800B3E34: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    after_6:
    // 0x800B3E38: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800B3E3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B3E40: jal         0x800B39D0
    // 0x800B3E44: lh          $a1, 0x0($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X0);
    func_800B39D0(rdram, ctx);
        goto after_7;
    // 0x800B3E44: lh          $a1, 0x0($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X0);
    after_7:
    // 0x800B3E48: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800B3E4C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B3E50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B3E54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B3E58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B3E5C: lh          $a3, 0x2($s5)
    ctx->r7 = MEM_H(ctx->r21, 0X2);
    // 0x800B3E60: jal         0x800B3B8C
    // 0x800B3E64: sh          $t8, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r24;
    func_800B3B8C(rdram, ctx);
        goto after_8;
    // 0x800B3E64: sh          $t8, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r24;
    after_8:
    // 0x800B3E68: lh          $t9, 0x2($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X2);
    // 0x800B3E6C: lh          $t0, 0x0($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X0);
    // 0x800B3E70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800B3E74: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800B3E78: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3E7C: mflo        $a2
    ctx->r6 = lo;
    // 0x800B3E80: jal         0x8001BBC8
    // 0x800B3E84: nop

    aligned4_memcpy(rdram, ctx);
        goto after_9;
    // 0x800B3E84: nop

    after_9:
    // 0x800B3E88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B3E8C: jal         0x800B3BDC
    // 0x800B3E90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800B3BDC(rdram, ctx);
        goto after_10;
    // 0x800B3E90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800B3E94: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800B3E98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B3E9C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800B3EA0: jal         0x800B3B08
    // 0x800B3EA4: lh          $a2, 0x2($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X2);
    func_800B3B08(rdram, ctx);
        goto after_11;
    // 0x800B3EA4: lh          $a2, 0x2($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X2);
    after_11:
L_800B3EA8:
    // 0x800B3EA8: lh          $t1, 0x2($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X2);
    // 0x800B3EAC: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800B3EB0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B3EB4: sh          $t2, 0x2($s5)
    MEM_H(0X2, ctx->r21) = ctx->r10;
    // 0x800B3EB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3EBC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800B3EC0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800B3EC4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B3EC8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3ECC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B3ED0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B3ED4: jr          $ra
    // 0x800B3ED8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800B3ED8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void bafly_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C30: jal         0x80084C98
    // 0x80800C34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800C34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800C38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800C3C: beq         $v0, $at, L_80800C98
    if (ctx->r2 == ctx->r1) {
        // 0x80800C40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C98;
    }
    // 0x80800C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C44: jal         0x80095738
    // 0x80800C48: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x80800C48: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_1:
    // 0x80800C4C: beq         $v0, $zero, L_80800C68
    if (ctx->r2 == 0) {
        // 0x80800C50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C68;
    }
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C58: jal         0x80084CE8
    // 0x80800C5C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bafpctrl_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x80800C5C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800C60: b           L_80800C74
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800C74;
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C68:
    // 0x80800C68: jal         0x80084CE8
    // 0x80800C6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bafpctrl_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x80800C6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C74:
    // 0x80800C74: jal         0x80084CC0
    // 0x80800C78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800C78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800C7C: jal         0x800C6E38
    // 0x80800C80: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800C6E38(rdram, ctx);
        goto after_5;
    // 0x80800C80: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_5:
    // 0x80800C84: bne         $v0, $zero, L_80800C98
    if (ctx->r2 != 0) {
        // 0x80800C88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C98;
    }
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C8C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800C90: jal         0x80084CD0
    // 0x80800C94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800C94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
L_80800C98:
    // 0x80800C98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CA4: jr          $ra
    // 0x80800CA8: nop

    return;
    // 0x80800CA8: nop

;}
RECOMP_FUNC void _charea51gate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E60: syscall     250
    recomp_syscall_handler(rdram, ctx, 0x80085E60);
    return;
    // 0x80085E64: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void glhittableDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800D8F40
    // 0x8080000C: nop

    func_800D8F40(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800014: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800018: addiu       $t1, $zero, 0x398
    ctx->r9 = ADD32(0, 0X398);
    // 0x8080001C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80800020:
    // 0x80800020: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2742, 0X530) << 16);
    // 0x80800024: addiu       $t7, $t7, 0x530
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2742, 0X530));
    // 0x80800028: sll         $t6, $zero, 6
    ctx->r14 = S32(0 << 6);
    // 0x8080002C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800030: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800038: sh          $t0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r8;
    // 0x8080003C: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
L_80800040:
    // 0x80800040: bnel        $a2, $t8, L_80800054
    if (ctx->r6 != ctx->r24) {
        // 0x80800044: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80800054;
    }
    goto skip_0;
    // 0x80800044: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80800048: sh          $a0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r4;
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800050: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80800054:
    // 0x80800054: slti        $at, $a0, 0x99
    ctx->r1 = SIGNED(ctx->r4) < 0X99 ? 1 : 0;
    // 0x80800058: beq         $at, $zero, L_80800068
    if (ctx->r1 == 0) {
        // 0x8080005C: addiu       $v1, $v1, 0x44
        ctx->r3 = ADD32(ctx->r3, 0X44);
            goto L_80800068;
    }
    // 0x8080005C: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
    // 0x80800060: beql        $a1, $zero, L_80800040
    if (ctx->r5 == 0) {
        // 0x80800064: lhu         $t8, 0x0($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0X0);
            goto L_80800040;
    }
    goto skip_1;
    // 0x80800064: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    skip_1:
L_80800068:
    // 0x80800068: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8080006C: bne         $a2, $t1, L_80800020
    if (ctx->r6 != ctx->r9) {
        // 0x80800070: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80800020;
    }
    // 0x80800070: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void _bswasher_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843E8: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x800843E8);
    return;
    // 0x800843EC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chtemplebossdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2184, 0X1C0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2184, 0X1C0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2184, 0X1C0));
;}
RECOMP_FUNC void func_800CF640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF648: jal         0x800CEAA8
    // 0x800CF64C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEAA8(rdram, ctx);
        goto after_0;
    // 0x800CF64C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CF650: beq         $v0, $zero, L_800CF66C
    if (ctx->r2 == 0) {
        // 0x800CF654: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF66C;
    }
    // 0x800CF654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF658: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800CF65C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CF660: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800CF664: b           L_800CF670
    // 0x800CF668: lh          $v1, -0x4EA2($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4EA2);
        goto L_800CF670;
    // 0x800CF668: lh          $v1, -0x4EA2($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4EA2);
L_800CF66C:
    // 0x800CF66C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CF670:
    // 0x800CF670: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CF674: jr          $ra
    // 0x800CF678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CF678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80803D0C_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80803D10: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80803D14: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80803D18: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80803D1C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80803D20: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80803D24: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80803D28: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803D2C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80803D30: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80803D34: beq         $a1, $at, L_80803D90
    if (ctx->r5 == ctx->r1) {
        // 0x80803D38: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80803D90;
    }
    // 0x80803D38: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80803D3C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80803D40: beq         $a1, $at, L_80803D70
    if (ctx->r5 == ctx->r1) {
        // 0x80803D44: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80803D70;
    }
    // 0x80803D44: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80803D48: beq         $a1, $at, L_80803DC4
    if (ctx->r5 == ctx->r1) {
        // 0x80803D4C: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80803DC4;
    }
    // 0x80803D4C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80803D50: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80803D54: beq         $a1, $at, L_80803DA0
    if (ctx->r5 == ctx->r1) {
        // 0x80803D58: lw          $t6, 0x40($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X40);
            goto L_80803DA0;
    }
    // 0x80803D58: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80803D5C: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x80803D60: beq         $a1, $at, L_80803D80
    if (ctx->r5 == ctx->r1) {
        // 0x80803D64: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80803D80;
    }
    // 0x80803D64: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80803D68: b           L_80803E68
    // 0x80803D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803E68;
    // 0x80803D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803D70:
    // 0x80803D70: jal         0x808002FC
    // 0x80803D74: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808002FC_chintrochar(rdram, ctx);
        goto after_0;
    // 0x80803D74: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x80803D78: b           L_80803E68
    // 0x80803D7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803E68;
    // 0x80803D7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803D80:
    // 0x80803D80: jal         0x8080374C
    // 0x80803D84: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_8080374C_chintrochar(rdram, ctx);
        goto after_1;
    // 0x80803D84: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80803D88: b           L_80803E68
    // 0x80803D8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803E68;
    // 0x80803D8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803D90:
    // 0x80803D90: jal         0x80803888
    // 0x80803D94: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80803888_chintrochar(rdram, ctx);
        goto after_2;
    // 0x80803D94: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80803D98: b           L_80803E68
    // 0x80803D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803E68;
    // 0x80803D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803DA0:
    // 0x80803DA0: beq         $t6, $zero, L_80803DB0
    if (ctx->r14 == 0) {
        // 0x80803DA4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80803DB0;
    }
    // 0x80803DA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803DA8: bnel        $t6, $at, L_80803E68
    if (ctx->r14 != ctx->r1) {
        // 0x80803DAC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80803E68;
    }
    goto skip_0;
    // 0x80803DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_80803DB0:
    // 0x80803DB0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80803DB4: jal         0x80803418
    // 0x80803DB8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80803418_chintrochar(rdram, ctx);
        goto after_3;
    // 0x80803DB8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x80803DBC: b           L_80803E68
    // 0x80803DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803E68;
    // 0x80803DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803DC4:
    // 0x80803DC4: lhu         $t8, 0x76($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X76);
    // 0x80803DC8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X4160) << 16);
    // 0x80803DCC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80803DD0: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80803DD4: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80803DD8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80803DDC: lw          $v0, 0x4160($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1732, 0X4160));
    // 0x80803DE0: sll         $t1, $v0, 14
    ctx->r9 = S32(ctx->r2 << 14);
    // 0x80803DE4: bgezl       $t1, L_80803E68
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80803DE8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80803E68;
    }
    goto skip_1;
    // 0x80803DE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80803DEC: jal         0x80100094
    // 0x80803DF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80803DF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80803DF4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80803DF8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80803DFC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80803E00: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80803E04: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x80803E08: addiu       $s3, $sp, 0x38
    ctx->r19 = ADD32(ctx->r29, 0X38);
L_80803E0C:
    // 0x80803E0C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80803E10: addiu       $a0, $zero, 0x50A
    ctx->r4 = ADD32(0, 0X50A);
    // 0x80803E14: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80803E18: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80803E1C: jal         0x80108528
    // 0x80803E20: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_5;
    // 0x80803E20: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_5:
    // 0x80803E24: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80803E28: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80803E2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803E30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803E34: jal         0x80103110
    // 0x80803E38: sw          $t2, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->r10;
    func_80103110(rdram, ctx);
        goto after_6;
    // 0x80803E38: sw          $t2, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->r10;
    after_6:
    // 0x80803E3C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80803E40: jal         0x80102FDC
    // 0x80803E44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x80803E44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80803E48: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80803E4C: bne         $s0, $s4, L_80803E0C
    if (ctx->r16 != ctx->r20) {
        // 0x80803E50: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80803E0C;
    }
    // 0x80803E50: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80803E54: b           L_80803E68
    // 0x80803E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803E68;
    // 0x80803E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80803E5C: b           L_80803E68
    // 0x80803E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803E68;
    // 0x80803E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80803E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803E68:
    // 0x80803E68: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80803E6C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80803E70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80803E74: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80803E78: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80803E7C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80803E80: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80803E84: jr          $ra
    // 0x80803E88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80803E88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
