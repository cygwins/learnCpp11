#ifndef BUCKET_H_
#define BUCKET_H_
#include <string>

class Bucket {
public:
    Bucket() = default;
    Bucket(const int v); // construct with volume
    void fill(const int);
    void pour(const int);
    void replenish();
    void empty();
    void manip(); // manipulate interactively
    void paint(const std::string); // change appearance
    void show(); // show color and remaining water
    void hint(); // show manual

private:
    int volume;
    int water;
    std::string color;
};
#endif
