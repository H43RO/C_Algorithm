#include <stdio.h>
#include <string.h>

#define MAX_IOT_LIST_SIZE 45

typedef struct {
	char name[20]; //이름
	int id;	       //학번
} Namecard;

Namecard iot_list[MAX_IOT_LIST_SIZE]; //구조체 배열
int length; //리스트의 길이를 나타내는 전역변수

Namecard make_Namecard(char name[], int id) {
	Namecard newCard; //네임카드 생성 함수

	strcpy(newCard.name, name);
	newCard.id = id;

	return newCard;
}

void init(void) { //length를 0으로 초기화
	length = 0; //프로세스 시작 시 마다 호출
}

void insert(int pos, Namecard item) {
	//리스트의 위치 pos에 item 삽입
	//단, 예를들어 02번 요소가 있는데 02에 넣어달라고 호출 받았을때, 이전 값을 뒤로 물림

	if (is_full() == 0 && pos >= 0 && pos <= length) {
		//배열이 꽉 찼는지, 지정 위치 가능여부 확인
		for (int i = length; i > pos; i--) { //이전 값을 뒤로 물리는 시퀀스
			iot_list[i] = iot_list[i - 1];
		}
		iot_list[pos] = item; //삽입
		length++;
	}
	else {
		printf("포화상태 오류 및 삽입 위치 오류 발생\n");
	}
} //완성

void delete(int pos) { //리스트에서 위치 pos의 원소 삭제
	if (is_empty() == 0 && pos >= 0 && pos <= length) {
		//배열이 비어있는지 , 지정 위치 가능여부 확인
		for (int i = pos; i < length; i++) { //삭제 지점부터 배열 끝까지
			iot_list[i] = iot_list[i + 1]; //뒷 원소를 앞에 대입하는 시퀀스
		}
		length--;
	}
	else {
		printf("삭제 위치 오류 발생\n");
	}
} //완성

Namecard get_entry(int pos) { //리스트에서 위치 pos의 원소 반환 

	if (is_empty() == 0 && pos >= 0 && pos <= length) {
		//배열이 비어있는지, 지정 위치 참조 가능여부 확인
		return iot_list[pos];
	}
	else {
		printf("참조 위치 오류 및 반환 오류 발생\n");
	}
} //완성

int is_empty(void) { //리스트가 비어있으면 1, 아니면 0 리턴
	if (length == 0) {
		return 1;
	}
	else {
		return 0;
	}
} //완성

int is_full(void) { //리스트가 가득 차있으면 1, 아니면 0 리턴
	if (length == MAX_IOT_LIST_SIZE) { //포인팅 인덱스 == 배열 맥시멈
		return 1;
	}
	else {
		return 0;
	}
} //완성

int find(Namecard item) { //item이 리스트 내에 있으면
	//해당 item의 인덱스를 리턴, 없으면 -1 리턴
	//name과 id가 모두 일치한 것을 의미함
	int check = 0;

	if (is_empty() == 0) {
		//배열이 비어있는지 확인
		for (int i = 0; i <= length; i++) {
			if (item.id == iot_list[i].id && !strcmp(item.name, iot_list[i].name)) {
				return i;
			}
		}
		return -1;
	}
	else {
		printf("리스트 공백 및 오류 발생\n");
	}
} //완성

void replace(int pos, Namecard item) {
	//리스트의 위치 pos에 있는 원소를 item으로 교체

	if (pos >= 0 && pos <= length && is_empty() == 0) {
		iot_list[pos] = item;
	}
	else {
		printf("교체 위치 오류\n");
	}
} //완성

int size(void) { //리스트의 원소 개수를 리턴
	return length;
} //완성

void sort_list(void) { //학번에 따라 오름차순으로 정렬
	Namecard minCard = make_Namecard("name", 0);
	//최소 카드를 찾기 위한 구조체 만들기

	Namecard tempCard = make_Namecard("name", 0);
	//선택 정렬을 하기위한 임시 변수 (구조체)

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
		printf("정렬할 리스트가 없습니다.");
	}
} //완성

void print_list(char *msg) { //리스트의 모든 원소를 
	//다음 양식으로 출력 ex) msg: (이름,학번)(이름,학번)(이름,학번)
	printf("%s : ", msg);
	for (int i = 0; i < length; i++) {
		printf("(%s ,%d) ", iot_list[i].name, iot_list[i].id);
	}
} //완성

int main(void) {
	init();
	print_list("Init");
	printf("\n");
	printf("\n");

	insert(0, make_Namecard("김현준", 20181512));
	insert(0, make_Namecard("강병훈", 20181503));
	insert(1, make_Namecard("박선균", 20181498));
	insert(size(), make_Namecard("김연주", 20181531));
	insert(3, make_Namecard("이진우", 20181525));
	insert(size(), make_Namecard("강현익", 20181521));
	insert(10, make_Namecard("이병우", 20181502));
	print_list("Insert");
	printf("\n\n");

	replace(size() - 1, make_Namecard("김승겸", 20181508));
	replace(4, make_Namecard("장경호", 20181520));
	replace(20, make_Namecard("윤병수", 20181504));
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


	printf("%s is found at %d\n", "장경호", find(make_Namecard("장경호", 20181520)));
	printf("%s is found at %d\n", "서영훈", find(make_Namecard("서영훈", 20181499)));

	return 0;
}