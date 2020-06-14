#include "DemoWindow.hpp"

#include <QDebug>
#include <QOpenGLFunctions>

DemoWindow::DemoWindow(QApplication *_application, Settings *_settings, QWidget *parent)
    : QOpenGLWindow()
    , application(_application)
    , settings(_settings)
    , paused(false)
{
}

DemoWindow::~DemoWindow()
{

}

void DemoWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Q && e->modifiers() & Qt::ControlModifier
    || e->key() == Qt::Key_Escape
    || e->key() == Qt::Key_F4 && e->modifiers() & Qt::AltModifier)
        close();

    if(e->key() == Qt::Key_Space) paused = !paused;
}

void DemoWindow::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

void DemoWindow::resizeGL(int width, int height)
{
    (void)width;
    (void)height;
}

void DemoWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    update();
}