#include "./dgraphcodegenerator.h"
//#include <fmt/format.h>
#include <QtWidgets>
#include "pystring/pystring.hpp"
namespace widgets
{
DgraphCodeGenerator::DgraphCodeGenerator(QWidget *parent) : QWidget(parent)
{
  this->setAttribute(Qt::WA_DeleteOnClose);
  auto v1 = new QVBoxLayout(this);
  {
    auto g = new QGroupBox(this);
    g->setTitle("Schema Builder");
    auto h = new QHBoxLayout(g);
    auto v = new QVBoxLayout();
    // auto schemaLabel = new QLabel(this);
    auto schema = new QLineEdit(g);
    auto inputtext = new QPlainTextEdit(g);
    v->addWidget(schema);
    v->addWidget(inputtext);
    h->addItem(v);
    auto resultText = new QTextEdit(g);
    h->addWidget(resultText);
    h->setStretch(1, 2);
    v1->addWidget(g);
    auto generate = [schema, inputtext, resultText]() {
      auto t = inputtext->toPlainText();
      QString r;
      r = "auto dgraphorm = dgraph::DGraphClientManger::getDGraphOrm(\"1\");\n";
      r += "auto " + schema->text() + " = dgraphorm->model(dgraph::orm::Schema{\"" + schema->text() + "\", {\n";
      for (auto &l : t.split("\n"))
      {
        l.replace(" b ", ",FieldProps::builder{} ");
        l.replace(QRegExp(" n (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".name(\"\\1\") ");
        l.replace(QRegExp(" m (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".model(\"\\1\") ");
        l.replace(QRegExp(" 1 "), ".type(TypesType::INT) ");
        l.replace(QRegExp(" 2 "), ".type(TypesType::FLOAT) ");
        l.replace(QRegExp(" 3 "), ".type(TypesType::STRING) ");
        l.replace(QRegExp(" 4 "), ".type(TypesType::BOOL) ");
        l.replace(QRegExp(" 5 "), ".type(TypesType::DATETIME) ");
        l.replace(QRegExp(" 6 "), ".type(TypesType::GEO) ");
        l.replace(QRegExp(" 7 "), ".type(TypesType::PASSWORD) ");
        l.replace(QRegExp(" 8 "), ".type(TypesType::UID) ");
        l.replace(QRegExp(" li "), ".list(true) ");
        l.replace(QRegExp(" i "), ".index(true) ");
        l.replace(QRegExp(" l "), ".lang(true) ");
        l.replace(QRegExp(" c "), ".count(true) ");
        l.replace(QRegExp(" r "), ".reverse(true) ");
        l.replace(QRegExp(" u "), ".unique(true) ");
        l.replace(QRegExp(" t "), ".token(Token::builder{} ");
        l.replace(QRegExp(" tt "), ".term(true) ");
        l.replace(QRegExp(" ttr "), ".trigram(true) ");
        l.replace(QRegExp(" tf "), ".fulltext(true) ");
        l.replace(QRegExp(" te "), ".exact(true) ");
        l.replace(QRegExp(" th "), ".hash(true) ");
        l.replace(QRegExp(" b_"), ".build()");
        l.replace(QRegExp(" e_"), "}});");
        r += "\n";
        r += l;
      }
      resultText->setText(r);
    };
    connect(inputtext, &QPlainTextEdit::textChanged, generate);
    connect(schema, &QLineEdit::textChanged, generate);
  }
  {
    auto g = new QGroupBox(this);
    auto h = new QHBoxLayout(g);
    g->setTitle("method Builder:");
    auto grid = new QGridLayout();
    auto schemaLabel = new QLabel(g);
    schemaLabel->setText("schema");
    auto schema = new QLineEdit(g);
    auto methodLabel = new QLabel(g);
    methodLabel->setText("Method");
    auto methodselect = new QComboBox(g);
    methodselect->addItems(
        {"eq", "uid", "allofterms", "anyofterms", "regexp", "anyoftext", "alloftext", "has", "near", "within", "contains", "intersects", "uid_in", "ne", "le", "lt", "ge", "gt", "match", "type"});
    auto fieldlabel = new QLabel(g);
    auto fieldvalue = new QLineEdit(g);
    auto inputtext = new QPlainTextEdit(g);
    grid->addWidget(schemaLabel, 0, 0);
    grid->addWidget(schema, 0, 1);
    grid->addWidget(methodLabel, 1, 0);
    grid->addWidget(methodselect, 1, 1);
    grid->addWidget(fieldlabel, 2, 0);
    grid->addWidget(fieldvalue, 2, 1);
    grid->addWidget(inputtext, 3, 0, 1, 2);
    h->addItem(grid);
    auto resultText = new QTextEdit(g);
    h->addWidget(resultText);
    h->setStretch(1, 2);
    v1->addWidget(g);
    auto generate = [schema, methodselect, fieldvalue, inputtext, resultText]() {
      QString r;
      r += "auto dgraphorm = dgraph::DGraphClientManger::getDGraphOrm(\"1\");\n";
      r += "auto " + schema->text() + " = dgraphorm->newmodel(\"" + schema->text() + "\");\n";
      r += "auto result = new api::Response;\n";
      r += "auto status = " + schema->text() + "->method(dgraph::orm::MethodsType::" + methodselect->currentText() + ", " + fieldvalue->text() + ", \n\n";
      auto t = inputtext->toPlainText();
      r += "dgraph::orm::Params::builder{}";
      for (auto &l : t.split("\n"))
      {
        l.replace(" inc ", ".inc(dgraph::orm::IncludeBase::builder{} ");
        // QString t = "A <i>bon mot</i>.";
        l.replace(QRegExp(" n (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".name(\"\\1\") ");
        l.replace(QRegExp(" a (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".as(\"\\1\") ");
        l.replace(QRegExp(" c "), ".count(true) ");
        l.replace(QRegExp(" p "), ".params(dgraph::orm::Params::builder{} ");
        l.replace(QRegExp(" o "), ".order({{\"name\", \"value\"}, {\"name\", \"value\"}}) ");
        l.replace(QRegExp(" a "), ".attributes({\"uid\", \"name\", \"email\"}) ");
        l.replace(QRegExp(" f "), ".filter(dgraph::orm::Filter::builder{} ) ");
        l.replace(QRegExp(" m (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".model(\"\\1\") ");
        l.replace(QRegExp(" b_"), ".build()\n");
        l.replace(QRegExp(" i_"), ")\n");
        // t == "A \\emph{bon mot}."
        r += "\n";
        r += l;
      }
      r += ".build_shared(), result);\n";
      auto json = R"(  rapidjson::Document document;
  document.Parse(result->json().c_str());

  auto {0}s = response->mutable_{0}();
  auto &a = document["{0}"];
  for (rapidjson::Value::ConstValueIterator itr = a.Begin(); itr != a.End();
       ++itr) {{
    auto obj = itr->GetObject();
    todo::{0} {0};
    {0}s->Add(std::move({0}));
  }}
  std::cout << result->json();
  return grpc::Status::OK;)";
      /*r += QString::fromStdString(fmt::format(json, schema->text().toStdString()));
      resultText->setText(r);*/
    };
    connect(schema, &QLineEdit::textChanged, generate);
    connect(methodselect, &QComboBox::currentTextChanged, generate);
    connect(fieldvalue, &QLineEdit::textChanged, generate);
    connect(inputtext, &QPlainTextEdit::textChanged, generate);
  }
  {
    auto g = new QGroupBox(this);
    g->setTitle("insert Builder");
    auto h = new QHBoxLayout(g);
    auto v = new QVBoxLayout();
    // auto schemaLabel = new QLabel(this);
    auto schema = new QLineEdit(g);
    auto inputtext = new QPlainTextEdit(g);
    v->addWidget(schema);
    v->addWidget(inputtext);
    h->addItem(v);
    auto resultText = new QTextEdit(g);
    h->addWidget(resultText);
    h->setStretch(1, 2);
    v1->addWidget(g);
    auto generate = [schema, inputtext, resultText]() {
      auto t = inputtext->toPlainText();
      QString r;
      r += "auto dgraphorm = dgraph::DGraphClientManger::getDGraphOrm(\"1\");\n";
      r += "auto " + schema->text() + " = dgraphorm->newmodel(\"" + schema->text() + "\");\n";
      r += "auto result = new api::Response;\n";
      r += "auto status = " + schema->text() + "->create(dgraph::orm::Attributes{}\n";
      for (auto &l : t.split("\n"))
      {
        // l.replace(" b ", ",FieldProps::builder{} ");
        l.replace(QRegExp(" s (\\w*) (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".s(\"\\1\", \"\\2\") ");
        l.replace(QRegExp(" i (\\w*) (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".i(\"\\1\", \\2) ");
        l.replace(QRegExp(" d (\\w*) (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".d(\"\\1\", \\2) ");
        l.replace(QRegExp(" b (\\w*) (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".b(\"\\1\", \\2) ");
        l.replace(QRegExp(" u (\\w*) (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".u(\"\\1\", \"\\2\") ");
        l.replace(QRegExp(" u1 (\\w*) (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), ".u(\"\\1\", {\\2}) ");
        // set methods
        l.replace(QRegExp(" set (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), schema->text() + ".set_\\1(obj[\"\\1\"] ");
        l.replace(QRegExp(" 1 "), ".GetInt()); ");
        l.replace(QRegExp(" 2 "), ".GetFloat()); ");
        l.replace(QRegExp(" 3 "), ".GetString()); ");
        l.replace(QRegExp(" 4 "), ".GetBool()); ");
        l.replace(QRegExp(" e_"), ", result);");
        r += "\n";
        r += l;
      }
      r += "\n";
      auto swit = R"(switch (status) {
  case dgraph::orm::success: {
    auto j = nlohmann::json::parse(response->json());
    auto uid = j["%1"][0]["uid"].get<std::string>();
    break;
  }
  case dgraph::orm::unique_error:
    break;
  default:
    break;
})";
      r += QString::fromStdString(pystring::replace(swit, "%1", schema->text().toStdString()));
      r += "\ndelete response;\n";
      resultText->setText(r);
    };
    connect(inputtext, &QPlainTextEdit::textChanged, generate);
    connect(schema, &QLineEdit::textChanged, generate);
  }
  {
    auto g = new QGroupBox(this);
    g->setTitle("protobuf Builder");
    auto h = new QHBoxLayout(g);
    auto v = new QVBoxLayout();
    // auto schemaLabel = new QLabel(this);
    auto schema = new QLineEdit(g);
    auto inputtext = new QPlainTextEdit(g);
    v->addWidget(schema);
    v->addWidget(inputtext);
    h->addItem(v);
    auto resultText = new QTextEdit(g);
    h->addWidget(resultText);
    h->setStretch(1, 2);
    v1->addWidget(g);
    auto generate = [schema, inputtext, resultText]() {
      auto t = inputtext->toPlainText();
      QString r;
      for (auto &l : t.split("\n"))
      {
        // clang-format off
        l.replace(QRegExp(" map (\\w*) (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "map<\\1, \\2> ");
        l.replace(QRegExp(" rpc (\\w*) (\\w*) (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "rpc \\1 (\\2) returns (\\3);");
        l.replace(QRegExp(" rpcl (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "rpc get\\1 (\\1Req) returns (\\1Res);");
        l.replace(QRegExp(" rpcm (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "rpc mutate\\1 (\\1MutationReq) returns (\\1MutationRes);");
        l.replace(QRegExp(" rpcd (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "rpc delete\\1 (\\1DeleteReq) returns (\\1DeleteRes);");
        l.replace(QRegExp(" m1 "), "MutationReq ");
        l.replace(QRegExp(" m2 "), "MutationRes ");
        l.replace(QRegExp(" d1 "), "DeleteReq ");
        l.replace(QRegExp(" d2 "), "DeleteRes ");
        l.replace(QRegExp(" m (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "message \\1 {");
        l.replace(QRegExp(" s (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "service \\1 {");
        l.replace(QRegExp(" o (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "oneof \\1 {");
        // clang-format on
        l.replace(QRegExp(" 1 "), "bool ");
        l.replace(QRegExp(" 2 "), "string ");
        l.replace(QRegExp(" 3 "), "bytes ");
        l.replace(QRegExp(" 4 "), "double ");
        l.replace(QRegExp(" 5 "), "float ");
        l.replace(QRegExp(" 6 "), "int32 ");
        l.replace(QRegExp(" 7 "), "int64 ");
        l.replace(QRegExp(" 8 "), "uint32 ");
        l.replace(QRegExp(" 9 "), "uint64 ");
        l.replace(QRegExp(" 10 "), "sint32 ");
        l.replace(QRegExp(" 11 "), "sint64 ");
        l.replace(QRegExp(" 12 "), "fixed32 ");
        l.replace(QRegExp(" 13 "), "fixed64 ");
        l.replace(QRegExp(" 14 "), "sfixed32 ");
        l.replace(QRegExp(" 15 "), "sfixed64 ");
        l.replace(QRegExp(" e "), "enum ");
        l.replace(QRegExp(" r "), "repeated ");
        l.replace(QRegExp(" rt "), "returns ");
        l.replace(QRegExp(" a "), "google.protobuf.Any ");
        r += "\n";
        r += l;
      }
      r += "\n";
      resultText->setText(r);
    };
    connect(inputtext, &QPlainTextEdit::textChanged, generate);
    connect(schema, &QLineEdit::textChanged, generate);
  }
  {
    auto g = new QGroupBox(this);
    g->setTitle("yup Builder");
    auto h = new QHBoxLayout(g);
    auto v = new QVBoxLayout();
    // auto schemaLabel = new QLabel(this);
    auto schema = new QLineEdit(g);
    auto inputtext = new QPlainTextEdit(g);
    v->addWidget(schema);
    v->addWidget(inputtext);
    h->addItem(v);
    auto resultText = new QTextEdit(g);
    h->addWidget(resultText);
    h->setStretch(1, 2);
    v1->addWidget(g);
    auto generate = [schema, inputtext, resultText]() {
      auto t = inputtext->toPlainText();
      QString r;
      for (auto &l : t.split("\n"))
      {
        // clang-format off
        //l.replace(QRegExp(" map (\\w*) (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "map<\\1, \\2> ");
        //l.replace(QRegExp(" rpc (\\w*) (\\w*) (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "rpc \\1 (\\2) returns (\\3);");
        //l.replace(QRegExp(" rpcl (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "rpc get\\1 (\\1Req) returns (\\1Res);");
        //l.replace(QRegExp(" rpcm (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "rpc mutate\\1 (\\1MutationReq) returns (\\1MutationRes);");
        //l.replace(QRegExp(" rpcd (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "rpc delete\\1 (\\1DeleteReq) returns (\\1DeleteRes);");
        l.replace(QRegExp(" m "), ": A.yup.mixed() ");
        l.replace(QRegExp(" b "), ": A.yup.bool() ");
        l.replace(QRegExp(" b1 "), ": A.yup.boolean() ");
        l.replace(QRegExp(" s "), ": A.yup.string() ");
        l.replace(QRegExp(" n "), ": A.yup.number() ");
        l.replace(QRegExp(" d "), ": A.yup.date() ");
        l.replace(QRegExp(" o "), ": A.yup.object() ");
        l.replace(QRegExp(" a "), ": A.yup.array() ");
        l.replace(QRegExp(" v "), ": A.yup.ValidationError() ");
        l.replace(QRegExp(" re "), ": A.yup.reach() ");
        l.replace(QRegExp(" i "), ": A.yup.isSchema() ");
        l.replace(QRegExp(" sl "), ": A.yup.setLocale() ");
        l.replace(QRegExp(" ref "), ": A.yup.ref() ");
        l.replace(QRegExp(" l "), ": A.yup.lazy() ");

        l.replace(QRegExp(" r "), ".required() ");
        l.replace(QRegExp(" e "), ",");

        //l.replace(QRegExp(" m (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "message \\1 {");
        //l.replace(QRegExp(" s (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "service \\1 {");
        //l.replace(QRegExp(" o (\\w*) ", Qt::CaseSensitive, QRegExp::RegExp2), "oneof \\1 {");
        // clang-format on
        l.replace(QRegExp(" 1 "), "bool ");
        l.replace(QRegExp(" 2 "), "string ");
        l.replace(QRegExp(" 3 "), "bytes ");
        l.replace(QRegExp(" 4 "), "double ");
        l.replace(QRegExp(" 5 "), "float ");
        l.replace(QRegExp(" 6 "), "int32 ");
        l.replace(QRegExp(" 7 "), "int64 ");
        l.replace(QRegExp(" 8 "), "uint32 ");
        l.replace(QRegExp(" 9 "), "uint64 ");
        l.replace(QRegExp(" 10 "), "sint32 ");
        l.replace(QRegExp(" 11 "), "sint64 ");
        l.replace(QRegExp(" 12 "), "fixed32 ");
        l.replace(QRegExp(" 13 "), "fixed64 ");
        l.replace(QRegExp(" 14 "), "sfixed32 ");
        l.replace(QRegExp(" 15 "), "sfixed64 ");
        l.replace(QRegExp(" e "), "enum ");
        l.replace(QRegExp(" r "), "repeated ");
        l.replace(QRegExp(" rt "), "returns ");
        l.replace(QRegExp(" a "), "google.protobuf.Any ");
        r += "\n";
        r += l;
      }
      r += "\n";
      resultText->setText(r);
    };
    connect(inputtext, &QPlainTextEdit::textChanged, generate);
    connect(schema, &QLineEdit::textChanged, generate);
  }
  this->setLayout(v1);
}
DgraphCodeGenerator::~DgraphCodeGenerator() {}
}  // namespace widgets
