#include "taskwidget.h"
#include "movement2dwidget.h"
#include "assignmentwidget.h"
#include "implementationwidget.h"
#include "outputwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QListView>
#include <QFileDialog>
#include <QPropertyAnimation>
#include <QSplitter>
#include <QStringListModel>
#include <QGridLayout>


CTaskWidget::CTaskWidget(const QString &pluginpath, QWidget *parent) : /*QTabWidget(parent),*/ ITabs(parent)
{
    setAssignementWidget(pluginpath);
    setImplementationWidget();
    setOutputWidget(pluginpath);

    m_tabWidget.setTabShape(QTabWidget::Triangular);
    m_tabWidget.addTab(m_assignement, QIcon(), tr("Assignement"));
    m_tabWidget.addTab(m_implementation, QIcon(), tr("Implementation"));
    m_tabWidget.addTab(m_output, QIcon(), tr("Output"));

    QWidget* buttonsWidget = new QWidget;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    m_forward = new QPushButton(">");
    m_back = new QPushButton("<");
    buttonLayout->addWidget(m_back);
    buttonLayout->addWidget(m_forward);
    buttonsWidget->setLayout(buttonLayout);
    m_tabWidget.setCornerWidget(buttonsWidget);
    m_forward->setMinimumHeight(30);
    m_back->setMinimumHeight(30);
    buttonLayout->setContentsMargins(0, 0, 0, 0);

    m_tabWidget.setTabPosition(QTabWidget::TabPosition::South);
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(&m_tabWidget);
    setLayout(mainLayout);
    mainLayout->setContentsMargins(0,0,0,0);

    connect(m_forward, &QPushButton::clicked, this, &CTaskWidget::onForwardClicked);
    connect(m_back, &QPushButton::clicked, this, &CTaskWidget::onBackClicked);
    connect(&m_tabWidget, &QTabWidget::currentChanged, this, &CTaskWidget::onTabChanged);
    connect(m_implementation, &CImplementationWidget::compiled, m_output, &COutputWidget::onStudentCodeCompiled);

    m_tabWidget.setStyleSheet("QTabBar::tab { height: 30px; width: 200px; }");
    onTabChanged(0);
}

void CTaskWidget::retranslateUi()
{
    m_tabWidget.setTabText(m_tabWidget.indexOf(m_assignement), tr("Assignement"));
    m_tabWidget.setTabText(m_tabWidget.indexOf(m_implementation), tr("Implementation"));
    m_tabWidget.setTabText(m_tabWidget.indexOf(m_output), tr("Output"));

    m_output->retranslateUi();
    m_implementation->retranslateUi();
    m_assignement->retranslateUi();
}

void CTaskWidget::resizeEvent(QResizeEvent *event)
{
    //m_forward->move(this->width() -110, this->height() -40);
    //m_back->move(this->width() -215, this->height() -40);
}

void CTaskWidget::setAssignementWidget(const QString &pluginpath)
{
    m_assignement = new CAssignmentWidget(pluginpath);
}

void CTaskWidget::setImplementationWidget()
{
    m_implementation = new CImplementationWidget;
}

