#include "ex_6_8_9_20.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

// Напишите операцию "найти и заменить" для класса Docwnent, используя информацию из раздела 20.6.2.

// Напишите программу, подсчитывающую количество слов в объекте класса Document.Предусмотрите две версии : одну, в которой слово - это "последовательность символов, разделенных пробельными
// символами", и вторую, в которой слово - это "неразрывная после824 Глава 20 • Контейнеры и итераторы
// довательность алфавитных символов". Например, при первом определении выражения alpha . numeric и as12b это слова, а при втором каждое из них рассматривается как два слова.

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
        if (ch == '|') 
            break;           

        doc.line_.back().push_back(ch);

        if (ch == '\n')
            doc.line_.push_back(Line{});
    }

    if (doc.line_.back().size()) 
        doc.line_.push_back(Line{});

    return is;
}

void printDoc(Document& doc) {
    for (const auto& k : doc) {
        cout << k << " ";
    }
    cout << endl;
}

void eraseLine(Document& doc, int n) {
    if (n < 0 || doc.line_.size() - 1 <= n)
        return;

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

void ex_6_8_9_20() {
    Document myDoc;

    istringstream is{ "The test1\nThe test2\nThe test3\nThe test4\n" };
    is >> myDoc;

    printDoc(myDoc);

    cout << countSymbols(myDoc) << endl;
}