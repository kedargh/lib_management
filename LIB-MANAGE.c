#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000
#define MAX 500
typedef struct{
    char book_name[50];
    char author_name[30];
    char book_id[30];
    char date_of_issue[10];
    char issued_to[30];
}book_details;

void print_book_details_file(FILE *fp,book_details *book1);

book_details book_records[MAX_SIZE];

int book_count = 0;
void print_header(FILE *fp)
{
    fprintf(fp,"Book name,");
    fprintf(fp,"Author name,");
    fprintf(fp,"Book ID,");
    fprintf(fp,"Issue date,");
    fprintf(fp,"Issued to\n");
}

void write_to_file()
{   int i;
    FILE *fp;
    fp = fopen("C:\\DSA PROJECT\\book_data.csv","w");
    print_header(fp);
    for(i=0;i<book_count;i++)
    {
        print_book_details_file(fp, &book_records[i]);
    }

    fclose(fp);
}

void read_from_file()
{   FILE *fp;
    char buf[MAX];


    fp = fopen("C:\\DSA PROJECT\\book_data.csv","r");
    //while(fgets(buf, MAX, fp)!=NULL)
    char * token = strtok(fgets(buf, MAX, fp)!=NULL, ",");
    printf("%s\n", buf);
    fclose(fp);
    return 0;
}

void print_book_details_file(FILE *fp,book_details *book1)
{
    fprintf(fp,"%s,", book1->book_name);
    fprintf(fp,"%s,", book1->author_name);
    fprintf(fp,"%s,", book1->book_id);
    fprintf(fp,"%s,", book1->date_of_issue);
    fprintf(fp,"%s,\n", book1->issued_to);
}


void take_input(book_details *book) //Ithe te object pointer add karaycha ahe
{
    printf("Enter book name = ");
    scanf("%s",book->book_name);

    //strcpy(temp_book_name,book->book_name);

    printf("Enter author name = ");
    scanf("%s",book->author_name);

    //strcpy(temp_author_name,book->author_name);

    printf("Enter book id = ");
    scanf("%s",book->book_id);

    //strcpy(temp_book_id,book->book_id);

    printf("Enter issue date = ");
    scanf("%s",book->date_of_issue);

    //strcpy(temp_date_of_issue,book->date_of_issue);

    printf("Enter issued to record = ");
    scanf("%s",book->issued_to);

    //strcpy(temp_issued_to,book->issued_to);
}

void print_book_details(book_details *book1)
{
    printf("Book name = %s\t", book1->book_name);
    printf("Author name = %s\t", book1->author_name);
    printf("Book ID = %s\t", book1->book_id);
    printf("Issue date = %s\t", book1->date_of_issue);
    printf("Issued to = %s\t\n", book1->issued_to);
}

void add_book() //FUNCTION 1
{
    book_count++;
    take_input(&book_records[book_count-1]);
}

void print_books() //FUNCTION 2
{
    int i;
    for(i=0;i<book_count;i++)
    {
        print_book_details(&book_records[i]);
    }
}

int search_book(char *bookid) //FUNCTION 3
{
    int i=0;
    for(i=0;i<book_count;i++)
    {
        if(strcmp(book_records[i].book_id,bookid)==0)
            {return i;
            break;}

    }

    printf("Not found ");
    return -1;
}


int delete_book_record(char *bookid)
{   int book_position,i;
    book_position = search_book(bookid);
    if(book_position>=0)
    {
    for(i=book_position;i<book_count;i++)
    {
        book_records[i]=book_records[i+1];
    }
    book_count--;
    }
}


int main()
{   int i=0;
    int n_books; //USED IN THE FUNCTION OF ADD BOOKS
    char bookid[30];
    int operation;
    while(1){
    printf("Enter the input in the menu - \n 1 - ADD BOOK\n 2 - SEARCH BOOK NUMBER\n 3 - PRINT BOOK DETAILS\n 4 - DELETE BOOK RECORD\n 5 - SAVE CHANGES TO MAIN FILE\n 6 - EXIT");
    scanf("%d", &operation);


    switch(operation){
    case 1: printf("Enter the number of books you want to add = "); //adds books
            scanf("%d",&n_books);
            while(i<n_books)
                {add_book();
                 print_books();
                 i++;}
            break;

    case 2: printf("Enter bookid = ");  //prints book details
            scanf("%s",bookid);
            i = search_book(bookid);
            printf("Location = %d\n",i+1);
            break;

    case 3:
            printf("Enter bookid = ");  //searches position of the book
            scanf("%s",bookid);
            i = search_book(bookid);
            if(i>=0)
            {   print_book_details(&book_records[i]);
            }
            break;
    case 4:
            printf("Enter bookid = ");
            scanf("%s",bookid);
            delete_book_record(bookid);
            print_books();
            break;
    case 5:
            write_to_file();
            break;
    case 6:
            read_from_file();
            break;
    default:
            printf("Please enter valid input");
            break;
    }
    /*while(i<3)
    {add_book();
    print_books();
        i++;}
    printf("Enter bookid = ");
    scanf("%s",bookid);

    i = search_book(bookid);
    printf("Location = %d\n",i+1);//check if book is available and its index
    if(i>=0)
    print_book_details(&book_records[i]);

    //printf("Enter the number of books to add = ");
    //scanf("%d",&n);*/

    printf("\n\n");
    }
}
