#ifndef QSTEG_H
#define QSTEG_H

#include <QMainWindow>

namespace Ui {
class QSteg;
}

class QSteg : public QMainWindow
{
    Q_OBJECT

public:
    explicit QSteg(QWidget *parent = 0);
    ~QSteg();


private:
    Ui::QSteg *ui;
    void createActions();
    void createMenus();

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* encodeMenu;
    QMenu* decodeMenu;
    QMenu* helpMenu;

    QAction* newAct;
    QAction* openAct;
    QAction* saveAct;
    QAction* saveAsAct;
    QAction* quitAct;
    QAction* encodeAct;
    QAction* decodeAct;
    QAction* aboutAct;

private slots:
    void newFile();
    void open();
    void save();
    void saveAs();
    void quit();
    void encode();
    void decode();
    void about();
};

#endif // QSTEG_H
