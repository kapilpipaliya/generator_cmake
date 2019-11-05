#ifndef GLOBAL_H
#define GLOBAL_H

#include <QDebug>
#include <QDir>
#include "./searcher.h"

static QStringList __debug_start__ = {QString("noscope")};

struct BashrcSource {
  QString bashrc;
  QString program;
  QString bashrcAliases;
};

#define joinPath(path1, path2) \
  QDir::cleanPath(path1 + QDir::separator() + path2)

#define NAME QString("MX Bashrc Config")
#define NAME_BIN QString("mx-bashrc-config")
#define ORG QString("MX-Linux")

#define USER_BASHRC joinPath(QDir::homePath(), ".bashrc")
#define USER_BASHRC_ALIASES joinPath(QDir::homePath(), ".bash_aliases")
#define PROGRAM_BASHRC \
  joinPath(QDir::homePath(), ".config/mx-bashrc-config/bashrc.bash")
#define SUGGEST_ALIASES joinPath(QDir::homePath(), "suggest_aliases")
#define BACKUP_BASHRCS joinPath(QDir::homePath(), ".config/mx-bashrc-config/")

#define DEBUG qDebug() << __debug_start__.last()
#define DEBUG_VAR(x) \
  qDebug() << __debug_start__.last() << ":" << #x << " = " << x
#define DEBUG_POS qDebug() << __FILE__ << ":" << __LINE__
#define CHECK_SEARCH(x)                              \
  ((x != Searcher::ReturnValueSearchStatesFailed) && \
   (x != Searcher::ReturnValueSearchStringNotFound))
#define DEBUG_ENTER(x)                                                    \
  __debug_start__.append(tr(__FILE__) + ":" + QString::number(__LINE__) + \
                         ":" + tr(#x))  // qDebug() << "+++ " << #x << " +++"
#define DEBUG_EXIT(x) \
  __debug_start__.pop_back()  // qDebug() << "--- " << #x << " ---"
#define CHECK(x) \
  if (x == -1) continue
#endif  // GLOBAL_H
