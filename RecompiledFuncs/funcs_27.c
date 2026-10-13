#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _ncbadie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089278: syscall     769
    recomp_syscall_handler(rdram, ctx, 0x80089278);
    return;
    // 0x8008927C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800014_chlavaarchgrillswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: jr          $ra
    // 0x80800018: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800018: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80099B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099B94: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80099B98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80099B9C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80099BA0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80099BA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80099BA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80099BAC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80099BB0: jal         0x8009E6F8
    // 0x80099BB4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x80099BB4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_0:
    // 0x80099BB8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80099BBC: jal         0x8009E6EC
    // 0x80099BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_1;
    // 0x80099BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80099BC4: addiu       $t6, $v0, -0x4
    ctx->r14 = ADD32(ctx->r2, -0X4);
    // 0x80099BC8: sltiu       $at, $t6, 0x97
    ctx->r1 = ctx->r14 < 0X97 ? 1 : 0;
    // 0x80099BCC: beq         $at, $zero, L_8009AB48
    if (ctx->r1 == 0) {
        // 0x80099BD0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8009AB48;
    }
    // 0x80099BD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80099BD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099BD8: addu        $at, $at, $t6
    gpr jr_addend_80099BE0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80099BDC: lw          $t6, 0x503C($at)
    ctx->r14 = ADD32(ctx->r1, 0X503C);
    // 0x80099BE0: jr          $t6
    // 0x80099BE4: nop

    switch (jr_addend_80099BE0 >> 2) {
        case 0: goto L_8009A5EC; break;
        case 1: goto L_8009A5EC; break;
        case 2: goto L_8009AB48; break;
        case 3: goto L_8009AB48; break;
        case 4: goto L_8009AB48; break;
        case 5: goto L_8009AB48; break;
        case 6: goto L_80099CC8; break;
        case 7: goto L_8009A098; break;
        case 8: goto L_8009A758; break;
        case 9: goto L_8009AB48; break;
        case 10: goto L_8009AB48; break;
        case 11: goto L_8009A9B8; break;
        case 12: goto L_8009AB48; break;
        case 13: goto L_8009A0F0; break;
        case 14: goto L_8009AB48; break;
        case 15: goto L_8009A08C; break;
        case 16: goto L_8009A580; break;
        case 17: goto L_8009A834; break;
        case 18: goto L_8009AB48; break;
        case 19: goto L_8009AB48; break;
        case 20: goto L_8009AB48; break;
        case 21: goto L_8009A0DC; break;
        case 22: goto L_8009A22C; break;
        case 23: goto L_8009A274; break;
        case 24: goto L_8009A814; break;
        case 25: goto L_8009A7F4; break;
        case 26: goto L_8009A7D4; break;
        case 27: goto L_8009A33C; break;
        case 28: goto L_8009A4C8; break;
        case 29: goto L_8009A39C; break;
        case 30: goto L_8009AB48; break;
        case 31: goto L_80099F70; break;
        case 32: goto L_80099F44; break;
        case 33: goto L_8009A8DC; break;
        case 34: goto L_8009A0B8; break;
        case 35: goto L_8009A730; break;
        case 36: goto L_8009AB48; break;
        case 37: goto L_8009A1E4; break;
        case 38: goto L_8009AA18; break;
        case 39: goto L_8009A19C; break;
        case 40: goto L_8009AB48; break;
        case 41: goto L_80099F9C; break;
        case 42: goto L_8009A508; break;
        case 43: goto L_80099EF8; break;
        case 44: goto L_8009A9D8; break;
        case 45: goto L_8009A36C; break;
        case 46: goto L_8009AB48; break;
        case 47: goto L_8009A3BC; break;
        case 48: goto L_8009A744; break;
        case 49: goto L_8009A5CC; break;
        case 50: goto L_8009AB48; break;
        case 51: goto L_8009AA04; break;
        case 52: goto L_8009A918; break;
        case 53: goto L_80099BE8; break;
        case 54: goto L_8009A60C; break;
        case 55: goto L_8009A674; break;
        case 56: goto L_8009A150; break;
        case 57: goto L_8009A7C4; break;
        case 58: goto L_8009A138; break;
        case 59: goto L_8009A168; break;
        case 60: goto L_8009A54C; break;
        case 61: goto L_8009A6A4; break;
        case 62: goto L_8009AB48; break;
        case 63: goto L_8009AB48; break;
        case 64: goto L_8009A080; break;
        case 65: goto L_8009A024; break;
        case 66: goto L_8009AB48; break;
        case 67: goto L_8009A2A4; break;
        case 68: goto L_8009AB48; break;
        case 69: goto L_8009AA3C; break;
        case 70: goto L_8009AA50; break;
        case 71: goto L_8009AB48; break;
        case 72: goto L_8009A120; break;
        case 73: goto L_8009A0FC; break;
        case 74: goto L_8009A408; break;
        case 75: goto L_8009AB48; break;
        case 76: goto L_8009AB48; break;
        case 77: goto L_80099CDC; break;
        case 78: goto L_80099D44; break;
        case 79: goto L_8009AB48; break;
        case 80: goto L_8009AB48; break;
        case 81: goto L_8009AB48; break;
        case 82: goto L_8009A06C; break;
        case 83: goto L_8009A058; break;
        case 84: goto L_8009AB48; break;
        case 85: goto L_8009A924; break;
        case 86: goto L_8009A944; break;
        case 87: goto L_8009A978; break;
        case 88: goto L_8009A998; break;
        case 89: goto L_80099EC0; break;
        case 90: goto L_80099C20; break;
        case 91: goto L_8009A184; break;
        case 92: goto L_8009A58C; break;
        case 93: goto L_8009AA64; break;
        case 94: goto L_8009AA80; break;
        case 95: goto L_8009AAA0; break;
        case 96: goto L_8009AB48; break;
        case 97: goto L_8009AB48; break;
        case 98: goto L_8009AAC0; break;
        case 99: goto L_8009AADC; break;
        case 100: goto L_80099FFC; break;
        case 101: goto L_80099C68; break;
        case 102: goto L_80099CF4; break;
        case 103: goto L_80099DBC; break;
        case 104: goto L_80099E48; break;
        case 105: goto L_8009AB48; break;
        case 106: goto L_8009AB48; break;
        case 107: goto L_80099DA0; break;
        case 108: goto L_8009AB48; break;
        case 109: goto L_8009AB48; break;
        case 110: goto L_8009AB48; break;
        case 111: goto L_8009AB48; break;
        case 112: goto L_8009AB48; break;
        case 113: goto L_8009AB48; break;
        case 114: goto L_8009AB48; break;
        case 115: goto L_8009AB48; break;
        case 116: goto L_8009AB48; break;
        case 117: goto L_8009AB48; break;
        case 118: goto L_8009AB48; break;
        case 119: goto L_8009AB48; break;
        case 120: goto L_8009A10C; break;
        case 121: goto L_8009AAF4; break;
        case 122: goto L_8009AB48; break;
        case 123: goto L_8009AB48; break;
        case 124: goto L_8009AB48; break;
        case 125: goto L_8009AB48; break;
        case 126: goto L_8009AB48; break;
        case 127: goto L_8009AB48; break;
        case 128: goto L_8009A560; break;
        case 129: goto L_8009AB48; break;
        case 130: goto L_8009AB48; break;
        case 131: goto L_8009AB48; break;
        case 132: goto L_8009AB48; break;
        case 133: goto L_80099FE4; break;
        case 134: goto L_8009A900; break;
        case 135: goto L_8009AA74; break;
        case 136: goto L_8009AB40; break;
        case 137: goto L_8009AB48; break;
        case 138: goto L_8009AB48; break;
        case 139: goto L_8009AB48; break;
        case 140: goto L_8009AB48; break;
        case 141: goto L_8009A538; break;
        case 142: goto L_80099F18; break;
        case 143: goto L_8009A8F0; break;
        case 144: goto L_8009AB48; break;
        case 145: goto L_8009A6B8; break;
        case 146: goto L_8009A710; break;
        case 147: goto L_8009A720; break;
        case 148: goto L_80099F9C; break;
        case 149: goto L_8009AB48; break;
        case 150: goto L_8009A964; break;
        default: switch_error(__func__, 0x80099BE0, 0x8012503C);
    }
    // 0x80099BE4: nop

