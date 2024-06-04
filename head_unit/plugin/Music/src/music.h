// music.h
#ifndef music_H
#define music_H

#include <QObject>
#include <QStringList>
#include <QDir>
#include <QMediaPlayer>
#include <QFileSystemWatcher>

class Music : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList fileList READ fileList NOTIFY fileListChanged)



public:
    explicit Music(QObject *parent = nullptr);
    QStringList fileList() const;

    Q_INVOKABLE void startUSBScan();



signals:
    void usbInserted();
    void usbRemoved(bool status);
    void fileListChanged();


private:
    bool usb_status;

    QStringList m_fileList;
    QMediaPlayer m_mediaPlayer;
    QString m_usbDrivePath;
    QFileSystemWatcher usbWatcher;
    QString usbDirPath;

    void loadSongsFromUSB();
    void mountUSB();
    bool isUSBDriveMounted();
    QString findUSBDevice();
    void umountUSB();
    void removeUsbDirectory();
    void handleDirectoryChange(const QString &path);
};

#endif // Music_H
