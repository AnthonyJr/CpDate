//
//  main.cpp
//  Project 3
//
//  Created by Anthony Terrell Snow Jr. on 11/1/14.
//  Copyright (c) 2014 Anthony Terrell Snow Jr. All rights reserved.
// Last modified  11/7/2014
//the purpose of this program is to
//compare and manipualte dates given to us from the user

#include <iostream>
#include "date.h"
//where the magic happens
int main(){
    Date d;
    cout << d << endl;
    d.setLongDisplay();
    cout << d << endl;
    Date d1;
    Date d2;
    if (d1.toString() != d2.toString()) { // making sure the date compared to is current using object d2.
        cout << "error creating date!! " << endl;
    }
    
    
    d1.setDate("10/17/2014"); // setting the date using a string
    Date d3(2014,10,17);
    if (d1.toString() != d3.toString()) {
        cout << "error setting date " << endl;
    }
    
    d1.setDay(28);
    d1+=5;
    cout << d1 << endl;
    return 0;
}



