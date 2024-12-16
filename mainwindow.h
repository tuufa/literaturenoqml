#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include "factorybook.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addBook();
    void deleteBook();
    void markAsRead();
    void exportFromJSON();
    void importToJSON();
    void recommendBook();

private:
    Ui::MainWindow *ui;

    void createButtonHandlers();
    double cosineSimilarity(const QVector<double>& A, const QVector<double>& B);


};

#endif // MAINWINDOW_H
