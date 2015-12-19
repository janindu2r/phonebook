#include "contact.h"

Contact::Contact(const QString &name, const QString &mobile, const QString &email, const QString &address)
{
    varName = name;
    varMobile = mobile;
    varEmail = email;
    varAddress = address;

}

void Contact::setName(const QString &name)
{
    varName = name;
}

void Contact::setMobile(const QString &mobile)
{
    varMobile = mobile;
}

void Contact::setEmail(const QString &email)
{
    varEmail = email;
}

void Contact::setAddress(const QString &address)
{
    varAddress = address;
}

QString Contact::getName() const
{
    return varName;
}

QString Contact::getMobile() const
{
    return varMobile;
}

QString Contact::getEmail() const
{
    return varEmail;
}

QString Contact::getAddress() const
{
    return varAddress;
}
