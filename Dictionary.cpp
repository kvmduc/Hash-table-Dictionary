#include "Dictionary.h"

Hash::Hash()
{
	string temp, word, type, pronunciation, example;
	for (int i = 0; i < Tablesize; i++) {
		Dictionary[i] = new Word;
		Dictionary[i]->word = "empty";
		Dictionary[i]->type = "empty";
		Dictionary[i]->pronunciation = "empty";
		Dictionary[i]->example = "empty";
		Dictionary[i]->next = NULL;
	}
	ifstream file;
	file.open("output.csv");
	cout << "READING ...." << endl;
	getline(file, temp);
	while (!file.eof()){
		getline(file, word, ',');
		getline(file, type, ',');
		getline(file, pronunciation, ',');
		getline(file, example, '\n');
		Add(word, type, pronunciation, example);
	}
	cout << "DONE !!" << endl;
}

int Hash::hash(string key) {
	int hash = 0;
	int index;
	for (int i = 0; i < key.length(); i++) {
		hash = hash + (int) key[i] * 3;
	}
	index = hash % Tablesize;
	return index;
}

void Hash::Add(string word, string type, string pronunciation, string example)
{
	int index = hash(word);
	if (Dictionary[index]->word == "empty") {
		Dictionary[index]->word = word;
		Dictionary[index]->type = type;
		Dictionary[index]->pronunciation = pronunciation;
		Dictionary[index]->example = example;
	}
	else {
		Word* iterator = Dictionary[index];
		Word* temp = new Word;
		temp->word = word;
		temp->type = type;
		temp->pronunciation = pronunciation;
		temp->example = example;
		temp->next = NULL;
		while (iterator->next != NULL)
		{
			iterator = iterator->next;
		}
		iterator->next = temp;
	}
}

void Hash::Search(string word) {
	int n = 0;
	for (int i = 0; i < Tablesize; i++) {
		Word* iterator = Dictionary[i];
		while (iterator!=NULL)
		{
			if (iterator->word.substr(0,word.length()) == word) {
				n++;
				cout << "Found result !!" << endl;
				Print(iterator);
				iterator = iterator->next;
			}
			else {
				iterator = iterator->next;
			}
		}
	}
	if (n == 0) {
		cout << "No result !!" << endl;
	}
}

void Hash::Print(Word* p)
{
	cout << "\tWord : " << p->word << endl;
	cout << "\tType : " << p->type << endl;
	cout << "\tPronounciation : " << p->pronunciation << endl;
	cout << "\tExample : " << p->example << endl << endl;
}
