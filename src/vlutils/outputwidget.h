#ifndef COUTPUTWIDGET_H
#define COUTPUTWIDGET_H

#include "outputviewsfactory.h"

#include <QWidget>

class QLabel;
class QPushButton;
class QScrollArea;
class QHBoxLayout;
class QVBoxLayout;
class QFrame;

class COutputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit COutputWidget(TaskWidgets widgets, QWidget *parent = 0);
    void retranslateUi();
    void setReferenceView(QWidget* referenceView);
    void setStudentView(QWidget* studentView);

signals:

public slots:
    void onStudentCodeCompiled();

private slots:
    void onBothViewsSelected();
    void onStudentViewSelected();
    void onReferenceViewSelected();
    void onShowButtonClicked();
    void onHideButtonClicked();
    void onHideAnimationFinished();

private:
    void createUiElements();

    QLabel *m_leftLabel = nullptr;
    QLabel *m_rightLabel = nullptr;
    QLabel *m_toolboxLabel = nullptr;
    QLabel* m_missingImplementationLabel = nullptr;
    QLabel* m_missingStudentImplementationLabel = nullptr;
    QPushButton* m_bothSolutionsButton = nullptr;
    QPushButton* m_studentSolutionsButton = nullptr;
    QPushButton* m_referenceSolutionsButton = nullptr;
    QScrollArea* m_toolboxArea = nullptr;

    QFrame* m_minimizedToolbox = nullptr;
    QWidget* m_referenceView = nullptr;
    QWidget* m_studentView = nullptr;
    QWidget* m_referenceWidget = nullptr;
    QWidget* m_studentWidget = nullptr;
    QWidget* m_taskControlPanel = nullptr;
    QHBoxLayout* m_outputLayout = nullptr;

    QPushButton* m_bothSolutionsButtonMinimized = nullptr;
    QPushButton* m_studentSolutionsButtonMinimized = nullptr;
    QPushButton* m_referenceSolutionsButtonMinimized = nullptr;

    QVBoxLayout *m_leftLayout;
};

#endif // COUTPUTWIDGET_H
