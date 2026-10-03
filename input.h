#ifndef INPUT_H
#define INPUT_H

int readInt(const char *prompt, int min, int max);
double readDouble(const char *prompt, double min, double max);
void readNonEmptyString(const char *prompt, char *buffer, int size);

#endif
