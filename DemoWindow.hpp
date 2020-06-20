#pragma once

#include <QOpenGLWindow>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QApplication>
#include <QKeyEvent>
#include <QString>

#include "Settings.hpp"

class DemoWindow : public QOpenGLWindow, protected QOpenGLFunctions
{
    Q_OBJECT

    public:
    DemoWindow(QApplication *application, Settings *settings, QWidget *parent = nullptr);
    virtual ~DemoWindow();

    QApplication *application;
    Settings *settings;
    bool paused;
    QOpenGLShaderProgram *loadingBarProgram;
    QString shaderPath;
    QOpenGLBuffer vertexBufferObject;
    QOpenGLVertexArrayObject vertexArrayObject;

    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
    
    private:
    void keyPressEvent(QKeyEvent *e);
    void printContextInformation();
};
