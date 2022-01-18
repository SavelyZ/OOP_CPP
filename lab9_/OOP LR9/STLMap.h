#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

class STLMap
{
public:

	STLMap();
	STLMap(string Filename);
	~STLMap();

	bool WordIsExist(string Word);
	int GetRate(string Word);
	void WriteToFileSp(string Filename, bool IntSort);
	void VocabularToVocabular1();

private:
	void ReadFromFile(string Filename);
	void WriteToFile(string Filename);
	void WriteToFile1(string Filename);
	map<string, int> Vocabular;
	map<int, vector<string>> Vocabular1;
};

