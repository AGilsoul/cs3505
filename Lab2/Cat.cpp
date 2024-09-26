#include <iostream>

using std::cout;
using std::endl;

class Cat {
public:
    Cat(int numLives) : numLives(numLives) { }

     void reportLives() {
        cout << "This cat has " << numLives << " lives!" << endl;
     }

     void loseLife() {
        numLives--;
     }

     Cat& operator+=(int extraLives) {
        numLives += extraLives;
        return *this;
     }

private:
    int numLives {20};
};

int main() {
    Cat cat(9);
    cat.reportLives();
    cat.loseLife();
    cat.reportLives();
    (cat += 5) += 2;
    cat.reportLives();
}