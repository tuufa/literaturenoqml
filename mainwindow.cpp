#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "factorybook.h"
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QVector>
#include <QMap>
#include <cmath>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createButtonHandlers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createButtonHandlers()
{
    connect(ui->pushButton_add, &QPushButton::clicked, this, &MainWindow::addBook);
    connect(ui->pushButton_delete, &QPushButton::clicked, this, &MainWindow::deleteBook);
    connect(ui->pushButton_checked, &QPushButton::clicked, this, &MainWindow::markAsRead);
    connect(ui->pushButton_export, &QPushButton::clicked, this, &MainWindow::exportFromJSON);
    connect(ui->pushButton_import, &QPushButton::clicked, this, &MainWindow::importToJSON);
    connect(ui->pushButton_recommend, &QPushButton::clicked, this, &MainWindow::recommendBook);
}

void MainWindow::addBook()
{
    QString title = ui->lineEdit_title->text();
    QString category = ui->comboBox_category->currentText();
    int rating = ui->spinBox_rating->value();
    QString author = ui->lineEdit_author->text();
    QString date = ui->dateEdit_date->date().toString("dd.MM.yyyy");
    QString difficulty = ui->comboBox_difficulty->currentText();

    if (title.isEmpty() || author.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Название и автор книги обязательны для заполнения.");
        return;
    }

    QVector<QTableWidgetItem*> rowItems = FactoryBook::createBookRow(title, category, rating, author, date, difficulty);

    // Добавляем строку в таблицу
    int row = ui->tableWidget_books->rowCount();
    ui->tableWidget_books->insertRow(row);

    for (int col = 0; col < rowItems.size(); ++col)
    {
        ui->tableWidget_books->setItem(row, col, rowItems[col]);
    }
}

void MainWindow::deleteBook()
{
    int row = ui->tableWidget_books->currentRow();
    if (row >= 0)
    {
        ui->tableWidget_books->removeRow(row);
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Выберите книгу для удаления.");
    }
}

void MainWindow::markAsRead()
{
    int row = ui->tableWidget_books->currentRow();
    if (row >= 0)
    {
        QTableWidgetItem *statusItem = ui->tableWidget_books->item(row, 6);
        if (statusItem)
        {
            QString currentStatus = statusItem->text();
            if (currentStatus == "Не прочитано")
            {
                statusItem->setText("Прочитано");
            }
            else if (currentStatus == "Прочитано")
            {
                statusItem->setText("Не прочитано");
            }
        }
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Выберите книгу для изменения статуса.");
    }
}


void MainWindow::importToJSON()
{
    // Выбор файла для сохранения
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить в JSON файл", "", "JSON Files (*.json)");
    if (fileName.isEmpty())
    {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи: " + file.errorString());
        return;
    }

    QJsonArray jsonArray;

    int rowCount = ui->tableWidget_books->rowCount();
    int columnCount = ui->tableWidget_books->columnCount();

    for (int row = 0; row < rowCount; ++row)
    {
        QJsonObject bookObject;

        // Заполняем объект данными из таблицы
        bookObject["title"] = ui->tableWidget_books->item(row, 0)->text();
        bookObject["category"] = ui->tableWidget_books->item(row, 1)->text();
        bookObject["rating"] = ui->tableWidget_books->item(row, 2)->text().toInt();
        bookObject["author"] = ui->tableWidget_books->item(row, 3)->text();
        bookObject["date"] = ui->tableWidget_books->item(row, 4)->text();
        bookObject["difficulty"] = ui->tableWidget_books->item(row, 5)->text();
        bookObject["status"] = ui->tableWidget_books->item(row, 6)->text();

        jsonArray.append(bookObject);
    }

    // Записываем JSON массив в файл
    QJsonDocument jsonDoc(jsonArray);
    file.write(jsonDoc.toJson(QJsonDocument::Indented));
    file.close();

    QMessageBox::information(this, "Успех", "Данные успешно сохранены в файл: " + fileName);
}

void MainWindow::exportFromJSON()
{
    // Выбор JSON файла
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите JSON файл", "", "JSON Files (*.json)");
    if (fileName.isEmpty())
    {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл: " + file.errorString());
        return;
    }

    // Чтение содержимого файла
    QByteArray fileData = file.readAll();
    file.close();

    // Парсинг JSON
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    if (!jsonDoc.isArray())
    {
        QMessageBox::warning(this, "Ошибка", "Некорректный формат JSON: ожидается массив.");
        return;
    }

    QJsonArray jsonArray = jsonDoc.array();

    // Заполнение таблицы из JSON
    for (const QJsonValue &value : jsonArray)
    {
        if (!value.isObject())
        {
            QMessageBox::warning(this, "Ошибка", "Некорректный формат JSON: массив должен содержать объекты.");
            return;
        }

        QJsonObject bookObject = value.toObject();

        QString title = bookObject.value("title").toString();
        QString category = bookObject.value("category").toString();
        int rating = bookObject.value("rating").toInt();
        QString author = bookObject.value("author").toString();
        QString date = bookObject.value("date").toString();
        QString difficulty = bookObject.value("difficulty").toString();
        QString status = bookObject.value("status").toString("Не прочитано");

        int row = ui->tableWidget_books->rowCount();
        ui->tableWidget_books->insertRow(row);
        ui->tableWidget_books->setItem(row, 0, new QTableWidgetItem(title));
        ui->tableWidget_books->setItem(row, 1, new QTableWidgetItem(category));
        ui->tableWidget_books->setItem(row, 2, new QTableWidgetItem(QString::number(rating)));
        ui->tableWidget_books->setItem(row, 3, new QTableWidgetItem(author));
        ui->tableWidget_books->setItem(row, 4, new QTableWidgetItem(date));
        ui->tableWidget_books->setItem(row, 5, new QTableWidgetItem(difficulty));
        ui->tableWidget_books->setItem(row, 6, new QTableWidgetItem(status));
    }

    QMessageBox::information(this, "Успех", "Данные успешно загружены из JSON файла.");
}

