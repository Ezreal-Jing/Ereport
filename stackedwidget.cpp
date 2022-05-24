#include "stackedwidget.h"
#include "ui_stackedwidget.h"
#include <iostream>
#include <qprinter.h>
#include <QDateTime>
#include <QtWidgets>

using namespace std;

StackedWidget::StackedWidget(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::StackedWidget)
{
    ui->setupUi(this);
}

StackedWidget::~StackedWidget()
{
    delete ui;
}



void StackedWidget::on_Nextbtn_clicked()
{
//    if(ui->comboBox->currentIndex()==0)
//        cout<<"10086"<<endl;
//    else if(ui->comboBox->currentIndex()==1)
//        cout<<"10010"<<endl;
//    else if(ui->comboBox->currentIndex()==2)
//        cout<<"10000"<<endl;


    int i = currentIndex();
    setCurrentIndex(++i);
}

void StackedWidget::on_Nextbtn_2_clicked()
{

    int i = currentIndex();
    setCurrentIndex(++i);
}


void StackedWidget::on_Backbtn_clicked()
{
    exit(0);
}


void StackedWidget::on_Backbtn_2_clicked()
{
    int i = currentIndex();
    setCurrentIndex(--i);
}












//核心代码，创建PDF
void StackedWidget::PDFcreat()
{

    //获取当前时间
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");

    //获取第一个表格输入
    QString pro_name = ui->ProjectName->toPlainText();
    QString stu_name = ui->StuffName->toPlainText();
    QString chip_name = ui->ChipName->toPlainText();




    //设置字体，懒得麻烦
    //style=\"font-family:宋体\"
    //注意转义符号反斜杠的使用
    //第一个表格
    QString html1 =
            "<br>"
            "<html>"
            "<head>"
            "<style>"
            "table,th, td {border: 1px solid black;border-collapse: collapse;}"
            "</style>"
            "</head>"
            "<body>"

            "<h2 align=center>"+pro_name+"测试报告</h2>"


            "<table align=center width=\"100%\">"

            "<tr>"
            "<th>测试项目</th>"
            "<th>"+pro_name+"</th>"

            "</tr>"
            "<tr>"
            "<th>测试人员</th>"
            "<th>"+stu_name+"</th>"

            "</tr>"
            "<tr>"
            "<th>测试时间</th>"
            "<th>"+current_date+"</th>"

            "</tr>"
            "<tr>"
            "<th>芯片型号</th>"
            "<th>"+chip_name+"</th>"


            "</tr>"
            "</table>"

            "</body>"
            "</html>";

    //获取第二个表格输入
    QString spt_name = ui->ScriptName->toPlainText();
    QString spt_des = ui->ScriptDescribe->toPlainText();
    QString special_des = ui->SpecialDescribe->toPlainText();
    QString spt_path = ui->ScrpitPath->toPlainText();

    QString cb_3,cb_4,cb_5,cb_6;
    if(ui->comboBox_3->currentIndex()==0)
        cb_3 = "通过";
    else
        cb_3 = "N/A";

    if(ui->comboBox_4->currentIndex()==0)
        cb_4 = "通过";
    else
        cb_4 = "N/A";
    if(ui->comboBox_5->currentIndex()==0)
        cb_5 = "通过";
    else
        cb_5 = "N/A";
    if(ui->comboBox_6->currentIndex()==0)
        cb_6 = "通过";
    else
        cb_6 = "N/A";


    //第二个表格
    QString html2 =

            "<html>"
            "<head>"
            "<style>"
            "table, th, td {border: 1px solid black;border-collapse: collapse;}"
            "</style>"
            "</head>"
            "<body>"

            "<h2 align=center>文件名称及说明</h2>"


            "<table align=center width=\"100%\">"
              "<tr>"
                "<th rowspan=\"2\">项目</th>"
                "<th colspan=\"2\">测试结果</th>"
              "</tr>"
              "<tr>"
                "<td width=\"10%\" align=center>结论</td>"
                "<td align=center>备注</td>"
              "</tr>"

              "<tr>"
                "<td align=left>文档命名</td>"
                "<td align=center>"+cb_3+"</td>"
                "<td align=center>"+spt_name+"</td>"
              "</tr>"

              "<tr>"
                "<td align=left>文档说明</td>"
                "<td align=center>"+cb_4+"</td>"
                "<td align=center>"+spt_des+"</td>"
              "</tr>"

              "<tr>"
                "<td align=left>文档特殊说明</td>"
                "<td align=center>"+cb_5+"</td>"
                "<td align=center>"+special_des+"</td>"
              "</tr>"

              "<tr>"
                "<td align=left>文档禅道</td>"
                "<td align=center>"+cb_6+"</td>"
                "<td align=center>"+spt_path+"</td>"
              "</tr>"




            "</table>"
            "</body>"
            "</html>";












    //const QString filepath = "C:/Users/Ezreal/Desktop/123.pdf";
    //选择保存路径
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Repot"), "",
        tr("new report (*.pdf);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }
        QDataStream out(&file);
    }


    QString html = html1 + html2;
    //写入文件
    QTextDocument document;
    document.setHtml(html);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A4);
    printer.setOutputFileName(fileName);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    document.print(&printer);


}



void StackedWidget::on_Backbtn_3_clicked()
{
    int i = currentIndex();
    setCurrentIndex(--i);
}


void StackedWidget::on_Nextbtn_3_clicked()
{
    PDFcreat();
}

