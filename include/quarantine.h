#ifndef QUARANTINE_H
#define QUARANTINE_H

#include <malloc.h>
#include <stdio.h>
#include "./stringLib.h" 

typedef struct Quarantine {
	int ID;
	int vaccination; //0:������, 1:1��, 2:2�� �� 14�� �̰��, 3: �����Ϸ�
	char vaccineName[20]; //��� �̸� 
	struct Quarantine* nextQT;
} QT;



///// �Լ� ���� /////
int QTlinkedListSize(QT* qt);
void QTpush(QT* qt, char* vaccineName, int vaccination);
void QTsearchView(QT* qt, int IPID);
int QTsize(QT* qt);


///// �Լ� �ۼ� /////
int QTlinkedListSize(QT* qt) {
	int size = 0;
	while(qt->nextQT != '\0') {
		qt = qt->nextQT;
		size++;
	}
	return size;
}

//���������� �߰� 
void QTpush(QT* qt, char* vaccineName, int vaccination) {
	QT* tmp = qt; 
	while (tmp->nextQT != '\0') { //��ũ�� ����Ʈ�� �� ������ �̵�
		tmp = tmp->nextQT;
	}
	//�� �Ҵ� 
	tmp->ID = QTlinkedListSize(qt);
	tmp->vaccination = vaccination;
	ct_strcpy(tmp->vaccineName, vaccineName);
	//���ο� ��� �޸� �Ҵ� �� nextQT�� nullptr�� �ʱ�ȭ
	QT* newNode = (QT*)malloc(sizeof(QT)); 
	newNode->nextQT = '\0';
	//���� nextQT �� �Ҵ�
	tmp->nextQT = newNode; 
}

//���������� �˻� 
void QTsearchView(QT* qt, int IPID) {
	const char* vacStr[4] = {
		"������", "1������", "2������ �� 14�� �̰��", "�����Ϸ�"
	};
	printf("\n---- Ȯ����ID: %d�� ���������� ��ü �˻� ----\n", IPID);
	while (qt->nextQT != 0) {
		printf("ID: %d\n", qt->ID);
		printf("����̸�: %s , %s\n", qt->vaccineName, vacStr[qt->vaccination]);
		printf("\n");
		qt = qt->nextQT;
	}
	printf("---- ���������� �˻� ���� ----\n\n");
}

#endif

