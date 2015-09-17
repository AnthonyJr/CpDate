//
//  date.h
//  Project 3
//
//  Created by Anthony Terrell Snow Jr. on 11/1/14.
//  Copyright (c) 2014 Anthony Terrell Snow Jr. All rights reserved.
//

#ifndef __Project_3__date__
#define __Project_3__date__

#include <stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
//
//  date.h
//  Project3
//
//  Created by Anthony Terrell Snow Jr. on 10/28/14.
//
//

#ifndef __Project3__date__
#define __Project3__date__

#include <stdio.h>
#include <string>
#include<iostream>
using namespace std;
class Date {
private:
    friend ostream &operator <<(ostream&, Date&);
    friend istream &operator >>(istream&, Date&);
    int month;
    int year;
    int day;
    bool shortDisplay;
public:
    Date();
    Date(int yy, int mm, int dd); // default constructor
    Date(int yy, int mm); // constructor
    Date(int yy); // constructor
    Date(const Date &otherDate); // constructor
    Date(string dateStr); // constructor
    void setDate(int yy, int mm, int dd);
    void setDate(int yy,int mm);
    void setDate(int yy);
    void setDate(const Date& OtherDate);
    void setDate(string dateStr);
    void setYear(int yy);
    void setMonth(int mm);
    void setDay(int dd);
    int Boundary(int);
    int getYear();
    int getMonth();
    int getDay();
    void setShortDisplay();
    void setLongDisplay();
    bool isShortDisplay();
    friend bool operator!=(Date& otherDate,Date& otherDate2);
    Date operator++(int);
    Date operator+=(int);
    friend bool operator==(Date& otherDate, Date& otherDate2);
    friend bool operator<(Date& otherDate, Date& otherDate2);
    string toString();
    string monthString(int month);
    
};


#endif /* defined(__Project3__date__) */

#endif /* defined(__Project_3__date__) */
