/*
2_4. “Считалочка”. В круг выстроено N человек, пронумерованных числами от 1 до N. Будем исключать

каждого kого до тех пор, пока не уцелеет только один человек. (Например, если N=10, k=3, то сначала

умрет 3й, потом 6й, затем 9й, затем 2й, затем 7й, потом 1й, потом 8й, за ним  5й, и потом 10й. Таким

образом, уцелеет 4й.) Необходимо определить номер уцелевшего.

*/

#include <iostream>
using namespace std;

int TheGame(const int N, const int k) {
    bool players[N];
    for (int i = 0; i < N; i++)
        players[i] = true;
    int aliveCount = N;
    int survivedNumber = 0;
    int countToDeath = k; //Сколько счетов осталось до убийства
    
    while (true) {
        for (int i = 0; i < N; i++) {
            if (!players[i])   // Если уже мертв, пропускаем
                continue;
            if (aliveCount == 1){ // Возвращаем последнего
                survivedNumber = i+1; // массив считает с 0, а надо с 1
                 return survivedNumber;
            }
            countToDeath--;
            if (!countToDeath) {  // Иначе убиваем (Жестокая считалочка)
                players[i] = false;
                aliveCount--;
                countToDeath = k;
            }
        }
    }
    return survivedNumber;
}

int main() {
    int N = 0, k = 0; 
    cin >> N >> k;
    cout << TheGame(N, k);
    return 0;
}

