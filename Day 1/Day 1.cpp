#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int top3[3] = { 0, 0, 0 };
	int total = 0;
	int highesttotal = 0;
	bool replaced = false;
	int sum = 0;
	string puzzle;
	ifstream file ("Puzzle.txt");
	while (getline(file, puzzle))
	{
		if (puzzle != "")
		{
			int puzzleint = stoi(puzzle);
			total += puzzleint;
		}
		else 
		{
			for (int x = 0; x < 3; x++)
			{
				if (total > top3[x] && replaced == false)
				{
					top3[x] = total;
					replaced = true;
				}
			}
			sort(top3, top3 + 3);
			replaced = false;
			total = 0;
		}
	}
	for (int i = 0; i < 3; i++) 
	{
		sum += top3[i];
	}
	cout << sum;

	file.close();
}