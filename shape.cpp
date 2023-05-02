/*!*****************************************************************************
\File shape.cpp
\Author Timothy Lee Ke Xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Object-Oriented Programming
\Par Programming Lab #11
\Date 02-04-2022

    \brief
    The purpose of this lab is to program with inheritance and dynamic binding
    (run time polymorphism). The base class which all other cpp files like
    polygon, ellipse, and process uses. Storing and handling of a list of shapes 
    that consists of a mix of such different elements as ellipses and polygons.

  - Shape
    Non default constuctor that initializes the data members.
  
  - ~Shape
    Deconstructor.

  - getID
    Returns the id.

  - getBorder
    Returns the border.

  - getFill
    Returns the fill.

  - getCount
    Returns the number of shapes.
    
  - print_details
    Prints relevant details for the Shape class.
*******************************************************************************/
#include "shape.hpp"
#include <iostream>
#include <sstream>

int Shape::count = 0; //for static declared count in shape.hpp

/******************************************************************************/
/*!
    \brief
    Non default constuctor that initializes the data members.

    \param line
    Contains the line of string of data associated shape.

    \return 
    Nothing but initializes the data members.
*/
/******************************************************************************/
Shape::Shape(std::string& line) {
    std::stringstream ss(line);
    ss >> border;
    ss >> fill;
    line = line.substr(border.size() + fill.size() + 1);
    ++Shape::count;
    id = Shape::count;
}

/******************************************************************************/
/*!
    \brief
    Destructor.

    \return 
    Nothing but decrements the count.
*/
/******************************************************************************/
Shape::~Shape() {
    --Shape::count;
}

/******************************************************************************/
/*!
    \brief
    Returns the id.

    \return 
    Returns the id.
*/
/******************************************************************************/
int Shape::getId() const {
    return id;
}

/******************************************************************************/
/*!
    \brief
    Returns the border.

    \return 
    Returns the border.
*/
/******************************************************************************/
std::string Shape::getBorder() const {
    return border;
}

/******************************************************************************/
/*!
    \brief
    Returns the fill.

    \return 
    Returns the fill.
*/
/******************************************************************************/
std::string Shape::getFill() const {
    return fill;
}

/******************************************************************************/
/*!
    \brief
    Returns the number of shapes.

    \return 
    Returns the number of shapes.
*/
/******************************************************************************/
int Shape::getCount() {
    return Shape::count;       // this keyword use only for non static member function
}

/******************************************************************************/
/*!
    \brief
    Prints relevant details for the Shape class.

    \return 
    Nothing but initializes the data members.
*/
/******************************************************************************/
void Shape::print_details() const {
    std::cout << "Id = " << id << '\n';
    std::cout << "Border = " << border << '\n';
    std::cout << "Fill = " << fill << '\n';
}

