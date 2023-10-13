
#ifndef _VERIFIERS_H_
#define _VERIFIERS_H_
#include "bits.h"
#include "turing_machine.h"
#define VERIFIER_NR_MAX 6
struct Condition;
struct Verifier;
struct Checkcard;
int get_cond_nr(int ver_no);
// struct Verifier *get_ver(int ver_no,int cond_no);
bits get_cond_bitmap(int ver_no, int cond_no);
int map_test_cond(bits bit,int ver_no, int cond_no);
void map_add_cond(bits bit,int ver_no, int cond_no);
void init_verfiers();
void show_cond(struct Condition *cond);
void free_verfiers();
//int check_inx_table[183];
//int checkcard_table[95][4];
int find_real_cond(int ver_no,int idx);
//struct Verifier *ver_list[VERIFY_NR];
//#define get_ver(ver_no,cond_no) (ver_list[ver_no - 1]->cond[cond_no - 1])
//#define get_cond_nr(ver_no) (ver_list[ver_no - 1]->cond_nr)
#endif