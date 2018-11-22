#include<iostream>
#include<string>


struct symbol
{
    char name[10];
    int address;
};

void insert(struct symbol *table[], struct symbol entry){
    int hashVal = hash(entry.name), i=0;

    while(table[hashVal] != NULL && i<size){
        if(strcmp(table[hashVal]->name, entry.name) == 0){
            std::cout<<"----Symbol already exists----";
            return;
        }
        hashVal=(++hashVal)%size;
        i++;
    }
    if(i >= size){
        std::cout<<"----Table Full----";
        return;
    }
    printf("----Symbol inserted at %d----",hashVal);
    std::cout<<"--- Symbol inserted at"<<hashVal;
    table[hashVal] = malloc(sizeof(struct symbol));
    strcpy(table[hashVal]->name, entry.name);
    table[hashVal]->addr = entry.addr;

}

int main()
{
    struct symbol *table[100] = {NULL};
    struct symbol x;
    int choice,hashVal;
    
    while(1){
        std::cout<<"\n\n MENU\n 1)INSERT \n 2)SEARCH \n 3)Display \n 4)Exit\n Enter choice \t";
        std::cin>>choice;
          
        if(choice==1)
        {
            std::cin>>x.name>>x.address;
            insert(table,x);
        }
        
    }
    


}