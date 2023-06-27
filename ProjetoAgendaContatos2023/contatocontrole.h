#ifndef CONTATOCONTROLE_H
#define CONTATOCONTROLE_H
#include <IcrudContato.h>
#include <contatopersistencia.h>
#include <QMessageBox>
#include <QStringList>
#include <algorithm>
#include <QDebug>

namespace ggs {
    class ContatoControle : public ICrudContato
    {
    private:
        ggs::ICrudContato *contatoPersistencia;
        void verificarRegrasDeNegocio(const Contato &objContato) const;

    public:
        ContatoControle();
        ~ContatoControle();

        void incluir(const Contato &objContato) const;
        Contato *consultar(QString cpf) const;
        void excluir(QString cpf) const;
        void alterar(const Contato &objContato) const;

        std::list<Contato> *getListaDeContatos() const;

        bool validarCpf(const QString& cpf)const;
        bool validarEmail(const QString& email)const;
        bool validarFone(const QString& fone)const;
    };
}

#endif // CONTATOCONTROLE_H
