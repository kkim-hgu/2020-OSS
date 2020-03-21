#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 5      // 저장할 수 있는 회원 레코드 최대 갯수

// 회원 정보 레코드의 데이터 타입을 정의함
typedef struct st_member{
    char name[20];  // 회원이름
    char phone[20]; // 회원전화번호
    int birthyear;  // 회원생년
    char city[20];  // 회원거주도시
} T_Record;

// 라이브러리 함수 원형을 선언함
int m_is_available();       // 현재 추가할 수 있는 데이터 공간이 있는가?
int m_first_available();    // 추가할 수 있는 가장 빠른 포인터 배열의 인덱스 찾기
int m_count();              // 현재 저장된 회원 레코드의 갯수 가져오기
void m_create(char* n, char* ph, int b, char* c);   // 회원정보로 신규 회원 레코드 추가
T_Record* m_search_by_name(char* n);                // 이름이 일치하는 회원 레코드 포인터 찾기
void m_update(T_Record* p, char* ph, int b, char* c);  // 특정 회원 레코드의 정보 업데이트
void m_delete(T_Record* p);     // 특정 회원 레코드의 회원정보 제거
void m_get_all(T_Record* a[]);  // 회원정보가 들어있는 모든 레코드 포인터의 배열을 만들기
void m_get_all2(T_Record* a[]);  // 모든 레코드 포인터의 배열을 만들기 (for debug)
char* m_to_string(T_Record* p); // 특정 회원 레코드의 내용을 문자열로 가져오기
char* m_getname(T_Record* p);   // 특정 회원 레코드의 회원이름 가져오기
char* m_getphone(T_Record* p);  // 특정 회원 레코드의 회원전화번호 가져오기
int m_getbirthyear(T_Record* p);// 특정 회원 레코드의 회원생년 가져오기
char* m_getcity(T_Record* p);   // 특정 회원 레코드의 회원거주도시 가져오기
int m_get_all_by_name(T_Record* a[], char* n);  // 회원이름에 문자열이 포함된 모든 레코드 포인터의 배열 만들기 
int m_get_all_by_city(T_Record* a[], char* n);  // 회원거주도시가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
void m_init(); // 모든 레코드 제거
char* m_to_string_save(T_Record* p); // 특정 회원 레코드의 내용을 파일저장용 문자열로 가져오기
