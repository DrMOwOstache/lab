#include "Song.h"

using namespace std;

Song::Song()
{
	title = "N/A";
	artist = "N/A";
	link = "N/A";
	std::tuple<int, int, int > duration = std::tuple<int, int, int >{ 0,0,0 };
}

Song::Song(std::string title = "N/A", std::string artist = "N/A", std::string link = "N/A", std::tuple<int, int, int > duration = std::tuple<int, int, int >{ 0,0,0 })
{
	this->title = title;
	this->artist = artist;
	this->link = link;
	this->duration = duration;
	if (get<2>(this->duration) >= 60)
	{
		get<1>(this->duration) =
	}
}

std::string Song::getTitle()
{
	return title;
}

std::string Song::getArtist()
{
	return artist;
}

std::string Song::getLink()
{
	return link;
}

std::tuple<int, int, int > Song::getDuration()
{
	return duration;
}