#ifndef TRAIN_H_
#define TRAIN_H_
#include <iostream>
#include <vector>
#include <deque>
#include <string>
class Title {
public:
    explicit Title(const std::string s) : title_str(s) { init(); }
    Title() : Title("Notitle") { }
    ~Title();
    std::string getTitle() { return title_str; }
private:
    std::string title_str; // init() may change this attribute
    void init(); // trim leading/trailing white spaces
};

class Person {
public:
    Person(const std::string &n = "Noname",
           const Title t = Title("Passenger")) :
        name(n), title(t) { init(); }
    ~Person();
    std::string getName() { return name; }
    std::string getTitle() { return title.getTitle(); }
private:
    std::string name;
    Title title;
    void init();
};

class Goods {
public:
    Goods(const std::string &n, double a, double p = 0) :
        name(n), amount(a), price(p) { init(); }
    explicit Goods(const std::string &n) : Goods(n, 0, 0) { } // delegate constructor
    Goods() : Goods("Noname", 0, 0) { }
    ~Goods();
    std::string getName() { return name; }
    double getAmount() { return amount; }
    double getPrice() { return price; }
    double value() { return amount * price; } // implicit inline
private:
    std::string name;
    double amount;
    double price;
    void init();
};

class Cabin {
public:
    Cabin() { init(); }
    explicit Cabin(const std::vector<Person> &vP) : seats(vP) { init(); }
    explicit Cabin(const std::vector<Goods> &vG) : rack(vG) { init(); } 
    ~Cabin();
    bool hasPerson() { return !seats.empty(); }
    bool hasGoods() { return !rack.empty(); }
    unsigned int headCount(); // total number of people on board
    double totalValue(); // total value of all Goods
    Cabin &show(std::ostream &); // print content of Cabin, return *this
    Cabin &addPerson(const Person&); // return *this
    Cabin &addGoods(const Goods&);
    Cabin &clearSeats();
    Cabin &clearRack();
private:
    std::vector<Person> seats;
    std::vector<Goods> rack;
    void init();
};

class Train {
public:
    Train() { init(); }
    explicit Train(const std::string &n) : name(n) { init(); }
    explicit Train(const Person &captain); // require explicitly casting string argument to Person to avoid confusing with train name
    explicit Train(const std::deque<Cabin> &cabs) : cabins(cabs) { init(); }
    ~Train();
    std::string getName() { return name; }
    unsigned int headCount(); // number of riders on the train
    double totalValue(); // total value of all cargo
    void setName(const std::string &n) { name = n; }
    Train &addCrew(const Person &); // return *this
    Train &append(const Cabin &); // add cabin at tail, return *this
    Train &prepend(const Cabin &); // add cabin at head
    Train &cutTail(); // disconnect last cabin
    Train &cutHead(); // disconnect first cabin
    Train &show(std::ostream &);
private:
    std::string name;
    std::vector<Person> crew;
    std::deque<Cabin> cabins;
    void init();
};
#endif
