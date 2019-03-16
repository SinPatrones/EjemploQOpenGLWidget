#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QVector3D>
#include <QRgb>

class MyOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    MyOpenGLWidget(QWidget *parent = nullptr);
    float x1() const;
    float x2() const;
    float x3() const;
    float y1() const;
    float y2() const;
    float y3() const;
    float z1() const;
    float z2() const;
    float z3() const;
    float red1() const;
    float red2() const;
    float red3() const;
    float green1() const;
    float green2() const;
    float green3() const;
    float blue1() const;
    float blue2() const;
    float blue3() const;
    void setX1(float x);
    void setX2(float x);
    void setX3(float x);
    void setY1(float y);
    void setY2(float y);
    void setY3(float y);
    void setZ1(float z);
    void setZ2(float z);
    void setZ3(float z);
    void setRed1(int red);
    void setRed2(int red);
    void setRed3(int red);
    void setGreen1(int green);
    void setGreen2(int green);
    void setGreen3(int green);
    void setBlue1(int blue);
    void setBlue2(int blue);
    void setBlue3(int blue);
signals:
    void x1Changed();
    void x2Changed();
    void x3Changed();
    void y1Changed();
    void y2Changed();
    void y3Changed();
    void z1Changed();
    void z2Changed();
    void z3Changed();
    void red1Changed();
    void red2Changed();
    void red3Changed();
    void green1Changed();
    void green2Changed();
    void green3Changed();
    void blue1Changed();
    void blue2Changed();
    void blue3Changed();
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
private:
    QVector3D mVertex1;
    QVector3D mVertex2;
    QVector3D mVertex3;
    QRgb mColor1;
    QRgb mColor2;
    QRgb mColor3;
};

#endif // MYOPENGLWIDGET_H
