#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Word
{
	string word;
	string type;
	string pronunciation;
	string example;
	Word* next;
};

class Hash {
private:
	static const int Tablesize = 100000;
	Word * Dictionary[Tablesize];
public:
	Hash();
	int hash(string key);
	void Add(string word, string type, string pronunciation, string example);
	void Search(string word);
	void Print(Word* p);
};