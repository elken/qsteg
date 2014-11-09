#ifndef HEXEDITOR_H
#define HEXEDITOR_H

#include <QPlainTextEdit>
#include <QObject>

class HexEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    HexEditor(QWidget *parent = 0);

    void lineNumberAreaPaintEvent(QPaintEvent* event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *e);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect&, int);

private:
    QWidget* lineNumberArea;
};

class LineNumberArea : public QWidget
{
    Q_OBJECT

public:
    LineNumberArea(HexEditor* editor) : QWidget(editor)
    {
        hexEditor = editor;
    }

    QSize sizeHint() const
    {
        return QSize(hexEditor->lineNumberAreaWidth(), this->parentWidget()->height());
    }

protected:
    void paintEvent(QPaintEvent *event)
    {
        hexEditor->lineNumberAreaPaintEvent(event);
    }

private:
    HexEditor* hexEditor;
};


#endif // HEXEDITOR_H
