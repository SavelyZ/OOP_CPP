#include "STLMap.h"
#include <fstream>

STLMap::STLMap()
{
	ReadFromFile("data.txt");
}

STLMap::STLMap(string Filename)
{
	ReadFromFile(Filename);
}

STLMap::~STLMap()
{
	WriteToFile("Vocabular.txt");
}

bool STLMap::WordIsExist(string Word)
{
	return (Vocabular.find(Word) != Vocabular.end());
}

int STLMap::GetRate(string Word)
{
	if (WordIsExist(Word))
		return Vocabular[Word];
	else return 0;
}

void STLMap::WriteToFileSp(string Filename, bool IntSort)
{
	if (IntSort)
	{
		VocabularToVocabular1();
		WriteToFile1(Filename);
	}
	else WriteToFile(Filename);
}

void STLMap::VocabularToVocabular1()
{
	for (auto it = Vocabular.begin(); it != Vocabular.end(); it++)
		Vocabular1[it->second].push_back(it->first);
}

void STLMap::ReadFromFile(string Filename)
{
	ifstream File(Filename);
	string s;
	while (!File.eof()) {
		File >> s;
		Vocabular[s]++;
	}
	File.close();
}

void STLMap::WriteToFile(string Filename)
{
	ofstream File(Filename);
	for (auto it = Vocabular.begin(); it != Vocabular.end(); it++)
		File << it->second << ":\t" << it->first << endl;
	File.close();
}

void STLMap::WriteToFile1(string Filename)
{	
	ofstream File(Filename);
	for (auto it = Vocabular1.begin(); it != Vocabular1.end(); it++)
		for (int i = 0; i < it->second.size(); i++)
			File << it->first << ":\t" << it->second[i] << endl;
	File.close();
}
