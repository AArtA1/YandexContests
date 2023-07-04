#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Структура для хранения координат точек
struct Point {
    double x;
    double y;
};

// Функция для расчета расстояния между двумя точками
double calculateDistance(const Point& point1, const Point& point2) {
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;
    return sqrt(dx * dx + dy * dy);
}

// Функция для решения задачи коммивояжера с использованием жадного алгоритма
vector<int> solveTSP(const vector<Point>& points) {
    int numPoints = points.size();
    vector<bool> visited(numPoints, false);
    vector<int> path;
    path.reserve(numPoints);

    // Начинаем с первой точки
    int currentCity = 0;
    path.push_back(currentCity);
    visited[currentCity] = true;

    while (path.size() < numPoints) {
        double minDistance = numeric_limits<double>::max();
        int nextCity = -1;

        // Находим ближайший доступный город
        for (int i = 0; i < numPoints; i++) {
            if (!visited[i]) {
                double distance = calculateDistance(points[currentCity], points[i]);
                if (distance < minDistance) {
                    minDistance = distance;
                    nextCity = i;
                }
            }
        }

        // Добавляем ближайший город в путь
        path.push_back(nextCity);
        visited[nextCity] = true;
        currentCity = nextCity;
    }

    return path;
}

int main() {
    int n;
    double x,y;
    cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n;++i){
        cin >> x >> y;
        points[i] =  {x,y};
    }

    // Решение задачи коммивояжера
    vector<int> path = solveTSP(points);

    // Вывод пути
    for (int i = 0; i < path.size(); i++) {
        cout << ++path[i] << " ";
    }

    return 0;
}
