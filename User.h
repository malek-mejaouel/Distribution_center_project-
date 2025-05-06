#ifndef USER_H
#define USER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class User {
private:
    QString user;
    QString pass;
    int numberp;
    int id;
    QString role;

public:
    // Constructors
    User();
    User(const QString& username, const QString& password, int numberp, const QString& role);
    // Getters
    QString getUser() const;
    QString getPass() const;
    int getNumberP() const;
    int getId() const;
    QString getRole() const;

    // Setters
    void setUser(const QString& user);
    void setPass(const QString& pass);
    void setNumberP(int number);
    void setId(int id);
    void setRole(const QString& role);

    // Methods
    bool ajouterP();
    bool modifierP(int id);
    bool supprimerP(int id);
    bool login(const QString& user, const QString& pass);
    QString getPhoneNumber(QString username);
    QSqlQueryModel* afficher();
    QString checkRole(const QString &username);
};

#endif // USER_H
