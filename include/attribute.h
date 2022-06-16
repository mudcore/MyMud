/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: attribute.h
Description: attribute.c 函数声明
Author: xuefeng
Version: v1.0
Date: 2019-03-17
History:
*****************************************************************************/
#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

void set_attr(string attr, int value);
void add_attr(string attr, int value);
void query_attr(string attr);
int query_str();
int query_agi();
int query_vit();
int query_luk();
int query_charm();
int query_magic();
int query_mend();
int query_max_hp();
int query_max_mp();
int query_hp();
int query_mp();
int query_max_sp();
int query_sp();
int query_attack();
int query_defense();
float query_dodge();
float query_parry();
float query_critical();
float query_mp_rate();
int hp_regen();
int mp_regen();
varargs int query_score(int i);

#endif
