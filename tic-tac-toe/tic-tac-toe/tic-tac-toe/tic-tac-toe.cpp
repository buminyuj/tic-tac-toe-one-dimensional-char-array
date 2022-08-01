#include <iostream>
using namespace std;
char arr[9] = { '1','2','3','4','5','6','7','8','9' };
int checkwin();
void board();

int main() {
    int player = 1, k;
    int choice;
    do {
        char mark;
        player = (player % 2) ? 1 : 2;
        board();
        cout << "player " << player << " enter a number" << endl;
        cout << "choice:";
        cin >> choice;
        mark = (player == 1) ? 'x' : 'O';

        if (arr[choice - 1] == '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9')
            arr[choice - 1] = mark;
        else
            cout << "invalid move";
        cin.ignore();
        cin.get();
        k = checkwin();
        player++;
    } while (k == -1);
    board();
    if (k == 1)
        cout << "player " << player - 1 << " win";
    else if (k == 0)
        cout << "draw";
    else
        cout << "invalid game";
    cin.ignore();
    cin.get();

    return 0;
}
void board() {
    system("cls");
    for (int i = 0; i < 9; i++) {
        cout << "|___" << arr[i] << "___|";
        if (i % 3 == 2)
            cout << endl;
    };
}
int checkwin() {
    if (arr[0] == arr[1] && arr[1] == arr[2])
        return 1;
    else if (arr[3] == arr[4] && arr[4] == arr[5])
        return 1;
    else if (arr[6] == arr[7] && arr[7] == arr[8])
        return 1;
    else if (arr[0] == arr[3] && arr[3] == arr[6])
        return 1;
    else if (arr[1] == arr[4] && arr[4] == arr[7])
        return 1;
    else if (arr[2] == arr[5] && arr[5] == arr[8])
        return 1;
    else if (arr[0] == arr[4] && arr[4] == arr[8])
        return 1;
    else if (arr[2] == arr[4] && arr[4] == arr[6])
        return 1;
    else if (arr[0] != '1' && arr[1] != '2' && arr[2] != '3' && arr[3] != '4' && arr[4] != '5' && arr[5] != '6' && arr[6] != '7' && arr[7] != '8' && arr[8] != '9')
        return 0;
    else return -1;
}