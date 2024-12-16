#include <iostream>
#include <memory>
#include <string>

// Абстрактний клас-фігура
class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
    virtual std::unique_ptr<Shape> clone() const = 0;
};

// Конкретна фігура: Коло
class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}

    void draw() const override {
        std::cout << "Drawing a circle with radius: " << radius_ << std::endl;
    }

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }

    double getRadius() const { return radius_; }

private:
    double radius_;
};

// Конкретна фігура: Квадрат
class Square : public Shape {
public:
    Square(double side) : side_(side) {}

    void draw() const override {
        std::cout << "Drawing a square with side: " << side_ << std::endl;
    }

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Square>(*this);
    }

    double getSide() const { return side_; }

private:
    double side_;
};

int main() {
    // Створюємо початкові зразки (прототипи)
    std::unique_ptr<Shape> circlePrototype = std::make_unique<Circle>(5.0);
    std::unique_ptr<Shape> squarePrototype = std::make_unique<Square>(10.0);

    // Клонуємо фігури
    auto anotherCircle = circlePrototype->clone();
    auto anotherSquare = squarePrototype->clone();

    // Використовуємо скопійовані об'єкти
    anotherCircle->draw(); // Drawing a circle with radius: 5
    anotherSquare->draw(); // Drawing a square with side: 10

    // Ми можемо змінити одну з фігур та зробити нову копію без впливу на оригінал
    // Наприклад, якщо Circle підтримувало б встановлення радіусу:
    // (У поточному прикладі пропустимо зміни, аби проілюструвати концепт.)

    return 0;
}
