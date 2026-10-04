#ifndef ASSETS_H
#define ASSETS_H

/* Capacity of the asset register */
#define MAX_ASSETS 100

/* Maximum text lengths */
#define ID_LEN     15
#define NAME_LEN   40
#define TYPE_LEN   25
#define DEPT_LEN   30
#define COND_LEN   15
#define DATE_LEN   12

/* Called by main.c to run the Asset Management submenu */
void assetManagementMenu(void);

/* Used by the Reports module (Asset Report) */
void   displayAssets(void);
int    getAssetCount(void);
double getAssetTotalValue(void);
double getAverageAssetValue(void);

#endif /* ASSETS_H */
