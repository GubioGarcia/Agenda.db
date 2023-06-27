#ifndef CONTATOPERSISTENCIA_H
#define CONTATOPERSISTENCIA_H
#include <IcrudContato.h>
#include <contato.h>
#include <QStringList>
#include <fstream> //Biblioteca para tratamento de arquivos
// Bibliotecas para tratamento de banco de dados
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardPaths>
#include <QDir>

namespace ggs {
    class ContatoPersistencia : public ICrudContato
    {
    public:
        ContatoPersistencia();
        void incluir(const Contato &objContato) const;
        std::list<Contato> *getListaDeContatos() const;
        Contato *consultar(QString cpf) const;
        void excluir(QString cpf) const;
        void alterar(const Contato &objContato) const;
    };
}

#endif // CONTATOPERSISTENCIA_H
