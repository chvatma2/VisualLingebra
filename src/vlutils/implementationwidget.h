#ifndef CIMPLEMENTATIONWIDGET_H
#define CIMPLEMENTATIONWIDGET_H

#include <QWidget>

class QPushButton;
class QLabel;
class QTextEdit;
class QLineEdit;
class QStringListModel;
class QListView;

class CImplementationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CImplementationWidget(QWidget *parent = 0);
    void retranslateUi();

signals:

public slots:

private slots:
    void onUploadSolutionClicked();
    void onCompileSolutionClicked();
    void onLoadInputClicked();

private:
    void createUiElements();

    QPushButton *m_uploadSolutionButton = nullptr;
    QPushButton *m_compileSolutionButton = nullptr;
    QPushButton *m_loadInputsButton = nullptr;
    QLabel *m_solutionLabel = nullptr;
    QLabel *m_inputsLabel = nullptr;
    QLabel *m_consoleLabel = nullptr;
    QTextEdit *m_console = nullptr;
    QLineEdit *m_uploadSolutionLineEdit = nullptr;
    QStringListModel *m_stringModel = nullptr;
    QListView *m_inputsList = nullptr;
    QStringList m_inputs;
};

#endif // CIMPLEMENTATIONWIDGET_H
