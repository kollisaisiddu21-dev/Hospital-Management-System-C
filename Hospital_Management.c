#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct patient{
    int id;
    char name[30];
    int age;
    char gender[10];
    long long int num;
    char disease[30];
    char blood_group[10];
    struct patient* next;
}patient_node;
typedef struct doctor{
    int id;
    char name[30];
    char gender[10];
    int age;
    char spl[20];
    int exp;
    long long int num;
    int fee;
    struct doctor* next;
}doctor_node;
patient_node* patient_menu(patient_node* patient_head);
patient_node* patient_create(patient_node* patient_head);
patient_node* patient_add(patient_node* patient_head);
void patient_display(patient_node* patient_head);
void patient_search_id(patient_node* patient_head);
void patient_search_name(patient_node* patient_head);
patient_node* patient_update(patient_node* patient_head);
patient_node* patient_del_id(patient_node* patient_head);
void patient_stats(patient_node* patient_head);
void patient_free_ll(patient_node* patient_head);
int patient_check_id(patient_node* patient_head,int k);
doctor_node* doctor_menu(doctor_node* doctor_head);
doctor_node* doctor_create(doctor_node* doctor_head);
doctor_node* doctor_add(doctor_node* doctor_head);
void doctor_display(doctor_node* doctor_head);
void doctor_search_id(doctor_node* doctor_head);
void doctor_search_name(doctor_node* doctor_head);
doctor_node* doctor_update(doctor_node* doctor_head);
doctor_node* doctor_del_id(doctor_node* doctor_head);
void doctor_stats(doctor_node* doctor_head);
void doctor_free_ll(doctor_node* doctor_head);
int doctor_check_id(doctor_node* doctor_head,int k);
int main(){
    patient_node* patient_head=NULL;
    doctor_node* doctor_head=NULL;
    while(1){
        printf("|| HOSPITAL MANAGEMENT SYSTEM ||\n 1.Patient Management\n 2.Doctor Management\n 3.Hospital Statistics\n 4.Exit\n");
        printf("Enter Choice : ");
        int c;scanf("%d",&c);
        switch(c){
            case 1:patient_head=patient_menu(patient_head);break;
            case 2:doctor_head=doctor_menu(doctor_head);break;
            case 3:patient_stats(patient_head);doctor_stats(doctor_head);break;
            case 4:patient_free_ll(patient_head);doctor_free_ll(doctor_head); return 0;
            default:printf("Invalid Choice!! Enter Again\n");
        }
    }
}
patient_node* patient_menu(patient_node* patient_head){
    while(1){
        printf("|| Patients MANAGEMENT SYSTEM ||\n 1.Add Patient\n 2.Display All Patients\n 3.Search Patient by ID\n 4.Search Patient by Name\n 5.Update Patient Details\n 6.Delete Patient\n 7.Display Stats\n 8.Return to Main Menu\n");
        printf("Enter Choice : ");
        int c;scanf("%d",&c);
        switch(c){
            case 1:patient_head=patient_add(patient_head); break;
            case 2:patient_display(patient_head); break;
            case 3:patient_search_id(patient_head); break;
            case 4:patient_search_name(patient_head); break;
            case 5:patient_head=patient_update(patient_head); break;
            case 6:patient_head=patient_del_id(patient_head); break;
            case 7:patient_stats(patient_head); break;
            case 8:return patient_head;
            default: printf("Invalid Choice!! Enter Again\n");
        }
    }
}
patient_node* patient_create(patient_node* patient_head){
    patient_node* t=(patient_node*)malloc(sizeof(patient_node));
    if(t==NULL){
        printf("Memory not allocated!! Returning to main!");
        return NULL;
    }
    printf("Enter Details:\n");
    printf("Enter Id: ");scanf("%d",&t->id);
    while(t->id<=0){
        printf("Invalid Id!!");
        printf("Enter Id Again: ");scanf("%d",&t->id);
    }
    while(patient_check_id(patient_head,t->id)){
        printf("ID Already Allocated!!");
        printf("Enter Id Again: ");scanf("%d",&t->id);
    }
    printf("Enter Name: ");scanf(" %29[^\n]",t->name);
    printf("Enter Age: ");scanf("%d",&t->age);
    while(t->age<=0){
        printf("Invalid Age!!");
        printf("Enter Age Again: ");scanf("%d",&t->age);
    }
    printf("Enter Gender: ");scanf(" %9[^\n]",t->gender);
    printf("Enter Mobile Number: ");scanf("%lld",&t->num);
    while(t->num<6000000000||t->num>9999999999){
        printf("Invalid Mobile Number!!");
        printf("Enter Number Again: ");scanf("%lld",&t->num);
    }
    printf("Enter Disease: ");scanf(" %29[^\n]",t->disease);
    printf("Enter Blood Group: ");scanf(" %9[^\n]",t->blood_group);
    t->next=NULL;
    return t;
}
patient_node* patient_add(patient_node* patient_head){
    patient_node* t=patient_create(patient_head);
    if(t==NULL) return patient_head;
    if(patient_head==NULL){
        printf("Patient Added Successfully!\n");
        return t;
    }
    patient_node* c=patient_head;
    while(c->next!=NULL) c=c->next;
    c->next=t;
    printf("Patient Added Successfully!\n");
    return patient_head;
}
void patient_display(patient_node* patient_head){
    if(patient_head==NULL){
        printf("No Details Available!!\n");
        return;
    }
    patient_node* c=patient_head;
    printf("|| PATIENT DETAILS ||\n");
    printf("ID\t\tName\t\tAge\t\tGender\t\tNumber\t\tDisease\t\tBlood Group\n");
    while(c!=NULL){
        printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%s\n",c->id,c->name,c->age,c->gender,c->num,c->disease,c->blood_group);
        c=c->next;
    }
}
void patient_search_id(patient_node* patient_head){
    if(patient_head==NULL){
        printf("No Details Available!!\n");
        return;
    }
    int flag=1;
    patient_node* c=patient_head;
    printf("Enter the Patient ID you want to search: ");
    int k;scanf("%d",&k);
    while(c!=NULL){
        if(c->id==k){
            flag=0;
            printf("|| PATIENT DETAILS ||\n");
            printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%s\n",c->id,c->name,c->age,c->gender,c->num,c->disease,c->blood_group);
            break;
        }
        c=c->next;
    }
    if(flag){
        printf("No Records with given ID!!\n");
    }
}
void patient_search_name(patient_node* patient_head){
    if(patient_head==NULL){
        printf("No Details Available!!\n");
        return;
    }
    int flag=1;
    patient_node* c=patient_head;
    printf("Enter the Patient Name you want to search: ");
    char tname[30];scanf(" %29[^\n]",tname);
    while(c!=NULL){
        if(!strcmp(c->name,tname)){
            flag=0;
            printf("|| PATIENT DETAILS ||\n");
            printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%s\n",c->id,c->name,c->age,c->gender,c->num,c->disease,c->blood_group);
            break;
        }
        c=c->next;
    }
    if(flag){
        printf("No Records with given Name!!\n");
    }
}
patient_node* patient_update(patient_node* patient_head){
    if(patient_head==NULL){
        printf("No Details Available!!\n");
        return patient_head;
    }
    printf("Enter the Patient ID you want to update : ");
    int k;scanf("%d",&k);
    patient_node* c=patient_head;
    int flag=1;
    while(c!=NULL){
        if(c->id==k){
            printf("Enter the new details:\n Name : ");scanf(" %29[^\n]",c->name);
            printf("Age: ");scanf("%d",&c->age);
            while(c->age<=0){
                printf("Invalid Age!!");
                printf("Enter Age Again: ");scanf("%d",&c->age);
            }
            printf("Mobile Number: ");scanf("%lld",&c->num);
            while(c->num<6000000000||c->num>9999999999){
                printf("Invalid Mobile Number!!");
                printf("Enter Number Again: ");scanf("%lld",&c->num);
            }
            printf("Disease: ");scanf(" %29[^\n]",c->disease);
            printf("Blood Group: ");scanf(" %9[^\n]",c->blood_group);
            printf("Successfully Updated!!\n");
            flag=0;
            break;
        }
        c=c->next;
    }
    if(flag){
        printf("No Records with the given ID!!\n");
    }
    return patient_head;
}
patient_node* patient_del_id(patient_node* patient_head){
    if(patient_head==NULL){
        printf("No Details Available!!\n");
        return patient_head;
    }
    printf("Enter the Patient ID you want to delete : ");
    int k;scanf("%d",&k);
    if(patient_head->next==NULL && patient_head->id==k){
        free(patient_head);
        printf("Deleted!!\n");
        return NULL;
    }
    patient_node* c=patient_head;
    int flag=1;
    if(patient_head->id==k){
        patient_head=patient_head->next;
        free(c);
        printf("Deleted!!\n");
        return patient_head;
    }
    patient_node* p=NULL;
    while(c!=NULL){
        if(c->id==k){
            p->next=c->next;
            free(c);
            printf("Deleted!!\n");
            flag=0;
            break;
        }
        p=c;
        c=c->next;
    }
    if(flag){
        printf("No Records with the given ID!!\n");
    }
    return patient_head;
}
void patient_stats(patient_node* patient_head){
    if(patient_head==NULL){
        printf("No Patient Details Available!!\n");
        return;
    }
    int count,male_count,female_count,child,adult,old;
    count=male_count=female_count=child=adult=old=0;
    patient_node* c=patient_head;
    while(c!=NULL){
        count++;
        if(!strcmp(c->gender,"Male")) male_count++;
        else if(!strcmp(c->gender,"Female")) female_count++;
        if(c->age<18) child++;
        else if(c->age>=18 && c->age<60) adult++;
        else old++;
        c=c->next;
    }

    printf("PATIENT STATISTICS:\n");
    printf("Total Patient Count: %d\nMale Patient Count: %d\nFemale Patient Count: %d\nChildren: %d\nAdults: %d\nSenior Citizens: %d",count,male_count,female_count,child,adult,old);
}
void patient_free_ll(patient_node* patient_head){
    if(patient_head==NULL) return;
    if(patient_head->next==NULL){
        free(patient_head);
        return;
    }
    patient_node* c=patient_head;
    while(patient_head!=NULL){
        patient_head=patient_head->next;
        free(c);
        c=patient_head;
    }
    return;
}
int patient_check_id(patient_node* patient_head,int k){
    if(patient_head==NULL) return 0;
    patient_node* c=patient_head;
    while(c!=NULL){
        if(c->id==k) return 1;
        c=c->next;
    }
    return 0;
}
doctor_node* doctor_menu(doctor_node* doctor_head){
    while(1){
        printf("|| Doctors MANAGEMENT SYSTEM ||\n 1.Add Doctor\n 2.Display All Doctor\n 3.Search Doctor by ID\n 4.Search Doctor by Name\n 5.Update Doctor Details\n 6.Delete Doctor\n 7.Doctor Stats\n 8.Return to Main Menu\n");
        printf("Enter Choice : ");
        int c;scanf("%d",&c);
        switch(c){
            case 1:doctor_head=doctor_add(doctor_head); break;
            case 2:doctor_display(doctor_head); break;
            case 3:doctor_search_id(doctor_head); break;
            case 4:doctor_search_name(doctor_head); break;
            case 5:doctor_head=doctor_update(doctor_head); break;
            case 6:doctor_head=doctor_del_id(doctor_head); break;
            case 7:doctor_stats(doctor_head); break;
            case 8:return doctor_head;
            default: printf("Invalid Choice!! Enter Again\n");
        }
    }
}
doctor_node* doctor_create(doctor_node* doctor_head){
    doctor_node* t=(doctor_node*)malloc(sizeof(doctor_node));
    if(t==NULL){
        printf("Memory not allocated!! Returning to main!");
        return NULL;
    }
    printf("Enter Details:\n");
    printf("Enter Id: ");scanf("%d",&t->id);
    while(t->id<=0){
        printf("Invalid Id!!");
        printf("Enter Id Again: ");scanf("%d",&t->id);
    }
    while(doctor_check_id(doctor_head,t->id)){
        printf("ID Already Allocated!!");
        printf("Enter Id Again: ");scanf("%d",&t->id);
    }
    printf("Enter Name: ");scanf(" %29[^\n]",t->name);
    printf("Enter Age: ");scanf("%d",&t->age);
    while(t->age<26){
        printf("Invalid Age!!");
        printf("Enter Age Again: ");scanf("%d",&t->age);
    }
    printf("Enter Gender: ");scanf(" %9[^\n]",t->gender);
    printf("Enter Mobile Number: ");scanf("%lld",&t->num);
    while(t->num<6000000000||t->num>9999999999){
        printf("Invalid Mobile Number!!");
        printf("Enter Number Again: ");scanf("%lld",&t->num);
    }
    printf("Enter Specialization: ");scanf(" %19[^\n]",t->spl);
    printf("Enter Experience: ");scanf("%d",&t->exp);
    while(t->exp<0){
        printf("Invalid Experience!!");
        printf("Enter Experience Again: ");scanf("%d",&t->exp);
    }
    printf("Enter Consultation Fee: ");scanf("%d",&t->fee);
    while(t->fee<0){
        printf("Invalid Fee");
        scanf("%d",&t->fee);
    }
    t->next=NULL;
    return t;
}
doctor_node* doctor_add(doctor_node* doctor_head){
    doctor_node* t=doctor_create(doctor_head);
    if(t==NULL) return doctor_head;
    if(doctor_head==NULL){
        printf("Doctor Added Successfully!\n");
        return t;
    }
    doctor_node* c=doctor_head;
    while(c->next!=NULL) c=c->next;
    c->next=t;
    printf("Doctor Added Successfully!\n");
    return doctor_head;
}
void doctor_display(doctor_node* doctor_head){
    if(doctor_head==NULL){
        printf("No Details Available!!\n");
        return;
    }
    doctor_node* c=doctor_head;
    printf("|| DOCTOR DETAILS ||\n");
    printf("ID\t\tName\t\tAge\t\tGender\t\tNumber\t\tSpecialization\t\tExperience\t\tConsultation Fee\n");
    while(c!=NULL){
        printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\t\t%d\n",c->id,c->name,c->age,c->gender,c->num,c->spl,c->exp,c->fee);
        c=c->next;
    }
}
void doctor_search_id(doctor_node* doctor_head){
    if(doctor_head==NULL){
        printf("No Details Available!!\n");
        return;
    }
    int flag=1;
    doctor_node* c=doctor_head;
    printf("Enter the Doctor ID you want to search: ");
    int k;scanf("%d",&k);
    while(c!=NULL){
        if(c->id==k){
            flag=0;
            printf("|| DOCTOR DETAILS ||\n");
            printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\t\t%d\n",c->id,c->name,c->age,c->gender,c->num,c->spl,c->exp,c->fee);
            break;
        }
        c=c->next;
    }
    if(flag){
        printf("No Records with given ID!!\n");
    }
}
void doctor_search_name(doctor_node* doctor_head){
    if(doctor_head==NULL){
        printf("No Details Available!!\n");
        return;
    }
    int flag=1;
    doctor_node* c=doctor_head;
    printf("Enter the Doctor Name you want to search: ");
    char tname[30];scanf(" %29[^\n]",tname);
    while(c!=NULL){
        if(!strcmp(c->name,tname)){
            flag=0;
            printf("|| DOCTOR DETAILS ||\n");
            printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%d\t\t%d\n",c->id,c->name,c->age,c->gender,c->num,c->spl,c->exp,c->fee);
            break;
        }
        c=c->next;
    }
    if(flag){
        printf("No Records with given Name!!\n");
    }
}
doctor_node* doctor_update(doctor_node* doctor_head){
    if(doctor_head==NULL){
        printf("No Details Available!!\n");
        return doctor_head;
    }
    printf("Enter the Doctor ID you want to update : ");
    int k;scanf("%d",&k);
    doctor_node* c=doctor_head;
    int flag=1;
    while(c!=NULL){
        if(c->id==k){
            printf("Enter the new details:\n Name : ");scanf(" %29[^\n]",c->name);
            printf("Age: ");scanf("%d",&c->age);
            while(c->age<26){
                printf("Invalid Age!!");
                printf("Enter Age Again: ");scanf("%d",&c->age);
            }
            printf("Mobile Number: ");scanf("%lld",&c->num);
            while(c->num<6000000000||c->num>9999999999){
                printf("Invalid Mobile Number!!");
                printf("Enter Number Again: ");scanf("%lld",&c->num);
            }
            printf("Specialization: ");scanf(" %19[^\n]",c->spl);
            printf("Experience: ");scanf("%d",&c->exp);
            while(c->exp<0){
                printf("Invalid Experience!!");
                printf("Enter Experience Again: ");scanf("%d",&c->exp);
            }
            printf("Consultation Fee: ");scanf("%d",&c->fee);
            while(c->fee<0){
                printf("Invalid Fee");
                scanf("%d",&c->fee);
            }
            printf("Successfully Updated!!\n");
            flag=0;
            break;
        }
        c=c->next;
    }
    if(flag){
        printf("No Records with the given ID!!\n");
    }
    return doctor_head;
}
doctor_node* doctor_del_id(doctor_node* doctor_head){
    if(doctor_head==NULL){
        printf("No Details Available!!\n");
        return doctor_head;
    }
    printf("Enter the Doctor ID you want to delete : ");
    int k;scanf("%d",&k);
    if(doctor_head->next==NULL && doctor_head->id==k){
        free(doctor_head);
        printf("Deleted!!\n");
        return NULL;
    }
    doctor_node* c=doctor_head;
    int flag=1;
    if(doctor_head->id==k){
        doctor_head=doctor_head->next;
        free(c);
        printf("Deleted!!\n");
        return doctor_head;
    }
    doctor_node* p=NULL;
    while(c!=NULL){
        if(c->id==k){
            p->next=c->next;
            free(c);
            printf("Deleted!!\n");
            flag=0;
            break;
        }
        p=c;
        c=c->next;
    }
    if(flag){
        printf("No Records with the given ID!!\n");
    }
    return doctor_head;
}
void doctor_stats(doctor_node* doctor_head){
    if(doctor_head==NULL){
        printf("No Doctor Details Available!!\n");
        return;
    }
    int count,male_count,female_count,junior,senior;
    count=male_count=female_count=junior=senior=0;
    doctor_node* c=doctor_head;
    while(c!=NULL){
        count++;
        if(!strcmp(c->gender,"Male")) male_count++;
        else if(!strcmp(c->gender,"Female")) female_count++;
        if(c->exp<15) junior++;
        else senior++;
        c=c->next;
    }

    printf("DOCTOR STATISTICS:\n");
    printf("Total Doctor Count: %d\nMale Doctor Count: %d\nFemale Doctor Count: %d\nJunior Doctors: %d\nSenior Doctors: %d\n",count,male_count,female_count,junior,senior);
}
void doctor_free_ll(doctor_node* doctor_head){
    if(doctor_head==NULL) return;
    if(doctor_head->next==NULL){
        free(doctor_head);
        return;
    }
    doctor_node* c=doctor_head;
    while(doctor_head!=NULL){
        doctor_head=doctor_head->next;
        free(c);
        c=doctor_head;
    }
    return;
}
int doctor_check_id(doctor_node* doctor_head,int k){
    if(doctor_head==NULL) return 0;
    doctor_node* c=doctor_head;
    while(c!=NULL){
        if(c->id==k) return 1;
        c=c->next;
    }
    return 0;
}