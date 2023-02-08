#include"Queue.h"
using namespace std;

int main() {
    LinkQueue Q;
    InitQueue(Q);
    
    int n, x;
    cout << "Please enter the number of rows: ";
    cin >> n;
    cout << endl;

    EnQueue(Q, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int left = Q.front->next->data;
            DeQueue(Q, x);
            cout << x;
            int right = Q.front->next->data;
            EnQueue(Q, left + right);
        }
        cout << 1 << endl;
        EnQueue(Q, 1);
    }
    system("pause");
    return 0;
}