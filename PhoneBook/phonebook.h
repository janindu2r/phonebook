#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include <contact.h>

namespace Ui {
class Phonebook;
}

class Phonebook : public QMainWindow
{
    Q_OBJECT

public:
    explicit Phonebook(QWidget *parent = nullptr);
    ~Phonebook();

    void getSaveFileNameWithExtension();
    
private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionAdd_triggered();

    void on_actionRemove_triggered();

    void on_searchLineEdit_returnPressed();

    void on_searchButton_clicked();

private:
    enum{
        NAME,
        MOBILE,
        EMAIL,
        ADDRESS
    };

    void addContact(const Contact &passContact);
    Ui::Phonebook *ui;
};

#endif // PHONEBOOK_H
