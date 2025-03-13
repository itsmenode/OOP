#include "MovieComparison.h"

int movie_compare_name(const Movie& a, const Movie& b) {
    return a.get_name().compare(b.get_name());
}

int movie_compare_year(const Movie& a, const Movie& b) {
    return (a.get_year() < b.get_year()) ? -1 : (a.get_year() > b.get_year());
}

int movie_compare_score(const Movie& a, const Movie& b) {
    return (a.get_score() < b.get_score()) ? -1 : (a.get_score() > b.get_score());
}

int movie_compare_length(const Movie& a, const Movie& b) {
    return (a.get_length() < b.get_length()) ? -1 : (a.get_length() > b.get_length());
}

int movie_compare_passed_years(const Movie& a, const Movie& b) {
    return (a.get_passed_years() < b.get_passed_years()) ? -1 : (a.get_passed_years() > b.get_passed_years());
}
