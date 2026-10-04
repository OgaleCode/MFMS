#include <stdio.h>
#include <string.h>
#include "assets.h"

#define TYPE_COUNT 5
#define COND_COUNT 4

static char assetIDs[MAX_ASSETS][ID_LEN];
static char assetNames[MAX_ASSETS][NAME_LEN];
static char assetTypes[MAX_ASSETS][TYPE_LEN];
static char assetDepartments[MAX_ASSETS][DEPT_LEN];
static char assetConditions[MAX_ASSETS][COND_LEN];
static char assetDates[MAX_ASSETS][DATE_LEN];
static double assetValues[MAX_ASSETS];
static int assetCount = 0;


static const char *ASSET_TYPES[TYPE_COUNT] = {
    "Vehicle", "Computer", "Building", "Equipment", "Office Furniture"
};

static const char *ASSET_CONDITIONS[COND_COUNT] = {
    "New", "Good", "Fair", "Poor"
};


static void   clearInputBuffer(void);
static int    isBlank(const char s[]);
static int    readStringOptional(const char prompt[], char dest[], int maxSize);
static void   readString(const char prompt[], char dest[], int maxSize);
static int    readInt(const char prompt[]);
static double readPositiveDouble(const char prompt[]);
static int    chooseFromList(const char title[], const char *list[], int listSize, char dest[]);
static void   generateAssetID(const char type[], char dest[]);
static int    containsIgnoreCase(const char text[], const char word[]);
static int    findAssetByID(const char id[]);
static void   printAsset(int index);
static double calculateTotalAssetValue(void);
static int    addAsset(void);
static void   searchAssets(void);
static void   assetSummary(void);


static void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;   
};
static int isBlank(const char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\t')
            return 0;   /* found a real character */
    }
    return 1;
}

static int readStringOptional(const char prompt[], char dest[], int maxSize)
{
    size_t len;

    printf("%s", prompt);

    if (fgets(dest, maxSize, stdin) == NULL) {  /* EOF or read error */
        dest[0] = '\0';
        return 0;
    }

    len = strcspn(dest, "\n");      /* find position of the newline */
    if (dest[len] == '\n') {
        dest[len] = '\0';           /* normal case: strip newline   */
    } else {
        clearInputBuffer();         /* input too long: discard rest */
    }

    if (isBlank(dest))
        return 0;
    return 1;
}

static void readString(const char prompt[], char dest[], int maxSize)
{
    int valid;

    do {
        valid = readStringOptional(prompt, dest, maxSize);
        if (valid == 0)
            printf("  [!] Input cannot be empty. Please try again.\n");
    } while (valid == 0);
}

static int readInt(const char prompt[])
{
    int value;
    int ok;

    do {
        printf("%s", prompt);
        ok = scanf("%d", &value);
        clearInputBuffer();

        if (ok != 1)
            printf("  [!] Invalid input. Please enter a whole number.\n");
    } while (ok != 1);

    return value;
}

static double readPositiveDouble(const char prompt[])
{
    double value;
    int ok;

    do {
        printf("%s", prompt);
        ok = scanf("%lf", &value);
        clearInputBuffer();

        if (ok != 1) {
            printf("  [!] Invalid number. Please enter digits only.\n");
        } else if (value <= 0) {
            printf("  [!] Value must be greater than N$0. Negative values are not accepted.\n");
        }
    } while (ok != 1 || value <= 0);

    return value;
}

static int chooseFromList(const char title[], const char *list[], int listSize, char dest[])
{
    int choice;
    int i;

    printf("%s\n", title);
    for (i = 0; i < listSize; i++)
        printf("   %d. %s\n", i + 1, list[i]);

    do {
        choice = readInt("   Enter choice: ");
        if (choice < 1 || choice > listSize)
            printf("  [!] Please enter a number between 1 and %d.\n", listSize);
    } while (choice < 1 || choice > listSize);

    strcpy(dest, list[choice - 1]);   /* store the chosen text    */
    return choice;                    /* and also return its number */
}


static int findAssetByID(const char id[])
{
    int i;

    for (i = 0; i < assetCount; i++) {
        if (strcmp(assetIDs[i], id) == 0)
            return i;
    }
    return -1;
}

static int containsIgnoreCase(const char text[], const char word[])
{
    int i, j;

    if (word[0] == '\0')
        return 1;

    for (i = 0; text[i] != '\0'; i++) {
        for (j = 0; word[j] != '\0' && text[i + j] != '\0'; j++) {
            char a = text[i + j];
            char b = word[j];

            if (a >= 'A' && a <= 'Z') a = (char)(a + ('a' - 'A'));
            if (b >= 'A' && b <= 'Z') b = (char)(b + ('a' - 'A'));
            if (a != b)
                break;
        }
        if (word[j] == '\0')
            return 1;
    }
    return 0;
}

