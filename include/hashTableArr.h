#ifndef HASHTABLEARR_H
#define HASHTABLEARR_H

#include <malloc.h>
#include <stdio.h>
#include "./stringLib.h" 

typedef struct InfectedPerson {
	int ID;
	int gender; //0==����, 1==����
	int age;
	char region[50]; //����
} IP;



///// �Լ� ���� /////
int IParrSize(IP* ip);
void IPpush(IP* ip, int ID, int gender, int age, char* region);
void IPsearch(IP* ip, int ID);
void IPinit(IP* ip, int start, int end);
IP* tableSizeUP(IP* arr, int size);
IP* tableSizeDown(IP* arr, int size);



///// �Լ� �ۼ� /////
int IParrSize(IP* ip) {
	return _msize(ip) / sizeof(IP);
}

void IPinit(IP* ip, int start, int end) {
	while (start < end) {
		ip[start].ID = -1;
		start++;
	}
}

void IPpush(IP* ip, int ID, int gender, int age, char* region) {
	ip->ID = ID; 
	ip->gender = gender;
	ip->age = age;
	ct_strcpy(ip->region, region);
}

void IPsearch(IP* ip, int ID) {
	if (ID == 0) {
		printf("\n---- Ȯ���� ��ü �˻� ----\n");
		int size = IParrSize(ip);
		int i = 1;
		while (i < size) {
			printf("ID: %d\n", ip[i].ID);
			printf("gender: %d\n", ip[i].gender);
			printf("age: %d\n", ip[i].age);
			printf("region: %s\n", ip[i].region);
			if (ip[i].ID + 1 != ip[i+1].ID)
				break;
			printf("\n"); 
			i++;
		}
	}
	else {
		//������ �ƿ� �ȵ� ���ų� ������ ������ �����Ͱ� ���� ������� 
		if(ip[ID].ID == -1 || ID < 0 || ID >= IParrSize(ip)){
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
	printf("\n ������ ���� \n");
	free(arr);
	arr = '\0';
	arr = (IP*)malloc(size + (10 * sizeof(IP)));
	IPinit(arr, size, size + 10);
	return arr;
}

IP* tableSizeDown(IP* arr, int size) {
	free(arr);
	arr = '\0';
	arr = (IP*)malloc(size - (10 * sizeof(IP)));
	return arr;
}

#endif

