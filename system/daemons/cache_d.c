/**
 * 玩家存档缓存接口
 * 缓存玩家数据到db.sqlite，方便网页、全服排行等调用
 */
#ifdef __USE_SQLITE3__
// 初始化数据库
mixed init_db();
// 玩家数据缓存接口
mixed insert(object user, int last_touched);
// 玩家数据更新接口
mixed update(object user);
// 玩家数据删除接口
mixed delete(object user);

nosave object db;

void create()
{
    db = new (CORE_DB, "", "/data/db.sqlite", "", __USE_SQLITE3__);
}

// todo 增加魔物数据统计
mixed init_db()
{
    mixed res;

    db->sql("DROP TABLE IF EXISTS `users`")->exec();
    res = db->sql("CREATE TABLE IF NOT EXISTS `users` (
        `id` VARCHAR(10) PRIMARY KEY NOT NULL,
        `name` VARCHAR(10) NOT NULL,
        `mobile` INTEGER DEFAULT NULL,
        `birthday` INTEGER DEFAULT NULL,
        `gender` VARCHAR(10) DEFAULT NULL,
        `title` VARCHAR(50) DEFAULT NULL,
        `vocation` VARCHAR(20) DEFAULT NULL,
        `lv` INTEGER DEFAULT NULL,
        `exp` INTEGER DEFAULT NULL,
        `coin` INTEGER DEFAULT NULL,
        `hp` INTEGER DEFAULT NULL,
        `mp` INTEGER DEFAULT NULL,
        `tower` INTEGER DEFAULT NULL,
        `kill` INTEGER DEFAULT NULL,
        `die` INTEGER DEFAULT NULL,
        `updated_at` INTEGER DEFAULT NULL) ")->exec();

    if (stringp(res))
    {
        env("CACHE_DATA", 0);
    }

    return res;
}

mixed insert(object user, int last_touched)
{
    mixed res;
    mapping my = user->query_entire_dbase();
    mapping combat_record = user->query_combat_records();
    int kill = 0, die = 0;

    if (mapp(combat_record))
    {
        kill = combat_record["kill"];
        die = combat_record["die"];
    }

    res = db->table("users")->insert(([
        "id"         : my["id"],
        "name"       : my["name"],
        "mobile"     : my["mobile"],
        "birthday"   : my["birthday"],
        "gender"     : my["gender"],
        "title"      : my["title"],
        "vocation"   : my["vocation"],
        "lv"         : my["lv"],
        "exp"        : my["exp"],
        "coin"       : my["coin"],
        "hp"         : my["attr"]["max_hp"],
        "mp"         : my["attr"]["map_mp"],
        "tower"      : my["tower"],
        "kill"       : kill,
        "die"        : die,
        "updated_at" : last_touched,
    ]));

    return res;
}

mixed update(object user)
{
    mixed res;
    mapping my = user->query_entire_dbase();
    mapping combat_record = user->query_combat_records();
    int kill = 0, die = 0;

    if (mapp(combat_record))
    {
        kill = combat_record["kill"];
        die = combat_record["die"];
    }

    res = db->table("users")->where("id", my["id"])->update(([
        "name"       : my["name"],
        "mobile"     : my["mobile"],
        "birthday"   : my["birthday"],
        "gender"     : my["gender"],
        "title"      : my["title"],
        "vocation"   : my["vocation"],
        "lv"         : my["lv"],
        "exp"        : my["exp"],
        "coin"       : my["coin"],
        "hp"         : my["attr"]["max_hp"],
        "mp"         : my["attr"]["map_mp"],
        "tower"      : my["tower"],
        "kill"       : kill,
        "die"        : die,
        "updated_at" : time(),
    ]));

    return res;
}

mixed delete(object user)
{
    mixed res;

    res = db->table("users")->where("id", user->query("id"))->delete ();

    return res;
}

varargs mixed get(string column, string order)
{
    mixed res;
    column = column || "exp";
    order = order || "desc";

    res = db->table("users")->orderBy(column, order)->get();

    return res;
}
#endif
