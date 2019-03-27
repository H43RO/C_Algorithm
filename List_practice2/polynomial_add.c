#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {
	int degree;             //차수
	float coef[MAX_DEGREE]; //방정식
} polynomial;

polynomial addPoly(polynomial A, polynomial B) {
	polynomial C; //다항식 덧셈결과를 담을 구조체 변수
	int A_index =0 , B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A_degree, B_degree);

	while (A_index <= A.degree && B_index <= B.degree) {
		if (A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}

		else if (A_degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}

		else { // (B.degree > A.degree)
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;
}



int main(void) {
	polynomial A, B;

	printf("A 방정식의 차수를 입력하세요 : ");
	scanf("%d", &A.degree);
	for (int i = A.degree; i >= 0; i--) {
		printf("%d차 계수를 입력하세요 : ", i);
		scanf("%f", &A.coef[A.degree-i]);
	}

	printf("B 방정식의 차수를 입력하세요 : ");
	scanf("%d", &B.degree);
	for (int i = B.degree; i >= 0; i--) {
		printf("%d차 계수를 입력하세요 : ", i);
		scanf("%f", &B.coef[B.degree - i]);
	}

	polynomial C = addPoly(A, B);

	printf("A(x)= ");
	for (int i = 0; i <= A.degree; i++) {
		if (i == A.degree) {
			printf("%0.fx^%d\n", A.coef[i], A.degree-i);
			break;
		}
		printf("%0.fx^%d +", A.coef[i], A.degree - i);
	}

	printf("B(x)= ");
	for (int i = 0; i <= B.degree; i++) {
		if (i == B.degree) {
			printf("%0.fx^%d\n", B.coef[i], B.degree - i);
			break;
		}
		printf("%0.fx^%d +", B.coef[i], B.degree - i);
	}

	printf("C(x)= ");
	for (int i = 0; i <= C.degree; i++) {
		if (i == C.degree) {
			printf("%0.fx^%d\n", C.coef[i], C.degree - i);
			break;
		}
		printf("%0.fx^%d +", C.coef[i], C.degree - i);
	}
	

	return 0;
}