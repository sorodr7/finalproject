#ifndef SORTER_H
#define SORTER_H

#include "GameRecord.h"
#include <vector>

namespace Sorter {

    // sorts by genre and then globally by sales
    void sortByGenreThenSales(std::vector<GameRecord>& records);

}

#endif