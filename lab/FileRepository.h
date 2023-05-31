#pragma once
#include "SongRepo.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <qdebug.h>
#include <algorithm>


class FileRepository : public SongRepository
{
	friend class SongRepository;
private:

	std::string file;

public:

	FileRepository(std::string fileName);

	void load();

	void save();

};