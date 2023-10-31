#include <iostream>
#include <chrono>
#include "File.h"
#include "Folder.h"
using namespace std;

// Current folder List()
// List options 
// [Go to parent folder, Go to folder [n], Go to file [n]]
//		File [Rename, Delete]
//		Folder [Create Folder, Create File, Get Largest, ]
const int systemSize = 20;
Folder systemSpace[systemSize];

void NewFolder(string iname, Folder *parent)
{
	for (size_t i = 0; i < systemSize; i++)
	{
		if (systemSpace[i].GetName() == "")
		{
			systemSpace[i] = Folder(iname, parent);
			parent->Add(&(systemSpace[i]));
			return;
		}
	}
}


int main()
{
	randSeed();

	systemSpace[0] = Folder("root", nullptr);
	Folder* currentFolder = &systemSpace[0];


	Folder* thingy = &systemSpace[0];


	File *stuff = &systemSpace[0];
	systemSpace[1] = Folder("Folder1", currentFolder);
	systemSpace[1].Add(File("AlsoAFile"));
	File file1 = File("File1");
	File file2 = File("File2");
	systemSpace[0].Add(&systemSpace[1]);
	systemSpace[0].Add(file1);
	systemSpace[0].Add(file2);

	NewFolder("Folder3", thingy);

	cout << (*stuff).List() << endl;
	cout << systemSpace[0].GetLargest().List();
	(systemSpace[0].GoTo(1))->Add(File("File3"));
	//string moo[] = {"hi", "stuffs", "poyo", "cow", "bleh"};
	//cout << to_string(simpleMenu(moo, sizeof(moo)/sizeof(moo[0])));
	return 0;
}