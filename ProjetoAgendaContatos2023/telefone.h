#ifndef TELEFONE_H
#define TELEFONE_H
#include <QString>

namespace ggs {
    class Telefone
    {
    private:
        int ddi;
        int ddd;
        int numero;
    public:
        Telefone();
        Telefone(int ddi, int ddd, int numero);

        QString toString()const;
        QString obterTelefone()const;

        int getDdi() const;
        void setDdi(int newDdi);
        int getDdd() const;
        void setDdd(int newDdd);
        int getNumero() const;
        void setNumero(int newNumero);
    };
}

#endif // TELEFONE_H
