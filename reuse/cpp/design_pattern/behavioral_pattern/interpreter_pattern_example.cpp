#include <iostream>
#include <string>


// expression interface
class Expression {
 public:
  virtual bool interpret (std::string context) = 0;
};


// entity class
class TerminalExpression: public Expression {
 public:
  TerminalExpression(std::string data) : data(data) { }

  virtual bool interpret(std::string context) {
    if (context.find(this->data) != std::string::npos) {
      return true;
    } else {
      return false;
    }
  }

 private:
  std::string data;
};


class OrExpression: public Expression {
 public:
  OrExpression(Expression* expr1, Expression* expr2) : expr1(expr1), expr2(expr2) { }

  ~OrExpression() {
    delete this->expr1;
    delete this->expr2;
  }

  virtual bool interpret(std::string context) {
    return this->expr1->interpret(context) || this->expr2->interpret(context);
  }
 private:
  Expression* expr1;
  Expression* expr2;
};

class AndExpression: public Expression {
 public:
  AndExpression(Expression* expr1, Expression* expr2) : expr1(expr1), expr2(expr2) { }

  ~AndExpression() {
    delete this->expr1;
    delete this->expr2;
  }

  virtual bool interpret(std::string context) {
    return this->expr1->interpret(context) && this->expr2->interpret(context);
  }
 private:
  Expression* expr1;
  Expression* expr2;

};


// create rule
static Expression* get_male_expression() {
  Expression* robert = new TerminalExpression("Robert");
  Expression* john   = new TerminalExpression("John");
  return new OrExpression(robert, john);
}

static Expression* get_married_woman_expression() {
  Expression* julie   = new TerminalExpression("Julie");
  Expression* married = new TerminalExpression("Married");
  return new AndExpression(julie, married);
}

// using interpreter pettern example
int main() {
  Expression* is_male          = get_male_expression();
  Expression* is_married_woman = get_married_woman_expression();

  std::cout << "John is male? " << is_male->interpret("John") << std::endl;
  std::cout << "Julie is a married women? " << is_married_woman->interpret("Married Julie") << std::endl;

  delete is_male;
  delete is_married_woman;

  return 0;
}
