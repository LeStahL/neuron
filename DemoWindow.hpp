#pragma once

#include <QOpenGLWindow>
#include <QApplication>
#include <QKeyEvent>
#include <QOpenGLFunctions>

#include "Settings.hpp"

class DemoWindow : public QOpenGLWindow, QOpenGLFunctions
{
    Q_OBJECT

    public:
    DemoWindow(QApplication *application, Settings *settings, QWidget *parent = nullptr);
    virtual ~DemoWindow();

    QApplication *application;
    Settings *settings;
    bool paused;

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    
    private:
    void keyPressEvent(QKeyEvent *e);
};
