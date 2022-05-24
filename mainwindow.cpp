#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stackedwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    StackedWidget *sw = new StackedWidget(this);
    //在主窗口中嵌入StackedWidget
    //初始化窗口对象,如果没有指定父对象，则为独立窗口
    //显示独立窗口必须使用show()
}

MainWindow::~MainWindow()
{
    delete ui;
}

