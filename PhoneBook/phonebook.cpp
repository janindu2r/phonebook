#include "phonebook.h"
#include "ui_phonebook.h"
#include "addrecord.h"

#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

#include <QSortFilterProxyModel>
#include <QStandardItemModel>

#include <QToolButton>

Phonebook::Phonebook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Phonebook)
{
    ui->setupUi(this);

    QStringList title{"Name","Mobile","Email","Address"};


    QObject::connect(ui->searchButton,
                     SIGNAL(clicked()), this,
                     SLOT(on_searchButton_clicked()));

    //Seting User Interface
    ui->tableWidget->setColumnCount(title.size());
    ui->tableWidget->setHorizontalHeaderLabels(title);
    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    QWidget::setFixedSize(500,450);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);


}

Phonebook::~Phonebook()
{
    delete ui;
}

void Phonebook::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open",
                                                    QDir::rootPath(),
                                                    "XML file (*.xml)" );
    if(fileName.isEmpty()){
        return;
    }
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this,"Eror",file.errorString());
        return;
    }
    QDomDocument doc;
    doc.setContent(&file);
    file.close();

    auto root = doc.firstChild().toElement();
    auto  ix = root.firstChild().toElement();
    while(!ix.isNull()){
        auto name = ix.attribute("id");
        auto mobile = ix.firstChild().toElement().text();
        auto email = ix.firstChild().nextSibling().toElement().text();
        auto address = ix.firstChild().nextSibling().nextSibling().toElement().text();
        addContact(Contact(name, mobile, email, address));
        ix = ix.nextSibling().toElement();
    }

}

void Phonebook::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save as"),QDir::rootPath(),tr("XML file (*.xml)"));
    if(filename.isEmpty()){
        return;
    }

    QDomDocument doc;
    //Creates the document
    auto root = doc.createElement("employees");
    doc.appendChild(root);
    const int rowCount = ui->tableWidget->rowCount();

    for(int ix = 0; ix < rowCount; ++ix){
        Contact record(
                    ui->tableWidget->item(ix, NAME)->text(),
                    ui->tableWidget->item(ix, MOBILE)->text(),
                    ui->tableWidget->item(ix, EMAIL)->text(),
                    ui->tableWidget->item(ix, ADDRESS)->text());
        auto varName = doc.createElement("name");
        auto varMobile = doc.createElement("mobile");
        auto varEmail = doc.createElement("email");
        auto varAddress = doc.createElement("address");

        varMobile.appendChild(doc.createTextNode(record.getMobile()));
        varEmail.appendChild(doc.createTextNode(record.getEmail()));
        varAddress.appendChild(doc.createTextNode(record.getAddress()));

        varName.setAttribute("name",record.getName());
        varName.appendChild(varMobile);
        varName.appendChild(varEmail);
        varName.appendChild(varAddress);
        root.appendChild(varName);
    }
    QFile file(filename);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::critical(this, "Error",file.errorString());
        return;
    }
    QTextStream xout(&file);
    xout << doc.toString();
    file.flush();
    file.close();

}

void Phonebook::on_actionAdd_triggered()
{
    AddRecord dialog(this);
    if(dialog.exec() == QDialog::Rejected){
        return;
    }
    addContact(dialog.addContact());
}

void Phonebook::on_actionRemove_triggered()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void Phonebook::addContact(const Contact &passContact)
{
    const int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,NAME,
                             new QTableWidgetItem(passContact.getName()));
    ui->tableWidget->setItem(row , MOBILE,
                             new QTableWidgetItem(passContact.getMobile()));
    ui->tableWidget->setItem(row, EMAIL,
                             new QTableWidgetItem(passContact.getEmail()));
    ui->tableWidget->setItem(row, ADDRESS,
                             new QTableWidgetItem(passContact.getAddress()));
}

void Phonebook::on_searchLineEdit_returnPressed()
{
    QString filter = ui->searchLineEdit->text();
    for( int i = 0; i < ui->tableWidget->rowCount(); ++i )
    {
        bool match = false;
        for( int j = 0; j < ui->tableWidget->columnCount(); ++j )
        {
            QTableWidgetItem *item = ui->tableWidget->item( i, j );
            if( item->text().contains(filter) )
            {
                match = true;
                break;
            }
        }
        ui->tableWidget->setRowHidden(i,!match);

    }
}

void Phonebook::on_searchButton_clicked()
{
    QString filter = ui->searchLineEdit->text();
    for( int i = 0; i < ui->tableWidget->rowCount(); ++i )
    {
        bool filter = false;
        for( int j = 0; j < ui->tableWidget->columnCount(); ++j )
        {
            QTableWidgetItem *item = ui->tableWidget->item( i, j );
            if( item->text().contains(filter) )
            {
                filter = true;
                break;
            }
        }
        ui->tableWidget->setRowHidden(i,!filter);

    }
}
