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
    string time = "10:40";
    int num_of_cases;
    int turn_over, NA, NB;
    TrainMaster trainMaster;

    cin >> num_of_cases;

    for(int i = 0; i < num_of_cases; ++i)
    {
        cin >> turn_over >> NA >> NB;

        for(int j = 0; j < NA; ++j)
        {
            cin >> time;
            trainMaster.add_event(get_hours(time), get_minutes(time), "DEPARTURE", "NA");

            cin >> time;
            trainMaster.add_event(get_hours(time), get_minutes(time), "ARRIVAL", "NA");
        }

        for(int k = 0; k < NB; ++k)
        {
            cin >> time;
            trainMaster.add_event(get_hours(time), get_minutes(time), "DEPARTURE", "NB");

            cin >> time;
            trainMaster.add_event(get_hours(time), get_minutes(time), "ARRIVAL", "NB");
        }

        trainMaster.print_event_list();
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