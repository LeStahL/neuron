#include "DemoWindow.hpp"

#include <QDebug>
#include <QOpenGLFunctions>
#include <QSurfaceFormat>
#include <QScrollArea>
#include <QLayout>
#include <QLabel>
#include <QTabWidget>

GLfloat const vertices[] = {
    -1.f, -1.f, 0.0f,
    -1.f, 1.f, 0.0f,
    1.f, -1.f, 0.0f,
    -1.f, 1.f, 0.0f,
    1.f, -1.f, 0.0f,
    1.f, 1.f, 0.f
};

DemoWindow::DemoWindow(QApplication *_application, Settings *_settings, QWidget *parent)
    : QOpenGLWindow()
    , application(_application)
    , settings(_settings)
    , paused(false)
{
    shaderPath = application->applicationDirPath() + "/shaders/";
}

DemoWindow::~DemoWindow()
{
    delete loadingBarProgram;
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
    makeCurrent();
    initializeOpenGLFunctions();
    printContextInformation();

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    // Initialize loading bar
    loadingBarProgram = new QOpenGLShaderProgram();
    loadingBarProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, shaderPath + "load.frag");
    loadingBarProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, shaderPath + "dummy.vert");
    loadingBarProgram->link();
    qDebug() << loadingBarProgram->log(); // TODO: display error text on screen
    loadingBarProgram->bind();

    vertexBufferObject.create();
    vertexBufferObject.bind();
    vertexBufferObject.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vertexBufferObject.allocate(vertices, sizeof(vertices));

    vertexArrayObject.create();
    vertexArrayObject.bind();

    loadingBarProgram->enableAttributeArray(0);
    loadingBarProgram->setAttributeBuffer(0, GL_FLOAT, 0, 3);

    vertexBufferObject.release();
    vertexArrayObject.release();
    loadingBarProgram->release();
}

void DemoWindow::resizeGL(int width, int height)
{
    (void)width;
    (void)height;
}

void DemoWindow::quad()
{
    // glBegin(GL_QUADS);
    // glVertex3f(-1,-1,0);
    // glVertex3f(-1,1,0);
    // glVertex3f(1,1,0);
    // glVertex3f(1,-1,0);
    // glEnd();
    // glFlush();
}

void DemoWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    loadingBarProgram->bind();
    vertexBufferObject.bind();
    vertexArrayObject.bind();
    loadingBarProgram->setUniformValue("iProgress", (GLfloat).75);
    loadingBarProgram->setUniformValue("iResolution", size());

    // quad();
    glDrawArrays(GL_TRIANGLES, 0, 6);

    loadingBarProgram->disableAttributeArray("position");
    vertexBufferObject.release();
    vertexArrayObject.release();
    loadingBarProgram->release();
}

void DemoWindow::printContextInformation()
{
  QString glType;
  QString glVersion;
  QString glProfile;
 
  // Get Version Information
  glType = (context()->isOpenGLES()) ? "OpenGL ES" : "OpenGL";
  glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));
 
  // Get Profile Information
#define CASE(c) case QSurfaceFormat::c: glProfile = #c; break
  switch (format().profile())
  {
    CASE(NoProfile);
    CASE(CoreProfile);
    CASE(CompatibilityProfile);
  }
#undef CASE
 
  // qPrintable() will print our QString w/o quotes around it.
  qDebug() << qPrintable(glType) << qPrintable(glVersion) << "(" << qPrintable(glProfile) << ")";
}