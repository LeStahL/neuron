#include "Selector.hpp"

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QSurfaceFormat>

Selector::Selector(QApplication *_application, Settings *_settings, DemoWindow *_demoWindow, QWidget *parent)
    : QMainWindow(parent)
    , application(_application)
    , settings(_settings)
    , demoWindow(_demoWindow)
    , ui(Ui::Selector())
{
    ui.setupUi(this);

    // Load and display NFO
    try
    {
        QString nfoFileName = application->applicationDirPath() + "/Team210.nfo";
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

void Selector::startDemo()
{
    if(ui.comboBox->currentText() == "720p") settings->resolution = QPoint(1280,720);
    else if(ui.comboBox->currentText() == "1080p") settings->resolution = QPoint(1920,1080);
    settings->screenSpaceAntialiasing = ui.comboBox_2->currentText().split("xSSAA").first().toInt();
    settings->postAntialiasing = ui.comboBox_3->currentText().split("xPost").first().toInt();
    settings->fullScreen = ui.checkBox->isChecked();

    settings->muted = ui.checkBox_2->isChecked();
    
    settings->recordDemo = ui.checkBox_3->isChecked();
    settings->audioOutputFilename = ui.lineEdit_2->text();
    settings->videoOutputFilename = ui.lineEdit->text();

    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(3,3);

    demoWindow->setFormat(format);
    demoWindow->show();

    close();
}

void Selector::searchAudioFile()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("Images (*.ogg *.mp3 *.wav)"));
}

void Selector::searchVideoFile()
{

}

void Selector::recordToggled(bool state)
{
    ui.label_7->setEnabled(ui.checkBox_3->isChecked());
    ui.label_5->setEnabled(ui.checkBox_3->isChecked());
    ui.lineEdit->setEnabled(ui.checkBox_3->isChecked());
    ui.lineEdit_2->setEnabled(ui.checkBox_3->isChecked());
    ui.pushButton_2->setEnabled(ui.checkBox_3->isChecked());
    ui.pushButton_3->setEnabled(ui.checkBox_3->isChecked());
}