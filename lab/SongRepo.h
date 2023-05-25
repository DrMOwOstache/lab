#pragma once
#include "Song.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <qdebug.h>

class SongRepository
{
private:
	std::vector<Song> listOfSongs;
	std::string file;

public:

	SongRepository();
	SongRepository(std::string fileName);

	SongRepository(const SongRepository& other) = delete;
	SongRepository operator=(const SongRepository& other) = delete;

	//returns a vector of the songs 
	std::vector<Song> getSongs();

	//adds a new song to the repository
	bool addSong(Song newSong);

	//removes a song from a given position from the repository 
	bool removeSong(int position);

	//updates a song from a given position from the repository
	bool updateSong(int position, Song newSong);

	void updateFile();

	~SongRepository();

};