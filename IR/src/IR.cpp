// By Zhiping

#include <IR.h>

namespace IR {

  IR::Type::Type(std::string t) {
    switch (t[0]) {
      case 'v':
        this->type = IR::TYPE::VOID;
      case 't':
        this->type = IR::TYPE::TUPLE;
      case 'c':
        this->type = IR::TYPE::CODE;
      case 'i':
        this->type = IR::TYPE::INT;
        this->arr_count = std::count(t.begin(), t.end(), '[');
    }
  }

  IR::InsBr::InsBr(std::vector<std::string> & v) {
    for (int k = 0; k < v.size(); k++) {
      IR::Var* var = new IR::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  std::string IR::InsBr::toString() {
    if (this->vars.size() == 1) {
      return "br " + this->vars[0]->toString();
    } else {
      return "br " + this->vars[0]->toString() + " " + this->vars[1]->toString() + " " + this->vars[2]->toString();
    }
  }

  IR::InsReturn::InsReturn(std::vector<std::string> & v) {
    if (v.size() > 0) {
      IR::Var* var = new IR::Var(v[0]);
      // std::cout << "v[0]: " << v[0] << "\n";
      this->vars.push_back(var);
    }
  }

  std::string IR::InsReturn::toString() {
    if (this->vars.size() > 0) {
      // std::cout << "this->vars[0]->toString(): " << this->vars[0]->toString() << "\n";
      return "return " + this->vars[0]->toString();
    }
    return "return";
  }

  IR::InsAssignCall::InsAssignCall(std::vector<std::string> & v) {
    IR::Var* var = new IR::Var(v[0]);
    this->vars.push_back(var);
    for (int k = 2; k < v.size(); k++) {
      IR::Var* var = new IR::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  std::string IR::InsAssignCall::toString() {
    std::string res = this->vars[0]->toString() + " <- call " + this->vars[1]->toString() + "(";
    if (this->vars.size() > 2) {
      res += this->vars[2]->toString();
    }
    for (int k = 3; k < this->vars.size(); k++) {
      res += " " + this->vars[k]->toString();
    }
    res += ")";
    return res;
  }

  IR::InsOpAssign::InsOpAssign(std::vector<std::string> & v) {
    for (int k = 0; k < v.size(); k++) {
      IR::Var* var = new IR::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  std::string IR::InsOpAssign::toString() {
    return this->vars[0]->toString() + " <- " + this->vars[1]->toString() + " " + this->vars[2]->toString() + " " + this->vars[3]->toString();
  }


  IR::InsType::InsType(std::vector<std::string> & v) {
    IR::Var* var = new IR::Var(v[0], v[1]);
    this->vars.push_back(var);
  }

  std::string IR::InsType::toString() {
    return "";
  }

  IR::InsCall::InsCall(std::vector<std::string> & v) {
    for (int k = 1; k < v.size(); k++) {
      IR::Var* var = new IR::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  std::string IR::InsCall::toString() {
    std::string res = "call " + this->vars[0]->toString() + "(";
    if (this->vars.size() > 1) {
      res += this->vars[1]->toString();
    }
    for (int k = 2; k < this->vars.size(); k++) {
      res += " " + this->vars[k]->toString();
    }
    res += ")";
    return res;
    // return "";
  }

  IR::InsAssign::InsAssign(std::vector<std::string> & v) {
    IR::Var* var;
    if (v[0].find("[") != std::string::npos) {
      var = new IR::Var(v[0], true);
    } else {
      var = new IR::Var(v[0]);
    }
    this->vars.push_back(var);
    if (v[1].find("[") != std::string::npos) {
      var = new IR::Var(v[0], true);
    } else {
      var = new IR::Var(v[0]);
    }
    this->vars.push_back(var);
  }

  std::string IR::InsAssign::toString() {
    return this->vars[0]->toString() + " <- " + this->vars[1]->toString();
  }

  IR::InsLength::InsLength(std::vector<std::string> & v) {
    IR::Var* var = new IR::Var(v[0]);
    this->vars.push_back(var);
    for (int k = 2; k < v.size(); k++) {
      IR::Var* var = new IR::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  std::string IR::InsLength::toString() {
    return "";
  }

  IR::InsNewArray::InsNewArray(std::vector<std::string> & v) {
    for (int k = 1; k < v.size(); k++) {
      IR::Var* var = new IR::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  std::string IR::InsNewArray::toString() {
    return "";
  }

  IR::InsNewTuple::InsNewTuple(std::vector<std::string> & v) {
    IR::Var* var = new IR::Var(v[1]);
    this->vars.push_back(var);
  }

  std::string IR::InsNewTuple::toString() {
    return "";
  }


  IR::BasicBlock::BasicBlock(std::string name) {
    this->label = name;
  }

  IR::Var::Var(std::string t, std::string n) {
    this->name = n;
    this->type = new IR::Type(t);
  }

  // IR::Var::Var(std::string tStr, bool hasT) {
  //
  // }

  std::string IR::Var::toString() {
    // std::cout << "toString " << this->name << "\n";
    if (this->name[0] == '%') {
      return this->name.substr(1, this->name.size()-1);
    }
    return this->name;
  }

  IR::Var::Var(std::string str, bool hasT) {
    if (hasT) {
      int r = 0;
      while (str[r] != '[') {
        r++;
      }
      this->name = str.substr(0, r);
      int l = r + 1;
      for (; r < str.size(); r++) {
        if (str[r] == ']') {
          IR::Var* t = new IR::Var(str.substr(l, r - l));
          this->ts.push_back(t);
          l = r + 2;
        }
      }
    } else {
      this->name = str;
      // switch (str[0]) {
      //
      //   // case ':':
      //   //   this->name = str;
      //   //   // this->type = IR::INS::LABEL;
      //   //   break;
      //   // case '%':
      //   //   this->name = str;
      //   //   // this->type = IR::INS::VAR;
      //   //   break;
      //   // default:
      //   //   this->value = std::stoll(str);
      //     // this->type = IR::INS::N;
      // }
    }
  }

}
