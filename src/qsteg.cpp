#include "qsteg.h"
#include "ui_qsteg.h"
#include "aboutwindow.h"
#include "ui_aboutwindow.h"

QSteg::QSteg(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::QSteg)
{
    ui->setupUi(this);
    createActions();
    createMenus();
}

void QSteg::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open image"), QDir::homePath(), tr("Image files (*.bmp)"));
    stegImg->filename = fileName;
    if(!stegImg->filename.isEmpty())
    {
        QStegImage* stegImg = new QStegImage();
        stegImg->stegScene = new QGraphicsScene(this);
        stegImg->stegPixmapItem = new QGraphicsPixmapItem;
        stegImg->stegPixmap = new QPixmap(stegImg->filename);
        stegImg->stegPixmapItem->setPixmap(*stegImg->stegPixmap);
        stegImg->stegScene->addItem(stegImg->stegPixmapItem);

        ui->graphicsView->setScene(stegImg->stegScene);
        ui->graphicsView->show();
    }
}

void QSteg::save()
{
    qDebug() << "save";
    QByteArray img;
    QBuffer buf(&img);
    buf.open(QIODevice::WriteOnly);
}

void QSteg::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save image"), stegImg->filename);
    if(!fileName.isEmpty())
    {
        stegImg->stegPixmap->save(fileName, "BMP");
    }
}

void QSteg::quit()
{
    close();
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
    aboutWindow a(this);
    a.exec();
}

void QSteg::createActions()
{
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
