#ifndef ADDRECORD_H
#define ADDRECORD_H

#include <QDialog>
#include <contact.h>

namespace Ui {
class AddRecord;
}

class AddRecord : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecord(QWidget *parent = nullptr);
    ~AddRecord();

    Contact addContact();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddRecord *ui;

    Contact varContact;
};

#endif // ADDRECORD_H