void CTaskWidget::setOutputWidget(const QString &pluginpath)
{
    m_output = new COutputWidget(COutputViewsFactory::loadWidgetsFromPlugin(pluginpath));
//    QFont font;
//    font.setPointSize(14);

//    m_output = new ITabs;

//    QVBoxLayout *leftLayout = new QVBoxLayout;
//    QVBoxLayout *rightLayout = new QVBoxLayout;
//    QVBoxLayout *toolsLayout = new QVBoxLayout;

//    m_leftLabel = new QLabel(tr("Student's implementation"));
//    m_rightLabel = new QLabel(tr("Reference implementation"));
//    leftLayout->addWidget(m_leftLabel, 0, Qt::AlignTop | Qt::AlignCenter);
//    rightLayout->addWidget(m_rightLabel, 0, Qt::AlignTop | Qt::AlignCenter);

//    m_leftLabel->setFont(font);
//    m_rightLabel->setFont(font);

//    QPushButton *hideToolsButton = new QPushButton(">>");
//    hideToolsButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

//    m_bothSolutionsButton = new QPushButton(QIcon("../assets/bothwindows.png"), "");
//    m_studentSolutionsButton = new QPushButton(QIcon("../assets/studentwindow.png"), "");
//    m_referenceSolutionsButton = new QPushButton(QIcon("../assets/referencewindow.png"), "");

//    QHBoxLayout *showPartOfScreenButtonsLayout = new QHBoxLayout;
//    showPartOfScreenButtonsLayout->addWidget(m_bothSolutionsButton);
//    m_bothSolutionsButton->setDown(true);
//    showPartOfScreenButtonsLayout->addWidget(m_studentSolutionsButton);
//    showPartOfScreenButtonsLayout->addWidget(m_referenceSolutionsButton);3

//    showPartOfScreenButtonsLayout->addStretch();

//    QHBoxLayout *labelLayout = new QHBoxLayout;

//    m_toolboxLabel = new QLabel;
//    m_toolboxLabel->setText(tr("Toolbox"));
//    m_toolboxLabel->setFont(font);
//    hideToolsButton->setMaximumWidth(40);
//    labelLayout->addWidget(m_toolboxLabel);http://doc.qt.io/qt-5/qtabwidget.html#setCornerWidget
//    labelLayout->addWidget(hideToolsButton, 0, Qt::AlignRight);

//    //toolsLayout->addWidget(m_toolboxLabel, 0, Qt::AlignCenter);
//    toolsLayout->addLayout(labelLayout);
//    toolsLayout->addLayout(showPartOfScreenButtonsLayout);
//    toolsLayout->addStretch();

//    QWidget* gridWidget = new QWidget;
//    QGridLayout *gridLayout = new QGridLayout;

//    m_upButton = new QPushButton(QIcon("../assets/up-arrow.png"), "");
//    m_downButton = new QPushButton(QIcon("../assets/down-arrow.png"), "");
//    m_leftButton = new QPushButton(QIcon("../assets/left-arrow.png"), "");
//    m_rightButton = new QPushButton(QIcon("../assets/right-arrow.png"), "");

//    gridLayout->addWidget(m_upButton, 0, 1);
//    gridLayout->addWidget(m_downButton, 2, 1);
//    gridLayout->addWidget(m_leftButton, 1, 0);
//    gridLayout->addWidget(m_rightButton, 1, 2);
//    gridWidget->setLayout(gridLayout);

//    toolsLayout->addWidget(gridWidget);

//    toolsLayout->addStretch();

//    m_toolboxArea.setWidgetResizable(true);
//    m_toolboxArea.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
//    m_toolboxArea.setFrameStyle(QFrame::Panel);
//    m_toolboxArea.setLayout(toolsLayout);

//    CMovement2DWidget *studentMovementWidget = new CMovement2DWidget;
//    CMovement2DWidget *referenceMovementWidget = new CMovement2DWidget;

//    studentMovementWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    referenceMovementWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    rightLayout->addWidget(referenceMovementWidget);
//    if(m_hasStudentImplementation) {
//        leftLayout->addWidget(studentMovementWidget);
//    } else {
//        m_missingStudentImplementationLabel = new QLabel(tr("Implementation missing"));
//        m_missingStudentImplementationLabel->setFont(font);
//        leftLayout->addStretch();
//        leftLayout->addWidget(m_missingStudentImplementationLabel, 0, Qt::AlignCenter | Qt::AlignHCenter);
//        leftLayout->addStretch();
//    }

//    connect(referenceMovementWidget, &CMovement2DWidget::upPressed, this, &CTaskWidget::onUpButtonStateChanged);
//    connect(referenceMovementWidget, &CMovement2DWidget::downPressed, this, &CTaskWidget::onDownButtonStateChanged);
//    connect(referenceMovementWidget, &CMovement2DWidget::leftPressed, this, &CTaskWidget::onLeftButtonStateChanged);
//    connect(referenceMovementWidget, &CMovement2DWidget::rightPressed, this, &CTaskWidget::onRightButtonStateChanged);

//    connect(studentMovementWidget, &CMovement2DWidget::upPressed, this, &CTaskWidget::onUpButtonStateChanged);
//    connect(studentMovementWidget, &CMovement2DWidget::downPressed, this, &CTaskWidget::onDownButtonStateChanged);
//    connect(studentMovementWidget, &CMovement2DWidget::leftPressed, this, &CTaskWidget::onLeftButtonStateChanged);
//    connect(studentMovementWidget, &CMovement2DWidget::rightPressed, this, &CTaskWidget::onRightButtonStateChanged);

//    m_referenceView = new QWidget;
//    m_referenceView->setLayout(rightLayout);
//    m_studentView = new QWidget;
//    m_studentView->setLayout(leftLayout);

//    m_outputLayout.addWidget(m_studentView, 1);
//    m_outputLayout.addWidget(m_referenceView, 1);
//    m_outputLayout.addWidget(&m_toolboxArea);

//    m_output->setLayout(&m_outputLayout);

//    connect(hideToolsButton, &QPushButton::clicked, this, &CTaskWidget::onHideButtonClicked);
//    connect(m_bothSolutionsButton, &QPushButton::clicked, this, &CTaskWidget::onBothViewsSelected);
//    connect(m_studentSolutionsButton, &QPushButton::clicked, this, &CTaskWidget::onStudentViewSelected);
//    connect(m_referenceSolutionsButton, &QPushButton::clicked, this, &CTaskWidget::onReferenceViewSelected);

//    QPushButton *showToolboxButton = new QPushButton("<<");
//    QVBoxLayout *minimizedToolboxLayout = new QVBoxLayout;
//    m_bothSolutionsButton2 = new QPushButton(QIcon("../assets/bothwindows.png"), "");
//    m_studentSolutionsButton2 = new QPushButton(QIcon("../assets/studentwindow.png"), "");
//    m_referenceSolutionsButton2 = new QPushButton(QIcon("../assets/referencewindow.png"), "");
//    showToolboxButton->setMaximumWidth(30);
//    minimizedToolboxLayout->addWidget(showToolboxButton);
////    minimizedToolboxLayout->addStretch();
//    minimizedToolboxLayout->addWidget(m_bothSolutionsButton2);
//    m_bothSolutionsButton2->setDown(true);
//    minimizedToolboxLayout->addWidget(m_studentSolutionsButton2);
//    minimizedToolboxLayout->addWidget(m_referenceSolutionsButton2);
//    minimizedToolboxLayout->addStretch();
//    m_minimizedToolbox.setFrameShape(QFrame::Panel);
//    m_minimizedToolbox.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
//    m_minimizedToolbox.setLayout(minimizedToolboxLayout);

//    connect(showToolboxButton, &QPushButton::clicked, this, &CTaskWidget::onShowButtonClicked);
//    connect(m_bothSolutionsButton2, &QPushButton::clicked, this, &CTaskWidget::onBothViewsSelected);
//    connect(m_studentSolutionsButton2, &QPushButton::clicked, this, &CTaskWidget::onStudentViewSelected);
//    connect(m_referenceSolutionsButton2, &QPushButton::clicked, this, &CTaskWidget::onReferenceViewSelected);

//    if(!m_hasStudentImplementation) {
//        onReferenceViewSelected();
//    }
}

