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
int main(){
    patient_node* patient_head=NULL;
    while(1){
        printf("|| HOSPITAL MANAGEMENT SYSTEM ||\n 1.Add Patient\n 2.Display All Patients\n 3.Search Patient by ID\n 4.Search Patient by Name\n 5.Update Patient Details\n 6.Delete Patient\n 7.Display Stats\n 8.Exit\n");
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
            case 8:patient_free_ll(patient_head);return 0; break;
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
        printf("No Details Available!!\n");
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

    printf("STATISTICS:\n");
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