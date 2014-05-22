#ifndef VIEWER_H
#define VIEWER_H

#include <QTimer>
#include <QGLWidget>
#include <modelFile/modelFile.h>

class Viewer : public QGLWidget
{
    Q_OBJECT
public:
    explicit Viewer(int framesPerSecond = 20, QWidget *parent = 0, char *name = 0);
    void setModel(SimpleModel *model);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void keyPressEvent( QKeyEvent *keyEvent );

    void setPlateDimension(float width, float height);

    SimpleModel *model;
    float t;
    float plateWidth, plateHeight;

public slots:
    virtual void timeOutSlot();

private:
    QTimer *t_Timer;
};

#endif // VIEWER_H