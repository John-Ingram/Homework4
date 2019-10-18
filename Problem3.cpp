//
// Find Word in random string of chars
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void getInfo(ifstream file,vector<string> names, vector<string> maxTemps, vector<string> minTemps);

int main(void)
{
	ifstream infile;
    char trash;
	string line;
    double max, min;
    vector<string> names, maxTemps, minTemps, maxNames, minNames;

	infile.open(".\\weather_station_five_column.txt");
	if (!infile)
	{
		cout << "Error. Not able to open file.";
		system("pause");
		return(3);
	}

	system("pause");
	return 0;
}

void getInfo(vector<string> names, vector<string> maxTemps, vector<string> minTemps)
{
    while(!infile.eof())
    {

    }
}

