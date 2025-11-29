#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "GameRecord.h"
#include <vector>
#include <string>

// function that reads CSV file
namespace CSVParser {
    std::vector<GameRecord> loadCSV (const std::string& filename);
}

#endif