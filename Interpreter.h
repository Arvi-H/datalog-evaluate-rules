#ifndef INTERPRETER
#define INTERPRETER

#include <set>
#include <map>
#include <vector>
#include "DatalogProgram.h"
#include "Database.h"
#include "Relation.h"

class Interpreter {
public:
    Interpreter(DatalogProgram program) : program(program) {}

// Run Interpreter
    void start() {
        interpretSchemes();
        interpretFacts();
        interpretRules(); 
        interpretQueries();
    }

    void interpretSchemes() {
        for (Predicate scheme : program.getSchemes()) {
            Header header;
            
            for (Parameter p : scheme.getParameters()) {
                header.addAttribute(p.getID());
            }
            
            database.addRelation(scheme.getID(), header);
        }   
    }

    void interpretFacts() {
        for (Predicate fact : program.getFacts()) {
            Tuple tuple;
            
            for (Parameter p : fact.getParameters()) {
                tuple.addValue(p.getID());
            }
            
            database.addTuple(fact.getID(), tuple);
        }
    }

    void interpretRules() {
        std::cout << "Rule Evaluation" << std::endl;

        /** Each predicate should produce a single relation. If there are n predicates on the right-hand side of a rule, there should be n relations. These relations will be joined in step 2. */ 
        std::vector<Relation> relationsToJoin;
        
        unsigned int repeatedAlgCount = 0;
        bool repeatAlg = true;

        while (repeatAlg) {
            
            // Don't repeat again unless we have to
            repeatAlg = false;

            // Evaluate every rule
            for (Rule rule : program.getRules()) { 
                // STEP 1 : Evaluate each rule using the select, project, and rename relational alegbra operations
                for (Predicate p : rule.getPredicates()) {
                    relationsToJoin.push_back(evaluatePredicate(p));
                }   

                // STEP 2 : Join the relations from STEP 1
                Relation combinedRelation = relationsToJoin.at(0);

                for (int i = 1; i < relationsToJoin.size(); i++) {
                    combinedRelation = combinedRelation.join(combinedRelation);
                } 

                // STEP 3 : Project the columns that appear in the head predicate 
                Predicate headPredicate;
                std::vector<int> columnsToProject; 

                for (Parameter p : rule.getID().getParameters()) {
                    // Columns of the combined table
                    Header combinedRelationColumns = combinedRelation.getColumnNames();

                    // Columns in the combined table with the same parameters as head predicate 
                    int columnMatch = combinedRelationColumns.findColumn(p.getID());
                    
                    columnsToProject.push_back(columnMatch);
                }

                // Call project on the combined table for the columns that matched
                combinedRelation = combinedRelation.project(columnsToProject);

                // STEP 4 : Rename the relation to help with STEP 5
                combinedRelation = combinedRelation.rename(database.getRelation(rule.getID().getID()).getColumnNames().getAttributes());
                
                std::cout << rule.toString() << "." << std::endl;

                // STEP 5 : Union combinedRelation with the relation in the database whose name matches the name of the head of the rule.
                
                // Relation in the database whose name matches the name of the head of the rule.
                Relation dbRelation = database.getRelation(rule.getID().getID());

                for (Tuple t : combinedRelation.getTuples()) {
                    if (database.addTuple(rule.getID().getID(), t)) {
                        std::cout << " " << t.toString(dbRelation.getColumnNames()) << std::endl;
                        repeatAlg = true;
                    }
                }
            }
            repeatedAlgCount++;
        }

        std::cout << std::endl << "Schemes populated after " << repeatedAlgCount << " passes through the Rules." << std::endl << std::endl;
    }

    void interpretQueries() {
        std::cout << "Query Evaluation" << std::endl;

        for (Predicate query : program.getQueries()) {
            std::cout << query.toString() << "?";
            Relation result = evaluatePredicate(query);
            if (result.getSetSize() == 0) {
                std::cout << " " << "No" << std::endl;
            } else {
                std::cout << " " << "Yes(" << result.getSetSize() << ")" << std::endl;
            }

            std::cout << result.toString();
        }
    }

    Relation evaluatePredicate(Predicate predicate) {
        Relation output = database.getRelation(predicate.getID());
        std::map<std::string, unsigned int> seen;
        std::vector<int> uniqueIndex;
        std::vector<std::string> uniqueValues;
        unsigned int col = 0;

        for (Parameter parameter : predicate.getParameters()) {
            std::string val = parameter.getID();
            
            if (parameter.isConstant()) {
                output = output.select(col, parameter.getID());    // select type 1 (int, value)
            } else {
                // if not seen before
                if (seen.find(val) != seen.end()) {
                    output = output.select(col, seen.at(val));   // select type 2 (int, int)
                // mark it as seen
                } else {  
                    seen.insert({val, col});
                    uniqueIndex.push_back(col);
                    uniqueValues.push_back(val);
                }
            }
            col++;
        }

        // project
        output = output.project(uniqueIndex);

        // rename
        output = output.rename(uniqueValues);

        return output;
    }

private:
    DatalogProgram program;
    Database database;
};

#endif