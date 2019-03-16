#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "MyUtil.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow { parent }
    , ui { new Ui::MainWindow }
{
    ui->setupUi(this);
    const float currentX1 = ui->widget->x1();
    const float currentX2 = ui->widget->x2();
    const float currentX3 = ui->widget->x3();
    const float currentY1 = ui->widget->y1();
    const float currentY2 = ui->widget->y2();
    const float currentY3 = ui->widget->y3();
    const float currentZ1 = ui->widget->z1();
    const float currentZ2 = ui->widget->z2();
    const float currentZ3 = ui->widget->z3();
    const int displayX1 = denormalize2(currentX1, displayXYZMin, displayXYZMax);
    const int displayX2 = denormalize2(currentX2, displayXYZMin, displayXYZMax);
    const int displayX3 = denormalize2(currentX3, displayXYZMin, displayXYZMax);
    const int displayY1 = denormalize2(currentY1, displayXYZMin, displayXYZMax);
    const int displayY2 = denormalize2(currentY2, displayXYZMin, displayXYZMax);
    const int displayY3 = denormalize2(currentY3, displayXYZMin, displayXYZMax);
    const int displayZ1 = denormalize2(currentZ1, displayXYZMin, displayXYZMax);
    const int displayZ2 = denormalize2(currentZ2, displayXYZMin, displayXYZMax);
    const int displayZ3 = denormalize2(currentZ3, displayXYZMin, displayXYZMax);
    const int currentRed1 = ui->widget->red1();
    const int currentRed2 = ui->widget->red2();
    const int currentRed3 = ui->widget->red3();
    const int currentGreen1 = ui->widget->green1();
    const int currentGreen2 = ui->widget->green2();
    const int currentGreen3 = ui->widget->green3();
    const int currentBlue1 = ui->widget->blue1();
    const int currentBlue2 = ui->widget->blue2();
    const int currentBlue3 = ui->widget->blue3();

    ui->x1HorizontalSlider->setRange(displayXYZMin, displayXYZMax);
    ui->y1HorizontalSlider->setRange(displayXYZMin, displayXYZMax);
    ui->z1HorizontalSlider->setRange(displayXYZMin, displayXYZMax);
    ui->x2HorizontalSlider->setRange(displayXYZMin, displayXYZMax);
    ui->y2HorizontalSlider->setRange(displayXYZMin, displayXYZMax);
    ui->z2HorizontalSlider->setRange(displayXYZMin, displayXYZMax);
    ui->x3HorizontalSlider->setRange(displayXYZMin, displayXYZMax);
    ui->y3HorizontalSlider->setRange(displayXYZMin, displayXYZMax);
    ui->z3HorizontalSlider->setRange(displayXYZMin, displayXYZMax);
    ui->r1HorizontalSlider->setRange(currentRGBMin, currentRGBMax);
    ui->g1HorizontalSlider->setRange(currentRGBMin, currentRGBMax);
    ui->b1HorizontalSlider->setRange(currentRGBMin, currentRGBMax);
    ui->r2HorizontalSlider->setRange(currentRGBMin, currentRGBMax);
    ui->g2HorizontalSlider->setRange(currentRGBMin, currentRGBMax);
    ui->b2HorizontalSlider->setRange(currentRGBMin, currentRGBMax);
    ui->r3HorizontalSlider->setRange(currentRGBMin, currentRGBMax);
    ui->g3HorizontalSlider->setRange(currentRGBMin, currentRGBMax);
    ui->b3HorizontalSlider->setRange(currentRGBMin, currentRGBMax);

    ui->x1HorizontalSlider->setValue(displayX1);
    ui->x2HorizontalSlider->setValue(displayX2);
    ui->x3HorizontalSlider->setValue(displayX3);
    ui->y1HorizontalSlider->setValue(displayY1);
    ui->y2HorizontalSlider->setValue(displayY2);
    ui->y3HorizontalSlider->setValue(displayY3);
    ui->z1HorizontalSlider->setValue(displayZ1);
    ui->z2HorizontalSlider->setValue(displayZ2);
    ui->z3HorizontalSlider->setValue(displayZ3);
    ui->r1HorizontalSlider->setValue(currentRed1);
    ui->r2HorizontalSlider->setValue(currentRed2);
    ui->r3HorizontalSlider->setValue(currentRed3);
    ui->g1HorizontalSlider->setValue(currentGreen1);
    ui->g2HorizontalSlider->setValue(currentGreen2);
    ui->g3HorizontalSlider->setValue(currentGreen3);
    ui->b1HorizontalSlider->setValue(currentBlue1);
    ui->b2HorizontalSlider->setValue(currentBlue2);
    ui->b3HorizontalSlider->setValue(currentBlue3);

    ui->x1Label->setText(QString::number(currentX1, 'f', 2));
    ui->x2Label->setText(QString::number(currentX2, 'f', 2));
    ui->x3Label->setText(QString::number(currentX3, 'f', 2));
    ui->y1Label->setText(QString::number(currentY1, 'f', 2));
    ui->y2Label->setText(QString::number(currentY2, 'f', 2));
    ui->y3Label->setText(QString::number(currentY3, 'f', 2));
    ui->z1Label->setText(QString::number(currentZ1, 'f', 2));
    ui->z2Label->setText(QString::number(currentZ2, 'f', 2));
    ui->z3Label->setText(QString::number(currentZ3, 'f', 2));
    ui->red1Label->setText(QString::number(currentRed1));
    ui->red2Label->setText(QString::number(currentRed2));
    ui->red3Label->setText(QString::number(currentRed3));
    ui->green1Label->setText(QString::number(currentGreen1));
    ui->green2Label->setText(QString::number(currentGreen2));
    ui->green3Label->setText(QString::number(currentGreen3));
    ui->blue1Label->setText(QString::number(currentBlue1));
    ui->blue2Label->setText(QString::number(currentBlue2));
    ui->blue3Label->setText(QString::number(currentBlue3));

    connect(ui->x1HorizontalSlider, &QSlider::valueChanged, this, [&](int x)
    {
        const float x1 = normalize2(x, displayXYZMin, displayXYZMax);
        ui->widget->setX1(x1);
        ui->x1Label->setText(QString::number(x1, 'f', 2));
    });

    connect(ui->x2HorizontalSlider, &QSlider::valueChanged, this, [&](int x)
    {
        const float x2 = normalize2(x, displayXYZMin, displayXYZMax);
        ui->widget->setX2(x2);
        ui->x2Label->setText(QString::number(x2, 'f', 2));
    });

    connect(ui->x3HorizontalSlider, &QSlider::valueChanged, this, [&](int x)
    {
        const float x3 = normalize2(x, displayXYZMin, displayXYZMax);
        ui->widget->setX3(x3);
        ui->x3Label->setText(QString::number(x3, 'f', 2));
    });

    connect(ui->y1HorizontalSlider, &QSlider::valueChanged, this, [&](int y)
    {
        const float y1 = normalize2(y, displayXYZMin, displayXYZMax);
        ui->widget->setY1(y1);
        ui->y1Label->setText(QString::number(y1, 'f', 2));
    });

    connect(ui->y2HorizontalSlider, &QSlider::valueChanged, this, [&](int y)
    {
        const float y2 = normalize2(y, displayXYZMin, displayXYZMax);
        ui->widget->setY2(y2);
        ui->y2Label->setText(QString::number(y2, 'f', 2));
    });

    connect(ui->y3HorizontalSlider, &QSlider::valueChanged, this, [&](int y)
    {
        const float y3 = normalize2(y, displayXYZMin, displayXYZMax);
        ui->widget->setY3(y3);
        ui->y3Label->setText(QString::number(y3, 'f', 2));
    });

    connect(ui->z1HorizontalSlider, &QSlider::valueChanged, this, [&](int z)
    {
        const float z1 = normalize2(z, displayXYZMin, displayXYZMax);
        ui->widget->setZ1(z1);
        ui->z1Label->setText(QString::number(z1, 'f', 2));
    });

    connect(ui->z2HorizontalSlider, &QSlider::valueChanged, this, [&](int z)
    {
        const float z2 = normalize2(z, displayXYZMin, displayXYZMax);
        ui->widget->setZ2(z2);
        ui->z2Label->setText(QString::number(z2, 'f', 2));
    });

    connect(ui->z3HorizontalSlider, &QSlider::valueChanged, this, [&](int z)
    {
        const float z3 = normalize2(z, displayXYZMin, displayXYZMax);
        ui->widget->setZ3(z3);
        ui->z3Label->setText(QString::number(z3, 'f', 2));
    });

    connect(ui->r1HorizontalSlider, &QSlider::valueChanged, this, [&](int r)
    {
        ui->widget->setRed1(r);
        ui->red1Label->setText(QString::number(r));
    });

    connect(ui->g1HorizontalSlider, &QSlider::valueChanged, this, [&](int g)
    {
        ui->widget->setGreen1(g);
        ui->green1Label->setText(QString::number(g));
    });

    connect(ui->b1HorizontalSlider, &QSlider::valueChanged, this, [&](int b)
    {
        ui->widget->setBlue1(b);
        ui->blue1Label->setText(QString::number(b));
    });

    connect(ui->r2HorizontalSlider, &QSlider::valueChanged, this, [&](int r)
    {
        ui->widget->setRed2(r);
        ui->red2Label->setText(QString::number(r));
    });

    connect(ui->g2HorizontalSlider, &QSlider::valueChanged, this, [&](int g)
    {
        ui->widget->setGreen2(g);
        ui->green2Label->setText(QString::number(g));
    });

    connect(ui->b2HorizontalSlider, &QSlider::valueChanged, this, [&](int b)
    {
        ui->widget->setBlue2(b);
        ui->blue2Label->setText(QString::number(b));
    });

    connect(ui->r3HorizontalSlider, &QSlider::valueChanged, this, [&](int r)
    {
        ui->widget->setRed3(r);
        ui->red3Label->setText(QString::number(r));
    });

    connect(ui->g3HorizontalSlider, &QSlider::valueChanged, this, [&](int g)
    {
        ui->widget->setGreen3(g);
        ui->green3Label->setText(QString::number(g));
    });

    connect(ui->b3HorizontalSlider, &QSlider::valueChanged, this, [&](int b)
    {
        ui->widget->setBlue3(b);
        ui->blue3Label->setText(QString::number(b));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
