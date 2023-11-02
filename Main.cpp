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
	//option[0] = subject->GetFolder(0).GetName();
	//option[1 ... 5] = subject->GetFolder(1 ... 5).GetName();
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
	subject->GetLargest();
}

int main()
{
	randSeed();

	Folder root = Folder("root", nullptr);
	Folder* currentFolder = &root;

	currentFolder->Add(Folder("stuff", currentFolder));
	currentFolder->Add(File("meow"));
	(root.GetFolder(1))->Add(File("moo"));

	int menuSelector = 0;
	currentFolder = currentFolder->GetFolder(1);
	do
	{
		cout << "Current Folder is:\n";
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

			break;
		default:
			menuSelector = -1;
			break;
		}


	} while (menuSelector != -1);
	// do {List options; take input; Run corresponding function}
	// options [Move/select file, Rename, Add Folder, Add File]
	// Move[parent = 0, Folder = 1-5, Files = 6-15]
	// Rename {cin >> string input; currentFolder->Rename(input);}
	// Add Folder {cin input; currentFolder->Add(Folder("input", currentFolder);}
	// Add File {cin input; currentFolder->Add(File("input");}


	cout << (*currentFolder).List() << endl;
	// cout << currentFolder->GetLargest().List();
	return 0;
}