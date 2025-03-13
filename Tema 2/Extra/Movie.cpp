#include "Movie.h"
#include <ctime>

Movie::Movie() : release_year(0), imdb_score(1.0), length(0) {}

void Movie::set_name(const std::string& movie_name) {
    if (movie_name.length() <= 256)
        name = movie_name;
}

std::string Movie::get_name() const {
    return name;
}

void Movie::set_year(int year) {
    release_year = year;
}

int Movie::get_year() const {
    return release_year;
}

void Movie::set_score(double score) {
    if (score >= 1.0 && score <= 10.0)
        imdb_score = score;
}

double Movie::get_score() const {
    return imdb_score;
}

void Movie::set_length(int minutes) {
    length = minutes;
}

int Movie::get_length() const {
    return length;
}

int Movie::get_passed_years() const {
    time_t now = time(0);
    struct tm timeinfo;
    localtime_s(&timeinfo, &now);
    int current_year = 1900 + timeinfo.tm_year;
    return current_year - release_year;
}

