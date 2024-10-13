#include "Model.h"


void Doc::save(const Figure& figure)
{
    mydB.push_back(figure);
}

void Doc::remove(const Figure& figure)
{
    for (auto iter = mydB.cbegin(); iter != mydB.cend(); ++iter) {
        if (*iter == figure) {
            mydB.erase(iter);
        }
    }
}

bool Figure::operator==(const Figure& figure) const
{
    return m_center.get_x() == figure.m_center.get_x() &&
        m_center.get_y() == figure.m_center.get_y();
}
