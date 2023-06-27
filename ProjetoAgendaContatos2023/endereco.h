#ifndef ENDERECO_H
#define ENDERECO_H
#include <QString>

namespace ggs{
class Endereco
{
private:
    QString logradouro;
    QString numero;
    QString cep;
public:
    Endereco();
    Endereco(QString logradouro, QString numero, QString cep);

    QString toString()const;
    QString obterEndereco()const;

    const QString &getLogradouro() const;
    void setLogradouro(const QString &newLogradouro);
    QString getNumero() const;
    void setNumero(const QString &newNumero);
    QString getCep() const;
    void setCep(const QString &newCep);
};
}
#endif // ENDERECO_H
