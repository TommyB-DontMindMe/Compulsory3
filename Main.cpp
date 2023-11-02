#include <iostream>
#include <chrono>
#include "File.h"
#include "Folder.h"
using namespace std;

Folder Folder::systemSpace[] = { Folder() };
// Current folder List()
// List options 
// [Go to parent folder, Go to folder [n], Go to file [n]]
//		File [Rename, Delete]
//		Folder [Create Folder, Create File, Get Largest, ]

Folder *MoveMenu(Folder *subject)
{
	cout << "Please select a folder to move to" << endl;
	for (size_t i = 0; i < 1 + folderCap; i++)
	{
		if (subject->GetFolder(i) != nullptr)
		{
			cout << i << ". " << subject->GetFolder(i)->GetName() << endl;
		}
	}
	bool valid = true;
	int option;
	do
	{
		valid = true;
		string input;
		cin >> input;
		for (size_t i = 0; i < 1 + folderCap; i++)
		{
			if (subject->GetFolder(i) != nullptr && input == subject->GetFolder(i)->GetName())
			{
				return subject->GetFolder(i);
			}
		}
		try
		{
			option = stoi(input);
		}
		catch (const std::exception&)
		{
			cout << "I was unable to understand that input. Please try again\n";
			valid = false;
			continue;
		}
		if (option > 1 + folderCap || option < 0)
		{
			cout << "Your input is not a valid option. Please try again\n";
			valid = false;
			continue;
		}
	} while (!valid);
	return subject->GetFolder(option);
}
void RenameMenu(File *subject)
{
	cout << "Please enter a new name" << endl;
	string newName;
	cin >> newName;
	subject->Rename(newName);
}
void AddFolderMenu(Folder *subject)
{
	cout << "Please enter a name for the new folder" << endl;
	string newFolder;
	cin >> newFolder;
	subject->Add(Folder(newFolder, subject));
}
void AddFileMenu(Folder* subject)
{
	cout << "Please enter a name for the new file" << endl;
	string newFile;
	cin >> newFile;
	subject->Add(File(newFile));
}
void FindLargestMenu(Folder *subject)
{
	cout << "The largest file in this folder is: " << subject->GetLargest().GetName() << endl;
}

int main()
{
	randSeed();

	Folder root = Folder("root", nullptr);
	Folder* currentFolder = &root;

	currentFolder->Add(Folder("cluck", currentFolder));
	currentFolder->Add(File("meow"));
	currentFolder->GetFolder(1)->Add(File("chicken"));
	currentFolder->GetFolder(1)->Add(File("hen"));
	currentFolder->GetFolder(1)->Add(File("rooster"));

	bool run = true;
	do
	{
		cout << "Current Folder is: " << currentFolder->GetName() << endl;
		cout << currentFolder->List() << endl;
		string mOptions[] = {"Move", "Rename", "Add Folder", "Add File", "Find Largest File", "Exit"};
		switch (simpleMenu(mOptions, 6))
		{
		case 0:
			currentFolder = MoveMenu(currentFolder);
			break;
		case 1:
			RenameMenu(currentFolder);
			break;
		case 2:
			AddFolderMenu(currentFolder);
			break;
		case 3:
			AddFileMenu(currentFolder);
			break;
		case 4:
			FindLargestMenu(currentFolder);
			break;
		default:
			run =  false;
			break;
		}


	} while (run);
	return 0;
}