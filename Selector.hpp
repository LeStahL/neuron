#include "ui_Selector.h"

#include <QMainWindow>
#include <QString>

class Selector : public QMainWindow
{
    public:
    Selector(QApplication *application, QWidget *parent = nullptr);
    virtual ~Selector();

    Ui::Selector ui;
    QApplication *application;
    QString nfoContent;
};
