#ifndef TREEMAP_H
#define TREEMAP_H

nomask mixed _set(mapping map, string *parts, mixed value);
nomask mixed _query(mapping map, string *parts);
nomask int _delete(mapping map, string *parts);

#endif
