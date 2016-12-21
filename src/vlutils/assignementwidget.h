#ifndef CASSIGNEMENTWIDGET_H
#define CASSIGNEMENTWIDGET_H

#include <QWidget>

class QWebEngineView;
class QLabel;

class CAssignementWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CAssignementWidget(QWidget *parent = 0);
    void retranslateUi();
    void setHtmlFromFile(const QString & filename);

signals:

public slots:
private:
    void createUiElements();

    QWebEngineView *m_page;
};

#endif // CASSIGNEMENTWIDGET_H
