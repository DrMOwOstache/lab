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
#include <QMessageBox>
#include "ui_lab.h"


#include "Song.h"
#include <vector>

class lab : public QMainWindow
{
    Q_OBJECT

public:
    lab(QWidget *parent = nullptr);
    ~lab();

private slots:
    void addSong();
    void removeSong();
    void filterSong();
    void updateSong();

    void transferSong();

private:
    //++Song++//

    std::vector<Song> lSong;
    std::vector<Song> playLSong;

    //++Song++//

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
    //left column
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
    //middle column
    //++
    QPushButton* transferB;
    //++
    //right column
    //++
    QLabel* playlist;
    QListWidget* playlist_List;
    //++
    QPushButton* playB;
    QPushButton* nextB;
    //++
    //MessageBox
    //++
    QMessageBox* NotImplemented;
    QPushButton* OKB;

    //++
    //actions
    //--
    void connectorSetup();
    QString intToQString(int n);


    //--

    Ui::labClass ui;
};
