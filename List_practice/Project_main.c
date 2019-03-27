#include <stdio.h>
#include <string.h>

#define MAX_IOT_LIST_SIZE 45

typedef struct {
	char name[20]; //�̸�
	int id;	       //�й�
} Namecard;

Namecard iot_list[MAX_IOT_LIST_SIZE]; //����ü �迭
int length; //����Ʈ�� ���̸� ��Ÿ���� ��������

Namecard make_Namecard(char name[], int id) {
	Namecard newCard; //����ī�� ���� �Լ�

	strcpy(newCard.name, name);
	newCard.id = id;

	return newCard;
}

void init(void) { //length�� 0���� �ʱ�ȭ
	length = 0; //���μ��� ���� �� ���� ȣ��
}

void insert(int pos, Namecard item) {
	//����Ʈ�� ��ġ pos�� item ����
	//��, ������� 02�� ��Ұ� �ִµ� 02�� �־�޶�� ȣ�� �޾�����, ���� ���� �ڷ� ����

	if (is_full() == 0 && pos >= 0 && pos <= length) {
		//�迭�� �� á����, ���� ��ġ ���ɿ��� Ȯ��
		for (int i = length; i > pos; i--) { //���� ���� �ڷ� ������ ������
			iot_list[i] = iot_list[i - 1];
		}
		iot_list[pos] = item; //����
		length++;
	}
	else {
		printf("��ȭ���� ���� �� ���� ��ġ ���� �߻�\n");
	}
} //�ϼ�

void delete(int pos) { //����Ʈ���� ��ġ pos�� ���� ����
	if (is_empty() == 0 && pos >= 0 && pos <= length) {
		//�迭�� ����ִ��� , ���� ��ġ ���ɿ��� Ȯ��
		for (int i = pos; i < length; i++) { //���� �������� �迭 ������
			iot_list[i] = iot_list[i + 1]; //�� ���Ҹ� �տ� �����ϴ� ������
		}
		length--;
	}
	else {
		printf("���� ��ġ ���� �߻�\n");
	}
} //�ϼ�

Namecard get_entry(int pos) { //����Ʈ���� ��ġ pos�� ���� ��ȯ 

	if (is_empty() == 0 && pos >= 0 && pos <= length) {
		//�迭�� ����ִ���, ���� ��ġ ���� ���ɿ��� Ȯ��
		return iot_list[pos];
	}
	else {
		printf("���� ��ġ ���� �� ��ȯ ���� �߻�\n");
	}
} //�ϼ�

int is_empty(void) { //����Ʈ�� ��������� 1, �ƴϸ� 0 ����
	if (length == 0) {
		return 1;
	}
	else {
		return 0;
	}
} //�ϼ�

int is_full(void) { //����Ʈ�� ���� �������� 1, �ƴϸ� 0 ����
	if (length == MAX_IOT_LIST_SIZE) { //������ �ε��� == �迭 �ƽø�
		return 1;
	}
	else {
		return 0;
	}
} //�ϼ�

int find(Namecard item) { //item�� ����Ʈ ���� ������
	//�ش� item�� �ε����� ����, ������ -1 ����
	//name�� id�� ��� ��ġ�� ���� �ǹ���
	int check = 0;

	if (is_empty() == 0) {
		//�迭�� ����ִ��� Ȯ��
		for (int i = 0; i <= length; i++) {
			if (item.id == iot_list[i].id && !strcmp(item.name, iot_list[i].name)) {
				return i;
			}
		}
		return -1;
	}
	else {
		printf("����Ʈ ���� �� ���� �߻�\n");
	}
} //�ϼ�

void replace(int pos, Namecard item) {
	//����Ʈ�� ��ġ pos�� �ִ� ���Ҹ� item���� ��ü

	if (pos >= 0 && pos <= length && is_empty() == 0) {
		iot_list[pos] = item;
	}
	else {
		printf("��ü ��ġ ����\n");
	}
} //�ϼ�

int size(void) { //����Ʈ�� ���� ������ ����
	return length;
} //�ϼ�

void sort_list(void) { //�й��� ���� ������������ ����
	Namecard minCard = make_Namecard("name", 0);
	//�ּ� ī�带 ã�� ���� ����ü �����

	Namecard tempCard = make_Namecard("name", 0);
	//���� ������ �ϱ����� �ӽ� ���� (����ü)

	int k = 0;

	if (is_empty() == 0) {
		for (int i = 0; i < length; i++) {
			minCard = iot_list[i];
			k = 0;
			for (int j = i; k < length - i; k++) {
				if (minCard.id > iot_list[j].id) {
					tempCard = minCard;
					minCard = iot_list[j];
					iot_list[j] = tempCard;
				}
				j++;
			}
			iot_list[i] = minCard;
		}
	}
	else {
		printf("������ ����Ʈ�� �����ϴ�.");
	}
} //�ϼ�

void print_list(char *msg) { //����Ʈ�� ��� ���Ҹ� 
	//���� ������� ��� ex) msg: (�̸�,�й�)(�̸�,�й�)(�̸�,�й�)
	printf("%s : ", msg);
	for (int i = 0; i < length; i++) {
		printf("(%s ,%d) ", iot_list[i].name, iot_list[i].id);
	}
} //�ϼ�

int main(void) {
	init();
	print_list("Init");
	printf("\n");
	printf("\n");

	insert(0, make_Namecard("������", 20181512));
	insert(0, make_Namecard("������", 20181503));
	insert(1, make_Namecard("�ڼ���", 20181498));
	insert(size(), make_Namecard("�迬��", 20181531));
	insert(3, make_Namecard("������", 20181525));
	insert(size(), make_Namecard("������", 20181521));
	insert(10, make_Namecard("�̺���", 20181502));
	print_list("Insert");
	printf("\n\n");

	replace(size() - 1, make_Namecard("��°�", 20181508));
	replace(4, make_Namecard("���ȣ", 20181520));
	replace(20, make_Namecard("������", 20181504));
	print_list("Replace");
	printf("\n\n");


	delete(3);
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");
	printf("\n\n");


	sort_list();
	print_list("Sort");
	printf("\n\n");


	printf("%s is found at %d\n", "���ȣ", find(make_Namecard("���ȣ", 20181520)));
	printf("%s is found at %d\n", "������", find(make_Namecard("������", 20181499)));

	return 0;
}