void MainWindow::recommendBook()
{
    QVector<QVector<double>> bookVectors;
    QVector<QString> bookTitles;
    QVector<QVector<double>> unreadBookVectors;
    QVector<QString> unreadBookTitles;


    QMap<QString, double> genreWeights =
    {
        {"Фантастика", 4},
        {"Фэнтези", 10},
        {"Детектив", 2},
        {"Роман", 7},
        {"Научная литература", 10},
        {"История", 8},
        {"Биография", 1},
        {"Поэзия", 4},
        {"Триллер", 7},
        {"Приключения", 8}
    };

    // Собираем данные о прочитанных книгах
    for (int row = 0; row < ui->tableWidget_books->rowCount(); ++row)
    {
        // Проверяем статус книги (прочитано или нет)
        QString status = ui->tableWidget_books->item(row, 6)->text();

        if (status == "Прочитано")
        {
            // Собираем характеристики книги в вектор
            QVector<double> bookVector;

            double rating = ui->tableWidget_books->item(row, 2)->text().toDouble();
            QString difficulty = ui->tableWidget_books->item(row, 5)->text();
            double difficultyValue = (difficulty == "Легкая") ? 1.0 : (difficulty == "Средняя") ? 2.0 : 3.0;
            QString genre = ui->tableWidget_books->item(row, 2)->text();
            double genreWeight = genreWeights.contains(genre) ? genreWeights[genre] : 0;

            bookVector.append(rating);
            bookVector.append(difficultyValue);
            bookVector.append(genreWeight);

            bookVectors.append(bookVector);
            bookTitles.append(ui->tableWidget_books->item(row, 0)->text());
        }
        else if (status == "Не прочитано")
        {
            // Собираем характеристики непрочитанной книги в вектор
            QVector<double> unreadBookVector;

            double rating = ui->tableWidget_books->item(row, 2)->text().toDouble();
            QString difficulty = ui->tableWidget_books->item(row, 5)->text();
            double difficultyValue = (difficulty == "Легкая") ? 1.0 : (difficulty == "Средняя") ? 2.0 : 3.0;
            QString genre = ui->tableWidget_books->item(row, 2)->text();
            double genreWeight = genreWeights.contains(genre) ? genreWeights[genre] : 0;

            unreadBookVector.append(rating);
            unreadBookVector.append(difficultyValue);
            unreadBookVector.append(genreWeight);

            unreadBookVectors.append(unreadBookVector);
            unreadBookTitles.append(ui->tableWidget_books->item(row, 0)->text());
        }
    }

    if (bookVectors.isEmpty() || unreadBookVectors.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Нет данных для рекомендации.");
        return;
    }

    int mostSimilarIndex = -1;
    double highestSimilarity = -1;

    for (int i = 0; i < unreadBookVectors.size(); ++i)
    {
        QVector<double> unreadBookVector = unreadBookVectors[i];

        for (int j = 0; j < bookVectors.size(); ++j)
        {
            double similarity = cosineSimilarity(unreadBookVector, bookVectors[j]);

            if (similarity > highestSimilarity)
            {
                highestSimilarity = similarity;
                mostSimilarIndex = i;
            }
        }
    }

    // Выводим рекомендованную книгу
    if (mostSimilarIndex != -1)
    {
        QString recommendedBook = unreadBookTitles[mostSimilarIndex];
        QMessageBox::information(this, "Рекомендация", "Рекомендуем вам прочитать: " + recommendedBook);
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось найти подходящую книгу для рекомендации.");
    }
}

// Косинусное сходство
double MainWindow::cosineSimilarity(const QVector<double>& A, const QVector<double>& B)
{
    double dotProduct = 0;
    double normA = 0;
    double normB = 0;

    for (int i = 0; i < A.size(); ++i)
    {
        dotProduct += A[i] * B[i];
        normA += A[i] * A[i];
        normB += B[i] * B[i];
    }

    return dotProduct / (sqrt(normA) * sqrt(normB));
}





