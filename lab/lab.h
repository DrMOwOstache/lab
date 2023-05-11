#pragma once

#include <QtWidgets/QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QTextEdit>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QFormLayout>
#include <QRect>
#include <QGridLayout>
#include <QPushButton>
#include "ui_lab.h"

class lab : public QMainWindow
{
    Q_OBJECT

public:
    lab(QWidget *parent = nullptr);
    ~lab();

private:
    void setupUI();

    //==
    QWidget* centralWidget;
    //==
    QHBoxLayout* mainMusic;
    QVBoxLayout* firstColumn;
    //==
    QFormLayout* subLabels;
    QHBoxLayout* subSongs;
    //==
    QGridLayout* songOptions;
    //==
    QHBoxLayout* middleButton;
    //==
    QVBoxLayout* rightColumn;
    //==
    QGridLayout* playlistOptions;
    //==
    //first column
    //++
    QLabel* Songs;
    QListWidget* melody;
    //++
    QLabel* Title;
    QLineEdit* lineTitle;
    //++
    QLabel* Artist;
    QLineEdit* lineArtist;
    //++
    QLabel* Duration;
    QLineEdit* lineDuration;
    //++
    QLabel* Link;
    QLineEdit* lineLink;
    //++
    QPushButton* addB;
    QPushButton* delB;
    QPushButton* updB;
    QPushButton* fltB;
    //++
    QPushButton* transferB;
    //++
    QLabel* playlist;
    QListWidget* playlist_List;
    //++
    QPushButton* playB;
    QPushButton* nextB;
    //++

    Ui::labClass ui;
};
