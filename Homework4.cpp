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


int main()
{
/*
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
*/

    fstream infile, outfile;
    infile.open("C:/Users/owner/Documents/Filtered_AL_Weather_Station.txt");
    outfile.open("C:/Users/owner/Documents/weather_station_five_column.txt");
    string newline = "";
    string s_tmax, s_tmin, s_date;
    float tmax, tmin;
    int pos_tmax, pos_tmin, pos_prcp, pos_mdpr, pos_dapr, pos_snwd, pos_snow, pos_awnd, counter = 0, pos_date;

    getline(infile, newline);
    newline.erase(0, 18);
    pos_mdpr = newline.find("MDPR");
    newline.erase(pos_mdpr, 8);
    pos_dapr = newline.find("DAPR");
    newline.erase(pos_dapr, 8);
    pos_snwd = newline.find("SNWD");
    newline.erase(pos_snwd, 8);
    pos_snow = newline.find("SNOW");
    newline.erase(pos_snow, 8);
    pos_awnd = newline.find("AWND");
    newline.erase(pos_awnd, 8);
    pos_tmax = newline.find("TMAX");
    pos_tmin = newline.find("TMIN");
    pos_date = newline.find("DATE");
    outfile << newline << endl;
    getline(infile, newline);
    while(!infile.eof())
    {
            newline.erase(0, 18);
            newline.erase(pos_mdpr, 8);
            newline.erase(pos_dapr, 8);
            newline.erase(pos_snwd, 8);
            newline.erase(pos_snow, 8);
            newline.erase(pos_awnd, 8);
            s_tmax = newline.substr(pos_tmax, 2);
            s_tmin = newline.substr(pos_tmin, 2);
            tmax = stof(s_tmax) / 10.0;
            tmin = stof(s_tmin) / 10.0;
            tmax = (tmax * (9 / 5)) + 32;
            tmin = (tmin * (9 / 5)) + 32;
            s_tmax = to_string(tmax);
            s_tmin = to_string(tmin);
            s_date = newline.substr(pos_date, 8);
            s_date.insert(4," ",1);
            s_date.insert(7," ",1);
            newline.replace(pos_date, s_date.length(), s_date);
            newline.replace(pos_tmax, s_tmax.length(), s_tmax);
            newline.replace(pos_tmin, s_tmin.length(), s_tmin);
            outfile.precision(2);
            outfile << setprecision(2) << newline << endl;
            counter++;
            getline(infile, newline);

    }
    cout << counter << endl;
    infile.close();
    outfile.close();
   /* while(!infile.eof())
    {
            getline(infile, newline);
            newline.erase(0, 18);
            outfile << newline << endl;
    }
    getline(infile, newline);
    pos_mdpr = newline.find("MDPR");
    while(!infile.eof())
    {
            getline(infile, newline);
            newline.erase(pos_mdpr, 8);
            outfile << newline << endl;
    }
    getline(infile, newline);
    pos_dapr = newline.find("DAPR");
    while(!infile.eof())
    {
            getline(infile, newline);
            newline.erase(pos_dapr, 8);
            outfile << newline << endl;
    }
    getline(infile, newline);
    pos_snwd = newline.find("SNWD");
    while(!infile.eof())
    {
            getline(infile, newline);
            newline.erase(pos_snwd, 8);
            outfile << newline << endl;
    }
    getline(infile, newline);
    pos_snow = newline.find("SNOW");
    while(!infile.eof())
    {
            getline(infile, newline);
            newline.erase(pos_snow, 8);
            outfile << newline << endl;
    }
    getline(infile, newline);
    pos_awnd = newline.find("AWND");
    while(!infile.eof())
    {
            getline(infile, newline);
            newline.erase(pos_awnd, 8);
            outfile << newline << endl;
    }
    infile.close();*/
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

