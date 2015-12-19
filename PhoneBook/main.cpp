#include "phonebook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication program(argc, argv);
    program.setStyle("fusion");
    Phonebook w;
    w.show();

    return program.exec();
}
