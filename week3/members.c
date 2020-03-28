#include "members.h"

T_Record* members[MAX_MEMBERS]; // 회원정보데이터 (전역)
int _count = 0;

int m_is_available(){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(members[i]==NULL) return 1;
    }
    return 0;
}

int m_first_available(){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(members[i]==NULL) return i;
    }
    return -1;
}

int m_count(){
    return _count;
}

void m_create(char* n, char* ph, int b, char* c){
    int index = m_first_available();
    members[index] = (T_Record*)malloc(sizeof(T_Record));
    T_Record* p = members[index];
    strcpy(p->name, n);  
    strcpy(p->phone, ph);
    p->birthyear = b;
    strcpy(p->city, c);
    _count++;
}

T_Record* m_search_by_name(char* n){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(members[i]!=NULL && strcmp(members[i]->name, n)==0) return members[i];
    }
    return NULL;
}

void m_update(T_Record* p, char* ph, int b, char* c){
    strcpy(p->phone, ph);
    p->birthyear = b;
    strcpy(p->city, c);
}

void m_delete(T_Record* p){
    int i, index;
    for(i=0; i<MAX_MEMBERS; i++)
        if(members[i]==p) {
            index=i;
            break;
        }
    free(p);
    members[index] = NULL;
    _count--;
}

char* m_to_string(T_Record* p){
    static char str[80];
    sprintf(str, "[%d] %s / %s / %s", p->birthyear, p->name, p->phone, p->city);
    return str;
}

void m_get_all(T_Record* a[]){
    int i, c=0;
    for(i=0; i<MAX_MEMBERS; i++){
        if(members[i]!=NULL){
            a[c]=members[i];
            c++;
        }
    }
}

void m_get_all2(T_Record* a[]){
    int i, c=0;
    for(i=0; i<MAX_MEMBERS; i++){
        a[i]=members[i];
    }
}

char* m_getname(T_Record* p){
    return p->name;
}

char* m_getphone(T_Record* p){
    return p->phone;
}

int m_getbirthyear(T_Record* p){
    return p->birthyear;
}

char* m_getcity(T_Record* p){
    return p->city;
}

int m_get_all_by_name(T_Record* a[], char* n){
    // 회원이름에 문자열이 포함된 모든 레코드 포인터의 배열 만들기    
    int i, c=0;
    for(i=0; i<MAX_MEMBERS; i++){
        if(members[i]!=NULL && strstr(members[i]->name, n)){
            a[c]=members[i];
            c++;
        }
    }
    return c;
} 

int m_get_all_by_city(T_Record* a[], char* n){
    // 회원거주도시가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
    int i, c=0;
    for(i=0; i<MAX_MEMBERS; i++){
        if(members[i]!=NULL && (strcmp(members[i]->city, n)==0)){
            a[c]=members[i];
            c++;
        }
    }
    return c;
}

void m_init(){
    // 모든 레코드 제거    
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(members[i]!=NULL) {
            free(members[i]);
        }
        members[i] = NULL;
    }
    _count = 0;

} 

char* m_to_string_save(T_Record* p){
    static char str[80];
    sprintf(str, "%s %s %d %s", p->name, p->phone, p->birthyear, p->city);
    return str;
}
