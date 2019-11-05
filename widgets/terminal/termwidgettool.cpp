#include "termwidgettool.h"

TermWidgetTool::TermWidgetTool(QWidget *parent) : QWidget(parent) {
  terminal = new TermWidget(this);

  auto v = new QVBoxLayout(this);
  h = new QHBoxLayout();

  addButton("Up", "Up Dir", "..");
  addButton("Paste", "Paste from Clipboard",
            [this]() { terminal->pasteClipboard(); });
  addButton("Search", "Toogle Searchbar",
            [this]() { terminal->toggleShowSearchBar(); });
  addButton("Tmux new", "New Tmux session",
            [this]() { terminal->sendText("tmux new-session -s "); });
  addButton("Tmux attach", "Attach to a session",
            [this]() { terminal->sendText("tmux attach -t  "); });
  addButton("Tmux help", "Tmux help", []() {
    QDesktopServices::openUrl(QUrl(
        "https://gist.github.com/mortezaipo/285b6b9434a60447ff482a4fd5628118",
        QUrl::TolerantMode));
  });
  addButton("Exit", "send exit", [this]() { terminal->execute("exit"); });
  addButton("Go to End", "Scroll To End",
            [this]() { terminal->scrollToEnd(); });
  addButton("Home", "cd ~", [this]() { terminal->execute("cd ~"); });
  addButton("Tree", "Send Tree Path", [this]() {
    auto mindex = tree->currentIndex();
    auto path = model->filePath(mindex);
    terminal->sendText(path);
  });
  addButton("Title", "set title", [this]() {
    bool ok;
    QString text =
        QInputDialog::getText(this, "set title", "Title:", QLineEdit::Normal,
                              this->windowTitle(), &ok);

    if (ok && !text.isEmpty()) {
      this->setWindowTitle(text);
    };
  });
  addButton("Line", "Run a Line", [this]() { emit runLine(this); });

  h->addStretch();
  v->addItem(h);
  v->addWidget(terminal);
}

TermWidgetTool::~TermWidgetTool() { delete terminal; }

void TermWidgetTool::addButton(const QString &title, const QString &tooltip,
                               const QString &command) {
  auto button = new QToolButton(this);
  button->setText(title);
  button->setToolTip(tooltip);
  connect(button, &QToolButton::clicked,
          [this, command]() { terminal->execute(command); });
  h->addWidget(button);
}

void TermWidgetTool::addButton(const QString &title, const QString &tooltip,
                               std::function<void()> run) {
  auto button = new QToolButton(this);
  button->setText(title);
  button->setToolTip(tooltip);
  connect(button, &QToolButton::clicked, run);
  h->addWidget(button);
}
