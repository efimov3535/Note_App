#ifndef CATEGORY_H
#define CATEGORY_H
#include <QString>

class category
{
private:
    QString m_name;
public:
    category(QString name);
    QString get_name();
};

#endif // CATEGORY_H
