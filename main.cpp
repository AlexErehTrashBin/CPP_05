#include <iostream>
#include <string>
#include <utility>
#include <memory>

using std::string, std::make_unique, std::unique_ptr, std::cout, std::endl;

// Абстрактный класс "Животное"
class Animal {
protected:
    string name;
    int age;
public:
    // Делегуирующий конструктор
    Animal(string  name, const int age) : name(std::move(name)), age(age) {}
    virtual ~Animal() = default;

    virtual void move() const = 0; // Виртуальный метод для движения
    virtual void sound() const = 0; // Виртуальный метод для издания звука
    virtual void displayInfo() const = 0; // Виртуальный метод для отображения информации о животном
};

// Производный класс "Собака"
class Worm final : public Animal {
public:
    // Делегуирующий конструктор
    Worm(const string& name, const int age) : Animal(name, age) {}

    void move() const override {
        cout << name << " ползёт по парку." << endl;
    }

    void sound() const override {
        cout << name << " молчит." << endl;
    }

    void displayInfo() const override {
        cout << "Червяк с гранатамётом по имени " << name << ", возраст: " << age << " год(а)." << endl;
    }
};

// Производный класс "Кошка"
class Cat : public Animal {
public:
    // Делегуирующий конструктор
    Cat(const string& name, const int age) : Animal(name, age) {}

    void move() const override {
        cout << name << " бегает по дому." << endl;
    }

    void sound() const override {
        cout << name << " мяукает: 'Мяу!'" << endl;
    }

    void displayInfo() const override {
        cout << "Кошка по кличке " << name << ", возраст: " << age << " год(а)." << endl;
    }
};

class Karakal final : public Cat {
public:
    // Делегуирующий конструктор
    Karakal(const string& name, const int age) : Cat(name, age) {}

    void sound() const override {
        cout << name << " типо мяукает: 'КШШШШШШШШШШШ!'" << endl;
    }

    void displayInfo() const override {
        cout << "Каракал по кличке " << name << ", возраст: " << age << " год(а)." << endl;
    }
};

int main() {
    // Создание объектов классов
    const unique_ptr<Animal> worm = make_unique<Worm>(Worm("Default name", 3));
    const unique_ptr<Animal> cat = make_unique<Cat>(Cat("Мурка", 2));
    const unique_ptr<Animal> karakal = make_unique<Karakal>(Karakal("Шлёпа", 6));

    // Вызов методов и отображение информации
    worm->displayInfo();
    worm->move();
    worm->sound();
    cout << endl;


    cat->displayInfo();
    cat->move();
    cat->sound();
    cout << endl;

    karakal->displayInfo();
    karakal->move();
    karakal->sound();

    return 0;
}
