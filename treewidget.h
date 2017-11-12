#ifndef TREEWIDGET_H
#define TREEWIDGET_H
#include <QWidget>
#include <QTreeWidget>
#include <QMouseEvent>

class Treewidget : public QTreeWidget
{
    Q_OBJECT
   public:
       explicit Treewidget( QWidget *parent = 0 );
   protected:
       void mouseReleaseEvent (QMouseEvent *event);
};

#endif // TREEWIDGET_H
