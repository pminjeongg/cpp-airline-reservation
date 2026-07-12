#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct AirPlane {
    vector<string> seat07;
    vector<string> seat12;
    vector<string> seat17;
};

void reserve(vector<AirPlane>& air) {
    string name;
    int airnum;
    int time;
    int seatnum;

    printf("07시:1, 12시:2, 17시:3>>");
    scanf("%d", &time);
    if (time< 1 || time > 3) {
        printf("잘못된 시간입니다..\n");
        return;
    }
    printf("1호기,2호기,3호기>>");
    scanf("%d", &airnum);

    if (airnum < 1 || airnum > 3) {
        printf("잘못된 호기 번호입니다.\n");
        return;
    }
    
    if (time == 1) {
        for (int i = 0; i < air[airnum - 1].seat07.size(); i++) {
            cout << air[airnum - 1].seat07[i] << ' ';
        }
        cout << endl;

        printf("좌석번호>>");
        scanf("%d", &seatnum);

        if (seatnum < 1 || seatnum > 8) {
            printf("잘못된 좌석번호입니다.\n");
            return;
        }

        printf("이름 입력>>");
        cin >> name;

        if (air[airnum - 1].seat07[seatnum - 1] == "---") {
            air[airnum - 1].seat07[seatnum - 1] = name;
        }
        else {
            printf("이미 예약된 좌석입니다.\n");
        }
    }

    else if (time == 2) {
        for (int i = 0; i < air[airnum - 1].seat12.size(); i++) {
            cout << air[airnum - 1].seat12[i] << ' ';
        }
        cout << endl;

        printf("좌석번호>>");
        scanf("%d", &seatnum);

        if (seatnum < 1 || seatnum > 8) {
            printf("잘못된 좌석번호입니다.\n");
            return;
        }

        printf("이름 입력>>");
        cin >> name;

        if (air[airnum - 1].seat12[seatnum - 1] == "---") {
            air[airnum - 1].seat12[seatnum - 1] = name;
        }
        else {
            printf("이미 예약된 좌석입니다.\n");
        }
    }

    else if (time == 3) {
        for (int i = 0; i < air[airnum - 1].seat17.size(); i++) {
            cout << air[airnum - 1].seat17[i] << ' ';
        }
        cout << endl;

        printf("좌석번호>>");
        scanf("%d", &seatnum);

        if (seatnum < 1 || seatnum > 8) {
            printf("잘못된 좌석번호입니다.\n");
            return;
        }

        printf("이름 입력>>");
        cin >> name;

        if (air[airnum - 1].seat17[seatnum - 1] == "---") {
            air[airnum - 1].seat17[seatnum - 1] = name;
        }
        else {
            printf("이미 예약된 좌석입니다.\n");

        }
    }
}

void cancel(vector<AirPlane>& air) {
    int time;
    int airnum;
    int seatnum;
    string name;

    printf("항공기 번호>>");
    scanf("%d", &airnum);
    printf("07시:1, 12시:2, 17시:3>>");
    scanf("%d", &time);

    if (airnum < 1 || airnum > 3) {
        printf("잘못된 호기 번호입니다.\n");
        return;
    }
    if (time < 1 || time > 3) {
        printf("잘못된 시간입니다.\n");
        return;
    }

    switch (time) {
    case 1:
        for (int i = 0; i < air[airnum - 1].seat07.size(); i++) {
            cout << air[airnum - 1].seat07[i] << ' ';
        }

        cout << endl;

        printf("좌석번호>>");
        scanf("%d", &seatnum);

        printf("이름입력>>");
        cin >> name;

        if (seatnum < 1 || seatnum > 8) {
            printf("잘못된 좌석번호입니다.\n");
            break;
        }

        if (air[airnum - 1].seat07[seatnum - 1] == name) {
            air[airnum - 1].seat07[seatnum - 1] = "---";
            printf("취소되었습니다.\n");
        }
        else {
            printf("예약 정보가 일치하지 않습니다.\n");
        }
        break;

    case 2:
        for (int i = 0; i < air[airnum - 1].seat12.size(); i++) {
            cout << air[airnum - 1].seat12[i] << ' ';
        }
        cout << endl;

        printf("좌석번호>>");
        scanf("%d", &seatnum);

        printf("이름입력>>");
        cin >> name;

        if (seatnum < 1 || seatnum > 8) {
            printf("잘못된 좌석번호입니다.\n");
            break;
        }

        if (air[airnum - 1].seat12[seatnum - 1] == name) {
            air[airnum - 1].seat12[seatnum - 1] = "---";
            printf("취소되었습니다.\n");
        }
        else {
            printf("예약 정보가 일치하지 않습니다.\n");
        }
        break;

    case 3:
        for (int i = 0; i < air[airnum - 1].seat17.size(); i++) {
            cout << air[airnum - 1].seat17[i] << ' ';
        }

        cout << endl;

        printf("좌석번호>>");
        scanf("%d", &seatnum);

        printf("이름입력>>");
        cin >> name;

        if (seatnum < 1 || seatnum > 8) {
            printf("잘못된 좌석번호입니다.\n");
            break;
        }

        if (air[airnum - 1].seat17[seatnum - 1] == name) {
            air[airnum - 1].seat17[seatnum - 1] = "---";
            printf("취소되었습니다.\n");
        }
        else {
            printf("예약 정보가 일치하지 않습니다.\n");
        }
        break;
    }
}


