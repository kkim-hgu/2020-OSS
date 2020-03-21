#include "members.h"

// 애플리케이션용 함수 원형
void create_record();
void read_record();
void update_record();
void delete_record();
void list_record();
void search_name();
void search_city();
void load_file();
void save_file();
void debug_records(); // for debug  
int main(){
    m_init();
    int menu;
    while(1){
        printf("\nMenu : 1.Create 2.Read 3.Update 4.Delete 5.List 6.Search(name) 7.Search(city) 8.Load 9.Save 0.Quit > ");
        scanf("%d", &menu);
        printf("\n");
        switch(menu){
            case 1: 
                create_record();
                break;
            case 2: 
                read_record();
                break;
            case 3: 
                update_record();
                break;
            case 4: 
                delete_record();
                break;
            case 5: 
                list_record();
                break;
            case 6: 
                search_name();
                break;
            case 7: 
                search_city();
                break;
            case 8: 
                load_file();
                break;
            case 9: 
                save_file();
                break;
            case 11: 
                debug_records();
                break;
            case 0: 
            default: 
                return 0;
        }
    }
    return 0;
}

void create_record(){
    if(!m_is_available()) {
        printf("There is no space!\n");
        return;
    }
    char name[20], phone[20], city[20];
    int year;  
    printf("Enter a new member's info.\n");
    printf("Name > ");
    scanf("%s", name);
    if(m_search_by_name(name)) {
        printf("Duplicated name!\n");
        return;
    }
    printf("Phone > ");
    scanf("%s", phone);
    printf("Birth year > ");
    scanf("%d", &year);
    printf("City > ");
    scanf("%s", city);
    m_create(name, phone, year, city);
}

void read_record(){
    char name[20];
    printf("Enter a name > ");
    scanf("%s", name);

    T_Record* p = m_search_by_name(name);
    if(p) {
        printf("Member info.\n");
        printf("Name : %s\n", m_getname(p));
        printf("Phone : %s\n", m_getphone(p));
        printf("Birth year : %d\n", m_getbirthyear(p));
        printf("City : %s\n", m_getcity(p));
    }
    else {
        printf("No such member!\n");
    }
}

void update_record(){
    char name[20], phone[20], city[20];
    int year;  
    printf("Enter a name > ");
    scanf("%s", name);

    T_Record* p = m_search_by_name(name);
    if(p) {
        printf("Enter a updated info.\n");
        printf("Phone > ");
        scanf("%s", phone);
        printf("Birth year > ");
        scanf("%d", &year);
        printf("City > ");
        scanf("%s", city);

        m_update(p, phone, year, city);
    }
    else {
        printf("No such member!\n");
    }
}

void delete_record(){
    char name[20];
    printf("Enter a name > ");
    scanf("%s", name);

    T_Record* p = m_search_by_name(name);
    if(p) {
        m_delete(p);
        printf("The record is deleted!\n");
    }
    else {
        printf("No such member!\n");
    }
}

void list_record(){
    // 전체 리스트 출력
    printf("All records.\n");
    int size = m_count();
    T_Record* records[MAX_MEMBERS];
    m_get_all(records);
    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        printf("%d. %s\n", i+1, m_to_string(p));
    }
}

void search_name(){
    //이름 일부문자열로 검색
    char name[20];
    printf("Enter a name > ");
    scanf("%s", name);

    T_Record* records[MAX_MEMBERS];
    int size = m_get_all_by_name(records, name);
    printf("%d records found.\n", size);
    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        printf("%d. %s\n", i+1, m_to_string(p));
    }
}
void search_city(){
    // 거주도시로 검색
    char name[20];
    printf("Enter a city > ");
    scanf("%s", name);

    T_Record* records[MAX_MEMBERS];
    int size = m_get_all_by_city(records, name);
    printf("%d records found.\n", size);
    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        printf("%d. %s\n", i+1, m_to_string(p));
    }
}
void load_file(){
    // 데이터파일 읽기
    printf("All data will be deleted and new records will be reloaded.\n");
    printf("1.Yes 0.No > ");
    int yesno;
    scanf("%d", &yesno);
    if (yesno == 0) return;
    m_init();   // 레코드 모두 제거 

    FILE* f = fopen("members.txt", "r");
    char name[20], phone[20], city[20];
    int year;  
    while(!feof(f)){
        if(!m_is_available()) {
            printf("[Load] There is no space!\n");
            break;
        }
        int n = fscanf(f,"%s %s %d %s", name, phone, &year, city);
        if (n<4) break;
        if(m_search_by_name(name)) {
            printf("[Load] Duplicated name(%s)! loading.\n", name);
            continue;
        }
        m_create(name, phone, year, city);
        //printf("[Load] load %s\n", name);
    }
    printf("%d records are read from file!\n", m_count());    
    fclose(f);
}

void save_file(){
    // 데이터파일 저장
    FILE* f = fopen("members.txt", "w");
    printf("All records.\n");
    int size = m_count();
    T_Record* records[MAX_MEMBERS];
    m_get_all(records);
    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        fprintf(f,"%s\n", m_to_string_save(p));
    }
    fclose(f);
}
  
void debug_records(){
    // for debug  
    T_Record* records[MAX_MEMBERS]={0};
    m_get_all2(records);
    for(int i=0; i<MAX_MEMBERS; i++){
        printf("%d - %p\n",i, records[i]);
    }    
}
