#pragma once

#include "ui_Selector.h"
#include "Settings.hpp"
#include "DemoWindow.hpp"

#include <QMainWindow>
#include <QString>

class Selector : public QMainWindow
{
    Q_OBJECT

    public:
    Selector(QApplication *application, Settings *settings, DemoWindow *demoWindow, QWidget *parent = nullptr);
    virtual ~Selector();

    Ui::Selector ui;
    QApplication *application;
    QString nfoContent;
    Settings *settings;
    DemoWindow *demoWindow;

    private slots:
    void startDemo();
    void searchAudioFile();
    void searchVideoFile();
    void recordToggled(bool state);
};
