#include "./reactgenerator.h"
#include "pystring/pystring.hpp"
#include <QSizePolicy>
namespace widgets
{
ReactGenerator::ReactGenerator(QWidget *parent) : QWidget(parent)
{
  this->setAttribute(Qt::WA_DeleteOnClose);
  init();
}
ReactGenerator::~ReactGenerator() {}
void ReactGenerator::init()
{
  auto v1 = new QVBoxLayout(this);
  auto v1_h4 = new QHBoxLayout();
  importgenerator(v1_h4);
  auto v1_h2 = new QHBoxLayout();
  componentSkeletonGenerator(v1_h2);
  auto v1_h1 = new QHBoxLayout();
  hookGenerator(v1_h1);
  auto v1_h3 = new QHBoxLayout();
  eventListenerGenerator(v1_h3);
  auto v1_h5 = new QHBoxLayout();
  protobufgenerator(v1_h5);
  v1->addItem(v1_h4);
  v1->addItem(v1_h2);
  v1->addItem(v1_h1);
  v1->addItem(v1_h3);
  auto verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
  v1->addItem(verticalSpacer);
  this->setLayout(v1);
}
void ReactGenerator::hookGenerator(QHBoxLayout *hbox)
{
  auto g = new QGroupBox(this);
  g->setTitle("Hook Generator:");
  auto h = new QHBoxLayout(g);
  auto typeLabel = new QLabel(this);
  auto hookSelect = new QComboBox(this);
  hookSelect->addItem("useState");
  hookSelect->addItem("useRef");
  hookSelect->addItem("useCallback");
  hookSelect->addItem("useEffect");
  auto nameLabel = new QLabel(this);
  nameLabel->setText("variable name:");
  auto stateName = new QLineEdit(this);
  stateName->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
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
  h->addWidget(hookSelect);
  h->addWidget(nameLabel);
  h->addWidget(stateName);
  h->addWidget(exportasLabel);
  h->addWidget(exporttval);
  h->addWidget(defaultvalLabel);
  h->addWidget(defaultval);
  h->addWidget(checkbox);
  h->addWidget(resultLabel);
  h->addWidget(resultText);
  auto generate = [hookSelect, stateName, exporttval, defaultval, checkbox, resultText]() {
    auto nameText = stateName->text().trimmed();
    if (!nameText.isEmpty()) { nameText.replace(' ', '_'); }
    QString r;
    if (hookSelect->currentText() == "useState")
    {
      r += "const [" + nameText + ", set" + QString::fromStdString(pystring::capitalize(nameText.toStdString())) + "] = " + hookSelect->currentText() + "(";
      if (!defaultval->toPlainText().isEmpty()) { r += defaultval->toPlainText(); }
      r += ");";
    }
    else if (hookSelect->currentText() == "useRef")
    {
      r += "const " + nameText + " = " + hookSelect->currentText() + "(";
      if (!defaultval->toPlainText().isEmpty()) { r += defaultval->toPlainText(); }
      r += ");";
    }
    else if (hookSelect->currentText() == "useCallback")
    {
      r += "const " + nameText + " = " + hookSelect->currentText() + "(";
      if (!defaultval->toPlainText().isEmpty()) { r += defaultval->toPlainText(); }
      r += ");";
    }
    else if (hookSelect->currentText() == "useEffect")
    {
      r += hookSelect->currentText() + "(";
      if (!defaultval->toPlainText().isEmpty()) { r += defaultval->toPlainText(); }
      r += ");";
    }
    resultText->setText(r);
  };
  connect(hookSelect, &QComboBox::currentTextChanged, generate);
  connect(stateName, &QLineEdit::textEdited, generate);
  connect(exporttval, &QLineEdit::textEdited, generate);
  connect(defaultval, &QPlainTextEdit::textChanged, generate);
  connect(checkbox, &QCheckBox::clicked, generate);
  connect(checkbox, &QCheckBox::clicked, [defaultval, checkbox]() {
    if (!defaultval->toPlainText().isEmpty()) { checkbox->setChecked(true); }
  });
  connect(defaultval, &QPlainTextEdit::textChanged, [defaultval, checkbox]() {
    if (!defaultval->toPlainText().isEmpty()) { checkbox->setChecked(true); }
  });
  hbox->addWidget(g);
}
void ReactGenerator::componentSkeletonGenerator(QHBoxLayout *hbox)
{
  auto g = new QGroupBox(this);
  g->setTitle("component Skeleton Generator:");
  auto h = new QHBoxLayout(g);
  auto nameLabel = new QLabel(this);
  nameLabel->setText("component name:");
  auto componentName = new QLineEdit(this);
  componentName->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  auto simplevalueLabel = new QLabel(this);
  simplevalueLabel->setText("Simple Value:");
  auto propInterfaceValue = new QLineEdit(this);
  propInterfaceValue->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  propInterfaceValue->setToolTip("PropInterface");
  auto functionvalueLabel = new QLabel(this);
  functionvalueLabel->setText("OR  Function Value:");
  auto functionvalue = new QPlainTextEdit(this);
  auto resultLabel = new QLabel(this);
  resultLabel->setText("result:");
  auto resultText = new QTextEdit(this);
  h->addWidget(nameLabel);
  h->addWidget(componentName);
  h->addWidget(simplevalueLabel);
  h->addWidget(propInterfaceValue);
  h->addWidget(functionvalueLabel);
  h->addWidget(functionvalue);
  h->addWidget(resultLabel);
  h->addWidget(resultText);
  connect(componentName, &QLineEdit::textEdited, propInterfaceValue, &QLineEdit::setText);
  auto generate = [componentName, propInterfaceValue, functionvalue, resultText]() {
    auto nameText = componentName->text().trimmed();
    if (!nameText.isEmpty()) { nameText.replace(' ', '_'); }
    QString r;
    if (!propInterfaceValue->text().isEmpty())
    {
      r += R"(interface )";
      r += propInterfaceValue->text();
      r += R"(Props {

}\n)";
    }
    r += "const ";
    r += nameText + " = (props";
    if (!propInterfaceValue->text().isEmpty()) { r += ": " + propInterfaceValue->text() + "Props)"; }
    else
    {
      r += ")";
    }
    r += " => {\n";
    r += functionvalue->toPlainText();
    r += "\n}";
    resultText->setText(r);
  };
  connect(componentName, &QLineEdit::textEdited, generate);
  connect(propInterfaceValue, &QLineEdit::textEdited, generate);
  connect(functionvalue, &QPlainTextEdit::textChanged, generate);
  hbox->addWidget(g);
}
void ReactGenerator::eventListenerGenerator(QHBoxLayout *hbox)
{
  auto g = new QGroupBox(this);
  g->setTitle("Event Listners:");
  auto h = new QHBoxLayout(g);
  auto directiveLabel = new QLabel(this);
  auto directiveselect = new QComboBox(this);
  directiveselect->addItem("on");
  auto eventnameLabel = new QLabel(this);
  eventnameLabel->setText("name:");
  auto eventname = new QLineEdit(this);
  eventname->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  auto modifiersLabel = new QLabel(this);
  modifiersLabel->setText("Modifiers");
  auto modifiersselect = new QListWidget(this);
  // http://qt.shoutwiki.com/wiki/How_to_filter_QListView
  modifiersselect->setSelectionMode(QAbstractItemView::SingleSelection);
  modifiersselect->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
  modifiersselect->addItem("");
  modifiersselect->addItem("Change");
  modifiersselect->addItem("Click");
  modifiersselect->addItem("Focus");
  modifiersselect->addItem("Blue");
  modifiersselect->addItem("Input");
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
  connect(modifiersselect, &QListWidget::currentTextChanged, eventname, &QLineEdit::setText);
  auto generate = [directiveselect, eventname, handlertval, resultText]() {
    QString r = directiveselect->currentText();
    auto nameText = QString::fromStdString(pystring::capitalize(eventname->text().trimmed().toStdString()));
    if (!nameText.isEmpty()) { nameText.replace(' ', '_'); }
    r += nameText;
    if (!handlertval->toPlainText().isEmpty()) { r += "={" + handlertval->toPlainText() + "}"; }
    resultText->setText(r);
  };
  connect(directiveselect, QOverload<int>::of(&QComboBox::currentIndexChanged), [directiveselect, modifiersLabel, eventnameLabel, eventname, modifiersselect, handlerLabel]() {
    if (directiveselect->currentIndex() != 0)
    {
      modifiersselect->clearSelection();
      modifiersLabel->hide();
      modifiersselect->hide();
    }
    else
    {
      modifiersLabel->show();
      modifiersselect->show();
    }
    if (directiveselect->currentText() == "bind:group" || directiveselect->currentText() == "bind:this")
    {
      eventnameLabel->hide();
      eventname->setText("");
      eventname->hide();
    }
    else
    {
      eventnameLabel->show();
      eventname->show();
    }
    if (directiveselect->currentText() == "on:")
    {
      eventnameLabel->setText("Event:");
      handlerLabel->setText("Handler:");
    }
    else if (directiveselect->currentText() == "bind:")
    {
      eventnameLabel->setText("Property:");
      handlerLabel->setText("Variable:");
    }
    else if (directiveselect->currentText() == "bind:group")
    {
      eventnameLabel->setText("Property:");
      handlerLabel->setText("Variable:");
    }
    else if (directiveselect->currentText() == "bind:this")
    {
      eventnameLabel->setText("Property:");
      handlerLabel->setText("Variable:");
    }
    else if (directiveselect->currentText() == "class:")
    {
      eventnameLabel->setText("Property:");
      handlerLabel->setText("Variable:");
    }
    else if (directiveselect->currentText() == "use:")
    {
      eventnameLabel->setText("action:");
      handlerLabel->setText("parameters:");
    }
    else if (directiveselect->currentText() == "transition:")
    {
      eventnameLabel->setText("fn:");
      handlerLabel->setText("params:");
    }
    else if (directiveselect->currentText() == "in:")
    {
      eventnameLabel->setText("fn:");
      handlerLabel->setText("params:");
    }
    else if (directiveselect->currentText() == "out:")
    {
      eventnameLabel->setText("fn:");
      handlerLabel->setText("params:");
    }
    else if (directiveselect->currentText() == "animate:")
    {
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
void ReactGenerator::importgenerator(QHBoxLayout *hbox)
{
  auto g = new QGroupBox(this);
  g->setTitle("Import generate");
  auto h = new QHBoxLayout(g);
  auto moduleLabel = new QLabel(this);
  auto moduleselect = new QComboBox(this);
  moduleselect->addItem("react");
  moduleselect->addItem("create-subscription");
  moduleselect->addItem("react-art");
  moduleselect->addItem("react-dom");
  moduleselect->addItem("react-is");
  moduleselect->addItem("use-subscription");
  auto importLabel = new QLabel(this);
  importLabel->setText("import:");
  auto importselect = new QListWidget(this);
  importselect->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  importselect->setSelectionMode(QAbstractItemView::MultiSelection);
  importselect->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
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
    if (sel == "react")
    {
      importselect->addItems({"Children",
                              "createRef",
                              "Component",
                              //"PureComponent",
                              "createContext",
                              "forwardRef",
                              "lazy",
                              "memo",
                              "useCallback",
                              "useContext",
                              "useEffect",
                              "useImperativeHandle",
                              "useDebugValue",
                              "useLayoutEffect",
                              "useMemo",
                              "useReducer",
                              "useRef",
                              "useState",
                              "useMutableSource",
                              "createMutableSource",
                              "Fragment",
                              "Profiler",
                              "unstable_DebugTracingMode",
                              "StrictMode",
                              "Suspense",
                              "createElement",
                              "cloneElement",
                              "isValidElement",
                              "version"});
    }
    if (sel == "create-subscription") { importselect->addItems({"createSubscription"}); }
    if (sel == "react-art") { importselect->addItems({"ClippingRectangle", "Group", "Shape", "Path", "LinearGradient", "Pattern", "RadialGradient", "Surface", "Text", "Transform"}); }
    if (sel == "react-dom")
    {
      importselect->addItems({
          "createPortal",
          "unstable_batchedUpdates",
          "flushSync",
          "version",
          "findDOMNode",
          "hydrate",
          "render",
          "unmountComponentAtNode",
          "createRoot",
          "unstable_flushControlled",
          "unstable_scheduleHydration",
          "unstable_runWithPriority",
          "unstable_renderSubtreeIntoContainer",
          "unstable_createPortal",
          "unstable_createEventHandle",
          "unstable_isNewReconciler",
      });
    }
    if (sel == "react-is")
    {
      importselect->addItems({
          "typeOf",
          "ContextConsumer",
          "ContextProvider",
          "Element",
          "ForwardRef",
          "Fragment",
          "Lazy",
          "Memo",
          "Portal",
          "Profiler",
          "StrictMode",
          "Suspense",
          "unstable_SuspenseList",
          "isValidElementType",
          "isConcurrentMode",
          "isContextConsumer",
          "isContextProvider",
          "isElement",
          "isForwardRef",
          "isFragment",
          "isLazy",
          "isMemo",
          "isPortal",
          "isProfiler",
          "isStrictMode",
          "isSuspense",
          "unstable_isSuspenseList",
      });
    }
    if (sel == "use-subscription") { importselect->addItems({"useSubscription"}); }
  };
  onmoduleselect();
  auto generate = [moduleselect, importselect, resultText]() {
    auto nameText = moduleselect->currentText().trimmed();
    if (!nameText.isEmpty())
    {
      if (nameText.front() == '$') { nameText.remove(0, 1); }
      nameText.replace(' ', '_');
    }
    QString r;
    std::vector<std::string> v;
    for (auto &item : importselect->selectedItems()) { v.push_back(item->text().toStdString()); }
    auto j = pystring::join(", ", v);
    if (!j.empty())
    {
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
void ReactGenerator::protobufgenerator(QHBoxLayout *hbox) {}
}  // namespace widgets
