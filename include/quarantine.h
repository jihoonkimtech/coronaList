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
int QTremove(QT* qt, int QID);
void QTremoveAll(QT* qt);


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
	if (vaccineName[0] == 'h') { //head init
		qt->ID = -1;
	}
	else { //���� push
		int prevID = 0;
		while (tmp->nextQT != '\0') { //��ũ�� ����Ʈ�� �� ������ �̵�
			prevID = tmp->ID;
			tmp = tmp->nextQT;
		}
		//�� �Ҵ� 
		tmp->ID = prevID + 1;
		tmp->vaccination = vaccination;
		ct_strcpy(tmp->vaccineName, vaccineName);
	}
	//���ο� ��� �޸� �Ҵ� �� nextQT�� nullptr�� �ʱ�ȭ
	QT* newNode = (QT*)malloc(sizeof(QT)); 
	newNode->nextQT = '\0';
	//���� nextQT �� �Ҵ�
	tmp->nextQT = newNode;
}

//���������� ��ü �˻� 
void QTsearchView(QT* qt, int IPID) {
	const char* vacStr[4] = {
		"������", "1������", "2������ �� 14�� �̰��", "�����Ϸ�"
	};
	printf("\n---- Ȯ����ID: %d�� ���������� ��ü �˻� ----\n", IPID);
	while (qt->nextQT != 0) {
		if(qt->ID != -1) {
			printf("QID: %d\n", qt->ID);
			printf("����̸�: %s , %s\n", qt->vaccineName, vacStr[qt->vaccination]);
			printf("\n");
		}
		qt = qt->nextQT;
	}
	printf("---- ���������� �˻� ���� ----\n\n");
}

//���������� 1�� ����
int QTremove(QT* qt, int QID) {
	QT* prevQT = qt; //���� QT������ �ӽ� ����
	qt = qt->nextQT; 
	while (qt->nextQT != 0) { 
		if (qt->ID == QID) {
			prevQT->nextQT = qt->nextQT;
			qt->nextQT = 0;
			free(qt);
			qt = 0;
			return 1;
		}
		prevQT = qt;
		qt = qt->nextQT;
	}
	return 0;
}

//���������� ��ü ���� 
void QTremoveAll(QT* qt) {
	if(qt->nextQT != 0) {
		QTremoveAll(qt->nextQT);
		qt->nextQT = 0;
	}
	free(qt);
	qt = 0;
}

#endif

