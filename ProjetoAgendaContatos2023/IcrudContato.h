#ifndef ICRUDCONTATO_H
#define ICRUDCONTATO_H
#include <contato.h>
#include <list>

namespace ggs {
    class ICrudContato{
    public:
        virtual void incluir(const Contato &objContato) const = 0;
        virtual std::list<Contato> *getListaDeContatos() const = 0;
        virtual Contato *consultar(QString cpf) const = 0;
        virtual void alterar(const Contato &objContato) const = 0;
        virtual void excluir(QString cpf) const = 0;
   };
}

#endif // ICRUDCONTATO_H
