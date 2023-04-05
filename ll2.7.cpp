/*

Основная программа для чтения данных из файла и вывода их на экран
Данный код читает данные из файла "competitors.csv" в формате csv и выводит их на экран.
При возникновении ошибок открытия файла, программа выводит сообщение об ошибке и завершается.
Автор: Anastasia Manastyrly
Дата: 01/04/23
*/
#include <iostream> // библиотека для стандартного ввода-вывода
#include <fstream> // библиотека для работы с файлами
#include <string> // библиотека для работы со строками
#include <list> // библиотека для работы со списками
#include "Competitor.h" // Подключаем заголовочный файл с определением класса Competitor

using namespace std;

/**

 Класс, представляющий участника соревнования

 Класс хранит информацию о ФИО участника и его результаты в различных видах соревнований.
 /
 class Competitor {
 private:
 string name; // ФИО участника
 list<int> scores; // список результатов участника в различных видах соревнований
 public:
 /*

 Конструктор класса Competitor
 Создает объект класса Competitor с заданным ФИО и пустым списком результатов.
 @param name ФИО участника
 */
Competitor(string name);
/**

 Метод добавления результата участника
 Добавляет новый результат участника в список его результатов.
 @param score Новый результат участника
 */
void addScore(int score);
/**

 Метод получения среднего результата участника
 Вычисляет и возвращает средний результат участника во всех видах соревнований.
 @return Средний результат участника
 */
double getAverageScore() const;
/**

 Метод получения ФИО участника
 Возвращает ФИО участника.
 @return ФИО участника
 */
string getName() const;
        };
        /**

         Конструктор класса Competitor
         Создает объект класса Competitor с заданным ФИО и пустым списком результатов.
         @param name ФИО участника
         */
        Competitor::Competitor(string name) {
            this->name = name;
        }
        /**

         Метод добавления результата участника
         Добавляет новый результат участника в список его результатов.
         @param score Новый результат участника
         */
        void Competitor::addScore(int score) {
            scores.push_back(score);
        }
        /**

         Метод получения среднего результата участника
         Вычисляет и возвращает средний результат участника во всех видах соревнований.
         @return Средний результат участника
         */
        double Competitor::getAverageScore() const {
            if (scores.empty()) {
                return 0;
            }
            double sum = 0;
            for (int score : scores) {
                sum += score;
            }
            return sum / scores.size();
        }
        /**

         Метод получения ФИО участника
         Возвращает ФИО участника.
         @return ФИО участника
         */
        string Competitor::getName() const {
            return name;
        }
        /**

         Основная функция программы

         Читает данные из файла "competitors.csv" в формате csv и выводит их на экран.

         При возникновении ошибок открытия файла, программа выводит сообщение об ошибке и завершается.
         */
        int main() {
            setlocale(LC_ALL, "Russian");

            // Чтение данных из файла csv
            ifstream file("competitors.csv");
            if (!file) {
                cerr << "Failed to open file" << endl;
                return 1;
            }

            // Вывод данных на экран
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }

            // Закрытие файла
            file.close();

            return 0;
        }