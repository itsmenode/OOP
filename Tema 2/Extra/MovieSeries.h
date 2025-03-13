#pragma once

#include "Movie.h"
#include <vector>

class MovieSeries {
    Movie* movies[16];
    int count;

public:
    MovieSeries();
    void init();
    void add(Movie* movie);
    void print() const;
    void sort();
};