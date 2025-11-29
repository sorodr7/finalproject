#include <iostream>
#include "CSVParser.h"
#include "Sorter.h"

// loads all game data from the CSV

int main() {
    std::string filename = "video games sales.csv";
    std::cout << "Loading CSV.\n";

    auto records = CSVParser::loadCSV(filename);

    if (records.empty()) {
    std::cout << "No records found.\n";
    return 1;

}

std::cout << "Sorting by Genre -> Global Sales.\n";

Sorter::sortByGenreThenSales(records);

std::cout << "Top 10 games after sorting:\n";
for (int i = 0; i < 10 && i < records.size(); i++) {
    std::cout << records[i].genre << " | "
              << records [i].globalSales << "M | "
              << records[i].name << "\n";

}

return 0;

}