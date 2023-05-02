/*!*****************************************************************************
\File process.cpp
\Author Timothy Lee Ke Xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Object-Oriented Programming
\Par Programming Lab #11
\Date 02-04-2022

    \brief
    The purpose of this lab is to program with inheritance and dynamic binding
    (run time polymorphism). process.cpp processes the data from the input file
    stream and parses relevant data over to polygon and ellipse files.

  - parse_file
    Perform some processing on containers of type std::vector<Shape*>.
    
  - print_records
    Use dynamic-binding (run-time polygmorphism) to print details of shapes
    shapes represented in std::vector<Shape*> container.
    
  - compare
    To help in sorting the tmp vector<Shape*> in print_stats.
    
  - print_stats
    Computes and prints following statistics: shape count; mean of total areas; 
    and sorted list of shapes in ASCENDING order using a shape's area as sorting
    criterion with each line consisting of the following information:
    shape id, center, area.

  - cleanup
    Return memory allocated by operator new ONLY using pointers contained
    in container specified by first parameter. Why? Because containers specified
    in the next two containers reference the same memory locations as elements 
    of first container, double deletion will cause undefined run-time behavior.
    Next, clear contents of all 3 containers.
*******************************************************************************/
#include "process.hpp"
#include <algorithm>
#include <iostream>
#include <string>

/******************************************************************************/
/*!
    \brief
    Perform some processing on containers of type std::vector<Shape*>.

    \param ifs
    Input file stream with shapes' data.

    \param vs  
    Reference to vector<Shape*> that will be filled with pointers to every shape
    in file.

    \param ves 
    Reference to vector<Shape*> that will be filled with pointers to ellipse 
    shapes in file.

    \param vps 
    Reference to vector<Shape*> that will be filled with pointers to polygon 
    shapes in file.

    \return 
    Nothing. 
*/
/******************************************************************************/
void parse_file(std::ifstream &ifs, std::vector<Shape*>& vs,
                std::vector<Shape*>& ves, std::vector<Shape*>& vps) {

    std::string line;
    while (std::getline(ifs, line)) {
      char c = line[0];
      line = line.substr(2);

      if (c == 'E') {
        Shape* p = new Ellipse(line);
        vs.push_back(p);
        ves.push_back(p);
      }
      else if (c == 'P') {
        Shape* p = new Polygon(line);
        vs.push_back(p);
        vps.push_back(p);
      }
      else break;
    }
}

/******************************************************************************/
/*!
    \brief
    Use dynamic-binding (run-time polygmorphism) to print details of shapes
    shapes represented in std::vector<Shape*> container. 

    \param vs  
    Read-only reference to std::vector<Shape*>. 

    \return 
    Nothing. 
*/
/******************************************************************************/
void print_records(std::vector<Shape*> const& vs) {
  for (size_t i{}; i < vs.size(); ++i)
    vs[i]->print_details();
}


/******************************************************************************/
/*!
    \brief
    To help in sorting the tmp vector<Shape*> in print_stats.

    \param lhs  
    Pointer to Shape class object.

    \param rhs
    Pointer to Shape class object.

    \return 
    Nothing. 
*/
/******************************************************************************/
bool compare(Shape* lhs, Shape* rhs) {
  return lhs->getArea() < rhs->getArea() ? true : false;
}


/******************************************************************************/
/*!
    \brief
    Computes and prints following statistics: shape count; mean of total areas; 
    and sorted list of shapes in ASCENDING order using a shape's area as sorting
    criterion with each line consisting of the following information:
    shape id, center, area.

    \param vs  
    Read-only reference to vector<Shape*> for which statistics are to be 
    computed.

    \return 
    Nothing. 
*/
/******************************************************************************/
void print_stats(std::vector<Shape*> const& vs) {
  double area{}, mean_area{};
  std::vector<Shape*> tmp = vs;
  std::sort(tmp.begin(), tmp.end(), compare);
  
  for (size_t i{}; i < vs.size(); ++i)
    area += tmp[i]->getArea();
  
  mean_area = area / tmp.size();

  std::cout << "Number of shapes = " << vs.size() << '\n';
  std::cout << "The mean of the areas = " << mean_area << '\n';
  std::cout << "The sorted list of shapes (id,center,area) in ascending"; 
  std::cout << " order of areas:\n";
  for (size_t i{}; i < tmp.size(); ++i) 
    std::cout << tmp[i]->getId() << "," << tmp[i]->getCenter().x << "," 
              << tmp[i]->getCenter().y << "," << tmp[i]->getArea() << '\n';
}

/**
* @brief Return memory allocated by operator new ONLY using pointers contained
* in container specified by first parameter. Why? Because containers specified
* in the next two containers reference the same memory locations as elements of
* first container, double deletion will cause undefined run-time behavior.
* Next, clear contents of all 3 containers.
*
* @param vs Reference to vector<Shape*> containing pointers to all shapes.
* @param ves Reference to vector<Shape*> containing pointers to ellipses.
* @param vps Reference to vector<Shape*> containing pointers to polygons.
*/
void cleanup(std::vector<Shape*>& vs, std::vector<Shape*>& ves, std::vector<Shape*>& vps) {
  // delete memory previously allocated by operator new
  for (Shape *ps : vs)
    delete ps;

  // avoid double deletion!!!
  vs.clear();
  ves.clear();
  vps.clear();
}
