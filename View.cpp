#include "View.h"
#include <iostream>


void View::showMenu() const
{
    std::cout << "1: Create new document" << std::endl;
    std::cout << "2: Import a document from file" << std::endl;
    std::cout << "3: Export a document to file" << std::endl;
    std::cout << "4: Create a graphical figure" << std::endl;
    std::cout << "5: Delete a graphical figure" << std::endl;
}

int View::getMenuItem() const
{
    int nMenuItem;
    std::cin >> nMenuItem;
    return nMenuItem;
}

void View::showDoc(std::unique_ptr<Doc> pDoc) const
{
    (void)pDoc;    
}

Point2D View::getPoint() const
{
    return Point2D();
}

Figure View::getFigure(const Point2D& point) const
{
    return Figure(point);
}

void View::showFigure(const Figure* pFigure)
{
    (void)pFigure;
    std::cout << "show figure" << std::endl;
}

std::string View::setPath() const
{
    std::string path = getPath();
    return path;
}

std::string View::getPath() const
{
    return std::string();
}
