//
// Find Word in random string of chars
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void getInfo(ifstream file,vector<string> names, vector<string> maxTemps, vector<string> minTemps);

int main(void)
{
	ifstream infile;
    
    double max, min;
    vector<string> names, maxTemps, minTemps, maxNames, minNames;


	system("pause");
	return 0;
}

void getInfo(ifstream file, vector<string> names, vector<double> maxTemps, vector<double> minTemps)
{
    string identifiers [3] = {"DATE", "TMAX", "TMIN"};
    int positions [3] = {}; // Note that the first position is the end, while the others are beginnings
    double temp;
    char trash;
    stringstream stream; // A stream Used to convert strings to doubles.
	string line;
    file.open(".\\weather_station_five_column.txt");
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
        names.push_back(line.substr(0,positions[0])); //Add the station name to the vector

        stream << line.substr(positions[1], positions[2]);// Get the max temp from the file, and put it into a stream
        stream >> temp; // get the temperature from the stream as a doube
        maxTemps.push_back(temp); // add that to  the vector

        stream << line.substr(positions[1], string::npos); //Same as above but for max
        stream >> temp;
        minTemps.push_back(temp);
    }
}

