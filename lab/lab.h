#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab.h"

class lab : public QMainWindow
{
    Q_OBJECT

public:
    lab(QWidget *parent = nullptr);
    ~lab();

private:
    Ui::labClass ui;
};
