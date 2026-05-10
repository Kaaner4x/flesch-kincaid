#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int count_syllables(const char *word) {
    int count = 0;
    bool in_vowels = false;
    int len = strlen(word);

    if (len == 0) return 0;

    for (int i = 0; i < len; i++) {
        if (is_vowel(word[i])) {
            if (!in_vowels) {
                count++;
                in_vowels = true;
            }
        } else {
            in_vowels = false;
        }
    }

    if (tolower(word[len - 1]) == 'e') {
        if (len > 2 && tolower(word[len - 2]) == 'l' && !is_vowel(word[len - 3])) {
        } else {
            count--;
        }
    }

    if (count <= 0) {
        count = 1;
    }

    return count;
}

void analyze_text(const char *text, int *words, int *sentences, int *syllables) {
    *words = 0;
    *sentences = 0;
    *syllables = 0;
    
    int len = strlen(text);
    char word_buffer[256];
    int w_idx = 0;
    
    for (int i = 0; i <= len; i++) {
        char c = text[i];
        
        if (c == '.' || c == '!' || c == '?') {
            (*sentences)++;
        }
        
        if (isalpha((unsigned char)c)) {
            if (w_idx < 255) {
                word_buffer[w_idx++] = c;
            }
        } else if (w_idx > 0) {
            word_buffer[w_idx] = '\0';
            (*words)++;
            (*syllables) += count_syllables(word_buffer);
            w_idx = 0;
        }
    }
    
    if (*words > 0 && *sentences == 0) {
        *sentences = 1;
    }
}

int main() {
    char text[4096];
    
    printf("=== Flesch-Kincaid Readability Test ===\n\n");
    printf("Please enter the text to analyze:\n");
    
    if (!fgets(text, sizeof(text), stdin)) {
        printf("Error: Could not read text.\n");
        return 1;
    }

    int words = 0, sentences = 0, syllables = 0;
    analyze_text(text, &words, &sentences, &syllables);

    if (words == 0) {
        printf("\nNo valid words found.\n");
        return 0;
    }

    float reading_ease = 206.835 - 1.015 * ((float)words / sentences) - 84.6 * ((float)syllables / words);

    float grade_level = 0.39 * ((float)words / sentences) + 11.8 * ((float)syllables / words) - 15.59;

    printf("\n--- Analysis Results ---\n");
    printf("Words: %d\n", words);
    printf("Sentences: %d\n", sentences);
    printf("Syllables: %d\n", syllables);
    printf("\n");
    printf("Flesch Reading Ease: %.2f\n", reading_ease);
    printf("Flesch-Kincaid Grade Level: %.2f\n", grade_level);

    return 0;
}
