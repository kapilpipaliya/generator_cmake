// Scripter is not on the same level as the wheel invention, but for me it is a
// useful tool. but most rocket scientists are on this subject some "a useful
// tool is a valuable thing". °)

#include "./scripter.h"
#include <QApplication>
#include <QDir>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QTextStream>
#include <QVBoxLayout>
#include <QtDebug>
#include "./editor/mainwindow.h"

#include <QtWidgets>

// --- BEG User config
// ----------------------------------------------------------------------------------------

int WW = 250;  // Windows width
int HB = 38;   // Height of the buttons (29 – 42)
int BH = 0;    // Start value for determining the window height.

QString sudo = "gksu";  // SUDO GUI

// DOOMSDAY PROPHECY
QString CA = "Scripter Alert";
QString CB =
    "ERROR<br>Scripter [1] [2] [3]<br>[1] 0 default Theme / 1 "
    "QDarkStyleSheet<br>[2] The path to Scripter folder.<br>[3] The path to SH "
    "script folder.<br><br>Example:<br>Scripter 0 ~/Scripter/ "
    "~/SH-Folder/<br><br>With QDarkStyleSheet (install it) & use:<br>Scripter "
    "1 ~/Scripter/ ~/SH-Folder/";

// You can use a dark Theme in Qt with QDarkStylesheet
// https://github.com/ColinDuquesnoy/QDarkStyleSheet
int QD;  // 0 = default Theme || 1 = dark Theme QDarkStylesheet
// QDarkStylesheet Message
QString CC =
    "Could not find QDarkStylesheet,\nis it installed?\n\nGet QDarkStylesheet "
    "now, Download it from GitHub https://goo.gl/hAkJo5";

// --- END User config
// ----------------------------------------------------------------------------------------

// --- For a comfortable and easy work the following lines should not be
// changed.
// --- So you decided to continue reading and fiddling with the code – welcome
// to the Danger Zone °)

QString HP, DT,
    SR;  // The absolute path of Scripter & Script folder must be specified.
