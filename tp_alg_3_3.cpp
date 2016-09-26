/*
3_3. Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию. A[0..n1] и B[0..m1].

n >> m. Найдите их пересечение. Требуемое время работы: O(m * log k), где k  позиция элементта B[m1] в

массиве A.. В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом поиска

элемента B[i1].

n, k ≤ 10000.
*/

#include <iostream>
using namespace std;

void printAns(const int size, const int *arr) {
    for (int i = 0; i < size-1; i++)
        cout << arr[i] <<" ";
    cout<< arr[size-1];
}

 void Intersection(
     const int n,
     const int * a,
     const int m,
     const int * b,
     int &size,
     int* ans) {
    int i = 0, j = 0;
    while (i != n && j!= m) {
        if (a[i] == b[j]) {
            ans[size] = b[j];
            i++;
            j++;
            size++;
            continue;
        }
        if (a[i] < b[j]) {
            i++;
            continue;
        }
        if (a[i] > b[j]) {
            j++;
        }

    }
 }


int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    int temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] ;
    }
        
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }
    int *ans = new int[m];
    int size = 0;
    Intersection(n, a, m, b, size, ans);
    if (size != 0)
        printAns(size, ans);
        
     delete[] a;
     delete[] b;
     delete[] ans;

   
    return 0;
}