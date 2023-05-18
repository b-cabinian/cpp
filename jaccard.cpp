
/* 
Name: Brian Cabinian
Date: 22-11-10
Description: This script takes in two string arrays and reports
the jaccard index of those two sets.
*/

#include <iostream>
#include <iomanip>

using namespace std;

double intersectionMag(string tags1[], string tags2[], int size1, int size2);

int main ()
{
	//for taking in array
	int size1 = 0;
	int size2 = 0;
	int i = 0;
	string * tags1 = NULL;
	string * tags2 = NULL;
	char ch = '\0';
	string empty = "";

	//for calculating jaccard index
	double unionSize = 0;
	double intersectionSize = 0;

	//begin
	cout << "Number of tags in Item 1: ";
	cin >> size1;
	cout << "Enter tags: ";
	tags1 = new string[size1];

	do
	{
		cin >> tags1[i];
		i++;
		ch = cin.get();
	} while (ch != '\n' && i < size1);

	// Clear the input stream of excess inputs
	if(i == size1 && ch != '\n')
	{
		getline(cin, empty);
	}
	//Post-populate unused indices with empty string
	else if (i < size1 && ch == '\n')
	{
		for(i; i < size1; i++)
		{
			tags1[i] = "";
		}
	}

	i = 0;
	ch = '\0';


	cout << "Number of tags in Item 2: ";
	cin >> size2;
	cout << "Enter tags: ";
	tags2 = new string[size2];

	do
	{
		cin >> tags2[i];
		i++;
		ch = cin.get();
	} while (ch != '\n' && i < size2);

	// Clear the input stream of excess inputs
	if(i == size2 && ch != '\n')
	{
		getline(cin, empty);
	}
	//Post-populate unused indices with empty string
	else if (i < size2 && ch == '\n')
	{
		for(i; i < size2; i++)
		{
			tags2[i] = "";
		}
	}

	intersectionSize = intersectionMag(tags1, tags2, size1, size2);
	
	//cout << "Intersection size: " << intersectionSize;
	unionSize = size1 + size2 - intersectionSize;
	//cout << "Union size: " << unionSize;

	cout << setprecision(2) << fixed;
	cout << "Jaccard Index is " << intersectionSize / unionSize << endl;

	return 0;
}

double intersectionMag(string tags1[], string tags2[], int size1, int size2)
{
	double intersectCount = 0;
	bool matchFound = false;

	for (int i = 0; i < size1; i++)
	{
		//go through tags2 until you find match or hit end of tags2
		for (int j = 0; j < size2; j++)
		{
			if (tags1[i] == tags2[j])
			{
				matchFound = true;
				break;
			}
		}

		//if index j < size2 we terminated before end of tags2 so we found a match
		if (matchFound)
		{
			intersectCount++;
		}

		matchFound = false;
	}

	return intersectCount;
}

