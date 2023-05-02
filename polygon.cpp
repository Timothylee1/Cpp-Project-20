/*!*****************************************************************************
\File polygon.cpp
\Author Timothy Lee Ke Xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Object-Oriented Programming
\Par Programming Lab #11
\Date 02-04-2022

    \brief
    The purpose of this lab is to program with inheritance and dynamic binding
    (run time polymorphism). Polygons as geometrical shapes have such properties 
    as area, center of mass, perimeter of the border and so on that can be 
    calculated based on their descriptions using relatively simple formulas and 
    algorithms.

  - Polygon
    Non default constuctor that initializes the data members.
  
  - ~Polygon
    Deconstructor.

  - getCount
    Returns the number of shapes.
    
  - getVertices
    Returns the number of vertices.
    
  - print_details
    Prints relevant details for the polygon class.
    
  - getCenter
    Calculates the center point of the vertices.
    
  - getArea
    Calculates and returns the mean of the areas.
*******************************************************************************/
#include "polygon.hpp"
#include <sstream>

int _count = 0;

/******************************************************************************/
/*!
    \brief
    Non default constuctor that initializes the data members.

    \param line
    Contains the line of string of data associated polygon.

    \return 
    Nothing but initializes the data members.
*/
/******************************************************************************/
Polygon::Polygon(std::string& line):Shape(line) {
    std::stringstream ss{line};
    int X{}, Y{};
    char comma;
    Point tmp{};
    
    while (ss >> X >> comma >> Y) {
        tmp.x = X;
        tmp.y = Y;
        vertices.push_back(tmp);
    }
   ++::_count;
}

/******************************************************************************/
/*!
    \brief
    Destructor.

    \return 
    Nothing but decrements the count.
*/
/******************************************************************************/
Polygon::~Polygon() {
    --::_count;
}

/******************************************************************************/
/*!
    \brief
    Returns the number of shapes.

    \return 
    Returns the number of shapes.
*/
/******************************************************************************/
int Polygon::getCount() {
    return ::_count;
}

/******************************************************************************/
/*!
    \brief
    Returns the number of vertices.

    \return 
    Returns the number of vertices.
*/
/******************************************************************************/
std::vector<Point>& Polygon::getVertices() {
    return vertices;
}

/******************************************************************************/
/*!
    \brief
    Prints relevant details for the polygon class.

    \return 
    Nothing but initializes the data members.
*/
/******************************************************************************/
void Polygon::print_details() const {
    Shape::print_details();
    std::cout << "Type = Polygon Shape" << '\n';
    std::cout << "Vertices = ";
    
    for (const Point& i : vertices)
        std::cout << i.x << "," << i.y << " ";
    std::cout << "\n\n";
}

/******************************************************************************/
/*!
    \brief
    Calculates the center point of the vertices.

    \return 
    Returns the Point class object that contains the center.
*/
/******************************************************************************/
Point Polygon::getCenter() const {
    Point center;
    int meanX{}, meanY{};
    int counter;
    
    for (size_t i{}; i < vertices.size(); ++i) {
        counter++;
        meanX += vertices[i].x; meanY += vertices[i].y;
    }
    meanX /= counter; meanY /= counter;
    center.x = meanX; center.y = meanY;
    return center;
}

/******************************************************************************/
/*!
    \brief
    Calculates and returns the mean of the areas.

    \return 
    Returns the mean of the areas.
*/
/******************************************************************************/
double Polygon::getArea() const {
    double area{};
    for (size_t i{}; i < vertices.size(); ++i) {
        int n = 0;
        if (i + 1 < vertices.size())
            n = i + 1;
        else
            n = 0;
        area += 
        (vertices[i].x * vertices[n].y - vertices[i].y * vertices[n].x);
    }
    return area / 2;
}