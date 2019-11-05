/*
* This file is part of Octopi, an open-source GUI for pacman.
* Copyright (C) 2013 Alexandre Albuquerque Arnt
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*/

#include "termwidget.h"


#include <QClipboard>
#include <QApplication>
#include <QMenu>
#include <QMessageBox>
#include <QAbstractButton>

/*
 * This class extends some features of QTermWidget and adds some customizations
 */

TermWidget::TermWidget(QWidget *parent):
  QTermWidget(parent)
{
  QFont font = QApplication::font();
  font.setFamily("Monospace");
  setTerminalFont(font);
  setScrollBarPosition(QTermWidget::ScrollBarRight);
  changeDir("/");
  setColorScheme("WhiteOnBlack");
  execute("export TERM=xterm");
  execute("clear");
  setContextMenuPolicy(Qt::CustomContextMenu);

  m_actionZoomIn = new QAction(this);
  m_actionZoomIn->setText("Zoom in");
  m_actionZoomIn->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Plus));
  connect(m_actionZoomIn, &QAction::triggered, this, &TermWidget::onZoomIn);

  m_actionZoomOut = new QAction(this);
  m_actionZoomOut->setText("Zoom out");
  m_actionZoomOut->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Minus));
  connect(m_actionZoomOut, &QAction::triggered, this, &TermWidget::onZoomOut);

  m_actionMaximize = new QAction(this);
  m_actionMaximize->setText("Maximize");
  m_actionMaximize->setShortcut(QKeySequence(Qt::Key_F11));
  connect(m_actionMaximize, &QAction::triggered, this, &TermWidget::onKeyF11);

  m_actionPaste = new QAction(this);
  m_actionPaste->setText("Paste");
  connect(m_actionPaste, &QAction::triggered, this, &TermWidget::onPaste);

  addAction(m_actionZoomIn);
  addAction(m_actionZoomOut);
  addAction(m_actionMaximize);

  connect(this, SIGNAL(receivedData(QString)), this, SLOT(parseOutput(QString)));
  connect(this, SIGNAL(termKeyPressed(QKeyEvent*)), this, SLOT(onKeyPressed(QKeyEvent*)));
  connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(execContextMenu(const QPoint&)));

}


/*
 * Sends the given command to be executed in this terminal
 */
void TermWidget::execute(QString command)
{
  this->sendText(command);
  //After every command, we must send ENTER/RETURN
  this->enter();
}

/*
 * Sends the ENTER/RETURN key to this terminal
 */
void TermWidget::enter()
{
  //This is the ENTER/RETURN key!
  QString enter("\r");
  this->sendText(enter);
}

/*
 * Whenever we find "Press any key to continue..."
 */
void TermWidget::parseOutput(QString str)
{
  if (str.contains("Press any key to continue..."))
  {
    emit onPressAnyKeyToContinue();
  }
  else if (str.contains("quit: command not found") ||
           str.contains("close: command not found"))
  {
    emit onKeyQuit();
  }
}

/*
 * Whenever user hits a key inside this terminal
 */
void TermWidget::onKeyPressed(QKeyEvent *ke)
{
  if ((ke->key() == Qt::Key_Z && ke->modifiers() == Qt::ControlModifier) ||
    (ke->key() == Qt::Key_D && ke->modifiers() == Qt::ControlModifier) ||
    (ke->key() == Qt::Key_C && ke->modifiers() == Qt::ControlModifier))
  {
    emit onCancelControlKey();
  }
}

/*
 * Creates terminal's custom context menu with some options to configure its behaviour
 */
void TermWidget::execContextMenu(const QPoint & pos)
{
  QMenu menu;
  menu.addAction(m_actionZoomIn);
  menu.addAction(m_actionZoomOut);

  if (qApp->clipboard()->text().isEmpty())
    m_actionPaste->setEnabled(false);
  else {
    m_actionPaste->setEnabled(true);
  }

  menu.addAction(m_actionPaste);
  menu.addAction(m_actionMaximize);
  menu.exec(mapToGlobal(pos));
}

/*
 * Calls paste() code
 */
void TermWidget::onPaste()
{
  paste(QClipboard::Clipboard);
}


void TermWidget::onZoomIn()
{
  m_zoomFactor++;
  emit zoomIn();
}

void TermWidget::onZoomOut()
{
  m_zoomFactor--;
  emit zoomOut();
}

/*
 * Paste code extracted from project "lxqt/qterminal"
 */
void TermWidget::paste(QClipboard::Mode mode)
{
  // Paste Clipboard by simulating keypress events
  QString text = QApplication::clipboard()->text(mode);
  if ( ! text.isEmpty() )
  {
    text.replace(QLatin1String("\r\n"), QLatin1String("\n"));
    text.replace(QLatin1Char('\n'), QLatin1Char('\r'));
    QString trimmedTrailingNl(text);
    trimmedTrailingNl.replace(QRegExp(QStringLiteral("\\r+$")), QString());
    /*bool isMultiline = trimmedTrailingNl.contains(QLatin1Char('\r'));
        if (!isMultiline && Properties::Instance()->trimPastedTrailingNewlines)
        {
            text = trimmedTrailingNl;
        }
    if (text.contains(QLatin1Char('\r')))
    {
      QMessageBox confirmation(this);
      confirmation.setWindowTitle(tr("Paste multiline text"));
      confirmation.setText(tr("Are you sure you want to paste this text?"));
      confirmation.setDetailedText(text);
      confirmation.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
      // Click "Show details..." to show those by default
      const auto buttons = confirmation.buttons();

      for( QAbstractButton * btn : buttons )
      {
        if (confirmation.buttonRole(btn) == QMessageBox::ActionRole && btn->text() == QMessageBox::tr("Show Details..."))
        {
          btn->clicked();
          break;
        }
      }
      confirmation.setDefaultButton(QMessageBox::Yes);
      confirmation.exec();

      if (confirmation.standardButton(confirmation.clickedButton()) != QMessageBox::Yes)
      {
        return;
      }
    }*/

    bracketText(text);
    sendText(text);
    qApp->clipboard()->clear();
  }
}
