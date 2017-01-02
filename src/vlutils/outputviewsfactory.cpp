#include "outputviewsfactory.h"
#include "movement2dwidget.h"

#include <QWidget>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QKeyEvent>

COutputViewsFactory::COutputViewsFactory(QObject *parent) : QObject(parent)
{

}

TaskWidgets COutputViewsFactory::loadWidgetsFromPlugin(const QString &pluginpath)
{
    TaskWidgets result;
    if(pluginpath == "car.xml") {
        qDebug() << "Cars";
        CMovement2DWidget* carWidget = new CMovement2DWidget;
        CMovement2DWidget* studentCarWidget = new CMovement2DWidget;

        QWidget* controlPanelWidget = new QWidget;
        QGridLayout *gridLayout = new QGridLayout;

        QPushButton* upButton = new QPushButton(QIcon("../assets/up-arrow.png"), "");
        QPushButton* downButton = new QPushButton(QIcon("../assets/down-arrow.png"), "");
        QPushButton* leftButton = new QPushButton(QIcon("../assets/left-arrow.png"), "");
        QPushButton* rightButton = new QPushButton(QIcon("../assets/right-arrow.png"), "");

        QPushButton* resetButton = new QPushButton(tr("Reset"));

        gridLayout->addWidget(upButton, 0, 1);
        gridLayout->addWidget(downButton, 2, 1);
        gridLayout->addWidget(leftButton, 1, 0);
        gridLayout->addWidget(rightButton, 1, 2);

        gridLayout->addWidget(resetButton, 3, 0, 1, 3);
        controlPanelWidget->setLayout(gridLayout);

        connect(carWidget, &CMovement2DWidget::upPressed, upButton, &QPushButton::setDown);
        connect(carWidget, &CMovement2DWidget::downPressed, downButton, &QPushButton::setDown);
        connect(carWidget, &CMovement2DWidget::leftPressed, leftButton, &QPushButton::setDown);
        connect(carWidget, &CMovement2DWidget::rightPressed, rightButton, &QPushButton::setDown);

        connect(studentCarWidget, &CMovement2DWidget::upPressed, upButton, &QPushButton::setDown);
        connect(studentCarWidget, &CMovement2DWidget::downPressed, downButton, &QPushButton::setDown);
        connect(studentCarWidget, &CMovement2DWidget::leftPressed, leftButton, &QPushButton::setDown);
        connect(studentCarWidget, &CMovement2DWidget::rightPressed, rightButton, &QPushButton::setDown);

        connect(upButton, &QPushButton::pressed, carWidget, &CMovement2DWidget::onUpPressed);
        connect(downButton, &QPushButton::pressed, carWidget, &CMovement2DWidget::onDownPressed);
        connect(leftButton, &QPushButton::pressed, carWidget, &CMovement2DWidget::onLeftPressed);
        connect(rightButton, &QPushButton::pressed, carWidget, &CMovement2DWidget::onRightPressed);
        connect(upButton, &QPushButton::released, carWidget, &CMovement2DWidget::onUpReleased);
        connect(downButton, &QPushButton::released, carWidget, &CMovement2DWidget::onDownReleased);
        connect(leftButton, &QPushButton::released, carWidget, &CMovement2DWidget::onLeftReleased);
        connect(rightButton, &QPushButton::released, carWidget, &CMovement2DWidget::onRightReleased);

        connect(upButton, &QPushButton::pressed, studentCarWidget, &CMovement2DWidget::onUpPressed);
        connect(downButton, &QPushButton::pressed, studentCarWidget, &CMovement2DWidget::onDownPressed);
        connect(leftButton, &QPushButton::pressed, studentCarWidget, &CMovement2DWidget::onLeftPressed);
        connect(rightButton, &QPushButton::pressed, studentCarWidget, &CMovement2DWidget::onRightPressed);
        connect(upButton, &QPushButton::released, studentCarWidget, &CMovement2DWidget::onUpReleased);
        connect(downButton, &QPushButton::released, studentCarWidget, &CMovement2DWidget::onDownReleased);
        connect(leftButton, &QPushButton::released, studentCarWidget, &CMovement2DWidget::onLeftReleased);
        connect(rightButton, &QPushButton::released, studentCarWidget, &CMovement2DWidget::onRightReleased);

        connect(carWidget, &CMovement2DWidget::keyChanged, studentCarWidget, &CMovement2DWidget::onKeyChanged);
        connect(studentCarWidget, &CMovement2DWidget::keyChanged, carWidget, &CMovement2DWidget::onKeyChanged);

        connect(resetButton, &QPushButton::clicked, studentCarWidget, &CMovement2DWidget::reset);
        connect(resetButton, &QPushButton::clicked, carWidget, &CMovement2DWidget::reset);

        result.referenceWidget = carWidget;
        result.controlPanel = controlPanelWidget;
        result.studentWidget = studentCarWidget;
    } else {
        qDebug() << "Unhandled plugin name: " << pluginpath;
        result.referenceWidget = nullptr;
        result.controlPanel = nullptr;
        result.studentWidget = nullptr;
    }
    return result;
}
