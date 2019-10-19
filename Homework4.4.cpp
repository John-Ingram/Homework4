
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

float total_precip_day(float prcp[], unsigned int days[], int elements, int DOM);
float total_precip_range(float prcp[], unsigned int days[], int elements, int DOM, int start_day, int end_day);
//Declare function 3
//Declare function 4
//Declare function 5

int main(void)
{
	string dataline = "";
	string station[3000];
	string s_year, s_month, s_day;
	string s_tmax, s_tmin, s_prcp, station_name;

	string menu[6] = { "1. Total precipition from all stations for a given day",
					  "2. Total precipitation over a date range. ",
					  "3. Total precipitation by station for March. ",
					  "4. Temperature max, min and average by station for March.",
 "5. Temperature max, min and average by station for date range.",
 "6. Quit." };

	unsigned int j = 0, k = 0;;
	unsigned int pos_station_name = 0;
	unsigned int pos_date = 0;
	unsigned int pos_prcp = 0;
	unsigned int pos_tmax = 0;
	unsigned int pos_tmin = 0;
	unsigned int option = 0;
	unsigned int dayofmonth = 0, daysofmarch[3000];
	unsigned int start_day = 0, end_day = 0;
	float tmax = 0, tmin = 0, tavg_hi = 0, tavg_low = 0, prcp[2900] = { 0 };
	float tmaxF[2900] = { 0 }, tminF[2900] = { 0 };
	float max = 0, min = 0;

	ifstream infile;

	cout << "SUBSET of WEATHER STATION DATA" << endl << endl;
	cout << "Open the five column weather data file." << endl << endl;
	infile.open("weather_station_five_column.txt");

	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		system("pause");
		return(1);
	}
	else
	{
		cout << "Data file opened." << endl;
	}


	cout << "Use the first line of the file to find the column positions. " << endl;
	getline(infile, dataline);

	pos_station_name = dataline.find("STATION_NAME");
	pos_date = dataline.find("DATE");
	pos_prcp = dataline.find("PRCP");
	pos_tmax = dataline.find("TMAX");
	pos_tmin = dataline.find("TMIN");

	cout << "Now get the data records." << endl << endl;
	j = 0;
	getline(infile, dataline);
	while (!infile.eof())
	{
		station[j] = dataline.substr(0, 44);

		s_year = dataline.substr(pos_date, 4); 
		s_month = dataline.substr(pos_date + 5, 2); 
		s_day = dataline.substr(pos_date + 8, 2);   
		daysofmarch[j] = stoi(s_day);               


		s_prcp = dataline.substr(pos_prcp, 5);

		s_tmax = dataline.substr(pos_tmax, 5);
		s_tmin = dataline.substr(pos_tmin, 5);

		
		prcp[j] = stof(s_prcp); 
		tmaxF[j] = stof(s_tmax); 
		tminF[j] = stof(s_tmin); 
		j++;

		getline(infile, dataline);
	} 

	cout << "There are " << j << " records in the new file." << endl;
	infile.close();

	cout << endl << endl;
	cout << fixed << setprecision(2);

	while (option != 6)
	{
		cout << "Select an option from the following menu." << endl << endl;
		for (k = 0; k < 6; k++)
			cout << menu[k] << endl;

		cin >> option;
		cin.ignore(100, '\n');
		cout << "You selected option " << menu[option - 1] << endl;

		switch (option)
		{
		case 1: {
			cout << "Enter the day 1 - 31." << endl;
			cin >> dayofmonth;
			if (dayofmonth >= 1 && dayofmonth <= 31)
			{
				cout << "The total precipitation for the state of Alabama " << endl
					<< "on March " << dayofmonth << " was "
					<< total_precip_day(prcp, daysofmarch, j, dayofmonth)
					<< " inches. " << endl;
			}
			else
			{
				cout << "Error. Day must be between 1 and 31. " << endl;
			}
			break;
		}
		case 2: {
			cout << "Enter the beginning day 1 - 30." << endl;
			cin >> start_day;
			if (start_day >= 1 && start_day <= 31)
			{
				cout << "Enter the ending day 2 - 30." << endl;
				cin >> end_day;
				if (end_day >= 1 && end_day <= 31)
				{
					cout << "The total precipitation for the state of Alabama " << endl
						<< "from March " << start_day << " and " << end_day << " was "
						<< total_precip_range(prcp, daysofmarch, j, dayofmonth, start_day, end_day)
						<< " inches. " << endl;
				}
				else
				{
					cout << "Error. Day must be between 2 and 31. " << endl;
				}
			}
			else
			{
				cout << "Error. Day must be between 1 and 31. " << endl;
			}
			

			
			break;
		}
		case 3: {
			cout << "Enter the station name." << endl;
			getline(cin, station_name);


			// Add code here

			break;
		}
		case 4: {
			cout << "Enter the station name." << endl;
			getline(cin, station_name);


			// Add code here

			break;
		}
		case 5: {
			cout << "Enter the station name." << endl;
			getline(cin, station_name);
			for (k = 0; k < station_name.length(); k++)       // Make sure it is uppercase
				station_name[k] = toupper(station_name[k]);

			cout << "Enter the beginning day 1 - 30." << endl;
			cin >> start_day;
			cout << "Enter the ending day 2 - 30." << endl;
			cin >> end_day;


			// Add code here

		}
		} 
		cout << endl << endl;
	} 

	cout << endl << endl;
	return 0;
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
//Add function for part 4
//Add function for part 5
