#include <iostream>
using namespace std;

class Figure {
public:
    virtual float area() = 0;
};

class Parallelogram : Figure {
public:
    float width, height, corner;
    Parallelogram() : width(0), height(0), corner(0) {}
    Parallelogram(float w, float h, float c) : width(w), height(w), corner(c) {}
    float area() { return (width * height) * sin(corner); };
};

class Rectangle : Parallelogram {
public:
    float width, height;
    Rectangle() : width(0), height(0) {}
    Rectangle(float w, float h) : width(w), height(h) {}
    float area() { return width * height; };
};

class Square : Parallelogram {
public:
    float s;
    Square() : s(0) {}
    Square(float s) : s(s) {}
    float area() { return s * s; };
};

class Rhombus : Parallelogram {
public:
    float s, height;
    Rhombus() : s(0), height(0) {}
    Rhombus(float s, float h) : s(s), height(h) {}
    float area() { return s * height; }
};

class Circle : Figure {
public:
    float r;
    Circle() : r(0) {}
    Circle(float r) : r(r) {}
    float area() { return (float)3.1415926 * pow(r, 2); }
};

// Задание 2

class Car {
public:
    string company;
    string model;

    Car(string company, string model) {
        this->company = company;
        this->model = model;
    }

    virtual void printInfo() {
        cout << "Компания: " << company << ", Модель: " << model << endl;
    }
};

class PassengerCar : virtual public Car {
public:
    PassengerCar(string company, string model) : Car(company, model) {}

    virtual void printInfo() {
        cout << "Пассажирская машина - Компания: " << company << ", Модель: " << model << endl;
    }
};

class Bus : virtual public Car {
public:
    Bus(string company, string model) : Car(company, model) {}

    virtual void printInfo() {
        cout << "Автобус - Компания: " << company << ", Модель: " << model << endl;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(string company, string model) : Car(company, model), PassengerCar(company, model), Bus(company, model) {}

    virtual void printInfo() {
        cout << "Минивэн - Компания: " << company << ", Модель: " << model << endl;
    }
};

// Задание 3

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    Fraction(int num, int denom) {
        numerator = num;
        if (denom != 0)
            denominator = denom;
        else
        {
            cout << "Знаменатель не должен быть 0!" << endl;
            return;
        }
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator + other.numerator, denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator - other.numerator, denominator);
    }

    Fraction operator-() {
        return Fraction(-numerator, denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(denominator * other.denominator, numerator * other.numerator);
    }

    bool operator==(const Fraction& other) const {
        return numerator / denominator == other.numerator / other.denominator;
    }

    bool operator>(const Fraction& other) const {
        return numerator / denominator > other.numerator / other.denominator;
    }

    bool operator<(const Fraction& other) const {
        return numerator / denominator < other.numerator / other.denominator;
    }

    bool operator>=(const Fraction& other) const {
        return numerator / denominator >= other.numerator / other.denominator;
    }

    bool operator<=(const Fraction& other) const {
        return numerator / denominator <= other.numerator / other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return numerator / denominator != other.numerator / other.denominator;
    }

    void print()
    {
        cout << numerator << "/" << denominator;
    }

};


int main() {
    setlocale(0, "Rus");
    Parallelogram Parallelogram(5, 5, 30);
    Rectangle Rectangle(5, 10);
    Square Square(5);
    Rhombus Rhombus(8, 12);
    Circle Circle(5);

    cout << "Площадь параллелограмма: " << Parallelogram.area() << endl;
    cout << "Площадь прямоугольника: " << Rectangle.area() << endl;
    cout << "Площадь квадрата: " << Square.area() << endl;
    cout << "Площадь ромба: " << Rhombus.area() << endl;
    cout << "Площадь круга: " << Circle.area() << endl;

    // Задание 2

    Car* car = new Car("Toyota", "Corolla");
    car->printInfo();

    PassengerCar* passengerCar = new PassengerCar("Toyota", "Camry");
    passengerCar->printInfo();

    Bus* bus = new Bus("Volvo", "B7L");
    bus->printInfo();

    Minivan* minivan = new Minivan("Chrysler", "Pacifica");
    minivan->printInfo();

    // Задание 3

    Fraction f = Fraction(1, 3);
    Fraction f1 = Fraction(1, 3);

    Fraction sum = f + f1;
    sum.print();

    if (f == f1)
    {
        cout << "Дроби равны." << endl;
    }

}