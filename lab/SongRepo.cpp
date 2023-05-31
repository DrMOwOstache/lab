#include "SongRepo.h"


using namespace std;

SongRepository::SongRepository()
{
	string lineread, title, artist, link, hour, minute, second,aux;
	this->file = "default_songs.csv";
	ifstream openedFile(file);
	if (openedFile.peek() != std::ifstream::traits_type::eof())
	{
		getline(openedFile, aux);
		openedFile.close();
	}
	if (aux != "\0")
	{
		openedFile.open(file);
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
				getline(s, aux, '\n');

				qDebug() << "here";
				listOfSongs.push_back(Song(title, artist, link, tuple<int, int, int >{stoi(hour), stoi(minute), stoi(second)}));
			}
	}

	openedFile.close();
}

SongRepository::SongRepository(string fileName)
{
	string lineread, title, artist, link, hour, minute, second, aux;
	this->file = fileName;
	ifstream openedFile(file);

	if (openedFile.peek() != std::ifstream::traits_type::eof())
	{
		getline(openedFile, aux);
		openedFile.close();
	}
	if (aux != "\0")
	{
		openedFile.open(file);
		if (openedFile.peek() != std::ifstream::traits_type::eof())
		{
			while (!openedFile.eof())
			{
				getline(openedFile, lineread);
				stringstream s(lineread);
				qDebug() << lineread;
				getline(s, artist, ',');
				getline(s, title, ',');
				getline(s, link, ',');
				getline(s, hour, ',');
				getline(s, minute, ',');
				getline(s, second, ',');
				getline(s, aux, '\n');

				qDebug() << artist << ' ' << title << ' ' << link << hour << ':' << minute << ':' << second;
				listOfSongs.push_back(Song(title, artist, link, tuple<int, int, int >{stoi(hour), stoi(minute), stoi(second)}));
				if (openedFile.eof())
					break;
			}
		}
	}

	openedFile.close();
}

std::vector<Song> SongRepository::getSongs()
{
	return this->listOfSongs;
}

bool SongRepository::addSong(Song newSong, bool justAdd)
{
	if (justAdd == false)
	{
		for (int i = 0; i < listOfSongs.size(); i++)
			if (listOfSongs[i] == newSong)
				return false;
	}
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

void SongRepository::remove(const Song& s)
{
	auto temp = listOfSongs.erase(std::find(listOfSongs.begin(), listOfSongs.end(), s));
	
	if (temp == listOfSongs.end())
	{
		Song aux = s;
		throw SongException("A song " + aux.getTitle() + " by " + aux.getArtist() + " does not exist");
	}
}

bool SongRepository::updateSong(int position, Song newSong)
{
	return true;
}

void SongRepository::updateFile()
{
	fstream newFile;
	newFile.open(file);

	for (int i = 0; i < listOfSongs.size(); i++)
	{
		newFile << listOfSongs[i].getArtist() << ',';
		newFile << listOfSongs[i].getTitle() << ',';
		newFile << listOfSongs[i].getLink() << ',';
		newFile << get<0>(listOfSongs[i].getDuration()) << ',' << get<1>(listOfSongs[i].getDuration()) << ',' << get<2>(listOfSongs[i].getDuration()) << ',';
		if (i < listOfSongs.size() - 1)
			newFile << '\n';
	}

	newFile.close();
}

void SongRepository::store(const Song& s)
{
	for (int i = 0; i < listOfSongs.size(); i++)
		if (listOfSongs[i] == s)
			throw SongException("A song " + listOfSongs[i].getTitle() + " by " + listOfSongs[i].getArtist() + " already exists");
	
	listOfSongs.push_back(s);
}

const Song& SongRepository::find(std::string title, std::string artist)
{
	/*auto findItem = std::find(listOfSongs.begin(), listOfSongs.end(), [title, artist](std::string t, std::string a) {return (t == title && a == artist); });

	if(findItem == listOfSongs.end())
		throw SongException("A song " + title + " by " + artist + " does not exist");
	return *findItem;*/
	Song* aux;
	return *aux;
}

SongRepository::~SongRepository()
{
	updateFile();
}