L_80099BE8:
    // 0x80099BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099BEC: jal         0x80095760
    // 0x80099BF0: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    baflag_set(rdram, ctx);
        goto after_2;
    // 0x80099BF0: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_2:
    // 0x80099BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099BF8: jal         0x80095760
    // 0x80099BFC: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    baflag_set(rdram, ctx);
        goto after_3;
    // 0x80099BFC: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_3:
    // 0x80099C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099C04: jal         0x80095760
    // 0x80099C08: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    baflag_set(rdram, ctx);
        goto after_4;
    // 0x80099C08: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_4:
    // 0x80099C0C: jal         0x800848A8
    // 0x80099C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_5;
    // 0x80099C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80099C14: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099C18: b           L_8009AB48
    // 0x80099C1C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099C1C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099C20:
    // 0x80099C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099C24: jal         0x80095760
    // 0x80099C28: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    baflag_set(rdram, ctx);
        goto after_6;
    // 0x80099C28: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_6:
    // 0x80099C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099C30: jal         0x80095760
    // 0x80099C34: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    baflag_set(rdram, ctx);
        goto after_7;
    // 0x80099C34: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_7:
    // 0x80099C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099C3C: jal         0x80095760
    // 0x80099C40: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    baflag_set(rdram, ctx);
        goto after_8;
    // 0x80099C40: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_8:
    // 0x80099C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099C48: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80099C4C: jal         0x80084CD0
    // 0x80099C50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80099C50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80099C54: jal         0x800848A8
    // 0x80099C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_10;
    // 0x80099C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80099C5C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099C60: b           L_8009AB48
    // 0x80099C64: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099C64: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099C68:
    // 0x80099C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099C6C: jal         0x80095760
    // 0x80099C70: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    baflag_set(rdram, ctx);
        goto after_11;
    // 0x80099C70: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_11:
    // 0x80099C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099C78: jal         0x8009E71C
    // 0x80099C7C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8009E71C(rdram, ctx);
        goto after_12;
    // 0x80099C7C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_12:
    // 0x80099C80: beq         $v0, $zero, L_80099CB4
    if (ctx->r2 == 0) {
        // 0x80099C84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099CB4;
    }
    // 0x80099C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099C88: jal         0x80095760
    // 0x80099C8C: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    baflag_set(rdram, ctx);
        goto after_13;
    // 0x80099C8C: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_13:
    // 0x80099C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099C94: jal         0x80095760
    // 0x80099C98: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    baflag_set(rdram, ctx);
        goto after_14;
    // 0x80099C98: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_14:
    // 0x80099C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099CA0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80099CA4: jal         0x80084CD0
    // 0x80099CA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80099CA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80099CAC: b           L_8009AB48
    // 0x80099CB0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099CB0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099CB4:
    // 0x80099CB4: jal         0x800848A8
    // 0x80099CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_16;
    // 0x80099CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80099CBC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099CC0: b           L_8009AB48
    // 0x80099CC4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099CC4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099CC8:
    // 0x80099CC8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80099CCC: jal         0x800848C8
    // 0x80099CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_28(rdram, ctx);
        goto after_17;
    // 0x80099CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80099CD4: b           L_8009AB48
    // 0x80099CD8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8009AB48;
    // 0x80099CD8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80099CDC:
    // 0x80099CDC: jal         0x8008DD90
    // 0x80099CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD90(rdram, ctx);
        goto after_18;
    // 0x80099CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80099CE4: bne         $v0, $zero, L_8009AB48
    if (ctx->r2 != 0) {
        // 0x80099CE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x80099CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099CEC: jal         0x8009AD20
    // 0x80099CF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009AD20(rdram, ctx);
        goto after_19;
    // 0x80099CF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
L_80099CF4:
    // 0x80099CF4: jal         0x80099A58
    // 0x80099CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_20;
    // 0x80099CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80099CFC: beq         $v0, $zero, L_80099D0C
    if (ctx->r2 == 0) {
        // 0x80099D00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099D0C;
    }
    // 0x80099D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099D04: jal         0x800A17A8
    // 0x80099D08: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    func_800A17A8(rdram, ctx);
        goto after_21;
    // 0x80099D08: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    after_21:
L_80099D0C:
    // 0x80099D0C: jal         0x800A1718
    // 0x80099D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_22;
    // 0x80099D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80099D14: bne         $v0, $zero, L_80099D30
    if (ctx->r2 != 0) {
        // 0x80099D18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099D30;
    }
    // 0x80099D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099D1C: jal         0x80099840
    // 0x80099D20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80099840(rdram, ctx);
        goto after_23;
    // 0x80099D20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80099D24: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099D28: b           L_8009AB48
    // 0x80099D2C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099D2C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099D30:
    // 0x80099D30: jal         0x80084870
    // 0x80099D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_17(rdram, ctx);
        goto after_24;
    // 0x80099D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80099D38: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099D3C: b           L_8009AB48
    // 0x80099D40: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099D40: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099D44:
    // 0x80099D44: jal         0x80099A58
    // 0x80099D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_25;
    // 0x80099D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80099D4C: beq         $v0, $zero, L_80099D5C
    if (ctx->r2 == 0) {
        // 0x80099D50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099D5C;
    }
    // 0x80099D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099D54: jal         0x800A17A8
    // 0x80099D58: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    func_800A17A8(rdram, ctx);
        goto after_26;
    // 0x80099D58: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    after_26:
L_80099D5C:
    // 0x80099D5C: jal         0x800A1718
    // 0x80099D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_27;
    // 0x80099D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80099D64: bne         $v0, $zero, L_80099D84
    if (ctx->r2 != 0) {
        // 0x80099D68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099D84;
    }
    // 0x80099D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099D70: jal         0x80099840
    // 0x80099D74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80099840(rdram, ctx);
        goto after_28;
    // 0x80099D74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80099D78: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099D7C: b           L_8009AB48
    // 0x80099D80: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099D80: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099D84:
    // 0x80099D84: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x80099D88: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80099D8C: jal         0x80084888
    // 0x80099D90: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _badrone_entrypoint_20(rdram, ctx);
        goto after_29;
    // 0x80099D90: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_29:
    // 0x80099D94: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099D98: b           L_8009AB48
    // 0x80099D9C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099D9C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099DA0:
    // 0x80099DA0: lw          $t7, 0xC0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC0);
    // 0x80099DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099DA8: jal         0x80084878
    // 0x80099DAC: lw          $a1, 0x14($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X14);
    _badrone_entrypoint_18(rdram, ctx);
        goto after_30;
    // 0x80099DAC: lw          $a1, 0x14($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X14);
    after_30:
    // 0x80099DB0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099DB4: b           L_8009AB48
    // 0x80099DB8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099DB8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099DBC:
    // 0x80099DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099DC0: jal         0x80084CE0
    // 0x80099DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafpctrl_entrypoint_13(rdram, ctx);
        goto after_31;
    // 0x80099DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x80099DC8: jal         0x800A3404
    // 0x80099DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_32;
    // 0x80099DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80099DD0: beq         $v0, $zero, L_80099DE0
    if (ctx->r2 == 0) {
        // 0x80099DD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099DE0;
    }
    // 0x80099DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099DD8: jal         0x8009337C
    // 0x80099DDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009337C(rdram, ctx);
        goto after_33;
    // 0x80099DDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
L_80099DE0:
    // 0x80099DE0: jal         0x8008DAA8
    // 0x80099DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DAA8(rdram, ctx);
        goto after_34;
    // 0x80099DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80099DE8: beq         $v0, $zero, L_80099E40
    if (ctx->r2 == 0) {
        // 0x80099DEC: nop
    
            goto L_80099E40;
    }
    // 0x80099DEC: nop

    // 0x80099DF0: jal         0x800A3274
    // 0x80099DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_35;
    // 0x80099DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80099DF8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80099DFC: beq         $v0, $at, L_80099E40
    if (ctx->r2 == ctx->r1) {
        // 0x80099E00: nop
    
            goto L_80099E40;
    }
    // 0x80099E00: nop

    // 0x80099E04: jal         0x8008DD70
    // 0x80099E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD70(rdram, ctx);
        goto after_36;
    // 0x80099E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80099E0C: bne         $v0, $zero, L_80099E40
    if (ctx->r2 != 0) {
        // 0x80099E10: nop
    
            goto L_80099E40;
    }
    // 0x80099E10: nop

    // 0x80099E14: jal         0x800A9420
    // 0x80099E18: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800A9420(rdram, ctx);
        goto after_37;
    // 0x80099E18: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_37:
    // 0x80099E1C: bne         $v0, $zero, L_80099E40
    if (ctx->r2 != 0) {
        // 0x80099E20: nop
    
            goto L_80099E40;
    }
    // 0x80099E20: nop

    // 0x80099E24: jal         0x800878A0
    // 0x80099E28: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_38;
    // 0x80099E28: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_38:
    // 0x80099E2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80099E30: beq         $v0, $at, L_80099E40
    if (ctx->r2 == ctx->r1) {
        // 0x80099E34: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80099E40;
    }
    // 0x80099E34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80099E38: jal         0x800F7B9C
    // 0x80099E3C: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    func_800F7B9C(rdram, ctx);
        goto after_39;
    // 0x80099E3C: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    after_39:
L_80099E40:
    // 0x80099E40: b           L_8009AB48
    // 0x80099E44: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099E44: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099E48:
    // 0x80099E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099E4C: jal         0x80084CE0
    // 0x80099E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_13(rdram, ctx);
        goto after_40;
    // 0x80099E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x80099E54: jal         0x800A3404
    // 0x80099E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_41;
    // 0x80099E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80099E5C: beq         $v0, $zero, L_80099E6C
    if (ctx->r2 == 0) {
        // 0x80099E60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099E6C;
    }
    // 0x80099E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099E64: jal         0x8009337C
    // 0x80099E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009337C(rdram, ctx);
        goto after_42;
    // 0x80099E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_42:
L_80099E6C:
    // 0x80099E6C: jal         0x8008E124
    // 0x80099E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E124(rdram, ctx);
        goto after_43;
    // 0x80099E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80099E74: bne         $v0, $zero, L_80099EB8
    if (ctx->r2 != 0) {
        // 0x80099E78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099EB8;
    }
    // 0x80099E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099E7C: jal         0x8009E674
    // 0x80099E80: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8009E674(rdram, ctx);
        goto after_44;
    // 0x80099E80: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_44:
    // 0x80099E84: bne         $v0, $zero, L_80099EB8
    if (ctx->r2 != 0) {
        // 0x80099E88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099EB8;
    }
    // 0x80099E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099E8C: jal         0x8009E674
    // 0x80099E90: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8009E674(rdram, ctx);
        goto after_45;
    // 0x80099E90: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_45:
    // 0x80099E94: bne         $v0, $zero, L_80099EB8
    if (ctx->r2 != 0) {
        // 0x80099E98: nop
    
            goto L_80099EB8;
    }
    // 0x80099E98: nop

    // 0x80099E9C: jal         0x80084C98
    // 0x80099EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_46;
    // 0x80099EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x80099EA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80099EA8: bne         $v0, $at, L_80099EB8
    if (ctx->r2 != ctx->r1) {
        // 0x80099EAC: nop
    
            goto L_80099EB8;
    }
    // 0x80099EAC: nop

    // 0x80099EB0: jal         0x80084D10
    // 0x80099EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_19(rdram, ctx);
        goto after_47;
    // 0x80099EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
L_80099EB8:
    // 0x80099EB8: b           L_8009AB48
    // 0x80099EBC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099EBC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099EC0:
    // 0x80099EC0: lw          $t8, 0xC0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC0);
    // 0x80099EC4: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x80099EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099ECC: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x80099ED0: beq         $t9, $zero, L_80099EE8
    if (ctx->r25 == 0) {
        // 0x80099ED4: nop
    
            goto L_80099EE8;
    }
    // 0x80099ED4: nop

    // 0x80099ED8: jal         0x80095760
    // 0x80099EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baflag_set(rdram, ctx);
        goto after_48;
    // 0x80099EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80099EE0: b           L_8009AB48
    // 0x80099EE4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099EE4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099EE8:
    // 0x80099EE8: jal         0x80095774
    // 0x80099EEC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    baflag_clear(rdram, ctx);
        goto after_49;
    // 0x80099EEC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_49:
    // 0x80099EF0: b           L_8009AB48
    // 0x80099EF4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099EF4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099EF8:
    // 0x80099EF8: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x80099EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099F00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80099F04: jal         0x80084888
    // 0x80099F08: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _badrone_entrypoint_20(rdram, ctx);
        goto after_50;
    // 0x80099F08: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_50:
    // 0x80099F0C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099F10: b           L_8009AB48
    // 0x80099F14: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099F14: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099F18:
    // 0x80099F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099F1C: jal         0x800A17A8
    // 0x80099F20: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_51;
    // 0x80099F20: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_51:
    // 0x80099F24: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x80099F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099F2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80099F30: jal         0x80084888
    // 0x80099F34: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _badrone_entrypoint_20(rdram, ctx);
        goto after_52;
    // 0x80099F34: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_52:
    // 0x80099F38: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099F3C: b           L_8009AB48
    // 0x80099F40: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099F40: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099F44:
    // 0x80099F44: jal         0x8008DD90
    // 0x80099F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD90(rdram, ctx);
        goto after_53;
    // 0x80099F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80099F4C: bne         $v0, $zero, L_8009AB48
    if (ctx->r2 != 0) {
        // 0x80099F50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x80099F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099F54: jal         0x800995B8
    // 0x80099F58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800995B8(rdram, ctx);
        goto after_54;
    // 0x80099F58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_54:
    // 0x80099F5C: jal         0x80084718
    // 0x80099F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_27(rdram, ctx);
        goto after_55;
    // 0x80099F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80099F64: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099F68: b           L_8009AB48
    // 0x80099F6C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099F6C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099F70:
    // 0x80099F70: jal         0x8008DD90
    // 0x80099F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD90(rdram, ctx);
        goto after_56;
    // 0x80099F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x80099F78: bne         $v0, $zero, L_8009AB48
    if (ctx->r2 != 0) {
        // 0x80099F7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x80099F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099F80: jal         0x800995B8
    // 0x80099F84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800995B8(rdram, ctx);
        goto after_57;
    // 0x80099F84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_57:
    // 0x80099F88: jal         0x80084718
    // 0x80099F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_27(rdram, ctx);
        goto after_58;
    // 0x80099F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80099F90: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099F94: b           L_8009AB48
    // 0x80099F98: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099F98: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099F9C:
    // 0x80099F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099FA0: jal         0x800995B8
    // 0x80099FA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800995B8(rdram, ctx);
        goto after_59;
    // 0x80099FA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_59:
    // 0x80099FA8: jal         0x8008E35C
    // 0x80099FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_60;
    // 0x80099FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80099FB0: beq         $v0, $zero, L_80099FD0
    if (ctx->r2 == 0) {
        // 0x80099FB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099FD0;
    }
    // 0x80099FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099FB8: jal         0x8009E71C
    // 0x80099FBC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8009E71C(rdram, ctx);
        goto after_61;
    // 0x80099FBC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_61:
    // 0x80099FC0: beq         $v0, $zero, L_80099FD0
    if (ctx->r2 == 0) {
        // 0x80099FC4: addiu       $s2, $zero, 0xA2
        ctx->r18 = ADD32(0, 0XA2);
            goto L_80099FD0;
    }
    // 0x80099FC4: addiu       $s2, $zero, 0xA2
    ctx->r18 = ADD32(0, 0XA2);
    // 0x80099FC8: b           L_8009AB48
    // 0x80099FCC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099FCC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099FD0:
    // 0x80099FD0: jal         0x80084718
    // 0x80099FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_27(rdram, ctx);
        goto after_62;
    // 0x80099FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x80099FD8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80099FDC: b           L_8009AB48
    // 0x80099FE0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099FE0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099FE4:
    // 0x80099FE4: lw          $t0, 0xC0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC0);
    // 0x80099FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099FEC: jal         0x800845F0
    // 0x80099FF0: lw          $a1, 0x14($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X14);
    _babounce_entrypoint_7(rdram, ctx);
        goto after_63;
    // 0x80099FF0: lw          $a1, 0x14($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X14);
    after_63:
    // 0x80099FF4: b           L_8009AB48
    // 0x80099FF8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x80099FF8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80099FFC:
    // 0x80099FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A000: jal         0x800995B8
    // 0x8009A004: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800995B8(rdram, ctx);
        goto after_64;
    // 0x8009A004: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_64:
    // 0x8009A008: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A00C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A010: jal         0x80084898
    // 0x8009A014: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _badrone_entrypoint_22(rdram, ctx);
        goto after_65;
    // 0x8009A014: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_65:
    // 0x8009A018: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A01C: b           L_8009AB48
    // 0x8009A020: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A020: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A024:
    // 0x8009A024: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x8009A028: jal         0x800F64A4
    // 0x8009A02C: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_66;
    // 0x8009A02C: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_66:
    // 0x8009A030: beq         $v0, $zero, L_8009A044
    if (ctx->r2 == 0) {
        // 0x8009A034: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009A044;
    }
    // 0x8009A034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A038: addiu       $s2, $zero, 0x120
    ctx->r18 = ADD32(0, 0X120);
    // 0x8009A03C: b           L_8009AB48
    // 0x8009A040: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A040: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A044:
    // 0x8009A044: jal         0x80099840
    // 0x8009A048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80099840(rdram, ctx);
        goto after_67;
    // 0x8009A048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_67:
    // 0x8009A04C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A050: b           L_8009AB48
    // 0x8009A054: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A054: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A058:
    // 0x8009A058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A05C: jal         0x80084630
    // 0x8009A060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bacough_entrypoint_4(rdram, ctx);
        goto after_68;
    // 0x8009A060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_68:
    // 0x8009A064: b           L_8009AB48
    // 0x8009A068: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A068: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A06C:
    // 0x8009A06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A070: jal         0x80084630
    // 0x8009A074: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bacough_entrypoint_4(rdram, ctx);
        goto after_69;
    // 0x8009A074: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_69:
    // 0x8009A078: b           L_8009AB48
    // 0x8009A07C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A07C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A080:
    // 0x8009A080: addiu       $s2, $zero, 0x11F
    ctx->r18 = ADD32(0, 0X11F);
    // 0x8009A084: b           L_8009AB48
    // 0x8009A088: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A088: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A08C:
    // 0x8009A08C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A090: jal         0x800A17A8
    // 0x8009A094: addiu       $a1, $zero, -0x3E7
    ctx->r5 = ADD32(0, -0X3E7);
    func_800A17A8(rdram, ctx);
        goto after_70;
    // 0x8009A094: addiu       $a1, $zero, -0x3E7
    ctx->r5 = ADD32(0, -0X3E7);
    after_70:
L_8009A098:
    // 0x8009A098: jal         0x800997BC
    // 0x8009A09C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800997BC(rdram, ctx);
        goto after_71;
    // 0x8009A09C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_71:
    // 0x8009A0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A0A4: jal         0x80099840
    // 0x8009A0A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80099840(rdram, ctx);
        goto after_72;
    // 0x8009A0A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_72:
    // 0x8009A0AC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A0B0: b           L_8009AB48
    // 0x8009A0B4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A0B4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A0B8:
    // 0x8009A0B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A0BC: jal         0x800A17A8
    // 0x8009A0C0: addiu       $a1, $zero, -0x3E7
    ctx->r5 = ADD32(0, -0X3E7);
    func_800A17A8(rdram, ctx);
        goto after_73;
    // 0x8009A0C0: addiu       $a1, $zero, -0x3E7
    ctx->r5 = ADD32(0, -0X3E7);
    after_73:
    // 0x8009A0C4: jal         0x80085208
    // 0x8009A0C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_74;
    // 0x8009A0C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_74:
    // 0x8009A0CC: jal         0x80085200
    // 0x8009A0D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_75;
    // 0x8009A0D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_75:
    // 0x8009A0D4: b           L_8009AB48
    // 0x8009A0D8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A0D8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A0DC:
    // 0x8009A0DC: jal         0x8009F354
    // 0x8009A0E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F354(rdram, ctx);
        goto after_76;
    // 0x8009A0E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_76:
    // 0x8009A0E4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A0E8: b           L_8009AB48
    // 0x8009A0EC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A0EC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A0F0:
    // 0x8009A0F0: addiu       $s2, $zero, 0x54
    ctx->r18 = ADD32(0, 0X54);
    // 0x8009A0F4: b           L_8009AB48
    // 0x8009A0F8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A0F8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A0FC:
    // 0x8009A0FC: jal         0x800844E0
    // 0x8009A100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_14(rdram, ctx);
        goto after_77;
    // 0x8009A100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_77:
    // 0x8009A104: b           L_8009AB48
    // 0x8009A108: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A108: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A10C:
    // 0x8009A10C: jal         0x80084880
    // 0x8009A110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_19(rdram, ctx);
        goto after_78;
    // 0x8009A110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x8009A114: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A118: b           L_8009AB48
    // 0x8009A11C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A11C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A120:
    // 0x8009A120: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A128: jal         0x80084990
    // 0x8009A12C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _baduo_entrypoint_15(rdram, ctx);
        goto after_79;
    // 0x8009A12C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_79:
    // 0x8009A130: b           L_8009AB48
    // 0x8009A134: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A134: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A138:
    // 0x8009A138: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A13C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A140: jal         0x800849A0
    // 0x8009A144: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _baduo_entrypoint_17(rdram, ctx);
        goto after_80;
    // 0x8009A144: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_80:
    // 0x8009A148: b           L_8009AB48
    // 0x8009A14C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A14C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A150:
    // 0x8009A150: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A158: jal         0x800849A8
    // 0x8009A15C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _baduo_entrypoint_18(rdram, ctx);
        goto after_81;
    // 0x8009A15C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_81:
    // 0x8009A160: b           L_8009AB48
    // 0x8009A164: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A164: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A168:
    // 0x8009A168: lw          $v0, 0xC0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A170: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x8009A174: jal         0x800849B8
    // 0x8009A178: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    _baduo_entrypoint_20(rdram, ctx);
        goto after_82;
    // 0x8009A178: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    after_82:
    // 0x8009A17C: b           L_8009AB48
    // 0x8009A180: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A180: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A184:
    // 0x8009A184: lw          $t1, 0xC0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A18C: jal         0x80094430
    // 0x8009A190: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    func_80094430(rdram, ctx);
        goto after_83;
    // 0x8009A190: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    after_83:
    // 0x8009A194: b           L_8009AB48
    // 0x8009A198: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A198: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A19C:
    // 0x8009A19C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A1A0: jal         0x80095760
    // 0x8009A1A4: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    baflag_set(rdram, ctx);
        goto after_84;
    // 0x8009A1A4: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_84:
    // 0x8009A1A8: lw          $t2, 0xC0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A1AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A1B0: jal         0x80085038
    // 0x8009A1B4: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    _bashoes_entrypoint_12(rdram, ctx);
        goto after_85;
    // 0x8009A1B4: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    after_85:
    // 0x8009A1B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A1BC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8009A1C0: jal         0x8009CA70
    // 0x8009A1C4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8009CA70(rdram, ctx);
        goto after_86;
    // 0x8009A1C4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_86:
    // 0x8009A1C8: bne         $v0, $zero, L_8009A1DC
    if (ctx->r2 != 0) {
        // 0x8009A1CC: nop
    
            goto L_8009A1DC;
    }
    // 0x8009A1CC: nop

    // 0x8009A1D0: jal         0x8009F354
    // 0x8009A1D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F354(rdram, ctx);
        goto after_87;
    // 0x8009A1D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_87:
    // 0x8009A1D8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A1DC:
    // 0x8009A1DC: b           L_8009AB48
    // 0x8009A1E0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A1E0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A1E4:
    // 0x8009A1E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A1E8: jal         0x80095760
    // 0x8009A1EC: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    baflag_set(rdram, ctx);
        goto after_88;
    // 0x8009A1EC: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_88:
    // 0x8009A1F0: lw          $t3, 0xC0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A1F8: jal         0x80085038
    // 0x8009A1FC: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    _bashoes_entrypoint_12(rdram, ctx);
        goto after_89;
    // 0x8009A1FC: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    after_89:
    // 0x8009A200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A204: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8009A208: jal         0x8009CA70
    // 0x8009A20C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8009CA70(rdram, ctx);
        goto after_90;
    // 0x8009A20C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_90:
    // 0x8009A210: bne         $v0, $zero, L_8009A224
    if (ctx->r2 != 0) {
        // 0x8009A214: nop
    
            goto L_8009A224;
    }
    // 0x8009A214: nop

    // 0x8009A218: jal         0x8009F354
    // 0x8009A21C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F354(rdram, ctx);
        goto after_91;
    // 0x8009A21C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_91:
    // 0x8009A220: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A224:
    // 0x8009A224: b           L_8009AB48
    // 0x8009A228: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A228: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A22C:
    // 0x8009A22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A230: jal         0x80095760
    // 0x8009A234: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    baflag_set(rdram, ctx);
        goto after_92;
    // 0x8009A234: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_92:
    // 0x8009A238: lw          $t4, 0xC0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A240: jal         0x80085038
    // 0x8009A244: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    _bashoes_entrypoint_12(rdram, ctx);
        goto after_93;
    // 0x8009A244: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    after_93:
    // 0x8009A248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A24C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8009A250: jal         0x8009CA70
    // 0x8009A254: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8009CA70(rdram, ctx);
        goto after_94;
    // 0x8009A254: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_94:
    // 0x8009A258: bne         $v0, $zero, L_8009A26C
    if (ctx->r2 != 0) {
        // 0x8009A25C: nop
    
            goto L_8009A26C;
    }
    // 0x8009A25C: nop

    // 0x8009A260: jal         0x8009F354
    // 0x8009A264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F354(rdram, ctx);
        goto after_95;
    // 0x8009A264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_95:
    // 0x8009A268: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A26C:
    // 0x8009A26C: b           L_8009AB48
    // 0x8009A270: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A270: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A274:
    // 0x8009A274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A278: jal         0x80095760
    // 0x8009A27C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    baflag_set(rdram, ctx);
        goto after_96;
    // 0x8009A27C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_96:
    // 0x8009A280: lw          $t5, 0xC0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A288: jal         0x800A391C
    // 0x8009A28C: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    func_800A391C(rdram, ctx);
        goto after_97;
    // 0x8009A28C: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    after_97:
    // 0x8009A290: jal         0x8009F354
    // 0x8009A294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F354(rdram, ctx);
        goto after_98;
    // 0x8009A294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_98:
    // 0x8009A298: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A29C: b           L_8009AB48
    // 0x8009A2A0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A2A0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A2A4:
    // 0x8009A2A4: jal         0x80099A4C
    // 0x8009A2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A4C(rdram, ctx);
        goto after_99;
    // 0x8009A2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_99:
    // 0x8009A2AC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8009A2B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009A2B4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8009A2B8: jal         0x8008A3A8
    // 0x8009A2BC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    _suegg_entrypoint_6(rdram, ctx);
        goto after_100;
    // 0x8009A2BC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_100:
    // 0x8009A2C0: jal         0x800883F0
    // 0x8009A2C4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    _gcegg_entrypoint_7(rdram, ctx);
        goto after_101;
    // 0x8009A2C4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_101:
    // 0x8009A2C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A2CC: jal         0x8009AD20
    // 0x8009A2D0: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
    func_8009AD20(rdram, ctx);
        goto after_102;
    // 0x8009A2D0: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
    after_102:
    // 0x8009A2D4: jal         0x8009BD44
    // 0x8009A2D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD44(rdram, ctx);
        goto after_103;
    // 0x8009A2D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_103:
    // 0x8009A2DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009A2E0: beql        $v0, $at, L_8009AB4C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A2E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB4C;
    }
    goto skip_0;
    // 0x8009A2E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8009A2E8: jal         0x8008DD90
    // 0x8009A2EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD90(rdram, ctx);
        goto after_104;
    // 0x8009A2EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_104:
    // 0x8009A2F0: bne         $v0, $zero, L_8009AB48
    if (ctx->r2 != 0) {
        // 0x8009A2F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x8009A2F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A2F8: jal         0x800995B8
    // 0x8009A2FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800995B8(rdram, ctx);
        goto after_105;
    // 0x8009A2FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_105:
    // 0x8009A300: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8009A304: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8009A308: jal         0x8010114C
    // 0x8009A30C: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    func_8010114C(rdram, ctx);
        goto after_106;
    // 0x8009A30C: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    after_106:
    // 0x8009A310: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009A314: beq         $v0, $at, L_8009A324
    if (ctx->r2 == ctx->r1) {
        // 0x8009A318: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009A324;
    }
    // 0x8009A318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A31C: jal         0x800A17A8
    // 0x8009A320: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_107;
    // 0x8009A320: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_107:
L_8009A324:
    // 0x8009A324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A328: jal         0x80099840
    // 0x8009A32C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80099840(rdram, ctx);
        goto after_108;
    // 0x8009A32C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_108:
    // 0x8009A330: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A334: b           L_8009AB48
    // 0x8009A338: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A338: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A33C:
    // 0x8009A33C: jal         0x8009BD44
    // 0x8009A340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD44(rdram, ctx);
        goto after_109;
    // 0x8009A340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_109:
    // 0x8009A344: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009A348: beql        $v0, $at, L_8009AB4C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A34C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB4C;
    }
    goto skip_1;
    // 0x8009A34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8009A350: jal         0x8008DD90
    // 0x8009A354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD90(rdram, ctx);
        goto after_110;
    // 0x8009A354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_110:
    // 0x8009A358: bnel        $v0, $zero, L_8009AB4C
    if (ctx->r2 != 0) {
        // 0x8009A35C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB4C;
    }
    goto skip_2;
    // 0x8009A35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8009A360: jal         0x8008E974
    // 0x8009A364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E974(rdram, ctx);
        goto after_111;
    // 0x8009A364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_111:
    // 0x8009A368: beq         $v0, $zero, L_8009AB48
    if (ctx->r2 == 0) {
        // 0x8009A36C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
L_8009A36C:
    // 0x8009A36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A370: jal         0x800995B8
    // 0x8009A374: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800995B8(rdram, ctx);
        goto after_112;
    // 0x8009A374: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_112:
    // 0x8009A378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A37C: jal         0x800A17A8
    // 0x8009A380: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_113;
    // 0x8009A380: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_113:
    // 0x8009A384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A388: jal         0x80099840
    // 0x8009A38C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80099840(rdram, ctx);
        goto after_114;
    // 0x8009A38C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_114:
    // 0x8009A390: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A394: b           L_8009AB48
    // 0x8009A398: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A398: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A39C:
    // 0x8009A39C: jal         0x8009BD44
    // 0x8009A3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD44(rdram, ctx);
        goto after_115;
    // 0x8009A3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_115:
    // 0x8009A3A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009A3A8: beql        $v0, $at, L_8009AB4C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A3AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB4C;
    }
    goto skip_3;
    // 0x8009A3AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8009A3B0: jal         0x8008DD90
    // 0x8009A3B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD90(rdram, ctx);
        goto after_116;
    // 0x8009A3B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_116:
    // 0x8009A3B8: bne         $v0, $zero, L_8009AB48
    if (ctx->r2 != 0) {
        // 0x8009A3BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
L_8009A3BC:
    // 0x8009A3BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A3C0: jal         0x800995B8
    // 0x8009A3C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800995B8(rdram, ctx);
        goto after_117;
    // 0x8009A3C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_117:
    // 0x8009A3C8: lw          $t6, 0xC0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A3CC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8009A3D0: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    // 0x8009A3D4: jal         0x8010114C
    // 0x8009A3D8: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    func_8010114C(rdram, ctx);
        goto after_118;
    // 0x8009A3D8: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    after_118:
    // 0x8009A3DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009A3E0: beq         $v0, $at, L_8009A3F0
    if (ctx->r2 == ctx->r1) {
        // 0x8009A3E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009A3F0;
    }
    // 0x8009A3E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A3E8: jal         0x800A17A8
    // 0x8009A3EC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_119;
    // 0x8009A3EC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_119:
L_8009A3F0:
    // 0x8009A3F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A3F4: jal         0x80099840
    // 0x8009A3F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80099840(rdram, ctx);
        goto after_120;
    // 0x8009A3F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_120:
    // 0x8009A3FC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A400: b           L_8009AB48
    // 0x8009A404: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A404: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A408:
    // 0x8009A408: jal         0x8009BD44
    // 0x8009A40C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD44(rdram, ctx);
        goto after_121;
    // 0x8009A40C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_121:
    // 0x8009A410: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009A414: beq         $v0, $at, L_8009AB48
    if (ctx->r2 == ctx->r1) {
        // 0x8009A418: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x8009A418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A41C: jal         0x800995B8
    // 0x8009A420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800995B8(rdram, ctx);
        goto after_122;
    // 0x8009A420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_122:
    // 0x8009A424: jal         0x80099A58
    // 0x8009A428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_123;
    // 0x8009A428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_123:
    // 0x8009A42C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A430: jal         0x800A17A8
    // 0x8009A434: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    func_800A17A8(rdram, ctx);
        goto after_124;
    // 0x8009A434: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    after_124:
    // 0x8009A438: lw          $t7, 0x158($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X158);
    // 0x8009A43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A440: beq         $t7, $zero, L_8009A4B4
    if (ctx->r15 == 0) {
        // 0x8009A444: nop
    
            goto L_8009A4B4;
    }
    // 0x8009A444: nop

    // 0x8009A448: jal         0x800A1718
    // 0x8009A44C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_125;
    // 0x8009A44C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_125:
    // 0x8009A450: bne         $v0, $zero, L_8009A478
    if (ctx->r2 != 0) {
        // 0x8009A454: nop
    
            goto L_8009A478;
    }
    // 0x8009A454: nop

    // 0x8009A458: jal         0x80099A70
    // 0x8009A45C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A70(rdram, ctx);
        goto after_126;
    // 0x8009A45C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_126:
    // 0x8009A460: lw          $t8, 0x184($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X184);
    // 0x8009A464: addiu       $a0, $zero, 0x2C4
    ctx->r4 = ADD32(0, 0X2C4);
    // 0x8009A468: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x8009A46C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8009A470: jal         0x80101180
    // 0x8009A474: or          $a2, $v0, $t9
    ctx->r6 = ctx->r2 | ctx->r25;
    func_80101180(rdram, ctx);
        goto after_127;
    // 0x8009A474: or          $a2, $v0, $t9
    ctx->r6 = ctx->r2 | ctx->r25;
    after_127:
L_8009A478:
    // 0x8009A478: jal         0x800A3274
    // 0x8009A47C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_128;
    // 0x8009A47C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_128:
    // 0x8009A480: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8009A484: bne         $v0, $at, L_8009A4A0
    if (ctx->r2 != ctx->r1) {
        // 0x8009A488: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009A4A0;
    }
    // 0x8009A488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A48C: jal         0x80084710
    // 0x8009A490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_26(rdram, ctx);
        goto after_129;
    // 0x8009A490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_129:
    // 0x8009A494: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A498: b           L_8009AB48
    // 0x8009A49C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A49C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A4A0:
    // 0x8009A4A0: jal         0x80099840
    // 0x8009A4A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80099840(rdram, ctx);
        goto after_130;
    // 0x8009A4A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_130:
    // 0x8009A4A8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A4AC: b           L_8009AB48
    // 0x8009A4B0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A4B0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A4B4:
    // 0x8009A4B4: jal         0x80099840
    // 0x8009A4B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80099840(rdram, ctx);
        goto after_131;
    // 0x8009A4B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_131:
    // 0x8009A4BC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A4C0: b           L_8009AB48
    // 0x8009A4C4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A4C4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A4C8:
    // 0x8009A4C8: jal         0x8009BD44
    // 0x8009A4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD44(rdram, ctx);
        goto after_132;
    // 0x8009A4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_132:
    // 0x8009A4D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009A4D4: beq         $v0, $at, L_8009AB48
    if (ctx->r2 == ctx->r1) {
        // 0x8009A4D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x8009A4D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A4DC: jal         0x800995B8
    // 0x8009A4E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800995B8(rdram, ctx);
        goto after_133;
    // 0x8009A4E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_133:
    // 0x8009A4E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A4E8: jal         0x800A17A8
    // 0x8009A4EC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_134;
    // 0x8009A4EC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_134:
    // 0x8009A4F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A4F4: jal         0x80099840
    // 0x8009A4F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80099840(rdram, ctx);
        goto after_135;
    // 0x8009A4F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_135:
    // 0x8009A4FC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A500: b           L_8009AB48
    // 0x8009A504: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A504: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A508:
    // 0x8009A508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A50C: jal         0x800995B8
    // 0x8009A510: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800995B8(rdram, ctx);
        goto after_136;
    // 0x8009A510: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_136:
    // 0x8009A514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A518: jal         0x800A17A8
    // 0x8009A51C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_137;
    // 0x8009A51C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_137:
    // 0x8009A520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A524: jal         0x80099840
    // 0x8009A528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80099840(rdram, ctx);
        goto after_138;
    // 0x8009A528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_138:
    // 0x8009A52C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A530: b           L_8009AB48
    // 0x8009A534: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A534: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A538:
    // 0x8009A538: jal         0x80084890
    // 0x8009A53C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_21(rdram, ctx);
        goto after_139;
    // 0x8009A53C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_139:
    // 0x8009A540: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A544: b           L_8009AB48
    // 0x8009A548: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A548: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A54C:
    // 0x8009A54C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A550: jal         0x80084970
    // 0x8009A554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baduo_entrypoint_11(rdram, ctx);
        goto after_140;
    // 0x8009A554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_140:
    // 0x8009A558: b           L_8009AB48
    // 0x8009A55C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A55C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A560:
    // 0x8009A560: lw          $t0, 0xC0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A568: jal         0x800A3970
    // 0x8009A56C: lw          $a1, 0x18($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X18);
    func_800A3970(rdram, ctx);
        goto after_141;
    // 0x8009A56C: lw          $a1, 0x18($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X18);
    after_141:
    // 0x8009A570: beql        $v0, $zero, L_8009AB4C
    if (ctx->r2 == 0) {
        // 0x8009A574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB4C;
    }
    goto skip_4;
    // 0x8009A574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x8009A578: b           L_8009AB48
    // 0x8009A57C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A57C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A580:
    // 0x8009A580: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x8009A584: b           L_8009AB48
    // 0x8009A588: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A588: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A58C:
    // 0x8009A58C: jal         0x800F911C
    // 0x8009A590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F911C(rdram, ctx);
        goto after_142;
    // 0x8009A590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_142:
    // 0x8009A594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A598: jal         0x80084950
    // 0x8009A59C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baduo_entrypoint_7(rdram, ctx);
        goto after_143;
    // 0x8009A59C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_143:
    // 0x8009A5A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A5A4: jal         0x800A0CF4
    // 0x8009A5A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_144;
    // 0x8009A5A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_144:
    // 0x8009A5AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A5B0: jal         0x800A3410
    // 0x8009A5B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3410(rdram, ctx);
        goto after_145;
    // 0x8009A5B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_145:
    // 0x8009A5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A5BC: jal         0x800A3904
    // 0x8009A5C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3904(rdram, ctx);
        goto after_146;
    // 0x8009A5C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_146:
    // 0x8009A5C4: b           L_8009AB4C
    // 0x8009A5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8009AB4C;
    // 0x8009A5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009A5CC:
    // 0x8009A5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A5D0: jal         0x80095760
    // 0x8009A5D4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    baflag_set(rdram, ctx);
        goto after_147;
    // 0x8009A5D4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_147:
    // 0x8009A5D8: jal         0x8009F354
    // 0x8009A5DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F354(rdram, ctx);
        goto after_148;
    // 0x8009A5DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_148:
    // 0x8009A5E0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A5E4: b           L_8009AB48
    // 0x8009A5E8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A5E8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A5EC:
    // 0x8009A5EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A5F0: jal         0x80084968
    // 0x8009A5F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baduo_entrypoint_10(rdram, ctx);
        goto after_149;
    // 0x8009A5F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_149:
    // 0x8009A5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A5FC: jal         0x80084970
    // 0x8009A600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baduo_entrypoint_11(rdram, ctx);
        goto after_150;
    // 0x8009A600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_150:
    // 0x8009A604: b           L_8009AB48
    // 0x8009A608: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A608: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A60C:
    // 0x8009A60C: jal         0x8008E23C
    // 0x8009A610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E23C(rdram, ctx);
        goto after_151;
    // 0x8009A610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_151:
    // 0x8009A614: beq         $v0, $zero, L_8009A62C
    if (ctx->r2 == 0) {
        // 0x8009A618: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009A62C;
    }
    // 0x8009A618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A61C: jal         0x80084970
    // 0x8009A620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baduo_entrypoint_11(rdram, ctx);
        goto after_152;
    // 0x8009A620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_152:
    // 0x8009A624: b           L_8009AB48
    // 0x8009A628: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A628: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A62C:
    // 0x8009A62C: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A634: jal         0x80084958
    // 0x8009A638: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _baduo_entrypoint_8(rdram, ctx);
        goto after_153;
    // 0x8009A638: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_153:
    // 0x8009A63C: lw          $t1, 0xC0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A640: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009A644: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009A648: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8009A64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A650: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009A654: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8009A658: jal         0x80084960
    // 0x8009A65C: nop

    _baduo_entrypoint_9(rdram, ctx);
        goto after_154;
    // 0x8009A65C: nop

    after_154:
    // 0x8009A660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A664: jal         0x80084968
    // 0x8009A668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baduo_entrypoint_10(rdram, ctx);
        goto after_155;
    // 0x8009A668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_155:
    // 0x8009A66C: b           L_8009AB48
    // 0x8009A670: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A670: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A674:
    // 0x8009A674: jal         0x8008E23C
    // 0x8009A678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E23C(rdram, ctx);
        goto after_156;
    // 0x8009A678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_156:
    // 0x8009A67C: beq         $v0, $zero, L_8009AB48
    if (ctx->r2 == 0) {
        // 0x8009A680: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x8009A680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A684: jal         0x80084970
    // 0x8009A688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baduo_entrypoint_11(rdram, ctx);
        goto after_157;
    // 0x8009A688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_157:
    // 0x8009A68C: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A694: jal         0x80084958
    // 0x8009A698: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _baduo_entrypoint_8(rdram, ctx);
        goto after_158;
    // 0x8009A698: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_158:
    // 0x8009A69C: b           L_8009AB48
    // 0x8009A6A0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A6A0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A6A4:
    // 0x8009A6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A6A8: jal         0x80084970
    // 0x8009A6AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baduo_entrypoint_11(rdram, ctx);
        goto after_159;
    // 0x8009A6AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_159:
    // 0x8009A6B0: b           L_8009AB48
    // 0x8009A6B4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A6B4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A6B8:
    // 0x8009A6B8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8009A6BC: jal         0x8009EC08
    // 0x8009A6C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8009EC08(rdram, ctx);
        goto after_160;
    // 0x8009A6C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_160:
    // 0x8009A6C4: jal         0x80099A58
    // 0x8009A6C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_161;
    // 0x8009A6C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_161:
    // 0x8009A6CC: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
    // 0x8009A6D0: jal         0x80099A64
    // 0x8009A6D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A64(rdram, ctx);
        goto after_162;
    // 0x8009A6D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_162:
    // 0x8009A6D8: lh          $t2, 0x3C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3C);
    // 0x8009A6DC: lh          $t3, 0x3E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X3E);
    // 0x8009A6E0: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x8009A6E4: lh          $t4, 0x38($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X38);
    // 0x8009A6E8: bne         $t2, $t3, L_8009A6FC
    if (ctx->r10 != ctx->r11) {
        // 0x8009A6EC: sll         $t5, $v0, 16
        ctx->r13 = S32(ctx->r2 << 16);
            goto L_8009A6FC;
    }
    // 0x8009A6EC: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x8009A6F0: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8009A6F4: beq         $t4, $t6, L_8009A708
    if (ctx->r12 == ctx->r14) {
        // 0x8009A6F8: nop
    
            goto L_8009A708;
    }
    // 0x8009A6F8: nop

L_8009A6FC:
    // 0x8009A6FC: lh          $a0, 0x3E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3E);
    // 0x8009A700: jal         0x8009EB24
    // 0x8009A704: lh          $a1, 0x3A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3A);
    func_8009EB24(rdram, ctx);
        goto after_163;
    // 0x8009A704: lh          $a1, 0x3A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3A);
    after_163:
L_8009A708:
    // 0x8009A708: b           L_8009AB48
    // 0x8009A70C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A70C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A710:
    // 0x8009A710: jal         0x8009EBD0
    // 0x8009A714: nop

    func_8009EBD0(rdram, ctx);
        goto after_164;
    // 0x8009A714: nop

    after_164:
    // 0x8009A718: b           L_8009AB48
    // 0x8009A71C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A71C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A720:
    // 0x8009A720: jal         0x800A05DC
    // 0x8009A724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A05DC(rdram, ctx);
        goto after_165;
    // 0x8009A724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_165:
    // 0x8009A728: b           L_8009AB48
    // 0x8009A72C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A72C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A730:
    // 0x8009A730: jal         0x80099B54
    // 0x8009A734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B54(rdram, ctx);
        goto after_166;
    // 0x8009A734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_166:
    // 0x8009A738: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A73C: b           L_8009AB48
    // 0x8009A740: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A740: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A744:
    // 0x8009A744: jal         0x800848B8
    // 0x8009A748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_26(rdram, ctx);
        goto after_167;
    // 0x8009A748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_167:
    // 0x8009A74C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A750: b           L_8009AB48
    // 0x8009A754: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A754: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A758:
    // 0x8009A758: jal         0x8008FD48
    // 0x8009A75C: nop

    func_8008FD48(rdram, ctx);
        goto after_168;
    // 0x8009A75C: nop

    after_168:
    // 0x8009A760: xori        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 ^ 0X1;
    // 0x8009A764: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8009A768: sltiu       $a1, $v1, 0x1
    ctx->r5 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8009A76C: beq         $a1, $zero, L_8009A780
    if (ctx->r5 == 0) {
        // 0x8009A770: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009A780;
    }
    // 0x8009A770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A774: xori        $a1, $v0, 0xA
    ctx->r5 = ctx->r2 ^ 0XA;
    // 0x8009A778: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x8009A77C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
L_8009A780:
    // 0x8009A780: jal         0x8009CC68
    // 0x8009A784: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8009CC68(rdram, ctx);
        goto after_169;
    // 0x8009A784: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_169:
    // 0x8009A788: bne         $v0, $zero, L_8009AB48
    if (ctx->r2 != 0) {
        // 0x8009A78C: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8009AB48;
    }
    // 0x8009A78C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009A790: bne         $a1, $zero, L_8009AB48
    if (ctx->r5 != 0) {
        // 0x8009A794: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x8009A794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A798: jal         0x80095738
    // 0x8009A79C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_170;
    // 0x8009A79C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_170:
    // 0x8009A7A0: bnel        $v0, $zero, L_8009AB4C
    if (ctx->r2 != 0) {
        // 0x8009A7A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB4C;
    }
    goto skip_5;
    // 0x8009A7A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x8009A7A8: jal         0x8008E078
    // 0x8009A7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_171;
    // 0x8009A7AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_171:
    // 0x8009A7B0: bnel        $v0, $zero, L_8009AB4C
    if (ctx->r2 != 0) {
        // 0x8009A7B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB4C;
    }
    goto skip_6;
    // 0x8009A7B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x8009A7B8: addiu       $s2, $zero, 0x4F
    ctx->r18 = ADD32(0, 0X4F);
    // 0x8009A7BC: b           L_8009AB48
    // 0x8009A7C0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A7C0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A7C4:
    // 0x8009A7C4: jal         0x800849B0
    // 0x8009A7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_19(rdram, ctx);
        goto after_172;
    // 0x8009A7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_172:
    // 0x8009A7CC: b           L_8009AB48
    // 0x8009A7D0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A7D0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A7D4:
    // 0x8009A7D4: jal         0x8008D630
    // 0x8009A7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D630(rdram, ctx);
        goto after_173;
    // 0x8009A7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_173:
    // 0x8009A7DC: beq         $v0, $zero, L_8009AB48
    if (ctx->r2 == 0) {
        // 0x8009A7E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x8009A7E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A7E4: jal         0x80084728
    // 0x8009A7E8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    _badata_entrypoint_29(rdram, ctx);
        goto after_174;
    // 0x8009A7E8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    after_174:
    // 0x8009A7EC: b           L_8009AB48
    // 0x8009A7F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8009AB48;
    // 0x8009A7F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A7F4:
    // 0x8009A7F4: jal         0x8008D630
    // 0x8009A7F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D630(rdram, ctx);
        goto after_175;
    // 0x8009A7F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_175:
    // 0x8009A7FC: beq         $v0, $zero, L_8009AB48
    if (ctx->r2 == 0) {
        // 0x8009A800: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x8009A800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A804: jal         0x80084738
    // 0x8009A808: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    _badata_entrypoint_31(rdram, ctx);
        goto after_176;
    // 0x8009A808: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    after_176:
    // 0x8009A80C: b           L_8009AB48
    // 0x8009A810: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8009AB48;
    // 0x8009A810: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A814:
    // 0x8009A814: jal         0x8008D630
    // 0x8009A818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D630(rdram, ctx);
        goto after_177;
    // 0x8009A818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_177:
    // 0x8009A81C: beq         $v0, $zero, L_8009AB48
    if (ctx->r2 == 0) {
        // 0x8009A820: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AB48;
    }
    // 0x8009A820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A824: jal         0x80084740
    // 0x8009A828: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    _badata_entrypoint_32(rdram, ctx);
        goto after_178;
    // 0x8009A828: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    after_178:
    // 0x8009A82C: b           L_8009AB48
    // 0x8009A830: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8009AB48;
    // 0x8009A830: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A834:
    // 0x8009A834: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8009A838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A83C: jal         0x8009CBDC
    // 0x8009A840: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    func_8009CBDC(rdram, ctx);
        goto after_179;
    // 0x8009A840: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_179:
    // 0x8009A844: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8009A848: bne         $v0, $at, L_8009A858
    if (ctx->r2 != ctx->r1) {
        // 0x8009A84C: nop
    
            goto L_8009A858;
    }
    // 0x8009A84C: nop

    // 0x8009A850: b           L_8009A8BC
    // 0x8009A854: addiu       $s2, $zero, 0x24
    ctx->r18 = ADD32(0, 0X24);
        goto L_8009A8BC;
    // 0x8009A854: addiu       $s2, $zero, 0x24
    ctx->r18 = ADD32(0, 0X24);
L_8009A858:
    // 0x8009A858: jal         0x800F40EC
    // 0x8009A85C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F40EC(rdram, ctx);
        goto after_180;
    // 0x8009A85C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_180:
    // 0x8009A860: beq         $v0, $zero, L_8009A890
    if (ctx->r2 == 0) {
        // 0x8009A864: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8009A890;
    }
    // 0x8009A864: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009A868: beq         $v0, $at, L_8009A880
    if (ctx->r2 == ctx->r1) {
        // 0x8009A86C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8009A880;
    }
    // 0x8009A86C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009A870: beq         $v0, $at, L_8009A888
    if (ctx->r2 == ctx->r1) {
        // 0x8009A874: nop
    
            goto L_8009A888;
    }
    // 0x8009A874: nop

    // 0x8009A878: b           L_8009A8C0
    // 0x8009A87C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8009A8C0;
    // 0x8009A87C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009A880:
    // 0x8009A880: b           L_8009A8BC
    // 0x8009A884: addiu       $s2, $zero, 0x2D
    ctx->r18 = ADD32(0, 0X2D);
        goto L_8009A8BC;
    // 0x8009A884: addiu       $s2, $zero, 0x2D
    ctx->r18 = ADD32(0, 0X2D);
L_8009A888:
    // 0x8009A888: b           L_8009A8BC
    // 0x8009A88C: addiu       $s2, $zero, 0x2B
    ctx->r18 = ADD32(0, 0X2B);
        goto L_8009A8BC;
    // 0x8009A88C: addiu       $s2, $zero, 0x2B
    ctx->r18 = ADD32(0, 0X2B);
L_8009A890:
    // 0x8009A890: jal         0x8008E078
    // 0x8009A894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_181;
    // 0x8009A894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_181:
    // 0x8009A898: beq         $v0, $zero, L_8009A8B0
    if (ctx->r2 == 0) {
        // 0x8009A89C: nop
    
            goto L_8009A8B0;
    }
    // 0x8009A89C: nop

    // 0x8009A8A0: jal         0x80084750
    // 0x8009A8A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_34(rdram, ctx);
        goto after_182;
    // 0x8009A8A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_182:
    // 0x8009A8A8: b           L_8009A8BC
    // 0x8009A8AC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8009A8BC;
    // 0x8009A8AC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A8B0:
    // 0x8009A8B0: jal         0x80084700
    // 0x8009A8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_24(rdram, ctx);
        goto after_183;
    // 0x8009A8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_183:
    // 0x8009A8B8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A8BC:
    // 0x8009A8BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009A8C0:
    // 0x8009A8C0: jal         0x8009B9B0
    // 0x8009A8C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_184;
    // 0x8009A8C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_184:
    // 0x8009A8C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A8CC: jal         0x8009BA9C
    // 0x8009A8D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_185;
    // 0x8009A8D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_185:
    // 0x8009A8D4: b           L_8009AB4C
    // 0x8009A8D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8009AB4C;
    // 0x8009A8D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009A8DC:
    // 0x8009A8DC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8009A8E0: jal         0x80084740
    // 0x8009A8E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_32(rdram, ctx);
        goto after_186;
    // 0x8009A8E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_186:
    // 0x8009A8E8: b           L_8009AB48
    // 0x8009A8EC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8009AB48;
    // 0x8009A8EC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A8F0:
    // 0x8009A8F0: jal         0x80084D10
    // 0x8009A8F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_19(rdram, ctx);
        goto after_187;
    // 0x8009A8F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_187:
    // 0x8009A8F8: b           L_8009AB48
    // 0x8009A8FC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A8FC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A900:
    // 0x8009A900: lw          $t7, 0xC0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC0);
    // 0x8009A904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A908: jal         0x80094574
    // 0x8009A90C: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    func_80094574(rdram, ctx);
        goto after_188;
    // 0x8009A90C: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    after_188:
    // 0x8009A910: b           L_8009AB48
    // 0x8009A914: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A914: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A918:
    // 0x8009A918: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8009A91C: b           L_8009AB48
    // 0x8009A920: addiu       $s2, $zero, 0xB5
    ctx->r18 = ADD32(0, 0XB5);
        goto L_8009AB48;
    // 0x8009A920: addiu       $s2, $zero, 0xB5
    ctx->r18 = ADD32(0, 0XB5);
L_8009A924:
    // 0x8009A924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A928: jal         0x800850C8
    // 0x8009A92C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _basquash_entrypoint_3(rdram, ctx);
        goto after_189;
    // 0x8009A92C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_189:
    // 0x8009A930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A934: jal         0x80099730
    // 0x8009A938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80099730(rdram, ctx);
        goto after_190;
    // 0x8009A938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_190:
    // 0x8009A93C: b           L_8009AB48
    // 0x8009A940: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8009AB48;
    // 0x8009A940: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A944:
    // 0x8009A944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A948: jal         0x800850C8
    // 0x8009A94C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _basquash_entrypoint_3(rdram, ctx);
        goto after_191;
    // 0x8009A94C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_191:
    // 0x8009A950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A954: jal         0x80099730
    // 0x8009A958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80099730(rdram, ctx);
        goto after_192;
    // 0x8009A958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_192:
    // 0x8009A95C: b           L_8009AB48
    // 0x8009A960: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8009AB48;
    // 0x8009A960: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A964:
    // 0x8009A964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A968: jal         0x800850C8
    // 0x8009A96C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _basquash_entrypoint_3(rdram, ctx);
        goto after_193;
    // 0x8009A96C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_193:
    // 0x8009A970: b           L_8009AB4C
    // 0x8009A974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8009AB4C;
    // 0x8009A974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009A978:
    // 0x8009A978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A97C: jal         0x800850C8
    // 0x8009A980: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _basquash_entrypoint_3(rdram, ctx);
        goto after_194;
    // 0x8009A980: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_194:
    // 0x8009A984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A988: jal         0x80099730
    // 0x8009A98C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80099730(rdram, ctx);
        goto after_195;
    // 0x8009A98C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_195:
    // 0x8009A990: b           L_8009AB48
    // 0x8009A994: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8009AB48;
    // 0x8009A994: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A998:
    // 0x8009A998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A99C: jal         0x800850C8
    // 0x8009A9A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _basquash_entrypoint_3(rdram, ctx);
        goto after_196;
    // 0x8009A9A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_196:
    // 0x8009A9A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A9A8: jal         0x80099730
    // 0x8009A9AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80099730(rdram, ctx);
        goto after_197;
    // 0x8009A9AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_197:
    // 0x8009A9B0: b           L_8009AB48
    // 0x8009A9B4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8009AB48;
    // 0x8009A9B4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8009A9B8:
    // 0x8009A9B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A9BC: jal         0x80095760
    // 0x8009A9C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baflag_set(rdram, ctx);
        goto after_198;
    // 0x8009A9C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_198:
    // 0x8009A9C4: jal         0x8009F354
    // 0x8009A9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F354(rdram, ctx);
        goto after_199;
    // 0x8009A9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_199:
    // 0x8009A9CC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A9D0: b           L_8009AB48
    // 0x8009A9D4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009A9D4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009A9D8:
    // 0x8009A9D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A9DC: jal         0x800A17A8
    // 0x8009A9E0: addiu       $a1, $zero, -0x3E7
    ctx->r5 = ADD32(0, -0X3E7);
    func_800A17A8(rdram, ctx);
        goto after_200;
    // 0x8009A9E0: addiu       $a1, $zero, -0x3E7
    ctx->r5 = ADD32(0, -0X3E7);
    after_200:
    // 0x8009A9E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A9E8: jal         0x80095760
    // 0x8009A9EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baflag_set(rdram, ctx);
        goto after_201;
    // 0x8009A9EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_201:
    // 0x8009A9F0: jal         0x8009F354
    // 0x8009A9F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F354(rdram, ctx);
        goto after_202;
    // 0x8009A9F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_202:
    // 0x8009A9F8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009A9FC: b           L_8009AB48
    // 0x8009AA00: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AA00: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009AA04:
    // 0x8009AA04: jal         0x800848C0
    // 0x8009AA08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_27(rdram, ctx);
        goto after_203;
    // 0x8009AA08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_203:
    // 0x8009AA0C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009AA10: b           L_8009AB48
    // 0x8009AA14: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AA14: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009AA18:
    // 0x8009AA18: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8009AA1C: jal         0x8009F354
    // 0x8009AA20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F354(rdram, ctx);
        goto after_204;
    // 0x8009AA20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_204:
    // 0x8009AA24: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009AA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AA2C: jal         0x80095760
    // 0x8009AA30: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    baflag_set(rdram, ctx);
        goto after_205;
    // 0x8009AA30: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_205:
    // 0x8009AA34: b           L_8009AB4C
    // 0x8009AA38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8009AB4C;
    // 0x8009AA38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009AA3C:
    // 0x8009AA3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AA40: jal         0x80095760
    // 0x8009AA44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baflag_set(rdram, ctx);
        goto after_206;
    // 0x8009AA44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_206:
    // 0x8009AA48: b           L_8009AB48
    // 0x8009AA4C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AA4C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009AA50:
    // 0x8009AA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AA54: jal         0x80095760
    // 0x8009AA58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    baflag_set(rdram, ctx);
        goto after_207;
    // 0x8009AA58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_207:
    // 0x8009AA5C: b           L_8009AB48
    // 0x8009AA60: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AA60: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009AA64:
    // 0x8009AA64: jal         0x80084358
    // 0x8009AA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsfirstp_entrypoint_26(rdram, ctx);
        goto after_208;
    // 0x8009AA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_208:
    // 0x8009AA6C: b           L_8009AB64
    // 0x8009AA70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8009AB64;
    // 0x8009AA70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009AA74:
    // 0x8009AA74: addiu       $s2, $zero, 0x42
    ctx->r18 = ADD32(0, 0X42);
    // 0x8009AA78: b           L_8009AB48
    // 0x8009AA7C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AA7C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009AA80:
    // 0x8009AA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AA84: jal         0x800A3544
    // 0x8009AA88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3544(rdram, ctx);
        goto after_209;
    // 0x8009AA88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_209:
    // 0x8009AA8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AA90: jal         0x8009337C
    // 0x8009AA94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009337C(rdram, ctx);
        goto after_210;
    // 0x8009AA94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_210:
    // 0x8009AA98: b           L_8009AB48
    // 0x8009AA9C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AA9C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009AAA0:
    // 0x8009AAA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AAA4: jal         0x800A3544
    // 0x8009AAA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A3544(rdram, ctx);
        goto after_211;
    // 0x8009AAA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_211:
    // 0x8009AAAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AAB0: jal         0x8009337C
    // 0x8009AAB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009337C(rdram, ctx);
        goto after_212;
    // 0x8009AAB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_212:
    // 0x8009AAB8: b           L_8009AB48
    // 0x8009AABC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AABC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009AAC0:
    // 0x8009AAC0: lw          $v0, 0xC0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC0);
    // 0x8009AAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AAC8: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x8009AACC: jal         0x8008ED88
    // 0x8009AAD0: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    func_8008ED88(rdram, ctx);
        goto after_213;
    // 0x8009AAD0: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    after_213:
    // 0x8009AAD4: b           L_8009AB48
    // 0x8009AAD8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AAD8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009AADC:
    // 0x8009AADC: lw          $t8, 0xC0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC0);
    // 0x8009AAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AAE4: jal         0x800854D0
    // 0x8009AAE8: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    _bainvisible_entrypoint_5(rdram, ctx);
        goto after_214;
    // 0x8009AAE8: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_214:
    // 0x8009AAEC: b           L_8009AB48
    // 0x8009AAF0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AAF0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009AAF4:
    // 0x8009AAF4: lw          $t9, 0x158($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X158);
    // 0x8009AAF8: beql        $t9, $zero, L_8009AB2C
    if (ctx->r25 == 0) {
        // 0x8009AAFC: lw          $v0, 0xC0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XC0);
            goto L_8009AB2C;
    }
    goto skip_7;
    // 0x8009AAFC: lw          $v0, 0xC0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC0);
    skip_7:
    // 0x8009AB00: lw          $t0, 0xC0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC0);
    // 0x8009AB04: jal         0x80085518
    // 0x8009AB08: lw          $a0, 0x18($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X18);
    _badeathmatch_entrypoint_4(rdram, ctx);
        goto after_215;
    // 0x8009AB08: lw          $a0, 0x18($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X18);
    after_215:
    // 0x8009AB0C: lw          $t1, 0xC0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC0);
    // 0x8009AB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AB14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009AB18: jal         0x80085520
    // 0x8009AB1C: lw          $a2, 0x1C($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X1C);
    _badeathmatch_entrypoint_5(rdram, ctx);
        goto after_216;
    // 0x8009AB1C: lw          $a2, 0x1C($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X1C);
    after_216:
    // 0x8009AB20: b           L_8009AB48
    // 0x8009AB24: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AB24: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8009AB28: lw          $v0, 0xC0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC0);
L_8009AB2C:
    // 0x8009AB2C: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x8009AB30: jal         0x800D175C
    // 0x8009AB34: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    func_800D175C(rdram, ctx);
        goto after_217;
    // 0x8009AB34: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    after_217:
    // 0x8009AB38: b           L_8009AB48
    // 0x8009AB3C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_8009AB48;
    // 0x8009AB3C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8009AB40:
    // 0x8009AB40: jal         0x800956B8
    // 0x8009AB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800956B8(rdram, ctx);
        goto after_218;
    // 0x8009AB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_218:
L_8009AB48:
    // 0x8009AB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009AB4C:
    // 0x8009AB4C: jal         0x8009E830
    // 0x8009AB50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8009E830(rdram, ctx);
        goto after_219;
    // 0x8009AB50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_219:
    // 0x8009AB54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AB58: jal         0x8009E5C8
    // 0x8009AB5C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    bs_setState(rdram, ctx);
        goto after_220;
    // 0x8009AB5C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_220:
    // 0x8009AB60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009AB64:
    // 0x8009AB64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009AB68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009AB6C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009AB70: jr          $ra
    // 0x8009AB74: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8009AB74: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _chfactoryprop_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861B8: syscall     287
    recomp_syscall_handler(rdram, ctx, 0x800861B8);
    return;
    // 0x800861BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800D0908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0908: sltiu       $at, $a1, 0x9
    ctx->r1 = ctx->r5 < 0X9 ? 1 : 0;
    // 0x800D090C: beq         $at, $zero, L_800D0A74
    if (ctx->r1 == 0) {
        // 0x800D0910: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_800D0A74;
    }
    // 0x800D0910: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800D0914: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D0918: addu        $at, $at, $t6
    gpr jr_addend_800D0920 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D091C: lw          $t6, 0x5A74($at)
    ctx->r14 = ADD32(ctx->r1, 0X5A74);
    // 0x800D0920: jr          $t6
    // 0x800D0924: nop

    switch (jr_addend_800D0920 >> 2) {
        case 0: goto L_800D0928; break;
        case 1: goto L_800D095C; break;
        case 2: goto L_800D09BC; break;
        case 3: goto L_800D09EC; break;
        case 4: goto L_800D098C; break;
        case 5: goto L_800D0A74; break;
        case 6: goto L_800D0A74; break;
        case 7: goto L_800D0A1C; break;
        case 8: goto L_800D0A48; break;
        default: switch_error(__func__, 0x800D0920, 0x80125A74);
    }
    // 0x800D0924: nop

L_800D0928:
    // 0x800D0928: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800D092C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800D0930: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D0934: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800D0938: lbu         $v1, -0x54C1($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X54C1);
    // 0x800D093C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800D0940: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800D0944: beq         $v1, $zero, L_800D0A74
    if (ctx->r3 == 0) {
        // 0x800D0948: addu        $t9, $t9, $t8
        ctx->r25 = ADD32(ctx->r25, ctx->r24);
            goto L_800D0A74;
    }
    // 0x800D0948: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800D094C: lw          $t9, -0x50D8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X50D8);
    // 0x800D0950: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x800D0954: jr          $ra
    // 0x800D0958: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    return;
    // 0x800D0958: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800D095C:
    // 0x800D095C: sll         $t0, $a0, 1
    ctx->r8 = S32(ctx->r4 << 1);
    // 0x800D0960: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D0964: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800D0968: lbu         $v1, -0x5439($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5439);
    // 0x800D096C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x800D0970: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800D0974: beq         $v1, $zero, L_800D0A74
    if (ctx->r3 == 0) {
        // 0x800D0978: addu        $t2, $t2, $t1
        ctx->r10 = ADD32(ctx->r10, ctx->r9);
            goto L_800D0A74;
    }
    // 0x800D0978: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800D097C: lw          $t2, -0x50D8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X50D8);
    // 0x800D0980: addu        $v0, $v1, $t2
    ctx->r2 = ADD32(ctx->r3, ctx->r10);
    // 0x800D0984: jr          $ra
    // 0x800D0988: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    return;
    // 0x800D0988: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800D098C:
    // 0x800D098C: sll         $t3, $a0, 1
    ctx->r11 = S32(ctx->r4 << 1);
    // 0x800D0990: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D0994: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x800D0998: lbu         $v1, -0x532D($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X532D);
    // 0x800D099C: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x800D09A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800D09A4: beq         $v1, $zero, L_800D0A74
    if (ctx->r3 == 0) {
        // 0x800D09A8: addu        $t5, $t5, $t4
        ctx->r13 = ADD32(ctx->r13, ctx->r12);
            goto L_800D0A74;
    }
    // 0x800D09A8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800D09AC: lw          $t5, -0x50D8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X50D8);
    // 0x800D09B0: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x800D09B4: jr          $ra
    // 0x800D09B8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    return;
    // 0x800D09B8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800D09BC:
    // 0x800D09BC: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800D09C0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D09C4: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800D09C8: lbu         $v1, -0x5385($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5385);
    // 0x800D09CC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800D09D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800D09D4: beq         $v1, $zero, L_800D0A74
    if (ctx->r3 == 0) {
        // 0x800D09D8: addu        $t8, $t8, $t7
        ctx->r24 = ADD32(ctx->r24, ctx->r15);
            goto L_800D0A74;
    }
    // 0x800D09D8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800D09DC: lw          $t8, -0x50D8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X50D8);
    // 0x800D09E0: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x800D09E4: jr          $ra
    // 0x800D09E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    return;
    // 0x800D09E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800D09EC:
    // 0x800D09EC: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800D09F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D09F4: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x800D09F8: lbu         $v1, -0x5351($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5351);
    // 0x800D09FC: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x800D0A00: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800D0A04: beq         $v1, $zero, L_800D0A74
    if (ctx->r3 == 0) {
        // 0x800D0A08: addu        $t1, $t1, $t0
        ctx->r9 = ADD32(ctx->r9, ctx->r8);
            goto L_800D0A74;
    }
    // 0x800D0A08: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800D0A0C: lw          $t1, -0x50D8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X50D8);
    // 0x800D0A10: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x800D0A14: jr          $ra
    // 0x800D0A18: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    return;
    // 0x800D0A18: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800D0A1C:
    // 0x800D0A1C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D0A20: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800D0A24: lbu         $v1, -0x51C5($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X51C5);
    // 0x800D0A28: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x800D0A2C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800D0A30: beq         $v1, $zero, L_800D0A74
    if (ctx->r3 == 0) {
        // 0x800D0A34: addu        $t3, $t3, $t2
        ctx->r11 = ADD32(ctx->r11, ctx->r10);
            goto L_800D0A74;
    }
    // 0x800D0A34: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800D0A38: lw          $t3, -0x50D8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X50D8);
    // 0x800D0A3C: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x800D0A40: jr          $ra
    // 0x800D0A44: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    return;
    // 0x800D0A44: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800D0A48:
    // 0x800D0A48: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D0A4C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800D0A50: lbu         $v1, -0x51A5($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X51A5);
    // 0x800D0A54: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x800D0A58: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800D0A5C: beq         $v1, $zero, L_800D0A74
    if (ctx->r3 == 0) {
        // 0x800D0A60: addu        $t5, $t5, $t4
        ctx->r13 = ADD32(ctx->r13, ctx->r12);
            goto L_800D0A74;
    }
    // 0x800D0A60: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800D0A64: lw          $t5, -0x50D8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X50D8);
    // 0x800D0A68: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x800D0A6C: jr          $ra
    // 0x800D0A70: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    return;
    // 0x800D0A70: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800D0A74:
    // 0x800D0A74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D0A78: jr          $ra
    // 0x800D0A7C: nop

    return;
    // 0x800D0A7C: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808016DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808016E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808016E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808016E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808016EC: jal         0x8008CAEC
    // 0x808016F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_0;
    // 0x808016F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x808016F4: beq         $v0, $zero, L_80801700
    if (ctx->r2 == 0) {
        // 0x808016F8: nop
    
            goto L_80801700;
    }
    // 0x808016F8: nop

    // 0x808016FC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80801700:
    // 0x80801700: jal         0x8008CAC8
    // 0x80801704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_1;
    // 0x80801704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801708: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(124, 0X2E28) << 16);
    // 0x8080170C: lwc1        $f4, 0x2E28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(124, 0X2E28));
    // 0x80801710: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801714: nop

    // 0x80801718: bc1f        L_80801734
    if (!c1cs) {
        // 0x8080171C: nop
    
            goto L_80801734;
    }
    // 0x8080171C: nop

    // 0x80801720: jal         0x8009EF10
    // 0x80801724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_2;
    // 0x80801724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801728: beq         $v0, $zero, L_80801734
    if (ctx->r2 == 0) {
        // 0x8080172C: nop
    
            goto L_80801734;
    }
    // 0x8080172C: nop

    // 0x80801730: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80801734:
    // 0x80801734: jal         0x8008DD04
    // 0x80801738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_3;
    // 0x80801738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080173C: beq         $v0, $zero, L_80801748
    if (ctx->r2 == 0) {
        // 0x80801740: nop
    
            goto L_80801748;
    }
    // 0x80801740: nop

    // 0x80801744: addiu       $s1, $zero, 0x2F
    ctx->r17 = ADD32(0, 0X2F);
L_80801748:
    // 0x80801748: jal         0x8008E124
    // 0x8080174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E124(rdram, ctx);
        goto after_4;
    // 0x8080174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801750: beql        $v0, $zero, L_80801774
    if (ctx->r2 == 0) {
        // 0x80801754: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801774;
    }
    goto skip_0;
    // 0x80801754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801758: jal         0x8009CC68
    // 0x8080175C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CC68(rdram, ctx);
        goto after_5;
    // 0x8080175C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801764: jal         0x80084730
    // 0x80801768: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _badata_entrypoint_30(rdram, ctx);
        goto after_6;
    // 0x80801768: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8080176C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801774:
    // 0x80801774: jal         0x8009E5C8
    // 0x80801778: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80801778: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8080177C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801780: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801784: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801788: jr          $ra
    // 0x8080178C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080178C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chdinofamilysmall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E18: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2404, 0XF20) << 16);
    // 0x80800E1C: jr          $ra
    // 0x80800E20: addiu       $v0, $v0, 0xF20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2404, 0XF20));
    return;
    // 0x80800E20: addiu       $v0, $v0, 0xF20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2404, 0XF20));
    // 0x80800E24: nop

    // 0x80800E28: nop

    // 0x80800E2C: nop

;}
RECOMP_FUNC void func_80800000_bsdroneslide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800004: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800008: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800010: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80800014: jal         0x8008CB3C
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080001C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800020: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080002C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800030: jal         0x8009FFD8
    // 0x80800034: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    // 0x80800040: jal         0x8009BFE4
    // 0x80800044: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_2;
    // 0x80800044: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_2:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x8009B9B0
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800054: jal         0x8009D658
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_4;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800064: jal         0x80085338
    // 0x80800068: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _batimer_set(rdram, ctx);
        goto after_5;
    // 0x80800068: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x8080006C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800074: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void func_80800274_chmoley(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800278: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080027C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800284: jal         0x80100094
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080028C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800290: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800294: jal         0x800897D8
    // 0x80800298: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800298: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080029C: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x808002A0: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x808002A4: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x808002A8: beq         $at, $zero, L_80800358
    if (ctx->r1 == 0) {
        // 0x808002AC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800358;
    }
    // 0x808002AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808002B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1556, 0XA00) << 16);
    // 0x808002B4: addu        $at, $at, $t7
    gpr jr_addend_808002BC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808002B8: lw          $t7, 0xA00($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1556, 0XA00));
    // 0x808002BC: jr          $t7
    // 0x808002C0: nop

    switch (jr_addend_808002BC >> 2) {
        case 0: goto L_80800358; break;
        case 1: goto L_80800358; break;
        case 2: goto L_808002C4; break;
        case 3: goto L_80800358; break;
        case 4: goto L_80800358; break;
        case 5: goto L_808002F8; break;
        case 6: goto L_8080032C; break;
        default: switch_error(__func__, 0x808002BC, 0x80800A00);
    }
    // 0x808002C0: nop

L_808002C4:
    // 0x808002C4: jal         0x80800190
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800190_chmoley(rdram, ctx);
        goto after_2;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002CC: beq         $v0, $zero, L_80800358
    if (ctx->r2 == 0) {
        // 0x808002D0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800358;
    }
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002D4: jal         0x80086918
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chmolehill_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002DC: jal         0x80106790
    // 0x808002E0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x808002E0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_4:
    // 0x808002E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002E8: jal         0x80086920
    // 0x808002EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808002EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x808002F0: b           L_8080035C
    // 0x808002F4: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
        goto L_8080035C;
    // 0x808002F4: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
L_808002F8:
    // 0x808002F8: jal         0x80800190
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800190_chmoley(rdram, ctx);
        goto after_6;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800300: beq         $v0, $zero, L_80800358
    if (ctx->r2 == 0) {
        // 0x80800304: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800358;
    }
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800308: jal         0x80086918
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chmolehill_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800310: jal         0x80106790
    // 0x80800314: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_8;
    // 0x80800314: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_8:
    // 0x80800318: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080031C: jal         0x80086920
    // 0x80800320: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800320: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x80800324: b           L_8080035C
    // 0x80800328: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
        goto L_8080035C;
    // 0x80800328: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
L_8080032C:
    // 0x8080032C: jal         0x80800190
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800190_chmoley(rdram, ctx);
        goto after_10;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800334: beq         $v0, $zero, L_80800358
    if (ctx->r2 == 0) {
        // 0x80800338: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800358;
    }
    // 0x80800338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080033C: jal         0x80086918
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chmolehill_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800344: jal         0x80106790
    // 0x80800348: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_12;
    // 0x80800348: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_12:
    // 0x8080034C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800350: jal         0x80086920
    // 0x80800354: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800354: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_13:
L_80800358:
    // 0x80800358: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
L_8080035C:
    // 0x8080035C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800360: addiu       $t0, $t9, -0x2
    ctx->r8 = ADD32(ctx->r25, -0X2);
    // 0x80800364: sltiu       $at, $t0, 0xA
    ctx->r1 = ctx->r8 < 0XA ? 1 : 0;
    // 0x80800368: beq         $at, $zero, L_80800624
    if (ctx->r1 == 0) {
        // 0x8080036C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800624;
    }
    // 0x8080036C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800370: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1556, 0XA1C) << 16);
    // 0x80800374: addu        $at, $at, $t0
    gpr jr_addend_8080037C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800378: lw          $t0, 0xA1C($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1556, 0XA1C));
    // 0x8080037C: jr          $t0
    // 0x80800380: nop

    switch (jr_addend_8080037C >> 2) {
        case 0: goto L_80800384; break;
        case 1: goto L_808004DC; break;
        case 2: goto L_808005B0; break;
        case 3: goto L_80800624; break;
        case 4: goto L_80800450; break;
        case 5: goto L_808003F8; break;
        case 6: goto L_80800424; break;
        case 7: goto L_80800624; break;
        case 8: goto L_80800568; break;
        case 9: goto L_80800508; break;
        default: switch_error(__func__, 0x8080037C, 0x80800A1C);
    }
    // 0x80800380: nop

L_80800384:
    // 0x80800384: lui         $a1, 0x3F15
    ctx->r5 = S32(0X3F15 << 16);
    // 0x80800388: ori         $a1, $a1, 0x3F7D
    ctx->r5 = ctx->r5 | 0X3F7D;
    // 0x8080038C: jal         0x80101E14
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800394: beq         $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x80800398: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808003A0: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x808003A4: b           L_808003CC
    // 0x808003A8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_808003CC;
    // 0x808003A8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_808003AC:
    // 0x808003AC: lui         $a1, 0x3F6E
    ctx->r5 = S32(0X3F6E << 16);
    // 0x808003B0: jal         0x80101E14
    // 0x808003B4: ori         $a1, $a1, 0x5604
    ctx->r5 = ctx->r5 | 0X5604;
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x808003B4: ori         $a1, $a1, 0x5604
    ctx->r5 = ctx->r5 | 0X5604;
    after_15:
    // 0x808003B8: beq         $v0, $zero, L_808003CC
    if (ctx->r2 == 0) {
        // 0x808003BC: nop
    
            goto L_808003CC;
    }
    // 0x808003BC: nop

    // 0x808003C0: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x808003C4: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x808003C8: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_808003CC:
    // 0x808003CC: jal         0x80101DDC
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808003D4: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x808003D8: nop
    
            goto L_80800624;
    }
    // 0x808003D8: nop

    // 0x808003DC: jal         0x80106790
    // 0x808003E0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_17;
    // 0x808003E0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_17:
    // 0x808003E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003E8: jal         0x80086920
    // 0x808003EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x808003EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_18:
    // 0x808003F0: b           L_80800624
    // 0x808003F4: nop

        goto L_80800624;
    // 0x808003F4: nop

L_808003F8:
    // 0x808003F8: jal         0x80101DDC
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_19;
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800400: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x80800404: nop
    
            goto L_80800624;
    }
    // 0x80800404: nop

    // 0x80800408: jal         0x80106790
    // 0x8080040C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_20;
    // 0x8080040C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_20:
    // 0x80800410: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800414: jal         0x80086920
    // 0x80800418: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x80800418: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_21:
    // 0x8080041C: b           L_80800624
    // 0x80800420: nop

        goto L_80800624;
    // 0x80800420: nop

L_80800424:
    // 0x80800424: jal         0x80101DDC
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_22;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8080042C: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x80800430: nop
    
            goto L_80800624;
    }
    // 0x80800430: nop

    // 0x80800434: jal         0x80106790
    // 0x80800438: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_23;
    // 0x80800438: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_23:
    // 0x8080043C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800440: jal         0x80086920
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80800448: b           L_80800624
    // 0x8080044C: nop

        goto L_80800624;
    // 0x8080044C: nop

L_80800450:
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: jal         0x80101E14
    // 0x80800458: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_25;
    // 0x80800458: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_25:
    // 0x8080045C: beq         $v0, $zero, L_80800484
    if (ctx->r2 == 0) {
        // 0x80800460: addiu       $a1, $zero, 0xDBD
        ctx->r5 = ADD32(0, 0XDBD);
            goto L_80800484;
    }
    // 0x80800460: addiu       $a1, $zero, 0xDBD
    ctx->r5 = ADD32(0, 0XDBD);
    // 0x80800464: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800468: addiu       $t6, $zero, 0x6F
    ctx->r14 = ADD32(0, 0X6F);
    // 0x8080046C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800470: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800474: jal         0x8008A208
    // 0x80800478: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_26;
    // 0x80800478: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_26:
    // 0x8080047C: b           L_80800624
    // 0x80800480: nop

        goto L_80800624;
    // 0x80800480: nop

L_80800484:
    // 0x80800484: jal         0x80101DDC
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_27;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8080048C: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x80800490: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1556, 0XA44) << 16);
            goto L_80800624;
    }
    // 0x80800490: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1556, 0XA44) << 16);
    // 0x80800494: jal         0x800DC298
    // 0x80800498: lwc1        $f12, 0xA44($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1556, 0XA44));
    func_800DC298(rdram, ctx);
        goto after_28;
    // 0x80800498: lwc1        $f12, 0xA44($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1556, 0XA44));
    after_28:
    // 0x8080049C: beq         $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x808004A0: nop
    
            goto L_808004C0;
    }
    // 0x808004A0: nop

    // 0x808004A4: jal         0x80106790
    // 0x808004A8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_29;
    // 0x808004A8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_29:
    // 0x808004AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004B0: jal         0x80086920
    // 0x808004B4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x808004B4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_30:
    // 0x808004B8: b           L_80800624
    // 0x808004BC: nop

        goto L_80800624;
    // 0x808004BC: nop

