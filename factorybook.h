#ifndef FACTORYBOOK_H
#define FACTORYBOOK_H

#include <QTableWidgetItem>
#include <QString>
#include <QVector>

class FactoryBook
{
public:
    static QVector<QTableWidgetItem*> createBookRow(
        const QString &title, const QString &category, int rating,
        const QString &author, const QString &date, const QString &difficulty
        );
};

#endif // FACTORYBOOK_H
