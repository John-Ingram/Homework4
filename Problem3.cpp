//
// Find Word in random string of chars
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void getInfo(string inFileName, vector<string> &names, vector<double> &maxTemps, vector<double> &minTemps);

int main(void)
{
	string inFileName = ".\\weather_station_five_column.txt";
    double max, min;
    vector<string> names, minNames;
    vector<double>  maxTemps, minTemps, maxNames;

    getInfo(inFileName, names, maxTemps, minTemps);

    for(int i = 0; i < names.size(); i++) cout << names[i] <<"\t" << setprecision(15)<<maxTemps[i] << endl;
	system("pause");
	return 0;
}

void getInfo(string inFileName, vector<string> &names, vector<double> &maxTemps, vector<double> &minTemps)
{
    ifstream file;
    string identifiers [3] = {"DATE", "TMAX", "TMIN"};
    int positions [3] = {}; // Note that the first position is the end, while the others are beginnings
	string line;
    file.open(inFileName);
	if (!file)
	{
		cout << "Error. Not able to open file.";
		system("pause");
		exit(1);
	}
    // Set initial positions
    getline(file, line);
    positions[0] = line.find(identifiers[0]) - 7;
    positions[1] = line.find(identifiers[1]);
    positions[2] = line.find(identifiers[2]);

    // Put data into vectors
    while(!file.eof())
    {
        getline(file, line);
        if (line.length() > positions[1])
        {
            names.push_back(line.substr(0,positions[0])); //Add the station name to the vector
            maxTemps.push_back((double)atof((line.substr(positions[1], positions[2]-positions[1])).c_str())); // add max to  the vector
            minTemps.push_back((double)atof((line.substr(positions[2], string::npos)).c_str())); // add min to  the vector
            
        }
    }
}

