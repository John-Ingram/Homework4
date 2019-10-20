#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{

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

    return 0;
}
