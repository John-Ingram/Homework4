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


	system("pause");
	return 0;
}

void getInfo(ifstream file, vector<string> names, vector<string> maxTemps, vector<string> minTemps)
{
    string identifiers [3] = {"DATE", "TMAX", "TMIN"};
    file.open(".\\weather_station_five_column.txt");
	if (!file)
	{
		cout << "Error. Not able to open file.";
		system("pause");
		exit(1);
	}
    while(!file.eof())
    {

    }
}

