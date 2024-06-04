#include "category.h"

category::category(QString name)
{
    m_name = name;
}

QString category::get_name()
{
    return m_name;
}