static void generateAssetID(const char type[], char dest[])
{
    char prefix[5];
    char numberStr[10];
    int number = 1;

    if (strcmp(type, ASSET_TYPES[0]) == 0)
        strcpy(prefix, "VEH");
    else if (strcmp(type, ASSET_TYPES[1]) == 0)
        strcpy(prefix, "COM");
    else if (strcmp(type, ASSET_TYPES[2]) == 0)
        strcpy(prefix, "BLD");
    else if (strcmp(type, ASSET_TYPES[3]) == 0)
        strcpy(prefix, "EQP");
    else
        strcpy(prefix, "FUR");

    do {
        strcpy(dest, prefix);
        sprintf(numberStr, "-%03d", number);
        strcat(dest, numberStr);        /* ID = prefix + "-" + number */
        number++;
    } while (findAssetByID(dest) != -1);
}

/* Prints the full details of one asset.                              */
static void printAsset(int index)
{
    printf("  ----------------------------------------\n");
    printf("  Asset ID       : %s\n", assetIDs[index]);
    printf("  Asset Name     : %s\n", assetNames[index]);
    printf("  Asset Type     : %s\n", assetTypes[index]);
    printf("  Purchase Value : N$%.2f\n", assetValues[index]);
    printf("  Department     : %s\n", assetDepartments[index]);
    printf("  Condition      : %s\n", assetConditions[index]);
    printf("  Purchased      : %s\n", assetDates[index]);
}

/* Sums up the purchase value of all registered assets.               */
static double calculateTotalAssetValue(void)
{
    double total = 0.0;
    int i;

    for (i = 0; i < assetCount; i++)
        total = total + assetValues[i];

    return total;
}

/*                       MAIN ASSET OPERATIONS                        */

static int addAsset(void)
{
    char tempID[ID_LEN];
    int duplicate;

    if (assetCount >= MAX_ASSETS) {
        printf("\n  [!] Asset register is full (%d assets). Cannot add more.\n", MAX_ASSETS);
        return 0;
    }

    printf("\n------------ ADD NEW ASSET ------------\n");

    
    readString("  Asset name            : ", assetNames[assetCount], NAME_LEN);

  
    chooseFromList("  Asset type:", ASSET_TYPES, TYPE_COUNT, assetTypes[assetCount]);

    do {
        duplicate = 0;

        if (readStringOptional("  Asset ID (Enter = automatic): ", tempID, ID_LEN) == 0) {
            generateAssetID(assetTypes[assetCount], tempID);
            printf("  -> Automatic ID assigned: %s\n", tempID);
        }

        if (findAssetByID(tempID) != -1) {
            duplicate = 1;
            printf("  [!] Asset ID \"%s\" already exists. Enter a different ID.\n", tempID);
        }
    } while (duplicate == 1);

    strcpy(assetIDs[assetCount], tempID);

    assetValues[assetCount] = readPositiveDouble("  Purchase value (N$)   : ");

   
    readString("  Department            : ", assetDepartments[assetCount], DEPT_LEN);

    
    chooseFromList("  Condition:", ASSET_CONDITIONS, COND_COUNT, assetConditions[assetCount]);

    readString("  Purchase year/date    : ", assetDates[assetCount], DATE_LEN);

    assetCount++;

    printf("\n  [OK] Asset added successfully. Total assets in register: %d\n", assetCount);
    return 1;
}

void displayAssets(void)
{
    int i;
    double total;

    if (assetCount == 0) {
        printf("\n  [!] No assets registered yet. Use 'Add asset' first.\n");
        return;
    }

    total = calculateTotalAssetValue();

    printf("\n============================ ASSET REGISTER ============================\n");
    printf("%-11.11s %-20.20s %-14.14s %10s  %-16.16s %-6.6s\n",
           "ID", "Name", "Type", "Value(N$)", "Department", "Cond");
    printf("------------------------------------------------------------------------\n");

    for (i = 0; i < assetCount; i++) {
        printf("%-11.11s %-20.20s %-14.14s %10.2f  %-16.16s %-6.6s\n",
               assetIDs[i], assetNames[i], assetTypes[i],
               assetValues[i], assetDepartments[i], assetConditions[i]);
    }

    printf("------------------------------------------------------------------------\n");
    printf("  Total assets: %d  |  Total value: N$%.2f\n", assetCount, total);
}