L_808004C0:
    // 0x808004C0: jal         0x80106790
    // 0x808004C4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_31;
    // 0x808004C4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_31:
    // 0x808004C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004CC: jal         0x80086920
    // 0x808004D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_32;
    // 0x808004D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_32:
    // 0x808004D4: b           L_80800624
    // 0x808004D8: nop

        goto L_80800624;
    // 0x808004D8: nop

L_808004DC:
    // 0x808004DC: jal         0x80101DDC
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_33;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x808004E4: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x808004E8: nop
    
            goto L_80800624;
    }
    // 0x808004E8: nop

    // 0x808004EC: jal         0x80106790
    // 0x808004F0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_34;
    // 0x808004F0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_34:
    // 0x808004F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004F8: jal         0x80086920
    // 0x808004FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_35;
    // 0x808004FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x80800500: b           L_80800624
    // 0x80800504: nop

        goto L_80800624;
    // 0x80800504: nop

L_80800508:
    // 0x80800508: lui         $a1, 0x3DBC
    ctx->r5 = S32(0X3DBC << 16);
    // 0x8080050C: ori         $a1, $a1, 0x9EED
    ctx->r5 = ctx->r5 | 0X9EED;
    // 0x80800510: jal         0x80101E14
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_36;
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800518: beq         $v0, $zero, L_80800530
    if (ctx->r2 == 0) {
        // 0x8080051C: nop
    
            goto L_80800530;
    }
    // 0x8080051C: nop

    // 0x80800520: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800524: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80800528: b           L_80800624
    // 0x8080052C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_80800624;
    // 0x8080052C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80800530:
    // 0x80800530: jal         0x80101DDC
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_37;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800538: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x8080053C: nop
    
            goto L_80800624;
    }
    // 0x8080053C: nop

    // 0x80800540: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800544: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800548: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x8080054C: jal         0x80106790
    // 0x80800550: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_80106790(rdram, ctx);
        goto after_38;
    // 0x80800550: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_38:
    // 0x80800554: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800558: jal         0x80086920
    // 0x8080055C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_39;
    // 0x8080055C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_39:
    // 0x80800560: b           L_80800624
    // 0x80800564: nop

        goto L_80800624;
    // 0x80800564: nop

