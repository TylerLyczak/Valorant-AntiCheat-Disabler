/*
	Tyler Lyczak
	Valorant Anti-Cheat Disabler
	5/5/20
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

bool AntiCheatSolver(int option) {

	// The old file names and locations
	char vgcExe[] = "C:/Program Files/Riot Vanguard/vgc.exe";

	char vgcIcon[] = "C:/Program Files/Riot Vanguard/vgc.ico";

	char vgkSys[] = "C:/Program Files/Riot Vanguard/vgk.sys";

	char vgrlDll[] = "C:/Program Files/Riot Vanguard/vgrl.dll";

	char vgtrayExe[] = "C:/Program Files/Riot Vanguard/vgtray.exe";


	// The new file locations and names
	char newVgcExe[] = "C:/Program Files/Riot Vanguard/vgc1.exe";

	char newVgcIcon[] = "C:/Program Files/Riot Vanguard/vgc1.ico";

	char newVgkSys[] = "C:/Program Files/Riot Vanguard/vgk1.sys";

	char newVgrlDll[] = "C:/Program Files/Riot Vanguard/vgrl1.dll";

	char newVgtrayExe[] = "C:/Program Files/Riot Vanguard/vgtray1.exe";

	// Uses clib rename function to accomplish the task
	vector<int> resultVector;

	// To re-enable the anti-cheat to play the game
	if (option == 1) {
		resultVector.push_back(rename(newVgcExe, vgcExe));
		resultVector.push_back(rename(newVgcIcon, vgcIcon));
		resultVector.push_back(rename(newVgkSys, vgkSys));
		resultVector.push_back(rename(newVgrlDll, vgrlDll));
		resultVector.push_back(rename(newVgtrayExe, vgtrayExe));
	}
	// To disable the anti-cheat
	else {
		resultVector.push_back(rename(vgcExe, newVgcExe));
		resultVector.push_back(rename(vgcIcon, newVgcIcon));
		resultVector.push_back(rename(vgkSys, newVgkSys));
		resultVector.push_back(rename(vgrlDll, newVgrlDll));
		resultVector.push_back(rename(vgtrayExe, newVgtrayExe));
	}

	// Loop over the results to make sure all files were changed
	for (int& i : resultVector) {
		if (i != 0) {
			// If one wasn't changed, then return false
			return false;
		}
	}

	return true;
}


int main() {

	cout << "Valorant Anti-Cheat Disabler" << endl;
	cout << "By Tyler Lyczak, https://github.com/TylerLyczak" << endl;

	int option = 0;
	cout << "Enter 0 to exit program" << endl;
	cout << "Enter 1 for re-enable anticheat (requires reset)" << endl;
	cout << "Enter 2 for disable anticheat (requires reset)" << endl;
	cin >> option;

	while (option != 0 && option != 1 && option != 2) {
		cout << "Please enter a valid option" << endl;
		cin >> option;
	}
	cin.clear();

	bool result = false;
	if (option == 0)		exit(0);
	else if (option == 1) {
		// Calls the function to disable the anti-cheat
		result = AntiCheatSolver(1);
	}
	else if (option == 2) {
		// Calls the function to re-enable the anti-cheat
		result = AntiCheatSolver(2);
	}
	else					exit(0);

	if (result == true) {
		int restart = 0;
		cout << "Successfuly changed file names" << endl;
		cout << "Enter 0 to exit program and restart yourself" << endl;
		cout << "Enter 1 to restart now" << endl;
		cin >> restart;

		while (restart != 0 && restart != 1) {
			cout << "Please enter a valid option" << endl;
			cin >> restart;
		}
		cin.clear();

		if (restart == 1) {
			system("c:\\windows\\system32\\shutdown /r -t 0");
		}
		else {
			exit(0);
		}

	}
	else
	{
		cout << "Error has occured" << endl;
	}




}
