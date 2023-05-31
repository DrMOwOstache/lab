#pragma once
#include "Song.h"
#include "SongRepo.h"

class Controller
{
	friend class Song;
	friend class SongRepository;

private:
	SongRepository lSong{ "listSongs.csv" };
	SongRepository playLSong{ "playlistSongs.csv" };

public:
	SongRepository getListSongs(int whichOne);

};
