#pragma once
#include <chrono>
using namespace std;

/// <summary>
/// Seed the random number generator rand() using the system clock.
/// </summary>
void randSeed()
{
	srand((chrono::duration_cast<chrono::microseconds>(chrono::system_clock().now().time_since_epoch())).count());
}
/// <summary>
/// Provides a simple menu based on a list of options.
/// </summary>
/// <param name="options"> A string array, each string will be an option on the menu </param>
/// <param name="optionCount"> The number of  </param>
/// <returns></returns>
int simpleMenu(string options[], int optionCount)
{
	for (size_t i = 0; i < optionCount; i++)
	{
		cout << i + 1 << ". " + options[i] << endl;
	}
	bool valid;
	int output;
	do
	{
		valid = true;
		string input;
		cin >> input;
		try
		{
			output = stoi(input);
		}
		catch (const std::exception&)
		{
			cout << "I was unable to understand that input. Please try again\n";
			valid = false;
			continue;
		}
		if (output > optionCount ||output <= 0)
		{
			cout << "Your input is not a valid option. Please try again\n";
			valid = false;
			continue;
		}
	} while (!valid);
	return output;
}