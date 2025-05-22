#include <iostream>
using namespace std;

enum COLOR { WHITE, RED, BROWN, BLACK, KHAKI };

class Mammal {
public:
    // 构造函数
    Mammal() : itsAge(0), itsWeight(0) {}
    Mammal(int age) : itsAge(age), itsWeight(0) {}
    Mammal(int age, int weight) : itsAge(age), itsWeight(weight) {}
    ~Mammal() {}
    
    // 访问器
    int GetAge() const { return itsAge; }
    void SetAge(int a) { itsAge = a; }
    int GetWeight() const { return itsWeight; }
    void SetWeight(int w) { itsWeight = w; }
    
    // 其他方法
    void Speak() const {
        cout << "Mammal is speaking..." << endl;
    }
    void Sleep() const {
        cout << "Mammal is sleeping..." << endl;
    }
    
protected:
    int itsAge;
    int itsWeight;
};

class Dog : public Mammal {
public:
    // 构造函数
    Dog() : Mammal(), itsColor(WHITE) {}
    Dog(int age) : Mammal(age), itsColor(WHITE) {}
    Dog(int age, int weight) : Mammal(age, weight), itsColor(WHITE) {}
    Dog(int age, COLOR color) : Mammal(age), itsColor(color) {}
    Dog(int age, int weight, COLOR color) : Mammal(age, weight), itsColor(color) {}
    ~Dog() {}
    
    // 访问器
    COLOR GetColor() const { return itsColor; }
    void SetColor(COLOR color) { itsColor = color; }
    
    // 其他方法
    void WagTail() const {
        cout << "The dog is wagging its tail..." << endl;
    }
    void BegForFood() const {
        cout << "The dog is begging for food." << endl;
    }
    
private:
    COLOR itsColor;
};

int main() {
    Dog Fido;
    Dog Rover(5);
    Dog Buster(6, 8);
    Dog Yorkie(3, RED);
    Dog Dobbie(4, 20, KHAKI);
    
    Fido.Speak();       // Mammal is speaking...
    Rover.WagTail();    // The Dog is Wagging its tail...
    
    cout << "Yorkie is " << Yorkie.GetAge() << " years old." << endl;
    cout << "Dobbie weighs " << Dobbie.GetWeight() << " pounds." << endl;
    
    return 0;
}