L_80800568:
    // 0x80800568: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8080056C: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800570: jal         0x80101E14
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_40;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80800578: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x8080057C: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80800624;
    }
    // 0x8080057C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800580: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800584: jal         0x800DC298
    // 0x80800588: nop

    func_800DC298(rdram, ctx);
        goto after_41;
    // 0x80800588: nop

    after_41:
    // 0x8080058C: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x80800590: nop
    
            goto L_80800624;
    }
    // 0x80800590: nop

    // 0x80800594: jal         0x80106790
    // 0x80800598: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_42;
    // 0x80800598: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_42:
    // 0x8080059C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005A0: jal         0x80086920
    // 0x808005A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_43;
    // 0x808005A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_43:
    // 0x808005A8: b           L_80800624
    // 0x808005AC: nop

        goto L_80800624;
    // 0x808005AC: nop

L_808005B0:
    // 0x808005B0: lui         $a1, 0x3DBA
    ctx->r5 = S32(0X3DBA << 16);
    // 0x808005B4: ori         $a1, $a1, 0x29C7
    ctx->r5 = ctx->r5 | 0X29C7;
    // 0x808005B8: jal         0x80101E14
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_44;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x808005C0: beq         $v0, $zero, L_808005D8
    if (ctx->r2 == 0) {
        // 0x808005C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D8;
    }
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C8: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808005CC: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x808005D0: b           L_80800624
    // 0x808005D4: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
        goto L_80800624;
    // 0x808005D4: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_808005D8:
    // 0x808005D8: lui         $a1, 0x3F54
    ctx->r5 = S32(0X3F54 << 16);
    // 0x808005DC: jal         0x80101E14
    // 0x808005E0: ori         $a1, $a1, 0x5A1D
    ctx->r5 = ctx->r5 | 0X5A1D;
    func_80101E14(rdram, ctx);
        goto after_45;
    // 0x808005E0: ori         $a1, $a1, 0x5A1D
    ctx->r5 = ctx->r5 | 0X5A1D;
    after_45:
    // 0x808005E4: beq         $v0, $zero, L_808005FC
    if (ctx->r2 == 0) {
        // 0x808005E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005FC;
    }
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005EC: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x808005F0: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x808005F4: b           L_80800624
    // 0x808005F8: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
        goto L_80800624;
    // 0x808005F8: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
L_808005FC:
    // 0x808005FC: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800600: jal         0x80101E14
    // 0x80800604: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_46;
    // 0x80800604: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_46:
    // 0x80800608: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x8080060C: nop
    
            goto L_80800624;
    }
    // 0x8080060C: nop

    // 0x80800610: jal         0x80106790
    // 0x80800614: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_47;
    // 0x80800614: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_47:
    // 0x80800618: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080061C: jal         0x80086920
    // 0x80800620: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _chmolehill_entrypoint_2(rdram, ctx);
        goto after_48;
    // 0x80800620: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_48:
L_80800624:
    // 0x80800624: jal         0x80104248
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_49;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x8080062C: beql        $v0, $zero, L_8080087C
    if (ctx->r2 == 0) {
        // 0x80800630: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080087C;
    }
    goto skip_0;
    // 0x80800630: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800634: jal         0x801022E4
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_50;
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x8080063C: addiu       $t7, $v0, -0x2BB
    ctx->r15 = ADD32(ctx->r2, -0X2BB);
    // 0x80800640: sltiu       $at, $t7, 0xF
    ctx->r1 = ctx->r15 < 0XF ? 1 : 0;
    // 0x80800644: beq         $at, $zero, L_80800878
    if (ctx->r1 == 0) {
        // 0x80800648: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800878;
    }
    // 0x80800648: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080064C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1556, 0XA48) << 16);
    // 0x80800650: addu        $at, $at, $t7
    gpr jr_addend_80800658 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800654: lw          $t7, 0xA48($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1556, 0XA48));
    // 0x80800658: jr          $t7
    // 0x8080065C: nop

    switch (jr_addend_80800658 >> 2) {
        case 0: goto L_80800850; break;
        case 1: goto L_808007F8; break;
        case 2: goto L_80800878; break;
        case 3: goto L_80800878; break;
        case 4: goto L_80800878; break;
        case 5: goto L_80800878; break;
        case 6: goto L_80800878; break;
        case 7: goto L_80800878; break;
        case 8: goto L_80800878; break;
        case 9: goto L_80800878; break;
        case 10: goto L_80800878; break;
        case 11: goto L_80800878; break;
        case 12: goto L_80800878; break;
        case 13: goto L_808006F4; break;
        case 14: goto L_80800660; break;
        default: switch_error(__func__, 0x80800658, 0x80800A48);
    }
    // 0x8080065C: nop

L_80800660:
    // 0x80800660: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    // 0x80800664: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80800668: jal         0x80101F24
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_51;
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80800670: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1556, 0XA84) << 16);
    // 0x80800674: lwc1        $f4, 0xA84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1556, 0XA84));
    // 0x80800678: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1556, 0XA88) << 16);
    // 0x8080067C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80800680: nop

    // 0x80800684: bc1f        L_808006B4
    if (!c1cs) {
        // 0x80800688: nop
    
            goto L_808006B4;
    }
    // 0x80800688: nop

    // 0x8080068C: lwc1        $f6, 0xA88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1556, 0XA88));
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800694: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800698: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8080069C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808006A0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1556, 0XB4C) << 16);
    // 0x808006A4: bc1f        L_808006B4
    if (!c1cs) {
        // 0x808006A8: nop
    
            goto L_808006B4;
    }
    // 0x808006A8: nop

    // 0x808006AC: jal         0x80089D50
    // 0x808006B0: addiu       $a3, $a3, 0xB4C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1556, 0XB4C));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_52;
    // 0x808006B0: addiu       $a3, $a3, 0xB4C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1556, 0XB4C));
    after_52:
L_808006B4:
    // 0x808006B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1556, 0XA90) << 16);
    // 0x808006B8: lui         $a3, 0x3E23
    ctx->r7 = S32(0X3E23 << 16);
    // 0x808006BC: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x808006C0: addiu       $a2, $a2, 0xA90
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1556, 0XA90));
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C8: jal         0x80089D20
    // 0x808006CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_53;
    // 0x808006CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_53:
    // 0x808006D0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1556, 0XAA8) << 16);
    // 0x808006D4: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x808006D8: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808006DC: addiu       $a2, $a2, 0xAA8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1556, 0XAA8));
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: jal         0x80089D20
    // 0x808006E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_54;
    // 0x808006E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_54:
    // 0x808006EC: b           L_8080087C
    // 0x808006F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080087C;
    // 0x808006F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006F4:
    // 0x808006F4: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1556, 0XBE0) << 16);
    // 0x808006F8: addiu       $t9, $t9, 0xBE0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1556, 0XBE0));
    // 0x808006FC: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80800700: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800704: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1556, 0XBF0) << 16);
    // 0x80800708: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8080070C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80800710: addiu       $t3, $t3, 0xBF0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1556, 0XBF0));
    // 0x80800714: addiu       $t2, $sp, 0x44
    ctx->r10 = ADD32(ctx->r29, 0X44);
    // 0x80800718: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x8080071C: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x80800720: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1556, 0XC00) << 16);
    // 0x80800724: addiu       $t7, $t7, 0xC00
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1556, 0XC00));
    // 0x80800728: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8080072C: lw          $t1, 0xC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC);
    // 0x80800730: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800738: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    // 0x8080073C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80800740: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80800744: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x80800748: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x8080074C: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80800750: lw          $t5, 0xC($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC);
    // 0x80800754: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x80800758: sw          $t5, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r13;
    // 0x8080075C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800760: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800764: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800768: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8080076C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800770: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80800774: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800778: jal         0x80101E4C
    // 0x8080077C: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    func_80101E4C(rdram, ctx);
        goto after_55;
    // 0x8080077C: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    after_55:
    // 0x80800780: beq         $v0, $zero, L_808007A4
    if (ctx->r2 == 0) {
        // 0x80800784: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007A4;
    }
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800788: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1556, 0XAC0) << 16);
    // 0x8080078C: addiu       $a2, $a2, 0xAC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1556, 0XAC0));
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800794: jal         0x80089D18
    // 0x80800798: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_56;
    // 0x80800798: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_56:
    // 0x8080079C: b           L_8080087C
    // 0x808007A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080087C;
    // 0x808007A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007A4:
    // 0x808007A4: jal         0x80101E4C
    // 0x808007A8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80101E4C(rdram, ctx);
        goto after_57;
    // 0x808007A8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_57:
    // 0x808007AC: beq         $v0, $zero, L_808007D0
    if (ctx->r2 == 0) {
        // 0x808007B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007D0;
    }
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1556, 0XAD8) << 16);
    // 0x808007B8: addiu       $a2, $a2, 0xAD8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1556, 0XAD8));
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C0: jal         0x80089D18
    // 0x808007C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_58;
    // 0x808007C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_58:
    // 0x808007C8: b           L_8080087C
    // 0x808007CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080087C;
    // 0x808007CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007D0:
    // 0x808007D0: jal         0x80101E4C
    // 0x808007D4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80101E4C(rdram, ctx);
        goto after_59;
    // 0x808007D4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_59:
    // 0x808007D8: beq         $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x808007DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800878;
    }
    // 0x808007DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1556, 0XAF0) << 16);
    // 0x808007E4: addiu       $a2, $a2, 0xAF0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1556, 0XAF0));
    // 0x808007E8: jal         0x80089D18
    // 0x808007EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_60;
    // 0x808007EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_60:
    // 0x808007F0: b           L_8080087C
    // 0x808007F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080087C;
    // 0x808007F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007F8:
    // 0x808007F8: lui         $a1, 0x3E75
    ctx->r5 = S32(0X3E75 << 16);
    // 0x808007FC: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80800800: jal         0x80101E14
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_61;
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80800808: beq         $v0, $zero, L_80800820
    if (ctx->r2 == 0) {
        // 0x8080080C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800820;
    }
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1556, 0XB08) << 16);
    // 0x80800814: addiu       $a2, $a2, 0xB08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1556, 0XB08));
    // 0x80800818: jal         0x80089D18
    // 0x8080081C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_62;
    // 0x8080081C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_62:
L_80800820:
    // 0x80800820: lui         $a1, 0x3F3D
    ctx->r5 = S32(0X3F3D << 16);
    // 0x80800824: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x80800828: jal         0x80101E14
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_63;
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x80800830: beq         $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x80800834: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800878;
    }
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1556, 0XB20) << 16);
    // 0x8080083C: addiu       $a2, $a2, 0xB20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1556, 0XB20));
    // 0x80800840: jal         0x80089D18
    // 0x80800844: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_64;
    // 0x80800844: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_64:
    // 0x80800848: b           L_8080087C
    // 0x8080084C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080087C;
    // 0x8080084C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800850:
    // 0x80800850: lui         $a1, 0x3E85
    ctx->r5 = S32(0X3E85 << 16);
    // 0x80800854: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    // 0x80800858: jal         0x80101E14
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_65;
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x80800860: beq         $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x80800864: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800878;
    }
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800868: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1556, 0XB38) << 16);
    // 0x8080086C: addiu       $a2, $a2, 0xB38
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1556, 0XB38));
    // 0x80800870: jal         0x80089D18
    // 0x80800874: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_66;
    // 0x80800874: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_66:
L_80800878:
    // 0x80800878: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080087C:
    // 0x8080087C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800880: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800884: jr          $ra
    // 0x80800888: nop

    return;
    // 0x80800888: nop

;}
RECOMP_FUNC void func_8002C5F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C5F8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8002C5FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C600: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8002C604: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8002C608: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x8002C60C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x8002C610: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002C614: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8002C618: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x8002C61C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8002C620: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8002C624: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x8002C628: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8002C62C: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8002C630: bne         $t8, $zero, L_8002C640
    if (ctx->r24 != 0) {
        // 0x8002C634: nop
    
            goto L_8002C640;
    }
    // 0x8002C634: nop

    // 0x8002C638: b           L_8002CC88
    // 0x8002C63C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_8002CC88;
    // 0x8002C63C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_8002C640:
    // 0x8002C640: sh          $zero, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = 0;
    // 0x8002C644: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x8002C648: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8002C64C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x8002C650: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8002C654: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8002C658: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002C65C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002C660: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x8002C664: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8002C668: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8002C66C: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x8002C670: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8002C674: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8002C678: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002C67C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8002C680: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8002C684: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8002C688: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002C68C: addiu       $t8, $t7, 0x38
    ctx->r24 = ADD32(ctx->r15, 0X38);
    // 0x8002C690: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8002C694: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8002C698: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8002C69C: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8002C6A0: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8002C6A4: lw          $t5, 0x18($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X18);
    // 0x8002C6A8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8002C6AC: sltu        $s0, $t5, $t4
    ctx->r16 = ctx->r13 < ctx->r12 ? 1 : 0;
    // 0x8002C6B0: beq         $s0, $zero, L_8002C6C0
    if (ctx->r16 == 0) {
        // 0x8002C6B4: nop
    
            goto L_8002C6C0;
    }
    // 0x8002C6B4: nop

    // 0x8002C6B8: lw          $s0, 0x1C($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X1C);
    // 0x8002C6BC: sltu        $s0, $zero, $s0
    ctx->r16 = 0 < ctx->r16 ? 1 : 0;
L_8002C6C0:
    // 0x8002C6C0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8002C6C4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8002C6C8: beq         $t6, $zero, L_8002C6E8
    if (ctx->r14 == 0) {
        // 0x8002C6CC: nop
    
            goto L_8002C6E8;
    }
    // 0x8002C6CC: nop

    // 0x8002C6D0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002C6D4: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8002C6D8: lw          $t9, 0x30($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X30);
    // 0x8002C6DC: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8002C6E0: b           L_8002C6F0
    // 0x8002C6E4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
        goto L_8002C6F0;
    // 0x8002C6E4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
L_8002C6E8:
    // 0x8002C6E8: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8002C6EC: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
L_8002C6F0:
    // 0x8002C6F0: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8002C6F4: lw          $t4, 0x34($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X34);
    // 0x8002C6F8: beq         $t4, $zero, L_8002C718
    if (ctx->r12 == 0) {
        // 0x8002C6FC: nop
    
            goto L_8002C718;
    }
    // 0x8002C6FC: nop

    // 0x8002C700: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002C704: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8002C708: lw          $t1, 0x34($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X34);
    // 0x8002C70C: subu        $t7, $t6, $t1
    ctx->r15 = SUB32(ctx->r14, ctx->r9);
    // 0x8002C710: b           L_8002C71C
    // 0x8002C714: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
        goto L_8002C71C;
    // 0x8002C714: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
L_8002C718:
    // 0x8002C718: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_8002C71C:
    // 0x8002C71C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8002C720: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8002C724: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8002C728: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x8002C72C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8002C730: bgez        $t2, L_8002C73C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8002C734: nop
    
            goto L_8002C73C;
    }
    // 0x8002C734: nop

    // 0x8002C738: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
L_8002C73C:
    // 0x8002C73C: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8002C740: addiu       $t4, $t3, 0xF
    ctx->r12 = ADD32(ctx->r11, 0XF);
    // 0x8002C744: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x8002C748: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x8002C74C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8002C750: sll         $t1, $t6, 3
    ctx->r9 = S32(ctx->r14 << 3);
    // 0x8002C754: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x8002C758: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x8002C75C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8002C760: beq         $t7, $zero, L_8002CA3C
    if (ctx->r15 == 0) {
        // 0x8002C764: nop
    
            goto L_8002CA3C;
    }
    // 0x8002C764: nop

    // 0x8002C768: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x8002C76C: lh          $t2, 0x7A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X7A);
    // 0x8002C770: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8002C774: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8002C778: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8002C77C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8002C780: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8002C784: lw          $t3, 0x38($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X38);
    // 0x8002C788: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8002C78C: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8002C790: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8002C794: jal         0x8002CE70
    // 0x8002C798: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    func_8002CE70(rdram, ctx);
        goto after_0;
    // 0x8002C798: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_0:
    // 0x8002C79C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x8002C7A0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8002C7A4: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x8002C7A8: beq         $t5, $zero, L_8002C7D0
    if (ctx->r13 == 0) {
        // 0x8002C7AC: nop
    
            goto L_8002C7D0;
    }
    // 0x8002C7AC: nop

    // 0x8002C7B0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002C7B4: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x8002C7B8: lw          $t9, 0x34($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X34);
    // 0x8002C7BC: lh          $t1, 0x0($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X0);
    // 0x8002C7C0: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8002C7C4: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x8002C7C8: b           L_8002C7E0
    // 0x8002C7CC: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
        goto L_8002C7E0;
    // 0x8002C7CC: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
L_8002C7D0:
    // 0x8002C7D0: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8002C7D4: lh          $t3, 0x0($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X0);
    // 0x8002C7D8: addiu       $t4, $t3, 0x20
    ctx->r12 = ADD32(ctx->r11, 0X20);
    // 0x8002C7DC: sh          $t4, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r12;
L_8002C7E0:
    // 0x8002C7E0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002C7E4: lw          $t7, 0x14($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X14);
    // 0x8002C7E8: andi        $t9, $t7, 0xF
    ctx->r25 = ctx->r15 & 0XF;
    // 0x8002C7EC: sw          $t9, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r25;
    // 0x8002C7F0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8002C7F4: lw          $t0, 0x20($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X20);
    // 0x8002C7F8: lw          $t6, 0x14($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X14);
    // 0x8002C7FC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8002C800: srl         $t3, $t6, 4
    ctx->r11 = S32(U32(ctx->r14) >> 4);
    // 0x8002C804: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8002C808: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8002C80C: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x8002C810: addiu       $t7, $t8, 0x9
    ctx->r15 = ADD32(ctx->r24, 0X9);
    // 0x8002C814: sw          $t7, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r15;
    // 0x8002C818: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8002C81C: lw          $t5, 0x14($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X14);
    // 0x8002C820: sw          $t5, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r13;
    // 0x8002C824: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x8002C828: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x8002C82C: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8002C830: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8002C834: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8002C838: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002C83C: beq         $at, $zero, L_8002C9EC
    if (ctx->r1 == 0) {
        // 0x8002C840: nop
    
            goto L_8002C9EC;
    }
    // 0x8002C840: nop

L_8002C844:
    // 0x8002C844: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8002C848: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8002C84C: subu        $t7, $t4, $t8
    ctx->r15 = SUB32(ctx->r12, ctx->r24);
    // 0x8002C850: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
    // 0x8002C854: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8002C858: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002C85C: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x8002C860: addiu       $t5, $t1, 0x1
    ctx->r13 = ADD32(ctx->r9, 0X1);
    // 0x8002C864: sll         $t9, $t5, 5
    ctx->r25 = S32(ctx->r13 << 5);
    // 0x8002C868: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x8002C86C: addiu       $t3, $t6, 0x10
    ctx->r11 = ADD32(ctx->r14, 0X10);
    // 0x8002C870: and         $t2, $t3, $at
    ctx->r10 = ctx->r11 & ctx->r1;
    // 0x8002C874: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x8002C878: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8002C87C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002C880: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8002C884: addu        $t1, $t4, $t7
    ctx->r9 = ADD32(ctx->r12, ctx->r15);
    // 0x8002C888: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8002C88C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002C890: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002C894: lw          $t9, 0x1C($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X1C);
    // 0x8002C898: beq         $t9, $at, L_8002C8B8
    if (ctx->r25 == ctx->r1) {
        // 0x8002C89C: nop
    
            goto L_8002C8B8;
    }
    // 0x8002C89C: nop

    // 0x8002C8A0: beq         $t9, $zero, L_8002C8B8
    if (ctx->r25 == 0) {
        // 0x8002C8A4: nop
    
            goto L_8002C8B8;
    }
    // 0x8002C8A4: nop

    // 0x8002C8A8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8002C8AC: lw          $t6, 0x1C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X1C);
    // 0x8002C8B0: addiu       $t3, $t6, -0x1
    ctx->r11 = ADD32(ctx->r14, -0X1);
    // 0x8002C8B4: sw          $t3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r11;
L_8002C8B8:
    // 0x8002C8B8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8002C8BC: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8002C8C0: lw          $t4, 0x18($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X18);
    // 0x8002C8C4: lw          $t7, 0x14($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X14);
    // 0x8002C8C8: subu        $t1, $t4, $t7
    ctx->r9 = SUB32(ctx->r12, ctx->r15);
    // 0x8002C8CC: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
    // 0x8002C8D0: beq         $at, $zero, L_8002C8E0
    if (ctx->r1 == 0) {
        // 0x8002C8D4: nop
    
            goto L_8002C8E0;
    }
    // 0x8002C8D4: nop

    // 0x8002C8D8: b           L_8002C8F4
    // 0x8002C8DC: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
        goto L_8002C8F4;
    // 0x8002C8DC: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
L_8002C8E0:
    // 0x8002C8E0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002C8E4: lw          $t9, 0x18($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X18);
    // 0x8002C8E8: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x8002C8EC: subu        $t3, $t9, $t6
    ctx->r11 = SUB32(ctx->r25, ctx->r14);
    // 0x8002C8F0: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
L_8002C8F4:
    // 0x8002C8F4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8002C8F8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8002C8FC: lw          $t4, 0x34($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X34);
    // 0x8002C900: addu        $t7, $t0, $t4
    ctx->r15 = ADD32(ctx->r8, ctx->r12);
    // 0x8002C904: addiu       $t1, $t7, -0x10
    ctx->r9 = ADD32(ctx->r15, -0X10);
    // 0x8002C908: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8002C90C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8002C910: bgez        $t2, L_8002C91C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8002C914: nop
    
            goto L_8002C91C;
    }
    // 0x8002C914: nop

    // 0x8002C918: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
L_8002C91C:
    // 0x8002C91C: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8002C920: addiu       $t9, $t5, 0xF
    ctx->r25 = ADD32(ctx->r13, 0XF);
    // 0x8002C924: sra         $t6, $t9, 4
    ctx->r14 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8002C928: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x8002C92C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8002C930: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x8002C934: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x8002C938: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x8002C93C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8002C940: lh          $t7, 0x7A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X7A);
    // 0x8002C944: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8002C948: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002C94C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8002C950: lw          $t1, 0x38($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X38);
    // 0x8002C954: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8002C958: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8002C95C: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x8002C960: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8002C964: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8002C968: jal         0x8002CE70
    // 0x8002C96C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_8002CE70(rdram, ctx);
        goto after_1;
    // 0x8002C96C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_1:
    // 0x8002C970: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x8002C974: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8002C978: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x8002C97C: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x8002C980: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8002C984: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002C988: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8002C98C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002C990: lw          $t3, 0x34($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X34);
    // 0x8002C994: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002C998: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C99C: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x8002C9A0: addu        $t7, $t8, $t4
    ctx->r15 = ADD32(ctx->r24, ctx->r12);
    // 0x8002C9A4: and         $t0, $t7, $at
    ctx->r8 = ctx->r15 & ctx->r1;
    // 0x8002C9A8: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x8002C9AC: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8002C9B0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8002C9B4: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002C9B8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8002C9BC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C9C0: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x8002C9C4: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x8002C9C8: andi        $t4, $t8, 0xFFFF
    ctx->r12 = ctx->r24 & 0XFFFF;
    // 0x8002C9CC: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8002C9D0: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x8002C9D4: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8002C9D8: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x8002C9DC: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8002C9E0: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C9E4: bne         $at, $zero, L_8002C844
    if (ctx->r1 != 0) {
        // 0x8002C9E8: nop
    
            goto L_8002C844;
    }
    // 0x8002C9E8: nop

L_8002C9EC:
    // 0x8002C9EC: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002C9F0: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8002C9F4: lw          $t9, 0x34($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X34);
    // 0x8002C9F8: addu        $t8, $t9, $t3
    ctx->r24 = ADD32(ctx->r25, ctx->r11);
    // 0x8002C9FC: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8002CA00: sw          $t6, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r14;
    // 0x8002CA04: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8002CA08: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x8002CA0C: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x8002CA10: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8002CA14: sw          $t1, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r9;
    // 0x8002CA18: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002CA1C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8002CA20: lw          $t9, 0x3C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X3C);
    // 0x8002CA24: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x8002CA28: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x8002CA2C: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8002CA30: sw          $t6, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->r14;
    // 0x8002CA34: b           L_8002CC88
    // 0x8002CA38: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_8002CC88;
    // 0x8002CA38: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_8002CA3C:
    // 0x8002CA3C: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8002CA40: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8002CA44: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x8002CA48: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8002CA4C: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8002CA50: lw          $t9, 0x20($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X20);
    // 0x8002CA54: lw          $t1, 0x3C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X3C);
    // 0x8002CA58: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8002CA5C: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x8002CA60: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x8002CA64: addu        $t2, $t8, $t6
    ctx->r10 = ADD32(ctx->r24, ctx->r14);
    // 0x8002CA68: subu        $t5, $t3, $t2
    ctx->r13 = SUB32(ctx->r11, ctx->r10);
    // 0x8002CA6C: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x8002CA70: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8002CA74: bgez        $t7, L_8002CA80
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8002CA78: nop
    
            goto L_8002CA80;
    }
    // 0x8002CA78: nop

    // 0x8002CA7C: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
L_8002CA80:
    // 0x8002CA80: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8002CA84: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8002CA88: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8002CA8C: mflo        $t4
    ctx->r12 = lo;
    // 0x8002CA90: sll         $t0, $t4, 4
    ctx->r8 = S32(ctx->r12 << 4);
    // 0x8002CA94: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x8002CA98: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8002CA9C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8002CAA0: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8002CAA4: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x8002CAA8: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002CAAC: beq         $at, $zero, L_8002CAC4
    if (ctx->r1 == 0) {
        // 0x8002CAB0: nop
    
            goto L_8002CAC4;
    }
    // 0x8002CAB0: nop

    // 0x8002CAB4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8002CAB8: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8002CABC: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x8002CAC0: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