void CTaskWidget::onUploadSolutionClicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open cpp solution file"));
    m_uploadSolutionLineEdit.setText(filename);
}

void CTaskWidget::onLoadInputClicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select input file"));
    QFileInfo info(filename);
    if(!filename.isEmpty()) {
        m_inputs << info.fileName();
        m_stringModel->setStringList(m_inputs);
    }
}

void CTaskWidget::onCompileSolutionClicked()
{
    m_console.setText(m_uploadSolutionLineEdit.text() + " Compiled");
}

void CTaskWidget::onHideButtonClicked()
{
    QPropertyAnimation *hideToolboxAnimation = new QPropertyAnimation(&m_toolboxArea, "maximumWidth");
    hideToolboxAnimation->setDuration(200);
    hideToolboxAnimation->setStartValue(m_toolboxArea.width());
    hideToolboxAnimation->setEndValue(50);
    connect(hideToolboxAnimation, &QPropertyAnimation::finished, this, &CTaskWidget::onHideAnimationFinished);
    hideToolboxAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void CTaskWidget::onHideAnimationFinished()
{
    m_outputLayout.removeItem(m_outputLayout.itemAt(2));
    m_toolboxArea.setHidden(true);
    m_minimizedToolbox.setHidden(false);
    m_outputLayout.addWidget(&m_minimizedToolbox);
}

void CTaskWidget::onShowButtonClicked()
{
    m_outputLayout.removeItem(m_outputLayout.itemAt(2));
    m_minimizedToolbox.setHidden(true);
    m_toolboxArea.setHidden(false);
    m_outputLayout.addWidget(&m_toolboxArea);

    QPropertyAnimation *showToolboxAnimation = new QPropertyAnimation(&m_toolboxArea, "maximumWidth");
    showToolboxAnimation->setDuration(200);
    showToolboxAnimation->setStartValue(50);
    showToolboxAnimation->setEndValue(m_toolboxArea.sizeHint().width());
    //connect(showToolboxAnimation, &QPropertyAnimation::finished, this, &CTaskWidget::onShowAnimationFinished);
    showToolboxAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void CTaskWidget::onBothViewsSelected()
{
    m_referenceView->setHidden(false);
    m_studentView->setHidden(false);
    m_bothSolutionsButton2->setDown(true);
    m_referenceSolutionsButton2->setDown(false);
    m_studentSolutionsButton2->setDown(false);
    m_bothSolutionsButton->setDown(true);
    m_referenceSolutionsButton->setDown(false);
    m_studentSolutionsButton->setDown(false);
}

void CTaskWidget::onStudentViewSelected()
{
    m_referenceView->setHidden(true);
    m_studentView->setHidden(false);
    m_bothSolutionsButton2->setDown(false);
    m_referenceSolutionsButton2->setDown(false);
    m_studentSolutionsButton2->setDown(true);
    m_bothSolutionsButton->setDown(false);
    m_referenceSolutionsButton->setDown(false);
    m_studentSolutionsButton->setDown(true);
}

void CTaskWidget::onReferenceViewSelected()
{
    m_referenceView->setHidden(false);
    m_studentView->setHidden(true);
    m_bothSolutionsButton2->setDown(false);
    m_referenceSolutionsButton2->setDown(true);
    m_studentSolutionsButton2->setDown(false);
    m_bothSolutionsButton->setDown(false);
    m_referenceSolutionsButton->setDown(true);
    m_studentSolutionsButton->setDown(false);
}

void CTaskWidget::onUpButtonStateChanged(bool isPressed)
{
    m_upButton->setDown(isPressed);
}

void CTaskWidget::onDownButtonStateChanged(bool isPressed)
{
    m_downButton->setDown(isPressed);
}

void CTaskWidget::onLeftButtonStateChanged(bool isPressed)
{
    m_leftButton->setDown(isPressed);
}

void CTaskWidget::onRightButtonStateChanged(bool isPressed)
{
    m_rightButton->setDown(isPressed);
}

void CTaskWidget::onForwardClicked()
{
    int index = m_tabWidget.currentIndex();
    m_tabWidget.setCurrentIndex(index + 1);
    repaint();
}

void CTaskWidget::onBackClicked()
{
    int index = m_tabWidget.currentIndex();
    m_tabWidget.setCurrentIndex(index - 1);
    repaint();
}

void CTaskWidget::onTabChanged(int index)
{

    if(index == 0) {
        m_back->setDisabled(true);
    } else {
        m_back->setDisabled(false);
    }

    if(index == 2) {
        m_forward->setDisabled(true);
    } else {
        m_forward->setDisabled(false);
    }
    m_tabWidget.setFocus();
    resize(width()-1, height()-1);
    resize(width()+1, height()+1);
}
