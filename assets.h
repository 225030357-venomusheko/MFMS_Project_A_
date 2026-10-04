#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#define STR_SIZE 100

typedef struct {
    int id;
    char name[STR_SIZE];
    char type[STR_SIZE];
    double purchaseValue;
    char department[STR_SIZE];
    char condition[STR_SIZE];
} Asset;

void assetMenu(Asset assets[], int *count);
void addAsset(Asset assets[], int *count);
void displayAssets(const Asset assets[], int count);
void searchAsset(const Asset assets[], int count);

#endif
