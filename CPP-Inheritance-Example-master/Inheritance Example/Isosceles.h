//
//  Isosceles.h
//  Inheritance Example
//
//  Created by MacBook Air on 6/9/15.
//  Copyright (c) 2015 MacBook Air. All rights reserved.
//

#ifndef __Inheritance_Example__Isosceles__
#define __Inheritance_Example__Isosceles__

#include <stdio.h>
#include "Triangle.h"
using namespace std;
class Isosceles : public Triangle {
public:
    Isosceles();
    Isosceles(int, int, int);
    
    void setSideOne(int);
    void setBase(int);
    
    int getBase() const;
    int getSideOne() const;
    int getPerimeter() const;
    void printInfo() const;
    ~Isosceles();
private:
    int base;
    int sideOne;
};
#endif /* defined(__Inheritance_Example__Isosceles__) */
