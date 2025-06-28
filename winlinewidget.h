#ifndef WINLINEWIDGET_H
#define WINLINEWIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QPainter>

class WinLineWidget : public QWidget {
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)

public:
    WinLineWidget(QWidget *parent = nullptr);
    ~WinLineWidget();

    void setLine(QPoint start, QPoint end);
    qreal opacity() const;
    void setOpacity(qreal value);

private:
    QPoint startPoint;
    QPoint endPoint;
    qreal m_opacity = 1.0;
    QPropertyAnimation* animation = nullptr;

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // WINLINEWIDGET_H
