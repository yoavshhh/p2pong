#include "autocliplineedit.h"

#include <QApplication>
#include <QThread>

AutoClipLineEdit::AutoClipLineEdit(QWidget *parent) :
    QLineEdit(parent),
    clipboard(QApplication::clipboard())
{

}

AutoClipLineEdit::AutoClipLineEdit() :
    clipboard(QApplication::clipboard())
{

}

void AutoClipLineEdit::focusInEvent(QFocusEvent *event)
{
    QString clip = clipboard->text();
    qInfo() << "Focus " << clip << "\n";
    if (clip.length() == 6) {
        setText(clip);
        emit returnPressed();
    } else {
        QLineEdit::focusInEvent(event);
    }
}
