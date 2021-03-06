/*
 *  Copyright 2016 Utkin Dmitry <loentar@gmail.com>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*
 *  This file is part of ngrest-db: http://github.com/loentar/ngrest-db
 */

#ifndef NGREST_MYSQLDB_H
#define NGREST_MYSQLDB_H

#include <ngrest/db/Db.h>

namespace ngrest {

struct MySqlDbSettings
{
    std::string db;
    std::string login;
    std::string password;
    std::string host;
    unsigned port;

    MySqlDbSettings(const std::string& db_, const std::string& login_, const std::string& password_,
                    const std::string& host_ = "localhost", unsigned port_ = 3306):
        db(db_),
        login(login_),
        password(password_),
        host(host_),
        port(port_)
    {
    }
};

class MySqlDbImpl;
class MySqlQueryImpl;

class MySqlDb: public Db
{
public:
    MySqlDb(const MySqlDbSettings& settings);
    ~MySqlDb();

    QueryImpl* newQuery() override;

    std::string getCreateTableQuery(const Entity& entity) const override;
    const std::string& getTypeName(Field::DataType type) const override;

private:
    MySqlDb(const MySqlDb&);
    MySqlDb& operator=(const MySqlDb&);
    MySqlDbImpl* impl;
    friend class MySqlQueryImpl;
};

} // namespace ngrest

#endif // NGREST_MYSQLDB_H