L_8002CAC4:
    // 0x8002CAC4: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8002CAC8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8002CACC: subu        $t0, $t1, $t4
    ctx->r8 = SUB32(ctx->r9, ctx->r12);
    // 0x8002CAD0: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x8002CAD4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8002CAD8: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8002CADC: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x8002CAE0: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x8002CAE4: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002CAE8: beq         $at, $zero, L_8002CBC4
    if (ctx->r1 == 0) {
        // 0x8002CAEC: nop
    
            goto L_8002CBC4;
    }
    // 0x8002CAEC: nop

    // 0x8002CAF0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002CAF4: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8002CAF8: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x8002CAFC: lh          $t8, 0x7A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7A);
    // 0x8002CB00: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002CB04: lh          $t0, 0x0($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X0);
    // 0x8002CB08: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8002CB0C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8002CB10: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8002CB14: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8002CB18: lw          $t6, 0x38($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X38);
    // 0x8002CB1C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8002CB20: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8002CB24: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8002CB28: subu        $a2, $t7, $t1
    ctx->r6 = SUB32(ctx->r15, ctx->r9);
    // 0x8002CB2C: jal         0x8002CE70
    // 0x8002CB30: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8002CE70(rdram, ctx);
        goto after_2;
    // 0x8002CB30: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_2:
    // 0x8002CB34: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x8002CB38: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8002CB3C: lw          $t3, 0x34($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X34);
    // 0x8002CB40: beq         $t3, $zero, L_8002CB68
    if (ctx->r11 == 0) {
        // 0x8002CB44: nop
    
            goto L_8002CB68;
    }
    // 0x8002CB44: nop

    // 0x8002CB48: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8002CB4C: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8002CB50: lw          $t4, 0x34($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X34);
    // 0x8002CB54: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x8002CB58: sll         $t0, $t4, 1
    ctx->r8 = S32(ctx->r12 << 1);
    // 0x8002CB5C: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8002CB60: b           L_8002CB78
    // 0x8002CB64: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
        goto L_8002CB78;
    // 0x8002CB64: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
L_8002CB68:
    // 0x8002CB68: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x8002CB6C: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8002CB70: addiu       $t9, $t6, 0x20
    ctx->r25 = ADD32(ctx->r14, 0X20);
    // 0x8002CB74: sh          $t9, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r25;
L_8002CB78:
    // 0x8002CB78: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8002CB7C: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8002CB80: lw          $t1, 0x34($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X34);
    // 0x8002CB84: addu        $t7, $t1, $t4
    ctx->r15 = ADD32(ctx->r9, ctx->r12);
    // 0x8002CB88: andi        $t0, $t7, 0xF
    ctx->r8 = ctx->r15 & 0XF;
    // 0x8002CB8C: sw          $t0, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r8;
    // 0x8002CB90: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8002CB94: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8002CB98: lw          $t2, 0x30($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X30);
    // 0x8002CB9C: addu        $t9, $t2, $t6
    ctx->r25 = ADD32(ctx->r10, ctx->r14);
    // 0x8002CBA0: sw          $t9, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r25;
    // 0x8002CBA4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002CBA8: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8002CBAC: lw          $t1, 0x3C($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X3C);
    // 0x8002CBB0: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x8002CBB4: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x8002CBB8: addu        $t0, $t1, $t7
    ctx->r8 = ADD32(ctx->r9, ctx->r15);
    // 0x8002CBBC: b           L_8002CBE8
    // 0x8002CBC0: sw          $t0, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r8;
        goto L_8002CBE8;
    // 0x8002CBC0: sw          $t0, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r8;
L_8002CBC4:
    // 0x8002CBC4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8002CBC8: sw          $zero, 0x34($t3)
    MEM_W(0X34, ctx->r11) = 0;
    // 0x8002CBCC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002CBD0: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8002CBD4: lw          $t6, 0x3C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X3C);
    // 0x8002CBD8: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x8002CBDC: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8002CBE0: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x8002CBE4: sw          $t4, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->r12;
L_8002CBE8:
    // 0x8002CBE8: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8002CBEC: beq         $t1, $zero, L_8002CC78
    if (ctx->r9 == 0) {
        // 0x8002CBF0: nop
    
            goto L_8002CC78;
    }
    // 0x8002CBF0: nop

    // 0x8002CBF4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002CBF8: sw          $zero, 0x34($t7)
    MEM_W(0X34, ctx->r15) = 0;
    // 0x8002CBFC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8002CC00: beq         $t0, $zero, L_8002CC28
    if (ctx->r8 == 0) {
        // 0x8002CC04: nop
    
            goto L_8002CC28;
    }
    // 0x8002CC04: nop

    // 0x8002CC08: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8002CC0C: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8002CC10: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8002CC14: addu        $t9, $t5, $t3
    ctx->r25 = ADD32(ctx->r13, ctx->r11);
    // 0x8002CC18: subu        $t8, $t9, $t6
    ctx->r24 = SUB32(ctx->r25, ctx->r14);
    // 0x8002CC1C: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x8002CC20: b           L_8002CC2C
    // 0x8002CC24: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
        goto L_8002CC2C;
    // 0x8002CC24: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
L_8002CC28:
    // 0x8002CC28: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
L_8002CC2C:
    // 0x8002CC2C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8002CC30: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x8002CC34: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x8002CC38: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8002CC3C: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8002CC40: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8002CC44: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002CC48: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x8002CC4C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002CC50: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8002CC54: addu        $t3, $t0, $t5
    ctx->r11 = ADD32(ctx->r8, ctx->r13);
    // 0x8002CC58: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x8002CC5C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8002CC60: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8002CC64: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8002CC68: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8002CC6C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8002CC70: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8002CC74: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
L_8002CC78:
    // 0x8002CC78: b           L_8002CC88
    // 0x8002CC7C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_8002CC88;
    // 0x8002CC7C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x8002CC80: b           L_8002CC88
    // 0x8002CC84: nop

        goto L_8002CC88;
    // 0x8002CC84: nop

L_8002CC88:
    // 0x8002CC88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CC8C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002CC90: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8002CC94: jr          $ra
    // 0x8002CC98: nop

    return;
    // 0x8002CC98: nop

;}
RECOMP_FUNC void func_808002C4_chbilldrillboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002D0: jal         0x808004D4
    // 0x808002D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808004D4_chbilldrillboulder(rdram, ctx);
        goto after_0;
    // 0x808002D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002D8: beq         $v0, $zero, L_80800300
    if (ctx->r2 == 0) {
        // 0x808002DC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800300;
    }
    // 0x808002DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002E0: jal         0x800DA298
    // 0x808002E4: nop

    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808002E4: nop

    after_1:
    // 0x808002E8: beql        $v0, $zero, L_80800304
    if (ctx->r2 == 0) {
        // 0x808002EC: lw          $t6, 0x6C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X6C);
            goto L_80800304;
    }
    goto skip_0;
    // 0x808002EC: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x808002F0: jal         0x800FFAB0
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002F8: b           L_808003E0
    // 0x808002FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003E0;
    // 0x808002FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800300:
    // 0x80800300: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
L_80800304:
    // 0x80800304: addiu       $at, $zero, 0x3CF
    ctx->r1 = ADD32(0, 0X3CF);
    // 0x80800308: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x8080030C: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800310: bnel        $t8, $at, L_808003E0
    if (ctx->r24 != ctx->r1) {
        // 0x80800314: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003E0;
    }
    goto skip_1;
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800318: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x8080031C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800320: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    // 0x80800324: srl         $t9, $v0, 7
    ctx->r25 = S32(U32(ctx->r2) >> 7);
    // 0x80800328: addiu       $v0, $t9, -0x32
    ctx->r2 = ADD32(ctx->r25, -0X32);
    // 0x8080032C: beq         $v0, $at, L_80800344
    if (ctx->r2 == ctx->r1) {
        // 0x80800330: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800344;
    }
    // 0x80800330: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800334: beq         $v0, $at, L_80800394
    if (ctx->r2 == ctx->r1) {
        // 0x80800338: addiu       $a0, $zero, 0x1F7
        ctx->r4 = ADD32(0, 0X1F7);
            goto L_80800394;
    }
    // 0x80800338: addiu       $a0, $zero, 0x1F7
    ctx->r4 = ADD32(0, 0X1F7);
    // 0x8080033C: b           L_808003E0
    // 0x80800340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003E0;
    // 0x80800340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800344:
    // 0x80800344: jal         0x80088278
    // 0x80800348: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800348: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8080034C: jal         0x80088C08
    // 0x80800350: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x80800350: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800354: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800358: andi        $t1, $v0, 0x1FF
    ctx->r9 = ctx->r2 & 0X1FF;
    // 0x8080035C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800360: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80800364: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800368: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    // 0x8080036C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800370: andi        $t5, $a0, 0x1FF
    ctx->r13 = ctx->r4 & 0X1FF;
    // 0x80800374: jal         0x800D0A9C
    // 0x80800378: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_800D0A9C(rdram, ctx);
        goto after_5;
    // 0x80800378: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_5:
    // 0x8080037C: beql        $v0, $zero, L_808003E0
    if (ctx->r2 == 0) {
        // 0x80800380: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003E0;
    }
    goto skip_2;
    // 0x80800380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800384: jal         0x800FFAB0
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080038C: b           L_808003E0
    // 0x80800390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003E0;
    // 0x80800390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800394:
    // 0x80800394: jal         0x80088278
    // 0x80800398: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800398: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8080039C: jal         0x80088C08
    // 0x808003A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x808003A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x808003A4: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808003A8: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x808003AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003B0: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808003B4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808003B8: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x808003BC: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808003C0: andi        $t2, $a0, 0x1FF
    ctx->r10 = ctx->r4 & 0X1FF;
    // 0x808003C4: jal         0x800D0A9C
    // 0x808003C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800D0A9C(rdram, ctx);
        goto after_9;
    // 0x808003C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_9:
    // 0x808003CC: beql        $v0, $zero, L_808003E0
    if (ctx->r2 == 0) {
        // 0x808003D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003E0;
    }
    goto skip_3;
    // 0x808003D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808003D4: jal         0x800FFAB0
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808003DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003E0:
    // 0x808003E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003E8: jr          $ra
    // 0x808003EC: nop

    return;
    // 0x808003EC: nop

;}
RECOMP_FUNC void func_80802304_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802304: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802308: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080230C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80802310: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80802314: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80802318: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8080231C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80802320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802324: bc1tl       L_80802390
    if (c1cs) {
        // 0x80802328: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802390;
    }
    goto skip_0;
    // 0x80802328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080232C: sub.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80802330: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802334: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802338: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080233C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80802340: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802344: div.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80802348: bc1fl       L_80802364
    if (!c1cs) {
        // 0x8080234C: neg.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
            goto L_80802364;
    }
    goto skip_1;
    // 0x8080234C: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    skip_1:
    // 0x80802350: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80802354: mul.s       $f20, $f10, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80802358: b           L_80802380
    // 0x8080235C: nop

        goto L_80802380;
    // 0x8080235C: nop

    // 0x80802360: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
L_80802364:
    // 0x80802364: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80802368: nop

    // 0x8080236C: bc1f        L_80802380
    if (!c1cs) {
        // 0x80802370: nop
    
            goto L_80802380;
    }
    // 0x80802370: nop

    // 0x80802374: add.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80802378: mul.s       $f20, $f18, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8080237C: nop

L_80802380:
    // 0x80802380: jal         0x800F0DC0
    // 0x80802384: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800F0DC0(rdram, ctx);
        goto after_0;
    // 0x80802384: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80802388: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080238C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802390:
    // 0x80802390: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80802394: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80802398: jr          $ra
    // 0x8080239C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080239C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80802914_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080291C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3CA8) << 16);
    // 0x80802920: addiu       $a2, $a2, 0x3CA8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3CA8));
    // 0x80802924: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80802928: jal         0x80089D20
    // 0x8080292C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080292C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x80802930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802938: jr          $ra
    // 0x8080293C: nop

    return;
    // 0x8080293C: nop

;}
RECOMP_FUNC void ncba1p_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808008B8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808008BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808008C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808008C8: jal         0x800EE7F8
    // 0x808008CC: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808008CC: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x808008D0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808008D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008D8: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x808008DC: jal         0x800EE7F8
    // 0x808008E0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808008E0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_1:
    // 0x808008E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008EC: jr          $ra
    // 0x808008F0: nop

    return;
    // 0x808008F0: nop

    // 0x808008F4: nop

    // 0x808008F8: nop

    // 0x808008FC: nop

;}
RECOMP_FUNC void badust_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808006D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006E4: jal         0x8009C128
    // 0x808006E8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808006E8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x808006EC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808006F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006F4: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808006F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808006FC: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80800700: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x80800704: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80800708: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8080070C: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    // 0x80800710: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x80800714: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x80800718: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8080071C: bne         $at, $zero, L_80800730
    if (ctx->r1 != 0) {
        // 0x80800720: nop
    
            goto L_80800730;
    }
    // 0x80800720: nop

    // 0x80800724: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    // 0x80800728: lw          $t8, 0x5C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X5C);
    // 0x8080072C: lbu         $v1, 0x8($t8)
    ctx->r3 = MEM_BU(ctx->r24, 0X8);
L_80800730:
    // 0x80800730: beq         $v1, $zero, L_808007AC
    if (ctx->r3 == 0) {
        // 0x80800734: nop
    
            goto L_808007AC;
    }
    // 0x80800734: nop

    // 0x80800738: jal         0x8009C984
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800740: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800744: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800748: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080074C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800750: jal         0x800DC178
    // 0x80800754: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800754: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800758: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080075C: jal         0x800136E4
    // 0x80800760: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x80800760: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    after_3:
    // 0x80800764: jal         0x800DC0C0
    // 0x80800768: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_4;
    // 0x80800768: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8080076C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800770: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800774: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800778: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080077C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800780: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800784: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800788: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8080078C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800790: jal         0x800EFCD8
    // 0x80800794: nop

    func_800EFCD8(rdram, ctx);
        goto after_5;
    // 0x80800794: nop

    after_5:
    // 0x80800798: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080079C: nop

    // 0x808007A0: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x808007A4: lw          $t9, 0x5C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X5C);
    // 0x808007A8: lbu         $v1, 0x8($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X8);
L_808007AC:
    // 0x808007AC: beq         $v1, $zero, L_808007F4
    if (ctx->r3 == 0) {
        // 0x808007B0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808007F4;
    }
    // 0x808007B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007B4: beq         $v1, $at, L_808007D0
    if (ctx->r3 == ctx->r1) {
        // 0x808007B8: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_808007D0;
    }
    // 0x808007B8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808007BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007C0: beq         $v1, $at, L_808007EC
    if (ctx->r3 == ctx->r1) {
        // 0x808007C4: addiu       $a0, $sp, 0x50
        ctx->r4 = ADD32(ctx->r29, 0X50);
            goto L_808007EC;
    }
    // 0x808007C4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808007C8: b           L_808007F4
    // 0x808007CC: nop

        goto L_808007F4;
    // 0x808007CC: nop

L_808007D0:
    // 0x808007D0: jal         0x800EF334
    // 0x808007D4: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    func_800EF334(rdram, ctx);
        goto after_6;
    // 0x808007D4: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    after_6:
    // 0x808007D8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808007DC: jal         0x800EF04C
    // 0x808007E0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x808007E0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_7:
    // 0x808007E4: b           L_808007F4
    // 0x808007E8: nop

        goto L_808007F4;
    // 0x808007E8: nop

L_808007EC:
    // 0x808007EC: jal         0x800EF04C
    // 0x808007F0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x808007F0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_8:
L_808007F4:
    // 0x808007F4: jal         0x8009C984
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_9;
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808007FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800800: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80800804: jal         0x800EFCD8
    // 0x80800808: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_800EFCD8(rdram, ctx);
        goto after_10;
    // 0x80800808: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_10:
    // 0x8080080C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800810: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800814: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800818: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080081C: jal         0x800DC178
    // 0x80800820: nop

    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80800820: nop

    after_11:
    // 0x80800824: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC90) << 16);
    // 0x80800828: lwc1        $f12, 0xC90($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC90));
    // 0x8080082C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800830: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800834: jal         0x800DC178
    // 0x80800838: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80800838: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x8080083C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC94) << 16);
    // 0x80800840: lwc1        $f12, 0xC94($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC94));
    // 0x80800844: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC98) << 16);
    // 0x80800848: lwc1        $f14, 0xC98($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC98));
    // 0x8080084C: jal         0x800DC178
    // 0x80800850: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x80800850: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x80800854: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC9C) << 16);
    // 0x80800858: lwc1        $f12, 0xC9C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC9C));
    // 0x8080085C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XCA0) << 16);
    // 0x80800860: lwc1        $f14, 0xCA0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XCA0));
    // 0x80800864: jal         0x800DC178
    // 0x80800868: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_14;
    // 0x80800868: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x8080086C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80800878: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x8080087C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800880: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80800884: jal         0x80800260
    // 0x80800888: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    badust_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x80800888: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x8080088C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800890: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800894: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800898: jr          $ra
    // 0x8080089C: nop

    return;
    // 0x8080089C: nop

;}
RECOMP_FUNC void func_8010754C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010754C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107554: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80107558: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8010755C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80107560: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80107564: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80107568: jal         0x800EE88C
    // 0x8010756C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x8010756C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80107570: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80107574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80107578: lwl         $t6, 0xD($a3)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r7, 0XD);
    // 0x8010757C: lwr         $t6, 0x10($a3)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r7, 0X10);
    // 0x80107580: lhu         $t2, 0x72($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X72);
    // 0x80107584: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80107588: srl         $t9, $t7, 20
    ctx->r25 = S32(U32(ctx->r15) >> 20);
    // 0x8010758C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80107590: andi        $t1, $t0, 0x3F0
    ctx->r9 = ctx->r8 & 0X3F0;
    // 0x80107594: andi        $t3, $t2, 0xFC0F
    ctx->r11 = ctx->r10 & 0XFC0F;
    // 0x80107598: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8010759C: sh          $t4, 0x72($a0)
    MEM_H(0X72, ctx->r4) = ctx->r12;
    // 0x801075A0: lw          $t5, 0xC($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XC);
    // 0x801075A4: lbu         $t0, 0x70($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X70);
    // 0x801075A8: srl         $t7, $t5, 20
    ctx->r15 = S32(U32(ctx->r13) >> 20);
    // 0x801075AC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x801075B0: andi        $t2, $t0, 0xFF01
    ctx->r10 = ctx->r8 & 0XFF01;
    // 0x801075B4: or          $t1, $t9, $t2
    ctx->r9 = ctx->r25 | ctx->r10;
    // 0x801075B8: sb          $t1, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r9;
    // 0x801075BC: lh          $t3, 0x12($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X12);
    // 0x801075C0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801075C4: nop

    // 0x801075C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801075CC: jal         0x80103014
    // 0x801075D0: swc1        $f6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f6.u32l;
    func_80103014(rdram, ctx);
        goto after_1;
    // 0x801075D0: swc1        $f6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f6.u32l;
    after_1:
    // 0x801075D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801075D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801075DC: jr          $ra
    // 0x801075E0: nop

    return;
    // 0x801075E0: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012A0: lwc1        $f12, 0x10($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X10);
    // 0x808012A4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808012A8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808012AC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x808012B0: sh          $a1, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r5;
    // 0x808012B4: sh          $a2, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r6;
    // 0x808012B8: sh          $a3, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r7;
    // 0x808012BC: swc1        $f12, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f12.u32l;
    // 0x808012C0: jr          $ra
    // 0x808012C4: swc1        $f12, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x808012C4: swc1        $f12, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800018_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080001C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800024: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800028: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080002C: jal         0x80100094
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800034: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800038: jal         0x80088840
    // 0x8080003C: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x8080003C: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_1:
    // 0x80800040: beq         $v0, $zero, L_80800058
    if (ctx->r2 == 0) {
        // 0x80800044: nop
    
            goto L_80800058;
    }
    // 0x80800044: nop

    // 0x80800048: jal         0x800FFAB0
    // 0x8080004C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080004C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800050: b           L_808002AC
    // 0x80800054: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002AC;
    // 0x80800054: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800058:
    // 0x80800058: jal         0x80088848
    // 0x8080005C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x8080005C: nop

    after_3:
    // 0x80800060: bnel        $v0, $zero, L_808000E0
    if (ctx->r2 != 0) {
        // 0x80800064: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808000E0;
    }
    goto skip_0;
    // 0x80800064: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x80800068: jal         0x800DA298
    // 0x8080006C: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x8080006C: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    after_4:
    // 0x80800070: beq         $v0, $zero, L_80800090
    if (ctx->r2 == 0) {
        // 0x80800074: nop
    
            goto L_80800090;
    }
    // 0x80800074: nop

    // 0x80800078: jal         0x800861A8
    // 0x8080007C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x8080007C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80800080: jal         0x800FFAB0
    // 0x80800084: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800084: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80800088: b           L_808002AC
    // 0x8080008C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002AC;
    // 0x8080008C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800090:
    // 0x80800090: jal         0x800DA298
    // 0x80800094: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800094: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    after_7:
    // 0x80800098: beql        $v0, $zero, L_808000E0
    if (ctx->r2 == 0) {
        // 0x8080009C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808000E0;
    }
    goto skip_1;
    // 0x8080009C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_1:
    // 0x808000A0: jal         0x800F54E4
    // 0x808000A4: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x808000A4: nop

    after_8:
    // 0x808000A8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808000AC: jal         0x800F6438
    // 0x808000B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_9;
    // 0x808000B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x808000B4: beq         $v0, $zero, L_808000DC
    if (ctx->r2 == 0) {
        // 0x808000B8: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808000DC;
    }
    // 0x808000B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808000BC: jal         0x800F64A4
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_10;
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808000C4: bnel        $v0, $zero, L_808000E0
    if (ctx->r2 != 0) {
        // 0x808000C8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808000E0;
    }
    goto skip_2;
    // 0x808000C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_2:
    // 0x808000CC: jal         0x800FFAB0
    // 0x808000D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_11;
    // 0x808000D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x808000D4: b           L_808002AC
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002AC;
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000DC:
    // 0x808000DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_808000E0:
    // 0x808000E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000E8: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x808000EC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x808000F0: jal         0x8008A0C8
    // 0x808000F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x808000F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_12:
    // 0x808000F8: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    // 0x808000FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800100: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800104: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800108: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080010C: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80800110: jal         0x8008A0C8
    // 0x80800114: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80800114: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    after_13:
    // 0x80800118: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080011C: jal         0x80102D78
    // 0x80800120: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80102D78(rdram, ctx);
        goto after_14;
    // 0x80800120: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x80800124: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x80800128: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x8080012C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800130: jal         0x800EE7F8
    // 0x80800134: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80800134: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    after_15:
    // 0x80800138: jal         0x8008A020
    // 0x8080013C: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_16;
    // 0x8080013C: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_16:
    // 0x80800140: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800144: jal         0x80108B04
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_17;
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x8080014C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800150: jal         0x80109EEC
    // 0x80800154: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109EEC(rdram, ctx);
        goto after_18;
    // 0x80800154: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_18:
    // 0x80800158: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080015C: sh          $t8, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r24;
    // 0x80800160: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800164: jal         0x800BF744
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_19;
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x8080016C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800170: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800174: sb          $v1, 0x68($s0)
    MEM_B(0X68, ctx->r16) = ctx->r3;
    // 0x80800178: sb          $v1, 0x69($s0)
    MEM_B(0X69, ctx->r16) = ctx->r3;
    // 0x8080017C: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x80800180: sb          $v1, 0x69($v0)
    MEM_B(0X69, ctx->r2) = ctx->r3;
    // 0x80800184: sb          $v1, 0x6A($v0)
    MEM_B(0X6A, ctx->r2) = ctx->r3;
    // 0x80800188: sb          $v1, 0x6B($v0)
    MEM_B(0X6B, ctx->r2) = ctx->r3;
    // 0x8080018C: sb          $v1, 0x68($v0)
    MEM_B(0X68, ctx->r2) = ctx->r3;
    // 0x80800190: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800194: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800198: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8080019C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x808001A0: sb          $t9, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r25;
    // 0x808001A4: sh          $v0, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r2;
    // 0x808001A8: sh          $v0, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r2;
    // 0x808001AC: jal         0x800F54E4
    // 0x808001B0: swc1        $f4, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f4.u32l;
    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x808001B0: swc1        $f4, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f4.u32l;
    after_20:
    // 0x808001B4: jal         0x80088848
    // 0x808001B8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_21;
    // 0x808001B8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_21:
    // 0x808001BC: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001C0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808001EC;
    }
    // 0x808001C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001C4: jal         0x800EE7F8
    // 0x808001C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_22;
    // 0x808001C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_22:
    // 0x808001CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001D0: jal         0x80102424
    // 0x808001D4: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    func_80102424(rdram, ctx);
        goto after_23;
    // 0x808001D4: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_23:
    // 0x808001D8: lbu         $t0, 0x7B($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X7B);
    // 0x808001DC: andi        $t1, $t0, 0xFF3F
    ctx->r9 = ctx->r8 & 0XFF3F;
    // 0x808001E0: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x808001E4: b           L_808002A8
    // 0x808001E8: sb          $t2, 0x7B($s1)
    MEM_B(0X7B, ctx->r17) = ctx->r10;
        goto L_808002A8;
    // 0x808001E8: sb          $t2, 0x7B($s1)
    MEM_B(0X7B, ctx->r17) = ctx->r10;
L_808001EC:
    // 0x808001EC: jal         0x800DA298
    // 0x808001F0: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    func_800DA298(rdram, ctx);
        goto after_24;
    // 0x808001F0: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    after_24:
    // 0x808001F4: beq         $v0, $zero, L_80800274
    if (ctx->r2 == 0) {
        // 0x808001F8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800274;
    }
    // 0x808001F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001FC: jal         0x800EE7F8
    // 0x80800200: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_25;
    // 0x80800200: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_25:
    // 0x80800204: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800208: jal         0x800F608C
    // 0x8080020C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_26;
    // 0x8080020C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80800210: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800214: jal         0x800F8294
    // 0x80800218: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F8294(rdram, ctx);
        goto after_27;
    // 0x80800218: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_27:
    // 0x8080021C: jal         0x800F497C
    // 0x80800220: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800F497C(rdram, ctx);
        goto after_28;
    // 0x80800220: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_28:
    // 0x80800224: jal         0x800878F8
    // 0x80800228: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _plcamera_entrypoint_8(rdram, ctx);
        goto after_29;
    // 0x80800228: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_29:
    // 0x8080022C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800230: jal         0x80801AA0
    // 0x80800234: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_30;
    // 0x80800234: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_30:
    // 0x80800238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080023C: addiu       $a1, $zero, 0x1356
    ctx->r5 = ADD32(0, 0X1356);
    // 0x80800240: jal         0x80802214
    // 0x80800244: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_31;
    // 0x80800244: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_31:
    // 0x80800248: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080024C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80800250: jal         0x80803CF0
    // 0x80800254: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_32;
    // 0x80800254: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_32:
    // 0x80800258: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8080025C: sb          $v1, 0x61($s0)
    MEM_B(0X61, ctx->r16) = ctx->r3;
    // 0x80800260: lbu         $t3, 0x7B($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X7B);
    // 0x80800264: andi        $t4, $t3, 0xFF3F
    ctx->r12 = ctx->r11 & 0XFF3F;
    // 0x80800268: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x8080026C: b           L_808002A8
    // 0x80800270: sb          $t5, 0x7B($s1)
    MEM_B(0X7B, ctx->r17) = ctx->r13;
        goto L_808002A8;
    // 0x80800270: sb          $t5, 0x7B($s1)
    MEM_B(0X7B, ctx->r17) = ctx->r13;
L_80800274:
    // 0x80800274: jal         0x800D395C
    // 0x80800278: nop

    func_800D395C(rdram, ctx);
        goto after_33;
    // 0x80800278: nop

    after_33:
    // 0x8080027C: beq         $v0, $zero, L_80800294
    if (ctx->r2 == 0) {
        // 0x80800280: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800294;
    }
    // 0x80800280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800284: jal         0x80801AA0
    // 0x80800288: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_34;
    // 0x80800288: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_34:
    // 0x8080028C: b           L_808002AC
    // 0x80800290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808002AC;
    // 0x80800290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800294:
    // 0x80800294: jal         0x800861A8
    // 0x80800298: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_35;
    // 0x80800298: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x8080029C: lbu         $t6, 0x65($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X65);
    // 0x808002A0: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x808002A4: sb          $t7, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r15;
L_808002A8:
    // 0x808002A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002AC:
    // 0x808002AC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808002B4: jr          $ra
    // 0x808002B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808002B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gleeprom_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080001C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800024: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800028: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080002C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800030: jal         0x80016934
    // 0x80800034: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80016934(rdram, ctx);
        goto after_0;
    // 0x80800034: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800038: jal         0x80016928
    // 0x8080003C: nop

    func_80016928(rdram, ctx);
        goto after_1;
    // 0x8080003C: nop

    after_1:
    // 0x80800040: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800044: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800048: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8080004C: bgez        $a1, L_8080005C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80800050: sra         $t6, $a1, 3
        ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8080005C;
    }
    // 0x80800050: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80800054: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x80800058: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8080005C:
    // 0x8080005C: andi        $a1, $t6, 0xFF
    ctx->r5 = ctx->r14 & 0XFF;
    // 0x80800060: jal         0x8002DF00
    // 0x80800064: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    osEepromLongWrite_recomp(rdram, ctx);
        goto after_2;
    // 0x80800064: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800068: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8080006C: jal         0x80016934
    // 0x80800070: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80016934(rdram, ctx);
        goto after_3;
    // 0x80800070: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8080007C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void func_80801088_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080108C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801090: jal         0x800F54E4
    // 0x80801094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801098: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080109C: jal         0x800F6720
    // 0x808010A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6720(rdram, ctx);
        goto after_1;
    // 0x808010A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808010A4: beql        $v0, $zero, L_808010F0
    if (ctx->r2 == 0) {
        // 0x808010A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808010F0;
    }
    goto skip_0;
    // 0x808010A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808010AC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808010B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808010B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808010B8: lhu         $t6, 0x76($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X76);
    // 0x808010BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808010C0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x808010C4: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808010C8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808010CC: bgez        $t7, L_808010E0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808010D0: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808010E0;
    }
    // 0x808010D0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808010D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808010D8: nop

    // 0x808010DC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_808010E0:
    // 0x808010E0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x808010E4: jal         0x800F4F34
    // 0x808010E8: nop

    func_800F4F34(rdram, ctx);
        goto after_2;
    // 0x808010E8: nop

    after_2:
    // 0x808010EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808010F0:
    // 0x808010F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808010F4: jr          $ra
    // 0x808010F8: nop

    return;
    // 0x808010F8: nop

