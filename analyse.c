#include "analyse.h"

// List of keywords in C (basic set)
const char *keywords[MAX_KEYWORDS] = {
    "int","char","float","double","if","else","for","while","do",
    "switch","case","break","continue","return","void","static","const",
    "struct","union","typedef","enum","sizeof","long","short","unsigned",
    "signed","goto","default","volatile","register","extern","auto"
};

// Check if a word is a keyword
int isKeyword(const char *word) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (keywords[i] && strcmp(keywords[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Lexical analyser logic
void analyseFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    int ch, line = 1;
    int inString = 0, inChar = 0;

    while ((ch = fgetc(fp)) != EOF) {
        // Count newlines
        if (ch == '\n') {
            line++;
        }

        // Preprocessor directive
        if (ch == '#' && !inString && !inChar) {
            printf("[Preprocessor Directive] at line %d: #", line);
            while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
                putchar(ch);
            }
            putchar('\n');
            line++;
            continue;
        }

        // Strings
        if (ch == '"' && !inChar) {
            inString = !inString;
            printf("[String Literal] at line %d: \"", line);
            while ((ch = fgetc(fp)) != '"' && ch != EOF) {
                putchar(ch);
            }
            printf("\"\n");
            continue;
        }

        // Characters
        if (ch == '\'' && !inString) {
            inChar = !inChar;
            printf("[Character Literal] at line %d: '", line);
            while ((ch = fgetc(fp)) != '\'' && ch != EOF) {
                putchar(ch);
            }
            printf("'\n");
            continue;
        }

        // Identifiers or Keywords
        if (isalpha(ch) || ch == '_') {
            char ident[MAX_TOKEN_LEN];
            int idx = 0;
            do {
                ident[idx++] = ch;
                ch = fgetc(fp);
            } while (isalnum(ch) || ch == '_');
            ident[idx] = '\0';
            ungetc(ch, fp); // put back last non-identifier char

            if (isKeyword(ident))
                printf("[Keyword] %s\n", ident);
            else
                printf("[Identifier] %s\n", ident);

            continue;
        }

        // Numbers
        if (isdigit(ch)) {
            char num[MAX_TOKEN_LEN];
            int idx = 0;
            do {
                num[idx++] = ch;
                ch = fgetc(fp);
            } while (isdigit(ch) || ch == '.');
            num[idx] = '\0';
            ungetc(ch, fp);
            printf("[Number] %s\n", num);
            continue;
        }

        // Operators / Special symbols
        if (strchr("+-*/%=&|!<>^", ch)) {
            printf("[Operator] %c\n", ch);
            continue;
        }

        // Braces, semicolons, commas
        if (ch == ';' || ch == '{' || ch == '}' ||
            ch == '(' || ch == ')' || ch == ',') {
            printf("[Symbol] %c\n", ch);
            continue;
        }
    }

    fclose(fp);
}
