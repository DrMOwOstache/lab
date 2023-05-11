#include "lab.h"


lab::lab(QWidget *parent)
    : QMainWindow(parent)
{
    this->setupUI();
    //ui.setupUi(this);
}

lab::~lab()
{}

void lab::setupUI()
{
    int standartHeight = 5;
    int standartIndent = 0;
    //================//

    centralWidget = new QWidget;

    //================//

    mainMusic = new QHBoxLayout;
    firstColumn = new QVBoxLayout;

    //================//

    subLabels = new QFormLayout;
    subSongs = new QHBoxLayout;

    //================//
    songOptions = new QGridLayout;

    songOptions->setSpacing(5);
    //================//
    middleButton = new QHBoxLayout;

    //================//
    rightColumn = new QVBoxLayout;

    //================//
    playlistOptions = new QGridLayout;

    //================//
    //++++++++++++++++//
    Songs = new QLabel("All songs");
    melody = new QListWidget;

    subSongs->addWidget(Songs);

    firstColumn->addItem(subSongs);
    firstColumn->addWidget(melody);

    //++++++++++++++++//
    Title = new QLabel("Title:");
    lineTitle = new QLineEdit;

    Title->setMargin(standartHeight);

    subLabels->addRow(Title, lineTitle);

    //++++++++++++++++//
    Artist = new QLabel("Artist:");
    lineArtist = new QLineEdit;

    Artist->setMargin(standartHeight);

    subLabels->addRow(Artist, lineArtist);

    //++++++++++++++++//
    Duration = new QLabel("Duration:");
    lineDuration = new QLineEdit;

    Duration->setMargin(standartHeight);

    subLabels->addRow(Duration, lineDuration);

    //++++++++++++++++//
    Link = new QLabel("Link:");
    lineLink = new QLineEdit;

    Link->setMargin(standartHeight);

    subLabels->addRow(Link, lineLink);

    //++++++++++++++++//

    addB = new QPushButton("Add");

    songOptions->addWidget(addB,0,0);

    //++++++++++++++++//

    delB = new QPushButton("Delete");

    songOptions->addWidget(delB,0,1);

    //++++++++++++++++//

    updB = new QPushButton("Update");

    songOptions->addWidget(updB,0,2);

    //++++++++++++++++//

    fltB = new QPushButton("Filter");

    songOptions->addWidget(fltB,1,1);

    //++++++++++++++++//
    
    transferB = new QPushButton(">");
    
    middleButton->addWidget(transferB);

    //++++++++++++++++//

    playlist = new QLabel("Playlist");

    rightColumn->addWidget(playlist);

    //++++++++++++++++//

    playlist_List = new QListWidget;

    rightColumn->addWidget(playlist_List);
    //++++++++++++++++//

    playB = new QPushButton("Play");
    nextB = new QPushButton("Next");

    playlistOptions->addWidget(playB, 0, 0);
    playlistOptions->addWidget(nextB, 0, 1);

    //++++++++++++++++//
    //----------------//

    firstColumn->addItem(subLabels);
    firstColumn->addItem(songOptions);

    //----------------//

    rightColumn->addItem(playlistOptions);

    //----------------//
    mainMusic->addItem(firstColumn);
    mainMusic->addItem(middleButton);
    mainMusic->addItem(rightColumn);
    centralWidget->setLayout(mainMusic);
    this->setCentralWidget(centralWidget);

    //----------------//

}
