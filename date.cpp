//
//  date.cpp
//  Project 3
//
//  Created by Anthony Terrell Snow Jr. on 11/1/14.
//  Copyright (c) 2014 Anthony Terrell Snow Jr. All rights reserved.
//

#include "date.h"

// overloading the "<<" i=operator to be used with my class
ostream& operator<<(ostream& Output, Date& DateC){
    /*right here im using a conditional statement to decide which
     form to output. if true, it will use the short display, which uses
     slashes.if it is false, it will use the long display
     parameters are the ostream and referenced date class.
     returns output
     */
    if (DateC.shortDisplay == true) {
        Output << DateC.getMonth();
        Output << "/";
        Output << DateC.getDay();
        Output << "/";
        Output << DateC.getYear();
        return Output;
    } else if (DateC.shortDisplay == false){
        Output << DateC.monthString(DateC.getMonth());
        Output << "";
        Output << DateC.getDay();
        Output << ",";
        Output << DateC.getYear();
    }
    
    return Output;
}
/* overloading the ">>" opertaor so i can get input from the user.
 still uses the boundary testing and all. parameters are */
istream& operator>>(istream& Input, Date& refDate){
    cout << " enter a year " << endl;
    refDate.setYear(refDate.year);
    cout << " enter a month" << endl;
    refDate.setMonth(refDate.month);
    cout << " enter a day" << endl;
    refDate.setDay(refDate.day);
    return Input;
}
/* first constructor, if the object is just declared, it will give you the current date. also sets
 the display to true for default*/
Date::Date(){
    shortDisplay = true;
    time_t t = time(0);
    struct tm*  now = localtime(&t);
    setYear((now->tm_year + 1900));
    setMonth((now->tm_mon + 1));
    setDay((now->tm_mday));
    
    
    
}
/* this is the second contructor, if the user gives input for all parameters, it will check the
 boundary and give that value to the variables*/
Date::Date(int yy, int mm, int dd){
    shortDisplay = true;
    setDate(yy, mm, dd);
}
/*this constructor is if the user gives the first two varibables, but leaves the last one blank, giving
 you a default value 1 for day*/
Date::Date(int yy, int mm){
    shortDisplay = true;
    year = yy;
    month = mm;
    day = 1;
}
/*this constructor is for is the user only puts in a year. returns default of 1values for day and month*/
Date::Date(int yy){
    shortDisplay = true;
    setYear(yy);
    day = 1;
    month = 1;
}
/* this constructor gives default values*/
Date::Date(const Date &otherDate){
    shortDisplay = true;
    day = otherDate.day;
    month = otherDate.month;
    year = otherDate.year;
}
/* constructor gives default value of January 1, 1900*/
Date::Date(string dateStr){
    shortDisplay = true;
    setDate(dateStr);
}
/* the set functions actually make sure that the values you entered are within boundaries, if not, gives
 default values*/
void Date::setDate(int yy, int mm, int dd) {
    setYear(yy);
    setMonth(mm);
    setDay(dd);
}

void Date::setDate(int yy, int mm){
    setYear(yy);
    setMonth(mm);
    day = 1;
}

void Date::setDate(int yy){
    setYear(yy);
    month = 1;
    day = 1;
}

