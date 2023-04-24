#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int createEntry() {
	string entry;

	cout << "Enter your diary entry for today: ";
	getline(cin, entry); // read user input

	ofstream diaryFile("diary.txt", ios::app); // open diary in append mode
	if (diaryFile.is_open()) {
		diaryFile << entry << endl; // write entry into the file
		diaryFile.close();
		cout << "Entry saved to diary." << endl;
	} else {
		cout << "Unable to open your diary." << endl;
	}

	return 0;

}


int readEntry() {
	ifstream diaryFile("diary.txt"); // open diary file
	string entry;

	if (diaryFile.is_open()) {
		while (getline(diaryFile, entry)) {
			cout << entry << endl; // display line on console
		}
		diaryFile.close(); // close file
	} else {
		cout << "Unable to open diary file." << endl;
	}

	return 0;
}


int main() {

	createEntry();
	readEntry();

	return 0;
}

