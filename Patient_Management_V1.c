#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int id;
    char name[30];
    int age;
    char gender[10];
    long long int num;
    char disease[30];
    char blood_group[10];
    struct node* next;
}node;
node* create(node* f);
node* add_rear(node* f);
void display(node* f);
void search_id(node* f);
void search_name(node* f);
node* update(node* f);
node* del_id(node* f);
void stats(node* f);
void free_ll(node* f);
int check_id(node* f,int k);
int main(){
    node* f=NULL;
    while(1){
        printf("|| HOSPITAL MANAGEMENT SYSTEM ||\n 1.Add Patient\n 2.Display All Patients\n 3.Search Patient by ID\n 4.Search Patient by Name\n 5.Update Patient Details\n 6.Delete Patient\n 7.Display Stats\n 8.Exit\n");
        printf("Enter Choice : ");
        int c;scanf("%d",&c);
        switch(c){
            case 1:f=add_rear(f); break;
            case 2:display(f); break;
            case 3:search_id(f); break;
            case 4:search_name(f); break;
            case 5:f=update(f); break;
            case 6:f=del_id(f); break;
            case 7:stats(f); break;
            case 8:free_ll(f);return 0; break;
            default: printf("Invalid Choice!! Enter Again\n");
        }
    }
}
node* create(node* f){
    node* t=(node*)malloc(sizeof(node));
    if(t==NULL){
        printf("Memory not allocated!! Returning to main!");
        return NULL;
    }
    printf("Enter Details:\n");
    printf("Enter Id: ");scanf("%d",&t->id);
    while(check_id(f,t->id)){
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
node* add_rear(node* f){
    node* t=create(f);
    if(f==NULL) return t;
    if(t==NULL) return f;
    node* c=f;
    while(c->next!=NULL) c=c->next;
    c->next=t;
    printf("Patient Added Successfully!\n");
    return f;
}
void display(node* f){
    if(f==NULL){
        printf("No Details Availabel!!\n");
        return;
    }
    node* c=f;
    printf("|| PATIENT DETAILS ||");
    printf("ID\t\tName\t\tAge\t\tGender\t\tNumber\t\tDisease\t\tBlood Group\n");
    while(c!=NULL){
        printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%s\n",c->id,c->name,c->age,c->gender,c->num,c->disease,c->blood_group);
        c=c->next;
    }
}
void search_id(node* f){
    if(f==NULL){
        printf("No Details Availabel!!\n");
        return;
    }
    int flag=1;
    node* c=f;
    printf("Enter the Patient ID you want to search: ");
    int k;scanf("%d",&k);
    while(c!=NULL){
        if(c->id==k){
            flag=0;
            printf("|| PATIENT DETAILS ||");
            printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%s\n",c->id,c->name,c->age,c->gender,c->num,c->disease,c->blood_group);
            break;
        }
        c=c->next;
    }
    if(flag){
        printf("No Records with given ID!!\n");
    }
}
void search_name(node* f){
    if(f==NULL){
        printf("No Details Availabel!!\n");
        return;
    }
    int flag=1;
    node* c=f;
    printf("Enter the Patient Name you want to search: ");
    char tname[30];scanf(" %29[^\n]",tname);
    while(c!=NULL){
        if(!strcmp(c->name,tname)){
            flag=0;
            printf("|| PATIENT DETAILS ||");
            printf("%d\t\t%s\t\t%d\t\t%s\t\t%lld\t\t%s\t\t%s\n",c->id,c->name,c->age,c->gender,c->num,c->disease,c->blood_group);
            break;
        }
        c=c->next;
    }
    if(flag){
        printf("No Records with given Name!!\n");
    }
}
node* update(node* f){
    if(f==NULL){
        printf("No Details Availabel!!\n");
        return f;
    }
    printf("Enter the Patient ID you want to update : ");
    int k;scanf("%d",&k);
    node* c=f;
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
    return f;
}
node* del_id(node* f){
    if(f==NULL){
        printf("No Details Availabel!!\n");
        return f;
    }
    printf("Enter the Patient ID you want to delete : ");
    int k;scanf("%d",&k);
    if(f->next==NULL && f->id==k){
        free(f);
        printf("Deleted!!");
        return NULL;
    }
    node* c=f;
    int flag=1;
    if(f->id==k){
        f=f->next;
        free(c);
        printf("Deleted!!");
        return f;
    }
    node* p=NULL;
    while(c!=NULL){
        if(c->id==k){
            p->next=c->next;
            free(c);
            printf("Deleted!!");
            flag=0;
            break;
        }
        p=c;
        c=c->next;
    }
    if(flag){
        printf("No Records with the given ID!!\n");
    }
    return f;
}
void stats(node* f){
    if(f==NULL){
        printf("No Details Availabel!!\n");
        return;
    }
    int count,male_count,female_count,child,adult,old;
    count=male_count=female_count=child=adult=old=0;
    node* c=f;
    while(c!=NULL){
        count++;
        if(!strcmp(c->gender,"Male")) male_count++;
        else female_count++;
        if(c->age<18) child++;
        else if(c->age>=18 && c->age<60) adult++;
        else old++;
        c=c->next;
    }

    printf("STATISTICS:\n");
    printf("Total Patient Count: %d\nMale Patient Count: %d\nFemale Patient Count: %d\nChildren: %d\nAdults: %d\nSenior Citizens: %d",count,male_count,female_count,child,adult,old);
}
void free_ll(node* f){
    if(f==NULL) return;
    if(f->next==NULL){
        free(f);
        return;
    }
    node* c=f;
    while(f!=NULL){
        f=f->next;
        free(c);
        c=f;
    }
    return;
}
int check_id(node* f,int k){
    if(f==NULL) return 0;
    node* c=f;
    while(c!=NULL){
        if(c->id==k) return 1;
        c=c->next;
    }
    return 0;
}