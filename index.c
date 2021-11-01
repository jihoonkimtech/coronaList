#include <stdio.h>
#include "./include/hashTableArr.h"
#include "./include/stringLib.h"

void dataScan(int* gender, int *age, char region[50]) {
	printf("Ȯ������ ������ �Է����ּ���.\n");
	printf("gender: ");
	scanf("%d", gender);
	getchar(); //�Է¹��� ����
	printf("age: ");
	scanf("%d", age);
	getchar(); //�Է¹��� ���� 
	printf("region: ");
	scanf("%s", region);
	getchar(); //�Է¹��� ����
}

int main(int argc, char** argv) {
	IP* IPtable = (IP*)malloc(2 * sizeof(IP));
	IPinit(IPtable, 0, 2);
	char order;
	int IPpushIndex = 1;

	printf("[�ֹ�] 0: ���α׷� ����, 1: Ȯ���� �߰�, 2: Ȯ���� �˻�\n");
	while (1) {
		printf("[�ֹ�]: ");
		scanf("%c", &order);
		getchar(); //�Է¹��� ����
		if (order == '0') { //���α׷� ����
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
		else if (order == '1') {  // ������ �߰�
			int gender;
			int age;
			char region[50];
			
			dataScan(&gender, &age, region);
			//Ȯ���ڸ� �߰��ҷ��µ�
			//�迭�� �����Ͱ� ��á�ٸ�
			//�迭�� ũ�⸦ �ø�
			if (IPpushIndex >= IParrSize(IPtable)) {
				printf("%d\n", IParrSize(IPtable));
				tableSizeUP(IPtable, _msize(IPtable));
			}
			IPpush(&IPtable[IPpushIndex], IPpushIndex, gender, age, region);
			IPpushIndex++;			
		}
		else if (order == '2') { // ������ �˻�
			int searchIndex;
			printf("�˻��� ID�� �Է����ּ���. (0 �Է½� ��ü �˻��� �˴ϴ�.)\n");
			printf("ID: ");
			scanf("%d", &searchIndex);
			getchar(); //�Է¹��� �����
			IPsearch(IPtable, searchIndex);
		}
		else {
			printf("�ٽ� �Է����ּ���.\n");
		}
	}
	
	return 0;
}
