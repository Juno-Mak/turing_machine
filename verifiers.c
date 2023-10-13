#include <stdlib.h>
#include <stdio.h>
#include "include/bits.h"
#include "include/verifiers.h"

int check_inx_table[183] = {46, 73, 92, 34, 37, 29, 41, 22, 77, 39, 79, 89, 59, 44, 52, 32, 74, 2, 24, 40, 0, 72, 93, 3, 0, 27, 28, 56, 0, 57, 85, 84, 66, 8, 80, 95, 91, 69, 63, 14, 18, 75, 19, 65, 71, 48, 51, 53, 67, 25, 4, 62, 6, 88, 17, 9, 86, 50, 47, 21, 33, 12, 45, 26, 15, 78, 20, 11, 23, 16, 87, 49, 92, 29, 31, 38, 77, 94, 46, 61, 7, 34, 41, 54, 68, 39, 1, 73, 35, 36, 37, 22, 42, 89, 59, 44, 52, 32, 74, 70, 58, 43, 76, 90, 0, 60, 13, 55, 81, 30, 5, 88, 10, 64, 46, 73, 61, 35, 7, 36, 92, 34, 37, 29, 41, 22, 31, 54, 42, 38, 68, 82, 77, 39, 79, 94, 1, 83, 63, 14, 18, 75, 19, 65, 57, 85, 84, 66, 8, 80, 84, 85, 57, 95, 91, 69, 2, 24, 40, 72, 93, 3, 72, 93, 3, 27, 28, 56, 2, 24, 40, 27, 28, 56, 57, 85, 84, 66, 8, 80, 95, 91, 69};

int checkcard_table[95][4] = {
    {201, 798, 204, 796},
    {206, 793, 212, 790},
    {215, 786, 217, 783},
    {220, 781, 223, 779},
    {227, 776, 231, 773},
    {233, 770, 237, 767},
    {244, 765, 251, 759},
    {253, 757, 256, 754},
    {261, 750, 264, 747},
    {267, 744, 270, 742},
    {274, 740, 278, 738},
    {280, 736, 282, 733},
    {286, 729, 288, 725},
    {293, 720, 296, 718},
    {302, 715, 304, 710},
    {309, 708, 312, 704},
    {315, 699, 317, 696},
    {322, 694, 325, 690},
    {329, 687, 331, 684},
    {334, 680, 337, 673},
    {339, 669, 341, 667},
    {346, 664, 348, 662},
    {350, 658, 353, 656},
    {356, 653, 358, 651},
    {360, 649, 365, 647},
    {370, 645, 373, 641},
    {376, 639, 378, 637},
    {381, 635, 385, 633},
    {387, 631, 390, 629},
    {392, 627, 394, 621},
    {396, 617, 401, 615},
    {403, 613, 405, 610},
    {407, 608, 410, 605},
    {413, 599, 416, 597},
    {419, 595, 423, 593},
    {429, 591, 432, 589},
    {434, 587, 437, 585},
    {440, 581, 442, 579},
    {447, 577, 453, 573},
    {455, 571, 459, 567},
    {462, 564, 464, 562},
    {470, 558, 472, 553},
    {475, 550, 479, 547},
    {481, 543, 483, 540},
    {485, 536, 487, 533},
    {491, 530, 495, 527},
    {497, 523, 499, 518},
    {503, 515, 505, 509},
    {507, 506, 514, 504},
    {516, 502, 520, 498},
    {525, 496, 528, 492},
    {532, 490, 534, 486},
    {537, 484, 541, 482},
    {546, 480, 549, 476},
    {551, 474, 557, 471},
    {560, 469, 563, 463},
    {566, 461, 568, 458},
    {572, 454, 576, 449},
    {578, 445, 580, 441},
    {582, 439, 586, 435},
    {588, 433, 590, 430},
    {592, 424, 594, 421},
    {596, 418, 598, 414},
    {604, 412, 606, 409},
    {609, 406, 611, 404},
    {614, 402, 616, 399},
    {618, 395, 625, 393},
    {628, 391, 630, 391},
    {632, 386, 634, 382},
    {636, 379, 638, 377},
    {640, 374, 643, 372},
    {646, 369, 648, 362},
    {650, 359, 652, 357},
    {654, 355, 657, 352},
    {661, 349, 663, 347},
    {665, 344, 668, 340},
    {670, 338, 677, 335},
    {681, 332, 686, 330},
    {688, 327, 691, 324},
    {695, 319, 697, 316},
    {701, 314, 706, 311},
    {709, 308, 714, 303},
    {717, 299, 719, 294},
    {723, 289, 726, 287},
    {737, 279, 739, 277},
    {741, 273, 743, 268},
    {746, 266, 749, 263},
    {751, 257, 755, 255},
    {758, 252, 763, 247},
    {766, 243, 769, 236},
    {771, 232, 775, 228},
    {778, 224, 780, 221},
    {782, 219, 785, 216},
    {787, 213, 792, 207},
    {795, 205, 797, 202},
};

