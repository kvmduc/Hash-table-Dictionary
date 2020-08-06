#include "Dictionary.h"

void main() {
	string search;
	string choice;
	Hash Dictionary;
	do {
		cout << "Would you like to search a word? (yes or no) : ";
		cin >> choice;
		if (choice == "no") {
			cout << "exit !" << endl;
			break;
		}
		else if (choice == "yes") {
			cout << "Input word : ";
			cin >> search;
			Dictionary.Search(search);
		}
	} while (choice != "no");
}