#include "ex_6_8_9_20.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

using Line = vector<char>; 

class Text_iterator {
    list<Line>::iterator ln_;
    Line::iterator pos_;

public:
    Text_iterator(list<Line>::iterator ln, Line::iterator pos) : ln_{ ln }, pos_{ pos } { }

    char& operator *() {
        return *pos_;
    }

    Text_iterator& operator++();

    bool operator ==(const Text_iterator& other) const {
        return (ln_ == other.ln_) && (pos_ == other.pos_);
    }

    bool operator !=(const Text_iterator& other) const {
        return !(*this == other);
    }

    Line& getLine() const { 
        return *ln_; 
    }

    Line::iterator getPos() const {
        return pos_; 
    }
};

Text_iterator& Text_iterator::operator ++() {
    ++pos_;

    if (pos_ == ln_->end()) {
        ++ln_;
        pos_ = ln_->begin();
    }

    return *this;
}

struct Document {
    list<Line> line_;

    Document() {
        line_.push_back(Line{});
    }

    Text_iterator begin() {
        return Text_iterator(line_.begin(), line_.begin()->begin());
    }

    Text_iterator end() {
        auto last = line_.end();
        --last;                         
        return Text_iterator(last, last->end());
    }
};

istream& operator>>(istream& is, Document& doc) {
    for (char ch; is.get(ch); ) {
        if (ch == '|') {
            break;
        }

        doc.line_.back().push_back(ch);

        if (ch == '\n') {
            doc.line_.push_back(Line{});
        }
    }

    if (doc.line_.back().size()) {
        doc.line_.push_back(Line{});
    }

    return is;
}

void printDoc(Document& doc) {
    for (const auto& k : doc) {
        cout << k << " ";
    }
    cout << endl;
}

void eraseLine(Document& doc, int n) {
    if (n < 0 || doc.line_.size() - 1 <= n) {
        return;
    }

    auto p = doc.line_.begin();

    advance(p, n);

    doc.line_.erase(p);
}

int countSymbols(Document& doc) {
    int counter{ 0 };

    for (const auto& k : doc) {
        if (!isspace(k)) {
            ++counter;
        }
    }

    return counter;
}

template<typename Iter>         
void advance(Iter& pos, int n) {
    while (n > 0) { 
        ++pos; 
        --n; 
    }
   
    while (n < 0) { 
        --pos; 
        ++n; 
    }
}

bool match(Text_iterator p, Text_iterator last, const string& str) {
    for (auto q = str.begin(); q != str.end(); ++q) {
        if (*q != *p || p == last) {
            return false;
        }
        ++p;
    }
    return true;
}

Text_iterator findTxt(Text_iterator first, Text_iterator last, const string& str) {
    if (str.size() == 0) {
        return last;
    }
    char firstChar = str[0];

    while (true) {
        auto ptr = find(first, last, firstChar);

        if (ptr == last || match(ptr, last, str)) {
            return ptr;
        }

        first = ++ptr;
    }
}

int countWordsF(Document& doc) {
    bool param{ false };
    int counter{ 0 };

    for (const auto& k : doc) {
        if (!param and isalpha(k)) {
            param = true;
        }
        else if (param and isspace(k)) {
            param = false;
            ++counter;
        }
    }

    return counter;
}

int countWordsS(Document& doc) {
    bool param{ false };
    int counter{ 0 };

    for (const auto& k : doc) {
        if (!param and isalpha(k)) {
            param = true;
        }
        else if (param and !isalpha(k)) {
            param = false;
            ++counter;
        }
    }

    return counter;
}

void ex_6_8_9_20() {
    Document myDoc;

    istringstream is{ "The te.st1\nThe te1st2\nThe test3\nThe test4\n" };
    is >> myDoc;

    printDoc(myDoc);

    cout << countSymbols(myDoc) << endl;

    cout << countWordsF(myDoc) << endl;
    cout << countWordsS(myDoc) << endl;
}