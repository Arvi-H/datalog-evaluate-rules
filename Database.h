#ifndef DATABASE
#define DATABASE

#include <map>
#include "Relation.h"
#include "Header.h"
#include "Tuple.h"

class Database {

    private:
        std::map<std::string, Relation> database;

    public:
        std::map<std::string, Relation> getDatabase() {
            return database;
        }

        Relation getRelation(std::string key) {
            return database.at(key);
        }

        Relation addRelation(std::string name, Header columnNames) {
            Relation newRelation(name, columnNames);
            
            database.insert({name, newRelation});

            return newRelation;
        }

        void addTuple(std::string key, Tuple tuple) {
            database.at(key).addTuple(tuple);
        }
};

#endif  