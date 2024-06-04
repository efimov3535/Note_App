#ifndef CATEGORY_REPOSITORY_H
#define CATEGORY_REPOSITORY_H
#include "category.h"
#include <QVector>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

class category_repository
{
private:
    QVector <category*> m_categories;
public:
    category_repository();
    QVector <category*> get_categories();
    category* find_category(QString name);
};

#endif // CATEGORY_REPOSITORY_H