static int blue = 0;
static int yellow = 0;
static int purple = 0;

#define SUM (blue + yellow + purple)
static inline int count(int x) {
    return (blue == x) + (yellow == x) + (purple == x);
}
static inline int count_odd() {
    return blue % 2 + yellow % 2 + purple % 2;
}
static inline int count_order() {
    if (blue < yellow && yellow < purple) return 1;
    if (blue > yellow && yellow > purple) return 2;
    return 3;
}
static inline int count_order_seq() {
    if (blue == yellow - 1 && yellow == purple - 1) return 3;
    if (blue == yellow + 1 && yellow == purple + 1) return 3;
    if (blue == yellow - 1 || yellow == purple - 1) return 2;
    if (blue == yellow + 1 || yellow == purple + 1) return 2;    
    return 1;
}
static inline int count_order_seq_inc() {
    if ((yellow == blue + 1) && (purple == yellow + 1)) return 3;
    if ((yellow == blue + 1) || (purple == yellow + 1)) return 2; 
    return 0;
}
static inline int count_same(){
    if (blue == yellow && yellow == purple) return 3;
    if (blue == yellow || yellow == purple || blue == purple) return 2;
    return 0;
}

static void init_pram(int code) {
    blue = code / 25 + 1;
    yellow = (code / 5) % 5 + 1;
    purple = code % 5 + 1;
}

struct Condition {
    int ver_no;
    int cond_no;
    int checkcard_idx;
    bits bitmap;
    char comm[20];
} Condition;

struct Verifier {
    int no;
    int cond_nr;
    struct Condition *cond[9];
} Verifier;

static struct Verifier *ver_list[VERIFY_NR];

#define GET_CONDITION(ver_no, cond_no) (ver_list[ver_no - 1]->cond[cond_no - 1])
bits get_cond_bitmap(int ver_no, int cond_no) {return GET_CONDITION(ver_no, cond_no)->bitmap;}
int get_cond_nr(int ver_no) {return ver_list[ver_no - 1]->cond_nr;}

#define INIT_CODE_MAP(cond,condition)                        \
    for (int code = 0; code < 125; code++) {                 \
        init_pram(code);                                     \
        if (condition) bit_set(cond->bitmap, code, 1);       \
    }

