#include "factorybook.h"


QVector<QTableWidgetItem*> FactoryBook::createBookRow(
    const QString &title, const QString &category, int rating,
    const QString &author, const QString &date, const QString &difficulty)
{
    QVector<QTableWidgetItem*> rowItems;
    rowItems.append(new QTableWidgetItem(title));
    rowItems.append(new QTableWidgetItem(category));
    rowItems.append(new QTableWidgetItem(QString::number(rating)));
    rowItems.append(new QTableWidgetItem(author));
    rowItems.append(new QTableWidgetItem(date));
    rowItems.append(new QTableWidgetItem(difficulty));
    rowItems.append(new QTableWidgetItem("Не прочитано"));
    return rowItems;
}
