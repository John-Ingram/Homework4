//
// 
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void getInfo(string inFileName, vector<string> &names, vector<string> &times, vector<double> &maxTemps, vector<double> &minTemps);

int main(void)
{
	string inFileName = ".\\weather_station_five_column.txt";
    double max = -999999999.9, min = 99999999.9;
    vector<string> names, minNames , maxNames, dates, minTimes, maxTimes;
    vector<double>  maxTemps, minTemps;
    getInfo(inFileName, names, dates, maxTemps, minTemps);
    
    for(int i = 0; i < names.size(); i++)
    {
        if(maxTemps[i] > max)
        {
            max = maxTemps[i];
            maxNames.clear();
            maxTimes.clear();
            maxNames.push_back(names[i]);
            maxTimes.push_back(dates[i]);
        } else if(maxTemps[i] == max) {
            maxNames.push_back(names[i]);
            maxTimes.push_back(dates[i]);
        }

        if(minTemps[i] < min)
        {
            min = minTemps[i];
            minNames.clear();
            minTimes.clear();
            minNames.push_back(names[i]);
            minTimes.push_back(dates[i]);
        } else if(minTemps[i] == min) {
            minNames.push_back(names[i]);
            minTimes.push_back(dates[i]);
        }
        
    }
    
    cout << "The highest temperature in the state was " << max <<" It was measuread at the following stations: " << endl;
    for(int i = 0; i < maxNames.size(); i++) cout << maxNames[i] << " on "<< maxTimes[i] << endl;
    cout << endl;
    cout << "The lowest temperature in the state was "<< min <<" It was measuread at the following stations: " << endl;
    for(int i = 0; i < minNames.size(); i++) cout << minNames[i] << " on "<< minTimes[i] << endl;
    cout << endl;

	system("pause");
	return 0;
}

void getInfo(string inFileName, vector<string> &names, vector<string> &times, vector<double> &maxTemps, vector<double> &minTemps)
{
    ifstream file;
    string identifiers [3] = {"DATE", "TMAX", "TMIN"};
    string months [12] = {"January", "February", "March", "April", "May", "June", "July",
                         "August", "September", "October", "November", "December"};
    int positions [3] = {}; // Note that the first position is the end, while the others are beginnings
    int month;
	string line, rawDate, date;
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
            date = "";
            names.push_back(line.substr(0,positions[0])); //Add the station name to the vector
            rawDate = line.substr(positions[0]+13, 5);
            month = (int)atof(rawDate.substr(0,2).c_str());
            date.append(months[month-1]);
            date.append(" ");
            date.append(rawDate.substr(2,3));
            times.push_back(date); // Add the date to the vector
            maxTemps.push_back((double)atof((line.substr(positions[1], positions[2]-positions[1])).c_str())); // add max to  the vector
            minTemps.push_back((double)atof((line.substr(positions[2], string::npos)).c_str())); // add min to  the vector
            
        }
    }
}