#ifndef RELATION
#define RELATION

#include <string>
#include <set>
#include <map>
#include <sstream>
#include "Header.h"
#include "Tuple.h"

class Relation {
    public: 
        Relation() = default;
        Relation(std::string name, Header columnNames) : name(name), columnNames(columnNames) {}

        // Getter functions
        Header getColumnNames();
        std::string getName();
        std::set<Tuple> getTuples();
        int getSetSize();

        // Setter Functions
        void addTuple(Tuple t);
        void setTuples(std::set<Tuple> tuples);
        std::string toString();

        // Relational Algebra
        Relation select(int columnIndex, std::string value);
        Relation select(int columnIndex1, int columnIndex2);
        Relation project(std::vector<int> columnsToProject);
        Relation rename(std::vector<std::string> newColumnNames);
        Relation join(Relation otherTable);

    private:
        std::string name;
        Header columnNames;
        std::set<Tuple> tuples;
};

#endif