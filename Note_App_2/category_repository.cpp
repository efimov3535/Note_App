#include "category_repository.h"

category_repository::category_repository()
{
    QFile file("categories.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        category* cat;
        QString name = in.readLine();
        cat = new category(name);
        m_categories.push_back(cat);
    }
    file.close();
}


QVector <category*> category_repository::get_categories()
{
    return m_categories;
}

category *category_repository::find_category(QString name)
{
    for(auto d : m_categories)
    {
        if(d->get_name() == name)
            return d;
    }
}
