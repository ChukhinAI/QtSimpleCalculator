#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void numbers();
    void on_dot_button_clicked();
    void operations();
    void on_AC_button_clicked();
    void on_plus_button_clicked();
    void math_operations();
    void on_equals_button_clicked();
};
#endif // MAINWINDOW_H
