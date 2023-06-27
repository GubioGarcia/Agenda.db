#include "contatocontrole.h"

namespace ggs {
    ContatoControle::ContatoControle():
        contatoPersistencia(0)
    {
        contatoPersistencia = new ggs::ContatoPersistencia;
    }

    ContatoControle::~ContatoControle(){
        delete contatoPersistencia;
    }

    void ContatoControle::incluir(const Contato &objContato) const{
        try {
            verificarRegrasDeNegocio(objContato);//verificação de regras após coletar dados da ui
            contatoPersistencia->incluir(objContato);//inclusão do contato no arquivo, a cargo da classe contatoPersistencia
            return;
        } catch (QString &erro) {
            throw erro;
        }
    }

    std::list<Contato> *ContatoControle::getListaDeContatos() const{
        try {
            return contatoPersistencia->getListaDeContatos();
        } catch (QString &erro) {
            throw erro;
        }
    }

    Contato *ContatoControle::consultar(QString cpf) const{
        try {
            return contatoPersistencia->consultar(cpf);
        } catch (QString &erro) {
            throw erro;
        }
    }

    void ContatoControle::excluir(QString cpf) const{
        try {
            return contatoPersistencia->excluir(cpf);
        } catch (...) {
        }
    }

    void ContatoControle::alterar(const Contato &objContato) const{
        try {
            return contatoPersistencia->alterar(objContato);
        } catch (...) {
        }
    }

    void ContatoControle::verificarRegrasDeNegocio(const Contato &objContato) const{
        if(objContato.getCpf().isEmpty()) throw QString("ERRO: Insira CPF");
        if(objContato.getNomeCompleto().isEmpty()) throw QString("ERRO: Insira Nome Completo");
        if(objContato.getEmail().isEmpty()) throw QString("ERRO: Insira email válido");
        if(objContato.obterTelefone().isEmpty()) throw QString("ERRO: Insira Telefone válido");

        if(!validarCpf(objContato.getCpf())) throw QString("ERRO: CPF inválido"); // Verificar se CPF é válido
        if(!validarEmail(objContato.getEmail())) throw QString("ERRO: Email não é válido"); // Verificar se email é válido
        if(!validarFone(objContato.obterTelefone())) throw QString("ERRO: Telefone inválido"); // Verificar se Telefone é válido

        // Verificar se Endereço é válido
        if(objContato.getEndereco().getLogradouro().isEmpty()) throw QString("ERRO: Insira o Logradouro");
        if(objContato.getEndereco().getNumero().isEmpty()) throw QString("ERRO: Insira o Número");
        if(objContato.getEndereco().getCep().isEmpty()) throw QString("ERRO: Insira o CEP");
        return;
    }

    bool ContatoControle::validarCpf(const QString& cpf)const{
        if(cpf.size() != 11) return false;
        std::string str = cpf.toStdString();
        std::vector<int> arrayCpf;
        for(char aux : str) arrayCpf.push_back(aux - '0');
        //verificando se é um CPF inválido por possuir todos os digitos iguais
        bool todosDigitosIguais = std::adjacent_find(arrayCpf.begin(), arrayCpf.end(), std::not_equal_to<int>()) == arrayCpf.end();
        if (todosDigitosIguais) return false;
        int soma = 0;
        //verificando primeiro digito verificador do CPF
        for(int i=0, j=10; i<9; i++, j--){
            soma = soma  + (arrayCpf[i] * j);
        }
        soma = (soma*10)%11;
        if(soma == 10) soma = 0;
        if(soma == arrayCpf[9]){
            //verificando segundo digito verificador do CPF
            soma = 0;
            for(int i=0, j=11; i<10; i++, j--){
                soma = soma  + (arrayCpf[i] * j);
            }
            soma = (soma*10)%11;
            if(soma == 10) soma = 0;
            if(soma != arrayCpf[10]) return false;
            return true;
        } else return false;
    }

    bool ContatoControle::validarEmail(const QString& email)const{
        if(email.count('@') != 1) return false;//verificando duplicidade de '@'
        if(email.startsWith('.')) return false;//verificando se inicia com '.'
        if(email.startsWith('@')) return false;//verificando se inicia com '@'
        QChar ultimoCaractere = email.at(email.length() - 1);//verificando se último caractere é letra ou número
        if(!ultimoCaractere.isLetterOrNumber()) return false;
        if(email.contains("..")) return false;//verificando duplicidade de pontos seguidos
        QStringList partesEmail = email.split('@');//dividindo email em 2 partes pelo @
        if(partesEmail.size() != 2) return false;
        if(!partesEmail[1].contains('.')) return false;
    }

    bool ContatoControle::validarFone(const QString& fone)const{
        QStringList partesFone = fone.split(';');
        if(partesFone[0].size() != 2) return false;
        if(partesFone[1].size() != 2) return false;
        if(partesFone[2].size() < 8 || partesFone[2].size() >9) return false;
        for(int i=0; i<3; i++){
            for(const QChar& aux : partesFone[i]){
                if(!aux.isDigit()) return false;
            }
        }
        return true;
    }
}
