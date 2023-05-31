#include "lab.h"


lab::lab(QWidget *parent)
    : QMainWindow(parent)
{

    this->setupUI();

    connectorSetup();
    //ui.setupUi(this);
}

void lab::connectorSetup()
{
    connect(addB, SIGNAL(released()), this, SLOT(addSong()));
    connect(delB, SIGNAL(released()), this, SLOT(removeSong()));
    connect(updB, SIGNAL(released()), this, SLOT(updateSong()));
    connect(fltB, SIGNAL(released()), this, SLOT(filterSong()));
    connect(transferB, SIGNAL(released()), this, SLOT(transferSong()));

}

void lab::addSong()
{
    std::string dur = lineDuration->text().toLocal8Bit().constData();
    //qDebug() << dur;
    int h = 0, m = 0, s = 0, i;
    for (i = 0; dur[i] != '\0'; i++)
    {
        //qDebug() << dur[i] << ' ' << s;
        if (dur[i] == ':' || dur[i] == '.' || dur[i] == '.' || dur[i] == '\0')
        {
            while ((dur[i] == ':' || dur[i] == '.' || dur[i] == '.') && dur[i] != '\0')
                i++;
            s++;
            i--;
        }
    }

    i = 0;
    while (s == 2)
    {
        if (dur[i] == ':' || dur[i] == '.' || dur[i] == '.' || dur[i] == '\0')
        {
            while ((dur[i] == ':' || dur[i] == '.' || dur[i] == '.') && dur[i] != '\0')
                i++;
            s--;
            i--;
        }
        else
            h = h * 10 + dur[i] - '0';
        i++;
    }

    while (s == 1)
    {
        if (dur[i] == ':' || dur[i] == '.' || dur[i] == '.' || dur[i] == '\0')
        {
            while ((dur[i] == ':' || dur[i] == '.' || dur[i] == '.') && dur[i] != '\0')
                i++;
            s--;
            i--;
        }
        else
            m = m * 10 + dur[i] - '0';
        i++;
    }

    while (dur[i] != '\0')
    {
        if (dur[i] == ':' || dur[i] == '.' || dur[i] == '.' || dur[i] == '\0')
        {
            while ((dur[i] == ':' || dur[i] == '.' || dur[i] == '.') && dur[i] != '\0')
                i++;
            s--;
            i--;
        }
        else
            s = s * 10 + dur[i] - '0';
        i++;
    }

    //QString elem = QString(lineTitle->text() + " made by " + lineArtist->text() + " of duration "
    //    + QString::number(h) + ":"
    //    + QString::number(m) + ":"
    //    + QString::number(s));
    //bool ok = false;
    //if (!lSong.getSongs().empty())
    //    for (int i = 0; i < lSong.getSongs().size() && ok == false; i++)
    //    {
    //        qDebug() << melody->item(i)->text() << " == " << elem << " it's " << (melody->item(i)->text() == elem);
    //        if (melody->item(i)->text() == elem)
    //            ok = true;
    //    }


    bool ok;
    //qDebug() << "lol";
    ok = lSong.addSong(Song(std::string(lineTitle->text().toLocal8Bit().constData()),
        std::string(lineArtist->text().toLocal8Bit().constData()),
        std::string(lineLink->text().toLocal8Bit().constData()),
        std::tuple<int, int, int >{h, m, s}));

    if (ok == true)
    {
        melody->addItem(QString(QString::fromStdString(lSong.getSongs()[lSong.getSongs().size() - 1].getTitle()) + " made by "
            + QString::fromStdString(lSong.getSongs()[lSong.getSongs().size() - 1].getArtist()) + " of duration "
            + QString::number(get<0>(lSong.getSongs()[lSong.getSongs().size() - 1].getDuration())) + ":"
            + QString::number(get<1>(lSong.getSongs()[lSong.getSongs().size() - 1].getDuration())) + ":"
            + QString::number(get<2>(lSong.getSongs()[lSong.getSongs().size() - 1].getDuration()))));

        lSong.updateFile();
    }
}

void lab::removeSong()
{
    if (!melody->selectedItems().empty())
    {
        lSong.removeSong(melody->row(melody->selectedItems()[0]));
        //qDebug() << melody->row(melody->selectedItems()[0]);
        melody->takeItem(melody->row(melody->selectedItems()[0]));
        lSong.updateFile();
    }
}

void lab::filterSong()
{
    NotImplemented = new QMessageBox();
    NotImplemented->information(this, "What happen'?", "Not implemented yet!");
}

void lab::updateSong()
{
    NotImplemented = new QMessageBox();
    NotImplemented->information(this, "What happen'?", "Not implemented yet!");
}

void lab::transferSong()
{
    if (!melody->selectedItems().empty())
    {
        int selected = melody->row(melody->selectedItems()[0]);

        playlist_List->addItem(QString(QString::fromStdString(lSong.getSongs()[selected].getTitle()) + " made by "
            + QString::fromStdString(lSong.getSongs()[selected].getArtist()) + " of duration "
            + QString::number(get<0>(lSong.getSongs()[selected].getDuration())) + ":"
            + QString::number(get<1>(lSong.getSongs()[selected].getDuration())) + ":"
            + QString::number(get<2>(lSong.getSongs()[selected].getDuration()))));

        playLSong.addSong(lSong.getSongs()[selected],true);
        playLSong.updateFile();
    }
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

    if (!lSong.getSongs().empty())
        for (int i = 0; i < lSong.getSongs().size(); i++)
            melody->addItem(QString(QString::fromStdString(lSong.getSongs()[i].getTitle()) + " made by "
                + QString::fromStdString(lSong.getSongs()[i].getArtist()) + " of duration "
                + QString::number(get<0>(lSong.getSongs()[i].getDuration())) + ":"
                + QString::number(get<1>(lSong.getSongs()[i].getDuration())) + ":"
                + QString::number(get<2>(lSong.getSongs()[i].getDuration()))));

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

    if (!playLSong.getSongs().empty())
        for (int i = 0; i < playLSong.getSongs().size(); i++)
            playlist_List->addItem(QString(QString::fromStdString(playLSong.getSongs()[i].getTitle()) + " made by "
                + QString::fromStdString(playLSong.getSongs()[i].getArtist()) + " of duration "
                + QString::number(get<0>(playLSong.getSongs()[i].getDuration())) + ":"
                + QString::number(get<1>(playLSong.getSongs()[i].getDuration())) + ":"
                + QString::number(get<2>(playLSong.getSongs()[i].getDuration()))));

    rightColumn->addWidget(playlist_List);
    //++++++++++++++++//

    playB = new QPushButton("Play");
    nextB = new QPushButton("Next");

    playlistOptions->addWidget(playB, 0, 0);
    playlistOptions->addWidget(nextB, 0, 1);

    //++++++++++++++++//
    //----------------//

    firstColumn->addLayout(subLabels);
    firstColumn->addLayout(songOptions);

    //----------------//

    rightColumn->addLayout(playlistOptions);

    //----------------//
    mainMusic->addLayout(firstColumn);
    mainMusic->addLayout(middleButton);
    mainMusic->addLayout(rightColumn);
    centralWidget->setLayout(mainMusic);
    this->setCentralWidget(centralWidget);


    //----------------//

}


