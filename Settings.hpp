#pragma once

#include <QSize>

class Settings
{
    public:
    Settings(){};
    virtual ~Settings(){};

    QSize resolution;
    int screenSpaceAntialiasing,
        postAntialiasing;
    bool fullScreen,
        muted,
        recordDemo;
    QString audioOutputFilename,
        videoOutputFilename;
};