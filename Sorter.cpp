#include "Sorter.h"
#include <algorithm>

// main sort logic
void Sorter::sortByGenreThenSales(std:: vector<GameRecord>& records) {
    std::sort(records.begin(), records.end(),
    [](const GameRecord& a, const GameRecord& b) {
    
    // sorts by sale if in same genre

    if (a.genre == b.genre)
    return a.globalSales > b.globalSales;

    // otherwise sorts by genre
    
    return a.genre < b.genre;

        }
    );
}