;}
RECOMP_FUNC void _chchuffy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C18: syscall     432
    recomp_syscall_handler(rdram, ctx, 0x80086C18);
    return;
    // 0x80086C1C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsledge_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837D0: syscall     74
    recomp_syscall_handler(rdram, ctx, 0x800837D0);
    return;
    // 0x800837D4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chjrinnlight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087190: syscall     528
    recomp_syscall_handler(rdram, ctx, 0x80087190);
    return;
    // 0x80087194: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bstaxi_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E40: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E40);
    return;
    // 0x80083E44: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _sucoaster_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A118: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A118);
    return;
    // 0x8008A11C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chmayaentrydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087088: syscall     505
    recomp_syscall_handler(rdram, ctx, 0x80087088);
    return;
    // 0x8008708C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void dbvtxnormal_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x8001B084
    // 0x80800018: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x80800018: nop

    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void func_8080000C_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80090178
    // 0x80800018: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    func_80090178(rdram, ctx);
        goto after_0;
    // 0x80800018: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    after_0:
    // 0x8080001C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800020: beq         $t6, $zero, L_80800050
    if (ctx->r14 == 0) {
        // 0x80800024: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800050;
    }
    // 0x80800024: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800028: jal         0x800878A0
    // 0x8080002C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800030: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80800034: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80800038: beql        $v0, $zero, L_80800054
    if (ctx->r2 == 0) {
        // 0x8080003C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800054;
    }
    goto skip_0;
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800040: jal         0x800878A0
    // 0x80800044: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800044: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x80800048: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8080004C: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
L_80800050:
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800054:
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void func_808000DC_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E4: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x808000E8: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x808000EC: jal         0x800D0CC8
    // 0x808000F0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800D0CC8(rdram, ctx);
        goto after_0;
    // 0x808000F0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x808000F4: jal         0x8080010C
    // 0x808000F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    chjinjo_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808000F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_80800C58_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C60: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800C64: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800C68: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    // 0x80800C6C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800C70: bgez        $t8, L_80800C88
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800C74: nop
    
            goto L_80800C88;
    }
    // 0x80800C74: nop

    // 0x80800C78: jal         0x80800BC0
    // 0x80800C7C: nop

    func_80800BC0_chnewshovel(rdram, ctx);
        goto after_0;
    // 0x80800C7C: nop

    after_0:
    // 0x80800C80: b           L_80800CB8
    // 0x80800C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800CB8;
    // 0x80800C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C88:
    // 0x80800C88: jal         0x800EEB40
    // 0x80800C8C: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x80800C8C: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x80800C90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1516, 0XF48) << 16);
    // 0x80800C94: lwc1        $f4, 0xF48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1516, 0XF48));
    // 0x80800C98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C9C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800CA0: nop

    // 0x80800CA4: bc1f        L_80800CB4
    if (!c1cs) {
        // 0x80800CA8: nop
    
            goto L_80800CB4;
    }
    // 0x80800CA8: nop

    // 0x80800CAC: b           L_80800CB4
    // 0x80800CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800CB4;
    // 0x80800CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CB4:
    // 0x80800CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CB8:
    // 0x80800CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CBC: jr          $ra
    // 0x80800CC0: nop

    return;
    // 0x80800CC0: nop

;}
RECOMP_FUNC void func_808001D0_bsclimb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001E0: jal         0x8009E74C
    // 0x808001E4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x808001E4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x808001E8: bnel        $v0, $zero, L_80800248
    if (ctx->r2 != 0) {
        // 0x808001EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800248;
    }
    goto skip_0;
    // 0x808001EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001F0: jal         0x800A4E30
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_1;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001F8: jal         0x8009F1E0
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_2;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x8008CA4C
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_3;
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x8009B800
    // 0x80800214: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baphysics_set_type(rdram, ctx);
        goto after_4;
    // 0x80800214: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x800961AC
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_5;
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800224: jal         0x80095A40
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_6;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080022C: jal         0x8008E0E8
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_7;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800234: beq         $v0, $zero, L_80800244
    if (ctx->r2 == 0) {
        // 0x80800238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800244;
    }
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x80084788
    // 0x80800240: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x80800240: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
L_80800244:
    // 0x80800244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800248:
    // 0x80800248: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080024C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800250: jr          $ra
    // 0x80800254: nop

    return;
    // 0x80800254: nop

;}
RECOMP_FUNC void basub_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808009AC: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x808009B0: jr          $ra
    // 0x808009B4: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808009B4: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _sujiggy_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A758: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A758);
    return;
    // 0x8008A75C: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void glid_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800470: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800474: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800478: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8080047C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800480: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800484: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800488: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080048C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800490: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800494: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800498: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080049C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x808004A0: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x808004A4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x808004A8: jal         0x800B2190
    // 0x808004AC: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    func_800B2190(rdram, ctx);
        goto after_0;
    // 0x808004AC: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    after_0:
    // 0x808004B0: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x808004B4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x808004B8: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x808004BC: lw          $v1, 0x4($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X4);
    // 0x808004C0: addiu       $s3, $t7, 0x1C
    ctx->r19 = ADD32(ctx->r15, 0X1C);
    // 0x808004C4: blezl       $v1, L_8080056C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x808004C8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8080056C;
    }
    goto skip_0;
    // 0x808004C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
L_808004CC:
    // 0x808004CC: lh          $t8, 0x2($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2);
    // 0x808004D0: addiu       $s6, $s3, 0x8
    ctx->r22 = ADD32(ctx->r19, 0X8);
    // 0x808004D4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808004D8: addu        $s7, $t9, $s3
    ctx->r23 = ADD32(ctx->r25, ctx->r19);
    // 0x808004DC: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
    // 0x808004E0: sltu        $at, $s6, $s7
    ctx->r1 = ctx->r22 < ctx->r23 ? 1 : 0;
    // 0x808004E4: beq         $at, $zero, L_8080054C
    if (ctx->r1 == 0) {
        // 0x808004E8: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_8080054C;
    }
    // 0x808004E8: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x808004EC: lh          $t0, 0x0($s6)
    ctx->r8 = MEM_H(ctx->r22, 0X0);
L_808004F0:
    // 0x808004F0: lh          $t2, 0x2($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X2);
    // 0x808004F4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x808004F8: addu        $s0, $t1, $fp
    ctx->r16 = ADD32(ctx->r9, ctx->r30);
    // 0x808004FC: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80800500: addu        $s2, $t3, $s0
    ctx->r18 = ADD32(ctx->r11, ctx->r16);
    // 0x80800504: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800508: beql        $at, $zero, L_80800538
    if (ctx->r1 == 0) {
        // 0x8080050C: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80800538;
    }
    goto skip_1;
    // 0x8080050C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    skip_1:
L_80800510:
    // 0x80800510: lh          $a0, 0x0($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X0);
    // 0x80800514: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800518: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080051C: jalr        $s5
    // 0x80800520: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r21)(rdram, ctx);
        goto after_1;
    // 0x80800520: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_1:
    // 0x80800524: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800528: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x8080052C: bne         $at, $zero, L_80800510
    if (ctx->r1 != 0) {
        // 0x80800530: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800510;
    }
    // 0x80800530: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80800534: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80800538:
    // 0x80800538: sltu        $at, $s6, $s7
    ctx->r1 = ctx->r22 < ctx->r23 ? 1 : 0;
    // 0x8080053C: bnel        $at, $zero, L_808004F0
    if (ctx->r1 != 0) {
        // 0x80800540: lh          $t0, 0x0($s6)
        ctx->r8 = MEM_H(ctx->r22, 0X0);
            goto L_808004F0;
    }
    goto skip_2;
    // 0x80800540: lh          $t0, 0x0($s6)
    ctx->r8 = MEM_H(ctx->r22, 0X0);
    skip_2:
    // 0x80800544: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80800548: lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X4);
L_8080054C:
    // 0x8080054C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80800550: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x80800554: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800558: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8080055C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80800560: bne         $at, $zero, L_808004CC
    if (ctx->r1 != 0) {
        // 0x80800564: addu        $s3, $s3, $t5
        ctx->r19 = ADD32(ctx->r19, ctx->r13);
            goto L_808004CC;
    }
    // 0x80800564: addu        $s3, $s3, $t5
    ctx->r19 = ADD32(ctx->r19, ctx->r13);
    // 0x80800568: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8080056C:
    // 0x8080056C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800570: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800574: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800578: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080057C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800580: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800584: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800588: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8080058C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800590: jr          $ra
    // 0x80800594: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800594: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800F1988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1988: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800F198C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F1990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1994: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F1998: swc1        $f14, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f14.u32l;
    // 0x800F199C: swc1        $f14, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f14.u32l;
    // 0x800F19A0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F19A4: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F19A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F19AC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F19B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F19B4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F19B8: jal         0x8002DCA0
    // 0x800F19BC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F19BC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800F19C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F19C4: lwc1        $f8, 0x5ED0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5ED0);
    // 0x800F19C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F19CC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800F19D0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800F19D4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x800F19D8: bc1fl       L_800F19EC
    if (!c1cs) {
        // 0x800F19DC: lwc1        $f10, 0x0($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800F19EC;
    }
    goto skip_0;
    // 0x800F19DC: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800F19E0: b           L_800F1A78
    // 0x800F19E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F1A78;
    // 0x800F19E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F19E8: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
L_800F19EC:
    // 0x800F19EC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800F19F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F19F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F19F8: jal         0x800F1800
    // 0x800F19FC: div.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    func_800F1800(rdram, ctx);
        goto after_1;
    // 0x800F19FC: div.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    after_1:
    // 0x800F1A00: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800F1A04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F1A08: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F1A0C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x800F1A10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800F1A14: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1A18: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800F1A1C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800F1A20: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800F1A24: bc1fl       L_800F1A40
    if (!c1cs) {
        // 0x800F1A28: lwc1        $f10, 0x0($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800F1A40;
    }
    goto skip_1;
    // 0x800F1A28: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x800F1A2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F1A30: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800F1A34: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F1A38: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x800F1A3C: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
L_800F1A40:
    // 0x800F1A40: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800F1A44: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800F1A48: nop

    // 0x800F1A4C: bc1f        L_800F1A64
    if (!c1cs) {
        // 0x800F1A50: nop
    
            goto L_800F1A64;
    }
    // 0x800F1A50: nop

    // 0x800F1A54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F1A58: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800F1A5C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800F1A60: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_800F1A64:
    // 0x800F1A64: jal         0x800F1800
    // 0x800F1A68: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    func_800F1800(rdram, ctx);
        goto after_2;
    // 0x800F1A68: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_2:
    // 0x800F1A6C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800F1A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F1A74: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
L_800F1A78:
    // 0x800F1A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1A7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F1A80: jr          $ra
    // 0x800F1A84: nop

    return;
    // 0x800F1A84: nop

;}
RECOMP_FUNC void func_80805D64_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805D64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80805D68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80805D6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80805D70: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80805D74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80805D78: jal         0x80100094
    // 0x80805D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80805D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80805D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805D84: jal         0x80802228
    // 0x80805D88: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80805D88: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80805D8C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80805D90: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80805D94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80805D98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80805D9C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80805DA0: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x80805DA4: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x80805DA8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80805DAC: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80805DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805DB4: jal         0x808027F4
    // 0x80805DB8: sh          $t6, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r14;
    func_808027F4_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80805DB8: sh          $t6, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r14;
    after_2:
    // 0x80805DBC: jal         0x80802C0C
    // 0x80805DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802C0C_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80805DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80805DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805DC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80805DCC: jal         0x80803BE8
    // 0x80805DD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80805DD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80805DD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80805DD8: jal         0x80804A50
    // 0x80805DDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80804A50_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80805DDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80805DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80805DE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80805DE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80805DEC: jr          $ra
    // 0x80805DF0: nop

    return;
    // 0x80805DF0: nop

;}
RECOMP_FUNC void _babuzz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847A8: syscall     120
    recomp_syscall_handler(rdram, ctx, 0x800847A8);
    return;
    // 0x800847AC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800AF614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF614: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AF618: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AF61C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AF620: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF624: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800AF628: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800AF62C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800AF630: jal         0x800AF5FC
    // 0x800AF634: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800AF5FC(rdram, ctx);
        goto after_0;
    // 0x800AF634: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800AF638: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF63C: jal         0x800AF5D8
    // 0x800AF640: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800AF5D8(rdram, ctx);
        goto after_1;
    // 0x800AF640: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800AF644: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF648: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800AF64C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800AF650: lh          $t7, 0x8($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X8);
    // 0x800AF654: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x800AF658: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AF65C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800AF660: addu        $t2, $v0, $t6
    ctx->r10 = ADD32(ctx->r2, ctx->r14);
    // 0x800AF664: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800AF668: lh          $t9, 0xA($t1)
    ctx->r25 = MEM_H(ctx->r9, 0XA);
    // 0x800AF66C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AF670: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800AF674: lh          $a3, 0x2($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X2);
    // 0x800AF678: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800AF67C: andi        $t7, $a3, 0x1
    ctx->r15 = ctx->r7 & 0X1;
    // 0x800AF680: beql        $t7, $zero, L_800AF758
    if (ctx->r15 == 0) {
        // 0x800AF684: andi        $t7, $a3, 0x4
        ctx->r15 = ctx->r7 & 0X4;
            goto L_800AF758;
    }
    goto skip_0;
    // 0x800AF684: andi        $t7, $a3, 0x4
    ctx->r15 = ctx->r7 & 0X4;
    skip_0:
    // 0x800AF688: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF68C: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x800AF690: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x800AF694: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AF698: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800AF69C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800AF6A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800AF6A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF6A8: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x800AF6AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800AF6B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800AF6B4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AF6B8: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x800AF6BC: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x800AF6C0: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x800AF6C4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800AF6C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF6CC: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x800AF6D0: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x800AF6D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800AF6D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800AF6DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AF6E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AF6E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF6E8: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x800AF6EC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800AF6F0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AF6F4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800AF6F8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AF6FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF700: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800AF704: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x800AF708: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AF70C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800AF710: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AF714: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800AF718: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF71C: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x800AF720: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x800AF724: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800AF728: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AF72C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800AF730: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AF734: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF738: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800AF73C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800AF740: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AF744: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AF748: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AF74C: b           L_800AF828
    // 0x800AF750: lh          $a3, 0x2($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X2);
        goto L_800AF828;
    // 0x800AF750: lh          $a3, 0x2($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X2);
    // 0x800AF754: andi        $t7, $a3, 0x4
    ctx->r15 = ctx->r7 & 0X4;
L_800AF758:
    // 0x800AF758: beq         $t7, $zero, L_800AF828
    if (ctx->r15 == 0) {
        // 0x800AF75C: lui         $t9, 0xE300
        ctx->r25 = S32(0XE300 << 16);
            goto L_800AF828;
    }
    // 0x800AF75C: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800AF760: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF764: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x800AF768: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x800AF76C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AF770: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800AF774: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800AF778: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800AF77C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF780: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x800AF784: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800AF788: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800AF78C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AF790: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x800AF794: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x800AF798: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x800AF79C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800AF7A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF7A4: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x800AF7A8: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x800AF7AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800AF7B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800AF7B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AF7B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AF7BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF7C0: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x800AF7C4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800AF7C8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AF7CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800AF7D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AF7D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF7D8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800AF7DC: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x800AF7E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AF7E4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800AF7E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AF7EC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800AF7F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF7F4: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x800AF7F8: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x800AF7FC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800AF800: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AF804: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800AF808: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AF80C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF810: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800AF814: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800AF818: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AF81C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AF820: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AF824: lh          $a3, 0x2($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X2);
L_800AF828:
    // 0x800AF828: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800AF82C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800AF830: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800AF834: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x800AF838: bne         $t8, $zero, L_800AF860
    if (ctx->r24 != 0) {
        // 0x800AF83C: addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
            goto L_800AF860;
    }
    // 0x800AF83C: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x800AF840: beq         $v0, $zero, L_800AF860
    if (ctx->r2 == 0) {
        // 0x800AF844: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800AF860;
    }
    // 0x800AF844: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800AF848:
    // 0x800AF848: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800AF84C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AF850: bne         $t9, $zero, L_800AF848
    if (ctx->r25 != 0) {
        // 0x800AF854: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_800AF848;
    }
    // 0x800AF854: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800AF858: b           L_800AF864
    // 0x800AF85C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
        goto L_800AF864;
    // 0x800AF85C: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
L_800AF860:
    // 0x800AF860: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
L_800AF864:
    // 0x800AF864: andi        $t9, $a3, 0x800
    ctx->r25 = ctx->r7 & 0X800;
    // 0x800AF868: andi        $t7, $a1, 0x7
    ctx->r15 = ctx->r5 & 0X7;
    // 0x800AF86C: bne         $t7, $zero, L_800AF894
    if (ctx->r15 != 0) {
        // 0x800AF870: addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
            goto L_800AF894;
    }
    // 0x800AF870: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x800AF874: beq         $v0, $zero, L_800AF894
    if (ctx->r2 == 0) {
        // 0x800AF878: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AF894;
    }
    // 0x800AF878: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800AF87C:
    // 0x800AF87C: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800AF880: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AF884: bne         $t8, $zero, L_800AF87C
    if (ctx->r24 != 0) {
        // 0x800AF888: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800AF87C;
    }
    // 0x800AF888: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800AF88C: b           L_800AF894
    // 0x800AF890: nop

        goto L_800AF894;
    // 0x800AF890: nop

L_800AF894:
    // 0x800AF894: beq         $t9, $zero, L_800AFAD8
    if (ctx->r25 == 0) {
        // 0x800AF898: andi        $t7, $a3, 0x400
        ctx->r15 = ctx->r7 & 0X400;
            goto L_800AFAD8;
    }
    // 0x800AF898: andi        $t7, $a3, 0x400
    ctx->r15 = ctx->r7 & 0X400;
    // 0x800AF89C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF8A0: lui         $t7, 0xFD18
    ctx->r15 = S32(0XFD18 << 16);
    // 0x800AF8A4: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x800AF8A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800AF8AC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AF8B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AF8B4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800AF8B8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800AF8BC: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x800AF8C0: andi        $ra, $a0, 0xF
    ctx->r31 = ctx->r4 & 0XF;
    // 0x800AF8C4: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x800AF8C8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800AF8CC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800AF8D0: sll         $t8, $ra, 4
    ctx->r24 = S32(ctx->r31 << 4);
    // 0x800AF8D4: or          $ra, $t8, $zero
    ctx->r31 = ctx->r24 | 0;
    // 0x800AF8D8: andi        $t9, $t1, 0x1FF
    ctx->r25 = ctx->r9 & 0X1FF;
    // 0x800AF8DC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800AF8E0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800AF8E4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800AF8E8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800AF8EC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800AF8F0: andi        $t7, $t3, 0x3
    ctx->r15 = ctx->r11 & 0X3;
    // 0x800AF8F4: sll         $t3, $t7, 18
    ctx->r11 = S32(ctx->r15 << 18);
    // 0x800AF8F8: sll         $t9, $t4, 14
    ctx->r25 = S32(ctx->r12 << 14);
    // 0x800AF8FC: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x800AF900: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800AF904: or          $t4, $t9, $zero
    ctx->r12 = ctx->r25 | 0;
    // 0x800AF908: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800AF90C: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x800AF910: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x800AF914: or          $t5, $t7, $zero
    ctx->r13 = ctx->r15 | 0;
    // 0x800AF918: or          $t7, $t6, $t7
    ctx->r15 = ctx->r14 | ctx->r15;
    // 0x800AF91C: or          $t8, $t7, $t8
    ctx->r24 = ctx->r15 | ctx->r24;
    // 0x800AF920: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800AF924: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AF928: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800AF92C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800AF930: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800AF934: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AF938: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AF93C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AF940: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800AF944: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x800AF948: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800AF94C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800AF950: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800AF954: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800AF958: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800AF95C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AF960: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800AF964: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AF968: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800AF96C: mflo        $v1
    ctx->r3 = lo;
    // 0x800AF970: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AF974: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x800AF978: beq         $at, $zero, L_800AF988
    if (ctx->r1 == 0) {
        // 0x800AF97C: nop
    
            goto L_800AF988;
    }
    // 0x800AF97C: nop

    // 0x800AF980: b           L_800AF988
    // 0x800AF984: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
        goto L_800AF988;
    // 0x800AF984: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800AF988:
    // 0x800AF988: bgez        $v0, L_800AF998
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AF98C: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800AF998;
    }
    // 0x800AF98C: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800AF990: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800AF994: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_800AF998:
    // 0x800AF998: bgtz        $t8, L_800AF9A8
    if (SIGNED(ctx->r24) > 0) {
        // 0x800AF99C: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800AF9A8;
    }
    // 0x800AF99C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800AF9A0: b           L_800AF9AC
    // 0x800AF9A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800AF9AC;
    // 0x800AF9A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800AF9A8:
    // 0x800AF9A8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800AF9AC:
    // 0x800AF9AC: bgtz        $v0, L_800AF9BC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800AF9B0: addiu       $t9, $a3, 0x7FF
        ctx->r25 = ADD32(ctx->r7, 0X7FF);
            goto L_800AF9BC;
    }
    // 0x800AF9B0: addiu       $t9, $a3, 0x7FF
    ctx->r25 = ADD32(ctx->r7, 0X7FF);
    // 0x800AF9B4: b           L_800AF9C0
    // 0x800AF9B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800AF9C0;
    // 0x800AF9B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800AF9BC:
    // 0x800AF9BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800AF9C0:
    // 0x800AF9C0: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x800AF9C4: bne         $a0, $zero, L_800AF9D0
    if (ctx->r4 != 0) {
        // 0x800AF9C8: nop
    
            goto L_800AF9D0;
    }
    // 0x800AF9C8: nop

    // 0x800AF9CC: break       7
    do_break(2148202956);
L_800AF9D0:
    // 0x800AF9D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AF9D4: bne         $a0, $at, L_800AF9E8
    if (ctx->r4 != ctx->r1) {
        // 0x800AF9D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AF9E8;
    }
    // 0x800AF9D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AF9DC: bne         $t9, $at, L_800AF9E8
    if (ctx->r25 != ctx->r1) {
        // 0x800AF9E0: nop
    
            goto L_800AF9E8;
    }
    // 0x800AF9E0: nop

    // 0x800AF9E4: break       6
    do_break(2148202980);
L_800AF9E8:
    // 0x800AF9E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800AF9EC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800AF9F0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800AF9F4: andi        $t9, $t0, 0xFFF
    ctx->r25 = ctx->r8 & 0XFFF;
    // 0x800AF9F8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800AF9FC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800AFA00: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800AFA04: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x800AFA08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFA0C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AFA10: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x800AFA14: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800AFA18: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AFA1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800AFA20: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AFA24: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AFA28: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFA2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800AFA30: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AFA34: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800AFA38: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800AFA3C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800AFA40: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800AFA44: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x800AFA48: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800AFA4C: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x800AFA50: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x800AFA54: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800AFA58: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800AFA5C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AFA60: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800AFA64: andi        $t9, $v1, 0x7
    ctx->r25 = ctx->r3 & 0X7;
    // 0x800AFA68: sll         $t8, $t9, 24
    ctx->r24 = S32(ctx->r25 << 24);
    // 0x800AFA6C: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x800AFA70: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x800AFA74: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800AFA78: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800AFA7C: or          $t8, $t9, $ra
    ctx->r24 = ctx->r25 | ctx->r31;
    // 0x800AFA80: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800AFA84: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFA88: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800AFA8C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800AFA90: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AFA94: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AFA98: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800AFA9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AFAA0: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800AFAA4: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800AFAA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AFAAC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800AFAB0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800AFAB4: or          $t8, $t9, $v1
    ctx->r24 = ctx->r25 | ctx->r3;
    // 0x800AFAB8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AFABC: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800AFAC0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800AFAC4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800AFAC8: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800AFACC: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800AFAD0: b           L_800B0CE8
    // 0x800AFAD4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_800B0CE8;
    // 0x800AFAD4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800AFAD8:
    // 0x800AFAD8: beq         $t7, $zero, L_800AFD1C
    if (ctx->r15 == 0) {
        // 0x800AFADC: andi        $t9, $a3, 0x200
        ctx->r25 = ctx->r7 & 0X200;
            goto L_800AFD1C;
    }
    // 0x800AFADC: andi        $t9, $a3, 0x200
    ctx->r25 = ctx->r7 & 0X200;
    // 0x800AFAE0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFAE4: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x800AFAE8: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800AFAEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AFAF0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800AFAF4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800AFAF8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800AFAFC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800AFB00: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x800AFB04: andi        $ra, $a0, 0xF
    ctx->r31 = ctx->r4 & 0XF;
    // 0x800AFB08: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800AFB0C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AFB10: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800AFB14: sll         $t6, $ra, 4
    ctx->r14 = S32(ctx->r31 << 4);
    // 0x800AFB18: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x800AFB1C: andi        $t7, $t1, 0x1FF
    ctx->r15 = ctx->r9 & 0X1FF;
    // 0x800AFB20: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800AFB24: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800AFB28: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800AFB2C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800AFB30: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x800AFB34: andi        $t9, $t3, 0x3
    ctx->r25 = ctx->r11 & 0X3;
    // 0x800AFB38: sll         $t3, $t9, 18
    ctx->r11 = S32(ctx->r25 << 18);
    // 0x800AFB3C: sll         $t7, $t4, 14
    ctx->r15 = S32(ctx->r12 << 14);
    // 0x800AFB40: andi        $t8, $t5, 0x3
    ctx->r24 = ctx->r13 & 0X3;
    // 0x800AFB44: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800AFB48: or          $t4, $t7, $zero
    ctx->r12 = ctx->r15 | 0;
    // 0x800AFB4C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800AFB50: or          $t7, $t3, $at
    ctx->r15 = ctx->r11 | ctx->r1;
    // 0x800AFB54: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x800AFB58: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800AFB5C: or          $t9, $t8, $t9
    ctx->r25 = ctx->r24 | ctx->r25;
    // 0x800AFB60: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x800AFB64: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800AFB68: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFB6C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800AFB70: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800AFB74: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800AFB78: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800AFB7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AFB80: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AFB84: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800AFB88: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x800AFB8C: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x800AFB90: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AFB94: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800AFB98: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800AFB9C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800AFBA0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800AFBA4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800AFBA8: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFBAC: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800AFBB0: mflo        $v1
    ctx->r3 = lo;
    // 0x800AFBB4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AFBB8: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x800AFBBC: beq         $at, $zero, L_800AFBCC
    if (ctx->r1 == 0) {
        // 0x800AFBC0: nop
    
            goto L_800AFBCC;
    }
    // 0x800AFBC0: nop

    // 0x800AFBC4: b           L_800AFBCC
    // 0x800AFBC8: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
        goto L_800AFBCC;
    // 0x800AFBC8: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800AFBCC:
    // 0x800AFBCC: bgez        $v0, L_800AFBDC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AFBD0: sra         $t6, $v0, 3
        ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800AFBDC;
    }
    // 0x800AFBD0: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800AFBD4: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800AFBD8: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_800AFBDC:
    // 0x800AFBDC: bgtz        $t6, L_800AFBEC
    if (SIGNED(ctx->r14) > 0) {
        // 0x800AFBE0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800AFBEC;
    }
    // 0x800AFBE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800AFBE4: b           L_800AFBF0
    // 0x800AFBE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800AFBF0;
    // 0x800AFBE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800AFBEC:
    // 0x800AFBEC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800AFBF0:
    // 0x800AFBF0: bgtz        $v0, L_800AFC00
    if (SIGNED(ctx->r2) > 0) {
        // 0x800AFBF4: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_800AFC00;
    }
    // 0x800AFBF4: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x800AFBF8: b           L_800AFC04
    // 0x800AFBFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800AFC04;
    // 0x800AFBFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800AFC00:
    // 0x800AFC00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800AFC04:
    // 0x800AFC04: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x800AFC08: bne         $a0, $zero, L_800AFC14
    if (ctx->r4 != 0) {
        // 0x800AFC0C: nop
    
            goto L_800AFC14;
    }
    // 0x800AFC0C: nop

    // 0x800AFC10: break       7
    do_break(2148203536);
L_800AFC14:
    // 0x800AFC14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AFC18: bne         $a0, $at, L_800AFC2C
    if (ctx->r4 != ctx->r1) {
        // 0x800AFC1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AFC2C;
    }
    // 0x800AFC1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AFC20: bne         $t7, $at, L_800AFC2C
    if (ctx->r15 != ctx->r1) {
        // 0x800AFC24: nop
    
            goto L_800AFC2C;
    }
    // 0x800AFC24: nop

    // 0x800AFC28: break       6
    do_break(2148203560);
