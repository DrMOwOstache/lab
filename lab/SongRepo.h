#pragma once
#include "Song.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <qdebug.h>
#include <algorithm>

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
	bool addSong(Song newSong, bool justAdd = false);

	//removes a song from a given position from the repository 
	bool removeSong(int position);

	void remove(const Song& s);

	//updates a song from a given position from the repository
	bool updateSong(int position, Song newSong);

	void updateFile();

	void store(const Song& s);

	const Song& find(std::string title, std::string artist);

	~SongRepository();

};