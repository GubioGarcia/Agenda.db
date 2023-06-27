#include "telefone.h"

namespace ggs {
    Telefone::Telefone():
        ddi(0),
        ddd(0),
        numero(0)
    {}

    Telefone::Telefone(int ddi, int ddd, int numero):
        ddi(ddi),
        ddd(ddd),
        numero(numero)
    {}

    QString Telefone::toString()const{
        QString saida = QString::number(ddi);
        saida += ";";
        saida += QString::number(ddd);
        saida += ";";
        saida += QString::number(numero);
        saida += ";";
        return saida;
    }

    QString Telefone::obterTelefone()const{
        QString saida = "+";
        saida += QString::number(ddi);
        saida += "(";
        saida += QString::number(ddd);
        saida += ")";
        saida += QString::number(numero);
        return saida;
    }

    int Telefone::getDdi() const
    {
        return ddi;
    }

    void Telefone::setDdi(int newDdi)
    {
        ddi = newDdi;
    }

    int Telefone::getDdd() const
    {
        return ddd;
    }

    void Telefone::setDdd(int newDdd)
    {
        ddd = newDdd;
    }

    int Telefone::getNumero() const
    {
        return numero;
    }

    void Telefone::setNumero(int newNumero)
    {
        numero = newNumero;
    }
}
