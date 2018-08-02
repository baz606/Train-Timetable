//
// Created by Shehbaz Khan
//

#ifndef TRAIN_TIMETABLE_EVENT_H
#define TRAIN_TIMETABLE_EVENT_H

#include <iostream>
#include "fullTime.h"

using namespace std;

struct event
{
    string trip_type;
    string journey;
    fullTime time;
};

#endif //TRAIN_TIMETABLE_EVENT_H
