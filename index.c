#include <stdio.h>
#include "./include/hashTableArr.h"
#include "./include/stringLib.h"
#include "./include/quarantine.h" 

//Ȯ���� �߰��� Ȯ���� ���� �Է� �Լ� 
void IPscan(int* gender, int *age, char region[50]) {
	printf("Ȯ������ ������ �Է����ּ���.\n");
	printf("gender (0:����, 1:����): ");
	scanf("%d", gender);
	getchar(); //�Է¹��� ����
	printf("age: ");
	scanf("%d", age);
	getchar(); //�Է¹��� ���� 
	printf("region: ");
	scanf("%s", region);
	getchar(); //�Է¹��� ����
}

//���������� �߰��� ���������� ���� �Է� �Լ�
int QTscan(IP* ip, int* IPID, char* vaccineName, int* vaccination) {
	printf("������������ ������ �Է����ּ���.\n");
	//Ȯ����ID �Է�
	int tmpIPID;
	printf("Ȯ����ID: ");
	scanf("%d", &tmpIPID);
	getchar();
	if (IPsearch(ip, tmpIPID)) { //Ȯ���ڰ� �����Ѵٸ� 
		*IPID = tmpIPID;
	}
	else {
		printf("Ȯ���ڰ� �������� �ʽ��ϴ�. �ٽ� �Է����ֽʽÿ�.\n");
		return 0;
	}
	printf("��� ���� ���� (0: ������, 1: 1������, 2: 2������ �� 14�� �̰��, 3: �����Ϸ�): ");
	scanf("%d", vaccination);
	getchar(); //�Է¹��� ����
	if (*vaccination != 0) {
		printf("��� �̸�: ");
		scanf("%s", vaccineName);
		getchar(); //�Է¹��� ���� 
	}
	return 1;
} 

///// ���� �Լ� ///// 
int main(int argc, char** argv) {
	IP* IPtable = (IP*)malloc(2 * sizeof(IP));
	IPinit(IPtable, 0, 2);
	char order;
	int IPpushIndex = 1;

	printf("[�ֹ�] 0: ���α׷� ����, 1: Ȯ���� �߰�, 2: Ȯ���� �˻�, 3: Ȯ���� ����\n");
	printf("       4: ���������� �߰�, 5: ���������� �˻�\n");
	while (1) {
		printf("\n[�ֹ�]: ");
		scanf("%c", &order);
		getchar(); //�Է¹��� ����
		if (order == '0') { //���α׷� ����
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
		else if (order == '1') {  // Ȯ���� �߰�
			int gender;
			int age;
			char region[50];
			IPscan(&gender, &age, region);
			//Ȯ���ڸ� �߰��ҷ��µ�
			//�迭�� ũ�Ⱑ �����ϸ� sizeup 
			if (IPpushIndex >= IParrSize(IPtable)) {
				IPtable = tableSizeUP(IPtable, IParrSize(IPtable));
			}
			IPpush(&IPtable[IPpushIndex], IPpushIndex, gender, age, region);
			IPpushIndex++;
		}
		else if (order == '2') { // Ȯ���� �˻�
			int searchIndex;
			printf("�˻��� ID�� �Է����ּ���. (0 �Է½� ��ü �˻��� �˴ϴ�.): ");
			scanf("%d", &searchIndex);
			getchar(); //�Է¹��� �����
			IPsearchView(IPtable, searchIndex);
		}
		else if (order == '3') {
			printf("Ȯ���� ���� ���� �̱���\n");
		}
		else if (order == '4') { //���������� �߰�
			int IPID; //��� Ȯ������ �������������� 
			char vaccineName[20] = "����";
			int vaccination;
			int scanRes = QTscan(IPtable, &IPID, vaccineName, &vaccination);
			if (scanRes) {
				//��ũ�帮��Ʈ�� �߰��Ҷ����� �ϳ��� ����� �÷���
				QTpush(IPtable[IPID].qurantineList, vaccineName, vaccination);
			}
		}
		else if (order == '5') { //���������� �˻�
			//���������ڴ� ��ü �˻����� ����
			int inputID;
			printf("���������ڸ� �˻��Ϸ��� Ȯ����ID �Է�: ");
			scanf("%d", &inputID);
			getchar();
			if (IPsearch(IPtable, inputID)) { //Ȯ���ڰ� �����Ѵٸ� 
				QTsearchView(IPtable[inputID].qurantineList, inputID);
			}
		}
		else {
			printf("�ٽ� �Է����ּ���.\n");
		}
	}
	
	return 0;
}
