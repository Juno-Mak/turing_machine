/**
 *文件：bit.h
 *目的: 实现bitmap数据结构
 *作者：杜小波
 *联系方式：code2living@gmail.com
 **/

#ifndef _BIT_H_
#define _BIT_H_

/**
 *存储bitmap的结构体
 *存储的顺序从左至右
 **/
struct _Bits;
typedef struct _Bits *bits;


bits bit_new(unsigned int length);
void bit_destroy(bits bit);
unsigned int bit_length(bits bit);
void bit_set(bits bit, unsigned int pos, unsigned char value);
char bit_get(bits bit, unsigned int pos);
void bit_add(bits des, bits src);
int get_ones(bits bit);
void bit_copy(bits des, bits src);
void bit_all_set(bits bit);
void bit_clear(bits bit);
int bit_find_lowest_one(bits bit);
int bit_find_lowest_zero(bits bit);
int bit_find_lowest_xor(bits bit1, bits bit2);
#endif /*_BITS_H_*/