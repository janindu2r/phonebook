#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{

public:
    Contact(const QString &name= "",
            const QString &mobile= "",
            const QString &email= "",
            const QString &address= "");

    void setName(const QString &name);
    void setMobile(const QString &mobile);
    void setEmail(const QString &email);
    void setAddress(const QString &address);

    QString getName() const;
    QString getMobile() const;
    QString getEmail() const;
    QString getAddress() const;

private:
    QString varName;
    QString varMobile;
    QString varEmail;
    QString varAddress;
};

#endif // CONTACT_H
