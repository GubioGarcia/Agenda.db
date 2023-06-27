#ifndef CONTATO_H
#define CONTATO_H
#include <telefone.h>
#include <endereco.h>
#include <QString>

namespace ggs {
    class Contato
    {
    private:
        QString cpf;
        QString nomeCompleto;
        QString email;
        Telefone fone;
        Endereco endereco;
    public:
        Contato();
        Contato(QString &cpf, QString &nomeCompleto, QString &email, Telefone &fone, Endereco &endereco);// passagem de parâmetros por referência

        QString toString()const;
        QString obterTelefone()const;

        QString getNomeCompleto() const;
        void setNomeCompleto(const QString &newNomeCompleto);
        QString getEmail() const;
        void setEmail(const QString &newEmail);
        Telefone getFone() const;
        void setFone(const Telefone &newFone);
        QString getCpf() const;
        void setCpf(const QString &newCpf);
        Endereco getEndereco() const;
        void setEndereco(const Endereco &newEndereco);
    };
}

#endif // CONTATO_H
