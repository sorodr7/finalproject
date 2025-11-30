#include "CSVParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<GameRecord> CSVParser::loadCSV(const std::string& filename) {
    // storage for all parsed records
    std::vector<GameRecord> records; 
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return records;
    }

    std::string line;
    std::getline(file, line);

    int lineCount = 0; 

    while (std::getline(file, line)){
        std::stringstream ss(line);
        GameRecord record;  // constructs a new record

        // parses columns in Kaggle's order
        // Name,Platform,Year,Genre,Publisher,Sales
        // skips "rank" to properly organize columns
        
        std::string rank;
        std::getline(ss, rank, ',');
        std::getline(ss, record.name, ',');
        std::getline(ss, record.platform, ',');
        std::getline(ss,record.year, ',');
        std::getline(ss, record.genre, ',');
        std::getline(ss, record.publisher, ',');

        // skip NA/EU/JP/other sales (opted against using)

        std::string skip;
        for (int i = 0; i < 4; i++) {
            std::getline(ss, skip, ',');
        }

        // read global sales
        // AI advised in "try" syntax as rewrite to my original code

        std::string globalStr;
        std::getline(ss, globalStr, ',');

        try {
            record.globalSales = std::stof(globalStr);
        } catch (...) {
            record.globalSales = 0.0f;
        }

        records.push_back(record); // stores the data
        lineCount++;

        // notification for every 1000 records

        if (lineCount % 1000 == 0) {
            std::cout << "Processed " << lineCount << " records.\n";

        }
    }

    std::cout << "Finished parsing. Total records: " << records.size() << "\n";
    return records;

}