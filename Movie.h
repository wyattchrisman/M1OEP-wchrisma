//
// Created by Wyatt Chrisman on 2/5/23.
//

#ifndef M1OEP_WCHRISMA_MOVIE_H
#define M1OEP_WCHRISMA_MOVIE_H


#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

class Movie{

private:

    // Create all needed variables
    string title;
    int year;
    string genre;
    int length;
    string director;
    string actor;
    string description;

public:
    Movie()
    {
        // Set all variables to impossible outputs
        title = "XXX";
        year = -1;
        genre = "XXX";
        length = -1;
        director = "XXX";
        actor = "XXX";
        description = "XXX";
    }

    Movie(string title, int year, string genre, int length,
          string director, string actor, string description)
    {
        // Take in all movie attributes
        this->title = title;
        this->year = year;
        this->genre = genre;
        this->length = length;
        this->director = director;
        this->actor = actor;
        this->description = description;
    }

    string getTitle() const
    {
        return title;
    }

    void setTitle(string title)
    {
        this->title = title;
    }

    int getYear() const
    {
        return year;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    string getGenre () const
    {
        return genre;
    }

    void setGenre(string genre)
    {
        this->genre = genre;
    }

    int getLength() const
    {
        return length;
    }

    void setLength(int length)
    {
        this->length = length;
    }

    string getDirector() const
    {
        return director;
    }

    void setDirector(string director)
    {
        this->director = director;
    }

    string getActor() const
    {
        return actor;
    }

    void setActor(string actor)
    {
        this->actor = actor;
    }

    string getDescription() const
    {
        return description;
    }

    void setDescription(string description)
    {
        this->description = description;
    }


    friend ostream& operator << (ostream& outs, const Movie& mov)
    {
        outs << "Title: " << left << setw(25) << mov.getTitle();
        outs << endl;
        outs << "Release Year: " << left << setw(5) << mov.getYear();
        outs << endl;
        outs << "Genre(s): " << left << setw(26) << mov.getGenre();
        outs << endl;
        outs << "Length (in minutes): " << left << setw(3) << mov.getLength();
        outs << endl;
        outs << "Director(s): " << left << setw(33) << mov.getDirector();
        outs << endl;
        outs << "Actors: " << left << setw(200) << mov.getActor();
        outs << endl;
        outs << "Synopsis: " << left << setw(400) << mov.getDescription();

        return outs;
    }
};

void getDataFromFile(string filename, vector<Movie>& movies)
{
    // open file
    ifstream inFile;
    inFile.open(filename);

    // get header
    string header;
    if(inFile)
    {
        getline(inFile, header);
    }
    else
    {
        cout << "File could not be opened" << endl;
    }

    // set variables to impossible values
    string title = "XXX", description = "XXX";
    int year = -1, length = -1;
    string genre = "XXX", director= "XXX", actor = "XXX";

    char comma, quote;

    while(inFile && inFile.peek() != EOF)
    {
        if(inFile.peek() == '"')
        {
            inFile >> quote;
            getline(inFile, title, '"');
            inFile >> comma;
        }
        else
        {
            getline(inFile, title, ',');
        }

        inFile >> year;
        inFile >> comma;

        if(inFile.peek() == '"')
        {
            inFile >> quote;
            getline(inFile, genre, '"');
            inFile >> comma;

        }
        else
        {
            getline(inFile, genre, ',');
        }

        inFile >> length;
        inFile >> comma;

        if(inFile.peek() == '"')
        {
            inFile >> quote;
            getline(inFile, director, '"');
            inFile >> comma;

        }
        else
        {
            getline(inFile, director, ',');
        }

        if(inFile.peek() == '"')
        {
            inFile >> quote;
            getline(inFile, actor, '"');
            inFile >> comma;

        }
        else
        {
            getline(inFile, actor, ',');
        }

        if(inFile.peek() == '"')
        {
            inFile >> quote;
            getline(inFile, description, '"');
            inFile >> comma;

        }
        else
        {
            getline(inFile, description, ',');
        }

        movies.push_back(Movie(title, year, genre, length, director, actor, description));
    }
    inFile.close();
}






#endif //M1OEP_WCHRISMA_MOVIE_H

