#include "Sorter.h"
#include <algorithm>

// AI advised in using this helper to convert strings to floats
static float safeToFloat(const std::string& s) {
    try {
        return std::stof(s);
    } catch (...) {
        return 0.0f;
    }
}

// main sort logic
void Sorter::sortByGenreThenSales(std:: vector<GameRecord>& records) {
    std::sort(records.begin(), records.end(),
    [](const GameRecord& a, const GameRecord& b) {
    
    // sorts by sale if in same genre

    if (a.genre == b.genre)
    return safeToFloat(a.globalSales) > safeToFloat(b.globalSales);

    // otherwise sorts by genre
    
    return a.genre < b.genre;

        }
    );
}