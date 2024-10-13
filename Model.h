#pragma once

#include <vector>


class Point2D
{
public:
    Point2D(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    int get_x() const { return x; }
    int get_y() const { return y; }
        
private:
    int x;
    int y;      
};

class Figure
{
public:
    Figure(Point2D _point) : m_center(_point) {}
    bool operator==(const Figure& figure) const;       

private:
    Point2D m_center;
};

class Doc
{
public:            
    Doc() {}
    Doc(const Doc&) = delete;
    Doc(Doc&&) = default;

    Doc& operator=(const Doc&) = delete;
    Doc& operator=(Doc&&) = default;

    void save(const Figure& figure);
    void remove(const Figure& figure);

private:        
    std::vector<Figure> mydB;        
};

