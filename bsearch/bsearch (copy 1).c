#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
 
typedef struct
{
  char name[21];
  float age;
  int ID;
}
personID;
 
personID profiles[] = {
  {"White", 123.5, 1234},
  {"Barry", -12.75, 1235},
  {"Agnew", 24.55, 1236},
  {"Achison", 12.45, 1237},
  {"Barry", -38.49, 1238},
  {"Brown", -18.23, 1239},
  {"Cunningham", 19.32, 1240}
};
 
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));
int compID (const void *p1, const void *p2);
int compName (const void *p1, const void *p2);
int compAge(const void *p1, const void *p2);
void printID (personID * a);
personID * findByName (const char *name);
personID * findByID (int ID);
personID * findByAge (float age);
 
   

 
int main (int argc, char *argv[])
{
  char searchingForName[] = "Barry";
  int searchingForID = 1238;
  float searchingForAge = 123.5;
 
 
  qsort (profiles, sizeof (profiles) / sizeof (*profiles), sizeof (*profiles), compName);
  printf ("Searching for %s:\n", searchingForName);
  printprofiles(findByName(searchingForName));
 
 
  qsort (profiles, sizeof (profiles) / sizeof (*profiles), sizeof (*profiles), compID);
  printf ("Searching for %d:\n", searchingForID);
  printprofiles(findByID(searchingForID));
 
  qsort (profiles, sizeof (profiles) / sizeof (*profiles), sizeof (*profiles), compAge);
  printf ("Searching for %f:\n", searchingForAge);
  printprofiles(findByAge(searchingForAge));
 
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
 
int compID (const void *p1, const void *p2)
{
  return ((profiles *) p1)->ID - ((profiles *) p2)->ID;
}
 
 
int compName (const void *p1, const void *p2)
{
  return strcmp (((profiles *) p1)->name, ((profiles *) p2)->name);
}
 
 
int compBalance(const void *p1, const void *p2)
{  
    if (fabs(((profiles *) p1)->age - ((profiles *) p2)->age) < 0.00001)
    {
        return 0;    
    }
    else
    {
        if ((((profiles *) p1)->age - ((profiles *) p2)->age) > 0)
        {
            return 1;
        } else {
            return -1;
        }
    }
 
}
 
void printprofiles (profiles * a)
{
  if (a)
    printf ("Name: %20s\t ID: %d\t Age: %f\n", a->name,
        a->ID, a->age);
 
}
 
profiles * findByName (const char *name)
{
  profiles reference;
  strcpy (reference.name, name);
  if (bsearch(&reference, profiles, sizeof (profiles) / sizeof (*profiles), sizeof (*profiles), compName) == NULL)
  {
      printf("No profiles matching criteria: %s\n", name);
      return NULL;
  } else {
      return bsearch (&reference, profiles, sizeof (profiles) / sizeof (*profiles), sizeof (*profiles), compName);
  }
}
 
profiles * findByID (int accNo)
{
  profiles reference;
  reference.ID = ID;
  if (bsearch(&reference, profiles, sizeof (profiles) / sizeof (*profiles), sizeof (*profiles), compID) == NULL)
  {
      printf("No profiles matching criteria: %d\n", accNo);
      return NULL;
  } else {
      return bsearch (&reference, profiles, sizeof (profiles) / sizeof (*profiles), sizeof (*profiles), compID);
  }
}
 
profiles * findAge (float age)
{
    profiles reference;
    reference.age = age;
    if (bsearch(&reference, profiles, sizeof (profiles) / sizeof (*profiles), sizeof (*profiles), compAge) == NULL)
    {
        printf("No profile matching criteria: %f\n", balance);
        return NULL;
    } else {
        return bsearch (&reference, profiles, sizeof (profiles) / sizeof (*profiles), sizeof (*profiles), compAge);
    }
}