void Date::setDate(const Date& Otherdate){
    Date refDate;
    refDate = Otherdate;
}
/*I feel like i made this part extremely complicated. but it basically sets the date from a string*/
void Date::setDate(string dateStr){
    
    string day;
    string month;
    string year;
    if ((dateStr.substr(1,1) =="/") && (dateStr.substr(3,1) == "/")){
        //cout << " you are inside the 1 and 3!!!!" << endl;
        setYear(stoi(dateStr.substr(4,4)));
        setDay(stoi(dateStr.substr(2,1)));
        setMonth(stoi(dateStr.substr(0,1)));
        
        
    } else if((dateStr.substr(1,1) == "/") && (dateStr.substr(4,1) == "/")){
        //cout << " you are inside the 1 and 4!!!!!";
        setYear(stoi(dateStr.substr(5,4)));
        setDay(stoi(dateStr.substr(2,2)));
        setMonth(stoi(dateStr.substr(0,1)));
        
        
    } else if((dateStr.substr(2,1) == "/") && (dateStr.substr(5,1) == "/")){
        //cout << " you are inside the 2 and 5!!!!!";
        setYear(stoi(dateStr.substr(6,4)));
        setDay(stoi(dateStr.substr(3,2)));
        setMonth(stoi(dateStr.substr(0,2)));
        
        
        
    } else if((dateStr.substr(2,1) == "/") && (dateStr.substr(4,1) == "/")){
        //cout << "you are inside the 2 and 4!!!!";
        setYear(stoi(dateStr.substr(5,4)));
        setDay(stoi(dateStr.substr(3,1)));
        setMonth(stoi(dateStr.substr(0,2)));
        
        
    } else {
        setDay(1);
        setYear(1900);
        setMonth(1);
    }
}
// if the year is less than 1900, give back 1. if not, use that year
void Date::setYear(int yy){
    if (yy >=1900){
        year = yy;
    } else {
        year = 1;
    }
}
// if month isnt between 1 and 12, give back one. if not use that month
void Date::setMonth(int mm){
    if ((mm <=12) && (mm >=1)){
        month = mm;
    } else {
        month = 1;
    }
}

//void Date::setDay(int dd){
//
// // this one will get tricky bc of different days in a month
////maybe make a little swich statement?
//    if ((dd <=30) && (dd >= 1)) {
//        day = dd;
//    }
//    else {
//        day = 1;
//    }
//}


int Date::getYear(){return year;}


int Date::getMonth(){return month;}      


int Date::getDay() {return day;}

// THIS FUNCTION TURNS THE SHORT DISPLAY INTO THE LONG DISPLAY
string Date::monthString(int month){
    switch (month) {
        case 1:
            return "January ";
            break;
        case 2:
            return "February ";
            break;
        case 3:
            return "March ";
            break;
        case 4:
            return "April ";
            break;
        case 5:
            return "May ";
            break;
        case 6:
            return "June ";
            break;
        case 7:
            return "July ";
            break;
        case 8:
            return "August ";
            break;
        case 9:
            return "September ";
            break;
        case 10:
            return "October ";
            break;
        case 11:
            return "November ";
            break;
        case 12:
            return "December ";
            break;
            
            
        default:
            return "Neveruary ";
            break;
    }
    return " basegod ";
}
// END OF MONTHSTRING FUNCTION


void Date::setShortDisplay(){
    shortDisplay = true;
}                           // second hardest part of the program. basically a flag
// to say what display to use

void Date::setLongDisplay(){
    shortDisplay = false;
}
// overloading operators are surprisingly easy.  this one is able to see if two date objects are equal
bool operator==(Date& otherDate, Date& otherDate2){
    bool ans;
    if ((otherDate.year) == otherDate2.year){ //if years are equal.
        if ((otherDate.month) == (otherDate2.month)){//and if month is equal
            if((otherDate.day) == (otherDate2.day)){ // and if day is equal
                ans = true; // the objects are equal! so return true
            }
        }
    }
    else {ans = false;} //if not, return false
    return ans;
    
}
// this one
bool operator<(Date& otherDate, Date& otherDate2){
    bool ans = false;
    if (otherDate.year < otherDate2.year){ // if date 2 is bigger, its automatically true
        ans = true;
    } else if (otherDate.year == otherDate2.year){ // if the years are equal, we check month
        if (otherDate.month < otherDate2.month){   // if month 2 is bigger, its true
            ans = true;
        } else if (otherDate.month == otherDate2.month){ //if month are equal, we check day.
            if (otherDate.day < otherDate2.day){ //if month 2 is bigger, its true
                ans = true;
            }
        }
    }
    return ans;
}
// not equal overlaoded function!!!!
bool operator!=(Date& otherDate,Date& otherDate2){
    bool ans;
    if (otherDate.year != otherDate2.year) { // if theyre not equal, its true.
        ans = true;
    } else if (otherDate.month != otherDate2.month){ // if theyre not equal, its true
        ans = true;
    } else if (otherDate.day != otherDate2.day){ // if theyre not equal, its true
        ans = true;
    } else {ans = false;} // if they are, its false
    return ans;
}


