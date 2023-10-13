#include <stdlib.h>
#include <stdio.h>
#include "include/verifiers.h"
#include "include/bits.h"
#include "include/turing_machine.h"

struct password {
    int code;
    unsigned int cond_no[6];
};

struct password password_pool[1000];
static int possi_nr = 0;
struct Puzzle {
    int verifier_nr;
    int ver_list[VERIFIER_NR_MAX];
    int condition_choose[VERIFIER_NR_MAX];
    int checkcard_no[VERIFIER_NR_MAX];
    int real_cond_no[VERIFIER_NR_MAX];
} Puzzle;
int get_final_password(struct Puzzle *p);
int code_to_password(int code)
{
    int blue = code / 25 + 1;
    int yellow = (code / 5) % 5 + 1;
    int purple = code % 5 + 1;
    return blue * 100 + yellow * 10 + purple;
}

static void find_result_dfs(struct Puzzle* p,int depth, bits bit) {
    bits bit_temp = bit_new(CODE_NR);
    int ver_no = p->ver_list[depth];
    int cond_nr = get_cond_nr(ver_no);
    for (int cond_no = 1; cond_no <= cond_nr; cond_no++) {
        bit_copy(bit_temp, bit);
        p->condition_choose[depth] = cond_no;
        map_add_cond(bit_temp, ver_no, cond_no);
        if (get_ones(bit_temp) == 0) continue;
        if ((depth == p->verifier_nr - 1) && get_ones(bit_temp) == 1) {
            for (int i = 0; i < p->verifier_nr; i++) {
                password_pool[possi_nr].cond_no[i] = p->condition_choose[i];
            }
            password_pool[possi_nr].code = code_to_password(bit_find_lowest_one(bit_temp));
            possi_nr++;
            continue;
        }
        if (depth == p->verifier_nr - 1) continue;
        find_result_dfs(p, depth + 1, bit_temp);
    }
    bit_destroy(bit_temp); 
}
void find_possible_result(struct Puzzle* p)  {
    bits bit = bit_new(CODE_NR);
    bit_all_set(bit);
    find_result_dfs(p, 0, bit);
    bit_destroy(bit);
}
int main() {
    init_verfiers();
    struct Puzzle p;
    scanf("%d",&p.verifier_nr);
    if (p.verifier_nr > 6) {
        printf("error param length\r\n");
        return -1;
    }
    for (int i = 0; i < p.verifier_nr; i++) {
        scanf("%d", &p.ver_list[i]);
        scanf("%d", &p.checkcard_no[i]);
        p.real_cond_no[i] = find_real_cond(p.ver_list[i], p.checkcard_no[i]);
    }
    find_possible_result(&p);

    int password = get_final_password(&p);
    printf("find final password:%d", password);
    free_verfiers();
}

static void swap_p(struct password *a, struct password *b) {
    struct password *tmp = a;
    *a = *b;
    *b = *tmp;
}
int get_final_password(struct Puzzle *p) {
    int test_code;
    int ver_no;
    int checkcard_no;
    int result;
    int cond_no;
    int compared_cond_no;
    int comparing_cond_no;

    for (int ver_index = 0; ver_index < p->verifier_nr; ver_index++) {
        ver_no = p->ver_list[ver_index];
        checkcard_no = p->checkcard_no[ver_index];
        compared_cond_no = password_pool[0].cond_no[ver_index];
        for (int i = 1; i < possi_nr; i++) {
            comparing_cond_no = password_pool[i].cond_no[ver_index];
            if (comparing_cond_no != compared_cond_no) { 
                test_code = bit_find_lowest_xor(get_cond_bitmap(ver_no,comparing_cond_no), get_cond_bitmap(ver_no, compared_cond_no));
                result = bit_get(get_cond_bitmap(ver_no, p->real_cond_no[ver_index]), test_code);     
                
                for (int j = 0; j < possi_nr; j++) {
                    cond_no=password_pool[j].cond_no[ver_index];
                    if (result != bit_get(get_cond_bitmap(ver_no, cond_no),test_code)) {
                        swap_p(&password_pool[j--], &password_pool[--possi_nr]);
                        compared_cond_no = password_pool[0].cond_no[ver_index];
                        i = 0;
                    }
                }
                continue;
            }
        }
    }
    return password_pool[0].code;
}