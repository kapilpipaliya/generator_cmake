#include "./sveltegenerator.h"

#include "thirdparty/pystring/pystring.h"
namespace widgets {

SvelteGenerator::SvelteGenerator(QWidget *parent) : QWidget(parent) {
  this->setAttribute(Qt::WA_DeleteOnClose);
  init();
}

SvelteGenerator::~SvelteGenerator() {}

void SvelteGenerator::init() {
  auto v1 = new QVBoxLayout(this);

  auto v1_h1 = new QHBoxLayout();
  exportgenerator(v1_h1);
  auto v1_h2 = new QHBoxLayout();
  reactivestatgenerator(v1_h2);
  auto v1_h3 = new QHBoxLayout();
  elementdirectivesgenerator(v1_h3);
  auto v1_h4 = new QHBoxLayout();
  importgenerator(v1_h4);
  auto v1_h5 = new QHBoxLayout();
  protobufgenerator(v1_h5);

  v1->addItem(v1_h1);
  v1->addItem(v1_h2);
  v1->addItem(v1_h3);
  v1->addItem(v1_h4);
  auto verticalSpacer =
      new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
  v1->addItem(verticalSpacer);
  this->setLayout(v1);
}

void SvelteGenerator::exportgenerator(QHBoxLayout *hbox) {
  auto g = new QGroupBox(this);
  g->setTitle("create component prop");
  auto h = new QHBoxLayout(g);

  auto typeLabel = new QLabel(this);
  auto typeselect = new QComboBox(this);
  typeselect->addItem("let");
  typeselect->addItem("const");
  typeselect->addItem("class");
  typeselect->addItem("function");
  auto nameLabel = new QLabel(this);
  nameLabel->setText("variable name:");
  auto name = new QLineEdit(this);
  auto exportasLabel = new QLabel(this);
  exportasLabel->setText("export:");
  auto exporttval = new QLineEdit(this);
  auto defaultvalLabel = new QLabel(this);
  defaultvalLabel->setText("Default:");
  auto defaultval = new QPlainTextEdit(this);

  auto resultLabel = new QLabel(this);
  resultLabel->setText("result:");
  auto resultText = new QTextEdit(this);

  auto checkbox = new QCheckBox(this);
  checkbox->setText("optional");

  h->addWidget(typeLabel);
  h->addWidget(typeselect);
  h->addWidget(nameLabel);
  h->addWidget(name);
  h->addWidget(exportasLabel);
  h->addWidget(exporttval);
  h->addWidget(defaultvalLabel);
  h->addWidget(defaultval);
  h->addWidget(checkbox);
  h->addWidget(resultLabel);
  h->addWidget(resultText);

  auto generate = [typeselect, name, exporttval, defaultval, checkbox,
                   resultText]() {
    auto nameText = name->text().trimmed();
    if (!nameText.isEmpty()) {
      if (nameText.front() == '$') {
        nameText.remove(0, 1);
      }
      nameText.replace(' ', '_');
    }
    if (exporttval->text().isEmpty()) {
      QString r;
      r += "export " + typeselect->currentText() + " " + nameText;
      if (!defaultval->toPlainText().isEmpty()) {
        r += " = " + defaultval->toPlainText() + ";";
      } else {
        if (checkbox->isChecked()) {
          r += " = undefined;";
        } else {
          r += ";";
        }
      }
      resultText->setText(r);
    } else {
      QString r;

      r += typeselect->currentText() + " " + nameText + ";\n";
      r += "export { " + nameText + " as " + exporttval->text() + " };";
      resultText->setText(r);
    }
  };
  connect(typeselect, &QComboBox::currentTextChanged, generate);
  connect(name, &QLineEdit::textEdited, generate);
  connect(exporttval, &QLineEdit::textEdited, generate);
  connect(defaultval, &QPlainTextEdit::textChanged, generate);
  connect(checkbox, &QCheckBox::clicked, generate);
  connect(checkbox, &QCheckBox::clicked, [defaultval, checkbox]() {
    if (!defaultval->toPlainText().isEmpty()) {
      checkbox->setChecked(true);
    }
  });
  connect(defaultval, &QPlainTextEdit::textChanged, [defaultval, checkbox]() {
    if (!defaultval->toPlainText().isEmpty()) {
      checkbox->setChecked(true);
    }
  });
  hbox->addWidget(g);
}

void SvelteGenerator::reactivestatgenerator(QHBoxLayout *hbox) {
  auto g = new QGroupBox(this);
  g->setTitle("$: marks a statement as reactive");
  auto h = new QHBoxLayout(g);

  auto nameLabel = new QLabel(this);
  nameLabel->setText("variable name:");
  auto name = new QLineEdit(this);

  auto simplevalueLabel = new QLabel(this);
  simplevalueLabel->setText("Simple Value:");
  auto simplevalue = new QLineEdit(this);
  simplevalue->setToolTip(
      "If a statement consists entirely of an assignment to an undeclared "
      "variable, Svelte will inject a let declaration on your behalf.");
  auto functionvalueLabel = new QLabel(this);
  functionvalueLabel->setText("OR  Function Value:");
  auto functionvalue = new QPlainTextEdit(this);

  auto resultLabel = new QLabel(this);
  resultLabel->setText("result:");
  auto resultText = new QTextEdit(this);

  h->addWidget(nameLabel);
  h->addWidget(name);
  h->addWidget(simplevalueLabel);
  h->addWidget(simplevalue);
  h->addWidget(functionvalueLabel);
  h->addWidget(functionvalue);
  h->addWidget(resultLabel);
  h->addWidget(resultText);

  auto generate = [name, simplevalue, functionvalue, resultText]() {
    auto nameText = name->text().trimmed();
    if (!nameText.isEmpty()) {
      if (nameText.front() == '$') {
        nameText.remove(0, 1);
      }
      nameText.replace(' ', '_');
    }
    QString r;
    r += "$: ";
    if (!simplevalue->text().isEmpty()) {
      r += nameText + " = " + simplevalue->text() + ";";
    } else {
      r += "{\n" + functionvalue->toPlainText() + "\n}";
    }
    resultText->setText(r);
  };
  connect(name, &QLineEdit::textEdited, generate);
  connect(simplevalue, &QLineEdit::textEdited, generate);
  connect(functionvalue, &QPlainTextEdit::textChanged, generate);
  hbox->addWidget(g);
}

void SvelteGenerator::elementdirectivesgenerator(QHBoxLayout *hbox) {
  auto g = new QGroupBox(this);
  g->setTitle("Element directives");
  auto h = new QHBoxLayout(g);

  auto directiveLabel = new QLabel(this);
  auto directiveselect = new QComboBox(this);
  directiveselect->addItem("on:");
  directiveselect->addItem("bind:");
  // directiveselect->addItem("bind:innerHTML");
  // directiveselect->addItem("bind:contenteditable");
  // bind:duration
  // bind:buffered
  // bind:seekable
  // bind:played
  // bind:currentTime
  // bind:paused
  // bind:volume
  // clientWidth
  // clientHeight
  // offsetWidth
  // offsetHeight
  // introstart
  // introend
  // outrostart
  // outroend
  directiveselect->addItem("bind:group");
  directiveselect->addItem("bind:this");
  directiveselect->addItem("class:");
  directiveselect->addItem("use:");
  directiveselect->addItem("transition:");
  directiveselect->addItem("in:");
  directiveselect->addItem("out:");
  directiveselect->addItem("animate:");
  auto eventnameLabel = new QLabel(this);
  eventnameLabel->setText("name:");
  auto eventname = new QLineEdit(this);
  auto modifiersLabel = new QLabel(this);
  modifiersLabel->setText("Modifiers");
  auto modifiersselect = new QListWidget(this);
  modifiersselect->setSelectionMode(QAbstractItemView::MultiSelection);
  modifiersselect->addItem("");
  modifiersselect->addItem("preventDefault");
  modifiersselect->addItem("stopPropagation");
  modifiersselect->addItem("passive");
  modifiersselect->addItem("capture");
  modifiersselect->addItem("once");
  auto handlerLabel = new QLabel(this);
  handlerLabel->setText("Handler:");
  auto handlertval = new QPlainTextEdit(this);

  auto resultLabel = new QLabel(this);
  resultLabel->setText("result:");
  auto resultText = new QTextEdit(this);

  h->addWidget(directiveLabel);
  h->addWidget(directiveselect);
  h->addWidget(eventnameLabel);
  h->addWidget(eventname);
  h->addWidget(modifiersLabel);
  h->addWidget(modifiersselect);
  h->addWidget(handlerLabel);
  h->addWidget(handlertval);
  h->addWidget(resultLabel);
  h->addWidget(resultText);

  auto generate = [directiveselect, eventname, modifiersselect, handlertval,
                   resultText]() {
    // on:eventname={handler}
    // on:eventname|modifiers={handler}

    auto nameText = eventname->text().trimmed();
    if (!nameText.isEmpty()) {
      if (nameText.front() == '$') {
        nameText.remove(0, 1);
      }
      nameText.replace(' ', '_');
    }
    auto handleText = handlertval->toPlainText();
    bool isSame = nameText == handleText;

    QString r = directiveselect->currentText();
    r += nameText;
    std::vector<std::string> v;
    for (auto &item : modifiersselect->selectedItems()) {
      v.push_back(item->text().toStdString());
    }
    auto j = pystring::join("|", v);
    if (!j.empty()) {
      r += "|";
    }
    r += QString::fromStdString(j);
    if (!handlertval->toPlainText().isEmpty()) {
      if (!isSame || directiveselect->currentText() == "on:") {
        r += "='{" + handlertval->toPlainText() + "}'";
      }
    }
    resultText->setText(r);
  };
  connect(directiveselect, QOverload<int>::of(&QComboBox::currentIndexChanged),
          [directiveselect, modifiersLabel, eventnameLabel, eventname,
           modifiersselect, handlerLabel]() {
            if (directiveselect->currentIndex() != 0) {
              modifiersselect->clearSelection();
              modifiersLabel->hide();
              modifiersselect->hide();
            } else {
              modifiersLabel->show();
              modifiersselect->show();
            }
            if (directiveselect->currentText() == "bind:group" ||
                directiveselect->currentText() == "bind:this") {
              eventnameLabel->hide();
              eventname->setText("");
              eventname->hide();
            } else {
              eventnameLabel->show();
              eventname->show();
            }
            if (directiveselect->currentText() == "on:") {
              eventnameLabel->setText("Event:");
              handlerLabel->setText("Handler:");
            } else if (directiveselect->currentText() == "bind:") {
              eventnameLabel->setText("Property:");
              handlerLabel->setText("Variable:");
            } else if (directiveselect->currentText() == "bind:group") {
              eventnameLabel->setText("Property:");
              handlerLabel->setText("Variable:");
            } else if (directiveselect->currentText() == "bind:this") {
              eventnameLabel->setText("Property:");
              handlerLabel->setText("Variable:");
            } else if (directiveselect->currentText() == "class:") {
              eventnameLabel->setText("Property:");
              handlerLabel->setText("Variable:");
            } else if (directiveselect->currentText() == "use:") {
              eventnameLabel->setText("action:");
              handlerLabel->setText("parameters:");
            } else if (directiveselect->currentText() == "transition:") {
              eventnameLabel->setText("fn:");
              handlerLabel->setText("params:");
            } else if (directiveselect->currentText() == "in:") {
              eventnameLabel->setText("fn:");
              handlerLabel->setText("params:");
            } else if (directiveselect->currentText() == "out:") {
              eventnameLabel->setText("fn:");
              handlerLabel->setText("params:");
            } else if (directiveselect->currentText() == "animate:") {
              eventnameLabel->setText("fn:");
              handlerLabel->setText("params:");
            }
          });
  connect(directiveselect, &QComboBox::currentTextChanged, generate);
  connect(modifiersselect, &QListWidget::itemSelectionChanged, generate);
  connect(eventname, &QLineEdit::textEdited, generate);
  connect(handlertval, &QPlainTextEdit::textChanged, generate);
  hbox->addWidget(g);
}

void SvelteGenerator::importgenerator(QHBoxLayout *hbox) {
  auto g = new QGroupBox(this);
  g->setTitle("Import generate");
  auto h = new QHBoxLayout(g);

  auto moduleLabel = new QLabel(this);
  auto moduleselect = new QComboBox(this);
  moduleselect->addItem("svelte");
  moduleselect->addItem("@sapper/store");
  moduleselect->addItem("@sapper/app");
  moduleselect->addItem("@sapper/animate");
  moduleselect->addItem("@sapper/motion");
  moduleselect->addItem("@sapper/transition");
  moduleselect->addItem("@sapper/easing");
  auto importLabel = new QLabel(this);
  importLabel->setText("import:");
  auto importselect = new QListWidget(this);
  importselect->setSelectionMode(QAbstractItemView::MultiSelection);

  auto resultLabel = new QLabel(this);
  resultLabel->setText("result:");
  auto resultText = new QTextEdit(this);

  h->addWidget(moduleLabel);
  h->addWidget(moduleselect);
  h->addWidget(importLabel);
  h->addWidget(importselect);
  h->addWidget(resultLabel);
  h->addWidget(resultText);
  auto onmoduleselect = [importselect, moduleselect]() {
    auto sel = moduleselect->currentText();
    importselect->clear();
    if (sel == "svelte") {
      importselect->addItems({"afterUpdate", "beforeUpdate",
                              "createEventDispatcher", "getContext",
                              "onDestroy", "onMount", "setContext", "tick"});
    }
    if (sel == "@sapper/store") {
      importselect->addItems({"writable", "readable", "derived", "get"});
    }
    if (sel == "@sapper/app") {
      importselect->addItems(
          {"goto", "prefetch", "prefetchRoutes", "start", "stores"});
    }
    if (sel == "@sapper/animate") {
      importselect->addItems({"flip"});
    }
    if (sel == "@sapper/motion") {
      importselect->addItems({"spring", "tweened"});
    }
    if (sel == "@sapper/transition") {
      importselect->addItems({"fade", "blur", "fly", "slide", "scale", "draw"});
    }
    if (sel == "@sapper/easing") {
      importselect->addItems({"back", "bounce", "circ", "cubic", "elastic",
                              "expo", "quad", "quart", "quint", "sine"});
    }
  };
  onmoduleselect();

  auto generate = [moduleselect, importselect, resultText]() {
    auto nameText = moduleselect->currentText().trimmed();
    if (!nameText.isEmpty()) {
      if (nameText.front() == '$') {
        nameText.remove(0, 1);
      }
      nameText.replace(' ', '_');
    }
    QString r;
    std::vector<std::string> v;
    for (auto &item : importselect->selectedItems()) {
      v.push_back(item->text().toStdString());
    }
    auto j = pystring::join(", ", v);
    if (!j.empty()) {
      j.insert(0, " ");
      j.push_back(' ');
    }
    r += "import {" + QString::fromStdString(j) + "} from '" + nameText + "'";
    resultText->setText(r);
  };
  connect(moduleselect, &QComboBox::currentTextChanged, onmoduleselect);
  connect(importselect, &QListWidget::itemSelectionChanged, generate);
  hbox->addWidget(g);
}

void SvelteGenerator::protobufgenerator(QHBoxLayout *hbox) {}

}  // namespace widgets
