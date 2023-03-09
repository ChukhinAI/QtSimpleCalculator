#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"


double first_num;
double second_num;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zero_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->one_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->two_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->three_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->four_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->five_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->six_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->seven_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->eight_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->nine_button, SIGNAL(clicked()), this, SLOT(numbers()));

    connect(ui->sign_button, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->percent_button, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->plus_button, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->minus_button, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->div_button, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->multypluy_button, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->plus_button->setCheckable(true);
    ui->minus_button->setCheckable(true);
    ui->div_button->setCheckable(true);
    ui->multypluy_button->setCheckable(true);

    /*
    connect(ui->nine_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->nine_button, SIGNAL(clicked()), this, SLOT(numbers()));
    connect(ui->nine_button, SIGNAL(clicked()), this, SLOT(numbers()));
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numbers()
{
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;
    //all_numbers = (ui->output_label->text() + button->text()).toDouble();
    //ui->output_label->setText(button->text()); // put text into my answer area(output_label)
    QString all_numbers_text = ui->output_label->text() + button->text();

    //ui->output_label->setText(QString::number(all_numbers, 'g', 12));
    ui->output_label->setText(all_numbers_text);

    qDebug()<< "";
    qDebug()<<"first_num in numbers = " << first_num;
    qDebug()<<"second_num in numbers = " << second_num;
    qDebug()<<"all_numbers in numbers = " << all_numbers;
    qDebug()<< "";
}


void MainWindow::on_dot_button_clicked()
{
    if (!(ui->output_label->text().contains('.')))
        ui->output_label->setText(ui->output_label->text() + ".");
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;

    if(button->text() == "+/-")
    {
        all_numbers = (ui->output_label->text()).toDouble();
        all_numbers *= -1;

        ui->output_label->setText(QString::number(all_numbers, 'g', 12));
    }
    else if (button->text() == "%")
    {
        all_numbers = (ui->output_label->text()).toDouble();
        all_numbers *= 0.01;

        ui->output_label->setText(QString::number(all_numbers, 'g', 12));
    }
}

void MainWindow::on_AC_button_clicked()
{
    ui->output_label->setText("");
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *) sender();

    qDebug()<<"output_label->text() in math before = " << ui->output_label->text();
    qDebug()<<"first_num in math after = " << first_num;
    first_num = ui->output_label->text().toDouble();

    qDebug()<<"first_num in math after = " << button->objectName();
    //ui->output_label->setText(""); // RIGHT
    //ui->output_label->setText(QString::number(first_num) + " - "); // test
    //ui->output_label->setText(QString::number(first_num) + button->objectName());

    if (button->objectName() == "plus_button")
    {
        ui->output_label->setText(QString::number(first_num) + " + ");
    }

    else if (button->objectName() == "minus_button")
    {
        ui->output_label->setText(QString::number(first_num) + " - ");
    }

    else if (button->objectName() == "div_button")
    {
        ui->output_label->setText(QString::number(first_num) + " / ");
    }

    else if (button->objectName() == "multypluy_button")
    {
        ui->output_label->setText(QString::number(first_num) + " * ");
    }

    button->setChecked(true);
}

void MainWindow::on_equals_button_clicked()
{
    double label_number;
    QString new_label;
    second_num = ui->output_label->text().toDouble();

    qDebug()<<"second_num in eq but = " << second_num;

    QString first_num_text = QString::number(first_num);
    QString second_num_text = ui->output_label->text();
    //QString res = second_num_text.remove(second_num_text.indexOf(first_num_text), first_num_text.length());
    QString res = second_num_text.remove(second_num_text.indexOf(first_num_text), first_num_text.length() + 3);

    bool ok;
    second_num = res.toDouble(&ok);

    qDebug()<<"res in eq but = " << res;

    //second_num = ui->output_label->text().toDouble();
    //second_num = res.toDouble();

     qDebug()<<"second_num in eq but = " << second_num;

    if (ui->plus_button->isChecked())
    {
        qDebug()<<"first_num in cheked = " << first_num;
        qDebug()<<"second_num in cheked = " << second_num;

        label_number = first_num + second_num;
        new_label = QString::number(label_number, 'g', 12);

        //ui->output_label->setText(new_label);
        ui->output_label->setText(new_label);
        ui->plus_button->setChecked(false);
    }

    if (ui->minus_button->isChecked())
    {
        qDebug()<<"first_num = " << first_num;
        qDebug()<<"second_num = " << second_num;

        label_number = first_num - second_num;
        new_label = QString::number(label_number, 'g', 12);

        ui->output_label->setText(new_label);
        ui->minus_button->setChecked(false);
    }

    if (ui->div_button->isChecked())
    {
        qDebug()<<"first_num = " << first_num;
        qDebug()<<"second_num = " << second_num;

        if (second_num == 0)
        {
            ui->output_label->setText("zero div error!");
            ui->div_button->setChecked(false);
        }
        else
        {
            label_number = first_num / second_num;
            new_label = QString::number(label_number, 'g', 12);

            ui->output_label->setText(new_label);
            ui->div_button->setChecked(false);
        }
    }

    if (ui->multypluy_button->isChecked())
    {
        qDebug()<<"first_num = " << first_num;
        qDebug()<<"second_num = " << second_num;

        label_number = first_num * second_num;
        new_label = QString::number(label_number, 'g', 12);

        ui->output_label->setText(new_label);
        ui->multypluy_button->setChecked(false);
    }
}






































