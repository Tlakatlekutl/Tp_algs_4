#include <iostream>
using namespace std;

int CountZero(int N) {
  int count = 0;
  int FiveLevel = 5; // Уровень деления на 5 (5, 25, 125 .....)
  while (FiveLevel <= N) {
    count+=N/FiveLevel;
    FiveLevel*=5;
  }
  return count;
}

int main() {
  int n = 0;
  cin >> n;
  cout << CountZero(n);
  return 0;
}
