#ifndef COUTPUTWIDGET_H
#define COUTPUTWIDGET_H

#include <QWidget>

class QLabel;
class QPushButton;
class QScrollArea;
class QHBoxLayout;
class QFrame;

class COutputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit COutputWidget(QWidget *parent = 0);
    void retranslateUi();
    void setReferenceView(QWidget* referenceView);
    void setStudentView(QWidget* studentView);

signals:

public slots:

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
    QHBoxLayout* m_outputLayout = nullptr;

    QPushButton* m_bothSolutionsButtonMinimized = nullptr;
    QPushButton* m_studentSolutionsButtonMinimized = nullptr;
    QPushButton* m_referenceSolutionsButtonMinimized = nullptr;
};

#endif // COUTPUTWIDGET_H
