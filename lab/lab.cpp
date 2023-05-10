#include "lab.h"
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

lab::lab(QWidget *parent)
    : QMainWindow(parent)
{
    int standartHeight = 5;
    int standartIndent = 0;

    QGroupBox* musicTab = new QGroupBox(tr("music"));

    QHBoxLayout* mainMusic = new QHBoxLayout;
    QVBoxLayout* firstColumn = new QVBoxLayout;


    /*QFormLayout* subTitle = new QFormLayout;
    QFormLayout* subArtist = new QFormLayout;
    QFormLayout* subDuration = new QFormLayout;
    QFormLayout* subLink = new QFormLayout;*/
    QFormLayout* subLabels = new QFormLayout;
    QHBoxLayout* subSongs = new QHBoxLayout;


    //++++++++++++++++//
    QLabel* Songs = new QLabel;
    Songs->setText("All songs");
    Songs->setIndent(0);
    Songs->setMargin(standartHeight);
    subSongs->addWidget(Songs);

    firstColumn->addItem(subSongs);

    //++++++++++++++++//
    QListWidget* melody = new QListWidget;
    //melody->setFixedHeight(standartHeight);

    firstColumn->addWidget(melody);

    //++++++++++++++++//
    QLabel* Title = new QLabel;
    Title->setText("Title:");
    Title->setIndent(standartIndent);
    Title->setMargin(standartHeight);
    //subTitle->addWidget(Title);

    QLineEdit* lineTitle = new QLineEdit;
    //subTitle->addWidget(lineTitle);
    subLabels->addRow(Title, lineTitle);


    //++++++++++++++++//
    QLabel* Artist = new QLabel;
    Artist->setText("Artist:");
    Artist->setIndent(standartIndent);
    Artist->setScaledContents(true);
    Artist->setMargin(standartHeight);
    //subArtist->addWidget(Artist);

    QLineEdit* lineArtist = new QLineEdit;

    subLabels->addRow(Artist, lineArtist);

    //subArtist->addWidget(lineArtist);
    //firstColumn->addItem(subArtist);

    //++++++++++++++++//
    QLabel* Duration = new QLabel;
    Duration->setText("Duration:");
    Duration->setIndent(standartIndent);
    Duration->setMargin(standartHeight);
    //subDuration->addWidget(Duration);

    QLineEdit* lineDuration = new QLineEdit;

    subLabels->addRow(Duration, lineDuration);

    //subDuration->addWidget(lineDuration);
    //firstColumn->addItem(subDuration);

    //++++++++++++++++//
    QLabel* Link = new QLabel;
    Link->setText("Link:");
    Link->setIndent(standartIndent);
    Link->setMargin(standartHeight);
    //subLink->addWidget(Link);

    QLineEdit* lineLink = new QLineEdit;

    subLabels->addRow(Link, lineLink);

    //subLink->addWidget(lineLink);
    //firstColumn->addItem(subLink);

    //++++++++++++++++//
    
   


    //++++++++++++++++//
    //----------------//


    

    //----------------//
    firstColumn->addItem(subLabels);
    mainMusic->addItem(firstColumn);
    musicTab->setLayout(mainMusic);
    //----------------//
    musicTab->show();

    ui.setupUi(this);
}

lab::~lab()
{}
