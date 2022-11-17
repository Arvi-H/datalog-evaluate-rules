#include "Relation.h"

// Helper Functions
std::string Relation::getName() {
    return Relation::name;
}

Header Relation::getColumnNames() {
    return Relation::columnNames;
}

std::set<Tuple> Relation::getTuples() {
    return Relation::tuples;
}

int Relation::getSetSize() {
    return tuples.size();
}

void Relation::addTuple(Tuple t) {
    Relation::tuples.insert(t);
}

void Relation::setTuples(std::set<Tuple> tuples) {
    this->tuples = tuples;
}

std::string Relation::toString() {
    std::stringstream out;
    for (Tuple t : Relation::tuples) {
        if (t.getTupleSize() > 0) {
            out << " " << t.toString(Relation::columnNames) << std::endl;
        }
    }
    
    return out.str();
}

// Relational Algebra
Relation Relation::select(int columnIndex, std::string value) {
    Relation newRelation(Relation::name, Relation::columnNames);

    for (Tuple tuple : tuples) {
        if (tuple.findValue(columnIndex) == value) {
            newRelation.addTuple(tuple);
        }
    }

    return newRelation;
}

Relation Relation::select(int columnIndex1, int columnIndex2) {
    Relation newRelation(Relation::name, Relation::columnNames);

    for (Tuple tuple : tuples) {
        if (tuple.findValue(columnIndex1) == tuple.findValue(columnIndex2)) {
            newRelation.addTuple(tuple);
        }
    }

    return newRelation;
}

Relation Relation::project(std::vector<int> columnsToProject) {
    Header newHeader;

    // Update columnNames with the selcted columns (passed in the function)
    for (auto i : columnsToProject) {
        newHeader.addAttribute(Relation::columnNames.findAttribute(i));
    }
    
    Relation newRelation(Relation::name, newHeader);  

    // Update rows at the selcted columns (passed in the function)
    for (auto tuple : tuples) {
        Tuple newTuple;

        for (auto i : columnsToProject) {
            newTuple.addValue(tuple.findValue(i));
        }

        newRelation.addTuple(newTuple);
    }

    return newRelation;
}

Relation Relation::rename(std::vector<std::string> newColumnNames) { 
    Header columnNames(newColumnNames);
    
    Relation newRelation(Relation::name, columnNames);
    newRelation.setTuples(tuples);
    
    return newRelation;
}

Header Relation::joinColumns(Relation table1, Relation table2, std::map<int, int> repeatedColumns, std::set<int> uniqueColumns) {
    Header table1_columnNames = table1.getColumnNames();
    Header table2_columnNames = table2.getColumnNames();
    Header combinedColumns;

    // Loop through table 2 column names
    for (unsigned int i = 0; i < table2_columnNames.getHeaderSize(); i++) {
        // Repeated column flag
        bool repeated = false;
        
        // Loop through table 1 column names
        for (unsigned int j = 0; j < table1_columnNames.getHeaderSize(); j++) {
        
            // If they match, add indexes to our map of repeated columns
            if (table1_columnNames.findAttribute(j) == table2_columnNames.findAttribute(i)) {
                repeated = true;
                repeatedColumns.insert({j, i});
            } 
        }

        // If they don't match, add to our unique list
        if (!repeated) { uniqueColumns.insert(i); }
    }

    // Combine column names of table 1 and table 2

    // Set combined column names to the table 1 column names 
    combinedColumns = table1_columnNames;
    
    // Add the unique columns found in table 2 to the combined column names
    for (int i : uniqueColumns) {
        combinedColumns.addAttribute(table2_columnNames.findAttribute(i));
    }

    return combinedColumns;
}

void Relation::joinRows(Relation table1, Relation table2, Relation combinedTable, std::map<int, int> repeatedColumns, std::set<int> uniqueColumns) {
    Tuple combinedRows;

    // Loop through table 1 rows
    for (Tuple table1_row : table1.getTuples()) {

        // Loop through table 2 rows
        for (Tuple table2_row : table2.getTuples()) {

            // Search through the repeated columns key and values
            for (const auto &pair : repeatedColumns) {
                
                // Row contents of both tables at that column
                std::string rowAtKey = table1_row.findValue(pair.first);
                std::string rowAtValue = table2_row.findValue(pair.first);
                
                // If the row contents are the same
                if (rowAtKey == rowAtValue) {
                    // Set combined row names to the table 1 row names 
                    combinedRows = table1_row;

                    // Add the unique rows found in table 2 to the combined row names
                    for (int i : uniqueColumns) {
                        combinedRows.addValue(table2_row.findValue(i));
                    }
                    
                    // Add combined rows to our new table
                    combinedTable.addTuple(combinedRows);
                }
            }
        }
    }
}

Relation Relation::join(Relation otherTable) {
    Relation table1 = *this;
    Relation table2 = otherTable;

    std::map<int, int> repeatedColumns;
    std::set<int> uniqueColumns;

    // Create a new table with the combined table1 and table2 column names 
    Relation combinedTable(table1.getName() + " |x| " + table2.getName(), joinColumns(table1, table2, repeatedColumns, uniqueColumns));

    // Add the row contents to our new combined table 
    joinRows(table1, table2, combinedTable, repeatedColumns, uniqueColumns);

    return combinedTable;
}
 
