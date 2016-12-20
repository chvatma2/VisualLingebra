#ifndef CTASKWIDGET_H
#define CTASKWIDGET_H

#include "tabs.h"

#include <QWidget>
#include <QWebEngineView>
#include <QTreeView>
#include <QStatusBar>
#include <QTabWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QListView>
#include <QStringListModel>

//TODO
//1. Tooltipy
//2. Nastavovat texty pouze z retranslate UI

class CTaskWidget : /*public QTabWidget,*/ public ITabs
{
    Q_OBJECT
public:
    explicit CTaskWidget(QWidget *parent = 0);
    void retranslateUi() override;
signals:

public slots:
private:
    void setAssignementWidget();
    void setImplementationWidget();
    void setOutputWidget();

    QWebEngineView m_page;
    QListView m_index;
    QStatusBar m_statusBar;
    QTabWidget m_bottomTabs;
    ITabs *m_assignement = nullptr;
    ITabs *m_implementation = nullptr;
    ITabs *m_output = nullptr;
    QLineEdit m_uploadSolutionLineEdit;
    QTextEdit m_console;
    QHBoxLayout m_outputLayout;
    QScrollArea m_toolboxArea;
    QFrame m_minimizedToolbox;
    QTabWidget m_tabWidget;

    QPushButton *m_uploadSolutionButton = nullptr;
    QPushButton *m_compileSolutionButton = nullptr;
    QLabel *m_solutionLabel = nullptr;
    QLabel *m_consoleLabel = nullptr;
    QLabel *m_inputsLabel = nullptr;
    QPushButton *m_loadInputsButton = nullptr;
    QLabel *m_leftLabel = nullptr;
    QLabel *m_rightLabel = nullptr;
    QLabel *m_toolboxLabel = nullptr;
    QWidget *m_referenceView = nullptr;
    QWidget *m_studentView = nullptr;
    QPushButton *m_bothSolutionsButton = nullptr;
    QPushButton *m_studentSolutionsButton = nullptr;
    QPushButton *m_referenceSolutionsButton = nullptr;
    QPushButton *m_bothSolutionsButton2 = nullptr;
    QPushButton *m_studentSolutionsButton2 = nullptr;
    QPushButton *m_referenceSolutionsButton2 = nullptr;

    QListView *m_inputsList = nullptr;
    QStringListModel *m_stringModel = nullptr;
    QStringList m_inputs;

    QPushButton *m_upButton = nullptr;
    QPushButton *m_downButton = nullptr;
    QPushButton *m_leftButton = nullptr;
    QPushButton *m_rightButton = nullptr;

private slots:
    void onUploadSolutionClicked();
    void onLoadInputClicked();
    void onCompileSolutionClicked();
    void onHideButtonClicked();
    void onHideAnimationFinished();
    void onShowButtonClicked();
    void onShowAnimationFinished();
    void onBothViewsSelected();
    void onStudentViewSelected();
    void onReferenceViewSelected();
    void onUpButtonStateChanged(bool isPressed);
    void onDownButtonStateChanged(bool isPressed);
    void onLeftButtonStateChanged(bool isPressed);
    void onRightButtonStateChanged(bool isPressed);

};

#endif // CTASKWIDGET_H
