#include <stdio.h>
#include <string.h>

#define MAX_BORROWED 3
#define BOOKS_FILE "books.dat"
#define MEMBERS_FILE "members.dat"

typedef struct {
    int id;
    char title[100];
    char author[100];
    char isbn[20];
    int year;
    int available;
} Book;

typedef struct {
    int id;
    char name[100];
    char contact[50];
    int borrowedBooks[MAX_BORROWED];
    int borrowCount;
} Member;

Book books[100];
Member members[100];
int bookCount = 0, memberCount = 0;

void saveData() {
    FILE *f = fopen(BOOKS_FILE, "wb");
    fwrite(&bookCount, sizeof(int), 1, f);
    fwrite(books, sizeof(Book), bookCount, f);
    fclose(f);
    
    f = fopen(MEMBERS_FILE, "wb");
    fwrite(&memberCount, sizeof(int), 1, f);
    fwrite(members, sizeof(Member), memberCount, f);
    fclose(f);
}

void loadData() {
    FILE *f = fopen(BOOKS_FILE, "rb");
    if (f) {
        fread(&bookCount, sizeof(int), 1, f);
        fread(books, sizeof(Book), bookCount, f);
        fclose(f);
    }
    
    f = fopen(MEMBERS_FILE, "rb");
    if (f) {
        fread(&memberCount, sizeof(int), 1, f);
        fread(members, sizeof(Member), memberCount, f);
        fclose(f);
    }
}

void addBook() {
    Book b;
    printf("Enter Book ID: "); scanf("%d", &b.id);
    printf("Enter Title: "); scanf(" %[^\n]s", b.title);
    printf("Enter Author: "); scanf(" %[^\n]s", b.author);
    printf("Enter ISBN: "); scanf("%s", b.isbn);
    printf("Enter Year: "); scanf("%d", &b.year);
    b.available = 1;
    books[bookCount++] = b;
    saveData();
    printf("Book added.\n");
}

void addMember() {
    Member m;
    printf("Enter Member ID: "); scanf("%d", &m.id);
    printf("Enter Name: "); scanf(" %[^\n]s", m.name);
    printf("Enter Contact: "); scanf("%s", m.contact);
    m.borrowCount = 0;
    members[memberCount++] = m;
    saveData();
    printf("Member added.\n");
}

void issueBook() {
    int bookId, memberId;
    printf("Enter Book ID: "); scanf("%d", &bookId);
    printf("Enter Member ID: "); scanf("%d", &memberId);
    
    int bookIdx = -1, memberIdx = -1;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) { bookIdx = i; break; }
    }
    for (int i = 0; i < memberCount; i++) {
        if (members[i].id == memberId) { memberIdx = i; break; }
    }
    
    if (bookIdx == -1 || memberIdx == -1) {
        printf("Invalid book or member ID.\n");
        return;
    }
    if (!books[bookIdx].available) {
        printf("Book not available.\n");
        return;
    }
    if (members[memberIdx].borrowCount >= MAX_BORROWED) {
        printf("Member has reached borrow limit.\n");
        return;
    }
    
    books[bookIdx].available = 0;
    members[memberIdx].borrowedBooks[members[memberIdx].borrowCount++] = bookId;
    saveData();
    printf("Book issued.\n");
}

void returnBook() {
    int bookId, memberId;
    printf("Enter Book ID: "); scanf("%d", &bookId);
    printf("Enter Member ID: "); scanf("%d", &memberId);
    
    int bookIdx = -1, memberIdx = -1;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) { bookIdx = i; break; }
    }
    for (int i = 0; i < memberCount; i++) {
        if (members[i].id == memberId) { memberIdx = i; break; }
    }
    
    if (bookIdx == -1 || memberIdx == -1) {
        printf("Invalid book or member ID.\n");
        return;
    }
    
    int found = 0;
    for (int i = 0; i < members[memberIdx].borrowCount; i++) {
        if (members[memberIdx].borrowedBooks[i] == bookId) {
            for (int j = i; j < members[memberIdx].borrowCount - 1; j++) {
                members[memberIdx].borrowedBooks[j] = members[memberIdx].borrowedBooks[j + 1];
            }
            members[memberIdx].borrowCount--;
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Book not borrowed by this member.\n");
        return;
    }
    
    books[bookIdx].available = 1;
    saveData();
    printf("Book returned.\n");
}

void searchBooks() {
    char query[100];
    int choice;
    printf("Search by: 1. Author 2. Title\nChoice: ");
    scanf("%d", &choice);
    printf("Enter search term: "); scanf(" %[^\n]s", query);
    
    printf("\nSearch Results:\n");
    for (int i = 0; i < bookCount; i++) {
        if ((choice == 1 && strstr(books[i].author, query)) || 
            (choice == 2 && strstr(books[i].title, query))) {
            printf("ID: %d, Title: %s, Author: %s, Status: %s\n", 
                   books[i].id, books[i].title, books[i].author, 
                   books[i].available ? "Available" : "Borrowed");
        }
    }
}

void displayMemberBooks() {
    int memberId;
    printf("Enter Member ID: "); scanf("%d", &memberId);
    
    int memberIdx = -1;
    for (int i = 0; i < memberCount; i++) {
        if (members[i].id == memberId) { memberIdx = i; break; }
    }
    
    if (memberIdx == -1) {
        printf("Member not found.\n");
        return;
    }
    
    printf("\nBooks borrowed by %s:\n", members[memberIdx].name);
    for (int i = 0; i < members[memberIdx].borrowCount; i++) {
        int bookId = members[memberIdx].borrowedBooks[i];
        for (int j = 0; j < bookCount; j++) {
            if (books[j].id == bookId) {
                printf("- %s by %s\n", books[j].title, books[j].author);
                break;
            }
        }
    }
}

int main() {
    loadData();
    int choice;
    
    while (1) {
        printf("\n1. Add Book\n2. Add Member\n3. Issue Book\n4. Return Book\n5. Search Books\n6. Display Member Books\n7. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addBook(); break;
            case 2: addMember(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: searchBooks(); break;
            case 6: displayMemberBooks(); break;
            case 7: printf("Exiting.\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
    
    return 0;
}
