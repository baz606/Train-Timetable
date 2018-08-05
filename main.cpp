/*
 * Created by Shehbaz Khan
 */

#include <iostream>
#include "TrainMaster.h"

using namespace std;

int get_hours(string &time);
int get_minutes(string &time);

int main()
{
    string str_time;
    int num_of_cases;
    int turn_over, NA, NB;
    TrainMaster trainMaster;

    int trainsAtA, trainsAtB;

    cin >> num_of_cases;

    for(int i = 1; i <= num_of_cases; ++i)
    {
        //cout << "Case #" << i << endl;
        trainsAtA = 0;
        trainsAtB = 0;
        cin >> turn_over >> NA >> NB;

        for(int j = 0; j < NA; ++j)
        {
            cin >> str_time;
            trainMaster.add_event(get_hours(str_time), get_minutes(str_time), "DEPARTURE", "NA");

            cin >> str_time;
            trainMaster.add_event(get_hours(str_time), get_minutes(str_time), "ARRIVAL", "NA");
        }

        for(int k = 0; k < NB; ++k)
        {
            cin >> str_time;
            trainMaster.add_event(get_hours(str_time), get_minutes(str_time), "DEPARTURE", "NB");

            cin >> str_time;
            trainMaster.add_event(get_hours(str_time), get_minutes(str_time), "ARRIVAL", "NB");
        }

        trainMaster.add_turnover_time(turn_over);
        trainMaster.sort_list();
        trainMaster.calculateStartingTrains(trainsAtA, trainsAtB);

        cout << "Case #" << i << ": " << trainsAtA << " " << trainsAtB << endl;
        //trainMaster.print_event_list();
        trainMaster.clear_list();
    }

    return 0;
}

int get_hours(string &time)
{
    unsigned long pos = time.find(':');
    string hours = time.substr(0, pos);

    return stoi(hours);
}

int get_minutes(string &time)
{
    unsigned long pos = time.find(':');
    string minutes = time.substr(pos + 1);

    return stoi(minutes);
}