#include <iostream>
#include "CSVParser.h"
#include <vector>
#include <algorithm>
#include <unordered_map>

// structure to hold top game info

struct GameSummary {
    std::string name;
    std::string genre;
    float totalSales;
};


// loads all game data from the CSV

int main() {
    std::string filename = "video games sales.csv";
    std::cout << "Loading CSV.\n";

    auto records = CSVParser::loadCSV(filename);

    if (records.empty()) {
    std::cout << "No records found.\n";
    return 1;

}

// sales by game

std::unordered_map<std::string, float> gameSales;
std::unordered_map<std::string, std::string> gameToGenre;

// sales by genre

std::unordered_map<std::string, float> genreSales;

for (const auto& r : records) {
    gameSales[r.name] += r.globalSales;
    gameToGenre[r.name] = r.genre;
    genreSales[r.genre] += r.globalSales;
}

// AI helped in creating a sortable game vector

std::vector<GameSummary> gameList;
for (auto& p : gameSales) {
    gameList.push_back({
        p.first,
        gameToGenre[p.first],
        p.second
    });
}

// sort by total sales

std::sort(gameList.begin(), gameList.end(),
[](const GameSummary& a, const GameSummary& b) {
    return a.totalSales > b.totalSales;
});

// output top 10 game sales

std::cout << "\n----- TOP 10 GAMES (by global sales) -----\n";

for (int i= 0; i < 10 && i < gameList.size(); i++) {
    std::cout << i+1 << ". "
              << gameList[i].name
              << " | Genre: " << gameList[i].genre
              << " | Sales: " << gameList[i].totalSales << "M\n";
}


// sort genres

std::vector<std::pair<std::string, float>> genreList(
    genreSales.begin(), genreSales.end()
);

std::sort(genreList.begin(), genreList.end(),
    [](const auto& a, const auto& b) {
        return a.second > b.second;
});

// output top 5 genres

std::cout << "\n----- TOP 5 GENRES (by global sales) -----\n";

for (int i = 0; i < 5 && i < genreList.size(); i++) {
    std::cout << i+1 << ". "
              <<  genreList[i].first
              << " | Sales: " << genreList[i].second << "M\n";

    }
return 0;

}