#include <QMainWindow>
#include "ui_Selector.h"

class Selector : public QMainWindow
{
    public:
    Selector(QWidget *parent = nullptr);
    virtual ~Selector();

    Ui::Selector ui;
};
