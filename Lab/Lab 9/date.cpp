/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab Quiz #10
The purpose of this program is to get the date.
*/
#include <iostream>
#include <string>
#include <cmath>
class Date {
    public:
        int month;
        int day;
        int year;
};
std::string formatDate(Date * d) {
    std::string result = "";
    if(d->month == 1) {
        result += "Jan ";
    }
    if(d->month == 2) {
        result += "Feb ";
    }
    if(d->month == 3) {
        result += "Mar ";
    }
    if(d->month == 4) {
        result += "Apr ";
    }
    if(d->month == 5) {
        result += "May ";
    }
    if(d->month == 6) {
        result += "Jun ";
    }
    if(d->month == 7) {
        result += "Jul ";
    }
    if(d->month == 8) {
        result += "Aug ";
    }
    if(d->month == 9) {
        result += "Sep ";
    }
    if(d->month == 10) {
        result += "Oct ";
    }
    if(d->month == 11) {
        result += "Nov ";
    }
    else if(d->month == 12) {
        result += "Dec ";
    }
    result += std::to_string(d->day) + ", " + std::to_string(d->year);
    return result;
}