#define INIT_CONDITION(ver, no, condition)                         \
    cond = (struct Condition *)malloc(sizeof(struct Condition));   \
    cond->ver_no = ver;                                            \
    cond->cond_no = no;                                            \
    cond->checkcard_idx = check_inx_table[checkcard_idx];          \
    sprintf(cond->comm,#condition);                                \
    checkcard_idx++;                                               \
    cond->bitmap = bit_new(CODE_NR);                               \
    INIT_CODE_MAP(cond,condition);                                 \
    GET_CONDITION(ver,no) = cond;
#define INIT_VER_COND9(ver, condition1, condition2, condition3, condition4, condition5, condition6, condition7, condition8, condition9)   \
    ver_list[ver-1]->cond_nr=9;        \
    INIT_CONDITION(ver,1,condition1)   \
    INIT_CONDITION(ver,2,condition2)   \
    INIT_CONDITION(ver,3,condition3)   \
    INIT_CONDITION(ver,4,condition4)   \
    INIT_CONDITION(ver,5,condition5)   \
    INIT_CONDITION(ver,6,condition6)   \
    INIT_CONDITION(ver,7,condition7)   \
    INIT_CONDITION(ver,8,condition8)   \
    INIT_CONDITION(ver,9,condition9)
#define INIT_VER_COND6(ver, condition1, condition2, condition3, condition4, condition5, condition6)   \
    ver_list[ver-1]->cond_nr=6;        \
    INIT_CONDITION(ver,1,condition1)   \
    INIT_CONDITION(ver,2,condition2)   \
    INIT_CONDITION(ver,3,condition3)   \
    INIT_CONDITION(ver,4,condition4)   \
    INIT_CONDITION(ver,5,condition5)   \
    INIT_CONDITION(ver,6,condition6)
#define INIT_VER_COND4(ver, condition1, condition2, condition3, condition4)   \
    ver_list[ver-1]->cond_nr=4;        \
    INIT_CONDITION(ver,1,condition1)   \
    INIT_CONDITION(ver,2,condition2)   \
    INIT_CONDITION(ver,3,condition3)   \
    INIT_CONDITION(ver,4,condition4) 
#define INIT_VER_COND3(ver, condition1, condition2, condition3)   \
    ver_list[ver-1]->cond_nr=3;        \
    INIT_CONDITION(ver,1,condition1)   \
    INIT_CONDITION(ver,2,condition2)   \
    INIT_CONDITION(ver,3,condition3)
#define INIT_VER_COND2(ver, condition1,condition2)   \
    ver_list[ver-1]->cond_nr=2;        \
    INIT_CONDITION(ver,1,condition1)   \
    INIT_CONDITION(ver,2,condition2)
void map_add_cond(bits bit,int ver_no, int cond_no) {
    bit_add(bit,GET_CONDITION(ver_no,cond_no)->bitmap);
}

int test_condition(int code, int ver_no, int cond_no) {
    int ret = bit_get(GET_CONDITION(ver_no,cond_no)->bitmap,code);
    return !!ret;
}
void init_verfiers() {
    for (int ver = 0;ver < VERIFY_NR; ver++) {
        ver_list[ver] = (struct Verifier *)malloc(sizeof(struct Verifier));
    }
    int checkcard_idx = 0;
    struct Condition *cond;
    INIT_VER_COND2(1,blue == 1,blue > 1)
    INIT_VER_COND3(2,blue < 3, blue == 3, blue > 3)
    INIT_VER_COND3(3,yellow < 3, yellow == 3, yellow > 3)
    INIT_VER_COND3(4,yellow < 4, yellow == 4, yellow > 4)
    INIT_VER_COND2(5,(blue % 2) == 0, (blue % 2) == 1)
    INIT_VER_COND2(6,(yellow % 2) == 0, (yellow % 2) == 1)
    INIT_VER_COND2(7,(purple % 2) == 0, (purple % 2) == 1)
    INIT_VER_COND4(8,count(1) == 0,count(1) == 1,count(1) == 2,count(1) == 3)
    INIT_VER_COND4(9,count(3) == 0,count(3) == 1,count(3) == 2,count(3) == 3)
    INIT_VER_COND4(10,count(4) == 0,count(4) == 1,count(4) == 2,count(4) == 3)
    INIT_VER_COND3(11,blue < yellow, blue == yellow, blue > yellow)
    INIT_VER_COND3(12,blue < purple, blue == purple, blue > purple)
    INIT_VER_COND3(13,yellow < purple, yellow == purple, yellow > purple)
    INIT_VER_COND3(14,blue < yellow && blue < purple, yellow < blue && yellow < purple, purple < blue && purple < yellow)
    INIT_VER_COND3(15,blue > yellow && blue > purple, yellow > blue && yellow > purple, purple > blue && purple > yellow)
    INIT_VER_COND2(16,count_odd() < 2,count_odd() >= 2)
    INIT_VER_COND4(17,count_odd() == 3,count_odd() == 2,count_odd() == 1,count_odd() == 0)
    INIT_VER_COND2(18,SUM % 2 == 0,SUM % 2 == 1)
    INIT_VER_COND3(19,(blue + yellow) < 6,(blue + yellow) == 6, (blue + yellow) > 6)
    INIT_VER_COND3(20,count_same() == 3,count_same() == 2, count_same()== 0)
    INIT_VER_COND2(21,count_same() != 2 ,count_same() == 2)
    INIT_VER_COND3(22,count_order() == 1,count_order() == 2, count_order() == 3)
    INIT_VER_COND3(23,SUM < 6, SUM == 6, SUM > 6)
    INIT_VER_COND3(24,count_order_seq_inc() == 3, count_order_seq_inc() == 2, count_order_seq_inc() == 0)
    INIT_VER_COND3(25,count_order_seq() == 1, count_order_seq() == 2,count_order_seq() == 3)
    INIT_VER_COND3(26,blue < 3, yellow < 3, purple < 3)
    INIT_VER_COND3(27,blue < 4, yellow < 4, purple < 4)
    INIT_VER_COND3(28,blue == 1, yellow == 1, purple == 1)
    INIT_VER_COND3(29,blue == 3, yellow == 3, purple == 3)
    INIT_VER_COND3(30,blue == 4, yellow == 4, purple == 4)
    INIT_VER_COND3(31,blue > 1, yellow > 1, purple > 1)
    INIT_VER_COND3(32,blue > 3, yellow > 3, purple > 3)
    INIT_VER_COND6(33,blue % 2 == 0, blue % 2 == 1, yellow % 2 == 0, yellow % 2 == 1, purple % 2 == 0, purple % 2 == 1)
    INIT_VER_COND3(34,blue <= yellow && blue <= purple, yellow <= blue && yellow <= purple, purple <= yellow && purple <= blue)
    INIT_VER_COND3(35,blue >= yellow && blue >= purple, yellow >= blue && yellow >= purple, purple >= yellow && purple >= blue)
    INIT_VER_COND3(36,SUM % 3 == 0, SUM % 4 == 0, SUM % 5 == 0)
    INIT_VER_COND3(37,blue + yellow == 4,blue + purple == 4,purple + yellow == 4)
    INIT_VER_COND3(38,blue + yellow == 6,blue + purple == 6,purple + yellow == 6)
    INIT_VER_COND6(39,blue == 1, blue > 1, yellow == 1, yellow > 1, purple == 1, purple > 1)
    INIT_VER_COND9(40,blue < 3, blue == 3,blue > 3, yellow < 3, yellow == 3, yellow > 3, purple == 3, purple < 3, purple > 3)
    INIT_VER_COND9(41,blue < 4, blue == 4,blue > 4, yellow < 4, yellow == 4, yellow > 4, purple == 4, purple < 4, purple > 4)
    INIT_VER_COND6(42,blue < yellow && blue < purple, yellow < blue && yellow < purple, purple < yellow && purple < blue, blue > yellow && blue > purple, yellow > blue && yellow > purple, purple > yellow && purple > blue)
    INIT_VER_COND6(43,blue < yellow, blue == yellow, blue > yellow, blue < purple, blue == purple, blue > purple)
    INIT_VER_COND6(44,yellow > blue, yellow == blue, yellow < blue, yellow < purple, yellow == purple, yellow > purple)
    INIT_VER_COND6(45,count(1) == 0,count(1) == 1,count(1) == 2,count(3) == 0,count(3) == 1,count(3) == 2)
    INIT_VER_COND6(46,count(3) == 0,count(3) == 1,count(3) == 2,count(4) == 0,count(4) == 1,count(4) == 2)
    INIT_VER_COND6(47,count(1) == 0,count(1) == 1,count(1) == 2,count(4) == 0,count(4) == 1,count(4) == 2)
    INIT_VER_COND9(48,blue < yellow,blue == yellow,blue > yellow, blue < purple, blue == purple, blue > purple, yellow < purple, yellow == purple, yellow > purple)
}
void free_verfiers() {
     for (int ver_no = 1; ver_no <= VERIFY_NR; ver_no++) {
        for (int cond_no = 1; cond_no <= get_cond_nr(ver_no); cond_no++) {
            bit_destroy(GET_CONDITION(ver_no, cond_no)->bitmap);
            free(GET_CONDITION(ver_no, cond_no));
        }
        free(ver_list[ver_no - 1]);
    }
}

int find_real_cond(int ver_no, int idx) {
    for (int cond_no = 1;cond_no <= get_cond_nr(ver_no); cond_no++) {
        for (int j = 0; j < 4; j++) { 
            if(checkcard_table[GET_CONDITION(ver_no,cond_no)->checkcard_idx-1][j] == idx) return cond_no;
        }
    }
    return -1;
}