#ifndef HASHTABLEARR_H
#define HASHTABLEARR_H

#include <malloc.h>
#include <stdio.h>
#include "./quarantine.h"
#include "./stringLib.h" 

typedef struct InfectedPerson {
	int ID;
	int gender; //0: ����, 1: ����
	int age;
	char region[50]; //����
	QT* qurantineList; //���������� ����Ʈ 
} IP;



///// �Լ� ���� /////
int IParrSize(IP* ip);
void IPpush(IP* ip, int ID, int gender, int age, char* region);
int IPsearch(IP* ip, int ID);
void IPsearchView(IP* ip, int ID);
void IPinit(IP* ip, int start, int end);
IP* tableSizeUP(IP* arr, int size);
IP* tableSizeDown(IP* arr, int size);
void IParrCpy(IP* dest, IP* src, int size);



///// �Լ� �ۼ� /////
int IParrSize(IP* ip) {
	return _msize(ip) / sizeof(IP);
}

void IPinit(IP* ip, int start, int end) {
	while (start < end) {
		//���������� ����Ʈ 1 ũ�� �Ҵ� 
		//printf("%d�� QTsize: %d\n", start, _msize(ip[start].qurantineList));
		ip[start].ID = -1;
		ip[start].qurantineList = (QT*)malloc(sizeof(QT));
		//qurantine init
		ip[start].qurantineList->ID = -1;
		ip[start].qurantineList->nextQT = '\0';
		start++;
	}
}

void IPpush(IP* ip, int ID, int gender, int age, char* region) {
	ip->ID = ID; 
	ip->gender = gender;
	ip->age = age;
	ct_strcpy(ip->region, region);
}

int IPsearch(IP* ip, int ID) {
	//������ �ƿ� �ȵ� ���ų� ������ ������ �����Ͱ� ���� �������
	if(ip[ID].ID == -1 || ID <= 0 || ID >= IParrSize(ip)){
		return 0; //������ ������ (�˻� �Ұ�) 
	}
	else {
		return 1; //������ ���� 
	}
}

void IPsearchView(IP* ip, int ID) {
	if (ID == 0) {
		printf("\n---- Ȯ���� ��ü �˻� ----\n");
		int size = IParrSize(ip);
		int i = 1;
		while (i <= size) {
			if (ip[i].ID != -1) {
				printf("ID: %d\n", ip[i].ID);
				printf("gender: %d\n", ip[i].gender);
				printf("age: %d\n", ip[i].age);
				printf("region: %s\n", ip[i].region);
			}
			if (ip[i].ID + 1 != ip[i+1].ID)
				break;
			printf("\n"); 
			i++;
		}
	}
	else {
		int searchResult = IPsearch(ip, ID);
		if(!searchResult){
			printf("\nȮ���ڰ� �������� �ʽ��ϴ�.\n");
		}
		else {
			printf("\n---- Ȯ���� ID: %d �˻� ----\n", ip[ID].ID);
			printf("gender: %d\n", ip[ID].gender);
			printf("age: %d\n", ip[ID].age);
			printf("region: %s\n", ip[ID].region);
		}
	}
	printf("---- Ȯ���� �˻� ���� ----\n\n");
}

IP* tableSizeUP(IP* arr, int size) {
	IP tmpSrc[11];
	IParrCpy(tmpSrc, arr, 10);
	free(arr);
	arr = '\0';
	arr = (IP*)malloc(size + (10 * sizeof(IP)));
	IParrCpy(arr, tmpSrc, 10); //������ �ø� �迭�� �ٽ� ���� ������ ����
	IPinit(arr, size, size + 10);
	return arr;
}

/* tableSizeUPó�� �迭����� ������ Down��Ű�� */
IP* tableSizeDown(IP* arr, int size) {
	free(arr);
	arr = '\0';
	arr = (IP*)malloc(size - (10 * sizeof(IP)));
	return arr;
}

void IParrCpy(IP* dest, IP* src, int size) {
	int i = 1;
	while (src[i].ID != -1 || i < size) {
		if (src[i-1].ID + 1 != src[i].ID && i != 1)
			break;
		dest[i].ID = src[i].ID;
		dest[i].gender = src[i].gender;
		dest[i].age = src[i].age;
		ct_strcpy(dest[i].region, src[i].region);
		dest[i].qurantineList = src[i].qurantineList;
		i++;
	}
}

#endif

