#include "qsteg.h"
#include "ui_qsteg.h"
#include "aboutwindow.h"
#include "ui_aboutwindow.h"

#include "hexeditor.h"

QSteg::QSteg(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::QSteg)
{
    ui->setupUi(this);

    createActions();
    createMenus();
    setupHex();
}

void QSteg::open()
{
    stegImg = new QStegImage();
    stegImg->filename = QFileDialog::getOpenFileName(this, tr("Open image"), QDir::homePath(), tr("Image files (*.bmp)"));
    if(!stegImg->filename.isEmpty())
    {
        stegImg->stegScene = new QGraphicsScene(this);
        stegImg->stegPixmapItem = new QGraphicsPixmapItem;
        stegImg->stegPixmap = new QPixmap(stegImg->filename);
        stegImg->stegPixmapItem->setPixmap(*stegImg->stegPixmap);
        stegImg->stegScene->addItem(stegImg->stegPixmapItem);

        ui->stegImageView->setScene(stegImg->stegScene);
        ui->stegImageView->show();
    }
}

void QSteg::save()
{
    qDebug() << "save";
    QByteArray img;
    QBuffer buf(&img);
    buf.open(QIODevice::WriteOnly);
    stegImg->stegPixmap->save(&buf, "BMP");

    stegImg->stegBytes = hexFormat(img, img.size());

    qDebug() << stegImg->stegBytes;
}

void QSteg::saveAs()
{
    qDebug() << "save as ";
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

QString QSteg::hexFormat(QByteArray ba, size_t bs)
{
    std::stringstream s;
    s << std::setfill('0');
    std::cout << "size: " << bs << std::endl;

    for(auto sv=0U,n=0U,l=1U; n < bs; sv+=8, n++,l++)
    {
        s << std::hex << std::setw(2) << (reinterpret_cast<int>(ba.at(n) >> sv) & 0xFF) << " ";
        if(l%16==0)
            s << std::endl;
    }


    return QString::fromStdString(s.str());
}

void QSteg::setupHex()
{
    HexEditor* editor = new HexEditor(ui->stegBytesText);
    ui->stegBytesText->setReadOnly(true);
}

QSteg::~QSteg()
{
    delete ui;
}
