#pragma once

#include "Model.h"
#include <string>
#include <memory>


class View
{    
    public:
        View() {}
        void showMenu() const;
        int getMenuItem() const;        
        Point2D getPoint() const; 
        void showDoc(std::unique_ptr<Doc> pDoc) const;
        
        Figure getFigure(const Point2D & point) const;
        void showFigure(const Figure* pFigure);
        std::string setPath() const;
        std::string getPath() const;     
};

