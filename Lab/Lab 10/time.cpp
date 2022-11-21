/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 10E
The purpose of this program is to see if timeslots overlap.
*/
#include <iostream>
#include <string>
class Time { // Time class with members h and m denoting houra and time.
public:
    int h;
    int m;
};
void printTime(Time time) { // Prints Time
    std::cout << time.h << ":" << time.m;
}
int minutesSinceMidnight(Time time) { // Minutes since Midnight.
    return time.h * 60 + time.m;
}
int minutesUntil(Time earlier, Time later) { // Minutes until earlier goes to after.
    return (later.h - earlier.h)*60 + later.m - earlier.m;
}
Time addMinutes(Time time0, int min) { // adds minutes
    time0.m += min;
    while(time0.m >= 60) { // So we don't get over 60 mins.
        time0.m -= 60;
        time0.h++;
    }
    return time0;
}
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};
class Movie { 
public: 
    std::string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};
class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};
void printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}
void printTimeSlot(TimeSlot ts) {
    printMovie(ts.movie);
    std::cout << " [starts at "; 
    printTime(ts.startTime);
    std::cout << ", ends by ";
    printTime(addMinutes(ts.startTime, ts.movie.duration));
    std::cout << "]" << std::endl;
}
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    ts.startTime = addMinutes(ts.startTime, ts.movie.duration);
    ts.movie = nextMovie;
    return ts;
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    if(minutesUntil(ts1.startTime,ts2.startTime) > 0) {
        ts1.startTime = addMinutes(ts1.startTime, ts1.movie.duration);
        if(minutesUntil(ts1.startTime,ts2.startTime) < 0) {
            return true;
        }
    }
    else {
        ts2.startTime = addMinutes(ts2.startTime, ts2.movie.duration);
        if(minutesUntil(ts2.startTime,ts1.startTime) < 0) {
            return true;
        }
    }
    return false;
}
int main() {
    Movie bp = {"Black Panther", ACTION, 134};
    Time start = {12,15};
    TimeSlot wakanda = {bp, start};
    return 0;
}
