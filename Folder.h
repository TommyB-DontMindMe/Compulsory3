#pragma once
#include <iostream>
#include "File.h"
using namespace std;

const int folderCap = 5;
const int fileCap = 10;

class Folder: public File
{
public:
	Folder();
	Folder(string iName, Folder *iParent);
	~Folder();
	string List();

	int GetSize();
	File GetLargest();
	Folder* GoTo(int index);

	void Add(File iFile);
	void Add(Folder *iFolder);


private:
	Folder* parent;
	Folder *folders[folderCap];
	File files[fileCap];

};

Folder::Folder() : File()
{
	parent == nullptr;
	for (size_t i = 0; i < folderCap; i++)
	{
		folders[i] = nullptr;
	}
	for (size_t i = 0; i < fileCap; i++)
	{
		files[i] = File();
	}
}

Folder::Folder(string iName, Folder *iParent) : File(iName, 0)
{
	parent = iParent;
	for (size_t i = 0; i < folderCap; i++)
	{
		folders[i] = nullptr;
	}
	for (size_t i = 0; i < fileCap; i++)
	{
		files[i] = File();
	}

}

Folder::~Folder()
{
}

string Folder::List()
{
	string output = File::List();
	for (size_t i = 0; i < folderCap; i++)
	{
		if (folders[i] != nullptr)
		{
			output += "\n- " + (*folders)[i].File::List();
		}
	}
	for (size_t i = 0; i < fileCap; i++)
	{
		if (files[i].GetSize() >= 0)
		{
			output += "\n- " + files[i].File::List();
		}
	}
	return output;
}

int Folder::GetSize()
{
	int iSize = 0;
	for (size_t i = 0; i < folderCap; i++)
	{
		if (folders[i] != nullptr)
		{
			iSize += (*folders)[i].GetSize();
		}
	}
	for (size_t i = 0; i < fileCap; i++)
	{
		if (files[i].GetSize() >= 0)
		{
			iSize += files[i].GetSize();
		}
	}
	return iSize;
}

File Folder::GetLargest()
{
	File output;
	int currentSize = 0;
	for (size_t i = 0; i < fileCap; i++)
	{
		if (files[i].GetSize() >= 0 && files[i].GetSize() > currentSize)
		{
			output = files[i];
			currentSize = files[i].GetSize();
		}
	}
	return output;
}

Folder* Folder::GoTo(int index)
{
	if (index == 0)
	{
		return parent;
	}
	if (1 <= index <= folderCap+1)
	{
		return folders[index - 1];
	}
	return nullptr;
}

void Folder::Add(File iFile)
{
	for (size_t i = 0; i < fileCap; i++)
	{
		if (files[i].GetSize() < 0)
		{
			files[i] = iFile;
			return;
		}
	}
}
void Folder::Add(Folder *iFolder)
{
	for (size_t i = 0; i < folderCap; i++)
	{
		if (folders[i] == nullptr)
		{
			folders[i] = iFolder;
			return;
		}
	}
}

