// By Zhiping

#include <LA.h>

namespace LA {

  LA::Type::Type(std::string t) {
    switch (t[0]) {
      case 'v':
        this->type = LA::TYPE::VOID;
        break;
      case 't':
        this->type = LA::TYPE::TUPLE;
        break;
      case 'c':
        this->type = LA::TYPE::CODE;
        break;
      case 'i':
        this->type = LA::TYPE::INT;
        this->arr_count = std::count(t.begin(), t.end(), '[');
        break;
    }
  }

  ////////
  // Ins
  /////

  LA::InsBr::InsBr(std::vector<std::string> & v) {
    for (int k = 0; k < v.size(); k++) {
      LA::Var* var = new LA::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  void LA::InsBr::toIR(std::ofstream &o, LA::Function * currF) {

  }

  std::vector<std::string> LA::InsBr::toEncode() {
    std::vector<std::string> res;
    return res;
  }
  std::vector<std::string> LA::InsBr::toDecode() {
    std::vector<std::string> res;
    return res;
  }

  LA::InsReturn::InsReturn(std::vector<std::string> & v) {
    if (v.size() > 0) {
      LA::Var* var = new LA::Var(v[0]);
      // std::cout << "v[0]: " << v[0] << "\n";
      this->vars.push_back(var);
    }
  }

  void LA::InsReturn::toIR(std::ofstream &o, LA::Function * currF) {

  }

  std::vector<std::string> LA::InsReturn::toEncode() {
    std::vector<std::string> res;
    return res;
  }
  std::vector<std::string> LA::InsReturn::toDecode() {
    std::vector<std::string> res;
    return res;
  }

  LA::InsAssignCall::InsAssignCall(std::vector<std::string> & v) {
    LA::Var* var = new LA::Var(v[0]);
    this->vars.push_back(var);
    for (int k = 2; k < v.size(); k++) {
      LA::Var* var = new LA::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  void LA::InsAssignCall::toIR(std::ofstream &o, LA::Function * currF) {

  }
  std::vector<std::string> LA::InsAssignCall::toEncode() {
    std::vector<std::string> res;
    return res;
  }
  std::vector<std::string> LA::InsAssignCall::toDecode() {
    std::vector<std::string> res;
    return res;
  }

  LA::InsOpAssign::InsOpAssign(std::vector<std::string> & v) {
    for (int k = 0; k < v.size(); k++) {
      LA::Var* var = new LA::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  void LA::InsOpAssign::toIR(std::ofstream &o, LA::Function * currF) {

  }
  std::vector<std::string> LA::InsOpAssign::toEncode() {
    std::vector<std::string> res;
    return res;
  }
  std::vector<std::string> LA::InsOpAssign::toDecode() {
    std::vector<std::string> res;
    return res;
  }


  LA::InsType::InsType(std::vector<std::string> & v) {
    LA::Var* var = new LA::Var(v[0], v[1]);
    this->vars.push_back(var);
  }

  void LA::InsType::toIR(std::ofstream &o, LA::Function * currF) {

  }
  std::vector<std::string> LA::InsType::toEncode() {
    std::vector<std::string> res;
    return res;
  }
  std::vector<std::string> LA::InsType::toDecode() {
    std::vector<std::string> res;
    return res;
  }

  LA::InsCall::InsCall(std::vector<std::string> & v) {
    for (int k = 1; k < v.size(); k++) {
      LA::Var* var = new LA::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  void LA::InsCall::toIR(std::ofstream &o, LA::Function * currF) {

  }
  std::vector<std::string> LA::InsCall::toEncode() {
    std::vector<std::string> res;
    return res;
  }
  std::vector<std::string> LA::InsCall::toDecode() {
    std::vector<std::string> res;
    return res;
  }

  LA::InsAssign::InsAssign(std::vector<std::string> & v) {
    LA::Var* var;
    if (v[0].find("[") != std::string::npos) {
      var = new LA::Var(v[0], true);
    } else {
      var = new LA::Var(v[0]);
    }
    this->vars.push_back(var);

    if (v[1].find("[") != std::string::npos) {
      var = new LA::Var(v[1], true);
    } else {
      var = new LA::Var(v[1]);
    }
    this->vars.push_back(var);
  }

  void LA::InsAssign::toIR(std::ofstream &o, LA::Function * currF) {

  }
  std::vector<std::string> LA::InsAssign::toEncode() {
    std::vector<std::string> res;
    return res;
  }
  std::vector<std::string> LA::InsAssign::toDecode() {
    std::vector<std::string> res;
    return res;
  }

  LA::InsLength::InsLength(std::vector<std::string> & v) {
    LA::Var* var = new LA::Var(v[0]);
    this->vars.push_back(var);
    for (int k = 2; k < v.size(); k++) {
      LA::Var* var = new LA::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  void LA::InsLength::toIR(std::ofstream &o, LA::Function * currF) {

  }
  std::vector<std::string> LA::InsLength::toEncode() {
    std::vector<std::string> res;
    return res;
  }
  std::vector<std::string> LA::InsLength::toDecode() {
    std::vector<std::string> res;
    return res;
  }

  LA::InsNewArray::InsNewArray(std::vector<std::string> & v) {
    LA::Var* var = new LA::Var(v[0]);
    this->vars.push_back(var);
    for (int k = 3; k < v.size(); k++) {
      LA::Var* var = new LA::Var(v[k]);
      this->vars.push_back(var);
    }
  }

  void LA::InsNewArray::toIR(std::ofstream &o, LA::Function * currF) {

  }
  std::vector<std::string> LA::InsNewArray::toEncode() {
    std::vector<std::string> res;
    return res;
  }
  std::vector<std::string> LA::InsNewArray::toDecode() {
    std::vector<std::string> res;
    return res;
  }

  LA::InsNewTuple::InsNewTuple(std::vector<std::string> & v) {
    LA::Var* var = new LA::Var(v[0]);
    this->vars.push_back(var);
    var = new LA::Var(v[3]);
    this->vars.push_back(var);
  }

  void LA::InsNewTuple::toIR(std::ofstream &o, LA::Function * currF) {

  }
  std::vector<std::string> LA::InsNewTuple::toEncode() {
    std::vector<std::string> res;
    return res;
  }
  std::vector<std::string> LA::InsNewTuple::toDecode() {
    std::vector<std::string> res;
    return res;
  }

  ///////
  // Var
  /////

  LA::Var::Var(std::string t, std::string n) {
    this->name = n;
    this->type = new LA::Type(t);
  }

  std::string LA::Var::toString() {
    if (this->name[0] == '%') {
      return this->name.substr(1, this->name.size()-1);
    }
    return this->name;
  }

  LA::Var::Var(std::string & str, bool hasT) {
    if (hasT) {
      int r = 0;
      while (str[r] != '[') {
        r++;
      }
      this->name = str.substr(0, r);
      int l = r + 1;
      for (; r < str.size(); r++) {
        if (str[r] == ']') {
          std::string sub = str.substr(l, r - l);
          LA::Var* t = new LA::Var(sub);
          this->ts.push_back(t);
          l = r + 2;
        }
      }
    } else {
      this->name = str;
    }
  }
}
