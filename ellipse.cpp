/*!*****************************************************************************
\File ellipse.cpp
\Author Timothy Lee Ke Xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Object-Oriented Programming
\Par Programming Lab #11
\Date 02-04-2022

    \brief
    The purpose of this lab is to program with inheritance and dynamic binding
    (run time polymorphism). Each ellipse in the list has fixed size structure 
    that describes it. Has geometrical shapes have such properties as area, 
    center of mass, perimeter of the border and so on that can be calculated 
    based on their descriptions using relatively simple formulas and algorithms.

  - Ellipse
    Non default constuctor that initializes the data members.
  
  - ~Ellipse
    Deconstructor.

  - getA
    Returns a (a-length, length of the semi-major axis).

  - getB
    Returns b (b-length, length of the semi-minor axis).

  - getCount
    Returns the number of shapes. 
    
  - print_details
    Prints relevant details for the Ellipse class.
    
  - getCenter
    Returns the Point class object that contains the center.
    
  - getArea
    Returns the area of the Ellipse.
*******************************************************************************/
#include "ellipse.hpp"
#include <iostream>
#include <math.h>
#include <sstream>

int Ellipse::count=0;
/******************************************************************************/
/*!
    \brief
    Non default constuctor that initializes the data members.

    \param line
    Contains the line of string of data associated ellipse.

    \return 
    Nothing but initializes the data members.
*/
/******************************************************************************/
Ellipse::Ellipse(std::string& line):Shape(line) {
    std::stringstream ss(line);
    int x, y, A, B;
    char comma;
    while (ss >> x >> comma >> y >> A >> B) {
        center = {x, y}; 
        a = A;
        b = B;
    }
    ++Ellipse::count;
}

/******************************************************************************/
/*!
    \brief
    Destructor.

    \return 
    Nothing but decrements the count.
*/
/******************************************************************************/
Ellipse::~Ellipse() {
    --Ellipse::count;
}

/******************************************************************************/
/*!
    \brief
    Returns a (a-length, length of the semi-major axis).

    \return 
    Returns a (a-length, length of the semi-major axis).
*/
/******************************************************************************/
int Ellipse::getA() const {
    return a;
}

/******************************************************************************/
/*!
    \brief
    Returns b (b-length, length of the semi-minor axis).

    \return 
    Returns b (b-length, length of the semi-minor axis). 
*/
/******************************************************************************/
int Ellipse::getB() const {
    return b;
}

/******************************************************************************/
/*!
    \brief
    Returns the number of shapes.

    \return 
    Returns the number of shapes.
*/
/******************************************************************************/
int Ellipse::getCount() {
    return Ellipse::count;
}

/******************************************************************************/
/*!
    \brief
    Prints relevant details for the Ellipse class.

    \return 
    Nothing but initializes the data members.
*/
/******************************************************************************/
void Ellipse::print_details() const {
    Shape::print_details();
    std::cout << "Type = Ellipse Shape" << '\n';
    std::cout << "Center = " << center.x << "," << center.y << '\n';
    std::cout << "a-length = " << a << '\n';
    std::cout << "b-length = " << b << "\n\n";
}

/******************************************************************************/
/*!
    \brief
    Returns the Point class object that contains the center.

    \return 
    Returns the Point class object that contains the center.
*/
/******************************************************************************/
Point Ellipse::getCenter() const {
    return center;
}

/******************************************************************************/
/*!
    \brief
    Returns the area of the Ellipse.

    \return 
    Returns the area of the Ellipse.
*/
/******************************************************************************/
double Ellipse::getArea() const {
    return (double)(a * b * M_PI);
}

