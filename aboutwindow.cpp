#include "aboutwindow.h"
#include "ui_aboutwindow.h"

aboutWindow::aboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(quit()));
}

void aboutWindow::quit()
{
    close();
}

aboutWindow::~aboutWindow()
{
    delete ui;
}
