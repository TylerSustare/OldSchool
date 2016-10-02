//
//  Isosceles.cpp
//  Inheritance Example
//
//  Created by MacBook Air on 6/9/15.
//  Copyright (c) 2015 MacBook Air. All rights reserved.
//

#include "Isosceles.h"

Isosceles::Isosceles(): base{0}{}
Isosceles::Isosceles(int newBase, int newSideOne, int newHeight)
: Triangle(newHeight){  // used to initialize the height witht the Triangle constructor
    base = newBase;
    sideOne = newSideOne;
}

int Isosceles::getBase() const {
    return base;
}

int Isosceles::getSideOne() const {
    return sideOne;
}

void Isosceles::setBase(int newBase){
    base = newBase;
}

void Isosceles::setSideOne(int newSideOne){
    sideOne = newSideOne;
}

int Isosceles::getPerimeter() const{
    return ((2 * sideOne) + base);
}

void Isosceles::printInfo() const{
    cout << endl << "Perimeter: " << getPerimeter() << endl;
    cout << "Area: " << getArea(base) << endl;
}

Isosceles::~Isosceles(){}