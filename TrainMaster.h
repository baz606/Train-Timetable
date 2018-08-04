//
// Created by Shehbaz Khan
//

#ifndef TRAIN_TIMETABLE_TRAINMASTER_H
#define TRAIN_TIMETABLE_TRAINMASTER_H

#include <vector>
#include "event.h"

class TrainMaster
{
public:
    TrainMaster();
    void add_event(int hours, int minutes, string trip_type, string journey);
    void print_event_list();
    void clear_list();
    static bool compareEvents(const event &ev1, const event &ev2);

    void add_turnover_time(int turnover);
    void sort_list();

private:
    vector<event> event_list;
};


#endif //TRAIN_TIMETABLE_TRAINMASTER_H
