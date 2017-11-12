#include "treewidget.h"
#include <QMessageBox>

Treewidget::Treewidget(QWidget *parent)
    :QTreeWidget(parent)
{

}

void Treewidget::mouseReleaseEvent (QMouseEvent *event)
{
//    if (event->button () & Qt::RightButton )
//    {
//        emit customContextMenuRequested( event->pos ());
//    }else if (event->button () & Qt::LeftButton){
//        emit itemClicked(this->itemAt(event->pos()), 0);
//    }
}
