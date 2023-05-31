#include "FileRepository.h"

using namespace std;

FileRepository::FileRepository(std::string fileName)
{
}

void FileRepository::load()
{
}

void FileRepository::save()
{
	fstream newFile;
	string tempFile("new" + file);
	newFile.open(tempFile);

	for (int i = 0; i < SongRepository::listOfSongs.size(); i++)
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
