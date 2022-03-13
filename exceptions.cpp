#include <vector>
#include <thread>
#include <iostream>

void print_word(const std::string& word) {
    std::cout << "The word is " << word << '!' << std::endl;
}

// Запуск второго потока
int main() {
    // Запускаем поток
    std::thread other_thread(print_word, "DASR");
    // Выполняем фукнцию и в основном потоке
    print_word("IS CHAMPION");
    // Ждём, пока он завершится
    other_thread.join();
}

// Ловим исключение

//int main() {
//    std::vector<int> limited(5);
//    try {
//        std::cout << limited.at(10);
//    } catch (std::exception& ex) {
//        std::cout << ex.what() << std::endl;
//    }
//}