QString SH = "read";  // SH path
QString TP = QDir::tempPath();
namespace widgets {
QYN::QYN(QWidget *parent) : QPushButton(parent) {}

// Panic message generator
void Scripter::alert(QString a, QString b) {
  QMessageBox::StandardButton reply;
  reply = QMessageBox::warning(this, a, b, QMessageBox::Ok);

  if (reply == QMessageBox::Ok) {
    TMPkiller();
    exit(0);
  }
}

// Run the SH fun
void Scripter::startSHnowSUDO() {
  QYN *SG = qobject_cast<QYN *>(sender());
  QString buttonText = SG->text();

  QFile CS(SH + SR + ".sh");
  SR = buttonText.remove(0, 1);

  if (!CS.exists()) {
    SH = SH + "/";
  }
  system(qPrintable(sudo + " " + "sh '" + SH + SR + ".shs'"));
}

void Scripter::startSHnow() {
  QYN *SG = qobject_cast<QYN *>(sender());
  QString buttonText = SG->text();

  QFile CS(SH + SR + ".sh");
  SR = buttonText.remove(0, 1);

  if (!CS.exists()) {
    SH = SH + "/";
  }
  system(qPrintable("sh '" + SH + SR + ".sh'"));
}

// The backbone
Scripter::Scripter(QWidget *parent) : QWidget(parent) {
  // BEG double Scripter check and close
  QString A;
  if (QFileInfo("/tmp/Scripter-Task").exists()) {
    QFile fileA("/tmp/Scripter-Task");
    if (fileA.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QTextStream inA(&fileA);
      QString lineA = inA.readLine();
      while (!lineA.isNull()) {
        A = lineA;
        lineA = inA.readLine();
      }
      if (A == "1") {
        // send::USER::settings
      } else {
        TMPkiller();
        system(qPrintable("killall Scripter"));
      }
    }
  }
  // END

  // Load Scripter Path
  if (QFileInfo("/tmp/Scripter-Path").exists()) {
    QFile fileA("/tmp/Scripter-Path");
    if (!fileA.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream inA(&fileA);
    QString lineA = inA.readLine();
    while (!lineA.isNull()) {
      HP = lineA;
      lineA = inA.readLine();
    }
  }
  // Load SH Path
  if (QFileInfo("/tmp/Scripter-SH-Path").exists()) {
    QFile fileA("/tmp/Scripter-SH-Path");
    if (!fileA.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream inA(&fileA);
    QString lineA = inA.readLine();
    while (!lineA.isNull()) {
      SH = lineA;
      lineA = inA.readLine();
    }
  }

  // BEG QDarkStylesheet
  if (QFileInfo("/tmp/Scripter-Theme").exists()) {
    QFile fileA("/tmp/Scripter-Theme");
    if (!fileA.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream inA(&fileA);
    QString lineA = inA.readLine();
    while (!lineA.isNull()) {
      DT = lineA;
      if (DT == "0") {
        QD = 0;
      }
      if (DT == "1") {
        QD = 1;
      }
      lineA = inA.readLine();
    }
  }
  if (QD == 1) {
    QFile style(HP + "qdarkstyle/style.qss");
    if (!style.exists()) {
      alert(CA, CC);
    } else {
      style.open(QFile::ReadOnly | QFile::Text);
      QTextStream ts(&style);
      qApp->setStyleSheet(ts.readAll());
    }
  }
  // END QDarkStylesheet

  QIcon icon(HP + "icon.png");
  setWindowIcon(icon);
  initUi();

  if (!QDir(SH).exists() || !QDir(HP).exists()) {
    alert(CA, CB);
  } else {
    system(qPrintable(
        "find " + SH +
        " -name '*.sh*' -printf ' %p\n' | sort > /tmp/Scripter-List"));
    // system(qPrintable("find " + SH + " -name '*.shs' -printf ' %p\n' | sort
    // >> /tmp/Scripter-List"));
  }

  QFile file("/tmp/Scripter-List");
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
  QTextStream in(&file);
  QString line = in.readLine();

  // with SUDO CHECK
  // *.sh  = normal start
  // *.shs = start Script with GKSUDO

  while (!line.isNull()) {
    BH++;
    if (line.contains(".shs")) {
      addButton(line, true);
    }
    if (line.contains(".sh")) {
      addButton(line, false);
    }
    line = in.readLine();
  }
  // QWidget::setFixedWidth(WW);
  addNewButton();
}

// Clears the SH list to avoid future errors.
void Scripter::LittleKiller(QString a) {
  if (QFileInfo(a).exists()) {
    system(qPrintable("rm " + a));
  }
}

void Scripter::initUi() {
  /*
auto mainLayout = new QVBoxLayout(this);
// auto scroll = new QScrollArea();
//  scroll->setWidgetResizable(false);
auto verticalLayout = new QVBoxLayout();
verticalLayout->setObjectName("verticalLayout");
// scroll->setLayout(verticalLayout);
// mainLayout->addWidget(scroll);
mainLayout->addItem(verticalLayout);
this->setLayout(mainLayout);
*/

  auto gridLayout_1 = new QGridLayout();
  gridLayout_1->setObjectName(QString::fromUtf8("gridLayout_1"));
  auto verticalLayout = new QVBoxLayout();
  verticalLayout->setObjectName("verticalLayout");

  gridLayout_1->addLayout(verticalLayout, 0, 0, 1, 1);
  this->setLayout(gridLayout_1);
  // this->setCentralWidget(centralWidget);
  addNewButton();
}
void Scripter::addNewButton() {
  QVBoxLayout *verticalLayout =
      this->findChild<QVBoxLayout *>("verticalLayout");
  auto addToolButton = new QPushButton();
  addToolButton->setText("Add");
  verticalLayout->addWidget(addToolButton);
  connect(addToolButton, &QPushButton::clicked,
          [this]() { addButton("", false); });
}
void Scripter::addButton(QString line, bool isSudo) {
  QYN *button = new QYN(this);
  auto file_name = line;
  line.replace(".shs", "");
  line.replace(".sh", "");
  line.replace(SH + "/", "");
  line.replace(SH, "");
  button->setText(line);
  QWidget *topWidget = new QWidget();
  auto hLayout = new QHBoxLayout();
  auto editor = new widgets::scripter::EditorMainWindow();
  editor->loadFile(file_name.trimmed());
  editor->setWindowFlags(Qt::Widget);
  editor->show();
  hLayout->addWidget(button);
  hLayout->addWidget(editor);
  //  topWidget->setFixedHeight(300);
  QVBoxLayout *verticalLayout =
      this->findChild<QVBoxLayout *>("verticalLayout");
  topWidget->setLayout(hLayout);
  verticalLayout->addWidget(topWidget);
  // 1 & 2 buttons height adjustment
  //  QWidget::setFixedHeight(BH*HB);
  if (BH < 2) {
    BH = BH + 1;
  }
  if (isSudo) {
    connect(button, SIGNAL(clicked()), this, SLOT(startSHnowSUDO()));
  }
  connect(button, SIGNAL(clicked()), this, SLOT(startSHnow()));
  connect(editor, &widgets::scripter::EditorMainWindow::currFileChanged,
          [button](QString s) {
            s.replace(".shs", "");
            s.replace(".sh", "");
            s.replace(SH + "/", "");
            s.replace(SH, "");
            s.prepend(" ");
            button->setText(s);
          });
}

void Scripter::TMPkiller() {
  LittleKiller("/tmp/Scripter-Theme");
  LittleKiller("/tmp/Scripter-Path");
  LittleKiller("/tmp/Scripter-SH-Path");
  LittleKiller("/tmp/Scripter-List");
  LittleKiller("/tmp/Scripter-Task");
}

Scripter::~Scripter() { TMPkiller(); }
}  // namespace widgets
