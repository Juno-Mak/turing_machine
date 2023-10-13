#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/bits.h"
struct _Bits {
    char *bits;
    unsigned int length;
};

bits bit_new(unsigned int length)
{
    bits new_bits = (bits)malloc(sizeof(struct _Bits));
    if (new_bits == NULL)
        return NULL;

    int char_nums = sizeof(char) * (length >> 3) + 1;
    new_bits->bits = (char *)malloc(char_nums);
    if (new_bits == NULL) {
        free(new_bits);
        return NULL;
    }
    memset(new_bits->bits, 0, char_nums);
    new_bits->length = length;

    return new_bits;
}

void bit_destroy(bits bit)
{
    free(bit->bits);
    free(bit);
}

unsigned int bit_length(bits bit)
{
    return bit->length;
}

void bit_set(bits bit, unsigned int pos, unsigned char value)
{
    unsigned char mask = 0x80 >> (pos & 0x7);
    if (value) {
        bit->bits[pos>>3] |= mask;
    } else {
       bit->bits[pos>>3] &= ~mask;
    }
}

char bit_get(bits bit, unsigned int pos)
{
    unsigned char mask = 0x80 >> (pos & 0x7);

    return (mask & bit->bits[pos>>3]) == mask ? 1 : 0;
}
void bit_add(bits des, bits src) {
    if (des->length != src->length) return;
    for (int pos = 0; pos < (des->length >> 3) + 1; pos++) {
        des->bits[pos] &= (char)src->bits[pos];
    }
}
int get_ones(bits bit) {
    int count = 0;
    for (int pos = 0; pos < bit->length;pos++) {
        if (bit_get(bit, pos)) count++;
    }
    return count;
}

void bit_clear(bits bit) {
    int char_nums = sizeof(char) * (bit->length >> 3) + 1;
    memset(bit->bits, 0, char_nums);
}

void bit_copy(bits des, bits src) {
    if (des->length != src->length) return;
    for (int pos = 0; pos < (des->length >> 3) + 1; pos++) {
            des->bits[pos] = (char)src->bits[pos];
    }
}
void bit_all_set(bits bit) {
    for (int pos = 0; pos < bit->length; pos++) {
        bit_set(bit, pos, 1);
    }
}
int bit_find_lowest_one(bits bit) {
    int count = 0;
    for (int pos = 0; pos < bit->length; pos++) {
        if (bit_get(bit, pos))  break;
        count++;
    }
    return count;
}
int bit_find_lowest_zero(bits bit) {
    int count = 0;
    for (int pos = 0; pos < bit->length; pos++) {
        if (!bit_get(bit, pos))  break;
        count++;
    }
    return count;
}
int bit_find_lowest_xor(bits bit1, bits bit2) {
    int count = 0;
    if (bit1->length != bit2->length) return -1;
    for (int pos = 0; pos < bit1->length; pos++) {
        if (bit_get(bit1, pos) != bit_get(bit2, pos))  break;
        count++;
    }
    return count;
}