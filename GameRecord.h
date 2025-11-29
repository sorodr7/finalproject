#ifndef GAMERECORD_H
#define GAMERECORD_H

#include <string>

// this struct holds a game's data
struct GameRecord {
    std::string name;
    std::string platform;
    std::string year;
    std::string genre;
    std::string publisher;
    std::string globalSales;
};

#endif