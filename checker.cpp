#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>


using namespace std;

string get_res(string command){
    string output;
    char buffer[128];
    std::string cmd = command + " 2>&1"; // перенаправление потока ошибок в поток вывода

    FILE* pipe = popen(cmd.c_str(), "r"); // открытие канала для чтения

    if (pipe) {
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            output += buffer;
        }
        pclose(pipe); // закрытие канала
    }
    return output;
}

int main() {
    srand(time(NULL));
    int I = 0;
    string result;
    bool match = true;
    string input = "";
    while (match) {
        I++;
        std::ofstream fout("input.txt");
        // генерируем входные данные
        int n = rand() % 20 + 1;
        input = "1 " + to_string(n) + " ";
        for(int i=0; i<n; i++){
            int x = rand() % 5 + 1;
            if(rand() % 2) x = 1;
            input += to_string(x) + " ";
        }
        fout << input;
        fout.close();
        // запускаем первую программу
        string command1 = "Main1.exe < input.txt"; // test main
        string output1 = get_res(command1);
        // запускаем вторую программу
        string command2 = "Main2.exe < input.txt"; // good main
        string output2 = get_res(command2);

        // сравниваем результаты
        if (output1 != output2) {
            match = false;
            cout << "Test " + to_string(I) + ": mismatch\n";
            cout << input << endl;
            cout << "Expected: " + output2 + "  Got: " + output1 + '\n';
        } else {
            // записываем результат
            cout << "Test " + to_string(I) + ": " + output1 + " == " + output2 + '\n';
        }
    }
    return 0;
}