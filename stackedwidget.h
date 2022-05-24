#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H
#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class StackedWidget;
}

class StackedWidget : public QStackedWidget
{
    Q_OBJECT

public:
    explicit StackedWidget(QWidget *parent = nullptr);
    ~StackedWidget();
    //处理PDF的函数
    void PDFcreat();





private slots:
    void on_Nextbtn_clicked();

    void on_Backbtn_clicked();

    void on_Backbtn_2_clicked();

    void on_Nextbtn_2_clicked();

    void on_Backbtn_3_clicked();

    void on_Nextbtn_3_clicked();

private:
    Ui::StackedWidget *ui;
};

#endif // STACKEDWIDGET_H
