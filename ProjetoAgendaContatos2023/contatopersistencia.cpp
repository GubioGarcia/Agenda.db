#include "contatopersistencia.h"

namespace ggs {
    ContatoPersistencia::ContatoPersistencia()
    {}

    void ContatoPersistencia::incluir(const Contato &objContato) const {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // criando banco de dados
        db.setDatabaseName("C:/Users/Gubio/OneDrive/Documentos/ProjetosComp/TP2/AgendaSQL/SQL/agendaContatos.db");

        if (!db.open()) throw QString("ERRO: Banco de dados não foi aberto - IncluirPersistencia - ") + db.lastError().text();

        QSqlQuery query;
        query.prepare("INSERT INTO Contatos (cpf, nome, email, ddi, ddd, numero, logradouro, numeroCasa, cep) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);");
        query.bindValue(0, objContato.getCpf());
        query.bindValue(1, objContato.getNomeCompleto());
        query.bindValue(2, objContato.getEmail());
        query.bindValue(3, objContato.getFone().getDdi());
        query.bindValue(4, objContato.getFone().getDdd());
        query.bindValue(5, objContato.getFone().getNumero());
        query.bindValue(6, objContato.getEndereco().getLogradouro());
        query.bindValue(7, objContato.getEndereco().getNumero());
        query.bindValue(8, objContato.getEndereco().getCep());

        if (!query.exec()) {
            db.close();
            throw QString("Erro ao incluir o contato - IncluirPersistencia - ") + query.lastError().text();
        }

        db.close();
    }

    Contato *ContatoPersistencia::consultar(QString cpf) const{
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // criando banco de dados
        db.setDatabaseName("C:/Users/Gubio/OneDrive/Documentos/ProjetosComp/TP2/AgendaSQL/SQL/agendaContatos.db");

        if (!db.open()) throw QString("ERRO: Banco de dados não foi aberto - ConsultarPersistencia - ") + db.lastError().text();

        QSqlQuery query;
        query.prepare("SELECT cpf, nome, email, ddi, ddd, numero, logradouro, numeroCasa, cep " "FROM Contatos WHERE cpf = ?;");
        query.bindValue(0, cpf);

        if (!query.exec()) {
            db.close();
            throw QString("ERRO: ConsultarPersistencia - ") + query.lastError().text();
        }

        if (!query.next()) {
            db.close();
            return nullptr;
        }

        QString cpfObj = query.value(0).toString();
        QString nome = query.value(1).toString();
        QString email = query.value(2).toString();
        int ddi = query.value(3).toInt();
        int ddd = query.value(4).toInt();
        int numero = query.value(5).toInt();
        QString logradouro = query.value(6).toString();
        QString numeroCasa = query.value(7).toString();
        QString cep = QString::number(query.value(8).toInt());

        ggs::Telefone fone(ddi, ddd, numero);
        ggs::Endereco endereco(logradouro, numeroCasa, cep);
        ggs::Contato *objContato = new Contato(cpfObj, nome, email, fone, endereco);

        db.close();
        return objContato;
    }

    void ContatoPersistencia::excluir(QString cpf) const{
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // criando banco de dados
        db.setDatabaseName("C:/Users/Gubio/OneDrive/Documentos/ProjetosComp/TP2/AgendaSQL/SQL/agendaContatos.db");

        if (!db.open()) throw QString("ERRO: Banco de dados não foi aberto - ExcluirPersistencia - ") + db.lastError().text();

        QSqlQuery query;
        query.prepare("DELETE FROM Contatos WHERE cpf = ?;");
        query.bindValue(0, cpf);

        if (!query.exec()) {
            db.close();
            throw QString("ERRO: ExcluirPersistencia - ") + query.lastError().text();
        }

        db.close();
    }

    void ContatoPersistencia::alterar(const Contato &objContato) const{
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // criando banco de dados
        db.setDatabaseName("C:/Users/Gubio/OneDrive/Documentos/ProjetosComp/TP2/AgendaSQL/SQL/agendaContatos.db");

        if (!db.open()) throw QString("ERRO: Banco de dados não foi aberto - AlterarPersistencia - ") + db.lastError().text();

        QSqlQuery query;
        query.prepare("UPDATE Contatos SET cpf = ?, nome = ?, email = ?, ddi = ?, ddd = ?, numero = ?, logradouro = ?, numeroCasa = ?, cep = ? WHERE cpf = ?;");
        query.bindValue(0, objContato.getCpf());
        query.bindValue(1, objContato.getNomeCompleto());
        query.bindValue(2, objContato.getEmail());
        query.bindValue(3, objContato.getFone().getDdi());
        query.bindValue(4, objContato.getFone().getDdd());
        query.bindValue(5, objContato.getFone().getNumero());
        query.bindValue(6, objContato.getEndereco().getLogradouro());
        query.bindValue(7, objContato.getEndereco().getNumero());
        query.bindValue(8, objContato.getEndereco().getCep());
        query.bindValue(9, objContato.getCpf());

        if (!query.exec()) {
            db.close();
            throw QString("ERRO: AlterarPersistencia - ") + query.lastError().text();
        }

        db.close();
    }

    std::list<Contato> *ContatoPersistencia::getListaDeContatos() const{
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // criando banco de dados
        db.setDatabaseName("C:/Users/Gubio/OneDrive/Documentos/ProjetosComp/TP2/AgendaSQL/SQL/agendaContatos.db");

        if (!db.open()) throw QString("ERRO: Banco de dados não foi aberto - GetListaDeContatosPersistencia - ") + db.lastError().text();

        QSqlQuery query("SELECT cpf, nome, email, ddi, ddd, numero, logradouro, numeroCasa, cep FROM Contatos;");
        std::list<Contato> *listaDeContatos = new std::list<Contato>();

        while (query.next()) {
            QString cpf = query.value(0).toString();
            QString nome = query.value(1).toString();
            QString email = query.value(2).toString();
            int ddi = query.value(3).toInt();
            int ddd = query.value(4).toInt();
            int numero = query.value(5).toInt();
            QString logradouro = query.value(6).toString();
            QString numeroCasa = query.value(7).toString();
            QString cep = QString::number(query.value(8).toInt());

            ggs::Telefone fone(ddi, ddd, numero);
            ggs::Endereco endereco(logradouro, numeroCasa, cep);
            ggs::Contato objContato(cpf, nome, email, fone, endereco);
            listaDeContatos->push_back(objContato);
        }

        db.close();
        return listaDeContatos;
    }
}
