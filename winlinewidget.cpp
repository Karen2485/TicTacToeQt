#include "winlinewidget.h"

WinLineWidget::WinLineWidget(QWidget *parent)
    : QWidget(parent)
{
    // Прозрачный фон
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);

    // Анимация мигания
    animation = new QPropertyAnimation(this, "opacity", this);
    animation->setDuration(1000);
    animation->setStartValue(1.0);
    animation->setEndValue(0.3);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->setLoopCount(-1);
    animation->start();
}

WinLineWidget::~WinLineWidget() {
    if (animation) {
        animation->stop();
        animation->deleteLater();
    }
}

void WinLineWidget::setLine(QPoint start, QPoint end) {
    startPoint = start;
    endPoint = end;

    QRect bounds = QRect(start, end).normalized().adjusted(-10, -10, 10, 10);
    setGeometry(bounds);
    update();
}

qreal WinLineWidget::opacity() const {
    return m_opacity;
}

void WinLineWidget::setOpacity(qreal value) {
    m_opacity = value;
    update();
}

void WinLineWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::gray, 3, Qt::SolidLine, Qt::RoundCap);
    pen.setColor(QColor(128, 128, 128, static_cast<int>(255 * m_opacity)));
    painter.setPen(pen);

    QPoint start = startPoint - geometry().topLeft();
    QPoint end = endPoint - geometry().topLeft();

    painter.drawLine(start, end);
}
