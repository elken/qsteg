#include "qsteg.h"
#include "ui_qsteg.h"
#include <QDebug>
#include <QMenuBar>
#include <iostream>
#include <sstream>
#include <string>

QSteg::QSteg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QSteg)
{
    ui->setupUi(this);

    createActions();
    createMenus();
    setWindowTitle(tr("QSteg - menu test"));
}

void QSteg::newFile()
{
    qDebug() << "New file";
}

void QSteg::open()
{
    qDebug() << "open";
}

void QSteg::save()
{
    qDebug() << "save";
}

void QSteg::saveAs()
{
    qDebug() << "save as";
}

void QSteg::quit()
{
    qDebug() << "quit";
}

void QSteg::encode()
{
    qDebug() << "encode";
}

void QSteg::decode()
{
    qDebug() << "decode";
}

void QSteg::about()
{
    qDebug() << "about";
}

void QSteg::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open a file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Overwrite existing file"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(tr("&Save As"), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save as new file"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    quitAct = new QAction(tr("&Quit"), this);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Exit the program"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(quit()));

    encodeAct = new QAction(tr("&Encode"), this);
    encodeAct->setStatusTip(tr("Start the encoding process"));
    connect(encodeAct, SIGNAL(triggered()), this, SLOT(encode()));

    decodeAct = new QAction(tr("&Decode"), this);
    decodeAct->setStatusTip(tr("Start the decoding process"));
    connect(decodeAct, SIGNAL(triggered()), this, SLOT(decode()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setShortcuts(QKeySequence::HelpContents);
    aboutAct->setStatusTip(tr("Show help"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void QSteg::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    encodeMenu = menuBar()->addMenu(tr("&Encode"));
    encodeMenu->addAction(encodeAct);

    decodeMenu = menuBar()->addMenu(tr("&Decode"));
    decodeMenu->addAction(decodeAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}


QSteg::~QSteg()
{
    delete ui;
}
