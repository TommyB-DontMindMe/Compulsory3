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
Folder* FolderSearch(string iName)
{
	for (size_t i = 0; i < systemSize; i++)
	{
		if (systemSpace[i].GetName() == iName);
		{
			return &systemSpace[i];
		}
	}
	return nullptr;
}
Folder *FolderMoveMenu(Folder *subject)
{
	if (subject->GetFolder(0) != nullptr)
	{
		cout << "0. " + subject->GetFolder(0)->GetName() << " (Parent)" << endl;

	}
	int validAddress = 0;
	for (size_t i = 0; i < folderCap; i++)
	{
		if (subject->GetFolder(i+1) != nullptr)
		{
			cout << i+1 << ". " + subject->GetFolder(i+1)->GetName() << endl;
			validAddress++;
		}
	}
	bool valid;
	int oCase;
	do
	{
		valid = true;
		string input;
		cin >> input;
		try
		{
			oCase = stoi(input);
		}
		catch (const std::exception&)
		{
			cout << "I was unable to understand that input. Please try again\n";
			valid = false;
			continue;
		}
		if (oCase > validAddress || oCase < 0)
		{
			cout << "Your input is not a valid option. Please try again\n";
			valid = false;
			continue;
		}
	} while (!valid);
	return subject->GetFolder(oCase);
}
void RenameFolder(Folder *subject)
{
	string input;
	if (subject->GetFolder(0) == nullptr)
	{
		cout << "You cannot rename the root folder\n";
		return;
	}
	cout << "Please provide a new name\n";
	cin >> input;
	subject->Rename(input);
}
void FolderMenu(Folder* currentfolder)
{
	cout << currentfolder->List() << endl;
	string options[] = { "Move", "Rename", "Add Folder", "Add File" };
	switch (simpleMenu(options, 4))
	{
	case 0:
		FolderMoveMenu(currentfolder);
		break;
	case 1:
		RenameFolder(currentfolder);
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}


int main()
{
	randSeed();

	systemSpace[0] = Folder("root", nullptr);
	Folder* currentFolder = &systemSpace[0];




	File *stuff = &systemSpace[0];
	systemSpace[1] = Folder("Folder1", currentFolder);
	systemSpace[1].Add(File("AlsoAFile"));
	File file1 = File("File1");
	File file2 = File("File2");
	systemSpace[0].Add(&systemSpace[1]);
	systemSpace[0].Add(file1);
	systemSpace[0].Add(file2);

	NewFolder("Folder3", currentFolder);
	FolderMenu(currentFolder);

	cout << (*stuff).List() << endl;
	cout << systemSpace[0].GetLargest().List();
	(systemSpace[0].GetFolder(1))->Add(File("File3"));
	//string moo[] = {"hi", "stuffs", "poyo", "cow", "bleh"};
	//cout << to_string(simpleMenu(moo, sizeof(moo)/sizeof(moo[0])));
	return 0;
}