#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
 
typedef struct
{
  char name[21];
  float balance;
  int accNo;
}
CustAccount;
 
CustAccount accounts[] = {
  {"White", 123.5, 1234},
  {"Barry", -12.75, 1235},
  {"Agnew", 24.55, 1236},
  {"Achison", 12.45, 1237},
  {"Barry", -38.49, 1238},
  {"Brown", -18.23, 1239},
  {"Cunningham", 19.32, 1240}
};
 
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));
int compAccNo (const void *p1, const void *p2);
int compName (const void *p1, const void *p2);
int compBalance(const void *p1, const void *p2);
void printAccount (CustAccount * a);
CustAccount * findByName (const char *name);
CustAccount * findByAccNo (int accNo);
CustAccount * findBalance (float balance);
 

int main (int argc, char *argv[])
{
  char searchingForName[] = "Barry";
  int searchingForAccNo = 1238;
  float searchingForBalance = 123.5;
 
 
  qsort (accounts, sizeof (accounts) / sizeof (*accounts), sizeof (*accounts), compName);
  printf ("Searching for %s:\n", searchingForName);
  printAccount (findByName(searchingForName));
 
 
  qsort (accounts, sizeof (accounts) / sizeof (*accounts), sizeof (*accounts), compAccNo);
  printf ("Searching for %d:\n", searchingForAccNo);
  printAccount (findByAccNo(searchingForAccNo));
 
  qsort (accounts, sizeof (accounts) / sizeof (*accounts), sizeof (*accounts), compBalance);
  printf ("Searching for %f:\n", searchingForBalance);
  printAccount (findBalance(searchingForBalance));
 
  return 0;
}
 
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *))
{
    const void* currentElement = 0;
    int start = 0;
    int end = nmemb;
    int middle;
    int searchElement;
 
    while (start <= end)
    {
        middle = start + (end - start) / 2;
        currentElement = (char*)base + middle* size;
        searchElement = (*compare)(key, currentElement);
 
        if (searchElement == 0)
        {
            return ((void*)currentElement);
        }
        else if (searchElement < 0)
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }
 
    return NULL;
}
 
int compAccNo (const void *p1, const void *p2)
{
  return ((CustAccount *) p1)->accNo - ((CustAccount *) p2)->accNo;
}
 
 
int compName (const void *p1, const void *p2)
{
  return strcmp (((CustAccount *) p1)->name, ((CustAccount *) p2)->name);
}
 
 
int compBalance(const void *p1, const void *p2)
{  
    if (fabs(((CustAccount *) p1)->balance - ((CustAccount *) p2)->balance) < 0.00001)
    {
        return 0;    
    }
    else
    {
        if ((((CustAccount *) p1)->balance - ((CustAccount *) p2)->balance) > 0)
        {
            return 1;
        } else {
            return -1;
        }
    }
 
}
 
void printAccount (CustAccount * a)
{
  if (a)
    printf ("Name: %20s\t AccNo: %d\t Balance: %f\n", a->name,
        a->accNo, a->balance);
 
}
 
CustAccount * findByName (const char *name)
{
  CustAccount reference;
  strcpy (reference.name, name);
  if (bsearch(&reference, accounts, sizeof (accounts) / sizeof (*accounts), sizeof (*accounts), compName) == NULL)
  {
      printf("No accound matching criteria: %s\n", name);
      return NULL;
  } else {
      return bsearch (&reference, accounts, sizeof (accounts) / sizeof (*accounts), sizeof (*accounts), compName);
  }
}
 
CustAccount * findByAccNo (int accNo)
{
  CustAccount reference;
  reference.accNo = accNo;
  if (bsearch(&reference, accounts, sizeof (accounts) / sizeof (*accounts), sizeof (*accounts), compAccNo) == NULL)
  {
      printf("No accound matching criteria: %d\n", accNo);
      return NULL;
  } else {
      return bsearch (&reference, accounts, sizeof (accounts) / sizeof (*accounts), sizeof (*accounts), compAccNo);
  }
}
 
CustAccount * findBalance (float balance)
{
    CustAccount reference;
    reference.balance = balance;
    if (bsearch(&reference, accounts, sizeof (accounts) / sizeof (*accounts), sizeof (*accounts), compBalance) == NULL)
    {
        printf("No accound matching criteria: %f\n", balance);
        return NULL;
    } else {
        return bsearch (&reference, accounts, sizeof (accounts) / sizeof (*accounts), sizeof (*accounts), compBalance);
    }
}
