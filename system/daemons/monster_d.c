/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: monster_d.c
Description: 游戏怪物守护进程
Author: xuefeng
Version: v1.0
*****************************************************************************/
#ifndef DATA_DIR
#define DATA_DIR "/data/"
#endif

inherit SAVE;

mapping mob_desc;

/*
 * ID, Name, Family, HP, MP, 攻, 防, 速, EXP, Gold
 */
nosave mixed mob_info = ({
    ({"mob", "魔物", "???", 7, 6, 5, 4, 3, 2, 1}),
    ({"slime", "史莱姆", "Slime", 8, 2, 10, 7, 7, 2, 4}),
    ({"cruelcumber", "西葫芦枪兵", "Plant", 10, 2, 12, 9, 10, 3, 5}),
    ({"teeny sanguini", "哞萌萌", "Demon", 13, 2, 12, 6, 15, 4, 7}),
    ({"sacksquatch", "沙包怪", "Material", 15, 0, 13, 8, 8, 5, 8}),
    ({"batteryfly", "人面蝶", "Bug", 14, 5, 14, 12, 9, 7, 12}),
    ({"dracky", "笑脸蝙蝠", "Bird", 15, 3, 17, 12, 18, 10, 10}),
    ({"bodkin archer", "射手怪", "Humanoid", 17, 5, 16, 12, 10, 9, 16}),
    ({"bag laughs", "笑脸袋", "Material", 16, 4, 19, 14, 24, 11, 26}),
    ({"mecha mynah", "金属蜂", "Machine", 6, 4, 20, 38, 9, 12, 20}),
    ({"fire spirit", "梅拉鬼魂", "Elemental", 14, 3, 9, 9, 9, 12, 15}),
    ({"spirit", "幽灵", "Zombie", 20, 2, 23, 20, 14, 16, 24}),
    ({"winkster", "见习恶魔", "Demon", 18, 3, 19, 16, 22, 22, 25}),
    ({"hammerhood", "大木锤", "Humanoid", 20, 2, 12, 18, 17, 20, 20}),
    ({"she slime", "史莱姆倍斯", "Slime", 19, 4, 23, 18, 25, 20, 22}),
    ({"funghoul", "妖怪蘑菇", "Plant", 22, 3, 25, 17, 19, 25, 20}),
    ({"bubble slime", "泡沫史莱姆", "Slime", 23, 4, 26, 15, 8, 24, 18}),
    ({"wooper trooper", "鱼人士兵", "Aquatic", 30, 4, 33, 24, 28, 40, 32}),
    ({"betterfly", "食人蝶", "Bug", 37, 5, 30, 16, 44, 36, 28}),
    ({"meowgician", "猫法师", "Beast", 29, 5, 25, 20, 32, 40, 28}),
    ({"ragged reaper", "稻草人", "Material", 34, 4, 38, 24, 36, 56, 28}),
    ({"gastropog", "蜗牛蛙", "Bug", 28, 0, 36, 48, 22, 48, 36}),
    ({"brownie", "棕仙", "Humanoid", 40, 255, 29, 26, 40, 56, 32}),
    ({"boppin badger", "狸猫", "Beast", 39, 4, 38, 28, 33, 60, 30}),
    ({"drackmage", "大蝙蝠", "Bird", 35, 9, 34, 28, 47, 60, 30}),
    ({"bodkin fletcher", "毒箭小妖", "Humanoid", 36, 4, 42, 30, 53, 62, 44}),
    ({"ram rider", "疯狂山羊", "Beast", 57, 4, 46, 28, 40, 70, 30}),
    ({"cumaulus", "雾气魔", "Elemental", 30, 10, 28, 30, 72, 62, 42}),
    ({"skeleton", "骸骨", "Zombie", 42, 6, 48, 40, 54, 81, 60}),
    ({"heal slime", "荷伊米史莱姆", "Slime", 30, 10, 30, 26, 33, 56, 30}),
    ({"blinkster", "魔术师宝宝", "Demon", 33, 5, 26, 26, 50, 64, 40}),
    ({"leery lout", "盾小鬼", "Humanoid", 36, 255, 40, 28, 35, 68, 34}),
    ({"lunatick", "梅达", "Bug", 36, 8, 35, 40, 41, 70, 32}),
    ({"leafy larrikin", "红叶小鬼", "Plant", 36, 6, 40, 28, 66, 42, 28}),
    ({"clockwork cuckoo", "铁鸟", "Machine", 27, 0, 46, 80, 40, 72, 41}),
    ({"slugger", "舞蹈虫", "Bug", 48, 4, 42, 34, 68, 64, 47}),
    ({"chariot chappie", "突击小鬼", "Humanoid", 55, 5, 55, 55, 46, 90, 60}),
    ({"morphean mushroom", "蘑菇人", "Plant", 50, 5, 50, 42, 40, 75, 45}),
    ({"lost soul", "彷徨的灵魂", "Elemental", 62, 10, 32, 32, 70, 96, 40}),
    ({"flython", "翼蛇", "Dragon", 70, 6, 60, 50, 55, 100, 70}),
    ({"badger mager", "魔法狸猫", "Beast", 56, 12, 53, 48, 54, 105, 60}),
    ({"crabid", "军队蟹", "Bug", 72, 0, 72, 83, 15, 220, 96}),
    ({"mean spirit", "死神", "Zombie", 65, 8, 55, 40, 62, 99, 66}),
    ({"magus", "魔术师", "Humanoid", 58, 18, 48, 38, 70, 90, 80}),
    ({"mummy boy", "干尸男", "Zombie", 91, 8, 60, 30, 22, 105, 60}),
    ({"earthenwarrior", "陶俑骑士", "Material", 55, 6, 58, 65, 48, 110, 66}),
    ({"metal slime", "金属史莱姆", "Slime", 4, 255, 35, 256, 89, 4096, 20}),
    ({"bodkin bowyer", "弓箭妖精", "Humanoid", 58, 255, 58, 52, 56, 112, 62}),
    ({"slime knight", "史莱姆骑士", "Slime", 60, 9, 62, 60, 49, 127, 74}),
    ({"cyclown", "镰鼬", "Elemental", 56, 8, 52, 48, 78, 108, 79}),
    ({"badboon", "花面狒狒", "Beast", 90, 6, 80, 64, 40, 171, 69}),
    ({"slime stack", "史莱姆塔", "Slime", 177, 24, 93, 68, 102, 317, 137}),
    ({"mudraker", "烂泥怪", "Elemental", 120, 12, 85, 50, 26, 188, 86}),
    ({"mushroom mage", "魔法食人菇", "Plant", 67, 18, 50, 56, 56, 144, 70}),
    ({"drackyma", "魔法笑脸蝠", "Bird", 52, 10, 58, 58, 70, 145, 74}),
    ({"walking corpse", "腐烂尸体", "Zombie", 105, 9, 70, 35, 35, 155, 66}),
    ({"jinkster", "独眼小丑", "Demon", 60, 11, 50, 60, 78, 127, 80}),
    ({"restless armour", "彷徨铠甲", "Material", 100, 12, 95, 97, 63, 324, 120}),
    ({"knocktopus", "尖刺章鱼", "Aquatic", 75, 8, 68, 60, 51, 162, 64}),
    ({"chimaera", "奇美拉", "Bird", 75, 9, 70, 72, 86, 180, 89}),
    ({"salamarauder", "鱼人海贼", "Aquatic", 80, 8, 75, 67, 70, 171, 74}),
    ({"jellyfish", "麻痹水母", "Aquatic", 70, 10, 72, 68, 80, 200, 72}),
    ({"mortoad", "加农蛙", "Aquatic", 140, 10, 80, 70, 48, 290, 90}),
    ({"dread admiral", "麻痹蝴蝶", "Bug", 76, 9, 75, 76, 80, 192, 80}),
    ({"zumeanie", "火红西葫芦枪兵", "Plant", 85, 9, 82, 80, 62, 212, 104}),
    ({"bud brother", "斑点银杏", "Plant", 65, 6, 68, 55, 90, 100, 62}),
    ({"spinchilla", "旋流王", "Aquatic", 126, 30, 88, 78, 96, 300, 112}),
    ({"bewarewolf", "兽人", "Beast", 87, 255, 83, 89, 77, 225, 98}),
    ({"clawcerer", "豹法师", "Beast", 75, 17, 75, 75, 81, 212, 104}),
    ({"rampage", "蓝山羊", "Beast", 100, 12, 80, 80, 60, 224, 114}),
    ({"beakon", "大嘴鸡", "Bird", 65, 9, 68, 65, 68, 153, 78}),
    ({"mad moai", "大石像", "Material", 125, 0, 100, 125, 9, 350, 120}),
    ({"trigertaur", "虎骑兵", "Beast", 100, 12, 98, 100, 85, 350, 136}),
    ({"grinade", "笑脸岩石", "Material", 75, 0, 77, 103, 67, 288, 86}),
    ({"toxic zombie", "剧毒僵尸", "Zombie", 150, 10, 82, 35, 32, 270, 100}),
    ({"metal slime knight", "金属史莱姆骑士", "Slime", 46, 8, 82, 140, 80, 305, 82}),
    ({"hocus chimaera", "魔法奇美拉", "Bird", 80, 12, 80, 80, 86, 288, 126}),
    ({"treeface", "人面树", "Plant", 95, 12, 83, 78, 63, 315, 102}),
    ({"stone golem", "岩石巨像", "Material", 156, 0, 104, 130, 55, 400, 126}),
    ({"gum shield", "大脸怪", "Humanoid", 80, 255, 80, 101, 81, 226, 108}),
    ({"pink sanguini", "粉红哞萌萌", "Demon", 85, 9, 85, 92, 104, 236, 112}),
    ({"scarewolf", "玛姆尔兽人", "Beast", 102, 32, 94, 105, 87, 325, 126}),
    ({"big badboon", "绿狒狒", "Beast", 147, 8, 106, 74, 62, 420, 96}),
    ({"medislime", "北荷伊米史莱姆", "Slime", 82, 20, 82, 80, 70, 300, 110}),
    ({"shaman", "祈祷师", "Humanoid", 90, 33, 76, 64, 90, 290, 134}),
    ({"weaken beakon", "死亡怪鸟", "Bird", 78, 10, 72, 90, 88, 266, 88}),
    ({"raving lunatick", "梅达领主", "Bug", 85, 21, 86, 100, 90, 310, 98}),
    ({"hunter mech", "金属猎人", "Machine", 95, 5, 95, 110, 100, 450, 144}),
    ({"riptide", "利爪海妖", "Aquatic", 102, 18, 102, 105, 105, 540, 156}),
    ({"metal medley", "金属史莱姆塔", "Slime", 6, 255, 70, 256, 135, 12288, 60}),
    ({"king slime", "史莱姆王", "Slime", 245, 32, 136, 95, 75, 600, 164}),
    ({"claw hammer", "地狱鲨鱼", "Aquatic", 98, 9, 108, 90, 90, 432, 126}),
    ({"shocktopus", "魔界铁章鱼", "Machine", 75, 0, 85, 156, 90, 375, 144}),
    ({"axolhotl", "鱼人男爵", "Aquatic", 92, 8, 90, 100, 83, 360, 104}),
    ({"parched peckerel", "沙漠奔跑者", "Bird", 101, 9, 93, 98, 99, 405, 108}),
    ({"power hammer", "沙漠鲨鱼", "Aquatic", 110, 7, 85, 105, 100, 450, 168}),
    ({"gold golem", "黄金巨像", "Material", 250, 0, 136, 130, 77, 414, 505}),
    ({"expload", "沙漠战车", "Beast", 142, 10, 102, 116, 64, 522, 146}),
    ({"mummy", "木乃伊", "Zombie", 138, 12, 112, 80, 66, 455, 96}),
    ({"admirer", "果冻人", "Elemental", 120, 16, 102, 85, 75, 440, 168}),
    ({"legionnaire", "骸骨士兵", "Zombie", 99, 9, 106, 115, 99, 410, 100}),
    ({"diethon", "地狱毒蛇", "Dragon", 109, 10, 104, 108, 102, 432, 110}),
    ({"purrestidgitator", "孟加猫法师", "Beast", 96, 30, 84, 110, 102, 423, 126}),
    ({"manguini", "斗争恶魔", "Demon", 108, 11, 112, 114, 117, 477, 126}),
    ({"mandrake major", "蜥蜴人", "Dragon", 107, 16, 98, 107, 87, 510, 128}),
    ({"scourgette", "黑色贝吉塔", "Plant", 96, 20, 90, 98, 81, 500, 130}),
    ({"wyrtle", "龙龟", "Dragon", 105, 0, 105, 150, 47, 600, 116}),
    ({"crabber dabber doo", "地狱之蟹", "Aquatic", 112, 7, 115, 121, 78, 670, 118}),
    ({"badja", "黑狸猫", "Beast", 105, 20, 98, 101, 104, 570, 144}),
    ({"giddy gastropog", "美达巴尼蜗牛", "Bug", 90, 15, 104, 140, 50, 580, 100}),
    ({"treevil", "乌多拉", "Plant", 111, 14, 101, 101, 99, 600, 106}),
    ({"ghoul", "食尸鬼", "Zombie", 162, 12, 112, 65, 90, 760, 124}),
    ({"robo robin", "钢鹰", "Machine", 75, 0, 100, 210, 113, 580, 98}),
    ({"swinoceros", "突进角犀", "Beast", 120, 8, 105, 121, 91, 610, 102}),
    ({"peckerel", "刺客鸵鸟", "Bird", 107, 6, 107, 107, 107, 580, 132}),
    ({"battering ram", "大角羊", "Beast", 105, 9, 113, 122, 104, 600, 108}),
    ({"rockbomb", "爆弹岩石", "Material", 100, 5, 100, 156, 76, 700, 95}),
    ({"brainy badboon", "粉红狒狒", "Beast", 150, 16, 120, 99, 95, 800, 108}),
    ({"drackal", "强壮野兽", "Beast", 230, 20, 148, 123, 87, 1000, 150}),
    ({"gruffon", "努波恩", "Demon", 136, 12, 118, 106, 76, 540, 136}),
    ({"sorcerer", "妖术师", "Humanoid", 99, 66, 94, 114, 114, 690, 130}),
    ({"cheeky tiki", "无耻提基", "Material", 117, 9, 107, 127, 100, 660, 100}),
    ({"deadcurion", "死神兵", "Zombie", 112, 4, 115, 117, 98, 790, 127}),
    ({"infernal armour", "地狱铠甲", "Material", 125, 8, 135, 130, 102, 850, 150}),
    ({"troll", "巨魔", "Demon", 413, 255, 158, 70, 60, 1500, 52}),
    ({"shivery shrubbery", "雪恶魔", "Elemental", 81, 14, 96, 99, 102, 680, 98}),
    ({"tearwolf", "兽人杀手", "Beast", 136, 44, 121, 125, 112, 730, 140}),
    ({"brrearthenwarrior", "冬将军", "Material", 125, 0, 125, 135, 105, 800, 149}),
    ({"apeckalypse", "兰顿鸡", "Bird", 130, 9, 118, 118, 121, 740, 114}),
    ({"great gruffon", "大恶魔", "Demon", 150, 12, 120, 120, 70, 1180, 126}),
    ({"white trigertaur", "白骑士", "Beast", 128, 10, 130, 135, 116, 940, 167}),
    ({"sootheslime", "贝荷伊姆史莱姆", "Slime", 138, 40, 113, 125, 105, 1050, 172}),
    ({"icikiller", "寒冰利爪妖", "Humanoid", 140, 24, 140, 144, 136, 1050, 172}),
    ({"teaky mask", "杀人图腾", "Material", 98, 26, 111, 131, 114, 860, 117}),
    ({"raving reaper", "杀人玩偶", "Material", 134, 22, 135, 134, 119, 1050, 138}),
    ({"wight priest", "死亡神官", "Zombie", 126, 80, 108, 136, 125, 940, 147}),
    ({"sculptrice", "地狱兽", "Demon", 145, 36, 145, 144, 89, 920, 178}),
    ({"handsome crab", "大海蟹", "Aquatic", 121, 6, 68, 195, 56, 1350, 156}),
    ({"sail serpent", "海蛇王", "Dragon", 148, 14, 144, 143, 125, 850, 114}),
    ({"grim ginner", "暗黑矮人", "Humanoid", 110, 24, 115, 176, 110, 760, 118}),
    ({"sluggernaut", "超级舞蹈虫", "Bug", 118, 16, 96, 123, 124, 720, 120}),
    ({"splatterhorn", "角犀王", "Beast", 134, 15, 120, 164, 118, 980, 122}),
    ({"whirly girly", "真红龙卷", "Elemental", 144, 17, 120, 150, 131, 1020, 132}),
    ({"gramarye gruffon", "阿罗达塔斯", "Demon", 215, 22, 150, 125, 76, 1310, 145}),
    ({"skeleton soldier", "死灵騎士", "Zombie", 146, 12, 136, 160, 126, 1100, 149}),
    ({"bloody manguini", "鲜血恶魔", "Demon", 154, 16, 133, 148, 139, 1000, 148}),
    ({"blood mummy", "血之木乃伊", "Zombie", 166, 12, 138, 135, 67, 1200, 108}),
    ({"harmour", "恶魔铠甲", "Material", 145, 0, 135, 180, 108, 1300, 120}),
    ({"python priest", "蛇魔领主", "Demon", 136, 60, 120, 160, 130, 950, 164}),
    ({"sculpture vulture", "石像鬼", "Material", 153, 33, 140, 190, 110, 1320, 160}),
    ({"living statue", "活动石像", "Material", 236, 0, 155, 200, 99, 1500, 172}),
    ({"goodybag", "舞蹈宝石", "Material", 126, 48, 115, 130, 146, 500, 336}),
    ({"drakularge", "黄巨龙", "Dragon", 286, 9, 160, 175, 106, 1600, 187}),
    ({"liquid metal slime", "散失金属史莱姆", "Slime", 8, 255, 100, 256, 179, 40200, 40}),
    ({"moosifer", "高等恶魔", "Demon", 156, 18, 140, 155, 133, 1240, 152}),
    ({"drastic drackal", "地狱豺狼", "Beast", 225, 9, 165, 164, 124, 1380, 160}),
    ({"terrorhawk", "疯狂猎鹰", "Bird", 146, 10, 128, 160, 140, 1080, 132}),
    ({"cyclops", "独眼巨人", "Demon", 355, 8, 170, 150, 75, 1400, 84}),
    ({"cumulus rex", "云大王", "Elemental", 252, 18, 140, 151, 134, 1400, 144}),
    ({"bomboulder", "美伽查尔岩石", "Material", 146, 26, 78, 180, 100, 1300, 144}),
    ({"bagma", "熔岩枕魔", "Material", 120, 9, 120, 120, 120, 840, 102}),
    ({"golem", "巨像兵", "Material", 300, 0, 175, 210, 99, 1700, 174}),
    ({"seasaur", "海龙", "Aquatic", 304, 24, 180, 192, 101, 1900, 160}),
    ({"hell cumaulus", "热雾魔", "Elemental", 125, 11, 115, 145, 117, 960, 108}),
    ({"corrupt carter", "恶魔战车", "Humanoid", 155, 12, 138, 200, 147, 1550, 120}),
    ({"live lava", "岩浆人", "Elemental", 165, 24, 140, 186, 124, 1620, 110}),
    ({"mandrake marauder", "龙士兵", "Dragon", 172, 20, 132, 198, 144, 1760, 124}),
    ({"mega moai", "哥顿之首", "Material", 180, 0, 162, 235, 88, 2100, 144}),
    ({"magmalice", "熔岩魔神", "Elemental", 200, 18, 158, 225, 105, 2000, 160}),
    ({"green dragon", "绿龙", "Dragon", 245, 12, 178, 208, 109, 2200, 120}),
    ({"abyss diver", "地狱海龙", "Aquatic", 600, 28, 200, 220, 126, 2700, 92}),
    ({"stenchurion", "僵尸骑士", "Zombie", 160, 16, 148, 175, 136, 1380, 122}),
    ({"gloomy gastropog", "暗黑蜗牛", "Bug", 144, 70, 133, 210, 144, 1400, 118}),
    ({"dark skeleton", "影之骑士", "Zombie", 186, 17, 153, 194, 155, 1780, 162}),
    ({"killing machine", "杀人机器", "Machine", 182, 0, 155, 216, 164, 1880, 168}),
    ({"dreadful drackal", "恐怖野狗", "Beast", 240, 10, 170, 165, 143, 2000, 180}),
    ({"lethal armour", "杀人铠甲", "Material", 194, 16, 158, 210, 117, 1680, 164}),
    ({"freezing fog", "冰雾魔", "Elemental", 126, 10, 126, 156, 162, 1360, 120}),
    ({"stone guardian", "大魔神", "Material", 255, 0, 160, 255, 102, 2040, 182}),
    ({"boss troll", "绿巨魔", "Demon", 496, 10, 186, 86, 95, 2400, 98}),
    ({"blastoad", "加农王", "Beast", 356, 15, 163, 160, 101, 2100, 156}),
    ({"fright knight", "死灵骑士", "Zombie", 226, 33, 161, 206, 130, 2180, 180}),
    ({"wight king", "死灵之王", "Zombie", 186, 75, 143, 196, 149, 1680, 165}),
    ({"claws", "利爪杀手", "Humanoid", 206, 24, 153, 198, 178, 1980, 187}),
    ({"aggrosculpture", "狂风恶魔", "Demon", 220, 18, 150, 220, 153, 2280, 132}),
    ({"mandrake marshal", "跳跃者", "Dragon", 222, 24, 163, 212, 152, 2200, 140}),
    ({"bad karmour", "钢铁魔神", "Material", 188, 10, 161, 262, 98, 2280, 132}),
    ({"wyrtoise", "龙龟领主", "Dragon", 215, 8, 171, 240, 103, 2500, 188}),
    ({"king crab", "杀人蟹", "Aquatic", 270, 12, 181, 235, 158, 2800, 146}),
    ({"genie sanguini", "玛波蕾娜", "Demon", 155, 37, 89, 155, 162, 1260, 96}),
    ({"cumulus vex", "地狱魔云", "Elemental", 268, 40, 169, 246, 161, 2300, 178}),
    ({"red dragon", "红龙", "Dragon", 325, 9, 198, 230, 121, 3000, 98}),
    ({"gigantes", "远古巨人", "Demon", 640, 9, 212, 190, 115, 3200, 110}),
    ({"belisha beakon", "阿凯莱", "Bird", 136, 10, 146, 143, 167, 1460, 104}),
    ({"charmour", "魔铠甲", "Material", 220, 50, 171, 270, 134, 2450, 192}),
    ({"cureslime", "贝荷玛史莱姆", "Slime", 165, 120, 158, 172, 143, 1350, 167}),
    ({"great troll", "巨魔之王", "Demon", 768, 36, 220, 132, 107, 3800, 78}),
    ({"cobra cardinal", "地狱蛇法师", "Demon", 236, 90, 163, 198, 160, 2180, 184}),
    ({"prism peacock", "虹孔雀", "Bird", 246, 40, 171, 234, 177, 2300, 168}),
    ({"night knight", "死灵骑士王", "Zombie", 256, 48, 186, 225, 169, 2980, 182}),
    ({"drakulard", "绿巨龙", "Dragon", 520, 18, 203, 203, 112, 3450, 152}),
    ({"barbatos", "地狱管家", "Demon", 355, 30, 199, 255, 178, 3400, 187}),
    ({"firn fiend", "冰河魔神", "Elemental", 365, 0, 195, 268, 104, 3200, 172}),
    ({"sick trigertaur", "狮虎骑士", "Beast", 480, 32, 208, 222, 156, 3600, 195}),
    ({"cannibox", "食人箱", "Material", 187, 10, 140, 108, 140, 960, 210}),
    ({"mimic", "米米克", "Material", 627, 12, 256, 218, 173, 4120, 315}),
    ({"king cureslime", "贝荷玛珍史莱姆", "Slime", 256, 255, 216, 235, 101, 3030, 174}),
    ({"gem jamboree", "黄金史莱姆塔", "Slime", 5, 255, 208, 512, 296, 960, 1130}),
    ({"sluggerslaught", "终极舞蹈虫", "Bug", 468, 36, 324, 324, 246, 4600, 148}),
    ({"terror troll", "暗黑巨魔", "Demon", 1176, 40, 454, 263, 84, 4880, 58}),
    ({"cosmic chimaera", "星之奇美拉", "Bird", 516, 48, 378, 396, 275, 5200, 178}),
    ({"wishmaster", "吉力表卡拉", "Beast", 663, 255, 513, 563, 96, 5500, 75}),
    ({"cumulus hex", "地狱幻影", "Elemental", 796, 255, 462, 472, 282, 5850, 197}),
    ({"stale whale", "大王鲸", "Aquatic", 1244, 24, 584, 496, 106, 5700, 84}),
    ({"metal king slime", "金属史莱姆王", "Slime", 16, 0, 318, 512, 349, 120040, 80}),
    ({"slionheart", "神骑士", "Slime", 825, 72, 506, 512, 336, 6200, 184}),
    ({"godsteed", "传说角马", "Beast", 686, 20, 575, 566, 415, 6000, 172}),
    ({"wonder wyrtle", "传说龙龟", "Dragon", 1040, 0, 606, 720, 52, 6900, 98}),
    ({"death spider", "死亡毒蛛", "Bug", 955, 0, 595, 625, 302, 6800, 189}),
    ({"octagoon", "钢铁布鲁德加", "Beast", 522, 36, 420, 516, 129, 4620, 110}),
    ({"darkonium slime", "玛迪拉特史莱姆", "Slime", 420, 48, 400, 500, 403, 5880, 150}),
    ({"freaky tiki", "魔王的假面", "Material", 596, 21, 442, 498, 245, 5100, 158}),
    ({"alarmour", "撒旦铠甲", "Material", 454, 24, 454, 612, 109, 5200, 134}),
    ({"boa bishop", "深渊蛇魔", "Demon", 633, 136, 309, 296, 264, 4400, 168}),
    ({"cyber spider", "机械蜘蛛", "Bug", 596, 24, 478, 488, 255, 5800, 184}),
    ({"alphyn", "合成兽首领", "Beast", 1246, 135, 525, 556, 436, 6200, 195}),
    ({"gem slime", "黄金史莱姆王", "Slime", 20, 88, 455, 512, 456, 6000, 10080}),
    ({"au1000", "黄金机械兵", "Machine", 996, 0, 567, 798, 124, 6800, 216}),
    ({"void droid", "最终兵器", "Machine", 1325, 0, 575, 625, 348, 7800, 156}),
    ({"platinum king jewel", "白金史莱姆王", "Slime", 20, 20, 356, 546, 505, 240000, 1000}),
    ({"cannibelle", "地狱维纳斯", "Demon", 468, 90, 396, 396, 228, 4250, 156}),
    ({"grim reaper", "恶魔人偶", "Material", 596, 60, 476, 448, 383, 5000, 165}),
    ({"wight emperor", "死灵领主", "Zombie", 488, 120, 465, 455, 242, 5250, 185}),
    ({"grrrgoyle", "恐惧之兽", "Beast", 636, 60, 538, 598, 255, 5880, 170}),
    ({"pandora box", "潘多拉之盒", "Material", 868, 9, 623, 623, 407, 5990, 600}),
    ({"uncommon cold", "暴雪狂魔", "Elemental", 907, 28, 528, 487, 356, 6200, 104}),
    ({"geothaum", "暗黑魔神", "Elemental", 708, 0, 708, 668, 72, 6600, 86}),
    ({"blight knight", "英灵骑士", "Zombie", 965, 24, 695, 598, 298, 7000, 192}),
    ({"flamin drayman", "地狱车", "Humanoid", 480, 80, 416, 452, 229, 4700, 145}),
    ({"tantamount", "炼狱天马", "Beast", 1056, 60, 358, 388, 338, 4600, 167}),
    ({"barriearthenwarrior", "地底的守卫", "Material", 512, 18, 432, 596, 239, 5120, 176}),
    ({"bird of terrordise", "地狱魔鸟", "Bird", 648, 40, 514, 528, 285, 5560, 185}),
    ({"scarlet fever", "烈焰疯魔", "Elemental", 743, 28, 429, 478, 319, 5600, 115}),
    ({"hell gatekeeper", "地狱守卫", "Beast", 996, 26, 535, 645, 115, 6200, 95}),
    ({"rashaverak", "邪龙", "Dragon", 1124, 30, 707, 604, 98, 6600, 36}),
    ({"master moosifer", "死亡恺撒", "Demon", 1056, 40, 684, 648, 308, 7600, 175}),
    ({"vermil lion", "地狱鹤", "Beast", 1378, 36, 564, 626, 455, 8120, 200}),
    ({"slugly betsy", "海牛公主", "Demon", 1477, 120, 404, 236, 170, 5500, 158}),
    ({"moai minstrel", "王冠之兽", "Material", 518, 20, 368, 567, 206, 5880, 103}),
    ({"boogie manguini", "黄色撒旦", "Demon", 488, 20, 402, 478, 393, 5230, 149}),
    ({"mandrake monarch", "魔界战士", "Dragon", 735, 32, 486, 496, 250, 5000, 167}),
    ({"bling badger", "黄金狸", "Beast", 445, 80, 394, 495, 315, 5800, 196}),
    ({"prime slime", "迪迦", "Slime", 914, 24, 445, 375, 432, 5600, 178}),
    ({"hammer horror", "暗黑海鲨", "Aquatic", 874, 54, 586, 586, 375, 6400, 145}),
    ({"drakulord", "威龙", "Dragon", 1414, 255, 725, 404, 286, 6800, 65}),
    ({"pale whale", "海皇鲸", "Aquatic", 1456, 126, 748, 586, 79, 7500, 126}),
    ({"seavern", "海魔龙", "Aquatic", 1127, 64, 686, 546, 126, 7000, 87}),
    ({"hexagoon", "布鲁德加", "Beast", 93, 18, 30, 22, 11, 175, 100}),
    ({"wight knight", "迷之黑骑士", "Zombie", 296, 255, 53, 50, 45, 800, 200}),
    ({"morag", "妖女伊修达尔", "Demon", 456, 255, 56, 58, 54, 1600, 350}),
    ({"ragin contagion", "病魔帕恩迪姆", "Elemental", 696, 255, 68, 68, 50, 2295, 600}),
    ({"master jiadama", "魔神贾达玛", "BOSS", 796, 255, 80, 78, 56, 2904, 780}),
    ({"lleviathan", "海主大人", "Aquatic", 1256, 32, 110, 90, 36, 4134, 960}),
    ({"garth goyle", "石之守卫", "Material", 1054, 255, 120, 125, 66, 4134, 1250}),
    ({"tyrantula", "妖毒虫兹奥", "Bug", 1098, 36, 100, 154, 96, 5231, 1500}),
    ({"grand lizzier", "阿诺恩", "Dragon", 1276, 40, 200, 158, 85, 6200, 1750}),
    ({"larstastnaras", "咒幻师夏鲁玛纳", "Demon", 1562, 255, 140, 150, 95, 8200, 2000}),
    ({"dreadmaster", "魔教师艾鲁希昂", "Humanoid", 1680, 255, 160, 170, 125, 10000, 2550}),
    ({"gadrongo", "大怪像伽多恩格", "Beast", 2000, 255, 206, 214, 138, 12500, 3050}),
    ({"greygnarl", "格雷纳尔", "Dragon", 2280, 50, 188, 214, 145, 15500, 0}),
    ({"goreham hogg", "高雷昂将军", "Beast", 2470, 40, 196, 192, 130, 17500, 3550}),
    ({"hootingham gore", "格尔尼克将军", "Bird", 1854, 255, 125, 238, 148, 18500, 4050}),
    ({"goresby purrvis", "丘梅伊将军", "Beast", 2306, 25, 220, 256, 162, 20000, 4550}),
    ({"king godwyn", "暗黑皇帝伽纳撒旦", "BOSS", 1970, 255, 168, 266, 145, 0, 0}),
    ({"king godwyn", "暗黑皇帝伽纳撒旦", "BOSS", 3250, 255, 220, 266, 155, 26500, 6000}),
    ({"barbarus", "暗龙巴鲁波罗斯", "Dragon", 3098, 255, 238, 288, 160, 32500, 0}),
    ({"corvus", "堕天使艾尔基奥斯", "BOSS", 2790, 255, 214, 272, 167, 28500, 0}),
    ({"corvus", "堕天使艾尔基奥斯", "BOSS", 4800, 255, 248, 278, 157, 40000, 0}),
    ({"yore", "古代魔神", "BOSS", 4220, 255, 258, 328, 148, 36500, 4200}),
    ({"rover", "凶暴野兽", "Beast", 5000, 50, 325, 278, 152, 42500, 3750}),
    ({"king godfrey", "名字被剥夺的王", "BOSS", 4575, 255, 295, 300, 159, 42000, 4750}),
    ({"tyrannosaura wrecks", "费洛波希塔", "BOSS", 5000, 255, 285, 325, 163, 45550, 5000}),
    ({"nodoph", "阿鲁玛特拉", "Beast", 5600, 60, 352, 340, 185, 46800, 5120}),
    ({"equinox", "黑龙丸", "Beast", 1800, 255, 180, 180, 117, 10000, 825}),
    ({"nemean", "哈奴曼", "Beast", 2800, 255, 225, 240, 132, 15000, 967}),
    ({"shogum", "史莱姆将军", "Slime", 3600, 255, 242, 298, 130, 19000, 1110}),
    ({"trauminator", "终极杀人机器", "Machine", 4000, 255, 264, 354, 148, 25500, 1252}),
    ({"elusid", "伊迪阿拉贡", "Dragon", 4300, 255, 264, 338, 160, 25500, 1395}),
    ({"sir sanguinus", "鲜血骑士", "Zombie", 5200, 255, 319, 377, 182, 40000, 1537}),
    ({"atlas", "阿特拉斯", "Demon", 6500, 255, 462, 274, 163, 50000, 1680}),
    ({"hammibal", "怪力军曹伊波伊诺斯", "Beast", 6000, 100, 372, 442, 188, 60000, 1822}),
    ({"fowleye", "邪眼皇帝阿瓦特", "Bird", 5200, 255, 382, 418, 216, 65000, 1965}),
    ({"excalipurr", "魔神剑雷帕鲁德", "Beast", 6600, 255, 430, 430, 232, 70000, 2107}),
    ({"tyrannosaurus wrecks", "破坏神弗洛波斯", "BOSS", 7000, 255, 528, 452, 239, 75000, 2250}),
    ({"greygnarl", "格雷纳尔", "Dragon", 7400, 255, 478, 478, 252, 80000, 2392}),
    ({"dragonlord", "龙王", "BOSS", 7500, 255, 630, 450, 190, 63600, 2490}),
    ({"malroth", "希多", "BOSS", 7500, 255, 630, 480, 260, 64600, 2490}),
    ({"baramos", "巴拉摩斯", "BOSS", 6500, 255, 400, 400, 200, 59600, 2490}),
    ({"zoma", "佐玛", "BOSS", 8000, 255, 680, 570, 350, 70600, 2490}),
    ({"psaro", "死亡皮萨罗", "BOSS", 7500, 255, 640, 510, 280, 65600, 2490}),
    ({"estark", "艾斯塔克", "BOSS", 8000, 255, 710, 590, 320, 72600, 2490}),
    ({"nimzo", "米尔特兰斯", "BOSS", 7500, 255, 650, 520, 170, 66600, 2490}),
    ({"murdaw", "姆多", "BOSS", 6750, 255, 520, 415, 240, 60600, 2490}),
    ({"mortamor", "死亡塔姆亚", "BOSS", 6000, 255, 640, 520, 300, 67600, 2490}),
    ({"nokturnus", "暗黑多雷安", "BOSS", 8250, 255, 700, 610, 350, 74600, 2490}),
    ({"orgodemir", "欧鲁德米亚", "BOSS", 8000, 255, 660, 540, 260, 68600, 2490}),
    ({"dhoulmagus", "多鲁马古思", "BOSS", 7000, 255, 540, 430, 300, 61600, 2490}),
    ({"rhapthorne", "拉普索恩", "BOSS", 8500, 255, 670, 550, 230, 69600, 2490}),
});

void create()
{
    if (! restore() && ! mapp(mob_desc)){
        mob_desc = ([ ]);
    }
}

string query_save_file() { return DATA_DIR + "monster_d"; }

int limit(int index)
{
    if (index < 1 || index >= sizeof(mob_info))
        index = 1 + random(sizeof(mob_info) - 1);
    return index;
}

mixed info(int index)
{
    index = limit(index);
    return mob_info[index];
}

varargs string desc(string id, int raw)
{
    if (!raw && undefinedp(mob_desc[id]))
    {
        return "一只看起来很危险的魔物，当然，危险程度因人而异。";
    }

    return mob_desc[id];
}

int set_desc(string mob, string desc)
{
    if (!desc) return 0;

    mob_desc[mob] = desc;
    save();
    return 1;
}

int delete_desc(string mob)
{
    map_delete(mob_desc, mob);
    save();
    return 1;
}
