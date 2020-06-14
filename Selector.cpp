#include "Selector.hpp"

#include <QDebug>
#include <QFile>

#pragma push_macro("slots")
#undef slots
#include "Python.h"
#pragma pop_macro("slots")

Selector::Selector(QApplication *_application, QWidget *parent)
    : QMainWindow(parent)
    , application(_application)
    , ui(Ui::Selector())
{
    ui.setupUi(this);

    // Load and display NFO
    try
    {
        QString nfoFileName = application->applicationDirPath() + "/Team210.nfo",
            convertedFileName = application->applicationDirPath() + "/.Team210.utf8";

        // Decode CP437 using python
        Py_SetProgramName((wchar_t*)application->arguments().first().toUtf8().data());
        Py_Initialize();
        PyRun_SimpleString((
            "with open('" + nfoFileName + "', encoding='cp437') as inputFile:\n"
            "    with open('" + convertedFileName + "','w', encoding='utf8') as outputFile:\n"
            "        outputFile.write(inputFile.read())\n"
        ).toUtf8().data());
        Py_Finalize();

        QFile file(nfoFileName);
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