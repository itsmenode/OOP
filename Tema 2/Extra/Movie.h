#pragma once

#include <string>
#include <ctime>

class Movie {

    std::string name;
    int release_year;
    double imdb_score;
    int length;

public:
    Movie();

    void set_name(const std::string& movie_name);
    std::string get_name() const;

    void set_year(int year);
    int get_year() const;

    void set_score(double score);
    double get_score() const;

    void set_length(int minutes);
    int get_length() const;

    int get_passed_years() const;
};
