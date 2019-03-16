#include "MyOpenGLWidget.h"
#include "MyUtil.h"

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget { parent }
{
    mVertex1.setX(-0.5f);
    mVertex1.setY(-0.5f);
    mVertex1.setZ(0.0f);

    mVertex2.setX(0.5f);
    mVertex2.setY(-0.5f);
    mVertex2.setZ(0.0f);

    mVertex3.setX(0.0f);
    mVertex3.setY(0.5f);
    mVertex3.setZ(0.0f);

    mColor1 = QColor(denormalize(1.0f, currentRGBMin, currentRGBMax),
                     denormalize(0.0f, currentRGBMin, currentRGBMax),
                     denormalize(0.0f, currentRGBMin, currentRGBMax)).rgb();

    mColor2 = QColor(denormalize(0.0f, currentRGBMin, currentRGBMax),
                     denormalize(1.0f, currentRGBMin, currentRGBMax),
                     denormalize(0.0f, currentRGBMin, currentRGBMax)).rgb();

    mColor3 = QColor(denormalize(0.0f, currentRGBMin, currentRGBMax),
                     denormalize(0.0f, currentRGBMin, currentRGBMax),
                     denormalize(1.0f, currentRGBMin, currentRGBMax)).rgb();

    auto mySignal = static_cast<void (MyOpenGLWidget::*)(void)>(&MyOpenGLWidget::update);

    connect(this, &MyOpenGLWidget::x1Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::x2Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::x3Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::y1Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::y2Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::y3Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::z1Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::z2Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::z3Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::red1Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::red2Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::red3Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::green1Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::green2Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::green3Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::blue1Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::blue2Changed, this, mySignal);
    connect(this, &MyOpenGLWidget::blue3Changed, this, mySignal);
}

void MyOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MyOpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(normalize(qRed(mColor1), currentRGBMin, currentRGBMax),
              normalize(qGreen(mColor1), currentRGBMin, currentRGBMax),
              normalize(qBlue(mColor1), currentRGBMin, currentRGBMax));

    glVertex3f(mVertex1.x(), mVertex1.y(), mVertex1.z());

    glColor3f(normalize(qRed(mColor2), currentRGBMin, currentRGBMax),
              normalize(qGreen(mColor2), currentRGBMin, currentRGBMax),
              normalize(qBlue(mColor2), currentRGBMin, currentRGBMax));

    glVertex3f(mVertex2.x(), mVertex2.y(), mVertex2.z());

    glColor3f(normalize(qRed(mColor3), currentRGBMin, currentRGBMax),
              normalize(qGreen(mColor3), currentRGBMin, currentRGBMax),
              normalize(qBlue(mColor3), currentRGBMin, currentRGBMax));

    glVertex3f(mVertex3.x(), mVertex3.y(), mVertex3.z());

    glEnd();
}

float MyOpenGLWidget::x1() const
{
    return mVertex1.x();
}

float MyOpenGLWidget::y1() const
{
    return mVertex1.y();
}

float MyOpenGLWidget::z1() const
{
    return mVertex1.z();
}

float MyOpenGLWidget::red1() const
{
    return qRed(mColor1);
}

float MyOpenGLWidget::green1() const
{
    return qGreen(mColor1);
}

float MyOpenGLWidget::blue1() const
{
    return qBlue(mColor1);
}

float MyOpenGLWidget::x2() const
{
    return mVertex2.x();
}

float MyOpenGLWidget::y2() const
{
    return mVertex2.y();
}

float MyOpenGLWidget::z2() const
{
    return mVertex2.z();
}

float MyOpenGLWidget::red2() const
{
    return qRed(mColor2);
}

float MyOpenGLWidget::green2() const
{
    return qGreen(mColor2);
}

float MyOpenGLWidget::blue2() const
{
    return qBlue(mColor2);
}

float MyOpenGLWidget::x3() const
{
    return mVertex3.x();
}

float MyOpenGLWidget::y3() const
{
    return mVertex3.y();
}

float MyOpenGLWidget::z3() const
{
    return mVertex3.z();
}

float MyOpenGLWidget::red3() const
{
    return qRed(mColor3);
}

float MyOpenGLWidget::green3() const
{
    return qGreen(mColor3);
}

float MyOpenGLWidget::blue3() const
{
    return qBlue(mColor3);
}

void MyOpenGLWidget::setX1(float x)
{
    mVertex1.setX(x);
    emit x1Changed();
}

void MyOpenGLWidget::setY1(float y)
{
    mVertex1.setY(y);
    emit y1Changed();
}

void MyOpenGLWidget::setZ1(float z)
{
    mVertex1.setZ(z);
    emit z1Changed();
}

void MyOpenGLWidget::setX2(float x)
{
    mVertex2.setX(x);
    emit x2Changed();
}

void MyOpenGLWidget::setY2(float y)
{
    mVertex2.setY(y);
    emit y2Changed();
}

void MyOpenGLWidget::setZ2(float z)
{
    mVertex2.setZ(z);
    emit z2Changed();
}

void MyOpenGLWidget::setX3(float x)
{
    mVertex3.setX(x);
    emit x3Changed();
}

void MyOpenGLWidget::setY3(float y)
{
    mVertex3.setY(y);
    emit y3Changed();
}

void MyOpenGLWidget::setZ3(float z)
{
    mVertex3.setZ(z);
    emit z3Changed();
}

void MyOpenGLWidget::setRed1(int red)
{
    const int r = red;
    const int g = qGreen(mColor1);
    const int b = qBlue(mColor1);
    mColor1 = qRgb(r, g, b);
    emit red1Changed();
}

void MyOpenGLWidget::setGreen1(int green)
{
    const int r = qRed(mColor1);
    const int g = green;
    const int b = qBlue(mColor1);
    mColor1 = qRgb(r, g, b);
    emit green1Changed();
}

void MyOpenGLWidget::setBlue1(int blue)
{
    const int r = qRed(mColor1);
    const int g = qGreen(mColor1);
    const int b = blue;
    mColor1 = qRgb(r, g, b);
    emit blue1Changed();
}

void MyOpenGLWidget::setRed2(int red)
{
    const int r = red;
    const int g = qGreen(mColor2);
    const int b = qBlue(mColor2);
    mColor2 = qRgb(r, g, b);
    emit red2Changed();
}

void MyOpenGLWidget::setGreen2(int green)
{
    const int r = qRed(mColor2);
    const int g = green;
    const int b = qBlue(mColor2);
    mColor2 = qRgb(r, g, b);
    emit green2Changed();
}

void MyOpenGLWidget::setBlue2(int blue)
{
    const int r = qRed(mColor2);
    const int g = qGreen(mColor2);
    const int b = blue;
    mColor2 = qRgb(r, g, b);
    emit blue2Changed();
}

void MyOpenGLWidget::setRed3(int red)
{
    const int r = red;
    const int g = qGreen(mColor3);
    const int b = qBlue(mColor3);
    mColor3 = qRgb(r, g, b);
    emit red3Changed();
}

void MyOpenGLWidget::setGreen3(int green)
{
    const int r = qRed(mColor3);
    const int g = green;
    const int b = qBlue(mColor3);
    mColor3 = qRgb(r, g, b);
    emit green3Changed();
}

void MyOpenGLWidget::setBlue3(int blue)
{
    const int r = qRed(mColor3);
    const int g = qGreen(mColor3);
    const int b = blue;
    mColor3 = qRgb(r, g, b);
    emit blue3Changed();
}
