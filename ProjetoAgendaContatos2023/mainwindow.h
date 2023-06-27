#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <contatocontrole.h>
#include <IcrudContato.h>
#include <contato.h>
#include <telefone.h>
#include <QInputDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QStringList>
#include <QtWidgets>
#include <QDebug>
#include <list>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mostrarContatosNaGrid(std::list<ggs::Contato> *listaDeContatos);
    void selecaoDeItensNaTableWidget();
    void limparInterface()const;
private slots:
    void on_pushButtonIncluir_clicked();

    void on_pushButtonConsultar_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonAlterar_clicked();

    void on_pushButtonLimpar_clicked();

private:
    Ui::MainWindow *ui;
    ggs::ICrudContato *agendaDeContatosControle;
};
#endif // MAINWINDOW_H
