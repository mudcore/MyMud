// skill.h
#ifndef SKILL_H
#define SKILL_H

mapping query_skills();
void set_skill(string skill, int val);
int delete_skill(string skill);
int query_skill(string skill);

mapping query_spells();
void set_spell(string spell, int val);
int delete_spell(string spell);
int query_spell(string spell);

#endif