L_800AFC2C:
    // 0x800AFC2C: mflo        $t8
    ctx->r24 = lo;
    // 0x800AFC30: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800AFC34: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800AFC38: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x800AFC3C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800AFC40: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800AFC44: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800AFC48: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800AFC4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFC50: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800AFC54: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800AFC58: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800AFC5C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800AFC60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800AFC64: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AFC68: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AFC6C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFC70: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AFC74: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800AFC78: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800AFC7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800AFC80: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800AFC84: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800AFC88: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x800AFC8C: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800AFC90: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x800AFC94: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x800AFC98: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800AFC9C: or          $t9, $t8, $t1
    ctx->r25 = ctx->r24 | ctx->r9;
    // 0x800AFCA0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800AFCA4: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800AFCA8: andi        $t7, $v1, 0x7
    ctx->r15 = ctx->r3 & 0X7;
    // 0x800AFCAC: sll         $t6, $t7, 24
    ctx->r14 = S32(ctx->r15 << 24);
    // 0x800AFCB0: or          $t8, $t6, $t3
    ctx->r24 = ctx->r14 | ctx->r11;
    // 0x800AFCB4: or          $t9, $t8, $t4
    ctx->r25 = ctx->r24 | ctx->r12;
    // 0x800AFCB8: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800AFCBC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800AFCC0: or          $t6, $t7, $ra
    ctx->r14 = ctx->r15 | ctx->r31;
    // 0x800AFCC4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800AFCC8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFCCC: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800AFCD0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AFCD4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800AFCD8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800AFCDC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800AFCE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AFCE4: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800AFCE8: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x800AFCEC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AFCF0: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800AFCF4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800AFCF8: or          $t6, $t7, $v1
    ctx->r14 = ctx->r15 | ctx->r3;
    // 0x800AFCFC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800AFD00: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x800AFD04: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AFD08: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800AFD0C: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x800AFD10: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800AFD14: b           L_800B0CE8
    // 0x800AFD18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_800B0CE8;
    // 0x800AFD18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_800AFD1C:
    // 0x800AFD1C: beq         $t9, $zero, L_800AFF60
    if (ctx->r25 == 0) {
        // 0x800AFD20: andi        $t7, $a3, 0x4
        ctx->r15 = ctx->r7 & 0X4;
            goto L_800AFF60;
    }
    // 0x800AFD20: andi        $t7, $a3, 0x4
    ctx->r15 = ctx->r7 & 0X4;
    // 0x800AFD24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFD28: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x800AFD2C: lui         $at, 0xF570
    ctx->r1 = S32(0XF570 << 16);
    // 0x800AFD30: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800AFD34: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AFD38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AFD3C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800AFD40: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800AFD44: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x800AFD48: andi        $ra, $a0, 0xF
    ctx->r31 = ctx->r4 & 0XF;
    // 0x800AFD4C: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x800AFD50: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800AFD54: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800AFD58: sll         $t8, $ra, 4
    ctx->r24 = S32(ctx->r31 << 4);
    // 0x800AFD5C: or          $ra, $t8, $zero
    ctx->r31 = ctx->r24 | 0;
    // 0x800AFD60: andi        $t9, $t1, 0x1FF
    ctx->r25 = ctx->r9 & 0X1FF;
    // 0x800AFD64: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800AFD68: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800AFD6C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800AFD70: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800AFD74: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800AFD78: andi        $t7, $t3, 0x3
    ctx->r15 = ctx->r11 & 0X3;
    // 0x800AFD7C: sll         $t3, $t7, 18
    ctx->r11 = S32(ctx->r15 << 18);
    // 0x800AFD80: sll         $t9, $t4, 14
    ctx->r25 = S32(ctx->r12 << 14);
    // 0x800AFD84: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x800AFD88: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800AFD8C: or          $t4, $t9, $zero
    ctx->r12 = ctx->r25 | 0;
    // 0x800AFD90: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800AFD94: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x800AFD98: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x800AFD9C: or          $t5, $t7, $zero
    ctx->r13 = ctx->r15 | 0;
    // 0x800AFDA0: or          $t7, $t6, $t7
    ctx->r15 = ctx->r14 | ctx->r15;
    // 0x800AFDA4: or          $t8, $t7, $t8
    ctx->r24 = ctx->r15 | ctx->r24;
    // 0x800AFDA8: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800AFDAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFDB0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800AFDB4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800AFDB8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800AFDBC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AFDC0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AFDC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AFDC8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800AFDCC: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x800AFDD0: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800AFDD4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800AFDD8: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800AFDDC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800AFDE0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800AFDE4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AFDE8: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800AFDEC: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFDF0: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800AFDF4: mflo        $v1
    ctx->r3 = lo;
    // 0x800AFDF8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AFDFC: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x800AFE00: beq         $at, $zero, L_800AFE10
    if (ctx->r1 == 0) {
        // 0x800AFE04: nop
    
            goto L_800AFE10;
    }
    // 0x800AFE04: nop

    // 0x800AFE08: b           L_800AFE10
    // 0x800AFE0C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
        goto L_800AFE10;
    // 0x800AFE0C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800AFE10:
    // 0x800AFE10: bgez        $v0, L_800AFE20
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AFE14: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800AFE20;
    }
    // 0x800AFE14: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800AFE18: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800AFE1C: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_800AFE20:
    // 0x800AFE20: bgtz        $t8, L_800AFE30
    if (SIGNED(ctx->r24) > 0) {
        // 0x800AFE24: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800AFE30;
    }
    // 0x800AFE24: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800AFE28: b           L_800AFE34
    // 0x800AFE2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800AFE34;
    // 0x800AFE2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800AFE30:
    // 0x800AFE30: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800AFE34:
    // 0x800AFE34: bgtz        $v0, L_800AFE44
    if (SIGNED(ctx->r2) > 0) {
        // 0x800AFE38: addiu       $t9, $a3, 0x7FF
        ctx->r25 = ADD32(ctx->r7, 0X7FF);
            goto L_800AFE44;
    }
    // 0x800AFE38: addiu       $t9, $a3, 0x7FF
    ctx->r25 = ADD32(ctx->r7, 0X7FF);
    // 0x800AFE3C: b           L_800AFE48
    // 0x800AFE40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800AFE48;
    // 0x800AFE40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800AFE44:
    // 0x800AFE44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800AFE48:
    // 0x800AFE48: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x800AFE4C: bne         $a0, $zero, L_800AFE58
    if (ctx->r4 != 0) {
        // 0x800AFE50: nop
    
            goto L_800AFE58;
    }
    // 0x800AFE50: nop

    // 0x800AFE54: break       7
    do_break(2148204116);
L_800AFE58:
    // 0x800AFE58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AFE5C: bne         $a0, $at, L_800AFE70
    if (ctx->r4 != ctx->r1) {
        // 0x800AFE60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AFE70;
    }
    // 0x800AFE60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AFE64: bne         $t9, $at, L_800AFE70
    if (ctx->r25 != ctx->r1) {
        // 0x800AFE68: nop
    
            goto L_800AFE70;
    }
    // 0x800AFE68: nop

    // 0x800AFE6C: break       6
    do_break(2148204140);
L_800AFE70:
    // 0x800AFE70: mflo        $t6
    ctx->r14 = lo;
    // 0x800AFE74: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800AFE78: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800AFE7C: andi        $t9, $t0, 0xFFF
    ctx->r25 = ctx->r8 & 0XFFF;
    // 0x800AFE80: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800AFE84: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800AFE88: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800AFE8C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x800AFE90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFE94: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AFE98: lui         $at, 0xF570
    ctx->r1 = S32(0XF570 << 16);
    // 0x800AFE9C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800AFEA0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AFEA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800AFEA8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AFEAC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AFEB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFEB4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800AFEB8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AFEBC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800AFEC0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800AFEC4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800AFEC8: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800AFECC: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x800AFED0: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800AFED4: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x800AFED8: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x800AFEDC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800AFEE0: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800AFEE4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AFEE8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800AFEEC: andi        $t9, $v1, 0x7
    ctx->r25 = ctx->r3 & 0X7;
    // 0x800AFEF0: sll         $t8, $t9, 24
    ctx->r24 = S32(ctx->r25 << 24);
    // 0x800AFEF4: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x800AFEF8: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x800AFEFC: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800AFF00: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800AFF04: or          $t8, $t9, $ra
    ctx->r24 = ctx->r25 | ctx->r31;
    // 0x800AFF08: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800AFF0C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFF10: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800AFF14: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800AFF18: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AFF1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AFF20: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800AFF24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AFF28: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800AFF2C: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800AFF30: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AFF34: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800AFF38: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800AFF3C: or          $t8, $t9, $v1
    ctx->r24 = ctx->r25 | ctx->r3;
    // 0x800AFF40: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AFF44: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800AFF48: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800AFF4C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800AFF50: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800AFF54: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800AFF58: b           L_800B0CE8
    // 0x800AFF5C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_800B0CE8;
    // 0x800AFF5C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800AFF60:
    // 0x800AFF60: beq         $t7, $zero, L_800B01A0
    if (ctx->r15 == 0) {
        // 0x800AFF64: andi        $t8, $a3, 0x100
        ctx->r24 = ctx->r7 & 0X100;
            goto L_800B01A0;
    }
    // 0x800AFF64: andi        $t8, $a3, 0x100
    ctx->r24 = ctx->r7 & 0X100;
    // 0x800AFF68: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFF6C: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x800AFF70: lui         $at, 0xF550
    ctx->r1 = S32(0XF550 << 16);
    // 0x800AFF74: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AFF78: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800AFF7C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800AFF80: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800AFF84: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800AFF88: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x800AFF8C: andi        $ra, $a0, 0xF
    ctx->r31 = ctx->r4 & 0XF;
    // 0x800AFF90: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800AFF94: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AFF98: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800AFF9C: sll         $t6, $ra, 4
    ctx->r14 = S32(ctx->r31 << 4);
    // 0x800AFFA0: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x800AFFA4: andi        $t7, $t1, 0x1FF
    ctx->r15 = ctx->r9 & 0X1FF;
    // 0x800AFFA8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800AFFAC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800AFFB0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800AFFB4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800AFFB8: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x800AFFBC: andi        $t9, $t3, 0x3
    ctx->r25 = ctx->r11 & 0X3;
    // 0x800AFFC0: sll         $t3, $t9, 18
    ctx->r11 = S32(ctx->r25 << 18);
    // 0x800AFFC4: sll         $t7, $t4, 14
    ctx->r15 = S32(ctx->r12 << 14);
    // 0x800AFFC8: andi        $t8, $t5, 0x3
    ctx->r24 = ctx->r13 & 0X3;
    // 0x800AFFCC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800AFFD0: or          $t4, $t7, $zero
    ctx->r12 = ctx->r15 | 0;
    // 0x800AFFD4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800AFFD8: or          $t7, $t3, $at
    ctx->r15 = ctx->r11 | ctx->r1;
    // 0x800AFFDC: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x800AFFE0: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800AFFE4: or          $t9, $t8, $t9
    ctx->r25 = ctx->r24 | ctx->r25;
    // 0x800AFFE8: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x800AFFEC: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800AFFF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AFFF4: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800AFFF8: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800AFFFC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B0000: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B0004: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B0008: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B000C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800B0010: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x800B0014: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x800B0018: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B001C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800B0020: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800B0024: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B0028: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B002C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800B0030: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B0034: mflo        $v1
    ctx->r3 = lo;
    // 0x800B0038: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B003C: sra         $t6, $v1, 1
    ctx->r14 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800B0040: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B0044: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x800B0048: beq         $at, $zero, L_800B0058
    if (ctx->r1 == 0) {
        // 0x800B004C: nop
    
            goto L_800B0058;
    }
    // 0x800B004C: nop

    // 0x800B0050: b           L_800B0058
    // 0x800B0054: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
        goto L_800B0058;
    // 0x800B0054: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800B0058:
    // 0x800B0058: bgez        $a1, L_800B0068
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800B005C: sra         $v0, $a1, 3
        ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
            goto L_800B0068;
    }
    // 0x800B005C: sra         $v0, $a1, 3
    ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800B0060: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x800B0064: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800B0068:
    // 0x800B0068: bgtz        $v0, L_800B0078
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B006C: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B0078;
    }
    // 0x800B006C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B0070: b           L_800B0078
    // 0x800B0074: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800B0078;
    // 0x800B0074: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800B0078:
    // 0x800B0078: bgtz        $v0, L_800B0088
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B007C: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_800B0088;
    }
    // 0x800B007C: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x800B0080: b           L_800B008C
    // 0x800B0084: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B008C;
    // 0x800B0084: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B0088:
    // 0x800B0088: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800B008C:
    // 0x800B008C: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x800B0090: bne         $a0, $zero, L_800B009C
    if (ctx->r4 != 0) {
        // 0x800B0094: nop
    
            goto L_800B009C;
    }
    // 0x800B0094: nop

    // 0x800B0098: break       7
    do_break(2148204696);
L_800B009C:
    // 0x800B009C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B00A0: bne         $a0, $at, L_800B00B4
    if (ctx->r4 != ctx->r1) {
        // 0x800B00A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B00B4;
    }
    // 0x800B00A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B00A8: bne         $t7, $at, L_800B00B4
    if (ctx->r15 != ctx->r1) {
        // 0x800B00AC: nop
    
            goto L_800B00B4;
    }
    // 0x800B00AC: nop

    // 0x800B00B0: break       6
    do_break(2148204720);
L_800B00B4:
    // 0x800B00B4: mflo        $t8
    ctx->r24 = lo;
    // 0x800B00B8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B00BC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B00C0: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x800B00C4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800B00C8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800B00CC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B00D0: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800B00D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B00D8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800B00DC: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x800B00E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B00E4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B00E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B00EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B00F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B00F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B00F8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B00FC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B0100: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B0104: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800B0108: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800B010C: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x800B0110: sra         $t8, $t6, 3
    ctx->r24 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B0114: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800B0118: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x800B011C: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800B0120: or          $t8, $t6, $t1
    ctx->r24 = ctx->r14 | ctx->r9;
    // 0x800B0124: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B0128: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B012C: andi        $t9, $v1, 0x7
    ctx->r25 = ctx->r3 & 0X7;
    // 0x800B0130: sll         $t7, $t9, 24
    ctx->r15 = S32(ctx->r25 << 24);
    // 0x800B0134: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x800B0138: or          $t8, $t6, $t4
    ctx->r24 = ctx->r14 | ctx->r12;
    // 0x800B013C: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x800B0140: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800B0144: or          $t7, $t9, $ra
    ctx->r15 = ctx->r25 | ctx->r31;
    // 0x800B0148: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B014C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0150: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B0154: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B0158: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B015C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B0160: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800B0164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B0168: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800B016C: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800B0170: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800B0174: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B0178: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B017C: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x800B0180: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800B0184: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B0188: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B018C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800B0190: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800B0194: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800B0198: b           L_800B0CE8
    // 0x800B019C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_800B0CE8;
    // 0x800B019C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800B01A0:
    // 0x800B01A0: beq         $t8, $zero, L_800B03E0
    if (ctx->r24 == 0) {
        // 0x800B01A4: andi        $t7, $a3, 0x40
        ctx->r15 = ctx->r7 & 0X40;
            goto L_800B03E0;
    }
    // 0x800B01A4: andi        $t7, $a3, 0x40
    ctx->r15 = ctx->r7 & 0X40;
    // 0x800B01A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B01AC: lui         $t9, 0xFD70
    ctx->r25 = S32(0XFD70 << 16);
    // 0x800B01B0: lui         $at, 0xF570
    ctx->r1 = S32(0XF570 << 16);
    // 0x800B01B4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B01B8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B01BC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B01C0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800B01C4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B01C8: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x800B01CC: andi        $ra, $a0, 0xF
    ctx->r31 = ctx->r4 & 0XF;
    // 0x800B01D0: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800B01D4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B01D8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B01DC: sll         $t6, $ra, 4
    ctx->r14 = S32(ctx->r31 << 4);
    // 0x800B01E0: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x800B01E4: andi        $t8, $t1, 0x1FF
    ctx->r24 = ctx->r9 & 0X1FF;
    // 0x800B01E8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800B01EC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B01F0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B01F4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B01F8: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800B01FC: andi        $t9, $t3, 0x3
    ctx->r25 = ctx->r11 & 0X3;
    // 0x800B0200: sll         $t3, $t9, 18
    ctx->r11 = S32(ctx->r25 << 18);
    // 0x800B0204: sll         $t8, $t4, 14
    ctx->r24 = S32(ctx->r12 << 14);
    // 0x800B0208: andi        $t7, $t5, 0x3
    ctx->r15 = ctx->r13 & 0X3;
    // 0x800B020C: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800B0210: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x800B0214: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B0218: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x800B021C: or          $t7, $t8, $t4
    ctx->r15 = ctx->r24 | ctx->r12;
    // 0x800B0220: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800B0224: or          $t9, $t7, $t9
    ctx->r25 = ctx->r15 | ctx->r25;
    // 0x800B0228: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x800B022C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800B0230: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0234: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800B0238: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800B023C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B0240: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B0244: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B0248: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B024C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800B0250: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x800B0254: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x800B0258: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B025C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800B0260: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B0264: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B0268: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800B026C: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800B0270: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B0274: mflo        $v1
    ctx->r3 = lo;
    // 0x800B0278: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B027C: sra         $t6, $v1, 1
    ctx->r14 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800B0280: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B0284: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x800B0288: beq         $at, $zero, L_800B0298
    if (ctx->r1 == 0) {
        // 0x800B028C: nop
    
            goto L_800B0298;
    }
    // 0x800B028C: nop

    // 0x800B0290: b           L_800B0298
    // 0x800B0294: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
        goto L_800B0298;
    // 0x800B0294: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800B0298:
    // 0x800B0298: bgez        $a1, L_800B02A8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800B029C: sra         $v0, $a1, 3
        ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
            goto L_800B02A8;
    }
    // 0x800B029C: sra         $v0, $a1, 3
    ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800B02A0: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x800B02A4: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800B02A8:
    // 0x800B02A8: bgtz        $v0, L_800B02B8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B02AC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B02B8;
    }
    // 0x800B02AC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B02B0: b           L_800B02B8
    // 0x800B02B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800B02B8;
    // 0x800B02B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800B02B8:
    // 0x800B02B8: bgtz        $v0, L_800B02C8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B02BC: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_800B02C8;
    }
    // 0x800B02BC: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x800B02C0: b           L_800B02CC
    // 0x800B02C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B02CC;
    // 0x800B02C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B02C8:
    // 0x800B02C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800B02CC:
    // 0x800B02CC: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x800B02D0: bne         $a0, $zero, L_800B02DC
    if (ctx->r4 != 0) {
        // 0x800B02D4: nop
    
            goto L_800B02DC;
    }
    // 0x800B02D4: nop

    // 0x800B02D8: break       7
    do_break(2148205272);
L_800B02DC:
    // 0x800B02DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B02E0: bne         $a0, $at, L_800B02F4
    if (ctx->r4 != ctx->r1) {
        // 0x800B02E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B02F4;
    }
    // 0x800B02E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B02E8: bne         $t8, $at, L_800B02F4
    if (ctx->r24 != ctx->r1) {
        // 0x800B02EC: nop
    
            goto L_800B02F4;
    }
    // 0x800B02EC: nop

    // 0x800B02F0: break       6
    do_break(2148205296);
L_800B02F4:
    // 0x800B02F4: mflo        $t7
    ctx->r15 = lo;
    // 0x800B02F8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800B02FC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B0300: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x800B0304: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800B0308: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800B030C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800B0310: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800B0314: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0318: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800B031C: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x800B0320: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B0324: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B0328: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B032C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B0330: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B0334: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0338: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B033C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B0340: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B0344: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800B0348: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800B034C: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x800B0350: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B0354: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x800B0358: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x800B035C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800B0360: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800B0364: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B0368: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B036C: andi        $t9, $v1, 0x7
    ctx->r25 = ctx->r3 & 0X7;
    // 0x800B0370: sll         $t8, $t9, 24
    ctx->r24 = S32(ctx->r25 << 24);
    // 0x800B0374: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x800B0378: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x800B037C: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800B0380: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800B0384: or          $t8, $t9, $ra
    ctx->r24 = ctx->r25 | ctx->r31;
    // 0x800B0388: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B038C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0390: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800B0394: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B0398: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B039C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B03A0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800B03A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B03A8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800B03AC: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800B03B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B03B4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B03B8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800B03BC: or          $t8, $t9, $v1
    ctx->r24 = ctx->r25 | ctx->r3;
    // 0x800B03C0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B03C4: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800B03C8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B03CC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B03D0: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800B03D4: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800B03D8: b           L_800B0CE8
    // 0x800B03DC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_800B0CE8;
    // 0x800B03DC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800B03E0:
    // 0x800B03E0: beq         $t7, $zero, L_800B0620
    if (ctx->r15 == 0) {
        // 0x800B03E4: andi        $t8, $a3, 0x1
        ctx->r24 = ctx->r7 & 0X1;
            goto L_800B0620;
    }
    // 0x800B03E4: andi        $t8, $a3, 0x1
    ctx->r24 = ctx->r7 & 0X1;
    // 0x800B03E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B03EC: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x800B03F0: lui         $at, 0xF590
    ctx->r1 = S32(0XF590 << 16);
    // 0x800B03F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B03F8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B03FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B0400: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800B0404: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B0408: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x800B040C: andi        $ra, $a0, 0xF
    ctx->r31 = ctx->r4 & 0XF;
    // 0x800B0410: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800B0414: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B0418: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B041C: sll         $t6, $ra, 4
    ctx->r14 = S32(ctx->r31 << 4);
    // 0x800B0420: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x800B0424: andi        $t7, $t1, 0x1FF
    ctx->r15 = ctx->r9 & 0X1FF;
    // 0x800B0428: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B042C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800B0430: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B0434: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0438: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x800B043C: andi        $t9, $t3, 0x3
    ctx->r25 = ctx->r11 & 0X3;
    // 0x800B0440: sll         $t3, $t9, 18
    ctx->r11 = S32(ctx->r25 << 18);
    // 0x800B0444: sll         $t7, $t4, 14
    ctx->r15 = S32(ctx->r12 << 14);
    // 0x800B0448: andi        $t8, $t5, 0x3
    ctx->r24 = ctx->r13 & 0X3;
    // 0x800B044C: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800B0450: or          $t4, $t7, $zero
    ctx->r12 = ctx->r15 | 0;
    // 0x800B0454: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B0458: or          $t7, $t3, $at
    ctx->r15 = ctx->r11 | ctx->r1;
    // 0x800B045C: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x800B0460: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800B0464: or          $t9, $t8, $t9
    ctx->r25 = ctx->r24 | ctx->r25;
    // 0x800B0468: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x800B046C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800B0470: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0474: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800B0478: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800B047C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B0480: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B0484: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B0488: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B048C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800B0490: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x800B0494: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x800B0498: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B049C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800B04A0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800B04A4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B04A8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B04AC: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800B04B0: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B04B4: mflo        $v1
    ctx->r3 = lo;
    // 0x800B04B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B04BC: sra         $t6, $v1, 1
    ctx->r14 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800B04C0: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B04C4: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x800B04C8: beq         $at, $zero, L_800B04D8
    if (ctx->r1 == 0) {
        // 0x800B04CC: nop
    
            goto L_800B04D8;
    }
    // 0x800B04CC: nop

    // 0x800B04D0: b           L_800B04D8
    // 0x800B04D4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
        goto L_800B04D8;
    // 0x800B04D4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800B04D8:
    // 0x800B04D8: bgez        $a1, L_800B04E8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800B04DC: sra         $v0, $a1, 3
        ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
            goto L_800B04E8;
    }
    // 0x800B04DC: sra         $v0, $a1, 3
    ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800B04E0: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x800B04E4: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800B04E8:
    // 0x800B04E8: bgtz        $v0, L_800B04F8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B04EC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B04F8;
    }
    // 0x800B04EC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B04F0: b           L_800B04F8
    // 0x800B04F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800B04F8;
    // 0x800B04F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800B04F8:
    // 0x800B04F8: bgtz        $v0, L_800B0508
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B04FC: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_800B0508;
    }
    // 0x800B04FC: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x800B0500: b           L_800B050C
    // 0x800B0504: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B050C;
    // 0x800B0504: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B0508:
    // 0x800B0508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800B050C:
    // 0x800B050C: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x800B0510: bne         $a0, $zero, L_800B051C
    if (ctx->r4 != 0) {
        // 0x800B0514: nop
    
            goto L_800B051C;
    }
    // 0x800B0514: nop

    // 0x800B0518: break       7
    do_break(2148205848);
L_800B051C:
    // 0x800B051C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B0520: bne         $a0, $at, L_800B0534
    if (ctx->r4 != ctx->r1) {
        // 0x800B0524: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B0534;
    }
    // 0x800B0524: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0528: bne         $t7, $at, L_800B0534
    if (ctx->r15 != ctx->r1) {
        // 0x800B052C: nop
    
            goto L_800B0534;
    }
    // 0x800B052C: nop

    // 0x800B0530: break       6
    do_break(2148205872);
L_800B0534:
    // 0x800B0534: mflo        $t8
    ctx->r24 = lo;
    // 0x800B0538: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B053C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B0540: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x800B0544: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800B0548: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800B054C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B0550: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800B0554: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0558: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800B055C: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x800B0560: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B0564: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B0568: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B056C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B0570: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B0574: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0578: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B057C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B0580: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B0584: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800B0588: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800B058C: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x800B0590: sra         $t8, $t6, 3
    ctx->r24 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B0594: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800B0598: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x800B059C: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800B05A0: or          $t8, $t6, $t1
    ctx->r24 = ctx->r14 | ctx->r9;
    // 0x800B05A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B05A8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B05AC: andi        $t9, $v1, 0x7
    ctx->r25 = ctx->r3 & 0X7;
    // 0x800B05B0: sll         $t7, $t9, 24
    ctx->r15 = S32(ctx->r25 << 24);
    // 0x800B05B4: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x800B05B8: or          $t8, $t6, $t4
    ctx->r24 = ctx->r14 | ctx->r12;
    // 0x800B05BC: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x800B05C0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800B05C4: or          $t7, $t9, $ra
    ctx->r15 = ctx->r25 | ctx->r31;
    // 0x800B05C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B05CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B05D0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B05D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B05D8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B05DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B05E0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800B05E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B05E8: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800B05EC: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800B05F0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800B05F4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B05F8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B05FC: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x800B0600: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800B0604: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B0608: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B060C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800B0610: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800B0614: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800B0618: b           L_800B0CE8
    // 0x800B061C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_800B0CE8;
    // 0x800B061C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800B0620:
    // 0x800B0620: beq         $t8, $zero, L_800B0864
    if (ctx->r24 == 0) {
        // 0x800B0624: andi        $t9, $a3, 0x80
        ctx->r25 = ctx->r7 & 0X80;
            goto L_800B0864;
    }
    // 0x800B0624: andi        $t9, $a3, 0x80
    ctx->r25 = ctx->r7 & 0X80;
    // 0x800B0628: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B062C: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x800B0630: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800B0634: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B0638: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B063C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B0640: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800B0644: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B0648: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x800B064C: andi        $ra, $a0, 0xF
    ctx->r31 = ctx->r4 & 0XF;
    // 0x800B0650: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800B0654: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B0658: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B065C: sll         $t6, $ra, 4
    ctx->r14 = S32(ctx->r31 << 4);
    // 0x800B0660: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x800B0664: andi        $t8, $t1, 0x1FF
    ctx->r24 = ctx->r9 & 0X1FF;
    // 0x800B0668: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800B066C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B0670: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B0674: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0678: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800B067C: andi        $t9, $t3, 0x3
    ctx->r25 = ctx->r11 & 0X3;
    // 0x800B0680: sll         $t3, $t9, 18
    ctx->r11 = S32(ctx->r25 << 18);
    // 0x800B0684: sll         $t8, $t4, 14
    ctx->r24 = S32(ctx->r12 << 14);
    // 0x800B0688: andi        $t7, $t5, 0x3
    ctx->r15 = ctx->r13 & 0X3;
    // 0x800B068C: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800B0690: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x800B0694: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B0698: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x800B069C: or          $t7, $t8, $t4
    ctx->r15 = ctx->r24 | ctx->r12;
    // 0x800B06A0: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800B06A4: or          $t9, $t7, $t9
    ctx->r25 = ctx->r15 | ctx->r25;
    // 0x800B06A8: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x800B06AC: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800B06B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B06B4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800B06B8: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800B06BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B06C0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B06C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B06C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B06CC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800B06D0: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x800B06D4: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x800B06D8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B06DC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800B06E0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B06E4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B06E8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800B06EC: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800B06F0: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B06F4: mflo        $v1
    ctx->r3 = lo;
    // 0x800B06F8: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x800B06FC: sra         $t6, $v1, 2
    ctx->r14 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800B0700: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B0704: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x800B0708: beq         $at, $zero, L_800B0718
    if (ctx->r1 == 0) {
        // 0x800B070C: nop
    
            goto L_800B0718;
    }
    // 0x800B070C: nop

    // 0x800B0710: b           L_800B0718
    // 0x800B0714: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
        goto L_800B0718;
    // 0x800B0714: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800B0718:
    // 0x800B0718: bgez        $a1, L_800B0728
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800B071C: sra         $v0, $a1, 4
        ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
            goto L_800B0728;
    }
    // 0x800B071C: sra         $v0, $a1, 4
    ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
    // 0x800B0720: addiu       $at, $a1, 0xF
    ctx->r1 = ADD32(ctx->r5, 0XF);
    // 0x800B0724: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_800B0728:
    // 0x800B0728: bgtz        $v0, L_800B0738
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B072C: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B0738;
    }
    // 0x800B072C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B0730: b           L_800B0738
    // 0x800B0734: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800B0738;
    // 0x800B0734: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800B0738:
    // 0x800B0738: bgtz        $v0, L_800B0748
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B073C: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_800B0748;
    }
    // 0x800B073C: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x800B0740: b           L_800B074C
    // 0x800B0744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B074C;
    // 0x800B0744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B0748:
    // 0x800B0748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800B074C:
    // 0x800B074C: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x800B0750: bne         $a0, $zero, L_800B075C
    if (ctx->r4 != 0) {
        // 0x800B0754: nop
    
            goto L_800B075C;
    }
    // 0x800B0754: nop

    // 0x800B0758: break       7
    do_break(2148206424);
