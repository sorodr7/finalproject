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

        // parses columns into struct fields

        std::getline(ss, record.name, ',');
        std::getline(ss, record.platform, 'n');
        std::getline(ss,record.year, ',');
        std::getline(ss, record.genre, ',');
        std::getline(ss, record.publisher, ',');
        std::getline(ss, record.globalSales, ',');

        records.push_back(record); // stores the data
        lineCount++;

        // notification for every 10000 records

        if (lineCount % 10000 == 0) {
            std::cout << "Processed " << lineCount << " records.\n";

        }
    }

    std::cout << "Finished parsing. Total records: " << records.size() << "\n";
    return records;

}