#include "contato.h"

namespace ggs {
    Contato::Contato():
        cpf(""),
        nomeCompleto(""),
        email(""),
        fone(),
        endereco()
    {}

    Contato::Contato(QString &cpf, QString &nomeCompleto, QString &email, Telefone &fone, Endereco &endereco):
        cpf(cpf),
        nomeCompleto(nomeCompleto),
        email(email),
        fone(fone),
        endereco(endereco)
    {}

    QString Contato::toString()const{
        QString saida = cpf + ";";
        saida += nomeCompleto + ";";
        saida += email + ";";
        saida += fone.toString();
        saida += endereco.toString();
        return saida;
    }

    QString Contato::obterTelefone()const{
        return fone.toString();
    }

    QString Contato::getCpf() const{
        return cpf;
    }

    void Contato::setCpf(const QString &newCpf){
        cpf = newCpf;
    }

    QString Contato::getNomeCompleto() const{
        return nomeCompleto;
    }

    void Contato::setNomeCompleto(const QString &newNomeCompleto){
        nomeCompleto = newNomeCompleto;
    }

    QString Contato::getEmail() const{
        return email;
    }

    void Contato::setEmail(const QString &newEmail){
        email = newEmail;
    }

    Telefone Contato::getFone() const{
        return fone;
    }

    void Contato::setFone(const Telefone &newFone){
        fone = newFone;
    }

    Endereco Contato::getEndereco() const{
        return endereco;
    }

    void Contato::setEndereco(const Endereco &newEndereco){
        endereco = newEndereco;
    }
}