void see(vector<AirPlane>&air) {
    for (int i = 0; i < air.size(); i++) {
        cout << "\n" << i + 1 << "호기\n";
        cout << "7시 좌석표 : ";
        for (int j = 0; j < air[i].seat12.size(); j++) {
            cout << air[i].seat07[j] << '\t';
            }
        cout << endl;
        cout << "12시 좌석표 : ";
        for (int j = 0; j < air[i].seat12.size(); j++) {
            cout << air[i].seat12[j] << '\t';
            }
        cout << endl;
        cout << "17시 좌석표 : ";
        for (int j = 0; j < air[i].seat17.size(); j++) {
            cout << air[i].seat17[j] << '\t';
            }
        cout << endl;
    }
}

void saveFile(vector<AirPlane>& air) {
    FILE* fp = fopen("air.txt", "w");
    for (int i = 0; i < air.size(); i++) {
        for (int j = 0; j < 8; j++)
            fprintf(fp, "%s ", air[i].seat07[j].c_str());
        fprintf(fp, "\n");

        for (int j = 0; j < 8; j++)
            fprintf(fp, "%s ", air[i].seat12[j].c_str());
        fprintf(fp, "\n");

        for (int j = 0; j < 8; j++)
            fprintf(fp, "%s ", air[i].seat17[j].c_str());
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void loadFile(vector<AirPlane>& air) {
    FILE* fp = fopen("air.txt", "r");

    if (fp != NULL) {
        char temp[100];
        for (int i = 0; i < air.size(); i++) {
            for (int j = 0; j < 8; j++) {
                fscanf(fp, "%s", temp);
                air[i].seat07[j] = temp;
            }
            for (int j = 0; j < 8; j++) {
                fscanf(fp, "%s", temp);
                air[i].seat12[j] = temp;
            }
            for (int j = 0; j < 8; j++) {
                fscanf(fp, "%s", temp);
                air[i].seat17[j] = temp;
            }
        }
        fclose(fp);
    }

}

int main() {
    vector<AirPlane> air(3);
    int select;

    printf("**** 한성항공에 오신것을 환영합니다 ****\n");

    for (int i = 0; i < air.size(); i++) {
        air[i].seat07.resize(8, "---");
        air[i].seat12.resize(8, "---");
        air[i].seat17.resize(8, "---");
    } 
    while (1) {
        printf("\n예약:1, 취소:2, 보기:3, 끝내기:4>>");
        scanf("%d", &select);
        loadFile(air);
        switch (select) {
            case 1:
                reserve(air);
                break;
            case 2:
                cancel(air);
                break;

            case 3:
                see(air);
                break;

            case 4:
                saveFile(air);
                loadFile(air);
                return 0;

            default:
                printf("잘못된 메뉴입니다.\n");
        }
    }
}