// increment day by 1. rolling over days and months (why cant they all have the same number of day
Date Date::operator++(int){
    Date d(year, month, day);
    day++; //add one to the day
    if (day >= Boundary(month)) { // if the day goes over that months boundary, +1 month
        ++month;
        day = 1;
        if (month >=12) { // if month is greater than twelve, add one to year;
            ++year;
            month = 1;
            if (year >=9999) { // if year is bigger than 9999, go back to the 1900s
                year = 1900;
            }
        }
    }
    return d;
}

//basically used the same logic from the increment by one funtion, but added a for loop
Date Date::operator+=(int num){
    Date d(year, month, day);
    for (int i = 0; i <num; i++) {
        ++day;
        if (day >= Boundary(month)) {
            i++;
            ++month;
            day = 1;
            if (month >=12) {
                ++year;
                month = 1;
                if (year >=9999) {
                    year = 1;
                }
            }
        }
    }
    return d;
}
/*uses the boundary funtion to set the date. */
void Date::setDay(int dd){
    
    switch (month) {
        case 1: // happy new years!!
            if ((dd >=1) && (dd <=31)) {
                day = dd;
            } else {day = 1;}
            break;
        case 2:
            if ((dd >=1) && (dd <=28)){
                day = dd;
            } else {day = 1;}
            break;
        case 3:
            if ((dd >=1) && (dd <=31)) {
                day = dd;
            } else {day = 1;}
            break;
        case 4:
            if ((dd >=1) && (dd <=30)) {
                day = dd;
            } else {day = 1;}
            break;
        case 5: // mothersday?
            if ((dd >=1) && (dd <=31)){
                day = dd;
            } else {day = 1;}
            break;
        case 6: //summer time!
            if ((dd>=1) && (dd <=30)){
                day = dd;
            } else {day = 1;}
            break;
        case 7: //fireworks
            if ((dd>=1) && (dd <=31)){
                day = dd;
            } else {day = 1;}
            break;
        case 8: // moms bday
            if ((dd>=1) && (dd <= 31)){
                day = dd;
            } else {day = 1;}
            break;
        case 9: // merica
            if ((dd >=1) && (dd <=30)) {
                day = dd;
            } else {day = 1;}
            break;
        case 10: //boooo
            if ((dd >=1) && (dd <=31)){
                day = dd;
            } else {day = 1;}
            break;
        case 11: // gobble
            if ((dd>=1) && (dd<=30)){
                day = dd;
            } else {day = 1;}
            break;
        case 12: // fa la la la
            if ((dd <= 1) && (dd <= 31)){
                day = dd;
            } else {day = 1;}
            break;
            
            
        default:
            day = 1;
            break;
    }
}
/*checks the bounadry for the month, returning a day*/
int Date::Boundary(int month){
    switch (month) {
        case 1:
            return 31;
            break;
        case 2:
            return 28;
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 31;
            break;
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
        default:
            return 1;
            break;
    }
}
/*returns the date as a string*/
string Date::toString(){
    
    stringstream convertday;
    stringstream convertmonth;
    stringstream convertyear;
    string Result;
    convertday << day;
    convertmonth << month;
    convertyear << year;
    Result = convertmonth.str() + "/" + convertday.str(); + "/" + convertyear.str();
    
    
    return Result;
    
    
    
}