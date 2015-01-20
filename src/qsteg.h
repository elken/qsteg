#ifndef QSTEG_H
#define QSTEG_H

#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QSignalMapper>
#include <QBuffer>
#include <QTextEdit>
#include <QtGui>
#include <QMessageBox>

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

struct QStegImage
{
    QGraphicsScene* stegScene;
    QGraphicsPixmapItem* stegPixmapItem;
    QPixmap* stegPixmap;
    QString filename;
    QString stegBytes;
    QString stegBuffer;
};

namespace Ui {
class QSteg;
}

class QSteg : public QMainWindow
{
    Q_OBJECT

public:
    explicit QSteg(QWidget* parent = 0);
    ~QSteg();


private:
    // Custom objects
    Ui::QSteg *ui;
    QStegImage* stegImg;

    // Variables
    bool isLoaded = false;

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* encodeMenu;
    QMenu* decodeMenu;
    QMenu* helpMenu;

    QAction* openAct;
    QAction* saveAct;
    QAction* saveAsAct;
    QAction* quitAct;
    QAction* encodeAct;
    QAction* decodeAct;
    QAction* aboutAct;

    // Functions
    void createActions();
    void createMenus();
    void setupHex();

    QString hexFormat(QByteArray, size_t);

private slots:
    void open();
    void save();
    void saveAs();
    void quit();
    void encode();
    void decode();
    void about();
};


#endif // QSTEG_H
