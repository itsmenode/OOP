#include "MovieSeries.h"
#include <iostream>
#include <algorithm>

MovieSeries::MovieSeries() : count(0) {}

void MovieSeries::init() {
    count = 0;
}

void MovieSeries::add(Movie* movie) {
    if (count < 16) {
        movies[count++] = movie;
    }
}

void MovieSeries::print() const {
    for (int i = 0; i < count; ++i) {
        std::cout << movies[i]->get_name() << " (" << movies[i]->get_year() << ") - " << movies[i]->get_score() << " IMDB - " << movies[i]->get_length() << " min - " << movies[i]->get_passed_years() << " years ago\n";
    }
}

void MovieSeries::sort() {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (movies[j]->get_passed_years() < movies[j + 1]->get_passed_years()) {
                Movie* temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}
