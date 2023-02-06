//
// Created by Wyatt Chrisman on 2/3/23.
//

#include "Movie.h"
#include <vector>

using namespace std;

int main()
{
    // Read in all movies to vector
    string filename = "../movies.csv";
    vector<Movie> movies;
    getDataFromFile(filename,movies);

//    for(int i = 0; i < 99; ++i){
//        cout << movies[i].getTitle() << endl;
//    }

    cout << movies[1] << endl;
}
