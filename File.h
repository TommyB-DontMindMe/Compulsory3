#pragma once
#include <chrono>
#include <format>
#include <string>
#include "Utils.h"
using namespace std;

class File
{
public:
	File();
	File(string iName);
	File(string iName, int iSize);
	~File();
	virtual string List();
	void Rename(string iName);
	virtual int GetSize();
	string GetName();
	virtual void menu();

protected:
	string name;
	int size;
	std::chrono::time_point<chrono::system_clock> origin;
};

File::File()
{
	name = "";
	size = -1;
	origin = chrono::system_clock().now() - chrono::system_clock().now().time_since_epoch();
}
File::File(string iName)
{
	name = iName;
	size = rand() % 101;
	origin = chrono::system_clock().now();
}
File::File(string iName, int iSize)
{
	name = iName;
	size = iSize;
	origin = chrono::system_clock().now();
}

File::~File()
{
}

inline string File::List()
{
	const std::chrono::zoned_time lTime{ std::chrono::current_zone(), origin };
	return (GetName() + "\t" + to_string(GetSize()) + " mb\t" + std::vformat("{:%F %R}", std::make_format_args(lTime)));
}

inline void File::Rename(string iName)
{
	name = iName;
}

int File::GetSize()
{
	return size;
}

string File::GetName()
{
	return name;
}

void File::menu()
{
	string options[] = { "Rename", "Delete" };
	switch (simpleMenu(options, 2))
	{
	case 0:

		break;
	case 1:
		break;
	default:
		break;
	}
}

