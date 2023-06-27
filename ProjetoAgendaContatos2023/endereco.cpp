#include "endereco.h"

namespace ggs{
    Endereco::Endereco():
        logradouro(""),
        numero(""),
        cep("")
    {}

    Endereco::Endereco(QString logradouro, QString numero, QString cep):
        logradouro(logradouro), numero(numero), cep(cep)
    {}

    QString Endereco::toString() const{
        QString saida = logradouro + ";";
        saida += numero;
        saida += ";";
        saida += cep;
        saida += ";";
        return saida;
    }

    QString Endereco::obterEndereco()const{
        QString saida = logradouro + " ";
        saida += "Nº: " + numero;
        saida += " CEP: " + cep;
        return saida;
    }

    const QString &Endereco::getLogradouro() const
    {
        return logradouro;
    }

    void Endereco::setLogradouro(const QString &newLogradouro)
    {
        logradouro = newLogradouro;
    }

    QString Endereco::getNumero() const
    {
        return numero;
    }

    void Endereco::setNumero(const QString &newNumero)
    {
        numero = newNumero;
    }

    QString Endereco::getCep() const
    {
        return cep;
    }

    void Endereco::setCep(const QString &newCep)
    {
        cep = newCep;
    }
}
