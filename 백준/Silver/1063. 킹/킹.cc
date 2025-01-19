#include <iostream>
#include <string>
using namespace std;

class CheckChess {
    int Kcol, Scol;
    int Krow, Srow, Mcol, Mrow;

    // 방향 계산
    void direction(string input) {
        Mcol = 0, Mrow = 0;
        for (auto& a : input) {
            switch (a) {
            case 'R': Mcol += 1; break;
            case 'L': Mcol -= 1; break;
            case 'B': Mrow -= 1; break;
            case 'T': Mrow += 1; break;
            }
        }
    }

    // 킹과 돌이 같은 위치로 이동했는지 확인
    bool sameKS() {
        return (Kcol + Mcol == Scol && Krow + Mrow == Srow);
    }

    // 범위 초과 확인
    bool variableCheck(int Fcol, int Frow) {
        return (Fcol + Mcol < 0 || Fcol + Mcol > 7 || Frow + Mrow < 0 || Frow + Mrow > 7);
    }

public:
    CheckChess(char Kc, int Kr, char Sc, int Sr, int n) {
        Kcol = Kc - 'A'; // 0부터 시작하는 배열 좌표
        Scol = Sc - 'A';
        Krow = Kr - 1;
        Srow = Sr - 1;
    }

    void move(string input) {
        direction(input);

        // 킹의 이동이 범위를 벗어나면 무시
        if (variableCheck(Kcol, Krow)) return;

        // 킹이 이동하려는 곳에 돌이 있는 경우
        if (sameKS()) {
            // 돌도 이동해야 함
            if (variableCheck(Scol, Srow)) return; // 돌 이동이 범위를 벗어나면 무시
            Scol += Mcol;
            Srow += Mrow;
        }

        // 킹 이동
        Kcol += Mcol;
        Krow += Mrow;
    }

    void print() {
        // 킹과 돌의 위치 출력
        cout << (char)(Kcol + 'A') << (Krow + 1) << endl;
        cout << (char)(Scol + 'A') << (Srow + 1) << endl;
    }
};

int main() {
    char Kcol, Scol;
    int N, Krow, Srow;
    string input;

    // 초기 입력
    cin >> Kcol >> Krow >> Scol >> Srow >> N;

    // 클래스 생성
    CheckChess ch1(Kcol, Krow, Scol, Srow, N);

    // 움직임 처리
    for (int i = 0; i < N; i++) {
        cin >> input;
        ch1.move(input);
    }

    // 최종 위치 출력
    ch1.print();

    return 0;
}
