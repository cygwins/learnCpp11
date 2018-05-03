#include <iostream>
#include "Train.h"
void trim(std::string &s) {
    // trim leading/trailing white spaces
    const std::string whiteSpaces = " \t\n";
    auto head = s.find_first_not_of(whiteSpaces);
    auto rear = s.find_last_not_of(whiteSpaces);
    if (head != std::string::npos && rear != std::string::npos) { // not empty string
        s = s.substr(head, rear - head + 1);
    }
    else {
        s = "";
    }
}

Title::~Title() {
#ifdef VERBOSE
    std::cout << "Title obj '" << getTitle()
        << "' at " << this << " destroyed." << std::endl;
#endif
}

void Title::init() {
    trim(title_str);
#ifdef VERBOSE
    std::cout << "Title obj '" << getTitle()
        << "' at " << this << " initialized." << std::endl;
#endif
}

Person::~Person() {
#ifdef VERBOSE
    std::cout << "Person obj '" << getName()
        << "' at " << this << " destroyed." << std::endl;
#endif
}

void Person::init() {
    trim(name);
#ifdef VERBOSE
    std::cout << "Person obj '" << getName()
        << "' at " << this << " initialized." << std::endl;
#endif
}

Goods::~Goods() {
#ifdef VERBOSE
    std::cout << "Goods obj '" << getName()
        << "' at " << this << " destroyed." << std::endl;
#endif
}

void Goods::init() {
    trim(name);
#ifdef VERBOSE
    std::cout << "Goods obj '" << getName()
        << "' at " << this << " initialized." << std::endl;
#endif
}

Cabin::~Cabin() {
#ifdef VERBOSE
    std::cout << "Cabin obj at " << this << " destroyed." << std::endl;
#endif
}

void Cabin::init() {
    if(headCount() < 32) { // only reserve for memory, does not change seats.size()
        seats.reserve(32 - headCount());
    }
#ifdef VERBOSE
    std::cout << "Cabin obj at " << this << " initialized." << std::endl;
#endif
}

unsigned int Cabin::headCount() {
    return seats.size();
}

double Cabin::totalValue() {
    double v = 0;
    for(auto &goods : rack) {
        v += goods.value();
    }
    return v;
}

Cabin &Cabin::show(std::ostream &os) {
    if(seats.empty() && rack.empty()) {
        os << "(Empty cabin)" << std::endl;
        return *this;
    }
    if(seats.size()) {
        os << headCount() << " people on board:" << std::endl;
        for(auto &person : seats) {
            os << person.getName() << " (" << person.getTitle() << ")" << std::endl;
        }
    }
    if(rack.size()) {
        os << "Goods on rack:" << std::endl;
        os << "name\tprice\tamount\tsubtotal" << std::endl;
        for(auto &goods : rack) {
            os << goods.getName() << " \t$"
               << goods.getPrice() << " \tx" << goods.getAmount()
               << "\t=$" << goods.value() << std::endl;
        }
        os << "Total: $" << totalValue() << std::endl;
    }
    return *this;
}

Cabin &Cabin::addPerson(const Person &p) {
    seats.push_back(p);
    return *this;
}

Cabin &Cabin::addGoods (const Goods &g) {
    rack.push_back(g);
    return *this;
}

Cabin &Cabin::clearSeats() {
    seats.clear();
    return *this;
}

Cabin &Cabin::clearRack() {
    rack.clear();
    return *this;
}

Train::~Train() {
#ifdef VERBOSE
    std::cout << "Train obj '" << getName()
        << "' at " << this << " destroyed." << std::endl;
#endif
}

void Train::init() {
    if(name.empty()) {
        name = "Unnamed Train";
    }
    if(crew.empty()) {
        addCrew(Person("Bot", Title("Driver"))); // there must be someone running the train
    }
#ifdef VERBOSE
    std::cout << "Train obj '" << getName()
        << "' at " << this << " initialized." << std::endl;
#endif
}

Train::Train(const Person &captain) {
    addCrew(captain);
    init();
}

unsigned int Train::headCount() {
    unsigned int hc = 0;
    for(auto &cab : cabins) {
        hc += cab.headCount();
    }
    hc += crew.size();
    return hc;
}

double Train::totalValue() {
    double v = 0;
    for(auto &cab : cabins) {
        v += cab.totalValue();
    }
    return v;
}

Train &Train::addCrew(const Person &p) {
    crew.push_back(p);
    return *this;
}

Train &Train::append(const Cabin &cab) {
    cabins.push_back(cab);
    return *this;
}

Train &Train::prepend(const Cabin &cab) {
    cabins.push_front(cab);
    return *this;
}

Train &Train::cutTail() {
    cabins.pop_back();
    return *this;
}

Train &Train::cutHead() {
    cabins.pop_front();
    return *this;
}

Train &Train::show(std::ostream &os) {
    os << "************************" << std::endl;
    os << "Train: " << name << std::endl;
    os << "--------  Crew  --------" << std::endl;
    for(auto &c : crew) {
        os << c.getTitle() << ": \t" << c.getName() << std::endl;
    }
    os << "------------------------" << std::endl;
    unsigned int count = 0;
    for(auto &c : cabins) {
        os << " --> Cabin #" << ++count << ":" << std::endl;
        c.show(os);
    }
    os << "------  Summary  -------" << std::endl;
    os << "Total people on train: " << headCount() << std::endl;
    os << "Total value of cargo: " << totalValue() << std::endl;
    os << "**********end***********" << std::endl;
    return *this;
}
