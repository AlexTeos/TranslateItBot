#ifndef USERSTORAGE_H
#define USERSTORAGE_H

#include "usercache.h"
#include "userstoragedb.h"

class UserStorage
{
public:
    UserStorage(const QString& path) : m_db(path){};

    User::SPtr findOrCreate(qint64 id);

private:
    UserCache     m_cache;
    UserStorageDB m_db;
};

#endif // USERSTORAGE_H
