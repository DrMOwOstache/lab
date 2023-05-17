#include "Song.h"

using namespace std;

Song::Song()
{
	title = "N/A";
	artist = "N/A";
	link = "N/A";
	tuple<int, int, int > duration = tuple<int, int, int >{ 0,0,0 };
}

Song::Song(string title, string artist, string link, tuple<int, int, int > duration)
{
	this->title = title;
	this->artist = artist;
	this->link = link;
	this->duration = duration;
	if (get<2>(this->duration) >= 60)
	{
		get<1>(this->duration) += get<2>(this->duration) / 60;
		get<2>(this->duration) %= 60;
	}
	if (get<1>(this->duration) >= 60)
	{
		get<0>(this->duration) += get<1>(this->duration) / 60;
		get<1>(this->duration) %= 60;
	}

}

string Song::getTitle()
{
	return title;
}

string Song::getArtist()
{
	return artist;
}

string Song::getLink()
{
	return link;
}

tuple<int, int, int > Song::getDuration()
{
	return duration;
}

void Song::setTitle(string title)
{
	this->title = title;
}

void Song::setArtist(string artist)
{
	this->artist = artist;
}

void Song::setLink(string link)
{
	this->link = link;
}

void Song::setDuration(tuple<int, int, int > duration)
{
	this->duration = duration;
	if (get<2>(this->duration) >= 60)
	{
		get<1>(this->duration) += get<2>(this->duration) / 60;
		get<2>(this->duration) %= 60;
	}
	if (get<1>(this->duration) >= 60)
	{
		get<0>(this->duration) += get<1>(this->duration) / 60;
		get<1>(this->duration) %= 60;
	}

}

bool Song::operator==(const Song& other)
{
	if (duration == other.duration && artist == other.artist && link == other.link && title == other.title)
		return true;
	return false;
}
