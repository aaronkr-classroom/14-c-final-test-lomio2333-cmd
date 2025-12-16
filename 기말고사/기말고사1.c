//기말고사1


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char name[20];
    int kor, eng, math;
    int total;
    float avg;
    struct Node* next;
} Node;
void addStudent(Node** head, Node** tail) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    printf("이름: ");
    scanf_s("%s", newNode->name, (unsigned)_countof(newNode->name));

    printf("국어 점수: ");
    scanf_s("%d", &newNode->kor);

    printf("영어 점수: ");
    scanf_s("%d", &newNode->eng);

    printf("수학 점수: ");
    scanf_s("%d", &newNode->math);

    newNode->total = newNode->kor + newNode->eng + newNode->math;
    newNode->avg = newNode->total / 3.0f;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }
    else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
void printStudents(Node* head) {
    Node* p;
    int rank;

    printf("\n이름   국어 영어 수학 총점 평균 등수\n");

    for (p = head; p != NULL; p = p->next) {
        rank = 1;

        Node* q;
        for (q = head; q != NULL; q = q->next) {
            if (q->total > p->total)
                rank++;
        }

        printf("%-6s %4d %4d %4d %4d %6.1f %3d등\n",
            p->name, p->kor, p->eng, p->math,
            p->total, p->avg, rank);
    }
}
int main(void) {
    Node* head = NULL;
    Node* tail = NULL;
    int menu;

    while (1) {
        printf("\n[Menu]\n");
        printf("1. 성적 입력\n");
        printf("2. 성적 확인\n");
        printf("3. 종료\n");
        printf("선택(1~3): ");
        scanf_s("%d", &menu);

        if (menu == 1) {
            addStudent(&head, &tail);
        }
        else if (menu == 2) {
            printStudents(head);
        }
        else if (menu == 3) {
            printf("프로그램이 종료됨\n");
            break;
        }
        else {
            printf("잘못된 선택입니다.\n");
        }
    }

    // 메모리 해제
    Node* p;
    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
    tail = NULL;

    return 0;
}
