#include <iostream>
#include <cmath>

class Prisma_Inscribed_Rectilineal_Triangular {
private:
    double R; // радиус описанной окружности
    double a; // длина стороны правильного треугольника
    double H; // высота призмы
    double density; // плотность материала

public:
    Prisma_Inscribed_Rectilineal_Triangular(double radius, double height, double material_density) {
        R = radius;
        a = 2 * R * sin(3.14 / 3); // длина стороны правильного треугольника = 2R*sin(π/3)
        H = height;
        density = material_density;
    }

    double base_area() {
        return a * a * sqrt(3) / 4; // площадь основания Sосн. = a^2 * √3/4
    }

    double lateral_area() {
        return 3 * a * H; // площадь боковой поверхности Sбок. = 3a * H
    }

    double surface_area() {
        return 2 * base_area() + lateral_area(); // полная поверхность Sполн. = 2Sосн. + Sбок.
    }

    double volume() {
        return base_area() * H; // объем V = Sосн. * H
    }

    double weight() {
        return volume() * density; // вес = объем * плотность материала
    }
};

int main() {
    double radius = 5; // радиус описанной окружности
    double height = 10; // высота призмы
    double density = 7.8; // плотность материала (например, для стали)

    Prisma_Inscribed_Rectilineal_Triangular prism(radius, height, density);

    std::cout << "Base area: " << prism.base_area() << std::endl;
    std::cout << "Lateral area: " << prism.lateral_area() << std::endl;
    std::cout << "Surface area: " << prism.surface_area() << std::endl;
    std::cout << "Volume: " << prism.volume() << std::endl;
    std::cout << "Weight: " << prism.weight() << std::endl;

    return 0;
}