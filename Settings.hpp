#pragma once

#include <QPoint>

class Settings
{
    public:
    Settings(){};
    virtual ~Settings(){};

    QPoint resolution;
    int screenSpaceAntialiasing,
        postAntialiasing;
    bool fullScreen,
        muted,
        recordDemo;
    QString audioOutputFilename,
        videoOutputFilename;
};