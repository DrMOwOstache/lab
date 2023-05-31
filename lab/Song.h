#pragma once
#include <string>
#include <tuple>
#include <exception>

class Song
{
private:
	std::string title;
	std::string artist;
	std::string link;
	std::tuple<int, int, int > duration;

public:
	Song();
	Song(std::string title = "N/A", std::string artist = "N/A", std::string link = "N/A", std::tuple<int, int, int > duration = std::tuple<int, int, int >{ 0,0,0 });

	bool operator==(const Song& other);

	std::string getTitle();
	std::string getArtist();
	std::string getLink();
	std::tuple<int, int, int > getDuration();

	void setTitle(std::string title);
	void setArtist(std::string artist);
	void setLink(std::string link);
	void setDuration(std::tuple<int, int, int > duration);

	~Song() = default;
};

class SongException : public std::exception
{
	friend class Song;
private:
	std::string errorMass;

public:
	
	SongException(std::string massegePromt);

	_NODISCARD char const* what() const override;

};
