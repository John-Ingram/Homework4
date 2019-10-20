#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cmath>

using namespace std;

bool filegood(fstream &handle, string fname);
void find_max_min(double tmax[], double tmin[], int elements, double &max_val, double &min_val);
float total_precip_by_station(float prcp[], int elements, string answer, string dataline, string station[]);
float total_precip_day(float prcp[], unsigned int days[], int elements, int DOM);
float total_precip_range(float prcp[], unsigned int days[], int elements, int DOM, int start_day, int end_day);

int main()
{

	fstream infile, outfile;
	string infilename = "C:/Users/owner/Documents/AL_Weather_Station.txt";
	string outfilename = "C:/Users/owner/Documents/Filtered_AL_Weather_Station.txt";
	string firstline = "";
	string dataline = "";
	string s_tmax, s_tmin, s_prcp;
	double tmax[9000], tmin[9000];
	double max = 0.0, min = 0.0;
	int records = 0;
	int pos_tmax, pos_tmin, pos_prcp, pos_mdpr, pos_dapr, pos_snwd, pos_snow, pos_awnd;

    cout << "WEATHER STATION DATA" << endl << endl;
	cout << "Open the weather data file." << endl << endl;
	infile.open("C:/Users/owner/Documents/AL_Weather_Station.txt");
	if (!filegood(infile, infilename))
		return 2;

	cout << "Read the first line from the file. " << endl;
	getline(infile, firstline);
	cout << firstline << endl;
    outfile.open("C:/Users/owner/Documents/Filtered_AL_Weather_Station.txt");
    pos_mdpr = firstline.find("MDPR");
	if (pos_mdpr != string::npos)
	{
		cout << "The position of column MDPR is " << pos_mdpr << endl;
	}
	else
	{
		cout << "Error: MDPR not found." << endl;
		system("pause");
		return 5;
	}
    pos_dapr = firstline.find("DAPR");
	if (pos_dapr != string::npos)
	{
		cout << "The position of column DAPR is " << pos_dapr << endl;
	}
	else
	{
		cout << "Error: DAPR not found." << endl;
		system("pause");
		return 6;
	}
    pos_snwd = firstline.find("SNWD");
	if (pos_snwd != string::npos)
	{
		cout << "The position of column SNWD is " << pos_snwd << endl;
	}
	else
	{
		cout << "Error: SNWD not found." << endl;
		system("pause");
		return 7;
	}
    pos_snow = firstline.find("SNOW");
	if (pos_snow != string::npos)
	{
		cout << "The position of column SNOW is " << pos_snow << endl;
	}
	else
	{
		cout << "Error: SNOW not found." << endl;
		system("pause");
		return 8;
	}
    pos_awnd = firstline.find("AWND");
	if (pos_awnd != string::npos)
	{
		cout << "The position of column AWND is " << pos_awnd << endl;
	}
	else
	{
		cout << "Error: AWND not found." << endl;
		system("pause");
		return 9;
	}
    pos_tmax = firstline.find("TMAX");
	if (pos_tmax != string::npos)
	{
		cout << "The position of column TMAX is " << pos_tmax << endl;
	}
	else
	{
		cout << "Error: TMAX not found." << endl;
		system("pause");
		return 3;
	}
	pos_tmin = firstline.find("TMIN");
	if (pos_tmin != string::npos)
	{
		cout << "The position of column TMIN is " << pos_tmin << endl;
	}
	else
	{
		cout << "Error: TMIN not found." << endl;
		system("pause");
		return 4;
	}
    pos_prcp = firstline.find("PRCP");
	if (pos_prcp != string::npos)
	{
		cout << "The position of column PRCP is " << pos_prcp << endl;
	}
	else
	{
		cout << "Error: PRCP not found." << endl;
		system("pause");
		return 1;
	}
	outfile << firstline << endl;

	system ("pause");

    cout << "Read the second line from the file. " << endl;
	getline(infile, dataline);
	cout << dataline << endl;
	system ("pause");

	cout << "Now get first line of data." << endl << endl;
	getline(infile, dataline);
	cout << dataline << endl;


		while (!infile.eof())
	{
		// Extract the TMAX and TMIN values

		s_tmax = dataline.substr(pos_tmax, 5);
		s_tmin = dataline.substr(pos_tmin, 5);
		s_prcp = dataline.substr(pos_prcp, 5);
		// Check for bad data

		if (s_tmax != "-9999" && s_tmin != "-9999" && s_prcp != "-9999") // Good record
		{
            cout << dataline << endl;
		    outfile << dataline << endl;
			tmax[records] = stod(s_tmax) / 10.0;
            tmin[records] = stod(s_tmin) / 10.0;
			records++;
		}
		getline(infile, dataline);

	}

	cout << "There are " << records << " good data records for tmax and tmin" << endl;

	infile.close();

	find_max_min(tmax, tmin, records, max, min);

	cout << fixed << setprecision(2);
	cout << "The max temperature is " << max << endl;
	cout << "The min temperature is " << min << endl;
	outfile.close();


	cout << "\n\n";
	system("pause");
	return 0;

	return 0;
}




void find_max_min(double tmax[], double tmin[], int elements, double &max_val, double &min_val)
{
	max_val = tmax[0];
	min_val = tmin[0];

	for (int k = 1; k < elements; k++)
	{
		if (tmax[k] > max_val)
			max_val = tmax[k];
		if (tmin[k] < min_val)
			min_val = tmax[k];
	}
	return;
}

//
// Function fileopen
//

bool filegood(fstream &handle, string fname)
{
	if (!handle)
	{
		cout << "Unable to open the file " << fname << ". Check path and permissions. " << endl;
		system("pause");
		return false;
	}
	else
	{
		cout << "File " << fname << " was opened successfully." << endl;
		return true;
	}
}

float total_precip_day(float prcp[], unsigned int days[], int elements, int DOM)
{
	float total_prcp = 0.0;
	int k = 0;

	for (k = 0; k < elements; k++)
	{
		if (days[k] == DOM)
		{

			total_prcp += prcp[k];

		}

	}
	return total_prcp;
}
float total_precip_range(float prcp[], unsigned int days[], int elements, int DOM, int start_day, int end_day)
{
	float total_prcp = 0.0;
	int k = 0;

	for (k = 0; k < elements; k++)
	{

		if ((days[k] >= start_day) && (days[k] <= end_day))
		{

			total_prcp += prcp[k];

		}

	}
	return total_prcp;
}



//Add function for part 3
float total_precip_by_station(float prcp[], int elements, string answer, string dataline, string station[])
{
    string s_station;
    float total_prcp = 0.0;

    for(int i = 0; i < elements; i++)
    {
        if(station[i].find(answer) != string::npos)
        {
            total_prcp += prcp[i];
        }
    }

    return total_prcp;

}
