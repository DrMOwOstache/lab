#pragma once
#include <string>
#include <tuple>

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

	std::string getTitle();
	std::string getArtist();
	std::string getLink();
	std::tuple<int, int, int > getDuration();

	void setTitle(std::string title);
	void setArtist(std::string artist);
	void setLink(std::string link);
	void setDuration(std::tuple<int, int, int > duration);

	bool operator==(const Song& other);

	~Song() = default;
};
