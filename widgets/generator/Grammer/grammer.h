#ifndef GRAMMER_H
#define GRAMMER_H
#include <tao/pegtl.hpp>
namespace generator {
// Parsing rule that matches a literal "Hello, ".

struct prefix : tao::pegtl::string<'H', 'e', 'l', 'l', 'o', ',', ' '> {};

// Parsing rule that matches a non-empty sequence of
// alphabetic ascii-characters with greedy-matching.

struct name : tao::pegtl::plus<tao::pegtl::alpha> {};

// Parsing rule that matches a sequence of the 'prefix'
// rule, the 'name' rule, a literal "!", and 'eof'
// (end-of-file/input), and that throws an exception
// on failure.

struct grammar
    : tao::pegtl::must<prefix, name, tao::pegtl::one<'!'>, tao::pegtl::eof> {
};

// Class template for user-defined actions that does
// nothing by default.

template <typename Rule>
struct action {};

// Specialisation of the user-defined action to do
// something when the 'name' rule succeeds; is called
// with the portion of the input that matched the rule.

template <>
struct action<name> {
    template <typename Input>
    static void apply(const Input &in, std::string &v) {
        v = in.string();
    }
};


class Grammer {
public:
 public:
  Grammer();
};
}
#endif  // GRAMMER_H
