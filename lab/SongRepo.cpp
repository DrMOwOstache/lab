#include "SongRepo.h"


using namespace std;

SongRepository::SongRepository()
{
	string lineread, title, artist, link, hour, minute, second;
	this->file = "default_songs.csv";
	ifstream openedFile(file);

	if (openedFile.peek() != std::ifstream::traits_type::eof())
		while (!openedFile.eof())
		{
			getline(openedFile, lineread);
			stringstream s(lineread);
			getline(s, artist, ',');
			getline(s, title, ',');
			getline(s, link, ',');
			getline(s, hour, ',');
			getline(s, minute, ',');
			getline(s, second, ',');

			qDebug() << "here";
			listOfSongs.push_back(Song(artist, title, link, tuple<int, int, int >{stoi(hour), stoi(minute), stoi(second)}));
		}

	openedFile.close();
}

SongRepository::SongRepository(string fileName)
{
	string lineread, title, artist, link, hour, minute, second;
	this->file = fileName;
	ifstream openedFile(file);

	if (openedFile.peek() != std::ifstream::traits_type::eof())
		while (!openedFile.eof())
		{
			getline(openedFile, lineread);
			stringstream s(lineread);
			getline(s, artist, ',');
			getline(s, title, ',');
			getline(s, link, ',');
			getline(s, hour, ',');
			getline(s, minute, ',');
			getline(s, second, ',');

			listOfSongs.push_back(Song(artist, title, link, tuple<int, int, int >{stoi(hour), stoi(minute), stoi(second)}));
		}

	openedFile.close();
}

std::vector<Song> SongRepository::getSongs()
{
	return this->listOfSongs;
}

bool SongRepository::addSong(Song newSong)
{
	for (int i = 0; i < listOfSongs.size(); i++)
		if (listOfSongs[i] == newSong)
			return false;
	listOfSongs.push_back(newSong);
	return true;
}

bool SongRepository::removeSong(int position)
{
	if (position <0 || position>listOfSongs.size())
		return false;
	listOfSongs.erase(std::find(listOfSongs.begin(), listOfSongs.end(), listOfSongs[position]));
	return true;
}

bool SongRepository::updateSong(int position, Song newSong)
{
	return true;
}

void SongRepository::updateFile()
{
	fstream newFile;
	string tempFile("new" + file);
	newFile.open(tempFile);

	for (int i = 0; i < listOfSongs.size(); i++)
	{
		newFile << listOfSongs[i].getArtist() << ',';
		newFile << listOfSongs[i].getTitle() << ',';
		newFile << listOfSongs[i].getLink() << ',';
		newFile << get<0>(listOfSongs[i].getDuration()) << ',' << get<1>(listOfSongs[i].getDuration()) << ',' << get<2>(listOfSongs[i].getDuration()) << ',';
	}

	newFile.close();
	remove(file.c_str());
	rename(tempFile.c_str(), file.c_str());
}

SongRepository::~SongRepository()
{
	fstream newFile;
	string tempFile("new" + file);
	newFile.open(tempFile);

	for (int i = 0; i < listOfSongs.size(); i++)
	{
		newFile << listOfSongs[i].getArtist() << ',';
		newFile << listOfSongs[i].getTitle() << ',';
		newFile << listOfSongs[i].getLink() << ',';
		newFile << get<0>(listOfSongs[i].getDuration()) << ',' << get<1>(listOfSongs[i].getDuration()) <<','<< get<2>(listOfSongs[i].getDuration()) <<',';
	}

	newFile.close();
	remove(file.c_str());
	rename(tempFile.c_str(), file.c_str());
}
