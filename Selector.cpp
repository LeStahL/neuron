#include "Selector.hpp"

#include <QDebug>
#include <QFile>

Selector::Selector(QApplication *_application, QWidget *parent)
    : QMainWindow(parent)
    , application(_application)
    , ui(Ui::Selector())
{
    ui.setupUi(this);

    // Load and display NFO
    try
    {
        QFile file(application->applicationDirPath() + "/Team210.nfo");
        if(!file.open(QFile::ReadOnly)) throw;
        nfoContent = QString::fromUtf8(file.readAll());
    }
    catch(...)
    {
        qDebug() << "Could not load NFO.";
    }
    ui.textEdit->setText(nfoContent);
}

Selector::~Selector()
{

}