/* Searches the register by ID, name or department.                   */
static void searchAssets(void)
{
    int choice;
    char keyword[NAME_LEN];
    int i;
    int matches;
    int index;

    if (assetCount == 0) {
        printf("\n  [!] No assets registered yet. Use 'Add asset' first.\n");
        return;
    }

    printf("\n------------ SEARCH ASSETS ------------\n");
    printf("  1. Search by Asset ID\n");
    printf("  2. Search by Asset Name (partial match allowed)\n");
    printf("  3. Search by Department\n");

    choice = readInt("  Enter your choice: ");

    switch (choice) {
        case 1: /* exact match on the ID using strcmp() */
            readString("  Enter Asset ID: ", keyword, ID_LEN);
            index = findAssetByID(keyword);

            if (index == -1) {
                printf("  [!] No asset found with ID \"%s\".\n", keyword);
            } else {
                printf("  [OK] Asset found:\n");
                printAsset(index);
            }
            break;

        case 2: 
            readString("  Enter Asset Name (full or partial): ", keyword, NAME_LEN);
            matches = 0;
            for (i = 0; i < assetCount; i++) {
                if (containsIgnoreCase(assetNames[i], keyword) == 1) {
                    printAsset(i);
                    matches++;
                }
            }
            if (matches == 0)
                printf("  [!] No assets found matching \"%s\".\n", keyword);
            else
                printf("  [OK] %d asset(s) found.\n", matches);
            break;

        case 3:
            readString("  Enter Department: ", keyword, NAME_LEN);
            matches = 0;
            for (i = 0; i < assetCount; i++) {
                if (containsIgnoreCase(assetDepartments[i], keyword) == 1) {
                    printAsset(i);
                    matches++;
                }
            }
            if (matches == 0)
                printf("  [!] No assets found in department \"%s\".\n", keyword);
            else
                printf("  [OK] %d asset(s) found.\n", matches);
            break;

        default:
            printf("  [!] Invalid choice. Please enter 1, 2 or 3.\n");
            break;
    }
}

/* Prints statistics about the registered assets.                     */
static void assetSummary(void)
{
    int i, j, count;
    int mostExpensive;
    double total, average;

    if (assetCount == 0) {
        printf("\n  [!] No assets registered yet. Use 'Add asset' first.\n");
        return;
    }

    total   = calculateTotalAssetValue();
    average = total / assetCount;

    /* Find the most expensive asset (relational operator + array) */
    mostExpensive = 0;
    for (i = 1; i < assetCount; i++) {
        if (assetValues[i] > assetValues[mostExpensive])
            mostExpensive = i;
    }

    printf("\n============== ASSET SUMMARY ==============\n");
    printf("  Total assets  : %d\n", assetCount);
    printf("  Total value   : N$%.2f\n", total);
    printf("  Average value : N$%.2f\n", average);
    printf("  Most valuable : %s (N$%.2f)\n",
           assetNames[mostExpensive], assetValues[mostExpensive]);

    /* Count assets per type (strcmp() compares the strings) */
    printf("\n  Assets per type:\n");
    for (i = 0; i < TYPE_COUNT; i++) {
        count = 0;
        for (j = 0; j < assetCount; j++) {
            if (strcmp(assetTypes[j], ASSET_TYPES[i]) == 0)
                count++;
        }
        if (count > 0)
            printf("    %-16s: %d\n", ASSET_TYPES[i], count);
    }

    /* Count assets per condition */
    printf("\n  Assets per condition:\n");
    for (i = 0; i < COND_COUNT; i++) {
        count = 0;
        for (j = 0; j < assetCount; j++) {
            if (strcmp(assetConditions[j], ASSET_CONDITIONS[i]) == 0)
                count++;
        }
        if (count > 0) {
            printf("    %-6s: %d", ASSET_CONDITIONS[i], count);
            if (strcmp(ASSET_CONDITIONS[i], "Poor") == 0)
                printf("   <-- replacement may be needed");
            printf("\n");
        }
    }
}


/*                  PUBLIC FUNCTIONS (module API)                     */

/* Asset management submenu - called from main.c when the user        */
/* selects "4. Asset Management" on the main menu.                    */
void assetManagementMenu(void)
{
    int choice;
    int running = 1;

    while (running == 1) {
        printf("\n========================================\n");
        printf("             ASSET MANAGEMENT\n");
        printf("========================================\n");
        printf("  1. Add asset\n");
        printf("  2. Display all assets\n");
        printf("  3. Search for an asset\n");
        printf("  4. Asset summary\n");
        printf("  5. Back to main menu\n");

        choice = readInt("  Enter your choice: ");

        switch (choice) {
            case 1: addAsset();      break;
            case 2: displayAssets(); break;
            case 3: searchAssets();  break;
            case 4: assetSummary();  break;
            case 5: running = 0;     break;
            default:
                printf("  [!] Invalid choice. Please enter 1 to 5.\n");
                break;
        }
    }
}


int getAssetCount(void)
{
    return assetCount;
}

double getAssetTotalValue(void)
{
    return calculateTotalAssetValue();
}

double getAverageAssetValue(void)
{
    if (assetCount == 0)
        return 0.0;
    return calculateTotalAssetValue() / assetCount;
}
