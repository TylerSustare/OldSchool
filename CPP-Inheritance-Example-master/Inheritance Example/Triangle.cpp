//
//  Triangle.cpp
//  Inheritance Example
//
//  Created by MacBook Air on 6/9/15.
//  Copyright (c) 2015 MacBook Air. All rights reserved.
//

#include <stdio.h>
#include "Triangle.h"

Triangle::Triangle() : height{0}{}
Triangle::Triangle(int newHeight) : height{newHeight}{}

int Triangle::getHeight() const {return height;}

void Triangle::setHeight(int newHeight){
    height = newHeight;
}

double Triangle::getArea(int base) const {
    return (0.5 * base * height);
}

Triangle::~Triangle(){}


