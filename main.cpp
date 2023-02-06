//
// Created by Wyatt Chrisman on 2/3/23.
//

#include "Movie.h"
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    int randTime;

    // Read in all movies to vector
    string filename = "../movies.csv";
    vector<Movie> movies;
    getDataFromFile(filename,movies);

    // Get random number
    time_t present_time;
    present_time=time(NULL);
    randTime = (present_time*present_time)%100;

    cout << "Welcome to Random Movie Generator!" << endl;
    cout << "Press any key to generate a movie" << endl;




}
