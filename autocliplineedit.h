#ifndef AUTOCLIPLINEEDIT_H
#define AUTOCLIPLINEEDIT_H

#include <QClipboard>
#include <QLineEdit>

class AutoClipLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit AutoClipLineEdit(QWidget *parent = nullptr);
    AutoClipLineEdit();
protected:
    void focusInEvent(QFocusEvent *event) override;
private:
    QClipboard *clipboard;
};

#endif // AUTOCLIPLINEEDIT_H
