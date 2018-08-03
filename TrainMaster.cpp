//
// Created by Shehbaz Khan
//

#include "TrainMaster.h"

void TrainMaster::add_event(int hours, int minutes, string trip_type, string journey)
{
    event newEvent;
    newEvent.time.hours = hours;
    newEvent.time.minutes = minutes;
    newEvent.trip_type = trip_type;
    newEvent.journey = journey;

    event_list.push_back(newEvent);
}

void TrainMaster::print_event_list()
{
    for(event &e : event_list)
    {
        cout << "Hours: " << e.time.hours << endl;
        cout << "Minues: " << e.time.minutes << endl;
        cout << "Journey: " << e.journey << endl;
        cout << "Trip type: " << e.trip_type << endl;
        cout << endl;
    }
}

TrainMaster::TrainMaster()
{
    clear_list();
}

void TrainMaster::clear_list()
{
    event_list.clear();
}

void TrainMaster::add_turnover_time(int turnover)
{
    for(event &e : event_list)
    {
        if(e.trip_type == "ARRIVAL")
        {
            e.time.minutes += turnover;
            while(e.time.minutes >= 60)
            {
                e.time.hours++;
                if(e.time.hours > 23)
                {
                    e.time.hours = 0;
                }
                e.time.minutes -= 60;
            }
        }
    }
}
