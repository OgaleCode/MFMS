#ifndef VALIDATION_H
#define VALIDATION_H

int getValidInt(int min, int max, const char* prompt);
float getValidFloat(float min, float max, const char* prompt);
void getValidString(char* output, int maxLength, const char* prompt);

#endif
