#include "addrecord.h"
#include "ui_addrecord.h"

AddRecord::AddRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecord)
{
    ui->setupUi(this);

}

AddRecord::~AddRecord()
{
    delete ui;
}

Contact AddRecord::addContact()
{
    return varContact;
}

void AddRecord::on_buttonBox_accepted()
{
    varContact.setName(ui->nameLineEdit->text());
    varContact.setMobile(ui->mobileNoLineEdit->text());
    varContact.setEmail(ui->emailLineEdit->text());
    varContact.setAddress(ui->addressLineEdit->text());
    accept();
}

void AddRecord::on_buttonBox_rejected()
{
    reject();
}
