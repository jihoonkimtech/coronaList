#include <stdio.h>
#include "./include/hashTableArr.h"
#include "./include/stringLib.h"

void tmpScan(int* gender, int *age, char region[50]) {
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
	int gender;
	int age;
	char region[50];
	
	int index = 1;
	while (index < 5) {
		printf("%d: ", index);
		tmpScan(&gender, &age, region);
		//Ȯ���ڸ� �߰��ҷ��µ�
		//�迭�� �����Ͱ� ��á�ٸ�
		//�迭�� ũ�⸦ �ø�
		if (index >= IParrSize(IPtable)) {
			tableSizeUP(IPtable, _msize(IPtable));
		}
		IPpush(&IPtable[index], index, gender, age, region);
		IPsearch(IPtable, index);
		index++;
	}
	IPsearch(IPtable, -1); //��ü �˻� 
	
	return 0;
}