L_800B075C:
    // 0x800B075C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B0760: bne         $a0, $at, L_800B0774
    if (ctx->r4 != ctx->r1) {
        // 0x800B0764: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B0774;
    }
    // 0x800B0764: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0768: bne         $t8, $at, L_800B0774
    if (ctx->r24 != ctx->r1) {
        // 0x800B076C: nop
    
            goto L_800B0774;
    }
    // 0x800B076C: nop

    // 0x800B0770: break       6
    do_break(2148206448);
L_800B0774:
    // 0x800B0774: mflo        $t7
    ctx->r15 = lo;
    // 0x800B0778: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800B077C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B0780: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x800B0784: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800B0788: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800B078C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800B0790: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800B0794: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0798: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800B079C: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800B07A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B07A4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B07A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B07AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B07B0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B07B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B07B8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B07BC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B07C0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B07C4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800B07C8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800B07CC: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800B07D0: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800B07D4: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800B07D8: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x800B07DC: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x800B07E0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800B07E4: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x800B07E8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B07EC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B07F0: andi        $t8, $v1, 0x7
    ctx->r24 = ctx->r3 & 0X7;
    // 0x800B07F4: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x800B07F8: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800B07FC: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x800B0800: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x800B0804: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800B0808: or          $t6, $t8, $ra
    ctx->r14 = ctx->r24 | ctx->r31;
    // 0x800B080C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B0810: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0814: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800B0818: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B081C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B0820: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B0824: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800B0828: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B082C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800B0830: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B0834: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B0838: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B083C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800B0840: or          $t6, $t8, $v1
    ctx->r14 = ctx->r24 | ctx->r3;
    // 0x800B0844: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800B0848: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800B084C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800B0850: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800B0854: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800B0858: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800B085C: b           L_800B0CE8
    // 0x800B0860: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_800B0CE8;
    // 0x800B0860: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_800B0864:
    // 0x800B0864: beq         $t9, $zero, L_800B0AA8
    if (ctx->r25 == 0) {
        // 0x800B0868: andi        $t8, $a3, 0x20
        ctx->r24 = ctx->r7 & 0X20;
            goto L_800B0AA8;
    }
    // 0x800B0868: andi        $t8, $a3, 0x20
    ctx->r24 = ctx->r7 & 0X20;
    // 0x800B086C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0870: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x800B0874: lui         $at, 0xF570
    ctx->r1 = S32(0XF570 << 16);
    // 0x800B0878: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B087C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B0880: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B0884: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800B0888: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B088C: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x800B0890: andi        $ra, $a0, 0xF
    ctx->r31 = ctx->r4 & 0XF;
    // 0x800B0894: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x800B0898: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B089C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B08A0: sll         $t7, $ra, 4
    ctx->r15 = S32(ctx->r31 << 4);
    // 0x800B08A4: or          $ra, $t7, $zero
    ctx->r31 = ctx->r15 | 0;
    // 0x800B08A8: andi        $t9, $t1, 0x1FF
    ctx->r25 = ctx->r9 & 0X1FF;
    // 0x800B08AC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800B08B0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800B08B4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B08B8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B08BC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800B08C0: andi        $t8, $t3, 0x3
    ctx->r24 = ctx->r11 & 0X3;
    // 0x800B08C4: sll         $t3, $t8, 18
    ctx->r11 = S32(ctx->r24 << 18);
    // 0x800B08C8: sll         $t9, $t4, 14
    ctx->r25 = S32(ctx->r12 << 14);
    // 0x800B08CC: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x800B08D0: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800B08D4: or          $t4, $t9, $zero
    ctx->r12 = ctx->r25 | 0;
    // 0x800B08D8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B08DC: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x800B08E0: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x800B08E4: or          $t5, $t8, $zero
    ctx->r13 = ctx->r24 | 0;
    // 0x800B08E8: or          $t8, $t6, $t8
    ctx->r24 = ctx->r14 | ctx->r24;
    // 0x800B08EC: or          $t7, $t8, $t7
    ctx->r15 = ctx->r24 | ctx->r15;
    // 0x800B08F0: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800B08F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B08F8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800B08FC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800B0900: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B0904: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B0908: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B090C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B0910: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800B0914: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x800B0918: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x800B091C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B0920: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800B0924: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B0928: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B092C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800B0930: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800B0934: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B0938: mflo        $v1
    ctx->r3 = lo;
    // 0x800B093C: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x800B0940: sra         $t7, $v1, 2
    ctx->r15 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800B0944: addiu       $v1, $t7, -0x1
    ctx->r3 = ADD32(ctx->r15, -0X1);
    // 0x800B0948: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x800B094C: beq         $at, $zero, L_800B095C
    if (ctx->r1 == 0) {
        // 0x800B0950: nop
    
            goto L_800B095C;
    }
    // 0x800B0950: nop

    // 0x800B0954: b           L_800B095C
    // 0x800B0958: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
        goto L_800B095C;
    // 0x800B0958: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800B095C:
    // 0x800B095C: bgez        $a1, L_800B096C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800B0960: sra         $v0, $a1, 4
        ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
            goto L_800B096C;
    }
    // 0x800B0960: sra         $v0, $a1, 4
    ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
    // 0x800B0964: addiu       $at, $a1, 0xF
    ctx->r1 = ADD32(ctx->r5, 0XF);
    // 0x800B0968: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_800B096C:
    // 0x800B096C: bgtz        $v0, L_800B097C
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B0970: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B097C;
    }
    // 0x800B0970: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B0974: b           L_800B097C
    // 0x800B0978: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800B097C;
    // 0x800B0978: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800B097C:
    // 0x800B097C: bgtz        $v0, L_800B098C
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B0980: addiu       $t9, $a3, 0x7FF
        ctx->r25 = ADD32(ctx->r7, 0X7FF);
            goto L_800B098C;
    }
    // 0x800B0980: addiu       $t9, $a3, 0x7FF
    ctx->r25 = ADD32(ctx->r7, 0X7FF);
    // 0x800B0984: b           L_800B0990
    // 0x800B0988: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B0990;
    // 0x800B0988: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B098C:
    // 0x800B098C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800B0990:
    // 0x800B0990: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x800B0994: bne         $a0, $zero, L_800B09A0
    if (ctx->r4 != 0) {
        // 0x800B0998: nop
    
            goto L_800B09A0;
    }
    // 0x800B0998: nop

    // 0x800B099C: break       7
    do_break(2148207004);
L_800B09A0:
    // 0x800B09A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B09A4: bne         $a0, $at, L_800B09B8
    if (ctx->r4 != ctx->r1) {
        // 0x800B09A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B09B8;
    }
    // 0x800B09A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B09AC: bne         $t9, $at, L_800B09B8
    if (ctx->r25 != ctx->r1) {
        // 0x800B09B0: nop
    
            goto L_800B09B8;
    }
    // 0x800B09B0: nop

    // 0x800B09B4: break       6
    do_break(2148207028);
L_800B09B8:
    // 0x800B09B8: mflo        $t6
    ctx->r14 = lo;
    // 0x800B09BC: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800B09C0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B09C4: andi        $t9, $t0, 0xFFF
    ctx->r25 = ctx->r8 & 0XFFF;
    // 0x800B09C8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800B09CC: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800B09D0: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800B09D4: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x800B09D8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B09DC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B09E0: lui         $at, 0xF560
    ctx->r1 = S32(0XF560 << 16);
    // 0x800B09E4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B09E8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B09EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B09F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B09F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B09F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B09FC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B0A00: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B0A04: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B0A08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800B0A0C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B0A10: sra         $t7, $t9, 1
    ctx->r15 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800B0A14: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x800B0A18: sra         $t8, $t6, 3
    ctx->r24 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B0A1C: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800B0A20: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x800B0A24: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800B0A28: or          $t8, $t6, $t1
    ctx->r24 = ctx->r14 | ctx->r9;
    // 0x800B0A2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B0A30: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B0A34: andi        $t9, $v1, 0x7
    ctx->r25 = ctx->r3 & 0X7;
    // 0x800B0A38: sll         $t7, $t9, 24
    ctx->r15 = S32(ctx->r25 << 24);
    // 0x800B0A3C: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x800B0A40: or          $t8, $t6, $t4
    ctx->r24 = ctx->r14 | ctx->r12;
    // 0x800B0A44: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x800B0A48: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800B0A4C: or          $t7, $t9, $ra
    ctx->r15 = ctx->r25 | ctx->r31;
    // 0x800B0A50: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B0A54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0A58: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B0A5C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B0A60: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B0A64: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B0A68: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800B0A6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B0A70: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800B0A74: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800B0A78: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800B0A7C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B0A80: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B0A84: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x800B0A88: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800B0A8C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B0A90: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800B0A94: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800B0A98: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800B0A9C: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800B0AA0: b           L_800B0CE8
    // 0x800B0AA4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_800B0CE8;
    // 0x800B0AA4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800B0AA8:
    // 0x800B0AA8: beql        $t8, $zero, L_800B0CEC
    if (ctx->r24 == 0) {
        // 0x800B0AAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B0CEC;
    }
    goto skip_1;
    // 0x800B0AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800B0AB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0AB4: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x800B0AB8: lui         $at, 0xF590
    ctx->r1 = S32(0XF590 << 16);
    // 0x800B0ABC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B0AC0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B0AC4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B0AC8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800B0ACC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B0AD0: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x800B0AD4: andi        $ra, $a0, 0xF
    ctx->r31 = ctx->r4 & 0XF;
    // 0x800B0AD8: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800B0ADC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B0AE0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B0AE4: sll         $t6, $ra, 4
    ctx->r14 = S32(ctx->r31 << 4);
    // 0x800B0AE8: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x800B0AEC: andi        $t8, $t1, 0x1FF
    ctx->r24 = ctx->r9 & 0X1FF;
    // 0x800B0AF0: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800B0AF4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B0AF8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B0AFC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0B00: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800B0B04: andi        $t9, $t3, 0x3
    ctx->r25 = ctx->r11 & 0X3;
    // 0x800B0B08: sll         $t3, $t9, 18
    ctx->r11 = S32(ctx->r25 << 18);
    // 0x800B0B0C: sll         $t8, $t4, 14
    ctx->r24 = S32(ctx->r12 << 14);
    // 0x800B0B10: andi        $t7, $t5, 0x3
    ctx->r15 = ctx->r13 & 0X3;
    // 0x800B0B14: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800B0B18: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x800B0B1C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B0B20: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x800B0B24: or          $t7, $t8, $t4
    ctx->r15 = ctx->r24 | ctx->r12;
    // 0x800B0B28: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800B0B2C: or          $t9, $t7, $t9
    ctx->r25 = ctx->r15 | ctx->r25;
    // 0x800B0B30: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x800B0B34: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800B0B38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0B3C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800B0B40: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800B0B44: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B0B48: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B0B4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B0B50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B0B54: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800B0B58: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x800B0B5C: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x800B0B60: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B0B64: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800B0B68: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800B0B6C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B0B70: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800B0B74: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800B0B78: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B0B7C: mflo        $v1
    ctx->r3 = lo;
    // 0x800B0B80: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x800B0B84: sra         $t6, $v1, 2
    ctx->r14 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800B0B88: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B0B8C: slti        $at, $v1, 0x7FF
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF ? 1 : 0;
    // 0x800B0B90: beq         $at, $zero, L_800B0BA0
    if (ctx->r1 == 0) {
        // 0x800B0B94: nop
    
            goto L_800B0BA0;
    }
    // 0x800B0B94: nop

    // 0x800B0B98: b           L_800B0BA0
    // 0x800B0B9C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
        goto L_800B0BA0;
    // 0x800B0B9C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800B0BA0:
    // 0x800B0BA0: bgez        $a1, L_800B0BB0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800B0BA4: sra         $v0, $a1, 4
        ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
            goto L_800B0BB0;
    }
    // 0x800B0BA4: sra         $v0, $a1, 4
    ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
    // 0x800B0BA8: addiu       $at, $a1, 0xF
    ctx->r1 = ADD32(ctx->r5, 0XF);
    // 0x800B0BAC: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_800B0BB0:
    // 0x800B0BB0: bgtz        $v0, L_800B0BC0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B0BB4: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B0BC0;
    }
    // 0x800B0BB4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B0BB8: b           L_800B0BC0
    // 0x800B0BBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800B0BC0;
    // 0x800B0BBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800B0BC0:
    // 0x800B0BC0: bgtz        $v0, L_800B0BD0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B0BC4: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_800B0BD0;
    }
    // 0x800B0BC4: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x800B0BC8: b           L_800B0BD4
    // 0x800B0BCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B0BD4;
    // 0x800B0BCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B0BD0:
    // 0x800B0BD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800B0BD4:
    // 0x800B0BD4: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x800B0BD8: bne         $a0, $zero, L_800B0BE4
    if (ctx->r4 != 0) {
        // 0x800B0BDC: nop
    
            goto L_800B0BE4;
    }
    // 0x800B0BDC: nop

    // 0x800B0BE0: break       7
    do_break(2148207584);
L_800B0BE4:
    // 0x800B0BE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B0BE8: bne         $a0, $at, L_800B0BFC
    if (ctx->r4 != ctx->r1) {
        // 0x800B0BEC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B0BFC;
    }
    // 0x800B0BEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0BF0: bne         $t8, $at, L_800B0BFC
    if (ctx->r24 != ctx->r1) {
        // 0x800B0BF4: nop
    
            goto L_800B0BFC;
    }
    // 0x800B0BF4: nop

    // 0x800B0BF8: break       6
    do_break(2148207608);
L_800B0BFC:
    // 0x800B0BFC: mflo        $t7
    ctx->r15 = lo;
    // 0x800B0C00: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800B0C04: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B0C08: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x800B0C0C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800B0C10: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800B0C14: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800B0C18: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800B0C1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0C20: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800B0C24: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x800B0C28: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B0C2C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B0C30: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B0C34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B0C38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B0C3C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0C40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B0C44: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B0C48: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800B0C4C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800B0C50: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800B0C54: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800B0C58: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800B0C5C: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800B0C60: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x800B0C64: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x800B0C68: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800B0C6C: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x800B0C70: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B0C74: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B0C78: andi        $t8, $v1, 0x7
    ctx->r24 = ctx->r3 & 0X7;
    // 0x800B0C7C: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x800B0C80: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800B0C84: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x800B0C88: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x800B0C8C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800B0C90: or          $t6, $t8, $ra
    ctx->r14 = ctx->r24 | ctx->r31;
    // 0x800B0C94: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B0C98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B0C9C: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800B0CA0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B0CA4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B0CA8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B0CAC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800B0CB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B0CB4: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800B0CB8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B0CBC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B0CC0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B0CC4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800B0CC8: or          $t6, $t8, $v1
    ctx->r14 = ctx->r24 | ctx->r3;
    // 0x800B0CCC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800B0CD0: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800B0CD4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800B0CD8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800B0CDC: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800B0CE0: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800B0CE4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_800B0CE8:
    // 0x800B0CE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B0CEC:
    // 0x800B0CEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0CF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B0CF4: jr          $ra
    // 0x800B0CF8: nop

    return;
    // 0x800B0CF8: nop

;}
RECOMP_FUNC void func_800A18E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A18E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A18EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A18F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A18F4: jal         0x800852F0
    // 0x800A18F8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x800A18F8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_0:
    // 0x800A18FC: beql        $v0, $zero, L_800A1950
    if (ctx->r2 == 0) {
        // 0x800A1900: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1950;
    }
    goto skip_0;
    // 0x800A1900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A1904: jal         0x800A3274
    // 0x800A1908: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x800A1908: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800A190C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800A1910: jal         0x800D4E7C
    // 0x800A1914: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D4E7C(rdram, ctx);
        goto after_2;
    // 0x800A1914: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800A1918: beq         $v0, $zero, L_800A194C
    if (ctx->r2 == 0) {
        // 0x800A191C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800A194C;
    }
    // 0x800A191C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1920: jal         0x800D4EB8
    // 0x800A1924: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800D4EB8(rdram, ctx);
        goto after_3;
    // 0x800A1924: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_3:
    // 0x800A1928: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800A192C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800A1930: beql        $at, $zero, L_800A1950
    if (ctx->r1 == 0) {
        // 0x800A1934: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1950;
    }
    goto skip_1;
    // 0x800A1934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800A1938: jal         0x800FC660
    // 0x800A193C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x800A193C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
    // 0x800A1940: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A1944: jal         0x800A17A8
    // 0x800A1948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A17A8(rdram, ctx);
        goto after_5;
    // 0x800A1948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_800A194C:
    // 0x800A194C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1950:
    // 0x800A1950: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A1954: jr          $ra
    // 0x800A1958: nop

    return;
    // 0x800A1958: nop

    // 0x800A195C: nop

;}
RECOMP_FUNC void _chspotlight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085EC0: syscall     256
    recomp_syscall_handler(rdram, ctx, 0x80085EC0);
    return;
    // 0x80085EC4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BAB54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAB54: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BAB58: jr          $ra
    // 0x800BAB5C: swc1        $f12, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800BAB5C: swc1        $f12, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void _gcwater_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E80: syscall     659
    recomp_syscall_handler(rdram, ctx, 0x80087E80);
    return;
    // 0x80087E84: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80808B24_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808B24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808B2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80808B30: jal         0x80802D50
    // 0x80808B34: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80802D50_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808B34: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80808B38: beq         $v0, $zero, L_80808B48
    if (ctx->r2 == 0) {
        // 0x80808B3C: nop
    
            goto L_80808B48;
    }
    // 0x80808B3C: nop

    // 0x80808B40: b           L_80808B7C
    // 0x80808B44: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80808B7C;
    // 0x80808B44: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80808B48:
    // 0x80808B48: jal         0x80808630
    // 0x80808B4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80808630_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80808B4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80808B50: beq         $v0, $zero, L_80808B60
    if (ctx->r2 == 0) {
        // 0x80808B54: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80808B60;
    }
    // 0x80808B54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80808B58: b           L_80808B7C
    // 0x80808B5C: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
        goto L_80808B7C;
    // 0x80808B5C: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
L_80808B60:
    // 0x80808B60: jal         0x80809540
    // 0x80808B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80809540_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80808B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80808B68: beql        $v0, $zero, L_80808B7C
    if (ctx->r2 == 0) {
        // 0x80808B6C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80808B7C;
    }
    goto skip_0;
    // 0x80808B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80808B70: b           L_80808B7C
    // 0x80808B74: addiu       $v0, $zero, 0xD1
    ctx->r2 = ADD32(0, 0XD1);
        goto L_80808B7C;
    // 0x80808B74: addiu       $v0, $zero, 0xD1
    ctx->r2 = ADD32(0, 0XD1);
    // 0x80808B78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80808B7C:
    // 0x80808B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808B80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80808B84: jr          $ra
    // 0x80808B88: nop

    return;
    // 0x80808B88: nop

;}
RECOMP_FUNC void anctrl_setPlaybackType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B134: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008B138: beq         $a1, $at, L_8008B164
    if (ctx->r5 == ctx->r1) {
        // 0x8008B13C: sb          $a1, 0x1A($a0)
        MEM_B(0X1A, ctx->r4) = ctx->r5;
            goto L_8008B164;
    }
    // 0x8008B13C: sb          $a1, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r5;
    // 0x8008B140: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008B144: beq         $a1, $at, L_8008B174
    if (ctx->r5 == ctx->r1) {
        // 0x8008B148: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8008B174;
    }
    // 0x8008B148: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008B14C: beq         $a1, $at, L_8008B164
    if (ctx->r5 == ctx->r1) {
        // 0x8008B150: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8008B164;
    }
    // 0x8008B150: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008B154: beql        $a1, $at, L_8008B178
    if (ctx->r5 == ctx->r1) {
        // 0x8008B158: lbu         $t0, 0x1B($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X1B);
            goto L_8008B178;
    }
    goto skip_0;
    // 0x8008B158: lbu         $t0, 0x1B($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1B);
    skip_0:
    // 0x8008B15C: jr          $ra
    // 0x8008B160: nop

    return;
    // 0x8008B160: nop

L_8008B164:
    // 0x8008B164: lbu         $t7, 0x1B($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008B168: andi        $t8, $t7, 0xFFFB
    ctx->r24 = ctx->r15 & 0XFFFB;
    // 0x8008B16C: jr          $ra
    // 0x8008B170: sb          $t8, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r24;
    return;
    // 0x8008B170: sb          $t8, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r24;
L_8008B174:
    // 0x8008B174: lbu         $t0, 0x1B($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1B);
L_8008B178:
    // 0x8008B178: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x8008B17C: sb          $t1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r9;
    // 0x8008B180: jr          $ra
    // 0x8008B184: nop

    return;
    // 0x8008B184: nop

;}
RECOMP_FUNC void func_808001D8_chlagoonufoext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808001DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001E8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808001EC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x808001F0: jal         0x800CBDD4
    // 0x808001F4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800CBDD4(rdram, ctx);
        goto after_0;
    // 0x808001F4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x808001F8: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x808001FC: jal         0x800DA298
    // 0x80800200: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800200: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    after_1:
    // 0x80800204: beq         $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800208: nop
    
            goto L_80800234;
    }
    // 0x80800208: nop

    // 0x8080020C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80800210: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800214: beq         $a0, $at, L_80800224
    if (ctx->r4 == ctx->r1) {
        // 0x80800218: nop
    
            goto L_80800224;
    }
    // 0x80800218: nop

    // 0x8080021C: jal         0x800CBB80
    // 0x80800220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CBB80(rdram, ctx);
        goto after_2;
    // 0x80800220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_80800224:
    // 0x80800224: jal         0x800FFAB0
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080022C: b           L_80800254
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800254;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800234:
    // 0x80800234: jal         0x80089F48
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080023C: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800240: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800244: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800248: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8080024C: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800254:
    // 0x80800254: addiu       $a1, $zero, 0x1C0
    ctx->r5 = ADD32(0, 0X1C0);
    // 0x80800258: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8080025C: jal         0x8008A0C0
    // 0x80800260: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _subaddiemarker_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800260: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80800264: beq         $v0, $zero, L_80800274
    if (ctx->r2 == 0) {
        // 0x80800268: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_80800274;
    }
    // 0x80800268: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080026C: jal         0x800EE7F8
    // 0x80800270: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800270: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
L_80800274:
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x80100094
    // 0x8080027C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x8080027C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800288: jal         0x8008A2A0
    // 0x8080028C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x8080028C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
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
RECOMP_FUNC void chskeletonexplode_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800DA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DAC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800DB0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800DB4: lhu         $t7, 0x14($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X14);
    // 0x80800DB8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80800DBC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80800DC0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800DC4: lhu         $t9, 0x16($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X16);
    // 0x80800DC8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800DCC: jal         0x800EE904
    // 0x80800DD0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x80800DD0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80800DD4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800DD8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80800DDC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80800DE0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DE4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80800DE8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800DEC: addiu       $a0, $a0, 0x6DE8
    ctx->r4 = ADD32(ctx->r4, 0X6DE8);
    // 0x80800DF0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800DF4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80800DF8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800DFC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800E00: jal         0x80086D58
    // 0x80800E04: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800E04: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_1:
    // 0x80800E08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800E0C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800E10: jr          $ra
    // 0x80800E14: nop

    return;
    // 0x80800E14: nop

;}
RECOMP_FUNC void func_80801D08_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801D0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801D10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801D14: beq         $a1, $zero, L_80801D38
    if (ctx->r5 == 0) {
        // 0x80801D18: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80801D38;
    }
    // 0x80801D18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801D20: beq         $a1, $at, L_80801D54
    if (ctx->r5 == ctx->r1) {
        // 0x80801D24: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801D54;
    }
    // 0x80801D24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801D28: beq         $a1, $at, L_80801D80
    if (ctx->r5 == ctx->r1) {
        // 0x80801D2C: nop
    
            goto L_80801D80;
    }
    // 0x80801D2C: nop

    // 0x80801D30: b           L_80801D9C
    // 0x80801D34: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
        goto L_80801D9C;
    // 0x80801D34: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
L_80801D38:
    // 0x80801D38: jal         0x800EFD24
    // 0x80801D3C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80801D3C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80801D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D44: jal         0x80102D78
    // 0x80801D48: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x80801D48: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80801D4C: b           L_80801D98
    // 0x80801D50: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_80801D98;
    // 0x80801D50: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80801D54:
    // 0x80801D54: jal         0x800EFD24
    // 0x80801D58: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80801D58: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80801D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D60: jal         0x80102D78
    // 0x80801D64: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80102D78(rdram, ctx);
        goto after_3;
    // 0x80801D64: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80801D68: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801D6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801D70: nop

    // 0x80801D74: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80801D78: b           L_80801D98
    // 0x80801D7C: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
        goto L_80801D98;
    // 0x80801D7C: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
L_80801D80:
    // 0x80801D80: jal         0x8010D254
    // 0x80801D84: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8010D254(rdram, ctx);
        goto after_4;
    // 0x80801D84: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80801D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D8C: jal         0x80102D78
    // 0x80801D90: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80102D78(rdram, ctx);
        goto after_5;
    // 0x80801D90: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80801D94: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80801D98:
    // 0x80801D98: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
L_80801D9C:
    // 0x80801D9C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80801DA0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801DA4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DAC: jal         0x80102BF8
    // 0x80801DB0: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    func_80102BF8(rdram, ctx);
        goto after_6;
    // 0x80801DB0: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    after_6:
    // 0x80801DB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801DB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801DBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801DC0: jr          $ra
    // 0x80801DC4: nop

    return;
    // 0x80801DC4: nop

;}
RECOMP_FUNC void baswim_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001E8: beq         $a1, $zero, L_80800278
    if (ctx->r5 == 0) {
        // 0x808001EC: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800278;
    }
    // 0x808001EC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808001F0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808001F4: jal         0x80084CC0
    // 0x808001F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x808001F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808001FC: jal         0x80084C98
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800204: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800208: beq         $v0, $at, L_8080028C
    if (ctx->r2 == ctx->r1) {
        // 0x8080020C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080028C;
    }
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x80084CF8
    // 0x80800214: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bafpctrl_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x80800214: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800218: jal         0x800C6E38
    // 0x8080021C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    func_800C6E38(rdram, ctx);
        goto after_3;
    // 0x8080021C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_3:
    // 0x80800220: bne         $v0, $zero, L_8080022C
    if (ctx->r2 != 0) {
        // 0x80800224: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8080022C;
    }
    // 0x80800224: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800228: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8080022C:
    // 0x8080022C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800230: bnel        $t7, $zero, L_80800258
    if (ctx->r15 != 0) {
        // 0x80800234: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80800258;
    }
    goto skip_0;
    // 0x80800234: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800238: jal         0x800A3274
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_4;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800240: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800244: bne         $v0, $at, L_80800254
    if (ctx->r2 != ctx->r1) {
        // 0x80800248: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80800254;
    }
    // 0x80800248: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8080024C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80800250: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800254:
    // 0x80800254: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_80800258:
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800260: beql        $t0, $zero, L_80800290
    if (ctx->r8 == 0) {
        // 0x80800264: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800290;
    }
    goto skip_1;
    // 0x80800264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800268: jal         0x80084CD0
    // 0x8080026C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x8080026C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80800270: b           L_80800290
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800290;
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800278:
    // 0x80800278: jal         0x80084D00
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_17(rdram, ctx);
        goto after_6;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: jal         0x80084CC0
    // 0x80800288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafpctrl_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80800288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_8080028C:
    // 0x8080028C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800290:
    // 0x80800290: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void _chpickups_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085848: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085848);
    return;
    // 0x8008584C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800189A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800189A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800189AC: sll         $t8, $a0, 5
    ctx->r24 = S32(ctx->r4 << 5);
    // 0x800189B0: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800189B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800189B8: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800189BC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800189C0: lw          $t9, -0x4D30($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4D30);
    // 0x800189C4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800189C8: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x800189CC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800189D0: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800189D4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800189D8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800189DC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800189E0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800189E4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800189E8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800189EC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800189F0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800189F4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800189F8: beq         $t9, $zero, L_80018A98
    if (ctx->r25 == 0) {
        // 0x800189FC: sw          $a2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r6;
            goto L_80018A98;
    }
    // 0x800189FC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80018A00: addiu       $s2, $t7, -0x1
    ctx->r18 = ADD32(ctx->r15, -0X1);
    // 0x80018A04: blez        $s2, L_80018A98
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80018A08: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80018A98;
    }
    // 0x80018A08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80018A0C: lui         $at, 0x4900
    ctx->r1 = S32(0X4900 << 16);
    // 0x80018A10: lui         $s4, 0x8002
    ctx->r20 = S32(0X8002 << 16);
    // 0x80018A14: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80018A18: addiu       $s4, $s4, -0x7C2C
    ctx->r20 = ADD32(ctx->r20, -0X7C2C);
    // 0x80018A1C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80018A20: lwc1        $f24, 0x60($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X60);
L_80018A24:
    // 0x80018A24: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80018A28: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80018A2C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80018A30: mul.s       $f12, $f4, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80018A34: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018A38: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80018A3C: mul.s       $f0, $f6, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80018A40: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80018A44: mul.s       $f2, $f8, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x80018A48: nop

    // 0x80018A4C: mul.s       $f14, $f10, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80018A50: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80018A54: mul.s       $f16, $f2, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80018A58: nop

    // 0x80018A5C: mul.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80018A60: nop

    // 0x80018A64: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80018A68: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80018A6C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80018A70: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80018A74: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80018A78: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80018A7C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80018A80: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80018A84: jal         0x800C9EAC
    // 0x80018A88: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800C9EAC(rdram, ctx);
        goto after_0;
    // 0x80018A88: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_0:
    // 0x80018A8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80018A90: bne         $s1, $s2, L_80018A24
    if (ctx->r17 != ctx->r18) {
        // 0x80018A94: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80018A24;
    }
    // 0x80018A94: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80018A98:
    // 0x80018A98: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80018A9C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80018AA0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80018AA4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80018AA8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80018AAC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80018AB0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80018AB4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80018AB8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80018ABC: jr          $ra
    // 0x80018AC0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80018AC0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80018AC4: nop

    // 0x80018AC8: nop

    // 0x80018ACC: nop

;}
